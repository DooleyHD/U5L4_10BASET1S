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
* File Name    : R_drv_RSCCFD.h
* Version      : 1.00
* Device(s)    : RSENT
* Description  : This is header file for RSCFD driver.
*******************************************************************************/


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_RSCFD.h"


/*******************************************************************************
* Register definitions
*******************************************************************************/

/*******************************************************************************
* Global Variable Definitions
*******************************************************************************/
/* Array of pointers to TAUD registers */
/* All TAUD registers and bits can be accessed from this array. */
uint32_t	RSCFDn_base[] = {  RSCFD0_inst_0_BASE, 
           	                   RSCFD1_inst_0_BASE, 
           	                   RSCFD2_inst_0_BASE  };
							   

/*******************************************************************************
* Function body
*******************************************************************************/
/*******************************************************************************
* Description  : Preparation for use RSCFD
*                (wait until complete CANRAM initialize and transition to 
*                 Global Reset Mode.)
* Arguments    : uint8_t n: unit number of RSCFD
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_Prepare( uint8_t n, RSCFD_e_DCS dcs ){
	
	uint8_t 	ret = RET_OK;
	

 	/* wait until CANRAM initialize complete */
	while ( (Reg32Read( rRSCFDnCFDGSTS(n).UINT32 ) & (1 << 3)) != 0UL){	/* wait until GRAMINIT=0 */
		;
	}
	
	/* Release Global Stop Mode */
	ret += R_RSCFD_RelaseGloabalStop( n );
	
	/* Select RASCD communication clock */
	ret += R_RSCFD_SelectCommunicationClock( n, dcs );
	
	return( ret );
}


