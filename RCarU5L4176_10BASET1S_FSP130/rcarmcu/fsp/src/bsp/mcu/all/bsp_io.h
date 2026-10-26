/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_io_device.h"

/*******************************************************************************************************************//**
 * @defgroup BSP_IO BSP I/O access
 * @ingroup BSP_MCU
 * @brief This module provides basic read/write access to port pins.
 *
 * @{
 **********************************************************************************************************************/

#ifndef BSP_IO_H
 #define BSP_IO_H

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Shift to get port in bsp_io_port_t and bsp_io_port_pin_t enums. */
 #define BSP_IO_PORT_GROUP_POS          (8UL)
 #define BSP_IO_PORT_TYPE_POS           (16UL)
 #define BSP_IO_PORT_PWE_POS            (24UL)

 #define BSP_IO_PORT_PWE_MASK           (0xFF000000U)
 #define BSP_IO_PORT_TYPE_MASK          (0x00FF0000U)
 #define BSP_IO_PORT_GROUP_MASK         (0x0000FF00U)
 #define BSP_IO_PORT_PIN_MASK           (0x000000FFU)

 #define BSP_IO_SR_MASK_POS             (16UL)

 #define BSP_IO_PORT_PWE_UNSED          (0xFFUL)

 #define BSP_IO_PORT_KEYCODE_ENABLE     0xA5A5A501U
 #define BSP_IO_PORT_KEYCODE_DISABLE    0xA5A5A500U

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Levels that can be set and read for individual pins */
typedef enum e_bsp_io_level
{
    BSP_IO_LEVEL_LOW = 0,              ///< Port Level Low
    BSP_IO_LEVEL_HIGH                  ///< Port Level High
} bsp_io_level_t;

/** Direction of individual pins */
typedef enum e_bsp_io_direction
{
    BSP_IO_DIRECTION_INPUT  = 1,       ///< Input
    BSP_IO_DIRECTION_OUTPUT = 0        ///< Output
} bsp_io_direction_t;

/** Available Port type */
typedef enum e_bsp_io_port_type
{
    BSP_IO_PORT_TYPE_PORT  = 0x000000, ///< IO port type Port
    BSP_IO_PORT_TYPE_APORT = 0x010000, ///< IO port type APort
    BSP_IO_PORT_TYPE_JPORT = 0x020000, ///< IO port type JPort
    BSP_IO_PORT_TYPE_IPORT = 0x030000, ///< IO port type IPort
} bsp_io_port_type_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enable access to the selected port registers. Unlock PWE register protect by using R_BSP_PinAccessEnable
 * before calling this function.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PortWriteEnable (bsp_io_port_t port)
{
    uint32_t pwe_pos = ((uint32_t) port & BSP_IO_PORT_PWE_MASK) >> BSP_IO_PORT_PWE_POS;

    if (BSP_IO_PORT_PWE_UNSED != pwe_pos)
    {
        R_PORT->PWE = R_PORT->PWE | (1 << pwe_pos);
    }
}

