/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "bsp_guard_driver.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/* Array of all PBG groups base address */
const uint32_t g_pbgprot_baseaddress[] =
{
    [BSP_PBG_GROUP_000] = (uint32_t) R_PGRD00_CTL0_BASE,
    [BSP_PBG_GROUP_010] = (uint32_t) R_PGRD01_CTL0_BASE,
    [BSP_PBG_GROUP_011] = (uint32_t) R_PGRD01_CTL1_BASE,
    [BSP_PBG_GROUP_012] = (uint32_t) R_PGRD01_CTL2_BASE,
    [BSP_PBG_GROUP_020] = (uint32_t) R_PGRD02_CTL0_BASE,
    [BSP_PBG_GROUP_030] = (uint32_t) R_PGRD03_CTL0_BASE,
    [BSP_PBG_GROUP_040] = (uint32_t) R_PGRD04_CTL0_BASE,
    [BSP_PBG_GROUP_041] = (uint32_t) R_PGRD04_CTL1_BASE,
    [BSP_PBG_GROUP_042] = (uint32_t) R_PGRD04_CTL2_BASE,
    [BSP_PBG_GROUP_050] = (uint32_t) R_PGRD05_CTL0_BASE,
    [BSP_PBG_GROUP_060] = (uint32_t) R_PGRD06_CTL0_BASE,
    [BSP_PBG_GROUP_070] = (uint32_t) R_PGRD07_CTL0_BASE,
    [BSP_PBG_GROUP_080] = (uint32_t) R_PGRD08_CTL0_BASE,
    [BSP_PBG_GROUP_090] = (uint32_t) R_PGRD09_CTL0_BASE,
    [BSP_PBG_GROUP_100] = (uint32_t) R_PGRD10_CTL0_BASE,
    [BSP_PBG_GROUP_101] = (uint32_t) R_PGRD10_CTL1_BASE,
    [BSP_PBG_GROUP_110] = (uint32_t) R_PGRD11_CTL0_BASE,
    [BSP_HBG_GROUP_080] = (uint32_t) R_HGRD08_CTL0_BASE,
    [BSP_HBG_GROUP_081] = (uint32_t) R_HGRD08_CTL1_BASE,
    [BSP_HBG_GROUP_082] = (uint32_t) R_HGRD08_CTL2_BASE
};

/* Array of all PBG Key protection groups base address */
const uint32_t g_pbgkcprot_baseaddress[] =
{
    [BSP_PBG_GROUP_000] = (uint32_t) R_PGRD00_CAP0_BASE,
    [BSP_PBG_GROUP_010] = (uint32_t) R_PGRD01_CAP0_BASE,
    [BSP_PBG_GROUP_011] = (uint32_t) R_PGRD01_CAP0_BASE,
    [BSP_PBG_GROUP_012] = (uint32_t) R_PGRD01_CAP0_BASE,
    [BSP_PBG_GROUP_020] = (uint32_t) R_PGRD02_CAP0_BASE,
    [BSP_PBG_GROUP_030] = (uint32_t) R_PGRD03_CAP0_BASE,
    [BSP_PBG_GROUP_040] = (uint32_t) R_PGRD04_CAP0_BASE,
    [BSP_PBG_GROUP_041] = (uint32_t) R_PGRD04_CAP0_BASE,
    [BSP_PBG_GROUP_042] = (uint32_t) R_PGRD04_CAP0_BASE,
    [BSP_PBG_GROUP_050] = (uint32_t) R_PGRD05_CAP0_BASE,
    [BSP_PBG_GROUP_060] = (uint32_t) R_PGRD06_CAP0_BASE,
    [BSP_PBG_GROUP_070] = (uint32_t) R_PGRD07_CAP0_BASE,
    [BSP_PBG_GROUP_080] = (uint32_t) R_PGRD08_CAP0_BASE,
    [BSP_PBG_GROUP_090] = (uint32_t) R_PGRD09_CAP0_BASE,
    [BSP_PBG_GROUP_100] = (uint32_t) R_PGRD10_CAP0_BASE,
    [BSP_PBG_GROUP_101] = (uint32_t) R_PGRD10_CAP0_BASE,
    [BSP_PBG_GROUP_110] = (uint32_t) R_PGRD11_CAP0_BASE,
    [BSP_HBG_GROUP_080] = (uint32_t) R_HGRD08_CAP0_BASE,
    [BSP_HBG_GROUP_081] = (uint32_t) R_HGRD08_CAP1_BASE,
    [BSP_HBG_GROUP_082] = (uint32_t) R_HGRD08_CAP2_BASE
};

