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
* File Name    : R_device_RLIN3.h
* Version      : 1.00
* Module(s)    : RLIN3
* Device(s)    : R-Car U5L product
* Description  : This file contains product-specific descriptions of the RLIN3 
*                drivers.
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_device_RLIN3_H__
#define	__R_device_RLIN3_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"
#include "product.h"
#include "R_driver_port.h"


/*******************************************************************************
* Register Base Address Definitions
*******************************************************************************/
#if defined(U5L4_BGA257)
#define RLIN30_inst_0_BASE	0x5C3B4000UL
#define RLIN31_inst_0_BASE	0x5D19B100UL
#define RLIN32_inst_0_BASE	0x5C3B4200UL
#define RLIN33_inst_0_BASE	0x5D19B300UL
#define RLIN34_inst_0_BASE	0x5C3B4400UL
#define RLIN35_inst_0_BASE	0x5D19B500UL
#define RLIN36_inst_0_BASE	0x5C3B4600UL
#define RLIN37_inst_0_BASE	0x5D19B700UL
#define RLIN38_inst_0_BASE	0x5C3B4800UL
#define RLIN39_inst_0_BASE	0x5D19B900UL
#define RLIN310_inst_0_BASE	0x5C3B4A00UL
#define RLIN311_inst_0_BASE	0x5D19BB00UL
#define RLIN312_inst_0_BASE	0x5C3B4C00UL
#define RLIN313_inst_0_BASE	0x5D19BD00UL
#define RLIN314_inst_0_BASE	0x5C3B4E00UL
#define RLIN315_inst_0_BASE	0x5D19BF00UL
#define RLIN316_inst_0_BASE	0x5C3B5000UL
#define RLIN317_inst_0_BASE	0x5D19C100UL
#define	RLIN318_inst_0_BASE	0           	/* not exist */
#define	RLIN319_inst_0_BASE	0           	/* not exist */
#define	RLIN320_inst_0_BASE	0           	/* not exist */
#define	RLIN321_inst_0_BASE	0           	/* not exist */
#define	RLIN322_inst_0_BASE	0           	/* not exist */
#define	RLIN323_inst_0_BASE	0           	/* not exist */

#elif defined(U5L4_QFP176) || defined(U5L4_QFP144) || defined(U5L2_QFP176) || defined(U5L2_QFP144)
#define RLIN30_inst_0_BASE	0x5C3B4000UL
#define RLIN31_inst_0_BASE	0x5D19B100UL
#define RLIN32_inst_0_BASE	0x5C3B4200UL
#define RLIN33_inst_0_BASE	0x5D19B300UL
#define RLIN34_inst_0_BASE	0x5C3B4400UL
#define RLIN35_inst_0_BASE	0x5D19B500UL
#define RLIN36_inst_0_BASE	0x5C3B4600UL
#define RLIN37_inst_0_BASE	0x5D19B700UL
#define RLIN38_inst_0_BASE	0x5C3B4800UL
#define RLIN39_inst_0_BASE	0x5D19B900UL
#define RLIN310_inst_0_BASE	0x5C3B4A00UL
#define RLIN311_inst_0_BASE	0x5D19BB00UL
#define RLIN312_inst_0_BASE	0x5C3B4C00UL
#define RLIN313_inst_0_BASE	0x5D19BD00UL
#define RLIN314_inst_0_BASE	0x5C3B4E00UL
#define RLIN315_inst_0_BASE	0x5D19BF00UL
#define RLIN316_inst_0_BASE	0           	/* not exist */
#define RLIN317_inst_0_BASE	0           	/* not exist */
#define	RLIN318_inst_0_BASE	0           	/* not exist */
#define	RLIN319_inst_0_BASE	0           	/* not exist */
#define	RLIN320_inst_0_BASE	0           	/* not exist */
#define	RLIN321_inst_0_BASE	0           	/* not exist */
#define	RLIN322_inst_0_BASE	0           	/* not exist */
#define	RLIN323_inst_0_BASE	0           	/* not exist */

#elif defined(U5L4_QFP100)
#define RLIN30_inst_0_BASE	0x5C3B4000UL
#define RLIN31_inst_0_BASE	0x5D19B100UL
#define RLIN32_inst_0_BASE	0x5C3B4200UL
#define RLIN33_inst_0_BASE	0x5D19B300UL
#define RLIN34_inst_0_BASE	0x5C3B4400UL
#define RLIN35_inst_0_BASE	0x5D19B500UL
#define RLIN36_inst_0_BASE	0x5C3B4600UL
#define RLIN37_inst_0_BASE	0x5D19B700UL
#define RLIN38_inst_0_BASE	0x5C3B4800UL
#define RLIN39_inst_0_BASE	0x5D19B900UL
#define RLIN310_inst_0_BASE	0x5C3B4A00UL
#define RLIN311_inst_0_BASE	0x5D19BB00UL
#define RLIN312_inst_0_BASE	0x5C3B4C00UL
#define RLIN313_inst_0_BASE	0x5D19BD00UL
#define RLIN314_inst_0_BASE	0           	/* not exist */
#define RLIN315_inst_0_BASE	0           	/* not exist */
#define RLIN316_inst_0_BASE	0           	/* not exist */
#define RLIN317_inst_0_BASE	0           	/* not exist */
#define	RLIN318_inst_0_BASE	0           	/* not exist */
#define	RLIN319_inst_0_BASE	0           	/* not exist */
#define	RLIN320_inst_0_BASE	0           	/* not exist */
#define	RLIN321_inst_0_BASE	0           	/* not exist */
#define	RLIN322_inst_0_BASE	0           	/* not exist */
#define	RLIN323_inst_0_BASE	0           	/* not exist */

