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
* File Name    : R_driver_RLIN3_reg.h
* Version      : 1.00
* Module(s)    : RLIN3
* Device(s)    : RH850 series product, R-Car U5L product
* Description  : Register definition of RLIN3 that is used commonly by RH850 and 
*                R-Car products
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_RLIN3_reg_H__
#define	__R_driver_RLIN3_reg_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"
#include "R_device_RLIN3.h"    	/* Product-specific definition */


/*******************************************************************************
* Register Base Address Definitions
*******************************************************************************/
#define	RLIN3n_base(n)       	RLIN3n_base[n]


/*******************************************************************************
* Definition of register symbol
*******************************************************************************/
#define	rRLN3nLWBR(n)   	(*(volatile RLIN3_s_RLN3nLWBR    *) (RLIN3n_base(n) + 0x01) )          	/* LIN wake-up baud rate select register */
#define	rRLN3nLBRP01(n) 	(*(volatile RLIN3_s_RLN3nLBRP01  *) (RLIN3n_base(n) + 0x02) )          	/* LIN/UART baud rate prescaler 01 register */
#define	rRLN3nLBRP0(n)  	(*(volatile RLIN3_s_RLN3nLBRP0   *) (RLIN3n_base(n) + 0x02) )          	/* LIN/UART baud rate prescaler 0 register */
#define	rRLN3nLBRP1(n)  	(*(volatile RLIN3_s_RLN3nLBRP1   *) (RLIN3n_base(n) + 0x03) )          	/* LIN/UART baud rate prescaler 1 register */
#define	rRLN3nLSTC(n)   	(*(volatile RLIN3_s_RLN3nLSTC    *) (RLIN3n_base(n) + 0x04) )          	/* LIN self-test control register */
#define	rRLN3nLMD(n)    	(*(volatile RLIN3_s_RLN3nLMD     *) (RLIN3n_base(n) + 0x08) )          	/* LIN/UART mode register */
#define	rRLN3nLBFC(n)   	(*(volatile RLIN3_s_RLN3nLBFC    *) (RLIN3n_base(n) + 0x09) )          	/* LIN break field configuration register/ UART configuration register */
#define	rRLN3nLSC(n)    	(*(volatile RLIN3_s_RLN3nLSC     *) (RLIN3n_base(n) + 0x0A) )          	/* LIN/UART space configuration register */
#define	rRLN3nLWUP(n)   	(*(volatile RLIN3_s_RLN3nLWUP    *) (RLIN3n_base(n) + 0x0B) )          	/* LIN wake-up configuration register */
#define	rRLN3nLIE(n)    	(*(volatile RLIN3_s_RLN3nLIE     *) (RLIN3n_base(n) + 0x0C) )          	/* LIN interrupt enable register */
#define	rRLN3nLEDE(n)   	(*(volatile RLIN3_s_RLN3nLEDE    *) (RLIN3n_base(n) + 0x0D) )          	/* LIN/UART error detection enable register */
#define	rRLN3nLCUC(n)   	(*(volatile RLIN3_s_RLN3nLCUC    *) (RLIN3n_base(n) + 0x0E) )          	/* LIN/UART control register */
#define	rRLN3nLTRC(n)   	(*(volatile RLIN3_s_RLN3nLTRC    *) (RLIN3n_base(n) + 0x10) )          	/* LIN/UART transmission control register */
#define	rRLN3nLMST(n)   	(*(volatile RLIN3_s_RLN3nLMST    *) (RLIN3n_base(n) + 0x11) )          	/* LIN/UART mode status register */
#define	rRLN3nLST(n)    	(*(volatile RLIN3_s_RLN3nLST     *) (RLIN3n_base(n) + 0x12) )          	/* LIN/UART status register */
#define	rRLN3nLEST(n)   	(*(volatile RLIN3_s_RLN3nLEST    *) (RLIN3n_base(n) + 0x13) )          	/* LIN/UART error status register */
#define	rRLN3nLDFC(n)   	(*(volatile RLIN3_s_RLN3nLDFC    *) (RLIN3n_base(n) + 0x14) )          	/* LIN data field configuration register */
#define	rRLN3nLIDB(n)   	(*(volatile RLIN3_s_RLN3nLIDB    *) (RLIN3n_base(n) + 0x15) )          	/* LIN/UART ID buffer register */
#define	rRLN3nLCBR(n)   	(*(volatile RLIN3_s_RLN3nLCBR    *) (RLIN3n_base(n) + 0x16) )          	/* LIN checksum buffer register */
#define	rRLN3nLUDB0(n)  	(*(volatile RLIN3_s_RLN3nLUDB0   *) (RLIN3n_base(n) + 0x17) )          	/* UART data buffer 0 register */
#define	rRLN3nLDBRb(n,b)	(*(volatile RLIN3_s_RLN3nLDBRb   *) (RLIN3n_base(n) + 0x18 + ((b)-1)) )	/* LIN/UART data buffer b register */
#define	rRLN3nLDBR1(n)  	(*(volatile RLIN3_s_RLN3nLDBRb   *) (RLIN3n_base(n) + 0x18) )          	/* LIN/UART data buffer 1 register */
#define	rRLN3nLDBR2(n)  	(*(volatile RLIN3_s_RLN3nLDBRb   *) (RLIN3n_base(n) + 0x19) )          	/* LIN/UART data buffer 2 register */
#define	rRLN3nLDBR3(n)  	(*(volatile RLIN3_s_RLN3nLDBRb   *) (RLIN3n_base(n) + 0x1A) )          	/* LIN/UART data buffer 3 register */
#define	rRLN3nLDBR4(n)  	(*(volatile RLIN3_s_RLN3nLDBRb   *) (RLIN3n_base(n) + 0x1B) )          	/* LIN/UART data buffer 4 register */
#define	rRLN3nLDBR5(n)  	(*(volatile RLIN3_s_RLN3nLDBRb   *) (RLIN3n_base(n) + 0x1C) )          	/* LIN/UART data buffer 5 register */
#define	rRLN3nLDBR6(n)  	(*(volatile RLIN3_s_RLN3nLDBRb   *) (RLIN3n_base(n) + 0x1D) )          	/* LIN/UART data buffer 6 register */
#define	rRLN3nLDBR7(n)  	(*(volatile RLIN3_s_RLN3nLDBRb   *) (RLIN3n_base(n) + 0x1E) )          	/* LIN/UART data buffer 7 register */
#define	rRLN3nLDBR8(n)  	(*(volatile RLIN3_s_RLN3nLDBRb   *) (RLIN3n_base(n) + 0x1F) )          	/* LIN/UART data buffer 8 register */
#define	rRLN3nLUOER(n)  	(*(volatile RLIN3_s_RLN3nLUOER   *) (RLIN3n_base(n) + 0x20) )          	/* UART operation enable register */
#define	rRLN3nLUOR1(n)  	(*(volatile RLIN3_s_RLN3nLUOR1   *) (RLIN3n_base(n) + 0x21) )          	/* UART option register 1 */
#define	rRLN3nLUTDR(n)  	(*(volatile RLIN3_s_RLN3nLUTDR   *) (RLIN3n_base(n) + 0x24) )          	/* UART transmission data register */
#define	rRLN3nLURDR(n)  	(*(volatile RLIN3_s_RLN3nLURDR   *) (RLIN3n_base(n) + 0x26) )          	/* UART reception data register */
#define	rRLN3nLUWTDR(n) 	(*(volatile RLIN3_s_RLN3nLUWTDR  *) (RLIN3n_base(n) + 0x28) )          	/* UART wait transmission data register */
#define	rRLN3nLBSS(n)   	(*(volatile RLIN3_s_RLN3nLBSS    *) (RLIN3n_base(n) + 0x30) )          	/* LIN slave break/sync field status register */
#define	rRLN3nLRSS(n)   	(*(volatile RLIN3_s_RLN3nLRSS    *) (RLIN3n_base(n) + 0x34) )          	/* LIN slave response space status register */


/*******************************************************************************
* Definition of Register bit value (LIN Master Related Registers)
*******************************************************************************/
/* RLN3nLWBR.NSPB: These bits configure the value for number of samples in 1 Bit time period. */
typedef enum{
	RLIN3m_e_NSPB_16_samplings   = 0,	/* 0000: 16 samples per bit */
	RLIN3m_e_NSPB_16_samplings_2 = 15 	/* 1111: 16 samples per bit */
}RLIN3m_e_NSPB;

/* RLN3nLWBR.LPRS: Prescaler Clock Select */
typedef enum{
	RLIN3m_e_LPRS_div_1   = 0,	/* 000: 1/1 */
	RLIN3m_e_LPRS_div_2   = 1,	/* 001: 1/2 */
	RLIN3m_e_LPRS_div_4   = 2,	/* 010: 1/4 */
	RLIN3m_e_LPRS_div_8   = 3,	/* 011: 1/8 */
	RLIN3m_e_LPRS_div_16  = 4,	/* 100: 1/16 */
	RLIN3m_e_LPRS_div_32  = 5,	/* 101: 1/32 */
	RLIN3m_e_LPRS_div_64  = 6,	/* 110: 1/64 */
	RLIN3m_e_LPRS_div_128 = 7 	/* 111: 1/128 */
}RLIN3m_e_LPRS;

/* RLN3nLWBR.LWBR0: Wake-up Baud Rate Select */
typedef enum{
	RLIN3m_e_LWBR0_select_by_LCKS = 0,	/* 0: In LIN wake-up mode, the clock specified in the LCKS bit of the RLN3nLMD register is used. (LIN1.3) */
	RLIN3m_e_LWBR0_clock_fa       = 1 	/* 1: In LIN wake-up mode, the clock fa is used regardless of the setting in the LCKS bit of the RLN3nLMD register. (LIN2.x) */
}RLIN3m_e_LWBR0;