/* Array of all module PBG information */
const bsp_module_pbg_info_t g_bsp_module_pbg_info_table[] =
{
    [BSP_MODULE_PBG_INDEX_ADC] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_ADC_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_060,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_110,
            .pbg_channel = (BSP_PBG_CHANNEL_03)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_BSP] =
            {
            .no_of_element     = 3,
            .initial_cfg_value = BSP_GUARD_BSP_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_010,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_050,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_080,
            .pbg_channel = (BSP_PBG_CHANNEL_03)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_CANFD] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_CANFD_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_090,
            .pbg_channel = (0x3FE)
            },
            }
            },
#if (BSP_FEATURE_CANXL_IS_AVAILABLE)
    [BSP_MODULE_PBG_INDEX_CANXL] =
            {
            .no_of_element     = 3,
            .initial_cfg_value = BSP_GUARD_CANXL_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_040,
            .pbg_channel = (BSP_PBG_CHANNEL_01)
            },
            {
            .pbg_group   = BSP_HBG_GROUP_081,
            .pbg_channel = (BSP_PBG_CHANNEL_00)
            },
            {
            .pbg_group   = BSP_HBG_GROUP_082,
            .pbg_channel = (BSP_PBG_CHANNEL_00)
            },
            }
            },
#endif
    [BSP_MODULE_PBG_INDEX_CLMA] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_CLMA_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_010,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_CSIH] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_CSIH_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_041,
            .pbg_channel = (BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10 | BSP_PBG_CHANNEL_11)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_100,
            .pbg_channel = (BSP_PBG_CHANNEL_07 | BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_CRC] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_CRC_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_020,
            .pbg_channel = (BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 | BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_030,
            .pbg_channel = (BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 | BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_CXPI] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_CXPI_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_041,
            .pbg_channel = (BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_100,
            .pbg_channel = (BSP_PBG_CHANNEL_05 | BSP_PBG_CHANNEL_06)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_DMA] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_DMA_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_080,
            .pbg_channel = (BSP_PBG_CHANNEL_03)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_DTS] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_DTS_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_000,
            .pbg_channel = (BSP_PBG_CHANNEL_01)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_ECM] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_ECM_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_040,
            .pbg_channel = (BSP_PBG_CHANNEL_06)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_ENCA] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_ENCA_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_040,
            .pbg_channel = (BSP_PBG_CHANNEL_05)
            },
            }
            },
#if (BSP_FEATURE_T1S_IS_AVAILABLE)
    [BSP_MODULE_PBG_INDEX_ETHT1S] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_ETHT1S_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_070,
            .pbg_channel = (BSP_PBG_CHANNEL_03)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_080,
            .pbg_channel = (BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_04)
            },
            }
            },
#endif
#if (BSP_FEATURE_ETHTSN_IS_AVAILABLE)
    [BSP_MODULE_PBG_INDEX_ETHTSN] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_ETHTSN_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_070,
            .pbg_channel = (BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05 | BSP_PBG_CHANNEL_06)
            },
            }
            },
