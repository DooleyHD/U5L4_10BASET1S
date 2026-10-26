/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_ECM_H
#define BSP_ECM_H

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** ECM Trigger Factor */
typedef enum e_ecm_trigger_source
{
    ECM_TRIGGER_SOURCE_ESET                    = (2),  ///< ECMmESET monitor, status ECMmESET.ECMmEST writing.
    ECM_TRIGGER_SOURCE_DMT_OVF                 = (11), ///< Delay timer overflow for Error output.
    ECM_TRIGGER_SOURCE_MODE_ERR                = (24), ///< Mode error:  Detected unexpected mode.
    ECM_TRIGGER_SOURCE_FLASH_ACCESS            = (25), ///< Flash access error.
    ECM_TRIGGER_SOURCE_FACI_RST_TRANSFER       = (26), ///< FACI reset transfer error.
    ECM_TRIGGER_SOURCE_CLMA0_MOSC              = (27), ///< Clock monitor error for CLK_MOSC.
    ECM_TRIGGER_SOURCE_CLMA1_HSIOSC            = (28), ///< Clock monitor error for CLK_HSIOSC.
    ECM_TRIGGER_SOURCE_CLMA2_LSIOSC            = (29), ///< Clock monitor error for CLK_LSIOSC.
    ECM_TRIGGER_SOURCE_CLMA3_BUS4              = (30), ///< Clock monitor error for CLK_BUS4.
    ECM_TRIGGER_SOURCE_CLMA8_P040              = (31), ///< Clock monitor error for CLK_P040.
    ECM_TRIGGER_SOURCE_CLMAS_RSIP              = (32), ///< Clock monitor error for CLK_BUS2 /2 (RSIP clock).
    ECM_TRIGGER_SOURCE_OSTM1_INT               = (33), ///< OS timer 1 interrupt.
    ECM_TRIGGER_SOURCE_OSTM2_INT               = (34), ///< OS timer 2 interrupt.
    ECM_TRIGGER_SOURCE_OSTM3_INT               = (35), ///< OS timer 3 interrupt.
    ECM_TRIGGER_SOURCE_OSTM4_INT               = (36), ///< OS timer 4 interrupt.
    ECM_TRIGGER_SOURCE_CANXL_INT               = (37), ///< CANXL safety relevant interrupt.
    ECM_TRIGGER_SOURCE_ADC_PARITY              = (38), ///< A/D converter parity error.
    ECM_TRIGGER_SOURCE_TEMPERATURE             = (39), ///< Temperature sensor error.
    ECM_TRIGGER_SOURCE_CODE_FLASH_ECC_2B       = (40), ///< Code Flash Data ECC 2-bit error.
    ECM_TRIGGER_SOURCE_DATA_FLASH_ECC_2B       = (41), ///< Data Flash Data ECC 2-bit error.
    ECM_TRIGGER_SOURCE_CODE_FLASH_ECC_1B       = (42), ///< Code Flash data ECC 1-bit error.
    ECM_TRIGGER_SOURCE_DATA_FLASH_ECC_1B       = (43), ///< Data Flash data ECC 1-bit error.
    ECM_TRIGGER_SOURCE_CODE_ECC_OVF            = (44), ///< Code Flash ECC error address buffer overflow error.
    ECM_TRIGGER_SOURCE_DATA_ECC_OVF            = (45), ///< Data Flash ECC error address buffer overflow error.
    ECM_TRIGGER_SOURCE_GLOBAL_RAM_ECC_2B       = (46), ///< Global/Retention RAM - Data ECC 2-bit error.
    ECM_TRIGGER_SOURCE_GLOBAL_RAM_ECC_1B       = (47), ///< Global/Retention RAM - Data ECC 1-bit error.
    ECM_TRIGGER_SOURCE_GLOBAL_RAM_ECC_OVF      = (48), ///< Global/Retention RAM - ECC overflow error.
    ECM_TRIGGER_SOURCE_DTSRAM_ECC_2B           = (49), ///< DTSRAM - Data ECC 2-bit error.
    ECM_TRIGGER_SOURCE_DTSRAM_ECC_1B           = (50), ///< DTSRAM - Data ECC 1-bit error.
    ECM_TRIGGER_SOURCE_DTSRAM_ECC_OVF          = (51), ///< DTSRAM - ECC overflow error.
    ECM_TRIGGER_SOURCE_PERIPH_RAM_ECC_2B       = (52), ///< Peripheral RAM Data ECC 2-bit error.
    ECM_TRIGGER_SOURCE_PERIPH_RAM_ECC_1B       = (53), ///< Peripheral RAM Data ECC 1-bit error.
    ECM_TRIGGER_SOURCE_PERIPH_RAM_ECC_OVF      = (54), ///< Peripheral RAM - ECC overflow error.
    ECM_TRIGGER_SOURCE_GLOBAL_RAM_GUARD        = (55), ///< GLRG error/RRG error.
    ECM_TRIGGER_SOURCE_CPU_RAM_GUARD           = (56), ///< CPURAMG error.
    ECM_TRIGGER_SOURCE_PERIPH_GUARD            = (57), ///< Peripheral Guard error.
    ECM_TRIGGER_SOURCE_HS_PERIPH_GUARD         = (58), ///< High Speed Peripheral Guard.
    ECM_TRIGGER_SOURCE_DTS_DMAC_TRANS          = (59), ///< DTS transfer Error/pDMAC  Transfer error .
    ECM_TRIGGER_SOURCE_H_BUS_MASTER_TRANS      = (60), ///< H-Bus master Transfer Error .
    ECM_TRIGGER_SOURCE_EXT_ERR_IN              = (61), ///< External Error Input.
    ECM_TRIGGER_SOURCE_SW_ALARM0               = (62), ///< Software Alarm 0.
    ECM_TRIGGER_SOURCE_SEC_GUARD               = (63), ///< Security Guard Error.
    ECM_TRIGGER_SOURCE_SEC_MASTER_DIRECT_TRANS = (64), ///< Security Master Direct Transfer  Error.
    ECM_TRIGGER_SOURCE_SEC_MASTER_ECC_2B       = (65), ///< Security master internal RAM ECC 2-bit error.
    ECM_TRIGGER_SOURCE_SEC_MASTER_ECC_1B       = (66), ///< Security master internal RAM ECC 1-bit error.
    ECM_TRIGGER_SOURCE_FID_ERR                 = (67), ///< FID (Fault Injection Detector) Error.
    ECM_TRIGGER_SOURCE_SEC_PERIPH_RAM_ECC_2B   = (68), ///< Security peripheral RAM ECC 2-bit error.
    ECM_TRIGGER_SOURCE_SEC_PERIPH_RAM_ECC_1B   = (69), ///< Security peripheral RAM ECC 1-bit error.
    ECM_TRIGGER_SOURCE_DUP_FF                  = (70), ///< Duplicating FF Error.
    ECM_TRIGGER_SOURCE_SEC_MASTER_C_BUS_ACCESS = (71), ///< Security Master C-BUS Access Error.
    ECM_TRIGGER_SOURCE_SEC_MASTER_BUFF_ACCESS  = (72), ///< Security Master Bufferable access error.
    ECM_TRIGGER_SOURCE_DEBUG_EN_UNINTENDED     = (73), ///< Unintended Debug Enable detection.
    ECM_TRIGGER_SOURCE_WDT0                    = (74), ///< Watchdog timer error.
    ECM_TRIGGER_SOURCE_CPU_RAM_ECC_2B          = (75), ///< CPU RAM - Data ECC 2-bit error.
    ECM_TRIGGER_SOURCE_CPU_RAM_ECC_1B          = (76), ///< CPU RAM - Data ECC 1-bit error.
    ECM_TRIGGER_SOURCE_CPU_ECC_OVF             = (77), ///< CPU RAM - ECC overflow error.
    ECM_TRIGGER_SOURCE_CPU0_EDC                = (78), ///< Instruction cache RAM (CPU0) - Data EDC error.
    ECM_TRIGGER_SOURCE_DATA_ACCESS             = (79), ///< Data access errors.
} ecm_trigger_source_t;

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

#endif                                 /* BSP_ECM_H */