/* RLN3nLSTC.LSTM: LIN Self-Test Mode */
typedef enum{
	RLIN3m_e_LSTM_not_selftest = 0,	/* 0: The module is not in LIN self-test mode. */
	RLIN3m_e_LSTM_selftest     = 1 	/* 1: The module is in LIN self-test mode. */
}RLIN3m_e_LSTM;

/* RLN3nLMD.LRDNFS: LIN Reception Data Noise Filter Disable */
typedef enum{
	RLIN3m_e_LRDNFS_enable  = 0,	/* 0: The noise filter is enabled. */
	RLIN3m_e_LRDNFS_disable = 1 	/* 1: The noise filter is disabled. */
}RLIN3m_e_LRDNFS;

/* RLN3nLMD.LIOS: LIN Interrupt Output Select */
typedef enum{
	RLIN3m_e_LIOS_INTRLIN3n   = 0,	/* 0: RLIN3n interrupt is used. */
	RLIN3m_e_LIOS_INTRLIN3nUR = 1 	/* 1: RLIN3n transmission interrupt, RLIN3n successful reception interrupt, and RLIN3n status interrupt are used. */
}RLIN3m_e_LIOS;

/* RLN3nLMD.LCKS: LIN System Clock Select */		
typedef enum{		
	RLIN3m_e_LCKS_clock_fa = 0,	/* 00: fa (Clock generated by baud rate prescaler 0) */
	RLIN3m_e_LCKS_clock_fb = 1,	/* 01: fb (1/2 clock generated by baud rate prescaler 0) */
	RLIN3m_e_LCKS_clock_fc = 2,	/* 10: fc (1/8 clock generated by baud rate prescaler 0) */
	RLIN3m_e_LCKS_clock_fd = 3 	/* 11: fd (1/2 clock generated by baud rate prescaler 1) */
}RLIN3m_e_LCKS;		
		
/* RLN3nLMD.LMD: LIN/UART Mode Select */
typedef enum{
	RLIN3m_e_LMD_LIN_master_mode = 0 	/* 00: LIN master mode */
}RLIN3m_e_LMD;

/* RLN3nLBFC.BDT: Transmission Break Delimiter (High Level) Width Select */
typedef enum{
	RLIN3m_e_BDT_1_Tbit  = 0,	/* 00: 1 Tbit */
	RLIN3m_e_BDT_2_Tbits = 1,	/* 01: 2 Tbits */
	RLIN3m_e_BDT_3_Tbits = 2,	/* 10: 3 Tbits */
	RLIN3m_e_BDT_4_Tbits = 3 	/* 11: 4 Tbits */
}RLIN3m_e_BDT;

/* RLN3nLBFC.BLT: Transmission Break (Low Level) Width Select */
typedef enum{
	RLIN3m_e_BLT_13_Tbits = 0,	/* 0000: 13 Tbits */
	RLIN3m_e_BLT_14_Tbits = 1,	/* 0001: 14 Tbits */
	RLIN3m_e_BLT_15_Tbits = 2,	/* 0010: 15 Tbits */
	RLIN3m_e_BLT_16_Tbits = 3,	/* 0011: 16 Tbits */
	RLIN3m_e_BLT_17_Tbits = 4,	/* 0100: 17 Tbits */
	RLIN3m_e_BLT_18_Tbits = 5,	/* 0101: 18 Tbits */
	RLIN3m_e_BLT_19_Tbits = 6,	/* 0110: 19 Tbits */
	RLIN3m_e_BLT_20_Tbits = 7,	/* 0111: 20 Tbits */
	RLIN3m_e_BLT_21_Tbits = 8,	/* 1000: 21 Tbits */
	RLIN3m_e_BLT_22_Tbits = 9,	/* 1001: 22 Tbits */
	RLIN3m_e_BLT_23_Tbits = 10,	/* 1010: 23 Tbits */
	RLIN3m_e_BLT_24_Tbits = 11,	/* 1011: 24 Tbits */
	RLIN3m_e_BLT_25_Tbits = 12,	/* 1100: 25 Tbits */
	RLIN3m_e_BLT_26_Tbits = 13,	/* 1101: 26 Tbits */
	RLIN3m_e_BLT_27_Tbits = 14,	/* 1110: 27 Tbits */
	RLIN3m_e_BLT_28_Tbits = 15 	/* 1111: 28 Tbits */
}RLIN3m_e_BLT;

/* RLN3nLSC.IBS: Inter-Byte Space Select */
typedef enum{
	RLIN3m_e_IBS_0_Tbit  = 0,	/* 00: 0 Tbit */
	RLIN3m_e_IBS_1_Tbit  = 1,	/* 01: 1 Tbit */
	RLIN3m_e_IBS_2_Tbits = 2,	/* 10: 2 Tbits */
	RLIN3m_e_IBS_3_Tbits = 3 	/* 11: 3 Tbits */
}RLIN3m_e_IBS;

/* RLN3nLSC.IBHS: Inter-Byte Space (Header)/Response Space Select */
typedef enum{
	RLIN3m_e_IBHS_0_Tbit  = 0,	/* 000: 0 Tbit */
	RLIN3m_e_IBHS_1_Tbit  = 1,	/* 001: 1 Tbit */
	RLIN3m_e_IBHS_2_Tbits = 2,	/* 010: 2 Tbits */
	RLIN3m_e_IBHS_3_Tbits = 3,	/* 011: 3 Tbits */
	RLIN3m_e_IBHS_4_Tbits = 4,	/* 100: 4 Tbits */
	RLIN3m_e_IBHS_5_Tbits = 5,	/* 101: 5 Tbits */
	RLIN3m_e_IBHS_6_Tbits = 6,	/* 110: 6 Tbits */
	RLIN3m_e_IBHS_7_Tbits = 7 	/* 111: 7 Tbits */
}RLIN3m_e_IBHS;

/* RLN3nLWUP.WUTL: Wake-up Transmission Low Level Width Select */
typedef enum{
	RLIN3m_e_WUTL_1_Tbits  = 0, 	/* 0000: 1 Tbit */
	RLIN3m_e_WUTL_2_Tbits  = 1, 	/* 0001: 2 Tbits */
	RLIN3m_e_WUTL_3_Tbits  = 2, 	/* 0010: 3 Tbits */
	RLIN3m_e_WUTL_4_Tbits  = 3, 	/* 0011: 4 Tbits */
	RLIN3m_e_WUTL_5_Tbits  = 4, 	/* 0100: 5 Tbits */
	RLIN3m_e_WUTL_6_Tbits  = 5, 	/* 0101: 6 Tbits */
	RLIN3m_e_WUTL_7_Tbits  = 6, 	/* 0110: 7 Tbits */
	RLIN3m_e_WUTL_8_Tbits  = 7, 	/* 0111: 8 Tbits */
	RLIN3m_e_WUTL_9_Tbits  = 8, 	/* 1000: 9 Tbits */
	RLIN3m_e_WUTL_10_Tbits = 9, 	/* 1001: 10 Tbits */
	RLIN3m_e_WUTL_11_Tbits = 10,	/* 1010: 11 Tbits */
	RLIN3m_e_WUTL_12_Tbits = 11,	/* 1011: 12 Tbits */
	RLIN3m_e_WUTL_13_Tbits = 12,	/* 1100: 13 Tbits */
	RLIN3m_e_WUTL_14_Tbits = 13,	/* 1101: 14 Tbits */
	RLIN3m_e_WUTL_15_Tbits = 14,	/* 1110: 15 Tbits */
	RLIN3m_e_WUTL_16_Tbits = 15 	/* 1111: 16 Tbits */
}RLIN3m_e_WUTL;

/* RLN3nLIE.SHIE: Successful Header Transmission Interrupt Request Enable */
typedef enum{
	RLIN3m_e_SHIE_disable = 0,	/* 0: Disables successful header transmission interrupt request. */
	RLIN3m_e_SHIE_enable  = 1 	/* 1: Enables successful header transmission interrupt request. */
}RLIN3m_e_SHIE;

/* RLN3nLIE.ERRIE: Error Detection Interrupt Request Enable */
typedef enum{
	RLIN3m_e_ERRIE_disable = 0,	/* 0: Disables error detection interrupt request. */
	RLIN3m_e_ERRIE_enable  = 1 	/* 1: Enables error detection interrupt request. */
}RLIN3m_e_ERRIE;

/* RLN3nLIE.FRCIE: Successful Frame/Wake-up Reception Interrupt Request Enable */
typedef enum{
	RLIN3m_e_FRCIE_disable = 0,	/* 0: Disables successful frame/wake-up reception interrupt request. */
	RLIN3m_e_FRCIE_enable  = 1 	/* 1: Enables successful frame/wake-up reception interrupt request. */
}RLIN3m_e_FRCIE;

/* RLN3nLIE.FTCIE: Successful Frame/Wake-up Transmission Interrupt Request Enable */
typedef enum{
	RLIN3m_e_FTCIE_disable = 0,	/* 0: Disables successful frame/wake-up transmission interrupt request. */
	RLIN3m_e_FTCIE_enable  = 1 	/* 1: Enables successful frame/wake-up transmission interrupt request. */
}RLIN3m_e_FTCIE;

/* RLN3nLEDE.LTES: Timeout Error Select */
typedef enum{
	RLIN3m_e_LTES_frame_timeout_error    = 0,	/* 0: Frame timeout error */
	RLIN3m_e_LTES_response_timeout_error = 1 	/* 1: Response timeout error */
}RLIN3m_e_LTES;

/* RLN3nLEDE.FERE: Framing Error Detection Enable*1 */
typedef enum{
	RLIN3m_e_FERE_disable = 0,	/* 0: Disables framing error detection. */
	RLIN3m_e_FERE_enable  = 1 	/* 1: Enables framing error detection. */
}RLIN3m_e_FERE;

/* RLN3nLEDE.FTERE: Timeout Error Detection Enable */
typedef enum{
	RLIN3m_e_FTERE_disable = 0,	/* 0: Disables frame/response timeout error detection. */
	RLIN3m_e_FTERE_enable  = 1 	/* 1: Enables frame/response timeout error detection. */
}RLIN3m_e_FTERE;

