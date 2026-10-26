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
* File Name    : main.c
* Version      : 1.00 (modified: [DJ] RLIN33 UART echo test, 2026.10)
* Device(s)    : R-Car/U5L
* Description  : This is source file for main function.
*******************************************************************************/


/*******************************************************************************
* Includes
*******************************************************************************/
/* Test function */
#include "App_main.h"
#include "sub_pe0.h"
#include "R_driver_RLIN3.h"	/* [DJ] RLIN3 UART polling API */


/*******************************************************************************
* [DJ] RLIN3 UART test configuration
*******************************************************************************/
/* 1: run RLIN3 UART echo test after the ETNF(10BASE-T1S) test, 0: disable */
#define	APP_RLIN3_UART_TEST	1

/* RLIN3 unit for the test = COM port unit opened by App_OpenCOMport() (config.h)
   CFG_COM_UNIT = 3 / CFG_COM_PIN = 1 -> RLIN33
   TX: P09_0 (ALT_OUT2), RX: P09_1 (ALT_IN2), U5L4 QFP100 pin 69 / 70           */
#define	APP_UART_CH        	((uint8_t)CFG_COM_UNIT)

/* ESC key ends the echo test */
#define	APP_UART_KEY_EXIT  	0x1BU


/*******************************************************************************
* Prototype declarations
*******************************************************************************/
#if APP_RLIN3_UART_TEST
static void App_RLIN3_UART_EchoTest( void );
#endif


/*******************************************************************************
* Description  : main function of PE0
* Arguments    : None
* Return Value : None
*******************************************************************************/
void main( void ){

	uint8_t 	ret;


	/* Open monitor port */
	R_PORT_ChangeIOmode_P( CFG_M_Pn ,0 );	/* all bit change to output mode */

	/* start Main OCS */
	R_CLK_EnableMOSC();


	/* Gearup system clocks */
	R_CLK_GearUpCLK_SYS( CLK_e_CLK_SYS0 );
	R_CLK_GearUpCLK_SYS( CLK_e_CLK_SYS1 );

    /* COM port communication setting */
    App_OpenCOMport();

    /* Output start message */
	R_COM_printf( "Communication start\n" );

	/* product-dependent setting for ETNF */
	App_ConfigETNF_product();

	/* main function for test */
	App_main();

    /* Output start message */
	R_COM_printf( "Test end.\n" );

#if APP_RLIN3_UART_TEST
	/* [DJ] RLIN33 UART TX/RX test (Tera Term echo) */
	App_RLIN3_UART_EchoTest();
#endif

	/* [DJ] do not return from main */
	while( 1 ){
		;
	}
}


#if APP_RLIN3_UART_TEST
/*******************************************************************************
* Description  : [DJ] RLIN33 UART echo test
*                - transmits a banner (TX check)
*                - echoes every received character back (RX + TX check)
*                - ESC key: print the result and exit
* Arguments    : None
* Return Value : None
*******************************************************************************/
static void App_RLIN3_UART_EchoTest( void ){

	uint8_t 	rx_data;
	uint32_t	rx_count  = 0U;
	uint32_t	err_count = 0U;


	/* make sure TX and RX are enabled (UTOE = 1, UROE = 1) */
	(void)R_RLIN3u_EnableTXRX( APP_UART_CH );

	R_RLIN3u_SendString( APP_UART_CH, "\n[RLIN33 UART test] P09_0(TX) / P09_1(RX)\n" );
	R_RLIN3u_SendString( APP_UART_CH, "Type any key -> echo back, ESC -> exit\n> " );

	while( 1 ){
		if( R_RLIN3u_ReceiveByte( APP_UART_CH, &rx_data, RLIN3u_WAIT_FOREVER ) != RET_OK ){
			err_count++;	/* framing / overrun / bit error */
			continue;
		}

		if( rx_data == APP_UART_KEY_EXIT ){
			break;
		}

		rx_count++;

		/* echo back */
		R_RLIN3u_SendByte( APP_UART_CH, rx_data );
		if( rx_data == (uint8_t)'\r' ){
			R_RLIN3u_SendString( APP_UART_CH, "\n> " );
		}
	}

	R_COM_printf( "\nRLIN33 UART test end. RX=%d, ERR=%d -> %s\n",
	              (int)rx_count, (int)err_count, (err_count == 0U) ? "PASS" : "FAIL" );
}
#endif
