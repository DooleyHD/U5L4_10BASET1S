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
* File Name    : R_driver_port.h
* Version      : 1.00
* Module(s)    : PORT
* Device(s)    : R-Car U5L product
* Description  : PORT function driver for R-Car U5L
*******************************************************************************/

/*******************************************************************************
* Specifications
*******************************************************************************/
/*                | U5L4 | U5L4 | U5L4 | U5L4 | U5L2 | U5L2 | U5L2 | U5L2 | U5L2 | U5L1 | U5L1 | U5L1 |
 *                | 257  | 176  | 144  | 100  | 176  | 144  | 100  | 80   | 64   | 100  | 80   | 64   |
 *	JP0 AWO E0VCC | 0-6  | 0-6  | 0-6  | 0-5  | 0-5  | 0-5  | 0-5  | 0-5  | 0-5  | 0-5  | 0-5  | 0-5  |
 *  P00 AWO E0VCC | 0-14 | 0-14 | 0-14 | 0-8, | 0-14 | 0-14 | 0-7  | 1-5  | 1-5  | 0-14 | 1-5  | 1-5  |
 *                                     |11,12 |             |11,12 |             |      | 9,10 |      |
 *  P01 ISO E0VCC | 1-5  | 2-5  | 2-5  | -    | 0-5  | 0-5  | -    | -    | -    | -    | -    | -    |
 *                | 8-15 | 8-15 | 8-11 | -    | 8-15 | 8-11 |      |      |      |      |      |      |
 *  P02 AWO E0VCC | 0-13 | 0-6  | -    | -    | 0-6  | -    | -    | -    | -    | -    | -    | -    |
 *  P03 ISO E0VCC | 0-8  | -    | -    | -    | -    | -    | -    | -    | -    | -    | -    | -    |
 *  P08 AWO E0VCC | 0-12 | 0-12 | 0-12 | 0-12 | 0-5, | 0-5, | 0-5, | 0-3  | 0-3  | 0-5, | 0-3  | 0-3  |
 *                |      |      |      |      | 7-12 | 7-12 | 7-11 | -    | -    | 7-12 | -    | -    |
 *  P09 ISO E0VCC | 0-4  | 2-4  | 2-4  | 2-4  | 0-4  | 0-4  | 0-2  | -    | -    | 0-4  | 0,1  | 0,1  |
 *  P10 ISO E1VCC | 0-15 |0,2-12| 5-8, | -    | 0-15 |5-8,15| -    | -    | -    | 0-15 | 4-15 | 4-11 |
 *                |      | 15   | 15   |      |      |      |      |      |      |      |      |      |
 *  P11 ISO E1VCC | 0-15 | 0,1,4|0,8-15| -    | 0-15 |0,8-15| -    | -    | -    | 0-7  | 0,1  | -    |
 *                |      | 7-15 |      |      |      |      |      |      |      |      |      |      |
 *  P12 ISO E1VCC | 0-5  | 0-5  | 0-2  | -    | 0-5  | 0-2  | -    | -    | -    | -    | -    | -    |
 *  P13 ISO E1VCC | 0-7  | -    | -    | -    | -    | -    | -    | -    | -    | -    | -    | -    |
 *  P18 ISO E1VCC | 0-15 | 0-7  | 0-2  | -    | 0-7  | 0-2  | -    | -    | -    | -    | -    | -    |
 *  P19 ISO E1VCC | 0-3  | -    | -    | -    | -    | -    | -    | -    | -    | -    | -    | -    |
 *  P20 ISO E0VCC | 0-13 | 0-5  | 4,5  | -    | 0-5  | 4,5  | -    | -    | -    | -    | -    | -    |
 *  P21 ISO E1VCC | 0-2  | -    | -    | -    | -    | -    | -    | -    | -    | -    | -    | -    |
 *  AP0 ISO A0VREF| 0-15 | 0-15 | 0-15 | 0-15 | 0-15 | 0-15 | 0-15 | 0-10 | 0-9  | 0-15 | 0-10 | 0-9  |
 *  AP2 ISO A1VREF| 0-15 | 0-15 | 0-7  | -    | 4-15 | 4-7  | -    | -    | -    | -    | -    | -    |
 *
 */

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_port_H__
#define	__R_driver_port_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_port_reg.h"	/* for reference of register structure */
#include "R_driver_general.h"


/*******************************************************************************
* Extern of global variables
*******************************************************************************/
/* definition of relationship between port number and PWE bit number
   index of PORT_PWE_bit[] is same as port group number and 
   value of PORT_PWE_bit[] provides PWE bit number */
extern const uint8_t PORT_PWE_bit[];
extern const uint8_t PORT_PWEAP_bit[]; 
extern const uint8_t PORT_PWEIP_bit[];

/**/
typedef enum{
	PORT_e_kind_P, 	/* number port */
	PORT_e_kind_AP,	/* A port */
	PORT_e_kind_JP,	/* J port */
	PORT_e_kind_IP 	/* I port */
}PORT_e_kind;

/* input/output selection for R_PORT_SetAlt_Pnm/R_PORT_SetAlt_JPnm function  */
typedef enum{
	PORT_e_IO_OUT, 	/* output */
	PORT_e_IO_IN,  	/* input */
	PORT_e_IO_INOUT	/* input/output */
}PORT_e_IO;

/* drive strength selection for PORT_SetStrength_xx */
typedef enum{
	PORT_e_st_high,  	/* PDSCn_m=1, Drive strength = 2 (high) */
	PORT_e_st_medium,	/* PDSCn_m=1, Drive strength = 3 (medium) */
	PORT_e_st_low,   	/* PDSCn_m=0; Drive strength = 4 (low) */
}PORT_e_st;

/* open-drain/push-pull selection for R_PORT_ChangeOutputType_xx */
typedef enum{
	PORT_e_outtype_pushpull,	/* PODCEn_m=0, PODCn_m=0: Push-pull */
	PORT_e_outtype_Nch_od,  	/* PODCEn_m=0, PODCn_m=1: Emulated N-channel Open Drain */
	PORT_e_outtype_Pch_od,  	/* PODCEn_m=1, PODCn_m=1: Emulated P-channel Open Drain */
}PORT_e_outtype;

/* input buffer type selection for PORT_ChangeInputtype_xx */
typedef enum{
	PORT_e_intype_SHMT1,	/* PISAn_m=0, PISn_m=0: SHMT1 input buffer */
	PORT_e_intype_SHMT4,	/* PISAn_m=0, PISn_m=1: SHMT4 input buffer */
	PORT_e_intype_TTL   	/* PISAn_m=1, PISn_m=x: TTL input buffer */
}PORT_e_intype;


/*******************************************************************************
* Type definitions for the function return value
*******************************************************************************/


/*******************************************************************************
* Type definitions for the arguments of the function
*******************************************************************************/


