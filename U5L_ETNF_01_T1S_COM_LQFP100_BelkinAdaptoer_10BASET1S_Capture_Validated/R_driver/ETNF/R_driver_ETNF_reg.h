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
* File Name    : R_driver_ETNF_reg.h
* Version      : 1.00
* Module(s)    : ETNF
* Device(s)    : R-Car U5L product
* Description  : Register definition of RLIN3 that is used commonly by R-Car products
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_ETNF_reg_H__
#define	__R_driver_ETNF_reg_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"
#include "R_device_ETNF.h"    	/* Product-specific definition */


/*******************************************************************************
* Register Base Address Definitions
*******************************************************************************/


/*******************************************************************************
* Definition of register symbol
*******************************************************************************/

/* Register */
#define	rETNFnRIMR(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x008C) )	/* RMII Interface Mode Register */
#define	rETNFnCCC(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0000) )	/* AVB-DMAC Mode Register */
#define	rETNFnDBAT(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0004) )	/* Descriptor Base Address Table Register */
#define	rETNFnDLR(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0008) )	/* Descriptor Base Address Load Request Register */
#define	rETNFnCSR(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x000C) )	/* AVB-DMAC Status Register */
#define	rETNFnCDARq(n, q)	(*(volatile uint32_t *) (ETNFn_base(n) + ( 0x0010 + ( 0x4 * q ) ) ) )	/* Current Descriptor Address Register q (q = 0 to 21) */
#define	rETNFnESR(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0088) )	/* Error Status Register */
#define	rETNFnRCR(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0090) )	/* Receive Configuration Register */
#define	rETNFnRQCi(n, i) 	(*(volatile uint32_t *) (ETNFn_base(n) + ( 0x0094 + ( 0x4 * (i) ) ) ) )	/* Receive Queue Configuration Register i (i = 0 to 4) */
#define	rETNFnRPC(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x00B0) )	/* Receive Padding Configuration Register */
#define	rETNFnUFCW(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x00BC) )	/* Unread Frame Counter Warning Level Register */
#define	rETNFnUFCS(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x00C0) )	/* Unread Frame Counter Stop Level Configuration Register */
#define	rETNFnUFCVi(n, i)	(*(volatile uint32_t *) (ETNFn_base(n) + ( 0x00C4 + ( 0x4 * (i) ) ) ) )	/* Unread Frame Counter Register i (i = 0 to 4) */
#define	rETNFnUFCDi(n, i)	(*(volatile uint32_t *) (ETNFn_base(n) + ( 0x00E0 + ( 0x4 * (i) ) ) ) )	/* Unread Frame Counter Decrement Register i (i = 0 to 4) */
#define	rETNFnSFO(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x00FC) )	/* Separation Filter Offset Register */
#define	rETNFnSFPi(n, i) 	(*(volatile uint32_t *) (ETNFn_base(n) + ( 0x0100 + ( 0x4 * (i) ) ) ) )	/* Separation Filter Pattern Register i (i = 0 to 31) */
#define	rETNFnSFVi(n, i) 	(*(volatile uint32_t *) (ETNFn_base(n) + ( 0x01B8 + ( 0x4 * (i) ) ) ) )	/* Separation Filter Value register i (i = 0 or 1) */
#define	rETNFnSFMi(n, i) 	(*(volatile uint32_t *) (ETNFn_base(n) + ( 0x01C0 + ( 0x4 * (i) ) ) ) )	/* Separation Filter Mask Register i (i = 0 or 1) */
#define	rETNFnSFL(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x01C8) )	/* Separation Filter Load Register */
#define	rETNFnPCRC(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x01CC) )	/* Payload CRC Register */
#define	rETNFnTGC(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0300) )	/* Transmit Configuration Register */
#define	rETNFnTCCR(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0304) )	/* Transmit Configuration Control Register */
#define	rETNFnTSR(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0308) )	/* Transmit Status Register */
#define	rETNFnTFA0(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0310) )	/* Timestamp FIFO Access Register 0 */
#define	rETNFnTFA1(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0314) )	/* Timestamp FIFO Access Register 1 */
#define	rETNFnTFA2(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0318) )	/* Timestamp FIFO Access Register 2 */
#define	rETNFnVRR(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x031C) )	/* AVB-DMAC Version Register */

#define	rETNFnCIVRc(n, c)	(*(volatile uint32_t *) (ETNFn_base(n) + ( 0x0320 + ( 0x4 * (c) ) ) ) )	/* CBS Increment Value Register c (c = 0 or 1) */
#define	rETNFnCDVRc(n, c)	(*(volatile uint32_t *) (ETNFn_base(n) + ( 0x0328 + ( 0x4 * (c) ) ) ) )	/* CBS Decrement Value Register c (c = 0 or 1) */
#define	rETNFnCULc(n, c) 	(*(volatile uint32_t *) (ETNFn_base(n) + ( 0x0330 + ( 0x4 * (c) ) ) ) )	/* CBS Upper Limit Register c (c = 0 or 1) */
#define	rETNFnCLLc(n, c) 	(*(volatile uint32_t *) (ETNFn_base(n) + ( 0x0338 + ( 0x4 * (c) ) ) ) )	/* CBS Lower Limit Register c (c = 0 or 1) */

#define	rETNFnDIC(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0350) )	/* Descriptor Interrupt Control Register */
#define	rETNFnDIS(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0354) )	/* Descriptor Interrupt Status Register */

#define	rETNFnMAHR(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x05C0) )	/* MAC Address High Register */
#define	rETNFnMALR(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x05C8) )	/* MAC Address Low Register */

#define	rETNFnECMR(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0500) )	/* E-MAC Mode Register */
#define	rETNFnRFLR(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0508) )	/* Receive Frame Length Register */
#define	rETNFnECSR(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0510) )	/* E-MAC Status Register */
#define	rETNFnECSIPR(n)  	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0518) )	/* E-MAC Interrupt Permission Register */

#define	rETNFnPIR(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0520) )	/* PHY Interface Register */

#define	rETNFnRIC0(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0360) )	/* Receive Interrupt Control Register 0 */
#define	rETNFnRIS0(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0364) )	/* Receive Interrupt Status Register 0 */
#define	rETNFnRIC1(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0368) )	/* Receive Interrupt Control Register 1 */
#define	rETNFnRIS1(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x036C) )	/* Receive Interrupt Status Register 1 */
#define	rETNFnRIC2(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0370) )	/* Receive Interrupt Control Register 2 */
#define	rETNFnRIS2(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0374) )	/* Receive Interrupt Status Register 2 */
#define	rETNFnRIC3(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0388) )	/* Receive Interrupt Control Register 3 */
#define	rETNFnRIS3(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x038C) )	/* Receive Interrupt Status Register 3 */

#define	rETNFnTIC(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0378) )	/* Transmit Interrupt Control Register */
#define	rETNFnTIS(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x037C) )	/* Transmit Interrupt Status Register */

#define	rETNFnGTI(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x039C) )	/* gPTP Timer Increment Configuration Register */
#define	rETNFnGTO0(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x03A0) )	/* gPTP Timer Offset Configuration Register i (i = 0 to 2) */
#define	rETNFnGTO1(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x03A4) )	/* gPTP Timer Offset Configuration Register i (i = 0 to 2) */
#define	rETNFnGTO2(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x03A8) )	/* gPTP Timer Offset Configuration Register i (i = 0 to 2) */
#define	rETNFnGCCR(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0390) )	/* gPTP Configuration Control Register */
#define	rETNFnGCT0(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x03B8) )	/* gPTP Timer Capture Register i (i = 0 to 2) */
#define	rETNFnGCT1(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x03BC) )	/* gPTP Timer Capture Register i (i = 0 to 2) */
#define	rETNFnGCT2(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x03C0) )	/* gPTP Timer Capture Register i (i = 0 to 2) */

#define	rETNFnGMTT(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0394) )	/* gPTP Maximum Transit Time Configuration Register */
#define	rETNFnGPTC(n)    	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0398) )	/* gPTP Presentation Time Comparison Register */
#define	rETNFnGIC(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x03AC) )	/* gPTP Interrupt Control Register */
#define	rETNFnGIS(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x03B0) )	/* gPTP Interrupt Status Register */
#define	rETNFnGSR(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x03C4) )	/* gPTP Status Register */
#define	rETNFnGPTFi(n, i)	(*(volatile uint32_t *) (ETNFn_base(n) + ( 0x03E0 + ( 0x4 * (i) ) ) ) )	/* gPTP Presentation Time FIFO Register i (i = 0 to 3) */

#define	rETNFnCEFCR(n)     	(*(volatile uint32_t *) (ETNFn_base(n) + 0x0740) )	/* CRC Error Frame Receive Counter Register */

#define	rETNFnT1SCTL0(n) 	(*(volatile uint32_t *) (ETNFn_T1S_base(n) + 0x0000) )	/* T1S control register 0 */

/* ETNFnPIR PHY Interface Register */
#define ETNFnPIR_MDC_SHIFT	0
#define ETNFnPIR_MDC_MASK 	(0x1U << ETNFnPIR_MDC_SHIFT)
#define ETNFnPIR_MDC(x)   	(((uint32_t)(x) << ETNFnPIR_MDC_SHIFT) & ETNFnPIR_MDC_MASK)

#define ETNFnPIR_MMD_SHIFT	1
#define ETNFnPIR_MMD_MASK 	(0x1U << ETNFnPIR_MMD_SHIFT)
#define ETNFnPIR_MMD(x)   	(((uint32_t)(x) << ETNFnPIR_MMD_SHIFT) & ETNFnPIR_MMD_MASK)

