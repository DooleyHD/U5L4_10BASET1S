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
* File Name    : R_driver_ETNF
* Version      : 1.00
* Device(s)    : ETNF
* Description  : This is source file for ETNF function.
*******************************************************************************/

/*******************************************************************************
* Ver.1.00     : 2024/06/20
*                - Create New
*******************************************************************************/


/*******************************************************************************
* Includes
*******************************************************************************/
#include "product.h"
#include "R_driver_ETNF.h"
#include "R_COM.h"

/*******************************************************************************
* Register base address definition
*******************************************************************************/
const uint32_t	ETNFn_base_addr[]     = { ETNF_inst_0_BASE };
const uint32_t	ETNFn_T1S_base_addr[] = { ETNF0_T1S_inst_0_BASE };


/*******************************************************************************
* Global variable
*******************************************************************************/


/* for descriptor handling
*******************************************************************************/
/* Holds the the RX normal/extended descriptor currently being processed by the ETNF driver. */
ETNF_s_DescType_Common *ETNF_CurrRxDesc[ETNF_NUM_RXQ];

/* Holds the index of the RX descriptor currently being processed by the ETNF driver. */
uint8_t R_ETNF_CurrRxDescIndex[ETNF_NUM_RXQ];

/* Holds the the TX descriptor currently being processed by the ETNF driver.
   The index is based on DIE. */
ETNF_s_DescType_Normal *ETNF_CurrTxDesc[ETH_MAX_NUM_OF_DIE] = { 
	NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, 
	NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR };


/* for AVTP FIFO
*******************************************************************************/
const uint32_t *GpulNextCompareDataAddr[ETH_NUM_OF_AVTP_FIFO_COMPARE_UNIT];
uint8_t GucRemainingCompareDataCount[ETH_NUM_OF_AVTP_FIFO_COMPARE_UNIT];

/*******************************************************************************
* Description  : Request transmission suspend and wait until suspended
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : (none)
*******************************************************************************/
void R_ETNF_SuspendTransmission( uint8_t n ){

	/* Request data transfer suspend */
	Reg32SetBit( &rETNFnCCC(n), 8 );	/* DTSR = 1 */

	/* wait until data transfer suspend */
	Reg32Wait1( &rETNFnCSR(n), 8 ); 	/* wait until DTS = 0 */

}

/*******************************************************************************
* Description  : Operation Mode Change
* Arguments    : uint8_t  n  : unit number of ETNF
*                uint8_t mode : Mode to change
* Return Value : (none)
*******************************************************************************/
void R_ETNF_ChangeMode( uint8_t n, ETNF_e_OPC mode ){
	
	/* transition to specify mode */
	if ( mode == ETNF_e_OPC_reset_mode ){
		
		/* check current mode */
		if( R_ETNF_Get_CurrentMode( n ) == ETNF_e_OPS_operation_mode ){
			/* Request transmission suspend and wait until suspended */
			R_ETNF_SuspendTransmission( n );
		}

		/* transition to Reset mode */
		R_ETNF_SetMode( n, ETNF_e_OPC_reset_mode );
		
		/* wait until transition to Reset mode */
		R_ETNF_WaitModeChenge( n, ETNF_e_OPS_reset_mode )
			;
		
	}else if ( mode == ETNF_e_OPC_config_mode ){

		/* if current mode is operation mode */
		if( R_ETNF_Get_CurrentMode( n ) == ETNF_e_OPS_operation_mode ){

			/* Disable reception and transmisson */
			R_ETNF_StopTransmisson( n );
			R_ETNF_StopReception( n );

			/* wait until Receive Process Status is Normal operation */
			Reg32Wait0( &rETNFnCSR(n), 20 );	/* wait until RPO = 0 */

			/* wait until all Transmit Process Status is Normal operation */
			while( rETNFnCSR(n) != 0 )
				;

			/* wait until all Transmission Descriptor Update On-going is No pending */
			Reg32Wait0( &rETNFnCSR(n), 21 );	/* wait until TDUO = 0 */

			/* Request transmission suspend and wait until suspended */
			R_ETNF_SuspendTransmission( n );
	
			/* transition to Configuration mode */
			R_ETNF_SetMode( n, ETNF_e_OPC_config_mode );
			
			/* if transition to Configuration mode did not successfull */
			if( R_ETNF_Get_CurrentMode( n ) != ETNF_e_OPC_config_mode ){
				
				/* transition to Operation mode */
				R_ETNF_SetMode( n, ETNF_e_OPC_operation_mode );
				
				/* Clear request data transfer suspend */
				Reg32ClearBit( &rETNFnCCC(n), 8 );	/* DTSR = 0 */

				/* wait until Receive Process Status is Normal operation */
				Reg32Wait0( &rETNFnCSR(n), 20 );	/* wait until RPO = 0 */
				
				/* wait until all Transmission Descriptor Update On-going is No pending */
				Reg32Wait0( &rETNFnCSR(n), 21 );	/* wait until TDUO = 0 */

				/* Request transmission suspend and wait until suspended */
				R_ETNF_SuspendTransmission( n );
	
				/* transition to Configuration mode */
				Reg32RMWC( &rETNFnCCC(n), ETNF_e_OPC_config_mode, 0x3, 0 );	/* OPC = ETNF_e_OPC_config_mode */
	
				/* wait until transition to Configuration mode */
				R_ETNF_WaitModeChenge( n, ETNF_e_OPS_config_mode )
					;
			}

		}else{

			/* transition to Configuration mode */
			R_ETNF_SetMode( n, ETNF_e_OPC_config_mode );
	
			/* wait until transition to Configuration mode */
			R_ETNF_WaitModeChenge( n, ETNF_e_OPS_config_mode )
				;
		}

		/* Clear request data transfer suspend */
		Reg32ClearBit( &rETNFnCCC(n), 8 );	/* DTSR = 0 */

	}else if( mode == ETNF_e_OPC_operation_mode ){
		/* transition to operation mode */
		R_ETNF_SetMode( n, ETNF_e_OPC_operation_mode );

		/* wait until transition to operation mode */
		R_ETNF_WaitModeChenge( n, ETNF_e_OPS_operation_mode )
			;

	}else if( mode == ETNF_e_OPC_standby_mode ){
		/* transition to standby mode */
		R_ETNF_SetMode( n, ETNF_e_OPC_standby_mode );

		/* wait until transition to standby mode */
		R_ETNF_WaitModeChenge( n, ETNF_e_OPS_standby_mode )
			;
	}

}


