/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_FEATURE_H
#define BSP_FEATURE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/* BSP */
#if defined(BSP_MCU_R7F711001EBFC) || defined(BSP_MCU_R7F711002EBFC)
 #define BSP_FEATURE_SUB_OSC_IS_AVAILABLE                  (0U)
#else
 #define BSP_FEATURE_SUB_OSC_IS_AVAILABLE                  (1U)
#endif

#if defined(BSP_MCU_R7F711001EBBB) || defined(BSP_MCU_R7F711001EBFA) || defined(BSP_MCU_R7F711001EBFC) || \
    defined(BSP_MCU_R7F711001EBFP)
 #define BSP_FEATURE_CANXL_IS_AVAILABLE                    (1U)
 #define BSP_FEATURE_ETHTSN_IS_AVAILABLE                   (1U)
 #define BSP_FEATURE_T1S_IS_AVAILABLE                      (0U)

#else
 #define BSP_FEATURE_CANXL_IS_AVAILABLE                    (0U)
 #define BSP_FEATURE_ETHTSN_IS_AVAILABLE                   (1U)
 #define BSP_FEATURE_T1S_IS_AVAILABLE                      (1U)
#endif

#define BSP_FEATURE_PSI5_IS_AVAILABLE                      (1U)
#define BSP_FEATURE_MMCA_IS_AVAILABLE                      (1U)
#define BSP_FEATURE_SFMA_IS_AVAILABLE                      (1U)

#define BSP_FEATURE_BSP_HAS_SP_MON                         (0U) /*  Indicate feature Stack Monitor for FreeRTOS */

#define BSP_FEATURE_DEVICE_HAS_INTERRUPT_MERGE             (1U)

#define BSP_FEATURE_MODULE_STANDBY_IS_AVAILABLE            (1U)

#define BSP_FEATURE_MDLC_IS_AVAILABLE                      (0U)
#define BSP_FEATURE_COREID_AVAILABLE                       (0U)

#define BSP_FEATURE_CLOCK_PLLINS_AVAILABLE                 (1U)

#define BSP_FEATURE_CLOCK_EXTCLK1S_AVAILABLE               (0U)

#define BSP_FEATURE_CLOCK_SPIX2_AVAILABLE                  (0U)

#define BSP_FEATURE_GUARD_IS_AVAILABLE                     (1U)

#define BSP_FEATURE_GUARD_GROUP_PE_IS_AVAILABLE            (0U)

/* I3C */
#define BSP_FEATURE_I3C_MAX_DEV_COUNT                      (8U)
#define BSP_FEATURE_I3C_MSTP_OFFSET                        (4U)
#define BSP_FEATURE_I3C_NTDTBP0_DEPTH                      (8U)
#define BSP_FEATURE_I3C_NUM_CHANNELS                       (1U)
#define BSP_FEATURE_BSP_HAS_I3C_CLOCK                      (0UL)    /*  Indicates there is a separate clock for the I3C. */
#define BSP_FEATURE_IIC_B_VALID_CHANNEL_MASK               (0x01UL) /*  Mask of available IIC_B or compatible I3C channels. */
#define BSP_FEATURE_IIC_B_FAST_MODE_PLUS                   (0x01UL) /*  Mask of channels which support "Fast Mode Plus": up to 1 Mbps bit rates. */

/* OSTM */
#define BSP_FEATURE_OSTM_VALID_CHANNEL_MASK                (0x1FU)

/* CANFD */
#if defined(BSP_MCU_R7F711001EBFC) || defined(BSP_MCU_R7F711002EBFC)
 #define BSP_FEATURE_CANFD_NUM_CHANNELS                    (4UL)                 /* Number of CANFD channel on this MCU */
#else
 #define BSP_FEATURE_CANFD_NUM_CHANNELS                    (6UL)                 /* Number of CANFD channel on this MCU */
#endif

#define BSP_FEATURE_CANFD_NUM_UNITS                        (1UL)                 /* Number of CANFD Unit on this MCU */
#define BSP_FEATURE_CANFD_NUM_RXFIFO                       (8UL)                 /* Number of CANFD RX FIFO on this MCU */
#define BSP_FEATURE_CANFD_NUM_CFIFO_ALL                    (18UL)                /* Number of all CANFD CFIFO on this MCU */
#define BSP_FEATURE_CANFD_NUM_CFIFO_CHANNEL                (3UL)                 /* Number of CANFD CFIFO channel on this MCU */
#define BSP_FEATURE_CANFD_NUM_TXQUEUE_CHANNEL              (4UL)                 /* Number of CANFD TXQUEUE channel on this MCU */
#define BSP_FEATURE_CANFD_CLKC_SRC                         (FSP_PRIV_CLOCK_P080) /* CANFD CLKC clock source on this MCU */

