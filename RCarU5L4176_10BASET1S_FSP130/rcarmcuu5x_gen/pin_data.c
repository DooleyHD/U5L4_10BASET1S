/* generated pin source file - do not edit */
#include "bsp_api.h"
#if __has_include("r_ioport.h")
#include "r_ioport.h"
#endif

const ioport_pin_cfg_t g_bsp_pin_cfg_data[] =
        {
        { .pin = BSP_IO_PORT_JP00_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_PERIPHERAL_PIN) },
          { .pin = BSP_IO_PORT_JP00_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_HIGH
                  | (uint32_t) IOPORT_CFG_PERIPHERAL_PIN) },
          { .pin = BSP_IO_PORT_JP00_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_PERIPHERAL_PIN) },
          { .pin = BSP_IO_PORT_JP00_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_PERIPHERAL_PIN) },
          { .pin = BSP_IO_PORT_P10_PIN_0, .pin_cfg = ((uint32_t) IOPORT_ALT_OUT11 | (uint32_t) IOPORT_CFG_DRIVE_HIGH
                  | (uint32_t) IOPORT_CFG_PERIPHERAL_PIN | (uint32_t) IOPORT_CFG_PIPC_PERIPHERAL) },
          { .pin = BSP_IO_PORT_P10_PIN_1, .pin_cfg = ((uint32_t) IOPORT_ALT_OUT11 | (uint32_t) IOPORT_CFG_DRIVE_HIGH
                  | (uint32_t) IOPORT_CFG_PERIPHERAL_PIN | (uint32_t) IOPORT_CFG_PIPC_PERIPHERAL) },
          { .pin = BSP_IO_PORT_P10_PIN_2, .pin_cfg = ((uint32_t) IOPORT_ALT_OUT11 | (uint32_t) IOPORT_CFG_DRIVE_HIGH
                  | (uint32_t) IOPORT_CFG_PERIPHERAL_PIN) },
          { .pin = BSP_IO_PORT_P18_PIN_0, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT
                  | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW) },
          { .pin = BSP_IO_PORT_P18_PIN_1, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT
                  | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW) },
          { .pin = BSP_IO_PORT_P18_PIN_2, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT
                  | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW) },
          { .pin = BSP_IO_PORT_P18_PIN_3, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT
                  | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW) },
          { .pin = BSP_IO_PORT_P18_PIN_4, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT
                  | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW) },
          { .pin = BSP_IO_PORT_P18_PIN_5, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT
                  | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW) },
          { .pin = BSP_IO_PORT_P18_PIN_6, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT
                  | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW) },
          { .pin = BSP_IO_PORT_P18_PIN_7, .pin_cfg = ((uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT
                  | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW) }, };

const ioport_cfg_t g_bsp_pin_cfg =
{ .number_of_pins = sizeof(g_bsp_pin_cfg_data) / sizeof(ioport_pin_cfg_t), .p_pin_cfg_data = &g_bsp_pin_cfg_data[0], };
