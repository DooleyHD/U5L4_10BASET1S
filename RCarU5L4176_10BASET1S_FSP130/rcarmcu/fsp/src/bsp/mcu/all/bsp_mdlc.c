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
#define BSP_MDLC_DISABLE_BIT          (0U)
#define BSP_MDLC_CLOCK_SUPPLY         (0U)
#define BSP_MDLC_CLOCK_STOP           (1U)
#define BSP_MDLC_KEY_CODE_ENABLE      (0xA5A5A501U)
#define BSP_MDLC_KEY_CODE_DISABLE     (0xA5A5A500U)
#define BSP_MDLC_LOWER_NIBBLE_MASK    (0x0FU)
#define BSP_MDLC_MSRESS_BIT_MASK      (2U)
#define BSP_MDLC_STAC_BIT_MASK        (2U)
#define BSP_MDLC_PRV_DIV16(x)       ((x) >> 4)
#define BSP_MDLC_PRV_REMAIN16(x)    ((x) & (0x0FU))

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MDLC
 *
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enable supports clock supply control/reset control of modules in this device.
 *
 * @param[in] module      Module to be controller.
 * @param[in] state       Target state of the module.
 *
 * @retval FSP_SUCCESS                    The state transition was successful.
 * @retval FSP_ERR_ASSERTION              An unintended reset is occurring.
 * @retval FSP_ERR_UNSUPPORTED            Device is not support this feature.
 *
 * @note When transitioning from Module Standby to Module RUN, or vice versa, always go through Module Reset.
 **********************************************************************************************************************/