/*******************************************************************************
* Description  : E-MAC Initialization
* Arguments    : uint8_t n                 : unit number of ETNF
*                ETNF_s_Config_EMAC *config: Configuration value for E-MAC
* Return Value : (none)
*******************************************************************************/
uint8_t R_ETNF_ConfigEMAC( uint8_t n, ETNF_s_Config_EMAC *config ){

	volatile uint32_t LulLoopCount;
	volatile uint32_t LusPhyReadResult;
	uint32_t	value;
	uint8_t 	ret = RET_OK;

	
	/* Set MAC address 
	***************************************************************************/
	ret += Reg32WRC( &rETNFnMAHR(n), config->mahr, 0xFFFFFFFF );	/* lower 4bytes (1st:2nd:3rd:4th) */
	ret += Reg32WRC( &rETNFnMALR(n), config->malr, 0x0000FFFF );	/* upper 2bytes (5th:6th) */
	
	
	/* Configure E-MAC Mode
	***************************************************************************/
	/* prepare setting value */
	value = ( ( config->ECMR.TRCCM ) << 26 ) |
			( ( config->ECMR.RCSC  ) << 23 ) |
			( ( config->ECMR.DPAD  ) << 21 ) |
			( ( config->ECMR.RZPF  ) << 20 ) |
			( ( config->ECMR.ZPF   ) << 19 ) |
			( ( config->ECMR.PFR   ) << 18 ) |
			( ( config->ECMR.RXF   ) << 17 ) |
			( ( config->ECMR.TXF   ) << 16 ) |
			( ( config->ECMR.DM    ) <<  1 ) |
			( ( config->ECMR.PRM   ) <<  0 ) ;

	/* set to register */
	ret += Reg32WRC( &rETNFnECMR(n), value, 0x04BF00C3 );
	
	
	/* Configure Receive Frame Length
	***************************************************************************/
	ret += Reg32WRC( &rETNFnRFLR(n), config->size, 0x0003FFFF );
	
	
	/* Configure E-MAC false Carrier Detect Interrupt Enable
	***************************************************************************/
	ret += Reg32WRC( &rETNFnECSIPR(n), config->icdip, 0x00000001 );
	

	return( ret );
}


