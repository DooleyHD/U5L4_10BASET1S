/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RCARMCUU5L
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RCARMCUU5L) */

#ifndef BSP_OVERRIDE_H
#define BSP_OVERRIDE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/* C99 includes. */
#include <stdbool.h>

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Overrides for UART */
#define BSP_OVERRIDE_UART_DATA_BITS_T
#define BSP_OVERRIDE_UART_EVENT_T
#define BSP_OVERRIDE_UART_PARITY_T

/* Overrides for ADCK */
#define BSP_OVERRIDE_ADC_INCLUDE
#define BSP_OVERRIDE_ADC_EVENT_T
#define BSP_OVERRIDE_ADC_CHANNEL_T
#define BSP_OVERRIDE_ADC_INFO_T
#define BSP_OVERRIDE_ADC_NUMBER_OF_SG         (5U)

/* Override for Timer */
#define BSP_OVERRIDE_TIMER_EVENT_T            (1U)
#define BSP_OVERRIDE_TIMER_CALLBACK_ARGS_T    (1U)
#define BSP_OVERRIDE_TIMER_STATE_T            (1U)
#define BSP_OVERRIDE_TIMER_STATUS_T           (1U)

/* Override for CSIH */
#define BSP_OVERRIDE_CSIH_CFG_T
#define BSP_OVERRIDE_SPI_BIT_WIDTH_T

/* Override for SFMA */
#define BSP_OVERRIDE_SPI_FLASH_ADDRESS_BYTES_T

/* Override for DMA */
#define BSP_OVERRIDE_TRANSFER_MODE_T
#define BSP_OVERRIDE_TRANSFER_SIZE_T
#define BSP_OVERRIDE_TRANSFER_ADDR_MODE_T
#define BSP_OVERRIDE_TRANSFER_CHAIN_MODE_T
#define BSP_OVERRIDE_TRANSFER_RELOAD_FUNCTION_1_T
#define BSP_OVERRIDE_TRANSFER_RELOAD_FUNCTION_2_T
#define BSP_OVERRIDE_TRANSFER_INFO_T
#define BSP_OVERRIDE_TRANSFER_REPEAT_AREA_T
#define BSP_OVERRIDE_TRANSFER_IRQ_T
#define BSP_OVERRIDE_TRANSFER_REQUEST_T
#define BSP_OVERRIDE_TRANSFER_CALLBACK_ARGS_T

/* Override for ICU */
#define BSP_OVERRIDE_EXTERNAL_IRQ_TRIGGER_T

/* Override for ETHER */
#define BSP_OVERRIDE_ETHER_EVENT_T

/** LIN data length type */
#define BSP_OVERRIDE_LIN_DATA_LENGTH_T

/* Override for ETHER_PHY */
#define BSP_OVERRIDE_ETHER_PHY_LSI_TYPE_T

/* Overrides for CAN */
#define BSP_OVERRIDE_CAN_EVENT_T

/* Override for CRC */
#define BSP_OVERRIDE_CRC_BIT_ORDER_T
#define BSP_OVERRIDE_CRC_64_BIT_POLY_T

/* Override for POSITION_SENSOR */
#define BSP_OVERRIDE_POSITION_SENSOR_OUTPUT_CFG_T

/* Override for CGC */
#define BSP_OVERRIDE_CGC_CLOCK_T
#define BSP_OVERRIDE_CGC_SYS_CLOCK_DIV_T
#define BSP_OVERRIDE_CGC_PLL_CFG_T
#define BSP_OVERRIDE_CGC_CLOCK_CHANGE_T
#define BSP_OVERRIDE_CGC_DIVIDER_CFG_T
#define BSP_OVERRIDE_CGC_CLOCKS_CFG_T

/* Override for VMON */
#define BSP_OVERRIDE_VMON_FACTOR_STATUS_T
#define BSP_OVERRIDE_VMON_FACTOR_DETECTION_T

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                          ADCK
 **********************************************************************************************************************/

/** ADC callback event definitions  */
typedef enum e_adc_event
{
    ADC_EVENT_SCAN_COMPLETE_GROUP_0,   ///< Scan group 0 scan completed
    ADC_EVENT_SCAN_COMPLETE_GROUP_1,   ///< Scan group 1 scan completed
    ADC_EVENT_SCAN_COMPLETE_GROUP_2,   ///< Scan group 2 scan completed
    ADC_EVENT_SCAN_COMPLETE_GROUP_3,   ///< Scan group 3 scan completed
    ADC_EVENT_SCAN_COMPLETE_GROUP_4,   ///< Scan group 4 scan completed
    ADC_EVENT_SCAN_COMPLETE_SG_DIAG,   ///< SG-Diag scan completed
    ADC_EVENT_ID_ERROR,                ///< An ID event had occurred
    ADC_EVENT_OVERWRITE_ERROR,         ///< An overwrite event had occcured
    ADC_EVENT_TRIGGER_OVERLAP_ERROR,   ///< An trigger overlap event had occurred
    ADC_EVENT_MPX_CONVERSION,          ///< Even called when MPX interrupt occurred
    ADC_EVENT_UPPER_LOWER_LIMIT_ERROR  ///< An upper/lower limit check event had occured
} adc_event_t;

