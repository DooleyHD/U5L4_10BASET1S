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
* File Name    : App_interrupt.c
* Version      : 1.00
* Description  : This file describes the interrupt processing .
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "App_interrupt.h"


/*******************************************************************************
* Global variables
*******************************************************************************/
/* None */


/*******************************************************************************
* Function body
*******************************************************************************/



/*******************************************************************************
* Description  : interrupt handler of ETNF0
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
#pragma interrupt IntFunc_INTETNF0DATA( enable=false, channel=INTC_DP_INTETNF0DATA, fpu=false, fxu=false )
void IntFunc_INTETNF0DATA( void ){

	uint8_t 	n = 0;	/* unit number of ETNF */
	uint32_t	r_rx_int_sta;	/* read value of ETNFnRIS0 */
	uint32_t	r_tx_int_sta;	/* read value of ETNFnDIS */
	
	uint8_t        	curr_rx_desc_index;
	uint8_t        	next_rx_desc_index;
	uint8_t        	int_index;
	uint8_t enddesc_processing_flag;

	ETNF_s_DescType_Common	*curr_rx_desc;
	ETNF_s_DescType_Common	*next_rx_desc;

	ETNF_s_DescType_Normal  	*tx_desc;

	/* Get interrupt status
	***************************************************************************/
	/* Get receive interrupt status */
	r_rx_int_sta = rETNFnRIS0(n);
	
	/* Get descriptor interrupt status */
	r_tx_int_sta = rETNFnDIS(n);
	
	
	/* Received Data Process 
	***************************************************************************/
	if( r_rx_int_sta != 0 ){
		
		/* Clear interrut flag and set local variables */
		for( int i = 17; i >= 0; i-- ){	/* The processing priority is RIC17 to RIC0 */
			/* if receive interrupt flag RICi set */
			if( (r_rx_int_sta & (1 << i)) == (1 << i) ){
				/* set interrupt index to process */
				int_index = i;
				
				/* clear interrupt flag */
				rETNFnRIS0(n) = r_rx_int_sta & ~(1 << i);
				
				/* set local variable */
				curr_rx_desc        = ETNF_CurrRxDesc[i];
				curr_rx_desc_index  = R_ETNF_CurrRxDescIndex[i];
				next_rx_desc        = curr_rx_desc;
				next_rx_desc_index  = curr_rx_desc_index;
			
				/* Process only one queue per interrupt */
				break;
			}
		}
	
		/* Received Data Process  */
		while( ( curr_rx_desc->DT == ETNF_e_DT_FSINGLE ) ||
		       ( curr_rx_desc->DT == ETNF_e_DT_FSTART  ) ||
		       ( curr_rx_desc->DT == ETNF_e_DT_FMID    ) ||
		       ( curr_rx_desc->DT == ETNF_e_DT_FEND    ) ){

			/* Pass the received data to the application */
			App_Handle_Rx( curr_rx_desc, int_index, curr_rx_desc_index );

			next_rx_desc++;
			next_rx_desc_index++;

			/* If the next descriptor is LINK or LEMPTY, change the descriptor position to the beginning */
			if( ( next_rx_desc->DT == ETNF_e_DT_LINK ) || ( next_rx_desc->DT == ETNF_e_DT_LEMPTY ) ){
				next_rx_desc->DT = ETNF_e_DT_LINK;
				next_rx_desc = (ETNF_s_DescType_Common *)(next_rx_desc->DPTR);
				next_rx_desc_index = 0;
				
			}else{
				/* Do nothing */
			}

			/* Set the descriptor to read next */
			curr_rx_desc = next_rx_desc;
			curr_rx_desc_index = next_rx_desc_index;

		}

		/* Update current descriptor */
		ETNF_CurrRxDesc[int_index] = next_rx_desc;
		R_ETNF_CurrRxDescIndex[int_index] = curr_rx_desc_index;

	}

	/* Tranmited Data Process
	***************************************************************************/
	else if( r_tx_int_sta != 0 ){
		/* initialize flag processing end descriptor */
		enddesc_processing_flag = FALSE;
		
		/* Clear interrut flag and set local variables */
		for( int i = 15; i >= 1; i-- ){	/* The processing priority is DPF15 to DPF1 */

			/* if receive interrupt flag DPFi set */
			if( (r_tx_int_sta & (1 << i)) == (1 << i) ){
				/* set interrupt index to process */
				int_index = i;
				
				/* clear interrupt flag */
				rETNFnDIS(n) = r_tx_int_sta & ~(1 << i);
				
				/* set local variable */
				tx_desc = ETNF_CurrTxDesc[i];
			}
			
			/* Process only one queue per interrupt */
			break;
		}

		/* Procce the transmission */
		while( TRUE != enddesc_processing_flag ){
			if( (tx_desc->DT == ETNF_e_DT_EEMPTY) ||
			    (tx_desc->DT == ETNF_e_DT_EOS   ) ){
					
				/* Pass the transmitted data to the application */
				if( int_index == (tx_desc->DIE) ){
					ETNF_TXNotification( tx_desc );
				}else{
					/* Do nothing */
				}
				
				tx_desc++;
				enddesc_processing_flag = TRUE;
				
			}else if( (tx_desc->DT == ETNF_e_DT_LEMPTY ) || 
			          (tx_desc->DT == ETNF_e_DT_LINK   ) ||
			          (tx_desc->DT == ETNF_e_DT_LINKFIX) ){
				
				/* Pass the transmitted data to the application */
				if( int_index == ( tx_desc->DIE ) ){
					ETNF_TXNotification( tx_desc );
					enddesc_processing_flag = TRUE;
				}else{
					/* Do nothing */
				}

				tx_desc = (ETNF_s_DescType_Normal *)(tx_desc->DPTR);

			}else{
				
				if( int_index == (tx_desc->DIE) ){			
					if( (tx_desc->DS == 0UL             ) || 
				        (tx_desc->DT != ETNF_e_DT_FEMPTY) ){
						
						enddesc_processing_flag = TRUE;
					}else{
						/* Pass the transmitted data to the application */
						ETNF_TXNotification( tx_desc );
						
						tx_desc->DS = 0UL;
						tx_desc++;
					}
				}else{
					tx_desc++;
				}

			}

		}
		
		/* Update current descriptor */
		ETNF_CurrTxDesc[ int_index - 1 ] = tx_desc;
		
	}else{
		/* Do nothing */
	}

}



