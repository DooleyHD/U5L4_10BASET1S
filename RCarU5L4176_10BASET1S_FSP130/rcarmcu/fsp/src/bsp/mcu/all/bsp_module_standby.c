/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_WAKEUP_FACTOR_MASK          (0xFFFFFFFFU)
#define BSP_WAKEUP_FACTOR_SHIFT_WORD    (32U)
#define BSP_RESET_FLAG_MASK             (0x80DDU)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
extern bsp_chip_standby_mode_t g_chip_standby_mode;

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
#if (1U == BSP_FEATURE_MODULE_STANDBY_IS_AVAILABLE)
static void bsp_stbc_set_channel(bsp_module_standby_t module, bool enable);
static void bsp_stbc_write_with_protection(volatile uint32_t * p_msr_address, uint32_t value);

#endif
static void                    bsp_stbc_deepstop_enable(bsp_wk_factor_cfg_t wake_src);
static bsp_wk_factor_t         bsp_stbc_deepstop_getwakeupfactor(void);
static void                    bsp_stbc_deepstop_iohold(bsp_io_hold_t io_buffer);
static bsp_chip_standby_mode_t bsp_stbc_getstandbymode(void);

/*******************************************************************************************************************//**
 * @addtogroup BSP_MODULE_STANDBY
 *
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enable supply clock of all configured Module standby that is enabled on BSP MDF.
 **********************************************************************************************************************/
void R_BSP_ModuleStandbyEnableAll ()
{
#if (1U == BSP_FEATURE_MODULE_STANDBY_IS_AVAILABLE)
    uint8_t msr_reg_count;
    uint8_t total_msr;
    bool    init_cfg_value;

    /* Get total of g_msr_info_table elements */
    total_msr = sizeof(g_msr_info_table) / sizeof(g_msr_info_table[0]);

    /* Loop all configured Module standby for initialization. Skip the first element BSP_MODULE_STANDBY_START */
    for (msr_reg_count = 0; msr_reg_count < total_msr; msr_reg_count++)
    {
        /* Get Module standby initial configured value of specific module */
        init_cfg_value = g_msr_info_table[msr_reg_count].initial_cfg_value;

        /* If enable Module standby, process to enable clock supply */
        if (init_cfg_value)
        {
            /* Enable clock supply to target module */
            bsp_stbc_set_channel((bsp_module_standby_t) msr_reg_count, 1U);
        }
    }
#else

    /* The device is not support module standby */
#endif
}

/*******************************************************************************************************************//**
 * Enable clock supply for input module. Module Standby Register for
 * target module MSR_<module name>.
 *
 * @param[in] module      Module to enable supply clock.
 **********************************************************************************************************************/
void R_BSP_ModuleStandbyEnable (bsp_module_standby_t module)
{
#if (1U == BSP_FEATURE_MODULE_STANDBY_IS_AVAILABLE)

    /* Enable clock supply to target module */
    bsp_stbc_set_channel(module, 1U);
#else

    /* The device is not support module standby */
    FSP_PARAMETER_NOT_USED(module);
#endif
}

/*******************************************************************************************************************//**
 * Disable clock supply for input module. Module Standby Register for
 * target module MSR_<module name>.
 *
 * @param[in] module      Module to disable supply clock.
 **********************************************************************************************************************/
void R_BSP_ModuleStandbyDisable (bsp_module_standby_t module)
{
#if (1U == BSP_FEATURE_MODULE_STANDBY_IS_AVAILABLE)

    /* Disable clock supply to target module */
    bsp_stbc_set_channel(module, 0U);
#else

    /* The device is not support module standby */
    FSP_PARAMETER_NOT_USED(module);
#endif
}

/*******************************************************************************************************************//**
 * Disable all Clock supply, preparation for standby
 *
 **********************************************************************************************************************/
void R_BSP_ModuleStandbyDisableAll ()
{
#if (1U == BSP_FEATURE_MODULE_STANDBY_IS_AVAILABLE)
    uint8_t msr_reg_count;
    uint8_t total_msr;
    bool    init_cfg_value;

    /* Get total of g_msr_info_table elements */
    total_msr = sizeof(g_msr_info_table) / sizeof(g_msr_info_table[0]);

    /* Loop all configured Module standby for initialization. Skip the first element BSP_MODULE_STANDBY_START */
    for (msr_reg_count = 0; msr_reg_count < total_msr; msr_reg_count++)
    {
        /* Get Module standby initial configured value of specific module */
        init_cfg_value = g_msr_info_table[msr_reg_count].initial_cfg_value;

        /* If enable Module standby, process to enable clock supply */
        if (init_cfg_value)
        {
            /* Disable clock supply to target module */
            bsp_stbc_set_channel((bsp_module_standby_t) msr_reg_count, 0U);
        }
    }                                  /* Get the MSR module register address */
#else

    /* The device is not support module standby */
#endif
}