/* ADC channels for ADCK */
typedef enum e_adc_channel
{
    ADC_CHANNEL_0                 = 0U,   ///< ADCKn channel 0
    ADC_CHANNEL_1                 = 1U,   ///< ADCKn channel 1
    ADC_CHANNEL_2                 = 2U,   ///< ADCKn channel 2
    ADC_CHANNEL_3                 = 3U,   ///< ADCKn channel 3
    ADC_CHANNEL_4                 = 4U,   ///< ADCKn channel 4
    ADC_CHANNEL_5                 = 5U,   ///< ADCKn channel 5
    ADC_CHANNEL_6                 = 6U,   ///< ADCKn channel 6
    ADC_CHANNEL_7                 = 7U,   ///< ADCKn channel 7
    ADC_CHANNEL_8                 = 8U,   ///< ADCKn channel 8
    ADC_CHANNEL_9                 = 9U,   ///< ADCKn channel 9
    ADC_CHANNEL_10                = 10U,  ///< ADCKn channel 10
    ADC_CHANNEL_11                = 11U,  ///< ADCKn channel 11
    ADC_CHANNEL_12                = 12U,  ///< ADCKn channel 12
    ADC_CHANNEL_13                = 13U,  ///< ADCKn channel 13
    ADC_CHANNEL_14                = 14U,  ///< ADCKn channel 14
    ADC_CHANNEL_15                = 15U,  ///< ADCKn channel 15
    ADC_CHANNEL_16                = 16U,  ///< ADCKn channel 16
    ADC_CHANNEL_17                = 17U,  ///< ADCKn channel 17
    ADC_CHANNEL_18                = 18U,  ///< ADCKn channel 18
    ADC_CHANNEL_19                = 19U,  ///< ADCKn channel 19
    ADC_CHANNEL_20                = 20U,  ///< ADCKn channel 20
    ADC_CHANNEL_21                = 21U,  ///< ADCKn channel 21
    ADC_CHANNEL_22                = 22U,  ///< ADCKn channel 22
    ADC_CHANNEL_23                = 23U,  ///< ADCKn channel 23
    ADC_CHANNEL_24                = 24U,  ///< ADCKn channel 24
    ADC_CHANNEL_25                = 25U,  ///< ADCKn channel 25
    ADC_CHANNEL_26                = 26U,  ///< ADCKn channel 26
    ADC_CHANNEL_27                = 27U,  ///< ADCKn channel 27
    ADC_CHANNEL_28                = 28U,  ///< ADCKn channel 28
    ADC_CHANNEL_29                = 29U,  ///< ADCKn channel 29
    ADC_CHANNEL_30                = 30U,  ///< ADCKn channel 30
    ADC_CHANNEL_31                = 31U,  ///< ADCKn channel 31
    ADC_CHANNEL_32                = 32U,  ///< ADCKn channel 32
    ADC_CHANNEL_33                = 33U,  ///< ADCKn channel 33
    ADC_CHANNEL_34                = 34U,  ///< ADCKn channel 34
    ADC_CHANNEL_35                = 35U,  ///< ADCKn channel 35
    ADC_CHANNEL_36                = 36U,  ///< ADCKn channel 36
    ADC_CHANNEL_37                = 37U,  ///< ADCKn channel 37
    ADC_CHANNEL_38                = 38U,  ///< ADCKn channel 38
    ADC_CHANNEL_39                = 39U,  ///< ADCKn channel 39
    ADC_CHANNEL_40                = 40U,  ///< ADCKn channel 40
    ADC_CHANNEL_41                = 41U,  ///< ADCKn channel 41
    ADC_CHANNEL_42                = 42U,  ///< ADCKn channel 42
    ADC_CHANNEL_43                = 43U,  ///< ADCKn channel 43
    ADC_CHANNEL_44                = 44U,  ///< ADCKn channel 44
    ADC_CHANNEL_45                = 45U,  ///< ADCKn channel 45
    ADC_CHANNEL_46                = 46U,  ///< ADCKn channel 46
    ADC_CHANNEL_47                = 47U,  ///< ADCKn channel 47
    ADC_CHANNEL_48                = 48U,  ///< ADCKn channel 48
    ADC_CHANNEL_49                = 49U,  ///< ADCKn channel 49
    ADC_CHANNEL_50                = 50U,  ///< ADCKn channel 50
    ADC_CHANNEL_51                = 51U,  ///< ADCKn channel 51
    ADC_CHANNEL_52                = 52U,  ///< ADCKn channel 52
    ADC_CHANNEL_53                = 53U,  ///< ADCKn channel 53
    ADC_CHANNEL_54                = 54U,  ///< ADCKn channel 54
    ADC_CHANNEL_55                = 55U,  ///< ADCKn channel 55
    ADC_CHANNEL_56                = 56U,  ///< ADCKn channel 56
    ADC_CHANNEL_57                = 57U,  ///< ADCKn channel 57
    ADC_CHANNEL_58                = 58U,  ///< ADCKn channel 58
    ADC_CHANNEL_59                = 59U,  ///< ADCKn channel 59
    ADC_CHANNEL_60                = 60U,  ///< ADCKn channel 60
    ADC_CHANNEL_61                = 61U,  ///< ADCKn channel 61
    ADC_CHANNEL_62                = 62U,  ///< ADCKn channel 62
    ADC_CHANNEL_63                = 63U,  ///< ADCKn channel 63
    ADC_CHANNEL_PWM_DIAG          = 80U,  ///< ADCKn PWWM-Diag channel
    ADC_CHANNEL_SG_DIAG_CHANNEL_0 = 120U, ///< ADCKn SG-Diag channel 0
    ADC_CHANNEL_SG_DIAG_CHANNEL_1 = 121U, ///< ADCKn SG-Diag channel 1
    ADC_CHANNEL_SG_DIAG_CHANNEL_2 = 122U  ///< ADCKn SG-Diag channel 2
} adc_channel_t;

