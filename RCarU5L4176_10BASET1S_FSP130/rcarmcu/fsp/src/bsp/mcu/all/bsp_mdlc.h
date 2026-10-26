/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MDLC_H
#define BSP_MDLC_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_mdlc_driver.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @ingroup BSP_MCU
 * @defgroup BSP_MDLC BSP Module Controller
 *
 * @brief Provide the API for module controller (MDLC).
 *
 * @section MDLC_SUMMARY Summary
 * MDLC controls the operation state of modules in the device, including clock supply,
 * reset control, and RAM initialization behavior.
 * The module conntroller (MDLC) supports the following features:
 * - Control module states: RUN, STOP, STANDBY, and RESET
 * - Clock supply control (enable/disable module clock)
 * - Module reset control (assert/release reset per module)
 * - RAM initialization control on reset recovery (via RZEROMD)
 * - Reset acknowledge check support for Functional Safety (FuSa)
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Module controller state */
typedef enum e_bsp_mdlc_state
{
    BSP_MDLC_STATE_STANDBY = 0,        ///< State standby
    BSP_MDLC_STATE_RESET,              ///< State reset
    BSP_MDLC_STATE_STOP,               ///< State stop
    BSP_MDLC_STATE_RUN,                ///< State run
} bsp_mdlc_state_t;

/** Module controller ram initialization target module */
typedef enum e_bsp_mdlc_ram_init_mode
{
    BSP_MDLC_RAM_INIT_MODE_DISABLE  = 0, ///< Do not perform RAM initialization after module reset (RAM content is retained)
    BSP_MDLC_RAM_INIT_MODE_PROHIBIT = 1, ///< Prohibit RAM initialization (FuSa restriction, prevents unintended clearing)
    BSP_MDLC_RAM_INIT_MODE_ENABLE   = 3, ///< Perform RAM initialization (clear RAM) when recovering from module reset
} bsp_mdlc_ram_init_mode_t;

/** Module controller reset acknowledge type */
typedef enum e_bsp_mdlc_reset_ack
{
    BSP_MDLC_RESET_ACK_NOT_DETECTED = 0, ///< Reset is not detected
    BSP_MDLC_RESET_ACK_DETECTED,         ///< Reset is correctly detected
    BSP_MDLC_RESET_ACK_MONITOR_FAULT,    ///< Reset monitor register abnormal
} bsp_mdlc_reset_ack_t;

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

fsp_err_t R_BSP_MDLC_StateTransition(bsp_mdlc_module_t module, bsp_mdlc_state_t state);
fsp_err_t R_BSP_MDLC_StateGet(bsp_mdlc_module_t module, bsp_mdlc_state_t * p_state);
fsp_err_t R_BSP_MDLC_RamModeSet(bsp_mdlc_ram_init_module_t module, bsp_mdlc_ram_init_mode_t mode);
fsp_err_t R_BSP_MDLC_RamModeGet(bsp_mdlc_ram_init_module_t module, bsp_mdlc_ram_init_mode_t * p_mode);
fsp_err_t R_BSP_MDLC_ResetAckStart(bsp_mdlc_module_t module);
fsp_err_t R_BSP_MDLC_ResetAckCheck(bsp_mdlc_module_t module, bsp_mdlc_reset_ack_t * p_result);
fsp_err_t R_BSP_MDLC_ResetAckStop(bsp_mdlc_module_t module);

/** @} (end defgroup BSP_MDLC) */

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif                                 /* BSP_MDLC_H */