#endif
    [BSP_MODULE_PBG_INDEX_I2C] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_I2C_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_110,
            .pbg_channel = (BSP_PBG_CHANNEL_04 | BSP_PBG_CHANNEL_05)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_I3C] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_I3C_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_070,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_IOPORT] =
            {
            .no_of_element     = 3,
            .initial_cfg_value = BSP_GUARD_IOPORT_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_010,
            .pbg_channel = (BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10 | BSP_PBG_CHANNEL_11 |
                            BSP_PBG_CHANNEL_12 | BSP_PBG_CHANNEL_13 | BSP_PBG_CHANNEL_14 | BSP_PBG_CHANNEL_15)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_011,
            .pbg_channel = (0xffff)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_012,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_02)
            },
            }
            },
#if (BSP_FEATURE_MMCA_IS_AVAILABLE)
    [BSP_MODULE_PBG_INDEX_MMCA] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_MMCA_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_040,
            .pbg_channel = (BSP_PBG_CHANNEL_01)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_042,
            .pbg_channel = (BSP_PBG_CHANNEL_05)
            },
            }
            },
#endif
    [BSP_MODULE_PBG_INDEX_OSTM] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_OSTM_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_040,
            .pbg_channel = (BSP_PBG_CHANNEL_13 | BSP_PBG_CHANNEL_14 | BSP_PBG_CHANNEL_15)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_100,
            .pbg_channel = (BSP_PBG_CHANNEL_03 | BSP_PBG_CHANNEL_04)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_PIC] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_PIC_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_040,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            },
            }
            },
#if (BSP_FEATURE_PSI5_IS_AVAILABLE)
    [BSP_MODULE_PBG_INDEX_PSI5] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_PSI5_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_041,
            .pbg_channel = (BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03)
            },
            }
            },
#endif
    [BSP_MODULE_PBG_INDEX_PWMDIAG] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_PWMDIAG_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_110,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_RLIN] =
            {
            .no_of_element     = 4,
            .initial_cfg_value = BSP_GUARD_RLIN_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_041,
            .pbg_channel = (BSP_PBG_CHANNEL_12 | BSP_PBG_CHANNEL_13 | BSP_PBG_CHANNEL_14 | BSP_PBG_CHANNEL_15)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_042,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03 |
                            BSP_PBG_CHANNEL_04)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_100,
            .pbg_channel = (BSP_PBG_CHANNEL_11 | BSP_PBG_CHANNEL_12 | BSP_PBG_CHANNEL_13 | BSP_PBG_CHANNEL_14 |
                            BSP_PBG_CHANNEL_15)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_101,
            .pbg_channel = (BSP_PBG_CHANNEL_00 | BSP_PBG_CHANNEL_01 | BSP_PBG_CHANNEL_02 | BSP_PBG_CHANNEL_03)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_RSENT] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_RSENT_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_020,
            .pbg_channel = (BSP_PBG_CHANNEL_06 | BSP_PBG_CHANNEL_07 | BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09 |
                            BSP_PBG_CHANNEL_10)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_030,
            .pbg_channel = (BSP_PBG_CHANNEL_06 | BSP_PBG_CHANNEL_07 | BSP_PBG_CHANNEL_08 | BSP_PBG_CHANNEL_09)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_RTCA] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_RTCA_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_010,
            .pbg_channel = (BSP_PBG_CHANNEL_06)
            },
            }
            },
#if (BSP_FEATURE_SFMA_IS_AVAILABLE)
    [BSP_MODULE_PBG_INDEX_SFMA] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_SFMA_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_HBG_GROUP_080,
            .pbg_channel = (BSP_PBG_CHANNEL_00)
            },
            }
            },