#define ETNFnPIR_MDO_SHIFT	2
#define ETNFnPIR_MDO_MASK 	(0x1U << ETNFnPIR_MDO_SHIFT)
#define ETNFnPIR_MDO(x)   	(((uint32_t)(x) << ETNFnPIR_MDO_SHIFT) & ETNFnPIR_MDO_MASK)

#define ETNFnPIR_MDI_SHIFT	3
#define ETNFnPIR_MDI_MASK 	(0x1U << ETNFnPIR_MDI_SHIFT)
#define ETNFnPIR_MDI(x)   	(((uint32_t)(x) << ETNFnPIR_MDI_SHIFT) & ETNFnPIR_MDI_MASK)

/*******************************************************************************
* Definition of Register bit value (LIN Master Related Registers)
*******************************************************************************/
/* ETNFnRIMR.TSEL: Time stamp select */
typedef enum{
	ETNF_e_TSEL_MII_TS  = 0,	/* 0: MII timestamp select (default) */
	ETNF_e_TSEL_T1S_TS  = 1 	/* 1: T1S timestamp select */
}ETNF_e_TSEL;

/* ETNFnRIMR.SPEED: RMII Transfer Rate */
typedef enum{
	ETNF_e_SPEED_10Mbps  = 0,	/* 0: 10 Mbps */
	ETNF_e_SPEED_100Mbps  = 1 	/* 1: 100 Mbps */
}ETNF_e_SPEED;

/* ETNFnCCC.FCE: Flow Control Enable */
typedef enum{
	ETNF_e_FCE_disable = 0,	/* 0: Flow control disabled */
	ETNF_e_FCE_enable  = 1 	/* 1: Flow control enabled */
}ETNF_e_FCE;

/* ETNFnCCC.LBME: Loopback Mode Enable */
typedef enum{
	ETNF_e_LBME_disable = 0,	/* 0: Normal operation */
	ETNF_e_LBME_enable  = 1 	/* 1: Loopback mode is enabled. */
}ETNF_e_LBME;

/* ETNFnCCC.BOC: Byte Order Configuration */
typedef enum{
	ETNF_e_BOC_7_0   = 0,	/* 0: First Ethernet byte in URAM[7:0] */
	ETNF_e_BOC_31_24 = 1 	/* 1: First Ethernet byte in URAM[31:24] */
}ETNF_e_BOC;

/* ETNFnCCC.CSEL[17:16]: gPTP Clock Select */
typedef enum{
	ETNF_e_CSEL_gPTP_not_use = 0,	/* 00B: gPTP is not in use. */
	ETNF_e_CSEL_tx_clock     = 1,	/* 10B: Ethernet transmission clock */
	ETNF_e_CSEL_gPTP_clock   = 2,	/* 11B: gPTP clock soure */
	ETNF_e_CSEL_prohibited   = 3 	/* Other settings are prohibited */
}ETNF_e_CSEL;

/* ETNFnCCC.DTSR: Data Transfer Suspend Request */
typedef enum{
	ETNF_e_DTSR_no_request_suspend = 0,	/* 0: Normal operation */
	ETNF_e_DTSR_request_suspend    = 1 	/* 1: Requests suspension */
}ETNF_e_DTSR;

/* ETNFnCCC.GAC: gPTP Active in Config */
typedef enum{
	ETNF_e_GAC_inactive_in_conf = 0,	/* 0: Normal operation */
	ETNF_e_GAC_active_in_conf   = 1 	/* 1: gPTP support active in configuration mode */
}ETNF_e_GAC;

/* ETNFnCCC.OPC[1:0]: Operating Mode Configuration */
typedef enum{
	ETNF_e_OPC_reset_mode     = 0,	/* 00B: Reset mode */
	ETNF_e_OPC_config_mode    = 1,	/* 01B: Configuration mode */
	ETNF_e_OPC_operation_mode = 2,	/* 10B: Operation mode */
	ETNF_e_OPC_standby_mode   = 3 	/* 11B: Standby mode */
}ETNF_e_OPC;

/* ETNFnCSR.TDUO: Transmission Descriptor Update On-going */
typedef enum{
	ETNF_e_TDUO_no_pending_desc_update = 0,	/* 0: No pending descriptor update */
	ETNF_e_TDUO_pending_desc_update    = 1 	/* 1: Pending descriptor update in URAM */
}ETNF_e_TDUO;

/* ETNFnCSR.RPO: Receive Process Status */
typedef enum{
	ETNF_e_RPO_rx_no_progress = 0,	/* 0: Normal operation */
	ETNF_e_RPO_rx_in_progress = 1 	/* 1: Reception is in progress. */
}ETNF_e_RPO;

/* ETNFnCSR.TPO3: Transmit Process Status 3 (Stream Class A) */
typedef enum{
	ETNF_e_TPO3_tx_no_progress = 0,	/* 0: Normal operation */
	ETNF_e_TPO3_tx_in_progress = 1 	/* 1: Transmission is in progress. */
}ETNF_e_TPO3;

/* ETNFnCSR.TPO2: Transmit Process Status 2 (Stream Class B) */
typedef enum{
	ETNF_e_TPO2_tx_no_progress = 0,	/* 0: Normal operation */
	ETNF_e_TPO2_tx_in_progress = 1 	/* 1: Transmission is in progress. */
}ETNF_e_TPO2;

/* ETNFnCSR.TPO1: Transmit Process Status 1 (Network Control) */
typedef enum{
	ETNF_e_TPO1_tx_no_progress = 0,	/* 0: Normal operation */
	ETNF_e_TPO1_tx_in_progress = 1 	/* 1: Transmission is in progress. */
}ETNF_e_TPO1;

/* ETNFnCSR.TPO0: Transmit Process Status 0 (Best Effort) */
typedef enum{
	ETNF_e_TPO0_tx_no_progress = 0,	/* 0: Normal operation */
	ETNF_e_TPO0_tx_in_progress = 1 	/* 1: Transmission is in progress. */
}ETNF_e_TPO0;

/* ETNFnCSR.DTS: Data Transmission Suspended Status */
typedef enum{
	ETNF_e_DTS_tx_no_suspend = 0,	/* 0: Normal operation */
	ETNF_e_DTS_tx_in_suspend = 1 	/* 1: Transmission is suspended. */
}ETNF_e_DTS;

/* ETNFnCSR.OPS[3:0]: Operating Mode Status */
typedef enum{
	ETNF_e_OPS_reset_mode     = 1,	/* 0001B: Reset mode */
	ETNF_e_OPS_config_mode    = 2,	/* 0010B: Configuration mode */
	ETNF_e_OPS_operation_mode = 4,	/* 0100B: Operation mode */
	ETNF_e_OPS_standby_mode   = 8 	/* 1000B: Standby mode */
}ETNF_e_OPS;

/* ETNFnESR.EIL: Error Information Lost */
typedef enum{
	ETNF_e_EIL_no_lost_error = 0,	/* 0: No loss of error information */
	ETNF_e_EIL_lost_error    = 1 	/* 1: Lost of error information detected */
}ETNF_e_EIL;

/* ETNFnESR.ET[11:8]: Error Type */
typedef enum{
	ETNF_e_ET_read_desc_from_URAM   = 0x0,	/* 0000B: Read descriptor from URAM */
	ETNF_e_ET_write_desc_to_URAM    = 0x1,	/* 0001B: Write descriptor to URAM */
	ETNF_e_ET_interpret_read_desc   = 0x2,	/* 0010B: Interpret read descriptor */
	ETNF_e_ET_txbuf_corrupt         = 0x3,	/* 0011B: Tx-Buffer is corrupted */
	ETNF_e_ET_read_data_from_URAM   = 0x4,	/* 0100B: Read data from URAM */
	ETNF_e_ET_write_data_ts_to_URAM = 0x5,	/* 0101B: Write data or timestamp to URAM */
	ETNF_e_ET_read_RXFIFO           = 0x6,	/* 0110B: Reading from received FIFO */
	ETNF_e_ET_RXFIFO_corrupt        = 0x7,	/* 0111B: Received FIFO is corrupted */
	ETNF_e_ET_rx_frame_size_error   = 0x8,	/* 1000B: Frame size error during reception detected */
	ETNF_e_ET_tx_frame_size_error   = 0x9,	/* 1001B: Frame size error during transmission detected */
	ETNF_e_ET_txbuf_overflow        = 0xA,	/* 0001B: Write descriptor to URAM */
	ETNF_e_ET_AVTPFIFO_error        = 0xB 	/* 0010B: Interpret read descriptor */
}ETNF_e_ET;

/* ETNFnRCR.ETS2: Timestamp Enable (Stream) */
typedef enum{
	ETNF_e_ETS2_disable = 0,	/* 0: Stream Timestamp is disabled. */
	ETNF_e_ETS2_enable  = 1 	/* 1: Stream Timestamp is enabled. */
}ETNF_e_ETS2;

/* ETNFnRCR.ETS0: Timestamp Enable (Best Effort) */
typedef enum{
	ETNF_e_ETS0_disable = 0,	/* 0: Best Effort Timestamp is disabled. */
	ETNF_e_ETS0_enable  = 1 	/* 1: Best Effort Timestamp is enabled. */
}ETNF_e_ETS0;

/* ETNFnRCR.ESF[3:2]: Stream Filtering Select */
typedef enum{
	ETNF_e_ESF_disable                  = 0,	/* 00B: Filtering is disabled. Frames are processed in queue 0 (best effort). */
	ETNF_e_ESF_separating_enable_queue0 = 1,	/* 01B: The filter for separating AVB stream frames from non-AVB stream frames is enabled; non-matching stream frames are processed in queue 0 (best effort). */
	ETNF_e_ESF_enable_discard           = 2,	/* 10B: The separation filter is enabled for AVB stream frames. Non-matching stream frames are discarded. */
	ETNF_e_ESF_enable_queue0            = 3 	/* 11B: The separation filter is enabled for AVB stream frames. Non-matching stream frames are handled with queue 0 (best effort). */
}ETNF_e_ESF;

