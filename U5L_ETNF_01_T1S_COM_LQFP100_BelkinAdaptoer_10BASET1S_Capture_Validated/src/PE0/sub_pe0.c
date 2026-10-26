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
* File Name    : sub_pe0.c
* Version      : 1.00 (modified: [DJ] RX pin setting for RLIN3 echo test, 2026.10)
* Description  : This source file describes sub routine for the application
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "sub_pe0.h"
#include "R_driver_RLIN3.h"	/* [DJ] for R_RLIN3u_EnableTXRX() macro (UTOE/UROE) */

/*******************************************************************************
* Function body
*******************************************************************************/

/*******************************************************************************
* Description  : start COM port communication
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void App_OpenCOMport( void ){

	R_COM_s_setting	setting;	/* COM port setting */


	/* RLIN clock */
	R_CLK_ChangeClock_RLIN3( CFG_COM_CLK_RLIN3 );

	/* Release module standby of RLIN3n */
	R_STB_ReleaseModuleStandby( &rMSR_RLIN3.UINT32 );

	/* TX pin setting (RLIN33: P09_0 = RLIN33TX) */
	R_RLIN3_OpenRLIN3nTX( CFG_COM_UNIT, CFG_COM_PIN );

	/* [DJ] RX pin setting (RLIN33: P09_1 = RLIN33RX, ALT_IN2)
	   The original sample uses the COM port only for log output (TX only),
	   so the RX pin was not configured. RX is required for the UART echo test.
	   R_RLIN3_OpenRLIN3nRX( 3, 1 ) -> R_PORT_SetAlt_Pnm( 9, 1, 2, PORT_e_IO_IN )
	   (requires R_device_RLIN3.c [DJ] version: RLIN33 bit 3-2 = 00 case)      */
	R_RLIN3_OpenRLIN3nRX( CFG_COM_UNIT, CFG_COM_PIN );

	/* set configuration value for UART communication */
	setting.n         = CFG_COM_UNIT;
	setting.base_addr = CFG_COM_base_addr;
	setting.baudrate  = CFG_COM_baudrate;
	setting.clk_freq  = CFG_COM_clk_freq;

	/* Initial setting of RLIN3 to use COM port */
	R_COM_Initialize( setting );

	/* [DJ] enable reception as well as transmission (UTOE = 1, UROE = 1) */
	(void)R_RLIN3u_EnableTXRX( CFG_COM_UNIT );

}


/*******************************************************************************
* Description  : ETNF product-dependent settings
* Arguments    : None
* Return Value : None
*******************************************************************************/
void App_ConfigETNF_product( void ){

	uint8_t 	pin = APP_PIN;
	uint8_t 	ret = RET_OK;

	/* Setting for target unit
	***************************************************************************/
	/* Release module standby */
	R_COM_printf( "Release module standby ... " );
	R_STB_ReleaseModuleStandby_ETNF();
	R_COM_printf( "Done\n" );

	
	/* Pin setting for RMII I/F 
	***************************************************************************/
#if APP_COM_IF == APP_ETNF_RMII
	R_ETNF_OpenETS0_RMII_TXEN( pin, PORT_e_st_high );
	R_ETNF_OpenETS0_RMII_TXD( pin, PORT_e_st_high );	/* ETS0_RMII_TXD0 and ETS0_RMII_TXD1 */
	R_ETNF_OpenETS0_RMII_RXD( APP_PIN );	/* ETS0_RMII_RXD0 and ETS0_RMII_RXD1 */

	R_ETNF_OpenETS0_RMII_CRSDV( pin );	/* ETS0_RMII_CRSDV */
	R_ETNF_OpenETS0_RMII_REFCLK( pin );	/* ETS0_RMII_REFCLK */
	
	R_ETNF_OpenETS0_MDC( pin, PORT_e_st_high );	/* ETS0_MDC */
	R_ETNF_OpenETS0_MDIO( pin );               	/* ETS0_MDIO */
#endif
	
	/* Pin setting for T1S I/F
	***************************************************************************/
#if APP_COM_IF == APP_ETNF_T1S
	R_ETNF_OpenETS0_RX_MDC( pin );            	/* ETS0_RX_MDC */
	R_ETNF_OpenETS0_TX( pin, PORT_e_st_high );	/* ETS0_TX */
	R_ETNF_OpenETS0_ED_MDIO( pin );            	/* ETS0_ED_MDIO */

#endif


	/* Interrupt setting for ETNF
	***************************************************************************/
	R_INTC_ConfigInterrupt( INTC_e_index_INTETNF0DATA, enable, 0 );
			      

}

