/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @defgroup BSP_IO BSP I/O access
 * @ingroup BSP_MCU_RCARMCUU5L
 * @brief This module provides basic read/write access to port pins.
 *
 * @{
 **********************************************************************************************************************/

#ifndef BSP_IO_DEVICE_H
#define BSP_IO_DEVICE_H

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_PACKAGE_PINS_BGA257    (257U)
#define BSP_PACKAGE_PINS_BGA176    (176U)
#define BSP_PACKAGE_PINS_BGA144    (144U)
#define BSP_PACKAGE_PINS_BGA100    (100U)
#define BSP_PACKAGE_PINS_BGA80     (80U)
#define BSP_PACKAGE_PINS_BGA64     (64U)

/* Shift to get port in bsp_io_port_t and bsp_io_port_pin_t enums. */
#define BSP_PORT_GROUP_POS         (8UL)
#define BSP_PORT_TYPE_POS          (16UL)
#define BSP_PORT_PWE_POS           (24UL)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Available Port group for each type */
typedef enum e_bsp_io_port_group
{
    BSP_IO_PORT_GROUP_00 = 0x000000,   ///< IO P/IP/JP/AP Group 00
    BSP_IO_PORT_GROUP_01 = 0x000100,   ///< IO P/AP Group 01
    BSP_IO_PORT_GROUP_02 = 0x000200,   ///< IO P/AP Group 02
    BSP_IO_PORT_GROUP_03 = 0x000300,   ///< IO P Group 03
    BSP_IO_PORT_GROUP_08 = 0x000800,   ///< IO P Group 08
    BSP_IO_PORT_GROUP_09 = 0x000900,   ///< IO P Group 09
    BSP_IO_PORT_GROUP_10 = 0x000A00,   ///< IO P Group 10
    BSP_IO_PORT_GROUP_11 = 0x000B00,   ///< IO P Group 11
    BSP_IO_PORT_GROUP_12 = 0x000C00,   ///< IO P Group 12
    BSP_IO_PORT_GROUP_13 = 0x000D00,   ///< IO P Group 13
    BSP_IO_PORT_GROUP_14 = 0x000E00,   ///< IO P Group 14
    BSP_IO_PORT_GROUP_18 = 0x001200,   ///< IO P Group 18
    BSP_IO_PORT_GROUP_19 = 0x001300,   ///< IO P Group 19
    BSP_IO_PORT_GROUP_20 = 0x001400,   ///< IO P Group 20
    BSP_IO_PORT_GROUP_21 = 0x001500,   ///< IO P Group 21
    BSP_IO_PORT_GROUP_27 = 0x001b00,   ///< IO P Group 27
} bsp_io_port_group_t;

/** Superset list of all possible IO ports. */
/* BSP_IO_PORT_[TYPE][GROUP] = [PWE] << BSP_PORT_PWE_POS) | ([TYPE] << BSP_PORT_TYPE_POS) | ([GROUP] << BSP_PORT_GROUP_POS) | ([PORT] */

typedef enum e_bsp_io_port
{
#if (BSP_PACKAGE_PINS_BGA257 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00 =
        ((0 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P00
    BSP_IO_PORT_P01 =
        ((1 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (1 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P01
    BSP_IO_PORT_P02 =
        ((2 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (2 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P02
    BSP_IO_PORT_P03 =
        ((3 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (3 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P03
    BSP_IO_PORT_P08 =
        ((4 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (8 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P08
    BSP_IO_PORT_P09 =
        ((5 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (9 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P09
    BSP_IO_PORT_P10 =
        ((6 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (10 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P10
    BSP_IO_PORT_P11 =
        ((7 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (11 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P11
    BSP_IO_PORT_P12 =
        ((8 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (12 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P12
    BSP_IO_PORT_P13 =
        ((9 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (13 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P13
    BSP_IO_PORT_P18 =
        ((10 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (18 << BSP_PORT_GROUP_POS) | (0)), ///< IO port P18
    BSP_IO_PORT_P19 =
        ((11 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (19 << BSP_PORT_GROUP_POS) | (0)), ///< IO port P19
    BSP_IO_PORT_P20 =
        ((12 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (20 << BSP_PORT_GROUP_POS) | (0)), ///< IO port P20
    BSP_IO_PORT_P21 =
        ((13 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (21 << BSP_PORT_GROUP_POS) | (0)), ///< IO port P21
    BSP_IO_PORT_P27 =
        ((16 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (27 << BSP_PORT_GROUP_POS) | (0)), ///< IO port P27
    BSP_IO_PORT_AP00 =
        ((20 << BSP_PORT_PWE_POS) | (1 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port AP00
    BSP_IO_PORT_AP02 =
        ((22 << BSP_PORT_PWE_POS) | (1 << BSP_PORT_TYPE_POS) | (2 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port AP02
    BSP_IO_PORT_JP00 =
        ((255 << BSP_PORT_PWE_POS) | (2 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)), ///< IO port JP00
    BSP_IO_PORT_IP00 =
        ((26 << BSP_PORT_PWE_POS) | (3 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port IP00
#elif (BSP_PACKAGE_PINS_BGA176 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00 =
        ((0 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P00
    BSP_IO_PORT_P01 =
        ((1 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (1 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P01
    BSP_IO_PORT_P02 =
        ((2 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (2 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P02
    BSP_IO_PORT_P08 =
        ((4 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (8 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P08
    BSP_IO_PORT_P09 =
        ((5 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (9 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P09
    BSP_IO_PORT_P10 =
        ((6 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (10 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P10
    BSP_IO_PORT_P11 =
        ((7 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (11 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P11
    BSP_IO_PORT_P12 =
        ((8 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (12 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P12
    BSP_IO_PORT_P18 =
        ((10 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (18 << BSP_PORT_GROUP_POS) | (0)), ///< IO port P18
    BSP_IO_PORT_P20 =
        ((12 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (20 << BSP_PORT_GROUP_POS) | (0)), ///< IO port P20
    BSP_IO_PORT_P27 =
        ((16 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (27 << BSP_PORT_GROUP_POS) | (0)), ///< IO port P27
    BSP_IO_PORT_AP00 =
        ((20 << BSP_PORT_PWE_POS) | (1 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port AP00
    BSP_IO_PORT_AP02 =
        ((22 << BSP_PORT_PWE_POS) | (1 << BSP_PORT_TYPE_POS) | (2 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port AP02
    BSP_IO_PORT_JP00 =
        ((255 << BSP_PORT_PWE_POS) | (2 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)), ///< IO port JP00
    BSP_IO_PORT_IP00 =
        ((26 << BSP_PORT_PWE_POS) | (3 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port IP00
#elif (BSP_PACKAGE_PINS_BGA144 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00 =
        ((0 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P00
    BSP_IO_PORT_P01 =
        ((1 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (1 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P01
    BSP_IO_PORT_P08 =
        ((4 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (8 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P08
    BSP_IO_PORT_P09 =
        ((5 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (9 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P09
    BSP_IO_PORT_P10 =
        ((6 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (10 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P10
    BSP_IO_PORT_P11 =
        ((7 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (11 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P11
    BSP_IO_PORT_P12 =
        ((8 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (12 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P12
    BSP_IO_PORT_P18 =
        ((10 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (18 << BSP_PORT_GROUP_POS) | (0)), ///< IO port P18
    BSP_IO_PORT_P20 =
        ((12 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (20 << BSP_PORT_GROUP_POS) | (0)), ///< IO port P20
    BSP_IO_PORT_P27 =
        ((16 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (27 << BSP_PORT_GROUP_POS) | (0)), ///< IO port P27
    BSP_IO_PORT_AP00 =
        ((20 << BSP_PORT_PWE_POS) | (1 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port AP00
    BSP_IO_PORT_AP02 =
        ((22 << BSP_PORT_PWE_POS) | (1 << BSP_PORT_TYPE_POS) | (2 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port AP02
    BSP_IO_PORT_JP00 =
        ((255 << BSP_PORT_PWE_POS) | (2 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)), ///< IO port JP00
    BSP_IO_PORT_IP00 =
        ((26 << BSP_PORT_PWE_POS) | (3 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port IP00
#elif (BSP_PACKAGE_PINS_BGA100 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00 =
        ((0 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P00
    BSP_IO_PORT_P08 =
        ((4 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (8 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P08
    BSP_IO_PORT_P09 =
        ((5 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (9 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P09
    BSP_IO_PORT_P10 =
        ((6 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (10 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P10
    BSP_IO_PORT_P11 =
        ((7 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (11 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P11
    BSP_IO_PORT_P27 =
        ((16 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (27 << BSP_PORT_GROUP_POS) | (0)), ///< IO port P27
    BSP_IO_PORT_AP00 =
        ((20 << BSP_PORT_PWE_POS) | (1 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port AP00
    BSP_IO_PORT_JP00 =
        ((255 << BSP_PORT_PWE_POS) | (2 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)), ///< IO port JP00
#elif (BSP_PACKAGE_PINS_BGA80 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00 =
        ((0 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P00
    BSP_IO_PORT_P08 =
        ((4 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (8 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P08
    BSP_IO_PORT_P09 =
        ((5 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (9 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P09
    BSP_IO_PORT_P10 =
        ((6 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (10 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P10
    BSP_IO_PORT_P11 =
        ((7 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (11 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P11
    BSP_IO_PORT_P27 =
        ((16 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (27 << BSP_PORT_GROUP_POS) | (0)), ///< IO port P27
    BSP_IO_PORT_AP00 =
        ((20 << BSP_PORT_PWE_POS) | (1 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port AP00
    BSP_IO_PORT_JP00 =
        ((255 << BSP_PORT_PWE_POS) | (2 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)), ///< IO port JP00
#elif (BSP_PACKAGE_PINS_BGA64 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00 =
        ((0 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P00
    BSP_IO_PORT_P08 =
        ((4 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (8 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P08
    BSP_IO_PORT_P09 =
        ((5 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (9 << BSP_PORT_GROUP_POS) | (0)),   ///< IO port P09
    BSP_IO_PORT_P10 =
        ((6 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (10 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port P10
    BSP_IO_PORT_P27 =
        ((16 << BSP_PORT_PWE_POS) | (0 << BSP_PORT_TYPE_POS) | (27 << BSP_PORT_GROUP_POS) | (0)), ///< IO port P27
    BSP_IO_PORT_AP00 =
        ((20 << BSP_PORT_PWE_POS) | (1 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)),  ///< IO port AP00
    BSP_IO_PORT_JP00 =
        ((255 << BSP_PORT_PWE_POS) | (2 << BSP_PORT_TYPE_POS) | (0 << BSP_PORT_GROUP_POS) | (0)), ///< IO port JP00
#endif
} bsp_io_port_t;

/** Superset list of all possible IO port pins. */
typedef enum e_bsp_io_port_pin_t
{
#if (BSP_PACKAGE_PINS_BGA257 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00_PIN_0  = (BSP_IO_PORT_P00 | 0x00),   ///< IO port P00 pin 0
    BSP_IO_PORT_P00_PIN_1  = (BSP_IO_PORT_P00 | 0x01),   ///< IO port P00 pin 1
    BSP_IO_PORT_P00_PIN_2  = (BSP_IO_PORT_P00 | 0x02),   ///< IO port P00 pin 2
    BSP_IO_PORT_P00_PIN_3  = (BSP_IO_PORT_P00 | 0x03),   ///< IO port P00 pin 3
    BSP_IO_PORT_P00_PIN_4  = (BSP_IO_PORT_P00 | 0x04),   ///< IO port P00 pin 4
    BSP_IO_PORT_P00_PIN_5  = (BSP_IO_PORT_P00 | 0x05),   ///< IO port P00 pin 5
    BSP_IO_PORT_P00_PIN_6  = (BSP_IO_PORT_P00 | 0x06),   ///< IO port P00 pin 6
    BSP_IO_PORT_P00_PIN_7  = (BSP_IO_PORT_P00 | 0x07),   ///< IO port P00 pin 7
    BSP_IO_PORT_P00_PIN_8  = (BSP_IO_PORT_P00 | 0x08),   ///< IO port P00 pin 8
    BSP_IO_PORT_P00_PIN_9  = (BSP_IO_PORT_P00 | 0x09),   ///< IO port P00 pin 9
    BSP_IO_PORT_P00_PIN_10 = (BSP_IO_PORT_P00 | 0x0A),   ///< IO port P00 pin 10
    BSP_IO_PORT_P00_PIN_11 = (BSP_IO_PORT_P00 | 0x0B),   ///< IO port P00 pin 11
    BSP_IO_PORT_P00_PIN_12 = (BSP_IO_PORT_P00 | 0x0C),   ///< IO port P00 pin 12
    BSP_IO_PORT_P00_PIN_13 = (BSP_IO_PORT_P00 | 0x0D),   ///< IO port P00 pin 13
    BSP_IO_PORT_P00_PIN_14 = (BSP_IO_PORT_P00 | 0x0E),   ///< IO port P00 pin 14

    BSP_IO_PORT_P01_PIN_0  = (BSP_IO_PORT_P01 | 0x00),   ///< IO port P01 pin 0
    BSP_IO_PORT_P01_PIN_1  = (BSP_IO_PORT_P01 | 0x01),   ///< IO port P01 pin 1
    BSP_IO_PORT_P01_PIN_2  = (BSP_IO_PORT_P01 | 0x02),   ///< IO port P01 pin 2
    BSP_IO_PORT_P01_PIN_3  = (BSP_IO_PORT_P01 | 0x03),   ///< IO port P01 pin 3
    BSP_IO_PORT_P01_PIN_4  = (BSP_IO_PORT_P01 | 0x04),   ///< IO port P01 pin 4
    BSP_IO_PORT_P01_PIN_5  = (BSP_IO_PORT_P01 | 0x05),   ///< IO port P01 pin 5
    BSP_IO_PORT_P01_PIN_8  = (BSP_IO_PORT_P01 | 0x08),   ///< IO port P01 pin 8
    BSP_IO_PORT_P01_PIN_9  = (BSP_IO_PORT_P01 | 0x09),   ///< IO port P01 pin 9
    BSP_IO_PORT_P01_PIN_10 = (BSP_IO_PORT_P01 | 0x0A),   ///< IO port P01 pin 10
    BSP_IO_PORT_P01_PIN_11 = (BSP_IO_PORT_P01 | 0x0B),   ///< IO port P01 pin 11
    BSP_IO_PORT_P01_PIN_12 = (BSP_IO_PORT_P01 | 0x0C),   ///< IO port P01 pin 12
    BSP_IO_PORT_P01_PIN_13 = (BSP_IO_PORT_P01 | 0x0D),   ///< IO port P01 pin 13
    BSP_IO_PORT_P01_PIN_14 = (BSP_IO_PORT_P01 | 0x0E),   ///< IO port P01 pin 14
    BSP_IO_PORT_P01_PIN_15 = (BSP_IO_PORT_P01 | 0x0F),   ///< IO port P01 pin 15

    BSP_IO_PORT_P02_PIN_0  = (BSP_IO_PORT_P02 | 0x00),   ///< IO port P02 pin 0
    BSP_IO_PORT_P02_PIN_1  = (BSP_IO_PORT_P02 | 0x01),   ///< IO port P02 pin 1
    BSP_IO_PORT_P02_PIN_2  = (BSP_IO_PORT_P02 | 0x02),   ///< IO port P02 pin 2
    BSP_IO_PORT_P02_PIN_3  = (BSP_IO_PORT_P02 | 0x03),   ///< IO port P02 pin 3
    BSP_IO_PORT_P02_PIN_4  = (BSP_IO_PORT_P02 | 0x04),   ///< IO port P02 pin 4
    BSP_IO_PORT_P02_PIN_5  = (BSP_IO_PORT_P02 | 0x05),   ///< IO port P02 pin 5
    BSP_IO_PORT_P02_PIN_6  = (BSP_IO_PORT_P02 | 0x06),   ///< IO port P02 pin 6
    BSP_IO_PORT_P02_PIN_7  = (BSP_IO_PORT_P02 | 0x07),   ///< IO port P02 pin 7
    BSP_IO_PORT_P02_PIN_8  = (BSP_IO_PORT_P02 | 0x08),   ///< IO port P02 pin 8
    BSP_IO_PORT_P02_PIN_9  = (BSP_IO_PORT_P02 | 0x09),   ///< IO port P02 pin 9
    BSP_IO_PORT_P02_PIN_10 = (BSP_IO_PORT_P02 | 0x0A),   ///< IO port P02 pin 10
    BSP_IO_PORT_P02_PIN_11 = (BSP_IO_PORT_P02 | 0x0B),   ///< IO port P02 pin 11
    BSP_IO_PORT_P02_PIN_12 = (BSP_IO_PORT_P02 | 0x0C),   ///< IO port P02 pin 12
    BSP_IO_PORT_P02_PIN_13 = (BSP_IO_PORT_P02 | 0x0D),   ///< IO port P02 pin 13

    BSP_IO_PORT_P03_PIN_0 = (BSP_IO_PORT_P03 | 0x00),    ///< IO port P03 pin 0
    BSP_IO_PORT_P03_PIN_1 = (BSP_IO_PORT_P03 | 0x01),    ///< IO port P03 pin 1
    BSP_IO_PORT_P03_PIN_2 = (BSP_IO_PORT_P03 | 0x02),    ///< IO port P03 pin 2
    BSP_IO_PORT_P03_PIN_3 = (BSP_IO_PORT_P03 | 0x03),    ///< IO port P03 pin 3
    BSP_IO_PORT_P03_PIN_4 = (BSP_IO_PORT_P03 | 0x04),    ///< IO port P03 pin 4
    BSP_IO_PORT_P03_PIN_5 = (BSP_IO_PORT_P03 | 0x05),    ///< IO port P03 pin 5
    BSP_IO_PORT_P03_PIN_6 = (BSP_IO_PORT_P03 | 0x06),    ///< IO port P03 pin 6
    BSP_IO_PORT_P03_PIN_7 = (BSP_IO_PORT_P03 | 0x07),    ///< IO port P03 pin 7
    BSP_IO_PORT_P03_PIN_8 = (BSP_IO_PORT_P03 | 0x08),    ///< IO port P03 pin 8

    BSP_IO_PORT_P08_PIN_0  = (BSP_IO_PORT_P08 | 0x00),   ///< IO port P08 pin 0
    BSP_IO_PORT_P08_PIN_1  = (BSP_IO_PORT_P08 | 0x01),   ///< IO port P08 pin 1
    BSP_IO_PORT_P08_PIN_2  = (BSP_IO_PORT_P08 | 0x02),   ///< IO port P08 pin 2
    BSP_IO_PORT_P08_PIN_3  = (BSP_IO_PORT_P08 | 0x03),   ///< IO port P08 pin 3
    BSP_IO_PORT_P08_PIN_4  = (BSP_IO_PORT_P08 | 0x04),   ///< IO port P08 pin 4
    BSP_IO_PORT_P08_PIN_5  = (BSP_IO_PORT_P08 | 0x05),   ///< IO port P08 pin 5
    BSP_IO_PORT_P08_PIN_7  = (BSP_IO_PORT_P08 | 0x07),   ///< IO port P08 pin 7
    BSP_IO_PORT_P08_PIN_8  = (BSP_IO_PORT_P08 | 0x08),   ///< IO port P08 pin 8
    BSP_IO_PORT_P08_PIN_9  = (BSP_IO_PORT_P08 | 0x09),   ///< IO port P08 pin 9
    BSP_IO_PORT_P08_PIN_10 = (BSP_IO_PORT_P08 | 0x0A),   ///< IO port P08 pin 10
    BSP_IO_PORT_P08_PIN_11 = (BSP_IO_PORT_P08 | 0x0B),   ///< IO port P08 pin 11
    BSP_IO_PORT_P08_PIN_12 = (BSP_IO_PORT_P08 | 0x0C),   ///< IO port P08 pin 12

    BSP_IO_PORT_P09_PIN_0  = (BSP_IO_PORT_P09 | 0x00),   ///< IO port P09 pin 0
    BSP_IO_PORT_P09_PIN_1  = (BSP_IO_PORT_P09 | 0x01),   ///< IO port P09 pin 1
    BSP_IO_PORT_P09_PIN_2  = (BSP_IO_PORT_P09 | 0x02),   ///< IO port P09 pin 2
    BSP_IO_PORT_P09_PIN_3  = (BSP_IO_PORT_P09 | 0x03),   ///< IO port P09 pin 3
    BSP_IO_PORT_P09_PIN_4  = (BSP_IO_PORT_P09 | 0x04),   ///< IO port P09 pin 4
    BSP_IO_PORT_P10_PIN_0  = (BSP_IO_PORT_P10 | 0x00),   ///< IO port P10 pin 0
    BSP_IO_PORT_P10_PIN_1  = (BSP_IO_PORT_P10 | 0x01),   ///< IO port P10 pin 1
    BSP_IO_PORT_P10_PIN_2  = (BSP_IO_PORT_P10 | 0x02),   ///< IO port P10 pin 2
    BSP_IO_PORT_P10_PIN_3  = (BSP_IO_PORT_P10 | 0x03),   ///< IO port P10 pin 3
    BSP_IO_PORT_P10_PIN_4  = (BSP_IO_PORT_P10 | 0x04),   ///< IO port P10 pin 4
    BSP_IO_PORT_P10_PIN_5  = (BSP_IO_PORT_P10 | 0x05),   ///< IO port P10 pin 5
    BSP_IO_PORT_P10_PIN_6  = (BSP_IO_PORT_P10 | 0x06),   ///< IO port P10 pin 6
    BSP_IO_PORT_P10_PIN_7  = (BSP_IO_PORT_P10 | 0x07),   ///< IO port P10 pin 7
    BSP_IO_PORT_P10_PIN_8  = (BSP_IO_PORT_P10 | 0x08),   ///< IO port P10 pin 8
    BSP_IO_PORT_P10_PIN_9  = (BSP_IO_PORT_P10 | 0x09),   ///< IO port P10 pin 9
    BSP_IO_PORT_P10_PIN_10 = (BSP_IO_PORT_P10 | 0x0A),   ///< IO port P10 pin 10
    BSP_IO_PORT_P10_PIN_11 = (BSP_IO_PORT_P10 | 0x0B),   ///< IO port P10 pin 11
    BSP_IO_PORT_P10_PIN_12 = (BSP_IO_PORT_P10 | 0x0C),   ///< IO port P10 pin 12
    BSP_IO_PORT_P10_PIN_13 = (BSP_IO_PORT_P10 | 0x0D),   ///< IO port P10 pin 13
    BSP_IO_PORT_P10_PIN_14 = (BSP_IO_PORT_P10 | 0x0E),   ///< IO port P10 pin 14
    BSP_IO_PORT_P10_PIN_15 = (BSP_IO_PORT_P10 | 0x0F),   ///< IO port P10 pin 15

    BSP_IO_PORT_P11_PIN_0  = (BSP_IO_PORT_P11 | 0x00),   ///< IO port P11 pin 0
    BSP_IO_PORT_P11_PIN_1  = (BSP_IO_PORT_P11 | 0x01),   ///< IO port P11 pin 1
    BSP_IO_PORT_P11_PIN_2  = (BSP_IO_PORT_P11 | 0x02),   ///< IO port P11 pin 2
    BSP_IO_PORT_P11_PIN_3  = (BSP_IO_PORT_P11 | 0x03),   ///< IO port P11 pin 3
    BSP_IO_PORT_P11_PIN_4  = (BSP_IO_PORT_P11 | 0x04),   ///< IO port P11 pin 4
    BSP_IO_PORT_P11_PIN_5  = (BSP_IO_PORT_P11 | 0x05),   ///< IO port P11 pin 5
    BSP_IO_PORT_P11_PIN_6  = (BSP_IO_PORT_P11 | 0x06),   ///< IO port P11 pin 6
    BSP_IO_PORT_P11_PIN_7  = (BSP_IO_PORT_P11 | 0x07),   ///< IO port P11 pin 7
    BSP_IO_PORT_P11_PIN_8  = (BSP_IO_PORT_P11 | 0x08),   ///< IO port P11 pin 8
    BSP_IO_PORT_P11_PIN_9  = (BSP_IO_PORT_P11 | 0x09),   ///< IO port P11 pin 9
    BSP_IO_PORT_P11_PIN_10 = (BSP_IO_PORT_P11 | 0x0A),   ///< IO port P11 pin 10
    BSP_IO_PORT_P11_PIN_11 = (BSP_IO_PORT_P11 | 0x0B),   ///< IO port P11 pin 11
    BSP_IO_PORT_P11_PIN_12 = (BSP_IO_PORT_P11 | 0x0C),   ///< IO port P11 pin 12
    BSP_IO_PORT_P11_PIN_15 = (BSP_IO_PORT_P11 | 0x0F),   ///< IO port P11 pin 15

    BSP_IO_PORT_P12_PIN_0 = (BSP_IO_PORT_P12 | 0x00),    ///< IO port P12 pin 0
    BSP_IO_PORT_P12_PIN_1 = (BSP_IO_PORT_P12 | 0x01),    ///< IO port P12 pin 1
    BSP_IO_PORT_P12_PIN_2 = (BSP_IO_PORT_P12 | 0x02),    ///< IO port P12 pin 2
    BSP_IO_PORT_P12_PIN_3 = (BSP_IO_PORT_P12 | 0x03),    ///< IO port P12 pin 3
    BSP_IO_PORT_P12_PIN_4 = (BSP_IO_PORT_P12 | 0x04),    ///< IO port P12 pin 4
    BSP_IO_PORT_P12_PIN_5 = (BSP_IO_PORT_P12 | 0x05),    ///< IO port P12 pin 5
    BSP_IO_PORT_P13_PIN_0 = (BSP_IO_PORT_P13 | 0x00),    ///< IO port P13 pin 0
    BSP_IO_PORT_P13_PIN_1 = (BSP_IO_PORT_P13 | 0x01),    ///< IO port P13 pin 1
    BSP_IO_PORT_P13_PIN_2 = (BSP_IO_PORT_P13 | 0x02),    ///< IO port P13 pin 2
    BSP_IO_PORT_P13_PIN_3 = (BSP_IO_PORT_P13 | 0x03),    ///< IO port P13 pin 3
    BSP_IO_PORT_P13_PIN_4 = (BSP_IO_PORT_P13 | 0x04),    ///< IO port P13 pin 4
    BSP_IO_PORT_P13_PIN_5 = (BSP_IO_PORT_P13 | 0x05),    ///< IO port P13 pin 5
    BSP_IO_PORT_P13_PIN_6 = (BSP_IO_PORT_P13 | 0x06),    ///< IO port P13 pin 6
    BSP_IO_PORT_P13_PIN_7 = (BSP_IO_PORT_P13 | 0x07),    ///< IO port P13 pin 7

    BSP_IO_PORT_P18_PIN_0  = (BSP_IO_PORT_P18 | 0x00),   ///< IO port P18 pin 0
    BSP_IO_PORT_P18_PIN_1  = (BSP_IO_PORT_P18 | 0x01),   ///< IO port P18 pin 1
    BSP_IO_PORT_P18_PIN_2  = (BSP_IO_PORT_P18 | 0x02),   ///< IO port P18 pin 2
    BSP_IO_PORT_P18_PIN_3  = (BSP_IO_PORT_P18 | 0x03),   ///< IO port P18 pin 3
    BSP_IO_PORT_P18_PIN_4  = (BSP_IO_PORT_P18 | 0x04),   ///< IO port P18 pin 4
    BSP_IO_PORT_P18_PIN_5  = (BSP_IO_PORT_P18 | 0x05),   ///< IO port P18 pin 5
    BSP_IO_PORT_P18_PIN_6  = (BSP_IO_PORT_P18 | 0x06),   ///< IO port P18 pin 6
    BSP_IO_PORT_P18_PIN_7  = (BSP_IO_PORT_P18 | 0x07),   ///< IO port P18 pin 7
    BSP_IO_PORT_P18_PIN_8  = (BSP_IO_PORT_P18 | 0x08),   ///< IO port P18 pin 8
    BSP_IO_PORT_P18_PIN_9  = (BSP_IO_PORT_P18 | 0x09),   ///< IO port P18 pin 9
    BSP_IO_PORT_P18_PIN_10 = (BSP_IO_PORT_P18 | 0x0A),   ///< IO port P18 pin 10
    BSP_IO_PORT_P18_PIN_11 = (BSP_IO_PORT_P18 | 0x0B),   ///< IO port P18 pin 11
    BSP_IO_PORT_P18_PIN_12 = (BSP_IO_PORT_P18 | 0x0C),   ///< IO port P18 pin 12
    BSP_IO_PORT_P18_PIN_13 = (BSP_IO_PORT_P18 | 0x0D),   ///< IO port P18 pin 13
    BSP_IO_PORT_P18_PIN_14 = (BSP_IO_PORT_P18 | 0x0E),   ///< IO port P18 pin 14
    BSP_IO_PORT_P18_PIN_15 = (BSP_IO_PORT_P18 | 0x0F),   ///< IO port P18 pin 15

    BSP_IO_PORT_P19_PIN_0 = (BSP_IO_PORT_P19 | 0x00),    ///< IO port P19 pin 0
    BSP_IO_PORT_P19_PIN_1 = (BSP_IO_PORT_P19 | 0x01),    ///< IO port P19 pin 1
    BSP_IO_PORT_P19_PIN_2 = (BSP_IO_PORT_P19 | 0x02),    ///< IO port P19 pin 2
    BSP_IO_PORT_P19_PIN_3 = (BSP_IO_PORT_P19 | 0x03),    ///< IO port P19 pin 3

    BSP_IO_PORT_P20_PIN_0  = (BSP_IO_PORT_P20 | 0x00),   ///< IO port P20 pin 0
    BSP_IO_PORT_P20_PIN_1  = (BSP_IO_PORT_P20 | 0x01),   ///< IO port P20 pin 1
    BSP_IO_PORT_P20_PIN_2  = (BSP_IO_PORT_P20 | 0x02),   ///< IO port P20 pin 2
    BSP_IO_PORT_P20_PIN_3  = (BSP_IO_PORT_P20 | 0x03),   ///< IO port P20 pin 3
    BSP_IO_PORT_P20_PIN_4  = (BSP_IO_PORT_P20 | 0x04),   ///< IO port P20 pin 4
    BSP_IO_PORT_P20_PIN_5  = (BSP_IO_PORT_P20 | 0x05),   ///< IO port P20 pin 5
    BSP_IO_PORT_P20_PIN_6  = (BSP_IO_PORT_P20 | 0x06),   ///< IO port P20 pin 6
    BSP_IO_PORT_P20_PIN_7  = (BSP_IO_PORT_P20 | 0x07),   ///< IO port P20 pin 7
    BSP_IO_PORT_P20_PIN_8  = (BSP_IO_PORT_P20 | 0x08),   ///< IO port P20 pin 8
    BSP_IO_PORT_P20_PIN_9  = (BSP_IO_PORT_P20 | 0x09),   ///< IO port P20 pin 9
    BSP_IO_PORT_P20_PIN_10 = (BSP_IO_PORT_P20 | 0x0A),   ///< IO port P20 pin 10
    BSP_IO_PORT_P20_PIN_11 = (BSP_IO_PORT_P20 | 0x0B),   ///< IO port P20 pin 11
    BSP_IO_PORT_P20_PIN_12 = (BSP_IO_PORT_P20 | 0x0C),   ///< IO port P20 pin 12
    BSP_IO_PORT_P20_PIN_13 = (BSP_IO_PORT_P20 | 0x0D),   ///< IO port P20 pin 13

    BSP_IO_PORT_P21_PIN_0 = (BSP_IO_PORT_P21 | 0x00),    ///< IO port P21 pin 0
    BSP_IO_PORT_P21_PIN_1 = (BSP_IO_PORT_P21 | 0x01),    ///< IO port P21 pin 1
    BSP_IO_PORT_P21_PIN_2 = (BSP_IO_PORT_P21 | 0x02),    ///< IO port P21 pin 2

    BSP_IO_PORT_P27_PIN_0 = (BSP_IO_PORT_P27 | 0x00),    ///< IO port P27 pin 0

    BSP_IO_PORT_AP00_PIN_0  = (BSP_IO_PORT_AP00 | 0x00), ///< IO port AP00 pin 0
    BSP_IO_PORT_AP00_PIN_1  = (BSP_IO_PORT_AP00 | 0x01), ///< IO port AP00 pin 1
    BSP_IO_PORT_AP00_PIN_2  = (BSP_IO_PORT_AP00 | 0x02), ///< IO port AP00 pin 2
    BSP_IO_PORT_AP00_PIN_3  = (BSP_IO_PORT_AP00 | 0x03), ///< IO port AP00 pin 3
    BSP_IO_PORT_AP00_PIN_4  = (BSP_IO_PORT_AP00 | 0x04), ///< IO port AP00 pin 4
    BSP_IO_PORT_AP00_PIN_5  = (BSP_IO_PORT_AP00 | 0x05), ///< IO port AP00 pin 5
    BSP_IO_PORT_AP00_PIN_6  = (BSP_IO_PORT_AP00 | 0x06), ///< IO port AP00 pin 6
    BSP_IO_PORT_AP00_PIN_7  = (BSP_IO_PORT_AP00 | 0x07), ///< IO port AP00 pin 7
    BSP_IO_PORT_AP00_PIN_8  = (BSP_IO_PORT_AP00 | 0x08), ///< IO port AP00 pin 8
    BSP_IO_PORT_AP00_PIN_9  = (BSP_IO_PORT_AP00 | 0x09), ///< IO port AP00 pin 9
    BSP_IO_PORT_AP00_PIN_10 = (BSP_IO_PORT_AP00 | 0x0A), ///< IO port AP00 pin 10
    BSP_IO_PORT_AP00_PIN_11 = (BSP_IO_PORT_AP00 | 0x0B), ///< IO port AP00 pin 11
    BSP_IO_PORT_AP00_PIN_12 = (BSP_IO_PORT_AP00 | 0x0C), ///< IO port AP00 pin 12
    BSP_IO_PORT_AP00_PIN_13 = (BSP_IO_PORT_AP00 | 0x0D), ///< IO port AP00 pin 13
    BSP_IO_PORT_AP00_PIN_14 = (BSP_IO_PORT_AP00 | 0x0E), ///< IO port AP00 pin 14
    BSP_IO_PORT_AP00_PIN_15 = (BSP_IO_PORT_AP00 | 0x0F), ///< IO port AP00 pin 15

    BSP_IO_PORT_AP02_PIN_0  = (BSP_IO_PORT_AP02 | 0x00), ///< IO port AP02 pin 0
    BSP_IO_PORT_AP02_PIN_1  = (BSP_IO_PORT_AP02 | 0x01), ///< IO port AP02 pin 1
    BSP_IO_PORT_AP02_PIN_2  = (BSP_IO_PORT_AP02 | 0x02), ///< IO port AP02 pin 2
    BSP_IO_PORT_AP02_PIN_3  = (BSP_IO_PORT_AP02 | 0x03), ///< IO port AP02 pin 3
    BSP_IO_PORT_AP02_PIN_4  = (BSP_IO_PORT_AP02 | 0x04), ///< IO port AP02 pin 4
    BSP_IO_PORT_AP02_PIN_5  = (BSP_IO_PORT_AP02 | 0x05), ///< IO port AP02 pin 5
    BSP_IO_PORT_AP02_PIN_6  = (BSP_IO_PORT_AP02 | 0x06), ///< IO port AP02 pin 6
    BSP_IO_PORT_AP02_PIN_7  = (BSP_IO_PORT_AP02 | 0x07), ///< IO port AP02 pin 7
    BSP_IO_PORT_AP02_PIN_8  = (BSP_IO_PORT_AP02 | 0x08), ///< IO port AP02 pin 8
    BSP_IO_PORT_AP02_PIN_9  = (BSP_IO_PORT_AP02 | 0x09), ///< IO port AP02 pin 9
    BSP_IO_PORT_AP02_PIN_10 = (BSP_IO_PORT_AP02 | 0x0A), ///< IO port AP02 pin 10
    BSP_IO_PORT_AP02_PIN_11 = (BSP_IO_PORT_AP02 | 0x0B), ///< IO port AP02 pin 11
    BSP_IO_PORT_AP02_PIN_12 = (BSP_IO_PORT_AP02 | 0x0C), ///< IO port AP02 pin 12
    BSP_IO_PORT_AP02_PIN_13 = (BSP_IO_PORT_AP02 | 0x0D), ///< IO port AP02 pin 13
    BSP_IO_PORT_AP02_PIN_14 = (BSP_IO_PORT_AP02 | 0x0E), ///< IO port AP02 pin 14
    BSP_IO_PORT_AP02_PIN_15 = (BSP_IO_PORT_AP02 | 0x0F), ///< IO port AP02 pin 15

    BSP_IO_PORT_JP00_PIN_0 = (BSP_IO_PORT_JP00 | 0x00),  ///< IO port JP00 pin 0
    BSP_IO_PORT_JP00_PIN_1 = (BSP_IO_PORT_JP00 | 0x01),  ///< IO port JP00 pin 1
    BSP_IO_PORT_JP00_PIN_2 = (BSP_IO_PORT_JP00 | 0x02),  ///< IO port JP00 pin 2
    BSP_IO_PORT_JP00_PIN_3 = (BSP_IO_PORT_JP00 | 0x03),  ///< IO port JP00 pin 3
    BSP_IO_PORT_JP00_PIN_5 = (BSP_IO_PORT_JP00 | 0x05),  ///< IO port JP00 pin 5
    BSP_IO_PORT_JP00_PIN_6 = (BSP_IO_PORT_JP00 | 0x06),  ///< IO port JP00 pin 6

    BSP_IO_PORT_IP00_PIN_0 = (BSP_IO_PORT_IP00 | 0x00),  ///< IO port IP00 pin 0
    BSP_IO_PORT_IP00_PIN_1 = (BSP_IO_PORT_IP00 | 0x01),  ///< IO port IP00 pin 1
#elif (BSP_PACKAGE_PINS_BGA176 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00_PIN_0  = (BSP_IO_PORT_P00 | 0x00),   ///< IO port P00 pin 0
    BSP_IO_PORT_P00_PIN_1  = (BSP_IO_PORT_P00 | 0x01),   ///< IO port P00 pin 1
    BSP_IO_PORT_P00_PIN_2  = (BSP_IO_PORT_P00 | 0x02),   ///< IO port P00 pin 2
    BSP_IO_PORT_P00_PIN_3  = (BSP_IO_PORT_P00 | 0x03),   ///< IO port P00 pin 3
    BSP_IO_PORT_P00_PIN_4  = (BSP_IO_PORT_P00 | 0x04),   ///< IO port P00 pin 4
    BSP_IO_PORT_P00_PIN_5  = (BSP_IO_PORT_P00 | 0x05),   ///< IO port P00 pin 5
    BSP_IO_PORT_P00_PIN_6  = (BSP_IO_PORT_P00 | 0x06),   ///< IO port P00 pin 6
    BSP_IO_PORT_P00_PIN_7  = (BSP_IO_PORT_P00 | 0x07),   ///< IO port P00 pin 7
    BSP_IO_PORT_P00_PIN_8  = (BSP_IO_PORT_P00 | 0x08),   ///< IO port P00 pin 8
    BSP_IO_PORT_P00_PIN_9  = (BSP_IO_PORT_P00 | 0x09),   ///< IO port P00 pin 9
    BSP_IO_PORT_P00_PIN_10 = (BSP_IO_PORT_P00 | 0x0A),   ///< IO port P00 pin 10
    BSP_IO_PORT_P00_PIN_11 = (BSP_IO_PORT_P00 | 0x0B),   ///< IO port P00 pin 11
    BSP_IO_PORT_P00_PIN_12 = (BSP_IO_PORT_P00 | 0x0C),   ///< IO port P00 pin 12
    BSP_IO_PORT_P00_PIN_13 = (BSP_IO_PORT_P00 | 0x0D),   ///< IO port P00 pin 13
    BSP_IO_PORT_P00_PIN_14 = (BSP_IO_PORT_P00 | 0x0E),   ///< IO port P00 pin 14

    BSP_IO_PORT_P01_PIN_0  = (BSP_IO_PORT_P01 | 0x00),   ///< IO port P01 pin 0
    BSP_IO_PORT_P01_PIN_1  = (BSP_IO_PORT_P01 | 0x01),   ///< IO port P01 pin 1
    BSP_IO_PORT_P01_PIN_2  = (BSP_IO_PORT_P01 | 0x02),   ///< IO port P01 pin 2
    BSP_IO_PORT_P01_PIN_3  = (BSP_IO_PORT_P01 | 0x03),   ///< IO port P01 pin 3
    BSP_IO_PORT_P01_PIN_4  = (BSP_IO_PORT_P01 | 0x04),   ///< IO port P01 pin 4
    BSP_IO_PORT_P01_PIN_5  = (BSP_IO_PORT_P01 | 0x05),   ///< IO port P01 pin 5
    BSP_IO_PORT_P01_PIN_8  = (BSP_IO_PORT_P01 | 0x08),   ///< IO port P01 pin 8
    BSP_IO_PORT_P01_PIN_9  = (BSP_IO_PORT_P01 | 0x09),   ///< IO port P01 pin 9
    BSP_IO_PORT_P01_PIN_10 = (BSP_IO_PORT_P01 | 0x0A),   ///< IO port P01 pin 10
    BSP_IO_PORT_P01_PIN_11 = (BSP_IO_PORT_P01 | 0x0B),   ///< IO port P01 pin 11
    BSP_IO_PORT_P01_PIN_12 = (BSP_IO_PORT_P01 | 0x0C),   ///< IO port P01 pin 12
    BSP_IO_PORT_P01_PIN_13 = (BSP_IO_PORT_P01 | 0x0D),   ///< IO port P01 pin 13
    BSP_IO_PORT_P01_PIN_14 = (BSP_IO_PORT_P01 | 0x0E),   ///< IO port P01 pin 14
    BSP_IO_PORT_P01_PIN_15 = (BSP_IO_PORT_P01 | 0x0F),   ///< IO port P01 pin 15

    BSP_IO_PORT_P02_PIN_0 = (BSP_IO_PORT_P02 | 0x00),    ///< IO port P02 pin 0
    BSP_IO_PORT_P02_PIN_1 = (BSP_IO_PORT_P02 | 0x01),    ///< IO port P02 pin 1
    BSP_IO_PORT_P02_PIN_2 = (BSP_IO_PORT_P02 | 0x02),    ///< IO port P02 pin 2
    BSP_IO_PORT_P02_PIN_3 = (BSP_IO_PORT_P02 | 0x03),    ///< IO port P02 pin 3
    BSP_IO_PORT_P02_PIN_4 = (BSP_IO_PORT_P02 | 0x04),    ///< IO port P02 pin 4
    BSP_IO_PORT_P02_PIN_5 = (BSP_IO_PORT_P02 | 0x05),    ///< IO port P02 pin 5
    BSP_IO_PORT_P02_PIN_6 = (BSP_IO_PORT_P02 | 0x06),    ///< IO port P02 pin 6

    BSP_IO_PORT_P08_PIN_0  = (BSP_IO_PORT_P08 | 0x00),   ///< IO port P08 pin 0
    BSP_IO_PORT_P08_PIN_1  = (BSP_IO_PORT_P08 | 0x01),   ///< IO port P08 pin 1
    BSP_IO_PORT_P08_PIN_2  = (BSP_IO_PORT_P08 | 0x02),   ///< IO port P08 pin 2
    BSP_IO_PORT_P08_PIN_3  = (BSP_IO_PORT_P08 | 0x03),   ///< IO port P08 pin 3
    BSP_IO_PORT_P08_PIN_4  = (BSP_IO_PORT_P08 | 0x04),   ///< IO port P08 pin 4
    BSP_IO_PORT_P08_PIN_5  = (BSP_IO_PORT_P08 | 0x05),   ///< IO port P08 pin 5
    BSP_IO_PORT_P08_PIN_7  = (BSP_IO_PORT_P08 | 0x07),   ///< IO port P08 pin 7
    BSP_IO_PORT_P08_PIN_8  = (BSP_IO_PORT_P08 | 0x08),   ///< IO port P08 pin 8
    BSP_IO_PORT_P08_PIN_9  = (BSP_IO_PORT_P08 | 0x09),   ///< IO port P08 pin 9
    BSP_IO_PORT_P08_PIN_10 = (BSP_IO_PORT_P08 | 0x0A),   ///< IO port P08 pin 10
    BSP_IO_PORT_P08_PIN_11 = (BSP_IO_PORT_P08 | 0x0B),   ///< IO port P08 pin 11
    BSP_IO_PORT_P08_PIN_12 = (BSP_IO_PORT_P08 | 0x0C),   ///< IO port P08 pin 12

    BSP_IO_PORT_P09_PIN_0  = (BSP_IO_PORT_P09 | 0x00),   ///< IO port P09 pin 0
    BSP_IO_PORT_P09_PIN_1  = (BSP_IO_PORT_P09 | 0x01),   ///< IO port P09 pin 1
    BSP_IO_PORT_P09_PIN_2  = (BSP_IO_PORT_P09 | 0x02),   ///< IO port P09 pin 2
    BSP_IO_PORT_P09_PIN_3  = (BSP_IO_PORT_P09 | 0x03),   ///< IO port P09 pin 3
    BSP_IO_PORT_P09_PIN_4  = (BSP_IO_PORT_P09 | 0x04),   ///< IO port P09 pin 4
    BSP_IO_PORT_P10_PIN_0  = (BSP_IO_PORT_P10 | 0x00),   ///< IO port P10 pin 0
    BSP_IO_PORT_P10_PIN_1  = (BSP_IO_PORT_P10 | 0x01),   ///< IO port P10 pin 1
    BSP_IO_PORT_P10_PIN_2  = (BSP_IO_PORT_P10 | 0x02),   ///< IO port P10 pin 2
    BSP_IO_PORT_P10_PIN_3  = (BSP_IO_PORT_P10 | 0x03),   ///< IO port P10 pin 3
    BSP_IO_PORT_P10_PIN_4  = (BSP_IO_PORT_P10 | 0x04),   ///< IO port P10 pin 4
    BSP_IO_PORT_P10_PIN_5  = (BSP_IO_PORT_P10 | 0x05),   ///< IO port P10 pin 5
    BSP_IO_PORT_P10_PIN_6  = (BSP_IO_PORT_P10 | 0x06),   ///< IO port P10 pin 6
    BSP_IO_PORT_P10_PIN_7  = (BSP_IO_PORT_P10 | 0x07),   ///< IO port P10 pin 7
    BSP_IO_PORT_P10_PIN_8  = (BSP_IO_PORT_P10 | 0x08),   ///< IO port P10 pin 8
    BSP_IO_PORT_P10_PIN_9  = (BSP_IO_PORT_P10 | 0x09),   ///< IO port P10 pin 9
    BSP_IO_PORT_P10_PIN_10 = (BSP_IO_PORT_P10 | 0x0A),   ///< IO port P10 pin 10
    BSP_IO_PORT_P10_PIN_11 = (BSP_IO_PORT_P10 | 0x0B),   ///< IO port P10 pin 11
    BSP_IO_PORT_P10_PIN_12 = (BSP_IO_PORT_P10 | 0x0C),   ///< IO port P10 pin 12
    BSP_IO_PORT_P10_PIN_13 = (BSP_IO_PORT_P10 | 0x0D),   ///< IO port P10 pin 13
    BSP_IO_PORT_P10_PIN_14 = (BSP_IO_PORT_P10 | 0x0E),   ///< IO port P10 pin 14
    BSP_IO_PORT_P10_PIN_15 = (BSP_IO_PORT_P10 | 0x0F),   ///< IO port P10 pin 15

    BSP_IO_PORT_P11_PIN_0  = (BSP_IO_PORT_P11 | 0x00),   ///< IO port P11 pin 0
    BSP_IO_PORT_P11_PIN_1  = (BSP_IO_PORT_P11 | 0x01),   ///< IO port P11 pin 1
    BSP_IO_PORT_P11_PIN_2  = (BSP_IO_PORT_P11 | 0x02),   ///< IO port P11 pin 2
    BSP_IO_PORT_P11_PIN_3  = (BSP_IO_PORT_P11 | 0x03),   ///< IO port P11 pin 3
    BSP_IO_PORT_P11_PIN_4  = (BSP_IO_PORT_P11 | 0x04),   ///< IO port P11 pin 4
    BSP_IO_PORT_P11_PIN_5  = (BSP_IO_PORT_P11 | 0x05),   ///< IO port P11 pin 5
    BSP_IO_PORT_P11_PIN_6  = (BSP_IO_PORT_P11 | 0x06),   ///< IO port P11 pin 6
    BSP_IO_PORT_P11_PIN_7  = (BSP_IO_PORT_P11 | 0x07),   ///< IO port P11 pin 7
    BSP_IO_PORT_P11_PIN_8  = (BSP_IO_PORT_P11 | 0x08),   ///< IO port P11 pin 8
    BSP_IO_PORT_P11_PIN_9  = (BSP_IO_PORT_P11 | 0x09),   ///< IO port P11 pin 9
    BSP_IO_PORT_P11_PIN_10 = (BSP_IO_PORT_P11 | 0x0A),   ///< IO port P11 pin 10
    BSP_IO_PORT_P11_PIN_11 = (BSP_IO_PORT_P11 | 0x0B),   ///< IO port P11 pin 11
    BSP_IO_PORT_P11_PIN_12 = (BSP_IO_PORT_P11 | 0x0C),   ///< IO port P11 pin 12
    BSP_IO_PORT_P11_PIN_15 = (BSP_IO_PORT_P11 | 0x0F),   ///< IO port P11 pin 15

    BSP_IO_PORT_P12_PIN_0 = (BSP_IO_PORT_P12 | 0x00),    ///< IO port P12 pin 0
    BSP_IO_PORT_P12_PIN_1 = (BSP_IO_PORT_P12 | 0x01),    ///< IO port P12 pin 1
    BSP_IO_PORT_P12_PIN_2 = (BSP_IO_PORT_P12 | 0x02),    ///< IO port P12 pin 2
    BSP_IO_PORT_P12_PIN_3 = (BSP_IO_PORT_P12 | 0x03),    ///< IO port P12 pin 3
    BSP_IO_PORT_P12_PIN_4 = (BSP_IO_PORT_P12 | 0x04),    ///< IO port P12 pin 4
    BSP_IO_PORT_P12_PIN_5 = (BSP_IO_PORT_P12 | 0x05),    ///< IO port P12 pin 5

    BSP_IO_PORT_P18_PIN_0 = (BSP_IO_PORT_P18 | 0x00),    ///< IO port P18 pin 0
    BSP_IO_PORT_P18_PIN_1 = (BSP_IO_PORT_P18 | 0x01),    ///< IO port P18 pin 1
    BSP_IO_PORT_P18_PIN_2 = (BSP_IO_PORT_P18 | 0x02),    ///< IO port P18 pin 2
    BSP_IO_PORT_P18_PIN_3 = (BSP_IO_PORT_P18 | 0x03),    ///< IO port P18 pin 3
    BSP_IO_PORT_P18_PIN_4 = (BSP_IO_PORT_P18 | 0x04),    ///< IO port P18 pin 4
    BSP_IO_PORT_P18_PIN_5 = (BSP_IO_PORT_P18 | 0x05),    ///< IO port P18 pin 5
    BSP_IO_PORT_P18_PIN_6 = (BSP_IO_PORT_P18 | 0x06),    ///< IO port P18 pin 6
    BSP_IO_PORT_P18_PIN_7 = (BSP_IO_PORT_P18 | 0x07),    ///< IO port P18 pin 7

    BSP_IO_PORT_P20_PIN_0 = (BSP_IO_PORT_P20 | 0x00),    ///< IO port P20 pin 0
    BSP_IO_PORT_P20_PIN_1 = (BSP_IO_PORT_P20 | 0x01),    ///< IO port P20 pin 1
    BSP_IO_PORT_P20_PIN_2 = (BSP_IO_PORT_P20 | 0x02),    ///< IO port P20 pin 2
    BSP_IO_PORT_P20_PIN_3 = (BSP_IO_PORT_P20 | 0x03),    ///< IO port P20 pin 3
    BSP_IO_PORT_P20_PIN_4 = (BSP_IO_PORT_P20 | 0x04),    ///< IO port P20 pin 4
    BSP_IO_PORT_P20_PIN_5 = (BSP_IO_PORT_P20 | 0x05),    ///< IO port P20 pin 5

    BSP_IO_PORT_P27_PIN_0 = (BSP_IO_PORT_P27 | 0x00),    ///< IO port P27 pin 0

    BSP_IO_PORT_AP00_PIN_0  = (BSP_IO_PORT_AP00 | 0x00), ///< IO port AP00 pin 0
    BSP_IO_PORT_AP00_PIN_1  = (BSP_IO_PORT_AP00 | 0x01), ///< IO port AP00 pin 1
    BSP_IO_PORT_AP00_PIN_2  = (BSP_IO_PORT_AP00 | 0x02), ///< IO port AP00 pin 2
    BSP_IO_PORT_AP00_PIN_3  = (BSP_IO_PORT_AP00 | 0x03), ///< IO port AP00 pin 3
    BSP_IO_PORT_AP00_PIN_4  = (BSP_IO_PORT_AP00 | 0x04), ///< IO port AP00 pin 4
    BSP_IO_PORT_AP00_PIN_5  = (BSP_IO_PORT_AP00 | 0x05), ///< IO port AP00 pin 5
    BSP_IO_PORT_AP00_PIN_6  = (BSP_IO_PORT_AP00 | 0x06), ///< IO port AP00 pin 6
    BSP_IO_PORT_AP00_PIN_7  = (BSP_IO_PORT_AP00 | 0x07), ///< IO port AP00 pin 7
    BSP_IO_PORT_AP00_PIN_8  = (BSP_IO_PORT_AP00 | 0x08), ///< IO port AP00 pin 8
    BSP_IO_PORT_AP00_PIN_9  = (BSP_IO_PORT_AP00 | 0x09), ///< IO port AP00 pin 9
    BSP_IO_PORT_AP00_PIN_10 = (BSP_IO_PORT_AP00 | 0x0A), ///< IO port AP00 pin 10
    BSP_IO_PORT_AP00_PIN_11 = (BSP_IO_PORT_AP00 | 0x0B), ///< IO port AP00 pin 11
    BSP_IO_PORT_AP00_PIN_12 = (BSP_IO_PORT_AP00 | 0x0C), ///< IO port AP00 pin 12
    BSP_IO_PORT_AP00_PIN_13 = (BSP_IO_PORT_AP00 | 0x0D), ///< IO port AP00 pin 13
    BSP_IO_PORT_AP00_PIN_14 = (BSP_IO_PORT_AP00 | 0x0E), ///< IO port AP00 pin 14
    BSP_IO_PORT_AP00_PIN_15 = (BSP_IO_PORT_AP00 | 0x0F), ///< IO port AP00 pin 15

    BSP_IO_PORT_AP02_PIN_0  = (BSP_IO_PORT_AP02 | 0x00), ///< IO port AP02 pin 0
    BSP_IO_PORT_AP02_PIN_1  = (BSP_IO_PORT_AP02 | 0x01), ///< IO port AP02 pin 1
    BSP_IO_PORT_AP02_PIN_2  = (BSP_IO_PORT_AP02 | 0x02), ///< IO port AP02 pin 2
    BSP_IO_PORT_AP02_PIN_3  = (BSP_IO_PORT_AP02 | 0x03), ///< IO port AP02 pin 3
    BSP_IO_PORT_AP02_PIN_4  = (BSP_IO_PORT_AP02 | 0x04), ///< IO port AP02 pin 4
    BSP_IO_PORT_AP02_PIN_5  = (BSP_IO_PORT_AP02 | 0x05), ///< IO port AP02 pin 5
    BSP_IO_PORT_AP02_PIN_6  = (BSP_IO_PORT_AP02 | 0x06), ///< IO port AP02 pin 6
    BSP_IO_PORT_AP02_PIN_7  = (BSP_IO_PORT_AP02 | 0x07), ///< IO port AP02 pin 7
    BSP_IO_PORT_AP02_PIN_8  = (BSP_IO_PORT_AP02 | 0x08), ///< IO port AP02 pin 8
    BSP_IO_PORT_AP02_PIN_9  = (BSP_IO_PORT_AP02 | 0x09), ///< IO port AP02 pin 9
    BSP_IO_PORT_AP02_PIN_10 = (BSP_IO_PORT_AP02 | 0x0A), ///< IO port AP02 pin 10
    BSP_IO_PORT_AP02_PIN_11 = (BSP_IO_PORT_AP02 | 0x0B), ///< IO port AP02 pin 11
    BSP_IO_PORT_AP02_PIN_12 = (BSP_IO_PORT_AP02 | 0x0C), ///< IO port AP02 pin 12
    BSP_IO_PORT_AP02_PIN_13 = (BSP_IO_PORT_AP02 | 0x0D), ///< IO port AP02 pin 13
    BSP_IO_PORT_AP02_PIN_14 = (BSP_IO_PORT_AP02 | 0x0E), ///< IO port AP02 pin 14
    BSP_IO_PORT_AP02_PIN_15 = (BSP_IO_PORT_AP02 | 0x0F), ///< IO port AP02 pin 15

    BSP_IO_PORT_JP00_PIN_0 = (BSP_IO_PORT_JP00 | 0x00),  ///< IO port JP00 pin 0
    BSP_IO_PORT_JP00_PIN_1 = (BSP_IO_PORT_JP00 | 0x01),  ///< IO port JP00 pin 1
    BSP_IO_PORT_JP00_PIN_2 = (BSP_IO_PORT_JP00 | 0x02),  ///< IO port JP00 pin 2
    BSP_IO_PORT_JP00_PIN_3 = (BSP_IO_PORT_JP00 | 0x03),  ///< IO port JP00 pin 3
    BSP_IO_PORT_JP00_PIN_5 = (BSP_IO_PORT_JP00 | 0x05),  ///< IO port JP00 pin 5
    BSP_IO_PORT_JP00_PIN_6 = (BSP_IO_PORT_JP00 | 0x06),  ///< IO port JP00 pin 6

    BSP_IO_PORT_IP00_PIN_0 = (BSP_IO_PORT_IP00 | 0x00),  ///< IO port IP00 pin 0
    BSP_IO_PORT_IP00_PIN_1 = (BSP_IO_PORT_IP00 | 0x01),  ///< IO port IP00 pin 1
#elif (BSP_PACKAGE_PINS_BGA144 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00_PIN_0  = (BSP_IO_PORT_P00 | 0x00),   ///< IO port P00 pin 0
    BSP_IO_PORT_P00_PIN_1  = (BSP_IO_PORT_P00 | 0x01),   ///< IO port P00 pin 1
    BSP_IO_PORT_P00_PIN_2  = (BSP_IO_PORT_P00 | 0x02),   ///< IO port P00 pin 2
    BSP_IO_PORT_P00_PIN_3  = (BSP_IO_PORT_P00 | 0x03),   ///< IO port P00 pin 3
    BSP_IO_PORT_P00_PIN_4  = (BSP_IO_PORT_P00 | 0x04),   ///< IO port P00 pin 4
    BSP_IO_PORT_P00_PIN_5  = (BSP_IO_PORT_P00 | 0x05),   ///< IO port P00 pin 5
    BSP_IO_PORT_P00_PIN_6  = (BSP_IO_PORT_P00 | 0x06),   ///< IO port P00 pin 6
    BSP_IO_PORT_P00_PIN_7  = (BSP_IO_PORT_P00 | 0x07),   ///< IO port P00 pin 7
    BSP_IO_PORT_P00_PIN_8  = (BSP_IO_PORT_P00 | 0x08),   ///< IO port P00 pin 8
    BSP_IO_PORT_P00_PIN_9  = (BSP_IO_PORT_P00 | 0x09),   ///< IO port P00 pin 9
    BSP_IO_PORT_P00_PIN_10 = (BSP_IO_PORT_P00 | 0x0A),   ///< IO port P00 pin 10
    BSP_IO_PORT_P00_PIN_11 = (BSP_IO_PORT_P00 | 0x0B),   ///< IO port P00 pin 11
    BSP_IO_PORT_P00_PIN_12 = (BSP_IO_PORT_P00 | 0x0C),   ///< IO port P00 pin 12
    BSP_IO_PORT_P00_PIN_13 = (BSP_IO_PORT_P00 | 0x0D),   ///< IO port P00 pin 13
    BSP_IO_PORT_P00_PIN_14 = (BSP_IO_PORT_P00 | 0x0E),   ///< IO port P00 pin 14

    BSP_IO_PORT_P01_PIN_0  = (BSP_IO_PORT_P01 | 0x00),   ///< IO port P01 pin 0
    BSP_IO_PORT_P01_PIN_1  = (BSP_IO_PORT_P01 | 0x01),   ///< IO port P01 pin 1
    BSP_IO_PORT_P01_PIN_2  = (BSP_IO_PORT_P01 | 0x02),   ///< IO port P01 pin 2
    BSP_IO_PORT_P01_PIN_3  = (BSP_IO_PORT_P01 | 0x03),   ///< IO port P01 pin 3
    BSP_IO_PORT_P01_PIN_4  = (BSP_IO_PORT_P01 | 0x04),   ///< IO port P01 pin 4
    BSP_IO_PORT_P01_PIN_5  = (BSP_IO_PORT_P01 | 0x05),   ///< IO port P01 pin 5
    BSP_IO_PORT_P01_PIN_8  = (BSP_IO_PORT_P01 | 0x08),   ///< IO port P01 pin 8
    BSP_IO_PORT_P01_PIN_9  = (BSP_IO_PORT_P01 | 0x09),   ///< IO port P01 pin 9
    BSP_IO_PORT_P01_PIN_10 = (BSP_IO_PORT_P01 | 0x0A),   ///< IO port P01 pin 10
    BSP_IO_PORT_P01_PIN_11 = (BSP_IO_PORT_P01 | 0x0B),   ///< IO port P01 pin 11

    BSP_IO_PORT_P08_PIN_0  = (BSP_IO_PORT_P08 | 0x00),   ///< IO port P08 pin 0
    BSP_IO_PORT_P08_PIN_1  = (BSP_IO_PORT_P08 | 0x01),   ///< IO port P08 pin 1
    BSP_IO_PORT_P08_PIN_2  = (BSP_IO_PORT_P08 | 0x02),   ///< IO port P08 pin 2
    BSP_IO_PORT_P08_PIN_3  = (BSP_IO_PORT_P08 | 0x03),   ///< IO port P08 pin 3
    BSP_IO_PORT_P08_PIN_4  = (BSP_IO_PORT_P08 | 0x04),   ///< IO port P08 pin 4
    BSP_IO_PORT_P08_PIN_5  = (BSP_IO_PORT_P08 | 0x05),   ///< IO port P08 pin 5
    BSP_IO_PORT_P08_PIN_7  = (BSP_IO_PORT_P08 | 0x07),   ///< IO port P08 pin 7
    BSP_IO_PORT_P08_PIN_8  = (BSP_IO_PORT_P08 | 0x08),   ///< IO port P08 pin 8
    BSP_IO_PORT_P08_PIN_9  = (BSP_IO_PORT_P08 | 0x09),   ///< IO port P08 pin 9
    BSP_IO_PORT_P08_PIN_10 = (BSP_IO_PORT_P08 | 0x0A),   ///< IO port P08 pin 10
    BSP_IO_PORT_P08_PIN_11 = (BSP_IO_PORT_P08 | 0x0B),   ///< IO port P08 pin 11
    BSP_IO_PORT_P08_PIN_12 = (BSP_IO_PORT_P08 | 0x0C),   ///< IO port P08 pin 12

    BSP_IO_PORT_P09_PIN_0  = (BSP_IO_PORT_P09 | 0x00),   ///< IO port P09 pin 0
    BSP_IO_PORT_P09_PIN_1  = (BSP_IO_PORT_P09 | 0x01),   ///< IO port P09 pin 1
    BSP_IO_PORT_P09_PIN_2  = (BSP_IO_PORT_P09 | 0x02),   ///< IO port P09 pin 2
    BSP_IO_PORT_P09_PIN_3  = (BSP_IO_PORT_P09 | 0x03),   ///< IO port P09 pin 3
    BSP_IO_PORT_P09_PIN_4  = (BSP_IO_PORT_P09 | 0x04),   ///< IO port P09 pin 4
    BSP_IO_PORT_P10_PIN_0  = (BSP_IO_PORT_P10 | 0x00),   ///< IO port P10 pin 0
    BSP_IO_PORT_P10_PIN_1  = (BSP_IO_PORT_P10 | 0x01),   ///< IO port P10 pin 1
    BSP_IO_PORT_P10_PIN_2  = (BSP_IO_PORT_P10 | 0x02),   ///< IO port P10 pin 2
    BSP_IO_PORT_P10_PIN_3  = (BSP_IO_PORT_P10 | 0x03),   ///< IO port P10 pin 3
    BSP_IO_PORT_P10_PIN_4  = (BSP_IO_PORT_P10 | 0x04),   ///< IO port P10 pin 4
    BSP_IO_PORT_P10_PIN_5  = (BSP_IO_PORT_P10 | 0x05),   ///< IO port P10 pin 5
    BSP_IO_PORT_P10_PIN_6  = (BSP_IO_PORT_P10 | 0x06),   ///< IO port P10 pin 6
    BSP_IO_PORT_P10_PIN_7  = (BSP_IO_PORT_P10 | 0x07),   ///< IO port P10 pin 7
    BSP_IO_PORT_P10_PIN_8  = (BSP_IO_PORT_P10 | 0x08),   ///< IO port P10 pin 8
    BSP_IO_PORT_P10_PIN_9  = (BSP_IO_PORT_P10 | 0x09),   ///< IO port P10 pin 9
    BSP_IO_PORT_P10_PIN_10 = (BSP_IO_PORT_P10 | 0x0A),   ///< IO port P10 pin 10
    BSP_IO_PORT_P10_PIN_11 = (BSP_IO_PORT_P10 | 0x0B),   ///< IO port P10 pin 11
    BSP_IO_PORT_P10_PIN_12 = (BSP_IO_PORT_P10 | 0x0C),   ///< IO port P10 pin 12
    BSP_IO_PORT_P10_PIN_13 = (BSP_IO_PORT_P10 | 0x0D),   ///< IO port P10 pin 13
    BSP_IO_PORT_P10_PIN_14 = (BSP_IO_PORT_P10 | 0x0E),   ///< IO port P10 pin 14
    BSP_IO_PORT_P10_PIN_15 = (BSP_IO_PORT_P10 | 0x0F),   ///< IO port P10 pin 15

    BSP_IO_PORT_P11_PIN_0  = (BSP_IO_PORT_P11 | 0x00),   ///< IO port P11 pin 0
    BSP_IO_PORT_P11_PIN_1  = (BSP_IO_PORT_P11 | 0x01),   ///< IO port P11 pin 1
    BSP_IO_PORT_P11_PIN_2  = (BSP_IO_PORT_P11 | 0x02),   ///< IO port P11 pin 2
    BSP_IO_PORT_P11_PIN_3  = (BSP_IO_PORT_P11 | 0x03),   ///< IO port P11 pin 3
    BSP_IO_PORT_P11_PIN_4  = (BSP_IO_PORT_P11 | 0x04),   ///< IO port P11 pin 4
    BSP_IO_PORT_P11_PIN_5  = (BSP_IO_PORT_P11 | 0x05),   ///< IO port P11 pin 5
    BSP_IO_PORT_P11_PIN_6  = (BSP_IO_PORT_P11 | 0x06),   ///< IO port P11 pin 6
    BSP_IO_PORT_P11_PIN_7  = (BSP_IO_PORT_P11 | 0x07),   ///< IO port P11 pin 7
    BSP_IO_PORT_P11_PIN_8  = (BSP_IO_PORT_P11 | 0x08),   ///< IO port P11 pin 8
    BSP_IO_PORT_P11_PIN_9  = (BSP_IO_PORT_P11 | 0x09),   ///< IO port P11 pin 9
    BSP_IO_PORT_P11_PIN_10 = (BSP_IO_PORT_P11 | 0x0A),   ///< IO port P11 pin 10
    BSP_IO_PORT_P11_PIN_11 = (BSP_IO_PORT_P11 | 0x0B),   ///< IO port P11 pin 11
    BSP_IO_PORT_P11_PIN_12 = (BSP_IO_PORT_P11 | 0x0C),   ///< IO port P11 pin 12
    BSP_IO_PORT_P11_PIN_15 = (BSP_IO_PORT_P11 | 0x0F),   ///< IO port P11 pin 15

    BSP_IO_PORT_P12_PIN_0 = (BSP_IO_PORT_P12 | 0x00),    ///< IO port P12 pin 0
    BSP_IO_PORT_P12_PIN_1 = (BSP_IO_PORT_P12 | 0x01),    ///< IO port P12 pin 1
    BSP_IO_PORT_P12_PIN_2 = (BSP_IO_PORT_P12 | 0x02),    ///< IO port P12 pin 2

    BSP_IO_PORT_P18_PIN_0 = (BSP_IO_PORT_P18 | 0x00),    ///< IO port P18 pin 0
    BSP_IO_PORT_P18_PIN_1 = (BSP_IO_PORT_P18 | 0x01),    ///< IO port P18 pin 1
    BSP_IO_PORT_P18_PIN_2 = (BSP_IO_PORT_P18 | 0x02),    ///< IO port P18 pin 2
    BSP_IO_PORT_P18_PIN_3 = (BSP_IO_PORT_P18 | 0x03),    ///< IO port P18 pin 3

    BSP_IO_PORT_P20_PIN_4 = (BSP_IO_PORT_P20 | 0x04),    ///< IO port P20 pin 4
    BSP_IO_PORT_P20_PIN_5 = (BSP_IO_PORT_P20 | 0x05),    ///< IO port P20 pin 5

    BSP_IO_PORT_P27_PIN_0 = (BSP_IO_PORT_P27 | 0x00),    ///< IO port P27 pin 0

    BSP_IO_PORT_AP00_PIN_0  = (BSP_IO_PORT_AP00 | 0x00), ///< IO port AP00 pin 0
    BSP_IO_PORT_AP00_PIN_1  = (BSP_IO_PORT_AP00 | 0x01), ///< IO port AP00 pin 1
    BSP_IO_PORT_AP00_PIN_2  = (BSP_IO_PORT_AP00 | 0x02), ///< IO port AP00 pin 2
    BSP_IO_PORT_AP00_PIN_3  = (BSP_IO_PORT_AP00 | 0x03), ///< IO port AP00 pin 3
    BSP_IO_PORT_AP00_PIN_4  = (BSP_IO_PORT_AP00 | 0x04), ///< IO port AP00 pin 4
    BSP_IO_PORT_AP00_PIN_5  = (BSP_IO_PORT_AP00 | 0x05), ///< IO port AP00 pin 5
    BSP_IO_PORT_AP00_PIN_6  = (BSP_IO_PORT_AP00 | 0x06), ///< IO port AP00 pin 6
    BSP_IO_PORT_AP00_PIN_7  = (BSP_IO_PORT_AP00 | 0x07), ///< IO port AP00 pin 7
    BSP_IO_PORT_AP00_PIN_8  = (BSP_IO_PORT_AP00 | 0x08), ///< IO port AP00 pin 8
    BSP_IO_PORT_AP00_PIN_9  = (BSP_IO_PORT_AP00 | 0x09), ///< IO port AP00 pin 9
    BSP_IO_PORT_AP00_PIN_10 = (BSP_IO_PORT_AP00 | 0x0A), ///< IO port AP00 pin 10
    BSP_IO_PORT_AP00_PIN_11 = (BSP_IO_PORT_AP00 | 0x0B), ///< IO port AP00 pin 11
    BSP_IO_PORT_AP00_PIN_12 = (BSP_IO_PORT_AP00 | 0x0C), ///< IO port AP00 pin 12
    BSP_IO_PORT_AP00_PIN_13 = (BSP_IO_PORT_AP00 | 0x0D), ///< IO port AP00 pin 13
    BSP_IO_PORT_AP00_PIN_14 = (BSP_IO_PORT_AP00 | 0x0E), ///< IO port AP00 pin 14
    BSP_IO_PORT_AP00_PIN_15 = (BSP_IO_PORT_AP00 | 0x0F), ///< IO port AP00 pin 15

    BSP_IO_PORT_AP02_PIN_0 = (BSP_IO_PORT_AP02 | 0x00),  ///< IO port AP02 pin 0
    BSP_IO_PORT_AP02_PIN_1 = (BSP_IO_PORT_AP02 | 0x01),  ///< IO port AP02 pin 1
    BSP_IO_PORT_AP02_PIN_2 = (BSP_IO_PORT_AP02 | 0x02),  ///< IO port AP02 pin 2
    BSP_IO_PORT_AP02_PIN_3 = (BSP_IO_PORT_AP02 | 0x03),  ///< IO port AP02 pin 3
    BSP_IO_PORT_AP02_PIN_4 = (BSP_IO_PORT_AP02 | 0x04),  ///< IO port AP02 pin 4
    BSP_IO_PORT_AP02_PIN_5 = (BSP_IO_PORT_AP02 | 0x05),  ///< IO port AP02 pin 5
    BSP_IO_PORT_AP02_PIN_6 = (BSP_IO_PORT_AP02 | 0x06),  ///< IO port AP02 pin 6
    BSP_IO_PORT_AP02_PIN_7 = (BSP_IO_PORT_AP02 | 0x07),  ///< IO port AP02 pin 7

    BSP_IO_PORT_JP00_PIN_0 = (BSP_IO_PORT_JP00 | 0x00),  ///< IO port JP00 pin 0
    BSP_IO_PORT_JP00_PIN_1 = (BSP_IO_PORT_JP00 | 0x01),  ///< IO port JP00 pin 1
    BSP_IO_PORT_JP00_PIN_2 = (BSP_IO_PORT_JP00 | 0x02),  ///< IO port JP00 pin 2
    BSP_IO_PORT_JP00_PIN_3 = (BSP_IO_PORT_JP00 | 0x03),  ///< IO port JP00 pin 3
    BSP_IO_PORT_JP00_PIN_5 = (BSP_IO_PORT_JP00 | 0x05),  ///< IO port JP00 pin 5
    BSP_IO_PORT_JP00_PIN_6 = (BSP_IO_PORT_JP00 | 0x06),  ///< IO port JP00 pin 6

    BSP_IO_PORT_IP00_PIN_0 = (BSP_IO_PORT_IP00 | 0x00),  ///< IO port IP00 pin 0
    BSP_IO_PORT_IP00_PIN_1 = (BSP_IO_PORT_IP00 | 0x01),  ///< IO port IP00 pin 1
#elif (BSP_PACKAGE_PINS_BGA100 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00_PIN_0  = (BSP_IO_PORT_P00 | 0x00),   ///< IO port P00 pin 0
    BSP_IO_PORT_P00_PIN_1  = (BSP_IO_PORT_P00 | 0x01),   ///< IO port P00 pin 1
    BSP_IO_PORT_P00_PIN_2  = (BSP_IO_PORT_P00 | 0x02),   ///< IO port P00 pin 2
    BSP_IO_PORT_P00_PIN_3  = (BSP_IO_PORT_P00 | 0x03),   ///< IO port P00 pin 3
    BSP_IO_PORT_P00_PIN_4  = (BSP_IO_PORT_P00 | 0x04),   ///< IO port P00 pin 4
    BSP_IO_PORT_P00_PIN_5  = (BSP_IO_PORT_P00 | 0x05),   ///< IO port P00 pin 5
    BSP_IO_PORT_P00_PIN_6  = (BSP_IO_PORT_P00 | 0x06),   ///< IO port P00 pin 6
    BSP_IO_PORT_P00_PIN_7  = (BSP_IO_PORT_P00 | 0x07),   ///< IO port P00 pin 7
    BSP_IO_PORT_P00_PIN_8  = (BSP_IO_PORT_P00 | 0x08),   ///< IO port P00 pin 8
    BSP_IO_PORT_P00_PIN_9  = (BSP_IO_PORT_P00 | 0x09),   ///< IO port P00 pin 9
    BSP_IO_PORT_P00_PIN_10 = (BSP_IO_PORT_P00 | 0x0A),   ///< IO port P00 pin 10
    BSP_IO_PORT_P00_PIN_11 = (BSP_IO_PORT_P00 | 0x0B),   ///< IO port P00 pin 11
    BSP_IO_PORT_P00_PIN_12 = (BSP_IO_PORT_P00 | 0x0C),   ///< IO port P00 pin 12
    BSP_IO_PORT_P00_PIN_13 = (BSP_IO_PORT_P00 | 0x0D),   ///< IO port P00 pin 13
    BSP_IO_PORT_P00_PIN_14 = (BSP_IO_PORT_P00 | 0x0E),   ///< IO port P00 pin 14

    BSP_IO_PORT_P08_PIN_0  = (BSP_IO_PORT_P08 | 0x00),   ///< IO port P08 pin 0
    BSP_IO_PORT_P08_PIN_1  = (BSP_IO_PORT_P08 | 0x01),   ///< IO port P08 pin 1
    BSP_IO_PORT_P08_PIN_2  = (BSP_IO_PORT_P08 | 0x02),   ///< IO port P08 pin 2
    BSP_IO_PORT_P08_PIN_3  = (BSP_IO_PORT_P08 | 0x03),   ///< IO port P08 pin 3
    BSP_IO_PORT_P08_PIN_4  = (BSP_IO_PORT_P08 | 0x04),   ///< IO port P08 pin 4
    BSP_IO_PORT_P08_PIN_5  = (BSP_IO_PORT_P08 | 0x05),   ///< IO port P08 pin 5
    BSP_IO_PORT_P08_PIN_7  = (BSP_IO_PORT_P08 | 0x07),   ///< IO port P08 pin 7
    BSP_IO_PORT_P08_PIN_8  = (BSP_IO_PORT_P08 | 0x08),   ///< IO port P08 pin 8
    BSP_IO_PORT_P08_PIN_9  = (BSP_IO_PORT_P08 | 0x09),   ///< IO port P08 pin 9
    BSP_IO_PORT_P08_PIN_10 = (BSP_IO_PORT_P08 | 0x0A),   ///< IO port P08 pin 10
    BSP_IO_PORT_P08_PIN_11 = (BSP_IO_PORT_P08 | 0x0B),   ///< IO port P08 pin 11
    BSP_IO_PORT_P08_PIN_12 = (BSP_IO_PORT_P08 | 0x0C),   ///< IO port P08 pin 12

    BSP_IO_PORT_P09_PIN_0  = (BSP_IO_PORT_P09 | 0x00),   ///< IO port P09 pin 0
    BSP_IO_PORT_P09_PIN_1  = (BSP_IO_PORT_P09 | 0x01),   ///< IO port P09 pin 1
    BSP_IO_PORT_P09_PIN_2  = (BSP_IO_PORT_P09 | 0x02),   ///< IO port P09 pin 2
    BSP_IO_PORT_P09_PIN_3  = (BSP_IO_PORT_P09 | 0x03),   ///< IO port P09 pin 3
    BSP_IO_PORT_P09_PIN_4  = (BSP_IO_PORT_P09 | 0x04),   ///< IO port P09 pin 4
    BSP_IO_PORT_P10_PIN_0  = (BSP_IO_PORT_P10 | 0x00),   ///< IO port P10 pin 0
    BSP_IO_PORT_P10_PIN_1  = (BSP_IO_PORT_P10 | 0x01),   ///< IO port P10 pin 1
    BSP_IO_PORT_P10_PIN_2  = (BSP_IO_PORT_P10 | 0x02),   ///< IO port P10 pin 2
    BSP_IO_PORT_P10_PIN_3  = (BSP_IO_PORT_P10 | 0x03),   ///< IO port P10 pin 3
    BSP_IO_PORT_P10_PIN_4  = (BSP_IO_PORT_P10 | 0x04),   ///< IO port P10 pin 4
    BSP_IO_PORT_P10_PIN_5  = (BSP_IO_PORT_P10 | 0x05),   ///< IO port P10 pin 5
    BSP_IO_PORT_P10_PIN_6  = (BSP_IO_PORT_P10 | 0x06),   ///< IO port P10 pin 6
    BSP_IO_PORT_P10_PIN_7  = (BSP_IO_PORT_P10 | 0x07),   ///< IO port P10 pin 7
    BSP_IO_PORT_P10_PIN_8  = (BSP_IO_PORT_P10 | 0x08),   ///< IO port P10 pin 8
    BSP_IO_PORT_P10_PIN_9  = (BSP_IO_PORT_P10 | 0x09),   ///< IO port P10 pin 9
    BSP_IO_PORT_P10_PIN_10 = (BSP_IO_PORT_P10 | 0x0A),   ///< IO port P10 pin 10
    BSP_IO_PORT_P10_PIN_11 = (BSP_IO_PORT_P10 | 0x0B),   ///< IO port P10 pin 11
    BSP_IO_PORT_P10_PIN_12 = (BSP_IO_PORT_P10 | 0x0C),   ///< IO port P10 pin 12
    BSP_IO_PORT_P10_PIN_13 = (BSP_IO_PORT_P10 | 0x0D),   ///< IO port P10 pin 13
    BSP_IO_PORT_P10_PIN_14 = (BSP_IO_PORT_P10 | 0x0E),   ///< IO port P10 pin 14
    BSP_IO_PORT_P10_PIN_15 = (BSP_IO_PORT_P10 | 0x0F),   ///< IO port P10 pin 15

    BSP_IO_PORT_P11_PIN_0 = (BSP_IO_PORT_P11 | 0x00),    ///< IO port P11 pin 0
    BSP_IO_PORT_P11_PIN_1 = (BSP_IO_PORT_P11 | 0x01),    ///< IO port P11 pin 1
    BSP_IO_PORT_P11_PIN_2 = (BSP_IO_PORT_P11 | 0x02),    ///< IO port P11 pin 2
    BSP_IO_PORT_P11_PIN_3 = (BSP_IO_PORT_P11 | 0x03),    ///< IO port P11 pin 3
    BSP_IO_PORT_P11_PIN_4 = (BSP_IO_PORT_P11 | 0x04),    ///< IO port P11 pin 4
    BSP_IO_PORT_P11_PIN_5 = (BSP_IO_PORT_P11 | 0x05),    ///< IO port P11 pin 5
    BSP_IO_PORT_P11_PIN_6 = (BSP_IO_PORT_P11 | 0x06),    ///< IO port P11 pin 6
    BSP_IO_PORT_P11_PIN_7 = (BSP_IO_PORT_P11 | 0x07),    ///< IO port P11 pin 7

    BSP_IO_PORT_P27_PIN_0 = (BSP_IO_PORT_P27 | 0x00),    ///< IO port P27 pin 0

    BSP_IO_PORT_AP00_PIN_0  = (BSP_IO_PORT_AP00 | 0x00), ///< IO port AP00 pin 0
    BSP_IO_PORT_AP00_PIN_1  = (BSP_IO_PORT_AP00 | 0x01), ///< IO port AP00 pin 1
    BSP_IO_PORT_AP00_PIN_2  = (BSP_IO_PORT_AP00 | 0x02), ///< IO port AP00 pin 2
    BSP_IO_PORT_AP00_PIN_3  = (BSP_IO_PORT_AP00 | 0x03), ///< IO port AP00 pin 3
    BSP_IO_PORT_AP00_PIN_4  = (BSP_IO_PORT_AP00 | 0x04), ///< IO port AP00 pin 4
    BSP_IO_PORT_AP00_PIN_5  = (BSP_IO_PORT_AP00 | 0x05), ///< IO port AP00 pin 5
    BSP_IO_PORT_AP00_PIN_6  = (BSP_IO_PORT_AP00 | 0x06), ///< IO port AP00 pin 6
    BSP_IO_PORT_AP00_PIN_7  = (BSP_IO_PORT_AP00 | 0x07), ///< IO port AP00 pin 7
    BSP_IO_PORT_AP00_PIN_8  = (BSP_IO_PORT_AP00 | 0x08), ///< IO port AP00 pin 8
    BSP_IO_PORT_AP00_PIN_9  = (BSP_IO_PORT_AP00 | 0x09), ///< IO port AP00 pin 9
    BSP_IO_PORT_AP00_PIN_10 = (BSP_IO_PORT_AP00 | 0x0A), ///< IO port AP00 pin 10
    BSP_IO_PORT_AP00_PIN_11 = (BSP_IO_PORT_AP00 | 0x0B), ///< IO port AP00 pin 11
    BSP_IO_PORT_AP00_PIN_12 = (BSP_IO_PORT_AP00 | 0x0C), ///< IO port AP00 pin 12
    BSP_IO_PORT_AP00_PIN_13 = (BSP_IO_PORT_AP00 | 0x0D), ///< IO port AP00 pin 13
    BSP_IO_PORT_AP00_PIN_14 = (BSP_IO_PORT_AP00 | 0x0E), ///< IO port AP00 pin 14
    BSP_IO_PORT_AP00_PIN_15 = (BSP_IO_PORT_AP00 | 0x0F), ///< IO port AP00 pin 15

    BSP_IO_PORT_JP00_PIN_0 = (BSP_IO_PORT_JP00 | 0x00),  ///< IO port JP00 pin 0
    BSP_IO_PORT_JP00_PIN_1 = (BSP_IO_PORT_JP00 | 0x01),  ///< IO port JP00 pin 1
    BSP_IO_PORT_JP00_PIN_2 = (BSP_IO_PORT_JP00 | 0x02),  ///< IO port JP00 pin 2
    BSP_IO_PORT_JP00_PIN_3 = (BSP_IO_PORT_JP00 | 0x03),  ///< IO port JP00 pin 3
    BSP_IO_PORT_JP00_PIN_5 = (BSP_IO_PORT_JP00 | 0x05),  ///< IO port JP00 pin 5
    BSP_IO_PORT_JP00_PIN_6 = (BSP_IO_PORT_JP00 | 0x06),  ///< IO port JP00 pin 6
#elif (BSP_PACKAGE_PINS_BGA80 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00_PIN_0  = (BSP_IO_PORT_P00 | 0x00),   ///< IO port P00 pin 0
    BSP_IO_PORT_P00_PIN_1  = (BSP_IO_PORT_P00 | 0x01),   ///< IO port P00 pin 1
    BSP_IO_PORT_P00_PIN_2  = (BSP_IO_PORT_P00 | 0x02),   ///< IO port P00 pin 2
    BSP_IO_PORT_P00_PIN_3  = (BSP_IO_PORT_P00 | 0x03),   ///< IO port P00 pin 3
    BSP_IO_PORT_P00_PIN_4  = (BSP_IO_PORT_P00 | 0x04),   ///< IO port P00 pin 4
    BSP_IO_PORT_P00_PIN_5  = (BSP_IO_PORT_P00 | 0x05),   ///< IO port P00 pin 5
    BSP_IO_PORT_P00_PIN_6  = (BSP_IO_PORT_P00 | 0x06),   ///< IO port P00 pin 6
    BSP_IO_PORT_P00_PIN_7  = (BSP_IO_PORT_P00 | 0x07),   ///< IO port P00 pin 7
    BSP_IO_PORT_P00_PIN_8  = (BSP_IO_PORT_P00 | 0x08),   ///< IO port P00 pin 8
    BSP_IO_PORT_P00_PIN_9  = (BSP_IO_PORT_P00 | 0x09),   ///< IO port P00 pin 9
    BSP_IO_PORT_P00_PIN_10 = (BSP_IO_PORT_P00 | 0x0A),   ///< IO port P00 pin 10
    BSP_IO_PORT_P00_PIN_11 = (BSP_IO_PORT_P00 | 0x0B),   ///< IO port P00 pin 11
    BSP_IO_PORT_P00_PIN_12 = (BSP_IO_PORT_P00 | 0x0C),   ///< IO port P00 pin 12

    BSP_IO_PORT_P08_PIN_0 = (BSP_IO_PORT_P08 | 0x00),    ///< IO port P08 pin 0
    BSP_IO_PORT_P08_PIN_1 = (BSP_IO_PORT_P08 | 0x01),    ///< IO port P08 pin 1
    BSP_IO_PORT_P08_PIN_2 = (BSP_IO_PORT_P08 | 0x02),    ///< IO port P08 pin 2
    BSP_IO_PORT_P08_PIN_3 = (BSP_IO_PORT_P08 | 0x03),    ///< IO port P08 pin 3
    BSP_IO_PORT_P08_PIN_4 = (BSP_IO_PORT_P08 | 0x04),    ///< IO port P08 pin 4
    BSP_IO_PORT_P08_PIN_5 = (BSP_IO_PORT_P08 | 0x05),    ///< IO port P08 pin 5

    BSP_IO_PORT_P09_PIN_0  = (BSP_IO_PORT_P09 | 0x00),   ///< IO port P09 pin 0
    BSP_IO_PORT_P09_PIN_1  = (BSP_IO_PORT_P09 | 0x01),   ///< IO port P09 pin 1
    BSP_IO_PORT_P09_PIN_2  = (BSP_IO_PORT_P09 | 0x02),   ///< IO port P09 pin 2
    BSP_IO_PORT_P09_PIN_3  = (BSP_IO_PORT_P09 | 0x03),   ///< IO port P09 pin 3
    BSP_IO_PORT_P09_PIN_4  = (BSP_IO_PORT_P09 | 0x04),   ///< IO port P09 pin 4
    BSP_IO_PORT_P10_PIN_0  = (BSP_IO_PORT_P10 | 0x00),   ///< IO port P10 pin 0
    BSP_IO_PORT_P10_PIN_1  = (BSP_IO_PORT_P10 | 0x01),   ///< IO port P10 pin 1
    BSP_IO_PORT_P10_PIN_2  = (BSP_IO_PORT_P10 | 0x02),   ///< IO port P10 pin 2
    BSP_IO_PORT_P10_PIN_3  = (BSP_IO_PORT_P10 | 0x03),   ///< IO port P10 pin 3
    BSP_IO_PORT_P10_PIN_4  = (BSP_IO_PORT_P10 | 0x04),   ///< IO port P10 pin 4
    BSP_IO_PORT_P10_PIN_5  = (BSP_IO_PORT_P10 | 0x05),   ///< IO port P10 pin 5
    BSP_IO_PORT_P10_PIN_6  = (BSP_IO_PORT_P10 | 0x06),   ///< IO port P10 pin 6
    BSP_IO_PORT_P10_PIN_7  = (BSP_IO_PORT_P10 | 0x07),   ///< IO port P10 pin 7
    BSP_IO_PORT_P10_PIN_8  = (BSP_IO_PORT_P10 | 0x08),   ///< IO port P10 pin 8
    BSP_IO_PORT_P10_PIN_9  = (BSP_IO_PORT_P10 | 0x09),   ///< IO port P10 pin 9
    BSP_IO_PORT_P10_PIN_10 = (BSP_IO_PORT_P10 | 0x0A),   ///< IO port P10 pin 10
    BSP_IO_PORT_P10_PIN_11 = (BSP_IO_PORT_P10 | 0x0B),   ///< IO port P10 pin 11
    BSP_IO_PORT_P10_PIN_12 = (BSP_IO_PORT_P10 | 0x0C),   ///< IO port P10 pin 12
    BSP_IO_PORT_P10_PIN_13 = (BSP_IO_PORT_P10 | 0x0D),   ///< IO port P10 pin 13
    BSP_IO_PORT_P10_PIN_14 = (BSP_IO_PORT_P10 | 0x0E),   ///< IO port P10 pin 14
    BSP_IO_PORT_P10_PIN_15 = (BSP_IO_PORT_P10 | 0x0F),   ///< IO port P10 pin 15

    BSP_IO_PORT_P11_PIN_0 = (BSP_IO_PORT_P11 | 0x00),    ///< IO port P11 pin 0
    BSP_IO_PORT_P11_PIN_1 = (BSP_IO_PORT_P11 | 0x01),    ///< IO port P11 pin 1
    BSP_IO_PORT_P11_PIN_2 = (BSP_IO_PORT_P11 | 0x02),    ///< IO port P11 pin 2
    BSP_IO_PORT_P11_PIN_3 = (BSP_IO_PORT_P11 | 0x03),    ///< IO port P11 pin 3
    BSP_IO_PORT_P11_PIN_4 = (BSP_IO_PORT_P11 | 0x04),    ///< IO port P11 pin 4

    BSP_IO_PORT_P27_PIN_0 = (BSP_IO_PORT_P27 | 0x00),    ///< IO port P27 pin 0

    BSP_IO_PORT_AP00_PIN_0  = (BSP_IO_PORT_AP00 | 0x00), ///< IO port AP00 pin 0
    BSP_IO_PORT_AP00_PIN_1  = (BSP_IO_PORT_AP00 | 0x01), ///< IO port AP00 pin 1
    BSP_IO_PORT_AP00_PIN_2  = (BSP_IO_PORT_AP00 | 0x02), ///< IO port AP00 pin 2
    BSP_IO_PORT_AP00_PIN_3  = (BSP_IO_PORT_AP00 | 0x03), ///< IO port AP00 pin 3
    BSP_IO_PORT_AP00_PIN_4  = (BSP_IO_PORT_AP00 | 0x04), ///< IO port AP00 pin 4
    BSP_IO_PORT_AP00_PIN_5  = (BSP_IO_PORT_AP00 | 0x05), ///< IO port AP00 pin 5
    BSP_IO_PORT_AP00_PIN_6  = (BSP_IO_PORT_AP00 | 0x06), ///< IO port AP00 pin 6
    BSP_IO_PORT_AP00_PIN_7  = (BSP_IO_PORT_AP00 | 0x07), ///< IO port AP00 pin 7
    BSP_IO_PORT_AP00_PIN_8  = (BSP_IO_PORT_AP00 | 0x08), ///< IO port AP00 pin 8
    BSP_IO_PORT_AP00_PIN_9  = (BSP_IO_PORT_AP00 | 0x09), ///< IO port AP00 pin 9
    BSP_IO_PORT_AP00_PIN_10 = (BSP_IO_PORT_AP00 | 0x0A), ///< IO port AP00 pin 10

    BSP_IO_PORT_JP00_PIN_0 = (BSP_IO_PORT_JP00 | 0x00),  ///< IO port JP00 pin 0
    BSP_IO_PORT_JP00_PIN_1 = (BSP_IO_PORT_JP00 | 0x01),  ///< IO port JP00 pin 1
    BSP_IO_PORT_JP00_PIN_2 = (BSP_IO_PORT_JP00 | 0x02),  ///< IO port JP00 pin 2
    BSP_IO_PORT_JP00_PIN_3 = (BSP_IO_PORT_JP00 | 0x03),  ///< IO port JP00 pin 3
    BSP_IO_PORT_JP00_PIN_5 = (BSP_IO_PORT_JP00 | 0x05),  ///< IO port JP00 pin 5
    BSP_IO_PORT_JP00_PIN_6 = (BSP_IO_PORT_JP00 | 0x06),  ///< IO port JP00 pin 6
#elif (BSP_PACKAGE_PINS_BGA64 == BSP_PACKAGE_PINS)
    BSP_IO_PORT_P00_PIN_0 = (BSP_IO_PORT_P00 | 0x00),    ///< IO port P00 pin 0
    BSP_IO_PORT_P00_PIN_1 = (BSP_IO_PORT_P00 | 0x01),    ///< IO port P00 pin 1
    BSP_IO_PORT_P00_PIN_2 = (BSP_IO_PORT_P00 | 0x02),    ///< IO port P00 pin 2
    BSP_IO_PORT_P00_PIN_3 = (BSP_IO_PORT_P00 | 0x03),    ///< IO port P00 pin 3
    BSP_IO_PORT_P00_PIN_4 = (BSP_IO_PORT_P00 | 0x04),    ///< IO port P00 pin 4
    BSP_IO_PORT_P00_PIN_5 = (BSP_IO_PORT_P00 | 0x05),    ///< IO port P00 pin 5
    BSP_IO_PORT_P00_PIN_6 = (BSP_IO_PORT_P00 | 0x06),    ///< IO port P00 pin 6

    BSP_IO_PORT_P08_PIN_0 = (BSP_IO_PORT_P08 | 0x00),    ///< IO port P08 pin 0
    BSP_IO_PORT_P08_PIN_1 = (BSP_IO_PORT_P08 | 0x01),    ///< IO port P08 pin 1
    BSP_IO_PORT_P08_PIN_2 = (BSP_IO_PORT_P08 | 0x02),    ///< IO port P08 pin 2
    BSP_IO_PORT_P08_PIN_3 = (BSP_IO_PORT_P08 | 0x03),    ///< IO port P08 pin 3
    BSP_IO_PORT_P08_PIN_4 = (BSP_IO_PORT_P08 | 0x04),    ///< IO port P08 pin 4
    BSP_IO_PORT_P08_PIN_5 = (BSP_IO_PORT_P08 | 0x05),    ///< IO port P08 pin 5

    BSP_IO_PORT_P09_PIN_0 = (BSP_IO_PORT_P09 | 0x00),    ///< IO port P09 pin 0
    BSP_IO_PORT_P09_PIN_1 = (BSP_IO_PORT_P09 | 0x01),    ///< IO port P09 pin 1

    BSP_IO_PORT_P10_PIN_0  = (BSP_IO_PORT_P10 | 0x00),   ///< IO port P10 pin 0
    BSP_IO_PORT_P10_PIN_1  = (BSP_IO_PORT_P10 | 0x01),   ///< IO port P10 pin 1
    BSP_IO_PORT_P10_PIN_2  = (BSP_IO_PORT_P10 | 0x02),   ///< IO port P10 pin 2
    BSP_IO_PORT_P10_PIN_3  = (BSP_IO_PORT_P10 | 0x03),   ///< IO port P10 pin 3
    BSP_IO_PORT_P10_PIN_4  = (BSP_IO_PORT_P10 | 0x04),   ///< IO port P10 pin 4
    BSP_IO_PORT_P10_PIN_5  = (BSP_IO_PORT_P10 | 0x05),   ///< IO port P10 pin 5
    BSP_IO_PORT_P10_PIN_6  = (BSP_IO_PORT_P10 | 0x06),   ///< IO port P10 pin 6
    BSP_IO_PORT_P10_PIN_7  = (BSP_IO_PORT_P10 | 0x07),   ///< IO port P10 pin 7
    BSP_IO_PORT_P10_PIN_8  = (BSP_IO_PORT_P10 | 0x08),   ///< IO port P10 pin 8
    BSP_IO_PORT_P10_PIN_9  = (BSP_IO_PORT_P10 | 0x09),   ///< IO port P10 pin 9
    BSP_IO_PORT_P10_PIN_10 = (BSP_IO_PORT_P10 | 0x0A),   ///< IO port P10 pin 10
    BSP_IO_PORT_P10_PIN_11 = (BSP_IO_PORT_P10 | 0x0B),   ///< IO port P10 pin 11
    BSP_IO_PORT_P10_PIN_12 = (BSP_IO_PORT_P10 | 0x0C),   ///< IO port P10 pin 12
    BSP_IO_PORT_P10_PIN_13 = (BSP_IO_PORT_P10 | 0x0D),   ///< IO port P10 pin 13
    BSP_IO_PORT_P10_PIN_14 = (BSP_IO_PORT_P10 | 0x0E),   ///< IO port P10 pin 14

    BSP_IO_PORT_P27_PIN_0 = (BSP_IO_PORT_P27 | 0x00),    ///< IO port P27 pin 0

    BSP_IO_PORT_AP00_PIN_0 = (BSP_IO_PORT_AP00 | 0x00),  ///< IO port AP00 pin 0
    BSP_IO_PORT_AP00_PIN_1 = (BSP_IO_PORT_AP00 | 0x01),  ///< IO port AP00 pin 1
    BSP_IO_PORT_AP00_PIN_2 = (BSP_IO_PORT_AP00 | 0x02),  ///< IO port AP00 pin 2
    BSP_IO_PORT_AP00_PIN_3 = (BSP_IO_PORT_AP00 | 0x03),  ///< IO port AP00 pin 3
    BSP_IO_PORT_AP00_PIN_4 = (BSP_IO_PORT_AP00 | 0x04),  ///< IO port AP00 pin 4
    BSP_IO_PORT_AP00_PIN_5 = (BSP_IO_PORT_AP00 | 0x05),  ///< IO port AP00 pin 5
    BSP_IO_PORT_AP00_PIN_6 = (BSP_IO_PORT_AP00 | 0x06),  ///< IO port AP00 pin 6
    BSP_IO_PORT_AP00_PIN_7 = (BSP_IO_PORT_AP00 | 0x07),  ///< IO port AP00 pin 7
    BSP_IO_PORT_AP00_PIN_8 = (BSP_IO_PORT_AP00 | 0x08),  ///< IO port AP00 pin 8
    BSP_IO_PORT_AP00_PIN_9 = (BSP_IO_PORT_AP00 | 0x09),  ///< IO port AP00 pin 9

    BSP_IO_PORT_JP00_PIN_0 = (BSP_IO_PORT_JP00 | 0x00),  ///< IO port JP00 pin 0
    BSP_IO_PORT_JP00_PIN_1 = (BSP_IO_PORT_JP00 | 0x01),  ///< IO port JP00 pin 1
    BSP_IO_PORT_JP00_PIN_2 = (BSP_IO_PORT_JP00 | 0x02),  ///< IO port JP00 pin 2
    BSP_IO_PORT_JP00_PIN_3 = (BSP_IO_PORT_JP00 | 0x03),  ///< IO port JP00 pin 3
    BSP_IO_PORT_JP00_PIN_5 = (BSP_IO_PORT_JP00 | 0x05),  ///< IO port JP00 pin 5
    BSP_IO_PORT_JP00_PIN_6 = (BSP_IO_PORT_JP00 | 0x06),  ///< IO port JP00 pin 6
#endif
} bsp_io_port_pin_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_IO) */

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