/* RLN3nLEDE.PBERE: Physical Bus Error Detection Enable */
typedef enum{
	RLIN3m_e_PBERE_disable = 0,	/* 0: Disables physical bus error detection. */
	RLIN3m_e_PBERE_enable  = 1 	/* 1: Enables physical bus error detection. */
}RLIN3m_e_PBERE;

/* RLN3nLEDE.BERE: Bit Error Detection Enable *1 */
typedef enum{
	RLIN3m_e_BERE_disable = 0,	/* 0: Disables bit error detection. */
	RLIN3m_e_BERE_enable  = 1 	/* 1: Enables bit error detection. */
}RLIN3m_e_BERE;

/* RLN3nLCUC.OM1: LIN Mode Select */
typedef enum{
	RLIN3m_e_OM1_LIN_waleup_mode    = 0,	/* 0: LIN wake-up mode. */
	RLIN3m_e_OM1_LIN_operation_mode = 1 	/* 1: LIN operation mode. */
}RLIN3m_e_OM1;

/* RLN3nLCUC.OM0: LIN Reset */
typedef enum{
	RLIN3m_e_OM0_LIN_reset_mode   = 0,	/* 0: LIN reset mode. */
	RLIN3m_e_OM0_LIN_reset_cancel = 1 	/* 1: LIN reset mode is canceled. */
}RLIN3m_e_OM0;

/* RLN3nLTRC.RTS: Response Transmission/Reception Start */
typedef enum{
	RLIN3m_e_RTS_stop  = 0,	/* 0: Response transmission/reception is stopped in frame separate mode. */
	RLIN3m_e_RTS_start = 1 	/* 1: Response transmission/reception is started in frame separate mode. */
}RLIN3m_e_RTS;

/* RLN3nLTRC.FTS: Frame Transmission/Wake-up Transmission /Reception Start */
typedef enum{
	RLIN3m_e_FTS_stop  = 0,	/* 0: Frame Transmission/wake-up transmission/reception is stopped. */
	RLIN3m_e_FTS_start = 1 	/* 1: Frame Transmission/wake-up transmission reception is started. */
}RLIN3m_e_FTS;

/* RLN3nLMST.OMM1: LIN Mode Status Monitor */
typedef enum{
	RLIN3m_e_OMM1_LIN_waleup_mode    = 0,	/* 0: LIN wake-up mode. */
	RLIN3m_e_OMM1_LIN_operation_mode = 1 	/* 1: LIN operation mode. */
}RLIN3m_e_OMM1;

/* RLN3nLMST.OMM0: LIN Reset Status Monitor */
typedef enum{
	RLIN3m_e_OMM0_LIN_reset_mode     = 0,	/* 0: LIN reset mode. */
	RLIN3m_e_OMM0_not_LIN_reset_mode = 1 	/* 1: Not in LIN reset mode. */
}RLIN3m_e_OMM0;

/* RLN3nLST.HTRC: Successful Header Transmission Flag */
typedef enum{
	RLIN3m_e_HTRC_not_complete = 0,	/* 0: Header transmission has not been completed. */
	RLIN3m_e_HTRC_complete     = 1 	/* 1: Header transmission has been completed. */
}RLIN3m_e_HTRC;

/* RLN3nLST.D1RC: Successful Data 1 Reception Flag */
typedef enum{
	RLIN3m_e_D1RC_not_complete = 0,	/* 0: Data 1 reception has not been completed. */
	RLIN3m_e_D1RC_complete     = 1 	/* 1: Data 1 reception has been completed. */
}RLIN3m_e_D1RC;

/* RLN3nLST.ERR: Error Detection Flag */
typedef enum{
	RLIN3m_e_ERR_no_error = 0,	/* 0: No error has been detected. */
	RLIN3m_e_ERR_error    = 1 	/* 1: Error has been detected. */
}RLIN3m_e_ERR;

/* RLN3nLST.FRC: Successful Frame/Wake-up Reception Flag */
typedef enum{
	RLIN3m_e_FRC_not_complete = 0,	/* 0: Frame or wake-up reception has not been completed. */
	RLIN3m_e_FRC_complete     = 1 	/* 1: Frame or wake-up reception has been completed. */
}RLIN3m_e_FRC;

/* RLN3nLST.FTC: Successful Frame/Wake-up Transmission Flag */
typedef enum{
	RLIN3m_e_FTC_not_complete = 0,	/* 0: Frame or wake-up transmission has not been completed. */
	RLIN3m_e_FTC_complete     = 1 	/* 1: Frame or wake-up transmission has been completed. */
}RLIN3m_e_FTC;

/* RLN3nLEST.RPER: Response Preparation Error Flag */
typedef enum{
	RLIN3m_e_RPER_no_error = 0,	/* 0: Response preparation error has not been detected. */
	RLIN3m_e_RPER_error    = 1 	/* 1: Response preparation error has been detected. */
}RLIN3m_e_RPER;

/* RLN3nLEST.CSER: Checksum Error Flag */
typedef enum{
	RLIN3m_e_CSER_no_error = 0,	/* 0: Checksum error has not been detected. */
	RLIN3m_e_CSER_error    = 1 	/* 1: Checksum error has been detected. */
}RLIN3m_e_CSER;

/* RLN3nLEST.FER: Framing Error Flag */
typedef enum{
	RLIN3m_e_FER_no_error = 0,	/* 0: Framing error has not been detected. */
	RLIN3m_e_FER_error    = 1 	/* 1: Framing error has been detected. */
}RLIN3m_e_FER;

/* RLN3nLEST.FTER: Timeout Error Flag */
typedef enum{
	RLIN3m_e_FTER_no_error = 0,	/* 0: Frame/response timeout error has not been detected. */
	RLIN3m_e_FTER_error    = 1 	/* 1: Frame/response timeout error has been detected. */
}RLIN3m_e_FTER;

/* RLN3nLEST.PBER: Physical Bus Error Flag */
typedef enum{
	RLIN3m_e_PBER_no_error = 0,	/* 0: Physical bus error has not been detected. */
	RLIN3m_e_PBER_error    = 1 	/* 1: Physical bus error has been detected. */
}RLIN3m_e_PBER;

/* RLN3nLEST.BER: Bit Error Flag */
typedef enum{
	RLIN3m_e_BER_no_error = 0,	/* 0: Bit error has not been detected. */
	RLIN3m_e_BER_error    = 1 	/* 1: Bit error has been detected. */
}RLIN3m_e_BER;

/* RLN3nLDFC.LSS: Transmission/Reception Continuation Select */
typedef enum{
	RLIN3m_e_LSS_next_is_last     = 0,	/* 0: The data group to be transmitted/received next is the last one. */
	RLIN3m_e_LSS_next_is_not_last = 1 	/* 1: The data group to be transmitted/received next is not the last one. */
}RLIN3m_e_LSS;

/* RLN3nLDFC.FSM: Frame Separate Mode Select */
typedef enum{
	RLIN3m_e_FSM_disable = 0,	/* 0: Frame separate mode is not set. */
	RLIN3m_e_FSM_enable  = 1 	/* 1: Frame separate mode is set. */
}RLIN3m_e_FSM;

/* RLN3nLDFC.CSM: Checksum Select */
typedef enum{
	RLIN3m_e_CSM_classic_checksum  = 0,	/* 0: Classic checksum */
	RLIN3m_e_CSM_enhanced_checksum = 1 	/* 1: Enhanced checksum */
}RLIN3m_e_CSM;

/* RLN3nLDFC.RFT: Response Field Communication Direction Select */
typedef enum{
	RLIN3m_e_RFT_reception    = 0,	/* 0: Reception */
	RLIN3m_e_RFT_transmission = 1 	/* 1: Transmission */
}RLIN3m_e_RFT;

/* RLN3nLDFC.RFDL: Response Field Length Select */
typedef enum{
	RLIN3m_e_RFDL_0_byte  = 0,	/* 0000: 0 byte (+ checksum) */
	RLIN3m_e_RFDL_1_byte  = 1,	/* 0001: 1 byte (+ checksum) */
	RLIN3m_e_RFDL_2_bytes = 2,	/* 0010: 2 bytes (+ checksum) */
	RLIN3m_e_RFDL_3_bytes = 3,	/* : */
	RLIN3m_e_RFDL_4_bytes = 4,	/* 0100: 4 bytes (+ checksum) */
	RLIN3m_e_RFDL_5_bytes = 5,	/* 0101: 5 bytes (+ checksum) */
	RLIN3m_e_RFDL_6_bytes = 6,	/* 0110: 6 bytes (+ checksum) */
	RLIN3m_e_RFDL_7_bytes = 7,	/* 0111: 7 bytes (+ checksum) */
	RLIN3m_e_RFDL_8_bytes = 8 	/* 1000: 8 bytes (+ checksum) */
	                          	/* Settings other than the above are prohibited. */
}RLIN3m_e_RFDL;


/*******************************************************************************
* Definition of Register bit value (LIN Slave Related Registers)
*******************************************************************************/
/* RLN3nLWBR.NSPB: Bit Sampling Count Select */
typedef enum{
	RLIN3s_e_NSPB_16_samplings   = 0,	/* 0000: 16 samplings */
	RLIN3s_e_NSPB_4_samplings    = 3,	/* 0011: 4 samplings */
	RLIN3s_e_NSPB_8_samplings    = 7,	/* 0111: 8 samplings */
	RLIN3s_e_NSPB_16_samplings_2 = 15 	/* 1111: 16 samplings */
}RLIN3s_e_NSPB;

