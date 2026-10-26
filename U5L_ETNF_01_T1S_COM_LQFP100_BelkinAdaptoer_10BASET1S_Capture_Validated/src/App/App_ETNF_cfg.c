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
* File Name    : App_ETNF_cfg.c
* Version      : 1.00
* Device(s)    : ETNF IP
* Description  : This source file contains application-specific setting.
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "App_ETNF_cfg.h"
#include "App_sub.h"


/*******************************************************************************
* Section specification for entire file
*******************************************************************************/
#pragma	section	default


/*******************************************************************************
* Global variables
*******************************************************************************/
/* Source MAC address */
#if  APP_COM_TEST == APP_ETNF_RxTx | APP_COM_MODE == APP_ETNF_AVB_LB | APP_COM_MODE == APP_ETNF_PCS_LB | APP_COM_MODE == APP_ETNF_PMA_LB
uint8_t App_SA[6] = { 0x74U, 0x90U, 0x50U, 0x00U, 0x00U, 0x00U };
#else
 uint8_t App_SA[6] = { 0x74U, 0x90U, 0x50U, 0x00U, 0x00U, 0x01U };
#endif


uint8_t App_DA[4][6] = {
#if  APP_COM_TEST == APP_ETNF_TxRx | APP_COM_MODE == APP_ETNF_AVB_LB | APP_COM_MODE == APP_ETNF_PCS_LB | APP_COM_MODE == APP_ETNF_PMA_LB
		{ 0x74U, 0x90U, 0x50U, 0x00U, 0x00U, 0x00U },  /* address as the source address for communicate with each device */
		{ 0x74U, 0x90U, 0x50U, 0x00U, 0x00U, 0x00U },  /* address as the source address for communicate with each device */
		{ 0x74U, 0x90U, 0x50U, 0x00U, 0x00U, 0x00U },  /* address as the source address for communicate with each device */
		{ 0x74U, 0x90U, 0x50U, 0x00U, 0x00U, 0x00U },  /* address as the source address for communicate with each device */
#else		
		{ 0x74U, 0x90U, 0x50U, 0x00U, 0x00U, 0x01U },  /* same address as the source address for loop back */
		{ 0x74U, 0x90U, 0x50U, 0x00U, 0x00U, 0x01U },  /* same address as the source address for loop back */
		{ 0x74U, 0x90U, 0x50U, 0x00U, 0x00U, 0x01U },  /* same address as the source address for loop back */
		{ 0x74U, 0x90U, 0x50U, 0x00U, 0x00U, 0x01U },  /* same address as the source address for loop back */
#endif
};

/* Ethernet type of transmit frame */
uint16_t	App_ET[] = { ETNF_e_type_IPv4,
		ETNF_e_type_IPv4,
		ETNF_e_type_IPv4,
		ETNF_e_type_IPv4 };

/* configuration of EMAC */
ETNF_s_Config_EMAC App_Config_EMAC = {
	/* MAC address */
	0x74905000,	/* lower 4bytes of MAC address (1st:2nd:3rd:4th) */
	
	#if  APP_COM_TEST == APP_ETNF_RxTx | APP_COM_MODE == APP_ETNF_AVB_LB | APP_COM_MODE == APP_ETNF_PCS_LB | APP_COM_MODE == APP_ETNF_PMA_LB
		0x0000,    	/* upper 2bytes of MAC address (5th:6th) */
	#else
		0x0001,    	/* upper 2bytes of MAC address (5th:6th) */
	#endif
	
	/* reception frame length */
	0x00000FFF,
	
	/* E-MAC Interrupt Permission */
	ETNF_e_ICDIP_disable,
	
	/* ECMR regisger */
	{
		.TRCCM = ETNF_e_TRCCM_write_clear,           	/* Writing to the counter register leads to the register being cleared to 0. */
		.RCSC  = ETNF_e_RCSC_not_auto_calculate,     	/* Checksums are not automatically calculated. */
		.DPAD  = ETNF_e_DPAD_no_padding_data,        	/* Padding is not inserted in data for transmission when fewer than 60 bytes are to be transmitted and the data are transmitted without being changed. */
		.RZPF  = ETNF_e_RZPF_disable,               	/* Reception of PAUSE frames with the TIME parameter value 0 is disabled. */
		.ZPF   = ETNF_e_ZPF_PAUSE_disable_CRS_enable,	/* (DM = 0) 0: Control in response to and for the sending of PAUSE frames with the TIME parameter value 0 is disabled. / (DM = 1) 0: CRS is checked in T1S mode */
		.PFR   = ETNF_e_PFR_not_transfer,
		.RXF   = ETNF_e_RXF_disable,
		.TXF   = ETNF_e_TXF_disable,
#if (APP_COM_IF == APP_ETNF_T1S) && (APP_COM_MODE != APP_ETNF_AVB_LB)
		.DM    = ETNF_e_DM_T1S_mode,
#else
		.DM    = ETNF_e_DM_RMII_mode,
#endif
		.PRM   = ETNF_e_PRM_normal_mode	
	}
	
};