/*******************************************************************************
* Description  : Management related interrupt handler of ETNF0
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
#pragma interrupt IntFunc_INTETNF0MNG( enable=false, channel=INTC_DP_INTETNF0MNG, fpu=false, fxu=false )
void IntFunc_INTETNF0MNG( void ){

	uint32_t LulTISIntStatus;
	uint32_t LulGISIntStatus;
	uint32_t LulCompareUnit;

	LulTISIntStatus = rETNFnTIS(0);
	LulGISIntStatus = rETNFnGIS(0);

	/* Received Data Process */
	if( ( LulTISIntStatus & (TIS_TFUF_MASK | TIS_TFWF_MASK) != 0 ) ){
		if( TIS_TFUF_TIMESTAMP_FIFO_UPDATED == ( LulTISIntStatus & TIS_TFUF_MASK ) ){

			rETNFnTIS(0) = ( rETNFnTIS(0) & ( ~TIS_TFUF_MASK ) );
		}
		else if( TIS_TFWF_TIMESTAMP_FIFO_WARNING == ( LulTISIntStatus & TIS_TFWF_MASK ) ){

			rETNFnTIS(0) = ( rETNFnTIS(0) & ( ~TIS_TFWF_MASK ) );
		}
		else{
			/* Do nothing */
		}

		ETNF_TSNotification();

	}
	else if( LulGISIntStatus != 0 ){
		if( GIS_PTMF_0 == ( LulGISIntStatus & GIS_PTMF_0 ) ){

			rETNFnGIS(0) = ( rETNFnGIS(0) & ( ~GIS_PTMF_0 ) ); //Clear Interrupt
			LulCompareUnit = 0;

			/* When a compare match occurs, one entry is released in the Compare data FIFO. */
			/* If there is any Compare data that has not been set yet, set one data additionally. */
			if( 0 < GucRemainingCompareDataCount[0] ){

				do{
					/* Do nothing */
				}while( 0 != ( rETNFnGSR(0) & GSR_AFU_0 ));

				rETNFnGPTFi(0, 0) = * GpulNextCompareDataAddr[0];

				GpulNextCompareDataAddr[0]++;
				GucRemainingCompareDataCount[0]--;
			}
			else{
				/* Do nothing */
			}

		}
		else if( GIS_PTMF_1 == ( LulGISIntStatus & GIS_PTMF_1 ) ){

			rETNFnGIS(0) = ( rETNFnGIS(0) & ( ~GIS_PTMF_1 ) ); //Clear Interrupt
			LulCompareUnit = 1;

			/* When a compare match occurs, one entry is released in the Compare data FIFO. */
			/* If there is any Compare data that has not been set yet, set one data additionally. */
			if( 0 < GucRemainingCompareDataCount[1] ){

				do{
					/* Do nothing */
				}while( 0 != ( rETNFnGSR(0) & GSR_AFU_1 ));

				rETNFnGPTFi(0, 1) = * GpulNextCompareDataAddr[1];

				GpulNextCompareDataAddr[1]++;
				GucRemainingCompareDataCount[1]--;
			}
			else{
				/* Do nothing */
			}

		}
		else if( GIS_PTMF_2 == ( LulGISIntStatus & GIS_PTMF_2 ) ){

			rETNFnGIS(0) = ( rETNFnGIS(0) & ( ~GIS_PTMF_2 ) ); //Clear Interrupt
			LulCompareUnit = 2;

			/* When a compare match occurs, one entry is released in the Compare data FIFO. */
			/* If there is any Compare data that has not been set yet, set one data additionally. */
			if( 0 < GucRemainingCompareDataCount[2] ){

				do{
					/* Do nothing */
				}while( 0 != ( rETNFnGSR(0) & GSR_AFU_2 ));

				rETNFnGPTFi(0, 2) = * GpulNextCompareDataAddr[2];

				GpulNextCompareDataAddr[2]++;
				GucRemainingCompareDataCount[2]--;
			}
			else{
				/* Do nothing */
			}

		}
		else if( GIS_PTMF_3 == ( LulGISIntStatus & GIS_PTMF_3 ) ){

			rETNFnGIS(0) = ( rETNFnGIS(0) & ( ~GIS_PTMF_3 ) ); //Clear Interrupt
			LulCompareUnit = 3;

			/* When a compare match occurs, one entry is released in the Compare data FIFO. */
			/* If there is any Compare data that has not been set yet, set one data additionally. */
			if( 0 < GucRemainingCompareDataCount[3] ){

				do{
					/* Do nothing */
				}while( 0 != ( rETNFnGSR(0) & GSR_AFU_3 ));

				rETNFnGPTFi(0, 3) = * GpulNextCompareDataAddr[3];

				GpulNextCompareDataAddr[3]++;
				GucRemainingCompareDataCount[3]--;
			}
			else{
				/* Do nothing */
			}

		}
		else if( GIS_PTMF_4 == ( LulGISIntStatus & GIS_PTMF_4 ) ){

			rETNFnGIS(0) = ( rETNFnGIS(0) & ( ~GIS_PTMF_4 ) ); //Clear Interrupt
			LulCompareUnit = 4;
		}
		else if( GIS_PTMF_5 == ( LulGISIntStatus & GIS_PTMF_5 ) ){

			rETNFnGIS(0) = ( rETNFnGIS(0) & ( ~GIS_PTMF_5 ) ); //Clear Interrupt
			LulCompareUnit = 5;
		}
		else if( GIS_PTMF_6 == ( LulGISIntStatus & GIS_PTMF_6 ) ){

			rETNFnGIS(0) = ( rETNFnGIS(0) & ( ~GIS_PTMF_6 ) ); //Clear Interrupt
			LulCompareUnit = 6;
		}
		else if( GIS_PTMF_7 == ( LulGISIntStatus & GIS_PTMF_7 ) ){

			rETNFnGIS(0) = ( rETNFnGIS(0) & ( ~GIS_PTMF_7 ) ); //Clear Interrupt
			LulCompareUnit = 7;
		}
		else{
			/* Do nothing */
		}

		ETNF_AVTPComparisonNotification( LulCompareUnit );

	}
	else{
		/* Do nothing */
	}

}


