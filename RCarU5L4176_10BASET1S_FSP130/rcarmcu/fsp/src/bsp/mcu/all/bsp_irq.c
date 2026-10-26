/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_PRV_IMFG_MASKED_ALL    0xFF

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/* This table is used to store the context in the ISR. */
void * gp_renesas_isr_context[BSP_ICU_IRQ_NUM_MAX_ENTRIES];

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_COMMON
 *
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_COMMON) */

/*******************************************************************************************************************//**
 * Initialize interrupt merge group.
 **********************************************************************************************************************/
void bsp_irq_cfg (void)
{
#if defined(BSP_FEATURE_DEVICE_HAS_INTERRUPT_MERGE)
    uint8_t irq_group;
    uint8_t irq_type;

    for (uint32_t irq = 0U; irq < sizeof(g_bsp_imf_infor_isr_table) / sizeof(g_bsp_imf_infor_isr_table[0]); irq++)
    {
        irq_group = (uint8_t) ((g_bsp_imf_infor_isr_table[irq] >> BSP_IMF_GROUP_SHIFT) & BSP_IMF_MASK_BYTE);
        irq_type  = (uint8_t) ((g_bsp_imf_infor_isr_table[irq] >> BSP_IMF_TYPE_SHIFT) & BSP_IMF_MASK_BYTE);

        if (BSP_IMF_ICU_IRQ_TYPE_PULSE == irq_type)
        {
            /* Mask all interrupt in pulse merge group */
            R_IMFU0->IMFUP[irq_group].IMFUPMSK = BSP_PRV_IMFG_MASKED_ALL;
        }
        else if (BSP_IMF_ICU_IRQ_TYPE_LEVEL == irq_type)
        {
            R_IMFU0->IMFUL[irq_group].IMFULMSK = BSP_PRV_IMFG_MASKED_ALL;
        }
        else
        {
            /* Do nothing */
        }
    }
#endif
}