/* RLN3nLWBR.LPRS: b3 b1 */
typedef enum{
	RLIN3s_e_LPRS_div_1   = 0,	/* 000: 1/1 */
	RLIN3s_e_LPRS_div_2   = 1,	/* 001: 1/2 */
	RLIN3s_e_LPRS_div_4   = 2,	/* 010: 1/4 */
	RLIN3s_e_LPRS_div_8   = 3,	/* 011: 1/8 */
	RLIN3s_e_LPRS_div_16  = 4,	/* 100: 1/16 */
	RLIN3s_e_LPRS_div_32  = 5,	/* 101: 1/32 */
	RLIN3s_e_LPRS_div_64  = 6,	/* 110: 1/64 */
	RLIN3s_e_LPRS_div_128 = 7 	/* 111: 1/128 */
}RLIN3s_e_LPRS;

/* RLN3nLSTC.LSTM: LIN Self-Test Mode */
typedef enum{
	RLIN3s_e_LSTM_not_selftest = 0,	/* 0: The module is not in LIN self-test mode. */
	RLIN3s_e_LSTM_selftest     = 1 	/* 1: The module is in LIN self-test mode. */
}RLIN3s_e_LSTM;

/* RLN3nLMD.LRDNFS: LIN Reception Data Noise Filter Disable */
typedef enum{
	RLIN3s_e_LRDNFS_enable  = 0,	/* 0: The noise filter is enabled. */
	RLIN3s_e_LRDNFS_disable = 1 	/* 1: The noise filter is disabled. */
}RLIN3s_e_LRDNFS;

/* RLN3nLMD.LIOS: LIN Interrupt Output Select */
typedef enum{
	RLIN3s_e_LIOS_INTRLIN3n   = 0,	/* 0: RLIN3n interrupt is used. */
	RLIN3s_e_LIOS_INTRLIN3nUR = 1 	/* 1: RLIN3n transmission interrupt, RLIN3n successful reception interrupt, and RLIN3n status interrupt are used. */
}RLIN3s_e_LIOS;

/* RLN3nLMD.LMD: LIN/UART Mode Select */
typedef enum{
	RLIN3s_e_LMD_LIN_slave_mode_auto  = 2,	/* 10: LIN slave mode with auto baud rate */
	RLIN3s_e_LMD_LIN_slave_mode_fixed = 3 	/* 11: LIN slave mode with fixed baud rate */
}RLIN3s_e_LMD;

/* RLN3nLBFC.LBLT: Reception Break (Low-Level) Detection Width Setting */
typedef enum{
	RLIN3s_e_LBLT_10_bits = 0,	/* 0: A break (low-level) is detected in 9.5 or 10 Tbits */
	RLIN3s_e_LBLT_11_bits = 1 	/* 1: A break (low-level) is detected in 10.5 or 11 Tbits */
}RLIN3s_e_LBLT;

/* RLN3nLBFC.IBS: Inter-Byte Space Select */
typedef enum{
	RLIN3s_e_IBS_0_Tbit  = 0,	/* 00: 0 Tbit */
	RLIN3s_e_IBS_1_Tbit  = 1,	/* 01: 1 Tbit */
	RLIN3s_e_IBS_2_Tbits = 2,	/* 10: 2 Tbits */
	RLIN3s_e_IBS_3_Tbits = 3 	/* 11: 3 Tbits */
}RLIN3s_e_IBS;

/* RLN3nLBFC.IBHS: Response Space Setting */
typedef enum{
	RLIN3s_e_IBHS_0_Tbit  = 0,	/* 000: 0 Tbit */
	RLIN3s_e_IBHS_1_Tbit  = 1,	/* 001: 1 Tbit */
	RLIN3s_e_IBHS_2_Tbits = 2,	/* 010: 2 Tbits */
	RLIN3s_e_IBHS_3_Tbits = 3,	/* 011: 3 Tbits */
	RLIN3s_e_IBHS_4_Tbits = 4,	/* 100: 4 Tbits */
	RLIN3s_e_IBHS_5_Tbits = 5,	/* 101: 5 Tbits */
	RLIN3s_e_IBHS_6_Tbits = 6,	/* 110: 6 Tbits */
	RLIN3s_e_IBHS_7_Tbits = 7 	/* 111: 7 Tbits */
}RLIN3s_e_IBHS;

/* RLN3nLWUP.WUTL: Wake-up Transmission Low Level Width Select */
typedef enum{
	RLIN3s_e_WUTL_1_Tbits  = 0,	/* 0000: 1 Tbit */
	RLIN3s_e_WUTL_2_Tbits  = 1,	/* 0001: 2 Tbits */
	RLIN3s_e_WUTL_3_Tbits  = 2,	/* 0010: 3 Tbits */
	RLIN3s_e_WUTL_4_Tbits  = 3,	/* 0011: 4 Tbits */
	RLIN3s_e_WUTL_5_Tbits  = 4,	/* 0100: 5 Tbits */
	RLIN3s_e_WUTL_6_Tbits  = 5,	/* 0101: 6 Tbits */
	RLIN3s_e_WUTL_7_Tbits  = 6,	/* 0110: 7 Tbits */
	RLIN3s_e_WUTL_8_Tbits  = 7,	/* 0111: 8 Tbits */
	RLIN3s_e_WUTL_9_Tbits  = 8,	/* 1000: 9 Tbits */
	RLIN3s_e_WUTL_10_Tbits = 9,	/* 1001: 10 Tbits */
	RLIN3s_e_WUTL_11_Tbits = 10,	/* 1010: 11 Tbits */
	RLIN3s_e_WUTL_12_Tbits = 11,	/* 1011: 12 Tbits */
	RLIN3s_e_WUTL_13_Tbits = 12,	/* 1100: 13 Tbits */
	RLIN3s_e_WUTL_14_Tbits = 13,	/* 1101: 14 Tbits */
	RLIN3s_e_WUTL_15_Tbits = 14,	/* 1110: 15 Tbits */
	RLIN3s_e_WUTL_16_Tbits = 15 	/* 1111: 16 Tbits */
}RLIN3s_e_WUTL;

/* RLN3nLIE.SHIE: Successful Header Reception Interrupt Request Enable */
typedef enum{
	RLIN3s_e_SHIE_disable = 0,	/* 0: Disables successful header reception interrupt request. */
	RLIN3s_e_SHIE_enable  = 1 	/* 1: Enables successful header reception interrupt request. */
}RLIN3s_e_SHIE;

/* RLN3nLIE.ERRIE: Error Detection Interrupt Request Enable */
typedef enum{
	RLIN3s_e_ERRIE_disable = 0,	/* 0: Disables error detection interrupt request. */
	RLIN3s_e_ERRIE_enable  = 1 	/* 1: Enables error detection interrupt request. */
}RLIN3s_e_ERRIE;

/* RLN3nLIE.FRCIE: Successful Response/Wake-up Reception Interrupt Request Enable */
typedef enum{
	RLIN3s_e_FRCIE_disable = 0,	/* 0: Disables successful Response/wake-up reception interrupt request. */
	RLIN3s_e_FRCIE_enable  = 1 	/* 1: Enables successful Response/wake-up reception interrupt request. */
}RLIN3s_e_FRCIE;

/* RLN3nLIE.FTCIE: Successful Response/Wake-up Transmission Interrupt Request Enable */
typedef enum{
	RLIN3s_e_FTCIE_disable = 0,	/* 0: Disables successful Response/wake-up transmission interrupt request. */
	RLIN3s_e_FTCIE_enable  = 1 	/* 1: Enables successful Response/wake-up transmission interrupt request. */
}RLIN3s_e_FTCIE;

/* RLN3nLEDE.LTES: Timeout Error Select */
typedef enum{
	RLIN3s_e_LTES_frame_timeout_error    = 0,	/* 0: Frame timeout error */
	RLIN3s_e_LTES_response_timeout_error = 1 	/* 1: Response timeout error */
}RLIN3s_e_LTES;

/* RLN3nLEDE.IPERE: ID Parity Error Detection Enable */
typedef enum{
	RLIN3s_e_IPERE_disable = 0,	/* 0: Disables ID Parity error detection. */
	RLIN3s_e_IPERE_enable  = 1 	/* 1: Enables ID Parity error detection. */
}RLIN3s_e_IPERE;

/* RLN3nLEDE.SFERE: Sync Field Error Detection Enable */
typedef enum{
	RLIN3s_e_SFERE_disable = 0,	/* 0: Disables Sync Field error detection. */
	RLIN3s_e_SFERE_enable  = 1 	/* 1: Enables Sync Field error detection. */
}RLIN3s_e_SFERE;

/* RLN3nLEDE.FERE: Framing Error Detection Enable*1 */
typedef enum{
	RLIN3s_e_FERE_disable = 0,	/* 0: Disables framing error detection. */
	RLIN3s_e_FERE_enable  = 1 	/* 1: Enables framing error detection. */
}RLIN3s_e_FERE;

/* RLN3nLEDE.TERE: Timeout Error Detection Enable */
typedef enum{
	RLIN3s_e_TERE_disable = 0,	/* 0: Disables frame/response timeout error detection. */
	RLIN3s_e_TERE_enable  = 1 	/* 1: Enables frame/response timeout error detection. */
}RLIN3s_e_TERE;

/* RLN3nLEDE.BERE: Bit Error Detection Enable *1 */
typedef enum{
	RLIN3s_e_BERE_disable = 0,	/* 0: Disables bit error detection. */
	RLIN3s_e_BERE_enable  = 1 	/* 1: Enables bit error detection. */
}RLIN3s_e_BERE;

/* RLN3nLCUC.OM1: LIN Mode Select */
typedef enum{
	RLIN3s_e_OM1_LIN_waleup_mode    = 0,	/* 0: LIN wake-up mode. */
	RLIN3s_e_OM1_LIN_operation_mode = 1 	/* 1: LIN operation mode. */
}RLIN3s_e_OM1;

/* RLN3nLCUC.OM0: LIN Reset */
typedef enum{
	RLIN3s_e_OM0_LIN_reset_mode   = 0,	/* 0: LIN reset mode. */
	RLIN3s_e_OM0_LIN_reset_cancel = 1 	/* 1: LIN reset mode is canceled. */
}RLIN3s_e_OM0;