/* Configuration of T1S PHY */
ETNF_s_Config_T1S App_Config_T1S = {
	ETNF_e_PMA_CFG_filtered_pin,         	/* enable filter of T1S energy detection pin */
	ETNF_e_MDIO_SHARE_ETS0_RX_MDC_ETS0_ED_MDIO,	/* select MDIO I/F */
	ETNF_PLCA_ADDR_DEFAULT               	/* PHY MDIO address */
};

/* configuration of AVB-DMAC for reception */
ETNF_s_Config_AVBDMAC_RX App_Config_AVBDMAC_RX = {
	ETNF_RFCL_DEFAULT,
	ETNF_e_ETS2_enable, 	/* Stream Timestamp is enabled. */
	ETNF_e_ETS0_disable, 	/* Best Effort Timestamp is disabled. */
	ETNF_e_ESF_separating_enable_queue0,	/* 01B: The filter for separating AVB stream frames from non-AVB stream frames is enabled; non-matching stream frames are processed in queue 0 (best effort). */
	ETNF_e_ENCF_enable, 	/* Network control is enabled */
	ETNF_e_EFFS_enable, 	/* Error frames are enabled */
	0,                  	/* Stored Data Counter [word] */
	0,                  	/* Stored Padding Counter [word] */
	APP_NUM_RXQ         	/* rxq_num */
};

/* configuration of RX Queue */
ETNF_s_Config_AVBDMAC_RXQ App_Config_AVBDMAC_RXQ[APP_NUM_RXQ] = {
	{ 0, ETNF_e_PIA_word_align, (ETNF_e_UFCC)0 },	/* RX Queue 0 */
	{ 1, ETNF_e_PIA_word_align, (ETNF_e_UFCC)0 },	/* RX Queue 1 */
	{ 2, ETNF_e_PIA_word_align, (ETNF_e_UFCC)0 },	/* RX Queue 2 */
	{ 3, ETNF_e_PIA_word_align, (ETNF_e_UFCC)0 },	/* RX Queue 3 */
	{ 4, ETNF_e_PIA_word_align, (ETNF_e_UFCC)0 },	/* RX Queue 4 */
	{ 5, ETNF_e_PIA_word_align, (ETNF_e_UFCC)0 }	/* RX Queue 5 */
};


/* Separation filter Setting */
/******************************************************************************/
/* Separation Filter Configuration                                            */
/* [SFR common setting]                                                       */
/* Stream Filtering Select: Only for separation, non-matching frames          */
/*                          are processed in reception queue 0                */
/* Network Control Filtering: Disable                                         */
/*                                                                            */
/* 0. Separation Filter For Stream Queue 0( Rx Queue 2 )                      */
/*    Location: 6byte from Payload                                            */
/*    Pattern: 0x11-11-11-11-11-11                                            */
/*    Mask: 0 to 48 bit Enable                                                */
/*                                                                            */
/* 1. Separation Filter For Stream Queue 1( Rx Queue 3 )                      */
/*    Location: 6byte from Payload                                            */
/*    Pattern: 0x22-22-22-22-22-22                                            */
/*    Mask: 0 to 48 bit Enable                                                */
/*                                                                            */
/* 2. Separation Filter For Stream Queue 2( Rx Queue 4 )                      */
/*    Location: 6byte from Payload                                            */
/*    Pattern: 0x33-33-33-33-33-33                                            */
/*    Mask: 0 to 48 bit Enable                                                */
/*                                                                            */
/* 3. Separation Filter For Stream Queue 3( Rx Queue 5 )                      */
/*    Location: 6byte from Payload                                            */
/*    Pattern: 0x44-44-44-44-44-44                                            */
/*    Mask: 0 to 48 bit Enable                                                */
/*                                                                            */
/******************************************************************************/
/* configuration for separation filter */
ETNF_s_Config_sFilter_common App_Config_sFilter_common = {
	ETNF_e_frameindex_Data,    	/* apply filter from data field */
	0xFFFFFFFFUL,	/* all bits no mask for lower 4bytes (1st:2nd:3rd:4th) */
	0x0000FFFFUL,	/* all bits no mask for upper 2bytes (5th:6th) */
};