/*******************************************************************************
* Description  : Configuration of T1S PHY
* Arguments    : uint8_t  n  : unit number of ETNF
*                ETNF_s_Config_T1S config : Configuration of T1S PHY
* Return Value : (none)
*******************************************************************************/
uint8_t R_ETNF_Config_T1SPHY( uint8_t n, ETNF_s_Config_T1S config ){

	uint32_t	value;
	uint8_t 	ret = RET_OK;
	
	
	/* prepare setting value */
	value = ( ( config.pma_cfg    << 24 ) |
	          ( 0x7F              << 17 ) |	/* bit 23 to 17 are fixed 1 */
	          ( config.mdio_share << 16 ) |
	          ( 0x7FF             <<  5 ) |	/* bit 14 to 5 are fixed 1 */
	          ( config.phy_add    <<  0 ) );

	/* set register */
	ret += Reg32WRC( &rETNFnT1SCTL0(n), value, 0x01FFFFFF );
	
	
	return( ret );
}

/*******************************************************************************
* Description  : Base Descriptor Queue Setting
* Arguments    : uint8_t  n   : unit number of ETNF
*                uint32_t addr[]: Descriptor Queue Address
*                ETNF_s_DescType_Normal dbat[]: Descriptor base address table
* Return Value : (none)
*******************************************************************************/
void R_ETNF_Config_DBAT( uint8_t n, uint32_t addr[], ETNF_s_DescType_Normal dbat[] ){

	uint8_t 	i;
	uint8_t 	i_rx;	/* index for RX descriptor */
	
	
	/* Set configuration value to each queue in DBAT */
	for( i = 0; i < ETNF_NUM_DESCQ; i++ ){

		dbat[i].DS   = (uint32_t)0UL;
		dbat[i].CTRL = 0;
		dbat[i].DIE  = ETNF_e_DIE_disable;
		dbat[i].DPTR = addr[i];
		dbat[i].DT   = ETNF_e_DT_LINKFIX;

		/* RX queue */
		if( ETNF_NUM_TXQ <= i ){	/* The index of RX queue starts from ETNF_NUM_TXQ. */
			/* i_rx is the relative index of the RX descriptor queue.
			   Each descriptor queue is defined in the config in the order TX to RX. */
			i_rx = i - ETNF_NUM_TXQ;
			
			/* set descriptor address to ETNF_CurrRxDesc */
			ETNF_CurrRxDesc[i_rx] = (ETNF_s_DescType_Common *)(addr[i]);
		}else{
			/* Do nothing */
		}
	}

	/* initialize index */
	for ( i = 0; i < ETNF_NUM_RXQ; i++ ){
		R_ETNF_CurrRxDescIndex[i] = 0;
	}

}

/*******************************************************************************
* Description  : Current Tx Desscriptor Setting
* Arguments    : ETNF_s_DescType_Normal *desc_queue_addr : Tx Descriptor Queue Address
*                uint8_t total_num: Total Number of Descriptor
* Return Value : (none)
*******************************************************************************/
void R_ETNF_CurrentTxDescSetting( ETNF_s_DescType_Normal *desc_queue_addr, uint8_t total_num ){

	ETNF_s_DescType_Normal *tx_desc_addr;
	ETNF_s_DescType_Normal *tx_desc_queue_addr;
	uint8_t i;

	tx_desc_queue_addr = desc_queue_addr;
	tx_desc_addr = desc_queue_addr;	/* address of descriptor 0 in desc_queue_addr */


	for( i = 0; i < total_num; i++ ){
		if( 0U < (tx_desc_addr->DIE) ){
		
			ETNF_CurrTxDesc[(tx_desc_addr->DIE) - 1] = tx_desc_queue_addr;
		}
		else{
			/* Do Nothing */
		}

		tx_desc_addr++;
	}
}


