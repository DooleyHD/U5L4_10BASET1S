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

#define BSP_GUARD_GET_BIT(value)    (__CLZ(__RBIT((value))))

#define BSP_GUARD_KCPROT_ADDRESS_OFFSET    (0x18)   /* KCPROT register offset */

#define BSP_PBG_CHANNEL_ADDRESS_OFFSET     (0x08)   /* PBG channel offset */

#define BSP_PBG_KCPROT_ADDRESS_OFFSET      (0x18)   /* PBG KCPROT offset */

#define BSP_GUARD_READ_WRITE_ACCESS        (0x103U) // Full read/write access

#define BSP_PRV_PBG_WRITE_ENABLE           (1 << 1) /* Enable bit to allow read/write access to PBG */

#define BSP_GUARD_PROTECTION_ENABLE        (uint32_t) 0xA5A5A501UL

#define BSP_GUARD_PROTECTION_DISABLE       (uint32_t) 0xA5A5A500UL

#define BSP_GUARD_MAX_32BITS_ADDRESS       (uint32_t) 0xFFFFFFFFUL

#define BSP_PRV_IBG_ENABLE                 (1U << 1U) /* IBG enable read, write access value */

#define BSP_IBG_CHANNEL_ADDRESS_OFFSET     (0x08U)    /* Macro is used to calculate the IBG address */

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static void bsp_guard_write_enable(const bsp_pbg_group_t pbg_group);
static void bsp_guard_write_disable(const bsp_pbg_group_t pbg_group);

#if (1U == BSP_FEATURE_GUARD_IS_AVAILABLE)
static void bsp_xram_guard_setting(bsp_r_rrgrd_ctl_xram_rrg_type_t * p_base_address,
                                   uint32_t                        * p_reg_xrgkcprot,
                                   bsp_channel_protection_control_t  channel_protection_control);
static void bsp_xram_guard_status(bsp_r_xrgd_cap_rramnn_type   * p_channel_base_address,
                                  bsp_xram_protection_status_t * p_status);

#endif
#if !BSP_VLAB_HARDWARE_BASED_USED
static void bsp_pbg_protection_setting(const bsp_guard_protection_setting_t * p_setting);

#endif
static void bsp_guard_channel_setting(const bsp_pbg_group_t pbg_group,
                                      const uint32_t        pbg_channels,
                                      const bool            pgb_enable);

/*******************************************************************************************************************//**
 * @addtogroup BSP_GUARD
 *
 * @{
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Enable Write Access of all configured region that is enabled access on BSP MDF.
 **********************************************************************************************************************/
void R_BSP_GuardEnableAccessAll ()
{
#if !BSP_VLAB_HARDWARE_BASED_USED
    uint32_t        channels;
    uint32_t        channel_num;
    bsp_pbg_group_t pbg_grp;

    uint8_t element_count;
    uint8_t module_count;
    uint8_t max_element_count;
    bool    initial_cfg_value;

    /* Initialize all protection configuration to all zeros */
    bsp_guard_protection_setting_t pbg_setting = {.slave_guard_protection.pbusgrd_setting.rgid = 0};

    /* PBG (Peripheral Bus Guard) & HBG (H-Bus Guard) Initialization */
    for (module_count = 0; module_count < BSP_MODULE_PBG_INDEX_END; module_count++)
    {
        initial_cfg_value = g_bsp_module_pbg_info_table[module_count].initial_cfg_value;

        if (1U == initial_cfg_value)
        {
            /* Get the number of elements (properties) for this PBG/HBG module */
            max_element_count = g_bsp_module_pbg_info_table[module_count].no_of_element;

            for (element_count = 0; element_count < max_element_count; element_count++)
            {
                /* Get PBG group and channel information from configuration table */
                pbg_grp  = g_bsp_module_pbg_info_table[module_count].properties[element_count].pbg_group;
                channels = g_bsp_module_pbg_info_table[module_count].properties[element_count].pbg_channel;

                /* Enable full read/write access for all specified channels */
                while (0 != channels)
                {
                    /* Get the next channel to configure */
                    channel_num = (uint8_t) BSP_GUARD_GET_BIT(channels);

                    pbg_setting.slave_guard_protection.pbusgrd_setting.group           = pbg_grp;
                    pbg_setting.slave_guard_protection.pbusgrd_setting.channel         = (uint8_t) channel_num;
                    pbg_setting.slave_guard_protection.pbusgrd_setting.protect_setting = BSP_GUARD_READ_WRITE_ACCESS;

                    bsp_pbg_protection_setting(&pbg_setting);

                    /* Set this channel is configured */
                    channels &= ~(1U << channel_num);
                }
            }
        }
    }
#endif
}

