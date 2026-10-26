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
* Copyright (C) 2023 Renesas Electronics Corporation. All rights reserved.     
*******************************************************************************/
/*******************************************************************************
* File Name    : R_driver_typedef.h
* Version      : 1.00
* Device(s)    : -
* Description  : General type that is used commonly
*******************************************************************************/

/*******************************************************************************
* Ver.1.00     : 2023/10/30
*                - Create New
*******************************************************************************/


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_typedef_H__
#define	__R_driver_typedef_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>


/*******************************************************************************
* Type Definition
*******************************************************************************/

/* use definition in stdint.h */
#if 0
typedef signed char       	int8_t;
typedef unsigned char     	uint8_t;
typedef short             	int16_t;
typedef unsigned short    	uint16_t;
//typedef int               	int32_t;
//typedef unsigned int      	uint32_t;
typedef long long         	int64_t;
typedef unsigned long long	uint64_t;
#endif

typedef	float             	float32;	/* E: 8 bit, M 23 bit */
typedef	double            	float64;	/* E: 11 bit, M 52 bit */

#endif /* __R_driver_typedef_H__ */