/*******************************************************************************
* Description  : AVB-DMAC Rx Setting
* Arguments    : uint8_t  n  : unit number of ETNF
*                ETNF_s_Config_AVBDMAC_RX  *config_rx : Configuration ric for AVB-DMAC Rx
*                ETNF_s_Config_AVBDMAC_RXQ *config_rxq: Configuration ric for Rx Queue
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_ETNF_Config_AVBDMAC_Rx( uint8_t n, ETNF_s_Config_AVBDMAC_RX *config_rx, ETNF_s_Config_AVBDMAC_RXQ *config_rxq ){

	uint8_t 	i, i_end;
	uint8_t 	queue;
	uint32_t	value;
	uint32_t	rqc[5];
	uint8_t 	ret = RET_OK;

	
	/* Configure Receive Configuration
    ***************************************************************************/
	/* prepare setting value */
	/* set register */
	value = ( (config_rx->RFCL) << 16) |
	        ( (config_rx->ETS2) << 5 ) |
	        ( (config_rx->ETS0) << 4 ) |
	        ( (config_rx->ESF ) << 2 ) |
	        ( (config_rx->ENCF) << 1 ) |
	        ( (config_rx->EFFS) << 0 );
			
	/* set register */
	Reg32WRC( &rETNFnRCR(n), value, 0x01FFF003F );
	
	
	/* Configure Receive Configuration
    ***************************************************************************/	
	/* prepare set values */
	for(i = 0; i < ETH_NUM_OF_RQC_REG; i++){
		rqc[i] = 0;
	}
	
	i_end = config_rx->rxq_num;
	queue = config_rxq->queue;
	
	for ( i = 0; i < i_end; i++ ){
		if( 4 > queue ){
			rqc[0] = rqc[0] |
			         ( ETNF_e_RSM_write_back << (  queue * 8      ) ) |	/* fixed */
			         ( (config_rxq->UFCC)    << ( (queue * 8) + 4 ) ) |
			         ( (config_rxq->PIA )    << ( (queue * 8) + 6 ) );
					 
		}else if( ( 4 <= config_rxq->queue ) && ( 8 > config_rxq->queue ) ){
			rqc[1] = rqc[1] |
			         ( ETNF_e_RSM_write_back << (   (queue - 4) * 8 )       ) |	/* fixed */
			         ( (config_rxq->UFCC)    << ( ( (queue - 4) * 8 ) + 4 ) ) |
			         ( (config_rxq->PIA )    << ( ( (queue - 4) * 8 ) + 6 ) );
					 
		}else if( ( 8 <= config_rxq->queue ) && ( 12 > config_rxq->queue ) ){
			rqc[2] = rqc[2] |
			         ( ETNF_e_RSM_write_back << (   (queue - 8) * 8 )     )   |	/* fixed */
			         ( (config_rxq->UFCC)    << ( ( (queue - 8) * 8 ) + 4 ) ) |
			         ( (config_rxq->PIA )    << ( ( (queue - 8) * 8 ) + 6 ) );
					 
		}else if( ( 12 <= config_rxq->queue ) && ( 16 > config_rxq->queue ) ){
			rqc[3] = rqc[3] |
			         ( ETNF_e_RSM_write_back << (   (queue - 12) * 8 )       ) |	/* fixed */
			         ( (config_rxq->UFCC)    << ( ( (queue - 12) * 8 ) + 4 ) ) |
			         ( (config_rxq->PIA )    << ( ( (queue - 12) * 8 ) + 6 ) );
					 
		}else if( ( 16 <= config_rxq->queue ) && ( 18 > config_rxq->queue ) ){
			rqc[4] = rqc[4] |
			         ( ETNF_e_RSM_write_back << (   (queue - 16) * 8 )       ) |	/* fixed */
			         ( (config_rxq->UFCC)    << ( ( (queue - 16) * 8 ) + 4 ) ) |
			         ( (config_rxq->PIA )    << ( ( (queue - 16) * 8 ) + 6 ) );
		}else{
			/* Do Nothing */
		}

		config_rxq++;
	}

	/* set registers */
	for(i = 0; i < ETH_NUM_OF_RQC_REG; i++){
		Reg32WRC( &rETNFnRQCi(n, i), rqc[i], 0x73737373 );
	}

	
	/* Configure Receive Configuration
    ***************************************************************************/
	/* prepare setting value */
	rETNFnRPC(n) = ( (config_rx->DCNT) << 16 ) |
	               ( (config_rx->PCNT) <<  8 );
			
	/* set registers */
	Reg32WRC( &rETNFnRPC(n), value, 0x00FF0700 );
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : Configuration to descriptor interrupt
* Arguments    : uint8_t  n  : unit number of ETNF
*                uint8_t desc_hword: Specify the descriptor to enable interrupt.
*                                    The bit position corresponds to the descriptor index.
*                            ex) 0x00000002: descriptor 1
*                                0x0000000E: descriptor 3-1
*                                0x0000FFFE: descriptor 15-1
* Return Value : (none)
*******************************************************************************/
#define	R_ETNF_ConfigDescInt(n,desc_hword)	Reg32WRC( &rETNFnDIC(n), desc_hword, 0x0000FFFE )	/* DPE15-1=desc_hword */