#endif
    [BSP_MODULE_PBG_INDEX_SSIF] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_SSIF_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_041,
            .pbg_channel = (BSP_PBG_CHANNEL_06 | BSP_PBG_CHANNEL_07)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_TAPA] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_TAPA_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_040,
            .pbg_channel = (BSP_PBG_CHANNEL_04)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_TAUD] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_TAUD_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_040,
            .pbg_channel = (BSP_PBG_CHANNEL_07 | BSP_PBG_CHANNEL_08)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_100,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_TAUJ] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_TAUJ_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_040,
            .pbg_channel = (BSP_PBG_CHANNEL_09 | BSP_PBG_CHANNEL_10 | BSP_PBG_CHANNEL_11 | BSP_PBG_CHANNEL_12)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_TSN] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_TSN_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_060,
            .pbg_channel = (BSP_PBG_CHANNEL_03)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_VMON] =
            {
            .no_of_element     = 1,
            .initial_cfg_value = BSP_GUARD_VMON_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_010,
            .pbg_channel = (BSP_PBG_CHANNEL_02)
            },
            }
            },
    [BSP_MODULE_PBG_INDEX_WDT] =
            {
            .no_of_element     = 2,
            .initial_cfg_value = BSP_GUARD_WDT_WRITE_ACCESS,
            .properties        = (bsp_module_pbg_properties_t[])
            {
            {
            .pbg_group   = BSP_PBG_GROUP_010,
            .pbg_channel = (BSP_PBG_CHANNEL_07)
            },
            {
            .pbg_group   = BSP_PBG_GROUP_041,
            .pbg_channel = (BSP_PBG_CHANNEL_00)
            },
            }
            },
};

