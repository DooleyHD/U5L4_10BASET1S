/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_GUARD_H
#define BSP_GUARD_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_guard_driver.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_GUARD BSP Guard Protection
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Indicate PBG channel bit.*/
typedef enum e_bsp_pbg_channel
{
    BSP_PBG_CHANNEL_00 = (1U << 0),    ///< Bit mask for PBG channel 00
    BSP_PBG_CHANNEL_01 = (1U << 1),    ///< Bit mask for PBG channel 01
    BSP_PBG_CHANNEL_02 = (1U << 2),    ///< Bit mask for PBG channel 02
    BSP_PBG_CHANNEL_03 = (1U << 3),    ///< Bit mask for PBG channel 03
    BSP_PBG_CHANNEL_04 = (1U << 4),    ///< Bit mask for PBG channel 04
    BSP_PBG_CHANNEL_05 = (1U << 5),    ///< Bit mask for PBG channel 05
    BSP_PBG_CHANNEL_06 = (1U << 6),    ///< Bit mask for PBG channel 06
    BSP_PBG_CHANNEL_07 = (1U << 7),    ///< Bit mask for PBG channel 07
    BSP_PBG_CHANNEL_08 = (1U << 8),    ///< Bit mask for PBG channel 08
    BSP_PBG_CHANNEL_09 = (1U << 9),    ///< Bit mask for PBG channel 09
    BSP_PBG_CHANNEL_10 = (1U << 10),   ///< Bit mask for PBG channel 10
    BSP_PBG_CHANNEL_11 = (1U << 11),   ///< Bit mask for PBG channel 11
    BSP_PBG_CHANNEL_12 = (1U << 12),   ///< Bit mask for PBG channel 12
    BSP_PBG_CHANNEL_13 = (1U << 13),   ///< Bit mask for PBG channel 13
    BSP_PBG_CHANNEL_14 = (1U << 14),   // < Bit mask for PBG channel 14
    BSP_PBG_CHANNEL_15 = (1U << 15),   ///< Bit mask for PBG channel 15
} bsp_pbg_channel_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

void R_BSP_GuardEnableAccessAll(void);
void R_BSP_GuardAccessEnable(const bsp_pbg_group_t pbg_group, const bsp_pbg_channel_t pbg_channels);
void R_BSP_GuardAccessDisable(const bsp_pbg_group_t pbg_group, const bsp_pbg_channel_t pbg_channels);
void R_BSP_RamGuardProtectionSetting(bsp_xram_memory_type_t           memory_type,
                                     bsp_xram_entry_number_t          entry_channel_number,
                                     bsp_channel_protection_control_t channel_protection_control);
void R_BSP_RamGuardProtectionStatus(bsp_xram_memory_type_t memory_type, bsp_xram_protection_status_t * status);
void R_BSP_IBG_ProtectionSetting(bsp_ibg_group_t igb_channel, uint16_t channels, bool guard_setting);

/** @} (end defgroup BSP_GUARD) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /** End of BSP_GUARD_H */
