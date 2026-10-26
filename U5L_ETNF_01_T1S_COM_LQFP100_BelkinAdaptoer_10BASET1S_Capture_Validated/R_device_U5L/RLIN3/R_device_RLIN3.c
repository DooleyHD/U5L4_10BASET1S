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
* Version      : 1.00 (modified: [DJ] RLIN33 RX default selection (bit 3-2 = 00) added, 2026.10)
* Module(s)    : RLIN3
* Device(s)    : R-Car U5L product
* Description  : This file contains product-specific descriptions of the RLIN3 
*                drivers.
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_device_RLIN3.h"


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
* Description  : open RLIN3nTX pin.
* Arguments    : uint8_t n  : unit number of RLIN3
*                uint8_t pin: serial number of same function pin
* Return Value : (none)
*******************************************************************************/
void R_RLIN3_OpenRLIN3nTX( uint8_t n, uint8_t pin ){
	
	switch( (n << 4) | (pin & 0x3) ){	/* "pin": only check bit 1-0 to share "pin" with R_RLIN3_OpenRLIN3nRX ([DJ] comment fix: TX->RX) */
		/* RLIN30 */
		case (0 << 4) | 0:	R_PORT_SetAlt_Pnm(  0,  2,  2, PORT_e_IO_OUT );	break;	/* P00_2 RLIN30TX */
		case (0 << 4) | 1:	R_PORT_SetAlt_Pnm( 10, 10,  2, PORT_e_IO_OUT );	break;	/* P10_10 RLIN30TX */
		
		/* RLIN31 */
		case (1 << 4) | 0:	R_PORT_SetAlt_Pnm(  0,  5,  1, PORT_e_IO_OUT );	break;	/* P00_5 RLIN31TX */
		case (1 << 4) | 1:	R_PORT_SetAlt_Pnm( 10, 12,  2, PORT_e_IO_OUT );	break;	/* P10_12 RLIN31TX */
		
		/* RLIN32 */
		case (2 << 4) | 0:	R_PORT_SetAlt_Pnm(  0, 14,  1, PORT_e_IO_OUT );	break;	/* P00_14 RLIN32TX */
		case (2 << 4) | 1:	R_PORT_SetAlt_Pnm( 10, 14,  2, PORT_e_IO_OUT );	break;	/* P10_14 RLIN32TX */
		case (2 << 4) | 2:	R_PORT_SetAlt_Pnm( 11,  3,  5, PORT_e_IO_OUT );	break;	/* P11_3 RLIN32TX */
		
		/* RLIN33 */
		case (3 << 4) | 0:	R_PORT_SetAlt_Pnm(  1,  1,  1, PORT_e_IO_OUT );	break;	/* P01_1 RLIN33TX */
		case (3 << 4) | 1:	R_PORT_SetAlt_Pnm(  9,  0,  2, PORT_e_IO_OUT );	break;	/* P09_0 RLIN33TX ALT_OUT2 */
		case (3 << 4) | 2:	R_PORT_SetAlt_Pnm( 10,  2, 12, PORT_e_IO_OUT );	break;	/* P10_2 RLIN33TX */
		case (3 << 4) | 3:	R_PORT_SetAlt_Pnm( 11,  5,  1, PORT_e_IO_OUT );	break;	/* P11_5 RLIN33TX */
		
		/* RLIN34 */
		case (4 << 4) | 0:	R_PORT_SetAlt_Pnm(  1,  9,  1, PORT_e_IO_OUT );	break;	/* P01_9 RLIN34TX */
		case (4 << 4) | 1:	R_PORT_SetAlt_Pnm(  8,  9,  4, PORT_e_IO_OUT );	break;	/* P08_9 RLIN34TX */
		case (4 << 4) | 2:	R_PORT_SetAlt_Pnm( 10, 13,  9, PORT_e_IO_OUT );	break;	/* P10_13 RLIN34TX */
		case (4 << 4) | 3:	R_PORT_SetAlt_Pnm( 12,  2,  1, PORT_e_IO_OUT );	break;	/* P12_2 RLIN34TX */
		
		/* RLIN35 */
		case (5 << 4) | 0:	R_PORT_SetAlt_Pnm(  1,  5,  1, PORT_e_IO_OUT );	break;	/* P01_5 RLIN35TX */
		case (5 << 4) | 1:	R_PORT_SetAlt_Pnm( 10,  1, 12, PORT_e_IO_OUT );	break;	/* P10_1 RLIN35TX */
		case (5 << 4) | 2:	R_PORT_SetAlt_Pnm( 11,  8,  1, PORT_e_IO_OUT );	break;	/* P11_8 RLIN35TX */
		
		/* RLIN36 */
		case (6 << 4) | 0:	R_PORT_SetAlt_Pnm(  1, 12,  2, PORT_e_IO_OUT );	break;	/* P01_12 RLIN36TX */
		case (6 << 4) | 1:	R_PORT_SetAlt_Pnm(  9,  2,  8, PORT_e_IO_OUT );	break;	/* P09_2 RLIN36TX */
		case (6 << 4) | 2:	R_PORT_SetAlt_Pnm( 11, 15,  5, PORT_e_IO_OUT );	break;	/* P11_15 RLIN36TX */
		
		/* RLIN37 */
		case (7 << 4) | 0:	R_PORT_SetAlt_Pnm(  8,  2,  4, PORT_e_IO_OUT );	break;	/* P08_2 RLIN37TX */
		case (7 << 4) | 1:	R_PORT_SetAlt_Pnm( 10,  2,  7, PORT_e_IO_OUT );	break;	/* P10_2 RLIN37TX */
		
		/* RLIN38 */
		case (8 << 4) | 0:	R_PORT_SetAlt_Pnm(  9,  1,  4, PORT_e_IO_OUT );	break;	/* P09_1 RLIN38TX */
		
		/* RLIN39 */
		case (9 << 4) | 0:	R_PORT_SetAlt_Pnm(  9,  3,  5, PORT_e_IO_OUT );	break;	/* P09_3 RLIN39TX */
		
		/* RLIN310 */
		case (10 << 4) | 0:	R_PORT_SetAlt_Pnm( 10,  0,  5, PORT_e_IO_OUT );	break;	/* P10_0 RLIN310TX */
		
		/* RLIN311 */
		case (11 << 4) | 0:	R_PORT_SetAlt_Pnm( 10,  5,  2, PORT_e_IO_OUT );	break;	/* P10_5 RLIN311TX */
		
		/* RLIN312 */
		case (12 << 4) | 0:	R_PORT_SetAlt_Pnm( 10,  7,  6, PORT_e_IO_OUT );	break;	/* P10_7 RLIN312TX */
		
		/* RLIN313 */
		case (13 << 4) | 0:	R_PORT_SetAlt_Pnm( 11,  2,  2, PORT_e_IO_OUT );	break;	/* P11_2 RLIN313TX */
		
		/* RLIN314 */
		case (14 << 4) | 0:	R_PORT_SetAlt_Pnm( 11,  0,  3, PORT_e_IO_OUT );	break;	/* P11_0 RLIN314TX */
		
		/* RLIN315 */
		case (15 << 4) | 0:	R_PORT_SetAlt_Pnm( 11, 11,  1, PORT_e_IO_OUT );	break;	/* P11_11 RLIN315TX */
		
		/* RLIN316 */
		case (16 << 4) | 0:	R_PORT_SetAlt_Pnm( 13,  1,  1, PORT_e_IO_OUT );	break;	/* P13_1 RLIN316TX */
		
		/* RLIN317 */
		case (17 << 4) | 0:	R_PORT_SetAlt_Pnm( 13,  3,  1, PORT_e_IO_OUT );	break;	/* P13_3 RLIN317TX */

	    default:	        break;
	}	
	
}


