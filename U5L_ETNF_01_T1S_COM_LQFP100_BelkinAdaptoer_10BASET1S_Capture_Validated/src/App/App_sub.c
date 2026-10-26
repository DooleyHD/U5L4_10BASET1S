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
* File Name    : App_sub.c
* Version      : 1.00
* Description  : This file describes the example application 
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "App_sub.h"
#include "App_main.h"
#include "R_device_RLIN3.h"
#include "App_ETNF_cfg.h"

#include "R_driver_port_reg.h"

/*******************************************************************************
* Definition
*******************************************************************************/


/*******************************************************************************
* Global variables
*******************************************************************************/
/* Reception frame count */
uint32_t App_RxCount = 0;

/* frames and buffers
*******************************************************************************/
/* transmission frame (need to allocate to RAM area ETNF can access) */
uint8_t App_TxFrame[APP_NUM_TXQ][APP_BUF_LEN] __attribute__ ((section (".GRAM_bss")));

/* reception buffer (need to allocate to RAM area ETNF can access) */
uint8_t App_RxBuffer_BE[APP_BUF_LEN] __attribute__ ((section (".GRAM_bss")));               	/* for Best Effort */
uint8_t App_RxBuffer_NC[APP_BUF_LEN] __attribute__ ((section (".GRAM_bss")));               	/* for Network Control */
uint8_t App_RxBuffer_ST[APP_NUM_RXQ-2][APP_BUF_LEN] __attribute__ ((section (".GRAM_bss")));	/* for Stream */

/* reception process
*******************************************************************************/
/* Total received timestamp */
App_s_RxTS App_RxTs[APP_TOTAL_RX_TS_SIZE];

/* current position of result data */
uint32_t App_CurrResultDataPosition;

/* Total reception data from read buffer */
volatile uint8_t App_RxData[APP_TOTAL_RX_DATA_SIZE];

/* Total transmitted timestamp */
ETNF_s_TSResult App_TxTS[APP_TOTAL_TX_TS_SIZE];

/* timestamp */
uint32_t App_CurrResultTSPosition;


/*******************************************************************************
* Description  : Output application title
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_OutputTitle( void ){
	
	R_COM_printf( "-----------------------------------------------------\n" );
	
#if APP_COM_MODE == APP_ETNF_PCS_LB
	R_COM_printf( "- Communication in the PCS loop back mode       -\n" );
#elif APP_COM_MODE == APP_ETNF_PMA_LB
	R_COM_printf( "- Communication in the PMA loop back mode       -\n" );
#elif APP_COM_MODE == APP_ETNF_AVB_LB
	R_COM_printf( "- Communication in the AVB loop back mode       -\n" );
#else
	R_COM_printf( "- Communication using external PHY device           -\n" );
#endif
	R_COM_printf( "-----------------------------------------------------\n" );
	R_COM_printf( "\n" );
	
}

/*******************************************************************************
* Description  : Global variable Initialization
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Init_GlobalVariable( void ){
	

	R_COM_printf( "[App_Init_GlobalVariable] ... " );
	
	/* Reception frame count */
	App_RxCount = 0;
	
	/* Initialize pointer for reveived frame */
	App_CurrResultDataPosition = 0;		/* received data (index of App_RxData) */
	App_CurrResultTSPosition = 0;  		/* received timestamp (index of App_RxTs)  */

	R_COM_printf( "Done.\n" );
}


