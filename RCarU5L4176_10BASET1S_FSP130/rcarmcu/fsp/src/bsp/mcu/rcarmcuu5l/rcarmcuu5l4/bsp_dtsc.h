/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_DTSC_H
#define BSP_DTSC_H

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Trigger source event of DTSC */
typedef enum dtsc_trigger_event
{
    DTSC_TRIGGER_EVENT_RS_CANFD_INTRCANRFDREQ0 = (8),  ///< DTSC Trigger Factor Interrupt CANFD REQ 0
    DTSC_TRIGGER_EVENT_RS_CANFD_INTRCANRFDREQ1 = (9),  ///< DTSC Trigger Factor Interrupt CANFD REQ 1
    DTSC_TRIGGER_EVENT_RS_CANFD_INTRCANRFDREQ2 = (10), ///< DTSC Trigger Factor Interrupt CANFD REQ 2
    DTSC_TRIGGER_EVENT_RLIN3_INTRLIN30UR0      = (11), ///< DTSC Trigger Factor Interrupt for RLIN30
    DTSC_TRIGGER_EVENT_RSENT_INTRSENT0RI       = (12), ///< DTSC Trigger Factor Interrupt for RSENT
    DTSC_TRIGGER_EVENT_TAUD_INTTAUD0I0         = (13), ///< DTSC Trigger Factor Interrupt for TAUD0
    DTSC_TRIGGER_EVENT_CSIH_INTCSIHIC_0        = (14), ///< DTSC Trigger Factor Interrupt for CSIH
    DTSC_TRIGGER_EVENT_SOFTWARE_TRIGGER        = (15), ///< Software trigger source
} dtsc_trigger_event_t;

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

#endif                                 /* BSP_DTSC_H */