const uint32_t g_xram_guard_protection_baseaddress[BSP_GUARD_PROTECTION_RAM_NUM][BSP_XSG_ENTRY_NUMBER_NUM] =
{
    [BSP_GUARD_PROTECTION_CPU_RAM][BSP_XRG_ENTRY_NUMBER_0]       = (uint32_t) &R_CRGRD_CTL_CPURAM00->CRG[0],
    [BSP_GUARD_PROTECTION_CPU_RAM][BSP_XRG_ENTRY_NUMBER_1]       = (uint32_t) &R_CRGRD_CTL_CPURAM00->CRG[1],
    [BSP_GUARD_PROTECTION_CPU_RAM][BSP_XRG_ENTRY_NUMBER_2]       = (uint32_t) &R_CRGRD_CTL_CPURAM00->CRG[2],
    [BSP_GUARD_PROTECTION_CPU_RAM][BSP_XRG_ENTRY_NUMBER_3]       = (uint32_t) &R_CRGRD_CTL_CPURAM00->CRG[3],
    [BSP_GUARD_PROTECTION_CPU_RAM][BSP_XRG_ENTRY_NUMBER_4]       = (uint32_t) &R_CRGRD_CTL_CPURAM00->CRG[4],
    [BSP_GUARD_PROTECTION_CPU_RAM][BSP_XRG_ENTRY_NUMBER_5]       = (uint32_t) &R_CRGRD_CTL_CPURAM00->CRG[5],
    [BSP_GUARD_PROTECTION_CPU_RAM][BSP_XRG_ENTRY_NUMBER_6]       = (uint32_t) &R_CRGRD_CTL_CPURAM00->CRG[6],
    [BSP_GUARD_PROTECTION_CPU_RAM][BSP_XRG_ENTRY_NUMBER_7]       = (uint32_t) &R_CRGRD_CTL_CPURAM00->CRG[7],
    [BSP_GUARD_PROTECTION_CPU_RAM][BSP_XSG_ENTRY_NUMBER_0]       = (uint32_t) &R_CSGRD_CTL_CPURAM00->CSG[0],
    [BSP_GUARD_PROTECTION_CPU_RAM][BSP_XSG_ENTRY_NUMBER_1]       = (uint32_t) &R_CSGRD_CTL_CPURAM00->CSG[1],
    [BSP_GUARD_PROTECTION_CPU_RAM][BSP_XSG_ENTRY_NUMBER_2]       = (uint32_t) &R_CSGRD_CTL_CPURAM00->CSG[2],
    [BSP_GUARD_PROTECTION_CPU_RAM][BSP_XSG_ENTRY_NUMBER_3]       = (uint32_t) &R_CSGRD_CTL_CPURAM00->CSG[3],
    [BSP_GUARD_PROTECTION_GLOBAL_RAM][BSP_XRG_ENTRY_NUMBER_0]    = (uint32_t) &R_CRGRD_CTL_GRAM00->GRG[0],
    [BSP_GUARD_PROTECTION_GLOBAL_RAM][BSP_XRG_ENTRY_NUMBER_1]    = (uint32_t) &R_CRGRD_CTL_GRAM00->GRG[1],
    [BSP_GUARD_PROTECTION_GLOBAL_RAM][BSP_XRG_ENTRY_NUMBER_2]    = (uint32_t) &R_CRGRD_CTL_GRAM00->GRG[2],
    [BSP_GUARD_PROTECTION_GLOBAL_RAM][BSP_XRG_ENTRY_NUMBER_3]    = (uint32_t) &R_CRGRD_CTL_GRAM00->GRG[3],
    [BSP_GUARD_PROTECTION_GLOBAL_RAM][BSP_XRG_ENTRY_NUMBER_4]    = (uint32_t) &R_CRGRD_CTL_GRAM00->GRG[4],
    [BSP_GUARD_PROTECTION_GLOBAL_RAM][BSP_XRG_ENTRY_NUMBER_5]    = (uint32_t) &R_CRGRD_CTL_GRAM00->GRG[5],
    [BSP_GUARD_PROTECTION_GLOBAL_RAM][BSP_XRG_ENTRY_NUMBER_6]    = (uint32_t) &R_CRGRD_CTL_GRAM00->GRG[6],
    [BSP_GUARD_PROTECTION_GLOBAL_RAM][BSP_XRG_ENTRY_NUMBER_7]    = (uint32_t) &R_CRGRD_CTL_GRAM00->GRG[7],
    [BSP_GUARD_PROTECTION_GLOBAL_RAM][BSP_XSG_ENTRY_NUMBER_0]    = (uint32_t) &R_CSGRD_CTL_GRAM00->GSG[0],
    [BSP_GUARD_PROTECTION_GLOBAL_RAM][BSP_XSG_ENTRY_NUMBER_1]    = (uint32_t) &R_CSGRD_CTL_GRAM00->GSG[1],
    [BSP_GUARD_PROTECTION_GLOBAL_RAM][BSP_XSG_ENTRY_NUMBER_2]    = (uint32_t) &R_CSGRD_CTL_GRAM00->GSG[2],
    [BSP_GUARD_PROTECTION_GLOBAL_RAM][BSP_XSG_ENTRY_NUMBER_3]    = (uint32_t) &R_CSGRD_CTL_GRAM00->GSG[3],
    [BSP_GUARD_PROTECTION_RETENTION_RAM][BSP_XRG_ENTRY_NUMBER_0] = (uint32_t) &R_CRGRD_CTL_RRAM00->RRG[0],
    [BSP_GUARD_PROTECTION_RETENTION_RAM][BSP_XRG_ENTRY_NUMBER_1] = (uint32_t) &R_CRGRD_CTL_RRAM00->RRG[1],
    [BSP_GUARD_PROTECTION_RETENTION_RAM][BSP_XRG_ENTRY_NUMBER_2] = (uint32_t) &R_CRGRD_CTL_RRAM00->RRG[2],
    [BSP_GUARD_PROTECTION_RETENTION_RAM][BSP_XRG_ENTRY_NUMBER_3] = (uint32_t) &R_CRGRD_CTL_RRAM00->RRG[3],
    [BSP_GUARD_PROTECTION_RETENTION_RAM][BSP_XRG_ENTRY_NUMBER_4] = (uint32_t) &R_CRGRD_CTL_RRAM00->RRG[4],
    [BSP_GUARD_PROTECTION_RETENTION_RAM][BSP_XRG_ENTRY_NUMBER_5] = (uint32_t) &R_CRGRD_CTL_RRAM00->RRG[5],
    [BSP_GUARD_PROTECTION_RETENTION_RAM][BSP_XRG_ENTRY_NUMBER_6] = (uint32_t) &R_CRGRD_CTL_RRAM00->RRG[6],
    [BSP_GUARD_PROTECTION_RETENTION_RAM][BSP_XRG_ENTRY_NUMBER_7] = (uint32_t) &R_CRGRD_CTL_RRAM00->RRG[7],
    [BSP_GUARD_PROTECTION_RETENTION_RAM][BSP_XSG_ENTRY_NUMBER_0] = (uint32_t) &R_CSGRD_CTL_RRAM00->RSG[0],
    [BSP_GUARD_PROTECTION_RETENTION_RAM][BSP_XSG_ENTRY_NUMBER_1] = (uint32_t) &R_CSGRD_CTL_RRAM00->RSG[1],
    [BSP_GUARD_PROTECTION_RETENTION_RAM][BSP_XSG_ENTRY_NUMBER_2] = (uint32_t) &R_CSGRD_CTL_RRAM00->RSG[2],
    [BSP_GUARD_PROTECTION_RETENTION_RAM][BSP_XSG_ENTRY_NUMBER_3] = (uint32_t) &R_CSGRD_CTL_RRAM00->RSG[3]
};

