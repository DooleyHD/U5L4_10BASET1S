/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "bsp_cpu.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Mask to select CP bits(0xF00000) */
#define BSP_CPU_CP_MASK    (0xFU << 20)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/
extern void * __Vectors[];

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Enables the Instruction Cache.
 *
 * @retval None
 **********************************************************************************************************************/
void R_BSP_ICacheEnable (void)
{
    /* Flush is not in progress */
    if (0U != R_CCACHE0->CCAFCT_b.FC)
    {
        FSP_HARDWARE_REGISTER_WAIT(R_CCACHE0->CCAFCT_b.FC, 0U);

        /* Cache enable and Flush Cache */
        R_CCACHE0->CCACTL = R_CCACHE0_CCACTL_ENC_Msk;
    }
    else
    {
        R_CCACHE0->CCACTL = (R_CCACHE0_CCACTL_FC_Msk | R_CCACHE0_CCACTL_ENC_Msk);

        /* Waiting for flush is completed */
        FSP_HARDWARE_REGISTER_WAIT(R_CCACHE0->CCAFCT_b.FC, 0U);
    }

    /* Flush is not in progress */
    if (0U != R_PFBUF0->PFBFCT_b.FB)
    {
        /* Waiting for flush is completed */
        FSP_HARDWARE_REGISTER_WAIT(R_PFBUF0->PFBFCT_b.FB, 0U);

        R_PFBUF0->PFBCTL = (R_PFBUF0_PFBCTL_ENB_Msk);
    }
    else
    {
        R_PFBUF0->PFBCTL = (R_PFBUF0_PFBCTL_FB_Msk | R_PFBUF0_PFBCTL_ENB_Msk);

        /* Waiting for flush is completed */
        FSP_HARDWARE_REGISTER_WAIT(R_PFBUF0->PFBFCT_b.FB, 0U);
    }

    /* Flush is not in progress */
    if (0U != R_MBBUF0->MBBFCT_b.FB)
    {
        R_MBBUF0->MBBCTL = (R_MBBUF0_MBBCTL_ENP_Msk | R_MBBUF0_MBBCTL_ENB_Msk);

        /* Waiting for flush is completed */
        FSP_HARDWARE_REGISTER_WAIT(R_MBBUF0->MBBFCT_b.FB, 0U);
    }
    else
    {
        R_MBBUF0->MBBCTL = (R_MBBUF0_MBBCTL_FB_Msk | R_MBBUF0_MBBCTL_ENP_Msk | R_MBBUF0_MBBCTL_ENB_Msk);

        /* Waiting for flush is completed */
        FSP_HARDWARE_REGISTER_WAIT(R_MBBUF0->MBBFCT_b.FB, 0U);
    }
}

/***********************************************************************************************************************
 * Disables the Instruction Cache.
 *
 * @retval None
 **********************************************************************************************************************/
void R_BSP_ICacheDisable (void)
{
    /* Cache disable and Flush Cache */
    R_CCACHE0->CCACTL = (R_CCACHE0_CCACTL_FC_Msk);

    /* Flush is completed */
    FSP_HARDWARE_REGISTER_WAIT(R_CCACHE0->CCAFCT_b.FC, 0U);

    /* Cache disable and Flush Cache */
    R_PFBUF0->PFBCTL = (R_PFBUF0_PFBCTL_FB_Msk);

    /* Flush is completed */
    FSP_HARDWARE_REGISTER_WAIT(R_PFBUF0->PFBFCT_b.FB, 0U);

    /* Cache disable and Flush Cache */
    R_MBBUF0->MBBCTL = (R_MBBUF0_MBBCTL_FB_Msk);

    /* Flush is completed */
    FSP_HARDWARE_REGISTER_WAIT(R_MBBUF0->MBBFCT_b.FB, 0U);
}

/***********************************************************************************************************************
 * Enables the Data Cache. Data cache is not available on R-Car U5L, so this function does nothing.
 *
 * @retval None
 **********************************************************************************************************************/
void R_BSP_DCacheEnable (void)
{
    /* Do nothing. Data cache is not available on R-Car U5L. */
}

/***********************************************************************************************************************
 * Disables the Data Cache. Data cache is not available on R-Car U5L, so this function does nothing.
 *
 * @retval None
 **********************************************************************************************************************/
void R_BSP_DCacheDisable (void)
{
    /* Do nothing. Data cache is not available on R-Car U5L. */
}

/***********************************************************************************************************************
 * Perform R-Car U5L specific CPU initialization. This function is called from SystemInit() during startup.
 **********************************************************************************************************************/
void bsp_cpu_init (void)
{
#if !BSP_TZ_NONSECURE_BUILD

    /* VTOR is in undefined state out of RESET:
     * https://developer.arm.com/documentation/100235/0004/the-cortex-m33-peripherals/system-control-block/system-control-block-registers-summary?lang=en.
     * Set the Secure/Non-Secure VTOR to the vector table address based on the build. This is skipped for non-secure
     * projects because SCB_NS->VTOR is set by the secure project before the non-secure project runs. */
    SCB->VTOR = (uint32_t) &__Vectors;
#endif

#if __FPU_USED

    /* Enable the FPU only when it is used.
     * Set bits 20-23 (CP10 and CP11) to enable FPU. */
    SCB->CPACR = (uint32_t) BSP_CPU_CP_MASK;
#endif

#if BSP_CFG_CPU_CORE_INSTRUCTION_CACHE
    R_BSP_ICacheEnable();
#endif
}
