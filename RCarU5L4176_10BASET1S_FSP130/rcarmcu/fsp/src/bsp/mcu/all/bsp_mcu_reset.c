/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_mcu_reset.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define BSP_RESET_FLAG_MASK           (0x80DDU)    // Mask for all reset flags
#define BSP_RESET_KEYCODE_DISABLE     (0xA5A5A500) // Key code protection disable value
#define BSP_RESET_KEYCODE_ENABLE      (0xA5A5A501) // Key code protection enable value
#define BSP_RESET_RESKCPROT0_RESET    (0x00000000) // RESKCPROT0 register reset value
#define BSP_RESET_MAX_FACTOR          (0x7)        // Maximum number of reset causes

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/* BSP reset table information */
static const bsp_reset_table_t reset_table[] =
{
    {0,  BSP_RESET_POWER_ON},          ///< Highest priority
    {2,  BSP_RESET_EXTERNAL},
    {3,  BSP_RESET_VMON    },
    {6,  BSP_RESET_ECM     },
    {7,  BSP_RESET_WDT     },
    {4,  BSP_RESET_SW      },
    {15, BSP_RESET_DEEPSTOP},          ///< Lowest priority
};

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RESET
 *
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Retrieves the reset source flags from the reset status register.
 *
 * This function reads the RESF register to determine the source of the last reset.
 *
 * @return bsp_reset_t The reset source flags. Possible values:
 * - BSP_RESET_POWER_ON: Power-on reset.
 * - BSP_RESET_EXTERNAL: External reset.
 * - BSP_RESET_VMON: Voltage monitor reset.
 * - BSP_RESET_ECM: ECM system reset.
 * - BSP_RESET_WDT: Watchdog timer reset.
 * - BSP_RESET_SW: Software system reset.
 * - BSP_RESET_DEEPSTOP: DeepSTOP reset.
 * - BSP_DO_NOT_RESET: No reset flags set.
 **********************************************************************************************************************/
bsp_reset_t R_BSP_McuResetGetFlags (void)
{
    uint32_t resf = R_SYS0_A_RESET->RESF;

    for (uint8_t i = 0; i < BSP_RESET_MAX_FACTOR; i++)
    {
        if (resf & (1U << reset_table[i].bit))
        {
            return reset_table[i].flag;
        }
    }

    return BSP_DO_NOT_RESET;
}

/*******************************************************************************************************************//**
 * Clears the reset flags in the reset status register.
 *
 * This function writes to the RESFC register to clear all reset flags.
 **********************************************************************************************************************/
void R_BSP_McuResetClearFlags (void)
{
    /* Clear all reset flags */
    R_SYS0_A_RESET->RESFC = BSP_RESET_FLAG_MASK;
}

/*******************************************************************************************************************//**
 * Performs a software reset of the MCU.
 *
 * This function enables write access to protected registers, triggers a software reset, and then disables write access.
 **********************************************************************************************************************/
void R_BSP_McuSoftwareSystemReset (void)
{
    /* Enable write access to protected registers */
    R_SYS0_RESET->RESKCPROT0 = BSP_RESET_KEYCODE_ENABLE;

    /* Trigger software reset */
    R_SYS0_A_RESET->SWSRESA = R_SYS0_A_RESET_SWSRESA_SWSRESA_Msk;

    /* Disable write access to protected registers */
    R_SYS0_RESET->RESKCPROT0 = BSP_RESET_KEYCODE_DISABLE;

    /* Confirm that RESKCPROT0 register is written 0x00000000 successfully */
    FSP_HARDWARE_REGISTER_WAIT(R_SYS0_RESET->RESKCPROT0, BSP_RESET_RESKCPROT0_RESET);
}

/** @} (end addtogroup BSP_MCU_RESET) */

/***********************************************************************************************************************
 * Private functions
 **********************************************************************************************************************/
