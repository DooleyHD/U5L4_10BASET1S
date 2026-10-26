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
* File Name    : R_device_RSCFD.c
* Version      : 1.00
* Module(s)    : RLIN3
* Device(s)    : RH850/U2B product
* Description  : This file contains product-specific descriptions of the RLIN3 
*                drivers.
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_device_RSCFD.h"
#include "R_driver_port.h"


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
* Description  : open CANnTX pin.
* Arguments    : uint8_t n  : unit number of RSCFD
*                uint8_t pin: serial number of same function pin
* Return Value : (none)
*******************************************************************************/
void R_RSCFD_OpenCANnTX( uint8_t n, uint8_t pin ){

	switch( (n << 4) | (pin & 0x3) ){	/* "pin": only check bit 2-0 to share "pin" with R_RSCFD_OpenCANnRX */
		/* CAN0 */
		case (0 << 4) | (0 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  0,  0, 2, PORT_e_IO_OUT );	break;	/* P00_0 CAN0TX */
		case (0 << 4) | (1 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm( 10,  1, 2, PORT_e_IO_OUT );	break;	/* P10_1 CAN0TX */

		/* CAN1 */
		case (1 << 4) | (0 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  0,  3, 2, PORT_e_IO_OUT );	break;	/* P00_3 CAN1TX */
		case (1 << 4) | (1 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm( 10,  7, 4, PORT_e_IO_OUT );	break;	/* P10_7 CAN1TX */

		/* CAN2 */
		case (2 << 4) | (0 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  0,  4, 1, PORT_e_IO_OUT );	break;	/* P00_4 CAN2TX */
		case (2 << 4) | (1 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm( 12,  0, 1, PORT_e_IO_OUT );	break;	/* P12_0 CAN2TX */

		/* CAN3 */
		case (3 << 4) | (0 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  1,  3, 1, PORT_e_IO_OUT );	break;	/* P01_3 CAN3TX */
		case (3 << 4) | (1 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm( 11,  4, 1, PORT_e_IO_OUT );	break;	/* P11_4 CAN3TX */
		case (3 << 4) | (2 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  0,  8, 5, PORT_e_IO_OUT );	break;	/* P00_8 CAN3TX */

		/* CAN4 */
		case (4 << 4) | (0 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  1, 13, 1, PORT_e_IO_OUT );	break;	/* P01_13 CAN4TX */
		case (4 << 4) | (1 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm( 20,  3, 1, PORT_e_IO_OUT );	break;	/* P20_3 CAN4TX */
		case (4 << 4) | (2 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  0, 10, 5, PORT_e_IO_OUT );	break;	/* P00_10 CAN4TX */

		/* CAN5 */
		case (5 << 4) | (0 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  0, 14, 5, PORT_e_IO_OUT );	break;	/* P00_14 CAN5TX */
		case (5 << 4) | (1 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm( 11,  6, 1, PORT_e_IO_OUT );	break;	/* P11_6 CAN5TX */

		default:			break;
	}
}


/*******************************************************************************
* Description  : open CANnRX pin.
* Arguments    : uint8_t n  : unit number of RSCFD
*                uint8_t pin: serial number of same function pin
* Return Value : (none)
*******************************************************************************/
void R_RSCFD_OpenCANnRX( uint8_t n, uint8_t pin ){
	
	switch( (n << 4) | (pin & 0x3) ){	/* "pin": only check bit 2-0 to share "pin" with R_RSCFD_OpenCANnRX */
		/* CAN0 */
		case (0 << 4) | (0 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  0,  1, 7, PORT_e_IO_IN  );	break;	/* P00_1 CAN0RX */
		case (0 << 4) | (1 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm( 10,  0, 7, PORT_e_IO_IN  );	break;	/* P10_0 CAN0RX */
		case (0 << 4) | (0 << 2) | (1 << 0):	R_PORT_SetAlt_Pnm(  0,  1, 2, PORT_e_IO_IN  );	break;	/* P00_1 CAN0RX/IRQ0 */
		case (0 << 4) | (1 << 2) | (1 << 0):	R_PORT_SetAlt_Pnm( 10,  0, 2, PORT_e_IO_IN  );	break;	/* P10_0 CAN0RX/IRQ0 */

		/* CAN1 */
		case (1 << 4) | (0 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  0,  2, 7, PORT_e_IO_IN  );	break;	/* P00_2 CAN1RX */
		case (1 << 4) | (1 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm( 10,  6, 7, PORT_e_IO_IN  );	break;	/* P10_6 CAN1RX */
		case (1 << 4) | (0 << 2) | (1 << 0):	R_PORT_SetAlt_Pnm(  0,  2, 2, PORT_e_IO_IN  );	break;	/* P00_2 CAN1RX/IRQ1 */
		case (1 << 4) | (1 << 2) | (1 << 0):	R_PORT_SetAlt_Pnm( 10,  6, 4, PORT_e_IO_IN  );	break;	/* P10_6 CAN1RX/IRQ1 */

		/* CAN2 */
		case (2 << 4) | (0 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  0,  5, 7, PORT_e_IO_IN  );	break;	/* P00_5 CAN2RX */
		case (2 << 4) | (1 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm( 11, 15, 7, PORT_e_IO_IN  );	break;	/* P11_15 CAN2RX */
		case (2 << 4) | (0 << 2) | (1 << 0):	R_PORT_SetAlt_Pnm(  0,  5, 1, PORT_e_IO_IN  );	break;	/* P00_5 CAN2RX/IRQ2 */
		case (2 << 4) | (1 << 2) | (1 << 0):	R_PORT_SetAlt_Pnm( 11, 15, 1, PORT_e_IO_IN  );	break;	/* P11_15 CAN2RX/IRQ2 */

		/* CAN3 */
		case (3 << 4) | (0 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  0,  7, 7, PORT_e_IO_IN  );	break;	/* P00_7 CAN3RX */
		case (3 << 4) | (1 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  1,  2, 7, PORT_e_IO_IN  );	break;	/* P01_2 CAN3RX */
		case (3 << 4) | (2 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm( 11,  3, 7, PORT_e_IO_IN  );	break;	/* P11_3 CAN3RX */
		case (3 << 4) | (0 << 2) | (1 << 0):	R_PORT_SetAlt_Pnm(  1,  2, 1, PORT_e_IO_IN  );	break;	/* P01_2 CAN3RX/IRQ3 */
		case (3 << 4) | (1 << 2) | (1 << 0):	R_PORT_SetAlt_Pnm( 11,  3, 2, PORT_e_IO_IN  );	break;	/* P11_3 CAN3RX/IRQ3 */
		case (3 << 4) | (2 << 2) | (1 << 0):	R_PORT_SetAlt_Pnm(  0,  7, 5, PORT_e_IO_IN  );	break;	/* P00_7 CAN3RX/IRQ3 */

		/* CAN4 */
		case (4 << 4) | (0 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  0,  9, 7, PORT_e_IO_IN  );	break;	/* P00_9 CAN4RX */
		case (4 << 4) | (1 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  1, 12, 7, PORT_e_IO_IN  );	break;	/* P01_12 CAN4RX */
		case (4 << 4) | (2 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm( 20,  2, 7, PORT_e_IO_IN  );	break;	/* P20_2 CAN4RX */
		case (4 << 4) | (0 << 2) | (1 << 0):	R_PORT_SetAlt_Pnm(  1, 12, 1, PORT_e_IO_IN  );	break;	/* P01_12 CAN4RX/IRQ4 */
		case (4 << 4) | (1 << 2) | (1 << 0):	R_PORT_SetAlt_Pnm( 20,  2, 1, PORT_e_IO_IN  );	break;	/* P20_2 CAN4RX/IRQ4 */
		case (4 << 4) | (2 << 2) | (1 << 0):	R_PORT_SetAlt_Pnm(  0,  9, 5, PORT_e_IO_IN  );	break;	/* P00_9 CAN4RX/IRQ4 */

		/* CAN5 */
		case (5 << 4) | (0 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm(  0, 13, 7, PORT_e_IO_IN  );	break;	/* P00_13 CAN5RX */
		case (5 << 4) | (1 << 2) | (0 << 0):	R_PORT_SetAlt_Pnm( 11,  5, 7, PORT_e_IO_IN  );	break;	/* P11_5 CAN5RX */
		case (5 << 4) | (0 << 2) | (1 << 0):	R_PORT_SetAlt_Pnm(  0, 13, 5, PORT_e_IO_IN  );	break;	/* P00_13 CAN5RX/IRQ5 */
		case (5 << 4) | (1 << 2) | (1 << 0):	R_PORT_SetAlt_Pnm( 11,  5, 1, PORT_e_IO_IN  );	break;	/* P11_5 CAN5RX/IRQ5 */

		default:			break;
	}

}



/*******************************************************************************
* Return to default section
*******************************************************************************/
#pragma	section	default
