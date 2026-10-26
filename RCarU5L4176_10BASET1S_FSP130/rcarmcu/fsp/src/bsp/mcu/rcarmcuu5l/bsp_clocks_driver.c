/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "bsp_clocks_driver.h"

#if BSP_TZ_NONSECURE_BUILD
 #include "bsp_guard.h"
#endif

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

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RCARMCUU5L
 * @{
 **********************************************************************************************************************/

/* This array stores the clock frequency of each bus clock. This section of RAM should not be initialized by the C
 * runtime environment. This is initialized and used in bsp_clock_init, which is called before the C runtime
 * environment is initialized. */

uint32_t g_clock_freq[FSP_PRIV_CLOCK_NUM] =
{
    [FSP_PRIV_CLOCK_HSOSC] = BSP_CFG_CLOCK_HSIOSC_HZ,
    [FSP_PRIV_CLOCK_LSOSC] = BSP_CFG_CLOCK_LSIOSC_HZ,

    [FSP_PRIV_CLOCK_IOSC0] = BSP_CFG_CLOCK_IOSC0_HZ,
    [FSP_PRIV_CLOCK_IOSC1] = BSP_CFG_CLOCK_IOSC1_HZ,

    [FSP_PRIV_CLOCK_MAINOSC] = BSP_CFG_CLOCK_MAINOSC_HZ,
#if (BSP_FEATURE_SUB_OSC_IS_AVAILABLE)
    [FSP_PRIV_CLOCK_SUBOSC] = BSP_CFG_CLOCK_SUBOSC_HZ,
#else
    [FSP_PRIV_CLOCK_SUBOSC] = BSP_CFG_CLOCK_HAS_NO_SUBOSC_HZ,
#endif                                 /* #if (BSP_FEATURE_SUB_OSC_IS_AVAILABLE) */

    [FSP_PRIV_CLOCK_PLL0]    = BSP_CFG_CLOCK_PLL0_HZ,
    [FSP_PRIV_CLOCK_PLL0OUT] = BSP_CFG_CLOCK_PLL0OUT_HZ,

    [FSP_PRIV_CLOCK_PLL1]    = BSP_CFG_CLOCK_PLL1_HZ,
    [FSP_PRIV_CLOCK_PLL1OUT] = BSP_CFG_CLOCK_PLL1OUT_HZ,

    [FSP_PRIV_CLOCK_SYSO] = BSP_CFG_CLOCK_SYS0_HZ,
    [FSP_PRIV_CLOCK_SYS1] = BSP_CFG_CLOCK_SYS1_HZ,

    [FSP_PRIV_CLOCK_CPU]   = BSP_CFG_CLOCK_CPU_HZ,
    [FSP_PRIV_CLOCK_BUS2]  = BSP_CFG_CLOCK_BUS2_HZ,
    [FSP_PRIV_CLOCK_BUS4]  = BSP_CFG_CLOCK_BUS4_HZ,
    [FSP_PRIV_CLOCK_BUS8]  = BSP_CFG_CLOCK_BUS8_HZ,
    [FSP_PRIV_CLOCK_BUS16] = BSP_CFG_CLOCK_BUS16_HZ,

    [FSP_PRIV_CLOCK_P100] = BSP_CFG_CLOCK_P100_HZ,
    [FSP_PRIV_CLOCK_P160] = BSP_CFG_CLOCK_P160_HZ,
    [FSP_PRIV_CLOCK_P080] = BSP_CFG_CLOCK_P080_HZ,
    [FSP_PRIV_CLOCK_P040] = BSP_CFG_CLOCK_P040_HZ,

    [FSP_PRIV_CLOCK_FLI]      = BSP_CFG_CLOCK_FLI_HZ,
    [FSP_PRIV_CLOCK_FACI]     = BSP_CFG_CLOCK_FACI_HZ,
    [FSP_PRIV_CLOCK_LPS]      = BSP_CFG_CLOCK_LPS_HZ,
    [FSP_PRIV_CLOCK_WDTBA]    = BSP_CFG_CLOCK_WDTBA_HZ,
    [FSP_PRIV_CLOCK_RTCA]     = BSP_CFG_CLOCK_RTCA_HZ,
    [FSP_PRIV_CLOCK_ADC0]     = BSP_CFG_CLOCK_ADC0_HZ,
    [FSP_PRIV_CLOCK_EXTCLK0O] = BSP_CFG_CLOCK_EXTCLK0_HZ,
    [FSP_PRIV_CLOCK_EXTCLK1O] = BSP_CFG_CLOCK_EXTCLK1_HZ,
    [FSP_PRIV_CLOCK_RLIN3]    = BSP_CFG_CLOCK_RLIN3_HZ,
    [FSP_PRIV_CLOCK_WDTB]     = BSP_CFG_CLOCK_WDTB_HZ,
    [FSP_PRIV_CLOCK_ECMCNT]   = BSP_CFG_CLOCK_ECM_HZ,

    /* Clock in CyclicRUN mode */
    [FSP_PRIV_CLOCK_CPU_CYCLICRUN]   = BSP_CFG_CLOCK_CPU_CYCLICRUN_HZ,
    [FSP_PRIV_CLOCK_BUS2_CYCLICRUN]  = BSP_CFG_CLOCK_BUS2_CYCLICRUN_HZ,
    [FSP_PRIV_CLOCK_BUS4_CYCLICRUN]  = BSP_CFG_CLOCK_BUS4_CYCLICRUN_HZ,
    [FSP_PRIV_CLOCK_BUS8_CYCLICRUN]  = BSP_CFG_CLOCK_BUS8_CYCLICRUN_HZ,
    [FSP_PRIV_CLOCK_BUS16_CYCLICRUN] = BSP_CFG_CLOCK_BUS16_CYCLICRUN_HZ,

    [FSP_PRIV_CLOCK_P100_CYCLICRUN] = BSP_CFG_CLOCK_P100_CYCLICRUN_HZ,
    [FSP_PRIV_CLOCK_P160_CYCLICRUN] = BSP_CFG_CLOCK_P160_CYCLICRUN_HZ,
    [FSP_PRIV_CLOCK_P080_CYCLICRUN] = BSP_CFG_CLOCK_P080_CYCLICRUN_HZ,
    [FSP_PRIV_CLOCK_P040_CYCLICRUN] = BSP_CFG_CLOCK_P040_CYCLICRUN_HZ,

    [FSP_PRIV_CLOCK_FLI_CYCLICRUN]  = BSP_CFG_CLOCK_FLI_CYCLICRUN_HZ,
    [FSP_PRIV_CLOCK_FACI_CYCLICRUN] = BSP_CFG_CLOCK_FACI_CYCLICRUN_HZ,

    [FSP_PRIV_CLOCK_EXTCLK1O_CYCLICRUN] = BSP_CFG_CLOCK_EXTCLK1_CYCLICRUN_HZ,
    [FSP_PRIV_CLOCK_RLIN3_CYCLICRUN]    = BSP_CFG_CLOCK_RLIN3_CYCLICRUN_HZ,
    [FSP_PRIV_CLOCK_ADC0_CYCLICRUN]     = BSP_CFG_CLOCK_ADC0_CYCLICRUN_HZ
};

const uint32_t g_gear_up_repetitions_arr[] =
{
    BSP_CLOCK_DIVIDED_BY_4_DIV_16,
    BSP_CLOCK_DIVIDED_BY_6_DIV_16,
    BSP_CLOCK_DIVIDED_BY_8_DIV_16,
    BSP_CLOCK_DIVIDED_BY_10_DIV_16,
    BSP_CLOCK_DIVIDED_BY_12_DIV_16,
    BSP_CLOCK_DIVIDED_BY_14_DIV_16,
    BSP_CLOCK_NO_DIVISION
};

const uint32_t g_gear_down_repetitions_arr[] =
{
    BSP_CLOCK_DIVIDED_BY_14_DIV_16,
    BSP_CLOCK_DIVIDED_BY_12_DIV_16,
    BSP_CLOCK_DIVIDED_BY_10_DIV_16,
    BSP_CLOCK_DIVIDED_BY_8_DIV_16,
    BSP_CLOCK_DIVIDED_BY_6_DIV_16,
    BSP_CLOCK_DIVIDED_BY_4_DIV_16,
    BSP_CLOCK_DIVIDED_BY_2_DIV_16,
};

bsp_chip_standby_mode_t g_chip_standby_mode = BSP_RUN_MODE;

/*******************************************************************************************************************//**
 * Initializes system clocks.  Makes no assumptions about current register settings.
 **********************************************************************************************************************/
void bsp_clock_driver_init (void)
{
#if (0 == BSP_CFG_CLK_SYS0_SRC) || (0 == BSP_CFG_CLK_SYS1_SRC)
    uint8_t repetition_count     = 0;
    uint8_t total_of_repetitions = 0;

    /* Get the total of repetitions */
    total_of_repetitions = (sizeof(g_gear_up_repetitions_arr) / sizeof(g_gear_up_repetitions_arr[0]));
#endif

#if BSP_CLOCK_SUPPORT_IN_CYCLICRUN_ENABLE

    /* Get the chip standby mode */
    R_BSP_CheckChipStandByMode();
#endif

    /* Enable write protect of clock controller */
    R_SYS0_CLOCK->CLKKCPROT1 = BSP_PRV_KEYCODE_ENABLE;

    /* Confirm HS IntOSC is stable*/
    FSP_HARDWARE_REGISTER_WAIT(R_SYS0_A_CLOCK->HSOSCS, R_SYS0_A_CLOCK_HSOSCS_HSOSCSTAB_Msk);

#if (BSP_CFG_CLOCK_MAINOSC_HZ > 0)

    /* Confirm Main OSC is stopped */
    if (0UL == R_SYS0_A_CLOCK->MOSCS)
    {
        R_SYS0_A_CLOCK->MOSCE = R_SYS0_A_CLOCK_MOSCE_MOSCENTRG_Msk;

        /* Confirm that the Main OSC has been stable
         * (MOSCS.MOSCEN = 1 & MOSCS.MOSCSTAB = 1)*/
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_A_CLOCK->MOSCS, 0x03);
    }
#else

    /* Confirm that the Main OSC is stable */
    if (1UL == R_SYS0_A_CLOCK->MOSCS_b.MOSCSTAB)
    {
        R_SYS0_A_CLOCK->MOSCE = R_SYS0_A_CLOCK_MOSCE_MOSCDISTRG_Msk;

        /* Confirm that the Main OSC has been stopped
         * (MOSCS.MOSCEN = 0 & MOSCS.MOSCSTAB = 0).*/
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_A_CLOCK->MOSCS, 0x00);
    }
