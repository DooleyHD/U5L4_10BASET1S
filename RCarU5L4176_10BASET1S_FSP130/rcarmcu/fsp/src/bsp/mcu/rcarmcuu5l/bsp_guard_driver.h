/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_GUARD_DRIVER_H
#define BSP_GUARD_DRIVER_H

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/*******************************************************************************************************************//**
 * @addtogroup BSP_MCU_RCARMCUU5L
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define BSP_GUARD_MAX_TYPE_ACCESS_REQUEST_STATUS    (uint8_t) 0x04U

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

typedef enum e_bsp_pbg_group
{
    BSP_PBG_GROUP_000 = 0,
    BSP_PBG_GROUP_010,
    BSP_PBG_GROUP_011,
    BSP_PBG_GROUP_012,
    BSP_PBG_GROUP_020,
    BSP_PBG_GROUP_030,
    BSP_PBG_GROUP_040,
    BSP_PBG_GROUP_041,
    BSP_PBG_GROUP_042,
    BSP_PBG_GROUP_050,
    BSP_PBG_GROUP_060,
    BSP_PBG_GROUP_070,
    BSP_PBG_GROUP_080,
    BSP_PBG_GROUP_090,
    BSP_PBG_GROUP_100,
    BSP_PBG_GROUP_101,
    BSP_PBG_GROUP_110,
    BSP_HBG_GROUP_080,
    BSP_HBG_GROUP_081,
    BSP_HBG_GROUP_082,
    BSP_PBG_GROUP_NUM
} bsp_pbg_group_t;

typedef enum e_bsp_ibg_group
{
    BSP_IBG_GROUP_00 = 0,
    BSP_IBG_GROUP_10,
    BSP_IBG_GROUP_11,
    BSP_IBG_GROUP_NUM
} bsp_ibg_group_t;

typedef enum e_bsp_module_pbg_index
{
    BSP_MODULE_PBG_INDEX_ADC = 0,
    BSP_MODULE_PBG_INDEX_BSP,
    BSP_MODULE_PBG_INDEX_CANFD,
#if (BSP_FEATURE_CANXL_IS_AVAILABLE)
    BSP_MODULE_PBG_INDEX_CANXL,
#endif
    BSP_MODULE_PBG_INDEX_CLMA,
    BSP_MODULE_PBG_INDEX_CSIH,
    BSP_MODULE_PBG_INDEX_CRC,
    BSP_MODULE_PBG_INDEX_CXPI,
    BSP_MODULE_PBG_INDEX_DMA,
    BSP_MODULE_PBG_INDEX_DTS,
    BSP_MODULE_PBG_INDEX_ECM,
    BSP_MODULE_PBG_INDEX_ENCA,
#if (BSP_FEATURE_T1S_IS_AVAILABLE)
    BSP_MODULE_PBG_INDEX_ETHT1S,
#endif
#if (BSP_FEATURE_ETHTSN_IS_AVAILABLE)
    BSP_MODULE_PBG_INDEX_ETHTSN,
#endif                                 /* #if (BSP_FEATURE_ETHTSN_IS_AVAILABLE) */
    BSP_MODULE_PBG_INDEX_I2C,
    BSP_MODULE_PBG_INDEX_I3C,
    BSP_MODULE_PBG_INDEX_IOPORT,
#if (BSP_FEATURE_MMCA_IS_AVAILABLE)
    BSP_MODULE_PBG_INDEX_MMCA,
#endif                                 /* #if (BSP_FEATURE_MMCA_IS_AVAILABLE) */
    BSP_MODULE_PBG_INDEX_OSTM,
    BSP_MODULE_PBG_INDEX_PIC,
#if (BSP_FEATURE_PSI5_IS_AVAILABLE)
    BSP_MODULE_PBG_INDEX_PSI5,
#endif                                 /* #if (BSP_FEATURE_PSI5_IS_AVAILABLE) */
    BSP_MODULE_PBG_INDEX_PWMDIAG,
    BSP_MODULE_PBG_INDEX_RLIN,
    BSP_MODULE_PBG_INDEX_RSENT,
    BSP_MODULE_PBG_INDEX_RTCA,
#if (BSP_FEATURE_SFMA_IS_AVAILABLE)
    BSP_MODULE_PBG_INDEX_SFMA,