/*******************************************************************************************************************//**
 * Enable Write access to guarded region. Region that are guarded cannot be written to. Register guard is
 * control by Peripheral Guard (PBG) and H-Peripheral Guard (HBG).
 *
 * @param[in] pbg_group      Guard group index to enable
 * @param[in] pbg_channels   Guard channel index to enable
 **********************************************************************************************************************/
void R_BSP_GuardAccessEnable (const bsp_pbg_group_t pbg_group, const bsp_pbg_channel_t pbg_channels)
{
    /* Enable Write access to guarded region */
    bsp_guard_channel_setting(pbg_group, pbg_channels, 1U);
}

/*******************************************************************************************************************//**
 * Disable Write access guarded region. Region that are guarded cannot be written to. Register guard is
 * control by Peripheral Guard (PBG) and H-Peripheral Guard (HBG).
 *
 * @param[in] pbg_group      Guard group index to enable
 * @param[in] pbg_channels   Guard channel index to enable
 **********************************************************************************************************************/
void R_BSP_GuardAccessDisable (const bsp_pbg_group_t pbg_group, const bsp_pbg_channel_t pbg_channels)
{
    /* Disable Write access to guarded region */
    bsp_guard_channel_setting(pbg_group, pbg_channels, 0U);
}

/*******************************************************************************************************************//**
 * Setting xRAM (CPU RAM/ Global RAM/ Cluster RAM) Guard Protection
 *
 * @param[in] memory_type                     Type of RAM guard protection (CPU RAM/ Global RAM/ Cluster RAM).
 * @param[in] entry_channel_number            Channel of RAM guard protection
 * @param[in] channel_protection_control      RAM guard protection setting.
 **********************************************************************************************************************/
void R_BSP_RamGuardProtectionSetting (bsp_xram_memory_type_t           memory_type,
                                      bsp_xram_entry_number_t          entry_channel_number,
                                      bsp_channel_protection_control_t channel_protection_control)
{
#if (1U == BSP_FEATURE_GUARD_IS_AVAILABLE)

    /* RAM Protection is protected by IBG, enable IBG before setting for RAM guard protection */
    R_BSP_IBG_ProtectionSetting(g_xram_ibg_protection[memory_type].ibg_group,
                                g_xram_ibg_protection[memory_type].channel,
                                true);
    bsp_xram_guard_setting((bsp_r_rrgrd_ctl_xram_rrg_type_t *) g_xram_guard_protection_baseaddress[memory_type][
                               entry_channel_number],
                           (uint32_t *) g_xram_guard_protection_register_baseaddress[memory_type],
                           channel_protection_control);

    /* RAM Protection is protected by IBG, disable IBG after setting for RAM guard protection */
    R_BSP_IBG_ProtectionSetting(g_xram_ibg_protection[memory_type].ibg_group,
                                g_xram_ibg_protection[memory_type].channel,
                                false);
#else
    FSP_PARAMETER_NOT_USED(memory_type);
    FSP_PARAMETER_NOT_USED(entry_channel_number);
    FSP_PARAMETER_NOT_USED(channel_protection_control);
#endif
}

/*******************************************************************************************************************//**
 * Get status of xRAM (CPU RAM/ Global RAM/ Cluster RAM) Guard Protection
 *
 * @param[in] memory_type      Type of RAM guard protection (CPU RAM/ Global RAM/ Cluster RAM).
 * @param[out] status          Status of ram guard protection
 **********************************************************************************************************************/
void R_BSP_RamGuardProtectionStatus (bsp_xram_memory_type_t memory_type, bsp_xram_protection_status_t * status)
{
#if (1U == BSP_FEATURE_GUARD_IS_AVAILABLE)
    bsp_xram_guard_status((bsp_r_xrgd_cap_rramnn_type *) g_xram_guard_protection_status_baseaddress[memory_type],
                          status);
#else
    FSP_PARAMETER_NOT_USED(memory_type);
    FSP_PARAMETER_NOT_USED(status);
#endif
}

/*******************************************************************************************************************//**
 * Enable/Disable Write access to guarded region (IBG).
 *
 * @param[in] igb_channel      IBG group.
 * @param[in] channels         Guard group index to enable
 * @param[in] guard_setting    Enable/Disable Write access to guarded region
 **********************************************************************************************************************/
