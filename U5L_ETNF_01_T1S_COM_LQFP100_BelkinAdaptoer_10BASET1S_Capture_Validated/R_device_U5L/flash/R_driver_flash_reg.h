/*******************************************************************************
* DISCLAIMER 
* This software is supplied by Renesas Electronics Corporation and is only  
* intended for use with Renesas products. No other uses are authorized. This  
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE  
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. 
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS  
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE  
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software. By using this software, 
* you agree to the additional terms and conditions found by accessing the  
* following link: 
* http://www.renesas.com/disclaimer 
* 
* Copyright (C) 2024 Renesas Electronics Corporation. All rights reserved.     
*******************************************************************************/
/*******************************************************************************
* File Name    : R_driver_flash_reg.h
* Version      : 1.00
* Device(s)    : flash
* Description  : This is source file for flash driver.
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_flash_reg_H__
#define	__R_driver_flash_reg_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"


/*******************************************************************************
* Register Base Address Definitions
*******************************************************************************/
/* Base address of Configuration Setting Area */
#define	CSAf_base	0x40120800	/* front side (for read) */
#define	CSAb_base	0x40121000	/* back side (for programming) */


/*******************************************************************************
* Definition of register symbol
*******************************************************************************/
#define	rSWOPBTn(n) 	(*(volatile uint32_t      *) (CSAf_base + 0x0300 + (n)*0x4) )	/* Software Configuration Option Byte (n = 0 to 31) */
#define	rVECTOR_CPU0	(*(volatile uint32_t      *) (CSAf_base + 0x0380) )          	/* Reset Vector (CPU0) */
#define	rOPBTn(n)   	(*(volatile uint32_t      *) (CSAf_base + 0x03A0 + (n)*0x4) )	/* Option byte n (OPBTn) */
#define	rOPBT0      	(*(volatile OPBT_s_OPBT0  *) (CSAf_base + 0x03A0) )          	/* Option byte 0 (OPBT0) */
#define	rOPBT1      	(*(volatile OPBT_s_OPBT1  *) (CSAf_base + 0x03A4) )          	/* Option byte 1 (OPBT1) */
#define	rOPBT3      	(*(volatile OPBT_s_OPBT3  *) (CSAf_base + 0x03AC) )          	/* Option byte 3 (OPBT3) */
#define	rOPBT4      	(*(volatile OPBT_s_OPBT4  *) (CSAf_base + 0x03B0) )          	/* Option byte 4 (OPBT4) */
#define	rOPBT6      	(*(volatile OPBT_s_OPBT6  *) (CSAf_base + 0x03B8) )          	/* Option byte 6 (OPBT6) */
#define	rOPBT8      	(*(volatile OPBT_s_OPBT8  *) (CSAf_base + 0x03C0) )          	/* Option byte 8 (OPBT8) */
#define	rOPBT10     	(*(volatile OPBT_s_OPBT10 *) (CSAf_base + 0x03C8) )          	/* Option byte 10 (OPBT10) */
#define	rOPBT11     	(*(volatile OPBT_s_OPBT11 *) (CSAf_base + 0x03CC) )          	/* Option byte 11 (OPBT11) */
#define	rOPBT12     	(*(volatile OPBT_s_OPBT12 *) (CSAf_base + 0x03D0) )          	/* Option byte 12 (OPBT12) */
#define	rOPBT13     	(*(volatile OPBT_s_OPBT13 *) (CSAf_base + 0x03D4) )          	/* Option byte 13 (OPBT13) */
#define	rOPBT26     	(*(volatile OPBT_s_OPBT26 *) (CSAf_base + 0x0408) )          	/* Option byte 26 (OPBT26) */
#define	rOPBT27     	(*(volatile OPBT_s_OPBT27 *) (CSAf_base + 0x040C) )          	/* Option byte 27 (OPBT27) */
#define	rOPBT42     	(*(volatile OPBT_s_OPBT42 *) (CSAf_base + 0x0448) )          	/* Option byte 42 (OPBT42) */
#define	rOPBT43     	(*(volatile OPBT_s_OPBT43 *) (CSAf_base + 0x044C) )          	/* Option byte 43 (OPBT43) */
#define	rOPBT44     	(*(volatile OPBT_s_OPBT44 *) (CSAf_base + 0x0450) )          	/* Option byte 44 (OPBT44) */
#define	rOPBT45     	(*(volatile OPBT_s_OPBT45 *) (CSAf_base + 0x0454) )          	/* Option byte 45 (OPBT45) */
#define	rOPBT47     	(*(volatile OPBT_s_OPBT47 *) (CSAf_base + 0x045C) )          	/* Option byte 47 (OPBT47) */


