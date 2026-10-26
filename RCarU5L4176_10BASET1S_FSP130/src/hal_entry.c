/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * 10BASE-T1S (ETNF0 + internal CT25205 PHY) communication test on FSP r_ether_t1s / r_ether_phy.
 *
 * Ported from the validated register-level sample
 * "U5L_ETNF_01_T1S_COM_LQFP100_BelkinAdaptoer_10BASET1S_Capture_Validated" (App_main.c / App_sub.c / App_ETNF_cfg.c):
 *   - T1S mode, PMA filtered, MDIO shared on ETS0_RX_MDC / ETS0_ED_MDIO, PHY MDIO address 0x02 (configuration.xml)
 *   - Source MAC 74:90:50:00:00:01, destination MAC 74:90:50:00:00:00, EtherType IPv4 (0x0800) (configuration.xml)
 *   - PLCA coordinator: node ID 0, node count 9 (slave: ID 1, node count 2)
 *   - 4 frames of 70 bytes (14-byte header + 56-byte payload filled with 0x11 / 0x22 / 0x33 / 0x44)
 *   - TxRx: transmit 4 frames, then wait for 4 frames and check their payload (RxTx: reverse order)
 *
 * The FSP project has no UART driver, so the progress is shown on LED10..LED17 (P18_0..P18_7) and
 * in g_app_t1s_status (watch it in the debugger).
 **********************************************************************************************************************/
#include <string.h>
#include "hal_data.h"

void R_BSP_WarmStart(bsp_warm_start_event_t event);

extern bsp_leds_t g_bsp_leds;

/***********************************************************************************************************************
 * Test configuration (same meaning as App_ETNF_cfg.h of the validated sample)
 **********************************************************************************************************************/

/* Communication type for test */
#define APP_ETNF_TXRX                 (0)    /* 1st communication: Transmit, 2nd communication: Receive */
#define APP_ETNF_RXTX                 (1)    /* 1st communication: Receive, 2nd communication: Transmit */
#define APP_COM_TEST                  (APP_ETNF_TXRX)

/* PLCA role */
#define APP_COM_MASTER                (0)    /* PLCA coordinator (node ID = 0) */
#define APP_COM_SLAVE                 (1)    /* PLCA follower (node ID = 1) */
#define APP_COM_TYPE                  (APP_COM_MASTER)

/* 1: synchronize with the partner board through a GPIO like the validated sample
 *    (master waits until the pin = High, slave drives the pin = High), 0: no synchronization (PC capture)
 * The validated LQFP100 sample uses P13_7, which does not exist on the 176-pin package:
 * define APP_SYNC_PIN with a free pin of the board (e.g. BSP_IO_PORT_P10_PIN_3) when enabling it. */
#define APP_USE_SYNC_PIN              (0)
#if (APP_USE_SYNC_PIN) && !defined(APP_SYNC_PIN)
 #error "Define APP_SYNC_PIN (bsp_io_port_pin_t) for the master/slave synchronization"
#endif

/* Wait time for the reception in milliseconds, 0: wait forever (same as the validated sample) */
#define APP_RX_TIMEOUT_MS             (0U)

/* Frame setting */
#define APP_NUM_FRAME                 (4U)
#define APP_HEADER_SIZE               (14U)
#define APP_PAYLOAD_LEN               (56U)
#define APP_FRAME_LEN                 (APP_HEADER_SIZE + APP_PAYLOAD_LEN) /* Without FCS */
#define APP_ETHER_TYPE_IPV4           (0x0800U)
#define APP_RX_BUFFER_SIZE            (1536U)
#define APP_MAC_ADDRESS_SIZE          (6U)

/* CT25205 (internal T1S PHY) registers, accessed through R_ETHER_PHY_Read() / R_ETHER_PHY_Write() */
#define APP_PHY_REG_STATUS            (0x000001U)
#define APP_PHY_REG_T1STWEAKS         (0x3F8001U)
#define APP_PHY_REG_T1SPLCAEXT        (0x3F8002U)
#define APP_PHY_REG_T1STXCCTL         (0x3F8005U)
#define APP_PHY_REG_T1SPMACTRL        (0x2108F9U)
#define APP_PHY_REG_PLCACTRL0         (0x3FCA01U)
#define APP_PHY_REG_PLCACTRL1         (0x3FCA02U)