/*******************************************************************************
* Description  : Initial setting for ETNF
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
uint8_t App_Init_ETNF( void ){

	uint8_t 	ret = RET_OK;
	uint8_t 	n = APP_UNIT;	/* unit number of ETNF to use */
	

	R_COM_printf( "[App_Init_ETNF]\n" );
	
	/* E-MAC and AVB-DMAC initialization 
	****************************************************************************/
	R_COM_printf( "[Change to Configuration Mode]\n" );
	/* Change to Configuration Mode */
	R_ETNF_ChangeMode( n, ETNF_e_OPC_config_mode );

	/* E-MAC Initialization */
	R_COM_printf( "[E-MAC Initialization]\n" );
	ret += App_InitSetting_EMAC(n);
	
	/* AVB-DMAC common setting */
	R_COM_printf( "[AVB-DMAC common setting]\n" );
	ret += App_InitSetting_AVBDMAC_Common(n);

	/* AVB-DMAC setting for reception */
	R_COM_printf( "[AVB-DMAC setting for reception]\n" );
	ret += App_InitSetting_AVBDMAC_RX(n);
	
	/* AVB-DMAC setting for transmission */
	R_COM_printf( "[AVB-DMAC setting for transmission]\n" );
	ret += App_InitSetting_AVBDMAC_TX(n);
	
	/* Descriptor related configuration
	****************************************************************************/
	/* Descriptor base address table Setting */
	R_ETNF_Config_DBAT( n, &App_Config_DBAT[0], &App_BaseDescQueue[0] );

	/* Rx Descriptor Setting */
	App_Make_RxDesc();

	/* Tx Frame Setting */	
	App_Make_TxFrame();

	/* Tx Descriptor Setting */
	App_Make_TxDesc();
	
	/* Change to Operation Mode */
	R_COM_printf( "[Change to Operation Mode] ... " );
	R_ETNF_ChangeMode( n, ETNF_e_OPC_operation_mode );
	R_COM_printf( "Done\n" );

#if ( (APP_COM_MODE == APP_ETNF_PCS_LB) && (APP_COM_IF == APP_ETNF_T1S) ) || \
	( (APP_COM_MODE == APP_ETNF_PMA_LB) && (APP_COM_IF == APP_ETNF_T1S) ) || \
	( (APP_COM_MODE == APP_ETNF_NORMAL) && (APP_COM_IF == APP_ETNF_T1S) )
	/* Configure T1S PHY (PLCA) */
	App_ConfigureT1SPHYSetting( n );
#endif

	/* Enable Transmission and Reception */
	R_ETNF_Enable_TXRX(n);

	R_COM_printf( "[Enabled Transmission and Reception]\n" );
	
	return( ret );
	
}


/*******************************************************************************
* Description  : Configure E-MAC Setting
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t App_InitSetting_EMAC( uint8_t n ){

	uint8_t 	ret = RET_OK;
	
	
	/* configuration of EMAC
	***************************************************************************/
	R_ETNF_ConfigEMAC( n, &App_Config_EMAC );
	

	/* PHY initialization
	***************************************************************************/
#if APP_COM_MODE != APP_ETNF_AVB_LB
{
	uint32_t 	value;
	
#if APP_COM_IF == APP_ETNF_RMII
	R_ETNF_WritePhyReg( n, ETH_PHY_RESET, APP_RMIIPHY_DADDR );

	do{
		value = R_ETNF_ReadPhyReg( n, APP_RMIIPHY_DADDR, ETH_PHY_CONTROL_REG_ID );
	}while( ((value & ETH_PHY_RESET) != ETH_PHY_RESET_REQ_CLEARED) || (value == PHY_ALL_HIGH_LEVEL) );

#elif APP_COM_IF == APP_ETNF_T1S
	/* configure T1S PHY initialize */
	R_ETNF_Config_T1SPHY( n, App_Config_T1S );
	
	/* Reset PHY and wait it's completed */
	value = (1 << 15);
	R_ETNF_WritePhyReg( n, APP_PLCA_ADDR, ETNF_rPLCA_CONTROL_REG, value );

	do {	    
		value = R_ETNF_ReadPhyReg( n, APP_PLCA_ADDR, ETNF_rPLCA_CONTROL_REG );
	}while( (value & (1 << 15)) == (1 << 15) );
	
#endif
}
#endif
	
#ifdef APP_REG_OUTPUT	
	App_Output_Config_EMAC( "[After EMAC setting]", n );
#endif

	return( ret );
}


/*******************************************************************************
* Description  : Configure AVB-DMAC Common Setting
* Arguments    : uint8_t  n: unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t App_InitSetting_AVBDMAC_Common( uint8_t n ){
	
	uint8_t 	ret = RET_OK;
	
	
	/* Set base address of the descriptor table in the URAM */
	ret += R_ETNF_SetDescBaseAddrTable( n, (uint32_t)&App_BaseDescQueue[0] );
	