/*******************************************************************************
* Definition of Register bit value
*******************************************************************************/
/* OPBT0.OPWDRUNA: This bit sets the start mode of WDTBA */
typedef enum{
	OPBT0_e_OPWDRUNA_software_trigger = 0,	/* 0: WDTBA software trigger start mode */
	OPBT0_e_OPWDRUNA_default_start    = 1 	/* 1: WDTBA default start mode */
}OPBT0_e_OPWDRUNA;

/* OPBT0.OPWDWMSA: This bit selects Window Open function mode of WDTBA */
typedef enum{
	OPBT0_e_OPWDWMSA_WS   = 0,	/* 0: Window Size of Window Open function is set by WDTBAWS[1:0]. WDTBATIT outputs When the counter reaches 75% of the overflow setting defined by WDTBAMD.WDTBAOVF[2:0] */
	OPBT0_e_OPWDWMSA_WOST = 1 	/* 1: Window Size of Window Open function is set by WDTBAWOST WDTBATIT outputs When WDTBAWIS matches WDT counter. */
}OPBT0_e_OPWDWMSA;

/* OPBT0.OPWDOVFA[29:27]: These bits select the overflow interval time of WDTBA. */
typedef enum{
	OPBT0_e_OPWDOVFA_2_9  = 0,	/* 000B: 2^9/WDTBTCKI */
	OPBT0_e_OPWDOVFA_2_10 = 1,	/* 001B: 2^10/WDTBTCKI */
	OPBT0_e_OPWDOVFA_2_11 = 2,	/* 010B: 2^11/WDTBTCKI */
	OPBT0_e_OPWDOVFA_2_12 = 3,	/* 011B: 2^12/WDTBTCKI */
	OPBT0_e_OPWDOVFA_2_13 = 4,	/* 100B: 2^13/WDTBTCKI */
	OPBT0_e_OPWDOVFA_2_14 = 5,	/* 101B: 2^14/WDTBTCKI */
	OPBT0_e_OPWDOVFA_2_15 = 6,	/* 110B: 2^15/WDTBTCKI */
	OPBT0_e_OPWDOVFA_2_16 = 7 	/* 111B: 2^16/WDTBTCKI */
}OPBT0_e_OPWDOVFA;

/* OPBT0.OPWDINTA: This bit enables or disables a 75% interrupt request of WDTBA (WDTBATIT). */
typedef enum{
	OPBT0_e_OPWDINTA_disable = 0,	/* 0: WDTBATIT disabled */
	OPBT0_e_OPWDINTA_enable  = 1 	/* 1: WDTBATIT enabled */
}OPBT0_e_OPWDINTA;

/* OPBT0.OPWDWSA[24:23]: These bits select the window open period of WDTBA. */
typedef enum{
	OPBT0_e_OPWDWSA_25_per  = 0,	/* 00B: 25% */
	OPBT0_e_OPWDWSA_50_per  = 1,	/* 01B: 50% */
	OPBT0_e_OPWDWSA_75_per  = 2,	/* 10B: 75% */
	OPBT0_e_OPWDWSA_100_per = 3 	/* 11B: 100% */
}OPBT0_e_OPWDWSA;

/* OPBT0.WDTBARES_EN: WDTBA Reset Enable */
typedef enum{
	OPBT0_e_WDTBARES_EN_disable = 1,	/* 1: Enable */
	OPBT0_e_WDTBARES_EN_enable  = 0 	/* 0: Disable */
}OPBT0_e_WDTBARES_EN;

/* OPBT0.OPWDVACA: This bit specifies the trigger register for the generation of counter re-start triggers to keep the counter from overflowing. */
typedef enum{
	OPBT0_e_OPWDVACA_WDTE = 0,	/* 0: WDTBAWDTE (fixed) */
	OPBT0_e_OPWDVACA_EVAC = 1 	/* 1: WDTBAEVAC (variable) */
}OPBT0_e_OPWDVACA;

