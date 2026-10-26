/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MODULE_STANDBY_H
#define BSP_MODULE_STANDBY_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_module_standby_driver.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_MODULE_STANDBY BSP Module Standby
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** DeepStop Transition */
typedef enum e_bsp_deepstop_wake
{
    BSP_DEEPSTOP_WAKE_TO_RUNMODE = 0U,
    BSP_DEEPSTOP_WAKE_TO_CYCLIC  = 1U,
} bsp_deepstop_wake_t;

/** Chip Standby Mode */
typedef enum e_bsp_chip_standby_mode
{
    BSP_RUN_MODE       = 0U,
    BSP_CYCLICRUN_MODE = 1U
} bsp_chip_standby_mode_t;

/* Assign Wake-up Factor for Run Mode and Cyclic Mode */
typedef struct st_bsp_wk_factor_cfg
{
    bsp_wk_factor_t wk_run;            ///< Wake up Factors for RUN Mode
    bsp_wk_factor_t wk_cyclic;         ///< Wake up Factors for Cyclic Mode
} bsp_wk_factor_cfg_t;

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

void                    R_BSP_ModuleStandbyEnableAll(void);
void                    R_BSP_ModuleStandbyEnable(bsp_module_standby_t module);
void                    R_BSP_ModuleStandbyDisable(bsp_module_standby_t module);
void                    R_BSP_ModuleStandbyDisableAll(void);
void                    R_BSP_DeepStopEnable(bsp_wk_factor_cfg_t wake_src);
void                    R_BSP_DeepStopIOHold(bsp_io_hold_t io_buffer);
bsp_wk_factor_t         R_BSP_DeepStopGetWakeUpFactor(void);
void                    R_BSP_CheckChipStandByMode(void);
bsp_chip_standby_mode_t R_BSP_GetChipStandByMode(void);

/** @} (end defgroup BSP_MODULE_STANDBY) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif                                 /* BSP_MODULE_STANDBY_H */