#elif defined(U5L2_QFP100)
#define RLIN30_inst_0_BASE	0x5C3B4000UL
#define RLIN31_inst_0_BASE	0x5D19B100UL
#define RLIN32_inst_0_BASE	0x5C3B4200UL
#define RLIN33_inst_0_BASE	0x5D19B300UL
#define RLIN34_inst_0_BASE	0x5C3B4400UL
#define RLIN35_inst_0_BASE	0x5D19B500UL
#define RLIN36_inst_0_BASE	0x5C3B4600UL
#define RLIN37_inst_0_BASE	0x5D19B700UL
#define RLIN38_inst_0_BASE	0x5C3B4800UL
#define RLIN39_inst_0_BASE	0x5D19B900UL
#define RLIN310_inst_0_BASE	0x5C3B4A00UL
#define RLIN311_inst_0_BASE	0x5D19BB00UL
#define RLIN312_inst_0_BASE	0           	/* not exist */
#define RLIN313_inst_0_BASE	0           	/* not exist */
#define RLIN314_inst_0_BASE	0           	/* not exist */
#define RLIN315_inst_0_BASE	0           	/* not exist */
#define RLIN316_inst_0_BASE	0           	/* not exist */
#define RLIN317_inst_0_BASE	0           	/* not exist */
#define	RLIN318_inst_0_BASE	0           	/* not exist */
#define	RLIN319_inst_0_BASE	0           	/* not exist */
#define	RLIN320_inst_0_BASE	0           	/* not exist */
#define	RLIN321_inst_0_BASE	0           	/* not exist */
#define	RLIN322_inst_0_BASE	0           	/* not exist */
#define	RLIN323_inst_0_BASE	0           	/* not exist */

#elif defined(U5L2_QFP80) || defined(U5L1_QFP100)
#define RLIN30_inst_0_BASE	0x5C3B4000UL
#define RLIN31_inst_0_BASE	0x5D19B100UL
#define RLIN32_inst_0_BASE	0x5C3B4200UL
#define RLIN33_inst_0_BASE	0x5D19B300UL
#define RLIN34_inst_0_BASE	0x5C3B4400UL
#define RLIN35_inst_0_BASE	0x5D19B500UL
#define RLIN36_inst_0_BASE	0x5C3B4600UL
#define RLIN37_inst_0_BASE	0x5D19B700UL
#define RLIN38_inst_0_BASE	0           	/* not exist */
#define RLIN39_inst_0_BASE	0           	/* not exist */
#define RLIN310_inst_0_BASE	0           	/* not exist */
#define RLIN311_inst_0_BASE	0           	/* not exist */
#define RLIN312_inst_0_BASE	0           	/* not exist */
#define RLIN313_inst_0_BASE	0           	/* not exist */
#define RLIN314_inst_0_BASE	0           	/* not exist */
#define RLIN315_inst_0_BASE	0           	/* not exist */
#define RLIN316_inst_0_BASE	0           	/* not exist */
#define RLIN317_inst_0_BASE	0           	/* not exist */
#define	RLIN318_inst_0_BASE	0           	/* not exist */
#define	RLIN319_inst_0_BASE	0           	/* not exist */
#define	RLIN320_inst_0_BASE	0           	/* not exist */
#define	RLIN321_inst_0_BASE	0           	/* not exist */
#define	RLIN322_inst_0_BASE	0           	/* not exist */
#define	RLIN323_inst_0_BASE	0           	/* not exist */

#elif defined(U5L2_QFP64) || defined(U5L1_QFP80)
#define RLIN30_inst_0_BASE	0x5C3B4000UL
#define RLIN31_inst_0_BASE	0x5D19B100UL
#define RLIN32_inst_0_BASE	0x5C3B4200UL
#define RLIN33_inst_0_BASE	0x5D19B300UL
#define RLIN34_inst_0_BASE	0x5C3B4400UL
#define RLIN35_inst_0_BASE	0x5D19B500UL
#define RLIN36_inst_0_BASE	0           	/* not exist */
#define RLIN37_inst_0_BASE	0           	/* not exist */
#define RLIN38_inst_0_BASE	0           	/* not exist */
#define RLIN39_inst_0_BASE	0           	/* not exist */
#define RLIN310_inst_0_BASE	0           	/* not exist */
#define RLIN311_inst_0_BASE	0           	/* not exist */
#define RLIN312_inst_0_BASE	0           	/* not exist */
#define RLIN313_inst_0_BASE	0           	/* not exist */
#define RLIN314_inst_0_BASE	0           	/* not exist */
#define RLIN315_inst_0_BASE	0           	/* not exist */
#define RLIN316_inst_0_BASE	0           	/* not exist */
#define RLIN317_inst_0_BASE	0           	/* not exist */
#define	RLIN318_inst_0_BASE	0           	/* not exist */
#define	RLIN319_inst_0_BASE	0           	/* not exist */
#define	RLIN320_inst_0_BASE	0           	/* not exist */
#define	RLIN321_inst_0_BASE	0           	/* not exist */
#define	RLIN322_inst_0_BASE	0           	/* not exist */
#define	RLIN323_inst_0_BASE	0           	/* not exist */