void R_BSP_IBG_ProtectionSetting (bsp_ibg_group_t igb_channel, uint16_t channels, bool guard_setting)
{
#if (1U == BSP_FEATURE_GUARD_IS_AVAILABLE)
    volatile uint32_t * p_ibgprot_address;
    uint16_t            channel_num;

    /* Enables write access of protected registers */
    *(volatile uint32_t *) g_ibg_protection_register_baseaddress[igb_channel] = BSP_GUARD_PROTECTION_ENABLE;

    /* Initialize all PBG channels that assigned for module */
    while (channels != 0)
    {
        /* Get the next channel to configure */
        channel_num = (uint16_t) BSP_GUARD_GET_BIT(channels);

        /* Get the IPBG address */
        p_ibgprot_address =
            (volatile uint32_t *) (g_igbprot_baseaddress[igb_channel] + (channel_num * BSP_IBG_CHANNEL_ADDRESS_OFFSET));

        /* Enable Read, Write access PBG.WG and PBG.RG bits */
        if (guard_setting)
        {
            *p_ibgprot_address = (*p_ibgprot_address) | (uint32_t) (BSP_PRV_IBG_ENABLE);
        }
        else
        {
            *p_ibgprot_address = (*p_ibgprot_address) & (uint32_t) ~(BSP_PRV_IBG_ENABLE);
        }

        /* Set this channel is configured */
        channels &= (uint16_t) ~(1U << channel_num);
    }

    /* Disables write access of protected registers */
    *(volatile uint32_t *) g_ibg_protection_register_baseaddress[igb_channel] = BSP_GUARD_PROTECTION_DISABLE;
#else
    FSP_PARAMETER_NOT_USED(igb_channel);
    FSP_PARAMETER_NOT_USED(channels);
    FSP_PARAMETER_NOT_USED(guard_setting);
#endif
}

/** @} (end addtogroup BSP_GUARD) */

/*******************************************************************************************************************//**
 * Enable write access to all protected register of guard
 *
 * @param[in] pbg_group      Guard group index to enable
 **********************************************************************************************************************/
static void bsp_guard_write_enable (const bsp_pbg_group_t pbg_group)
{
    volatile uint32_t * p_pbgkcprot_address;

#if (1U == BSP_FEATURE_GUARD_GROUP_PE_IS_AVAILABLE)
    if (BSP_PBG_GROUP_PE == pbg_group)
    {
        /* Get the PBGKCPROT address */
        p_pbgkcprot_address = (uint32_t *) R_PGRDPE_KCPROT_BASE;
    }
    else
#endif
    {
        /* Get the PBGKCPROT address */
        p_pbgkcprot_address = (uint32_t *) (g_pbgkcprot_baseaddress[pbg_group] + BSP_PBG_KCPROT_ADDRESS_OFFSET);
    }

    /* Enable write access to protected registers */
    *p_pbgkcprot_address = (uint32_t) BSP_PRV_KEYCODE_ENABLE;
}

/*******************************************************************************************************************//**
 * Disable write access to all protected register of guard
 *
 * @param[in] pbg_group      Guard group index to enable
 **********************************************************************************************************************/
static void bsp_guard_write_disable (const bsp_pbg_group_t pbg_group)
{
    volatile uint32_t * p_pbgkcprot_address;

#if (1U == BSP_FEATURE_GUARD_GROUP_PE_IS_AVAILABLE)
    if (BSP_PBG_GROUP_PE == pbg_group)
    {
        /* Get the PBGKCPROT address */
        p_pbgkcprot_address = (uint32_t *) R_PGRDPE_KCPROT_BASE;
    }
    else
#endif
    {
        p_pbgkcprot_address = (uint32_t *) (g_pbgkcprot_baseaddress[pbg_group] + BSP_PBG_KCPROT_ADDRESS_OFFSET);
    }

    /* Disable write access to protected registers */
    *p_pbgkcprot_address = (uint32_t) BSP_PRV_KEYCODE_DISABLE;
}

#if (1U == BSP_FEATURE_GUARD_IS_AVAILABLE)

/*******************************************************************************************************************//**
 * Setting xRAM Guard Protection
 **********************************************************************************************************************/