/* T1STWEAKS: PKTLOOP = 0, ENIE = 0, UNJT = 0, RXNRZ = 0, SCRD = 0, NCOLM = 1, RXDLY = 1 */
#define APP_PHY_T1STWEAKS_VALUE       ((1U << 1) | (1U << 0))

/* T1SPLCAEXT: PREN = 0, reserved(bit11) = 1, LDEN = 0, LDR = 0 */
#define APP_PHY_T1SPLCAEXT_VALUE      (1U << 11)

/* T1SPMACTRL: PMARST = 0, TXDIS = 0, LPWR = 0, MULT = 1, LOOP = 0 */
#define APP_PHY_T1SPMACTRL_VALUE      (1U << 10)

/* PLCACTRL0: EN = 1, RST = 0 */
#define APP_PHY_PLCACTRL0_VALUE       (1U << 15)

/* PLCACTRL1: NCNT[15:8] / ID[7:0] */
#if (APP_COM_TYPE == APP_COM_MASTER)
 #define APP_PHY_PLCACTRL1_VALUE      ((0x09U << 8) | 0x00U)
#else
 #define APP_PHY_PLCACTRL1_VALUE      ((0x02U << 8) | 0x01U)
#endif

/* T1STXCCTL commands */
#define APP_PHY_T1S_CMD_NORQ          (0U)   /* Normal operation */
#define APP_PHY_T1S_CMD_RESETRQ       (3U)   /* Forces RESET requests to the TXC */

/* STATUS: LNOK(bit5) | ANAB(bit3) | LKST(bit2) | EXTC(bit0) */
#define APP_PHY_STATUS_DONE           ((1U << 5) | (1U << 3) | (1U << 2) | (1U << 0))

/* LED index (LED10..LED17 = P18_0..P18_7) */
#define APP_LED_OPEN                  (0U)   /* LED10: R_ETHER_T1S_Open() succeeded */
#define APP_LED_PLCA                  (1U)   /* LED11: PLCA configuration done */
#define APP_LED_LINK                  (2U)   /* LED12: link up */
#define APP_LED_TX                    (3U)   /* LED13: transmission done */
#define APP_LED_RX                    (4U)   /* LED14: reception done */
#define APP_LED_PASS                  (5U)   /* LED15: received payload check OK */
#define APP_LED_FAIL                  (6U)   /* LED16: error */
#define APP_LED_ALIVE                 (7U)   /* LED17: blinks after the test */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef enum e_app_t1s_step
{
    APP_T1S_STEP_INIT = 0,
    APP_T1S_STEP_OPEN,
    APP_T1S_STEP_PLCA,
    APP_T1S_STEP_LINK,
    APP_T1S_STEP_SYNC,
    APP_T1S_STEP_TX,
    APP_T1S_STEP_RX,
    APP_T1S_STEP_DONE,
} app_t1s_step_t;

typedef struct st_app_t1s_status
{
    app_t1s_step_t step;               /* Current test step */
    fsp_err_t      last_err;           /* Last FSP error */
    uint32_t       phy_status;         /* PHY STATUS register (0x0001) */
    uint32_t       phy_plcactrl1;      /* PHY PLCACTRL1 register read back */
    uint32_t       tx_count;           /* Number of transmitted frames */
    uint32_t       rx_count;           /* Number of received frames */
    uint32_t       rx_match_count;     /* Number of received frames with a valid test payload */
    uint32_t       rx_error_count;     /* Number of payload bytes not matching */
    uint32_t       rx_last_length;     /* Length of the last received frame */
    bool           result_ok;          /* true: Transmission and reception were successful */
} app_t1s_status_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void      app_led_write(uint32_t index, bsp_io_level_t level);
static fsp_err_t app_t1s_configure_phy(void);
static fsp_err_t app_t1s_wait_link_up(void);
static void      app_t1s_sync_partner(void);
static void      app_t1s_make_tx_frame(void);
static fsp_err_t app_t1s_transmit(void);
static fsp_err_t app_t1s_receive(void);
static bool      app_t1s_check_rx_frame(const uint8_t * p_frame, uint32_t length);
static void      app_t1s_error_trap(fsp_err_t err);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* Test status (watch it in the debugger) */
volatile app_t1s_status_t g_app_t1s_status;

/* Payload pattern of each frame */
static const uint8_t g_app_payload_pattern[APP_NUM_FRAME] = {0x11U, 0x22U, 0x33U, 0x44U};