#if APP_COM_MODE == APP_ETNF_AVB_LB
	/*  Enable AVB loop back */
	R_ETNF_EnableAVBLB(n);
#endif
	
#ifdef APP_REG_OUTPUT	
	App_Output_Config_DMAC_common( "[After AVB-DMAC common setting]", n );
#endif


	return( ret );
	
}


/*******************************************************************************
* Description  : Configure AVB-DMAC Rx Setting
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t App_InitSetting_AVBDMAC_RX( uint8_t n ){

	uint8_t 	ret = RET_OK;


	/* Configuration of Reception frame interrupt enable
	***************************************************************************/
	ret += R_ETNF_ConfigRxInt( n, APP_RX_INT_EN );
	
	
	/* conifuration of AVB-DMAC for reception
	***************************************************************************/
	ret += R_ETNF_Config_AVBDMAC_Rx( n, &App_Config_AVBDMAC_RX, &App_Config_AVBDMAC_RXQ[0] );

#ifdef APP_REG_OUTPUT	
	App_Output_Config_Receive( "[After reception setting]", n );
#endif


	/* conifuration of Separation filter
	***************************************************************************/
	/* offset */
	ret += R_ETNF_SetsFilterOffset( n, App_Config_sFilter_common.offset );

	/* filter values */
	for( int i = 0; i < APP_NUM_SFL; i++ ){
		ret += R_ETNF_Config_sFilterPattern( n, &App_Config_sFilter[i] );	
	}
		
	/* filter mask */
	ret += R_ETNF_Config_sFilterMask( n, &App_Config_sFilter_common );

#ifdef APP_REG_OUTPUT	
	App_Output_Config_sFilter( "[After execute Separation filter functions]", n, APP_NUM_SFL );
#endif


	return( ret );
	
}


/*******************************************************************************
* Description  : Configure AVB-DMAC Tx Setting
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t App_InitSetting_AVBDMAC_TX( uint8_t n ){

	uint8_t 	ret = RET_OK;
	
	
	/* Transmission frame interrupt enable
	***************************************************************************/
	ret += R_ETNF_ConfigDescInt( n, APP_DESC_INT_EN );
	
	
	/* configuration of AVB-DMAC for transmission
	***************************************************************************/
	ret += R_ETNF_Config_AVBDMAC_Tx( n, &App_Config_AVBDMAC_TX );

#ifdef APP_REG_OUTPUT	
	App_Output_Config_transmit( "[After transmission setting]", n );
#endif

	return( ret );
	
}