/*******************************************************************************
* Description  : Release Global Stop Mode
* Arguments    : uint8_t n: unit number of RSCFD
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_RelaseGloabalStop( uint8_t n ){
	
	uint8_t	ret;
	
	
	/* Release Global Stop Mode */
	ret = Reg32ClearBitCheck( &rRSCFDnCFDGCTR(n).UINT32, 2 );	/* GSLPR=0 */
    
	// wait until Global Stop Mode released
	while ( (Reg32Read( rRSCFDnCFDGSTS(n).UINT32 ) & (1 << 2)) != 0UL){	/* wait until GSLPSTS=0 */
		;
	}
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Releases Channel Stop Mode
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_ReleaseChannelStopMode( uint8_t n, uint8_t m ){
	
	uint8_t	ret;
	
	
	/* Release Channel Stop Mode */
	ret = Reg32ClearBitCheck( &rRSCFDnCFDCmCTR(n,m).UINT32, 2 );	/* CSLPR=0 */
    
	/* wait until Channel Stop Mode released */
	while ( (Reg32Read( rRSCFDnCFDCmSTS(n,m).UINT32 ) & (1 << 2)) != 0UL){	/* wait until CSLPSTS=0 */
		;
	}
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Changes specified Global Mode and until the mode changed
* Arguments    : uint8_t n        : unit number of RSCFD
*                RSCFD_e_GMDC gmdc: Global Mode to changing request
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_ChangeGloabalMode( uint8_t n, RSCFD_e_GMDC gmdc ){
	
	uint8_t 	ret;
	uint32_t	b_sts;
	
	
	/* save current state */
	if( gmdc == RSCFD_e_GMDC_keep_current_value ){
		b_sts = Reg32Read( rRSCFDnCFDGSTS(n).UINT32 );
	}
	
	/* Change Global Mode */
	ret = Reg32RMWC( &rRSCFDnCFDGCTR(n).UINT32, gmdc, 0x3, 0 );	/* GMDC[1:0]=gmdc */
	
	/* wait until mode changed */
	if( gmdc == RSCFD_e_GMDC_reset_mode ){	   
		/* wait until transition to Global Reset Mode */
		while ( (Reg32Read( rRSCFDnCFDGSTS(n).UINT32 ) & (1 << 0)) == 0UL){	/* wait until GRSTSTS=1 */
			;
		}
		
	}else if( gmdc == RSCFD_e_GMDC_test_mode ){	   
		/* wait until transition to global test mode */
		while ( (Reg32Read( rRSCFDnCFDGSTS(n).UINT32 ) & (1 << 1)) == 0UL){	/* wait until GHLTSTS=1 */
			;
		}
		
	}else if( gmdc == RSCFD_e_GMDC_keep_current_value ){
		if( b_sts == Reg32Read( rRSCFDnCFDGSTS(n).UINT32 ) ){
			/* When gmdc = RSCFD_e_GMDC_keep_current_value, the ret value is overwritten 
		       with the status check result.
		       The readback check of the RSCFDnCFDGCTR.GMDC bit will fail, so if it can 
			   confirm that the status has not changed, you can assume that this function is 
			   working correctly. */
			ret = RET_OK;
		}
	
	}else{
		/* operating mode has not status flag */
	}
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Changes specified Channel Mode and until the mode changed
* Arguments    : uint8_t n          : unit number of RSCFD
*                uint8_t m          : channel number of RSCFDn
*                RSCFD_e_CHMDC chmdc: Channel Mode to changing request
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_ChangeChannelMode( uint8_t n, uint8_t m, RSCFD_e_CHMDC chmdc ){
	
	uint8_t 	ret;
	uint32_t	b_sts;
	
	
	/* save current state */
	if( chmdc == RSCFD_e_CHMDC_keep_current_mode ){
		b_sts = Reg32Read( rRSCFDnCFDCmSTS(n,m).UINT32 );
	}
	
	/* change Channel Mode */
	ret = Reg32RMWC( &rRSCFDnCFDCmCTR(n,m).UINT32, chmdc, 0x3, 0 );	/* CHMDC[1:0]=chmdc */
	
	/* wait until mode changed */
	if( chmdc == RSCFD_e_CHMDC_communication_mode ){
		// wait until Channel Reset Mode and Halt Mode release
		while ( (Reg32Read( rRSCFDnCFDCmSTS(n,m).UINT32 ) & (3 << 0)) != 0UL){	/* wait until CRSTSTS=0 and CHLTSTS=0 */
			;
		}
	}else if( chmdc == RSCFD_e_CHMDC_reset_mode ){
		// wait until transition to Channel Reset Mode
		while ( (Reg32Read( rRSCFDnCFDCmSTS(n,m).UINT32 ) & (1 << 0)) == 0UL){	/* wait until CRSTSTS=1 */
			;
		}
	}else if( chmdc == RSCFD_e_CHMDC_halt_mode ){
		// wait until transition to channel Halt Mode
		while ( (Reg32Read( rRSCFDnCFDCmSTS(n,m).UINT32 ) & (1 << 1)) == 0UL){	/* wait until CHLTSTS=1 */
			;
		}
	}else if( chmdc == RSCFD_e_CHMDC_keep_current_mode ){
		if( b_sts == Reg32Read( rRSCFDnCFDCmSTS(n,m).UINT32 ) ){
			/* When chmdc = RSCFD_e_CHMDC_keep_current_mode, the ret value is overwritten 
		       with the status check result.
		       The readback check of the RSCFDnCFDCmCTR.CHMDC bit will fail, so if it can 
			   confirm that the status has not changed, you can assume that this function is 
			   working correctly. */
			ret = RET_OK;
		}
		
	}else{
	}
	
	
	return( ret );
}
	

/*******************************************************************************
* Description  : Configures reception rule
* Arguments    : uint8_t n          : unit number of RSCFD
*                uint8_t rule_entry   : rule No. to edit
*                RSCFD_s_config_AFL *config: reception rule
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_Config_ReceiveRule( uint8_t n, uint16_t rule_entry, RSCFD_s_config_AFL *config  ){
	
	RSCFD_s_RSCFDnCFDGAFLIDj	GAFLID_reg;
	RSCFD_s_RSCFDnCFDGAFLMj 	GAFLM_reg;
	RSCFD_s_RSCFDnCFDGAFLP0j	GAFLP0_reg;
	RSCFD_s_RSCFDnCFDGAFLP1j	GAFLP1_reg;
	uint8_t 	ret=RET_OK;
	uint8_t 	page;         	/* edit page number of reception rule */
	uint8_t 	rule_num_page;	/* edit page-relative reception rule number (r=0 to 15 per page) */
	uint32_t	value;
	
	
	/* prepare
	***************************************************************************/
	/* Calculate page number and page-relative reception rule number */
	page = rule_entry / RSCFD_j_NUM;
	rule_num_page = rule_entry % RSCFD_j_NUM;
	
	
	/* Enable writing to reception rule table & specify page number
	***************************************************************************/
	value = (   1 << 8) |	// AFLDAE=1: Acceptance Filter List Data access enable
	        (page << 0);	// AFLPN[6:0]=page: Acceptance Filter List Page = page
	ret += Reg32WRC( &rRSCFDnCFDGAFLECTR(n).UINT32, value, 0x0000017F );
	
	
	/* Set RSCFDnCFDGAFLIDj register 
	***************************************************************************/
	/* make write value */
	GAFLID_reg.BIT.GAFLID  = config->ID_comp;
	GAFLID_reg.BIT.GAFLLB  = config->GAFLLB;
	GAFLID_reg.BIT.GAFLRTR = config->RTR_comp;
	GAFLID_reg.BIT.GAFLIDE = config->IDE_comp;
	
	/* set to register */
	ret += Reg32WRC( &rRSCFDnCFDGAFLIDj(n,rule_num_page).UINT32, GAFLID_reg.UINT32, 0xFFFFFFFF );
	
	
	/* Set RSCFDnCFDGAFLMj register 
	***************************************************************************/
	/* make write value */
	GAFLM_reg.BIT.GAFLIDM = config->ID_mask;
	GAFLM_reg.BIT.GAFLIFL1 = (config->attach_IFL >> 1) & 0x1;	/* bit 1 of attach_IFL */
	GAFLM_reg.BIT.GAFLRTRM = config->RTR_mask;
	GAFLM_reg.BIT.GAFLIDEM = config->IDE_mask;
	
	/* set to register */
	ret += Reg32WRC( &rRSCFDnCFDGAFLMj(n,rule_num_page).UINT32, GAFLM_reg.UINT32, 0xFFFFFFFF );
	
	
	/* Set RSCFDnCFDGAFLP0j register 
	***************************************************************************/
	/* make write value */
	GAFLP0_reg.BIT.GAFLDLC  = config->min_dlc;
	GAFLP0_reg.BIT.GAFLSRD0 = config->GAFLSRD0;
	GAFLP0_reg.BIT.GAFLSRD1 = config->GAFLSRD1;
	GAFLP0_reg.BIT.GAFLSRD2 = config->GAFLSRD2;
	GAFLP0_reg.BIT.GAFLIFL0 = config->attach_IFL & 0x1;	/* bit 0 of attach_IFL */
	GAFLP0_reg.BIT.GAFLRMDP = config->rx_buffer_num;
	GAFLP0_reg.BIT.GAFLRMV  = config->en_rx_buffer;
	GAFLP0_reg.BIT.GAFLPTR  = config->attach_PTR;
	
	/* set to register */
	ret += Reg32WRC( &rRSCFDnCFDGAFLP0j(n,rule_num_page).UINT32, GAFLP0_reg.UINT32, 0xFFFFFFFF );
	
	
	/* Set RSCFDnCFDGAFLP1j register 
	***************************************************************************/
	/* make write value */
	GAFLP1_reg.UINT32 = (config->en_txrx_fifos << 8) |	/* enable TX/RX FIFO */
	                    (config->en_tx_queues  << 8) |	/* enable TX queue */
	                    (config->en_rx_fifos   << 0); 	/* enable RX FIFO */
	
	/* set to register */
	ret += Reg32WRC( &rRSCFDnCFDGAFLP1j(n,rule_num_page).UINT32, GAFLP1_reg.UINT32, 0xFFFFFFFF );
	
	
	/* Disable write Receive rule table
	***************************************************************************/
	ret += Reg32ClearBitCheck( &rRSCFDnCFDGAFLECTR(n).UINT32, 8 );		/* AFLDAE=0 */
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Set typical Nominal bit rate and data bit rate
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                RSCFD_e_freq freq: frequency of CLK_RSCFD
*                RSCFD_e_baudrate : typical baudrate
* Return Value : RET_OK:        Register Readback check was successful
*                RET_ERR_PARAM: Parameter is out of range
*                Others:        Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_SetPresetBaudRate( uint8_t n, uint8_t m, RSCFD_e_freq freq, RSCFD_e_baudrate baudrate ){
	
	uint8_t 	ret;
	RSCFD_s_RSCFDnCFDCmNCFG	config_NBR;
	RSCFD_s_RSCFDnCFDCmDCFG	config_DBR;
	
	
	switch( (freq << 8) | baudrate ){
		case (RSCFD_e_freq_80 << 8) | RSCFD_e_baudrate_Nomi_1M_Data_8M:
			/* Norminal baudrate */
			config_NBR.BIT.NBRP   = 0;	/* Channel Nominal Baud Rate Prescaler */
			config_NBR.BIT.NSJW   = RSCFD_PREBRG_80TQ_SWJ - 1;  	/* Nominal Bit Rate Resynchronization Jump Width Control */
			config_NBR.BIT.NTSEG1 = RSCFD_PREBRG_80TQ_TSEG1 - 1;	/* Time Segment 1 */
			config_NBR.BIT.NTSEG2 = RSCFD_PREBRG_80TQ_TSEG2 - 1;	/* Time Segment 2 */
			
			/* Data bit rate setting */
			config_DBR.BIT.DBRP   = 0;	/* Channel Data Rate Prescaler */
			config_DBR.BIT.DSJW   = (RSCFD_PREBRG_10TQ_SWJ - 1);  	/* Resynchronization Jump Width */
			config_DBR.BIT.DTSEG1 = (RSCFD_PREBRG_10TQ_TSEG1 - 1);	/* Time Segment 1 */
			config_DBR.BIT.DTSEG2 = (RSCFD_PREBRG_10TQ_TSEG2 - 1);	/* Time Segment 2 */
			
			break;
			
		case (RSCFD_e_freq_80 << 8) | RSCFD_e_baudrate_Nomi_1M_Data_5M:
			/* Norminal baudrate */
			config_NBR.BIT.NBRP   = 0;	/* Channel Nominal Baud Rate Prescaler */
			config_NBR.BIT.NSJW   = RSCFD_PREBRG_80TQ_SWJ - 1;  	/* Nominal Bit Rate Resynchronization Jump Width Control */
			config_NBR.BIT.NTSEG1 = RSCFD_PREBRG_80TQ_TSEG1 - 1;	/* Time Segment 1 */
			config_NBR.BIT.NTSEG2 = RSCFD_PREBRG_80TQ_TSEG2 - 1;	/* Time Segment 2 */
			
			/* Data bit rate setting */
			config_DBR.BIT.DBRP   = 0;	/* Channel Data Rate Prescaler */
			config_DBR.BIT.DSJW   = (RSCFD_PREBRG_16TQ_SWJ - 1);	/* Resynchronization Jump Width */
			config_DBR.BIT.DTSEG1 = (RSCFD_PREBRG_16TQ_TSEG1 - 1);	/* Time Segment 1 */
			config_DBR.BIT.DTSEG2 = (RSCFD_PREBRG_16TQ_TSEG2 - 1);	/* Time Segment 2 */
			
			break;
			
		case (RSCFD_e_freq_80 << 8) | RSCFD_e_baudrate_Nomi_500K_Data_2M:
			/* Norminal baudrate */
			config_NBR.BIT.NBRP   = 0;	/* Channel Nominal Baud Rate Prescaler */
			config_NBR.BIT.NSJW   = RSCFD_PREBRG_160TQ_SWJ - 1;  	/* Nominal Bit Rate Resynchronization Jump Width Control */
			config_NBR.BIT.NTSEG1 = RSCFD_PREBRG_160TQ_TSEG1 - 1;	/* Time Segment 1 */
			config_NBR.BIT.NTSEG2 = RSCFD_PREBRG_160TQ_TSEG2 - 1;	/* Time Segment 2 */
			
			/* Data bit rate setting */
			config_DBR.BIT.DBRP   = 0;	/* Channel Data Rate Prescaler */
			config_DBR.BIT.DSJW   = (RSCFD_PREBRG_40TQ_SWJ - 1);	/* Resynchronization Jump Width */
			config_DBR.BIT.DTSEG1 = (RSCFD_PREBRG_40TQ_TSEG1 - 1);	/* Time Segment 1 */
			config_DBR.BIT.DTSEG2 = (RSCFD_PREBRG_40TQ_TSEG2 - 1);	/* Time Segment 2 */
			
			break;
			
		case (RSCFD_e_freq_40 << 8) | RSCFD_e_baudrate_Nomi_1M_Data_8M:
			/* Norminal baudrate */
			config_NBR.BIT.NBRP   = 0;	/* Channel Nominal Baud Rate Prescaler */
			config_NBR.BIT.NSJW   = RSCFD_PREBRG_40TQ_SWJ - 1;  	/* Nominal Bit Rate Resynchronization Jump Width Control */
			config_NBR.BIT.NTSEG1 = RSCFD_PREBRG_40TQ_TSEG1 - 1;	/* Time Segment 1 */
			config_NBR.BIT.NTSEG2 = RSCFD_PREBRG_40TQ_TSEG2 - 1;	/* Time Segment 2 */
			
			/* Data bit rate setting */
			config_DBR.BIT.DBRP   = 0;	/* Channel Data Rate Prescaler */
			config_DBR.BIT.DSJW   = (RSCFD_PREBRG_5TQ_SWJ - 1);  	/* Resynchronization Jump Width */
			config_DBR.BIT.DTSEG1 = (RSCFD_PREBRG_5TQ_TSEG1 - 1);	/* Time Segment 1 */
			config_DBR.BIT.DTSEG2 = (RSCFD_PREBRG_5TQ_TSEG2 - 1);	/* Time Segment 2 */
			
			break;
			
		case (RSCFD_e_freq_40 << 8) | RSCFD_e_baudrate_Nomi_1M_Data_5M:
			/* Norminal baudrate */
			config_NBR.BIT.NBRP   = 0;	/* Channel Nominal Baud Rate Prescaler */
			config_NBR.BIT.NSJW   = RSCFD_PREBRG_40TQ_SWJ - 1;  	/* Nominal Bit Rate Resynchronization Jump Width Control */
			config_NBR.BIT.NTSEG1 = RSCFD_PREBRG_40TQ_TSEG1 - 1;	/* Time Segment 1 */
			config_NBR.BIT.NTSEG2 = RSCFD_PREBRG_40TQ_TSEG2 - 1;	/* Time Segment 2 */
			
			/* Data bit rate setting */
			config_DBR.BIT.DBRP   = 0;	/* Channel Data Rate Prescaler */
			config_DBR.BIT.DSJW   = (RSCFD_PREBRG_8TQ_SWJ - 1);	/* Resynchronization Jump Width */
			config_DBR.BIT.DTSEG1 = (RSCFD_PREBRG_8TQ_TSEG1 - 1);	/* Time Segment 1 */
			config_DBR.BIT.DTSEG2 = (RSCFD_PREBRG_8TQ_TSEG2 - 1);	/* Time Segment 2 */
			
			break;
			
		case (RSCFD_e_freq_40 << 8) | RSCFD_e_baudrate_Nomi_500K_Data_2M:
			/* Norminal baudrate */
			config_NBR.BIT.NBRP   = 0;	/* Channel Nominal Baud Rate Prescaler */
			config_NBR.BIT.NSJW   = RSCFD_PREBRG_80TQ_SWJ - 1;  	/* Nominal Bit Rate Resynchronization Jump Width Control */
			config_NBR.BIT.NTSEG1 = RSCFD_PREBRG_80TQ_TSEG1 - 1;	/* Time Segment 1 */
			config_NBR.BIT.NTSEG2 = RSCFD_PREBRG_80TQ_TSEG2 - 1;	/* Time Segment 2 */
			
			/* Data bit rate setting */
			config_DBR.BIT.DBRP   = 0;	/* Channel Data Rate Prescaler */
			config_DBR.BIT.DSJW   = (RSCFD_PREBRG_20TQ_SWJ - 1);	/* Resynchronization Jump Width */
			config_DBR.BIT.DTSEG1 = (RSCFD_PREBRG_20TQ_TSEG1 - 1);	/* Time Segment 1 */
			config_DBR.BIT.DTSEG2 = (RSCFD_PREBRG_20TQ_TSEG2 - 1);	/* Time Segment 2 */
			
			break;
			
		case (RSCFD_e_freq_20 << 8) | RSCFD_e_baudrate_Nomi_500K_Data_2M:
			/* Norminal baudrate */
			config_NBR.BIT.NBRP   = 0;	/* Channel Nominal Baud Rate Prescaler */
			config_NBR.BIT.NSJW   = RSCFD_PREBRG_40TQ_SWJ - 1;  	/* Nominal Bit Rate Resynchronization Jump Width Control */
			config_NBR.BIT.NTSEG1 = RSCFD_PREBRG_40TQ_TSEG1 - 1;	/* Time Segment 1 */
			config_NBR.BIT.NTSEG2 = RSCFD_PREBRG_40TQ_TSEG2 - 1;	/* Time Segment 2 */
			
			/* Data bit rate setting */
			config_DBR.BIT.DBRP   = 0;	/* Channel Data Rate Prescaler */
			config_DBR.BIT.DSJW   = (RSCFD_PREBRG_10TQ_SWJ - 1);	/* Resynchronization Jump Width */
			config_DBR.BIT.DTSEG1 = (RSCFD_PREBRG_10TQ_TSEG1 - 1);	/* Time Segment 1 */
			config_DBR.BIT.DTSEG2 = (RSCFD_PREBRG_10TQ_TSEG2 - 1);	/* Time Segment 2 */
			
			break;
			
	    default:
	    	ret = RET_ERR_PARAM;
	}
	
	if( ret != RET_ERR_PARAM ){
		/* Set config_NBR and config_DBR to registers */
		ret  = R_RSCFD_Config_NominalBaudrate( n, m, config_NBR.UINT32 );
		ret += R_RSCFD_Config_DataBitrate( n, m, config_DBR.UINT32 );
	}
	
	
	return( ret );
}

	
/*******************************************************************************
* Description  : Convert DLC value to message size [byte]
* Arguments    : uint8_t dlc: DLC value
*                RSCFD_e_FDF fdf: non CANFD frame or CANFD frame
* Return Value : size[byte] corresponding the argument dlc.
*                if unexpected error occured, retrun 0xFF
*******************************************************************************/
uint8_t R_RSCFD_DLC2size( uint8_t dlc, RSCFD_e_FDF fdf ){
	
	uint8_t 	size;
	uint8_t 	dlc_l;
	
	
	/* Shape dlc value */
	if( (fdf == RSCFD_e_FDF_non_CANFD_frame) & (dlc > 8) ){
		dlc_l = 8;
	}else{
		dlc_l = dlc & 0x0F;
	}
	
	/* convert dlc_l to size */
	switch( dlc_l ){
	    case 0:
	    case 1:
	    case 2:
	    case 3:
	    case 4:
	    case 5:
	    case 6:
	    case 7:
	    case 8: 	size = dlc_l; break;
	    case 9: 	size = 12;    break;	/* only CANFD */
	    case 10:	size = 16;    break;	/* only CANFD */
	    case 11:	size = 20;    break;	/* only CANFD */
	    case 12:	size = 24;    break;	/* only CANFD */
	    case 13:	size = 32;    break;	/* only CANFD */
	    case 14:	size = 48;    break;	/* only CANFD */
	    case 15:	size = 64;    break;	/* only CANFD */
	    default:	size = 0xFF;  break;	/* error */
	}
	
	
	return( size );
}


/*******************************************************************************
* Description  : Set transmit message to TX/RX FIFO
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                uint8_t k: number of TX/RX FIFO buffer
*                RSCFD_s_MB mb: fields value of transmit message
* Return Value : RET_OK:        Register Readback check was successful
*                RET_ERR_PARAM: Parameter is out of range
*                Others:        Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_SetMessageBuffer_CF( uint8_t n, uint8_t m, uint8_t k, RSCFD_s_MB *mb ){
	
	RSCFD_s_RSCFDnCFDCFFDCSTS	sts_reg;
	RSCFD_s_RSCFDnCFDCFID    	id_reg;
	RSCFD_s_RSCFDnCFDCFPTR   	ptr_reg;
	uint8_t 	i;
	uint8_t 	size;	/* transmit size [byte] */
	uint8_t 	b;
	uint8_t 	ret=RET_OK;
	uint32_t	value;
	
	
	/* make "b" value for RSCFDnCFDCFID, RSCFDnCFDCFPTR, RSCFDnCFDCFDF register */
	b = k % 3;
	
    /* wait until TX/RX FIFO does not full */
	while ( (Reg32Read( rRSCFDnCFDCFSTSk(n,k).UINT32 ) & (1 << 1)) != 0)	/* wait until CFFLL=0 */
		;
	

	/* Set ID, history data, frame kind, kind of ID
	***************************************************************************/
	/* Prepare value */
	id_reg.BIT.CFID  = mb->ID;   	/* ID field */
	id_reg.BIT.THLEN = mb->THLEN;	/* THL field */
	id_reg.BIT.CFRTR = mb->RTR;  	/* RTR field (data frame/remote frame) */
	id_reg.BIT.CFIDE = mb->IDE;  	/* IDE field (standard ID/extended ID) */
	
	/* set to register  */
	ret += Reg32WRC( &rRSCFDnCFDCFID(n,m,b).UINT32, id_reg.UINT32, 0xFFFFFFFF );
	
	
	/* Set ESI, BRS, FDF, IFL, PTR field
	***************************************************************************/
	/* Prepare value */
	sts_reg.BIT.CFESI = mb->ESI;   	/* ESI field */
	sts_reg.BIT.CFBRS = mb->BRS;   	/* BRS field */
	sts_reg.BIT.CFFDF = mb->FDF;   	/* FDF field */
	sts_reg.BIT.CFIFL = mb->IFL;   	/* IFL field */
	sts_reg.BIT.CFPTR = mb->PTR;   	/* PTR field */
	
	/* set to register  */
	ret += Reg32WRC( &rRSCFDnCFDCFFDCSTS(n,m,b).UINT32, sts_reg.UINT32, 0xFFFFFFFF );
	
	
	/* Set DLC, timestamp
	***************************************************************************/
	/* Prepare value */
	ptr_reg.BIT.CFTS  = mb->TS;    	/* TS field (timestamp) */
	ptr_reg.BIT.Reserved_16 = 0;
	ptr_reg.BIT.CFDLC = mb->DLC;   	/* DLC field */
	
	/* set to register  */
	ret += Reg32WRC( &rRSCFDnCFDCFPTR(n,m,b).UINT32, ptr_reg.UINT32, 0xFFFFFFFF );
	
	
	/* Set payload data
	***************************************************************************/
	/* get total size to set from DLC */
	size = R_RSCFD_DLC2size( mb->DLC, mb->FDF );
	
	/* set transmit data */
	for( i = 0; i < size/4; i++ ){
		/* convert 1 byte to 4 byte */
		value = (mb->DB[i*4+3] << 8*3) |
		        (mb->DB[i*4+2] << 8*2) |
		        (mb->DB[i*4+1] << 8*1) |
		        (mb->DB[i*4+0] << 8*0);
		
		/* set to register */
		ret += Reg32WRC( &rRSCFDnCFDCFDFd(n,m,b,i).UINT32, value, 0xFFFFFFFF );
	}
	/* Since size is a multiple of 4 bytes, no processing is required 
	   if the length is less than 4 bytes. */
	
		
	return( ret );
}
	
#if 0
/* How to use the function R_RSCFD_SetMessageBuffer_CF */
	uint8_t n = 0;	/* unit number of RSCFD */
	uint8_t m = 0;	/* channel number of RSCFDn */
	uint8_t k = 0;	/* number of TX/RX FIFO buffer */
	RSCFD_s_MB	mb;	/* fields value of transmit message */
	uint8_t		data[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07 };
	
	
	/* prepare ESI, BRS, FDF, IFL, PTR field */
	mb.ESI = RSCFD_e_ESI_active_node;    	/* ESI field */
	mb.BRS = RSCFD_e_BRS_no_bitrate;     	/* BRS field */
	mb.FDF = RSCFD_e_FDF_non_CANFD_frame;	/* FDF field */
	mb.IFL = 0x3;                        	/* IFL field */
	mb.PTR = 0;                          	/* PTR field */
	
	/* prepare ID, history data, frame kind, kind of ID */
	mb.ID    = 0x5A;                  	/* ID */
	mb.THLEN = RSCFD_e_THLEN_disable; 	/* Transmit history data is not stored in the buffer */
	mb.RTR   = RSCFD_e_RTR_data_frame;	/* Data Frame */
	mb.IDE   = RSCFD_e_IDE_STD_ID;    	/* Standard ID */
	
	/* prepare DLC, timestamp */
	mb.DLC   = 0x8;                   	/* DLC */        	
	mb.TS    = 0;                     	/* timestamp value */
	
	/* set pointer of transmit data */
	mb.DB    = data;	
	
	/* set TX/RX FIFO */
	R_RSCFD_SetMessageBuffer_CF( n, m, k, mb );
#endif


/*******************************************************************************
* Description  : Set transmit message to TX Buffer
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                uint8_t p: number of TX buffer
*                RSCFD_s_MB mb: fields value of transmit message
* Return Value : RET_OK:        Register Readback check was successful
*                RET_ERR_PARAM: Parameter is out of range
*                Others:        Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_SetMessageBuffer_TM( uint8_t n, uint8_t m, uint8_t p, RSCFD_s_MB *mb ){
	
	RSCFD_s_RSCFDnCFDTMFDCTR	ctr_reg;
	RSCFD_s_RSCFDnCFDTMID   	id_reg;
	RSCFD_s_RSCFDnCFDTMPTR  	ptr_reg;
	uint8_t 	d;
	uint8_t 	size;	/* transmit size [byte] */
	uint8_t 	b;
	uint32_t	value;
	uint8_t 	ret=RET_OK;
	
	
	/* make "b" value for RSCFDnCFDTMID, RSCFDnCFDTMPTR, RSCFDnCFDTMDF register */
	b = p % RSCFD_TM_PER_CH_NUM;
	

	/* set ID, history data, frame kind, kind of ID
	***************************************************************************/
	/* Prepare value */
	id_reg.BIT.TMID  = mb->ID;   	/* ID field */
	id_reg.BIT.THLEN = mb->THLEN;	/* THL field */
	id_reg.BIT.TMRTR = mb->RTR;  	/* RTR field (data frame/remote frame) */
	id_reg.BIT.TMIDE = mb->IDE;  	/* IDE field (standard ID/extended ID) */

	/* set to register  */
	ret += Reg32WRC( &rRSCFDnCFDTMID(n,m,b).UINT32, id_reg.UINT32, 0xFFFFFFFF );
	

	/* Set ESI, BRS, FDF, IFL, PTR field
	***************************************************************************/
	/* Prepare value */
	ctr_reg.BIT.TMESI = mb->ESI;   	/* ESI field */
	ctr_reg.BIT.TMBRS = mb->BRS;   	/* BRS field */
	ctr_reg.BIT.TMFDF = mb->FDF;   	/* FDF field */
	ctr_reg.BIT.TMIFL = mb->IFL;   	/* IFL field */
	ctr_reg.BIT.TMPTR = mb->PTR;   	/* PTR field */
	
	/* set to register  */
	ret += Reg32WRC( &rRSCFDnCFDTMFDCTR(n,m,b).UINT32, ctr_reg.UINT32, 0xFFFFFFFF );
	

	/* set DLC, timestamp
	***************************************************************************/
	/* Prepare value */
	ptr_reg.BIT.Reserved_0 = 0;
	ptr_reg.BIT.TMDLC = mb->DLC;   	/* DLC field */
	ret += Reg32WRC( &rRSCFDnCFDTMPTR(n,m,b).UINT32, ptr_reg.UINT32, 0xFFFFFFFF );
	
	/* get total size to set from DLC */
	size = R_RSCFD_DLC2size( mb->DLC, mb->FDF );
	
	
	/* set transmit data
	***************************************************************************/
	for( d = 0; d < size/4; d++ ){
		/* convert 1 byte to 4 byte */
		value = (mb->DB[d*4+0] << 8*0) |
		        (mb->DB[d*4+1] << 8*1) |
		        (mb->DB[d*4+2] << 8*2) |
		        (mb->DB[d*4+3] << 8*3);
		
		/* set to register */
		ret += Reg32WRC( &rRSCFDnCFDTMDFd(n,m,b,d).UINT32, value, 0xFFFFFFFF );
	}	
	
	
	return( ret );
}
	