/* CANXL */
#if defined(BSP_MCU_R7F711001EBBB) || defined(BSP_MCU_R7F711001EBFA) || defined(BSP_MCU_R7F711001EBFC) || \
    defined(BSP_MCU_R7F711001EBFP)
 #define BSP_FEATURE_CANXL_NUM_CHANNELS                    (2UL) /* Number of CANXL channel on this MCU */
#else
 #define BSP_FEATURE_CANXL_NUM_CHANNELS                    (0UL) /* Number of CANXL channel on this MCU */
#endif

/* PSI5 */
#define BSP_FEATURE_PSI5_NUM_SLOTS_EACH_UNIT               (8U)  /* Number of PSI5 slot of each unit on this MCU */

/* DMAC */
#define BSP_FEATURE_DMAC_MAX_CHANNEL                       (8U)  /* Number of DMAC channel on this MCU */
#define BSP_FEATURE_DMAC_MAX_UNIT                          (2U)  /* Number of DMAC unit on this MCU */

/* DWT */
#define BSP_FEATURE_DWT_CYCCNT                             (0U)  /* Feature is not supported on this MCU */

/* IIC */
#define BSP_FEATURE_IIC_VALID_CHANNEL_MASK                 (0x3) /* The Mask is used to check valid IIC channel */

/* PWM */
#if defined(BSP_MCU_R7F711001EBBB) || defined(BSP_MCU_R7F711002EBBB)
 #define BSP_FEATURE_PWM_DIAG_NUM_OF_CHANNEL               (96U) /* Number of PWM DIAG PWGC channel on this MCU */
#elif defined(BSP_MCU_R7F711001EBFA) || defined(BSP_MCU_R7F711002EBFA)
 #define BSP_FEATURE_PWM_DIAG_NUM_OF_CHANNEL               (64U) /* Number of PWM DIAG PWGC channel on this MCU */
#elif defined(BSP_MCU_R7F711002EBFA) || defined(BSP_MCU_R7F711002EBFC)
 #define BSP_FEATURE_PWM_DIAG_NUM_OF_CHANNEL               (48U) /* Number of PWM DIAG PWGC channel on this MCU */
#elif defined(BSP_MCU_R7F711001EBFP) || defined(BSP_MCU_R7F711002EBFP)
 #define BSP_FEATURE_PWM_DIAG_NUM_OF_CHANNEL               (72U) /* Number of PWM DIAG PWGC channel on this MCU */
#endif

/* DTSC */
#define BSP_FEATURE_DTSC_MAX_CHANNEL                       (8U)  /* Number of DTSC channel on this MCU */

/* SSI */
#define BSP_FEATURE_SSI_FIFO_NUM_STAGES                    (32U) /* Number of I2S FIFO stages on this MCU */

/* RSENT */
#define BSP_FEATURE_RSENT_SENT_NUM_OF_UNIT                 (8U)  /* Number of RSENT units on this MCU */
#define BSP_FEATURE_RSENT_SENT_HAS_SPCSEL_DUAL_REGISTER    (0U)  /* Has single RSENTSPCSEL register */

/* CSIH */
#if defined(BSP_MCU_R7F711001EBBB) || defined(BSP_MCU_R7F711002EBFP) || defined(BSP_MCU_R7F711001EBFP) || \
    defined(BSP_MCU_R7F711002EBBB)
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT               (8U) /* Number of chip select signal of CSIH */
 #define BSP_FEATURE_CSIH_MAX_UNIT                         (8U) /*  Number of unit of CSIH */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_0        (4U) /*  Number of chip select on unit 0 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_1        (4U) /*  Number of chip select on unit 1 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_2        (4U) /*  Number of chip select on unit 2 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_3        (4U) /*  Number of chip select on unit 3 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_4        (4U) /*  Number of chip select on unit 4 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_5        (4U) /*  Number of chip select on unit 5 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_6        (4U) /*  Number of chip select on unit 6 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_7        (4U) /*  Number of chip select on unit 7 */
#elif defined(BSP_MCU_R7F711001EBFA) || defined(BSP_MCU_R7F711002EBFA)
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT               (8U) /* Number of chip select signal of CSIH */
 #define BSP_FEATURE_CSIH_MAX_UNIT                         (6U) /*  Number of unit of CSIH */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_0        (4U) /*  Number of chip select on unit 0 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_1        (4U) /*  Number of chip select on unit 1 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_2        (4U) /*  Number of chip select on unit 2 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_3        (4U) /*  Number of chip select on unit 3 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_4        (4U) /*  Number of chip select on unit 4 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_5        (4U) /*  Number of chip select on unit 5 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_6        (0U) /*  Number of chip select on unit 6 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_7        (0U) /*  Number of chip select on unit 7 */