/*******************************************************************************
* Description  : Initial setting of RX descriptors of each RX queue
*                It use the receive frame interrupt to know when each queue has 
*                received data, so it disable the descriptor interrupts for all 
*                RX queues.
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Make_RxDesc( void ){
	
	/* Set initial value of each desctiptor
	 *    - Rx Descriptor Queue 0 (Best Effort)
	***************************************************************************/
		App_RxDescQueue_BE[0].DS   = (uint32_t)APP_FRAME_LEN;
		App_RxDescQueue_BE[0].CTRL = 0;
		App_RxDescQueue_BE[0].DIE  = ETNF_e_DIE_disable;
		App_RxDescQueue_BE[0].DPTR = (uint32_t)&App_RxBuffer_BE[0];
		App_RxDescQueue_BE[0].TS0  = (uint32_t)0UL;
		App_RxDescQueue_BE[0].TS1  = (uint32_t)0UL;
		App_RxDescQueue_BE[0].TS2  = 0UL;
		App_RxDescQueue_BE[0].DT   = ETNF_e_DT_FEMPTY;

		App_RxDescQueue_BE[1].DS   = (uint32_t)0UL;
		App_RxDescQueue_BE[1].CTRL = 0;
		App_RxDescQueue_BE[1].DIE  = ETNF_e_DIE_disable;
		App_RxDescQueue_BE[1].DPTR = (uint32_t)&App_RxDescQueue_BE[0];
		App_RxDescQueue_BE[1].TS0  = (uint32_t)0UL;
		App_RxDescQueue_BE[1].TS1  = (uint32_t)0UL;
		App_RxDescQueue_BE[1].TS2  = 0UL;
		App_RxDescQueue_BE[1].DT   = ETNF_e_DT_LINKFIX;
		
	
	/* Set initial value of each desctiptor
	 *    - Rx Descriptor Queue 1 (Network Control)
	***************************************************************************/
		App_RxDescQueue_NC[0].DS   = (uint32_t)APP_FRAME_LEN;
		App_RxDescQueue_NC[0].CTRL = 0;
		App_RxDescQueue_NC[0].DIE  = ETNF_e_DIE_disable;
		App_RxDescQueue_NC[0].DPTR = (uint32_t)&App_RxBuffer_NC[0];
		App_RxDescQueue_NC[0].TS0  = (uint32_t)0UL;
		App_RxDescQueue_NC[0].TS1  = (uint32_t)0UL;
		App_RxDescQueue_NC[0].TS2  = 0UL;
		App_RxDescQueue_NC[0].DT   = ETNF_e_DT_FEMPTY;

		App_RxDescQueue_NC[1].DS   = (uint32_t)0UL;
		App_RxDescQueue_NC[1].CTRL = 0;
		App_RxDescQueue_NC[1].DIE  = ETNF_e_DIE_disable;
		App_RxDescQueue_NC[1].DPTR = (uint32_t)&App_RxDescQueue_NC[0];
		App_RxDescQueue_NC[1].TS0  = (uint32_t)0UL;
		App_RxDescQueue_NC[1].TS1  = (uint32_t)0UL;
		App_RxDescQueue_NC[1].TS2  = 0UL;
		App_RxDescQueue_NC[1].DT   = ETNF_e_DT_LINKFIX;
		
		
	/* Set initial value of each desctiptor
	 *    - Rx Descriptor Queue 2 (Stream 0)
	 *    - Rx Descriptor Queue 3 (Stream 1)
	 *    - Rx Descriptor Queue 4 (Stream 2)
	 *    - Rx Descriptor Queue 5 (Stream 3)
	***************************************************************************/
	for( uint8_t i = 0; i < APP_NUM_RXQ; i++ ){		/* from Stream 0 */
		App_RxDescQueue_ST[i][0].DS   = (uint32_t)APP_FRAME_LEN;
		App_RxDescQueue_ST[i][0].CTRL = 0;
		App_RxDescQueue_ST[i][0].DIE  = ETNF_e_DIE_disable;
		App_RxDescQueue_ST[i][0].DPTR = (uint32_t)&App_RxBuffer_ST[i][0];
		App_RxDescQueue_ST[i][0].TS0  = (uint32_t)0UL;
		App_RxDescQueue_ST[i][0].TS1  = (uint32_t)0UL;
		App_RxDescQueue_ST[i][0].TS2  = 0UL;
		App_RxDescQueue_ST[i][0].DT   = ETNF_e_DT_FEMPTY;

		App_RxDescQueue_ST[i][1].DS   = (uint32_t)0UL;
		App_RxDescQueue_ST[i][1].CTRL = 0;
		App_RxDescQueue_ST[i][1].DIE  = ETNF_e_DIE_disable;
		App_RxDescQueue_ST[i][1].DPTR = (uint32_t)&App_RxDescQueue_ST[i][0];
		App_RxDescQueue_ST[i][1].TS0  = (uint32_t)0UL;
		App_RxDescQueue_ST[i][1].TS1  = (uint32_t)0UL;
		App_RxDescQueue_ST[i][1].TS2  = 0UL;
		App_RxDescQueue_ST[i][1].DT   = ETNF_e_DT_LINKFIX;
	}

}