fsp_err_t R_BSP_MDLC_StateTransition (bsp_mdlc_module_t module, bsp_mdlc_state_t state)
{
#if (1U == BSP_FEATURE_MDLC_IS_AVAILABLE) && (0U == BSP_VLAB_HARDWARE_BASED_USED)
    fsp_err_t err = FSP_SUCCESS;

    /* Extract MDLC instance (SYS0 / SYSA) */
    uint8_t mdlc_instance = (uint8_t) (module / BSP_MDLC_NUM_OF_MODULE_IN_GROUP);

    /* Module index in the group */
    uint16_t module_group_index = 0;

    /* Index of register (each register controls 16 modules) */
    uint8_t reg_index = 0U;

    /* Each module occupies 2 bits in register */
    uint8_t bit_shift = (uint8_t) (BSP_MDLC_PRV_REMAIN16(module) << 1U);

    /* Mask for 2-bit state field */
    uint32_t state_mask = (uint32_t) (0x03U << bit_shift);

    uint32_t msres_value  = 0;
    uint32_t msress_value = 0;

    /* Select MDLC register base */
    R_SYS0_MDLC_Type * p_reg = (R_SYS0_MDLC_Type *) R_SYS0_MDLC;

    if (1U == mdlc_instance)
    {
        p_reg              = (R_SYS0_MDLC_Type *) R_SYS0_A_MDLC;
        module_group_index = (uint16_t) (module - BSP_MDLC_NUM_OF_MODULE_IN_GROUP);
        reg_index          = (uint8_t) BSP_MDLC_PRV_DIV16(module_group_index);
    }
    else
    {
        reg_index = (uint8_t) BSP_MDLC_PRV_DIV16(module);
    }

    /* Unlock protected register */
    p_reg->MDLC0KCPROT0 = BSP_MDLC_KEY_CODE_ENABLE;

    /* Clock control (MSR) */
    if (BSP_MDLC_CLOCK_STOP == p_reg->MDLC_MSR_b[reg_index].MS)
    {
        p_reg->MDLC_MSR_b[reg_index].MS = BSP_MDLC_CLOCK_SUPPLY;
    }

    /* Update module state */
    msres_value  = p_reg->MDLC_MSRES[reg_index];
    msres_value &= ~(state_mask);
    msres_value |= (uint32_t) (state << bit_shift);
    p_reg->MDLC_MSRES[reg_index] = msres_value;

    /* Wait until state transition is applied */
    do
    {
        msres_value  = p_reg->MDLC_MSRES[reg_index] & state_mask;
        msress_value = p_reg->MDLC_MSRESS[reg_index] & state_mask;
    } while (msres_value != msress_value);

    /* Lock protected register */
    p_reg->MDLC0KCPROT0 = BSP_MDLC_KEY_CODE_DISABLE;

    return err;
#else
    FSP_PARAMETER_NOT_USED(module);
    FSP_PARAMETER_NOT_USED(state);

    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * This function get the state of target module.
 *
 * @param[in]  module     Module to be controller.
 * @param[out] p_state    Pointer to store current state.
 *
 * @retval FSP_SUCCESS                    The get state was successful.
 * @retval FSP_ERR_UNSUPPORTED            Device is not support this feature
 **********************************************************************************************************************/
fsp_err_t R_BSP_MDLC_StateGet (bsp_mdlc_module_t module, bsp_mdlc_state_t * p_state)
{
#if (1U == BSP_FEATURE_MDLC_IS_AVAILABLE) && (0U == BSP_VLAB_HARDWARE_BASED_USED)

    /* Extract MDLC instance (SYS0 / SYSA) */
    uint8_t mdlc_instance = (uint8_t) (module / BSP_MDLC_NUM_OF_MODULE_IN_GROUP);

    /* Module index in the group */
    uint16_t module_group_index = 0;

    /* Index of register (each register controls 16 modules) */
    uint8_t reg_index = 0U;

    /* Each module occupies 2 bits in register */
    uint8_t bit_shift = (uint8_t) (BSP_MDLC_PRV_REMAIN16(module) << 1U);

    /* Select MDLC register base */
    R_SYS0_MDLC_Type * p_reg = (R_SYS0_MDLC_Type *) R_SYS0_MDLC;
    if (1U == mdlc_instance)
    {
        p_reg              = (R_SYS0_MDLC_Type *) R_SYS0_A_MDLC;
        module_group_index = (uint16_t) (module - BSP_MDLC_NUM_OF_MODULE_IN_GROUP);
        reg_index          = (uint8_t) BSP_MDLC_PRV_DIV16(module_group_index);
    }
    else
    {
        reg_index = (uint8_t) BSP_MDLC_PRV_DIV16(module);
    }

    *p_state = (bsp_mdlc_state_t) ((p_reg->MDLC_MSRESS[reg_index] >> bit_shift) & BSP_MDLC_MSRESS_BIT_MASK);

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(module);
    FSP_PARAMETER_NOT_USED(p_state);

    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * Start FuSa Reset acknowledge of modules in this device.
 *
 * @param[in] module      Module to be controlled.
 *
 * @retval FSP_SUCCESS                    The reset ack start was successful.
 * @retval FSP_ERR_UNSUPPORTED            Device is not support this feature
 **********************************************************************************************************************/
fsp_err_t R_BSP_MDLC_ResetAckStart (bsp_mdlc_module_t module)
{
#if (1U == BSP_FEATURE_MDLC_IS_AVAILABLE) && (0U == BSP_VLAB_HARDWARE_BASED_USED)

    /* Extract MDLC instance (SYS0 / SYSA) */
    uint8_t mdlc_instance = (uint8_t) (module / BSP_MDLC_NUM_OF_MODULE_IN_GROUP);

    /* Module index in the group */
    uint16_t module_group_index = 0;

    /* Index of register (each register controls 16 modules) */
    uint8_t reg_index = 0U;

    /* FuSa reset acknowledge bit position (1 bit per module) */
    uint8_t reset_ack_bit_shift = (uint8_t) (BSP_MDLC_PRV_REMAIN16(module));

    /* Mask for reset acknowledge */
    uint32_t reset_ack_mask = (uint32_t) (0x01U << reset_ack_bit_shift);

    /* Select MDLC register base */
    R_SYS0_MDLC_Type * p_reg = (R_SYS0_MDLC_Type *) R_SYS0_MDLC;
    if (1U == mdlc_instance)
    {
        p_reg              = (R_SYS0_MDLC_Type *) R_SYS0_A_MDLC;
        module_group_index = (uint16_t) (module - BSP_MDLC_NUM_OF_MODULE_IN_GROUP);
        reg_index          = (uint8_t) BSP_MDLC_PRV_DIV16(module_group_index);
    }
    else
    {
        reg_index = (uint8_t) BSP_MDLC_PRV_DIV16(module);
    }

    while (((p_reg->MDLC_FSRCHKRA[reg_index] & reset_ack_mask) != reset_ack_mask) ||
           ((p_reg->MDLC_FSRCHKRB[reg_index] & reset_ack_mask) != reset_ack_mask))
    {
        /* Enable reset check */
        p_reg->MDLC_FSRCHKSETR[reg_index] |= reset_ack_mask;
    }

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(module);

    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * Check the FuSa Reset acknowledge of modules in this device.
 *
 * @param[in] module       Module to be controlled.
 * @param[out] p_result    Pointer to store current result reset acknowledge.
 *
 * @retval FSP_SUCCESS                    The reset ack check was successful.
 * @retval FSP_ERR_UNSUPPORTED            Device is not support this feature
 **********************************************************************************************************************/
fsp_err_t R_BSP_MDLC_ResetAckCheck (bsp_mdlc_module_t module, bsp_mdlc_reset_ack_t * p_result)
{
#if (1U == BSP_FEATURE_MDLC_IS_AVAILABLE) && (0U == BSP_VLAB_HARDWARE_BASED_USED)

    /* Extract MDLC instance (SYS0 / SYSA) */
    uint8_t mdlc_instance = (uint8_t) (module / BSP_MDLC_NUM_OF_MODULE_IN_GROUP);

    /* Module index in the group */
    uint16_t module_group_index = 0;

    /* Index of register (each register controls 16 modules) */
    uint8_t reg_index = 0U;

    /* FuSa reset acknowledge bit position (1 bit per module) */
    uint8_t reset_ack_bit_shift = (uint8_t) (BSP_MDLC_PRV_REMAIN16(module));

    /* Mask for reset acknowledge */
    uint32_t reset_ack_mask = (uint32_t) (0x01U << reset_ack_bit_shift);

    /* Select MDLC register base */
    R_SYS0_MDLC_Type * p_reg = (R_SYS0_MDLC_Type *) R_SYS0_MDLC;
    if (1U == mdlc_instance)
    {
        p_reg              = (R_SYS0_MDLC_Type *) R_SYS0_A_MDLC;
        module_group_index = (uint8_t) (module - BSP_MDLC_NUM_OF_MODULE_IN_GROUP);
        reg_index          = (uint8_t) BSP_MDLC_PRV_DIV16(module_group_index);
    }
    else
    {
        reg_index = (uint8_t) BSP_MDLC_PRV_DIV16(module);
    }

    if ((reset_ack_mask == (p_reg->MDLC_FSRCHKRA[reg_index] & reset_ack_mask)) &&
        (reset_ack_mask == (p_reg->MDLC_FSRCHKRB[reg_index] & reset_ack_mask)))
    {
        *p_result = BSP_MDLC_RESET_ACK_NOT_DETECTED;
    }
    else if ((BSP_MDLC_DISABLE_BIT == (p_reg->MDLC_FSRCHKRA[reg_index] & reset_ack_mask)) &&
             (BSP_MDLC_DISABLE_BIT == (p_reg->MDLC_FSRCHKRB[reg_index] & reset_ack_mask)))
    {
        *p_result = BSP_MDLC_RESET_ACK_DETECTED;
    }
    else
    {
        *p_result = BSP_MDLC_RESET_ACK_MONITOR_FAULT;
    }

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(module);
    FSP_PARAMETER_NOT_USED(p_result);

    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * Stop FuSa Reset acknowledge of modules in this device.
 *
 * @param[in] module      Module to be controlled.
 *
 * @retval FSP_SUCCESS                    The reset ack stop was successful.
 * @retval FSP_ERR_UNSUPPORTED            Device is not support this feature
 **********************************************************************************************************************/
fsp_err_t R_BSP_MDLC_ResetAckStop (bsp_mdlc_module_t module)
{
#if (1U == BSP_FEATURE_MDLC_IS_AVAILABLE) && (0U == BSP_VLAB_HARDWARE_BASED_USED)

    /* Extract MDLC instance (SYS0 / SYSA) */
    uint8_t mdlc_instance = (uint8_t) (module / BSP_MDLC_NUM_OF_MODULE_IN_GROUP);

    /* Module index in the group */
    uint16_t module_group_index = 0;

    /* Index of register (each register controls 16 modules) */
    uint8_t reg_index = 0U;

    /* FuSa reset acknowledge bit position (1 bit per module) */
    uint8_t reset_ack_bit_shift = (uint8_t) (BSP_MDLC_PRV_REMAIN16(module));

    /* Mask for reset acknowledge */
    uint32_t reset_ack_mask = (uint32_t) (0x01U << reset_ack_bit_shift);

    /* Select MDLC register base */
    R_SYS0_MDLC_Type * p_reg = (R_SYS0_MDLC_Type *) R_SYS0_MDLC;
    if (1U == mdlc_instance)
    {
        p_reg              = (R_SYS0_MDLC_Type *) R_SYS0_A_MDLC;
        module_group_index = (uint8_t) (module - BSP_MDLC_NUM_OF_MODULE_IN_GROUP);
        reg_index          = (uint8_t) BSP_MDLC_PRV_DIV16(module_group_index);
    }
    else
    {
        reg_index = (uint8_t) BSP_MDLC_PRV_DIV16(module);
    }

    /* Clear the register Module Reset Check A/B */
    p_reg->MDLC_FSRCHKCLRR[reg_index] |= reset_ack_mask;

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(module);

    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * Configure RAM initialization behavior for the specified module when recovering from Module Reset state.
 *
 * @param[in] module      Target module for RAM initialization control.
 * @param[in] mode        RAM initialization mode (disable, prohibit, or enable).
 *
 * @retval FSP_SUCCESS                    The ram mode set was successful.
 * @retval FSP_ERR_UNSUPPORTED            Device is not support this feature
 **********************************************************************************************************************/
fsp_err_t R_BSP_MDLC_RamModeSet (bsp_mdlc_ram_init_module_t module, bsp_mdlc_ram_init_mode_t mode)
{
#if (1U == BSP_FEATURE_MDLC_IS_AVAILABLE) && (0U == BSP_VLAB_HARDWARE_BASED_USED)

    /* Index of register (each register controls 16 modules) */
    uint8_t reg_index = (uint8_t) BSP_MDLC_PRV_DIV16(module);

    /* Each module occupies 2 bits in register */
    uint8_t bit_shift = (uint8_t) (BSP_MDLC_PRV_REMAIN16(module) << 1U);

    /* Select MDLC register base */
    R_SYS0_MDLC_Type * p_reg = (R_SYS0_MDLC_Type *) R_SYS0_MDLC;

    /* Clear mode ram initialization of module */
    p_reg->MDLC_STAC[reg_index] &= ~(3U << bit_shift);

    /* Update module mode ram initialization */
    p_reg->MDLC_STAC[reg_index] |= (uint32_t) (mode << bit_shift);

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(module);
    FSP_PARAMETER_NOT_USED(mode);

    return FSP_ERR_UNSUPPORTED;
#endif
}

/*******************************************************************************************************************//**
 * This function get the overall mode of target module for RAM initialization control.
 *
 * @param[in]  module      Target module for RAM initialization control.
 * @param[out] p_mode      Pointer to store current mode.
 *
 * @retval FSP_SUCCESS                    The get ram mode was successful.
 * @retval FSP_ERR_UNSUPPORTED            Device is not support this feature
 **********************************************************************************************************************/
fsp_err_t R_BSP_MDLC_RamModeGet (bsp_mdlc_ram_init_module_t module, bsp_mdlc_ram_init_mode_t * p_mode)
{
#if (1U == BSP_FEATURE_MDLC_IS_AVAILABLE) && (0U == BSP_VLAB_HARDWARE_BASED_USED)

    /* Index of register (each register controls 16 modules) */
    uint8_t reg_index = (uint8_t) BSP_MDLC_PRV_DIV16(module);

    /* Each module occupies 2 bits in register */
    uint8_t bit_shift = (uint8_t) (BSP_MDLC_PRV_REMAIN16(module) << 1U);

    /* Select MDLC register base */
    R_SYS0_MDLC_Type * p_reg = (R_SYS0_MDLC_Type *) R_SYS0_MDLC;

    /* Update module mode ram initialization */
    *p_mode = (bsp_mdlc_ram_init_mode_t) ((p_reg->MDLC_STAC[reg_index] >> bit_shift) & BSP_MDLC_STAC_BIT_MASK);

    return FSP_SUCCESS;
#else
    FSP_PARAMETER_NOT_USED(module);
    FSP_PARAMETER_NOT_USED(p_mode);

    return FSP_ERR_UNSUPPORTED;
#endif
}

/** @} (end addtogroup BSP_MDLC) */