#elif defined(BSP_MCU_R7F711001EBFC) || defined(BSP_MCU_R7F711002EBFC)
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT               (8U) /* Number of chip select signal of CSIH */
 #define BSP_FEATURE_CSIH_MAX_UNIT                         (4U) /*  Number of unit of CSIH */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_0        (4U) /*  Number of chip select on unit 0 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_1        (4U) /*  Number of chip select on unit 1 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_2        (4U) /*  Number of chip select on unit 2 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_3        (4U) /*  Number of chip select on unit 3 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_4        (0U) /*  Number of chip select on unit 4 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_5        (0U) /*  Number of chip select on unit 5 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_6        (0U) /*  Number of chip select on unit 6 */
 #define BSP_FEATURE_CSIH_NUMBER_CHIP_SELECT_UNIT_7        (0U) /*  Number of chip select on unit 7 */
#endif

/* CXPI */
#if defined(BSP_MCU_R7F711001EBBB) || defined(BSP_MCU_R7F711002EBBB)
 #define BSP_FEATURE_CXPI_NUM_CHANNELS                     (4U) // Number of CXPI channel on this MCU
#else
 #define BSP_FEATURE_CXPI_NUM_CHANNELS                     (2U) // Number of CXPI channel on this MCU
#endif

/* RLIN3 */
#if defined(BSP_MCU_R7F711001EBBB) || defined(BSP_MCU_R7F711002EBBB)
 #define BSP_FEATURE_R_RLIN3_LIN_MAX_CHANNEL               (18U)
#elif defined(BSP_MCU_R7F711001EBFC) || defined(BSP_MCU_R7F711002EBFC)
 #define BSP_FEATURE_R_RLIN3_LIN_MAX_CHANNEL               (14U)
#elif defined(BSP_MCU_R7F711001EBFA) || defined(BSP_MCU_R7F711002EBFA) || defined(BSP_MCU_R7F711001EBFP) || \
    defined(BSP_MCU_R7F711002EBFP)
 #define BSP_FEATURE_R_RLIN3_LIN_MAX_CHANNEL               (16U)
#endif

/* CRC */
#define BSP_FEATURE_CRC_NUM_OF_UNIT                        (8U)

/* IIC */
#define BSP_FEATURE_IIC_HAS_FMPE                           (0UL) // Indicates the FMPE bit is available in IIC.
#define BSP_FEATURE_IIC_B_HAS_FMPLUS                       (0UL) // Indicates the FMPLUS bit is available in I3C.
#define BSP_FEATURE_IIC_HAS_IMF_ISR                        (0UL) /* Indicates the IMF ISR is available in IIC */

/* PSI5 */
#define BSP_FEATURE_PSI5_MAX_CHANNEL                       (2U)  /* Number of PSI5 channel on this MCU */
#define BSP_FEATURE_PSI5_WP_IS_AVAILABLE                   (1U)  /* Indicates the wrapper function is available in PSI5 */
#define BSP_FEATURE_PSI5_HAS_IMF_ISR                       (0U)  /* Indicates the IMF ISR is available in PSI5 */

/* ADCK */
#if defined(BSP_MCU_R7F711001EBBF) || defined(BSP_MCU_R7F711001EBBB) || defined(BSP_MCU_R7F711001EBFP) || \
    defined(BSP_MCU_R7F711001EBFA) || defined(BSP_MCU_R7F711002EBBF) || defined(BSP_MCU_R7F711002EBBB) || \
    defined(BSP_MCU_R7F711002EBFP) || defined(BSP_MCU_R7F711002EBFA)
 #define BSP_FEATURE_ADCK_NUM_OF_UNIT                      (2U)
#else
 #define BSP_FEATURE_ADCK_NUM_OF_UNIT                      (1U)
#endif

#define BSP_FEATURE_STBC_MSRKCPROT                         (1U)

/* CLMA */
#define BSP_FEATURE_CLMA_PLLIN_AVAILABLE                   (1U)  /* Register PLLIN is available on this device */
#define BSP_FEATURE_CLMA_MAX_CHANNELS                      (5U)  ///< Maximum CLMA channels

/* CGC */
#define BSP_FEATURE_CGC_PLLIN_AVAILABLE                    (1U)  /* Register PLLIN is available on this device */
#define BSP_FEATURE_CGC_CLKKCPROT6_AVAILABLE               (0U)  /* Register CLKKCPROT6 is available on this device */
#define BSP_FEATURE_CGC_NUM_OF_REPETITIONS                 (7U)  /* Number of repetitions for system clock gear up/down */