/*******************************************************************************
* Description  : Make transmit frame to App_TxFrame[].
*                The address of App_TxFrame will set DPTR of TX descriptor in
*                the function App_Make_TxDesc.
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Make_TxFrame( void ){

	uint32_t	i;
	
	
	/* set header
	***************************************************************************/
	/* set header to frame */
	for( i = 0; i < ETNF_NUM_TXQ; i++ ){
		/* Set destination address to frame */
		R_ETNF_SetFrameDA( App_TxFrame[i], &App_DA[i][0] );
		
		/* Set source address to frame */
		R_ETNF_SetFrameSA( App_TxFrame[i], &App_SA[0] );
		
		/* Set type to frame */
		R_ETNF_SetFrameET( App_TxFrame[i], App_ET[i] );
	}
	
	
	/* set payload
	***************************************************************************/
	/* set payload to frame */
	for(i = 0; i < APP_PAYLOAD_LEN; i++){
		App_TxFrame[0][i + ETNF_HEADER_SIZE] = 0x11;
		App_TxFrame[1][i + ETNF_HEADER_SIZE] = 0x22;
		App_TxFrame[2][i + ETNF_HEADER_SIZE] = 0x33;
		App_TxFrame[3][i + ETNF_HEADER_SIZE] = 0x44;	
	}

}


/*******************************************************************************
* Description  : Initial setting of TX descriptors of each TX queue
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_Make_TxDesc( void ){
	
	ETNF_s_CTRL_TX	ctrl_tx;

	
	/* Set initial value of each desctiptor
	 *    - Tx Descriptor Queue 0 
	 *    - Tx Descriptor Queue 1 
	 *    - Tx Descriptor Queue 2
	 *    - Tx Descriptor Queue 3
	***************************************************************************/
	for( uint8_t i = 0; i < APP_NUM_TXQ; i++ ){
		/* Content control for transmission */
		ctrl_tx.BIT.TAG = i + 1;	/* Frame Tag */
		ctrl_tx.BIT.TSR = ETNF_e_TSR_retain_ts;	/* Timestamp Store Request */
		ctrl_tx.BIT.MSR = ETNF_e_MSR_no_info;	/* MAC Status storage Request */
		
		/* Descriptor Setting */
		App_TxDescQueue[i][0].DS   = (uint32_t)APP_FRAME_LEN;
		App_TxDescQueue[i][0].CTRL = ctrl_tx.ALL;
		App_TxDescQueue[i][0].DIE  = ETNF_e_DIE_DSF1;
		App_TxDescQueue[i][0].DPTR = (uint32_t) &App_TxFrame[i][0];
		App_TxDescQueue[i][0].DT   = ETNF_e_DT_FSINGLE;
		
		App_TxDescQueue[i][1].DS   = (uint32_t)0UL;
		App_TxDescQueue[i][1].CTRL = 0;
		App_TxDescQueue[i][1].DIE  = ETNF_e_DIE_disable;
		App_TxDescQueue[i][1].DPTR = (uint32_t) &App_TxDescQueue[i][0];
		App_TxDescQueue[i][1].DT   = ETNF_e_DT_LINKFIX;

		R_ETNF_CurrentTxDescSetting( &App_TxDescQueue[i][0], ETH_TOTAL_NUM_OF_DESC_2 );
	}

}