/*******************************************************************************************************************//**
 * Disable writing to the PWE registers. Unlock PWE register protect by using R_BSP_PinAccessEnable
 * before calling this function.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PortWriteDisable (bsp_io_port_t port)
{
    uint32_t pwe_pos = ((uint32_t) port & BSP_IO_PORT_PWE_MASK) >> BSP_IO_PORT_PWE_POS;

    if (BSP_IO_PORT_PWE_UNSED != pwe_pos)
    {
        R_PORT->PWE = R_PORT->PWE & (uint32_t) ~(1 << pwe_pos);
    }
}

/*******************************************************************************************************************//**
 * Enable access to the PWE registers.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PinAccessEnable ()
{
    R_PORT->PKCPROT = BSP_IO_PORT_KEYCODE_ENABLE;
}

/*******************************************************************************************************************//**
 * Disable access to the PWE registers.
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PinAccessDisable ()
{
    R_PORT->PKCPROT = BSP_IO_PORT_KEYCODE_DISABLE;
}

/*******************************************************************************************************************//**
 * Read the current input level of the pin. Pin must be a valid pin before calling this function
 *
 * @param[in]  pin             The pin
 *
 * @retval     Current input level
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t R_BSP_PinRead (bsp_io_port_pin_t pin)
{
    uint32_t level      = 0;
    uint32_t port_type  = (uint32_t) pin & BSP_IO_PORT_TYPE_MASK;
    uint32_t port_group = ((uint32_t) pin & BSP_IO_PORT_GROUP_MASK) >> BSP_IO_PORT_GROUP_POS;
    uint32_t port_pin   = (uint32_t) pin & BSP_IO_PORT_PIN_MASK;

    if (BSP_IO_PORT_TYPE_IPORT == port_type)
    {
        /* Read IPort Level */
        level = (R_PORT->IPPR0 >> port_pin) & 0x1U;
    }
    else if (BSP_IO_PORT_TYPE_JPORT == port_type)
    {
        /* Read JPort Level */
        level = R_JPORT->JPCRn_m[port_group].PCR_b[port_pin].JPPR;
    }
    else if (BSP_IO_PORT_TYPE_APORT == port_type)
    {
        /* Read APort Level */
        level = R_PORT->APCRn_m[port_group].PCR_b[port_pin].APPR;
    }
    else
    {
        /* Read Port Level */
        level = R_PORT->PCRn_m[port_group].PCR_b[port_pin].PPR;
    }

    return level;
}

/*******************************************************************************************************************//**
 * Set the output level to the level provided. Disable port write
 * protection using R_BSP_PortWriteEnable() before calling this function.
 *
 * @param[in]  pin      The pin to write
 * @param[in]  level    The level
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PinWrite (bsp_io_port_pin_t pin, bsp_io_level_t level)
{
    uint32_t port_type  = (uint32_t) pin & BSP_IO_PORT_TYPE_MASK;
    uint32_t port_group = (uint32_t) pin & BSP_IO_PORT_GROUP_MASK;
    uint32_t port_pin   = (uint32_t) pin & BSP_IO_PORT_PIN_MASK;

    if (BSP_IO_PORT_TYPE_IPORT == port_type)
    {
        /* Do nothing IPort not support output */
    }
    else if (BSP_IO_PORT_TYPE_JPORT == port_type)
    {
        /* Set JPort Level */
        R_JPORT->JPORT_CTR[port_group >> BSP_IO_PORT_GROUP_POS].PSR = (1U << (BSP_IO_SR_MASK_POS + port_pin)) |
                                                                      ((uint32_t) level << port_pin);
    }
    else if (BSP_IO_PORT_TYPE_APORT == port_type)
    {
        /* Set APort Level */
        R_PORT->APORT_CTR[port_group >> BSP_IO_PORT_GROUP_POS].PSR = (1U << (BSP_IO_SR_MASK_POS + port_pin)) |
                                                                     ((uint32_t) level << port_pin);
    }
    else
    {
        /* Set port level */
        R_PORT->PORT_CTR[port_group >> BSP_IO_PORT_GROUP_POS].PSR = (1U << (BSP_IO_SR_MASK_POS + port_pin)) |
                                                                    ((uint32_t) level << port_pin);
    }
}