#endif                                 /* #if (BSP_FEATURE_SFMA_IS_AVAILABLE) */
    BSP_MODULE_PBG_INDEX_SSIF,
    BSP_MODULE_PBG_INDEX_TAPA,
    BSP_MODULE_PBG_INDEX_TAUD,
    BSP_MODULE_PBG_INDEX_TAUJ,
    BSP_MODULE_PBG_INDEX_TSN,
    BSP_MODULE_PBG_INDEX_VMON,
    BSP_MODULE_PBG_INDEX_WDT,
    BSP_MODULE_PBG_INDEX_END
} bsp_module_pbg_index_t;

/* Guard control register types */
typedef enum e_bsp_guard_reg
{
    BSP_GUARD_REG_PROT = 0,            // Protection control register
    BSP_GUARD_REG_RGID,                // SPID setting register
} bsp_guard_reg_t;

/* Guard enable setting */
typedef enum e_bsp_guard_setting
{
    BSP_GUARD_SETTING_DISABLE = 0,     // Disable guard setting
    BSP_GUARD_SETTING_ENABLE  = 1,     // Enable guard setting
} bsp_guard_setting_t;

/* Guard debug access control */
typedef enum e_bsp_guard_debug
{
    BSP_GUARD_DEBUG_DEPENDS = 0,       // R/W depends on other protection settings
    BSP_GUARD_DEBUG_ENABLE  = 1        // R/W enabled for debug master
} bsp_guard_debug_t;

/* Guard user mode access control */
typedef enum e_bsp_guard_um
{
    BSP_GUARD_UM_DISABLE = 0,          // Disable user mode access (R/W)
    BSP_GUARD_UM_ENABLE  = 1           // Enable user mode access (R/W depends on protection settings)
} bsp_guard_um_t;

/* Guard write access control */
typedef enum e_bsp_guard_write
{
    BSP_GUARD_WRITE_USE_SPID  = 0,     // Write uses SPID check (SPID is used as judgment condition)
    BSP_GUARD_WRITE_ALLOW_ALL = 1      // Write allows all (SPID is NOT used as judgment condition)
} bsp_guard_write_t;

/* Guard read access control */
typedef enum e_bsp_guard_read
{
    BSP_GUARD_READ_USE_SPID  = 0,      // Read uses SPID check (SPID is used as judgment condition)
    BSP_GUARD_READ_ALLOW_ALL = 1       // Read allows all (SPID is NOT used as judgment condition)
} bsp_guard_read_t;

/* Guard secure access control */
typedef enum e_bsp_guard_secure
{
    BSP_GUARD_SECURE_DISABLE = 0,      // R/W disabled for non-secure master
    BSP_GUARD_SECURE_ENABLE  = 1,      // R/W depends on other protection settings
} bsp_guard_secure_t;

/* Guard lock setting control */
typedef enum e_bsp_guard_lock
{
    BSP_GUARD_LOCK_DISABLE = 0,        // Allow re-configure protect setting rewrite
    BSP_GUARD_LOCK_ENABLE  = 1,        // Block further writes until reset
} bsp_guard_lock_t;

/* PBG/HBG guard protection configuration */
typedef struct st_bsp_pbg_protection_setting
{
    /* Bus group target: Specifies which PBG or HBG group to protect */
    bsp_pbg_group_t group;

    /* Specifies which channel number within PBG group */
    uint8_t channel;

    /* Protection Control setting */
    union
    {
        struct
        {
            bsp_guard_read_t  read_global     : 1; // Read Global enable
            bsp_guard_write_t write_global    : 1; // Write Global enable
            uint32_t                          : 5;
            bsp_guard_secure_t  secure_master : 1; // Secure Master setting
            bsp_guard_setting_t guard_enable  : 1; // Guard Enable: Disable
            uint32_t                          : 22;
            bsp_guard_lock_t lock             : 1; // Lock Prevents modification when set
        }        protect_setting_b;                // Protection attribute setting
        uint32_t protect_setting;                  // Direct access to all protection control settings
    };

    uint32_t rgid;                                 // Rgids permitted to access this region
} bsp_pbg_protection_setting_t;

/* Guard protection setting structure for all guard types. Use the appropriate member based on the target guard module. */
typedef struct st_bsp_guard_protection_setting
{
    /* Guard module-specific protection settings */
    union
    {
        /* Peripheral Bus Guard settings */
        bsp_pbg_protection_setting_t pbusgrd_setting;
    } slave_guard_protection;
} bsp_guard_protection_setting_t;

