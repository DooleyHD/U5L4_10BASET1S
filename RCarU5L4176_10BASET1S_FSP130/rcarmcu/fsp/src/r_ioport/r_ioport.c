/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdint.h>
#include "bsp_api.h"
#include "r_ioport.h"
#include "r_ioport_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* "PORT" in ASCII, used to determine if the module is open */
#define IOPORT_OPEN           (0x504F5254U)
#define IOPORT_CLOSED         (0x00000000U)

#define IOPORT_SR_MASK_POS    (16U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/
static void r_ioport_pins_config(const ioport_cfg_t * p_cfg);

static void r_ioport_pcr_write(bsp_io_port_pin_t pin, uint32_t value);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global Variables
 **********************************************************************************************************************/

/* IOPort Implementation of IOPort Driver  */
const ioport_api_t g_ioport_on_ioport =
{
    .open                 = R_IOPORT_Open,
    .close                = R_IOPORT_Close,
    .pinsCfg              = R_IOPORT_PinsCfg,
    .pinCfg               = R_IOPORT_PinCfg,
    .pinEventInputRead    = R_IOPORT_PinEventInputRead,
    .pinEventOutputWrite  = R_IOPORT_PinEventOutputWrite,
    .pinRead              = R_IOPORT_PinRead,
    .pinWrite             = R_IOPORT_PinWrite,
    .portDirectionSet     = R_IOPORT_PortDirectionSet,
    .portEventInputRead   = R_IOPORT_PortEventInputRead,
    .portEventOutputWrite = R_IOPORT_PortEventOutputWrite,
    .portRead             = R_IOPORT_PortRead,
    .portWrite            = R_IOPORT_PortWrite,
};