/*******************************************************************************************************************//**
 * Enter DeepStop Mode
 *
 * @param[in] wake_src      Wakeup Source.
 **********************************************************************************************************************/
void R_BSP_DeepStopEnable (bsp_wk_factor_cfg_t wake_src)
{
    /* Enable deep stop mode with specified wake-up source using bsp_stbc_deepstop_enable(). */
    bsp_stbc_deepstop_enable(wake_src);
}

/*******************************************************************************************************************//**
 * Get Wake Up Factor in DeepStop Mode
 *
 * @return     Wake Up Factor.
 **********************************************************************************************************************/
bsp_wk_factor_t R_BSP_DeepStopGetWakeUpFactor (void)
{
    /* Get wake-up factor after deep stop using bsp_stbc_deepstop_getwakeupfactor(). */
    return bsp_stbc_deepstop_getwakeupfactor();
}

/*******************************************************************************************************************//**
 * Hold I/O Port State before enter DeepStop
 *
 * @param[in] io_buffer      I/0 Port.
 **********************************************************************************************************************/
void R_BSP_DeepStopIOHold (bsp_io_hold_t io_buffer)
{
    /* Apply IO hold settings during deep stop mode using bsp_stbc_deepstop_iohold(). */
    bsp_stbc_deepstop_iohold(io_buffer);
}

/*******************************************************************************************************************//**
 * Check and return the current chip standby mode
 *
 * @return     The state of chip standby mode.
 **********************************************************************************************************************/
void R_BSP_CheckChipStandByMode (void)
{
    /* Retrieve the current standby mode of the chip using bsp_stbc_getstandbymode()
     * and store the result in the global variable g_chip_standby_mode. */
    g_chip_standby_mode = bsp_stbc_getstandbymode();
}

/*******************************************************************************************************************//**
 * Get the current Chip Stanby Mode
 *
 * @return     The state of chip standby mode.
 **********************************************************************************************************************/
bsp_chip_standby_mode_t R_BSP_GetChipStandByMode (void)
{
    return g_chip_standby_mode;
}

/** @} (end addtogroup BSP_MODULE_STANDBY) */

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/
#if (1U == BSP_FEATURE_MODULE_STANDBY_IS_AVAILABLE)

/*******************************************************************************************************************//**
 * @brief Configures the module setting for a specific STBC module.
 *
 * Enables or disables the specified module for the given STBC module.
 *
 * @param[in] module   Target STBC module to configure.
 * @param[in] enable   Enable (true) or disable (false) the specified module.
 **********************************************************************************************************************/
static void bsp_stbc_set_channel (bsp_module_standby_t module, bool enable)
{
    volatile uint32_t * p_msr_address;
    uint32_t            setting_value;

    /* Get the MSR module register address */
    p_msr_address = (uint32_t *) (g_msr_info_table[module].msr_reg_address);

    /* Enable/Disable clock supply to target module */
    if (enable)
    {
        setting_value = (uint32_t) BSP_PRV_MSR_ENABLE;
    }
    else
    {
        setting_value = (uint32_t) BSP_PRV_MSR_DISABLE;
    }

    /* Write the setting value */
    bsp_stbc_write_with_protection(p_msr_address, setting_value);
}

/*******************************************************************************************************************//**
 * @brief Writes a value to a protected STBC register.
 *
 * Enables write access to the specified STBC register, writes the given value,
 * and then disables write access to ensure register protection.
 *
 * @param[in] p_msr_address  Pointer to the target STBC register address.
 * @param[in] value          Value to be written to the register.
 **********************************************************************************************************************/
static void bsp_stbc_write_with_protection (volatile uint32_t * p_msr_address, uint32_t value)
{
 #if (1U == BSP_FEATURE_STBC_MSRKCPROT)

    /* Enable write access to protected registers */
    R_SYS0_STBC->MSRKCPROT = (uint32_t) BSP_PRV_KEYCODE_ENABLE;

    *p_msr_address = value;

    /* Disable write access to protected registers */
    R_SYS0_STBC->MSRKCPROT = (uint32_t) BSP_PRV_KEYCODE_DISABLE;
 #else
    *p_msr_address = value;
 #endif
}

#endif

/*******************************************************************************************************************//**
 * @brief Enables DeepStop mode with the specified wake-up source configuration.
 *
 * @param[in] wake_src  Configuration for wake-up sources during DeepStop mode.
 **********************************************************************************************************************/
