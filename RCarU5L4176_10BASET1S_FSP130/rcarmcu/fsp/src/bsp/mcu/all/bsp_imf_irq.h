/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_IMF_IRQ_H
#define BSP_IMF_IRQ_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern void               * gp_renesas_isr_context[BSP_IMF_ICU_IRQ_IMF_NUM_MAX_ENTRIES];
extern const IRQn_Type      g_bsp_imf_isr_table[BSP_IMF_ICU_IRQ_IMF_NUM_MAX_ENTRIES];
extern const bsp_imf_info_t g_bsp_imf_infor_isr_table[BSP_IMF_ICU_IRQ_IMF_NUM_MAX_ENTRIES];

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup BSP_COMMON
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief      Sets the ISR merge context associated with the requested IRQ.
 *
 * @param[in]  irq            IRQ merge number (parameter checking must ensure the IRQ number is valid before calling
 *                            this function.)
 * @param[in]  p_context      ISR context for IRQ merge.
 **********************************************************************************************************************/
__STATIC_INLINE void R_FSP_IsrMrgContextSet (bsp_imf_irqn_t const irq, void * p_context)
{
    uint8_t  irq_channel_no = (uint8_t) (irq & BSP_IMF_MASK_BYTE);
    uint8_t  irq_bit_assign = (uint8_t) ((irq >> BSP_IMF_BIT_SHIFT) & BSP_IMF_MASK_BYTE);
    uint32_t _irq           = (uint32_t) (g_bsp_imf_isr_table[irq_channel_no] + irq_bit_assign);
    gp_renesas_isr_context[_irq] = p_context;
}

/*******************************************************************************************************************//**
 * Clear the interrupt status flag (IR) for a given interrupt merge. When an interrupt is triggered the IR bit
 * is set. If it is not cleared in the ISR then the interrupt will trigger again immediately.
 *
 * @param[in] irq            Interrupt merge for which to clear the IR bit. Note that the enums listed for bsp_imf_irqn_t
 *                           are only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the bsp_imf_irqn_t value is < 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqMrgStatusClear (bsp_imf_irqn_t irq)
{
    uint8_t irq_bit_assign = (uint8_t) ((irq >> BSP_IMF_BIT_SHIFT) & BSP_IMF_MASK_BYTE);
    uint8_t irq_type       = (uint8_t) (irq >> BSP_IMF_TYPE_SHIFT);
    uint8_t irq_group      = (uint8_t) ((irq >> BSP_IMF_GROUP_SHIFT) & BSP_IMF_MASK_BYTE);

    if (irq_type == BSP_IMF_ICU_IRQ_TYPE_PULSE)
    {
        /* Clear IMFUPC Flags */
        R_IMFU0->IMFUP[irq_group].IMFUPC = (1 << irq_bit_assign);

        /* Dummy Read IMFUPC */
        uint32_t dummy = R_IMFU0->IMFUP[irq_group].IMFUPC;
        (void) dummy;
    }

    /* Do nothing */
}

/*******************************************************************************************************************//**
 * Clear the interrupt status flag (IR) for a given interrupt merge and clear the NVIC pending interrupt.
 *
 * @param[in] irq            Interrupt merge for which to clear the IR bit. Note that the enums listed for bsp_imf_irqn_t
 *                           are only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the bsp_imf_irqn_t value is < 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqMrgClearPending (bsp_imf_irqn_t irq)
{
    uint8_t _irq = (uint8_t) (irq & BSP_IMF_MASK_BYTE);

    /* The following statement is used in place of NVIC_ClearPendingIRQ to avoid including a branch for system
     * exceptions every time an interrupt is cleared in the NVIC. */

    /* Clear the IR bit in the selected IELSR register. */
    R_BSP_IrqMrgStatusClear(irq);

    /* Flush memory transactions to ensure that the IR bit is cleared before clearing the pending bit in the NVIC. */
    __DMB();
    NVIC->ICPR[(((uint32_t) _irq) >> 5UL)] = (uint32_t) (1UL << (_irq & 0x1FUL));
}

/*******************************************************************************************************************//**
 * Sets the interrupt merge priority and context.
 *
 * @param[in] irq            The IRQ merge to configure.
 * @param[in] priority       NVIC priority of the interrupt
 * @param[in] p_context      The interrupt merge context is a pointer to data required in the ISR.
 *
 * @warning Do not call this function for system exceptions where the bsp_imf_irqn_t value is < 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqMrgCfg (bsp_imf_irqn_t const irq, uint32_t priority, void * p_context)
{
    uint8_t _irq = (uint8_t) (irq & BSP_IMF_MASK_BYTE);

    /* The following statement is used in place of NVIC_SetPriority to avoid including a branch for system exceptions
     * every time a priority is configured in the NVIC. */
    NVIC->IPR[_irq] =
        (uint8_t) ((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t) UINT8_MAX);

    /* Store the context. The context is recovered in the ISR. */
    R_FSP_IsrMrgContextSet(irq, p_context);
}