/*******************************************************************************
* Function calling description of port alternative function
*******************************************************************************/
#if 0
R_PORT_SetAlt_Pnm( 10, 4, 8, PORT_e_IO_IN );	/* P10_4 "6" (�v�m�F) */
R_PORT_SetAlt_Pnm( 10, 9, 6, PORT_e_IO_OUT );	/* P10_9 ADCK0END0 */
R_PORT_SetAlt_Pnm( 10, 10, 5, PORT_e_IO_OUT );	/* P10_10 ADCK0END1 */
R_PORT_SetAlt_Pnm( 10, 11, 5, PORT_e_IO_OUT );	/* P10_11 ADCK0END2 */
R_PORT_SetAlt_Pnm( 10, 12, 5, PORT_e_IO_OUT );	/* P10_12 ADCK0END3 */
R_PORT_SetAlt_Pnm( 10, 13, 5, PORT_e_IO_OUT );	/* P10_13 ADCK0END4 */
R_PORT_SetAlt_Pnm( 2, 4, 2, PORT_e_IO_OUT );	/* P02_4 ADCK0SEL0 */
R_PORT_SetAlt_Pnm( 8, 7, 3, PORT_e_IO_OUT );	/* P08_7 ADCK0SEL0 */
R_PORT_SetAlt_Pnm( 10, 4, 7, PORT_e_IO_OUT );	/* P10_4 ADCK0SEL0 */
R_PORT_SetAlt_Pnm( 2, 5, 2, PORT_e_IO_OUT );	/* P02_5 ADCK0SEL1 */
R_PORT_SetAlt_Pnm( 8, 8, 3, PORT_e_IO_OUT );	/* P08_8 ADCK0SEL1 */
R_PORT_SetAlt_Pnm( 10, 5, 7, PORT_e_IO_OUT );	/* P10_5 ADCK0SEL1 */
R_PORT_SetAlt_Pnm( 2, 6, 1, PORT_e_IO_OUT );	/* P02_6 ADCK0SEL2 */
R_PORT_SetAlt_Pnm( 8, 9, 3, PORT_e_IO_OUT );	/* P08_9 ADCK0SEL2 */
R_PORT_SetAlt_Pnm( 10, 6, 7, PORT_e_IO_OUT );	/* P10_6 ADCK0SEL2 */
R_PORT_SetAlt_Pnm( 9, 0, 3, PORT_e_IO_IN );	/* P09_0 ADCK0TRG0 */
R_PORT_SetAlt_Pnm( 10, 2, 4, PORT_e_IO_IN );	/* P10_2 ADCK0TRG0 */
R_PORT_SetAlt_Pnm( 10, 3, 4, PORT_e_IO_IN );	/* P10_3 ADCK0TRG1 */
R_PORT_SetAlt_Pnm( 10, 4, 4, PORT_e_IO_IN );	/* P10_4 ADCK0TRG2 */
R_PORT_SetAlt_Pnm( 10, 7, 4, PORT_e_IO_IN );	/* P10_7 ADCK0TRG3 */
R_PORT_SetAlt_Pnm( 10, 8, 4, PORT_e_IO_IN );	/* P10_8 ADCK0TRG4 */
R_PORT_SetAlt_Pnm( 10, 15, 5, PORT_e_IO_OUT );	/* P10_15 ADCK1END0 */
R_PORT_SetAlt_Pnm( 11, 1, 5, PORT_e_IO_OUT );	/* P11_1 ADCK1END1 */
R_PORT_SetAlt_Pnm( 11, 2, 5, PORT_e_IO_OUT );	/* P11_2 ADCK1END2 */
R_PORT_SetAlt_Pnm( 11, 3, 4, PORT_e_IO_OUT );	/* P11_3 ADCK1END3 */
R_PORT_SetAlt_Pnm( 11, 4, 4, PORT_e_IO_OUT );	/* P11_4 ADCK1END4 */
R_PORT_SetAlt_Pnm( 11, 8, 4, PORT_e_IO_OUT );	/* P11_8 ADCK1SEL0 */
R_PORT_SetAlt_Pnm( 11, 9, 4, PORT_e_IO_OUT );	/* P11_9 ADCK1SEL1 */
R_PORT_SetAlt_Pnm( 11, 10, 4, PORT_e_IO_OUT );	/* P11_10 ADCK1SEL2 */
R_PORT_SetAlt_Pnm( 1, 5, 1, PORT_e_IO_IN );	/* P01_5 ADCK1TRG0 */
R_PORT_SetAlt_Pnm( 10, 14, 1, PORT_e_IO_IN );	/* P10_14 ADCK1TRG0 */
R_PORT_SetAlt_Pnm( 11, 6, 2, PORT_e_IO_IN );	/* P11_6 ADCK1TRG1 */
R_PORT_SetAlt_Pnm( 1, 10, 4, PORT_e_IO_IN );	/* P01_10 ADCK1TRG1 */
R_PORT_SetAlt_Pnm( 1, 11, 1, PORT_e_IO_IN );	/* P01_11 ADCK1TRG2 */
R_PORT_SetAlt_Pnm( 11, 0, 2, PORT_e_IO_IN );	/* P11_0 ADCK1TRG2 */
R_PORT_SetAlt_Pnm( 11, 5, 2, PORT_e_IO_IN );	/* P11_5 ADCK1TRG3 */
R_PORT_SetAlt_Pnm( 11, 7, 2, PORT_e_IO_IN );	/* P11_7 ADCK1TRG4 */
R_PORT_SetAlt_Pnm( 0, 1, 4, PORT_e_IO_OUT );	/* P00_1 APO */
R_PORT_SetAlt_Pnm( 0, 1, 7, PORT_e_IO_IN );	/* P00_1 CAN0RX */
R_PORT_SetAlt_Pnm( 10, 0, 7, PORT_e_IO_IN );	/* P10_0 CAN0RX */
R_PORT_SetAlt_Pnm( 0, 1, 2, PORT_e_IO_IN );	/* P00_1 CAN0RX/IRQ0 */
R_PORT_SetAlt_Pnm( 10, 0, 2, PORT_e_IO_IN );	/* P10_0 CAN0RX/IRQ0 */
R_PORT_SetAlt_Pnm( 0, 0, 2, PORT_e_IO_OUT );	/* P00_0 CAN0TX */
R_PORT_SetAlt_Pnm( 10, 1, 2, PORT_e_IO_OUT );	/* P10_1 CAN0TX */
R_PORT_SetAlt_Pnm( 0, 2, 7, PORT_e_IO_IN );	/* P00_2 CAN1RX */
R_PORT_SetAlt_Pnm( 10, 6, 7, PORT_e_IO_IN );	/* P10_6 CAN1RX */
R_PORT_SetAlt_Pnm( 0, 2, 2, PORT_e_IO_IN );	/* P00_2 CAN1RX/IRQ1 */
R_PORT_SetAlt_Pnm( 10, 6, 4, PORT_e_IO_IN );	/* P10_6 CAN1RX/IRQ1 */
R_PORT_SetAlt_Pnm( 0, 3, 2, PORT_e_IO_OUT );	/* P00_3 CAN1TX */
R_PORT_SetAlt_Pnm( 10, 7, 4, PORT_e_IO_OUT );	/* P10_7 CAN1TX */
R_PORT_SetAlt_Pnm( 0, 5, 7, PORT_e_IO_IN );	/* P00_5 CAN2RX */
R_PORT_SetAlt_Pnm( 11, 15, 7, PORT_e_IO_IN );	/* P11_15 CAN2RX */
R_PORT_SetAlt_Pnm( 0, 5, 1, PORT_e_IO_IN );	/* P00_5 CAN2RX/IRQ2 */
R_PORT_SetAlt_Pnm( 11, 15, 1, PORT_e_IO_IN );	/* P11_15 CAN2RX/IRQ2 */
R_PORT_SetAlt_Pnm( 0, 4, 1, PORT_e_IO_OUT );	/* P00_4 CAN2TX */
R_PORT_SetAlt_Pnm( 12, 0, 1, PORT_e_IO_OUT );	/* P12_0 CAN2TX */
R_PORT_SetAlt_Pnm( 0, 7, 7, PORT_e_IO_IN );	/* P00_7 CAN3RX */
R_PORT_SetAlt_Pnm( 1, 2, 7, PORT_e_IO_IN );	/* P01_2 CAN3RX */
R_PORT_SetAlt_Pnm( 11, 3, 7, PORT_e_IO_IN );	/* P11_3 CAN3RX */
R_PORT_SetAlt_Pnm( 1, 2, 1, PORT_e_IO_IN );	/* P01_2 CAN3RX/IRQ3 */
R_PORT_SetAlt_Pnm( 11, 3, 2, PORT_e_IO_IN );	/* P11_3 CAN3RX/IRQ3 */
R_PORT_SetAlt_Pnm( 0, 7, 5, PORT_e_IO_IN );	/* P00_7 CAN3RX/IRQ3 */
R_PORT_SetAlt_Pnm( 1, 3, 1, PORT_e_IO_OUT );	/* P01_3 CAN3TX */
R_PORT_SetAlt_Pnm( 11, 4, 1, PORT_e_IO_OUT );	/* P11_4 CAN3TX */
R_PORT_SetAlt_Pnm( 0, 8, 5, PORT_e_IO_OUT );	/* P00_8 CAN3TX */
R_PORT_SetAlt_Pnm( 0, 9, 7, PORT_e_IO_IN );	/* P00_9 CAN4RX */
R_PORT_SetAlt_Pnm( 1, 12, 7, PORT_e_IO_IN );	/* P01_12 CAN4RX */
R_PORT_SetAlt_Pnm( 20, 2, 7, PORT_e_IO_IN );	/* P20_2 CAN4RX */
R_PORT_SetAlt_Pnm( 1, 12, 1, PORT_e_IO_IN );	/* P01_12 CAN4RX/IRQ4 */
R_PORT_SetAlt_Pnm( 20, 2, 1, PORT_e_IO_IN );	/* P20_2 CAN4RX/IRQ4 */
R_PORT_SetAlt_Pnm( 0, 9, 5, PORT_e_IO_IN );	/* P00_9 CAN4RX/IRQ4 */
R_PORT_SetAlt_Pnm( 1, 13, 1, PORT_e_IO_OUT );	/* P01_13 CAN4TX */
R_PORT_SetAlt_Pnm( 20, 3, 1, PORT_e_IO_OUT );	/* P20_3 CAN4TX */
R_PORT_SetAlt_Pnm( 0, 10, 5, PORT_e_IO_OUT );	/* P00_10 CAN4TX */
R_PORT_SetAlt_Pnm( 0, 13, 7, PORT_e_IO_IN );	/* P00_13 CAN5RX */
R_PORT_SetAlt_Pnm( 11, 5, 7, PORT_e_IO_IN );	/* P11_5 CAN5RX */
R_PORT_SetAlt_Pnm( 11, 5, 1, PORT_e_IO_IN );	/* P11_5 CAN5RX/IRQ5 */
R_PORT_SetAlt_Pnm( 0, 13, 5, PORT_e_IO_IN );	/* P00_13 CAN5RX/IRQ5 */
R_PORT_SetAlt_Pnm( 11, 6, 1, PORT_e_IO_OUT );	/* P11_6 CAN5TX */
R_PORT_SetAlt_Pnm( 0, 14, 5, PORT_e_IO_OUT );	/* P00_14 CAN5TX */
R_PORT_SetAlt_Pnm( 10, 0, 8, PORT_e_IO_IN );	/* P10_0 CANXL0RXD */
R_PORT_SetAlt_Pnm( 10, 0, 3, PORT_e_IO_IN );	/* P10_0 CANXL0RXD/IRQ6 */
R_PORT_SetAlt_Pnm( 10, 1, 8, PORT_e_IO_OUT );	/* P10_1 CANXL0TXD */
R_PORT_SetAlt_Pnm( 2, 0, 7, PORT_e_IO_IN );	/* P02_0 CANXL1RXD */
R_PORT_SetAlt_Pnm( 8, 0, 7, PORT_e_IO_IN );	/* P08_0 CANXL1RXD */
R_PORT_SetAlt_Pnm( 10, 5, 7, PORT_e_IO_IN );	/* P10_5 CANXL1RXD */
R_PORT_SetAlt_Pnm( 20, 0, 7, PORT_e_IO_IN );	/* P20_0 CANXL1RXD */
R_PORT_SetAlt_Pnm( 2, 0, 2, PORT_e_IO_IN );	/* P02_0 CANXL1RXD/IRQ7 */
R_PORT_SetAlt_Pnm( 10, 5, 2, PORT_e_IO_IN );	/* P10_5 CANXL1RXD/IRQ7 */
R_PORT_SetAlt_Pnm( 20, 0, 3, PORT_e_IO_IN );	/* P20_0 CANXL1RXD/IRQ7 */
R_PORT_SetAlt_Pnm( 8, 0, 4, PORT_e_IO_IN );	/* P08_0 CANXL1RXD/IRQ7 */
R_PORT_SetAlt_Pnm( 2, 1, 2, PORT_e_IO_OUT );	/* P02_1 CANXL1TXD */
R_PORT_SetAlt_Pnm( 10, 4, 2, PORT_e_IO_OUT );	/* P10_4 CANXL1TXD */
R_PORT_SetAlt_Pnm( 20, 1, 3, PORT_e_IO_OUT );	/* P20_1 CANXL1TXD */
R_PORT_SetAlt_Pnm( 8, 1, 4, PORT_e_IO_OUT );	/* P08_1 CANXL1TXD */
R_PORT_SetAlt_Pnm( 8, 2, 2, PORT_e_IO_OUT );	/* P08_2 CSIH0CSS0 */
R_PORT_SetAlt_Pnm( 8, 0, 3, PORT_e_IO_OUT );	/* P08_0 CSIH0CSS0 */
R_PORT_SetAlt_Pnm( 8, 3, 2, PORT_e_IO_OUT );	/* P08_3 CSIH0CSS1 */
R_PORT_SetAlt_Pnm( 10, 10, 4, PORT_e_IO_OUT );	/* P10_10 CSIH0CSS1 */
R_PORT_SetAlt_Pnm( 8, 4, 2, PORT_e_IO_OUT );	/* P08_4 CSIH0CSS2 */
R_PORT_SetAlt_Pnm( 8, 5, 2, PORT_e_IO_OUT );	/* P08_5 CSIH0CSS3 */
R_PORT_SetAlt_Pnm( 0, 3, 4, PORT_e_IO_INOUT );	/* P00_3 CSIH0SO/DCS */
R_PORT_SetAlt_Pnm( 10, 9, 4, PORT_e_IO_IN );	/* P10_9 CSIH0RYI */
R_PORT_SetAlt_Pnm( 10, 9, 4, PORT_e_IO_OUT );	/* P10_9 CSIH0RYO */
R_PORT_SetAlt_Pnm( 0, 2, 4, PORT_e_IO_IN );	/* P00_2 CSIH0SC */
R_PORT_SetAlt_Pnm( 0, 2, 4, PORT_e_IO_OUT );	/* P00_2 CSIH0SC */
R_PORT_SetAlt_Pnm( 0, 1, 4, PORT_e_IO_IN );	/* P00_1 CSIH0SI */
R_PORT_SetAlt_Pnm( 0, 3, 4, PORT_e_IO_INOUT );	/* P00_3 CSIH0SO/DCS */
R_PORT_SetAlt_Pnm( 10, 13, 1, PORT_e_IO_IN );	/* P10_13 CSIH0SSI */
R_PORT_SetAlt_Pnm( 0, 0, 4, PORT_e_IO_IN );	/* P00_0 CSIH0SSI */
R_PORT_SetAlt_Pnm( 0, 9, 1, PORT_e_IO_OUT );	/* P00_9 CSIH1CSS0 */
R_PORT_SetAlt_Pnm( 10, 11, 3, PORT_e_IO_OUT );	/* P10_11 CSIH1CSS0 */
R_PORT_SetAlt_Pnm( 0, 10, 1, PORT_e_IO_OUT );	/* P00_10 CSIH1CSS1 */
R_PORT_SetAlt_Pnm( 10, 12, 3, PORT_e_IO_OUT );	/* P10_12 CSIH1CSS1 */
R_PORT_SetAlt_Pnm( 0, 11, 2, PORT_e_IO_OUT );	/* P00_11 CSIH1CSS2 */
R_PORT_SetAlt_Pnm( 0, 2, 8, PORT_e_IO_OUT );	/* P00_2 CSIH1CSS2 */
R_PORT_SetAlt_Pnm( 8, 1, 3, PORT_e_IO_OUT );	/* P08_1 CSIH1CSS3 */
R_PORT_SetAlt_Pnm( 8, 11, 3, PORT_e_IO_OUT );	/* P08_11 CSIH1CSS3 */
R_PORT_SetAlt_Pnm( 0, 5, 3, PORT_e_IO_INOUT );	/* P00_5 CSIH1SO/DCS */
R_PORT_SetAlt_Pnm( 10, 2, 5, PORT_e_IO_INOUT );	/* P10_2 CSIH1SO/DCS */
R_PORT_SetAlt_Pnm( 0, 7, 3, PORT_e_IO_IN );	/* P00_7 CSIH1RYI */
R_PORT_SetAlt_Pnm( 0, 3, 8, PORT_e_IO_IN );	/* P00_3 CSIH1RYI */
R_PORT_SetAlt_Pnm( 0, 7, 3, PORT_e_IO_OUT );	/* P00_7 CSIH1RYO */
R_PORT_SetAlt_Pnm( 0, 3, 8, PORT_e_IO_OUT );	/* P00_3 CSIH1RYO */
R_PORT_SetAlt_Pnm( 0, 6, 3, PORT_e_IO_IN );	/* P00_6 CSIH1SC */
R_PORT_SetAlt_Pnm( 0, 6, 3, PORT_e_IO_OUT );	/* P00_6 CSIH1SC */
R_PORT_SetAlt_Pnm( 10, 1, 5, PORT_e_IO_IN );	/* P10_1 CSIH1SC */
R_PORT_SetAlt_Pnm( 10, 1, 5, PORT_e_IO_OUT );	/* P10_1 CSIH1SC */
R_PORT_SetAlt_Pnm( 0, 4, 3, PORT_e_IO_IN );	/* P00_4 CSIH1SI */
R_PORT_SetAlt_Pnm( 10, 0, 5, PORT_e_IO_IN );	/* P10_0 CSIH1SI */
R_PORT_SetAlt_Pnm( 0, 5, 3, PORT_e_IO_INOUT );	/* P00_5 CSIH1SO/DCS */
R_PORT_SetAlt_Pnm( 10, 2, 5, PORT_e_IO_INOUT );	/* P10_2 CSIH1SO/DCS */
R_PORT_SetAlt_Pnm( 0, 8, 3, PORT_e_IO_IN );	/* P00_8 CSIH1SSI */
R_PORT_SetAlt_Pnm( 10, 3, 5, PORT_e_IO_IN );	/* P10_3 CSIH1SSI */
R_PORT_SetAlt_Pnm( 9, 0, 3, PORT_e_IO_OUT );	/* P09_0 CSIH2CSS0 */
R_PORT_SetAlt_Pnm( 9, 1, 3, PORT_e_IO_OUT );	/* P09_1 CSIH2CSS1 */
R_PORT_SetAlt_Pnm( 9, 2, 2, PORT_e_IO_OUT );	/* P09_2 CSIH2CSS2 */
R_PORT_SetAlt_Pnm( 10, 9, 12, PORT_e_IO_OUT );	/* P10_9 CSIH2CSS2 */
R_PORT_SetAlt_Pnm( 9, 3, 2, PORT_e_IO_OUT );	/* P09_3 CSIH2CSS3 */
R_PORT_SetAlt_Pnm( 10, 10, 12, PORT_e_IO_OUT );	/* P10_10 CSIH2CSS3 */
R_PORT_SetAlt_Pnm( 11, 2, 1, PORT_e_IO_INOUT );	/* P11_2 CSIH2SO/DCS */
R_PORT_SetAlt_Pnm( 10, 7, 12, PORT_e_IO_INOUT );	/* P10_7 CSIH2SO/DCS */
R_PORT_SetAlt_Pnm( 11, 0, 1, PORT_e_IO_IN );	/* P11_0 CSIH2RYI */
R_PORT_SetAlt_Pnm( 10, 13, 12, PORT_e_IO_IN );	/* P10_13 CSIH2RYI */
R_PORT_SetAlt_Pnm( 11, 0, 1, PORT_e_IO_OUT );	/* P11_0 CSIH2RYO */
R_PORT_SetAlt_Pnm( 10, 13, 12, PORT_e_IO_OUT );	/* P10_13 CSIH2RYO */
R_PORT_SetAlt_Pnm( 11, 3, 1, PORT_e_IO_IN );	/* P11_3 CSIH2SC */
R_PORT_SetAlt_Pnm( 11, 3, 1, PORT_e_IO_OUT );	/* P11_3 CSIH2SC */
R_PORT_SetAlt_Pnm( 10, 12, 12, PORT_e_IO_IN );	/* P10_12 CSIH2SC */
R_PORT_SetAlt_Pnm( 10, 12, 12, PORT_e_IO_OUT );	/* P10_12 CSIH2SC */
R_PORT_SetAlt_Pnm( 11, 4, 1, PORT_e_IO_IN );	/* P11_4 CSIH2SI */
R_PORT_SetAlt_Pnm( 10, 11, 12, PORT_e_IO_IN );	/* P10_11 CSIH2SI */
R_PORT_SetAlt_Pnm( 11, 2, 1, PORT_e_IO_INOUT );	/* P11_2 CSIH2SO/DCS */
R_PORT_SetAlt_Pnm( 10, 7, 12, PORT_e_IO_INOUT );	/* P10_7 CSIH2SO/DCS */
R_PORT_SetAlt_Pnm( 11, 1, 1, PORT_e_IO_IN );	/* P11_1 CSIH2SSI */
R_PORT_SetAlt_Pnm( 10, 8, 12, PORT_e_IO_IN );	/* P10_8 CSIH2SSI */
R_PORT_SetAlt_Pnm( 8, 7, 1, PORT_e_IO_OUT );	/* P08_7 CSIH3CSS0 */
R_PORT_SetAlt_Pnm( 11, 2, 12, PORT_e_IO_OUT );	/* P11_2 CSIH3CSS0 */
R_PORT_SetAlt_Pnm( 8, 8, 1, PORT_e_IO_OUT );	/* P08_8 CSIH3CSS1 */
R_PORT_SetAlt_Pnm( 11, 3, 12, PORT_e_IO_OUT );	/* P11_3 CSIH3CSS1 */
R_PORT_SetAlt_Pnm( 8, 9, 1, PORT_e_IO_OUT );	/* P08_9 CSIH3CSS2 */
R_PORT_SetAlt_Pnm( 11, 4, 12, PORT_e_IO_OUT );	/* P11_4 CSIH3CSS2 */
R_PORT_SetAlt_Pnm( 8, 10, 1, PORT_e_IO_OUT );	/* P08_10 CSIH3CSS3 */
R_PORT_SetAlt_Pnm( 10, 12, 7, PORT_e_IO_OUT );	/* P10_12 CSIH3CSS3 */
R_PORT_SetAlt_Pnm( 11, 6, 3, PORT_e_IO_INOUT );	/* P11_6 CSIH3SO/DCS */
R_PORT_SetAlt_Pnm( 10, 13, 6, PORT_e_IO_INOUT );	/* P10_13 CSIH3SO/DCS */
R_PORT_SetAlt_Pnm( 10, 15, 1, PORT_e_IO_IN );	/* P10_15 CSIH3RYI */
R_PORT_SetAlt_Pnm( 10, 15, 1, PORT_e_IO_OUT );	/* P10_15 CSIH3RYO */
R_PORT_SetAlt_Pnm( 11, 7, 3, PORT_e_IO_IN );	/* P11_7 CSIH3SC */
R_PORT_SetAlt_Pnm( 11, 7, 3, PORT_e_IO_OUT );	/* P11_7 CSIH3SC */
R_PORT_SetAlt_Pnm( 11, 1, 12, PORT_e_IO_IN );	/* P11_1 CSIH3SC */
R_PORT_SetAlt_Pnm( 11, 1, 12, PORT_e_IO_OUT );	/* P11_1 CSIH3SC */
R_PORT_SetAlt_Pnm( 11, 5, 3, PORT_e_IO_IN );	/* P11_5 CSIH3SI */
R_PORT_SetAlt_Pnm( 11, 0, 12, PORT_e_IO_IN );	/* P11_0 CSIH3SI */
R_PORT_SetAlt_Pnm( 11, 6, 3, PORT_e_IO_INOUT );	/* P11_6 CSIH3SO/DCS */
R_PORT_SetAlt_Pnm( 10, 13, 6, PORT_e_IO_INOUT );	/* P10_13 CSIH3SO/DCS */
R_PORT_SetAlt_Pnm( 10, 14, 3, PORT_e_IO_IN );	/* P10_14 CSIH3SSI */
R_PORT_SetAlt_Pnm( 2, 2, 1, PORT_e_IO_OUT );	/* P02_2 CSIH4CSS0 */
R_PORT_SetAlt_Pnm( 11, 1, 6, PORT_e_IO_OUT );	/* P11_1 CSIH4CSS0 */
R_PORT_SetAlt_Pnm( 2, 3, 2, PORT_e_IO_OUT );	/* P02_3 CSIH4CSS1 */
R_PORT_SetAlt_Pnm( 11, 0, 6, PORT_e_IO_OUT );	/* P11_0 CSIH4CSS1 */
R_PORT_SetAlt_Pnm( 2, 1, 3, PORT_e_IO_OUT );	/* P02_1 CSIH4CSS2 */
R_PORT_SetAlt_Pnm( 10, 15, 6, PORT_e_IO_OUT );	/* P10_15 CSIH4CSS2 */
R_PORT_SetAlt_Pnm( 2, 0, 3, PORT_e_IO_OUT );	/* P02_0 CSIH4CSS3 */
R_PORT_SetAlt_Pnm( 11, 7, 9, PORT_e_IO_OUT );	/* P11_7 CSIH4CSS3 */
R_PORT_SetAlt_Pnm( 2, 4, 3, PORT_e_IO_INOUT );	/* P02_4 CSIH4SO/DCS */
R_PORT_SetAlt_Pnm( 11, 3, 13, PORT_e_IO_INOUT );	/* P11_3 CSIH4SO/DCS */
R_PORT_SetAlt_Pnm( 1, 14, 3, PORT_e_IO_IN );	/* P01_14 CSIH4RYI */
R_PORT_SetAlt_Pnm( 11, 5, 13, PORT_e_IO_IN );	/* P11_5 CSIH4RYI */
R_PORT_SetAlt_Pnm( 1, 14, 3, PORT_e_IO_OUT );	/* P01_14 CSIH4RYO */
R_PORT_SetAlt_Pnm( 11, 5, 13, PORT_e_IO_OUT );	/* P11_5 CSIH4RYO */
R_PORT_SetAlt_Pnm( 1, 5, 4, PORT_e_IO_IN );	/* P01_5 CSIH4SC */
R_PORT_SetAlt_Pnm( 1, 5, 4, PORT_e_IO_OUT );	/* P01_5 CSIH4SC */
R_PORT_SetAlt_Pnm( 11, 4, 13, PORT_e_IO_IN );	/* P11_4 CSIH4SC */
R_PORT_SetAlt_Pnm( 11, 4, 13, PORT_e_IO_OUT );	/* P11_4 CSIH4SC */
R_PORT_SetAlt_Pnm( 1, 4, 4, PORT_e_IO_IN );	/* P01_4 CSIH4SI */
R_PORT_SetAlt_Pnm( 11, 2, 5, PORT_e_IO_IN );	/* P11_2 CSIH4SI */
R_PORT_SetAlt_Pnm( 2, 4, 3, PORT_e_IO_INOUT );	/* P02_4 CSIH4SO/DCS */
R_PORT_SetAlt_Pnm( 11, 3, 13, PORT_e_IO_INOUT );	/* P11_3 CSIH4SO/DCS */
R_PORT_SetAlt_Pnm( 2, 5, 2, PORT_e_IO_IN );	/* P02_5 CSIH4SSI */
R_PORT_SetAlt_Pnm( 11, 6, 9, PORT_e_IO_IN );	/* P11_6 CSIH4SSI */
R_PORT_SetAlt_Pnm( 10, 7, 11, PORT_e_IO_OUT );	/* P10_7 CSIH5CSS0 */
R_PORT_SetAlt_Pnm( 10, 8, 11, PORT_e_IO_OUT );	/* P10_8 CSIH5CSS1 */
R_PORT_SetAlt_Pnm( 11, 10, 5, PORT_e_IO_OUT );	/* P11_10 CSIH5CSS2 */
R_PORT_SetAlt_Pnm( 11, 2, 8, PORT_e_IO_OUT );	/* P11_2 CSIH5CSS2 */
R_PORT_SetAlt_Pnm( 11, 11, 5, PORT_e_IO_OUT );	/* P11_11 CSIH5CSS3 */
R_PORT_SetAlt_Pnm( 11, 3, 8, PORT_e_IO_OUT );	/* P11_3 CSIH5CSS3 */
R_PORT_SetAlt_Pnm( 11, 8, 5, PORT_e_IO_INOUT );	/* P11_8 CSIH5SO/DCS */
R_PORT_SetAlt_Pnm( 10, 15, 8, PORT_e_IO_INOUT );	/* P10_15 CSIH5SO/DCS */
R_PORT_SetAlt_Pnm( 10, 6, 11, PORT_e_IO_IN );	/* P10_6 CSIH5RYI */
R_PORT_SetAlt_Pnm( 10, 6, 11, PORT_e_IO_OUT );	/* P10_6 CSIH5RYO */
R_PORT_SetAlt_Pnm( 10, 5, 11, PORT_e_IO_IN );	/* P10_5 CSIH5SC */
R_PORT_SetAlt_Pnm( 10, 5, 11, PORT_e_IO_OUT );	/* P10_5 CSIH5SC */
R_PORT_SetAlt_Pnm( 10, 4, 11, PORT_e_IO_IN );	/* P10_4 CSIH5SI */
R_PORT_SetAlt_Pnm( 11, 8, 5, PORT_e_IO_INOUT );	/* P11_8 CSIH5SO/DCS */
R_PORT_SetAlt_Pnm( 10, 15, 8, PORT_e_IO_INOUT );	/* P10_15 CSIH5SO/DCS */
R_PORT_SetAlt_Pnm( 11, 9, 5, PORT_e_IO_IN );	/* P11_9 CSIH5SSI */
R_PORT_SetAlt_Pnm( 11, 0, 8, PORT_e_IO_IN );	/* P11_0 CSIH5SSI */
R_PORT_SetAlt_Pnm( 10, 12, 10, PORT_e_IO_OUT );	/* P10_12 CSIH6CSS0 */
R_PORT_SetAlt_Pnm( 10, 13, 10, PORT_e_IO_OUT );	/* P10_13 CSIH6CSS1 */
R_PORT_SetAlt_Pnm( 11, 2, 11, PORT_e_IO_OUT );	/* P11_2 CSIH6CSS2 */
R_PORT_SetAlt_Pnm( 11, 3, 11, PORT_e_IO_OUT );	/* P11_3 CSIH6CSS3 */
R_PORT_SetAlt_Pnm( 10, 14, 10, PORT_e_IO_INOUT );	/* P10_14 CSIH6SO/DCS */
R_PORT_SetAlt_Pnm( 10, 11, 10, PORT_e_IO_IN );	/* P10_11 CSIH6RYI */
R_PORT_SetAlt_Pnm( 10, 11, 10, PORT_e_IO_OUT );	/* P10_11 CSIH6RYO */
R_PORT_SetAlt_Pnm( 10, 10, 10, PORT_e_IO_IN );	/* P10_10 CSIH6SC */
R_PORT_SetAlt_Pnm( 10, 10, 10, PORT_e_IO_OUT );	/* P10_10 CSIH6SC */
R_PORT_SetAlt_Pnm( 10, 9, 10, PORT_e_IO_IN );	/* P10_9 CSIH6SI */
R_PORT_SetAlt_Pnm( 10, 14, 10, PORT_e_IO_INOUT );	/* P10_14 CSIH6SO/DCS */
R_PORT_SetAlt_Pnm( 11, 1, 11, PORT_e_IO_IN );	/* P11_1 CSIH6SSI */
R_PORT_SetAlt_Pnm( 10, 1, 6, PORT_e_IO_OUT );	/* P10_1 CSIH7CSS0 */
R_PORT_SetAlt_Pnm( 10, 2, 6, PORT_e_IO_OUT );	/* P10_2 CSIH7CSS1 */
R_PORT_SetAlt_Pnm( 10, 3, 6, PORT_e_IO_OUT );	/* P10_3 CSIH7CSS2 */
R_PORT_SetAlt_Pnm( 10, 4, 6, PORT_e_IO_OUT );	/* P10_4 CSIH7CSS3 */
R_PORT_SetAlt_Pnm( 11, 5, 5, PORT_e_IO_INOUT );	/* P11_5 CSIH7SO/DCS */
R_PORT_SetAlt_Pnm( 11, 7, 5, PORT_e_IO_IN );	/* P11_7 CSIH7RYI */
R_PORT_SetAlt_Pnm( 11, 7, 5, PORT_e_IO_OUT );	/* P11_7 CSIH7RYO */
R_PORT_SetAlt_Pnm( 11, 6, 5, PORT_e_IO_IN );	/* P11_6 CSIH7SC */
R_PORT_SetAlt_Pnm( 11, 6, 5, PORT_e_IO_OUT );	/* P11_6 CSIH7SC */
R_PORT_SetAlt_Pnm( 11, 4, 5, PORT_e_IO_IN );	/* P11_4 CSIH7SI */
R_PORT_SetAlt_Pnm( 11, 5, 5, PORT_e_IO_INOUT );	/* P11_5 CSIH7SO/DCS */
R_PORT_SetAlt_Pnm( 10, 0, 6, PORT_e_IO_IN );	/* P10_0 CSIH7SSI */
R_PORT_SetAlt_Pnm( 10, 10, 6, PORT_e_IO_OUT );	/* P10_10 CXP10TX */
R_PORT_SetAlt_Pnm( 0, 5, 6, PORT_e_IO_OUT );	/* P00_5 CXP11TX */
R_PORT_SetAlt_Pnm( 10, 12, 6, PORT_e_IO_OUT );	/* P10_12 CXP11TX */
R_PORT_SetAlt_Pnm( 0, 14, 6, PORT_e_IO_OUT );	/* P00_14 CXP12TX */
R_PORT_SetAlt_Pnm( 10, 14, 6, PORT_e_IO_OUT );	/* P10_14 CXP12TX */
R_PORT_SetAlt_Pnm( 11, 3, 7, PORT_e_IO_OUT );	/* P11_3 CXP12TX */
R_PORT_SetAlt_Pnm( 1, 1, 2, PORT_e_IO_OUT );	/* P01_1 CXP13TX */
R_PORT_SetAlt_Pnm( 11, 5, 7, PORT_e_IO_OUT );	/* P11_5 CXP13TX */
R_PORT_SetAlt_Pnm( 8, 1, 2, PORT_e_IO_IN );	/* P08_1 DPIN0 */
R_PORT_SetAlt_Pnm( 0, 3, 3, PORT_e_IO_IN );	/* P00_3 DPIN1 */
R_PORT_SetAlt_Pnm( 0, 6, 2, PORT_e_IO_IN );	/* P00_6 DPIN10 */
R_PORT_SetAlt_Pnm( 0, 10, 2, PORT_e_IO_IN );	/* P00_10 DPIN11 */
R_PORT_SetAlt_Pnm( 0, 11, 2, PORT_e_IO_IN );	/* P00_11 DPIN12 */
R_PORT_SetAlt_Pnm( 0, 12, 2, PORT_e_IO_IN );	/* P00_12 DPIN13 */
R_PORT_SetAlt_Pnm( 8, 10, 2, PORT_e_IO_IN );	/* P08_10 DPIN14 */
R_PORT_SetAlt_Pnm( 8, 11, 2, PORT_e_IO_IN );	/* P08_11 DPIN15 */
R_PORT_SetAlt_Pnm( 8, 12, 2, PORT_e_IO_IN );	/* P08_12 DPIN16 */
R_PORT_SetAlt_Pnm( 1, 5, 2, PORT_e_IO_IN );	/* P01_5 DPIN17 */
R_PORT_SetAlt_Pnm( 1, 4, 3, PORT_e_IO_IN );	/* P01_4 DPIN18 */
R_PORT_SetAlt_Pnm( 1, 2, 3, PORT_e_IO_IN );	/* P01_2 DPIN19 */
R_PORT_SetAlt_Pnm( 8, 0, 2, PORT_e_IO_IN );	/* P08_0 DPIN2 */
R_PORT_SetAlt_Pnm( 8, 2, 2, PORT_e_IO_IN );	/* P08_2 DPIN2 */
R_PORT_SetAlt_Pnm( 1, 9, 2, PORT_e_IO_IN );	/* P01_9 DPIN20 */
R_PORT_SetAlt_Pnm( 1, 10, 2, PORT_e_IO_IN );	/* P01_10 DPIN21 */
R_PORT_SetAlt_Pnm( 1, 11, 2, PORT_e_IO_IN );	/* P01_11 DPIN22 */
R_PORT_SetAlt_Pnm( 1, 3, 2, PORT_e_IO_IN );	/* P01_3 DPIN23 */
R_PORT_SetAlt_Pnm( 8, 3, 2, PORT_e_IO_IN );	/* P08_3 DPIN3 */
R_PORT_SetAlt_Pnm( 8, 4, 2, PORT_e_IO_IN );	/* P08_4 DPIN4 */
R_PORT_SetAlt_Pnm( 0, 7, 2, PORT_e_IO_IN );	/* P00_7 DPIN5 */
R_PORT_SetAlt_Pnm( 0, 8, 2, PORT_e_IO_IN );	/* P00_8 DPIN6 */
R_PORT_SetAlt_Pnm( 0, 9, 2, PORT_e_IO_IN );	/* P00_9 DPIN7 */
R_PORT_SetAlt_Pnm( 0, 4, 4, PORT_e_IO_IN );	/* P00_4 DPIN8 */
R_PORT_SetAlt_Pnm( 0, 5, 2, PORT_e_IO_IN );	/* P00_5 DPIN9 */
R_PORT_SetAlt_Pnm( 0, 0, 4, PORT_e_IO_OUT );	/* P00_0 DPO */
R_PORT_SetAlt_Pnm( 0, 2, 5, PORT_e_IO_OUT );	/* P00_2 DPO */
R_PORT_SetAlt_Pnm( 10, 9, 3, PORT_e_IO_IN );	/* P10_9 ENCA0E0 */
R_PORT_SetAlt_Pnm( 10, 10, 3, PORT_e_IO_IN );	/* P10_10 ENCA0E1 */
R_PORT_SetAlt_Pnm( 10, 8, 3, PORT_e_IO_IN );	/* P10_8 ENCA0EC */
R_PORT_SetAlt_Pnm( 10, 6, 3, PORT_e_IO_IN );	/* P10_6 ENCA0TIN0 */
R_PORT_SetAlt_Pnm( 10, 7, 3, PORT_e_IO_IN );	/* P10_7 ENCA0TIN1 */
R_PORT_SetAlt_Pnm( 9, 1, 3, PORT_e_IO_IN );	/* P09_1 ERRORIN */
R_PORT_SetAlt_Pnm( 10, 13, 3, PORT_e_IO_IN );	/* P10_13 ERRORIN */
R_PORT_SetAlt_Pnm( 8, 2, 5, PORT_e_IO_IN );	/* P08_2 ERRORIN */
R_PORT_SetAlt_Pnm( 10, 4, 5, PORT_e_IO_IN );	/* P10_4 ERRORIN */
R_PORT_SetAlt_Pnm( 9, 2, 3, PORT_e_IO_OUT );	/* P09_2 ERROROUT */
R_PORT_SetAlt_Pnm( 10, 5, 3, PORT_e_IO_OUT );	/* P10_5 ERROROUT */
R_PORT_SetAlt_Pnm( 10, 14, 3, PORT_e_IO_OUT );	/* P10_14 ERROROUT */
R_PORT_SetAlt_Pnm( 8, 3, 5, PORT_e_IO_OUT );	/* P08_3 ERROROUT */
R_PORT_SetAlt_Pnm( 10, 14, 9, PORT_e_IO_OUT );	/* P10_14 ETH_PPS0 */
R_PORT_SetAlt_Pnm( 11, 1, 9, PORT_e_IO_OUT );	/* P11_1 ETH_PPS1 */
R_PORT_SetAlt_Pnm( 10, 13, 9, PORT_e_IO_IN );	/* P10_13 ETH0_LINKSTA */
R_PORT_SetAlt_Pnm( 10, 8, 9, PORT_e_IO_OUT );	/* P10_8 ETH0_MDC */
R_PORT_SetAlt_Pnm( 10, 7, 9, PORT_e_IO_INOUT );	/* P10_7 ETH0_MDIO */
R_PORT_SetAlt_Pnm( 10, 11, 9, PORT_e_IO_IN );	/* P10_11 ETH0_MII_RX_CLK */
R_PORT_SetAlt_Pnm( 11, 5, 9, PORT_e_IO_IN );	/* P11_5 ETH0_MII_RX_DV */
R_PORT_SetAlt_Pnm( 11, 2, 9, PORT_e_IO_IN );	/* P11_2 ETH0_MII_RX_ER */
R_PORT_SetAlt_Pnm( 11, 4, 9, PORT_e_IO_IN );	/* P11_4 ETH0_MII_RXD0 */
R_PORT_SetAlt_Pnm( 11, 3, 9, PORT_e_IO_IN );	/* P11_3 ETH0_MII_RXD1 */
R_PORT_SetAlt_Pnm( 10, 10, 9, PORT_e_IO_IN );	/* P10_10 ETH0_MII_RXD2 */
R_PORT_SetAlt_Pnm( 10, 9, 9, PORT_e_IO_IN );	/* P10_9 ETH0_MII_RXD3 */
R_PORT_SetAlt_Pnm( 10, 5, 9, PORT_e_IO_IN );	/* P10_5 ETH0_MII_TX_CLK */
R_PORT_SetAlt_Pnm( 10, 2, 9, PORT_e_IO_OUT );	/* P10_2 ETH0_MII_TX_EN */
R_PORT_SetAlt_Pnm( 10, 6, 9, PORT_e_IO_OUT );	/* P10_6 ETH0_MII_TX_ER */
R_PORT_SetAlt_Pnm( 10, 4, 9, PORT_e_IO_OUT );	/* P10_4 ETH0_MII_TXD0 */
R_PORT_SetAlt_Pnm( 10, 3, 9, PORT_e_IO_OUT );	/* P10_3 ETH0_MII_TXD1 */
R_PORT_SetAlt_Pnm( 10, 1, 9, PORT_e_IO_OUT );	/* P10_1 ETH0_MII_TXD2 */
R_PORT_SetAlt_Pnm( 10, 0, 9, PORT_e_IO_OUT );	/* P10_0 ETH0_MII_TXD3 */
R_PORT_SetAlt_Pnm( 10, 12, 9, PORT_e_IO_IN );	/* P10_12 ETH0_PHY_INT */
R_PORT_SetAlt_Pnm( 10, 5, 10, PORT_e_IO_OUT );	/* P10_5 ETH0_RevMII_CLK */
R_PORT_SetAlt_Pnm( 11, 2, 10, PORT_e_IO_IN );	/* P11_2 ETH0_RMII_ER */
R_PORT_SetAlt_Pnm( 11, 5, 10, PORT_e_IO_IN );	/* P11_5 ETH0_RMII_RX_DV */
R_PORT_SetAlt_Pnm( 11, 4, 10, PORT_e_IO_IN );	/* P11_4 ETH0_RMII_RXD0 */
R_PORT_SetAlt_Pnm( 11, 3, 10, PORT_e_IO_IN );	/* P11_3 ETH0_RMII_RXD1 */
R_PORT_SetAlt_Pnm( 11, 6, 10, PORT_e_IO_OUT );	/* P11_6 ETH0_RMII_TX_EN */
R_PORT_SetAlt_Pnm( 10, 4, 10, PORT_e_IO_OUT );	/* P10_4 ETH0_RMII_TXD0 */
R_PORT_SetAlt_Pnm( 10, 3, 10, PORT_e_IO_OUT );	/* P10_3 ETH0_RMII_TXD1 */
R_PORT_SetAlt_Pnm( 10, 1, 11, PORT_e_IO_INOUT );	/* P10_1 ETS0_ED_MDIO */
R_PORT_SetAlt_Pnm( 10, 12, 11, PORT_e_IO_OUT );	/* P10_12 ETS0_MDC */
R_PORT_SetAlt_Pnm( 10, 13, 11, PORT_e_IO_INOUT );	/* P10_13 ETS0_MDIO */
R_PORT_SetAlt_Pnm( 10, 14, 11, PORT_e_IO_OUT );	/* P10_14 ETS0_PPS */
R_PORT_SetAlt_Pnm( 10, 0, 11, PORT_e_IO_INOUT );	/* P10_0 ETS0_RX_MDC */
R_PORT_SetAlt_Pnm( 10, 2, 11, PORT_e_IO_OUT );	/* P10_2 ETS0_TX */
R_PORT_SetAlt_Pnm( 0, 7, 2, PORT_e_IO_OUT );	/* P00_7 EXTCLK0O */
R_PORT_SetAlt_Pnm( 8, 4, 4, PORT_e_IO_OUT );	/* P08_4 EXTCLK0O */
R_PORT_SetAlt_Pnm( 0, 0, 6, PORT_e_IO_OUT );	/* P00_0 EXTCLK0O */
R_PORT_SetAlt_Pnm( 10, 0, 2, PORT_e_IO_OUT );	/* P10_0 EXTCLK1O */
R_PORT_SetAlt_Pnm( 9, 2, 4, PORT_e_IO_OUT );	/* P09_2 EXTCLK1O */
R_PORT_SetAlt_Pnm( 10, 3, 5, PORT_e_IO_OUT );	/* P10_3 EXTCLK1O */
R_PORT_SetAlt_JPnm( 0, 2, 3, PORT_e_IO_IN );	/* JP0_2 FPCK */
R_PORT_SetAlt_JPnm( 0, 0, 3, PORT_e_IO_IN );	/* JP0_0 FPDR */
R_PORT_SetAlt_JPnm( 0, 1, 3, PORT_e_IO_OUT );	/* JP0_1 FPDT */
R_PORT_SetAlt_JPnm( 0, 0, 1, PORT_e_IO_IN );	/* JP0_0 IRQ0 */
R_PORT_SetAlt_Pnm( 0, 1, 3, PORT_e_IO_IN );	/* P00_1 IRQ0 */
R_PORT_SetAlt_JPnm( 0, 1, 1, PORT_e_IO_IN );	/* JP0_1 IRQ1 */
R_PORT_SetAlt_Pnm( 0, 2, 5, PORT_e_IO_IN );	/* P00_2 IRQ1 */
R_PORT_SetAlt_Pnm( 0, 3, 5, PORT_e_IO_IN );	/* P00_3 IRQ10 */
R_PORT_SetAlt_Pnm( 9, 1, 1, PORT_e_IO_IN );	/* P09_1 IRQ11 */
R_PORT_SetAlt_Pnm( 0, 4, 2, PORT_e_IO_IN );	/* P00_4 IRQ11 */
R_PORT_SetAlt_Pnm( 0, 9, 1, PORT_e_IO_IN );	/* P00_9 IRQ12 */
R_PORT_SetAlt_Pnm( 0, 13, 2, PORT_e_IO_IN );	/* P00_13 IRQ12 */
R_PORT_SetAlt_Pnm( 1, 0, 2, PORT_e_IO_IN );	/* P01_0 IRQ13 */
R_PORT_SetAlt_Pnm( 0, 12, 4, PORT_e_IO_IN );	/* P00_12 IRQ13 */
R_PORT_SetAlt_Pnm( 0, 7, 1, PORT_e_IO_IN );	/* P00_7 IRQ14 */
R_PORT_SetAlt_Pnm( 1, 8, 2, PORT_e_IO_IN );	/* P01_8 IRQ14 */
R_PORT_SetAlt_Pnm( 1, 11, 3, PORT_e_IO_IN );	/* P01_11 IRQ14 */
R_PORT_SetAlt_Pnm( 0, 0, 2, PORT_e_IO_IN );	/* P00_0 IRQ15 */
R_PORT_SetAlt_Pnm( 1, 4, 2, PORT_e_IO_IN );	/* P01_4 IRQ15 */
R_PORT_SetAlt_Pnm( 0, 8, 1, PORT_e_IO_IN );	/* P00_8 IRQ16 */
R_PORT_SetAlt_Pnm( 9, 3, 4, PORT_e_IO_IN );	/* P09_3 IRQ16 */
R_PORT_SetAlt_Pnm( 10, 0, 10, PORT_e_IO_IN );	/* P10_0 IRQ16 */
R_PORT_SetAlt_Pnm( 0, 14, 1, PORT_e_IO_IN );	/* P00_14 IRQ17 */
R_PORT_SetAlt_Pnm( 9, 4, 4, PORT_e_IO_IN );	/* P09_4 IRQ17 */
R_PORT_SetAlt_Pnm( 1, 1, 1, PORT_e_IO_IN );	/* P01_1 IRQ18 */
R_PORT_SetAlt_Pnm( 10, 1, 2, PORT_e_IO_IN );	/* P10_1 IRQ18 */
R_PORT_SetAlt_Pnm( 1, 3, 1, PORT_e_IO_IN );	/* P01_3 IRQ19 */
R_PORT_SetAlt_Pnm( 12, 2, 1, PORT_e_IO_IN );	/* P12_2 IRQ19 */
R_PORT_SetAlt_Pnm( 11, 6, 6, PORT_e_IO_IN );	/* P11_6 IRQ19 */
R_PORT_SetAlt_Pnm( 0, 6, 1, PORT_e_IO_IN );	/* P00_6 IRQ2 */
R_PORT_SetAlt_JPnm( 0, 2, 1, PORT_e_IO_IN );	/* JP0_2 IRQ2 */
R_PORT_SetAlt_Pnm( 1, 5, 3, PORT_e_IO_IN );	/* P01_5 IRQ20 */
R_PORT_SetAlt_Pnm( 11, 1, 3, PORT_e_IO_IN );	/* P11_1 IRQ20 */
R_PORT_SetAlt_Pnm( 11, 4, 2, PORT_e_IO_IN );	/* P11_4 IRQ21 */
R_PORT_SetAlt_Pnm( 1, 9, 3, PORT_e_IO_IN );	/* P01_9 IRQ21 */
R_PORT_SetAlt_Pnm( 20, 4, 2, PORT_e_IO_IN );	/* P20_4 IRQ22 */
R_PORT_SetAlt_Pnm( 1, 10, 3, PORT_e_IO_IN );	/* P01_10 IRQ22 */
R_PORT_SetAlt_Pnm( 11, 5, 8, PORT_e_IO_IN );	/* P11_5 IRQ22 */
R_PORT_SetAlt_Pnm( 10, 15, 9, PORT_e_IO_IN );	/* P10_15 IRQ22 */
R_PORT_SetAlt_Pnm( 20, 5, 2, PORT_e_IO_IN );	/* P20_5 IRQ23 */
R_PORT_SetAlt_Pnm( 8, 12, 4, PORT_e_IO_IN );	/* P08_12 IRQ23 */
R_PORT_SetAlt_Pnm( 11, 0, 9, PORT_e_IO_IN );	/* P11_0 IRQ23 */
R_PORT_SetAlt_Pnm( 10, 12, 2, PORT_e_IO_IN );	/* P10_12 IRQ24 */
R_PORT_SetAlt_Pnm( 21, 0, 2, PORT_e_IO_IN );	/* P21_0 IRQ25 */
R_PORT_SetAlt_Pnm( 0, 10, 1, PORT_e_IO_IN );	/* P00_10 IRQ3 */
R_PORT_SetAlt_JPnm( 0, 3, 1, PORT_e_IO_IN );	/* JP0_3 IRQ3 */
R_PORT_SetAlt_Pnm( 1, 2, 2, PORT_e_IO_IN );	/* P01_2 IRQ3 */
R_PORT_SetAlt_Pnm( 1, 12, 2, PORT_e_IO_IN );	/* P01_12 IRQ4 */
R_PORT_SetAlt_Pnm( 0, 11, 3, PORT_e_IO_IN );	/* P00_11 IRQ4 */
R_PORT_SetAlt_Pnm( 8, 0, 3, PORT_e_IO_IN );	/* P08_0 IRQ4 */
R_PORT_SetAlt_Pnm( 11, 7, 1, PORT_e_IO_IN );	/* P11_7 IRQ5 */
R_PORT_SetAlt_Pnm( 8, 1, 3, PORT_e_IO_IN );	/* P08_1 IRQ5 */
R_PORT_SetAlt_Pnm( 8, 2, 3, PORT_e_IO_IN );	/* P08_2 IRQ6 */
R_PORT_SetAlt_Pnm( 8, 3, 3, PORT_e_IO_IN );	/* P08_3 IRQ7 */
R_PORT_SetAlt_Pnm( 8, 4, 3, PORT_e_IO_IN );	/* P08_4 IRQ8 */
R_PORT_SetAlt_Pnm( 0, 5, 4, PORT_e_IO_IN );	/* P00_5 IRQ8 */
R_PORT_SetAlt_Pnm( 8, 5, 3, PORT_e_IO_IN );	/* P08_5 IRQ9 */
R_PORT_SetAlt_Pnm( 0, 4, 8, PORT_e_IO_OUT );	/* P00_4 LPSTMOUT0 */
R_PORT_SetAlt_Pnm( 0, 5, 8, PORT_e_IO_OUT );	/* P00_5 LPSTMOUT1 */
R_PORT_SetAlt_Pnm( 0, 6, 8, PORT_e_IO_OUT );	/* P00_6 LPSTMOUT2 */
R_PORT_SetAlt_Pnm( 0, 0, 8, PORT_e_IO_OUT );	/* P00_0 LPSTMOUT3 */
R_PORT_SetAlt_Pnm( 0, 1, 8, PORT_e_IO_OUT );	/* P00_1 LPSTMOUT4 */
R_PORT_SetAlt_Pnm( 10, 6, 8, PORT_e_IO_OUT );	/* P10_6 MMCA0CLK */
R_PORT_SetAlt_Pnm( 11, 1, 8, PORT_e_IO_INOUT );	/* P11_1 MMCA0CMD */
R_PORT_SetAlt_Pnm( 10, 7, 8, PORT_e_IO_INOUT );	/* P10_7 MMCA0DAT0 */
R_PORT_SetAlt_Pnm( 10, 8, 8, PORT_e_IO_INOUT );	/* P10_8 MMCA0DAT1 */
R_PORT_SetAlt_Pnm( 10, 9, 8, PORT_e_IO_INOUT );	/* P10_9 MMCA0DAT2 */
R_PORT_SetAlt_Pnm( 10, 10, 8, PORT_e_IO_INOUT );	/* P10_10 MMCA0DAT3 */
R_PORT_SetAlt_Pnm( 10, 11, 8, PORT_e_IO_INOUT );	/* P10_11 MMCA0DAT4 */
R_PORT_SetAlt_Pnm( 10, 12, 8, PORT_e_IO_INOUT );	/* P10_12 MMCA0DAT5 */
R_PORT_SetAlt_Pnm( 10, 13, 8, PORT_e_IO_INOUT );	/* P10_13 MMCA0DAT6 */
R_PORT_SetAlt_Pnm( 10, 14, 8, PORT_e_IO_INOUT );	/* P10_14 MMCA0DAT7 */
R_PORT_SetAlt_Pnm( 9, 0, 1, PORT_e_IO_IN );	/* P09_0 NMI */
R_PORT_SetAlt_JPnm( 0, 5, 1, PORT_e_IO_IN );	/* JP0_5 NMI */
R_PORT_SetAlt_Pnm( 8, 5, 2, PORT_e_IO_IN );	/* P08_5 NMI */
R_PORT_SetAlt_Pnm( 9, 2, 4, PORT_e_IO_IN );	/* P09_2 PSI50RX */
R_PORT_SetAlt_Pnm( 9, 3, 4, PORT_e_IO_OUT );	/* P09_3 PSI50TX */
R_PORT_SetAlt_Pnm( 10, 10, 6, PORT_e_IO_IN );	/* P10_10 PSI51RX */
R_PORT_SetAlt_Pnm( 10, 11, 6, PORT_e_IO_OUT );	/* P10_11 PSI51TX */
R_PORT_SetAlt_Pnm( 10, 0, 3, PORT_e_IO_OUT );	/* P10_0 PWGC0O */
R_PORT_SetAlt_Pnm( 0, 4, 2, PORT_e_IO_OUT );	/* P00_4 PWGC10O */
R_PORT_SetAlt_Pnm( 0, 0, 3, PORT_e_IO_OUT );	/* P00_0 PWGC10O */
R_PORT_SetAlt_Pnm( 0, 1, 3, PORT_e_IO_OUT );	/* P00_1 PWGC11O */
R_PORT_SetAlt_Pnm( 0, 2, 3, PORT_e_IO_OUT );	/* P00_2 PWGC12O */
R_PORT_SetAlt_Pnm( 0, 3, 3, PORT_e_IO_OUT );	/* P00_3 PWGC13O */
R_PORT_SetAlt_Pnm( 8, 0, 2, PORT_e_IO_OUT );	/* P08_0 PWGC14O */
R_PORT_SetAlt_Pnm( 8, 1, 2, PORT_e_IO_OUT );	/* P08_1 PWGC15O */
R_PORT_SetAlt_Pnm( 10, 11, 1, PORT_e_IO_OUT );	/* P10_11 PWGC16O */
R_PORT_SetAlt_Pnm( 10, 12, 1, PORT_e_IO_OUT );	/* P10_12 PWGC17O */
R_PORT_SetAlt_Pnm( 10, 13, 1, PORT_e_IO_OUT );	/* P10_13 PWGC18O */
R_PORT_SetAlt_Pnm( 10, 14, 1, PORT_e_IO_OUT );	/* P10_14 PWGC19O */
R_PORT_SetAlt_Pnm( 10, 1, 3, PORT_e_IO_OUT );	/* P10_1 PWGC1O */
R_PORT_SetAlt_Pnm( 9, 2, 1, PORT_e_IO_OUT );	/* P09_2 PWGC20O */
R_PORT_SetAlt_Pnm( 9, 0, 8, PORT_e_IO_OUT );	/* P09_0 PWGC20O */
R_PORT_SetAlt_Pnm( 9, 3, 1, PORT_e_IO_OUT );	/* P09_3 PWGC21O */
R_PORT_SetAlt_Pnm( 9, 1, 8, PORT_e_IO_OUT );	/* P09_1 PWGC21O */
R_PORT_SetAlt_Pnm( 8, 2, 3, PORT_e_IO_OUT );	/* P08_2 PWGC22O */
R_PORT_SetAlt_Pnm( 8, 3, 3, PORT_e_IO_OUT );	/* P08_3 PWGC23O */
R_PORT_SetAlt_Pnm( 10, 15, 2, PORT_e_IO_OUT );	/* P10_15 PWGC24O */
R_PORT_SetAlt_Pnm( 11, 0, 2, PORT_e_IO_OUT );	/* P11_0 PWGC25O */
R_PORT_SetAlt_Pnm( 11, 1, 3, PORT_e_IO_OUT );	/* P11_1 PWGC26O */
R_PORT_SetAlt_Pnm( 11, 2, 3, PORT_e_IO_OUT );	/* P11_2 PWGC27O */
R_PORT_SetAlt_Pnm( 11, 3, 2, PORT_e_IO_OUT );	/* P11_3 PWGC28O */
R_PORT_SetAlt_Pnm( 11, 4, 2, PORT_e_IO_OUT );	/* P11_4 PWGC29O */
R_PORT_SetAlt_Pnm( 10, 2, 3, PORT_e_IO_OUT );	/* P10_2 PWGC2O */
R_PORT_SetAlt_Pnm( 11, 5, 2, PORT_e_IO_OUT );	/* P11_5 PWGC30O */
R_PORT_SetAlt_Pnm( 11, 0, 4, PORT_e_IO_OUT );	/* P11_0 PWGC30O */
R_PORT_SetAlt_Pnm( 11, 6, 2, PORT_e_IO_OUT );	/* P11_6 PWGC31O */
R_PORT_SetAlt_Pnm( 11, 1, 4, PORT_e_IO_OUT );	/* P11_1 PWGC31O */
R_PORT_SetAlt_Pnm( 11, 7, 2, PORT_e_IO_OUT );	/* P11_7 PWGC32O */
R_PORT_SetAlt_Pnm( 9, 4, 2, PORT_e_IO_OUT );	/* P09_4 PWGC33O */
R_PORT_SetAlt_Pnm( 0, 11, 4, PORT_e_IO_OUT );	/* P00_11 PWGC34O */
R_PORT_SetAlt_Pnm( 0, 6, 5, PORT_e_IO_OUT );	/* P00_6 PWGC35O */
R_PORT_SetAlt_Pnm( 8, 4, 3, PORT_e_IO_OUT );	/* P08_4 PWGC36O */
R_PORT_SetAlt_Pnm( 8, 5, 3, PORT_e_IO_OUT );	/* P08_5 PWGC37O */
R_PORT_SetAlt_Pnm( 27, 0, 2, PORT_e_IO_OUT );	/* P27_0 PWGC38O */
R_PORT_SetAlt_Pnm( 8, 7, 2, PORT_e_IO_OUT );	/* P08_7 PWGC39O */
R_PORT_SetAlt_Pnm( 10, 3, 3, PORT_e_IO_OUT );	/* P10_3 PWGC3O */
R_PORT_SetAlt_Pnm( 8, 8, 2, PORT_e_IO_OUT );	/* P08_8 PWGC40O */
R_PORT_SetAlt_Pnm( 8, 9, 2, PORT_e_IO_OUT );	/* P08_9 PWGC41O */
R_PORT_SetAlt_Pnm( 8, 10, 2, PORT_e_IO_OUT );	/* P08_10 PWGC42O */
R_PORT_SetAlt_Pnm( 8, 11, 2, PORT_e_IO_OUT );	/* P08_11 PWGC43O */
R_PORT_SetAlt_Pnm( 8, 12, 2, PORT_e_IO_OUT );	/* P08_12 PWGC44O */
R_PORT_SetAlt_Pnm( 0, 12, 2, PORT_e_IO_OUT );	/* P00_12 PWGC45O */
R_PORT_SetAlt_Pnm( 0, 13, 2, PORT_e_IO_OUT );	/* P00_13 PWGC46O */
R_PORT_SetAlt_Pnm( 0, 14, 2, PORT_e_IO_OUT );	/* P00_14 PWGC47O */
R_PORT_SetAlt_Pnm( 11, 8, 2, PORT_e_IO_OUT );	/* P11_8 PWGC48O */
R_PORT_SetAlt_Pnm( 11, 9, 2, PORT_e_IO_OUT );	/* P11_9 PWGC49O */
R_PORT_SetAlt_Pnm( 10, 7, 3, PORT_e_IO_OUT );	/* P10_7 PWGC4O */
R_PORT_SetAlt_Pnm( 11, 10, 2, PORT_e_IO_OUT );	/* P11_10 PWGC50O */
R_PORT_SetAlt_Pnm( 11, 11, 2, PORT_e_IO_OUT );	/* P11_11 PWGC51O */
R_PORT_SetAlt_Pnm( 11, 12, 2, PORT_e_IO_OUT );	/* P11_12 PWGC52O */
R_PORT_SetAlt_Pnm( 10, 4, 5, PORT_e_IO_OUT );	/* P10_4 PWGC53O */
R_PORT_SetAlt_Pnm( 10, 5, 6, PORT_e_IO_OUT );	/* P10_5 PWGC54O */
R_PORT_SetAlt_Pnm( 11, 15, 2, PORT_e_IO_OUT );	/* P11_15 PWGC55O */
R_PORT_SetAlt_Pnm( 12, 0, 2, PORT_e_IO_OUT );	/* P12_0 PWGC56O */
R_PORT_SetAlt_Pnm( 12, 1, 2, PORT_e_IO_OUT );	/* P12_1 PWGC57O */
R_PORT_SetAlt_Pnm( 12, 2, 2, PORT_e_IO_OUT );	/* P12_2 PWGC58O */
R_PORT_SetAlt_Pnm( 20, 4, 2, PORT_e_IO_OUT );	/* P20_4 PWGC59O */
R_PORT_SetAlt_Pnm( 10, 8, 3, PORT_e_IO_OUT );	/* P10_8 PWGC5O */
R_PORT_SetAlt_Pnm( 20, 5, 2, PORT_e_IO_OUT );	/* P20_5 PWGC60O */
R_PORT_SetAlt_Pnm( 18, 0, 2, PORT_e_IO_OUT );	/* P18_0 PWGC61O */
R_PORT_SetAlt_Pnm( 18, 1, 1, PORT_e_IO_OUT );	/* P18_1 PWGC62O */
R_PORT_SetAlt_Pnm( 18, 2, 1, PORT_e_IO_OUT );	/* P18_2 PWGC63O */
R_PORT_SetAlt_Pnm( 20, 0, 2, PORT_e_IO_OUT );	/* P20_0 PWGC64O */
R_PORT_SetAlt_Pnm( 20, 1, 2, PORT_e_IO_OUT );	/* P20_1 PWGC65O */
R_PORT_SetAlt_Pnm( 20, 2, 2, PORT_e_IO_OUT );	/* P20_2 PWGC66O */
R_PORT_SetAlt_Pnm( 20, 3, 2, PORT_e_IO_OUT );	/* P20_3 PWGC67O */
R_PORT_SetAlt_Pnm( 12, 3, 2, PORT_e_IO_OUT );	/* P12_3 PWGC68O */
R_PORT_SetAlt_Pnm( 12, 4, 2, PORT_e_IO_OUT );	/* P12_4 PWGC69O */
R_PORT_SetAlt_Pnm( 10, 9, 3, PORT_e_IO_OUT );	/* P10_9 PWGC6O */
R_PORT_SetAlt_Pnm( 12, 5, 1, PORT_e_IO_OUT );	/* P12_5 PWGC70O */
R_PORT_SetAlt_Pnm( 18, 3, 1, PORT_e_IO_OUT );	/* P18_3 PWGC71O */
R_PORT_SetAlt_Pnm( 13, 6, 2, PORT_e_IO_OUT );	/* P13_6 PWGC72O */
R_PORT_SetAlt_Pnm( 13, 7, 2, PORT_e_IO_OUT );	/* P13_7 PWGC73O */
R_PORT_SetAlt_Pnm( 2, 12, 1, PORT_e_IO_OUT );	/* P02_12 PWGC74O */
R_PORT_SetAlt_Pnm( 2, 13, 1, PORT_e_IO_OUT );	/* P02_13 PWGC75O */
R_PORT_SetAlt_Pnm( 3, 0, 1, PORT_e_IO_OUT );	/* P03_0 PWGC76O */
R_PORT_SetAlt_Pnm( 2, 9, 1, PORT_e_IO_OUT );	/* P02_9 PWGC77O */
R_PORT_SetAlt_Pnm( 2, 10, 1, PORT_e_IO_OUT );	/* P02_10 PWGC78O */
R_PORT_SetAlt_Pnm( 2, 11, 1, PORT_e_IO_OUT );	/* P02_11 PWGC79O */
R_PORT_SetAlt_Pnm( 10, 10, 3, PORT_e_IO_OUT );	/* P10_10 PWGC7O */
R_PORT_SetAlt_Pnm( 3, 1, 1, PORT_e_IO_OUT );	/* P03_1 PWGC80O */
R_PORT_SetAlt_Pnm( 3, 2, 1, PORT_e_IO_OUT );	/* P03_2 PWGC81O */
R_PORT_SetAlt_Pnm( 3, 3, 1, PORT_e_IO_OUT );	/* P03_3 PWGC82O */
R_PORT_SetAlt_Pnm( 3, 4, 1, PORT_e_IO_OUT );	/* P03_4 PWGC83O */
R_PORT_SetAlt_Pnm( 3, 5, 1, PORT_e_IO_OUT );	/* P03_5 PWGC84O */
R_PORT_SetAlt_Pnm( 3, 6, 1, PORT_e_IO_OUT );	/* P03_6 PWGC85O */
R_PORT_SetAlt_Pnm( 3, 7, 1, PORT_e_IO_OUT );	/* P03_7 PWGC86O */
R_PORT_SetAlt_Pnm( 3, 8, 1, PORT_e_IO_OUT );	/* P03_8 PWGC87O */
R_PORT_SetAlt_Pnm( 20, 6, 1, PORT_e_IO_OUT );	/* P20_6 PWGC88O */
R_PORT_SetAlt_Pnm( 20, 7, 1, PORT_e_IO_OUT );	/* P20_7 PWGC89O */
R_PORT_SetAlt_Pnm( 9, 0, 1, PORT_e_IO_OUT );	/* P09_0 PWGC8O */
R_PORT_SetAlt_Pnm( 20, 8, 1, PORT_e_IO_OUT );	/* P20_8 PWGC90O */
R_PORT_SetAlt_Pnm( 20, 9, 1, PORT_e_IO_OUT );	/* P20_9 PWGC91O */
R_PORT_SetAlt_Pnm( 20, 10, 1, PORT_e_IO_OUT );	/* P20_10 PWGC92O */
R_PORT_SetAlt_Pnm( 20, 11, 1, PORT_e_IO_OUT );	/* P20_11 PWGC93O */
R_PORT_SetAlt_Pnm( 20, 12, 1, PORT_e_IO_OUT );	/* P20_12 PWGC94O */
R_PORT_SetAlt_Pnm( 20, 13, 1, PORT_e_IO_OUT );	/* P20_13 PWGC95O */
R_PORT_SetAlt_Pnm( 9, 1, 1, PORT_e_IO_OUT );	/* P09_1 PWGC9O */
R_PORT_SetAlt_Pnm( 10, 3, 2, PORT_e_IO_INOUT );	/* P10_3 RI3C0SCL */
R_PORT_SetAlt_Pnm( 10, 2, 2, PORT_e_IO_INOUT );	/* P10_2 RI3C0SDA */
R_PORT_SetAlt_Pnm( 0, 12, 1, PORT_e_IO_IN );	/* P00_12 RIIC0SCL */
R_PORT_SetAlt_Pnm( 0, 12, 1, PORT_e_IO_OUT );	/* P00_12 RIIC0SCL */
R_PORT_SetAlt_Pnm( 9, 1, 7, PORT_e_IO_IN );	/* P09_1 RIIC0SCL */
R_PORT_SetAlt_Pnm( 9, 1, 7, PORT_e_IO_OUT );	/* P09_1 RIIC0SCL */
R_PORT_SetAlt_Pnm( 0, 11, 1, PORT_e_IO_IN );	/* P00_11 RIIC0SDA */
R_PORT_SetAlt_Pnm( 0, 11, 1, PORT_e_IO_OUT );	/* P00_11 RIIC0SDA */
R_PORT_SetAlt_Pnm( 9, 0, 7, PORT_e_IO_IN );	/* P09_0 RIIC0SDA */
R_PORT_SetAlt_Pnm( 9, 0, 7, PORT_e_IO_OUT );	/* P09_0 RIIC0SDA */
R_PORT_SetAlt_Pnm( 8, 1, 5, PORT_e_IO_IN );	/* P08_1 RIIC1SCL */
R_PORT_SetAlt_Pnm( 8, 1, 5, PORT_e_IO_OUT );	/* P08_1 RIIC1SCL */
R_PORT_SetAlt_Pnm( 8, 0, 5, PORT_e_IO_IN );	/* P08_0 RIIC1SDA */
R_PORT_SetAlt_Pnm( 8, 0, 5, PORT_e_IO_OUT );	/* P08_0 RIIC1SDA */
R_PORT_SetAlt_Pnm( 0, 3, 7, PORT_e_IO_IN );	/* P00_3 RLIN30RX/CXP10RX */
R_PORT_SetAlt_Pnm( 10, 9, 7, PORT_e_IO_IN );	/* P10_9 RLIN30RX/CXP10RX */
R_PORT_SetAlt_Pnm( 0, 3, 2, PORT_e_IO_IN );	/* P00_3 RLIN30RX/IRQ8/CXP10RX */
R_PORT_SetAlt_Pnm( 10, 9, 2, PORT_e_IO_IN );	/* P10_9 RLIN30RX/IRQ8/CXP10RX */
R_PORT_SetAlt_Pnm( 0, 2, 2, PORT_e_IO_OUT );	/* P00_2 RLIN30TX */
R_PORT_SetAlt_Pnm( 10, 10, 2, PORT_e_IO_OUT );	/* P10_10 RLIN30TX */
R_PORT_SetAlt_Pnm( 9, 4, 6, PORT_e_IO_IN );	/* P09_4 RLIN310RX */
R_PORT_SetAlt_Pnm( 9, 4, 5, PORT_e_IO_IN );	/* P09_4 RLIN310RX/IRQ18 */
R_PORT_SetAlt_Pnm( 10, 0, 5, PORT_e_IO_OUT );	/* P10_0 RLIN310TX */
R_PORT_SetAlt_Pnm( 10, 4, 7, PORT_e_IO_IN );	/* P10_4 RLIN311RX */
R_PORT_SetAlt_Pnm( 10, 4, 2, PORT_e_IO_IN );	/* P10_4 RLIN311RX/IRQ19 */
R_PORT_SetAlt_Pnm( 10, 5, 2, PORT_e_IO_OUT );	/* P10_5 RLIN311TX */
R_PORT_SetAlt_Pnm( 10, 14, 7, PORT_e_IO_IN );	/* P10_14 RLIN312RX */
R_PORT_SetAlt_Pnm( 10, 6, 6, PORT_e_IO_IN );	/* P10_6 RLIN312RX/IRQ20 */
R_PORT_SetAlt_Pnm( 10, 7, 6, PORT_e_IO_OUT );	/* P10_7 RLIN312TX */
R_PORT_SetAlt_Pnm( 11, 1, 5, PORT_e_IO_IN );	/* P11_1 RLIN313RX */
R_PORT_SetAlt_Pnm( 11, 1, 2, PORT_e_IO_IN );	/* P11_1 RLIN313RX/IRQ21 */
R_PORT_SetAlt_Pnm( 11, 2, 2, PORT_e_IO_OUT );	/* P11_2 RLIN313TX */
R_PORT_SetAlt_Pnm( 10, 15, 6, PORT_e_IO_IN );	/* P10_15 RLIN314RX */
R_PORT_SetAlt_Pnm( 10, 15, 3, PORT_e_IO_IN );	/* P10_15 RLIN314RX/IRQ22 */
R_PORT_SetAlt_Pnm( 11, 0, 3, PORT_e_IO_OUT );	/* P11_0 RLIN314TX */
R_PORT_SetAlt_Pnm( 11, 10, 6, PORT_e_IO_IN );	/* P11_10 RLIN315RX */
R_PORT_SetAlt_Pnm( 11, 10, 1, PORT_e_IO_IN );	/* P11_10 RLIN315RX/IRQ23 */
R_PORT_SetAlt_Pnm( 11, 11, 1, PORT_e_IO_OUT );	/* P11_11 RLIN315TX */
R_PORT_SetAlt_Pnm( 13, 0, 2, PORT_e_IO_IN );	/* P13_0 RLIN316RX */
R_PORT_SetAlt_Pnm( 13, 0, 1, PORT_e_IO_IN );	/* P13_0 RLIN316RX/IRQ24 */
R_PORT_SetAlt_Pnm( 13, 1, 1, PORT_e_IO_OUT );	/* P13_1 RLIN316TX */
R_PORT_SetAlt_Pnm( 13, 2, 2, PORT_e_IO_IN );	/* P13_2 RLIN317RX */
R_PORT_SetAlt_Pnm( 13, 2, 1, PORT_e_IO_IN );	/* P13_2 RLIN317RX/IRQ25 */
R_PORT_SetAlt_Pnm( 13, 3, 1, PORT_e_IO_OUT );	/* P13_3 RLIN317TX */
R_PORT_SetAlt_Pnm( 0, 4, 7, PORT_e_IO_IN );	/* P00_4 RLIN31RX/CXP11RX */
R_PORT_SetAlt_Pnm( 10, 11, 7, PORT_e_IO_IN );	/* P10_11 RLIN31RX/CXP11RX */
R_PORT_SetAlt_Pnm( 0, 4, 1, PORT_e_IO_IN );	/* P00_4 RLIN31RX/IRQ9/CXP11RX */
R_PORT_SetAlt_Pnm( 10, 11, 2, PORT_e_IO_IN );	/* P10_11 RLIN31RX/IRQ9/CXP11RX */
R_PORT_SetAlt_Pnm( 0, 5, 1, PORT_e_IO_OUT );	/* P00_5 RLIN31TX */
R_PORT_SetAlt_Pnm( 10, 12, 2, PORT_e_IO_OUT );	/* P10_12 RLIN31TX */
R_PORT_SetAlt_Pnm( 10, 13, 7, PORT_e_IO_IN );	/* P10_13 RLIN32RX */
R_PORT_SetAlt_Pnm( 0, 13, 6, PORT_e_IO_IN );	/* P00_13 RLIN32RX/CXP12RX */
R_PORT_SetAlt_Pnm( 10, 13, 7, PORT_e_IO_IN );	/* P10_13 RLIN32RX/CXP12RX */
R_PORT_SetAlt_Pnm( 11, 2, 7, PORT_e_IO_IN );	/* P11_2 RLIN32RX/CXP12RX */
R_PORT_SetAlt_Pnm( 0, 13, 1, PORT_e_IO_IN );	/* P00_13 RLIN32RX/IRQ10 */
R_PORT_SetAlt_Pnm( 10, 13, 2, PORT_e_IO_IN );	/* P10_13 RLIN32RX/IRQ10 */
R_PORT_SetAlt_Pnm( 11, 2, 2, PORT_e_IO_IN );	/* P11_2 RLIN32RX/IRQ10 */
R_PORT_SetAlt_Pnm( 0, 13, 1, PORT_e_IO_IN );	/* P00_13 RLIN32RX/IRQ10/CXP12RX */
R_PORT_SetAlt_Pnm( 10, 13, 2, PORT_e_IO_IN );	/* P10_13 RLIN32RX/IRQ10/CXP12RX */
R_PORT_SetAlt_Pnm( 11, 2, 2, PORT_e_IO_IN );	/* P11_2 RLIN32RX/IRQ10/CXP12RX */
R_PORT_SetAlt_Pnm( 0, 14, 1, PORT_e_IO_OUT );	/* P00_14 RLIN32TX */
R_PORT_SetAlt_Pnm( 10, 14, 2, PORT_e_IO_OUT );	/* P10_14 RLIN32TX */
R_PORT_SetAlt_Pnm( 11, 3, 5, PORT_e_IO_OUT );	/* P11_3 RLIN32TX */
R_PORT_SetAlt_Pnm( 9, 1, 2, PORT_e_IO_IN );	/* P09_1 RLIN33RX/CXP13RX */
R_PORT_SetAlt_Pnm( 1, 0, 7, PORT_e_IO_IN );	/* P01_0 RLIN33RX/CXP13RX */
R_PORT_SetAlt_Pnm( 10, 1, 7, PORT_e_IO_IN );	/* P10_1 RLIN33RX/CXP13RX */
R_PORT_SetAlt_Pnm( 11, 6, 7, PORT_e_IO_IN );	/* P11_6 RLIN33RX/CXP13RX */
R_PORT_SetAlt_Pnm( 1, 0, 1, PORT_e_IO_IN );	/* P01_0 RLIN33RX/IRQ11 */
R_PORT_SetAlt_Pnm( 11, 6, 1, PORT_e_IO_IN );	/* P11_6 RLIN33RX/IRQ11 */
R_PORT_SetAlt_Pnm( 9, 1, 5, PORT_e_IO_IN );	/* P09_1 RLIN33RX/IRQ11 */
R_PORT_SetAlt_Pnm( 10, 1, 6, PORT_e_IO_IN );	/* P10_1 RLIN33RX/IRQ11 */
R_PORT_SetAlt_Pnm( 1, 0, 1, PORT_e_IO_IN );	/* P01_0 RLIN33RX/IRQ11/CXP13RX */
R_PORT_SetAlt_Pnm( 11, 6, 1, PORT_e_IO_IN );	/* P11_6 RLIN33RX/IRQ11/CXP13RX */
R_PORT_SetAlt_Pnm( 9, 1, 5, PORT_e_IO_IN );	/* P09_1 RLIN33RX/IRQ11/CXP13RX */
R_PORT_SetAlt_Pnm( 10, 1, 6, PORT_e_IO_IN );	/* P10_1 RLIN33RX/IRQ11/CXP13RX */
R_PORT_SetAlt_Pnm( 1, 1, 1, PORT_e_IO_OUT );	/* P01_1 RLIN33TX */
R_PORT_SetAlt_Pnm( 11, 5, 1, PORT_e_IO_OUT );	/* P11_5 RLIN33TX */
R_PORT_SetAlt_Pnm( 9, 0, 2, PORT_e_IO_OUT );	/* P09_0 RLIN33TX */
R_PORT_SetAlt_Pnm( 10, 2, 12, PORT_e_IO_OUT );	/* P10_2 RLIN33TX */
R_PORT_SetAlt_Pnm( 10, 14, 6, PORT_e_IO_IN );	/* P10_14 RLIN34RX */
R_PORT_SetAlt_Pnm( 8, 8, 7, PORT_e_IO_IN );	/* P08_8 RLIN34RX */
R_PORT_SetAlt_Pnm( 12, 1, 7, PORT_e_IO_IN );	/* P12_1 RLIN34RX */
R_PORT_SetAlt_Pnm( 1, 8, 1, PORT_e_IO_IN );	/* P01_8 RLIN34RX/IRQ12 */
R_PORT_SetAlt_Pnm( 12, 1, 1, PORT_e_IO_IN );	/* P12_1 RLIN34RX/IRQ12 */
R_PORT_SetAlt_Pnm( 8, 8, 4, PORT_e_IO_IN );	/* P08_8 RLIN34RX/IRQ12 */
R_PORT_SetAlt_Pnm( 10, 14, 4, PORT_e_IO_IN );	/* P10_14 RLIN34RX/IRQ12 */
R_PORT_SetAlt_Pnm( 1, 9, 1, PORT_e_IO_OUT );	/* P01_9 RLIN34TX */
R_PORT_SetAlt_Pnm( 12, 2, 1, PORT_e_IO_OUT );	/* P12_2 RLIN34TX */
R_PORT_SetAlt_Pnm( 8, 9, 4, PORT_e_IO_OUT );	/* P08_9 RLIN34TX */
R_PORT_SetAlt_Pnm( 10, 13, 9, PORT_e_IO_OUT );	/* P10_13 RLIN34TX */
R_PORT_SetAlt_Pnm( 1, 4, 7, PORT_e_IO_IN );	/* P01_4 RLIN35RX */
R_PORT_SetAlt_Pnm( 10, 2, 7, PORT_e_IO_IN );	/* P10_2 RLIN35RX */
R_PORT_SetAlt_Pnm( 11, 9, 7, PORT_e_IO_IN );	/* P11_9 RLIN35RX */
R_PORT_SetAlt_Pnm( 1, 4, 1, PORT_e_IO_IN );	/* P01_4 RLIN35RX/IRQ13 */
R_PORT_SetAlt_Pnm( 11, 9, 2, PORT_e_IO_IN );	/* P11_9 RLIN35RX/IRQ13 */
R_PORT_SetAlt_Pnm( 10, 2, 6, PORT_e_IO_IN );	/* P10_2 RLIN35RX/IRQ13 */
R_PORT_SetAlt_Pnm( 1, 5, 1, PORT_e_IO_OUT );	/* P01_5 RLIN35TX */
R_PORT_SetAlt_Pnm( 11, 8, 1, PORT_e_IO_OUT );	/* P11_8 RLIN35TX */
R_PORT_SetAlt_Pnm( 10, 1, 12, PORT_e_IO_OUT );	/* P10_1 RLIN35TX */
R_PORT_SetAlt_Pnm( 9, 3, 3, PORT_e_IO_IN );	/* P09_3 RLIN36RX */
R_PORT_SetAlt_Pnm( 1, 13, 7, PORT_e_IO_IN );	/* P01_13 RLIN36RX */
R_PORT_SetAlt_Pnm( 12, 0, 7, PORT_e_IO_IN );	/* P12_0 RLIN36RX */
R_PORT_SetAlt_Pnm( 1, 13, 2, PORT_e_IO_IN );	/* P01_13 RLIN36RX/IRQ14 */
R_PORT_SetAlt_Pnm( 9, 3, 2, PORT_e_IO_IN );	/* P09_3 RLIN36RX/IRQ14 */
R_PORT_SetAlt_Pnm( 12, 0, 5, PORT_e_IO_IN );	/* P12_0 RLIN36RX/IRQ14 */
R_PORT_SetAlt_Pnm( 1, 12, 2, PORT_e_IO_OUT );	/* P01_12 RLIN36TX */
R_PORT_SetAlt_Pnm( 11, 15, 5, PORT_e_IO_OUT );	/* P11_15 RLIN36TX */
R_PORT_SetAlt_Pnm( 9, 2, 8, PORT_e_IO_OUT );	/* P09_2 RLIN36TX */
R_PORT_SetAlt_Pnm( 8, 10, 7, PORT_e_IO_IN );	/* P08_10 RLIN37RX */
R_PORT_SetAlt_Pnm( 10, 3, 7, PORT_e_IO_IN );	/* P10_3 RLIN37RX */
R_PORT_SetAlt_Pnm( 8, 10, 4, PORT_e_IO_IN );	/* P08_10 RLIN37RX/IRQ15 */
R_PORT_SetAlt_Pnm( 10, 3, 6, PORT_e_IO_IN );	/* P10_3 RLIN37RX/IRQ15 */
R_PORT_SetAlt_Pnm( 8, 2, 4, PORT_e_IO_OUT );	/* P08_2 RLIN37TX */
R_PORT_SetAlt_Pnm( 10, 2, 7, PORT_e_IO_OUT );	/* P10_2 RLIN37TX */
R_PORT_SetAlt_Pnm( 9, 0, 8, PORT_e_IO_IN );	/* P09_0 RLIN38RX */
R_PORT_SetAlt_Pnm( 9, 0, 4, PORT_e_IO_IN );	/* P09_0 RLIN38RX/IRQ16 */
R_PORT_SetAlt_Pnm( 9, 1, 4, PORT_e_IO_OUT );	/* P09_1 RLIN38TX */
R_PORT_SetAlt_Pnm( 9, 2, 6, PORT_e_IO_IN );	/* P09_2 RLIN39RX */
R_PORT_SetAlt_Pnm( 9, 2, 5, PORT_e_IO_IN );	/* P09_2 RLIN39RX/IRQ17 */
R_PORT_SetAlt_Pnm( 9, 3, 5, PORT_e_IO_OUT );	/* P09_3 RLIN39TX */
R_PORT_SetAlt_Pnm( 8, 0, 6, PORT_e_IO_IN );	/* P08_0 RSENT0RX */
R_PORT_SetAlt_Pnm( 8, 2, 6, PORT_e_IO_IN );	/* P08_2 RSENT0RX */
R_PORT_SetAlt_Pnm( 8, 1, 6, PORT_e_IO_OUT );	/* P08_1 RSENT0SPCO */
R_PORT_SetAlt_Pnm( 8, 2, 6, PORT_e_IO_OUT );	/* P08_2 RSENT0SPCO */
R_PORT_SetAlt_Pnm( 8, 3, 6, PORT_e_IO_OUT );	/* P08_3 RSENT0SPCO */
R_PORT_SetAlt_Pnm( 9, 0, 6, PORT_e_IO_IN );	/* P09_0 RSENT1RX */
R_PORT_SetAlt_Pnm( 9, 0, 6, PORT_e_IO_OUT );	/* P09_0 RSENT1SPCO */
R_PORT_SetAlt_Pnm( 9, 1, 6, PORT_e_IO_OUT );	/* P09_1 RSENT1SPCO */
R_PORT_SetAlt_Pnm( 9, 2, 7, PORT_e_IO_IN );	/* P09_2 RSENT2RX */
R_PORT_SetAlt_Pnm( 9, 2, 7, PORT_e_IO_OUT );	/* P09_2 RSENT2SPCO */
R_PORT_SetAlt_Pnm( 9, 3, 7, PORT_e_IO_OUT );	/* P09_3 RSENT2SPCO */
R_PORT_SetAlt_Pnm( 10, 3, 13, PORT_e_IO_IN );	/* P10_3 RSENT3RX */
R_PORT_SetAlt_Pnm( 10, 4, 3, PORT_e_IO_OUT );	/* P10_4 RSENT3SPCO */
R_PORT_SetAlt_Pnm( 10, 3, 13, PORT_e_IO_OUT );	/* P10_3 RSENT3SPCO */
R_PORT_SetAlt_Pnm( 10, 5, 5, PORT_e_IO_IN );	/* P10_5 RSENT4RX */
R_PORT_SetAlt_Pnm( 10, 5, 5, PORT_e_IO_OUT );	/* P10_5 RSENT4SPCO */
R_PORT_SetAlt_Pnm( 10, 6, 5, PORT_e_IO_OUT );	/* P10_6 RSENT4SPCO */
R_PORT_SetAlt_Pnm( 11, 4, 7, PORT_e_IO_IN );	/* P11_4 RSENT5RX */
R_PORT_SetAlt_Pnm( 11, 4, 7, PORT_e_IO_OUT );	/* P11_4 RSENT5SPCO */
R_PORT_SetAlt_Pnm( 11, 3, 10, PORT_e_IO_OUT );	/* P11_3 RSENT5SPCO */
R_PORT_SetAlt_Pnm( 11, 6, 8, PORT_e_IO_IN );	/* P11_6 RSENT6RX */
R_PORT_SetAlt_Pnm( 11, 6, 8, PORT_e_IO_OUT );	/* P11_6 RSENT6SPCO */
R_PORT_SetAlt_Pnm( 11, 7, 8, PORT_e_IO_OUT );	/* P11_7 RSENT6SPCO */
R_PORT_SetAlt_Pnm( 9, 4, 7, PORT_e_IO_IN );	/* P09_4 RSENT7RX */
R_PORT_SetAlt_Pnm( 9, 4, 7, PORT_e_IO_OUT );	/* P09_4 RSENT7SPCO */
R_PORT_SetAlt_Pnm( 10, 0, 7, PORT_e_IO_OUT );	/* P10_0 RSENT7SPCO */
R_PORT_SetAlt_JPnm( 0, 5, 1, PORT_e_IO_OUT );	/* JP0_5 RTCA0OUT */
R_PORT_SetAlt_Pnm( 27, 0, 3, PORT_e_IO_OUT );	/* P27_0 RTCA0OUT */
R_PORT_SetAlt_Pnm( 8, 7, 4, PORT_e_IO_OUT );	/* P08_7 RTCA0OUT */
R_PORT_SetAlt_Pnm( 0, 4, 3, PORT_e_IO_OUT );	/* P00_4 SELDP0 */
R_PORT_SetAlt_Pnm( 0, 5, 2, PORT_e_IO_OUT );	/* P00_5 SELDP1 */
R_PORT_SetAlt_Pnm( 0, 6, 2, PORT_e_IO_OUT );	/* P00_6 SELDP2 */
R_PORT_SetAlt_Pnm( 11, 7, 6, PORT_e_IO_OUT );	/* P11_7 SFMA0CLK */
R_PORT_SetAlt_Pnm( 11, 5, 6, PORT_e_IO_INOUT );	/* P11_5 SFMA0IO0 */
R_PORT_SetAlt_Pnm( 11, 4, 6, PORT_e_IO_INOUT );	/* P11_4 SFMA0IO1 */
R_PORT_SetAlt_Pnm( 11, 3, 6, PORT_e_IO_INOUT );	/* P11_3 SFMA0IO2 */
R_PORT_SetAlt_Pnm( 11, 2, 6, PORT_e_IO_INOUT );	/* P11_2 SFMA0IO3 */
R_PORT_SetAlt_Pnm( 11, 6, 6, PORT_e_IO_OUT );	/* P11_6 SFMA0SSL */
R_PORT_SetAlt_Pnm( 10, 4, 8, PORT_e_IO_INOUT );	/* P10_4 SSIF0BCK */
R_PORT_SetAlt_Pnm( 10, 5, 8, PORT_e_IO_INOUT );	/* P10_5 SSIF0LRCK/FS */
R_PORT_SetAlt_Pnm( 10, 2, 8, PORT_e_IO_IN );	/* P10_2 SSIF0RXD */
R_PORT_SetAlt_Pnm( 10, 3, 8, PORT_e_IO_INOUT );	/* P10_3 SSIF0TXD */
R_PORT_SetAlt_Pnm( 10, 3, 8, PORT_e_IO_OUT );	/* P10_3 SSIF0TXD */
R_PORT_SetAlt_Pnm( 10, 8, 5, PORT_e_IO_INOUT );	/* P10_8 SSIF1BCK */
R_PORT_SetAlt_Pnm( 10, 9, 5, PORT_e_IO_INOUT );	/* P10_9 SSIF1LRCK/FS */
R_PORT_SetAlt_Pnm( 10, 6, 5, PORT_e_IO_IN );	/* P10_6 SSIF1RXD */
R_PORT_SetAlt_Pnm( 10, 7, 5, PORT_e_IO_INOUT );	/* P10_7 SSIF1TXD */
R_PORT_SetAlt_Pnm( 10, 10, 5, PORT_e_IO_IN );	/* P10_10 SSIFACK */
R_PORT_SetAlt_Pnm( 8, 1, 1, PORT_e_IO_IN );	/* P08_1 TAPA0ESO */
R_PORT_SetAlt_Pnm( 9, 2, 2, PORT_e_IO_IN );	/* P09_2 TAPA0ESO */
R_PORT_SetAlt_Pnm( 10, 1, 4, PORT_e_IO_INOUT );	/* P10_1 TAPA0UN */
R_PORT_SetAlt_Pnm( 10, 0, 4, PORT_e_IO_INOUT );	/* P10_0 TAPA0UP */
R_PORT_SetAlt_Pnm( 10, 3, 4, PORT_e_IO_INOUT );	/* P10_3 TAPA0VN */
R_PORT_SetAlt_Pnm( 10, 2, 4, PORT_e_IO_INOUT );	/* P10_2 TAPA0VP */
R_PORT_SetAlt_Pnm( 10, 5, 4, PORT_e_IO_INOUT );	/* P10_5 TAPA0WN */
R_PORT_SetAlt_Pnm( 10, 4, 4, PORT_e_IO_INOUT );	/* P10_4 TAPA0WP */
R_PORT_SetAlt_Pnm( 9, 0, 2, PORT_e_IO_IN );	/* P09_0 TAUD0I0 */
R_PORT_SetAlt_Pnm( 10, 0, 1, PORT_e_IO_IN );	/* P10_0 TAUD0I1 */
R_PORT_SetAlt_Pnm( 10, 8, 2, PORT_e_IO_IN );	/* P10_8 TAUD0I10 */
R_PORT_SetAlt_Pnm( 10, 5, 3, PORT_e_IO_IN );	/* P10_5 TAUD0I11 */
R_PORT_SetAlt_Pnm( 10, 9, 6, PORT_e_IO_IN );	/* P10_9 TAUD0I12 */
R_PORT_SetAlt_Pnm( 10, 6, 2, PORT_e_IO_IN );	/* P10_6 TAUD0I13 */
R_PORT_SetAlt_Pnm( 10, 10, 2, PORT_e_IO_IN );	/* P10_10 TAUD0I14 */
R_PORT_SetAlt_Pnm( 10, 7, 2, PORT_e_IO_IN );	/* P10_7 TAUD0I15 */
R_PORT_SetAlt_Pnm( 0, 0, 3, PORT_e_IO_IN );	/* P00_0 TAUD0I2 */
R_PORT_SetAlt_Pnm( 9, 1, 4, PORT_e_IO_IN );	/* P09_1 TAUD0I2 */
R_PORT_SetAlt_Pnm( 10, 1, 3, PORT_e_IO_IN );	/* P10_1 TAUD0I3 */
R_PORT_SetAlt_Pnm( 0, 1, 1, PORT_e_IO_IN );	/* P00_1 TAUD0I4 */
R_PORT_SetAlt_Pnm( 10, 2, 3, PORT_e_IO_IN );	/* P10_2 TAUD0I5 */
R_PORT_SetAlt_Pnm( 0, 2, 3, PORT_e_IO_IN );	/* P00_2 TAUD0I6 */
R_PORT_SetAlt_Pnm( 10, 3, 8, PORT_e_IO_IN );	/* P10_3 TAUD0I7 */
R_PORT_SetAlt_Pnm( 0, 3, 1, PORT_e_IO_IN );	/* P00_3 TAUD0I8 */
R_PORT_SetAlt_Pnm( 10, 4, 3, PORT_e_IO_IN );	/* P10_4 TAUD0I9 */
R_PORT_SetAlt_Pnm( 10, 8, 1, PORT_e_IO_OUT );	/* P10_8 TAUD0O0 */
R_PORT_SetAlt_Pnm( 10, 5, 1, PORT_e_IO_OUT );	/* P10_5 TAUD0O1 */
R_PORT_SetAlt_Pnm( 0, 3, 5, PORT_e_IO_OUT );	/* P00_3 TAUD0O10 */
R_PORT_SetAlt_Pnm( 10, 4, 1, PORT_e_IO_OUT );	/* P10_4 TAUD0O11 */
R_PORT_SetAlt_Pnm( 10, 10, 1, PORT_e_IO_OUT );	/* P10_10 TAUD0O12 */
R_PORT_SetAlt_Pnm( 10, 7, 1, PORT_e_IO_OUT );	/* P10_7 TAUD0O13 */
R_PORT_SetAlt_Pnm( 10, 9, 1, PORT_e_IO_OUT );	/* P10_9 TAUD0O14 */
R_PORT_SetAlt_Pnm( 10, 6, 1, PORT_e_IO_OUT );	/* P10_6 TAUD0O15 */
R_PORT_SetAlt_Pnm( 9, 0, 4, PORT_e_IO_OUT );	/* P09_0 TAUD0O2 */
R_PORT_SetAlt_Pnm( 10, 0, 8, PORT_e_IO_OUT );	/* P10_0 TAUD0O3 */
R_PORT_SetAlt_Pnm( 0, 0, 1, PORT_e_IO_OUT );	/* P00_0 TAUD0O4 */
R_PORT_SetAlt_Pnm( 9, 1, 2, PORT_e_IO_OUT );	/* P09_1 TAUD0O4 */
R_PORT_SetAlt_Pnm( 10, 1, 1, PORT_e_IO_OUT );	/* P10_1 TAUD0O5 */
R_PORT_SetAlt_Pnm( 0, 1, 2, PORT_e_IO_OUT );	/* P00_1 TAUD0O6 */
R_PORT_SetAlt_Pnm( 10, 2, 1, PORT_e_IO_OUT );	/* P10_2 TAUD0O7 */
R_PORT_SetAlt_Pnm( 0, 2, 1, PORT_e_IO_OUT );	/* P00_2 TAUD0O8 */
R_PORT_SetAlt_Pnm( 10, 3, 1, PORT_e_IO_OUT );	/* P10_3 TAUD0O9 */
R_PORT_SetAlt_Pnm( 0, 6, 6, PORT_e_IO_IN );	/* P00_6 TAUD1I0 */
R_PORT_SetAlt_Pnm( 10, 11, 5, PORT_e_IO_IN );	/* P10_11 TAUD1I1 */
R_PORT_SetAlt_Pnm( 0, 12, 6, PORT_e_IO_IN );	/* P00_12 TAUD1I10 */
R_PORT_SetAlt_Pnm( 8, 4, 6, PORT_e_IO_IN );	/* P08_4 TAUD1I10 */
R_PORT_SetAlt_Pnm( 11, 2, 4, PORT_e_IO_IN );	/* P11_2 TAUD1I11 */
R_PORT_SetAlt_Pnm( 10, 1, 9, PORT_e_IO_IN );	/* P10_1 TAUD1I11 */
R_PORT_SetAlt_Pnm( 0, 13, 4, PORT_e_IO_IN );	/* P00_13 TAUD1I12 */
R_PORT_SetAlt_Pnm( 0, 4, 6, PORT_e_IO_IN );	/* P00_4 TAUD1I12 */
R_PORT_SetAlt_Pnm( 11, 3, 8, PORT_e_IO_IN );	/* P11_3 TAUD1I13 */
R_PORT_SetAlt_Pnm( 10, 2, 9, PORT_e_IO_IN );	/* P10_2 TAUD1I13 */
R_PORT_SetAlt_Pnm( 0, 14, 4, PORT_e_IO_IN );	/* P00_14 TAUD1I14 */
R_PORT_SetAlt_Pnm( 0, 5, 6, PORT_e_IO_IN );	/* P00_5 TAUD1I14 */
R_PORT_SetAlt_Pnm( 11, 4, 8, PORT_e_IO_IN );	/* P11_4 TAUD1I15 */
R_PORT_SetAlt_Pnm( 10, 3, 9, PORT_e_IO_IN );	/* P10_3 TAUD1I15 */
R_PORT_SetAlt_Pnm( 0, 8, 6, PORT_e_IO_IN );	/* P00_8 TAUD1I2 */
R_PORT_SetAlt_Pnm( 8, 0, 8, PORT_e_IO_IN );	/* P08_0 TAUD1I2 */
R_PORT_SetAlt_Pnm( 10, 12, 5, PORT_e_IO_IN );	/* P10_12 TAUD1I3 */
R_PORT_SetAlt_Pnm( 0, 9, 6, PORT_e_IO_IN );	/* P00_9 TAUD1I4 */
R_PORT_SetAlt_Pnm( 8, 1, 6, PORT_e_IO_IN );	/* P08_1 TAUD1I4 */
R_PORT_SetAlt_Pnm( 10, 13, 5, PORT_e_IO_IN );	/* P10_13 TAUD1I5 */
R_PORT_SetAlt_Pnm( 8, 2, 4, PORT_e_IO_IN );	/* P08_2 TAUD1I6 */
R_PORT_SetAlt_Pnm( 0, 10, 6, PORT_e_IO_IN );	/* P00_10 TAUD1I6 */
R_PORT_SetAlt_Pnm( 10, 14, 5, PORT_e_IO_IN );	/* P10_14 TAUD1I7 */
R_PORT_SetAlt_Pnm( 0, 11, 6, PORT_e_IO_IN );	/* P00_11 TAUD1I8 */
R_PORT_SetAlt_Pnm( 8, 3, 6, PORT_e_IO_IN );	/* P08_3 TAUD1I8 */
R_PORT_SetAlt_Pnm( 11, 1, 4, PORT_e_IO_IN );	/* P11_1 TAUD1I9 */
R_PORT_SetAlt_Pnm( 10, 0, 9, PORT_e_IO_IN );	/* P10_0 TAUD1I9 */
R_PORT_SetAlt_Pnm( 0, 12, 3, PORT_e_IO_OUT );	/* P00_12 TAUD1O0 */
R_PORT_SetAlt_Pnm( 8, 4, 8, PORT_e_IO_OUT );	/* P08_4 TAUD1O0 */
R_PORT_SetAlt_Pnm( 11, 2, 7, PORT_e_IO_OUT );	/* P11_2 TAUD1O1 */
R_PORT_SetAlt_Pnm( 10, 1, 10, PORT_e_IO_OUT );	/* P10_1 TAUD1O1 */
R_PORT_SetAlt_Pnm( 0, 11, 7, PORT_e_IO_OUT );	/* P00_11 TAUD1O10 */
R_PORT_SetAlt_Pnm( 8, 3, 8, PORT_e_IO_OUT );	/* P08_3 TAUD1O10 */
R_PORT_SetAlt_Pnm( 11, 1, 7, PORT_e_IO_OUT );	/* P11_1 TAUD1O11 */
R_PORT_SetAlt_Pnm( 10, 0, 10, PORT_e_IO_OUT );	/* P10_0 TAUD1O11 */
R_PORT_SetAlt_Pnm( 0, 14, 3, PORT_e_IO_OUT );	/* P00_14 TAUD1O12 */
R_PORT_SetAlt_Pnm( 0, 5, 5, PORT_e_IO_OUT );	/* P00_5 TAUD1O12 */
R_PORT_SetAlt_Pnm( 11, 3, 9, PORT_e_IO_OUT );	/* P11_3 TAUD1O13 */
R_PORT_SetAlt_Pnm( 10, 3, 11, PORT_e_IO_OUT );	/* P10_3 TAUD1O13 */
R_PORT_SetAlt_Pnm( 0, 13, 3, PORT_e_IO_OUT );	/* P00_13 TAUD1O14 */
R_PORT_SetAlt_Pnm( 0, 4, 5, PORT_e_IO_OUT );	/* P00_4 TAUD1O14 */
R_PORT_SetAlt_Pnm( 11, 4, 9, PORT_e_IO_OUT );	/* P11_4 TAUD1O15 */
R_PORT_SetAlt_Pnm( 10, 2, 10, PORT_e_IO_OUT );	/* P10_2 TAUD1O15 */
R_PORT_SetAlt_Pnm( 0, 6, 4, PORT_e_IO_OUT );	/* P00_6 TAUD1O2 */
R_PORT_SetAlt_Pnm( 10, 11, 4, PORT_e_IO_OUT );	/* P10_11 TAUD1O3 */
R_PORT_SetAlt_Pnm( 0, 8, 4, PORT_e_IO_OUT );	/* P00_8 TAUD1O4 */
R_PORT_SetAlt_Pnm( 8, 0, 6, PORT_e_IO_OUT );	/* P08_0 TAUD1O4 */
R_PORT_SetAlt_Pnm( 10, 12, 4, PORT_e_IO_OUT );	/* P10_12 TAUD1O5 */
R_PORT_SetAlt_Pnm( 0, 9, 4, PORT_e_IO_OUT );	/* P00_9 TAUD1O6 */
R_PORT_SetAlt_Pnm( 8, 1, 8, PORT_e_IO_OUT );	/* P08_1 TAUD1O6 */
R_PORT_SetAlt_Pnm( 10, 13, 4, PORT_e_IO_OUT );	/* P10_13 TAUD1O7 */
R_PORT_SetAlt_Pnm( 0, 10, 4, PORT_e_IO_OUT );	/* P00_10 TAUD1O8 */
R_PORT_SetAlt_Pnm( 8, 2, 8, PORT_e_IO_OUT );	/* P08_2 TAUD1O8 */
R_PORT_SetAlt_Pnm( 10, 14, 4, PORT_e_IO_OUT );	/* P10_14 TAUD1O9 */
R_PORT_SetAlt_Pnm( 11, 11, 8, PORT_e_IO_IN );	/* P11_11 TAUD2I0 */
R_PORT_SetAlt_Pnm( 10, 7, 11, PORT_e_IO_IN );	/* P10_7 TAUD2I0 */
R_PORT_SetAlt_Pnm( 9, 0, 10, PORT_e_IO_IN );	/* P09_0 TAUD2I1 */
R_PORT_SetAlt_Pnm( 11, 3, 11, PORT_e_IO_IN );	/* P11_3 TAUD2I1 */
R_PORT_SetAlt_Pnm( 12, 0, 8, PORT_e_IO_IN );	/* P12_0 TAUD2I10 */
R_PORT_SetAlt_Pnm( 10, 12, 11, PORT_e_IO_IN );	/* P10_12 TAUD2I10 */
R_PORT_SetAlt_Pnm( 11, 8, 8, PORT_e_IO_IN );	/* P11_8 TAUD2I11 */
R_PORT_SetAlt_Pnm( 10, 4, 10, PORT_e_IO_IN );	/* P10_4 TAUD2I11 */
R_PORT_SetAlt_Pnm( 12, 1, 8, PORT_e_IO_IN );	/* P12_1 TAUD2I12 */
R_PORT_SetAlt_Pnm( 10, 13, 10, PORT_e_IO_IN );	/* P10_13 TAUD2I12 */
R_PORT_SetAlt_Pnm( 11, 9, 8, PORT_e_IO_IN );	/* P11_9 TAUD2I13 */
R_PORT_SetAlt_Pnm( 10, 5, 10, PORT_e_IO_IN );	/* P10_5 TAUD2I13 */
R_PORT_SetAlt_Pnm( 12, 2, 8, PORT_e_IO_IN );	/* P12_2 TAUD2I14 */
R_PORT_SetAlt_Pnm( 10, 14, 11, PORT_e_IO_IN );	/* P10_14 TAUD2I14 */
R_PORT_SetAlt_Pnm( 11, 10, 8, PORT_e_IO_IN );	/* P11_10 TAUD2I15 */
R_PORT_SetAlt_Pnm( 10, 6, 10, PORT_e_IO_IN );	/* P10_6 TAUD2I15 */
R_PORT_SetAlt_Pnm( 11, 12, 8, PORT_e_IO_IN );	/* P11_12 TAUD2I2 */
R_PORT_SetAlt_Pnm( 10, 8, 11, PORT_e_IO_IN );	/* P10_8 TAUD2I2 */
R_PORT_SetAlt_Pnm( 9, 1, 10, PORT_e_IO_IN );	/* P09_1 TAUD2I3 */
R_PORT_SetAlt_Pnm( 11, 4, 11, PORT_e_IO_IN );	/* P11_4 TAUD2I3 */
R_PORT_SetAlt_Pnm( 12, 5, 8, PORT_e_IO_IN );	/* P12_5 TAUD2I4 */
R_PORT_SetAlt_Pnm( 10, 9, 11, PORT_e_IO_IN );	/* P10_9 TAUD2I4 */
R_PORT_SetAlt_Pnm( 11, 5, 11, PORT_e_IO_IN );	/* P11_5 TAUD2I5 */
R_PORT_SetAlt_Pnm( 10, 1, 12, PORT_e_IO_IN );	/* P10_1 TAUD2I5 */
R_PORT_SetAlt_Pnm( 12, 3, 8, PORT_e_IO_IN );	/* P12_3 TAUD2I6 */
R_PORT_SetAlt_Pnm( 10, 10, 11, PORT_e_IO_IN );	/* P10_10 TAUD2I6 */
R_PORT_SetAlt_Pnm( 11, 6, 11, PORT_e_IO_IN );	/* P11_6 TAUD2I7 */
R_PORT_SetAlt_Pnm( 10, 2, 12, PORT_e_IO_IN );	/* P10_2 TAUD2I7 */
R_PORT_SetAlt_Pnm( 11, 15, 8, PORT_e_IO_IN );	/* P11_15 TAUD2I8 */
R_PORT_SetAlt_Pnm( 10, 11, 11, PORT_e_IO_IN );	/* P10_11 TAUD2I8 */
R_PORT_SetAlt_Pnm( 10, 3, 10, PORT_e_IO_IN );	/* P10_3 TAUD2I9 */
R_PORT_SetAlt_Pnm( 11, 7, 11, PORT_e_IO_IN );	/* P11_7 TAUD2I9 */
R_PORT_SetAlt_Pnm( 12, 0, 3, PORT_e_IO_OUT );	/* P12_0 TAUD2O0 */
R_PORT_SetAlt_Pnm( 10, 12, 9, PORT_e_IO_OUT );	/* P10_12 TAUD2O0 */
R_PORT_SetAlt_Pnm( 11, 8, 3, PORT_e_IO_OUT );	/* P11_8 TAUD2O1 */
R_PORT_SetAlt_Pnm( 10, 3, 12, PORT_e_IO_OUT );	/* P10_3 TAUD2O1 */
R_PORT_SetAlt_Pnm( 11, 15, 3, PORT_e_IO_OUT );	/* P11_15 TAUD2O10 */
R_PORT_SetAlt_Pnm( 10, 11, 9, PORT_e_IO_OUT );	/* P10_11 TAUD2O10 */
R_PORT_SetAlt_Pnm( 11, 7, 4, PORT_e_IO_OUT );	/* P11_7 TAUD2O11 */
R_PORT_SetAlt_Pnm( 10, 2, 13, PORT_e_IO_OUT );	/* P10_2 TAUD2O11 */
R_PORT_SetAlt_Pnm( 12, 2, 3, PORT_e_IO_OUT );	/* P12_2 TAUD2O12 */
R_PORT_SetAlt_Pnm( 10, 14, 7, PORT_e_IO_OUT );	/* P10_14 TAUD2O12 */
R_PORT_SetAlt_Pnm( 11, 10, 3, PORT_e_IO_OUT );	/* P11_10 TAUD2O13 */
R_PORT_SetAlt_Pnm( 10, 5, 12, PORT_e_IO_OUT );	/* P10_5 TAUD2O13 */
R_PORT_SetAlt_Pnm( 12, 1, 3, PORT_e_IO_OUT );	/* P12_1 TAUD2O14 */
R_PORT_SetAlt_Pnm( 10, 13, 7, PORT_e_IO_OUT );	/* P10_13 TAUD2O14 */
R_PORT_SetAlt_Pnm( 11, 9, 3, PORT_e_IO_OUT );	/* P11_9 TAUD2O15 */
R_PORT_SetAlt_Pnm( 10, 4, 12, PORT_e_IO_OUT );	/* P10_4 TAUD2O15 */
R_PORT_SetAlt_Pnm( 11, 11, 3, PORT_e_IO_OUT );	/* P11_11 TAUD2O2 */
R_PORT_SetAlt_Pnm( 10, 7, 10, PORT_e_IO_OUT );	/* P10_7 TAUD2O2 */
R_PORT_SetAlt_Pnm( 11, 3, 3, PORT_e_IO_OUT );	/* P11_3 TAUD2O3 */
R_PORT_SetAlt_Pnm( 9, 0, 9, PORT_e_IO_OUT );	/* P09_0 TAUD2O3 */
R_PORT_SetAlt_Pnm( 11, 12, 3, PORT_e_IO_OUT );	/* P11_12 TAUD2O4 */
R_PORT_SetAlt_Pnm( 10, 8, 10, PORT_e_IO_OUT );	/* P10_8 TAUD2O4 */
R_PORT_SetAlt_Pnm( 11, 4, 3, PORT_e_IO_OUT );	/* P11_4 TAUD2O5 */
R_PORT_SetAlt_Pnm( 9, 1, 9, PORT_e_IO_OUT );	/* P09_1 TAUD2O5 */
R_PORT_SetAlt_Pnm( 12, 5, 3, PORT_e_IO_OUT );	/* P12_5 TAUD2O6 */
R_PORT_SetAlt_Pnm( 10, 9, 9, PORT_e_IO_OUT );	/* P10_9 TAUD2O6 */
R_PORT_SetAlt_Pnm( 11, 5, 4, PORT_e_IO_OUT );	/* P11_5 TAUD2O7 */
R_PORT_SetAlt_Pnm( 10, 0, 12, PORT_e_IO_OUT );	/* P10_0 TAUD2O7 */
R_PORT_SetAlt_Pnm( 12, 3, 3, PORT_e_IO_OUT );	/* P12_3 TAUD2O8 */
R_PORT_SetAlt_Pnm( 10, 10, 9, PORT_e_IO_OUT );	/* P10_10 TAUD2O8 */
R_PORT_SetAlt_Pnm( 11, 6, 4, PORT_e_IO_OUT );	/* P11_6 TAUD2O9 */
R_PORT_SetAlt_Pnm( 10, 1, 13, PORT_e_IO_OUT );	/* P10_1 TAUD2O9 */
R_PORT_SetAlt_Pnm( 8, 0, 1, PORT_e_IO_IN );	/* P08_0 TAUJ0I0 */
R_PORT_SetAlt_Pnm( 8, 2, 1, PORT_e_IO_IN );	/* P08_2 TAUJ0I0 */
R_PORT_SetAlt_Pnm( 8, 3, 1, PORT_e_IO_IN );	/* P08_3 TAUJ0I1 */
R_PORT_SetAlt_Pnm( 8, 1, 4, PORT_e_IO_IN );	/* P08_1 TAUJ0I1 */
R_PORT_SetAlt_Pnm( 8, 4, 1, PORT_e_IO_IN );	/* P08_4 TAUJ0I2 */
R_PORT_SetAlt_Pnm( 8, 5, 1, PORT_e_IO_IN );	/* P08_5 TAUJ0I3 */
R_PORT_SetAlt_Pnm( 8, 4, 7, PORT_e_IO_OUT );	/* P08_4 TAUJ0O0 */
R_PORT_SetAlt_Pnm( 8, 5, 7, PORT_e_IO_OUT );	/* P08_5 TAUJ0O1 */
R_PORT_SetAlt_Pnm( 8, 0, 4, PORT_e_IO_OUT );	/* P08_0 TAUJ0O2 */
R_PORT_SetAlt_Pnm( 8, 2, 7, PORT_e_IO_OUT );	/* P08_2 TAUJ0O2 */
R_PORT_SetAlt_Pnm( 8, 1, 7, PORT_e_IO_OUT );	/* P08_1 TAUJ0O3 */
R_PORT_SetAlt_Pnm( 8, 3, 7, PORT_e_IO_OUT );	/* P08_3 TAUJ0O3 */
R_PORT_SetAlt_Pnm( 9, 4, 1, PORT_e_IO_IN );	/* P09_4 TAUJ1I0 */
R_PORT_SetAlt_Pnm( 0, 3, 6, PORT_e_IO_IN );	/* P00_3 TAUJ1I0 */
R_PORT_SetAlt_Pnm( 9, 3, 1, PORT_e_IO_IN );	/* P09_3 TAUJ1I1 */
R_PORT_SetAlt_Pnm( 9, 0, 5, PORT_e_IO_IN );	/* P09_0 TAUJ1I1 */
R_PORT_SetAlt_Pnm( 8, 11, 1, PORT_e_IO_IN );	/* P08_11 TAUJ1I2 */
R_PORT_SetAlt_Pnm( 9, 1, 6, PORT_e_IO_IN );	/* P09_1 TAUJ1I2 */
R_PORT_SetAlt_Pnm( 8, 12, 1, PORT_e_IO_IN );	/* P08_12 TAUJ1I3 */
R_PORT_SetAlt_Pnm( 10, 0, 4, PORT_e_IO_IN );	/* P10_0 TAUJ1I3 */
R_PORT_SetAlt_Pnm( 8, 11, 5, PORT_e_IO_OUT );	/* P08_11 TAUJ1O0 */
R_PORT_SetAlt_Pnm( 9, 1, 5, PORT_e_IO_OUT );	/* P09_1 TAUJ1O0 */
R_PORT_SetAlt_Pnm( 8, 12, 5, PORT_e_IO_OUT );	/* P08_12 TAUJ1O1 */
R_PORT_SetAlt_Pnm( 10, 0, 6, PORT_e_IO_OUT );	/* P10_0 TAUJ1O1 */
R_PORT_SetAlt_Pnm( 9, 4, 3, PORT_e_IO_OUT );	/* P09_4 TAUJ1O2 */
R_PORT_SetAlt_Pnm( 0, 3, 7, PORT_e_IO_OUT );	/* P00_3 TAUJ1O2 */
R_PORT_SetAlt_Pnm( 9, 3, 3, PORT_e_IO_OUT );	/* P09_3 TAUJ1O3 */
R_PORT_SetAlt_Pnm( 9, 0, 5, PORT_e_IO_OUT );	/* P09_0 TAUJ1O3 */
R_PORT_SetAlt_Pnm( 1, 0, 4, PORT_e_IO_IN );	/* P01_0 TAUJ2I0 */
R_PORT_SetAlt_JPnm( 0, 0, 4, PORT_e_IO_IN );	/* JP0_0 TAUJ2I0 */
R_PORT_SetAlt_Pnm( 1, 1, 4, PORT_e_IO_IN );	/* P01_1 TAUJ2I1 */
R_PORT_SetAlt_Pnm( 0, 0, 6, PORT_e_IO_IN );	/* P00_0 TAUJ2I1 */
R_PORT_SetAlt_Pnm( 1, 2, 4, PORT_e_IO_IN );	/* P01_2 TAUJ2I2 */
R_PORT_SetAlt_Pnm( 0, 1, 6, PORT_e_IO_IN );	/* P00_1 TAUJ2I2 */
R_PORT_SetAlt_Pnm( 1, 3, 4, PORT_e_IO_IN );	/* P01_3 TAUJ2I3 */
R_PORT_SetAlt_Pnm( 0, 2, 6, PORT_e_IO_IN );	/* P00_2 TAUJ2I3 */
R_PORT_SetAlt_Pnm( 1, 2, 4, PORT_e_IO_OUT );	/* P01_2 TAUJ2O0 */
R_PORT_SetAlt_Pnm( 0, 1, 5, PORT_e_IO_OUT );	/* P00_1 TAUJ2O0 */
R_PORT_SetAlt_Pnm( 1, 3, 4, PORT_e_IO_OUT );	/* P01_3 TAUJ2O1 */
R_PORT_SetAlt_Pnm( 0, 2, 6, PORT_e_IO_OUT );	/* P00_2 TAUJ2O1 */
R_PORT_SetAlt_JPnm( 0, 0, 2, PORT_e_IO_OUT );	/* JP0_0 TAUJ2O2 */
R_PORT_SetAlt_Pnm( 1, 0, 4, PORT_e_IO_OUT );	/* P01_0 TAUJ2O2 */
R_PORT_SetAlt_Pnm( 1, 1, 4, PORT_e_IO_OUT );	/* P01_1 TAUJ2O3 */
R_PORT_SetAlt_Pnm( 0, 0, 5, PORT_e_IO_OUT );	/* P00_0 TAUJ2O3 */
R_PORT_SetAlt_Pnm( 10, 1, 4, PORT_e_IO_IN );	/* P10_1 TAUJ3I0 */
R_PORT_SetAlt_Pnm( 18, 0, 4, PORT_e_IO_IN );	/* P18_0 TAUJ3I0 */
R_PORT_SetAlt_JPnm( 0, 1, 4, PORT_e_IO_IN );	/* JP0_1 TAUJ3I0 */
R_PORT_SetAlt_Pnm( 18, 1, 4, PORT_e_IO_IN );	/* P18_1 TAUJ3I1 */
R_PORT_SetAlt_JPnm( 0, 2, 4, PORT_e_IO_IN );	/* JP0_2 TAUJ3I1 */
R_PORT_SetAlt_Pnm( 10, 7, 7, PORT_e_IO_IN );	/* P10_7 TAUJ3I1 */
R_PORT_SetAlt_Pnm( 18, 2, 4, PORT_e_IO_IN );	/* P18_2 TAUJ3I2 */
R_PORT_SetAlt_JPnm( 0, 3, 4, PORT_e_IO_IN );	/* JP0_3 TAUJ3I2 */
R_PORT_SetAlt_Pnm( 10, 8, 7, PORT_e_IO_IN );	/* P10_8 TAUJ3I2 */
R_PORT_SetAlt_Pnm( 18, 3, 4, PORT_e_IO_IN );	/* P18_3 TAUJ3I3 */
R_PORT_SetAlt_JPnm( 0, 5, 4, PORT_e_IO_IN );	/* JP0_5 TAUJ3I3 */
R_PORT_SetAlt_Pnm( 10, 10, 7, PORT_e_IO_IN );	/* P10_10 TAUJ3I3 */
R_PORT_SetAlt_JPnm( 0, 3, 2, PORT_e_IO_OUT );	/* JP0_3 TAUJ3O0 */
R_PORT_SetAlt_Pnm( 18, 2, 3, PORT_e_IO_OUT );	/* P18_2 TAUJ3O0 */
R_PORT_SetAlt_Pnm( 10, 8, 7, PORT_e_IO_OUT );	/* P10_8 TAUJ3O0 */
R_PORT_SetAlt_JPnm( 0, 5, 2, PORT_e_IO_OUT );	/* JP0_5 TAUJ3O1 */
R_PORT_SetAlt_Pnm( 18, 3, 3, PORT_e_IO_OUT );	/* P18_3 TAUJ3O1 */
R_PORT_SetAlt_Pnm( 10, 10, 7, PORT_e_IO_OUT );	/* P10_10 TAUJ3O1 */
R_PORT_SetAlt_JPnm( 0, 1, 2, PORT_e_IO_OUT );	/* JP0_1 TAUJ3O2 */
R_PORT_SetAlt_Pnm( 18, 0, 3, PORT_e_IO_OUT );	/* P18_0 TAUJ3O2 */
R_PORT_SetAlt_Pnm( 10, 1, 7, PORT_e_IO_OUT );	/* P10_1 TAUJ3O2 */
R_PORT_SetAlt_JPnm( 0, 2, 2, PORT_e_IO_OUT );	/* JP0_2 TAUJ3O3 */
R_PORT_SetAlt_Pnm( 18, 1, 3, PORT_e_IO_OUT );	/* P18_1 TAUJ3O3 */
R_PORT_SetAlt_Pnm( 10, 7, 7, PORT_e_IO_OUT );	/* P10_7 TAUJ3O3 */
R_PORT_SetAlt_Pnm( 13, 0, 3, PORT_e_IO_OUT );	/* P13_0 TCLK */
R_PORT_SetAlt_Pnm( 13, 1, 3, PORT_e_IO_OUT );	/* P13_1 TDATA0 */
R_PORT_SetAlt_Pnm( 13, 2, 3, PORT_e_IO_OUT );	/* P13_2 TDATA1 */
R_PORT_SetAlt_Pnm( 13, 3, 3, PORT_e_IO_OUT );	/* P13_3 TDATA2 */
R_PORT_SetAlt_Pnm( 13, 4, 3, PORT_e_IO_OUT );	/* P13_4 TDATA3 */
R_PORT_SetAlt_Pnm( 8, 3, 4, PORT_e_IO_IN );	/* P08_3 TRIGIN */
R_PORT_SetAlt_JPnm( 0, 6, 1, PORT_e_IO_OUT );	/* JP0_6 TRIGOUT */
#endif