static void bsp_stbc_deepstop_enable (bsp_wk_factor_cfg_t wake_src)
{
    /* Disable Interrupt, Interrupt Flag is cleared in Module */
    __disable_irq();

    /* Clear Wake up Flag */
    R_WUF->WUFC_A1 = BSP_WAKEUP_FACTOR_MASK;
    R_WUF->WUFC_A0 = BSP_WAKEUP_FACTOR_MASK;

    /* Set wake up source for RUN mode */
    R_WUF->WUF0EN_A0 = (uint32_t) wake_src.wk_run;
    R_WUF->WUF0EN_A1 = (uint32_t) (wake_src.wk_run >> BSP_WAKEUP_FACTOR_SHIFT_WORD);

    /* Set wake up source for Cyclic mode */
    R_WUF->WUF1EN_A0 = (uint32_t) wake_src.wk_cyclic;
    R_WUF->WUF1EN_A1 = (uint32_t) (wake_src.wk_cyclic >> BSP_WAKEUP_FACTOR_SHIFT_WORD);

    if (BSP_CYCLICRUN_MODE != R_BSP_GetChipStandByMode())
    {
        bsp_clock_gear_down();
    }

    /* Reset Wake Up Factor Flag */
    R_SYS0_A_RESET->RESFC = BSP_RESET_FLAG_MASK;

    /* Transition to DeepStop */
    R_SYS0_STBC->STBCKCPROT = BSP_PRV_KEYCODE_ENABLE;

    R_SYS0_A_STBC->STBC0PSC = R_SYS0_A_STBC_STBC0PSC_STBC0DISTRG_Msk;
    R_SYS0_STBC->STBCKCPROT = BSP_PRV_KEYCODE_DISABLE;

    /* Setting the sleep deep bit */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __WFI();
}

/*******************************************************************************************************************//**
 * @brief Retrieves the wake-up factor that caused exit from DeepStop mode.
 *
 * @return Wake-up factor indicating the source of wake-up.
 **********************************************************************************************************************/
static bsp_wk_factor_t bsp_stbc_deepstop_getwakeupfactor (void)
{
    if (BSP_RESET_SRC_DEEPSTOP == R_SYS0_A_RESET->RESF)
    {
        bsp_wk_factor_t wuf_a0 = (bsp_wk_factor_t) R_WUF->WUF_A0;
        bsp_wk_factor_t wuf_a1 = (bsp_wk_factor_t) R_WUF->WUF_A1;

        return (bsp_wk_factor_t) (wuf_a0 | (wuf_a1 << BSP_WAKEUP_FACTOR_SHIFT_WORD));
    }
    else
    {
        return (bsp_wk_factor_t) 0;
    }
}

/*******************************************************************************************************************//**
 * @brief Holds I/O port state before entering DeepStop mode.
 *
 * @param[in] io_buffer  I/O port configuration to retain during DeepStop.
 **********************************************************************************************************************/
static void bsp_stbc_deepstop_iohold (bsp_io_hold_t io_buffer)
{
    R_SYS0_STBC->STBCKCPROT = BSP_PRV_KEYCODE_ENABLE;
    R_SYS0_A_STBC->IOHOLD0  = (uint32_t) io_buffer;
    R_SYS0_A_STBC->IOHOLD2  = (uint32_t) (io_buffer >> BSP_WAKEUP_FACTOR_SHIFT_WORD);
    R_SYS0_STBC->STBCKCPROT = BSP_PRV_KEYCODE_DISABLE;
}

/*******************************************************************************************************************//**
 * @brief Checks and returns the current standby mode of the chip.
 *
 * @return Current chip standby mode.
 **********************************************************************************************************************/
static bsp_chip_standby_mode_t bsp_stbc_getstandbymode (void)
{
    /* Check Reset Factor Register and Compare the Wake-up Factor */
    uint32_t reset_source = R_SYS0_A_RESET->RESF;
    uint32_t wuf_a0       = R_WUF->WUF_A0;
    uint32_t wuf1en_a0    = R_WUF->WUF1EN_A0;
    uint32_t wuf_a1       = R_WUF->WUF_A1;
    uint32_t wuf1en_a1    = R_WUF->WUF1EN_A1;

    if ((BSP_RESET_SRC_DEEPSTOP == reset_source) && \
        ((wuf_a0 & wuf1en_a0) || (wuf_a1 & wuf1en_a1)))
    {
        /* The current mode is cyclicRUN mode */
        return BSP_CYCLICRUN_MODE;
    }
    else
    {
        return BSP_RUN_MODE;
    }
}