/** ADC Information Structure for Transfer Interface */
typedef struct st_adc_info
{
    volatile void * p_address[BSP_OVERRIDE_ADC_NUMBER_OF_SG]; ///< The address to start reading the data from
    uint32_t        length[BSP_OVERRIDE_ADC_NUMBER_OF_SG];    ///< The total number of transfers to read
} adc_info_t;

/***********************************************************************************************************************
 *                          UART
 **********************************************************************************************************************/

/** UART Event codes */
typedef enum e_uart_event
{
    UART_EVENT_ERR_BIT     = 0x01 << 0, ///< Bit error event
    UART_EVENT_ERR_OVERRUN = 0x01 << 2, ///< Overrun error event
    UART_EVENT_ERR_FRAMING = 0x01 << 3, ///< Frame error event
    UART_EVENT_ERR_EXPAND  = 0x01 << 4, ///< Expansion bit error event
    UART_EVENT_ERR_ID      = 0x01 << 5, ///< ID match error event
    UART_EVENT_ERR_PARITY  = 0x01 << 6, ///< Parity error event
    UART_EVENT_TX_COMPLETE = 0x00,      ///< Transmit complete event
    UART_EVENT_RX_CHAR     = 0xFE,      ///< Character received
    UART_EVENT_RX_COMPLETE = 0xFF,      ///< Receive complete event
    UART_EVENT_ID_MATCH    = 0x30       ///< Receive data matched the ID value
} uart_event_t;

/** UART Data bit length definition */
typedef enum e_uart_data_bits
{
    UART_DATA_BITS_9 = 2U,             ///< Data bits 9-bits
    UART_DATA_BITS_8 = 0U,             ///< Data bits 8-bits
    UART_DATA_BITS_7 = 1U              ///< Data bits 7-bits
} uart_data_bits_t;

/** UART Parity definition */
typedef enum e_uart_parity
{
    UART_PARITY_OFF  = 0U,             ///< No parity
    UART_PARITY_EVEN = 1U,             ///< Even parity
    UART_PARITY_ZERO = 2U,             ///< Zero parity
    UART_PARITY_ODD  = 3U              ///< Odd parity
} uart_parity_t;

/***********************************************************************************************************************
 *                          SFMA
 **********************************************************************************************************************/

/** Number of bytes in the address. */
typedef enum e_spi_flash_address_bytes
{
    SPI_FLASH_ADDRESS_BYTES_3 = 0x07,                ///< 3 address bytes

    SPI_FLASH_ADDRESS_BYTES_4 = 0x0F,                ///< 4 address bytes

    SPI_FLASH_ADDRESS_BYTES_4_4BYTE_READ_CODE = 0x13 ///< 4 address bytes with 4-byte read command
} spi_flash_address_bytes_t;

/***********************************************************************************************************************
 *                          DMA
 **********************************************************************************************************************/

/** Transfer request type selection when using DMAC */
typedef enum e_transfer_request
{
    /** Transfer is triggered by software */
    TRANSFER_REQUEST_DMA_SOFTWARE = 0,

    /** Transfer is triggered by hardware request */
    TRANSFER_REQUEST_DMA_HARDWARE = 1
} transfer_request_t;

/** Transfer mode describes what will happen when a transfer request occurs. */
typedef enum e_transfer_mode
{
    TRANSFER_MODE_SINGLE  = 0,         ///< Single transfer mode
    TRANSFER_MODE_BLOCK_1 = 1,         ///< Block transfer mode 1
    TRANSFER_MODE_BLOCK_2 = 2          ///< Block transfer mode 2
} transfer_mode_t;

