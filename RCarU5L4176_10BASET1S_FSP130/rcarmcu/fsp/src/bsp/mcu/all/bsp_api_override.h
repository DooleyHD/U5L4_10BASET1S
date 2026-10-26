/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU
 * @{
 **********************************************************************************************************************/

#ifndef BSP_API_OVERRIDE_H_
#define BSP_API_OVERRIDE_H_

/* BSP Common Includes. */
#include "../../src/bsp/mcu/all/bsp_common.h"

/* BSP MCU Specific Includes. */
#include "../../src/bsp/mcu/all/bsp_guard.h"
#include "../../src/bsp/mcu/all/bsp_irq.h"
#include "../../src/bsp/mcu/all/bsp_io.h"
#include "../../src/bsp/mcu/all/bsp_group_irq.h"
#include "../../src/bsp/mcu/all/bsp_clocks.h"
#include "../../src/bsp/mcu/all/bsp_module_standby.h"
#include "../../src/bsp/mcu/all/bsp_mdlc.h"
#include "../../src/bsp/mcu/all/bsp_mcu_reset.h"
#include "../../src/bsp/mcu/all/bsp_mpu.h"
#include "../../src/bsp/mcu/all/bsp_cpu.h"

/* Factory MCU information. */
#include "../../inc/fsp_features.h"

/* BSP Common Includes (Other than bsp_common.h) */
#include "../../src/bsp/mcu/all/bsp_delay.h"
#include "../../src/bsp/mcu/all/bsp_mcu_api.h"

#endif                                 /* BSP_API_OVERRIDE_H_ */

/** @} (end addtogroup BSP_MCU) */
