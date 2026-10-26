/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RCARMCUU5L
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RCARMCUU5L) */

/***********************************************************************************************************************
 * Definition of re-inclusion prevention
 **********************************************************************************************************************/
#ifndef  __U5L_OPBT_H__
#define  __U5L_OPBT_H__

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdint.h>
#include "bsp_mcu_device_pn_cfg.h"
#include "bsp_api.h"

/***********************************************************************************************************************
 * Extern declaration
 **********************************************************************************************************************/
typedef const struct opbt_setting_cfg
{
/* Software Configuration Option Byte (n = 0 to 31) */
    const uint32_t SW_CFG_OPBT_0_setting;
    const uint32_t SW_CFG_OPBT_1_setting;
    const uint32_t SW_CFG_OPBT_2_setting;
    const uint32_t SW_CFG_OPBT_3_setting;
    const uint32_t SW_CFG_OPBT_4_setting;
    const uint32_t SW_CFG_OPBT_5_setting;
    const uint32_t SW_CFG_OPBT_6_setting;
    const uint32_t SW_CFG_OPBT_7_setting;
    const uint32_t SW_CFG_OPBT_8_setting;
    const uint32_t SW_CFG_OPBT_9_setting;
    const uint32_t SW_CFG_OPBT_10_setting;
    const uint32_t SW_CFG_OPBT_11_setting;
    const uint32_t SW_CFG_OPBT_12_setting;
    const uint32_t SW_CFG_OPBT_13_setting;
    const uint32_t SW_CFG_OPBT_14_setting;
    const uint32_t SW_CFG_OPBT_15_setting;
    const uint32_t SW_CFG_OPBT_16_setting;
    const uint32_t SW_CFG_OPBT_17_setting;
    const uint32_t SW_CFG_OPBT_18_setting;
    const uint32_t SW_CFG_OPBT_19_setting;
    const uint32_t SW_CFG_OPBT_20_setting;
    const uint32_t SW_CFG_OPBT_21_setting;
    const uint32_t SW_CFG_OPBT_22_setting;
    const uint32_t SW_CFG_OPBT_23_setting;
    const uint32_t SW_CFG_OPBT_24_setting;
    const uint32_t SW_CFG_OPBT_25_setting;
    const uint32_t SW_CFG_OPBT_26_setting;
    const uint32_t SW_CFG_OPBT_27_setting;
    const uint32_t SW_CFG_OPBT_28_setting;
    const uint32_t SW_CFG_OPBT_29_setting;
    const uint32_t SW_CFG_OPBT_30_setting;
    const uint32_t SW_CFG_OPBT_31_setting;

/* Vector Table Base Address (CPU0) */
    const uint32_t VECTOR_TABLE_BASE_ADDRESS_CPU0_setting;
    const uint32_t Reserved_0;
    const uint32_t Reserved_1;
    const uint32_t Reserved_2;
    const uint32_t Reserved_3;
    const uint32_t Reserved_4;
    const uint32_t Reserved_5;
    const uint32_t Reserved_6;

/* OPBT setting value */
    const uint32_t OPBT_OPBT0_setting;
    const uint32_t OPBT_OPBT1_setting;
    const uint32_t OPBT_OPBT2_setting;
    const uint32_t OPBT_OPBT3_setting;
    const uint32_t OPBT_OPBT4_setting;
    const uint32_t OPBT_OPBT5_setting;
    const uint32_t OPBT_OPBT6_setting;
    const uint32_t OPBT_OPBT7_setting;
    const uint32_t OPBT_OPBT8_setting;
    const uint32_t OPBT_OPBT9_setting;
    const uint32_t OPBT_OPBT10_setting;
    const uint32_t OPBT_OPBT11_setting;
    const uint32_t OPBT_OPBT12_setting;
    const uint32_t OPBT_OPBT13_setting;
    const uint32_t OPBT_OPBT14_setting;
    const uint32_t OPBT_OPBT15_setting;
    const uint32_t OPBT_OPBT16_setting;
    const uint32_t OPBT_OPBT17_setting;
    const uint32_t OPBT_OPBT18_setting;
    const uint32_t OPBT_OPBT19_setting;
    const uint32_t OPBT_OPBT20_setting;
    const uint32_t OPBT_OPBT21_setting;
    const uint32_t OPBT_OPBT22_setting;
    const uint32_t OPBT_OPBT23_setting;
    const uint32_t OPBT_OPBT24_setting;
    const uint32_t OPBT_OPBT25_setting;
    const uint32_t OPBT_OPBT26_setting;
    const uint32_t OPBT_OPBT27_setting;
    const uint32_t OPBT_OPBT28_setting;
    const uint32_t OPBT_OPBT29_setting;
    const uint32_t OPBT_OPBT30_setting;
    const uint32_t OPBT_OPBT31_setting;
    const uint32_t OPBT_OPBT32_setting;
    const uint32_t OPBT_OPBT33_setting;
    const uint32_t OPBT_OPBT34_setting;
    const uint32_t OPBT_OPBT35_setting;
    const uint32_t OPBT_OPBT36_setting;
    const uint32_t OPBT_OPBT37_setting;
    const uint32_t OPBT_OPBT38_setting;
    const uint32_t OPBT_OPBT39_setting;
    const uint32_t OPBT_OPBT40_setting;
    const uint32_t OPBT_OPBT41_setting;
    const uint32_t OPBT_OPBT42_setting;
    const uint32_t OPBT_OPBT43_setting;
    const uint32_t OPBT_OPBT44_setting;
    const uint32_t OPBT_OPBT45_setting;
    const uint32_t OPBT_OPBT46_setting;
    const uint32_t OPBT_OPBT47_setting;
} opbt_setting;

extern const opbt_setting OPBT_OPBT_setting;

#endif                                 /* __U5L_OPBT_H__ */