#if 0
/* How to use the function R_RSCFD_SetMessageBuffer_TM */
	uint8_t n = 0;	/* unit number of RSCFD */
	uint8_t m = 0;	/* channel number of RSCFDn */
	uint8_t p = 0;	/* number of TX buffer */
	RSCFD_s_MB mb;	/* fields value of transmit message */
	uint8_t	msg[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07 };
	

	/* prepare ESI, BRS, FDF, IFL, PTR field */
	mb.ESI = RSCFD_e_ESI_active_node;    	/* ESI field */
	mb.BRS = RSCFD_e_BRS_no_bitrate;     	/* BRS field */
	mb.FDF = RSCFD_e_FDF_CANFD_frame;   	/* FDF field */
	mb.IFL = 0x3;                        	/* IFL field */
	mb.PTR = 0;                          	/* PTR field */
	
	/* prepare ID, history data, frame kind, kind of ID */
	mb.ID    = 0x5A;                  	/* ID */
	mb.THLEN = RSCFD_e_THLEN_disable; 	/* Transmit history data is not stored in the buffer */
	mb.RTR   = RSCFD_e_RTR_data_frame;	/* Data Frame */
	mb.IDE   = RSCFD_e_IDE_STD_ID;    	/* Standard ID */
	
	/* prepare DLC, timestamp */
	mb.DLC   = 0x8;                   	/* DLC */        	
	
	/* prepare transmit data */
	mb.DB    = data;		
	
	/* set TX Buffer */
	R_RSCFD_SetMessageBuffer_TM( n, m, p, mb );
