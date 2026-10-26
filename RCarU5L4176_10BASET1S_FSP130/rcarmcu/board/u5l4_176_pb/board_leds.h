/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @ingroup BOARD_U5L4_176_PB
 * @defgroup BOARD_U5L4_176_PB_LEDS Board LEDs
 * @brief LED information for this board.
 *
 * This is code specific to the PB board. It includes info on the number of LEDs and which pins they are on.
 *
 * @{
 **********************************************************************************************************************/

#ifndef BOARD_LEDS_H
#define BOARD_LEDS_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Information on how many LEDs and what pins they are on. */
typedef struct st_bsp_leds
{
    uint32_t         led_count;        ///< The number of LEDs on this board
    uint32_t const * p_leds;           ///< Pointer to an array of IOPORT pins for controlling LEDs
} bsp_leds_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public Functions
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/** @} (end defgroup BOARD_U5L4_176_PB_LEDS) */