#endif                                 /* End of (BSP_CFG_CLOCK_MAINOSC_HZ > 0) */

#if (BSP_FEATURE_SUB_OSC_IS_AVAILABLE)
 #if (BSP_CFG_CLOCK_SUBOSC_HZ > 0)

    /* Confirm Sub OSC is stopped */
    if (0UL == R_SYS0_A_CLOCK->SOSCS)
    {
        R_SYS0_A_CLOCK->SOSCE = R_SYS0_A_CLOCK_SOSCE_SOSCENTRG_Msk;

        /* Confirm that the Sub OSC has been stable
         * (SOSCS.SOSCEN = 1 & SOSCS.SOSCSTAB = 1)*/
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_A_CLOCK->SOSCS, 0x03);
    }
 #else

    /* Confirm that the Sub OSC is stable */
    if (1UL == R_SYS0_A_CLOCK->SOSCS_b.SOSCSTAB)
    {
        R_SYS0_A_CLOCK->SOSCE = R_SYS0_A_CLOCK_SOSCE_SOSCDISTRG_Msk;

        /* Confirm that the Sub OSC has been stopped
         * (SOSCS.SOSCEN = 0 & SOSCS.SOSCSTAB = 0).*/
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_A_CLOCK->SOSCS, 0x00);
    }
 #endif                                /* End of (BSP_CFG_CLOCK_SUBOSC_HZ > 0) */