/* ETNFnRCR.ENCF: Network Control Filtering Enable */
typedef enum{
	ETNF_e_ENCF_disable = 0,	/* 0: Network control is disabled. */
	ETNF_e_ENCF_enable  = 1 	/* 1: Network control is enabled. */
}ETNF_e_ENCF;

/* ETNFnRCR.EFFS: Error Frame Enable */
typedef enum{
	ETNF_e_EFFS_disable = 0,	/* 0: Error frames are disabled. */
	ETNF_e_EFFS_enable  = 1 	/* 1: Error frames are enabled. */
}ETNF_e_EFFS;

/* ETNFnRQCi.PIAr: Packed Incremental Data Area */
typedef enum{
	ETNF_e_PIA_word_align = 0,	/* 0: frame data in incremental data area starts always at a 32 bit address. */
	ETNF_e_PIA_no_align   = 1 	/* 1: there will no gaps generated between two frames in incremental data area. */
}ETNF_e_PIA;

/* ETNFnRQCi.UFCCr: Unread Frame Counter Configuration */
typedef enum{
	ETNF_e_UFCC_stop_level_0 = 0,	/* 00B: use ETNFnUFCS.SL0 as stop level */
	ETNF_e_UFCC_stop_level_1 = 1,	/* 01B: use ETNFnUFCS.SL0 as stop level */
	ETNF_e_UFCC_stop_level_2 = 2,	/* 10B: use ETNFnUFCS.SL0 as stop level */
	ETNF_e_UFCC_stop_level_3 = 3 	/* 11B: use ETNFnUFCS.SL0 as stop level */
}ETNF_e_UFCC;

/* ETNFnRQCi.RSMr */
typedef enum{
	ETNF_e_RSM_write_back = 0,	/* 00B: Mode with write-back */
	ETNF_e_RSM_prohibit1  = 1,	/* 01B: Setting prohibited */
	ETNF_e_RSM_prohibit2  = 2,	/* 02B: Setting prohibited */
	ETNF_e_RSM_prohibit3  = 3	/* 03B: Setting prohibited */
}ETNF_e_RSM;

/* ETNFnSFL.LC[4:0]: Load Command */
typedef enum{
	ETNF_e_LC_load_FP0        = 0,	/* 0: Load of ETNF0SFPi.FP0 */
	ETNF_e_LC_load_FP1        = 1,	/* 1: Load of ETNF0SFPi.FP1 */
	ETNF_e_LC_load_FP2        = 2,	/* 2: Load of ETNF0SFPi.FP2 */
	ETNF_e_LC_load_FP3        = 3,	/* 3: Load of ETNF0SFPi.FP3 */
	ETNF_e_LC_load_FP4        = 4,	/* 4: Load of ETNF0SFPi.FP4 */
	ETNF_e_LC_load_FP5        = 5,	/* 5: Load of ETNF0SFPi.FP5 */
	ETNF_e_LC_load_FP6        = 6,	/* 6: Load of ETNF0SFPi.FP6 */
	ETNF_e_LC_load_FP7        = 7,	/* 7: Load of ETNF0SFPi.FP7 */
	ETNF_e_LC_load_FP8        = 8,	/* 8: Load of ETNF0SFPi.FP8 */
	ETNF_e_LC_load_FP9        = 9,	/* 9: Load of ETNF0SFPi.FP9 */
	ETNF_e_LC_load_FP10       = 10,	/* 10: Load of ETNF0SFPi.FP10 */
	ETNF_e_LC_load_FP11       = 11,	/* 11: Load of ETNF0SFPi.FP11 */
	ETNF_e_LC_load_FP12       = 12,	/* 12: Load of ETNF0SFPi.FP12 */
	ETNF_e_LC_load_FP13       = 13,	/* 13: Load of ETNF0SFPi.FP13 */
	ETNF_e_LC_load_FP14       = 14,	/* 14: Load of ETNF0SFPi.FP14 */
	ETNF_e_LC_load_FP15       = 15,	/* 15: Load of ETNF0SFPi.FP15 */
	ETNF_e_LC_load_CFM        = 29,	/* 29: Load of ETNF0SFMi.CFM */
	ETNF_e_LC_load_FBP        = 30,	/* 30: Load of ETNF0SFO.FBP */
	ETNF_e_LC_no_pending_load = 31 	/* 31: No pending load request */
}ETNF_e_LC;

/* ETNFnTGC.TQP[5:4]: Transmit Queue Priority */
typedef enum{
	ETNF_e_TQP_non_AVB_mode = 0,	/* 00: Non-AVB mode */
	ETNF_e_TQP_AVB_mode_1   = 1,	/* 01: AVB mode 1 */
	ETNF_e_TQP_prohibited   = 2,	/* 10: Setting prohibited */
	ETNF_e_TQP_AVB_mode_2   = 3 	/* 11: AVB mode 2 */
}ETNF_e_TQP;

/* ETNFnTGC.TSM3: Transmit Synchronous Mode (Stream Class A) */
typedef enum{
	ETNF_e_TSM3_with_write_back = 0,	/* 0: With write-back */
	ETNF_e_TSM3_prohibited      = 1 	/* 1: Setting prohibited */
}ETNF_e_TSM3;

/* ETNFnTGC.TSM2: Transmit Synchronous Mode (Stream Class B) */
typedef enum{
	ETNF_e_TSM2_with_write_back = 0,	/* 0: With write-back */
	ETNF_e_TSM2_prohibited      = 1 	/* 1: Setting prohibited */
}ETNF_e_TSM2;

/* ETNFnTGC.TSM1: Transmit Synchronous Mode (Network Control) */
typedef enum{
	ETNF_e_TSM1_with_write_back = 0,	/* 0: With write-back */
	ETNF_e_TSM1_prohibited      = 1 	/* 1: Setting prohibited */
}ETNF_e_TSM1;

/* ETNFnTGC.TSM0: Transmit Synchronous Mode (Best Effort) */
typedef enum{
	ETNF_e_TSM0_with_write_back = 0,	/* 0: With write-back */
	ETNF_e_TSM0_prohibited      = 1 	/* 1: Setting prohibited */
}ETNF_e_TSM0;

/* ETNFnTCCR.MFR: MAC status FIFO Release */
typedef enum{
	ETNF_e_MFR_no_request           = 0,	/* 0: No request to MAC status FIFO */
	ETNF_e_MFR_release_oldest_entry = 1 	/* 1: Release oldest entry of MAC status FIFO */
}ETNF_e_MFR;

/* ETNFnTCCR.MFEN: MAC status FIFO Enable */
typedef enum{
	ETNF_e_MFEN_disable = 0,	/* 0: Disabled */
	ETNF_e_MFEN_enable  = 1 	/* 1: Enabled */
}ETNF_e_MFEN;

/* ETNFnTCCR.TFR: Timestamp FIFO Release */
typedef enum{
	ETNF_e_TFR_no_operate           = 0,	/* 0: (Not operating) */
	ETNF_e_TFR_release_oldest_entry = 1 	/* 1: Releases the oldest entry in the timestamp FIFO. */
}ETNF_e_TFR;

/* ETNFnTCCR.TFEN: Timestamp FIFO Enable */
typedef enum{
	ETNF_e_TFEN_disable = 0,	/* 0: Recording of transmission timestamps in the timestamp FIFO is disabled. */
	ETNF_e_TFEN_enable  = 1 	/* 1: Recording of transmission timestamps in the timestamp FIFO is enabled. */
}ETNF_e_TFEN;

/* ETNFnTCCR.TSRQ3: Transmit Start Request (Queue 3 (Stream Class A)) */
typedef enum{
	ETNF_e_TSRQ3_empty_or_stop = 0,	/* 0: Transmission queue is empty or stopped. */
	ETNF_e_TSRQ3_start_request = 1 	/* 1: When written: A transmission start request is issued. */
}ETNF_e_TSRQ3;

/* ETNFnTCCR.TSRQ2: Transmit Start Request (Queue 2 (Stream Class B)) */
typedef enum{
	ETNF_e_TSRQ2_empty_or_stop = 0,	/* 0: Transmission queue is empty or stopped. */
	ETNF_e_TSRQ2_start_request = 1 	/* 1: When written: A transmission start request is issued. */
}ETNF_e_TSRQ2;

/* ETNFnTCCR.TSRQ1: Transmit Start Request (Queue 1 (Network Control)) */
typedef enum{
	ETNF_e_TSRQ1_empty_or_stop = 0,	/* 0: Transmission queue is empty or stopped. */
	ETNF_e_TSRQ1_start_request = 1 	/* 1: When written: A transmission start request is issued. */
}ETNF_e_TSRQ1;

/* ETNFnTCCR.TSRQ0: Transmit Start Request (Queue 0 (Best Effort)) */
typedef enum{
	ETNF_e_TSRQ0_empty_or_stop = 0,	/* 0: Transmission queue is empty or stopped. */
	ETNF_e_TSRQ0_start_request = 1 	/* 1: When written: A transmission start request is issued. */
}ETNF_e_TSRQ0;

/* ETNFnTSR.CCS1[3:2]: CBS Counter Status 1 (Class A) */
typedef enum{
	ETNF_e_CCS1_within_the_range       = 0,	/* 00B: The current credit value is within the range. */
	ETNF_e_CCS1_less_or_equal_limit    = 1,	/* 01B: The current credit value is less than or equal to the lower limit. */
	ETNF_e_CCS1_greater_or_equal_limit = 2,	/* 10B: The current credit value is greater than or equal to the upper limit. */
	ETNF_e_CCS1_reserved               = 3 	/* 11B: (Reserved) */
}ETNF_e_CCS1;