#elif defined(U5L1_QFP64)
#define RLIN30_inst_0_BASE	0x5C3B4000UL
#define RLIN31_inst_0_BASE	0x5D19B100UL
#define RLIN32_inst_0_BASE	0x5C3B4200UL
#define RLIN33_inst_0_BASE	0x5D19B300UL
#define RLIN34_inst_0_BASE	0           	/* not exist */
#define RLIN35_inst_0_BASE	0           	/* not exist */
#define RLIN36_inst_0_BASE	0           	/* not exist */
#define RLIN37_inst_0_BASE	0           	/* not exist */
#define RLIN38_inst_0_BASE	0           	/* not exist */
#define RLIN39_inst_0_BASE	0           	/* not exist */
#define RLIN310_inst_0_BASE	0           	/* not exist */
#define RLIN311_inst_0_BASE	0           	/* not exist */
#define RLIN312_inst_0_BASE	0           	/* not exist */
#define RLIN313_inst_0_BASE	0           	/* not exist */
#define RLIN314_inst_0_BASE	0           	/* not exist */
#define RLIN315_inst_0_BASE	0           	/* not exist */
#define RLIN316_inst_0_BASE	0           	/* not exist */
#define RLIN317_inst_0_BASE	0           	/* not exist */
#define	RLIN318_inst_0_BASE	0           	/* not exist */
#define	RLIN319_inst_0_BASE	0           	/* not exist */
#define	RLIN320_inst_0_BASE	0           	/* not exist */
#define	RLIN321_inst_0_BASE	0           	/* not exist */
#define	RLIN322_inst_0_BASE	0           	/* not exist */
#define	RLIN323_inst_0_BASE	0           	/* not exist */

#endif


/*******************************************************************************
* Definition of Index
*******************************************************************************/
#if defined(U5L4_BGA257)
#define	RLIN3_n_NUM 	18 	/* unit (n = 0 to 17) */
#define	RLIN3_n_EXIST 	0x0003FFFF	/* 1 means exist unit corresponding bit number. bit number = unit number.  */

#elif defined(U5L4_QFP176) || defined(U5L4_QFP144) || defined(U5L2_QFP176) || defined(U5L2_QFP144)
#define	RLIN3_n_NUM 	16 	/* unit (n = 0 to 15) */
#define	RLIN3_n_EXIST 	0x0000FFFF	/* 1 means exist unit corresponding bit number. bit number = unit number.  */

#elif defined(U5L4_QFP100)
#define	RLIN3_n_NUM 	14 	/* unit (n = 0 to 13) */
#define	RLIN3_n_EXIST 	0x00003FFF	/* 1 means exist unit corresponding bit number. bit number = unit number.  */

#elif defined(U5L2_QFP100)
#define	RLIN3_n_NUM 	12 	/* unit (n = 0 to 11) */
#define	RLIN3_n_EXIST 	0x00000FFF	/* 1 means exist unit corresponding bit number. bit number = unit number.  */

#elif defined(U5L2_QFP80) || defined(U5L1_QFP100)
#define	RLIN3_n_NUM 	8  	/* unit (n = 0 to 7) */
#define	RLIN3_n_EXIST 	0x000000FF	/* 1 means exist unit corresponding bit number. bit number = unit number.  */

#elif defined(U5L2_QFP64) || defined(U5L1_QFP80)
#define	RLIN3_n_NUM 	6 	/* unit (n = 0 to 5) */
#define	RLIN3_n_EXIST 	0x0000003F	/* 1 means exist unit corresponding bit number. bit number = unit number.  */

#elif defined(U5L1_QFP64)
#define	RLIN3_n_NUM 	4 	/* unit (n = 0 to 3) */
#define	RLIN3_n_EXIST 	0x0000000F	/* 1 means exist unit corresponding bit number. bit number = unit number.  */
#endif


/*******************************************************************************
* Prototype declarations of functions and
* functional definition (macro)
*******************************************************************************/
/* open RLIN3nTX pin */
void R_RLIN3_OpenRLIN3nTX( uint8_t n, uint8_t pin );

/* open RLIN3nRX pin */
void R_RLIN3_OpenRLIN3nRX( uint8_t n, uint8_t pin );

/* return RLIN3nTX pin to port mode */
void R_RLIN3_CloseRLIN3nTX( uint8_t n, uint8_t pin );

/* return RLIN3nRX pin to port mode */
void R_RLIN3_CloseRLIN3nRX( uint8_t n, uint8_t pin );


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_device_RLIN3_H__ */