/* Transmission frames (DA + SA + EtherType + payload) and reception buffer */
static uint8_t g_app_tx_frame[APP_NUM_FRAME][APP_FRAME_LEN] BSP_ALIGN_VARIABLE(4);
static uint8_t g_app_rx_buffer[APP_RX_BUFFER_SIZE] BSP_ALIGN_VARIABLE(4);

/*******************************************************************************************************************//**
 * @brief  10BASE-T1S transmission / reception test
 **********************************************************************************************************************/
void hal_entry (void)
{
#if BSP_TZ_SECURE_BUILD

    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif

    fsp_err_t      err;
    bsp_io_level_t alive = BSP_IO_LEVEL_HIGH;

    g_app_t1s_status.step      = APP_T1S_STEP_INIT;
    g_app_t1s_status.last_err  = FSP_SUCCESS;
    g_app_t1s_status.result_ok = false;

    for (uint32_t i = 0; i < g_bsp_leds.led_count; i++)
    {
        app_led_write(i, BSP_IO_LEVEL_LOW);
    }

    /* Configuration of ETNF and PHY (App_ConfigETNF_product() + App_Init_ETNF())
     * Releases the module standby, configures E-MAC / AVB-DMAC / descriptors, sets the T1S control register
     * (PMA filtered, shared MDIO, PHY address) and initializes the CT25205 PHY.
     ****************************************************************************/
    g_app_t1s_status.step = APP_T1S_STEP_OPEN;
    err = R_ETHER_T1S_Open(&g_ether_t1s0_ctrl, &g_ether_t1s0_cfg);
    app_t1s_error_trap(err);
    app_led_write(APP_LED_OPEN, BSP_IO_LEVEL_HIGH);

    /* Configure T1S PHY (PLCA) (App_ConfigureT1SPHYSetting())
     ****************************************************************************/
    g_app_t1s_status.step = APP_T1S_STEP_PLCA;
    err = app_t1s_configure_phy();
    app_t1s_error_trap(err);
    app_led_write(APP_LED_PLCA, BSP_IO_LEVEL_HIGH);

    /* Wait for the link up and enable transmission and reception
     ****************************************************************************/
    g_app_t1s_status.step = APP_T1S_STEP_LINK;
    err = app_t1s_wait_link_up();
    app_t1s_error_trap(err);
    app_led_write(APP_LED_LINK, BSP_IO_LEVEL_HIGH);

    /* Tx Frame Setting (App_Make_TxFrame())
     ****************************************************************************/
    app_t1s_make_tx_frame();

    g_app_t1s_status.step = APP_T1S_STEP_SYNC;
    app_t1s_sync_partner();

#if (APP_COM_TEST == APP_ETNF_TXRX)

    /* Start transmission and wait until complete, then wait until all data received */
    g_app_t1s_status.step = APP_T1S_STEP_TX;
    err = app_t1s_transmit();
    app_t1s_error_trap(err);
    app_led_write(APP_LED_TX, BSP_IO_LEVEL_HIGH);

    g_app_t1s_status.step = APP_T1S_STEP_RX;
    err = app_t1s_receive();
    app_t1s_error_trap(err);
    app_led_write(APP_LED_RX, BSP_IO_LEVEL_HIGH);
#else

    /* Wait until all data received, then start transmission and wait until complete */
    g_app_t1s_status.step = APP_T1S_STEP_RX;
    err = app_t1s_receive();
    app_t1s_error_trap(err);
    app_led_write(APP_LED_RX, BSP_IO_LEVEL_HIGH);

    g_app_t1s_status.step = APP_T1S_STEP_TX;
    err = app_t1s_transmit();
    app_t1s_error_trap(err);
    app_led_write(APP_LED_TX, BSP_IO_LEVEL_HIGH);
#endif

    /* Check received frames and output result (App_Check_Rxframe())
     ****************************************************************************/
    g_app_t1s_status.step      = APP_T1S_STEP_DONE;
    g_app_t1s_status.result_ok = ((APP_NUM_FRAME <= g_app_t1s_status.rx_match_count) &&
                                  (0U == g_app_t1s_status.rx_error_count));
    if (g_app_t1s_status.result_ok)
    {
        app_led_write(APP_LED_PASS, BSP_IO_LEVEL_HIGH);
    }
    else
    {
        app_led_write(APP_LED_FAIL, BSP_IO_LEVEL_HIGH);
    }

    /* The channel is kept open so that the link can be inspected after the test */
    while (1)
    {
        app_led_write(APP_LED_ALIVE, alive);
        alive = (BSP_IO_LEVEL_HIGH == alive) ? BSP_IO_LEVEL_LOW : BSP_IO_LEVEL_HIGH;

        (void) R_ETHER_T1S_LinkProcess(&g_ether_t1s0_ctrl);

        R_BSP_SoftwareDelay(500U, BSP_DELAY_UNITS_MILLISECONDS);
    }
}