/*******************************************************************************
* Description  : configure PHY Setting for PLCA
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : (none)
*******************************************************************************/
void App_ConfigureT1SPHYSetting( uint8_t n ){
	
	uint16_t	value;
	
	/* Set loop back for PHY(PCS) */
#if APP_COM_MODE == APP_ETNF_PCS_LB
	value = (1 << 14) | /* LOOP: loop back enable */
	        (1 << 12);	/* LCTL: the PHY transmit/receive functions are activated */
#else
	value = (1 << 12);	/* LCTL: the PHY transmit/receive functions are activated */
#endif	
	R_ETNF_WritePhyReg( n, APP_PLCA_ADDR, ETNF_rPLCA_CONTROL_REG, value );

#ifdef debug
{	/* for debug */
	R_COM_printf( "      write value  = 0x%4x\n", value );
	value = R_ETNF_ReadPhyReg( n, APP_PLCA_ADDR, ETNF_rPLCA_CONTROL_REG );
	R_COM_printf( "      PLCA_CONTROL = 0x%4x\n", value );
	value = R_ETNF_ReadPhyReg( n, APP_PLCA_ADDR, ETNF_rPLCA_STATUS_REG );
	R_COM_printf( "      PLCA_STATUS  = 0x%4x\n", value );
	value = R_ETNF_ReadPhyReg( n, APP_PLCA_ADDR, ETNF_rPLCA_STATUS_REG );
	R_COM_printf( "      PLCA_STATUS  = 0x%4x\n", value );
	value = R_ETNF_ReadPhyReg( n, APP_PLCA_ADDR, ETNF_rPLCA_STATUS_REG );
	R_COM_printf( "      PLCA_STATUS  = 0x%4x\n", value );
}
#endif

	R_COM_printf( "[wait PLCA status] ... " );
	do{
		value = R_ETNF_ReadPhyReg( n, APP_PLCA_ADDR, ETNF_rPLCA_STATUS_REG );
	}while( (value & ETNF_rPLCA_STATUS_REG_DONE) != ETNF_rPLCA_STATUS_REG_DONE );
	R_COM_printf( "Done\n" );


	/* configuration for CT25205-specific features */
	value = (0 << 15) |	/* PKTLOOP = 0: the TX frame is not reflected back on the MII RX */
	        (0 <<  7) |	/* ENIE    = 0: PHY does not operate in Enhanced Noise Immunity mode (ENI). */
	        (0 <<  6) |	/* UNJT    = 0: the PCS does not perform automatic recovery from the TX cooldown state */
	        (0 <<  3) |	/* RXNRZ   = 0: the AFE RX signal is assumed to be RZ encoded */
	        (0 <<  2) |	/* SCRD    = 0: the PCS scrambling and de-scrambling functions are enabled */
	        (1 <<  1) |	/* NCOLM   = 1: PLCA status is 0 the collision detection is always enabled regardless the value of this bit */
	        (1 <<  0); 	/* RXDLY   = 1: the MII RX signals are delayed in order to avoid concurrent MII TX and MII RX communication during PLCA operation mode. */
	R_ETNF_WritePhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_T1STWEAKS, value );    /* T1STWEAKS */

	value = R_ETNF_ReadPhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_T1STWEAKS);    /* PLCACTRL1 Device as master */
	
	/* configuration for CT25205-specific PLCA features (initial value) */
	        
	value = (0 << 15) |	/* PREN    = 0: the PLCA RS does not operate in strict-precedence mode */
	        (1 << 11) |	/* reserved= 1: fixed */
	        (0 <<  1) |	/* LDEN    = 0: the PLCA role of this node is selected by the node ID */
	        (0 <<  0);	/* LDR     = 0: no use because LDEN = 0 */
	        	         
	        
	R_ETNF_WritePhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_T1SPLCAEXT, value );   /* T1SPLCAEXT */
	value = R_ETNF_ReadPhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_T1SPLCAEXT);    /* PLCACTRL1 Device as master */

	/* configuration for CT25205-specific PMA features */

	/* Set loop back for PHY(PMA) */
#if APP_COM_MODE == APP_ETNF_PMA_LB
	value = (0 << 15) |	/* PMARST    = 0: Setting this bit causes the PCS and PMA PHY layers to reset. */
	        (0 << 14) |	/* TXDIS	= 0: When the TXDIS bit is set, the PHY transmitter is shut down, and any transmission request is ignored. */
	        (0 << 11) |	/* LPWR    = 0: This bit is an alias of the Clause 22 low-power mode bit */
	        (1 << 10) |	/* MULT    = 1: this bit is read-only and always read as ‘1’ (multidrop mode enabled). */
	        (1 <<  0);	/* LOOP     = 1: When this bit is set, any data coming from the MAC is looped back. */
#else
	value = (0 << 15) |	/* PMARST    = 0: Setting this bit causes the PCS and PMA PHY layers to reset. */
	        (0 << 14) |	/* TXDIS	= 0: When the TXDIS bit is set, the PHY transmitter is shut down, and any transmission request is ignored. */
	        (0 << 11) |	/* LPWR    = 0: This bit is an alias of the Clause 22 low-power mode bit */
	        (1 << 10) |	/* MULT    = 1: this bit is read-only and always read as ‘1’ (multidrop mode enabled). */
	        (0 <<  0);	/* LOOP     = 0: When this bit is set, any data coming from the MAC is looped back. */