#endif /* #if (BSP_FEATURE_SUB_OSC_IS_AVAILABLE) */

    if ((0UL == R_SYS0_CLOCK->PLLS)
#if BSP_CLOCK_SUPPORT_IN_CYCLICRUN_ENABLE
        && (BSP_CYCLICRUN_MODE != g_chip_standby_mode)
#endif
        )
    {
        R_SYS0_CLOCK->CKS_PLLINC = BSP_CFG_CLK_PLLIN_SRC;

        /* Confirm that CKS_PLLINS.PLLINSACT register
         * becomes same value with CKS_PLLINC.PLLINSCSID */
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKS_PLLINS, BSP_CFG_CLK_PLLIN_SRC);

        /* Start PLL */
        R_SYS0_CLOCK->PLLE = R_SYS0_CLOCK_PLLE_PLLENTRG_Msk;

        /* Confirm that the PLL0/1 have been stable
         * (PLLS.PLLCLKEN = 1 & PLLS.PLLCLKSTAB = 1)*/
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->PLLS, 0x03);
    }

#if (0 == BSP_CFG_CLK_SYS0_SRC)
 #if BSP_CLOCK_SUPPORT_IN_CYCLICRUN_ENABLE
    if (BSP_CYCLICRUN_MODE != g_chip_standby_mode)
 #endif
    {
        /* Shifting the System Clock Gear Up for System Clock */

        /* Division ratio of clock source PLL0 are changed from 1 to 2/16 */
        R_SYS0_CLOCK->CKD_PLL0C = BSP_CLOCK_DIVIDED_BY_2_DIV_16;

        /* Confirm that PLL0 divider is synchronized */
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKD_PLL0S, R_SYS0_CLOCK_CKD_PLL0S_PLLCLKDSYNC_Msk);

        /* Setting PLLO for Clock SYS0 */
        R_SYS0_CLOCK->CKS_SYS0C = BSP_CFG_CLK_SYS0_SRC;

        /* Confirm that PLLO have been selected */
        FSP_HARDWARE_REGISTER_WAIT(BSP_CFG_CLK_SYS0_SRC, R_SYS0_CLOCK->CKS_SYS0S);

        /* Delay 100us */
        R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MICROSECONDS);

        /* Start of repetition 7 repetitions for Gear up*/
        for (repetition_count = 0; repetition_count < total_of_repetitions; repetition_count++)
        {
            /* Write the Divider value to PLL0 */
            R_SYS0_CLOCK->CKD_PLL0C = g_gear_up_repetitions_arr[repetition_count];

            /* Confirm that PLL0 dividers are synchronized */
            FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKD_PLL0S, R_SYS0_CLOCK_CKD_PLL0S_PLLCLKDSYNC_Msk);
        }

        /* Delay 100us */
        R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MICROSECONDS);
    }
