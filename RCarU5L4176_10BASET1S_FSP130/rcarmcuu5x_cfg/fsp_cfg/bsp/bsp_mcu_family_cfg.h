/* generated configuration header file - do not edit */
#ifndef BSP_MCU_FAMILY_CFG_H_
#define BSP_MCU_FAMILY_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "bsp_mcu_device_pn_cfg.h"
#include "bsp_mcu_device_cfg.h"
#include "../../../rcarmcu/fsp/src/bsp/mcu/rcarmcuu5l/bsp_mcu_info.h"
#include "../../../rcarmcu/fsp/src/bsp/mcu/rcarmcuu5l/bsp_override.h"
#include "bsp_clock_cfg.h"
#define BSP_MCU_GROUP_RCARU5LX       (1)

#define BSP_CORTEX_VECTOR_TABLE_ENTRIES    (16U)

/* Define the macros related to Interrupt */
#define BSP_CORTEX_VECTOR_TABLE_ENTRIES     (16U)
#define BSP_VECTOR_TABLE_MAX_ENTRIES        (213U)
#define BSP_VECTOR_IRQ_NUM_MAX_ENTRIES      (425U)

/* U5L cache Settings */
#define BSP_CFG_CPU_CORE_INSTRUCTION_CACHE          (1U)

#ifdef __cplusplus
}
#endif
#endif /* BSP_MCU_FAMILY_CFG_H_ */