/* Guard protection setting structure for xram guard types.*/
typedef struct st_bsp_r_rrgrd_ctl_xram_rrg_type
{
    union
    {
        __IOM uint32_t PROT;           /* Channel protection control register */

        struct
        {
            __IOM uint32_t RG  : 1;    /* Read Global Enable */
            __IOM uint32_t WG  : 1;    /* Write Global Enable */
            uint32_t           : 6;
            __IOM uint32_t GEN : 1;    /* Enables/disables guard setting */
            uint32_t           : 23;
        } PROT_b;
    };

    union
    {
        __IOM uint32_t RGID;           /* Channel RGID setting register */

        struct
        {
            __IOM uint32_t RGID : 32;  /* R/W enable setting by RGID */
        } RGID_b;
    };

    union
    {
        __IOM uint32_t BAD;            /* Channel base address setting register */

        struct
        {
            uint32_t           : 8;
            __IOM uint32_t BAD : 12;   /* Base address */
            uint32_t           : 12;
        } BAD_b;
    };

    union
    {
        __IOM uint32_t ADV;            /* Channel address valid bit setting register */

        struct
        {
            uint32_t           : 8;
            __IOM uint32_t ADV : 12;   /* Valid bits of CRGBADv */
            uint32_t           : 12;
        } ADV_b;
    };
    __IM uint32_t RESERVED[4];
} bsp_r_rrgrd_ctl_xram_rrg_type_t;

/* XRAM entry number definition */
typedef enum e_bsp_xram_entry_number
{
    BSP_XRG_ENTRY_NUMBER_0 = 0,
    BSP_XRG_ENTRY_NUMBER_1,
    BSP_XRG_ENTRY_NUMBER_2,
    BSP_XRG_ENTRY_NUMBER_3,
    BSP_XRG_ENTRY_NUMBER_4,
    BSP_XRG_ENTRY_NUMBER_5,
    BSP_XRG_ENTRY_NUMBER_6,
    BSP_XRG_ENTRY_NUMBER_7,
    BSP_XSG_ENTRY_NUMBER_0,
    BSP_XSG_ENTRY_NUMBER_1,
    BSP_XSG_ENTRY_NUMBER_2,
    BSP_XSG_ENTRY_NUMBER_3,
    BSP_XSG_ENTRY_NUMBER_NUM
} bsp_xram_entry_number_t;

/* XRAM memory type definition */
typedef enum e_bsp_xram_memory_type
{
    BSP_GUARD_PROTECTION_CPU_RAM,
    BSP_GUARD_PROTECTION_GLOBAL_RAM,
    BSP_GUARD_PROTECTION_RETENTION_RAM,
    BSP_GUARD_PROTECTION_RAM_NUM
} bsp_xram_memory_type_t;

/* Protection control structure */
typedef struct st_bsp_channel_protection_control
{
    /* Guard RGID Setting Register - R/W enable setting by RGID */
    uint32_t rgid_setting;

    /* Guard Protection Control Register */
    /* Read Global Enable */
    uint8_t enable_read_global : 1;

    /* Write Global Enable */
    uint8_t enable_write_global : 1;

    /* Enables/disables guard setting */
    uint8_t enable_guard_setting : 1;

    /* Guard Base Address Setting Register */
    uint32_t guard_base_address : 12;

    /* Guard Address Valid Bit Setting */
    uint32_t valid_bit_setting : 12;
} bsp_channel_protection_control_t;

/* XRAM protection error status */
typedef enum e_xram_protection_error_status
{
    BSP_RAM_GUARD_PROTECTION_STATUS_NORMAL  = 0,
    BSP_RAM_GUARD_PROTECTION_ERROR_OCCURRED = 1,
    BSP_RAM_GUARD_PROTECTION_ERROR_OVERFLOW = 2
} bsp_xram_protection_error_status_t;

/* Guard error access type */
typedef enum e_bsp_guard_err_access
{
    BSP_GUARD_ERROR_ACCESS_READ  = 0,
    BSP_GUARD_ERROR_ACCESS_WRITE = 1
} bsp_guard_err_access_t;

/* Guard protection error information for one access type */
typedef struct st_bsp_ram_protection_status
{
    /* Guard Error Overflow */
    bsp_xram_protection_error_status_t errstatus;

    /* Guard Error Address */
    uint32_t err_access_address;

    /* Guard Error Access Information */
    uint16_t               err_attribute;
    bsp_guard_err_access_t err_type_access;
} bsp_ram_protection_status_t;

