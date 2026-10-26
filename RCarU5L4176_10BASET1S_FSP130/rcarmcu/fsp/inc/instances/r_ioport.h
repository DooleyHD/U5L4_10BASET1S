/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup IOPORT
 * @{
 **********************************************************************************************************************/

#ifndef R_IOPORT_H
#define R_IOPORT_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#include "r_ioport_api.h"
#if __has_include("r_ioport_cfg.h")
 #include "r_ioport_cfg.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Superset ALT mode functions.  */
typedef enum e_ioport_alt
{
    IOPORT_ALT_IN1  = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x00U << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 1
    IOPORT_ALT_IN2  = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x01U << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 2
    IOPORT_ALT_IN3  = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x02U << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 3
    IOPORT_ALT_IN4  = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x03U << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 4
    IOPORT_ALT_IN5  = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x04U << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 5
    IOPORT_ALT_IN6  = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x05U << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 6
    IOPORT_ALT_IN7  = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x06U << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 7
    IOPORT_ALT_IN8  = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x07U << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 8
    IOPORT_ALT_IN9  = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x08U << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 9
    IOPORT_ALT_IN10 = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x09U << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 10
    IOPORT_ALT_IN11 = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0aU << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 11
    IOPORT_ALT_IN12 = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0bU << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 12
    IOPORT_ALT_IN13 = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0cU << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 13
    IOPORT_ALT_IN14 = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0dU << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 14
    IOPORT_ALT_IN15 = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0eU << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 15
    IOPORT_ALT_IN16 = (1 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0fU << R_PORT_PCRn_m_PCR_PFC_Pos),  ///< Alternative input 16

    IOPORT_ALT_OUT1  = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x00U << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 1
    IOPORT_ALT_OUT2  = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x01U << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 2
    IOPORT_ALT_OUT3  = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x02U << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 3
    IOPORT_ALT_OUT4  = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x03U << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 4
    IOPORT_ALT_OUT5  = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x04U << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 5
    IOPORT_ALT_OUT6  = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x05U << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 6
    IOPORT_ALT_OUT7  = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x06U << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 7
    IOPORT_ALT_OUT8  = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x07U << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 8
    IOPORT_ALT_OUT9  = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x08U << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 9
    IOPORT_ALT_OUT10 = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x09U << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 10
    IOPORT_ALT_OUT11 = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0aU << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 11
    IOPORT_ALT_OUT12 = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0bU << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 12
    IOPORT_ALT_OUT13 = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0cU << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 13
    IOPORT_ALT_OUT14 = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0dU << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 14
    IOPORT_ALT_OUT15 = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0eU << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 15
    IOPORT_ALT_OUT16 = (0 << R_PORT_PCRn_m_PCR_PM_Pos) | (0x0fU << R_PORT_PCRn_m_PCR_PFC_Pos), ///< Alternative output 16
} ioport_alt_t;

/** Options to configure pin functions  */
typedef enum e_ioport_cfg_options
{
    IOPORT_CFG_PORT_DIRECTION_INPUT  = (uint32_t)(1U << R_PORT_PCRn_m_PCR_PM_Pos),    ///< Sets the pin direction to input (default)
    IOPORT_CFG_PORT_DIRECTION_OUTPUT = (uint32_t)(0U << R_PORT_PCRn_m_PCR_PM_Pos),    ///< Sets the pin direction to output
    IOPORT_CFG_INPUT_BUFFER_NONE     = (uint32_t)(0U << R_PORT_PCRn_m_PCR_PIBC_Pos),  ///< Disable input buffer on pin
    IOPORT_CFG_INPUT_BUFFER_SHMT1    = (uint32_t)((1U << R_PORT_PCRn_m_PCR_PIBC_Pos) |
                                                  (0U << R_PORT_PCRn_m_PCR_PIS_Pos)), ///< Select input buffer type SHMT1
    IOPORT_CFG_INPUT_BUFFER_SHMT4 = (uint32_t)((1U << R_PORT_PCRn_m_PCR_PIBC_Pos) |
                                               (1U << R_PORT_PCRn_m_PCR_PIS_Pos)),    ///< Select input buffer type SHMT4
    IOPORT_CFG_INPUT_BUFFER_TTL = (uint32_t)((1U << R_PORT_PCRn_m_PCR_PIBC_Pos) |
                                             (4 << R_PORT_PCRn_m_PCR_PIS_Pos)),       ///< Select input buffer type TTL
    IOPORT_CFG_BIDIRECTIONAL_ENABLE  = (uint32_t)(1U << R_PORT_PCRn_m_PCR_PBDC_Pos),  ///< Enable Pin Bidirectional
    IOPORT_CFG_BIDIRECTIONAL_DISABLE = (uint32_t)(0U << R_PORT_PCRn_m_PCR_PBDC_Pos),  ///< Disable Pin Bidirectional
    IOPORT_CFG_PORT_DIO_MODE         = (uint32_t)(0U << R_PORT_PCRn_m_PCR_PMC_Pos),   ///< Set pin mode to IO mode
    IOPORT_CFG_PERIPHERAL_PIN        = (uint32_t)(1U << R_PORT_PCRn_m_PCR_PMC_Pos),   ///< Set pin mode to Alternative mode
    IOPORT_CFG_PIPC_SOFTWARE         = (uint32_t)(0U << R_PORT_PCRn_m_PCR_PIPC_Pos),  ///< Set pin mode to alternative Software Control
    IOPORT_CFG_PIPC_PERIPHERAL       = (uint32_t)(1U << R_PORT_PCRn_m_PCR_PIPC_Pos),  ///< Set pin mode to Alternative Direct Control
    IOPORT_CFG_PULLUP                = (uint32_t)(1U << R_PORT_PCRn_m_PCR_PU_Pos),    ///< Enable the pin's internal pull-up
    IOPORT_CFG_PULLDOWN              = (uint32_t)(1U << R_PORT_PCRn_m_PCR_PD_Pos),    ///< Enable the pin's internal pull-down
    IOPORT_CFG_P_CH_OPEN_DRAIN       = (uint32_t)(3U << R_PORT_PCRn_m_PCR_PODCE_Pos), ///< Select output buffer open drain
    IOPORT_CFG_N_CH_OPEN_DRAIN       = (uint32_t)(2U << R_PORT_PCRn_m_PCR_PODCE_Pos), ///< Select output buffer open drain
    IOPORT_CFG_PUSHPULL              = (uint32_t)(0U << R_PORT_PCRn_m_PCR_PODCE_Pos), ///< Select output buffer push-pull
    IOPORT_CFG_DRIVE_HIGH            = (uint32_t)(1U << R_PORT_PCRn_m_PCR_PDSC_Pos),  ///< Select port drive strength high
    IOPORT_CFG_DRIVE_MEDIUM          = (uint32_t)(1U << R_PORT_PCRn_m_PCR_PDSC_Pos),  ///< Select port drive strength low
    IOPORT_CFG_DRIVE_LOW             = (uint32_t)(0U << R_PORT_PCRn_m_PCR_PDSC_Pos),  ///< Select port drive strength low
    IOPORT_CFG_PORT_OUTPUT_LOW       = (uint32_t)(0U << R_PORT_PCRn_m_PCR_P_Pos),     ///< Sets pin level to low
    IOPORT_CFG_PORT_OUTPUT_HIGH      = (uint32_t)(1U << R_PORT_PCRn_m_PCR_P_Pos),     ///< Set pin level to high
    IOPORT_CFG_OUTPUT_INVERT         = (uint32_t)(1U << R_PORT_PCRn_m_PCR_PINV_Pos)   ///< Set Inverted Output
} ioport_cfg_options_t;

/** IOPORT extended configuration
 *  @note IOPORT do not use extend_cfg
 */

typedef void * ioport_extend_cfg_t;

/** IOPORT private control block. DO NOT MODIFY. Initialization occurs when R_IOPORT_Open() is called. */
typedef struct st_ioport_instance_ctrl
{
    uint32_t     open;
    void const * p_context;
} ioport_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const ioport_api_t g_ioport_on_ioport;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/

fsp_err_t R_IOPORT_Open(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);
fsp_err_t R_IOPORT_Close(ioport_ctrl_t * const p_ctrl);
fsp_err_t R_IOPORT_PinsCfg(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);
fsp_err_t R_IOPORT_PinCfg(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, uint32_t cfg);
fsp_err_t R_IOPORT_PinEventInputRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_event);
fsp_err_t R_IOPORT_PinEventOutputWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t pin_value);
fsp_err_t R_IOPORT_PinRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_value);
fsp_err_t R_IOPORT_PinWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t level);
fsp_err_t R_IOPORT_PortDirectionSet(ioport_ctrl_t * const p_ctrl,
                                    bsp_io_port_t         port,
                                    ioport_size_t         direction_values,
                                    ioport_size_t         mask);
fsp_err_t R_IOPORT_PortEventInputRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * event_data);
fsp_err_t R_IOPORT_PortEventOutputWrite(ioport_ctrl_t * const p_ctrl,
                                        bsp_io_port_t         port,
                                        ioport_size_t         event_data,
                                        ioport_size_t         mask_value);
fsp_err_t R_IOPORT_PortRead(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * p_port_value);
fsp_err_t R_IOPORT_PortWrite(ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t value, ioport_size_t mask);

/*******************************************************************************************************************//**
 * @} (end defgroup IOPORT)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 // R_IOPORT_H