/* RLN3nLTRC.LNRR: No LIN Response Request */
typedef enum{
	RLIN3s_e_LNRR_response    = 0,	/* 0: Response for the reception ID */
	RLIN3s_e_LNRR_no_response = 1 	/* 1: No response for the reception ID */
}RLIN3s_e_LNRR;

/* RLN3nLTRC.RTS: Response Transmission/Reception Start */
typedef enum{
	RLIN3s_e_RTS_stop  = 0,	/* 0: Response transmission/reception is stopped in frame separate mode. */
	RLIN3s_e_RTS_start = 1 	/* 1: Response transmission/reception is started in frame separate mode. */
}RLIN3s_e_RTS;

/* RLN3nLTRC.FTS: Frame Transmission/Wake-up Transmission /Reception Start */
typedef enum{
	RLIN3s_e_FTS_stop  = 0,	/* 0: Frame Transmission/wake-up transmission/reception is stopped. */
	RLIN3s_e_FTS_start = 1 	/* 1: Frame Transmission/wake-up transmission reception is started. */
}RLIN3s_e_FTS;

/* RLN3nLMST.OMM1: LIN Mode Status Monitor */
typedef enum{
	RLIN3s_e_OMM1_LIN_waleup_mode    = 0,	/* 0: LIN wake-up mode. */
	RLIN3s_e_OMM1_LIN_operation_mode = 1 	/* 1: LIN operation mode. */
}RLIN3s_e_OMM1;

/* RLN3nLMST.OMM0: LIN Reset Status Monitor */
typedef enum{
	RLIN3s_e_OMM0_LIN_reset_mode     = 0,	/* 0: LIN reset mode. */
	RLIN3s_e_OMM0_not_LIN_reset_mode = 1 	/* 1: Not in LIN reset mode. */
}RLIN3s_e_OMM0;

/* RLN3nLST.HTRC: Successful Header Reception Flag */
typedef enum{
	RLIN3s_e_HTRC_not_complete = 0,	/* 0: Header reception has not been completed. */
	RLIN3s_e_HTRC_complete     = 1 	/* 1: Header reception has been completed. */
}RLIN3s_e_HTRC;

/* RLN3nLST.D1RC: Successful Data 1 Reception Flag */
typedef enum{
	RLIN3s_e_D1RC_not_complete = 0,	/* 0: Data 1 reception has not been completed. */
	RLIN3s_e_D1RC_complete     = 1 	/* 1: Data 1 reception has been completed. */
}RLIN3s_e_D1RC;

/* RLN3nLST.ERR: Error Detection Flag */
typedef enum{
	RLIN3s_e_ERR_no_error = 0,	/* 0: No error has been detected. */
	RLIN3s_e_ERR_error    = 1 	/* 1: Error has been detected. */
}RLIN3s_e_ERR;

/* RLN3nLST.FRC: Successful Response/Wake-up Reception Flag */
typedef enum{
	RLIN3s_e_FRC_not_complete = 0,	/* 0: Response or wake-up reception has not been completed. */
	RLIN3s_e_FRC_complete     = 1 	/* 1: Response or wake-up reception has been completed. */
}RLIN3s_e_FRC;

/* RLN3nLST.FTC: Successful Response/Wake-up Transmission Flag */
typedef enum{
	RLIN3s_e_FTC_not_complete = 0,	/* 0: Response or wake-up transmission has not been completed. */
	RLIN3s_e_FTC_complete     = 1 	/* 1: Response or wake-up transmission has been completed. */
}RLIN3s_e_FTC;

/* RLN3nLEST.RPER: Response Preparation Error Flag */
typedef enum{
	RLIN3s_e_RPER_no_error = 0,	/* 0: Response preparation error has not been detected. */
	RLIN3s_e_RPER_error    = 1 	/* 1: Response preparation error has been detected. */
}RLIN3s_e_RPER;

/* RLN3nLEST.IPER: ID Parity Error Flag */
typedef enum{
	RLIN3s_e_IPER_no_error = 0,	/* 0: ID parity error has not been detected. */
	RLIN3s_e_IPER_error    = 1 	/* 1: ID parity error has been detected. */
}RLIN3s_e_IPER;

/* RLN3nLEST.CSER: Checksum Error Flag */
typedef enum{
	RLIN3s_e_CSER_no_error = 0,	/* 0: Checksum error has not been detected. */
	RLIN3s_e_CSER_error    = 1 	/* 1: Checksum error has been detected. */
}RLIN3s_e_CSER;

/* RLN3nLEST.SFER: Sync Field Error Flag */
typedef enum{
	RLIN3s_e_SFER_no_error = 0,	/* 0: Sync field error has not been detected. */
	RLIN3s_e_SFER_error    = 1 	/* 1: Sync field error has been detected. */
}RLIN3s_e_SFER;

/* RLN3nLEST.FER: Framing Error Flag */
typedef enum{
	RLIN3s_e_FER_no_error = 0,	/* 0: Framing error has not been detected. */
	RLIN3s_e_FER_error    = 1 	/* 1: Framing error has been detected. */
}RLIN3s_e_FER;

/* RLN3nLEST.TER: Timeout Error Flag */
typedef enum{
	RLIN3s_e_TER_no_error = 0,	/* 0: Frame/response timeout error has not been detected. */
	RLIN3s_e_TER_error    = 1 	/* 1: Frame/response timeout error has been detected. */
}RLIN3s_e_TER;

/* RLN3nLEST.BER: Bit Error Flag */
typedef enum{
	RLIN3s_e_BER_no_error = 0,	/* 0: Bit error has not been detected. */
	RLIN3s_e_BER_error    = 1 	/* 1: Bit error has been detected. */
}RLIN3s_e_BER;

/* RLN3nLDFC.LSS: Transmission/Reception Continuation Select */
typedef enum{
	RLIN3s_e_LSS_next_is_last     = 0,	/* 0: The data group to be transmitted/received next is the last one. */
	RLIN3s_e_LSS_next_is_not_last = 1 	/* 1: The data group to be transmitted/received next is not the last one. */
}RLIN3s_e_LSS;

/* RLN3nLDFC.LCS: Checksum Select */
typedef enum{
	RLIN3s_e_LCS_classic_checksum  = 0,	/* 0: Classic checksum */
	RLIN3s_e_LCS_enhanced_checksum = 1 	/* 1: Enhanced checksum */
}RLIN3s_e_LCS;

/* RLN3nLDFC.RCDS: Response Field Communication Direction Select */
typedef enum{
	RLIN3s_e_RCDS_rx = 0,	/* 0: Reception */
	RLIN3s_e_RCDS_tx = 1 	/* 1: Transmission */
}RLIN3s_e_RCDS;

/* RLN3nLDFC.RFDL: Response Field Length Select */
typedef enum{
	RLIN3s_e_RFDL_0_byte  = 0,	/* 0000: 0 byte (+ checksum) */
	RLIN3s_e_RFDL_1_byte  = 1,	/* 0001: 1 byte (+ checksum) */
	RLIN3s_e_RFDL_2_bytes = 2,	/* 0010: 2 bytes (+ checksum) */
	RLIN3s_e_RFDL_3_bytes = 3,	/* : */
	RLIN3s_e_RFDL_4_bytes = 4,	/* 0100: 4 bytes (+ checksum) */
	RLIN3s_e_RFDL_5_bytes = 5,	/* 0101: 5 bytes (+ checksum) */
	RLIN3s_e_RFDL_6_bytes = 6,	/* 0110: 6 bytes (+ checksum) */
	RLIN3s_e_RFDL_7_bytes = 7,	/* 0111: 7 bytes (+ checksum) */
	RLIN3s_e_RFDL_8_bytes = 8 	/* 1000: 8 bytes (+ checksum) */
	                          	/* Settings other than the above are prohibited. */
}RLIN3s_e_RFDL;

/* RLN3nLBSS.SYCC: LIN Sync Field Reception Flag */
typedef enum{
	RLIN3u_e_SYCC_not_complete = 0,	/* 0: LIN Sync Field Rx not completed */
	RLIN3u_e_SYCC_complete     = 1 	/* 1: LIN Sync Field Rx completed successfully */
}RLIN3u_e_SYCC;

/* RLN3nLBSS.BRKC: LIN Break Field Reception Flag */
typedef enum{
	RLIN3u_e_BRKC_not_complete = 0,	/* 0: LIN Break Field Rx not completed */
	RLIN3u_e_BRKC_complete     = 1 	/* 1: LIN Break Field Rx completed successfully */
}RLIN3u_e_BRKC;

/* RLN3nLRSS.RSDD: Response Space Dominant Detection Flag */
typedef enum{
	RLIN3u_e_RSDD_not_detect = 0,	/* 0: No dominant detected. */
	RLIN3u_e_RSDD_detect     = 1 	/* 1: Dominant detected. */
}RLIN3u_e_RSDD;


/*******************************************************************************
* Definition of Register bit value (UART Related Registers)
*******************************************************************************/
/* RLN3nLWBR.NSPB: Bit Sampling Count Select */
typedef enum{
	RLIN3u_e_NSPB_16_samplings   = 0,	/* 0000: 16 samplings */
	RLIN3u_e_NSPB_4_samplings    = 3,	/* 0011: 4 samplings */
	RLIN3u_e_NSPB_6_samplings    = 5,	/* 0101: 6 samplings */
	RLIN3u_e_NSPB_7_samplings    = 6,	/* 0110: 7 samplings */
	RLIN3u_e_NSPB_8_samplings    = 7,	/* 0111: 8 samplings */
	RLIN3u_e_NSPB_9_samplings    = 8,	/* 1000: 9 samplings */
	RLIN3u_e_NSPB_10_samplings   = 9,	/* 1001: 10 samplings */
	RLIN3u_e_NSPB_11_samplings   = 10,	/* 1010: 11 samplings */
	RLIN3u_e_NSPB_12_samplings   = 11,	/* 1011: 12 samplings */
	RLIN3u_e_NSPB_13_samplings   = 12,	/* 1100: 13 samplings */
	RLIN3u_e_NSPB_14_samplings   = 13,	/* 1101: 14 samplings */
	RLIN3u_e_NSPB_15_samplings   = 14,	/* 1110: 15 samplings */
	RLIN3u_e_NSPB_16_samplings_2 = 15 	/* 1111: 16 samplings */
	                                  	/* Settings other than the above are prohibited. */
}RLIN3u_e_NSPB;

