/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_CLOCKS_DRIVER_H
#define BSP_CLOCKS_DRIVER_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_CLOCK_DIVIDED_BY_2_DIV_16     (0x02U)
#define BSP_CLOCK_DIVIDED_BY_4_DIV_16     (0x04U)
#define BSP_CLOCK_DIVIDED_BY_6_DIV_16     (0x06U)
#define BSP_CLOCK_DIVIDED_BY_8_DIV_16     (0x08U)
#define BSP_CLOCK_DIVIDED_BY_10_DIV_16    (0x0AU)
#define BSP_CLOCK_DIVIDED_BY_12_DIV_16    (0x0CU)
#define BSP_CLOCK_DIVIDED_BY_14_DIV_16    (0x0EU)
#define BSP_CLOCK_NO_DIVISION             (0x0000U)
#define BSP_CFG_CLOCK_HAS_NO_SUBOSC_HZ    (0U)

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RCARMCUU5L
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/* Enum used in R_FSP_SystemClockHzGet.  Maps clock name to base bit in SCKDIVCR. */
typedef enum e_fsp_priv_clock
{
    FSP_PRIV_CLOCK_HSOSC = 0,          /* HS intOSC Clock */
    FSP_PRIV_CLOCK_LSOSC,              /* LS intOSC Clock */

    FSP_PRIV_CLOCK_IOSC0,              /* Internal OSC 0 Clock */
    FSP_PRIV_CLOCK_IOSC1,              /* Internal OSC 1 Clock */

    FSP_PRIV_CLOCK_MAINOSC,            /* MainOSC Clock */
    FSP_PRIV_CLOCK_SUBOSC,             /* Sub OSC Clock */

    FSP_PRIV_CLOCK_PLL0,               /* PLL0  Clock */
    FSP_PRIV_CLOCK_PLL0OUT,            /* PLL0 Out Clock */

    FSP_PRIV_CLOCK_PLL1,               /* PLL1 Clock */
    FSP_PRIV_CLOCK_PLL1OUT,            /* PLL1 Out Clock */

    FSP_PRIV_CLOCK_SYSO,               /* SYS0 Clock */
    FSP_PRIV_CLOCK_SYS1,               /* SYS1 Clock */

    FSP_PRIV_CLOCK_CPU,                /* CPU Clock */
    FSP_PRIV_CLOCK_BUS2,               /* BUS2 Clock */
    FSP_PRIV_CLOCK_BUS4,               /* BUS4 Clock */
    FSP_PRIV_CLOCK_BUS8,               /* BUS8 Clock */
    FSP_PRIV_CLOCK_BUS16,              /* BUS16 Clock */

    FSP_PRIV_CLOCK_P100,               /* P100 Clock */
    FSP_PRIV_CLOCK_P160,               /* P160 Clock */
    FSP_PRIV_CLOCK_P080,               /* P080 Clock */
    FSP_PRIV_CLOCK_P040,               /* P040 Clock */

    FSP_PRIV_CLOCK_FLI,                /* FLI Clock */
    FSP_PRIV_CLOCK_FACI,               /* FACI Clock */
    FSP_PRIV_CLOCK_LPS,                /* LPS Clock */
    FSP_PRIV_CLOCK_WDTBA,              /* WDTBA Clock */
    FSP_PRIV_CLOCK_RTCA,               /* RTCA Clock */
    FSP_PRIV_CLOCK_ADC0,               /* ADC0 Clock */
    FSP_PRIV_CLOCK_EXTCLK0O,           /* EXTCLK0O Clock */
    FSP_PRIV_CLOCK_EXTCLK1O,           /* EXTCLK1O Clock */
    FSP_PRIV_CLOCK_RLIN3,              /* RLIN3 Clock */
    FSP_PRIV_CLOCK_WDTB,               /* WDTB Clock */
    FSP_PRIV_CLOCK_ECMCNT,             /* ECMCNT Clock */

    /* Clock in CyclicRUN mode */
    FSP_PRIV_CLOCK_CPU_CYCLICRUN,      /* CPU Clock in CyclicRUN mode */
    FSP_PRIV_CLOCK_BUS2_CYCLICRUN,     /* BUS2 Clock in CyclicRUN mode */
    FSP_PRIV_CLOCK_BUS4_CYCLICRUN,     /* BUS4 Clock in CyclicRUN mode */
    FSP_PRIV_CLOCK_BUS8_CYCLICRUN,     /* BUS8 Clock in CyclicRUN mode */
    FSP_PRIV_CLOCK_BUS16_CYCLICRUN,    /* BUS16 Clock in CyclicRUN mode */

    FSP_PRIV_CLOCK_P100_CYCLICRUN,     /* P100 Clock in CyclicRUN mode */
    FSP_PRIV_CLOCK_P160_CYCLICRUN,     /* P160 Clock in CyclicRUN mode */
    FSP_PRIV_CLOCK_P080_CYCLICRUN,     /* P080 Clock in CyclicRUN mode */
    FSP_PRIV_CLOCK_P040_CYCLICRUN,     /* P040 Clock in CyclicRUN mode */

    FSP_PRIV_CLOCK_FLI_CYCLICRUN,      /* FLI Clock in CyclicRUN mode */
    FSP_PRIV_CLOCK_FACI_CYCLICRUN,     /* FACI Clock in CyclicRUN mode */
    FSP_PRIV_CLOCK_EXTCLK1O_CYCLICRUN, /* EXTCLK1O Clock in CyclicRUN mode */
    FSP_PRIV_CLOCK_RLIN3_CYCLICRUN,    /* RLIN3 Clock in CyclicRUN mode */
    FSP_PRIV_CLOCK_ADC0_CYCLICRUN,     /* ADC0 Clock in CyclicRUN mode */

    FSP_PRIV_CLOCK_NUM,
} fsp_priv_clock_t;

/** @} (end addtogroup BSP_MCU_RCARMCUU5L) */

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern uint32_t g_clock_freq[FSP_PRIV_CLOCK_NUM];

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/* Public functions defined in bsp.h */
void bsp_clock_driver_init(void);      // Used internally by BSP
void bsp_clock_gear_down();            // Used internally by BSP

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