/*******************************************************************************
* Description  : AVB-DMAC Tx Setting
* Arguments    : uint8_t  n  : unit number of ETNF
*                ETNF_s_Config_AVBDMAC_TX *config: Configuration value for AVB-DMAC Tx
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_ETNF_Config_AVBDMAC_Tx( uint8_t n, ETNF_s_Config_AVBDMAC_TX *config ){

	uint32_t	value;
	uint8_t 	ret = RET_OK;
	
	
	/* Configure Transmit Configuration
    ***************************************************************************/
	/* prepare setting value */
	value = ( (config->TBD3) << 20 ) |	/* Transmit FIFO Size (Stream Class A) */
			( (config->TBD2) << 16 ) |	/* Transmit FIFO Size (Stream Class B) */
			( (config->TBD1) << 12 ) |	/* Transmit FIFO Size (Network Control) */
			( (config->TBD0) <<  8 ) |	/* Transmit FIFO Size (Best Effort) */
			( (config->TQP)  <<  4 ) |	/* Transmit Queue Priority */
			( ETNF_e_TSM3_with_write_back << 3 ) |	/* 0: With write-back (Stream Class A) */
			( ETNF_e_TSM2_with_write_back << 2 ) |	/* 0: With write-back (Stream Class B) */
			( ETNF_e_TSM1_with_write_back << 1 ) |	/* 0: With write-back (Network Control) */
			( ETNF_e_TSM0_with_write_back << 0 ) ;	/* 0: With write-back (Best Effort) */
			
	/* set register */
	ret += Reg32WRC( &rETNFnTGC(n), value, 0x0033333F );
	
	
	/* Configure Transmit Configuration Control
    ***************************************************************************/
	/* prepare setting value */
	value = ( Reg32Read(rETNFnTCCR(n)) & ( ~( (1 << 16) | (1 << 8) ) ) ) |
			( ( config->MFEN ) << 16 ) | 
			( ( config->TFEN ) <<  8 );
			
	/* set register */
	ret += Reg32WRC( &rETNFnTCCR(n), value, 0x0003030F );
	
	
	return( ret );

}


/*******************************************************************************
* Description  : Configure Separation Filter Pattern
* Arguments    : uint8_t  n  : unit number of ETNF
*                ETNF_s_Config_sFilter *config: Configuration value for Separation filter
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_ETNF_Config_sFilterPattern( uint8_t n, ETNF_s_Config_sFilter *config ){

	uint8_t 	x = config->num;
	uint8_t 	ret = RET_OK;
	
	
	/* Set Separation Filter Pattern */
	ret += Reg32WRC( &rETNFnSFPi(n, (x * 2)), config->fl_value_lower, 0xFFFFFFFF );
	ret += Reg32WRC( &rETNFnSFPi(n, (x * 2)+1), config->fl_value_upper, 0xFFFFFFFF );

	
	return( ret );
	
}


/*******************************************************************************
* Description  : Configure Separation Filter Mask
* Arguments    : uint8_t  n  : unit number of ETNF
*                ETNF_s_Config_sFilter_common *config: Configuration value for Separation filter Mask setting
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_ETNF_Config_sFilterMask( uint8_t n, ETNF_s_Config_sFilter_common *config ){

	uint8_t 	ret = RET_OK;
	
	
	/* Set Separation Filter Mask */
	ret += Reg32WRC( &rETNFnSFMi(n,0), config->fl_mask_lower, 0xFFFFFFFF );
	ret += Reg32WRC( &rETNFnSFMi(n,1), config->fl_mask_upper, 0x0000FFFF );
	
	
	return( ret );
	
}

/*******************************************************************************
* Description  : Wait for MDC half cycle to keep MDC level
*                The wait time of this function decides period of MDC.
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void R_ETNF_KeepLevel_MDC( void ){

	volatile uint32_t LulLoopCount;

	LulLoopCount = ETH_PHY_MDC_DELAY;

	do{
		LulLoopCount--;
	}while( LulLoopCount > 0 );

}


/*******************************************************************************
* Description  : 1-bit data write to MII interface
* Arguments    : uint8_t    n  : unit number of ETNF
*                ETNF_e_MDO mdo: output value to MDO pin (0 or 1)
* Return Value : (none)
*******************************************************************************/
void R_ETNF_OutputMO_bit( uint8_t n, ETNF_e_MDO mdo ){

	uint8_t      	mdo_bit;	/* bit 2 */
	const uint8_t	mmd_write_bit= ETNF_e_MMD_write << 1;	/* bit 1 */


	/* make MDO bit value */
	mdo_bit = mdo << 2;

	rETNFnPIR(n) = (uint32_t)( mdo_bit | mmd_write_bit | ETNF_e_MDC_low );
	R_ETNF_KeepLevel_MDC();

	rETNFnPIR(n) = (uint32_t)( mdo_bit | mmd_write_bit | ETNF_e_MDC_high );
	R_ETNF_KeepLevel_MDC();

	rETNFnPIR(n) = (uint32_t)( mdo_bit | mmd_write_bit | ETNF_e_MDC_low );
	R_ETNF_KeepLevel_MDC();

}