/*******************************************************************************************************************//**
 * Enable the IRQ merge in the NVIC (Without clearing the pending bit).
 *
 * @param[in] irq            The IRQ merge to enable. Note that the enums listed for bsp_imf_irqn_t are only those for
 *                           the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the bsp_imf_irqn_t value is < 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqMrgEnableNoClear (bsp_imf_irqn_t const irq)
{
    uint8_t irq_bit_assign = (uint8_t) ((irq >> BSP_IMF_BIT_SHIFT) & BSP_IMF_MASK_BYTE);
    uint8_t irq_type       = (uint8_t) (irq >> BSP_IMF_TYPE_SHIFT);
    uint8_t irq_group      = (uint8_t) ((irq >> BSP_IMF_GROUP_SHIFT) & BSP_IMF_MASK_BYTE);
    uint8_t _irq           = (uint8_t) (irq & BSP_IMF_MASK_BYTE);

    if (irq_type == BSP_IMF_ICU_IRQ_TYPE_PULSE)
    {
        /* Unmask IMFU Pulse interrupt bit*/
        R_IMFU0->IMFUP[irq_group].IMFUPMSK = R_IMFU0->IMFUP[irq_group].IMFUPMSK &
                                             ((uint32_t) ~(1 << (irq_bit_assign)));
    }
    else if (irq_type == BSP_IMF_ICU_IRQ_TYPE_LEVEL)
    {
        /* Unmask IMFU Level interrupt bit*/
        R_IMFU0->IMFUL[irq_group].IMFULMSK = R_IMFU0->IMFUL[irq_group].IMFULMSK &
                                             ((uint32_t) ~(1 << (irq_bit_assign)));
    }
    else
    {
        /* Non-merge do nothing */
    }

    /* The following statement is used in place of NVIC_EnableIRQ to avoid including a branch for system exceptions
     * every time an interrupt is enabled in the NVIC. */

    __COMPILER_BARRIER();
    NVIC->ISER[(_irq >> 5UL)] = (uint32_t) (1UL << (_irq & 0x1FUL));
    __COMPILER_BARRIER();
}

/*******************************************************************************************************************//**
 * Clears pending interrupt merge in both ICU and NVIC, then enables the interrupt.
 *
 * @param[in] irq            Interrupt merge for which to clear the IR bit and enable in the NVIC. Note that the enums
 *                           listed for bsp_imf_irqn_t are only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the bsp_imf_irqn_t value is < 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqMrgEnable (bsp_imf_irqn_t const irq)
{
    /* Enable the IRQ in the NVIC. */

    /* Clear pending Interrupt in NVIC*/
    R_BSP_IrqMrgClearPending(irq);
    R_BSP_IrqMrgEnableNoClear(irq);
}

/*******************************************************************************************************************//**
 * Disables interrupt merge in the NVIC.
 *
 * @param[in] irq            The IRQ merge to disable in the NVIC. Note that the enums listed for bsp_imf_irqn_t are
 *                           only those for the Cortex Processor Exceptions Numbers.
 *
 * @warning Do not call this function for system exceptions where the bsp_imf_irqn_t value is < 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqMrgDisable (bsp_imf_irqn_t const irq)
{
    uint8_t  irq_bit_assign = (uint8_t) ((irq >> BSP_IMF_BIT_SHIFT) & BSP_IMF_MASK_BYTE);
    uint8_t  irq_type       = (uint8_t) (irq >> BSP_IMF_TYPE_SHIFT);
    uint8_t  irq_group      = (uint8_t) ((irq >> BSP_IMF_GROUP_SHIFT) & BSP_IMF_MASK_BYTE);
    uint8_t  _irq           = (uint8_t) (irq & BSP_IMF_MASK_BYTE);
    uint32_t disable_irq    = 0;

    if (irq_type == BSP_IMF_ICU_IRQ_TYPE_PULSE)
    {
        /* Mask IMFU Pulse interrupt bit*/
        R_IMFU0->IMFUP[irq_group].IMFUPMSK = (R_IMFU0->IMFUP[irq_group].IMFUPMSK) |
                                             (1 << (irq_bit_assign));

        /* If all interrupt in merge group is masked also disable NVIC */
        disable_irq = (R_IMFU0->IMFUP[irq_group].IMFUPMSK) == 0x0f ? 1 : 0;
    }
    else if (irq_type == BSP_IMF_ICU_IRQ_TYPE_LEVEL)
    {
        /* Mask IMFU Level interrupt bit*/
        R_IMFU0->IMFUL[irq_group].IMFULMSK = (R_IMFU0->IMFUL[irq_group].IMFULMSK) |
                                             (1 << (irq_bit_assign));

        /* If all interrupt in merge group is masked also disable NVIC */
        disable_irq = (R_IMFU0->IMFUP[irq_group].IMFUPMSK) == 0x0f ? 1 : 0;
    }
    else
    {
        disable_irq = 1;
    }

    /* The following statements is used in place of NVIC_DisableIRQ to avoid including a branch for system
     * exceptions every time an interrupt is cleared in the NVIC. */
    if (disable_irq)
    {
        NVIC->ICER[(_irq >> 5UL)] = (uint32_t) (1UL << (_irq & 0x1FUL));

        /* Clear pending Interrupt in NVIC*/
        R_BSP_IrqMrgClearPending(irq);

        /* Dummy read NVIC ICER */
        NVIC->ICER[(_irq >> 5UL)];
    }

    __DSB();
    __ISB();
}