/* RLN3nLWBR.LPRS: Prescaler Clock Select */
typedef enum{
	RLIN3u_e_LPRS_div_1   = 0,	/* 000: 1/1 */
	RLIN3u_e_LPRS_div_2   = 1,	/* 001: 1/2 */
	RLIN3u_e_LPRS_div_4   = 2,	/* 010: 1/4 */
	RLIN3u_e_LPRS_div_8   = 3,	/* 011: 1/8 */
	RLIN3u_e_LPRS_div_16  = 4,	/* 100: 1/16 */
	RLIN3u_e_LPRS_div_32  = 5,	/* 101: 1/32 */
	RLIN3u_e_LPRS_div_64  = 6,	/* 110: 1/64 */
	RLIN3u_e_LPRS_div_128 = 7 	/* 111: 1/128 */
}RLIN3u_e_LPRS;

/* RLN3nLMD.LRDNFS: UART Reception Data Noise Filter Disable */
typedef enum{
	RLIN3u_e_LRDNFS_enable  = 0,	/* 0: The noise filter is enabled. */
	RLIN3u_e_LRDNFS_disable = 1 	/* 1: The noise filter is disabled. */
}RLIN3u_e_LRDNFS;

/* RLN3nLMD.LMD: LIN/UART Mode Select */
typedef enum{
	RLIN3u_e_LMD_UART_mode = 1 	/* 01: UART mode */
}RLIN3u_e_LMD;

/* RLN3nLBFC.UTPS: UART Output Polarity Switch */
typedef enum{
	RLIN3u_e_UTPS_non_invert = 0,	/* 0: Transmit data normal output */
	RLIN3u_e_UTPS_invert     = 1 	/* 1: Transmit data with inverted output */
}RLIN3u_e_UTPS;

/* RLN3nLBFC.URPS: UART Input Polarity Switch */
typedef enum{
	RLIN3u_e_URPS_non_invert = 0,	/* 0: Reception data normal input */
	RLIN3u_e_URPS_invert     = 1 	/* 1: Reception data inverted input */
}RLIN3u_e_URPS;

/* RLN3nLBFC.UPS: UART Parity Select */
typedef enum{
	RLIN3u_e_UPS_disable_parity = 0,	/* 00: Parity disabled */
	RLIN3u_e_UPS_even_parity    = 1,	/* 01: Even parity */
	RLIN3u_e_UPS_zero_parity    = 2,	/* 10: 0 Parity */
	RLIN3u_e_UPS_odd_parity     = 3 	/* 11: Odd parity */
}RLIN3u_e_UPS;

/* RLN3nLBFC.USBLS: UART Stop Bit length Select */
typedef enum{
	RLIN3u_e_USBLS_1_stop_bit  = 0,	/* 0: Stop bit: 1 bit */
	RLIN3u_e_USBLS_2_stop_bits = 1 	/* 1: Stop bit: 2 bits */
}RLIN3u_e_USBLS;

/* RLN3nLBFC.UBOS: UART Transfer Format Order Select */
typedef enum{
	RLIN3u_e_UBOS_LSB_first = 0,	/* 0: LSB First */
	RLIN3u_e_UBOS_MSB_first = 1 	/* 1: MSB First */
}RLIN3u_e_UBOS;

/* RLN3nLBFC.UBLS: UART Character Length Select */
typedef enum{
	RLIN3u_e_UBLS_8_bits = 0,	/* 0: UART 8 bits communication */
	RLIN3u_e_UBLS_7_bits = 1 	/* 1: UART 7 bits communication */
}RLIN3u_e_UBLS;

/* RLN3nLBFC.IBS: Inter-Byte Space Select */
typedef enum{
	RLIN3u_e_IBS_0_Tbit  = 0,	/* 00: 0 Tbit */
	RLIN3u_e_IBS_1_Tbit  = 1,	/* 01: 1 Tbit */
	RLIN3u_e_IBS_2_Tbits = 2,	/* 10: 2 Tbits */
	RLIN3u_e_IBS_3_Tbits = 3 	/* 11: 3 Tbits */
}RLIN3u_e_IBS;

/* RLN3nLEDE.FERE: Framing Error Detection Enable*1 */
typedef enum{
	RLIN3u_e_FERE_disable = 0,	/* 0: Disables framing error detection. */
	RLIN3u_e_FERE_enable  = 1 	/* 1: Enables framing error detection. */
}RLIN3u_e_FERE;

/* RLN3nLEDE.OERE: Overrun Error Detection Enable */
typedef enum{
	RLIN3u_e_OERE_disable = 0,	/* 0: Disables overrun error detection. */
	RLIN3u_e_OERE_enable  = 1 	/* 1: Enables overrun error detection. */
}RLIN3u_e_OERE;

/* RLN3nLEDE.BERE: Bit Error Detection Enable */
typedef enum{
	RLIN3u_e_BERE_disable = 0,	/* 0: Disables bit error detection. */
	RLIN3u_e_BERE_enable  = 1 	/* 1: Enables bit error detection. */
}RLIN3u_e_BERE;

/* RLN3nLCUC.OM0: LIN Reset */
typedef enum{
	RLIN3u_e_OM0_LIN_reset_mode   = 0,	/* 0: LIN reset mode. */
	RLIN3u_e_OM0_LIN_reset_cancel = 1 	/* 1: LIN reset mode is canceled. */
}RLIN3u_e_OM0;

/* RLN3nLTRC.RTS: UART Buffer Transmission Start */
typedef enum{
	RLIN3u_e_RTS_stop  = 0,	/* 0: UART Buffer transmission is stopped. */
	RLIN3u_e_RTS_start = 1 	/* 1: UART Buffer transmission is started. */
}RLIN3u_e_RTS;

/* RLN3nLMST.OMM0: LIN Reset Status Monitor */
typedef enum{
	RLIN3u_e_OMM0_LIN_reset_mode     = 0,	/* 0: LIN reset mode. */
	RLIN3u_e_OMM0_not_LIN_reset_mode = 1 	/* 1: Not in LIN reset mode. */
}RLIN3u_e_OMM0;

/* RLN3nLST.URS: Reception Status Flag */
typedef enum{
	RLIN3u_e_URS_stop  = 0,	/* 0: Reception is stopped. */
	RLIN3u_e_URS_start = 1 	/* 1: Reception is started. */
}RLIN3u_e_URS;

/* RLN3nLST.UTS: Transmission Status Flag */
typedef enum{
	RLIN3u_e_UTS_stop  = 0,	/* 0: Transmission is stopped. */
	RLIN3u_e_UTS_start = 1 	/* 1: Transmission is started. */
}RLIN3u_e_UTS;

/* RLN3nLST.ERR: Error Detection Flag */
typedef enum{
	RLIN3u_e_ERR_no_error = 0,	/* 0: No error has been detected. */
	RLIN3u_e_ERR_error    = 1 	/* 1: Error has been detected. */
}RLIN3u_e_ERR;

/* RLN3nLST.FTC: Successful Response/Wake-up Transmission Flag */
typedef enum{
	RLIN3u_e_FTC_not_complete = 0,	/* 0: Response or wake-up transmission has not been completed. */
	RLIN3u_e_FTC_complete     = 1 	/* 1: Response or wake-up transmission has been completed. */
}RLIN3u_e_FTC;

/* RLN3nLEST.UPER: Parity Error Flag */
typedef enum{
	RLIN3u_e_UPER_no_error = 0,	/* 0: Parity error has not been detected. */
	RLIN3u_e_UPER_error    = 1 	/* 1: Parity error has been detected. */
}RLIN3u_e_UPER;

/* RLN3nLEST.IDMT: ID Match Flag */
typedef enum{
	RLIN3u_e_IDMT_not_match = 0,	/* 0: The receive data does not match the ID value. */
	RLIN3u_e_IDMT_match     = 1 	/* 1: The receive data matches the ID value. */
}RLIN3u_e_IDMT;

/* RLN3nLEST.EXBT: Expansion Bit Detection Flag */
typedef enum{
	RLIN3u_e_EXBT_not_detect = 0,	/* 0: Expansion bit has not been detected. */
	RLIN3u_e_EXBT_detect     = 1 	/* 1: Expansion bit has been detected. */
}RLIN3u_e_EXBT;

/* RLN3nLEST.FER: Framing Error Flag */
typedef enum{
	RLIN3u_e_FER_no_error = 0,	/* 0: Framing error has not been detected. */
	RLIN3u_e_FER_error    = 1 	/* 1: Framing error has been detected. */
}RLIN3u_e_FER;

/* RLN3nLEST.OER: Overrun Error Flag */
typedef enum{
	RLIN3u_e_OER_no_error = 0,	/* 0: Overrun error has not been detected. */
	RLIN3u_e_OER_error    = 1 	/* 1: Overrun error has been detected. */
}RLIN3u_e_OER;

/* RLN3nLEST.BER: Bit Error Flag */
typedef enum{
	RLIN3u_e_BER_no_error = 0,	/* 0: Bit error has not been detected. */
	RLIN3u_e_BER_error    = 1 	/* 1: Bit error has been detected. */
}RLIN3u_e_BER;

/* RLN3nLDFC.UTSW: Transmission Start Wait */
typedef enum{
	RLIN3u_e_UTSW_transmit_at_request      = 0,	/* 0: When UART buffer transmission is requested, transmission is started immediately. */
	RLIN3u_e_UTSW_transmit_after_reception = 1 	/* 1: When UART buffer transmission is requested, transmission is not started until reception of the stop bit is completed. */
}RLIN3u_e_UTSW;