/* OPBT0.OPWDENA: This bit enables/disables the WDTBA */
typedef enum{
	OPBT0_e_OPWDENA_disable = 0,	/* 0: WDTBA is disabled */
	OPBT0_e_OPWDENA_enable  = 1 	/* 1: WDTBA is enabled */
}OPBT0_e_OPWDENA;

/* OPBT1.OPWDRUN0: This bit sets the start mode of WDTB0. */
typedef enum{
	OPBT1_e_OPWDRUN0_software_trigger = 0,	/* 0: WDTB0 software trigger start mode */
	OPBT1_e_OPWDRUN0_default_start    = 1 	/* 1: WDTB0 default start mode */
}OPBT1_e_OPWDRUN0;

/* OPBT1.OPWDWMS0: This bit selects Window Open function mode of WDTB0 */
typedef enum{
	OPBT1_e_OPWDWMS0_WS   = 0,	/* 0: Window Size of Window Open function is set by WDTB0WS[1:0]. WDTB0TIT outputs When the counter reaches 75% of the overflow setting defined by WDTB0MD.WDTB0OVF[2:0] */
	OPBT1_e_OPWDWMS0_WOST = 1 	/* 1: Window Size of Window Open function is set by WDTB0WOST */
}OPBT1_e_OPWDWMS0;
/* OPBT1.OPWDOVF[22:20]: These bits select the overflow interval time of WDTBn  */
typedef enum{
	OPBT1_e_OPWDOVF_2_9  = 0,	/* 000B: 2^9/WDTBTCKI */
	OPBT1_e_OPWDOVF_2_10 = 1,	/* 001B: 2^10/WDTBTCKI */
	OPBT1_e_OPWDOVF_2_11 = 2,	/* 010B: 2^11/WDTBTCKI */
	OPBT1_e_OPWDOVF_2_12 = 3,	/* 011B: 2^12/WDTBTCKI */
	OPBT1_e_OPWDOVF_2_13 = 4,	/* 100B: 2^13/WDTBTCKI */
	OPBT1_e_OPWDOVF_2_14 = 5,	/* 101B: 2^14/WDTBTCKI */
	OPBT1_e_OPWDOVF_2_15 = 6,	/* 110B: 2^15/WDTBTCKI */
	OPBT1_e_OPWDOVF_2_16 = 7 	/* 111B: 2^16/WDTBTCKI */
}OPBT1_e_OPWDOVF;

/* OPBT1.OPWDINT0: This bit enables or disables interrupt request of WDTB0 (WDTB0TIT). */
typedef enum{
	OPBT1_e_OPWDINT0_disable = 0,	/* 0: WDTB0TIT disabled */
	OPBT1_e_OPWDINT0_enable  = 1 	/* 1: WDTB0TIT enabled */
}OPBT1_e_OPWDINT0;

/* OPBT1.OPWDVAC: This bit specifies the trigger register of WDTB0 for the generation of counter restart triggers to keep the counter from overflowing. */
typedef enum{
	OPBT1_e_OPWDVAC_WDTE = 0,	/* 0: WDTB0WDTE (fixed) */
	OPBT1_e_OPWDVAC_EVAC = 1 	/* 1: WDTB0EVAC (variable) */
}OPBT1_e_OPWDVAC;

/* OPBT1.OPWDWS0[17:16]: Select the window open period of WDTB0 */
typedef enum{
	OPBT1_e_OPWDWS0_25_per  = 0,	/* 00B: 25% */
	OPBT1_e_OPWDWS0_50_per  = 1,	/* 01B: 50% */
	OPBT1_e_OPWDWS0_75_per  = 2,	/* 10B: 75% */
	OPBT1_e_OPWDWS0_100_per = 3 	/* 11B: 100% */
}OPBT1_e_OPWDWS0;

/* OPBT3.STMSEL1: This bit selects operating mode and startup area. */
typedef enum{
	OPBT3_e_STMSEL1_normal_operating_mode   = 0,	/* 0: Normal Operating (Test) Mode is selected */
	OPBT3_e_STMSEL1_serial_programming_mode = 1 	/* 1: Serial Programming (Test) Mode 0 is selected */
}OPBT3_e_STMSEL1;