/*******************************************************************************
* Prototype declarations of functions and
* functional definition (macro)
*******************************************************************************/

/*******************************************************************************
* Description  : Releases write protection of specified port group.
* Arguments    : uint8_t n: port group number
*                PORT_e_kind kind: kind of target port
* Return Value : RET_OK       : Register Readback check was successful
*                RET_ERR_PARAM: Argument kind is out of range
*                RET_NONEED   : Port group n is not eligible for releasing write protection
*                RET_ERR_REG  : Register Readback check was failed
*******************************************************************************/
uint8_t R_PORT_ReleaseWriteProtect( uint8_t n, PORT_e_kind kind );


/*******************************************************************************
* Description  : Sets write protection of specified port group.
* Arguments    : uint8_t n: port group number
*                PORT_e_kind kind: kind of target port
* Return Value : RET_OK       : Register Readback check was successful
*                RET_ERR_PARAM: Argument kind is out of range
*                RET_NONEED   : Port group n is not eligible for releasing write protection
*                RET_ERR_REG  : Register Readback check was failed
*******************************************************************************/
uint8_t R_PORT_SetWriteProtect( uint8_t n, PORT_e_kind kind );


/*******************************************************************************
* Description  : Changes alternative function.
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
*                uint8_t alt: alternative function number
*                PORT_e_IO io_modes: PORT_e_IO_OUT/PORT_e_IO_IN/PORT_e_IO_INOUT
*                PORT_e_kind kind: kind of target port
* Return Value : 0: Register readback check was successful
*                1: Register readback check failed
*                RET_ERR_PARAM: kind is out of range
*******************************************************************************/
/* for number port and J port */
uint8_t R_PORT_ChangeAlt_nm( uint8_t n, uint8_t m, uint8_t alt, PORT_e_IO io_mode, PORT_e_kind kind );

