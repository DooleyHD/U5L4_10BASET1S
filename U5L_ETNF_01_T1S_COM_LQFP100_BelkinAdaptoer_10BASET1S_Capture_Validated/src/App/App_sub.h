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
* File Name    : App_sub.h
* Version      : 1.00
* Description  : This header file is for the application
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__App_sub_H__
#define	__App_sub_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "App_main.h"
#include "App_check.h"

/* target module */
#include "App_ETNF_cfg.h"
#include "R_driver_ETNF.h"

/*******************************************************************************
* Type definition
*******************************************************************************/
typedef struct{
	uint32_t TS0;
	uint32_t TS1;
	uint16_t TS2;
	uint32_t ulReceivedDataPos;
}App_s_RxTS;



/*******************************************************************************
* Definition
*******************************************************************************/


/* Separation Filter Setting */
#define	ETH_SEPARATION_MASK_LOWER_SA                    0xFFFFFFFFUL
#define ETH_SEPARATION_MASK_UPPER_SA                    0x0000FFFFUL

/* PHY Setting */
#define ETH_PHY_DEVICE_ADDR                             1U
#define ETH_PHY_CTRL_SPEED_10MBPS                       0U
#define ETH_PHY_CTRL_SPEED_100MBPS                      1U
#define ETH_PHY_CTRL_POWER_DOWN_NORMAL                  0U
#define ETH_PHY_CTRL_ISOLATE_NORMAL                     0U
#define ETH_PHY_CTRL_RESTART_NEGOTIATION_NORMAL         0U
#define ETH_PHY_CTRL_FULL_DUPLEX                        1U

#define	ETH_TOTAL_NUM_OF_DESC_2                         2U
#define	ETH_TOTAL_NUM_OF_DESC_7                         7U
#define	APP_TOTAL_RX_DATA_SIZE                         530U /* 74 byte * 6 + 78 byte */

/* gPTP Timer Setting */
#define	ETH_GPTP_NO_USE                                 0U
#define	ETH_GPTP_CLOCK_SOURCE                           3U
#define ETH_GPTP_TIMER_INCREMENT_VALUE                  10485760UL
#define ETH_GPTP_TIMER_NO_OFFSET                        0UL
#define ETH_GPTP_TIMER_MID_OFFSET                       0xFFFF0000UL
#define ETH_MAX_TRANSITION_TIME_16                      0x00000010UL

#define ETH_TCSS_GPTP_TIMER                             0U
#define ETH_TCSS_ADJUSTED_GPTP_TIMER                    1U
#define ETH_TCSS_AVTP_PRESENTATION_TIME                 2U

#define ETH_COMPARE_UNIT_0                              0U
#define ETH_COMPARE_UNIT_1                              1U
#define ETH_COMPARE_UNIT_2                              2U
#define ETH_NUM_OF_COMPARE_1                            1U
#define ETH_NUM_OF_COMPARE_17                           17U
#define ETH_SINGLE_SHOT_COMPARE                         0U
#define ETH_PERIOD_COMPARE                              1U

#define ETH_GPTP_TOTAL_NUM_OF_AVTP_FIFO_COMPARE_CONFIG  17U
#define ETH_GPTP_TOTAL_NUM_OF_SINGLE_COMPARE_CONFIG     1U
#define ETH_GPTP_TOTAL_NUM_OF_PERIOD_COMPARE_CONFIG     1U

#define APP_TOTAL_TX_TS_SIZE                        32UL
#define ETH_RESULT_AVTP_CAPTURE_SIZE                        32UL
#define ETH_RESULT_CAPTURE_TIMER_SIZE                       2UL
#define APP_TOTAL_RX_TS_SIZE                        6UL

#define PHY_MII_PRE_VALUE                  0xFFFFFFFF
#define PHY_MII_ST                         0x1
#define PHY_MII_OP_READ                    0x2
#define PHY_MII_OP_WRITE                   0x1
#define PHY_MII_TA_WRITE                   0x2


#define	tETNFn		(0)

#define ETNF_MDIO_DELAY (1000)


/*******************************************************************************
* Extern of global variables
*******************************************************************************/
/* Reception frame count */
extern uint32_t App_RxCount;


/* frames and buffers
*******************************************************************************/
/* transmission frame (need to allocate to RAM area ETNF can access) */
extern uint8_t App_TxFrame[APP_NUM_TXQ][APP_BUF_LEN];

/* reception buffer (need to allocate to RAM area ETNF can access) */
extern uint8_t App_RxBuffer_BE[APP_BUF_LEN];            	/* for Best Effort */
extern uint8_t App_RxBuffer_NC[APP_BUF_LEN];            	/* for Network Control */
extern uint8_t App_RxBuffer_ST[APP_NUM_RXQ-2][APP_BUF_LEN];	/* for Stream */


/* reception process
*******************************************************************************/
/* current position of result data */
extern uint32_t App_CurrResultDataPosition;

/* Total received timestamp */
extern App_s_RxTS App_RxTs[APP_TOTAL_RX_TS_SIZE];

/* Total reception data from read buffer */
extern volatile uint8_t App_RxData[APP_TOTAL_RX_DATA_SIZE];

/* Total transmitted timestamp */
extern ETNF_s_TSResult App_TxTS[APP_TOTAL_TX_TS_SIZE];

/*******************************************************************************
* Prototype declarations of functions and 
* Functional definitions
*******************************************************************************/

/*******************************************************************************
* Description  : Output application title
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_OutputTitle( void );

/*******************************************************************************
* Description  : Initial setting for ETNF
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
uint8_t App_Init_ETNF( void );

/*******************************************************************************
* Description  : Global variable Initialization
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Init_GlobalVariable( void );

/*******************************************************************************
* Description  : Configure E-MAC Setting
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t App_InitSetting_EMAC( uint8_t n );

/*******************************************************************************
* Description  : Configure AVB-DMAC Common Setting
* Arguments    : uint8_t  n: unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t App_InitSetting_AVBDMAC_Common( uint8_t n );

/*******************************************************************************
* Description  : Configure AVB-DMAC Tx Setting
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t App_InitSetting_AVBDMAC_TX( uint8_t n );

/*******************************************************************************
* Description  : Configure AVB-DMAC Rx Setting
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t App_InitSetting_AVBDMAC_RX( uint8_t n );

/*******************************************************************************
* Description  : Initial setting of RX descriptors of each RX queue
*                It use the receive frame interrupt to know when each queue has 
*                received data, so it disable the descriptor interrupts for all 
*                RX queues.
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Make_RxDesc( void );

/*******************************************************************************
* Description  : Make transmit frame to App_TxFrame[].
*                The address of App_TxFrame will set DPTR of TX descriptor in
*                the function App_Make_TxDesc.
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Make_TxFrame( void );

/*******************************************************************************
* Description  : Initial setting of TX descriptors of each TX queue
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Make_TxDesc( void );

void App_ConfigureT1SPHYSetting( uint8_t n );

uint8_t App_Check_Rxframe( uint8_t n );

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __App_sub_H__ */