/*******************************************************************************************************************//**
 * Toggle the level of the provided pin. Disable port write
 * protection using R_BSP_PortWriteEnable() before calling this function.
 *
 * @param[in]  pin      The pin to write
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PinToggle (bsp_io_port_pin_t pin)
{
    uint32_t port_type  = (uint32_t) pin & BSP_IO_PORT_TYPE_MASK;
    uint32_t port_group = (uint32_t) pin & BSP_IO_PORT_GROUP_MASK;
    uint32_t port_pin   = (uint32_t) pin & BSP_IO_PORT_PIN_MASK;

    if (BSP_IO_PORT_TYPE_IPORT == port_type)
    {
        /* Do nothing IPort not support output */
    }
    else if (BSP_IO_PORT_TYPE_JPORT == port_type)
    {
        /* Read JPort Level */
        R_JPORT->JPORT_CTR[port_group >> BSP_IO_PORT_GROUP_POS].PNOT = (uint8_t) (1 << port_pin);
    }
    else if (BSP_IO_PORT_TYPE_APORT == port_type)
    {
        /* Read APort Level */
        R_PORT->APORT_CTR[port_group >> BSP_IO_PORT_GROUP_POS].PNOT = (uint16_t) (1 << port_pin);
    }
    else
    {
        /* Change direction to output and set port level */
        R_PORT->PORT_CTR[port_group >> BSP_IO_PORT_GROUP_POS].PNOT = (uint16_t) (1 << port_pin);
    }
}

/*******************************************************************************************************************//**
 * Configure a pin. Disable port write protection by using R_BSP_PortWriteEnable() before calling
 * this function.
 *
 * @param[in]  pin      The pin to be configured
 * @param[in]  cfg      Configuration for the pin (PCRm_n register setting)
 **********************************************************************************************************************/
__STATIC_INLINE void R_BSP_PinCfg (bsp_io_port_pin_t pin, uint32_t cfg)
{
    uint32_t port_type  = (uint32_t) pin & BSP_IO_PORT_TYPE_MASK;
    uint32_t port_group = (uint32_t) pin & BSP_IO_PORT_GROUP_MASK;
    uint32_t port_pin   = (uint32_t) pin & BSP_IO_PORT_PIN_MASK;

    if (BSP_IO_PORT_TYPE_IPORT == port_type)
    {
        /* Config IPort Pin */
        if (0U == (cfg & R_PORT_PCRn_m_PCR_PIBC_Msk))
        {
            R_PORT->IPIBC0 = (uint16_t) R_PORT->IPIBC0 & (~(uint16_t) (1U << port_pin));
        }
        else
        {
            R_PORT->IPIBC0 = (uint16_t) R_PORT->IPIBC0 | (uint16_t) (1U << port_pin);
        }
    }
    else if (BSP_IO_PORT_TYPE_JPORT == port_type)
    {
        /* Config JPort Pin */
        R_JPORT->JPCRn_m[port_group >>
                         BSP_IO_PORT_GROUP_POS].PCR[port_pin] =
            (R_JPORT->JPCRn_m[port_group >> BSP_IO_PORT_GROUP_POS].PCR[port_pin] & R_JPORT_JPCRn_m_PCR_JPINV_Msk) | cfg;
        R_JPORT->JPCRn_m[port_group >> BSP_IO_PORT_GROUP_POS].PCR[port_pin] = cfg;
    }
    else if (BSP_IO_PORT_TYPE_APORT == port_type)
    {
        /* Config APort Pin */
        R_PORT->APCRn_m[port_group >>
                        BSP_IO_PORT_GROUP_POS].PCR[port_pin] =
            (R_PORT->APCRn_m[port_group >> BSP_IO_PORT_GROUP_POS].PCR[port_pin] & R_PORT_APCRn_m_PCR_APINV_Msk) | cfg;
        R_PORT->APCRn_m[port_group >> BSP_IO_PORT_GROUP_POS].PCR[port_pin] = cfg;
    }
    else
    {
        /* Config Port Pin */
        R_PORT->PCRn_m[port_group >>
                       BSP_IO_PORT_GROUP_POS].PCR[port_pin] =
            (R_PORT->PCRn_m[port_group >> BSP_IO_PORT_GROUP_POS].PCR[port_pin] & R_PORT_PCRn_m_PCR_PINV_Msk) | cfg;
        R_PORT->PCRn_m[port_group >> BSP_IO_PORT_GROUP_POS].PCR[port_pin] = cfg;
    }
}

/** @} (end addtogroup BSP_IO) */

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