/* for number port */
#define R_PORT_SetAlt_Pnm(n,m,alt,io_mode)	R_PORT_ChangeAlt_nm( n, m, alt, io_mode, PORT_e_kind_P )

/* for J port */
#define R_PORT_SetAlt_JPnm(n,m,alt,io_mode)	R_PORT_ChangeAlt_nm( n, m, alt, io_mode, PORT_e_kind_JP )


/*******************************************************************************
* Description  : Initialize port function.
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
*                PORT_e_kind kind: kind of target port
* Return Value : RET_OK       : Register readback check was successful
*                RET_ERR_REG  : The fail count of register readback check
*                RET_ERR_PARAM: kind is out of range
*******************************************************************************/
/* for number port and J port */
uint8_t R_PORT_InitPort_nm( uint8_t n, uint8_t m, PORT_e_kind kind );

/* for number port */
#define R_PORT_InitPort_Pnm(n,m)	R_PORT_InitPort_nm( n, m, PORT_e_kind_P )

/* for J port */
#define R_PORT_InitPort_JPnm(n,m)	R_PORT_InitPort_nm( n, m, PORT_e_kind_JP )


/*******************************************************************************
* Description  : Changes port drive strength.
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
*                PORT_e_st strength: drive strength
*                PORT_e_kind kind: kind of target port
* Return Value : RET_OK       : Register readback check was successful
*                RET_ERR_REG  : The fail count of register readback check
*                RET_ERR_PARAM: kind is out of range
*******************************************************************************/
/* for number port and J port */
uint8_t R_PORT_ChangeStrength_nm( uint8_t n, uint8_t m, PORT_e_st strength, PORT_e_kind kind );

