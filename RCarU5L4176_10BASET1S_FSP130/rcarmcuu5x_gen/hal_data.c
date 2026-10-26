/* generated HAL source file - do not edit */
#include "hal_data.h"

ether_phy_instance_ctrl_t g_ether_phy0_ctrl;

const ether_phy_lsi_cfg_t g_ether_phy0_phy_lsi_cfg_list =
{ .address = 31, .type = ETHER_PHY_LSI_TYPE_CT25205_RTL, };

const ether_phy_extended_cfg_t g_ether_phy0_extended_cfg =
{ .p_target_init = NULL,
  .p_target_link_partner_ability_get = NULL,
  .p_phy_lsi_cfg_list = &g_ether_phy0_phy_lsi_cfg_list,
  .eth_reg = ETHER_PHY_ETH_REG_T1S,
  .p_mdio_read = NULL,
  .p_mdio_write = NULL, };

const ether_phy_cfg_t g_ether_phy0_cfg =
{

.channel = 0,
  .phy_lsi_address = 31, .phy_reset_wait_time = 0x00020000, .mii_bit_access_wait_time = 8, .phy_lsi_type =
          ETHER_PHY_LSI_TYPE_CT25205_RTL,
  .flow_control = ETHER_PHY_FLOW_CONTROL_DISABLE, .p_context = NULL, .p_extend = &g_ether_phy0_extended_cfg,

};
/* Instance structure to use this module. */
const ether_phy_instance_t g_ether_phy0 =
{ .p_ctrl = &g_ether_phy0_ctrl, .p_cfg = &g_ether_phy0_cfg, .p_api = &g_ether_phy_on_ether_phy };
/* RAM size calculated by descriptor chain, tx descriptor, rx descriptor and rx buffer */
uint8_t g_ether_t1s0_mem_pool_buffer_0[25500] BSP_PLACE_IN_SECTION(BSP_SECTION_GRAM_BSS) BSP_ALIGN_VARIABLE(4);

ether_t1s_instance_ctrl_t g_ether_t1s0_ctrl;

uint8_t g_ether_t1s0_mac_address_source[6] =
{ 0x74, 0x90, 0x50, 0x00, 0x00, 0x00 };
uint8_t g_ether_t1s0_mac_address_destination[6] =
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
#if (ETHER_T1S_CFG_UPDATE_PHYS_ADDR_FILTER)
            uint8_t g_ether_t1s0_mac_address_filter[32][6] = { {0x00,0x00,0x00,0x00,0x00,0x00}, \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},  \
                                                                              {0x00,0x00,0x00,0x00,0x00,0x00},
                                                                              };
            #endif

const ether_t1s_tx_queue_type_etnf g_ether_t1s0_tx_queue_config[] =
{
{
/* Tx queue 0 */
.eth_tx_queue_bufs = 8,
  .eth_tx_queue_id = 0, },
  {
  /* Tx queue 1 */
  .eth_tx_queue_bufs = 8,
    .eth_tx_queue_id = 1, },
  {
  /* Tx queue 2 */
#if (ETHER_T1S_CFG_QOS_SUPPORT)
                .tx_queue_shaper.tx_q_policy = ETHER_T1S_NONE,
                .tx_queue_shaper.civ = 0,
                .tx_queue_shaper.cdv = 0,
                 #endif
    .eth_tx_queue_bufs = 8,
    .eth_tx_queue_id = 2, },
  {
  /* Tx queue 3 */
#if (ETHER_T1S_CFG_QOS_SUPPORT)
                .tx_queue_shaper.tx_q_policy = ETHER_T1S_NONE,
                .tx_queue_shaper.civ = 0,
                .tx_queue_shaper.cdv = 0,
                 #endif
    .eth_tx_queue_bufs = 8,
    .eth_tx_queue_id = 3, }, };

const ether_t1s_rx_queue_type_etnf g_ether_t1s0_rx_queue_config[] =
{
/* Rx queue 0 */
{ .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 0U, },

  /* Rx queue 1 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 1U, },

  /* Rx queue 2 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 2U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 3 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 3U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 4 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 4U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 5 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 5U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 6 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 6U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 7 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 7U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 8 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 8U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 9 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 9U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 10 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 10U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 11 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 11U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 12 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 12U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 13 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 13U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 14 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 14U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 15 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 15U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 16 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 16U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

  /* Rx queue 17 */
  { .eth_rx_queue_bufs = 8, .eth_rx_queue_id = 17U,
#if (ETHER_T1S_CFG_STREAM_FILTERING)
                .eth_pattern_stream = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
                #endif
  },

};
#if (ETHER_T1S_CFG_QOS_SUPPORT)
            const ether_t1s_priority_mapping_type g_ether_t1s0_ctrl_priority_table[] =
            {
                {
                    .eth_ctrl_priority_value = 0,
                    .eth_ctrl_tx_queue_id = 0,
                },
                {
                    .eth_ctrl_priority_value = 0,
                    .eth_ctrl_tx_queue_id = 0,
                },
                {
                    .eth_ctrl_priority_value = 0,
                    .eth_ctrl_tx_queue_id = 0,
                },
                {
                    .eth_ctrl_priority_value = 0,
                    .eth_ctrl_tx_queue_id = 0,
                },
                {
                    .eth_ctrl_priority_value = 0,
                    .eth_ctrl_tx_queue_id = 0,
                },
                {
                    .eth_ctrl_priority_value = 0,
                    .eth_ctrl_tx_queue_id = 0,
                },
                {
                    .eth_ctrl_priority_value = 0,
                    .eth_ctrl_tx_queue_id = 0,
                },
                {
                    .eth_ctrl_priority_value = 0,
                    .eth_ctrl_tx_queue_id = 0,
                },
            };
            #endif
