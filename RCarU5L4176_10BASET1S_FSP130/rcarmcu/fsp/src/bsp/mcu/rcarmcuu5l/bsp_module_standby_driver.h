/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_MODULE_STANDBY_DRIVER_H
#define BSP_MODULE_STANDBY_DRIVER_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RCARMCUU5L
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define BSP_PRV_MSR_ENABLE     0x00000000 /* Enable Clock supply for module standby value */
#define BSP_PRV_MSR_DISABLE    0x80000000 /* Disable Clock supply for module standby value */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Standby Module */
typedef enum e_bsp_module_standby
{
    BSP_MODULE_STANDBY_START = 0,
    BSP_MODULE_STANDBY_ADC_AWO,
    BSP_MODULE_STANDBY_ADC_ISO,
    BSP_MODULE_STANDBY_CANFD,
#if (BSP_FEATURE_CANXL_IS_AVAILABLE)
    BSP_MODULE_STANDBY_CANXL,
#endif                                 /* #if (BSP_FEATURE_CANXL_IS_AVAILABLE) */
    BSP_MODULE_STANDBY_CSIH,
    BSP_MODULE_STANDBY_CXPI,
    BSP_MODULE_STANDBY_ENCA,
#if (BSP_FEATURE_ETHTSN_IS_AVAILABLE)
    BSP_MODULE_STANDBY_ETHTSN,
#endif                                 /* #if (BSP_FEATURE_ETHTSN_IS_AVAILABLE) */
#if (BSP_FEATURE_T1S_IS_AVAILABLE)
    BSP_MODULE_STANDBY_ETHT1S,
#endif                                 /* #if (BSP_FEATURE_T1S_IS_AVAILABLE) */
    BSP_MODULE_STANDBY_I2C,
    BSP_MODULE_STANDBY_I3C,
    BSP_MODULE_STANDBY_OSTM,
#if (BSP_FEATURE_PSI5_IS_AVAILABLE)
    BSP_MODULE_STANDBY_PSI5,
#endif                                 /* #if (BSP_FEATURE_PSI5_IS_AVAILABLE) */
    BSP_MODULE_STANDBY_PWMDIAG,
    BSP_MODULE_STANDBY_RSENT,
    BSP_MODULE_STANDBY_RLIN,
    BSP_MODULE_STANDBY_RTCA,
#if (BSP_FEATURE_MMCA_IS_AVAILABLE)
    BSP_MODULE_STANDBY_MMCA,
#endif                                 /* #if (BSP_FEATURE_MMCA_IS_AVAILABLE) */
#if (BSP_FEATURE_SFMA_IS_AVAILABLE)
    BSP_MODULE_STANDBY_SFMA,
#endif                                 /* #if (BSP_FEATURE_SFMA_IS_AVAILABLE) */
    BSP_MODULE_STANDBY_SSIF,
    BSP_MODULE_STANDBY_TAPA,
    BSP_MODULE_STANDBY_TAUD,
    BSP_MODULE_STANDBY_TAUJ,
    BSP_MODULE_STANDBY_WDT,
    BSP_MODULE_STANDBY_TOTAL_INDEX_END
} bsp_module_standby_t;

/** Reset Source */
typedef enum e_bsp_reset_src
{
    BSP_RESET_SRC_POWER_ON  = 0x1ULL << 0,  /* Power On SYS0_RESET Flag  */
    BSP_RESET_SRC_EXTERNAL  = 0x1ULL << 2,  /* External SYS0_RESET Flag  */
    BSP_RESET_SRC_VMON      = 0x1ULL << 3,  /*  VMON SYS0_RESET Flag  */
    BSP_RESET_SRC_SW        = 0x1ULL << 4,  /* ECM System SYS0_RESET 1 Flag  */
    BSP_RESET_SRC_ECM       = 0x1ULL << 6,  /* Software System SYS0_RESET Flag  */
    BSP_RESET_SRC_WDT       = 0x1ULL << 7,  /* WDTBA SYS0_RESET Flag  */
    BSP_RESET_SRC_DEEPSTOP  = 0x1ULL << 15, /* DeepSTOP SYS0_RESET Flag  */
    BSP_RESET_SRC_RSIP_M30A = 0x1ULL << 16, /* RSIP-M30A Software System SYS0_RESET Flag */
} bsp_reset_src_t;