/* for number port */
#define	R_PORT_ChangeStrength_Pnm(n,m,strength) 	R_PORT_ChangeStrength_nm( n, m, strength, PORT_e_kind_P )

/* for J port */
#define	R_PORT_ChangeStrength_JPnm(n,m,strength)	R_PORT_ChangeStrength_nm( n, m, strength, PORT_e_kind_JP )


/*******************************************************************************
* Description  : Change output level multiple bits
* Arguments    : uint8_t n     : port group number
*                uint16_t value: set value of Pn register
* Return Value : RET_OK     : Register readback check was successful
*                RET_ERR_REG: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_ChangeOutputLevel_P(n,value) 	Reg16WRC( &rPn(n).UINT16, value, 0xFFFF )	/* Pn = value */

/* for A port */
#define	R_PORT_ChangeOutputLevel_AP(n,value)	Reg16WRC( &rAPn(n).UINT16, value, 0xFFFF )	/* APn = value */

/* for J port */
#define	R_PORT_ChangeOutputLevel_JP(n,value)	Reg08WRC( &rJPn(n).UINT8, value, 0xFF )	/* JPn = value */


/*******************************************************************************
* Description  : Output high level in port mode for individual bit
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
* Return Value : RET_OK     : Register readback check was successful
*                RET_ERR_REG: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_OutputHigh_Pnm(n,m) 	Reg16SetBitCheck( &rPn(n).UINT16, m )	/* Pn_m = 1 */