/*******************************************************************************************************************//**
 * @brief  Write the level of the board LED
 *
 * @param[in]  index    LED index (0: LED10 .. 7: LED17)
 * @param[in]  level    Output level
 **********************************************************************************************************************/
static void app_led_write (uint32_t index, bsp_io_level_t level)
{
    if (index < g_bsp_leds.led_count)
    {
        uint32_t pin = g_bsp_leds.p_leds[index];

        R_BSP_PinAccessEnable();
        R_BSP_PortWriteEnable((bsp_io_port_t) pin);
        R_BSP_PinWrite((bsp_io_port_pin_t) pin, level);
        R_BSP_PortWriteDisable((bsp_io_port_t) pin);
        R_BSP_PinAccessDisable();
    }
}

/*******************************************************************************************************************//**
 * @brief  Configure PHY setting for PLCA (App_ConfigureT1SPHYSetting() of the validated sample)
 *
 * R_ETHER_T1S_Open() already resets the CT25205 and enables PLCA with node count 8 / ID 0.
 * This function applies the validated CT25205 settings and the PLCA node count / node ID of APP_COM_TYPE.
 *
 * @retval FSP_SUCCESS     PHY configured
 * @retval Others          Error of R_ETHER_PHY_Read() / R_ETHER_PHY_Write()
 **********************************************************************************************************************/
static fsp_err_t app_t1s_configure_phy (void)
{
    fsp_err_t err;
    uint32_t  value = 0U;

    /* configuration for CT25205-specific features */
    err = R_ETHER_PHY_Write(&g_ether_phy0_ctrl, APP_PHY_REG_T1STWEAKS, APP_PHY_T1STWEAKS_VALUE);

    /* configuration for CT25205-specific PLCA features (initial value) */
    if (FSP_SUCCESS == err)
    {
        err = R_ETHER_PHY_Write(&g_ether_phy0_ctrl, APP_PHY_REG_T1SPLCAEXT, APP_PHY_T1SPLCAEXT_VALUE);
    }

    /* configuration for CT25205-specific PMA features (no PMA loop back) */
    if (FSP_SUCCESS == err)
    {
        err = R_ETHER_PHY_Write(&g_ether_phy0_ctrl, APP_PHY_REG_T1SPMACTRL, APP_PHY_T1SPMACTRL_VALUE);
    }

    /* basic PLCA configuration */
    if (FSP_SUCCESS == err)
    {
        err = R_ETHER_PHY_Write(&g_ether_phy0_ctrl, APP_PHY_REG_PLCACTRL0, APP_PHY_PLCACTRL0_VALUE);
    }

    /* configuring the PLCA node count and local node ID parameters */
    if (FSP_SUCCESS == err)
    {
        err = R_ETHER_PHY_Write(&g_ether_phy0_ctrl, APP_PHY_REG_PLCACTRL1, APP_PHY_PLCACTRL1_VALUE);
    }

    if (FSP_SUCCESS == err)
    {
        err = R_ETHER_PHY_Read(&g_ether_phy0_ctrl, APP_PHY_REG_PLCACTRL1, &value);
        g_app_t1s_status.phy_plcactrl1 = value;
    }

    /* Forces RESET requests to the TXC, then normal operation */
    if (FSP_SUCCESS == err)
    {
        err = R_ETHER_PHY_Write(&g_ether_phy0_ctrl, APP_PHY_REG_T1STXCCTL, APP_PHY_T1S_CMD_RESETRQ);
    }

    if (FSP_SUCCESS == err)
    {
        err = R_ETHER_PHY_Write(&g_ether_phy0_ctrl, APP_PHY_REG_T1STXCCTL, APP_PHY_T1S_CMD_NORQ);
    }

    /* wait until linkup (STATUS: LNOK, ANAB, LKST, EXTC) */
    while (FSP_SUCCESS == err)
    {
        err = R_ETHER_PHY_Read(&g_ether_phy0_ctrl, APP_PHY_REG_STATUS, &value);
        g_app_t1s_status.phy_status = value;

        if ((value & APP_PHY_STATUS_DONE) == APP_PHY_STATUS_DONE)
        {
            break;
        }
    }

    return err;
}