/* OPBT4.ISOVDDHDE: ISOVDD High voltage detection enable */
typedef enum{
	OPBT4_e_ISOVDDHDE_disable = 0,	/* 0: Disable ISOVDD high voltage detection */
	OPBT4_e_ISOVDDHDE_enable  = 1 	/* 1: Enable ISOVDD high voltage detection */
}OPBT4_e_ISOVDDHDE;

/* OPBT4.ISOVDDLDE: ISOVDD High voltage detection enable */
typedef enum{
	OPBT4_e_ISOVDDLDE_disable = 0,	/* 0: Disable ISOVDD low voltage detection */
	OPBT4_e_ISOVDDLDE_enable  = 1 	/* 1: Enable ISOVDD low voltage detection */
}OPBT4_e_ISOVDDLDE;

/* OPBT8.ETND0_IF_SEL[26:25]: ETND0 MII/RMII/RevMII select */
typedef enum{
	OPBT8_e_ETND0_IF_SEL_MII              = 0,	/* 00: MII */
	OPBT8_e_ETND0_IF_SEL_RMII             = 1,	/* 01: RMII */
	OPBT8_e_ETND0_IF_SEL_setting_prohibit = 2,	/* 10: Prohibited */
	OPBT8_e_ETND0_IF_SEL_RevMII           = 3 	/* 11: RevMII */
}OPBT8_e_ETND0_IF_SEL;

/* OPBT8.CLMA1SEL: Select sampling clock for CLMA1 */
typedef enum{
	OPBT8_e_CLMA1SEL_CLK_MOSC_32 = 0,	/* 0: CLK_MOSC/32 */
	OPBT8_e_CLMA1SEL_CLK_LSIOSC  = 1 	/* 1: CLK_LSIOSC */
}OPBT8_e_CLMA1SEL;

/* OPBT8.RESET_PD_EN: This bit enables or disables Pull-down resistor of RESET pin */
typedef enum{
	OPBT8_e_RESET_PD_EN_disable = 0,	/* 0: Pull-down resistor of RESET: Disable */
	OPBT8_e_RESET_PD_EN_enable  = 1 	/* 1: Pull-down resistor of RESET: Enable */
}OPBT8_e_RESET_PD_EN;

/* OPBT10.MOSC_EXCLKINPUT: Main OSC input clock select. */
typedef enum{
	OPBT10_e_MOSC_EXCLKINPUT_disable = 0,	/* 0: Direct clock input to X1 (EXCLK mode). Main OSC amplifier is disabled. */
	OPBT10_e_MOSC_EXCLKINPUT_enable  = 1 	/* 1: Normal crystal oscillation. Main OSC amplifier is enabled. */
}OPBT10_e_MOSC_EXCLKINPUT;

/* OPBT10.MOSC_FREQ[26:24]: 3'b000: 8MHz */
typedef enum{
	OPBT10_e_MOSC_FREQ_8MHz  = 0,	/* 3'b000: 8MHz */
	OPBT10_e_MOSC_FREQ_16MHz = 1,	/* 3'b001: 16MHz */
	OPBT10_e_MOSC_FREQ_20MHz = 2,	/* 3'b010: 20MHz */
	OPBT10_e_MOSC_FREQ_24MHz = 3 	/* 3'b011: 24MHz */
	                             	/* 3'b1xx: prohibited */
}OPBT10_e_MOSC_FREQ;

/* OPBT10.SOSC_XMSEL: SubOSC oscillation mode selection */
typedef enum{
	OPBT10_e_SOSC_XMSEL_disable = 1,	/* 1: High drive mode */
	OPBT10_e_SOSC_XMSEL_enable  = 0 	/* 0: Standard mode */
}OPBT10_e_SOSC_XMSEL;

/* OPBT10.MOSC_SHTSTBY_A: Main OSC trimming configuration */
typedef enum{
	OPBT10_e_MOSC_SHTSTBY_A_fixed = 1,	/* This bit controls OSC drivability during oscillation destabilization. */
}OPBT10_e_MOSC_SHTSTBY_A;

/* OPBT10.MOSC_SHTSTBY_B: Main OSC trimming configuration */
typedef enum{
	OPBT10_e_MOSC_SHTSTBY_B_fixed = 0,	/* This bit controls OSC drivability during oscillation stabilization. */
}OPBT10_e_MOSC_SHTSTBY_B;

/* OPBT11.CKDIVMD[31:30]: Products of CPU Frequency ＆ CPU System Clock Setting */
typedef enum{
	OPBT11_e_CKDIVMD_120MHz = 0,	/* 0xB: 120 MHz */
	OPBT11_e_CKDIVMD_160MHz = 2,	/* 10B: 160 MHz */
	OPBT11_e_CKDIVMD_240MHz = 3 	/* 11B: 240 MHz(only U5L4 and U5L2) */
}OPBT11_e_CKDIVMD;

/* OPBT11.STARTUPPLL: Start Up of Main OSC and PLL at Power Up */
typedef enum{
	OPBT11_e_STARTUPPLL_disable = 0,	/* 0: Main OSC and PLL are enabled */
	OPBT11_e_STARTUPPLL_enable  = 1 	/* 1: Main OSC and PLL are disabled */
}OPBT11_e_STARTUPPLL;

/* OPBT12.MAPMODE[1:0]: Code Flash Memory Mapping Mode Select */
typedef enum{
	OPBT12_e_MAPMODE_double_map_mode   = 0,	/* 00B: Double Map Mode. */
	OPBT12_e_MAPMODE_signle_map_mode   = 1,	/* 01B: Single Map Mode. */
	OPBT12_e_MAPMODE_setting_prohibit1 = 2,	/* 10B: setting prohibited. */
	OPBT12_e_MAPMODE_setting_prohibit2 = 3 	/* 11B: setting prohibited. */
}OPBT12_e_MAPMODE;

/* OPBT13.DBMAPSW0: Double Map Mode Switching of Cluster 0 */
typedef enum{
	OPBT13_e_DBMAPSW0_double_map_mode = 0,	/* 0: Bank B is mapped in valid area. */
	OPBT13_e_DBMAPSW0_signle_map_mode = 1 	/* 1: Bank A is mapped in valid area. */
}OPBT13_e_DBMAPSW0;

/* OPBT42.ADCK0ENDP: ADCK0 (AD0VDD) Enable bit in DeepSTOP. */
typedef enum{
	OPBT42_e_ADCK0ENDP_disable = 0,	/* 0: ADCK0 Disable. And stop power supply for ADCK0 (AD0VDD). */
	OPBT42_e_ADCK0ENDP_enable  = 1 	/* 1: ADCK0 Enable. */
}OPBT42_e_ADCK0ENDP;

/* OPBT43.OUI1924[31:26]: ETNFn PHY OUI[19:24] */
typedef enum{
	OPBT43_e_OUI1924_fixed = 0x0A 	/* ETNFn PHY OUI[19:24] */
}OPBT43_e_OUI1924;

/* OPBT43.IC_MODEL[25:20]: ETNFn PHY IC_MODEL[5:0] */
typedef enum{
	OPBT43_e_IC_MODEL_fixed = 0x30 	/* ETNFn PHY IC_MODEL[5:0] */
}OPBT43_e_IC_MODEL;

/* OPBT43.IC_REVISION[19:16]: ETNFn PHY IC_REVISION[3:0] */
typedef enum{
	OPBT43_e_IC_REVISION_fixed = 0x1 	/* ETNFn PHY IC_REVISION[3:0] */
}OPBT43_e_IC_REVISION;

/* OPBT43.OUI318[15:0]: ETNFn PHY OUI[3:18] */
typedef enum{
	OPBT43_e_OUI318_fixed = 0xB824 	/* ETNFn PHY OUI[3:18] */
}OPBT43_e_OUI318;

/* OPBT45.GRAM_SIZE: Global RAM Size */
typedef enum{
	OPBT45_e_GRAM_SIZE_704KB = 1,	/* 1: 704KB */
	OPBT45_e_GRAM_SIZE_352KB = 0 	/* 0: 352KB */
}OPBT45_e_GRAM_SIZE;

/* OPBT45.RRAM_SIZE[1:0]: Retention RAM Size */
typedef enum{
	OPBT45_e_RRAM_SIZE_32KB = 3,	/* 11: 32KB M419(for U5L4 and U5L2) */
	OPBT45_e_RRAM_SIZE_16KB = 2,	/* 10: 16KB */
	OPBT45_e_RRAM_SIZE_4KB  = 0 	/* 0x: 4KB */
}OPBT45_e_RRAM_SIZE;