/*******************************************************************************
* Description  : open RLIN3nRX pin.
* Arguments    : uint8_t n  : unit number of RLIN3
*                uint8_t pin: bit 3-2=00: w/o IRQ, w/o CXP1nRX
*                             bit 3-2=01: w/o IRQ, w   CXP1nRX
*                             bit 3-2=10: w   IRQ, w/o CXP1nRX
*                             bit 3-2=11: w   IRQ, w   CXP1nRX
*                             bit 1-0: serial number of same function pin
*                [DJ] RLIN33: bit 3-2=00 is handled the same as 01 (RLIN33RX, ALT_IN2 for P09_1),
*                     so the same "pin" value can be used for OpenRLIN3nTX and OpenRLIN3nRX.
* Return Value : (none)
*******************************************************************************/
void R_RLIN3_OpenRLIN3nRX( uint8_t n, uint8_t pin ){

	switch( (n << 4) | pin ){
		/* RLIN30 */
		case ( 0 << 4) | (1 << 2) | 0:	R_PORT_SetAlt_Pnm(  0,  3, 7, PORT_e_IO_IN );	break;	/* P00_3 RLIN30RX/CXP10RX */
		case ( 0 << 4) | (1 << 2) | 1:	R_PORT_SetAlt_Pnm( 10,  9, 7, PORT_e_IO_IN );	break;	/* P10_9 RLIN30RX/CXP10RX */
		case ( 0 << 4) | (0 << 2) | 0:	/* for pin = 0 */
		case ( 0 << 4) | (3 << 2) | 0:	R_PORT_SetAlt_Pnm(  0,  3, 2, PORT_e_IO_IN );	break;	/* P00_3 RLIN30RX/IRQ8/CXP10RX */
		case ( 0 << 4) | (0 << 2) | 1:	/* for pin = 1 */
		case ( 0 << 4) | (3 << 2) | 1:	R_PORT_SetAlt_Pnm( 10,  9, 2, PORT_e_IO_IN );	break;	/* P10_9 RLIN30RX/IRQ8/CXP10RX */
		
		/* RLIN31 */
		case ( 1 << 4) | (1 << 2) | 0:	R_PORT_SetAlt_Pnm(  0,  4, 7, PORT_e_IO_IN );	break;	/* P00_4  RLIN31RX/CXP11RX */
		case ( 1 << 4) | (1 << 2) | 1:	R_PORT_SetAlt_Pnm( 10, 11, 7, PORT_e_IO_IN );	break;	/* P10_11 RLIN31RX/CXP11RX */
		case ( 1 << 4) | (0 << 2) | 0:	/* for pin = 0 */
		case ( 1 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm(  0,  4, 1, PORT_e_IO_IN );	break;	/* P00_4  RLIN31RX/IRQ9/CXP11RX */
		case ( 1 << 4) | (0 << 2) | 1:	/* for pin = 1 */
		case ( 1 << 4) | (2 << 2) | 1:	R_PORT_SetAlt_Pnm( 10, 11, 2, PORT_e_IO_IN );	break;	/* P10_11 RLIN31RX/IRQ9/CXP11RX */
		
		/* RLIN32 */
		case ( 2 << 4) | (1 << 2) | 0:	R_PORT_SetAlt_Pnm(  0, 13, 6, PORT_e_IO_IN );	break;	/* P00_13 RLIN32RX/CXP12RX */
		case ( 2 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm(  0, 13, 1, PORT_e_IO_IN );	break;	/* P00_13 RLIN32RX/IRQ10 */
		case ( 2 << 4) | (3 << 2) | 0:	R_PORT_SetAlt_Pnm(  0, 13, 1, PORT_e_IO_IN );	break;	/* P00_13 RLIN32RX/IRQ10/CXP12RX */
		case ( 2 << 4) | (0 << 2) | 0:	R_PORT_SetAlt_Pnm( 10, 13, 7, PORT_e_IO_IN );	break;	/* P10_13 RLIN32RX */
		case ( 2 << 4) | (1 << 2) | 1:	R_PORT_SetAlt_Pnm( 10, 13, 7, PORT_e_IO_IN );	break;	/* P10_13 RLIN32RX/CXP12RX */
		case ( 2 << 4) | (2 << 2) | 1:	R_PORT_SetAlt_Pnm( 10, 13, 2, PORT_e_IO_IN );	break;	/* P10_13 RLIN32RX/IRQ10 */
		case ( 2 << 4) | (3 << 2) | 1:	R_PORT_SetAlt_Pnm( 10, 13, 2, PORT_e_IO_IN );	break;	/* P10_13 RLIN32RX/IRQ10/CXP12RX */
		case ( 2 << 4) | (1 << 2) | 2:	R_PORT_SetAlt_Pnm( 11,  2, 7, PORT_e_IO_IN );	break;	/* P11_2  RLIN32RX/CXP12RX */
		case ( 2 << 4) | (2 << 2) | 2:	R_PORT_SetAlt_Pnm( 11,  2, 2, PORT_e_IO_IN );	break;	/* P11_2  RLIN32RX/IRQ10 */
		case ( 2 << 4) | (3 << 2) | 2:	R_PORT_SetAlt_Pnm( 11,  2, 2, PORT_e_IO_IN );	break;	/* P11_2  RLIN32RX/IRQ10/CXP12RX */
		
		/* RLIN33 */
		/* [DJ] bit 3-2 = 00 (pin = 0..3) was not defined for RLIN33 -> no pin setting.
		        Added as fall-through to bit 3-2 = 01 (w/o IRQ), same as RLIN30/31 style.
		        ex) R_RLIN3_OpenRLIN3nRX( 3, 1 ) -> P09_1 ALT_IN2 (RLIN33RX)            */
		case ( 3 << 4) | (0 << 2) | 0:	/* [DJ] for pin = 0 */
		case ( 3 << 4) | (1 << 2) | 0:	R_PORT_SetAlt_Pnm(  1,  0, 7, PORT_e_IO_IN );	break;	/* P01_0 RLIN33RX/CXP13RX */
		case ( 3 << 4) | (0 << 2) | 1:	/* [DJ] for pin = 1 */
		case ( 3 << 4) | (1 << 2) | 1:	R_PORT_SetAlt_Pnm(  9,  1, 2, PORT_e_IO_IN );	break;	/* P09_1 RLIN33RX/CXP13RX (QFP: RLIN33RX) ALT_IN2 */
		case ( 3 << 4) | (0 << 2) | 2:	/* [DJ] for pin = 2 */
		case ( 3 << 4) | (1 << 2) | 2:	R_PORT_SetAlt_Pnm( 10,  1, 7, PORT_e_IO_IN );	break;	/* P10_1 RLIN33RX/CXP13RX */
		case ( 3 << 4) | (0 << 2) | 3:	/* [DJ] for pin = 3 */
		case ( 3 << 4) | (1 << 2) | 3:	R_PORT_SetAlt_Pnm( 11,  6, 7, PORT_e_IO_IN );	break;	/* P11_6 RLIN33RX/CXP13RX */
		case ( 3 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm(  1,  0, 1, PORT_e_IO_IN );	break;	/* P01_0 RLIN33RX/IRQ11 */
		case ( 3 << 4) | (2 << 2) | 1:	R_PORT_SetAlt_Pnm(  9,  1, 5, PORT_e_IO_IN );	break;	/* P09_1 RLIN33RX/IRQ11 */
		case ( 3 << 4) | (2 << 2) | 2:	R_PORT_SetAlt_Pnm( 10,  1, 6, PORT_e_IO_IN );	break;	/* P10_1 RLIN33RX/IRQ11 */
		case ( 3 << 4) | (2 << 2) | 3:	R_PORT_SetAlt_Pnm( 11,  6, 1, PORT_e_IO_IN );	break;	/* P11_6 RLIN33RX/IRQ11 */
		case ( 3 << 4) | (3 << 2) | 0:	R_PORT_SetAlt_Pnm(  1,  0, 1, PORT_e_IO_IN );	break;	/* P01_0 RLIN33RX/IRQ11/CXP13RX */
		case ( 3 << 4) | (3 << 2) | 1:	R_PORT_SetAlt_Pnm(  9,  1, 5, PORT_e_IO_IN );	break;	/* P09_1 RLIN33RX/IRQ11/CXP13RX */
		case ( 3 << 4) | (3 << 2) | 2:	R_PORT_SetAlt_Pnm( 10,  1, 6, PORT_e_IO_IN );	break;	/* P10_1 RLIN33RX/IRQ11/CXP13RX */
		case ( 3 << 4) | (3 << 2) | 3:	R_PORT_SetAlt_Pnm( 11,  6, 1, PORT_e_IO_IN );	break;	/* P11_6 RLIN33RX/IRQ11/CXP13RX */
		
		/* RLIN34 */
		case ( 4 << 4) | (0 << 2) | 1:	R_PORT_SetAlt_Pnm(  8,  8, 7, PORT_e_IO_IN );	break;	/* P08_8  RLIN34RX */
		case ( 4 << 4) | (0 << 2) | 2:	R_PORT_SetAlt_Pnm( 10, 14, 6, PORT_e_IO_IN );	break;	/* P10_14 RLIN34RX */
		case ( 4 << 4) | (0 << 2) | 3:	R_PORT_SetAlt_Pnm( 12,  1, 7, PORT_e_IO_IN );	break;	/* P12_1  RLIN34RX */
		case ( 4 << 4) | (0 << 2) | 0:	
		case ( 4 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm(  1,  8, 1, PORT_e_IO_IN );	break;	/* P01_8  RLIN34RX/IRQ12 */
		case ( 4 << 4) | (2 << 2) | 1:	R_PORT_SetAlt_Pnm(  8,  8, 4, PORT_e_IO_IN );	break;	/* P08_8  RLIN34RX/IRQ12 */
		case ( 4 << 4) | (2 << 2) | 2:	R_PORT_SetAlt_Pnm( 10, 14, 4, PORT_e_IO_IN );	break;	/* P10_14 RLIN34RX/IRQ12 */
		case ( 4 << 4) | (2 << 2) | 3:	R_PORT_SetAlt_Pnm( 12,  1, 1, PORT_e_IO_IN );	break;	/* P12_1  RLIN34RX/IRQ12 */
		
		/* RLIN35 */
		case ( 5 << 4) | (0 << 2) | 0:	R_PORT_SetAlt_Pnm(  1,  4, 7, PORT_e_IO_IN );	break;	/* P01_4 RLIN35RX */
		case ( 5 << 4) | (0 << 2) | 1:	R_PORT_SetAlt_Pnm( 10,  2, 7, PORT_e_IO_IN );	break;	/* P10_2 RLIN35RX */
		case ( 5 << 4) | (0 << 2) | 2:	R_PORT_SetAlt_Pnm( 11,  9, 7, PORT_e_IO_IN );	break;	/* P11_9 RLIN35RX */
		case ( 5 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm(  1,  4, 1, PORT_e_IO_IN );	break;	/* P01_4 RLIN35RX/IRQ13 */
		case ( 5 << 4) | (2 << 2) | 1:	R_PORT_SetAlt_Pnm( 10,  2, 6, PORT_e_IO_IN );	break;	/* P10_2 RLIN35RX/IRQ13 */
		case ( 5 << 4) | (2 << 2) | 2:	R_PORT_SetAlt_Pnm( 11,  9, 2, PORT_e_IO_IN );	break;	/* P11_9 RLIN35RX/IRQ13 */
		
		/* RLIN36 */
		case ( 6 << 4) | (0 << 2) | 0:	R_PORT_SetAlt_Pnm(  1, 13, 7, PORT_e_IO_IN );	break;	/* P01_13 RLIN36RX */
		case ( 6 << 4) | (0 << 2) | 1:	R_PORT_SetAlt_Pnm(  9,  3, 3, PORT_e_IO_IN );	break;	/* P09_3  RLIN36RX */
		case ( 6 << 4) | (0 << 2) | 2:	R_PORT_SetAlt_Pnm( 12,  0, 7, PORT_e_IO_IN );	break;	/* P12_0  RLIN36RX */
		case ( 6 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm(  1, 13, 2, PORT_e_IO_IN );	break;	/* P01_13 RLIN36RX/IRQ14 */
		case ( 6 << 4) | (2 << 2) | 1:	R_PORT_SetAlt_Pnm(  9,  3, 2, PORT_e_IO_IN );	break;	/* P09_3  RLIN36RX/IRQ14 */
		case ( 6 << 4) | (2 << 2) | 2:	R_PORT_SetAlt_Pnm( 12,  0, 5, PORT_e_IO_IN );	break;	/* P12_0  RLIN36RX/IRQ14 */
		
		/* RLIN37 */
		case ( 7 << 4) | (0 << 2) | 0:	R_PORT_SetAlt_Pnm(  8, 10, 7, PORT_e_IO_IN );	break;	/* P08_10 RLIN37RX */
		case ( 7 << 4) | (0 << 2) | 1:	R_PORT_SetAlt_Pnm( 10,  3, 7, PORT_e_IO_IN );	break;	/* P10_3  RLIN37RX */
		case ( 7 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm(  8, 10, 4, PORT_e_IO_IN );	break;	/* P08_10 RLIN37RX/IRQ15 */
		case ( 7 << 4) | (2 << 2) | 1:	R_PORT_SetAlt_Pnm( 10,  3, 6, PORT_e_IO_IN );	break;	/* P10_3  RLIN37RX/IRQ15 */
		
		/* RLIN38 */
		case ( 8 << 4) | (0 << 2) | 0:	R_PORT_SetAlt_Pnm(  9,  0, 8, PORT_e_IO_IN );	break;	/* P09_0 RLIN38RX */
		case ( 8 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm(  9,  0, 4, PORT_e_IO_IN );	break;	/* P09_0 RLIN38RX/IRQ16 */
		
		/* RLIN39 */
		case ( 9 << 4) | (0 << 2) | 0:	R_PORT_SetAlt_Pnm(  9,  2, 6, PORT_e_IO_IN );	break;	/* P09_2 RLIN39RX */
		case ( 9 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm(  9,  2, 5, PORT_e_IO_IN );	break;	/* P09_2 RLIN39RX/IRQ17 */
		
		/* RLIN310 */
		case (10 << 4) | (0 << 2) | 0:	R_PORT_SetAlt_Pnm(  9,  4, 6, PORT_e_IO_IN );	break;	/* P09_4 RLIN310RX */
		case (10 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm(  9,  4, 5, PORT_e_IO_IN );	break;	/* P09_4 RLIN310RX/IRQ18 */
		
		/* RLIN311 */
		case (11 << 4) | (0 << 2) | 0:	R_PORT_SetAlt_Pnm( 10,  4, 7, PORT_e_IO_IN );	break;	/* P10_4 RLIN311RX */
		case (11 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm( 10,  4, 2, PORT_e_IO_IN );	break;	/* P10_4 RLIN311RX/IRQ19 */
		
		/* RLIN312 */
		case (12 << 4) | (0 << 2) | 0:	R_PORT_SetAlt_Pnm( 10, 14, 7, PORT_e_IO_IN );	break;	/* P10_14 RLIN312RX */
		case (12 << 4) | (2 << 2) | 1:	R_PORT_SetAlt_Pnm( 10,  6, 6, PORT_e_IO_IN );	break;	/* P10_6 RLIN312RX/IRQ20 */
		
		/* RLIN313 */
		case (13 << 4) | (0 << 2) | 0:	R_PORT_SetAlt_Pnm( 11,  1, 5, PORT_e_IO_IN );	break;	/* P11_1 RLIN313RX */
		case (13 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm( 11,  1, 2, PORT_e_IO_IN );	break;	/* P11_1 RLIN313RX/IRQ21 */
		
		/* RLIN314 */
		case (14 << 4) | (0 << 2) | 0:	R_PORT_SetAlt_Pnm( 10, 15, 6, PORT_e_IO_IN );	break;	/* P10_15 RLIN314RX */
		case (14 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm( 10, 15, 3, PORT_e_IO_IN );	break;	/* P10_15 RLIN314RX/IRQ22 */
		
		/* RLIN315 */
		case (15 << 4) | (0 << 2) | 0:	R_PORT_SetAlt_Pnm( 11, 10, 6, PORT_e_IO_IN );	break;	/* P11_10 RLIN315RX */
		case (15 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm( 11, 10, 1, PORT_e_IO_IN );	break;	/* P11_10 RLIN315RX/IRQ23 */
		
		/* RLIN316 */
		case (16 << 4) | (0 << 2) | 0:	R_PORT_SetAlt_Pnm( 13,  0, 2, PORT_e_IO_IN );	break;	/* P13_0 RLIN316RX */
		case (16 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm( 13,  0, 1, PORT_e_IO_IN );	break;	/* P13_0 RLIN316RX/IRQ24 */
		
		/* RLIN317 */
		case (17 << 4) | (0 << 2) | 0:	R_PORT_SetAlt_Pnm( 13,  2, 2, PORT_e_IO_IN );	break;	/* P13_2 RLIN317RX */
		case (17 << 4) | (2 << 2) | 0:	R_PORT_SetAlt_Pnm( 13,  2, 1, PORT_e_IO_IN );	break;	/* P13_2 RLIN317RX/IRQ25 */
		
	    default:	break;
	}	
	
}


/*******************************************************************************
* Description  : return RLIN3nTX pin to port mode
* Arguments    : uint8_t n  : unit number of RLIN3
*                uint8_t pin: serial number of same function pin
* Return Value : (none)
*******************************************************************************/
void R_RLIN3_CloseRLIN3nTX( uint8_t n, uint8_t pin ){
	
	switch( (n << 4) | pin ){	
		/* RLIN30 */
		case (0 << 4) | 0:	R_PORT_InitPort_Pnm(  0,  2 );	break;	/* P00_2 RLIN30TX */
		case (0 << 4) | 1:	R_PORT_InitPort_Pnm( 10, 10 );	break;	/* P10_10 RLIN30TX */
		
		/* RLIN31 */
		case (1 << 4) | 0:	R_PORT_InitPort_Pnm(  0,  5 );	break;	/* P00_5 RLIN31TX */
		case (1 << 4) | 1:	R_PORT_InitPort_Pnm( 10, 12 );	break;	/* P10_12 RLIN31TX */
		
		/* RLIN32 */
		case (2 << 4) | 0:	R_PORT_InitPort_Pnm(  0, 14 );	break;	/* P00_14 RLIN32TX */
		case (2 << 4) | 1:	R_PORT_InitPort_Pnm( 10, 14 );	break;	/* P10_14 RLIN32TX */
		case (2 << 4) | 2:	R_PORT_InitPort_Pnm( 11,  3 );	break;	/* P11_3 RLIN32TX */
		
		/* RLIN33 */
		case (3 << 4) | 0:	R_PORT_InitPort_Pnm(  1,  1 );	break;	/* P01_1 RLIN33TX */
		case (3 << 4) | 1:	R_PORT_InitPort_Pnm(  9,  0 );	break;	/* P09_0 RLIN33TX */
		case (3 << 4) | 2:	R_PORT_InitPort_Pnm( 10,  2 );	break;	/* P10_2 RLIN33TX */
		case (3 << 4) | 3:	R_PORT_InitPort_Pnm( 11,  5 );	break;	/* P11_5 RLIN33TX */
		
		/* RLIN34 */
		case (4 << 4) | 0:	R_PORT_InitPort_Pnm(  1,  9 );	break;	/* P01_9 RLIN34TX */
		case (4 << 4) | 1:	R_PORT_InitPort_Pnm(  8,  9 );	break;	/* P08_9 RLIN34TX */
		case (4 << 4) | 2:	R_PORT_InitPort_Pnm( 10, 13 );	break;	/* P10_13 RLIN34TX */
		case (4 << 4) | 3:	R_PORT_InitPort_Pnm( 12,  2 );	break;	/* P12_2 RLIN34TX */
		
		/* RLIN35 */
		case (5 << 4) | 0:	R_PORT_InitPort_Pnm(  1,  5 );	break;	/* P01_5 RLIN35TX */
		case (5 << 4) | 1:	R_PORT_InitPort_Pnm( 10,  1 );	break;	/* P10_1 RLIN35TX */
		case (5 << 4) | 2:	R_PORT_InitPort_Pnm( 11,  8 );	break;	/* P11_8 RLIN35TX */
		
		/* RLIN36 */
		case (6 << 4) | 0:	R_PORT_InitPort_Pnm(  1, 12 );	break;	/* P01_12 RLIN36TX */
		case (6 << 4) | 1:	R_PORT_InitPort_Pnm(  9,  2 );	break;	/* P09_2 RLIN36TX */
		case (6 << 4) | 2:	R_PORT_InitPort_Pnm( 11, 15 );	break;	/* P11_15 RLIN36TX */
		
		/* RLIN37 */
		case (7 << 4) | 0:	R_PORT_InitPort_Pnm(  8,  2 );	break;	/* P08_2 RLIN37TX */
		case (7 << 4) | 1:	R_PORT_InitPort_Pnm( 10,  2 );	break;	/* P10_2 RLIN37TX */
		
		/* RLIN38 */
		case (8 << 4) | 0:	R_PORT_InitPort_Pnm(  9,  1 );	break;	/* P09_1 RLIN38TX */
		
		/* RLIN39 */
		case (9 << 4) | 0:	R_PORT_InitPort_Pnm(  9,  3 );	break;	/* P09_3 RLIN39TX */
		
		/* RLIN310 */
		case (10 << 4) | 0:	R_PORT_InitPort_Pnm( 10,  0 );	break;	/* P10_0 RLIN310TX */
		
		/* RLIN311 */
		case (11 << 4) | 0:	R_PORT_InitPort_Pnm( 10,  5 );	break;	/* P10_5 RLIN311TX */
		
		/* RLIN312 */
		case (12 << 4) | 0:	R_PORT_InitPort_Pnm( 10,  7 );	break;	/* P10_7 RLIN312TX */
		
		/* RLIN313 */
		case (13 << 4) | 0:	R_PORT_InitPort_Pnm( 11,  2 );	break;	/* P11_2 RLIN313TX */
		
		/* RLIN314 */
		case (14 << 4) | 0:	R_PORT_InitPort_Pnm( 11,  0 );	break;	/* P11_0 RLIN314TX */
		
		/* RLIN315 */
		case (15 << 4) | 0:	R_PORT_InitPort_Pnm( 11, 11 );	break;	/* P11_11 RLIN315TX */
		
		/* RLIN316 */
		case (16 << 4) | 0:	R_PORT_InitPort_Pnm( 13,  1 );	break;	/* P13_1 RLIN316TX */
		
		/* RLIN317 */
		case (17 << 4) | 0:	R_PORT_InitPort_Pnm( 13,  3 );	break;	/* P13_3 RLIN317TX */
		
    	default:	        break;
	}
	
}


/*******************************************************************************
* Description  : return RLIN3nRX pin to port mode
* Arguments    : uint8_t n  : unit number of RLIN3
*                uint8_t pin: serial number of same function pin
* Return Value : (none)
*******************************************************************************/
void R_RLIN3_CloseRLIN3nRX( uint8_t n, uint8_t pin ){

	switch( (n << 4) | (pin & 0x3) ){	/* pin: only check bit 1-0 because different of bit 3-2 are the same pins,
                                           only the shared function numbers are different. */
		/* RLIN30 */
		case ( 0 << 4) | 0:	R_PORT_InitPort_Pnm(  0,  3 );	break;	/* P00_3 */
		case ( 0 << 4) | 1:	R_PORT_InitPort_Pnm( 10,  9 );	break;	/* P10_9 */
		
		/* RLIN31 */
		case ( 1 << 4) | 0:	R_PORT_InitPort_Pnm(  0,  4 );	break;	/* P00_4 */
		case ( 1 << 4) | 1:	R_PORT_InitPort_Pnm( 10, 11 );	break;	/* P10_11 */
		
		/* RLIN32 */
		case ( 2 << 4) | 0:	R_PORT_InitPort_Pnm(  0, 13 );	break;	/* P00_13 */
		case ( 2 << 4) | 1:	R_PORT_InitPort_Pnm( 10, 13 );	break;	/* P10_13 */
		case ( 2 << 4) | 2:	R_PORT_InitPort_Pnm( 11,  2 );	break;	/* P11_2 */
		
		/* RLIN33 */
		case ( 3 << 4) | 0:	R_PORT_InitPort_Pnm(  1,  0 );	break;	/* P01_0 */
		case ( 3 << 4) | 1:	R_PORT_InitPort_Pnm(  9,  1 );	break;	/* P09_1 */
		case ( 3 << 4) | 2:	R_PORT_InitPort_Pnm( 10,  1 );	break;	/* P10_1 */
		case ( 3 << 4) | 3:	R_PORT_InitPort_Pnm( 11,  6 );	break;	/* P11_6 */
		
		/* RLIN34 */
		case ( 4 << 4) | 0:	R_PORT_InitPort_Pnm(  8,  8 );	break;	/* P08_8 */
		case ( 4 << 4) | 1:	R_PORT_InitPort_Pnm( 10, 14 );	break;	/* P10_14 */
		case ( 4 << 4) | 2:	R_PORT_InitPort_Pnm( 12,  1 );	break;	/* P12_1 */
		case ( 4 << 4) | 3:	R_PORT_InitPort_Pnm(  1,  8 );	break;	/* P01_8 */
		
		/* RLIN35 */
		case ( 5 << 4) | 0:	R_PORT_InitPort_Pnm(  1,  4 );	break;	/* P01_4 */
		case ( 5 << 4) | 1:	R_PORT_InitPort_Pnm( 10,  2 );	break;	/* P10_2 */
		case ( 5 << 4) | 2:	R_PORT_InitPort_Pnm( 11,  9 );	break;	/* P11_9 */
		
		/* RLIN36 */
		case ( 6 << 4) | 0:	R_PORT_InitPort_Pnm(  1, 13 );	break;	/* P01_13 */
		case ( 6 << 4) | 1:	R_PORT_InitPort_Pnm(  9,  3 );	break;	/* P09_3 */
		case ( 6 << 4) | 2:	R_PORT_InitPort_Pnm( 12,  0 );	break;	/* P12_0 */
		
		/* RLIN37 */
		case ( 7 << 4) | 0:	R_PORT_InitPort_Pnm(  8, 10 );	break;	/* P08_10 */
		case ( 7 << 4) | 1:	R_PORT_InitPort_Pnm( 10,  3 );	break;	/* P10_3 */
		
		/* RLIN38 */
		case ( 8 << 4) | 0:	R_PORT_InitPort_Pnm(  9,  0 );	break;	/* P09_0 */
		
		/* RLIN39 */
		case ( 9 << 4) | 0:	R_PORT_InitPort_Pnm(  9,  2 );	break;	/* P09_2 */
		
		/* RLIN310 */
		case (10 << 4) | 0:	R_PORT_InitPort_Pnm(  9,  4 );	break;	/* P09_4 */
		
		/* RLIN311 */
		case (11 << 4) | 0:	R_PORT_InitPort_Pnm( 10,  4 );	break;	/* P10_4 */
		
		/* RLIN312 */
		case (12 << 4) | 0:	R_PORT_InitPort_Pnm( 10, 14 );	break;	/* P10_14 */
		case (12 << 4) | 1:	R_PORT_InitPort_Pnm( 10,  6 );	break;	/* P10_6 */
		
		/* RLIN313 */
		case (13 << 4) | 0:	R_PORT_InitPort_Pnm( 11,  1 );	break;	/* P11_1 */
		
		/* RLIN314 */
		case (14 << 4) | 0:	R_PORT_InitPort_Pnm( 10, 15 );	break;	/* P10_15 */
		
		/* RLIN315 */
		case (15 << 4) | 0:	R_PORT_InitPort_Pnm( 11, 10 );	break;	/* P11_10 */
		
		/* RLIN316 */
		case (16 << 4) | 0:	R_PORT_InitPort_Pnm( 13,  0 );	break;	/* P13_0 */
		
		/* RLIN317 */
		case (17 << 4) | 0:	R_PORT_InitPort_Pnm( 13,  2 );	break;	/* P13_2 */
		
		default:	break;
	}	
	
}


/*******************************************************************************
* Return to default section
*******************************************************************************/
#pragma	section	default