/*******************************************************************************
* Description  : 1-bit data read from MII interface
* Arguments    : uint8_t    n  : unit number of ETNF
* Return Value : ETNFnPIR.MDI bit value
*******************************************************************************/
uint8_t R_ETNF_InputMI_bit( uint8_t n ){

	const uint8_t	mdo_low_bit = ETNF_e_MDO_low << 2;  	/* bit 2 */
	const uint8_t	mmd_read_bit = ETNF_e_MMD_read << 1;	/* bit 1 */
	uint8_t      	read;
	 unsigned long i;

	/* get MDI sequence */
	read = (uint8_t)( (Reg32Read (rETNFnPIR(n)) >> 3) & 0x01);

	rETNFnPIR(n) = (uint32_t)( mdo_low_bit | mmd_read_bit | ETNF_e_MDC_high );
	R_ETNF_KeepLevel_MDC();


	rETNFnPIR(n) = (uint32_t)( mdo_low_bit | mmd_read_bit | ETNF_e_MDC_low );
	R_ETNF_KeepLevel_MDC();

	return( read );
}


/*******************************************************************************
* Description  : release MII interface for write sequence
* Arguments    : uint8_t    n  : unit number of ETNF
* Return Value : (none)
*******************************************************************************/
void R_ETNF_ReleaseMO_write( uint8_t n ){

	const uint8_t	mdo_low_bit = ETNF_e_MDO_low << 2;	/* bit 2 */
	const uint8_t	mmd_read_bit = ETNF_e_MMD_read << 1;	/* bit 1 */


	/* release sequence for write process */
	rETNFnPIR(n) = (uint32_t)( mdo_low_bit | mmd_read_bit | ETNF_e_MDC_low );
	R_ETNF_KeepLevel_MDC();

}


/*******************************************************************************
* Description  : release MII interface for read sequence
* Arguments    : uint8_t    n  : unit number of ETNF
* Return Value : (none)
*******************************************************************************/
void R_ETNF_ReleaseMO_read( uint8_t n ){

	const uint8_t	mdo_low_bit = ETNF_e_MDO_low << 2; 	/* bit 2 */
	const uint8_t	mmd_read_bit = ETNF_e_MMD_read << 1;	/* bit 1 */


	/* release sequence for read process */
	rETNFnPIR(n) = (uint32_t)( mdo_low_bit | mmd_read_bit | ETNF_e_MDC_low );
	R_ETNF_KeepLevel_MDC();

	rETNFnPIR(n) = (uint32_t)( mdo_low_bit | mmd_read_bit | ETNF_e_MDC_high );
	R_ETNF_KeepLevel_MDC();

	rETNFnPIR(n) = (uint32_t)( mdo_low_bit | mmd_read_bit | ETNF_e_MDC_low );
	R_ETNF_KeepLevel_MDC();

	rETNFnPIR(n) = (uint32_t)( mdo_low_bit | mmd_read_bit | ETNF_e_MDC_high );
	R_ETNF_KeepLevel_MDC();

	rETNFnPIR(n) = (uint32_t)( mdo_low_bit | mmd_read_bit | ETNF_e_MDC_low );
	R_ETNF_KeepLevel_MDC();

}