static void bsp_xram_guard_setting (bsp_r_rrgrd_ctl_xram_rrg_type_t * p_base_address,
                                    uint32_t                        * p_reg_xrgkcprot,
                                    bsp_channel_protection_control_t  channel_protection_control)
{
    volatile bsp_r_rrgrd_ctl_xram_rrg_type_t * p_xrg_reg;
    volatile uint32_t * p_xrgkcprot_reg;

    /* Assign input pointers to local variables for easier access */
    p_xrg_reg       = (volatile bsp_r_rrgrd_ctl_xram_rrg_type_t *) p_base_address;
    p_xrgkcprot_reg = (volatile uint32_t *) p_reg_xrgkcprot;

    /* Enables write access of protected registers */
    *(p_xrgkcprot_reg) = BSP_GUARD_PROTECTION_ENABLE;

    /* Setting the R/W enable setting by RGID */
    p_xrg_reg->RGID = channel_protection_control.rgid_setting;

    /* Enable Read/Write Permission */
    p_xrg_reg->PROT_b.RG  = channel_protection_control.enable_read_global;
    p_xrg_reg->PROT_b.WG  = channel_protection_control.enable_write_global;
    p_xrg_reg->PROT_b.GEN = channel_protection_control.enable_guard_setting;

    /* Guard Base Address Setting */
    p_xrg_reg->BAD_b.BAD = channel_protection_control.guard_base_address;

    /* Guard Address Valid Bit Setting */
    p_xrg_reg->ADV = channel_protection_control.valid_bit_setting;

    /* Disables write access of protected registers */
    *(p_xrgkcprot_reg) = BSP_GUARD_PROTECTION_DISABLE;
}

/*******************************************************************************************************************//**
 * Get status of xRAM Guard Protection
 **********************************************************************************************************************/
static void bsp_xram_guard_status (bsp_r_xrgd_cap_rramnn_type   * p_channel_base_address,
                                   bsp_xram_protection_status_t * p_status)
{
    volatile bsp_r_xrgd_cap_rramnn_type   * p_channel_reg;
    volatile bsp_xram_protection_status_t * p_channel_status;

    /* Assign input pointers to local variables for easier access */
    p_channel_reg    = (volatile bsp_r_xrgd_cap_rramnn_type *) p_channel_base_address;
    p_channel_status = (volatile bsp_xram_protection_status_t *) p_status;

    /* Error access type request (IH, IL, DH, DL) */
    uint8_t  l_type_access_idx;
    uint32_t l_err_status_flag;

    /* Loop for each access of request type */
    for (l_type_access_idx = 0; l_type_access_idx < BSP_GUARD_MAX_TYPE_ACCESS_REQUEST_STATUS; l_type_access_idx++)
    {
        /* Set the default value to BSP_RAM_GUARD_PROTECTION_STATUS_NORMAL */
        p_channel_status->xram_status[l_type_access_idx].errstatus          = BSP_RAM_GUARD_PROTECTION_STATUS_NORMAL;
        p_channel_status->xram_status[l_type_access_idx].err_access_address = 0UL;
        p_channel_status->xram_status[l_type_access_idx].err_attribute      = 0U;
        p_channel_status->xram_status[l_type_access_idx].err_type_access    = BSP_GUARD_ERROR_ACCESS_READ;

        /* Get the error flag of all channels */
        l_err_status_flag = p_channel_reg->XRGRGIDERRSTAT;

        /* If there are any errors that occurs */
        if ((uint8_t) 0U != l_err_status_flag)
        {
            /* Set the status to error occurred */
            p_channel_status->xram_status[l_type_access_idx].errstatus = BSP_RAM_GUARD_PROTECTION_ERROR_OCCURRED;

            /* Clear all the error */
            p_channel_reg->XRGRGIDERRCLR = BSP_GUARD_MAX_32BITS_ADDRESS;

            /* Get the access address in case any error occur */
            p_status->xram_status[l_type_access_idx].err_access_address = p_channel_reg->XRGERRADDR;
            p_status->xram_status[l_type_access_idx].err_type_access    =
                (bsp_guard_err_access_t) p_channel_reg->XRGERRTYPE_b.WRITE;
            p_status->xram_status[l_type_access_idx].err_attribute = p_channel_reg->XRGERRTYPE_b.RGID;

            if ((uint8_t) 1U == p_channel_reg->XRGOVFSTAT_b.OVF)
            {
                /* Set the status to error overflow */
                p_channel_status->xram_status[l_type_access_idx].errstatus = BSP_RAM_GUARD_PROTECTION_ERROR_OVERFLOW;

                /* Clear the overflow status */
                p_channel_reg->XRGOVFCLR_b.CLRO = 1U;
            }
        }

        /* Move to the next type of access request */
        p_channel_reg++;
    }
}

#endif

