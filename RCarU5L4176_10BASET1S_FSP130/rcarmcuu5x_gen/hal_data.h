/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_ether_phy.h"
#include "r_ether_phy_api.h"
#include "r_ether_t1s.h"
#include "r_ether_api.h"
FSP_HEADER
#ifndef NULL
void NULL(ether_phy_instance_ctrl_t *p_instance_ctrl);
#endif

#ifndef NULL
bool NULL(ether_phy_instance_ctrl_t *p_instance_ctrl, uint32_t line_speed_duplex);
#endif

#ifndef NULL
void NULL(uint8_t phy_addr, uint32_t reg_addr, uint32_t *p_data);
#endif

#ifndef NULL
void NULL(uint8_t phy_addr, uint32_t reg_addr, uint32_t data);
#endif

/** ether_phy on ether_phy Instance. */
extern const ether_phy_instance_t g_ether_phy0;

/** Access the Ethernet PHY instance using these structures when calling API functions directly (::p_api is not used). */
extern ether_phy_instance_ctrl_t g_ether_phy0_ctrl;
extern const ether_phy_cfg_t g_ether_phy0_cfg;
extern const ether_phy_extended_cfg_t g_ether_phy0_extended_cfg;
/** ether t1s on ether Instance. */
extern const ether_instance_t g_ether_t1s0;

/** Access the Ethernet instance using these structures when calling API functions directly (::p_api is not used). */
extern ether_t1s_instance_ctrl_t g_ether_t1s0_ctrl;
extern const ether_cfg_t g_ether_t1s0_cfg;

#ifndef NULL
void NULL(ether_callback_args_t *p_args);
#endif
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */
