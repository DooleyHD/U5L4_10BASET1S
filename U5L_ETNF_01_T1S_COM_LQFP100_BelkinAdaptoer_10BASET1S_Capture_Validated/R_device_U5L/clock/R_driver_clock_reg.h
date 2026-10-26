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
* File Name    : R_driver_clock_reg.h
* Version      : 1.00
* Module(s)    : Cslock controller
* Device(s)    : R-Car U5L product
* Description  : Register definition of clock controller for R-Car U5L
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_clock_reg_H__
#define	__R_driver_clock_reg_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"


/*******************************************************************************
* Register Base Address Definitions
*******************************************************************************/
/* no definition */


/*******************************************************************************
* Definition of register symbol
*******************************************************************************/
/* Clock Oscillator Registers - PLL, SSCG *************************************/
#define	rPLLE             	(*(volatile CLK_s_PLLE              *) (0x5C080000) )	/* PLL Enable Register */
#define	rPLLS             	(*(volatile CLK_s_PLLS              *) (0x5C080004) )	/* PLL Status Register */
#define	rCKS_PLLINC       	(*(volatile CLK_s_CKS_PLLINC        *) (0x5C080010) )	/* PLL Input Clock Selector Control Register */
#define	rCKS_PLLINS       	(*(volatile CLK_s_CKS_PLLINS        *) (0x5C080014) )	/* PLL Input Clock Selector Status Register */
#define	rSSCGC            	(*(volatile CLK_s_SSCGC             *) (0x5C08002C) )	/* SSCG Control Register */

/* Clock Oscillator Registers - Main OSC **************************************/
#define	rMOSCE            	(*(volatile CLK_s_MOSCE             *) (0x5C088000) )	/* Main OSC Enable Register */
#define	rMOSCS            	(*(volatile CLK_s_MOSCS             *) (0x5C088004) )	/* Main OSC Status Register */
#define	rMOSCSTPM         	(*(volatile CLK_s_MOSCSTPM          *) (0x5C08800C) )	/* Main OSC Stop Mask Register */

/* Clock Oscillator Registers - Sub OSC ***************************************/
#define	rSOSCE            	(*(volatile CLK_s_SOSCE             *) (0x5C088020) )	/* Sub OSC Enable Register */
#define	rSOSCS            	(*(volatile CLK_s_SOSCS             *) (0x5C088024) )	/* Sub OSC Status Register */
#define	rSOSCST           	(*(volatile CLK_s_SOSCST            *) (0x5C088028) )	/* Sub OSC Stabilization Time Register */

/* Clock Oscillator Registers - HS IntOSC *************************************/
#define	rHSOSCS           	(*(volatile CLK_s_HSOSCS            *) (0x5C088100) )	/* HS IntOSC Status Register */
#define	rHSOSCSTPM        	(*(volatile CLK_s_HSOSCSTPM         *) (0x5C088104) )	/* HS IntOSC Stop Mask Register */
#define	rHSOSCUSERTRMPRODC	(*(volatile CLK_s_HSOSCUSERTRMPRODC *) (0x5C080080) )	/* HS IntOSC User Trimming Period Control Register */
#define	rHSOSCUSERTRMEN   	(*(volatile CLK_s_HSOSCUSERTRMEN    *) (0x5C080084) )	/* HS IntOSC User Trimming Function Enable Register */
#define	rHSOSCUSERTRMS    	(*(volatile CLK_s_HSOSCUSERTRMS     *) (0x5C080088) )	/* HS IntOSC User Trimming Status Register */
#define	rHSOSCUSERTRMCNT  	(*(volatile CLK_s_HSOSCUSERTRMCNT   *) (0x5C08008C) )	/* HS IntOSC User Trimming Counter Register */
#define	rHSOSCUSERTRMSET  	(*(volatile CLK_s_HSOSCUSERTRMSET   *) (0x5C088148) )	/* HS IntOSC User Trimming Code Set Register */

/* Clock Selector/Divider Control Registers - System Clock (CLK_SYS1) *********/
#define	rCKS_SYS1C        	(*(volatile CLK_s_CKS_SYS1C         *) (0x5C080100) )	/* CLK_SYS1 Selector Control Register */
#define	rCKS_SYS1S        	(*(volatile CLK_s_CKS_SYS1S         *) (0x5C080108) )	/* CLK_SYS1 Selector Status Register */

/* Clock Selector/Divider Control Registers - System Clock (CLK_SYS0) *********/
#define	rCKS_SYS0C        	(*(volatile CLK_s_CKS_SYS0C         *) (0x5C080110) )	/* CLK_SYS0 Selector Control Register */
#define	rCKS_SYS0S        	(*(volatile CLK_s_CKS_SYS0S         *) (0x5C080114) )	/* CLK_SYS0 Selector Status Register */

/* Clock Selector/Divider Control Registers - PLL1 Clock (CLK_PLL1O) **********/
#define	rCKD_PLL1C        	(*(volatile CLK_s_CKD_PLL1C         *) (0x5C080120) )	/* CLK_PLL1O Divider Control Register */
#define	rCKD_PLL1S        	(*(volatile CLK_s_CKD_PLL1S         *) (0x5C080128) )	/* CLK_PLL1O Divider Status Register */

/* Clock Selector/Divider Control Registers - PLL0 Clock (CLK_PLL0O) **********/
#define	rCKD_PLL0C        	(*(volatile CLK_s_CKD_PLL0C         *) (0x5C080130) )	/* CLK_PLL0O Divider Control Register */
#define	rCKD_PLL0S        	(*(volatile CLK_s_CKD_PLL0S         *) (0x5C080134) )	/* CLK_PLL0O Divider Status Register */

/* Clock Selector/Divider Control Registers - RLIN Clock (CLK_RLIN3) **********/
#define	rCKS_RLINC        	(*(volatile CLK_s_CKS_RLINC         *) (0x5C080140) )	/* CLK_RLIN3 Selector Control Register */
#define	rCKS_RLINS        	(*(volatile CLK_s_CKS_RLINS         *) (0x5C080148) )	/* CLK_RLIN3 Selector Status Register */

/* Clock Selector/Divider Control Registers - RTCA Clock (CLK_RTCA) ***********/
#define	rCKS_ARTCAC       	(*(volatile CLK_s_CKS_ARTCAC        *) (0x5C088220) )	/* CLK_RTCA Selector Control Register */
#define	rCKS_ARTCAS       	(*(volatile CLK_s_CKS_ARTCAS        *) (0x5C088228) )	/* CLK_RTCA Selector Status Register */

/* Clock Selector/Divider Control Registers - ADCK0 Clock (CLK_ADC0) **********/
#define	rCKS_AADCC        	(*(volatile CLK_s_CKS_AADCC         *) (0x5C088230) )	/* CLK_ADC0 Selector Control Register */
#define	rCKS_AADCS        	(*(volatile CLK_s_CKS_AADCS         *) (0x5C088238) )	/* CLK_ADC0 Selector Status Register */

/* Clock Selector/Divider Control Registers - EXTCLK0 Clock (EXTCLK0O) ********/
#define	rCKS_EXTCLK0C     	(*(volatile CLK_s_CKS_EXTCLK0C      *) (0x5C088250) )	/* EXTCLK0 Clock Selector Control Register */
#define	rCKS_EXTCLK0S     	(*(volatile CLK_s_CKS_EXTCLK0S      *) (0x5C088258) )	/* EXTCLK0 Clock Selector Status Register */
#define	rCKD_EXTCLK0C     	(*(volatile CLK_s_CKD_EXTCLK0C      *) (0x5C088260) )	/* EXTCLK0 Clock Divider Control Register */
#define	rCKD_EXTCLK0S     	(*(volatile CLK_s_CKD_EXTCLK0S      *) (0x5C088268) )	/* EXTCLK0 Clock Divider Status Register */

/* Clock Selector/Divider Control Registers - EXTCLK1 Clock (EXTCLK1O) ********/
#define	rCKS_EXTCLK1C     	(*(volatile CLK_s_CKS_EXTCLK1C      *) (0x5C080600) )	/* EXTCLK1 Clock Selector Control Register */
#define	rCKS_EXTCLK1S     	(*(volatile CLK_s_CKS_EXTCLK1S      *) (0x5C080608) )	/* EXTCLK1 Clock Selector Status Register */
#define	rCKD_EXTCLK1C     	(*(volatile CLK_s_CKD_EXTCLK1C      *) (0x5C080610) )	/* EXTCLK1 Clock Divider Control Register */
#define	rCKD_EXTCLK1S     	(*(volatile CLK_s_CKD_EXTCLK1S      *) (0x5C080618) )	/* EXTCLK1 Clock Divider Status Register */

/* Clock Selector/Divider Control Registers - LPS Clock (CLK_LPS) *************/
#define	rCKS_ALPSC        	(*(volatile CLK_s_CKS_ALPSC         *) (0x5C088310) )	/* CLK_LPS Selector Control Register */
#define	rCKS_ALPSS        	(*(volatile CLK_s_CKS_ALPSS         *) (0x5C088318) )	/* CLK_LPS Selector Status Register */

/* Protection Register ********************************************************/
#define	rCLKKCPROT1       	(*(volatile CLK_s_CLKKCPROT1        *) (0x5C080700) )	/* Clock Controller Register Key Code Protection Register 1 */
#define	rCLKKCPROT4       	(*(volatile CLK_s_CLKKCPROT4        *) (0x5C080730) )	/* Clock Controller Register Key Code Protection Register 4 */


/*******************************************************************************
* Definition of Register bit value
*******************************************************************************/
/* PLLS.PLLCLKSTAB: PLL0/1 clock stable state */
/* MOSCS.MOSCSTAB: Main OSC stable state */
/* SOSCS.SOSCSTAB: Sub OSC stable state */
/* HSOSCS.HSOSCSTAB: HS IntOSC clock stable State */
typedef enum{
	CLK_e_STAB_unstable = 0,	/* 0: PLL0/1 clock are unstable. */
	CLK_e_STAB_stable   = 1 	/* 1: PLL0/1 clock are stable. */
}CLK_e_STAB;

/* PLLS.PLLCLKEN: PLL0/1 clock enable state */
/* MOSCS.MOSCEN: Main OSC enable state */
/* SOSCS.SOSCEN: Sub OSC enable state */
typedef enum{
	CLK_e_EN_DISTRG_1 = 0,	/* 0: PLLE.PLLDISTRG is set to 1. */
	CLK_e_EN_ENTRG_1  = 1 	/* 1: PLLE.PLLENTRG is set to 1. */
}CLK_e_EN;

/* CKS_PLLINC.PLLINSCSID: SYS0_CLOCK source control */
/* CKS_PLLINC.PLLINSACT: SYS0_CLOCK source status for CLK_PLLIN */
typedef enum{
	CLK_e_PLLIN_CLK_MOSC   = 0,	/* ID = 0: CLK_MOSC (default) */
	CLK_e_PLLIN_CLK_HSIOSC = 1 	/* ID = 1: CLK_HSIOSC */
}CLK_e_PLLIN;

/* SSCGC.SSMODE1: SSCG Control */
typedef enum{
	CLK_e_SSMODE1_disable = 0,	/* 0: Modulation disabled */
	CLK_e_SSMODE1_enable  = 1 	/* 1: Modulation enabled */
}CLK_e_SSMODE1;

/* SSCGC.SELMFREQ[4:0]: The modulation frequency (Fpfd=8) */
typedef enum{
	CLK_e_SELMFREQ_FPDF8_58_8MHz = 0x08,	/* 1000B: 58.8MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_52_6MHz = 0x09,	/* 1001B: 52.6MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_50_0MHz = 0x0A,	/* 1010B: 50.0MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_45_5MHz = 0x0B,	/* 1011B: 45.5MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_40_0MHz = 0x0C,	/* 1100B: 40.0MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_35_7MHz = 0x0D,	/* 1101B: 35.7MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_34_5MHz = 0x0E,	/* 1110B: 34.5MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_33_3MHz = 0x0F,	/* 1111B: 33.3MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_32_3MHz = 0x10,	/* 10000B: 32.3MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_30_3MHz = 0x11,	/* 10001B: 30.3MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_27_8MHz = 0x12,	/* 10010B: 27.8MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_26_3MHz = 0x13,	/* 10011B: 26.3MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_25_0MHz = 0x14,	/* 10100B: 25.0MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_23_8MHz = 0x15,	/* 10101B: 23.8MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_23_3MHz = 0x16,	/* 10110B: 23.3MHz when Fpdf = 8 */
	CLK_e_SELMFREQ_FPDF8_20_0MHz = 0x17 	/* 10111B: 20.0MHz when Fpdf = 8 */
}CLK_e_SELMFREQ_FPDF8;

/* SSCGC.SELMFREQ[4:0]: The modulation frequency (Fpfd=10) */
typedef enum{
	CLK_e_SELMFREQ_FPDF10_56_8MHz = 0x0B,	/* 1011B: 56.8MHz when Fpdf = 10 */
	CLK_e_SELMFREQ_FPDF10_50_0MHz = 0x0C,	/* 1100B: 50.0MHz when Fpdf = 10 */
	CLK_e_SELMFREQ_FPDF10_44_6MHz = 0x0D,	/* 1101B: 44.6MHz when Fpdf = 10 */
	CLK_e_SELMFREQ_FPDF10_43_1MHz = 0x0E,	/* 1110B: 43.1MHz when Fpdf = 10 */
	CLK_e_SELMFREQ_FPDF10_41_7MHz = 0x0F,	/* 1111B: 41.7MHz when Fpdf = 10 */
	CLK_e_SELMFREQ_FPDF10_40_3MHz = 0x10,	/* 10000B: 40.3MHz when Fpdf = 10 */
	CLK_e_SELMFREQ_FPDF10_37_9MHz = 0x11,	/* 10001B: 37.9MHz when Fpdf = 10 */
	CLK_e_SELMFREQ_FPDF10_34_7MHz = 0x12,	/* 10010B: 34.7MHz when Fpdf = 10 */
	CLK_e_SELMFREQ_FPDF10_32_9MHz = 0x13,	/* 10011B: 32.9MHz when Fpdf = 10 */
	CLK_e_SELMFREQ_FPDF10_31_3MHz = 0x14,	/* 10100B: 31.3MHz when Fpdf = 10 */
	CLK_e_SELMFREQ_FPDF10_29_8MHz = 0x15,	/* 10101B: 29.8MHz when Fpdf = 10 */
	CLK_e_SELMFREQ_FPDF10_29_1MHz = 0x16,	/* 10110B: 29.1MHz when Fpdf = 10 */
	CLK_e_SELMFREQ_FPDF10_25_0MHz = 0x17,	/* 10111B: 25.0MHz when Fpdf = 10 */
	CLK_e_SELMFREQ_FPDF10_20_8MHz = 0x18 	/* 11000B: 20.8MHz when Fpdf = 10 */
}CLK_e_SELMFREQ_FPDF10;

/* SSCGC.SELMPERCENT: SSCG Modulation dithered range control */
typedef enum{
	CLK_e_SELMPERCENT_down_1_per = 0,	/* 000B: -1.0% */
	CLK_e_SELMPERCENT_down_2_per = 1,	/* 001B: -2.0% */
	CLK_e_SELMPERCENT_down_3_per = 2,	/* 010B: -3.0% */
	CLK_e_SELMPERCENT_down_4_per = 3,	/* 011B: -4.0% */
	CLK_e_SELMPERCENT_down_5_per = 4 	/* 100B: -5.0% */
	                                 	/* Setting other than the above is prohibited. */
}CLK_e_SELMPERCENT;

/* MOSCSTPM.MOSCSTPMSK: Main OSC Stop Request Mask */
/* HSOSCSTPM.HSOSCSTPMSK: HS IntOSC Stop Request Mask */
typedef enum{
	CLK_e_STPMSK_stop_clock   = 0,	/* 0: Main OSC stops operation in chip standby mode. */
	CLK_e_STPMSK_supply_clock = 1 	/* 1: Main OSC continues operation in chip standby mode. */
}CLK_e_STPMSK;

/* HSOSCUSERTRMPRODC.PROD: Frequency measurement period */
typedef enum{
	CLK_e_PROD_50us  = 2,	/* 10: 50us */
	CLK_e_PROD_100us = 3 	/* 11: 100us */
/* Setting other than the above is prohibited. */
}CLK_e_PROD;

/* HSOSCUSERTRMS.TRMST: Trimming Status */
typedef enum{
	CLK_e_TRMST_end      = 0,	/* 0: End of trimming count */
	CLK_e_TRMST_progress = 1 	/* 1: During trimming count */
}CLK_e_TRMST;

/* CKS_SYS1C.SYSCLKSCSID: SYS0_CLOCK source control */
/* CKS_SYS1S.SYSCLKSACT: SYS0_CLOCK source status for CLK_SYS1 */
typedef enum{
	CLK_e_SYS1_CLK_PLL1O = 0,	/* ID = 0: CLK_PLL1O */
	CLK_e_SYS1_CLK_IOSC1 = 1 	/* ID = 1: CLK_IOSC1 (default) */
}CLK_e_SYS1;

/* CKS_SYS0C.SYSCLKSCSID: SYS0_CLOCK source control */
/* CKS_SYS0S.SYSCLKSACT: SYS0_CLOCK source status for CLK_SYS0 */
typedef enum{
	CLK_e_SYS0_CLK_PLL0O = 0,	/* ID = 0: CLK_PLL0O */
	CLK_e_SYS0_CLK_IOSC1 = 1 	/* ID = 1: CLK_IOSC1 (default) */
}CLK_e_SYS0;

/* CKD_PLL1C.PLLCLKDCSID[3:0]: SYS0_CLOCK Divider control */
/* CKD_PLL0C.PLLCLKDCSID[3:0]: SYS0_CLOCK Divider control */
typedef enum{
	CLK_e_PLLCLKDCSID_no_div = 0,	/* 0000B: No division (default) */
	CLK_e_PLLCLKDCSID_1_16   = 1,	/* 0001B: Divided by 1/16 (DIV16) */
	CLK_e_PLLCLKDCSID_2_16   = 2,	/* 0010B: Divided by 2/16 (DIV8) */
	CLK_e_PLLCLKDCSID_3_16   = 3,	/* 0011B: Divided by 3/16 */
	CLK_e_PLLCLKDCSID_4_16   = 4,	/* 0100B: Divided by 4/16 (DIV4) */
	CLK_e_PLLCLKDCSID_5_16   = 5,	/* 0101B: Divided by 5/16 */
	CLK_e_PLLCLKDCSID_6_16   = 6,	/* 0110B: Divided by 6/16 */
	CLK_e_PLLCLKDCSID_7_16   = 7,	/* 0111B: Divided by 7/16 */
	CLK_e_PLLCLKDCSID_8_16   = 8,	/* 1000B: Divided by 8/16 (DIV2) */
	CLK_e_PLLCLKDCSID_9_16   = 9,	/* 1001B: Divided by 9/16 */
	CLK_e_PLLCLKDCSID_10_16  = 10,	/* 1010B: Divided by 10/16 */
	CLK_e_PLLCLKDCSID_11_16  = 11,	/* 1011B: Divided by 11/16 */
	CLK_e_PLLCLKDCSID_12_16  = 12,	/* 1100B: Divided by 12/16 */
	CLK_e_PLLCLKDCSID_13_16  = 13,	/* 1101B: Divided by 13/16 */
	CLK_e_PLLCLKDCSID_14_16  = 14,	/* 1110B: Divided by 14/16 */
	CLK_e_PLLCLKDCSID_15_16  = 15 	/* 1111B: Divided by 15/16 */
}CLK_e_PLLCLKDCSID;

/* CKD_PLL1S.PLLCLKDSYNC: Divider clock synchronized */
/* CKD_PLL0S.PLLCLKDSYNC: Divider clock synchronized */
typedef enum{
	CLK_e_CLKDSYNC_not_sync = 0,	/* 0: SYS0_CLOCK output does not correspond to the actual divisor setting in CKD_PLL1C.PLLCLKDCSID */
	CLK_e_CLKDSYNC_sync     = 1 	/* 1: SYS0_CLOCK output corresponds to the actual divisor setting in CKD_PLL1C.PLLCLKDCSID */
}CLK_e_CLKDSYNC;

/* CKS_RLINC.RLINSCSID[1:0]: SYS0_CLOCK source control */
/* CKS_RLINS.RLINSACT[1:0]: SYS0_CLOCK source status for CLK_RLIN3 */
typedef enum{
	CLK_e_RLIN_CLK_IOSC0     = 0,	/* ID = 00B: CLK_IOSC0 (default) */
	CLK_e_RLIN_CLK_P080      = 1,	/* ID = 01B: CLK_P080 */
	CLK_e_RLIN_CLK_MOSC      = 2,	/* ID = 10B: CLK_MOSC */
	CLK_e_RLIN_CLK_MOSC_4MHz = 3 	/* ID = 11B: 4MHz with CLK_MOSC */
}CLK_e_RLIN;

/* CKS_ARTCAC.ARTCASCSID[1:0]: SYS0_CLOCK source control */
/* CKS_ARTCAS.ARTCASACT[1:0]: SYS0_CLOCK source status for CLK_RTCA */
typedef enum{
	CLK_e_ARTCA_CLK_IOSC0  = 0,	/* ID = 00B: CLK_IOSC0 (default) */
	CLK_e_ARTCA_CLK_LSIOSC = 1,	/* ID = 01B: CLK_LSIOSC */
	CLK_e_ARTCA_CLK_SOSC   = 2 	/* ID = 10B: CLK_SOSC */
}CLK_e_ARTCA;

/* CKS_AADCC.AADCSCSID[1:0]: SYS0_CLOCK source control */
/* CKS_AADCS.AADCSACT[1:0]: SYS0_CLOCK source status for CLK_ADC0 */
typedef enum{
	CLK_e_AADC_CLK_IOSC0    = 0,	/* ID = 00B: CLK_IOSC0 (default) */
	CLK_e_AADC_CLK_P040     = 1,	/* ID = 01B: CLK_P040 */
	CLK_e_AADC_CLK_HSIOSC_2 = 2 	/* ID = 10B: CLK_HSIOSC/2 */
}CLK_e_AADC;

/* CKS_EXTCLK0C.EXTCLK0SCSID[1:0]: Source SYS0_CLOCK Setting for EXTCLK0O */
/* CKS_EXTCLK0S.EXTCLK0SACT[1:0]: SYS0_CLOCK source status for EXTCLK0 */
typedef enum{
	CLK_e_EXTCLK0_CLK_MOSC     = 0,	/* ID = 00B: CLK_MOSC */
	CLK_e_EXTCLK0_CLK_LSIOSC   = 1,	/* ID = 01B: CLK_LSIOSC */
	CLK_e_EXTCLK0_CLK_HSIOSC_2 = 2,	/* ID = 10B: CLK_HSIOSC/2 (default) */
	CLK_e_EXTCLK0_CLK_SOSC     = 3 	/* ID = 11B: CLK_SOSC */
}CLK_e_EXTCLK0;

/* CKS_EXTCLK1C.EXTCLK1SCSID: Source SYS0_CLOCK Setting for EXTCLK1O */
/* CKS_EXTCLK1S.EXTCLK1SACT: SYS0_CLOCK source status for EXTCLK1 */
typedef enum{
	CLK_e_EXTCLK1_CLK_BUS8 = 0,	/* ID = 0B: CLK_BUS8 (default) */
	CLK_e_EXTCLK1_CLK_P080 = 1 	/* ID = 1B: CLK_P080 */
}CLK_e_EXTCLK1;

/* CKD_EXTCLK1S.EXTCLK1CLKACT: SYS0_CLOCK Divider Active */
/* CKD_EXTCLK0S.EXTCLK0CLKACT: SYS0_CLOCK Divider Active */
typedef enum{
	CLK_e_ACT_not_active = 0,	/* ID = 0: Frequency output is stopped. */
	CLK_e_ACT_active     = 1 	/* ID = 1: Frequency output is ongoing. */
}CLK_e_ACT;

/* CKD_EXTCLK1S.EXTCLK1SYNC: SYS0_CLOCK Divider Synchronized */
/* CKD_EXTCLK0S.EXTCLK0SYNC: SYS0_CLOCK Divider Synchronized */
typedef enum{
	CLK_e_SYNC_unstable = 0,	/* ID = 0: The clock divider is in the process of synchronization. */
	CLK_e_SYNC_stable   = 1 	/* ID = 1: The clock divider is stable (or stopped). */
}CLK_e_SYNC;

/* CKS_ALPSC.ALPSSCSID[1:0]: SYS0_CLOCK source control */
/* CKS_ALPSS.ALPSSACT[1:0]: SYS0_CLOCK source status for CLK_LPS */
typedef enum{
	CLK_e_ALPS_CLK_IOSC0    = 0,	/* ID = 00B: CLK_IOSC0 (default) */
	CLK_e_ALPS_CLK_LSIOSC   = 1,	/* ID = 01B: CLK_LSIOSC */
	CLK_e_ALPS_CLK_HSIOSC_2 = 2 	/* ID = 10B: CLK_HSIOSC/2 */
	                            	/* Setting other than the above is prohibited. */
}CLK_e_ALPS;

/* CLKKCPROT1: Enable/Disables write access of protected registers */
/* CLKKCPROT4: Enable/Disables write access of protected registers */
typedef enum{
	CLK_e_KCPROT_write_disable = 0xA5A5A500,	/* Disables write access of protected registers */
	CLK_e_KCPROT_write_enable  = 0xA5A5A501 	/* Enables write access of protected registers */
}CLK_e_KCPROT;

/* CLKKCPROT1.KCE: Key Code Enable bit */
/* CLKKCPROT4.KCE: Key Code Enable bit */
typedef enum{
	CLK_e_KCE_write_disable = 0,	/* ID = 0: Disables write access of protected registers */
	CLK_e_KCE_write_enable  = 1 	/* ID = 1: Enables write access of protected registers */
}CLK_e_KCE;


/*******************************************************************************
* Definition of Register typedef
*******************************************************************************/
/* Clock Oscillator Registers - PLL, SSCG *************************************/
/* PLLE register */
typedef union{
		uint32_t         	UINT32;
	struct{
		uint32_t         	PLLENTRG     	:1;
		uint32_t         	PLLDISTRG    	:1;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_PLLE;

/* PLLS register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_EN         	PLLCLKEN     	:1;
		CLK_e_STAB       	PLLCLKSTAB   	:1;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_PLLS;

/* CKS_PLLINC register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_PLLIN      	PLLINSCSID   	:1;
		uint32_t         	Reserved_1   	:31;
	}BIT;
}CLK_s_CKS_PLLINC;

/* CKS_PLLINS register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_PLLIN      	PLLINSACT    	:1;
		uint32_t         	Reserved_1   	:31;
	}BIT;
}CLK_s_CKS_PLLINS;

/* SSCGC register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_SELMPERCENT	SELMPERCENT  	:3;
		uint32_t         	SELMFREQ     	:5;
		uint32_t         	Reserved_8   	:1;
		CLK_e_SSMODE1    	SSMODE1      	:1;
		uint32_t         	Reserved_10  	:22;
	}BIT;
	struct{
		CLK_e_SELMPERCENT   	SELMPERCENT  	:3;
		CLK_e_SELMFREQ_FPDF8	SELMFREQ     	:5;
		uint32_t            	Reserved_8   	:1;
		CLK_e_SSMODE1       	SSMODE1      	:1;
		uint32_t            	Reserved_10  	:22;
	}BIT_FPDF8;
	struct{
		CLK_e_SELMPERCENT    	SELMPERCENT  	:3;
		CLK_e_SELMFREQ_FPDF10	SELMFREQ     	:5;
		uint32_t             	Reserved_8   	:1;
		CLK_e_SSMODE1        	SSMODE1      	:1;
		uint32_t             	Reserved_10  	:22;
	}BIT_FPDF10;
}CLK_s_SSCGC;

/* Clock Oscillator Registers - Main OSC **************************************/
/* MOSCE register */
typedef union{
		uint32_t         	UINT32;
	struct{
		uint32_t         	MOSCENTRG    	:1;
		uint32_t         	MOSCDISTRG   	:1;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_MOSCE;

/* MOSCS register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_EN         	MOSCEN       	:1;
		CLK_e_STAB       	MOSCSTAB     	:1;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_MOSCS;

/* MOSCSTPM register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_STPMSK     	MOSCSTPMSK   	:1;
		uint32_t         	Reserved_1   	:31;
	}BIT;
}CLK_s_MOSCSTPM;

/* Clock Oscillator Registers - Sub OSC ***************************************/
/* SOSCE register */
typedef union{
		uint32_t         	UINT32;
	struct{
		uint32_t         	SOSCENTRG    	:1;
		uint32_t         	SOSCDISTRG   	:1;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_SOSCE;

/* SOSCS register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_EN         	SOSCEN       	:1;
		CLK_e_STAB       	SOSCSTAB     	:1;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_SOSCS;

/* SOSCST register */
typedef union{
		uint32_t         	UINT32;
	struct{
		uint32_t         	SOSCCLKST    	:22;
		uint32_t         	Reserved_22  	:10;
	}BIT;
}CLK_s_SOSCST;

/* Clock Oscillator Registers - HS IntOSC *************************************/
/* HSOSCS register */
typedef union{
		uint32_t         	UINT32;
	struct{
		uint32_t         	Reserved_0   	:1;
		CLK_e_STAB       	HSOSCSTAB    	:1;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_HSOSCS;

/* HSOSCSTPM register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_STPMSK     	HSOSCSTPMSK  	:1;
		uint32_t         	Reserved_1   	:31;
	}BIT;
}CLK_s_HSOSCSTPM;

/* HSOSCUSERTRMPRODC register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_PROD       	PROD         	:2;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_HSOSCUSERTRMPRODC;

/* HSOSCUSERTRMEN register */
typedef union{
		uint32_t         	UINT32;
	struct{
		uint32_t         	ENTRG        	:1;
		uint32_t         	Reserved_1   	:31;
	}BIT;
}CLK_s_HSOSCUSERTRMEN;

/* HSOSCUSERTRMS register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_TRMST      	TRMST        	:1;
		uint32_t         	Reserved_1   	:31;
	}BIT;
}CLK_s_HSOSCUSERTRMS;

/* HSOSCUSERTRMCNT register */
typedef union{
		uint32_t         	UINT32;
	struct{
		uint32_t         	CNT          	:11;
		uint32_t         	Reserved_11  	:21;
	}BIT;
}CLK_s_HSOSCUSERTRMCNT;

/* HSOSCUSERTRMSET register */
typedef union{
		uint32_t         	UINT32;
	struct{
		uint32_t         	TRMSET       	:9;
		uint32_t         	Reserved_9   	:23;
	}BIT;
}CLK_s_HSOSCUSERTRMSET;

/* Clock Selector/Divider Control Registers - System Clock (CLK_SYS1) *********/
/* CKS_SYS1C register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_SYS1       	SYSCLKSCSID  	:1;
		uint32_t         	Reserved_1   	:31;
	}BIT;
}CLK_s_CKS_SYS1C;

/* CKS_SYS1S register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_SYS1       	SYSCLKSACT   	:1;
		uint32_t         	Reserved_1   	:31;
	}BIT;
}CLK_s_CKS_SYS1S;

/* Clock Selector/Divider Control Registers - System Clock (CLK_SYS0) *********/
/* CKS_SYS0C register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_SYS0       	SYSCLKSCSID  	:1;
		uint32_t         	Reserved_1   	:31;
	}BIT;
}CLK_s_CKS_SYS0C;

/* CKS_SYS0S register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_SYS0       	SYSCLKSACT   	:1;
		uint32_t         	Reserved_1   	:31;
	}BIT;
}CLK_s_CKS_SYS0S;

/* Clock Selector/Divider Control Registers - PLL1 Clock (CLK_PLL1O) **********/
/* CKD_PLL1C register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_PLLCLKDCSID	PLLCLKDCSID  	:4;
		uint32_t         	Reserved_4   	:28;
	}BIT;
}CLK_s_CKD_PLL1C;

/* CKD_PLL1S register */
typedef union{
		uint32_t         	UINT32;
	struct{
		uint32_t         	Reserved_0   	:1;
		CLK_e_CLKDSYNC   	PLLCLKDSYNC  	:1;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_CKD_PLL1S;

/* Clock Selector/Divider Control Registers - PLL0 Clock (CLK_PLL0O) **********/
/* CKD_PLL0C register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_PLLCLKDCSID	PLLCLKDCSID  	:4;
		uint32_t         	Reserved_4   	:28;
	}BIT;
}CLK_s_CKD_PLL0C;

/* CKD_PLL0S register */
typedef union{
		uint32_t         	UINT32;
	struct{
		uint32_t         	Reserved_0   	:1;
		CLK_e_CLKDSYNC   	PLLCLKDSYNC  	:1;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_CKD_PLL0S;

/* Clock Selector/Divider Control Registers - RLIN Clock (CLK_RLIN3) **********/
/* CKS_RLINC register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_RLIN       	RLINSCSID    	:2;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_CKS_RLINC;

/* CKS_RLINS register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_RLIN       	RLINSACT     	:2;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_CKS_RLINS;

/* Clock Selector/Divider Control Registers - RTCA Clock (CLK_RTCA) ***********/
/* CKS_ARTCAC register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_ARTCA      	ARTCASCSID   	:2;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_CKS_ARTCAC;

/* CKS_ARTCAS register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_ARTCA      	ARTCASACT    	:2;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_CKS_ARTCAS;

/* Clock Selector/Divider Control Registers - ADCK0 Clock (CLK_ADC0) **********/
/* CKS_AADCC register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_AADC       	AADCSCSID    	:2;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_CKS_AADCC;

/* CKS_AADCS register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_AADC       	AADCSACT     	:2;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_CKS_AADCS;

/* Clock Selector/Divider Control Registers - EXTCLK0 Clock (EXTCLK0O) ********/
/* CKS_EXTCLK0C register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_EXTCLK0    	EXTCLK0SCSID 	:2;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_CKS_EXTCLK0C;

/* CKS_EXTCLK0S register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_EXTCLK0    	EXTCLK0SACT  	:2;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_CKS_EXTCLK0S;

/* CKD_EXTCLK0C register */
typedef union{
		uint32_t         	UINT32;
	struct{
		uint32_t         	EXTCLK0DIV   	:10;
		uint32_t         	Reserved_10  	:22;
	}BIT;
}CLK_s_CKD_EXTCLK0C;

/* CKD_EXTCLK0S register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_SYNC       	EXTCLK0SYNC  	:1;
		CLK_e_ACT        	EXTCLK0CLKACT	:1;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_CKD_EXTCLK0S;

/* Clock Selector/Divider Control Registers - EXTCLK1 Clock (EXTCLK1O) ********/
/* CKS_EXTCLK1C register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_EXTCLK1    	EXTCLK1SCSID 	:1;
		uint32_t         	Reserved_1   	:31;
	}BIT;
}CLK_s_CKS_EXTCLK1C;

/* CKS_EXTCLK1S register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_EXTCLK1    	EXTCLK1SACT  	:1;
		uint32_t         	Reserved_1   	:31;
	}BIT;
}CLK_s_CKS_EXTCLK1S;

/* CKD_EXTCLK1C register */
typedef union{
		uint32_t         	UINT32;
	struct{
		uint32_t         	EXTCLK1DIV   	:10;
		uint32_t         	Reserved_10  	:22;
	}BIT;
}CLK_s_CKD_EXTCLK1C;

/* CKD_EXTCLK1S register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_SYNC       	EXTCLK1SYNC  	:1;
		CLK_e_ACT        	EXTCLK1CLKACT	:1;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_CKD_EXTCLK1S;

/* Clock Selector/Divider Control Registers - LPS Clock (CLK_LPS) *************/
/* CKS_ALPSC register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_ALPS       	ALPSSCSID    	:2;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_CKS_ALPSC;

/* CKS_ALPSS register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_ALPS       	ALPSSACT     	:2;
		uint32_t         	Reserved_2   	:30;
	}BIT;
}CLK_s_CKS_ALPSS;

/* Protection Register ********************************************************/
/* CLKKCPROT1 register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_KCE        	KCE          	:1;
		uint32_t         	KCPROT       	:31;
	}BIT;
}CLK_s_CLKKCPROT1;

/* CLKKCPROT4 register */
typedef union{
		uint32_t         	UINT32;
	struct{
		CLK_e_KCE        	KCE          	:1;
		uint32_t         	KCPROT       	:31;
	}BIT;
}CLK_s_CLKKCPROT4;


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_clock_reg_H__ */

