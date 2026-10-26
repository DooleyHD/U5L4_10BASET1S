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
 * Section specification for entire file
 **********************************************************************************************************************/

/* The following sections must be specified in the .ld file:
 * OPBT_Area (r)           : ORIGIN = 0x40121300, LENGTH = 0x00000160 // OPBT0 to OPBT47 (0x03A0 to 0x045C)
 *
 * // OPBT
 * .OPBT0_top :
 * {
 * KEEP(*(.OPBT0_top*))
 * } > OPBT_Area
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_opbt.h"

/***********************************************************************************************************************
 * Type definition
 **********************************************************************************************************************/

/* no definition */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/* no definition */

#if BSP_OPBT_CFG_SETTING_ENABLE

/***********************************************************************************************************************
 * OPBT setting
 **********************************************************************************************************************/

const opbt_setting OPBT_OPBT_setting BSP_PLACE_IN_SECTION (BSP_OPBYTE_SETTING) = {
/* SOFTWARE CONFIGURATION OPBT 0 **********************************************/
    .SW_CFG_OPBT_0_setting                  = BSP_OPBT_SW_CFG_OPTION_0,

/* SOFTWARE CONFIGURATION OPBT 1 **********************************************/
    .SW_CFG_OPBT_1_setting                  = BSP_OPBT_SW_CFG_OPTION_1,

/* SOFTWARE CONFIGURATION OPBT 2 **********************************************/
    .SW_CFG_OPBT_2_setting                  = BSP_OPBT_SW_CFG_OPTION_2,

/* SOFTWARE CONFIGURATION OPBT 3 **********************************************/
    .SW_CFG_OPBT_3_setting                  = BSP_OPBT_SW_CFG_OPTION_3,

/* SOFTWARE CONFIGURATION OPBT 4 **********************************************/
    .SW_CFG_OPBT_4_setting                  = BSP_OPBT_SW_CFG_OPTION_4,

/* SOFTWARE CONFIGURATION OPBT 5 **********************************************/
    .SW_CFG_OPBT_5_setting                  = BSP_OPBT_SW_CFG_OPTION_5,

/* SOFTWARE CONFIGURATION OPBT 6 **********************************************/
    .SW_CFG_OPBT_6_setting                  = BSP_OPBT_SW_CFG_OPTION_6,

/* SOFTWARE CONFIGURATION OPBT 7 **********************************************/
    .SW_CFG_OPBT_7_setting                  = BSP_OPBT_SW_CFG_OPTION_7,

/* SOFTWARE CONFIGURATION OPBT 8 **********************************************/
    .SW_CFG_OPBT_8_setting                  = BSP_OPBT_SW_CFG_OPTION_8,

/* SOFTWARE CONFIGURATION OPBT 9 **********************************************/
    .SW_CFG_OPBT_9_setting                  = BSP_OPBT_SW_CFG_OPTION_9,

/* SOFTWARE CONFIGURATION OPBT 10 *********************************************/
    .SW_CFG_OPBT_10_setting                 = BSP_OPBT_SW_CFG_OPTION_10,

/* SOFTWARE CONFIGURATION OPBT 11 *********************************************/
    .SW_CFG_OPBT_11_setting                 = BSP_OPBT_SW_CFG_OPTION_11,

/* SOFTWARE CONFIGURATION OPBT 12 *********************************************/
    .SW_CFG_OPBT_12_setting                 = BSP_OPBT_SW_CFG_OPTION_12,

/* SOFTWARE CONFIGURATION OPBT 13 *********************************************/
    .SW_CFG_OPBT_13_setting                 = BSP_OPBT_SW_CFG_OPTION_13,

/* SOFTWARE CONFIGURATION OPBT 14 *********************************************/
    .SW_CFG_OPBT_14_setting                 = BSP_OPBT_SW_CFG_OPTION_14,

/* SOFTWARE CONFIGURATION OPBT 15 *********************************************/
    .SW_CFG_OPBT_15_setting                 = BSP_OPBT_SW_CFG_OPTION_15,

/* SOFTWARE CONFIGURATION OPBT 16 *********************************************/
    .SW_CFG_OPBT_16_setting                 = BSP_OPBT_SW_CFG_OPTION_16,

/* SOFTWARE CONFIGURATION OPBT 17 *********************************************/
    .SW_CFG_OPBT_17_setting                 = BSP_OPBT_SW_CFG_OPTION_17,

/* SOFTWARE CONFIGURATION OPBT 18 *********************************************/
    .SW_CFG_OPBT_18_setting                 = BSP_OPBT_SW_CFG_OPTION_18,

/* SOFTWARE CONFIGURATION OPBT 19 *********************************************/
    .SW_CFG_OPBT_19_setting                 = BSP_OPBT_SW_CFG_OPTION_19,

/* SOFTWARE CONFIGURATION OPBT 20 *********************************************/
    .SW_CFG_OPBT_20_setting                 = BSP_OPBT_SW_CFG_OPTION_20,

/* SOFTWARE CONFIGURATION OPBT 21 *********************************************/
    .SW_CFG_OPBT_21_setting                 = BSP_OPBT_SW_CFG_OPTION_21,

/* SOFTWARE CONFIGURATION OPBT 22 *********************************************/
    .SW_CFG_OPBT_22_setting                 = BSP_OPBT_SW_CFG_OPTION_22,

/* SOFTWARE CONFIGURATION OPBT 23 *********************************************/
    .SW_CFG_OPBT_23_setting                 = BSP_OPBT_SW_CFG_OPTION_23,

/* SOFTWARE CONFIGURATION OPBT 24 *********************************************/
    .SW_CFG_OPBT_24_setting                 = BSP_OPBT_SW_CFG_OPTION_24,

/* SOFTWARE CONFIGURATION OPBT 25 *********************************************/
    .SW_CFG_OPBT_25_setting                 = BSP_OPBT_SW_CFG_OPTION_25,

/* SOFTWARE CONFIGURATION OPBT 26 *********************************************/
    .SW_CFG_OPBT_26_setting                 = BSP_OPBT_SW_CFG_OPTION_26,

/* SOFTWARE CONFIGURATION OPBT 27 *********************************************/
    .SW_CFG_OPBT_27_setting                 = BSP_OPBT_SW_CFG_OPTION_27,

/* SOFTWARE CONFIGURATION OPBT 28 *********************************************/
    .SW_CFG_OPBT_28_setting                 = BSP_OPBT_SW_CFG_OPTION_28,

/* SOFTWARE CONFIGURATION OPBT 29 *********************************************/
    .SW_CFG_OPBT_29_setting                 = BSP_OPBT_SW_CFG_OPTION_29,

/* SOFTWARE CONFIGURATION OPBT 30 *********************************************/
    .SW_CFG_OPBT_30_setting                 = BSP_OPBT_SW_CFG_OPTION_30,

/* SOFTWARE CONFIGURATION OPBT 31 *********************************************/
    .SW_CFG_OPBT_31_setting                 = BSP_OPBT_SW_CFG_OPTION_31,

/* VECTOR TABLE BASE ADDRESS CPU 0 ********************************************/
    .VECTOR_TABLE_BASE_ADDRESS_CPU0_setting = BSP_OPBT_VECTOR_TABLE_BASE_ADDRESS,

    .Reserved_0 = 0xFFFFFFFF,          /* Reserved */
    .Reserved_1 = 0xFFFFFFFF,          /* Reserved */
    .Reserved_2 = 0xFFFFFFFF,          /* Reserved */
    .Reserved_3 = 0xFFFFFFFF,          /* Reserved */
    .Reserved_4 = 0xFFFFFFFF,          /* Reserved */
    .Reserved_5 = 0xFFFFFFFF,          /* Reserved */
    .Reserved_6 = 0xFFFFFFFF,          /* Reserved */

/* OPBT0 **********************************************************************/
    .OPBT_OPBT0_setting                     = BSP_OPBT_SETTING_OPBT0,

/* OPBT1 **********************************************************************/
    .OPBT_OPBT1_setting                     = BSP_OPBT_SETTING_OPBT1,

/* OPBT2 **********************************************************************/
    .OPBT_OPBT2_setting                     = 0xFFFFFFFF, /* Reserved */

/* OPBT3 **********************************************************************/
    .OPBT_OPBT3_setting                     = BSP_OPBT_SETTING_OPBT3,

/* OPBT4 **********************************************************************/
    .OPBT_OPBT4_setting                     = BSP_OPBT_SETTING_OPBT4,

/* OPBT5 **********************************************************************/
    .OPBT_OPBT5_setting                     = 0xFFFFE7FF, /* Reserved */

/* OPBT6 **********************************************************************/
    .OPBT_OPBT6_setting                     = BSP_OPBT_SETTING_OPBT6,

/* OPBT7 **********************************************************************/
    .OPBT_OPBT7_setting                     = 0xFFFFFFFF, /* Reserved */

/* OPBT8 **********************************************************************/
    .OPBT_OPBT8_setting                     = BSP_OPBT_SETTING_OPBT8,

/* OPBT9 **********************************************************************/
    .OPBT_OPBT9_setting                     = 0xFFFFFFFF, /* Reserved */

/* OPBT10 *********************************************************************/
    .OPBT_OPBT10_setting                    = BSP_OPBT_SETTING_OPBT10,

/* OPBT11 *********************************************************************/
    .OPBT_OPBT11_setting                    = BSP_OPBT_SETTING_OPBT11,

/* OPBT12 *********************************************************************/
    .OPBT_OPBT12_setting                    = BSP_OPBT_SETTING_OPBT12,

/* OPBT13 *********************************************************************/
    .OPBT_OPBT13_setting                    = BSP_OPBT_SETTING_OPBT13,

/* OPBT14 **********************************************************************/
    .OPBT_OPBT14_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT15 **********************************************************************/
    .OPBT_OPBT15_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT16 **********************************************************************/
    .OPBT_OPBT16_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT17 **********************************************************************/
    .OPBT_OPBT17_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT18 **********************************************************************/
    .OPBT_OPBT18_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT19 **********************************************************************/
    .OPBT_OPBT19_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT20 **********************************************************************/
    .OPBT_OPBT20_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT21 **********************************************************************/
    .OPBT_OPBT21_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT22 **********************************************************************/
    .OPBT_OPBT22_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT23 **********************************************************************/
    .OPBT_OPBT23_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT24 **********************************************************************/
    .OPBT_OPBT24_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT25 **********************************************************************/
    .OPBT_OPBT25_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT26 *********************************************************************/
    .OPBT_OPBT26_setting                    = BSP_OPBT_SETTING_OPBT26,

/* OPBT27 *********************************************************************/
    .OPBT_OPBT27_setting                    = BSP_OPBT_SETTING_OPBT27,

/* OPBT28 **********************************************************************/
    .OPBT_OPBT28_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT29 **********************************************************************/
    .OPBT_OPBT29_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT30 **********************************************************************/
    .OPBT_OPBT30_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT31 **********************************************************************/
    .OPBT_OPBT31_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT32 **********************************************************************/
    .OPBT_OPBT32_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT33 **********************************************************************/
    .OPBT_OPBT33_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT34 **********************************************************************/
    .OPBT_OPBT34_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT35 **********************************************************************/
    .OPBT_OPBT35_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT36 **********************************************************************/
    .OPBT_OPBT36_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT37 **********************************************************************/
    .OPBT_OPBT37_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT38 **********************************************************************/
    .OPBT_OPBT38_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT39 **********************************************************************/
    .OPBT_OPBT39_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT40 **********************************************************************/
    .OPBT_OPBT40_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT41 **********************************************************************/
    .OPBT_OPBT41_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT42 *********************************************************************/
    .OPBT_OPBT42_setting                    = BSP_OPBT_SETTING_OPBT42,

/* OPBT43 *********************************************************************/
    .OPBT_OPBT43_setting                    = BSP_OPBT_SETTING_OPBT43,

/* OPBT44 *********************************************************************/
    .OPBT_OPBT44_setting                    = BSP_OPBT_SETTING_OPBT44,

/* OPBT45 *********************************************************************/
    .OPBT_OPBT45_setting                    = BSP_OPBT_SETTING_OPBT45,

/* OPBT46 **********************************************************************/
    .OPBT_OPBT46_setting                    = 0xFFFFFFFF, /* Reserved */

/* OPBT47 *********************************************************************/
    .OPBT_OPBT47_setting                    = BSP_OPBT_SETTING_OPBT47,
};

#endif