const ether_t1s_etnf_config_type g_ether_t1s0_hw_unit_configuration_etnf =
{ .queue_config.p_tx_queue_config = &g_ether_t1s0_tx_queue_config[0],
  .queue_config.p_rx_queue_config = &g_ether_t1s0_rx_queue_config[0],
  .queue_config.number_of_tx_queue = 1,
  .queue_config.number_of_rx_queue = 1,
  .rx_config.encf = ETHER_T1S_DISABLE,
  .rx_config.esf = ETHER_T1S_AVBNMQUE0,
  .rx_config.ets0 = ETHER_T1S_DISABLE,
  .rx_config.ets2 = ETHER_T1S_DISABLE,
  .rx_config.rfcl = 0x1800U,
  .tx_config = ETHER_T1S_AVBDEF,
  .ecbs = ETHER_T1S_DISABLE,
#if (ETHER_T1S_CFG_QOS_SUPPORT)
                .ctrl_priority.p_priority_table = &g_ether_t1s0_ctrl_priority_table[0],
                .ctrl_priority.number_of_priorities = 1,
                .ctrl_priority.dfl_tx_queue = 0,
                #endif
        };

const ether_t1s_extended_cfg_t g_ether_t1s0_extended_cfg =
        { .eth_mac_addr =
        { 0x74, 0x90, 0x50, 0x00, 0x00, 0x00 },
          .ether_t1s_cfg_type_tx_isr = ETHER_T1S_CTRL_POLLING_MODE, .ether_t1s_cfg_type_rx_isr =
                  ETHER_T1S_CTRL_POLLING_MODE,
          .ether_t1s_ctl_mode = ETHER_T1S_CTRL_POLLING_MODE,
#if (ETHER_T1S_CFG_UPDATE_PHYS_ADDR_FILTER)
                .p_mac_address_filter = (uint8_t *)g_ether_t1s0_mac_address_filter,
                .ether_t1s_filter_action_type = ETHER_T1S_ADD_TO_FILTER,
                #endif
          .header_data_custom = ETHER_T1S_HEADER_CUSTOM,
          .ether_type = 0x003E, .p_hw_unit_config = &g_ether_t1s0_hw_unit_configuration_etnf, .ether_loopback_config =
                  ETHER_T1S_LOOPBACK_OFF,
          .ether_network_speed = ETHER_T1S_SPEED_10MBPS, .ether_phy_interface = ETHER_T1S_MODE,
#if (ETHER_T1S_CFG_UPDATE_PHYS_ADDR_FILTER)
                .number_of_addr_filter = 1,
                #endif
          .p_mac_address_target = g_ether_t1s0_mac_address_destination,

          .pma_type = ETHER_T1S_PMA_FILTERED,
          .mdio_interface_type = ETHER_T1S_MDIO_INTERFACE_SHARED, .mdio_slave_address = 31, .ether_t1s_ram_size = 25500U, .p_mem_pool_buffer_table =
                  g_ether_t1s0_mem_pool_buffer_0,
#if defined(VECTOR_NUMBER_INTETNF0MNG)
                .other_irq = VECTOR_NUMBER_INTETNF0MNG,
            #else
          .other_irq = FSP_INVALID_VECTOR,
#endif
          .interrupt_priority = (uint8_t) (BSP_IRQ_DISABLED),
          .time_stamp_sel = ETHER_T1S_TIME_STAMP_MII, };

const ether_cfg_t g_ether_t1s0_cfg =
        { .channel = 0, .zerocopy = ETHER_ZEROCOPY_DISABLE, .p_mac_address = g_ether_t1s0_mac_address_source,
#if defined(VECTOR_NUMBER_INTETNF0DATA)
                    .irq = VECTOR_NUMBER_INTETNF0DATA,
                #else
          .irq = FSP_INVALID_VECTOR,
#endif
          .interrupt_priority = (uint8_t) (BSP_IRQ_DISABLED),
          .p_callback = NULL, .p_ether_phy_instance = &g_ether_phy0, .p_context = NULL, .p_extend =
                  &g_ether_t1s0_extended_cfg, };
/* Instance structure to use this module. */
const ether_instance_t g_ether_t1s0 =
{ .p_ctrl = &g_ether_t1s0_ctrl, .p_cfg = &g_ether_t1s0_cfg, .p_api = &g_ether_t1s_on_ether_t1s };
void g_hal_init(void)
{
    g_common_init ();
}