/*******************************************************************************
* Description  : PHY Write Control Register
* Arguments    : uint8_t  n      : unit number of ETNF
*                uint8_t  phyaddr: PHY device address
*                uint8_t  regaddr: PHY register address
*                uint16_t value  : Value to write to DATA field
* Return Value : (none)
*******************************************************************************/
void R_ETNF_WritePhyReg( uint8_t n, uint8_t phyaddr, uint8_t regaddr, uint16_t value ){

	uint16_t header;
	int8_t i;


	/* prepare header part
		bit 13 = 0: ST
		bit 12 = 1: ST
		bit 11 = 0: OP
		bit 10 = 1: OP
		bit  9 = Y: PHYAD
		bit  8 = Y: PHYAD
		bit  7 = Y: PHYAD
		bit  6 = Y: PHYAD
		bit  5 = Y: PHYAD
		bit  4 = z: REGAD
		bit  3 = z: REGAD
		bit  2 = z: REGAD
		bit  1 = z: REGAD
		bit  0 = z: REGAD */
	header =  ( (             1  << 12) |	/* ST (01B) */
	            (             1  << 10) |	/* OP (01B) */
	            ( (phyaddr&0x1F) <<  5) |	/* PHYAD (YYYYYB) */
	            ( (regaddr&0x1F) <<  0) ); 	/* PHYAD (zzzzzB) */

	/* Output preamble */
	for( i = 0; i < 32; i++ ){
		R_ETNF_OutputMO_bit( n, ETNF_e_MDO_high );
	}

	/* Output ST, OP, PHYAD, REGID */
	for ( i = 13; i >= 0; i-- ){
		R_ETNF_OutputMO_bit( n, (ETNF_e_MDO)((header & (1 << i)) >> i) );
	}

	/* TA (01B) */
	R_ETNF_OutputMO_bit( n, ETNF_e_MDO_high );
	R_ETNF_OutputMO_bit( n, ETNF_e_MDO_low );

	/* DATA (MSB to LSB) */
	for ( i = 15; i >= 0; i-- ){
		R_ETNF_OutputMO_bit( n, (ETNF_e_MDO)((value & (1 << i)) >> i) );
	}

	/* PHY Bus release in write */
	R_ETNF_ReleaseMO_write( n );

}


/*******************************************************************************
* Description  : PHY Read Control Register
* Arguments    : uint8_t  n : unit number of ETNF
*                uint8_t phyaddr: PHY device Address
*                uint8_t regaddr: PHY register address
* Return Value : uint16_t LusPhyReadResult: Read result of PHY STATUS Register
*******************************************************************************/
uint16_t R_ETNF_ReadPhyReg( uint8_t n, uint8_t phyaddr, uint8_t regaddr ){


	int8_t  	i;
	uint16_t	header;
	uint16_t	read;


	/* prepare header part
		bit 13 = 0: ST
		bit 12 = 1: ST
		bit 11 = 0: OP
		bit 10 = 1: OP
		bit  9 = Y: PHYAD
		bit  8 = Y: PHYAD
		bit  7 = Y: PHYAD
		bit  6 = Y: PHYAD
		bit  5 = Y: PHYAD
		bit  4 = z: REGAD
		bit  3 = z: REGAD
		bit  2 = z: REGAD
		bit  1 = z: REGAD
		bit  0 = z: REGAD */
	header =  ( (             1  << 12) |	/* ST (01B) */
	            (             2  << 10) |	/* OP (10B) */
	            ( (phyaddr&0x1F) <<  5) |	/* PHYAD (YYYYYB) */
	            ( (regaddr&0x1F) <<  0) ); 	/* PHYAD (zzzzzB) */

	/* Output preamble */
	for( i = 0; i < 32; i++ ){
		R_ETNF_OutputMO_bit( n, ETNF_e_MDO_high );
	}

	/* Output ST, OP, PHYAD, REGID */
	for ( i = 13; i >= 0; i-- ){
		R_ETNF_OutputMO_bit( n, (ETNF_e_MDO)((header & (1 << i)) >> i) );
	}

	/* PHY Bus release in read */
	R_ETNF_ReleaseMO_read( n );

	/* Get DATA (MSB to LSB) */
	for( i = 15; i >= 0; i-- ){
		read |= R_ETNF_InputMI_bit( n ) << i;
	}

	return( read );

}



/*******************************************************************************
* Description  : Write to PHY Clause45 Register
* Arguments    : uint8_t  n           : unit number of ETNF
*	           : uint8_t  phyAddr     : PHY address
*	           : uint32_t regAddr     : PHY Register address
*	           : uint16_t write_value : write value
* Return Value : (none)
*******************************************************************************/
void R_ETNF_WritePhyReg_Clause45( uint8_t n, uint8_t phyAddr, uint32_t regAddr, uint16_t write_value ){

	uint16_t value;


	value = (regAddr >> 16) & 0x1F;
	R_ETNF_WritePhyReg(n, phyAddr, 13, value);

	value = regAddr & 0xFFFF;
	R_ETNF_WritePhyReg(n, phyAddr, 14, value);

	value = ((regAddr >> 16) & 0x1F) | (0x01 << 14);    /* Write FN = 01 and register */
	R_ETNF_WritePhyReg(n, phyAddr, 13, value);

	/* write to register */
	R_ETNF_WritePhyReg(n, phyAddr, 14, write_value);

}