/** Wakup Factor for DeepStop */
typedef enum e_bsp_wk_factor
{
    BSP_WK_FACTOR_NONE       = 0U,
    BSP_WK_FACTOR_NMI        = 0x1ULL << 0,
    BSP_WK_FACTOR_NTWDTBATIT = 0x1ULL << 4,
    BSP_WK_FACTOR_INTRTCA01S = 0x1ULL << 8,
    BSP_WK_FACTOR_INTRTCA0AL = 0x1ULL << 9,
    BSP_WK_FACTOR_INTRTCA0R  = 0x1ULL << 10,
    BSP_WK_FACTOR_WUTRG0     = 0x1ULL << 16,
    BSP_WK_FACTOR_WUTRG1     = 0x1ULL << 17,
    BSP_WK_FACTOR_INTLPSTM0  = 0x1ULL << 20,
    BSP_WK_FACTOR_INTLPSTM1  = 0x1ULL << 21,
    BSP_WK_FACTOR_INTLPSTM2  = 0x1ULL << 22,
    BSP_WK_FACTOR_INTLPSTM3  = 0x1ULL << 23,
    BSP_WK_FACTOR_INTLPSTM4  = 0x1ULL << 24,
    BSP_WK_FACTOR_IRQ0       = 0x1ULL << 32,
    BSP_WK_FACTOR_IRQ1       = 0x1ULL << 33,
    BSP_WK_FACTOR_IRQ2       = 0x1ULL << 34,
    BSP_WK_FACTOR_IRQ3       = 0x1ULL << 35,
    BSP_WK_FACTOR_IRQ4       = 0x1ULL << 36,
    BSP_WK_FACTOR_IRQ5       = 0x1ULL << 37,
    BSP_WK_FACTOR_IRQ6       = 0x1ULL << 38,
    BSP_WK_FACTOR_IRQ7       = 0x1ULL << 39,
    BSP_WK_FACTOR_IRQ8       = 0x1ULL << 40,
    BSP_WK_FACTOR_IRQ9       = 0x1ULL << 41,
    BSP_WK_FACTOR_IRQ10      = 0x1ULL << 42,
    BSP_WK_FACTOR_IRQ11      = 0x1ULL << 43,
    BSP_WK_FACTOR_IRQ12      = 0x1ULL << 44,
    BSP_WK_FACTOR_IRQ13      = 0x1ULL << 45,
    BSP_WK_FACTOR_IRQ14      = 0x1ULL << 46,
    BSP_WK_FACTOR_IRQ15      = 0x1ULL << 47,
    BSP_WK_FACTOR_IRQ16      = 0x1ULL << 48,
    BSP_WK_FACTOR_IRQ17      = 0x1ULL << 49,
    BSP_WK_FACTOR_IRQ18      = 0x1ULL << 50,
    BSP_WK_FACTOR_IRQ19      = 0x1ULL << 51,
    BSP_WK_FACTOR_IRQ20      = 0x1ULL << 52,
    BSP_WK_FACTOR_IRQ21      = 0x1ULL << 53,
    BSP_WK_FACTOR_IRQ22      = 0x1ULL << 54,
    BSP_WK_FACTOR_IRQ23      = 0x1ULL << 55,
} bsp_wk_factor_t;

/** IO Hold */
typedef enum e_bsp_io_hold
{
    BSP_IO_HOLD_P01       = 0x1ULL << 1,
    BSP_IO_HOLD_P03       = 0x1ULL << 3,
    BSP_IO_HOLD_P09       = 0x1ULL << 9,
    BSP_IO_HOLD_P10       = 0x1ULL << 10,
    BSP_IO_HOLD_P11       = 0x1ULL << 11,
    BSP_IO_HOLD_P12       = 0x1ULL << 12,
    BSP_IO_HOLD_P13       = 0x1ULL << 13,
    BSP_IO_HOLD_P18       = 0x1ULL << 18,
    BSP_IO_HOLD_P19       = 0x1ULL << 19,
    BSP_IO_HOLD_P20       = 0x1ULL << 20,
    BSP_IO_HOLD_P21       = 0x1ULL << 21,
    BSP_IO_HOLD_AP0       = 0x1ULL << 32,
    BSP_IO_HOLD_AP2       = 0x1ULL << 34,
    BSP_IO_HOLD_CLEAR_ALL = 0U,
} bsp_io_hold_t;

typedef struct st_bsp_module_standby_info
{
    volatile uint32_t * msr_reg_address;   ///< Guard channel, bit position indicate the channel.
    bool                initial_cfg_value; ///< Configured value in MDF used to enable Guard for all module.
} bsp_module_standby_info_t;

/***********************************************************************************************************************
 * Exported global variable (to be accessed by other files)
 **********************************************************************************************************************/
extern const bsp_module_standby_info_t g_msr_info_table[BSP_MODULE_STANDBY_TOTAL_INDEX_END];

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RCARMCUU5L) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif                                 /* BSP_MODULE_STANDBY_DRIVER_H */