#else                                  /* (1 == BSP_CFG_CLK_SYS0_SRC) */
    /* Setting CLK_IOSC1 for SYS0 clock source*/
    R_SYS0_CLOCK->CKS_SYS0C = BSP_CFG_CLK_SYS0_SRC;
    FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKS_SYS0C, R_SYS0_CLOCK->CKS_SYS0S);
#endif /* End of (0 == BSP_CFG_CLK_SYS0_SRC) */

#if (0 == BSP_CFG_CLK_SYS1_SRC)
 #if BSP_CLOCK_SUPPORT_IN_CYCLICRUN_ENABLE
    if (BSP_CYCLICRUN_MODE != g_chip_standby_mode)
 #endif
    {
        /* Shifting the System Clock Gear Up for System Clock */

        /* Division ratio of clock source PLL1 are changed from 1 to 2/16 */
        R_SYS0_CLOCK->CKD_PLL1C = BSP_CLOCK_DIVIDED_BY_2_DIV_16;

        /* Confirm that PLL1 divider is synchronized */
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKD_PLL1S, R_SYS0_CLOCK_CKD_PLL1S_PLLCLKDSYNC_Msk);

        /* Setting PLLO for Clock SYS1 */
        R_SYS0_CLOCK->CKS_SYS1C = BSP_CFG_CLK_SYS1_SRC;

        /* Confirm that PLLO have been selected */
        FSP_HARDWARE_REGISTER_WAIT(BSP_CFG_CLK_SYS1_SRC, R_SYS0_CLOCK->CKS_SYS1S);

        /* Delay 100us */
        R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MICROSECONDS);

        /* Start of repetition 7 repetitions for Gear up*/
        for (repetition_count = 0; repetition_count < total_of_repetitions; repetition_count++)
        {
            /* Write the Divider value to PLL1 */
            R_SYS0_CLOCK->CKD_PLL1C = g_gear_up_repetitions_arr[repetition_count];

            /* Confirm that PLL1 dividers are synchronized */
            FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKD_PLL1S, R_SYS0_CLOCK_CKD_PLL1S_PLLCLKDSYNC_Msk);
        }

        /* Delay 100us */
        R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MICROSECONDS);
    }
