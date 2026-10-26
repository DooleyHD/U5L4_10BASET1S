/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
#ifndef BSP_MCU_RESET_H
#define BSP_MCU_RESET_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include "bsp_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_MCU_RESET BSP MCU Reset
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Reset flag information */
typedef enum e_bsp_reset
{
    BSP_RESET_POWER_ON,                ///< Power On SYS0_RESET Flag
    BSP_RESET_EXTERNAL,                ///< External SYS0_RESET Flag
    BSP_RESET_VMON,                    ///< VMON SYS0_RESET Flag
    BSP_RESET_ECM,                     ///< ECM System SYS0_RESET Flag
    BSP_RESET_WDT,                     ///< WDTBA SYS0_RESET Flag
    BSP_RESET_SW,                      ///< Software System SYS0_RESET 2 Flag
    BSP_RESET_DEEPSTOP,                ///< DeepSTOP SYS0_RESET Flag
    BSP_DO_NOT_RESET,                  ///< Do not have reset
} bsp_reset_t;

/* Reset table information*/
typedef struct st_bsp_reset_table
{
    uint8_t     bit;                   ///< Bit position of the reset flag in the RESF register
    bsp_reset_t flag;                  ///< Corresponding reset flag
} bsp_reset_table_t;

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** Function declarations */
bsp_reset_t R_BSP_McuResetGetFlags(void);
void        R_BSP_McuResetClearFlags(void);
void        R_BSP_McuSoftwareSystemReset(void);

/** @} (end defgroup BSP_MCU_RESET) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