/*******************************************************************************************************************//**
 * @addtogroup IOPORT
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Initializes internal driver data, then calls pin configuration function to configure pins.
 *
 * @retval FSP_SUCCESS                  Pin configuration data written to PFS register(s)
 * @retval FSP_ERR_ASSERTION            NULL pointer
 * @retval FSP_ERR_ALREADY_OPEN         Module is already open.
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_Open (ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg)
{
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;

#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_pin_cfg_data || 0 == p_cfg->number_of_pins);
    FSP_ERROR_RETURN(IOPORT_OPEN != p_instance_ctrl->open, FSP_ERR_ALREADY_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    /* Set driver status to open */
    p_instance_ctrl->open = IOPORT_OPEN;

    r_ioport_pins_config(p_cfg);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Resets IOPORT registers. Implements @ref ioport_api_t::close
 *
 * @retval FSP_SUCCESS             The IOPORT was successfully uninitialized
 * @retval FSP_ERR_ASSERTION       p_ctrl was NULL
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_Close (ioport_ctrl_t * const p_ctrl)
{
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;

#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    /* Set state to closed */
    p_instance_ctrl->open = IOPORT_CLOSED;

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Configures the functions of multiple pins by loading configuration data into pin PFS registers.
 * Implements @ref ioport_api_t::pinsCfg.
 *
 * This function initializes the supplied list of PmnPFS registers with the supplied values. This data can be generated
 * by the Pins tab of the RA Configuration editor or manually by the developer. Different pin configurations can be
 * loaded for different situations such as low power modes and testing.
 *
 * @retval FSP_SUCCESS             Pin configuration data written to PFS register(s)
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 * @retval FSP_ERR_ASSERTION       NULL pointer
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PinsCfg (ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg)
{
#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_cfg);
    FSP_ASSERT(NULL != p_cfg->p_pin_cfg_data);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    r_ioport_pins_config(p_cfg);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Configures the settings of a pin. Implements @ref ioport_api_t::pinCfg.
 *
 * @retval FSP_SUCCESS             Pin configured
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 * @retval FSP_ERR_ASSERTION       NULL pointer
 *
 * @note This function will change the configuration of the pin with the new configuration. For example it is not
 * possible with this function to change the drive strength of a pin while leaving all the other pin settings unchanged.
 * To achieve this the original settings with the required change will need to be written using this function.
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PinCfg (ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, uint32_t cfg)
{
#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif
    R_BSP_PinAccessEnable();
    r_ioport_pcr_write(pin, cfg);
    R_BSP_PinAccessDisable();

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads the level on a pin. Implements @ref ioport_api_t::pinRead.
 *
 * @retval FSP_SUCCESS             Pin read
 * @retval FSP_ERR_ASSERTION       NULL pointer
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 * @note This function is re-entrant for different pins.
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PinRead (ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_value)
{
#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_pin_value);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    *p_pin_value = (bsp_io_level_t) R_BSP_PinRead(pin);

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads the value on an IO port. Implements @ref ioport_api_t::portRead.
 *
 * The specified port will be read, and the levels for all the pins will be returned.
 * Each bit in the returned value corresponds to a pin on the port. For example, bit 7 corresponds
 * to pin 7, bit 6 to pin 6, and so on.
 *
 * @retval FSP_SUCCESS             Port read
 * @retval FSP_ERR_ASSERTION       NULL pointer
 * @retval FSP_ERR_NOT_OPEN        The module has not been opened
 *
 * @note This function is re-entrant for different ports.
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PortRead (ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * p_port_value)
{
#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ASSERT(NULL != p_port_value);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif
    uint32_t port_type  = ((uint32_t) port) & BSP_IO_PORT_TYPE_MASK;
    uint32_t port_group = (((uint32_t) port) & BSP_IO_PORT_GROUP_MASK) >> BSP_IO_PORT_GROUP_POS;

    if (BSP_IO_PORT_TYPE_IPORT == port_type)
    {
        /* Read IPort level */
        *p_port_value = R_PORT->IPPR0;
    }
    else if (BSP_IO_PORT_TYPE_JPORT == port_type)
    {
        /* Read JPort level */
        *p_port_value = R_JPORT->JPORT_CTR[port_group].PPR;
    }
    else if (BSP_IO_PORT_TYPE_APORT == port_type)
    {
        /* Read APort level */
        *p_port_value = R_PORT->APORT_CTR[port_group].PPR;
    }
    else
    {
        /* Read Port level */
        *p_port_value = R_PORT->PORT_CTR[port_group].PPR;
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Writes to multiple pins on a port. Implements @ref ioport_api_t::portWrite.
 *
 * The input value will be written to the specified port. Each bit in the value parameter corresponds to a bit
 * on the port. For example, bit 7 corresponds to pin 7, bit 6 to pin 6, and so on.
 * Each bit in the mask parameter corresponds to a pin on the port.
 *
 * Only the bits with the corresponding bit in the mask value set will be updated.
 * For example, value = 0xFFFF, mask = 0x0003 results in only bits 0 and 1 being updated.
 *
 * @retval FSP_SUCCESS                  Port written to
 * @retval FSP_ERR_INVALID_ARGUMENT     The port and/or mask not valid
 * @retval FSP_ERR_NOT_OPEN             The module has not been opened
 * @retval FSP_ERR_ASSERTION            NULL pointerd
 *
 * @note This function is re-entrant for different ports. This function makes use of the PCNTR3 register to atomically
 * modify the levels on the specified pins on a port.
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PortWrite (ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t value, ioport_size_t mask)
{
    uint32_t port_type  = ((uint32_t) port) & BSP_IO_PORT_TYPE_MASK;
    uint32_t port_group = ((uint32_t) port) & BSP_IO_PORT_GROUP_MASK;

#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(mask > (ioport_size_t) 0, FSP_ERR_INVALID_ARGUMENT);
    FSP_ERROR_RETURN(port_type != BSP_IO_PORT_TYPE_IPORT, FSP_ERR_INVALID_ARGUMENT);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif

    R_BSP_PinAccessEnable();
    R_BSP_PortWriteEnable(port);

    if (BSP_IO_PORT_TYPE_IPORT == port_type)
    {
        /* Do nothing */
    }
    else if (BSP_IO_PORT_TYPE_JPORT == port_type)
    {
        /* Set JPort Level */
        R_JPORT->JPORT_CTR[0].PSR = (uint32_t) (mask << IOPORT_SR_MASK_POS) | value;
    }
    else if (BSP_IO_PORT_TYPE_APORT == port_type)
    {
        /* Set APort Level */
        if (port_group <= BSP_IO_PORT_GROUP_02)
        {
            R_PORT->APORT_CTR[port_group >> BSP_IO_PORT_GROUP_POS].PSR = (uint32_t) (mask << IOPORT_SR_MASK_POS) |
                                                                         value;
        }
    }
    else
    {
        /* Set Port Level */
        if (port_group <= BSP_IO_PORT_GROUP_27)
        {
            R_PORT->PORT_CTR[port_group >> BSP_IO_PORT_GROUP_POS].PSR = (uint32_t) (mask << IOPORT_SR_MASK_POS) | value;
        }
    }

    R_BSP_PortWriteDisable(port);
    R_BSP_PinAccessDisable();

    /* Return the unsupported error. */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Sets a pin's output either high or low. Implements @ref ioport_api_t::pinWrite.
 *
 * @retval FSP_SUCCESS                      Pin written to
 * @retval FSP_ERR_NOT_OPEN                 The module has not been opene
 * @retval FSP_ERR_ASSERTION                NULL pointerd
 * @retval FSP_ERR_INVALID_ARGUMENT         IPORT doesn't support PinWrite function
 *
 * @note This function is re-entrant for different pins. This function makes use of the PCNTR3 register to atomically
 * modify the level on the specified pin on a port.
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PinWrite (ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t level)
{
#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN((((uint32_t) pin) & BSP_IO_PORT_TYPE_MASK) != BSP_IO_PORT_TYPE_IPORT, FSP_ERR_INVALID_ARGUMENT);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif
    R_BSP_PinAccessEnable();
    R_BSP_PortWriteEnable((bsp_io_port_t) pin);

    R_BSP_PinWrite(pin, level);

    R_BSP_PortWriteDisable((bsp_io_port_t) pin);
    R_BSP_PinAccessDisable();

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Sets the direction of individual pins on a port. Implements @ref ioport_api_t::portDirectionSet().
 *
 * Multiple pins on a port can be set to inputs or outputs at once.
 * Each bit in the mask parameter corresponds to a pin on the port. For example, bit 7 corresponds to
 * pin 7, bit 6 to pin 6, and so on. If a bit is set to 1 then the corresponding pin will be changed to
 * an input or an output as specified by the direction values. If a mask bit is set to 0 then the direction of
 * the pin will not be changed.
 *
 * @retval FSP_SUCCESS                 Port direction updated
 * @retval FSP_ERR_INVALID_ARGUMENT    The port and/or mask not valid
 * @retval FSP_ERR_NOT_OPEN            The module has not been opened
 * @retval FSP_ERR_ASSERTION           NULL pointer
 *
 * @note This function is re-entrant for different ports.
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PortDirectionSet (ioport_ctrl_t * const p_ctrl,
                                     bsp_io_port_t         port,
                                     ioport_size_t         direction_values,
                                     ioport_size_t         mask)
{
#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(mask > (ioport_size_t) 0, FSP_ERR_INVALID_ARGUMENT);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif
    uint32_t port_type  = ((uint32_t) port) & BSP_IO_PORT_TYPE_MASK;
    uint32_t port_group = ((uint32_t) port) & BSP_IO_PORT_GROUP_MASK;

    R_BSP_PinAccessEnable();
    R_BSP_PortWriteEnable(port);

    if (BSP_IO_PORT_TYPE_IPORT == port_type)
    {
        /* Do nothing, IPORT only support input direction */
    }
    else if (BSP_IO_PORT_TYPE_JPORT == port_type)
    {
        /* Set JPort Direction */
        R_JPORT->JPORT_CTR[0].PMSR = (uint32_t) (mask << IOPORT_SR_MASK_POS) | direction_values;
    }
    else if (BSP_IO_PORT_TYPE_APORT == port_type)
    {
        /* Set APort Direction */
        R_PORT->APORT_CTR[port_group >> BSP_IO_PORT_GROUP_POS].PMSR = (uint32_t) (mask << IOPORT_SR_MASK_POS) |
                                                                      direction_values;
    }
    else
    {
        /* Set Port Direction Port */
        R_PORT->PORT_CTR[port_group >> BSP_IO_PORT_GROUP_POS].PMSR = (uint32_t) (mask << IOPORT_SR_MASK_POS) |
                                                                     direction_values;
    }

    R_BSP_PortWriteDisable(port);
    R_BSP_PinAccessDisable();

    /* Return the unsupported error. */
    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 * Reads the value of the event input data. Implements @ref ioport_api_t::portEventInputRead().
 *
 * @retval FSP_ERR_UNSUPPORTED       This function is not supported
 *
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PortEventInputRead (ioport_ctrl_t * const p_ctrl, bsp_io_port_t port, ioport_size_t * p_event_data)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(port);
    FSP_PARAMETER_NOT_USED(p_event_data);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * Reads the value of the event input data of a specific pin. Implements @ref ioport_api_t::pinEventInputRead.
 *
 * @retval FSP_ERR_UNSUPPORTED       This function is not supported
 *
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PinEventInputRead (ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t * p_pin_event)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(pin);
    FSP_PARAMETER_NOT_USED(p_pin_event);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * This function writes the set and reset event output data for a port.
 * Implements @ref ioport_api_t::portEventOutputWrite.
 *
 * @retval FSP_ERR_UNSUPPORTED       This function is not supported
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PortEventOutputWrite (ioport_ctrl_t * const p_ctrl,
                                         bsp_io_port_t         port,
                                         ioport_size_t         event_data,
                                         ioport_size_t         mask_value)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(port);
    FSP_PARAMETER_NOT_USED(event_data);
    FSP_PARAMETER_NOT_USED(mask_value);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/**********************************************************************************************************************//**
 * This function writes the event output data value to a pin.
 * Implements @ref ioport_api_t::pinEventOutputWrite.
 *
 * @retval FSP_ERR_UNSUPPORTED       This function is not supported
 *
 **********************************************************************************************************************/
fsp_err_t R_IOPORT_PinEventOutputWrite (ioport_ctrl_t * const p_ctrl, bsp_io_port_pin_t pin, bsp_io_level_t pin_value)
{
    FSP_PARAMETER_NOT_USED(p_ctrl);
    FSP_PARAMETER_NOT_USED(pin);
    FSP_PARAMETER_NOT_USED(pin_value);

    /* Return the unsupported error. */
    return FSP_ERR_UNSUPPORTED;
}

/*******************************************************************************************************************//**
 * @} (end addtogroup IOPORT)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Configures pins.
 *
 * @param[in]    p_cfg          Pin configuration data
 **********************************************************************************************************************/
void r_ioport_pins_config (const ioport_cfg_t * p_cfg)
{
    uint16_t       pin_count;
    ioport_cfg_t * p_pin_data;

    p_pin_data = (ioport_cfg_t *) p_cfg;

    R_BSP_PinAccessEnable();
    for (pin_count = 0U; pin_count < p_pin_data->number_of_pins; pin_count++)
    {
        r_ioport_pcr_write(p_pin_data->p_pin_cfg_data[pin_count].pin, p_pin_data->p_pin_cfg_data[pin_count].pin_cfg);
    }

    R_BSP_PinAccessDisable();
}

/*******************************************************************************************************************//**
 * Writes to the specified pin's PCR
 *
 * @param[in]    pin        Pin to write PCR data for
 * @param[in]    value      Value to be written to the PCR register
 *
 **********************************************************************************************************************/
static void r_ioport_pcr_write (bsp_io_port_pin_t pin, uint32_t value)
{
    uint32_t port_type  = ((uint32_t) pin) & BSP_IO_PORT_TYPE_MASK;
    uint32_t port_group = ((uint32_t) pin) & BSP_IO_PORT_GROUP_MASK;
    uint32_t port_pin   = ((uint32_t) pin) & BSP_IO_PORT_PIN_MASK;

    R_BSP_PortWriteEnable((bsp_io_port_t) pin);

    if (BSP_IO_PORT_TYPE_IPORT == port_type)
    {
        /* Do nothing*/
    }
    else if (BSP_IO_PORT_TYPE_JPORT == port_type)
    {
        /* Write JPCR */
        R_JPORT->JPCRn_m[0].PCR[port_pin] = value;
    }
    else if (BSP_IO_PORT_TYPE_APORT == port_type)
    {
        /* Write APCR */
        if (port_group <= BSP_IO_PORT_GROUP_02)
        {
            R_PORT->APCRn_m[port_group >> BSP_IO_PORT_GROUP_POS].PCR[port_pin] = value;
        }
    }
    else
    {
        /* Write PCR */
        if (port_group <= BSP_IO_PORT_GROUP_27)
        {
            R_PORT->PCRn_m[port_group >> BSP_IO_PORT_GROUP_POS].PCR[port_pin] = value;
        }
    }

    R_BSP_PortWriteDisable((bsp_io_port_t) pin);
}