const uint32_t g_xram_guard_protection_status_baseaddress[BSP_GUARD_PROTECTION_RAM_NUM] =
{
    [BSP_GUARD_PROTECTION_CPU_RAM]       = (uint32_t) R_CRGRD_CAP_CPURAMIH00_BASE,
    [BSP_GUARD_PROTECTION_GLOBAL_RAM]    = (uint32_t) R_CRGRD_CAP_GRAMIH00_BASE,
    [BSP_GUARD_PROTECTION_RETENTION_RAM] = (uint32_t) R_CRGRD_CAP_RRAMIH00_BASE
};

const uint32_t g_xram_guard_protection_register_baseaddress[BSP_GUARD_PROTECTION_RAM_NUM] =
{
    [BSP_GUARD_PROTECTION_CPU_RAM]       = (uint32_t) R_CRGRD_CTL_CPURAM00_BASE,
    [BSP_GUARD_PROTECTION_GLOBAL_RAM]    = (uint32_t) R_CRGRD_CTL_GRAM00_BASE,
    [BSP_GUARD_PROTECTION_RETENTION_RAM] = (uint32_t) R_CRGRD_CTL_RRAM00_BASE
};

/* Array of all IBG groups base address */
const uint32_t g_igbprot_baseaddress[BSP_IBG_GROUP_NUM] =
{
    [BSP_IBG_GROUP_00] = (uint32_t) R_IGRD00_CTL0_BASE,
    [BSP_IBG_GROUP_10] = (uint32_t) R_IGRD01_CTL0_BASE,
    [BSP_IBG_GROUP_11] = (uint32_t) R_IGRD01_CTL1_BASE
};

const uint32_t g_ibg_protection_register_baseaddress[BSP_IBG_GROUP_NUM] =
{
    [BSP_IBG_GROUP_00] = (uint32_t) &R_IGRD00_CAP0->IBG0KCPROT,
    [BSP_IBG_GROUP_10] = (uint32_t) R_IGRD1KCPROT_BASE,
    [BSP_IBG_GROUP_11] = (uint32_t) R_IGRD1KCPROT_BASE
};

const bsp_module_igb_info_t g_xram_ibg_protection[BSP_GUARD_PROTECTION_RAM_NUM] =
{
    [BSP_GUARD_PROTECTION_CPU_RAM] =
    {
    .ibg_group = BSP_IBG_GROUP_00,
    .channel   = 1 << 8
    },
    [BSP_GUARD_PROTECTION_GLOBAL_RAM] =
    {
    .ibg_group = BSP_IBG_GROUP_00,
    .channel   = 1 << 3,
    },
    [BSP_GUARD_PROTECTION_RETENTION_RAM] =
    {
    .ibg_group = BSP_IBG_GROUP_00,
    .channel   = 1 << 3
    }
};