#else                                  /* (1 == BSP_CFG_CLK_SYS1_SRC) */
    /* Setting CLK_IOSC1 SYS1 clock source*/
    R_SYS0_CLOCK->CKS_SYS1C = BSP_CFG_CLK_SYS1_SRC;
    FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKS_SYS1C, R_SYS0_CLOCK->CKS_SYS1S);
#endif /* End of (0 == BSP_CFG_CLK_SYS1_SRC) */

#if BSP_CLOCK_SUPPORT_IN_CYCLICRUN_ENABLE
    if (BSP_CYCLICRUN_MODE == g_chip_standby_mode)
    {
        /* Setting RLIN clock source*/
        R_SYS0_CLOCK->CKS_RLINC = BSP_CFG_CLK_RLIN3_CYCLICRUN_SRC;
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKS_RLINC, R_SYS0_CLOCK->CKS_RLINS);

        /* Setting ADC0 clock source*/
        R_SYS0_A_CLOCK->CKS_AADCC = BSP_CFG_CLK_ADC0_CYCLICRUN_SRC;
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_A_CLOCK->CKS_AADCC, R_SYS0_A_CLOCK->CKS_AADCS);
    }
    else
#endif
    {
        /* Setting RLIN clock source*/
        R_SYS0_CLOCK->CKS_RLINC = BSP_CFG_CLK_RLIN3_SRC;
        FSP_HARDWARE_REGISTER_WAIT(BSP_CFG_CLK_RLIN3_SRC, R_SYS0_CLOCK->CKS_RLINS);

        /* Setting ADC0 clock source*/
        R_SYS0_A_CLOCK->CKS_AADCC = BSP_CFG_CLK_ADC0_SRC;
        FSP_HARDWARE_REGISTER_WAIT(BSP_CFG_CLK_ADC0_SRC, R_SYS0_A_CLOCK->CKS_AADCS);
    }

    /* Setting RTCA clock source*/
    R_SYS0_A_CLOCK->CKS_ARTCAC = BSP_CFG_CLK_RTCA_SRC;
    FSP_HARDWARE_REGISTER_WAIT(BSP_CFG_CLK_RTCA_SRC, R_SYS0_A_CLOCK->CKS_ARTCAS);

    /* These Clocks are not supported in U5x Toolbox v0.4.1 */
#if BSP_VLAB_HARDWARE_BASED_USED == 0

    /* Setting LPS clock source*/
    R_SYS0_A_CLOCK->CKS_ALPSC = BSP_CFG_CLK_LPS_SRC;
    FSP_HARDWARE_REGISTER_WAIT(BSP_CFG_CLK_LPS_SRC, R_SYS0_A_CLOCK->CKS_ALPSS);

 #if BSP_CFG_CLK_EXTCLK0_DIV > 0

    /* Confirm clock divider is stable */
    FSP_HARDWARE_REGISTER_WAIT(R_SYS0_A_CLOCK->CKD_EXTCLK0S_b.EXTCLK0SYNC, 1);

    /* Stop EXTCLK0O before setting EXTCLK0 clock source */
    R_SYS0_A_CLOCK->CKD_EXTCLK0C = 0x00U;
    FSP_HARDWARE_REGISTER_WAIT(R_SYS0_A_CLOCK->CKD_EXTCLK0C, 0x00U);

    /* Setting EXTCLK0 clock source*/
    R_SYS0_A_CLOCK->CKS_EXTCLK0C = BSP_CFG_CLK_EXTCLK0_SRC;
    FSP_HARDWARE_REGISTER_WAIT(R_SYS0_A_CLOCK->CKS_EXTCLK0C, R_SYS0_A_CLOCK->CKS_EXTCLK0S);

    /* Setting EXTCLK0 divider*/

    /* Confirm clock divider is stable */
    FSP_HARDWARE_REGISTER_WAIT(R_SYS0_A_CLOCK->CKD_EXTCLK0S_b.EXTCLK0SYNC, 1);
    R_SYS0_A_CLOCK->CKD_EXTCLK0C = BSP_CFG_CLK_EXTCLK0_DIV;
    FSP_HARDWARE_REGISTER_WAIT(R_SYS0_A_CLOCK->CKD_EXTCLK0S, 0x03);
 #endif

 #if (BSP_CFG_CLK_EXTCLK1_DIV > 0) || (BSP_CFG_CLK_EXTCLK1_CYCLICRUN_DIV > 0)

    /* Confirm clock divider is stable */
    FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKD_EXTCLK1S_b.EXTCLK1SYNC, 1);

    /* Stop EXTCLK1O before setting EXTCLK1 clock source */
    R_SYS0_CLOCK->CKD_EXTCLK1C = 0x00U;
    FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKD_EXTCLK1C, 0x00U);
  #if BSP_CLOCK_SUPPORT_IN_CYCLICRUN_ENABLE
    if (BSP_CYCLICRUN_MODE == g_chip_standby_mode)
    {
        /* Setting EXTCLK1 clock source*/
        R_SYS0_CLOCK->CKS_EXTCLK1C = BSP_CFG_CLK_EXTCLK1_CYCLICRUN_SRC;
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKS_EXTCLK1C, R_SYS0_CLOCK->CKS_EXTCLK1S);

        /* Setting EXTCLK1 divider*/

        /* Confirm clock divider is stable */
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKD_EXTCLK1S_b.EXTCLK1SYNC, 1);
        R_SYS0_CLOCK->CKD_EXTCLK1C = BSP_CFG_CLK_EXTCLK1_CYCLICRUN_DIV;
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKD_EXTCLK1S, 0x03);
    }
    else
  #endif
    {
        /* Setting EXTCLK1 clock source*/
        R_SYS0_CLOCK->CKS_EXTCLK1C = BSP_CFG_CLK_EXTCLK1_SRC;
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKS_EXTCLK1C, R_SYS0_CLOCK->CKS_EXTCLK1S);

        /* Setting EXTCLK1 divider*/

        /* Confirm clock divider is stable */
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKD_EXTCLK1S_b.EXTCLK1SYNC, 1);
        R_SYS0_CLOCK->CKD_EXTCLK1C = BSP_CFG_CLK_EXTCLK1_DIV;
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKD_EXTCLK1S, 0x03);
    }
 #endif