#endif


/*******************************************************************************
* Description  : Get reception message to TX/RX FIFO
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                uint8_t k: number of TX/RX FIFO buffer
*                RSCFD_s_MB mb: message buffer
* Return Value : RET_OK:        Register Readback check was successful
*                RET_ERR_PARAM: Parameter is out of range
*                Others:        Register Readback check was failed
*******************************************************************************/
void R_RSCFD_GetMessageBuffer_CF( uint8_t n, uint8_t m, uint8_t k, RSCFD_s_MB *mb ){

	RSCFD_s_RSCFDnCFDCFID    	id_reg;
	RSCFD_s_RSCFDnCFDCFPTR   	ptr_reg;
	RSCFD_s_RSCFDnCFDCFFDCSTS	sts_reg;
	uint32_t	db;
	uint32_t	*data;
	uint8_t 	b = k;
	uint8_t 	p, p_end;
	
	
	/* RSCFDnCFDCFID register 
	***************************************************************************/
	/* read register */
	id_reg.UINT32  = Reg32Read( rRSCFDnCFDCFID(n,m,b).UINT32 );
	
	/* set to mb */
	mb->ID    = id_reg.BIT.CFID;
	mb->THLEN = id_reg.BIT.THLEN;
	mb->RTR   = id_reg.BIT.CFRTR;
	mb->IDE   = id_reg.BIT.CFIDE;
	
	
	/* RSCFDnCFDCFPTR register
	***************************************************************************/
	/* read register */
	ptr_reg.UINT32 = Reg32Read( rRSCFDnCFDCFPTR(n,m,b).UINT32 );
	
	/* set to mb */
	mb->TS  = ptr_reg.BIT.CFTS;
	mb->DLC = ptr_reg.BIT.CFDLC;
	
	
	/* read RSCFDnCFDCFFDCSTS register
	***************************************************************************/
	/* read register */
	sts_reg.UINT32 = Reg32Read( rRSCFDnCFDCFFDCSTS(n,m,b).UINT32 );
	
	/* set to mb */
	mb->ESI    = sts_reg.BIT.CFESI;
	mb->BRS    = sts_reg.BIT.CFBRS;
	mb->FDF    = sts_reg.BIT.CFFDF;
	mb->IFL    = sts_reg.BIT.CFIFL;
	mb->PTR    = sts_reg.BIT.CFPTR;
	
	
	/* read rRSCFDnCFDCFDF register
	***************************************************************************/
	/* get payload size */
	p_end = R_RSCFD_PLS_to_Byte( rRSCFDnCFDCFCCk(n,k).BIT.CFPLS );
	
	/* set to mb */
	for( p = 0; p < p_end; p++ ){
		/* read register */
		db = Reg32Read( rRSCFDnCFDCFDFd(n,m,b,p).UINT32 );
		
		/* set to mb */
		data = (uint32_t *)&mb->DB[p*4];
		*data = db;
	}
	
}