/* ETNFnTSR.CCS0[1:0]: CBS Counter Status 0 (Class B) */
typedef enum{
	ETNF_e_CCS0_within_the_range       = 0,	/* 00B: The current credit value is within the range. */
	ETNF_e_CCS0_less_or_equal_limit    = 1,	/* 01B: The current credit value is less than or equal to the lower limit. */
	ETNF_e_CCS0_greater_or_equal_limit = 2,	/* 10B: The current credit value is greater than or equal to the upper limit. */
	ETNF_e_CCS0_reserved               = 3 	/* 11B: (Reserved) */
}ETNF_e_CCS0;

/* ETNFnDIC.DPEx: Descriptor Interrupt Enable x */
typedef enum{
	ETNF_e_DPEx_disable = 0,	/* 0: Disabled */
	ETNF_e_DPEx_enable  = 1 	/* 1: Enabled */
}ETNF_e_DPEx;

/* ETNFnDIS.DPFx: Descriptor Interrupt Status x */
typedef enum{
	ETNF_e_DPFx_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_DPFx_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_DPFx;

/* ETNFnEIC.TBFE: Tx-Buffer Full Interrupt Enable */
typedef enum{
	ETNF_e_TBFE_disable = 0,	/* 0: Disabled */
	ETNF_e_TBFE_enable  = 1 	/* 1: Enabled */
}ETNF_e_TBFE;

/* ETNFnEIC.MFFE: MAC Status FIFO Full Interrupt Enable */
typedef enum{
	ETNF_e_MFFE_disable = 0,	/* 0: Disabled */
	ETNF_e_MFFE_enable  = 1 	/* 1: Enabled */
}ETNF_e_MFFE;

/* ETNFnEIC.TFFE: Timestamp FIFO Full-Error Interrupt Enable */
typedef enum{
	ETNF_e_TFFE_disable = 0,	/* 0: Disabled */
	ETNF_e_TFFE_enable  = 1 	/* 1: Enabled */
}ETNF_e_TFFE;

/* ETNFnEIC.CULE1: CBS Upper Limit Error Interrupt Enable (Class A) */
typedef enum{
	ETNF_e_CULE1_disable = 0,	/* 0: Disabled */
	ETNF_e_CULE1_enable  = 1 	/* 1: Enabled */
}ETNF_e_CULE1;

/* ETNFnEIC.CULE0: CBS Upper Limit Error Interrupt Enable (Class B) */
typedef enum{
	ETNF_e_CULE0_disable = 0,	/* 0: Disabled */
	ETNF_e_CULE0_enable  = 1 	/* 1: Enabled */
}ETNF_e_CULE0;

/* ETNFnEIC.CLLE1: CBS Lower Limit Error Interrupt Enable (Class A) */
typedef enum{
	ETNF_e_CLLE1_disable = 0,	/* 0: Disabled */
	ETNF_e_CLLE1_enable  = 1 	/* 1: Enabled */
}ETNF_e_CLLE1;

/* ETNFnEIC.CLLE0: CBS Lower Limit Error Interrupt Enable (Class B) */
typedef enum{
	ETNF_e_CLLE0_disable = 0,	/* 0: Disabled */
	ETNF_e_CLLE0_enable  = 1 	/* 1: Enabled */
}ETNF_e_CLLE0;

/* ETNFnEIC.SEE: Separation Error interrupt Enable */
typedef enum{
	ETNF_e_SEE_disable = 0,	/* 0: Disabled */
	ETNF_e_SEE_enable  = 1 	/* 1: Enabled */
}ETNF_e_SEE;

/* ETNFnEIC.QEE: Queue Error interrupt Enable */
typedef enum{
	ETNF_e_QEE_disable = 0,	/* 0: Disabled */
	ETNF_e_QEE_enable  = 1 	/* 1: Enabled */
}ETNF_e_QEE;

/* ETNFnEIC.MTEE: MAC Transmission Error interrupt Enable */
typedef enum{
	ETNF_e_MTEE_disable = 0,	/* 0: Disabled */
	ETNF_e_MTEE_enable  = 1 	/* 1: Enabled */
}ETNF_e_MTEE;

/* ETNFnEIC.MREE: MAC Reception Error interrupt Enable */
typedef enum{
	ETNF_e_MREE_disable = 0,	/* 0: Disabled */
	ETNF_e_MREE_enable  = 1 	/* 1: Enabled */
}ETNF_e_MREE;

/* ETNFnEIS.QFS: Queue Full Summary */
typedef enum{
	ETNF_e_QFS_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_QFS_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_QFS;

/* ETNFnEIS.TBFF: Tx-Buffer Full Flag */
typedef enum{
	ETNF_e_TBFF_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_TBFF_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_TBFF;

/* ETNFnEIS.MFFF: MAC Status FIFO Full Flag */
typedef enum{
	ETNF_e_MFFF_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_MFFF_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_MFFF;

/* ETNFnEIS.TFFF: Timestamp FIFO Full Flag */
typedef enum{
	ETNF_e_TFFF_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_TFFF_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_TFFF;

/* ETNFnEIS.CULF1: CBS Upper Limit reached Flag 1 (Class A) */
typedef enum{
	ETNF_e_CULF1_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_CULF1_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_CULF1;

/* ETNFnEIS.CULF0: CBS Upper Limit reached Flag 0 (Class B) */
typedef enum{
	ETNF_e_CULF0_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_CULF0_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_CULF0;

/* ETNFnEIS.CLLF1: CBS Lower Limit reached Flag 1 (Class A) */
typedef enum{
	ETNF_e_CLLF1_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_CLLF1_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_CLLF1;

/* ETNFnEIS.CLLF0: CBS Lower Limit reached Flag 0 (Class B) */
typedef enum{
	ETNF_e_CLLF0_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_CLLF0_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_CLLF0;

/* ETNFnEIS.SEF: Separation Error Flag */
typedef enum{
	ETNF_e_SEF_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_SEF_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_SEF;

/* ETNFnEIS.QEF: Queue Error Flag */
typedef enum{
	ETNF_e_QEF_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_QEF_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_QEF;

/* ETNFnEIS.MTEF: MAC Transmission Error Flag */
typedef enum{
	ETNF_e_MTEF_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_MTEF_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_MTEF;

/* ETNFnEIS.MREF: MAC Reception Error Flag */
typedef enum{
	ETNF_e_MREF_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_MREF_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_MREF;

/* ETNFnRIC0.FREx: Receive Frame Interrupt Enable x (Stream x-2) */
/* ETNFnRIC0.FRE1: Receive Frame Interrupt Enable 1 (Network Control) */
/* ETNFnRIC0.FRE0: Receive Frame Interrupt Enable 0 (Best Effort) */
typedef enum{
	ETNF_e_FREx_disable = 0,	/* 0: Disabled */
	ETNF_e_FREx_enable  = 1 	/* 1: Enabled */
}ETNF_e_FREx;

/* ETNFnRIS0.FRFx: Receive Frame Interrupt Status x (Stream x-2) */
/* ETNFnRIS0.FRF1: Receive Frame Interrupt Status 1 (Network Control) */
/* ETNFnRIS0.FRF0: Receive Frame Interrupt Status 0 (Best Effort) */
typedef enum{
	ETNF_e_FRFx_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_FRFx_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_FRFx;

/* ETNFnRIC1.RFWE: Receive FIFO Warning Interrupt Enable */
typedef enum{
	ETNF_e_RFWE_disable = 0,	/* 0: Disabled */
	ETNF_e_RFWE_enable  = 1 	/* 1: Enabled */
}ETNF_e_RFWE;

/* ETNFnRIC1.RWEx: Reception Warning Interrupt Enable */
typedef enum{
	ETNF_e_RWEx_disable = 0,	/* 0: Disabled */
	ETNF_e_RWEx_enable  = 1 	/* 1: Enabled */
}ETNF_e_RWEx;

/* ETNFnRIS1.RFWF: Receive FIFO Warning Flag */
typedef enum{
	ETNF_e_RFWF_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_RFWF_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_RFWF;

/* ETNFnRIS1.RWFx: Receive Warning Flag x (Stream) */
typedef enum{
	ETNF_e_RWFx_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_RWFx_pending     = 1 	/* 1: Unread frame counter warning level reached. */
}ETNF_e_RWFx;

/* ETNFnRIC2.RFFE: Receive FIFO Full Interrupt Enable */
typedef enum{
	ETNF_e_RFFE_disable = 0,	/* 0: Disabled */
	ETNF_e_RFFE_enable  = 1 	/* 1: Enabled */
}ETNF_e_RFFE;

/* ETNFnRIC2.QFEx: Receive Queue x (Stream x-2) Full Interrupt Enable */
/* ETNFnRIC2.QFE1: Receive Queue 1 (Network Control) Full Interrupt Enable */
/* ETNFnRIC2.QFE0: Receive Queue 0 (Best Effort) Full Interrupt Enable */
typedef enum{
	ETNF_e_QFEx_disable = 0,	/* 0: Disabled */
	ETNF_e_QFEx_enable  = 1 	/* 1: Enabled */
}ETNF_e_QFEx;

/* ETNFnRIS2.RFFF: Receive FIFO Full Interrupt Status */
typedef enum{
	ETNF_e_RFFF_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_RFFF_pending     = 1 	/* 1: The interrupt is pending */
}ETNF_e_RFFF;

/* ETNFnRIS2.QFFx: Receive Queue x (Stream x-2) Full Interrupt Status */
/* ETNFnRIS2.QFF1: Receive Queue 1 (Network Control) Full Interrupt Status */
/* ETNFnRIS2.QFF0: Receive Queue 0 (Best Effort) Full Interrupt Status */
typedef enum{
	ETNF_e_QFFx_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_QFFx_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_QFFx;

/* ETNFnTIC.TDPE3: Transmit Descriptor Processed Interrupt Enable 3 */
typedef enum{
	ETNF_e_TDPE3_disable = 0,	/* 0: Disabled */
	ETNF_e_TDPE3_enable  = 1 	/* 1: Enabled */
}ETNF_e_TDPE3;

/* ETNFnTIC.TDPE2: Transmit Descriptor Processed Interrupt Enable 2 */
typedef enum{
	ETNF_e_TDPE2_disable = 0,	/* 0: Disabled */
	ETNF_e_TDPE2_enable  = 1 	/* 1: Enabled */
}ETNF_e_TDPE2;

/* ETNFnTIC.TDPE1: Transmit Descriptor Processed Interrupt Enable 1 */
typedef enum{
	ETNF_e_TDPE1_disable = 0,	/* 0: Disabled */
	ETNF_e_TDPE1_enable  = 1 	/* 1: Enabled */
}ETNF_e_TDPE1;

/* ETNFnTIC.TDPE0: Transmit Descriptor Processed Interrupt Enable 0 */
typedef enum{
	ETNF_e_TDPE0_disable = 0,	/* 0: Disabled */
	ETNF_e_TDPE0_enable  = 1 	/* 1: Enabled */
}ETNF_e_TDPE0;

/* ETNFnTIC.MFWE: MAC Status FIFO Warning Interrupt Enable */
typedef enum{
	ETNF_e_MFWE_disable = 0,	/* 0: Disabled */
	ETNF_e_MFWE_enable  = 1 	/* 1: Enabled */
}ETNF_e_MFWE;

/* ETNFnTIC.MFUE: MAC Status FIFO Update Interrupt Enable */
typedef enum{
	ETNF_e_MFUE_disable = 0,	/* 0: Disabled */
	ETNF_e_MFUE_enable  = 1 	/* 1: Enabled */
}ETNF_e_MFUE;

/* ETNFnTIC.TFWE: Timestamp FIFO Warning Interrupt Enable */
typedef enum{
	ETNF_e_TFWE_disable = 0,	/* 0: Disabled */
	ETNF_e_TFWE_enable  = 1 	/* 1: Enabled */
}ETNF_e_TFWE;

/* ETNFnTIC.TFUE: Timestamp FIFO Update Interrupt Enable */
typedef enum{
	ETNF_e_TFUE_disable = 0,	/* 0: Disabled */
	ETNF_e_TFUE_enable  = 1 	/* 1: Enabled */
}ETNF_e_TFUE;

/* ETNFnTIC.FTE3: Frame Transmitted Interrupt Enable 3 */
typedef enum{
	ETNF_e_FTE3_disable = 0,	/* 0: Disabled */
	ETNF_e_FTE3_enable  = 1 	/* 1: Enabled */
}ETNF_e_FTE3;

/* ETNFnTIC.FTE2: Frame Transmitted Interrupt Enable 2 */
typedef enum{
	ETNF_e_FTE2_disable = 0,	/* 0: Disabled */
	ETNF_e_FTE2_enable  = 1 	/* 1: Enabled */
}ETNF_e_FTE2;

/* ETNFnTIC.FTE1: Frame Transmitted Interrupt Enable 1 */
typedef enum{
	ETNF_e_FTE1_disable = 0,	/* 0: Disabled */
	ETNF_e_FTE1_enable  = 1 	/* 1: Enabled */
}ETNF_e_FTE1;

/* ETNFnTIC.FTE0: Frame Transmitted Interrupt Enable 0 */
typedef enum{
	ETNF_e_FTE0_disable = 0,	/* 0: Disabled */
	ETNF_e_FTE0_enable  = 1 	/* 1: Enabled */
}ETNF_e_FTE0;

/* ETNFnTIS.TDPF3: Transmit Descriptor Processed Flag 3 */
typedef enum{
	ETNF_e_TDPF3_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_TDPF3_pending     = 1 	/* 1: The descriptor interrupt is pending. */
}ETNF_e_TDPF3;

/* ETNFnTIS.TDPF2: Transmit Descriptor Processed Flag 2 */
typedef enum{
	ETNF_e_TDPF2_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_TDPF2_pending     = 1 	/* 1: The descriptor interrupt is pending. */
}ETNF_e_TDPF2;

/* ETNFnTIS.TDPF1: Transmit Descriptor Processed Flag 1 */
typedef enum{
	ETNF_e_TDPF1_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_TDPF1_pending     = 1 	/* 1: The descriptor interrupt is pending. */
}ETNF_e_TDPF1;

/* ETNFnTIS.TDPF0: Transmit Descriptor Processed Flag 0 */
typedef enum{
	ETNF_e_TDPF0_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_TDPF0_pending     = 1 	/* 1: The descriptor interrupt is pending. */
}ETNF_e_TDPF0;

/* ETNFnTIS.MFWF: MAC status FIFO Warning Flag */
typedef enum{
	ETNF_e_MFWF_not_pending   = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_MFWF_reach_warning = 1 	/* 1: The Tx Status FIFO has reached the warning level. */
}ETNF_e_MFWF;

/* ETNFnTIS.MFUF: MAC status FIFO Update Flag */
typedef enum{
	ETNF_e_MFUF_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_MFUF_updated     = 1 	/* 1: The Tx Status FIFO has been updated. */
}ETNF_e_MFUF;

/* ETNFnTIS.TFWF: Timestamp FIFO Warning Flag */
typedef enum{
	ETNF_e_TFWF_not_pending   = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_TFWF_reach_warning = 1 	/* 1: The timestamp FIFO has reached the warning level. */
}ETNF_e_TFWF;

/* ETNFnTIS.TFUF: Timestamp FIFO Update Flag */
typedef enum{
	ETNF_e_TFUF_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_TFUF_updated     = 1 	/* 1: The timestamp FIFO has been updated. */
}ETNF_e_TFUF;

/* ETNFnTIS.FTF3: Frame Transmitted Flag 3 */
typedef enum{
	ETNF_e_FTF3_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_FTF3_transmitted = 1 	/* 1: Frame transmitted by MAC. */
}ETNF_e_FTF3;

/* ETNFnTIS.FTF2: Frame Transmitted Flag 2 */
typedef enum{
	ETNF_e_FTF2_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_FTF2_transmitted = 1 	/* 1: Frame transmitted by MAC. */
}ETNF_e_FTF2;

/* ETNFnTIS.FTF1: Frame Transmitted Flag 1 */
typedef enum{
	ETNF_e_FTF1_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_FTF1_transmitted = 1 	/* 1: Frame transmitted by MAC. */
}ETNF_e_FTF1;

/* ETNFnTIS.FTF0: Frame Transmitted Flag 0 */
typedef enum{
	ETNF_e_FTF0_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_FTF0_transmitted = 1 	/* 1: Frame transmitted by MAC. */
}ETNF_e_FTF0;

/* ETNFnISS.DPMx: Descriptor Processed Mirror x */
typedef enum{
	ETNF_e_DPMx_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_DPMx_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_DPMx;

/* ETNFnISS.CGIM: Combined gPTP Interrupt Mirror */
typedef enum{
	ETNF_e_CGIM_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_CGIM_transmitted = 1 	/* 1: The interrupt is pending. */
}ETNF_e_CGIM;

/* ETNFnISS.RFWM: Receive FIFO Warning Mirror */
typedef enum{
	ETNF_e_RFWM_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_RFWM_transmitted = 1 	/* 1: The interrupt is pending. */
}ETNF_e_RFWM;

/* ETNFnISS.MFWM: MAC Status FIFO Warning Mirror */
typedef enum{
	ETNF_e_MFWM_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_MFWM_transmitted = 1 	/* 1: The interrupt is pending. */
}ETNF_e_MFWM;

/* ETNFnISS.MFUM: MAC Status FIFO Updated Mirror */
typedef enum{
	ETNF_e_MFUM_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_MFUM_transmitted = 1 	/* 1: The interrupt is pending. */
}ETNF_e_MFUM;

/* ETNFnISS.TFWM: Timestamp FIFO Warning Mirror */
typedef enum{
	ETNF_e_TFWM_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_TFWM_transmitted = 1 	/* 1: The interrupt is pending. */
}ETNF_e_TFWM;

/* ETNFnISS.TFUM: Timestamp FIFO Update Mirror */
typedef enum{
	ETNF_e_TFUM_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_TFUM_transmitted = 1 	/* 1: The interrupt is pending. */
}ETNF_e_TFUM;

/* ETNFnISS.MM: MAC Mirror */
typedef enum{
	ETNF_e_MM_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_MM_transmitted = 1 	/* 1: The interrupt is pending. */
}ETNF_e_MM;

/* ETNFnISS.EM: Error Mirror */
typedef enum{
	ETNF_e_EM_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_EM_transmitted = 1 	/* 1: The interrupt is pending. */
}ETNF_e_EM;

/* ETNFnISS.FTM: Frame Transmitted Mirror */
typedef enum{
	ETNF_e_FTM_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_FTM_transmitted = 1 	/* 1: The interrupt is pending. */
}ETNF_e_FTM;

/* ETNFnISS.RWM: Receive Warning Mirror */
typedef enum{
	ETNF_e_RWM_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_RWM_transmitted = 1 	/* 1: The interrupt is pending. */
}ETNF_e_RWM;

/* ETNFnISS.FRM: Frame Received Mirror */
typedef enum{
	ETNF_e_FRM_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_FRM_transmitted = 1 	/* 1: The interrupt is pending. */
}ETNF_e_FRM;

/* ETNFnCIE.RFFL: Rx-FIFO Full interrupt Line select */
typedef enum{
	ETNF_e_RFFL_line_A = 0,	/* 0: Interrupt line A used for this notification */
	ETNF_e_RFFL_line_B = 1 	/* 1: Interrupt line B used for this notification */
}ETNF_e_RFFL;

/* ETNFnCIE.RFWL: Rx-FIFO Warning interrupt Line select */
typedef enum{
	ETNF_e_RFWL_line_A = 0,	/* 0: Interrupt line A used for this notification */
	ETNF_e_RFWL_line_B = 1 	/* 1: Interrupt line B used for this notification */
}ETNF_e_RFWL;

/* ETNFnCIE.CL0M: Common Line 0 Mode */
typedef enum{
	ETNF_e_CL0M_common_line   = 0,	/* 0: Use common interrupt line 0 */
	ETNF_e_CL0M_specific_line = 1 	/* 1: Use queue specific interrupt line 0 */
}ETNF_e_CL0M;

/* ETNFnCIE.RQFM: Reception Queue Full Mode */
typedef enum{
	ETNF_e_RQFM_common_line   = 0,	/* 0: Use for error interrupt line */
	ETNF_e_RQFM_specific_line = 1 	/* 1: Use for queue specific interrupt line */
}ETNF_e_RQFM;

/* ETNFnCIE.CTIE: Common Transmit Interrupt Enable */
typedef enum{
	ETNF_e_CTIE_disable = 0,	/* 0: Disabled */
	ETNF_e_CTIE_enable  = 1 	/* 1: Enabled */
}ETNF_e_CTIE;

/* ETNFnCIE.CRIE: Common Receive Interrupt Enable */
typedef enum{
	ETNF_e_CRIE_disable = 0,	/* 0: Disabled */
	ETNF_e_CRIE_enable  = 1 	/* 1: Enabled */
}ETNF_e_CRIE;

/* ETNFnRIC3.RDPEx: Receive Descriptor Processed Interrupt Enable x */
typedef enum{
	ETNF_e_RDPEx_disable = 0,	/* 0: Disabled */
	ETNF_e_RDPEx_enable  = 1 	/* 1: Enabled */
}ETNF_e_RDPEx;

/* ETNFnRIS3.RDPFx: Receive Descriptor Processed Flag x (Stream) */
/* ETNFnRIS3.RDPF1: Receive Descriptor Processed Flag 1 (Network Control) */
/* ETNFnRIS3.RDPF0: Receive Descriptor Processed Flag 0 (Best Effort) */
typedef enum{
	ETNF_e_RDPFx_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_RDPFx_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_RDPFx;

/* ETNFnRIE0.FRSr: Frame Received interrupt Set r */
typedef enum{
	ETNF_e_FRSr_no_change = 0,	/* 0: No change of ETNF0RIC0.FREr */
	ETNF_e_FRSr_set_FREr  = 1 	/* 1: Set ETNF0RIC0.FREr to 1 */
}ETNF_e_FRSr;

/* ETNFnRIE0.RFWS: Rx-FIFO Warning interrupt Set */
typedef enum{
	ETNF_e_RFWS_no_change = 0,	/* 0: No change of ETNF0RIC1.RFWE */
	ETNF_e_RFWS_set_RFWE  = 1 	/* 1: Set ETNF0RIC1.RFWE to 1 */
}ETNF_e_RFWS;

/* ETNFnRIE0.RWSr: Reception Warning interrupt Set r */
typedef enum{
	ETNF_e_RWSr_no_change = 0,	/* 0: No change of ETNF0RIC1.RWEr */
	ETNF_e_RWSr_set_RWEr  = 1 	/* 1: Set ETNF0RIC1.RWEr to 1 */
}ETNF_e_RWSr;

/* ETNFnRIE2.RFFS: Rx-FIFO Full interrupt Set */
typedef enum{
	ETNF_e_RFFS_no_change = 0,	/* 0: No change of ETNF0RIC2.RFFE */
	ETNF_e_RFFS_set_RFFE  = 1 	/* 1: Set ETNF0RIC2.RFFE to 1 */
}ETNF_e_RFFS;

/* ETNFnRIE2.QFSr: Queue Full interrupt Set r */
typedef enum{
	ETNF_e_QFSr_no_change = 0,	/* 0: No change of ETNF0RIC2.QFEr */
	ETNF_e_QFSr_set_QFEr  = 1 	/* 1: Set ETNF0RIC2.QFEr to 1 */
}ETNF_e_QFSr;

/* ETNFnRIE3.RDPSr: Receive Descriptor Processed interrupt Set r */
typedef enum{
	ETNF_e_RDPSr_no_change = 0,	/* 0: No change of ETNF0RIC3.RDPEr */
	ETNF_e_RDPSr_set_RDPEr = 1 	/* 1: Set ETNF0RIC3.RDPEr to 1 */
}ETNF_e_RDPSr;

/* ETNFnRID0.FRDr: Frame Received interrupt Disable r */
typedef enum{
	ETNF_e_FRDr_no_change  = 0,	/* 0: No change of ETNF0RIC0.FREr */
	ETNF_e_FRDr_clear_FREr = 1 	/* 1: Set ETNF0RIC0.FREr to 0 */
}ETNF_e_FRDr;

/* ETNFnRID1.RFWD: Rx-FIFO Warning interrupt Disable */
typedef enum{
	ETNF_e_RFWD_no_change  = 0,	/* 0: No change of ETNF0RIC1.RFWE */
	ETNF_e_RFWD_clear_RFWE = 1 	/* 1: Set ETNF0RIC1.RFWE to 0 */
}ETNF_e_RFWD;

/* ETNFnRID1.RWDr: Reception Warning interrupt Set r */
typedef enum{
	ETNF_e_RWDr_no_change  = 0,	/* 0: No change of ETNF0RIC1.RWEr */
	ETNF_e_RWDr_clear_RWEr = 1 	/* 1: Set ETNF0RIC1.RWEr to 0 */
}ETNF_e_RWDr;

/* ETNFnRID2.RFFD: Rx-FIFO Full interrupt Disable */
typedef enum{
	ETNF_e_RFFD_no_change  = 0,	/* 0: No change of ETNF0RIC2.RFFE */
	ETNF_e_RFFD_clear_RFFE = 1 	/* 1: Set ETNF0RIC2.RFFE to 0 */
}ETNF_e_RFFD;

/* ETNFnRID2.QFDr: Queue Full interrupt Disable r */
typedef enum{
	ETNF_e_QFDr_no_change  = 0,	/* 0: No change of ETNF0RIC2.QFEr */
	ETNF_e_QFDr_clear_QFEr = 1 	/* 1: Set ETNF0RIC2.QFEr to 0 */
}ETNF_e_QFDr;

/* ETNFnRID3.RDPDr: Receive Descriptor Processed interrupt Disable r */
typedef enum{
	ETNF_e_RDPDr_no_change   = 0,	/* 0: No change of ETNF0RIC3.RDPEr */
	ETNF_e_RDPDr_clear_RDPEr = 1 	/* 1: Set ETNF0RIC3.RDPEr to 0 */
}ETNF_e_RDPDr;

/* ETNFnTIE.TDPS3: Transmit Descriptor Processed Interrupt Set 3 */
typedef enum{
	ETNF_e_TDPS3_no_change = 0,	/* 0: No change of ETNF0TIC.TDPEt */
	ETNF_e_TDPS3_set_TDPEt = 1 	/* 1: Set ETNF0TIC.TDPEt to 1 */
}ETNF_e_TDPS3;

/* ETNFnTIE.TDPS2: Transmit Descriptor Processed Interrupt Set 2 */
typedef enum{
	ETNF_e_TDPS2_no_change = 0,	/* 0: No change of ETNF0TIC.TDPEt */
	ETNF_e_TDPS2_set_TDPEt = 1 	/* 1: Set ETNF0TIC.TDPEt to 1 */
}ETNF_e_TDPS2;

/* ETNFnTIE.TDPS1: Transmit Descriptor Processed Interrupt Set 1 */
typedef enum{
	ETNF_e_TDPS1_no_change = 0,	/* 0: No change of ETNF0TIC.TDPEt */
	ETNF_e_TDPS1_set_TDPEt = 1 	/* 1: Set ETNF0TIC.TDPEt to 1 */
}ETNF_e_TDPS1;

/* ETNFnTIE.TDPS0: Transmit Descriptor Processed Interrupt Set 0 */
typedef enum{
	ETNF_e_TDPS0_no_change = 0,	/* 0: No change of ETNF0TIC.TDPEt */
	ETNF_e_TDPS0_set_TDPEt = 1 	/* 1: Set ETNF0TIC.TDPEt to 1 */
}ETNF_e_TDPS0;

/* ETNFnTIE.MFWS: MAC Status FIFO Warning Interrupt Set */
typedef enum{
	ETNF_e_MFWS_no_change = 0,	/* 0: No change of ETNF0TIC.MFWE */
	ETNF_e_MFWS_set_MFWE  = 1 	/* 1: Set ETNF0TIC.MFWE to 1 */
}ETNF_e_MFWS;

/* ETNFnTIE.MFUS: MAC Status FIFO Updated Interrupt Set */
typedef enum{
	ETNF_e_MFUS_no_change = 0,	/* 0: No change of ETNF0TIC.MFUE */
	ETNF_e_MFUS_set_MFUE  = 1 	/* 1: Set ETNF0TIC.MFUE to 1 */
}ETNF_e_MFUS;

/* ETNFnTIE.TFWS: Transtamp FIFO Warning Interrupt Set */
typedef enum{
	ETNF_e_TFWS_no_change = 0,	/* 0: No change of ETNF0TIC.TFWE */
	ETNF_e_TFWS_set_TFWE  = 1 	/* 1: Set ETNF0TIC.TFWE to 1 */
}ETNF_e_TFWS;

/* ETNFnTIE.TFUS: Transtamp FIFO Updated Interrupt Set */
typedef enum{
	ETNF_e_TFUS_no_change = 0,	/* 0: No change of ETNF0TIC.TFUE */
	ETNF_e_TFUS_set_TFUE  = 1 	/* 1: Set ETNF0TIC.TFUE to 1 */
}ETNF_e_TFUS;

/* ETNFnTIE.FTS3: Frame Transmitted Interrupt Set 3 */
typedef enum{
	ETNF_e_FTS3_no_change = 0,	/* 0: No change of ETNF0TIC.FTEt */
	ETNF_e_FTS3_set_FTEt  = 1 	/* 1: Set ETNF0TIC.FTEt to 1 */
}ETNF_e_FTS3;

/* ETNFnTIE.FTS2: Frame Transmitted Interrupt Set 2 */
typedef enum{
	ETNF_e_FTS2_no_change = 0,	/* 0: No change of ETNF0TIC.FTEt */
	ETNF_e_FTS2_set_FTEt  = 1 	/* 1: Set ETNF0TIC.FTEt to 1 */
}ETNF_e_FTS2;

/* ETNFnTIE.FTS1: Frame Transmitted Interrupt Set 1 */
typedef enum{
	ETNF_e_FTS1_no_change = 0,	/* 0: No change of ETNF0TIC.FTEt */
	ETNF_e_FTS1_set_FTEt  = 1 	/* 1: Set ETNF0TIC.FTEt to 1 */
}ETNF_e_FTS1;

/* ETNFnTIE.FTS0: Frame Transmitted Interrupt Set 0 */
typedef enum{
	ETNF_e_FTS0_no_change = 0,	/* 0: No change of ETNF0TIC.FTEt */
	ETNF_e_FTS0_set_FTEt  = 1 	/* 1: Set ETNF0TIC.FTEt to 1 */
}ETNF_e_FTS0;

/* ETNFnTID.TDPD3: Transmit Descriptor Processed interrupt Disable 3 */
typedef enum{
	ETNF_e_TDPD3_no_change   = 0,	/* 0: No change of ETNF0TIC.TDPEt */
	ETNF_e_TDPD3_clear_TDPEt = 1 	/* 1: Set ETNF0TIC.TDPEt to 0 */
}ETNF_e_TDPD3;

/* ETNFnTID.TDPD2: Transmit Descriptor Processed interrupt Disable 2 */
typedef enum{
	ETNF_e_TDPD2_no_change   = 0,	/* 0: No change of ETNF0TIC.TDPEt */
	ETNF_e_TDPD2_clear_TDPEt = 1 	/* 1: Set ETNF0TIC.TDPEt to 0 */
}ETNF_e_TDPD2;

/* ETNFnTID.TDPD1: Transmit Descriptor Processed interrupt Disable 1 */
typedef enum{
	ETNF_e_TDPD1_no_change   = 0,	/* 0: No change of ETNF0TIC.TDPEt */
	ETNF_e_TDPD1_clear_TDPEt = 1 	/* 1: Set ETNF0TIC.TDPEt to 0 */
}ETNF_e_TDPD1;

/* ETNFnTID.TDPD0: Transmit Descriptor Processed interrupt Disable 0 */
typedef enum{
	ETNF_e_TDPD0_no_change   = 0,	/* 0: No change of ETNF0TIC.TDPEt */
	ETNF_e_TDPD0_clear_TDPEt = 1 	/* 1: Set ETNF0TIC.TDPEt to 0 */
}ETNF_e_TDPD0;

/* ETNFnTID.MFWD: MAC status FIFO Warning interrupt Disable */
typedef enum{
	ETNF_e_MFWD_no_change  = 0,	/* 0: No change of ETNF0TIC.MFWE */
	ETNF_e_MFWD_clear_MFWE = 1 	/* 1: Set ETNF0TIC.MFWE to 0 */
}ETNF_e_MFWD;

/* ETNFnTID.MFUD: MAC status FIFO Updated interrupt Disable */
typedef enum{
	ETNF_e_MFUD_no_change  = 0,	/* 0: No change of ETNF0TIC.MFUE */
	ETNF_e_MFUD_clear_MFUE = 1 	/* 1: Set ETNF0TIC.MFUE to 0 */
}ETNF_e_MFUD;

/* ETNFnTID.TFWD: Timestamp FIFO Warning interrupt Disable */
typedef enum{
	ETNF_e_TFWD_no_change  = 0,	/* 0: No change of ETNF0TIC.TFWE */
	ETNF_e_TFWD_clear_TFWE = 1 	/* 1: Set ETNF0TIC.TFWE to 0 */
}ETNF_e_TFWD;

/* ETNFnTID.TFUD: Timestamp FIFO Updated interrupt Disable */
typedef enum{
	ETNF_e_TFUD_no_change   = 0,	/* 0: No change of ETNF0TIC.TFUE */
	ETNF_e_TFUD_clear_TFUEv = 1 	/* 1: Set ETNF0TIC.TFUE to 0 */
}ETNF_e_TFUD;

/* ETNFnTID.FTD3: Frame Transmitted interrupt Disable 3 */
typedef enum{
	ETNF_e_FTD3_no_change  = 0,	/* 0: No change of TIC.FTEt */
	ETNF_e_FTD3_clear_FTEt = 1 	/* 1: Set ETNF0TIC.FTEt to 0 */
}ETNF_e_FTD3;

/* ETNFnTID.FTD2: Frame Transmitted interrupt Disable 2 */
typedef enum{
	ETNF_e_FTD2_no_change  = 0,	/* 0: No change of TIC.FTEt */
	ETNF_e_FTD2_clear_FTEt = 1 	/* 1: Set ETNF0TIC.FTEt to 0 */
}ETNF_e_FTD2;

/* ETNFnTID.FTD1: Frame Transmitted interrupt Disable 1 */
typedef enum{
	ETNF_e_FTD1_no_change  = 0,	/* 0: No change of TIC.FTEt */
	ETNF_e_FTD1_clear_FTEt = 1 	/* 1: Set ETNF0TIC.FTEt to 0 */
}ETNF_e_FTD1;

/* ETNFnTID.FTD0: Frame Transmitted interrupt Disable 0 */
typedef enum{
	ETNF_e_FTD0_no_change  = 0,	/* 0: No change of TIC.FTEt */
	ETNF_e_FTD0_clear_FTEt = 1 	/* 1: Set ETNF0TIC.FTEt to 0 */
}ETNF_e_FTD0;

/* ETNFnGCCR.SPC: Start Periodic Comparison */
typedef enum{
	ETNF_e_SPC_absolute_comparison = 0,	/* 0: Absolute comparison value updated by ETNF0GCCR.LPTC request */
	ETNF_e_SPC_periodic_comparison = 1 	/* 1: Periodic comparison value updated by ETNF0GCCR.LPTC request */
}ETNF_e_SPC;

/* ETNFnGCCR.PGM: Pulse Generation Mode */
typedef enum{
	ETNF_e_PGM_gPTP_timer_value           = 0,	/* 0: Pulse per second is related to gPTP timer value */
	ETNF_e_PGM_corrected_gPTP_timer_value = 1 	/* 1: Pulse per second is related to corrected gPTP timer value */
}ETNF_e_PGM;

/* ETNFnGCCR.TCSS[9:8]: Timer Capture Source Select */
typedef enum{
	ETNF_e_TCSS_gPTP_timer_value          = 0,	/* 00B: gPTP timer value */
	ETNF_e_TCSS_adjusted_gPTP_timer_value = 1,	/* 01B: Adjusted gPTP timer value */
	ETNF_e_TCSS_AVTP_presentation_time    = 2,	/* 10B: AVTP presentation time */
	ETNF_e_TCSS_no_change                 = 3 	/* 11B: No change */
}ETNF_e_TCSS;

/* ETNFnGCCR.LMTT: Maximum Transit Time Configuration Request */
typedef enum{
	ETNF_e_LMTT_setting_completed     = 0,	/* 0: Setting completed */
	ETNF_e_LMTT_configuration_request = 1 	/* 1: When written: Issue a configuration request. */
}ETNF_e_LMTT;

/* ETNFnGCCR.LPTC: Presentation Time Compare Value Configuration Request */
typedef enum{
	ETNF_e_LPTC_setting_completed     = 0,	/* 0: Setting completed */
	ETNF_e_LPTC_configuration_request = 1 	/* 1: When written: Issue a configuration request. */
}ETNF_e_LPTC;

/* ETNFnGCCR.LTI: Timer Increment Value Configuration Request */
typedef enum{
	ETNF_e_LTI_setting_completed     = 0,	/* 0: Setting completed */
	ETNF_e_LTI_configuration_request = 1 	/* 1: When written: Issue a configuration request. */
}ETNF_e_LTI;

/* ETNFnGCCR.LTO: Timer Offset Value Configuration Request */
typedef enum{
	ETNF_e_LTO_setting_completed     = 0,	/* 0: Setting completed */
	ETNF_e_LTO_configuration_request = 1 	/* 1: When written: Issue a configuration request. */
}ETNF_e_LTO;

/* ETNFnGCCR.TCR[1:0]: Timer Control Request */
typedef enum{
	ETNF_e_TCR_not_request            = 0,	/* 00B: Timer control is not requested. */
	ETNF_e_TCR_time_reset             = 1,	/* 01B: gPTP/AVTP presentation time reset */
	ETNF_e_TCR_continuous_capture     = 2,	/* 10B: Continuous capture of AVTP to ETNF0GCTi.CTV */
	ETNF_e_TCR_captures_the_value_set = 3 	/* 11B: Captures the value set in the TCSS bit. */
}ETNF_e_TCR;

/* ETNFnGIC.PTMEx: Presentation Time Match Interrupt Enable x */
typedef enum{
	ETNF_e_PTMEx_disable = 0,	/* 0: Disabled */
	ETNF_e_PTMEx_enable  = 1 	/* 1: Enabled */
}ETNF_e_PTMEx;

/* ETNFnGIS.PTMFx: Presentation Time Match Interrupt Flag x */
typedef enum{
	ETNF_e_PTMFx_not_pending = 0,	/* 0: The interrupt is not pending. */
	ETNF_e_PTMFx_pending     = 1 	/* 1: The interrupt is pending. */
}ETNF_e_PTMFx;

/* ETNFnGSR.AFU3: AVTP FIFO Update 3 */
typedef enum{
	ETNF_e_AFU3_no_pending = 0,	/* 0: No update of AVTP FIFO pending */
	ETNF_e_AFU3_updating   = 1 	/* 1: Update of AVTP FIFO with value from ETNF0GPTFi.PTFV is ongoing */
}ETNF_e_AFU3;

/* ETNFnGSR.AFU2: AVTP FIFO Update 2 */
typedef enum{
	ETNF_e_AFU2_no_pending = 0,	/* 0: No update of AVTP FIFO pending */
	ETNF_e_AFU2_updating   = 1 	/* 1: Update of AVTP FIFO with value from ETNF0GPTFi.PTFV is ongoing */
}ETNF_e_AFU2;

/* ETNFnGSR.AFU1: AVTP FIFO Update 1 */
typedef enum{
	ETNF_e_AFU1_no_pending = 0,	/* 0: No update of AVTP FIFO pending */
	ETNF_e_AFU1_updating   = 1 	/* 1: Update of AVTP FIFO with value from ETNF0GPTFi.PTFV is ongoing */
}ETNF_e_AFU1;

/* ETNFnGSR.AFU0: AVTP FIFO Update 0 */
typedef enum{
	ETNF_e_AFU0_no_pending = 0,	/* 0: No update of AVTP FIFO pending */
	ETNF_e_AFU0_updating   = 1 	/* 1: Update of AVTP FIFO with value from ETNF0GPTFi.PTFV is ongoing */
}ETNF_e_AFU0;

/* ETNFnGSR.PCMx: Periodic Comparison Mode x */
typedef enum{
	ETNF_e_PCMx_single_shot_comparison = 0,	/* 0: Single shot comparison */
	ETNF_e_PCMx_periodic_comparison    = 1 	/* 1: Periodic comparison */
}ETNF_e_PCMx;

/* ETNFnECMR.TRCCM: Counter Clear Mode */
typedef enum{
	ETNF_e_TRCCM_write_clear = 0,	/* 0: Writing to the counter register leads to the register being cleared to 0. */
	ETNF_e_TRCCM_read_clear  = 1 	/* 1: Reading from the counter register leads to the register being cleared to 0. */
}ETNF_e_TRCCM;

/* ETNFnECMR.RCSC: Checksum Calculation */
typedef enum{
	ETNF_e_RCSC_not_auto_calculate = 0,	/* 0: Checksums are not automatically calculated. */
	ETNF_e_RCSC_auto_calculate     = 1 	/* 1: Checksums are automatically calculated. */
}ETNF_e_RCSC;

/* ETNFnECMR.DPAD: Data Padding */
typedef enum{
	ETNF_e_DPAD_padding_data    = 0,	/* 0: Padding to make up 60 bytes is inserted in data for transmission when fewer than 60 bytes are to be transmitted. */
	ETNF_e_DPAD_no_padding_data = 1 	/* 1: Padding is not inserted in data for transmission when fewer than 60 bytes are to be transmitted and the data are transmitted without being changed. */
}ETNF_e_DPAD;

/* ETNFnECMR.RZPF: PAUSE Frame Reception with Time = 0 */
typedef enum{
	ETNF_e_RZPF_disable = 0,	/* 0: Reception of PAUSE frames with the TIME parameter value 0 is disabled. */
	ETNF_e_RZPF_enable  = 1 	/* 1: Reception of PAUSE frames with the TIME parameter value 0 is enabled. */
}ETNF_e_RZPF;

/* ETNFnECMR.ZPF: (DM = 0) */
typedef enum{
	ETNF_e_ZPF_PAUSE_disable_CRS_enable = 0,	/* (DM = 0) 0: Control in response to and for the sending of PAUSE frames with the TIME parameter value 0 is disabled. / (DM = 1) 0: CRS is checked in T1S mode */
	ETNF_e_ZPF_PAUSE_enable_CRS_disable = 1 	/* (DM = 0) 1: Control in response to and for the sending of PAUSE frames with the TIME parameter value is 0 is enabled. / (DM = 1) 1: CRS is not checked in T1S mode */
}ETNF_e_ZPF;

/* ETNFnECMR.PFR: PAUSE Frame Receive Mode */
typedef enum{
	ETNF_e_PFR_not_transfer = 0,	/* 0: PAUSE frames are not transferred to the AVB-DMAC. */
	ETNF_e_PFR_transfer     = 1 	/* 1: PAUSE frames are transferred to the AVB-DMAC. */
}ETNF_e_PFR;

/* ETNFnECMR.RXF: Reception Flow Control Operation Mode */
typedef enum{
	ETNF_e_RXF_disable = 0,	/* 0: Flow control for the receiving port (reception of PAUSE frame) is disabled. */
	ETNF_e_RXF_enable  = 1 	/* 1: Flow control for the receiving port (reception of PAUSE frame) is enabled. */
}ETNF_e_RXF;

/* ETNFnECMR.TXF: Transmission Flow Control Operation Mode*1 */
typedef enum{
	ETNF_e_TXF_disable = 0,	/* 0: Flow control for the transmitting port is disabled */
	ETNF_e_TXF_enable  = 1 	/* 1: Flow control for the transmitting port is enabled */
}ETNF_e_TXF;

/* ETNFnECMR.RE: Reception Enable */
typedef enum{
	ETNF_e_RE_disable = 0,	/* 0: Reception is disabled. */
	ETNF_e_RE_enable  = 1 	/* 1: Reception is enabled. */
}ETNF_e_RE;

/* ETNFnECMR.TE: Transmission Enable */
typedef enum{
	ETNF_e_TE_disable = 0,	/* 0: Transmission is disabled. */
	ETNF_e_TE_enable  = 1 	/* 1: Transmission is enabled. */
}ETNF_e_TE;

/* ETNFnECMR.DM: Mode selection */
typedef enum{
	ETNF_e_DM_T1S_mode  = 0,	/* 0: T1S mode */
	ETNF_e_DM_RMII_mode = 1 	/* 1: RMII Full-duplex mode */
}ETNF_e_DM;

/* ETNFnECMR.PRM: Promiscuous Mode */
typedef enum{
	ETNF_e_PRM_normal_mode = 0,	/* 0: Normal operation */
	ETNF_e_PRM_promiscuous_mode     = 1 	/* 1: Promiscuous mode operation */
}ETNF_e_PRM;

/* ETNFnECSR.ICD: Illegal Carrier Detection */
typedef enum{
	ETNF_e_ICD_no_detect = 0,	/* 0: PHY-LSI has not detected an illegal carrier on the line. */
	ETNF_e_ICD_detect    = 1 	/* 1: PHY-LSI has detected an illegal carrier on the line. */
}ETNF_e_ICD;

/* ETNFnECSIPR.ICDIP: false Carrier Detect Interrupt Enable */
typedef enum{
	ETNF_e_ICDIP_disable = 0,	/* 0: Interrupts by the ICD bit setting prohibited. */
	ETNF_e_ICDIP_enable  = 1 	/* 1: Interrupt by the ICD bit setting permitted. */
}ETNF_e_ICDIP;

/* ETNFnPIR.MDI: MII Management Data-In */
typedef enum{
	ETNF_e_MDI_low  = 0,	/* low level */
	ETNF_e_MDI_high = 1 	/* high level */
}ETNF_e_MDI;

/* ETNFnPIR.MDO: MII Management Data-Out */
typedef enum{
	ETNF_e_MDO_low  = 0,	/* low level */
	ETNF_e_MDO_high = 1 	/* high level */
}ETNF_e_MDO;

/* ETNFnPIR.MMD: MII Management Mode */
typedef enum{
	ETNF_e_MMD_read  = 0,	/* 0: Read direction is specified. */
	ETNF_e_MMD_write = 1 	/* 1: Write direction is specified. */
}ETNF_e_MMD;

/* ETNFnPIR.MDC: MII Management Data Clock */
typedef enum{
	ETNF_e_MDC_low  = 0,	/* low level */
	ETNF_e_MDC_high = 1 	/* high level */
}ETNF_e_MDC;

/* ETNFnT1SCTL0.PMA_CFG: Configures the PMA to handle a filtered or unfiltered T1S energy detection pin (ETNFnED_MDIO): */
typedef enum{
	ETNF_e_PMA_CFG_unfiltered_pin = 0,	/* 0: Handle an unfiltered */
	ETNF_e_PMA_CFG_filtered_pin   = 1 	/* 1: Handle a filtered */
}ETNF_e_PMA_CFG;

/* ETNFnT1SCTL0.MDIO_SHARE: Configures the MDIO interface */
typedef enum{
	ETNF_e_MDIO_SHARE_ETS0_MDC_ETS0_MDIO       = 0,	/* 0: use ETS0_MDC, ETS0_MDIO (use a dedicated MDIO interface of Tranceiver) */
	ETNF_e_MDIO_SHARE_ETS0_RX_MDC_ETS0_ED_MDIO = 1 	/* 1: use ETS0_RX_MDC, ETS0_ED_MDIO */
}ETNF_e_MDIO_SHARE;


/*******************************************************************************
* Definition of Register typedef
*******************************************************************************/



/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_ETNF_reg_H__ */