/*******************************************************************************************************************//**
 * Sets the interrupt merge priority and context, clears pending interrupts, then enables the interrupt.
 *
 * @param[in] irq            Interrupt merge number.
 * @param[in] priority       NVIC priority of the interrupt
 * @param[in] p_context      The interrupt merge context is a pointer to data required in the ISR.
 *
 * @warning Do not call this function for system exceptions where the bsp_imf_irqn_t value is < 0.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_IrqMrgCfgEnable (bsp_imf_irqn_t const irq, uint32_t priority, void * p_context)
{
    if (BSP_IRQ_DISABLED != priority)
    {
        R_BSP_IrqMrgCfg(irq, priority, p_context);
        R_BSP_IrqMrgEnable(irq);
    }
}

/*******************************************************************************************************************//**
 * @brief      This function finds the ISR merge context associated with the requested IRQ.
 *
 * @param[in]  irq            IRQ merge number (parameter checking must ensure the IRQ number is valid before calling
 *                             this function.
 * @return  ISR context for IRQ.
 **********************************************************************************************************************/
__STATIC_INLINE void * R_FSP_IsrMrgContextGet (bsp_imf_irqn_t const irq)
{
    /* This provides access to the ISR context array defined in bsp_irq.c. This is an inline function instead of
     * being part of bsp_irq.c for performance considerations because it is used in interrupt service routines. */
    uint8_t  irq_channel_no = (uint8_t) (irq & BSP_IMF_MASK_BYTE);
    uint8_t  irq_bit_assign = (uint8_t) ((irq >> BSP_IMF_BIT_SHIFT) & BSP_IMF_MASK_BYTE);
    uint32_t _irq           = (uint32_t) (g_bsp_imf_isr_table[irq_channel_no] + irq_bit_assign);

    return gp_renesas_isr_context[_irq];
}

/*******************************************************************************************************************//**
 * Return the value of the active interrupt merge vector number.
 *
 * @return     Active Interrupt Merge Vector Value
 **********************************************************************************************************************/
__STATIC_INLINE bsp_imf_irqn_t R_FSP_CurrentIrqMrgGet (void)
{
    xPSR_Type xpsr_value;
    xpsr_value.w = __get_xPSR();

    uint32_t       irq_channel_no = xpsr_value.b.ISR - BSP_CORTEX_VECTOR_TABLE_ENTRIES;
    bsp_imf_irqn_t irq_num        = (bsp_imf_irqn_t) g_bsp_imf_infor_isr_table[irq_channel_no];
    irq_num |= (bsp_imf_irqn_t) irq_channel_no;
    uint8_t irq_group =
        (uint8_t) ((g_bsp_imf_infor_isr_table[irq_channel_no] >> BSP_IMF_GROUP_SHIFT) & BSP_IMF_MASK_BYTE);
    uint8_t irq_type       = (uint8_t) (g_bsp_imf_infor_isr_table[irq_channel_no] >> BSP_IMF_TYPE_SHIFT);
    uint8_t irq_bit_assign = 0u;

    /* Re-calculate irq_num base on merge bit flag */
    if (irq_type == BSP_IMF_ICU_IRQ_TYPE_PULSE)
    {
        /* IMFG Pulse */
        uint32_t imfupf   = R_IMFU0->IMFUP[irq_group].IMFUPF;
        uint32_t imfupmsk = R_IMFU0->IMFUP[irq_group].IMFUPMSK;
        irq_bit_assign += __CLZ(__RBIT(imfupf & (~imfupmsk)));
    }
    else if (irq_type == BSP_IMF_ICU_IRQ_TYPE_LEVEL)
    {
        /* IMFG Level */
        uint32_t imfulf   = R_IMFU0->IMFUL[irq_group].IMFULF;
        uint32_t imfulmsk = R_IMFU0->IMFUL[irq_group].IMFULMSK;
        irq_bit_assign += __CLZ(__RBIT(imfulf & (~imfulmsk)));
    }
    else
    {
        /* Non-merge interrupt do nothing*/
    }

    irq_num |= (bsp_imf_irqn_t) (((uint16_t) (irq_bit_assign)) << BSP_IMF_BIT_SHIFT);

    return (bsp_imf_irqn_t) irq_num;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup BSP_COMMON)
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_PRV) */

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