/*******************************************************************************
* Description  : Get reception frame to RX FIFO
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                uint8_t x: number of RX FIFO buffer
*                RSCFD_s_MB mb: message buffer
* Return Value : RET_OK:        Register Readback check was successful
*                RET_ERR_PARAM: Parameter is out of range
*                Others:        Register Readback check was failed
*******************************************************************************/
void R_RSCFD_GetMessageBuffer_RF( uint8_t n, uint8_t m, uint8_t x, RSCFD_s_MB *mb ){

	RSCFD_s_RSCFDnCFDRFID    	id_reg;
	RSCFD_s_RSCFDnCFDRFPTR   	ptr_reg;
	RSCFD_s_RSCFDnCFDRFFDSTS	sts_reg;
	uint32_t	db;   	/* read data from Data Field d Register */
	uint8_t 	b = x;
	uint8_t 	size;	/* payload size [byte] */
	uint8_t 	d, d_end;
	uint8_t 	i, i_end;
	
	
	/* RSCFDnCFDCFID register 
	***************************************************************************/
	/* read register */
	id_reg.UINT32  = Reg32Read( rRSCFDnCFDRFID(n,b).UINT32 );
	
	/* set to mb */
	mb->ID    = id_reg.BIT.RFID;
	mb->RTR   = id_reg.BIT.RFRTR;
	mb->IDE   = id_reg.BIT.RFIDE;
	
	/* RSCFDnCFDCFPTR register
	***************************************************************************/
	/* read register */
	ptr_reg.UINT32 = Reg32Read( rRSCFDnCFDRFPTR(n,b).UINT32 );
	
	/* set to mb */
	mb->TS  = ptr_reg.BIT.RFTS;
	mb->DLC = ptr_reg.BIT.RFDLC;
	
	/* read RSCFDnCFDCFFDCSTS register
	***************************************************************************/
	/* read register */
	sts_reg.UINT32 = Reg32Read( rRSCFDnCFDRFFDSTS(n,b).UINT32 );
	
	/* set to mb */
	mb->ESI    = sts_reg.BIT.RFESI;
	mb->BRS    = sts_reg.BIT.RFBRS;
	mb->FDF    = sts_reg.BIT.RFFDF;
	mb->IFL    = sts_reg.BIT.RFIFL;
	mb->PTR    = sts_reg.BIT.CFDRFPTR;
	
	/* read rRSCFDnCFDCFDF register
	***************************************************************************/
	/* get payload size [byte] */
	size = R_RSCFD_PLS_to_Byte( rRSCFDnCFDRFCCx(n,x).BIT.RFPLS );
	
	/* Makes the last index of the Data Field Register where the received data is stored */
	d_end = size/4;
	
	/* set to mb */
	for( d = 0; d < d_end; d++ ){
		/* read register by 32-bit unit */
		db = Reg32Read( rRSCFDnCFDRFDFd(n,b,d).UINT32 );
		
		
		if( (d != (d_end - 1)) || ((size % 4)==0) ){
			i_end = 4;	/* all byte of CFDRFDFp write to mb.DB */
		}else{
			i_end = (size % 4);	/* left byte of CFDRFDFp write to mb.DB */
		}
			
		for( i = 0; i < i_end; i++ ){
			/* store 1byte data to mb.DB */
			mb->DB[i+4*d] = (db >> (8 * i)) & 0xFF;
		}
	}
	
}