#if !BSP_VLAB_HARDWARE_BASED_USED

/*******************************************************************************************************************//**
 * @brief Configures access protection for the specified PBG group and channel, or HBG group.
 *
 * When all guards are disabled, all bus masters can access these registers freely. When enabled, access is restricted
 * according to the specified settings.
 *
 * @param[in] p_setting   Protection settings and access configuration.
 *
 **********************************************************************************************************************/
static void bsp_pbg_protection_setting (const bsp_guard_protection_setting_t * p_setting)
{
    bsp_pbg_group_t pbg_group;
    const bsp_pbg_protection_setting_t * p_pbg_setting;
    volatile uint32_t * p_pbg_prot;
    uint8_t             channels;
    volatile uint32_t * p_pbg_kcprot;

    /* Get pointer to PBG Guard-specific settings from the guard configuration */
    p_pbg_setting = (bsp_pbg_protection_setting_t *) (&p_setting->slave_guard_protection.pbusgrd_setting);

    /* Get PBus Group register target and channel number for protection from settings */
    pbg_group = p_pbg_setting->group;
    channels  = p_pbg_setting->channel;

    /* Calculate address of Protection Control Register for the target and channel */
    p_pbg_prot =
        (volatile uint32_t *) (g_pbgprot_baseaddress[pbg_group] + channels * BSP_PBG_CHANNEL_ADDRESS_OFFSET);

 #if (1U == BSP_FEATURE_GUARD_GROUP_PE_IS_AVAILABLE)
    if (BSP_PBG_GROUP_PE == pbg_group)
    {
        /* Get address of Key Code Protection Register */
        p_pbg_kcprot = (volatile uint32_t *) R_PGRDPE_KCPROT_BASE;
    }
    else
 #endif
    {
        /* Get address of Key Code Protection Register */
        p_pbg_kcprot = (volatile uint32_t *) (g_pbgkcprot_baseaddress[pbg_group] + BSP_GUARD_KCPROT_ADDRESS_OFFSET);
    }

    /* Apply the protection setting to the specified PBus Group */
    (*p_pbg_kcprot) = BSP_PRV_KEYCODE_ENABLE;

    p_pbg_prot[BSP_GUARD_REG_PROT] = p_pbg_setting->protect_setting;

    p_pbg_prot[BSP_GUARD_REG_RGID] = p_pbg_setting->rgid;

    (*p_pbg_kcprot) = BSP_PRV_KEYCODE_DISABLE;
}

#endif

/*******************************************************************************************************************//**
 * Enable/Disable Write access to guarded region. Region that are guarded cannot be written to. Register guard is
 * control by Peripheral Guard (PBG) and H-Peripheral Guard (HBG).
 *
 * @param[in] pbg_group      Guard group index to enable
 * @param[in] pbg_channels   Guard channel index to enable
 * @param[in] pgb_enable     Enable/Disable Write access to guarded region
 **********************************************************************************************************************/
static void bsp_guard_channel_setting (const bsp_pbg_group_t pbg_group,
                                       const uint32_t        pbg_channels,
                                       const bool            pgb_enable)
{
    volatile uint32_t * p_pbgprot_address;
    uint32_t            channels;
    uint32_t            channel_num;

    /* Assign the value of pbg_channels to channels */
    channels = pbg_channels;

    /* Enable Write access protection and Guard control */
    bsp_guard_write_enable(pbg_group);

    /* Initialize all PBG channels that assigned for module */
    while (channels != 0)
    {
        /* Get the next channel to configure */
        channel_num = (uint32_t) BSP_GUARD_GET_BIT(channels);

        /* Get the PBG address */
        p_pbgprot_address =
            (uint32_t *) (g_pbgprot_baseaddress[pbg_group] + (channel_num * BSP_PBG_CHANNEL_ADDRESS_OFFSET));

        if (pgb_enable)
        {
            /* Enable Read, Write access PBG.WG and PBG.RG bits */
            *p_pbgprot_address = (*p_pbgprot_address) | (uint32_t) BSP_PRV_PBG_WRITE_ENABLE;
        }
        else
        {
            /* Disable Write access - PBG.WG bit */
            *p_pbgprot_address = (*p_pbgprot_address) & (uint32_t) ~(BSP_PRV_PBG_WRITE_ENABLE);
        }

        /* Set this channel is configured */
        channels &= ~(1U << channel_num);
    }

    /* Disable Write access protection after the PBG initialization completed */
    bsp_guard_write_disable(pbg_group);
}