/* XRAM protection status for all access request types */
typedef struct st_bsp_xram_protection_status
{
    /*
     * [0] = IH: Fetch access request for odd words
     * [1] = IL: Fetch access request for even words
     * [2] = DH: Data access request for odd words
     * [3] = DL: Data access request for even words
     */
    bsp_ram_protection_status_t xram_status[BSP_GUARD_MAX_TYPE_ACCESS_REQUEST_STATUS];
} bsp_xram_protection_status_t;

/* XRAM Guard Capability Register block */
typedef struct st_bsp_r_xrgd_cap_rramnn_type
{
    union
    {
        __IOM uint32_t XRGOVFCLR;      /* Guard Error Overflow Clear Register */

        struct
        {
            uint32_t           : 1;
            __OM uint32_t CLRO : 1;    /* Clear the CRGOVFSTAT.OVF bit by writing 1. */
            uint32_t           : 30;
        } XRGOVFCLR_b;
    };

    union
    {
        union
        {
            __IM uint32_t XRGOVFSTAT;  /* Guard Error Overflow Status Register */

            struct
            {
                uint32_t          : 1;
                __IM uint32_t OVF : 1; /* Overflow status flag */
                uint32_t          : 30;
            } XRGOVFSTAT_b;
        };
        __IM uint32_t XRGOVFSTATHH;    /* Guard Error Overflow Status Register */
        __IM uint32_t XRGOVFSTATHL;    /* Guard Error Overflow Status Register */
        __IM uint32_t XRGOVFSTATLH;    /* Guard Error Overflow Status Register */
        __IM uint32_t XRGOVFSTATLL;    /* Guard Error Overflow Status Register */
    };

    __IM uint32_t XRGERRADDR;          /* Guard Error Address Register */

    union
    {
        __IM uint32_t XRGERRTYPE;      /* Guard Error Access Information Register */

        struct
        {
            __IM uint32_t WRITE : 1;   /* Access type of read or write to the target slave when a guard error occurred */
            uint32_t            : 5;
            __IM uint32_t RGID  : 5;   /* Access attribute of RGID to the target slave when a guard error occurred */
            uint32_t            : 21;
        } XRGERRTYPE_b;
    };

    __OM uint32_t XRGRGIDERRCLR;       /* Guard Error RGID Error Clear Register */
    __IM uint32_t XRGRGIDERRSTAT;      /* Guard Error RGID Error Status Register */
    __IM uint32_t RESERVED[2];
} bsp_r_xrgd_cap_rramnn_type;

/* Properties of a PBG module including group and channel information */
typedef struct st_bsp_module_pbg_properties
{
    bsp_pbg_group_t pbg_group;         // Guard group
    uint32_t        pbg_channel;       // Guard channel, bit position indicate the channel.
} bsp_module_pbg_properties_t;

/* PBG module info */
typedef struct st_bsp_module_pbg_info
{
    uint8_t no_of_element;                    // Number of elements in this PBG module
    uint8_t initial_cfg_value;                // Initial configuration value for access control
    bsp_module_pbg_properties_t * properties; // Pointer to module PBG property table
} bsp_module_pbg_info_t;

/* IBG group infor definition */
typedef struct st_bsp_module_ibg_info
{
    bsp_ibg_group_t ibg_group;         // Guard group
    uint16_t        channel;           // Guard channel, bit position indicate the channel.
} bsp_module_igb_info_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/
extern const uint32_t              g_pbgprot_baseaddress[BSP_PBG_GROUP_NUM];
extern const uint32_t              g_pbgkcprot_baseaddress[BSP_PBG_GROUP_NUM];
extern const bsp_module_pbg_info_t g_bsp_module_pbg_info_table[BSP_MODULE_PBG_INDEX_END];
extern const uint32_t              g_xram_guard_protection_baseaddress[BSP_GUARD_PROTECTION_RAM_NUM][
    BSP_XSG_ENTRY_NUMBER_NUM];
extern const uint32_t              g_xram_guard_protection_status_baseaddress[BSP_GUARD_PROTECTION_RAM_NUM];
extern const uint32_t              g_xram_guard_protection_register_baseaddress[BSP_GUARD_PROTECTION_RAM_NUM];
extern const uint32_t              g_igbprot_baseaddress[BSP_IBG_GROUP_NUM];
extern const uint32_t              g_ibg_protection_register_baseaddress[BSP_IBG_GROUP_NUM];
extern const bsp_module_igb_info_t g_xram_ibg_protection[BSP_GUARD_PROTECTION_RAM_NUM];

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

/** @} (end addtogroup BSP_MCU_RCARMCUU5L) */

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif                                 /** End of BSP_GUARD_DRIVER_H */
