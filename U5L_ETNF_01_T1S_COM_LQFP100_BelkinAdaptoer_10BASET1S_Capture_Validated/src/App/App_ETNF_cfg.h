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
* File Name    : App_ETNF_cfg.h
* Version      : 1.00
* Device(s)    : ETNF IP
* Description  : This source file contains application-specific setting.
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__App_ETNF_cfg_H__
#define	__App_ETNF_cfg_H__


/*******************************************************************************
* Includes
*******************************************************************************/
/* general */
#include "product.h"
#include "R_driver_typedef.h"
#include "R_driver_general.h"

/* target module */
#include "R_driver_ETNF.h"


/*******************************************************************************
* Definitions for flow option
*******************************************************************************/
/* Selection of communication mode */
#define	APP_ETNF_PCS_LB	0	/* Loopback in PCS */
#define	APP_ETNF_PMA_LB	1	/* Loopback in PMA */
#define	APP_ETNF_AVB_LB	2	/* Loopback in AVB */
#define	APP_ETNF_NORMAL	3	/* normal communication (using external transceiver) */
#define	APP_COM_MODE	APP_ETNF_NORMAL

/* Communication type for test */	// update
#define APP_ETNF_TxRx	0	/* 1st communication:Transmit, 2nd communication:Receive*/
#define APP_ETNF_RxTx	1	/* 1st communication:Receive, 2nd communication:Transmit*/
#define APP_COM_TEST	APP_ETNF_TxRx

/* Communication of Master/Slave (ID=0 or not)  */
#define APP_COM_MASTER	0	/* PHY ID=0 */
#define APP_COM_SLAVE	1	/* PHY ID is not 0 */
#if ( (APP_COM_MODE == APP_ETNF_PCS_LB) ) || ( (APP_COM_MODE == APP_ETNF_PMA_LB) ) || ( (APP_COM_MODE == APP_ETNF_AVB_LB) )
	#define APP_COM_TYPE	APP_COM_MASTER	/* if want to loopback, need to set master  */
#else
	#define APP_COM_TYPE	APP_COM_MASTER
#endif

/* Selection of communication I/F */
#define	APP_ETNF_RMII	0	/* RMII I/F */
#define	APP_ETNF_T1S 	1	/* T1S I/F */
#define	APP_COM_IF	APP_ETNF_T1S

/* if defined, not clear RX buffer after reception */
#define	APP_NO_CLEAR_RXBUFFER

/* if defined, output register value set by each ETNF function */
#define	APP_REG_OUTPUT

/* device address of external PHY device */
#define	APP_RMIIPHY_DADDR	0x01

/*******************************************************************************
* Definitions
*******************************************************************************/
#define	APP_UNIT	0	/* unit number of ETNF to use */
#define	APP_PIN 	0	/* serial number of ETNF PIN (use in the function R_ETNF_OpenXXX) */

/* TX queue to use (each bit value = 1: use, 0: no use) */
#define	APP_USE_TXQ_B	( (1 << 3) | /* TX Queue 3 */ \
                     	  (1 << 2) | /* TX Queue 2 */ \
                     	  (1 << 1) | /* TX Queue 1 */ \
                     	  (1 << 0) ) /* TX Queue 0 */ 

/* Receive frame interrupt for RX queue to enable (each bit value = 1: enable, 0: disabe) */
#define	APP_RX_INT_EN	( (1 << 5) | /* RX Queue 3 (Stream 3) */ \
                     	  (1 << 4) | /* RX Queue 2 (Stream 2) */ \
                     	  (1 << 3) | /* RX Queue 1 (Stream 1) */ \
                     	  (1 << 2) | /* RX Queue 0 (Stream 0) */ \
                     	  (1 << 1) | /* Network Control */ \
                     	  (1 << 0) ) /* Best Effort */ 
						
/* Receive frame interrupt for descriptor to enable (each bit value = 1: enable, 0: disabe) */
#define	APP_DESC_INT_EN	(1 << 2) /* Descriptor interupt 2 */

/* AVB-DMAC Setting */
#define	APP_NUM_TXQ 	4	/* total number of TX queue to use */
#define	APP_NUM_RXQ 	6	/* total number of RX queue to use */
#define	APP_NUM_DESCQ	(APP_NUM_TXQ+APP_NUM_RXQ)	/* total number of TX queue and RX queue to use */

/* Separation Filter Setting */
#define	APP_NUM_SFL 	4	/* total number of separation filter to use */

/* PLCA PHY address */
#define	APP_PLCA_ADDR	ETNF_PLCA_ADDR_DEFAULT

/* External T1S transceiver address */
#define	APP_T1STANS_DADDR	0x01

/* Frame Setting */
#define APP_PAYLOAD_LEN	56U	/* Witht header and FCS */
#define APP_FRAME_LEN	(ETNF_HEADER_SIZE + APP_PAYLOAD_LEN)   /* Without FCS */
#define APP_BUF_LEN    	(APP_FRAME_LEN/4 + 1) * 4   /* Without FCS */

/*******************************************************************************
* Global variables
*******************************************************************************/
/* Source MAC address */
extern uint8_t App_SA[6]; 

/* Destination MAC  address */
extern uint8_t App_DA[4][6];
	
/* Ethernet type of transmit frame */
extern uint16_t	App_ET[];

/* configuration of EMAC */
extern ETNF_s_Config_EMAC App_Config_EMAC;

/* configuration of T1S PHY */
extern ETNF_s_Config_T1S App_Config_T1S;

/* Configure AVB-DMAC Common Setting */
#define	APP_GPTP_CLK	ETNF_e_CSEL_gPTP_clock

/* configuration of AVB-DMAC for reception */
extern ETNF_s_Config_AVBDMAC_RX App_Config_AVBDMAC_RX;

/* configuration of RX Queue */
extern ETNF_s_Config_AVBDMAC_RXQ App_Config_AVBDMAC_RXQ[APP_NUM_RXQ];

/* configuration for separation filter */
extern ETNF_s_Config_sFilter_common App_Config_sFilter_common;

/* configuration for separation filter */
extern ETNF_s_Config_sFilter App_Config_sFilter[APP_NUM_SFL];

/* configuration of AVB-DMAC for transmission */
extern ETNF_s_Config_AVBDMAC_TX App_Config_AVBDMAC_TX;


/*******************************************************************************
* Configuration for Descriptor
*******************************************************************************/
/* Base address of the descriptor table in the URAM */
extern ETNF_s_DescType_Normal App_BaseDescQueue[APP_NUM_DESCQ];

/* TX Queue */
extern ETNF_s_DescType_Normal	App_TxDescQueue[APP_NUM_TXQ][2];

/* RX Queue */
extern ETNF_s_DescType_Common	App_RxDescQueue_BE[2];
extern ETNF_s_DescType_Common	App_RxDescQueue_NC[2];
extern ETNF_s_DescType_Common	App_RxDescQueue_ST[APP_NUM_RXQ][2];

/* Base Descriptor information table */
extern uint32_t App_Config_DBAT[ETNF_NUM_DESCQ];	/* need to set all queue */

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __App_ETNF_cfg_H__ */