/* ECM */
#define BSP_FEATURE_ECM_INT_CONFIG_MULTIPLE_REG            (0U)  /* Indicates that only register ECMINCFG in this device. */
#define BSP_FEATURE_ECM_INSTANCE                           (3U)  /* ECM feature instance */
#define BSP_FEATURE_ECM_ERROR_SOURCE_CHECK_VALID           (79U) /* Maximum ECM error source index supported */
#define BSP_FEATURE_ECM_ERROR_OUTPUT_TRIGGER_VALID         (0U)  /* Indicates that only register ECMETMK in this device. */
#define BSP_FEATURE_ECM_CHECKER_VALID                      (0U)  /* Indicates that only ECM Checker in this device. */

/* VMON */
#define BSP_FEATURE_VMON_SUPPLY_POWER_AVAILABLE            (0U)
#define BSP_FEATURE_VMON00_FC_ENABLE                       (12U)
#define BSP_FEATURE_VMON00_DMASK_ENABLE                    (32U)
#define BSP_FEATURE_VMON00_RESET_DMASK_ENABLE              (0U)

/* ICU */
#define BSP_FEATURE_ICU_CHANNEL_NMI_ADDRESS                (0U)

/* ETHT1S */
#define BSP_FEATURE_ETHT1S_NUM_CHANNELS                    (1U)

/* ETH TSN */
#define BSP_FEATURE_ETH_TSN_NUM_CHANNELS                   (1U)

/** FLASH */
#define BSP_FEATURE_FLASH_CF_WRITE_SIZE                    (512U)        ///< Code flash minimum write size in bytes
#define BSP_FEATURE_FLASH_CF_REGION0_BLOCK_SIZE            (0x4000U)     ///< Small CF block size: 16 KB
#define BSP_FEATURE_FLASH_CF_REGION1_BLOCK_SIZE            (0x10000U)    ///< Large CF block size: 64 KB
#define BSP_FEATURE_FLASH_CF_REGION0_SIZE                  (0x00020000U) ///< Region 0 total size: 128 KB (8 x 16 KB)
#define BSP_FEATURE_FLASH_CF_BLANK_CHECK_AREA_START        (0x0C000000U) ///< Code Flash Blank Check Area base address

#define BSP_FEATURE_FLASH_CF_BANK_A_START                  (0x00000000U) ///< Bank A start address
#define BSP_FEATURE_FLASH_CF_BANK_A_SIZE                   (0x00200000U) ///< Bank A size: 2 MB
#define BSP_FEATURE_FLASH_CF_BANK_B_START                  (0x00400000U) ///< Bank B start address
#define BSP_FEATURE_FLASH_CF_BANK_B_SIZE                   (0x00200000U) ///< Bank B size: 2 MB

#define BSP_FEATURE_FLASH_CODE_FLASH_START                 (0x00000000U) ///< Code flash start address
#define BSP_FEATURE_FLASH_DF_BLOCK_SIZE                    (0x1000U)     ///< Data flash block (erase unit): 4 KB
#define BSP_FEATURE_FLASH_DF_WRITE_SIZE                    (4U)          ///< Data flash minimum write size in bytes

#define BSP_FEATURE_FLASH_DATA_FLASH_AREA0_START           (0x40000000U) ///< Data Area 0 start (FPSYS0)
#define BSP_FEATURE_FLASH_DATA_FLASH_AREA0_SIZE            (0x40000U)    ///< Data Area 0 size: 256 KB
#define BSP_FEATURE_FLASH_DATA_FLASH_AREA2_START           (0x400C0000U) ///< Data Area 2 start (FPSYS2) - RSIP-M30 only
#define BSP_FEATURE_FLASH_DATA_FLASH_AREA2_SIZE            (0x10000U)    ///< Data Area 2 size: 64 KB - RSIP-M30 only

/* FACI0 command-issuing area base address (R-Car U5L Flash HW manual Table 4.1: 5C42 0000H).
 * Not modeled as a peripheral in the device SVD; accessed via direct address. */
#define BSP_FEATURE_FLASH_FACI0_CMD_AREA                   (0x5C420000U) ///< FACI0 command-issuing area

/* R-Car U5L contains only FPSYS0 and FPSYS2 (no FPSYS1). */
#define BSP_FEATURE_FLASH_FHVE_HAS_FPSYS1                  (0U)          ///< No third flash sequencer (FPSYS1)

#endif