/* for A port */
#define	R_PORT_OutputHigh_APnm(n,m)	Reg16SetBitCheck( &rAPn(n).UINT16, m )	/* APn_m = 1 */

/* for J port */
#define	R_PORT_OutputHigh_JPnm(n,m)	Reg08SetBitCheck( &rJPn(n).UINT8, m )	/* JPn_m = 1 */


/*******************************************************************************
* Description  : Output low level in port mode for individual bit
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
* Return Value : RET_OK     : Register readback check was successful
*                RET_ERR_REG: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_OutputLow_Pnm(n,m) 	Reg16ClearBitCheck( &rPn(n).UINT16, m ) 	/* Pn_m = 0 */

/* for number port */
#define	R_PORT_OutputLow_APnm(n,m)	Reg16ClearBitCheck( &rAPn(n).UINT16, m )	/* APn_m = 0 */

/* for Jport */
#define	R_PORT_OutputLow_JPnm(n,m)	Reg08ClearBitCheck( &rJPn(n).UINT8, m ) 	/* JPn_m = 0 */


/*******************************************************************************
* Description  : Toggle output level for multiple bits
* Arguments    : uint8_t n     : port group number
*                uint16_t value: set value of PNOTn register
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_ToggleOutputLevel_P(n,value) 	rPNOTn(n).UINT16 = value 	/* PNOTn = value */