/*******************************************************************************
* Description  : Get reception frame to RX buffer
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                uint8_t p: number of RX buffer
*                RSCFD_s_MB mb: message buffer
* Return Value : RET_OK:        Register Readback check was successful
*                RET_ERR_PARAM: Parameter is out of range
*                Others:        Register Readback check was failed
*******************************************************************************/
void R_RSCFD_GetMessageBuffer_RM( uint8_t n, uint8_t m, uint8_t x, RSCFD_s_MB *mb ){

	RSCFD_s_RSCFDnCFDRMID    	id_reg;
	RSCFD_s_RSCFDnCFDRMPTR   	ptr_reg;
	RSCFD_s_RSCFDnCFDRMFDSTS	sts_reg;
	uint32_t	db;   	/* read data from Data Field d Register */
	uint8_t 	f = x % RSCFD_RM_PER_CH_NUM;
	uint8_t 	size;	/* payload size [byte] */
	uint8_t 	d, d_end;
	uint8_t 	i, i_end;
	
	
	/* RSCFDnCFDCFID register 
	***************************************************************************/
	/* read register */
	id_reg.UINT32  = Reg32Read( rRSCFDnCFDRMID(n,m,f).UINT32 );
	
	/* set to mb */
	mb->ID    = id_reg.BIT.RMID;
	mb->RTR   = id_reg.BIT.RMRTR;
	mb->IDE   = id_reg.BIT.RMIDE;
	
	/* RSCFDnCFDCFPTR register
	***************************************************************************/
	/* read register */
	ptr_reg.UINT32 = Reg32Read( rRSCFDnCFDRMPTR(n,m,f).UINT32 );
	
	/* set to mb */
	mb->TS  = ptr_reg.BIT.RMTS;
	mb->DLC = ptr_reg.BIT.RMDLC;
	
	/* read RSCFDnCFDCFFDCSTS register
	***************************************************************************/
	/* read register */
	sts_reg.UINT32 = Reg32Read( rRSCFDnCFDRMFDSTS(n,m,f).UINT32 );
	
	/* set to mb */
	mb->ESI    = sts_reg.BIT.RMESI;
	mb->BRS    = sts_reg.BIT.RMBRS;
	mb->FDF    = sts_reg.BIT.RMFDF;
	mb->IFL    = sts_reg.BIT.RMIFL;
	mb->PTR    = sts_reg.BIT.RMPTR;
	
	/* read rRSCFDnCFDCFDF register
	***************************************************************************/
	/* get payload size [byte] */
	size = R_RSCFD_PLS_to_Byte( rRSCFDnCFDRMNB(n).BIT.RMPLS );
	
	/* Makes the last index of the Data Field Register where the received data is stored */
	d_end = size/4;
	
	/* set to mb */
	for( d = 0; d < d_end; d++ ){
		/* read register by 32-bit unit */
		db = Reg32Read( rRSCFDnCFDRMDFd(n,m,f,d).UINT32 );
		
		
		if( (d != (d_end - 1)) || ((size % 4)==0) ){
			i_end = 4;	/* all byte of CFDRFDFp write to mb.DB */
		}else{
			i_end = (size % 4);	/* left byte of CFDRMDFp write to mb.DB */
		}
			
		for( i = 0; i < i_end; i++ ){
			/* store 1byte data to mb.DB */
			mb->DB[i+4*d] = (db >> (8 * i)) & 0xFF;
		}
	}
	
}


