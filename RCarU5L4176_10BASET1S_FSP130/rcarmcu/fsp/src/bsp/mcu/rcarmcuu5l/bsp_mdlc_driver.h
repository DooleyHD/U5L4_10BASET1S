/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MDLC_DRIVER_H
#define BSP_MDLC_DRIVER_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RCARMCUU5L
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Module Controller Target Module. Device U5L does not support module controller */
typedef enum e_bsp_mdlc_module
{
    BSP_MDLC_MODULE_NONE = 0,
} bsp_mdlc_module_t;

/** Module controller ram initialization target module. Device U5L does not support module controller */
typedef enum e_bsp_mdlc_ram_init_module
{
    BSP_MDLC_RAM_INIT_MODULE_NONE = 0,
} bsp_mdlc_ram_init_module_t;

/***********************************************************************************************************************
 * Exported global variable (to be accessed by other files)
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RCARMCUU5L) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif                                 /* BSP_MDLC_DRIVER_H */