/* for A port */
#define	R_PORT_ToggleOutputLevel_AP(n,value)	rAPNOTn(n).UINT16 = value	/* APNOTn = value */

/* for J port */
#define	R_PORT_ToggleOutputLevel_JP(n,value)	rJPNOTn(n).UINT8 = value 	/* JPNOTn = value */


/*******************************************************************************
* Description  : Toggle output level for individual bit
* Arguments    : uint8_t n     : port group number
*                uint16_t value: set value of PNOTn register
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_ToggleOutputLevel_Pnm(n,m) 	rPNOTn(n).UINT16 = (1 << m) 	/* PNOTn_m = value */

/* for A port */
#define	R_PORT_ToggleOutputLevel_APnm(n,m)	rAPNOTn(n).UINT16 = (1 << m)	/* APNOTn_m = value */

/* for J port */
#define	R_PORT_ToggleOutputLevel_JPnm(n,m)	rJPNOTn(n).UINT8 = (1 << m) 	/* JPNOTn_m = value */


/*******************************************************************************
* Description  : Read port terminal level by multiple bits
* Arguments    : uint8_t n     : port group number
* Return Value : PPRn, APPRn, JPPRn register value
*******************************************************************************/
/* for number port */
#define	R_PORT_Read_P(n) 	rPPRn(n).UINT16

