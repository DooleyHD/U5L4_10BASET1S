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
* File Name    : R_device_RLIN3.c
* Version      : 1.00
* Module(s)    : RLIN3
* Device(s)    : RH850/U2B product
* Description  : This file contains product-specific descriptions of the RLIN3 
*                drivers.
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_device_ETNF.h"


/*******************************************************************************
* Section specification for entire file
*******************************************************************************/
#pragma	section	default


/*******************************************************************************
* Definitions
*******************************************************************************/


/*******************************************************************************
* Global variables
*******************************************************************************/


/*******************************************************************************
* Function body
*******************************************************************************/

/*******************************************************************************
* Description  : open ETS0_ED_MDIO pin.
* Arguments    : uint8_t pin: serial number of same function pin
* Return Value : (none)
*******************************************************************************/
void R_ETNF_OpenETS0_ED_MDIO( uint8_t pin ){

	 R_PORT_SetAlt_Pnm( 10, 1, 11, PORT_e_IO_INOUT );	/* P10_1 ETS0_ED_MDIO */

		/* Change port drive strength */
		R_PORT_ChangeStrength_Pnm( 10, 1, PORT_e_st_high );
}


/*******************************************************************************
* Description  : open ETS0_MDC pin.
* Arguments    : uint8_t pin: serial number of same function pin
*                PORT_e_st strength: drive strength
* Return Value : (none)
*******************************************************************************/
void R_ETNF_OpenETS0_MDC( uint8_t pin, PORT_e_st strength ){
	
	uint8_t 	p_n, p_m, alt;
	

	p_n=10; p_m=12; alt=11;	/* ETS0_MDC */
	
	/* Change port alternative function */
	R_PORT_SetAlt_Pnm( p_n, p_m, alt, PORT_e_IO_OUT );

	/* Change port drive strength */
	R_PORT_ChangeStrength_Pnm( p_n, p_m, strength );
}


/*******************************************************************************
* Description  : open ETS0_MDIO pin.
* Arguments    : uint8_t pin: serial number of same function pin
* Return Value : (none)
*******************************************************************************/
void R_ETNF_OpenETS0_MDIO( uint8_t pin ){
	
	R_PORT_SetAlt_Pnm( 10, 13, 11, PORT_e_IO_INOUT );	/* P10_13 ETS0_MDIO */
	
}


/*******************************************************************************
* Description  : open ETS0_RX_MDC pin.
* Arguments    : uint8_t pin: serial number of same function pin
* Return Value : (none)
*******************************************************************************/
void R_ETNF_OpenETS0_RX_MDC( uint8_t pin ){
	
	R_PORT_SetAlt_Pnm( 10, 0, 11, PORT_e_IO_INOUT );	/* P10_0 ETS0_RX_MDC */

	/* Change port drive strength */
	R_PORT_ChangeStrength_Pnm( 10, 0, PORT_e_st_high );

}


/*******************************************************************************
* Description  : open ETS0_TX pin.
* Arguments    : uint8_t pin: serial number of same function pin
*                PORT_e_st strength: drive strength
* Return Value : (none)
*******************************************************************************/
void R_ETNF_OpenETS0_TX( uint8_t pin, PORT_e_st strength ){
	
	uint8_t 	p_n, p_m, alt;
	
	
	p_n=10, p_m=2, alt=11;	/* P10_2 ETS0_TX */
	
	/* Change port alternative function */
	R_PORT_SetAlt_Pnm( p_n, p_m, alt, PORT_e_IO_OUT );

	/* Change port drive strength */
	R_PORT_ChangeStrength_Pnm( p_n, p_m, strength );
}
	

/*******************************************************************************
* Return to default section
*******************************************************************************/
#pragma	section	default