/** Interrupt options. */
typedef enum e_transfer_irq
{
    /** Interrupt is disable */
    TRANSFER_IRQ_DISABLE = 0,

    /** The transfer completion interrupt is set when the last transfer is complete */
    TRANSFER_IRQ_ENABLE = 1
} transfer_irq_t;

/** Reload function 1 enables the transfer count (number of trasnfer) reloads at the end of DMA cycle,
 * and source/destination address reload is also attached in reload function 2 settings */
typedef enum e_transfer_reload_function_1
{
    TRANSFER_RELOAD_FUNCTION_1_DISABLE          = 0, ///< Reload function_1 disabled
    TRANSFER_RELOAD_FUNCTION_1_SRC_ADDR_RELOAD  = 1, ///< Reload source address
    TRANSFER_RELOAD_FUNCTION_1_DEST_ADDR_RELOAD = 2, ///< Reload destination address
    TRANSFER_RELOAD_FUNCTION_1_ALL_ADDR_RELOAD  = 3  ///< Reload both source and destination addresses
} transfer_reload_function_1_t;

/** Reload function 2 enables the address reload count reloads at the end of DMA cycle, and source/destination address
 * reload is also attached in reload function 2 settings */
typedef enum e_transfer_reload_function_2
{
    TRANSFER_RELOAD_FUNCTION_2_DISABLE          = 0, ///< Reload function_2 disabled
    TRANSFER_RELOAD_FUNCTION_2_SRC_ADDR_RELOAD  = 1, ///< Reload source address
    TRANSFER_RELOAD_FUNCTION_2_DEST_ADDR_RELOAD = 2, ///< Reload destination address
    TRANSFER_RELOAD_FUNCTION_2_ALL_ADDR_RELOAD  = 3  ///< Reload both source and destination addresses
} transfer_reload_function_2_t;

/** Address mode specifies whether to modify (increment or decrement) pointer after each transfer. */
typedef enum e_transfer_addr_mode
{
    TRANSFER_ADDR_MODE_INCREMENTED = 0, ///< Address is incremented after each transfer

    TRANSFER_ADDR_MODE_DECREMENTED,     ///< Address is decremented after each transfer

    TRANSFER_ADDR_MODE_FIXED            ///< Address is not modified after each transfer
} transfer_addr_mode_t;

typedef enum e_transfer_event_t
{
    TRANSFER_EVENT_TRANS_COMPLETION      = 0x01 << 4, ///< Completion of the last transfer and shows whether the DMA transfer is complete.
    TRANSFER_EVENT_TRANS_COUNT_MATCH     = 0x01 << 5, ///< Remaining transfer count is the same as the value set in transfer compare register.
    TRANSFER_EVENT_ERR_TRANS_READ_CYCLE  = 0x01 << 7, ///< Transfer error occurs at read cycle.
    TRANSFER_EVENT_ERR_TRANS_WRITE_CYCLE = 0x01 << 11 ///< Transfer error occurs at write cycle.
} transfer_event_t;

/** Callback function parameter data. */
typedef struct st_transfer_callback_args
{
    transfer_event_t event;            ///< Event code
    void const     * p_context;        ///< Placeholder for user data.
} transfer_callback_args_t;

/** Transfer size specifies the size of each individual transfer.
 *  Total transfer length = transfer_size_t * transfer_length_t
 */
typedef enum e_transfer_size
{
    TRANSFER_SIZE_1_BYTE = 0,          ///< Each transfer transfers a 8-bit value
    TRANSFER_SIZE_2_BYTE,              ///< Each transfer transfers a 16-bit value
    TRANSFER_SIZE_4_BYTE,              ///< Each transfer transfers a 32-bit value
    TRANSFER_SIZE_8_BYTE,              ///< Each transfer transfers a 64-bit value
    TRANSFER_SIZE_16_BYTE              ///< Each transfer transfers a 128-bit value
} transfer_size_t;

/** Chain transfer mode options.
 *  @note Only applies for DTC. */
typedef enum e_transfer_chain_mode
{
    TRANSFER_CHAIN_MODE_DISABLED = 0,     ///< Chain function is disabled

    TRANSFER_CHAIN_MODE_ALWAYS = 3,       ///< Chain function is always enabled

    TRANSFER_CHAIN_MODE_LAST_TRANSFER = 1 ///< Chain function is enabled when the current transfer is the last transfer in the block
} transfer_chain_mode_t;

/* Reliabilty function */
typedef enum e_transfer_chain_restriction
{
    TRANSFER_CHAIN_RESTRICTION_ENABLE  = 0, ///< restrict chain function
    TRANSFER_CHAIN_RESTRICTION_DISABLE = 1  ///< do not restrict chain function
} transfer_chain_retriction_t;