/* RLN3nLDFC.MDL: UART Buffer Data Length Select */
typedef enum{
	RLIN3u_e_MDL_9_data   = 0,	/* 0000: 9 data */
	RLIN3u_e_MDL_1_data   = 1,	/* 0001: 1 data */
	RLIN3u_e_MDL_2_data   = 2,	/* 0010: 2 data */
	RLIN3u_e_MDL_3_data   = 3,	/* 0011: 3 data */
	RLIN3u_e_MDL_4_data   = 4,	/* 0100: 4 data (+ checksum) */
	RLIN3u_e_MDL_5_data   = 5,	/* 0101: 5 data (+ checksum) */
	RLIN3u_e_MDL_6_data   = 6,	/* 0110: 6 data (+ checksum) */
	RLIN3u_e_MDL_7_data   = 7,	/* 0111: 7 data */
	RLIN3u_e_MDL_8_data   = 8,	/* 1000: 8 data */
	RLIN3u_e_MDL_9_data_2 = 9 	/* 1001: 9 data */
	                          	/* Settings other than the above are prohibited. */
}RLIN3u_e_MDL;

/* RLN3nLUOER.UROE: Reception Enable */
typedef enum{
	RLIN3u_e_UROE_disable = 0,	/* 0: Disables reception. */
	RLIN3u_e_UROE_enable  = 1 	/* 1: Enables reception. */
}RLIN3u_e_UROE;

/* RLN3nLUOER.UTOE: Transmission Enable */
typedef enum{
	RLIN3u_e_UTOE_disable = 0,	/* 0: Disables transmission. */
	RLIN3u_e_UTOE_enable  = 1 	/* 1: Enables transmission. */
}RLIN3u_e_UTOE;

/* RLN3nLUOER.UECD: Expansion Bit Comparison Disable */
typedef enum{
	RLIN3u_e_UECD_disable = 0,	/* 0: Enables expansion bit comparison. */
	RLIN3u_e_UECD_enable  = 1 	/* 1: Disables expansion bit comparison. */
}RLIN3u_e_UECD;

/* RLN3nLUOER.UTIGTS: Transmission Interrupt Generation Timing Select */
typedef enum{
	RLIN3u_e_UTIGTS_at_tx_start       = 0,	/* 0: Transmission interrupt is generated at the start of transmission. */
	RLIN3u_e_UTIGTS_after_tx_complete = 1 	/* 1: Transmission interrupt is generated at the completion of transmission. */
}RLIN3u_e_UTIGTS;

/* RLN3nLUOER.UEBDCE: Expansion Bit Data Comparison Enable */
typedef enum{
	RLIN3u_e_UEBDCE_disable = 0,	/* 0: Disables data comparison after an expansion bit is detected. */
	RLIN3u_e_UEBDCE_enable  = 1 	/* 1: Enables data comparison after an expansion bit is detected. */
}RLIN3u_e_UEBDCE;

/* RLN3nLUOER.UEBDL: Expansion Bit Detection Level Select */
typedef enum{
	RLIN3u_e_UEBDL_value_0 = 0,	/* 0: Selects expansion bit value 0 as the expansion bit detection level. */
	RLIN3u_e_UEBDL_value_1 = 1 	/* 1: Selects expansion bit value 1 as the expansion bit detection level. */
}RLIN3u_e_UEBDL;

/* RLN3nLUOER.UEBE: Expansion Bit Enable */
typedef enum{
	RLIN3u_e_UEBE_disable = 0,	/* 0: Disables expansion bit operation. */
	RLIN3u_e_UEBE_enable  = 1 	/* 1: Enables expansion bit operation. */
}RLIN3u_e_UEBE;


/*******************************************************************************
* Definition of Register typedef
*******************************************************************************/
/* RLN3nLWBR register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3m_e_LWBR0     	LWBR0     	:1;
		RLIN3m_e_LPRS      	LPRS      	:3;
		RLIN3m_e_NSPB      	NSPB      	:4;
	}BITm;
	struct{
		uint8_t	Reserved_0	:1;
		RLIN3s_e_LPRS      	LPRS      	:3;
		RLIN3s_e_NSPB      	NSPB      	:4;
	}BITs;
	struct{
		uint8_t	Reserved_0	:1;
		RLIN3u_e_LPRS      	LPRS      	:3;
		RLIN3u_e_NSPB      	NSPB      	:4;
	}BITu;
}RLIN3_s_RLN3nLWBR;

/* RLN3nLBRP0 register */
typedef union{
		uint8_t            	UINT8;
	struct{
		uint8_t     	LBRP0     	:8;
	}BITm;
}RLIN3_s_RLN3nLBRP0;

/* RLN3nLBRP1 register */
typedef union{
		uint8_t            	UINT8;
	struct{
		uint8_t     	LBRP1     	:8;
	}BITm;
}RLIN3_s_RLN3nLBRP1;

/* RLN3nLBRP01 register */
typedef union{
		uint16_t            	UINT16;
	struct{
		uint8_t         	L;
		uint8_t         	H;
	}UINT8;
	struct{
		uint16_t       	BRP       	:16;
	}BITs;
	struct{
		uint16_t       	BRP       	:16;
	}BITu;
}RLIN3_s_RLN3nLBRP01;

/* RLN3nLSTC register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3m_e_LSTM      	LSTM      	:1;
		uint8_t         	LSTME     	:6;
		uint8_t         	Reserved_7	:1;
	}BITm;
	struct{
		RLIN3s_e_LSTM      	LSTM      	:1;
		uint8_t         	LSTME     	:6;
		uint8_t         	Reserved_7	:1;
	}BITs;
}RLIN3_s_RLN3nLSTC;

/* RLN3nLMD register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3m_e_LMD       	LMD       	:2;
		RLIN3m_e_LCKS      	LCKS      	:2;
		RLIN3m_e_LIOS      	LIOS      	:1;
		RLIN3m_e_LRDNFS    	LRDNFS    	:1;
		uint8_t	Reserved_6	:2;
	}BITm;
	struct{
		RLIN3s_e_LMD       	LMD       	:2;
		uint8_t	Reserved_2	:2;
		RLIN3s_e_LIOS      	LIOS      	:1;
		RLIN3s_e_LRDNFS    	LRDNFS    	:1;
		uint8_t	Reserved_6	:2;
	}BITs;
	struct{
		RLIN3u_e_LMD       	LMD       	:2;
		uint8_t	Reserved_2	:3;
		RLIN3u_e_LRDNFS    	LRDNFS    	:1;
		uint8_t	Reserved_6	:2;
	}BITu;
}RLIN3_s_RLN3nLMD;

/* RLN3nLBFC register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3m_e_BLT       	BLT       	:4;
		RLIN3m_e_BDT       	BDT       	:2;
		uint8_t	Reserved_6	:2;
	}BITm;
	struct{
		RLIN3s_e_LBLT      	LBLT      	:1;
		uint8_t	Reserved_1	:7;
	}BITs;
	struct{
		RLIN3u_e_UBLS      	UBLS      	:1;
		RLIN3u_e_UBOS      	UBOS      	:1;
		RLIN3u_e_USBLS     	USBLS     	:1;
		RLIN3u_e_UPS       	UPS       	:2;
		RLIN3u_e_URPS      	URPS      	:1;
		RLIN3u_e_UTPS      	UTPS      	:1;
		uint8_t	Reserved_7	:1;
	}BITu;
}RLIN3_s_RLN3nLBFC;

/* RLN3nLSC register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3m_e_IBHS      	IBHS      	:3;
		uint8_t	Reserved_3	:1;
		RLIN3m_e_IBS       	IBS       	:2;
		uint8_t	Reserved_6	:2;
	}BITm;
	struct{
		RLIN3s_e_IBHS      	IBHS      	:3;
		uint8_t	Reserved_3	:1;
		RLIN3s_e_IBS       	IBS       	:2;
		uint8_t	Reserved_6	:2;
	}BITs;
	struct{
		uint8_t	Reserved_3	:4;
		RLIN3u_e_IBS       	IBS       	:2;
		uint8_t	Reserved_6	:2;
	}BITu;
}RLIN3_s_RLN3nLSC;

/* RLN3nLWUP register */
typedef union{
		uint8_t            	UINT8;
	struct{
		uint8_t	Reserved_0	:4;
		RLIN3m_e_WUTL      	WUTL      	:4;
	}BITm;
	struct{
		uint8_t	Reserved_0	:4;
		RLIN3s_e_WUTL      	WUTL      	:4;
	}BITs;
}RLIN3_s_RLN3nLWUP;