/*******************************************************************************************************************//**
 * @brief  Wait until the driver detects the link up and changes the controller to the active mode
 *         (operation mode + transmission / reception enabled).
 *
 * @retval FSP_SUCCESS     Link up
 * @retval Others          Error of R_ETHER_T1S_LinkProcess()
 **********************************************************************************************************************/
static fsp_err_t app_t1s_wait_link_up (void)
{
    fsp_err_t err;

    do
    {
        err = R_ETHER_T1S_LinkProcess(&g_ether_t1s0_ctrl);

        /* FSP_ERR_ETHER_ERROR_LINK: link is still down, retry */
        if ((FSP_SUCCESS != err) && (FSP_ERR_ETHER_ERROR_LINK != err))
        {
            return err;
        }
    } while (ETHER_T1S_LINK_ESTABLISH_STATUS_UP != g_ether_t1s0_ctrl.link_establish_status);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief  Synchronize with the partner board through P13_7 (APP_USE_SYNC_PIN = 1 only)
 **********************************************************************************************************************/
static void app_t1s_sync_partner (void)
{
#if (APP_USE_SYNC_PIN)
 #if (APP_COM_TYPE == APP_COM_MASTER)

    /* Wait until the slave sets the flag (P13_7 = High) */
    (void) R_IOPORT_PinCfg(&g_ioport_ctrl, APP_SYNC_PIN,
                           (uint32_t) IOPORT_CFG_PORT_DIRECTION_INPUT | (uint32_t) IOPORT_CFG_INPUT_BUFFER_SHMT1);
    while ((uint32_t) BSP_IO_LEVEL_HIGH != R_BSP_PinRead(APP_SYNC_PIN))
    {
        ;
    }
 #else

    /* Set the flag for the master (P13_7 = High) */
    (void) R_IOPORT_PinCfg(&g_ioport_ctrl, APP_SYNC_PIN,
                           (uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT | (uint32_t) IOPORT_CFG_PORT_OUTPUT_HIGH);
 #endif
#endif
}

/*******************************************************************************************************************//**
 * @brief  Make transmit frames (App_Make_TxFrame() of the validated sample)
 *         The driver is configured with "Header data custom", so the application writes the whole frame.
 **********************************************************************************************************************/
static void app_t1s_make_tx_frame (void)
{
    const ether_t1s_extended_cfg_t * p_extend = (const ether_t1s_extended_cfg_t *) g_ether_t1s0_cfg.p_extend;

    for (uint32_t i = 0; i < APP_NUM_FRAME; i++)
    {
        /* Destination address, source address and EtherType
         * (App_DA / App_SA of the validated sample = "Destination MAC address" / "Source MAC address" of
         * configuration.xml: 74:90:50:00:00:00 / 74:90:50:00:00:01) */
        memcpy(&g_app_tx_frame[i][0], p_extend->p_mac_address_target, APP_MAC_ADDRESS_SIZE);
        memcpy(&g_app_tx_frame[i][APP_MAC_ADDRESS_SIZE], g_ether_t1s0_cfg.p_mac_address, APP_MAC_ADDRESS_SIZE);
        g_app_tx_frame[i][12] = (uint8_t) (APP_ETHER_TYPE_IPV4 >> 8);
        g_app_tx_frame[i][13] = (uint8_t) (APP_ETHER_TYPE_IPV4 & 0xFFU);

        /* Payload */
        memset(&g_app_tx_frame[i][APP_HEADER_SIZE], g_app_payload_pattern[i], APP_PAYLOAD_LEN);
    }
}

/*******************************************************************************************************************//**
 * @brief  Transmit all frames. In polling mode R_ETHER_T1S_Write() returns after the transmission is complete.
 *
 * @retval FSP_SUCCESS     All frames transmitted
 * @retval Others          Error of R_ETHER_T1S_Write()
 **********************************************************************************************************************/
static fsp_err_t app_t1s_transmit (void)
{
    fsp_err_t err = FSP_SUCCESS;

    for (uint32_t i = 0; i < APP_NUM_FRAME; i++)
    {
        do
        {
            err = R_ETHER_T1S_Write(&g_ether_t1s0_ctrl, &g_app_tx_frame[i][0], APP_FRAME_LEN);
        } while (FSP_ERR_IN_USE == err); /* Tx buffer is still in use, retry */

        if (FSP_SUCCESS != err)
        {
            break;
        }

        g_app_t1s_status.tx_count++;
    }

    return err;
}

/*******************************************************************************************************************//**
 * @brief  Wait until APP_NUM_FRAME frames with a test payload are received
 *
 * @retval FSP_SUCCESS     All frames received
 * @retval FSP_ERR_TIMEOUT Not all frames received within APP_RX_TIMEOUT_MS
 * @retval Others          Error of R_ETHER_T1S_Read()
 **********************************************************************************************************************/
static fsp_err_t app_t1s_receive (void)
{
    fsp_err_t err;
    uint32_t  length;
    uint32_t  elapsed_ms = 0U;

    while (g_app_t1s_status.rx_match_count < APP_NUM_FRAME)
    {
        length = sizeof(g_app_rx_buffer);
        err    = R_ETHER_T1S_Read(&g_ether_t1s0_ctrl, g_app_rx_buffer, &length);

        if (FSP_SUCCESS == err)
        {
            g_app_t1s_status.rx_count++;
            g_app_t1s_status.rx_last_length = length;

            if (app_t1s_check_rx_frame(g_app_rx_buffer, length))
            {
                g_app_t1s_status.rx_match_count++;
            }
        }
        else if (FSP_ERR_ETHER_ERROR_NO_DATA == err)
        {
#if (0U != APP_RX_TIMEOUT_MS)
            R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MILLISECONDS);
            elapsed_ms++;
            if (APP_RX_TIMEOUT_MS <= elapsed_ms)
            {
                return FSP_ERR_TIMEOUT;
            }
#endif
        }
        else
        {
            return err;
        }
    }

    FSP_PARAMETER_NOT_USED(elapsed_ms);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * @brief  Check the payload of a received frame (App_Check_Rxframe() of the validated sample)
 *         A frame whose first payload byte is one of the test patterns is a test frame; all the 56 payload bytes
 *         must then be the same pattern. Other frames (e.g. PC traffic) are ignored.
 *
 * @param[in]  p_frame    Received frame (from destination address)
 * @param[in]  length     Received length in bytes
 *
 * @retval true           Test frame received
 * @retval false          Not a test frame
 **********************************************************************************************************************/
static bool app_t1s_check_rx_frame (const uint8_t * p_frame, uint32_t length)
{
    uint8_t pattern = p_frame[APP_HEADER_SIZE];
    bool    is_test = false;

    if (length < APP_FRAME_LEN)
    {
        return false;
    }

    for (uint32_t i = 0; i < APP_NUM_FRAME; i++)
    {
        if (g_app_payload_pattern[i] == pattern)
        {
            is_test = true;
        }
    }

    if (is_test)
    {
        for (uint32_t j = APP_HEADER_SIZE; j < APP_FRAME_LEN; j++)
        {
            if (pattern != p_frame[j])
            {
                g_app_t1s_status.rx_error_count++;
            }
        }
    }

    return is_test;
}

/*******************************************************************************************************************//**
 * @brief  Stop here when an error occurs (LED16 on, g_app_t1s_status.step / last_err show where)
 *
 * @param[in]  err    FSP error
 **********************************************************************************************************************/
static void app_t1s_error_trap (fsp_err_t err)
{
    if (FSP_SUCCESS != err)
    {
        g_app_t1s_status.last_err = err;
        app_led_write(APP_LED_FAIL, BSP_IO_LEVEL_HIGH);

        while (1)
        {
            ;
        }
    }
}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process.  This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart (bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {
    }

    if (BSP_WARM_START_POST_C == event)
    {
        /* C runtime environment and system clocks are setup. */

        /* Enable Guard write access for all configured modules */
        R_BSP_GuardEnableAccessAll();

        /* Enable clock supply for all configured modules */
        R_BSP_ModuleStandbyEnableAll();

        /* Configure pins. */
        IOPORT_CFG_OPEN(&IOPORT_CFG_CTRL, &IOPORT_CFG_NAME);
    }
}