typedef struct st_transfer_info
{
    void const * volatile p_src;                       ///< Source pointer
    void * volatile       p_dest;                      ///< Destination pointer
    uint16_t              number_transfer;             ///< Number of transfers
    uint16_t              number_transfer_count_match; ///< Number of transfers for transfer count match

    uint16_t addr_reload_count;                        ///< Address reload count

    uint16_t reload_number_transfer;                   ///< Number of transfers for reload

    uint16_t reload_addr_reload_count;                 ///< Address reload count for reload

    union
    {
        struct
        {
            transfer_mode_t transfer_mode : 2;              ///< Transfer mode setting

            transfer_size_t transfer_data_size : 3;         ///< Transfer size setting

            transfer_addr_mode_t src_addr_direction : 2;    ///< Source address mode setting

            transfer_addr_mode_t des_addr_direction : 2;    ///< Destination address mode setting

            transfer_reload_function_1_t reload_func_1 : 2; ///< Reload function 1 setting

            transfer_reload_function_2_t reload_func_2 : 2; ///< Reload function 2 setting

            uint32_t continous_transfer : 1;                ///< Continuous transfer mode setting

            uint32_t transfer_completion_irq : 1;           ///< Transfer completion interrupt setting

            uint32_t transfer_count_match_irq : 1;          ///< Transfer count match interrupt setting

            transfer_chain_mode_t chain_function : 2;       ///< Chain transfer mode setting

            uint32_t next_channel_to_chain : 3;             ///< Next channel to chain setting

            uint32_t : 5;                                   ///< Reserved bits

            transfer_request_t transfer_request_type : 1;   ///< Transfer request type setting

            uint32_t transfer_disable_in_error : 1;         ///< Transfer disable in error setting

            uint32_t : 4;                                   ///< Reserved bits
        }        transfer_control_b;
        uint32_t transfer_control;                          ///< Transfer control register
    };
    void * volatile p_reload_src_addr;                      ///< Source address for reload
    void * volatile p_reload_des_addr;                      ///< Destination address for reload
} transfer_info_t;

/** Chain Restriction Config*/
typedef struct st_transfer_chain_restrict_cfg
{
    transfer_chain_retriction_t chain_restriction_mode;
    uint8_t master_rgid;
    uint8_t chain_rgid;
} transfer_chain_restrict_cfg_t;

/***********************************************************************************************************************
 *                          CSIH
 **********************************************************************************************************************/

/** SPI data bit width */
typedef enum e_spi_bit_width
{
    SPI_BIT_WIDTH_16_BITS = (0x0),     ///< Selects the data length is 16 bits
    SPI_BIT_WIDTH_1_BIT   = (0x1),     ///< Selects the data length is 1 bit
    SPI_BIT_WIDTH_2_BITS  = (0x2),     ///< Selects the data length is 2 bits
    SPI_BIT_WIDTH_3_BITS  = (0x3),     ///< Selects the data length is 3 bits
    SPI_BIT_WIDTH_4_BITS  = (0x4),     ///< Selects the data length is 4 bits
    SPI_BIT_WIDTH_5_BITS  = (0x5),     ///< Selects the data length is 5 bits
    SPI_BIT_WIDTH_6_BITS  = (0x6),     ///< Selects the data length is 6 bits
    SPI_BIT_WIDTH_7_BITS  = (0x7),     ///< Selects the data length is 7 bits
    SPI_BIT_WIDTH_8_BITS  = (0x8),     ///< Selects the data length is 8 bits
    SPI_BIT_WIDTH_9_BITS  = (0x9),     ///< Selects the data length is 9 bits
    SPI_BIT_WIDTH_10_BITS = (0xA),     ///< Selects the data length is 10 bits
    SPI_BIT_WIDTH_11_BITS = (0xB),     ///< Selects the data length is 11 bits
    SPI_BIT_WIDTH_12_BITS = (0xC),     ///< Selects the data length is 12 bits
    SPI_BIT_WIDTH_13_BITS = (0xD),     ///< Selects the data length is 13 bits
    SPI_BIT_WIDTH_14_BITS = (0xE),     ///< Selects the data length is 14 bits
    SPI_BIT_WIDTH_15_BITS = (0xF),     ///< Selects the data length is 15 bits
    SPI_BIT_WIDTH_17_BITS = (0x11),    ///< Selects the data length is 17 bits
    SPI_BIT_WIDTH_18_BITS = (0x12),    ///< Selects the data length is 18 bits
    SPI_BIT_WIDTH_19_BITS = (0x13),    ///< Selects the data length is 19 bits
    SPI_BIT_WIDTH_20_BITS = (0x14),    ///< Selects the data length is 20 bits
    SPI_BIT_WIDTH_21_BITS = (0x15),    ///< Selects the data length is 21 bits
    SPI_BIT_WIDTH_22_BITS = (0x16),    ///< Selects the data length is 22 bits
    SPI_BIT_WIDTH_23_BITS = (0x17),    ///< Selects the data length is 23 bits
    SPI_BIT_WIDTH_24_BITS = (0x18),    ///< Selects the data length is 24 bits
    SPI_BIT_WIDTH_25_BITS = (0x19),    ///< Selects the data length is 25 bits
    SPI_BIT_WIDTH_26_BITS = (0x1A),    ///< Selects the data length is 26 bits
    SPI_BIT_WIDTH_27_BITS = (0x1B),    ///< Selects the data length is 27 bits
    SPI_BIT_WIDTH_28_BITS = (0x1C),    ///< Selects the data length is 28 bits
    SPI_BIT_WIDTH_29_BITS = (0x1D),    ///< Selects the data length is 29 bits
    SPI_BIT_WIDTH_30_BITS = (0x1E),    ///< Selects the data length is 30 bits
    SPI_BIT_WIDTH_31_BITS = (0x1F),    ///< Selects the data length is 31 bits
    SPI_BIT_WIDTH_32_BITS = (0x20)     ///< Selects the data length is 32 bits
} spi_bit_width_t;

