/* generated configuration header file - do not edit */
#ifndef BSP_CFG_H_
#define BSP_CFG_H_
#ifdef __cplusplus
            extern "C" {
            #endif

#include "bsp_clock_cfg.h"
#include "bsp_mcu_family_cfg.h"

#if defined(BSP_MCU_GROUP_RCARU5LX)
             #include "bsp_mcu_cpu_memory_cfg.h"
            #endif

#include "bsp_memory_cfg.h"
#include "board_cfg.h"
#define BSP_API_OVERRIDE                 "bsp_api_override.h"
#define FSP_NOT_DEFINED 0
#ifndef BSP_CFG_RTOS
#if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)
              #define BSP_CFG_RTOS (2)
             #elif (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)
              #define BSP_CFG_RTOS (1)
             #else
#define BSP_CFG_RTOS (0)
#endif
#endif
#undef FSP_NOT_DEFINED
#if defined(_RA_BOOT_IMAGE)
             #define BSP_CFG_BOOT_IMAGE (1)
            #endif
#define BSP_CFG_MCU_VCC_MV (3300)
#define BSP_CFG_STACK_MAIN_BYTES (0x400)
#define BSP_CFG_HEAP_SIZE_BYTES (0x400)
#define BSP_CFG_PARAM_CHECKING_ENABLE (0)
#define BSP_CFG_ASSERT (0)
#define BSP_CFG_ERROR_LOG (0)

#define BSP_CFG_C_RUNTIME_INIT ((1))
#define BSP_CFG_EARLY_INIT     ((0))
#define BSP_CFG_HEAP_ZERO_INIT  ((1))

#ifdef __cplusplus
            }
            #endif
#endif /* BSP_CFG_H_ */