/*******************************************************************************
* Description  : Enter specified test mode
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                RSCFD_e_CTMS ctms: channel test mode
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_EnterTestMode( uint8_t n, uint8_t m, RSCFD_e_CTMS ctms ){
	
	RSCFD_s_RSCFDnCFDCmCTR	ctr_reg;
	uint8_t 	ret;
	
	
	/* change to global test mode */
	R_RSCFD_ChangeGloabalMode( n, RSCFD_e_GMDC_test_mode );
	
					     
	/* change to channel Halt Mode */
	R_RSCFD_ChangeChannelMode( n, m, RSCFD_e_CHMDC_halt_mode );
			

	/* select and enable test mode */
	ctr_reg.UINT32 = Reg32Read( rRSCFDnCFDCmCTR(n,m).UINT32 );
	ctr_reg.BIT.CTME = RSCFD_e_CTME_enable;	/* Channel Test Mode enabled */
	ctr_reg.BIT.CTMS = ctms;	/* Channel Test Mode Select */

	ret = Reg32WRC( &rRSCFDnCFDCmCTR(n,m).UINT32, ctr_reg.UINT32, 0xFFFFFFFF );
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Enter RAM test mode
* Arguments    : uint8_t n: unit number of RSCFD
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_EnterRAMtestMode( uint8_t n ){
	
	uint8_t	ret;
	
	
	/* transit global test mode */
	R_RSCFD_ChangeGloabalMode( n, RSCFD_e_GMDC_test_mode );
	
	/* RAM Test Mode Enable */
	ret = R_RSCFD_UnlockTestMode( n );
	
	return( ret );
}