/* RLN3nLIE register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3m_e_FTCIE     	FTCIE     	:1;
		RLIN3m_e_FRCIE     	FRCIE     	:1;
		RLIN3m_e_ERRIE     	ERRIE     	:1;
		RLIN3m_e_SHIE      	SHIE      	:1;
		uint8_t	Reserved_4	:4;
	}BITm;
	struct{
		RLIN3s_e_FTCIE     	FTCIE     	:1;
		RLIN3s_e_FRCIE     	FRCIE     	:1;
		RLIN3s_e_ERRIE     	ERRIE     	:1;
		RLIN3s_e_SHIE      	SHIE      	:1;
		uint8_t	Reserved_4	:4;
	}BITs;
}RLIN3_s_RLN3nLIE;

/* RLN3nLEDE register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3m_e_BERE      	BERE      	:1;
		RLIN3m_e_PBERE     	PBERE     	:1;
		RLIN3m_e_FTERE     	FTERE     	:1;
		RLIN3m_e_FERE      	FERE      	:1;
		uint8_t	Reserved_4	:3;
		RLIN3m_e_LTES      	LTES      	:1;
	}BITm;
	struct{
		RLIN3s_e_BERE      	BERE      	:1;
		uint8_t	Reserved_1	:1;
		RLIN3s_e_TERE      	TERE      	:1;
		RLIN3s_e_FERE      	FERE      	:1;
		RLIN3s_e_SFERE     	SFERE     	:1;
		uint8_t	Reserved_5	:1;
		RLIN3s_e_IPERE     	IPERE     	:1;
		RLIN3s_e_LTES      	LTES      	:1;
	}BITs;
	struct{
		RLIN3u_e_BERE      	BERE      	:1;
		uint8_t	Reserved_1	:1;
		RLIN3u_e_OERE      	OERE      	:1;
		RLIN3u_e_FERE      	FERE      	:1;
		uint8_t	Reserved_4	:4;
	}BITu;
}RLIN3_s_RLN3nLEDE;

/* RLN3nLCUC register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3m_e_OM0       	OM0       	:1;
		RLIN3m_e_OM1       	OM1       	:1;
		uint8_t	Reserved_1	:6;
	}BITm;
	struct{
		RLIN3s_e_OM0       	OM0       	:1;
		RLIN3s_e_OM1       	OM1       	:1;
		uint8_t	Reserved_1	:6;
	}BITs;
	struct{
		RLIN3u_e_OM0       	OM0       	:1;
		uint8_t	Reserved_1	:7;
	}BITu;
}RLIN3_s_RLN3nLCUC;

/* RLN3nLTRC register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3m_e_FTS       	FTS       	:1;
		RLIN3m_e_RTS       	RTS       	:1;
		uint8_t	Reserved_2	:6;
	}BITm;
	struct{
		RLIN3s_e_FTS       	FTS       	:1;
		RLIN3s_e_RTS       	RTS       	:1;
		RLIN3s_e_LNRR      	LNRR      	:1;
		uint8_t	Reserved_3	:5;
	}BITs;
	struct{
		uint8_t	Reserved_0	:1;
		RLIN3u_e_RTS       	RTS       	:1;
		uint8_t	Reserved_2	:6;
	}BITu;
}RLIN3_s_RLN3nLTRC;

/* RLN3nLMST register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3m_e_OMM0      	OMM0      	:1;
		RLIN3m_e_OMM1      	OMM1      	:1;
		uint8_t	Reserved_1	:6;
	}BITm;
	struct{
		RLIN3s_e_OMM0      	OMM0      	:1;
		RLIN3s_e_OMM1      	OMM1      	:1;
		uint8_t	Reserved_1	:6;
	}BITs;
	struct{
		RLIN3u_e_OMM0      	OMM0      	:1;
		uint8_t	Reserved_1	:7;
	}BITu;
}RLIN3_s_RLN3nLMST;

/* RLN3nLST register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3m_e_FTC       	FTC       	:1;
		RLIN3m_e_FRC       	FRC       	:1;
		uint8_t	Reserved_2	:1;
		RLIN3m_e_ERR       	ERR       	:1;
		uint8_t	Reserved_4	:2;
		RLIN3m_e_D1RC      	D1RC      	:1;
		RLIN3m_e_HTRC      	HTRC      	:1;
	}BITm;
	struct{
		RLIN3s_e_FTC       	FTC       	:1;
		RLIN3s_e_FRC       	FRC       	:1;
		uint8_t	Reserved_2	:1;
		RLIN3s_e_ERR       	ERR       	:1;
		uint8_t	Reserved_4	:2;
		RLIN3s_e_D1RC      	D1RC      	:1;
		RLIN3s_e_HTRC      	HTRC      	:1;
	}BITs;
	struct{
		RLIN3u_e_FTC       	FTC       	:1;
		uint8_t	Reserved_2	:2;
		RLIN3u_e_ERR       	ERR       	:1;
		RLIN3u_e_UTS       	UTS       	:1;
		RLIN3u_e_URS       	URS       	:1;
		uint8_t	Reserved_6	:2;
	}BITu;
}RLIN3_s_RLN3nLST;

/* RLN3nLEST register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3m_e_BER       	BER       	:1;
		RLIN3m_e_PBER      	PBER      	:1;
		RLIN3m_e_FTER      	FTER      	:1;
		RLIN3m_e_FER       	FER       	:1;
		uint8_t	Reserved_4	:1;
		RLIN3m_e_CSER      	CSER      	:1;
		uint8_t	Reserved_6	:1;
		RLIN3m_e_RPER      	RPER      	:1;
	}BITm;
	struct{
		RLIN3s_e_BER       	BER       	:1;
		uint8_t	Reserved_1	:1;
		RLIN3s_e_TER       	TER       	:1;
		RLIN3s_e_FER       	FER       	:1;
		RLIN3s_e_SFER      	SFER      	:1;
		RLIN3s_e_CSER      	CSER      	:1;
		RLIN3s_e_IPER      	IPER      	:1;
		RLIN3s_e_RPER      	RPER      	:1;
	}BITs;
	struct{
		RLIN3u_e_BER       	BER       	:1;
		uint8_t	Reserved_1	:1;
		RLIN3u_e_OER       	OER       	:1;
		RLIN3u_e_FER       	FER       	:1;
		RLIN3u_e_EXBT      	EXBT      	:1;
		RLIN3u_e_IDMT      	IDMT      	:1;
		RLIN3u_e_UPER      	UPER      	:1;
		uint8_t	Reserved_7	:1;
	}BITu;
}RLIN3_s_RLN3nLEST;

/* RLN3nLDFC register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3m_e_RFDL      	RFDL      	:4;
		RLIN3m_e_RFT       	RFT       	:1;
		RLIN3m_e_CSM       	CSM       	:1;
		RLIN3m_e_FSM       	FSM       	:1;
		RLIN3m_e_LSS       	LSS       	:1;
	}BITm;
	struct{
		RLIN3s_e_RFDL      	RFDL      	:4;
		RLIN3s_e_RCDS      	RCDS      	:1;
		RLIN3s_e_LCS       	LCS       	:1;
		uint8_t	Reserved_6	:1;
		RLIN3s_e_LSS       	LSS       	:1;
	}BITs;
	struct{
		RLIN3u_e_MDL       	MDL       	:4;
		uint8_t	Reserved_4	:1;
		RLIN3u_e_UTSW      	UTSW      	:1;
		uint8_t	Reserved_6	:2;
	}BITu;
}RLIN3_s_RLN3nLDFC;

/* RLN3nLIDB register */
typedef union{
		uint8_t            	UINT8;
	struct{
		uint8_t        	ID        	:6;
		uint8_t      	IDP0      	:1;
		uint8_t      	IDP1      	:1;
	}BITm;
	struct{
		uint8_t        	ID        	:6;
		uint8_t      	IDP0      	:1;
		uint8_t      	IDP1      	:1;
	}BITs;
	struct{
		uint8_t        	ID        	:8;
	}BITu;
}RLIN3_s_RLN3nLIDB;

/* RLN3nLCBR register */
typedef union{
		uint8_t            	UINT8;
	struct{
		uint8_t      	CKSM      	:8;
	}BITm;
	struct{
		uint8_t      	CKSM      	:8;
	}BITu;
}RLIN3_s_RLN3nLCBR;

/* RLN3nLUDB0 register */
typedef union{
		uint8_t            	UINT8;
	struct{
		uint8_t       	UDB       	:8;
	}BITu;
}RLIN3_s_RLN3nLUDB0;

/* RLN3nLDBRb register */
typedef union{
		uint8_t            	UINT8;
	struct{
		uint8_t       	LDB       	:8;
	}BITm;
	struct{
		uint8_t       	LDB       	:8;
	}BITs;
	struct{
		uint8_t       	LDB       	:8;
	}BITu;
}RLIN3_s_RLN3nLDBRb;

/* RLN3nLUOER register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3u_e_UTOE      	UTOE      	:1;
		RLIN3u_e_UROE      	UROE      	:1;
		uint8_t	Reserved_2	:6;
	}BITu;
}RLIN3_s_RLN3nLUOER;

/* RLN3nLUOR1 register */
typedef union{
		uint8_t            	UINT8;
	struct{
		RLIN3u_e_UEBE      	UEBE      	:1;
		RLIN3u_e_UEBDL     	UEBDL     	:1;
		RLIN3u_e_UEBDCE    	UEBDCE    	:1;
		RLIN3u_e_UTIGTS    	UTIGTS    	:1;
		RLIN3u_e_UECD      	UECD      	:1;
		uint8_t	Reserved_5	:3;
	}BITu;
}RLIN3_s_RLN3nLUOR1;

/* RLN3nLUTDR register */
typedef union{
		uint16_t            	UINT16;
	struct{
		uint8_t         	L;
		uint8_t         	H;
	}UINT8;
	struct{
		uint16_t       	UTD       	:9;
		uint16_t	Reserved_9	:7;
	}BITu;
}RLIN3_s_RLN3nLUTDR;

/* RLN3nLURDR register */
typedef union{
		uint16_t            	UINT16;
	struct{
		uint8_t         	L;
		uint8_t         	H;
	}UINT8;
	struct{
		uint16_t       	URD       	:9;
		uint16_t	Reserved_9	:7;
	}BITu;
}RLIN3_s_RLN3nLURDR;

/* RLN3nLUWTDR register */
typedef union{
		uint16_t            	UINT16;
	struct{
		uint8_t         	L;
		uint8_t         	H;
	}UINT8;
	struct{
		uint16_t      	UWTD      	:9;
		uint16_t	Reserved_9	:7;
	}BITu;
}RLIN3_s_RLN3nLUWTDR;

/* RLN3nLBSS register */
typedef union{
		uint8_t            	UINT8;

	struct{
		uint8_t      	BRKC      	:1;
		uint8_t      	SYCC      	:1;
		uint8_t	Reserved_2	:6;
	}BITs;
}RLIN3_s_RLN3nLBSS;

/* RLN3nLRSS register */
typedef union{
		uint8_t            	UINT8;

	struct{
		uint8_t      	RSDD      	:1;
		uint8_t	Reserved_1	:7;
	}BITs;
}RLIN3_s_RLN3nLRSS;


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_RLIN3_reg_H__ */