#endif

	R_ETNF_WritePhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_T1SPMACTRL, value );   /* T1SPMACTRL */
	value = R_ETNF_ReadPhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_T1SPMACTRL);    /* PLCACTRL1 Device as master */
		
	/* basic PLCA configuration */
	value = (1 << 15) |	/* EN  = 1: the PLCA RS functions are enabled */
	        (0 << 14); 	/* RST = 0: the PLCA RS is not reset */
	        	        
	R_ETNF_WritePhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_PLCACTRL0, value );    /* PLCACTRL0 Enable PLCA */

	value = R_ETNF_ReadPhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_PLCACTRL0);    /* PLCACTRL1 Device as master */

	/* ******************************************************************************** */
	/* Please make the necessary settings according to the transceiver specifications.  */
	/* ******************************************************************************** */
	/* Setting Transceiver */



	/* configuring the PLCA node count and local node ID parameters */
	if (APP_COM_TYPE == APP_COM_MASTER){
		value = (0x09 << 8) |	/* NCNT = 0x09: the PLCA node count parameter on the PLCA coordinator node */
		        (0x00 << 0); 	/* ID   = 0x00: the PLCA node ID parameter of the node */
	}else if(APP_COM_TYPE == APP_COM_SLAVE){
		value = (0x02 << 8) |	/* NCNT = 0x09: the PLCA node count parameter on the PLCA coordinator node */
		        (0x01 << 0); 	/* ID   = 0x01: the PLCA node ID parameter of the node */
	}else{
	}
	
	R_ETNF_WritePhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_PLCACTRL1, value );    /* PLCACTRL1 Device as master */

	value = R_ETNF_ReadPhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_PLCACTRL1);    /* PLCACTRL1 Device as master */

	/* Forces RESET requests to the TXC */
	R_ETNF_WritePhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_T1STXCCTL, ETNF_e_T1S_CMD_RESETRQ );
	
	/* Normal operation */
	R_ETNF_WritePhyReg_Clause45( n, APP_PLCA_ADDR, ETNF_rPLCA_T1STXCCTL, ETNF_e_T1S_CMD_NORQ );

	/* wait until linkup */
	do{
		value = R_ETNF_ReadPhyReg( n, APP_PLCA_ADDR, ETNF_rPLCA_STATUS_REG );
	}while( (value & ETNF_rPLCA_STATUS_REG_DONE) != ETNF_rPLCA_STATUS_REG_DONE );


#ifdef APP_REG_OUTPUT	
	App_Output_Config_PLCA( "[After execute PLCA]", n );
#endif
}


/*******************************************************************************
* Description  : Data transmission notification
* Arguments    : ETNF_s_DescType_Extend * pTxDescAddr : Tx Descriptor Address
* Return Value : (none)
*******************************************************************************/
void ETNF_TXNotification( ETNF_s_DescType_Normal * pTxDescAddr ){
	/* Do nothing */
}

/*******************************************************************************
* Description  : tETNF InternalLoopback check
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : (none)
*******************************************************************************/
uint8_t App_Check_Rxframe( uint8_t n ){

	uint8_t j;	
	uint8_t i;
	uint8_t	ret = 0;
	

	for( i = 0; i < App_RxCount; i++ ){
//		for( j = 0; j < 70; j++ ){

	#if (APP_COM_MODE == APP_ETNF_PCS_LB) | (APP_COM_MODE == APP_ETNF_AVB_LB)
		for( j = 0; j < 70; j++ ){
	#else
		for( j = 14; j < 70; j++ ){
	#endif
	

			if( i == 0 ){
				if((uint32_t) App_TxFrame[0][j] != App_RxData[(70U * (App_RxCount-1)) - (i*70) + j ]){
					ret++;
				}
			}else if( i == 1 ){
				if((uint32_t) App_TxFrame[1][j] != App_RxData[(70U * (App_RxCount-1)) - (i*70) + j ]){
					ret++;
				}		
			}else if( i == 2 ){
				if((uint32_t) App_TxFrame[2][j] != App_RxData[(70U * (App_RxCount-1)) - (i*70) + j ]){
					ret++;
				}		
			}else if( i == 3 ){
				if((uint32_t) App_TxFrame[3][j] != App_RxData[(70U * (App_RxCount-1)) - (i*70) + j ]){
					ret++;
				}		
			}else{
			}
		}

	}
	
	return( ret );
	
}