/***********************************************************************************************************************
 *                          TIMER
 **********************************************************************************************************************/

/** Events that can trigger a callback function */
typedef enum e_timer_event
{
    TIMER_EVENT_CYCLE_END,             ///< Requested timer delay has expired or timer has wrapped around
    TIMER_EVENT_INPUT_CAPTURE,         ///< A capture has occurred on the input signal pin.
    TIMER_EVENT_PWSD_QUEUE_FULL,       ///< PWSD queue full happened, applied only for PWM-Diag.
    TIMER_EVENT_PWGC_INTF_00,          ///< PWGC interrupt factor 0 group 0 happened, apply only for PWM-Diag.
    TIMER_EVENT_PWGC_INTF_01,          ///< PWGC interrupt factor 0 group 1 happened, apply only for PWM-Diag.
    TIMER_EVENT_PWGC_INTF_02,          ///< PWGC interrupt factor 0 group 2 happened, apply only for PWM-Diag.
    TIMER_EVENT_PEAK_INTERRUPT,        ///< PEAK interrupt happened, apply only for TAPA
    TIMER_EVENT_VALLEY_INTERRUPT       ///< VALLEY interrupt happened, apply only for TAPA
} timer_event_t;

/** Callback function parameter data */
typedef struct st_timer_callback_args
{
    void        * p_context;           ///< Placeholder for user data.
    timer_event_t event;               ///< The event can be used to identify what caused the callback.
    uint64_t      capture;             ///< The captured value when event is TIMER_EVENT_INPUT_CAPTURE.
    uint32_t      channel;             ///< Channel number that triggered the callback.
} timer_callback_args_t;

/** Possible status values. */
typedef enum e_timer_state
{
    TIMER_STATE_STOPPED  = 0,          ///< Timer is stopped
    TIMER_STATE_COUNTING = 1,          ///< Timer is running
    TIMER_STATE_UNKNOWN  = 2           ///< Timer state could not be defined
} timer_state_t;

/** Current timer status. */
typedef struct st_timer_status
{
    uint32_t      counter;             ///< Current counter value
    timer_state_t state;               ///< Current timer state (running or stopped)
    bool          is_rsf_active;       ///< Current simultaneous rewrite status
} timer_status_t;

/***********************************************************************************************************************
 *                          ICU
 **********************************************************************************************************************/

/** Condition that will trigger an interrupt when detected. */
typedef enum e_external_irq_trigger
{
    EXTERNAL_IRQ_TRIGGER_DISABLE    = 0, ///< Disable trigger
    EXTERNAL_IRQ_TRIGGER_RISING     = 1, ///< Rising edge trigger
    EXTERNAL_IRQ_TRIGGER_FALLING    = 2, ///< Falling edge trigger
    EXTERNAL_IRQ_TRIGGER_BOTH_EDGE  = 3, ///< Both edges trigger
    EXTERNAL_IRQ_TRIGGER_LEVEL_LOW  = 4, ///< Low level trigger
    EXTERNAL_IRQ_TRIGGER_LEVEL_HIGH = 5  ///< High level trigger
} external_irq_trigger_t;

/***********************************************************************************************************************
 *                          ETHER
 **********************************************************************************************************************/