/* OPBT47.DECOME: Life-cycle state setting for decommissioning of microcontroller */
typedef enum{
	OPBT47_e_DECOME_disable = 1,	/* 1: Decommissioning of microcontroller is disabled */
	OPBT47_e_DECOME_enable  = 0 	/* 0: Decommissioning of microcontroller is enabled */
}OPBT47_e_DECOME;

/* OPBT47.FIDE: Fault Injection detection enable/disable */
typedef enum{
	OPBT47_e_FIDE_disable = 0,	/* 0: Fault Injection detection is disabled */
	OPBT47_e_FIDE_enable  = 1 	/* 1: Fault Injection detection is enabled */
}OPBT47_e_FIDE;


/*******************************************************************************
* Definition of Register typedef
*******************************************************************************/
/* OPBT0 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		uint32_t                	OPWDWOSTA      	:16;
		OPBT0_e_OPWDENA         	OPWDENA        	:1;
		uint32_t                	Reserved_17    	:1;
		OPBT0_e_OPWDVACA        	OPWDVACA       	:1;
		uint32_t                	Reserved_19    	:1;
		OPBT0_e_WDTBARES_EN     	WDTBARES_EN    	:1;
		uint32_t                	Reserved_21    	:2;
		OPBT0_e_OPWDWSA         	OPWDWSA        	:2;
		uint32_t                	Reserved_25    	:1;
		OPBT0_e_OPWDINTA        	OPWDINTA       	:1;
		OPBT0_e_OPWDOVFA        	OPWDOVFA       	:3;
		OPBT0_e_OPWDWMSA        	OPWDWMSA       	:1;
		OPBT0_e_OPWDRUNA        	OPWDRUNA       	:1;
	}BIT;
}OPBT_s_OPBT0;

/* OPBT1 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		uint32_t                	OPWDWISA       	:16;
		OPBT1_e_OPWDWS0         	OPWDWS0        	:2;
		OPBT1_e_OPWDVAC         	OPWDVAC        	:1;
		OPBT1_e_OPWDINT0        	OPWDINT0       	:1;
		OPBT1_e_OPWDOVF         	OPWDOVF        	:3;
		OPBT1_e_OPWDWMS0        	OPWDWMS0       	:1;
		OPBT1_e_OPWDRUN0        	OPWDRUN0       	:1;
		uint32_t                	Reserved_25    	:7;
	}BIT;
}OPBT_s_OPBT1;

/* OPBT3 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		uint32_t                	Reserved_0     	:1;
		OPBT3_e_STMSEL1         	STMSEL1        	:1;
		uint32_t                	Reserved_2     	:30;
	}BIT;
}OPBT_s_OPBT3;

/* OPBT4 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		uint32_t                	Reserved_0     	:24;
		OPBT4_e_ISOVDDLDE       	ISOVDDLDE      	:1;
		OPBT4_e_ISOVDDHDE       	ISOVDDHDE      	:1;
		uint32_t                	Reserved_26    	:6;
	}BIT;
}OPBT_s_OPBT4;

/* OPBT5 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		uint32_t                	Reserved_0     	:8;
		uint32_t                	ISOVDDFLTW     	:7;
		uint32_t                	Reserved_15    	:17;
	}BIT;
}OPBT_s_OPBT5;

/* OPBT6 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		uint32_t                	Reserved_0     	:23;
		uint32_t                	OSC_USERTRM    	:9;
	}BIT;
}OPBT_s_OPBT6;

/* OPBT8 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		uint32_t                	Reserved_0     	:1;
		OPBT8_e_RESET_PD_EN     	RESET_PD_EN    	:1;
		uint32_t                	Reserved_2     	:20;
		OPBT8_e_CLMA1SEL        	CLMA1SEL       	:1;
		uint32_t                	Reserved_23    	:2;
		OPBT8_e_ETND0_IF_SEL    	ETND0_IF_SEL   	:2;
		uint32_t                	Reserved_27    	:5;
	}BIT;
}OPBT_s_OPBT8;

/* OPBT10 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		OPBT10_e_MOSC_SHTSTBY_B 	MOSC_SHTSTBY_B 	:1;
		OPBT10_e_MOSC_SHTSTBY_A 	MOSC_SHTSTBY_A 	:1;
		OPBT10_e_SOSC_XMSEL     	SOSC_XMSEL     	:1;
		uint32_t                	Reserved_3     	:1;
		uint32_t                	MOSC_RD_SEL_B  	:2;
		uint32_t                	Reserved_6     	:2;
		uint32_t                	MOSC_RD_SEL_A  	:2;
		uint32_t                	Reserved_10    	:6;
		uint32_t                	MOSC_AMP_SEL_B 	:3;
		uint32_t                	Reserved_19    	:1;
		uint32_t                	MOSC_AMP_SEL_A 	:3;
		uint32_t                	Reserved_23    	:1;
		OPBT10_e_MOSC_FREQ      	MOSC_FREQ      	:3;
		uint32_t                	Reserved_27    	:1;
		OPBT10_e_MOSC_EXCLKINPUT	MOSC_EXCLKINPUT	:1;
		uint32_t                	Reserved_29    	:3;
	}BIT;
}OPBT_s_OPBT10;

/* OPBT11 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		uint32_t                	Reserved_0     	:4;
		uint32_t                	Reserved_4     	:7;
		uint32_t                	Reserved_11    	:1;
		uint32_t                	Reserved_12    	:3;
		uint32_t                	Reserved_15    	:13;
		OPBT11_e_STARTUPPLL     	STARTUPPLL     	:1;
		uint32_t                	Reserved_29    	:1;
		OPBT11_e_CKDIVMD        	CKDIVMD        	:2;
	}BIT;
}OPBT_s_OPBT11;

/* OPBT12 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		OPBT12_e_MAPMODE        	MAPMODE        	:2;
		uint32_t                	Reserved_2     	:30;
	}BIT;
}OPBT_s_OPBT12;

/* OPBT13 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		OPBT13_e_DBMAPSW0       	DBMAPSW0       	:1;
		uint32_t                	Reserved_1     	:31;
	}BIT;
}OPBT_s_OPBT13;

/* OPBT26 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		uint32_t                	OPWDWOST0      	:16;
		uint32_t                	Reserved_16    	:16;
	}BIT;
}OPBT_s_OPBT26;

/* OPBT27 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		uint32_t                	OPWDWIS0       	:16;
		uint32_t                	Reserved_16    	:16;
	}BIT;
}OPBT_s_OPBT27;

/* OPBT42 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		uint32_t                	Reserved_0     	:16;
		OPBT42_e_ADCK0ENDP      	ADCK0ENDP      	:1;
		uint32_t                	Reserved_17    	:15;
	}BIT;
}OPBT_s_OPBT42;

/* OPBT43 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		OPBT43_e_OUI318         	OUI318         	:16;
		OPBT43_e_IC_REVISION    	IC_REVISION    	:4;
		OPBT43_e_IC_MODEL       	IC_MODEL       	:6;
		OPBT43_e_OUI1924        	OUI1924        	:6;
	}BIT;
}OPBT_s_OPBT43;

/* OPBT44 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		uint32_t                	RESV0_CRUN     	:32;
	}BIT;
}OPBT_s_OPBT44;

/* OPBT45 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		OPBT45_e_RRAM_SIZE      	RRAM_SIZEb     	:2; 	/* Changed the bit name because it overlaps with the definition indicating the size of Retention RAM. */
		uint32_t                	Reserved_2     	:14;
		OPBT45_e_GRAM_SIZE      	GRAM_SIZEb     	:1; 	/* Changed the bit name because it overlaps with the definition indicating the size of Global RAM. */
		uint32_t                	Reserved_17    	:15;
	}BIT;
}OPBT_s_OPBT45;

/* OPBT47 register */
typedef union{
		uint32_t                	UINT32;
	struct{
		OPBT47_e_FIDE           	FIDE           	:1;
		uint32_t                	Reserved_1     	:15;
		OPBT47_e_DECOME         	DECOME         	:1;
		uint32_t                	Reserved_17    	:15;
	}BIT;
}OPBT_s_OPBT47;


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_flash_reg_H__ */

