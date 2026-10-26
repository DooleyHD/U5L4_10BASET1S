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

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/** This array holds callback functions. */
bsp_grp_irq_cb_t g_bsp_group_irq_sources[BSP_GRP_IRQ_NMIER_MAX_INDEX] BSP_SECTION_EARLY_INIT;

void        NMI_Handler(void);
static void bsp_group_irq_call(bsp_grp_irq_t irq);

/*******************************************************************************************************************//**
 * Calls the callback function for an interrupt if a callback has been registered.
 *
 * @param[in]   irq         Which interrupt to check and possibly call.
 *
 * @retval FSP_SUCCESS              Callback was called.
 * @retval FSP_ERR_INVALID_ARGUMENT No valid callback has been registered for this interrupt source.
 *
 * @warning This function is called from within an interrupt
 **********************************************************************************************************************/
static void bsp_group_irq_call (bsp_grp_irq_t irq)
{
    /** Check for valid callback */
    if (NULL != g_bsp_group_irq_sources[irq])
    {
        /** Callback has been found. Call it. */
        g_bsp_group_irq_sources[irq](irq);
    }
}

/*******************************************************************************************************************//**
 * @addtogroup BSP_COMMON
 *
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Register a callback function for supported interrupts. If NULL is passed for the callback argument then any
 * previously registered callbacks are unregistered.
 *
 * @param[in]  irq          Interrupt for which  to register a callback.
 * @param[in]  p_callback   Pointer to function to call when interrupt occurs.
 *
 * @retval     FSP_SUCCESS                  Callback registered
 * @retval     FSP_ERR_ASSERTION            Callback pointer is NULL
 **********************************************************************************************************************/
fsp_err_t R_BSP_GroupIrqWrite (bsp_grp_irq_t irq, void (* p_callback)(bsp_grp_irq_t irq))
{
#if BSP_CFG_PARAM_CHECKING_ENABLE

    /* Check pointer for NULL value. */
    FSP_ASSERT(p_callback);
#endif

    /* Register callback. */
    g_bsp_group_irq_sources[irq] = p_callback;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Non-maskable interrupt handler. This exception is defined by the BSP, unlike other system exceptions, because
 * there are many sources that map to the NMI exception.
 **********************************************************************************************************************/
void NMI_Handler (void)
{
    /* NMIF is a flag indicating the NMI status. */
    uint32_t nmif = R_FENC0->NMIF;

    /* Loop over all NMI status flags */
    for (bsp_grp_irq_t irq = (bsp_grp_irq_t) 0U; irq < (bsp_grp_irq_t) (BSP_GRP_IRQ_NMIER_MAX_INDEX); irq++)
    {
        /* If the current irq status register is set call the irq callback. */
        if (0U != (nmif & (1U << irq)))
        {
            bsp_group_irq_call(irq);
        }
    }

    /* Clear NMI status flag */
    R_FENC0->NMIC = nmif;

    /* Wait for NMIF to be cleared before exiting the ISR to prevent the IRQ from being generated */
    FSP_HARDWARE_REGISTER_WAIT((R_FENC0->NMIF_b.NMIF & nmif), 0U);

    /* Dummy Read NMIC*/
    R_FENC0->NMIC;
}

/** @} (end addtogroup BSP_COMMON) */