/** Event code of callback function */
typedef enum e_ether_event
{
    ETHER_EVENT_WAKEON_LAN,              ///< Magic packet detection event
    ETHER_EVENT_LINK_ON,                 ///< Link up detection event
    ETHER_EVENT_LINK_OFF,                ///< Link down detection event
    ETHER_EVENT_RX_COMPLETE,             ///< Receive complete event.
    ETHER_EVENT_RX_MESSAGE_LOST,         ///< Receive FIFO overflow or Receive descriptor is full.
    ETHER_EVENT_TX_COMPLETE,             ///< Transmit complete event.
    ETHER_EVENT_TX_BUFFER_EMPTY,         ///< Transmit descriptor or FIFO is empty.
    ETHER_EVENT_TX_ABORTED,              ///< Transmit abort event.
    ETHER_EVENT_ERR_GLOBAL,              ///< Global error has occurred.
    ETHER_EVENT_GET_NIC_INFO,            ///< Get NIC Info.
    ETHER_LINK_VERIFICATION_SUCCEED,     ///< Link verification succeed event
    ETHER_LINK_VERIFICATION_FAIL,        ///< Link verification fail event
    ETHER_EVENT_RX_INTERRUPT,            ///< Rx Interrupt event
    ETHER_EVENT_TX_INTERRUPT,            ///< Tx Interrupt event
    ETHER_CLOSE_SUCCEED,                 ///< Close event
    ETHER_EVENT_ERROR_LACK_OF_RESOURCES, ///< Allocation memory error due to lack of resources
    ETHER_EVENT_CONFIG_PHY_SUCCESSFUL,   ///< Physical event
    ETHER_EVENT_TIME_COMPARE_MATCH,      ///< Timer compare value match event
    ETHER_EVENT_SGMII_INIT_COMPLETED,    ///< SGMII PHY initialize completed
    ETHER_EVENT_TX_TIMESTAMP,            ///< Tx timestamp Interrupt event
    ETHER_EVENT_RX_TIMESTAMP,            ///< Rx timestamp
} ether_event_t;

/***********************************************************************************************************************
 *                          ETHER_PHY
 **********************************************************************************************************************/

/** Phy LSI */
typedef enum e_ether_phy_lsi_type
{
    ETHER_PHY_LSI_TYPE_DEFAULT            = 0,    ///< Select default configuration. This type dose not change Phy LSI default setting by strapping option.
    ETHER_PHY_LSI_TYPE_LAN8700            = 1,    ///< Select configuration for LAN8700.
    ETHER_PHY_LSI_TYPE_10BASE_T1S_LAN8680 = 2,    ///< Select configuration for LAN8680.
    ETHER_PHY_LSI_TYPE_CT25205_RTL        = 3,    ///< Select configuration for CT25205-RTL.
    ETHER_PHY_LSI_TYPE_CUSTOM             = 0xFFU ///< Select configuration for User custom.
} ether_phy_lsi_type_t;

/***********************************************************************************************************************
 *                          CAN
 **********************************************************************************************************************/

/** CAN event codes */
typedef enum e_can_event
{
    CAN_EVENT_ERR_WARNING          = 0x0002,  ///< Error Warning event.
    CAN_EVENT_ERR_PASSIVE          = 0x0004,  ///< Error Passive event.
    CAN_EVENT_ERR_BUS_OFF          = 0x0008,  ///< Bus Off event.
    CAN_EVENT_BUS_RECOVERY         = 0x0010,  ///< Bus Off Recovery event.
    CAN_EVENT_MAILBOX_MESSAGE_LOST = 0x0020,  ///< Mailbox has been overrun.
    CAN_EVENT_ERR_BUS_LOCK         = 0x0080,  ///< Bus lock detected (32 consecutive dominant bits).
    CAN_EVENT_ERR_CHANNEL          = 0x0100,  ///< Channel error has occurred.
    CAN_EVENT_TX_ABORTED           = 0x0200,  ///< Transmit abort event.
    CAN_EVENT_RX_COMPLETE          = 0x0400,  ///< Receive complete event.
    CAN_EVENT_TX_COMPLETE          = 0x0800,  ///< Transmit complete event.
    CAN_EVENT_ERR_GLOBAL           = 0x1000,  ///< Global error has occurred.
    CAN_EVENT_TX_FIFO_EMPTY        = 0x2000,  ///< Transmit FIFO is empty.
    CAN_EVENT_FIFO_MESSAGE_LOST    = 0x4000,  ///< Receive FIFO overrun.
    CAN_EVENT_TX_QUEUE_EMPTY       = 0x8000,  ///< Transmit Queue is empty
    CAN_EVENT_FIFO_THRESHOLD_REACH = 0x10000, ///< FIFO configured threshold is reached.
    CAN_EVENT_TX_FILTER_REJECTED   = 0x20000, ///< Transmit Filter rejected frame.
    CAN_EVENT_RX_FILTER_REJECTED   = 0x40000  ///< Receive Filter rejected frame.
} can_event_t;

/***********************************************************************************************************************
 *                          CRC
 **********************************************************************************************************************/

/** CRC Calculation Switching (LMS) */
typedef enum e_crc_bit_order
{
    CRC_BIT_ORDER_LMS_MSB = 0,         ///< Generates CRC for MSB first communication
    CRC_BIT_ORDER_LMS_LSB = 1          ///< Generates CRC for LSB first communication
} crc_bit_order_t;