/*******************************************************************************
* Description  : Unlcok RAM test mode
* Arguments    : uint8_t n: unit number of RSCFD
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_UnlockTestMode( uint8_t n ){
	
	uint8_t	ret;
	
	
	/* 1st key code */
	rRSCFDnCFDGLOCKK(n).UINT32 = 0x7575;
	
	/* 2nd key code */
	rRSCFDnCFDGLOCKK(n).UINT32 = 0x8A8A;
	
	/* RAM Test Mode Enable */
	ret = Reg32SetBitCheck( &rRSCFDnCFDGTSTCTR(n).UINT32, 2 );  	/* RTME=1 */
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : convert PLS value to byte
* Arguments    : RSCFD_e_PLS pls: PLS bit value
* Return Value : 0     : unexpected error occured
*                Others: byte number corresponding pls
*******************************************************************************/
uint8_t	R_RSCFD_PLS_to_Byte( RSCFD_e_PLS pls ){
	
	uint8_t 	byte;
	
	
	switch( pls ){
		case RSCFD_e_PLS_8_bytes : byte = 8;  break;
		case RSCFD_e_PLS_12_bytes: byte = 12; break;
		case RSCFD_e_PLS_16_bytes: byte = 16; break;
		case RSCFD_e_PLS_20_bytes: byte = 20; break;
		case RSCFD_e_PLS_24_bytes: byte = 24; break;
		case RSCFD_e_PLS_32_bytes: byte = 32; break;
		case RSCFD_e_PLS_48_bytes: byte = 48; break;
		case RSCFD_e_PLS_64_bytes: byte = 64; break;
		default:                  byte = 0;  break;
	}
	
	return( byte );
}

	