/* configuration for separation filter */
ETNF_s_Config_sFilter App_Config_sFilter[APP_NUM_SFL] = {
	{ .num = 0, .fl_value_lower = 0x11111111, .fl_value_upper = 0x1111 },	/* filter 0 */
	{ .num = 1, .fl_value_lower = 0x22222222, .fl_value_upper = 0x2222 },	/* filter 1 */
	{ .num = 2, .fl_value_lower = 0x33333333, .fl_value_upper = 0x3333 },	/* filter 2 */
	{ .num = 3, .fl_value_lower = 0x44444444, .fl_value_upper = 0x4444 },	/* filter 3 */
};


/* configuration of AVB-DMAC for transmission */
ETNF_s_Config_AVBDMAC_TX App_Config_AVBDMAC_TX = {
	2,	/* Transmit FIFO Size (Stream Class A) */
	2,	/* Transmit FIFO Size (Stream Class B) */
	2,	/* Transmit FIFO Size (Network Control) */
	2,	/* Transmit FIFO Size (Best Effort) */
	ETNF_e_TQP_non_AVB_mode,	/* Transmit Queue Priority */
	ETNF_e_MFEN_disable,    	/* MAC status FIFO Enable */
	ETNF_e_TFEN_enable       	/* Timestamp FIFO Enable */
};


/*******************************************************************************
* Configuration for Descriptor
*******************************************************************************/

/* Base address of the descriptor table in the URAM */
ETNF_s_DescType_Normal App_BaseDescQueue[APP_NUM_DESCQ] __attribute__ ((section (".GRAM_bss")));

/* TX Queue */
ETNF_s_DescType_Normal	App_TxDescQueue[APP_NUM_TXQ][2] __attribute__ ((section (".GRAM_bss")));

/* RX Queue */
ETNF_s_DescType_Common	App_RxDescQueue_BE[2] __attribute__ ((section (".GRAM_bss")));
ETNF_s_DescType_Common	App_RxDescQueue_NC[2] __attribute__ ((section (".GRAM_bss")));
ETNF_s_DescType_Common	App_RxDescQueue_ST[APP_NUM_RXQ][2] __attribute__ ((section (".GRAM_bss")));

/* Base Descriptor information table */
uint32_t App_Config_DBAT[ETNF_NUM_DESCQ] = {
	(uint32_t)&App_TxDescQueue[0][0],	/* Descriptor queue 0 */
	(uint32_t)&App_TxDescQueue[1][0],	/* Descriptor queue 1 */
	(uint32_t)&App_TxDescQueue[2][0],	/* Descriptor queue 2 */
	(uint32_t)&App_TxDescQueue[3][0],	/* Descriptor queue 3 */
	(uint32_t)&App_RxDescQueue_BE[0],	/* Descriptor queue 4 (Best Effort) */
	(uint32_t)&App_RxDescQueue_NC[0],	/* Descriptor queue 5 (Network Control) */
	(uint32_t)&App_RxDescQueue_ST[0][0],	/* Descriptor queue 6 (Stream 0) */
	(uint32_t)&App_RxDescQueue_ST[1][0],	/* Descriptor queue 7 (Stream 1) */
	(uint32_t)&App_RxDescQueue_ST[2][0],	/* Descriptor queue 8 (Stream 2) */
	(uint32_t)&App_RxDescQueue_ST[3][0],	/* Descriptor queue 9 (Stream 3) */
	(uint32_t)0,                     	/* Descriptor queue 10 (Stream 4) */
	(uint32_t)0,                     	/* Descriptor queue 11 (Stream 5) */
	(uint32_t)0,                     	/* Descriptor queue 12 (Stream 6) */
	(uint32_t)0,                     	/* Descriptor queue 13 (Stream 7) */
	(uint32_t)0,                     	/* Descriptor queue 14 (Stream 8) */
	(uint32_t)0,                     	/* Descriptor queue 15 (Stream 9) */
	(uint32_t)0,                     	/* Descriptor queue 16 (Stream 10) */
	(uint32_t)0,                     	/* Descriptor queue 17 (Stream 11) */
	(uint32_t)0,                     	/* Descriptor queue 18 (Stream 12) */
	(uint32_t)0,                     	/* Descriptor queue 19 (Stream 13) */
	(uint32_t)0,                     	/* Descriptor queue 20 (Stream 14) */
	(uint32_t)0                      	/* Descriptor queue 21 (Stream 15) */
};


/*******************************************************************************
* Return to default section
*******************************************************************************/
#pragma	section	default