/***********************************************************************************************************************
 *                          POSITION SENSOR
 **********************************************************************************************************************/

typedef enum e_position_sensor_output_cfg
{
    POSITION_SENSOR_OUTPUT_CFG_AOUT = 0, ///< Analog out
    POSITION_SENSOR_OUTPUT_CFG_PWM  = 1, ///< PWM output
    POSITION_SENSOR_OUTPUT_CFG_SENT = 2, ///< SENT
    POSITION_SENSOR_OUTPUT_CFG_I2C  = 6  ///< I2C
} position_sensor_output_cfg_t;

/***********************************************************************************************************************
 *                          CGC
 **********************************************************************************************************************/

/** System clock source identifiers */
typedef enum e_cgc_clock
{
    CGC_CLOCK_MAIN_OSC = 0,            ///< The main oscillator
    CGC_CLOCK_SUBCLOCK = 1,            ///< The subclock oscillator
    CGC_CLOCK_PLL      = 2,            ///< The PLL0/1 oscillator
    CGC_CLOCK_HOCO     = 3,            ///< The high speed on chip oscillator
    CGC_CLOCK_LOCO     = 4,            ///< The low speed on chip oscillator
} cgc_clock_t;

/** System clock divider values */
typedef enum e_cgc_sys_clock_div
{
    CGC_SYS_CLOCK_DIV_NO_DIV   = 0,    ///< No division
    CGC_SYS_CLOCK_DIV_2_BY_16  = 2,    ///< System clock divided by 2
    CGC_SYS_CLOCK_DIV_3_BY_16  = 3,    ///< System clock divided by 3
    CGC_SYS_CLOCK_DIV_4_BY_16  = 4,    ///< System clock divided by 4
    CGC_SYS_CLOCK_DIV_5_BY_16  = 5,    ///< System clock divided by 5
    CGC_SYS_CLOCK_DIV_6_BY_16  = 6,    ///< System clock divided by 6
    CGC_SYS_CLOCK_DIV_7_BY_16  = 7,    ///< System clock divided by 7
    CGC_SYS_CLOCK_DIV_8_BY_16  = 8,    ///< System clock divided by 8
    CGC_SYS_CLOCK_DIV_9_BY_16  = 9,    ///< System clock divided by 9
    CGC_SYS_CLOCK_DIV_10_BY_16 = 10,   ///< System clock divided by 10
    CGC_SYS_CLOCK_DIV_11_BY_16 = 11,   ///< System clock divided by 11
    CGC_SYS_CLOCK_DIV_12_BY_16 = 12,   ///< System clock divided by 12
    CGC_SYS_CLOCK_DIV_13_BY_16 = 13,   ///< System clock divided by 13
    CGC_SYS_CLOCK_DIV_14_BY_16 = 14,   ///< System clock divided by 14
    CGC_SYS_CLOCK_DIV_15_BY_16 = 15,   ///< System clock divided by 15
} cgc_sys_clock_div_t;

/** Clock configuration structure */
typedef struct st_cgc_pll_cfg
{
    cgc_clock_t source_clock;          ///< PLL source clock
} cgc_pll_cfg_t;

/** Clock options */
typedef enum e_cgc_clock_change
{
    CGC_CLOCK_CHANGE_STOP  = 0,        ///< Stop the clock
    CGC_CLOCK_CHANGE_START = 1,        ///< Start the clock
    CGC_CLOCK_CHANGE_NONE  = 2,        ///< No change to the clock
} cgc_clock_change_t;

/** Clock configuration structure. */
typedef struct st_cgc_divider_cfg
{
    cgc_sys_clock_div_t sys0_div;      ///< Divider value for system clock 0
    cgc_sys_clock_div_t sys1_div;      ///< Divider value for system clock 1
} cgc_divider_cfg_t;

/** Clock configuration */
typedef struct st_cgc_clocks_cfg
{
    cgc_pll_cfg_t      pll_cfg;        ///< PLL configuration structure
    cgc_clock_change_t mainosc_state;  ///< State of Main oscillator
    cgc_clock_change_t pll_state;      ///< State of PLL
    cgc_clock_change_t subosc_state;   ///< State of Sub oscillator
} cgc_clocks_cfg_t;

/***********************************************************************************************************************
 *                          VMON
 **********************************************************************************************************************/

/**Factor detection status. */
typedef enum e_vmon_factor_detection
{
    VMON_FACTOR_DETECTION_NO_VIOLATION,   ///< No high voltage violation detected
    VMON_FACTOR_DETECTION_LOW_VIOLATION,  ///< Low voltage violation detected
    VMON_FACTOR_DETECTION_HIGH_VIOLATION, ///< High voltage violation detected
} vmon_factor_detection_t;

/** VMON factor status structure. */
typedef struct st_vmon_factor_status
{
    vmon_factor_detection_t isovdd_status; ///< Voltage isovdd status
} vmon_factor_status_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

#endif