#endif                                 /* End of #if BSP_VLAB_HARDWARE_BASED_USED */

    /* Disable write protect of clock controller*/
    R_SYS0_CLOCK->CLKKCPROT1 = BSP_PRV_KEYCODE_DISABLE;
}

/*******************************************************************************************************************//**
 * System Clock Gear Down or In DeepStop Mode.
 **********************************************************************************************************************/
void bsp_clock_gear_down ()
{
    /* Enable write protect of clock controller */
    R_SYS0_CLOCK->CLKKCPROT1 = BSP_PRV_KEYCODE_ENABLE;
    uint32_t total_of_repetitions = (sizeof(g_gear_up_repetitions_arr) / sizeof(g_gear_up_repetitions_arr[0]));

    /* Start of repetition 7 repetitions for Gear Down*/
    for (uint32_t repetition_count = 0; repetition_count < total_of_repetitions; repetition_count++)
    {
#if (0 == BSP_CFG_CLK_SYS0_SRC)

        /* Write the Divider value to PLL0 */
        R_SYS0_CLOCK->CKD_PLL0C = g_gear_down_repetitions_arr[repetition_count];

        /* Confirm that PLL0 dividers are synchronized */
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKD_PLL0S, R_SYS0_CLOCK_CKD_PLL0S_PLLCLKDSYNC_Msk);
#endif
#if (0 == BSP_CFG_CLK_SYS1_SRC)

        /* Write the Divider value to PLL0 */
        R_SYS0_CLOCK->CKD_PLL1C = g_gear_down_repetitions_arr[repetition_count];

        /* Confirm that PLL0 dividers are synchronized */
        FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKD_PLL1S, R_SYS0_CLOCK_CKD_PLL1S_PLLCLKDSYNC_Msk);
#endif
    }

    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MICROSECONDS);

    R_SYS0_CLOCK->CKS_SYS1C = 1U;
    R_SYS0_CLOCK->CKS_SYS0C = 1U;

    FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKS_SYS1S, 1U);
    FSP_HARDWARE_REGISTER_WAIT(R_SYS0_CLOCK->CKS_SYS0S, 1U);

    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MICROSECONDS);

    R_SYS0_CLOCK->CLKKCPROT1 = BSP_PRV_KEYCODE_DISABLE;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup BSP_MCU_RCARMCUU5L)
 **********************************************************************************************************************/