/*******************************************************************************
* Description  : Read from PHY Clause45 Register
* Arguments    : uint8_t  n           : unit number of ETNF
*	       : uint8_t  phyAddr     : PHY address
*	       : uint32_t regAddr     : PHY Register address
* Return Value : (none)
*******************************************************************************/
uint16_t R_ETNF_ReadPhyReg_Clause45( uint8_t n, uint8_t phyAddr, uint32_t regAddr ){

	uint16_t value;
	uint16_t read;


	value = (regAddr >> 16) & 0x1F;
	R_ETNF_WritePhyReg( n, phyAddr, 13, value );

	value = regAddr & 0xFFFF;
	R_ETNF_WritePhyReg( n, phyAddr, 14, value );

	value = ((regAddr >> 16) & 0x1F) | (0x01 << 14);    /* Write FN = 01 and register */
	R_ETNF_WritePhyReg( n, phyAddr, 13, value );

	/* write to register */
	read = R_ETNF_ReadPhyReg( n, phyAddr, 14 );


	return( read );
}


/*******************************************************************************
* Description  : Stop Transmission
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_ETNF_StopTransmisson( uint8_t n ){
	
	uint8_t 	ret = RET_OK;
	
	
	/* wait until ongoing transmission compete */
	R_ETNF_WaitTransmissionComplete( n );
	
	/* Disable transmission */
	ret += Reg32ClearBitCheck( &rETNFnECMR(n), 5 );	/* TE = 0 */
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Stop Reception
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_ETNF_StopReception( uint8_t n ){
	
	uint8_t 	ret = RET_OK;
	
	
	/* Disable reception */
	ret += Reg32ClearBitCheck( &rETNFnECMR(n), 6 );	/* RE = 0 */

	/* wait until ongoing reception compete */
	Reg32Wait0( &rETNFnCSR(n), 20 );	/* wait until RPO = 0 */
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Stop And Reset
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_ETNF_StopAndReset( uint8_t n ){
	
	uint8_t 	ret = RET_OK;
	
	
	/* Stop transmission */
	ret += R_ETNF_StopTransmisson(n);
	
	/* Stop reception */
	ret += R_ETNF_StopReception(n);

	/* change to reset mode  */
	R_ETNF_ChangeMode( n, ETNF_e_OPC_reset_mode );
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Wait Transmission Completed
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : (none)
*******************************************************************************/
void R_ETNF_WaitTransmissionComplete( uint8_t n ){

	/* Wait for transmission process to fetch is performed */
	while( (rETNFnTCCR(n) & 0x0000000FUL) != 0 )	/* TSRQ3-0 = 0000B? */
		;
	
	/* Wait until all TX queue transmission completed  */
	while( (rETNFnCSR(n) & 0x000F0000) != 0 ) 	/* TPO3-0 = 0000B? */
		;

}

/*******************************************************************************
* Description  : Set destination address to frame
* Arguments    : uint8_t *frame : Number of frame
*                uint8_t addr[]: Address of frame
* Return Value : (none)
*******************************************************************************/
void R_ETNF_SetFrameDA( uint8_t *frame, uint8_t addr[] ){

	uint8_t 	i;
	
	/* set addr to DA */
	for( i = ETNF_e_frameindex_DA1; i <= ETNF_e_frameindex_DA6; i++ ){
		frame[i] = addr[i-ETNF_e_frameindex_DA1];
	}
	
}


/*******************************************************************************
* Description  : Set source address to frame
* Arguments    : uint8_t *frame : Number of frame
*                uint8_t addr[]: Address of frame
* Return Value : (none)
*******************************************************************************/
void R_ETNF_SetFrameSA( uint8_t *frame, uint8_t addr[] ){

	uint8_t 	i;
	
	/* set addr to SA */
	for( i = ETNF_e_frameindex_SA1; i <= ETNF_e_frameindex_SA6; i++ ){
		frame[i] = addr[i-ETNF_e_frameindex_SA1];
	}
	
}


/*******************************************************************************
* Description  : Set Ethernet type to frame
* Arguments    : uint8_t *frame : Number of frame
*                uint16_t type: Ethernet type of frame
* Return Value : (none)
*******************************************************************************/
void R_ETNF_SetFrameET( uint8_t *frame, uint16_t type ){
		
	/* set ethernet type */
	frame[ETNF_e_frameindex_ET1] = (uint8_t)(0xFF & (type >> 0));
	frame[ETNF_e_frameindex_ET2] = (uint8_t)(0xFF & (type >> 8));

}