/*******************************************************************************
* Description  : Handle data reception
* Arguments    : ETNF_s_DescType_Extend *rx_desc : Rx Descriptor Address
*                uint8_t queue_num : Rx Descriptor queue number
*                uint8_t desc_index: Rx Descriptor index
* Return Value : (none)
*******************************************************************************/
void App_Handle_Rx( ETNF_s_DescType_Extend *rx_desc, uint8_t queue_num, uint8_t desc_index ){

	uint32_t i;
	uint32_t i_max;
	uint8_t *rx_data;
	
	
	/* Get time stamp
	***************************************************************************/
	if( (ETNF_e_DT_FSINGLE == (rx_desc->DT)) || (ETNF_e_DT_FSTART == (rx_desc->DT)) ){

		App_RxTs[App_RxCount].ulReceivedDataPos = App_CurrResultDataPosition;
		App_RxTs[App_RxCount].TS0 = (rx_desc->TS0);
		App_RxTs[App_RxCount].TS1 = (rx_desc->TS1);
		App_RxTs[App_RxCount].TS2 = (rx_desc->TS2);
		App_RxCount++;
	}else{
		/* Do nothing */
	}
	
	
	/* Get received data
	***************************************************************************/
	/* set address of received data pointed the descriptor */
	rx_data = (uint8_t *)rx_desc->DPTR;
	
	i_max = (rx_desc->DS) + App_CurrResultDataPosition;
	
	/* Store received data to result area and clear RX buffer */
	for( i = App_CurrResultDataPosition; i < i_max; i++ ){

		/* Store received data to RX buffer */
		App_RxData[i] = (uint8_t)*rx_data;
		
		/* clear RX buffer */
#ifndef APP_NO_CLEAR_RXBUFFER
		*rx_data = 0x00;
#endif
		
		/* increment index */
		rx_data++;
		App_CurrResultDataPosition++;
		
		/* if result area over flow, overwrite from index 0 */
		if( APP_TOTAL_RX_DATA_SIZE < App_CurrResultDataPosition ){
			App_CurrResultDataPosition = 0;
		}
	}

	/* descriptor initialization
	***************************************************************************/
	rx_desc->DS   = (uint32_t)APP_FRAME_LEN;
	rx_desc->CTRL = 0;
	rx_desc->DIE  = ETNF_e_DIE_disable;
	rx_desc->TS0  = (uint32_t) 0UL;
	rx_desc->TS1  = (uint32_t) 0UL;
	rx_desc->TS2  = 0UL;
	rx_desc->DT   = ETNF_e_DT_FEMPTY;
	
}