/* for A port */
#define	R_PORT_Read_AP(n)	rAPPRn(n).UINT16

/* for J port */
#define	R_PORT_Read_JP(n)	rJPPRn(n).UINT8


/*******************************************************************************
* Description  : Change I/O mode by multiple bits
* Arguments    : uint8_t n    : port group number
*                uint8_t value: set value of PMn register
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_ChangeIOmode_P(n,value) 	Reg16WRC( &rPMn(n).UINT16, value, 0xFFFF ) 	/* PMn = value */

/* for A port */
#define	R_PORT_ChangeIOmode_AP(n,value)	Reg16WRC( &rAPMn(n).UINT16, value, 0xFFFF )	/* APMn = value */

/* for J port */
#define	R_PORT_ChangeIOmode_JP(n,value)	Reg08WRC( &rJPMn(n).UINT8, value, 0xFF )   	/* JPMn = value */


/*******************************************************************************
* Description  : Change to port input mode by individual bit
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_SetInputMode_Pnm(n,m)	Reg16SetBitCheck( &rPMn(n).UINT16, m ); \
                                    	Reg16SetBitCheck( &rPIBCn(n).UINT16, m )	/* PMn_m = 1, PIBCn_m = 1 */

/* for AP port */
#define	R_PORT_SetInputMode_APnm(n,m)	Reg16SetBitCheck( &rAPMn(n).UINT16, m); \
                                     	Reg16SetBitCheck( &rAPIBCn(n).UINT16, m )	/* APMn_m = 1, APIBCn_m = 1 */

/* for J port */
#define	R_PORT_SetInputMode_JPnm(n,m)	Reg08SetBitCheck( &rJPMn(n).UINT8, m ); \
                                     	Reg08SetBitCheck( &rJPIBCn(n).UINT8, m )	/* JPMn_m = 1, JPIBCn_m = 1 */

										
/*******************************************************************************
* Description  : Change to port output mode by individual bit
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_SetOuputMode_Pnm(n,m)	Reg16ClearBitCheck( &rPMn(n).UINT16, m ); \
                                    	Reg16ClearBitCheck( &rPIBCn(n).UINT16, m );	/* PMn_m = 0, PIBCn_m = 0 */
/* for AP port */
#define	R_PORT_SetOuputMode_APnm(n,m)	Reg16ClearBitCheck( &rAPMn(n).UINT16, m ); \
                                     	Reg16ClearBitCheck( &rAPIBCn(n).UINT16, m );	/* APMn_m = 0, APIBCn_m = 0 */
/* for J port */
#define	R_PORT_SetOuputMode_JPnm(n,m)	Reg08ClearBitCheck( &rJPMn(n).UINT8, m ); \
                                     	Reg08ClearBitCheck( &rJPIBCn(n).UINT8, m );	/* JPMn_m = 0, JPIBCn_m = 0 */

										
/*******************************************************************************
* Description  : Invert output level by multiple bits
* Arguments    : uint8_t n    : port group number
*                uint8_t value: set value of PINVn register
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
* Remark       : need to relase write protection before execute this macro
*******************************************************************************/
/* for number port */
#define	R_PORT_ChangeInvertLevel_P(n,value) 	Reg16WRC( &rPINVn(n).UINT16, value, 0xFFFF ) 	/* PINVn = value */

/* for A port */
#define	R_PORT_ChangeInvertLevel_AP(n,value)	Reg16WRC( &rAPINVn(n).UINT16, value, 0xFFFF )	/* APINVn = value */

/* for J port */
#define	R_PORT_ChangeInvertLevel_JP(n,value)	Reg08WRC( &rJPINVn(n).UINT8, value, 0xFF )   	/* JPINVn = value */


/*******************************************************************************
* Description  : Change the input buffer to enable/disable by multiple bits
* Arguments    : uint8_t n    : port group number
*                uint8_t value: set value of PIBCn register
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
* Remark       : need to relase write protection before execute this macro
*******************************************************************************/
/* for number port */
#define	R_PORT_ChangeInputBuffer_P(n,value) 	Reg16WRC( &rPIBCn(n).UINT16, value, 0xFFFF ) 	/* PIBCn = value */

/* for A port */
#define	R_PORT_ChangeInputBuffer_AP(n,value)	Reg16WRC( &rAPIBCn(n).UINT16, value, 0xFFFF )	/* APIBCn = value */

/* for J port */
#define	R_PORT_ChangeInputBuffer_JP(n,value)	Reg08WRC( &rJPIBCn(n).UINT8, value, 0xFF )   	/* JPIBCn = value */

/* for I port */
#define	R_PORT_ChangeInputBuffer_IP(n,value)	Reg16WRC( &rIPIBCn(n).UINT16, value, 0xFFFF )	/* IPIBCn = value */


/*******************************************************************************
* Description  : Enable input buffer by individual bit 
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_EnableInputBuffer_Pnm(n,m) 	Reg16SetBitCheck( &rPIBCn(n).UINT16, m )	/* PIBC = 1 */

/* for AP port */
#define	R_PORT_EnableInputBuffer_APnm(n,m)	Reg16SetBitCheck( &rAPIBCn(n).UINT16, m )	/* APIBC = 1 */

/* for J port */
#define	R_PORT_EnableInputBuffer_JPnm(n,m)	Reg08SetBitCheck( &rJPIBCn(n).UINT8, m )	/* JPIBC = 1 */

/* for I port */
#define	R_PORT_EnableInputBuffer_IPnm(n,m)	Reg16SetBitCheck( &rIPIBCn(n).UINT16, m )	/* IPIBC = 1 */


/*******************************************************************************
* Description  : Disable input buffer by individual bit 
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_DisableInputBuffer_Pnm(n,m) 	Reg16ClearBitCheck( &rPIBCn(n).UINT16, m )	/* PIBC = 0 */

/* for AP port */
#define	R_PORT_DisableInputBuffer_APnm(n,m)	Reg16ClearBitCheck( &rAPIBCn(n).UINT16, m )	/* APIBC = 0 */

/* for J port */
#define	R_PORT_DisableInputBuffer_JPnm(n,m)	Reg08ClearBitCheck( &rJPIBCn(n).UINT8, m )	/* JPIBC = 0 */

/* for I port */
#define	R_PORT_DisableInputBuffer_IPnm(n,m)	Reg16ClearBitCheck( &rIPIBCn(n).UINT16, m )	/* IPIBC = 0 */


/*******************************************************************************
* Description  : Change the Bi-direction mode to enable/disable by multiple bits
* Arguments    : uint8_t n    : port group number
*                uint8_t value: set value of PIBCn register
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_ChangeBiDirection_P(n,value) 	Reg16WRC( &rPBDCn(n).UINT16, value, 0xFFFF ) 	/* PBDCn = value */

/* for A port */
#define	R_PORT_ChangeBiDirection_AP(n,value)	Reg16WRC( &rAPBDCn(n).UINT16, value, 0xFFFF )	/* APBDCn = value */

/* for J port */
#define	R_PORT_ChangeBiDirection_JP(n,value)	Reg08WRC( &rJPBDCn(n).UINT8, value, 0xFF )   	/* JPBDCn = value */


/*******************************************************************************
* Description  : Enable the Bi-direction mode by individual bit 
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_EnableBiDirection_Pnm(n,m) 	Reg16SetBitCheck( &rPBDCn(n).UINT16, m )	/* PBDC = 1 */

/* for A port */
#define	R_PORT_EnableBiDirection_APnm(n,m)	Reg16SetBitCheck( &rAPBDCn(n).UINT16, m )	/* APBDC = 1 */

/* for J port */
#define	R_PORT_EnableBiDirection_JPnm(n,m)	Reg08SetBitCheck( &rJPBDCn(n).UINT8, m )	/* JPBDC = 1 */


/*******************************************************************************
* Description  : Disable the Bi-direction mode by individual bit 
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_DisableBiDirection_Pnm(n,m) 	Reg16ClearBitCheck( &rPBDCn(n).UINT16, m )	/* PBDC = 0 */

/* for A port */
#define	R_PORT_DisableBiDirection_APnm(n,m) 	Reg16ClearBitCheck( &rAPBDCn(n).UINT16, m )	/* APBDC = 0 */

/* for J port */
#define	R_PORT_DisableBiDirection_JPnm(n,m)	Reg08ClearBitCheck( &rJPBDCn(n).UINT8, m )	/* JPBDC = 0 */


/*******************************************************************************
* Description  : Change to connect/disconnect the internal pullup resistor by multiple bits
* Arguments    : uint8_t n    : port group number
*                uint8_t value: set value of PUn register
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_ChangePullup_P(n,value) 	Reg16WRC( &rPUn(n).UINT16, value, 0xFFFF ) 	/* PUn = value */

/* for J port */
#define	R_PORT_ChangePullup_JP(n,value)	Reg08WRC( &rJPUn(n).UINT8, value, 0xFF )   	/* JPUn = value */


/*******************************************************************************
* Description  : Connect the internal pullup resistor by individual bit
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* Connect the internal pullup resistor for number port */
#define	R_PORT_ConnectPullup_Pnm(n,m) 	Reg16SetBitCheck( &rPUn(n).UINT16, m )  	/* PUn_m = 1 */

/* Connect the internal pullup resistor for Jport */
#define	R_PORT_ConnectPullup_JPnm(n,m)	Reg08SetBitCheck( &rJPUn(n).UINT8, m )  	/* JPUn_m = 1 */


/*******************************************************************************
* Description  : Disconnect the internal pullup resistor by individual bit
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* Disconnect the internal pullup resistor for number port */
#define	R_PORT_DisconnectPullup_Pnm(n,m) 	Reg16ClearBitCheck( &rPUn(n).UINT16, m )	/* PUn_m = 0 */

/* Disconnect the internal pullup resistor for Jport */
#define	R_PORT_DisconnectPullup_JPnm(n,m)	Reg08ClearBitCheck( &rJPUn(n).UINT8, m )	/* JPUn_m = 0 */


/*******************************************************************************
* Description  : Change to connect/disconnect the internal pulldown resistor
* Arguments    : uint8_t n    : port group number
*                uint8_t value: set value of PDn register
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_ChangePulldown_P(n,value) 	Reg16WRC( &rPDn(n).UINT16, value, 0xFFFF ); 	/* PDn = value */

/* for J port */
#define	R_PORT_ChangePulldown_JP(n,value)	Reg08WRC( &rJPDn(n).UINT8, value, 0xFF );   	/* JPDn = value */


/*******************************************************************************
* Description  : Connect the internal pulldown resistor by individual bit
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_ConnectPulldown_Pnm(n,m) 	Reg16SetBitCheck( &rPDn(n).UINT16, m )  	/* PDn_m = 1 */

/* for J port */
#define	R_PORT_ConnectPulldown_JPnm(n,m)	Reg08SetBitCheck( &rJPDn(n).UINT8, m )  	/* JPDn_m = 1 */


/*******************************************************************************
* Description  : Disconnect the internal pulldown resistor by individual bit
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for number port */
#define	R_PORT_DisconnectPulldown_Pnm(n,m) 	Reg16ClearBitCheck( &rPDn(n).UINT16, m )	/* PDn_m = 0 */

/* for Jport */
#define	R_PORT_DisconnectPulldown_JPnm(n,m)	Reg08ClearBitCheck( &rJPDn(n).UINT8, m )	/* JPDn_m = 0 */


/*******************************************************************************
* Description  : Changes open-drain or push-pull by individual bit
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
*                PORT_e_outtype outtype: open-drain or push-pull
* Return Value : 0     : Register readback check was successful
*                others: The fail count of register readback check
*******************************************************************************/
/* for any kind */
uint8_t R_PORT_ChangeOutputType_nm( uint8_t n, uint8_t m, PORT_e_outtype outtype, PORT_e_kind kind );

/* for number port */
#define	R_PORT_ChangeOutputType_Pnm(n,m,outtype) 	R_PORT_ChangeOutputType_nm( n, m, outtype, PORT_e_kind_P )

/* for A port */
#define	R_PORT_ChangeOutputType_APnm(n,m,outtype)	R_PORT_ChangeOutputType_nm( n, m, outtype, PORT_e_kind_AP )

/* for J port */
#define	R_PORT_ChangeOutputType_JPnm(n,m,outtype)	R_PORT_ChangeOutputType_nm( n, m, outtype, PORT_e_kind_JP )


/*******************************************************************************
* Description  : Changes input buffer type (open-drain or push-pull) by individual bit
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
*                PORT_e_intype intype: SHMT1 or SHMT4 or TTL
*                PORT_e_kind kind: kind of target port
* Return Value : 0: Register readback check was successful
*                1: Register readback check failed
*                RET_ERR_PARAM: kind is out of range
*******************************************************************************/
/* for any kind */
uint8_t R_PORT_ChangeInputType_nm( uint8_t n, uint8_t m, PORT_e_intype intype, PORT_e_kind kind );

/* for number port */
#define	R_PORT_ChangeInputType_Pnm(n,m,intype) 	R_PORT_ChangeInputType_nm( n, m, intype, PORT_e_kind_P )

/* for A port */
#define	R_PORT_ChangeInputType_APnm(n,m,intype)	R_PORT_ChangeInputType_nm( n, m, intype, PORT_e_kind_AP )

/* for J port */
#define	R_PORT_ChangeInputType_JPnm(n,m,intype)	R_PORT_ChangeInputType_nm( n, m, intype, PORT_e_kind_JP )


/*******************************************************************************
* Description  : Configure filter control
* Arguments    : PORT_s_FCLACTLm *addr: address of filter control register
*                PORT_e_BYPS byps     : Bypass mode selection
*                PORT_e_INTx intx     : Detection mode selection
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_PORT_ConfigFilter( PORT_s_FCLACTLm *addr, PORT_e_BYPS byps, PORT_e_INTx intx );

/* for IRQn */
#define R_PORT_ConfigFilter_IRQ(n,byps,intx)	R_PORT_ConfigFilter( &rFCLACTL_IRQn(n), byps, intx )

/* for NMI */
#define R_PORT_ConfigFilter_NMI(byps,intx)	R_PORT_ConfigFilter( &rFCLACTL_NMI, byps, intx )

/* for TAPA0ESO */
#define R_PORT_ConfigFilter_TAPA(byps,intx)	R_PORT_ConfigFilter( &rFCLACTL_TAPA, byps, intx )


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_port_H__ */
