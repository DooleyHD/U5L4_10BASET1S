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
* Device(s)    : RH850/U2B product
* Description  : This file contains product-specific descriptions of the RLIN3 
*                drivers.
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_device_RSCFD_H__
#define	__R_device_RSCFD_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"
#include "product.h"
#include "R_driver_port.h"


/*******************************************************************************
* Register Base Address Definitions
*******************************************************************************/
#define	RSCFD0_inst_0_BASE 	0x5D000000UL
#define	RSCFD1_inst_0_BASE 	0	/* not exist */
#define	RSCFD2_inst_0_BASE 	0	/* not exist */


/*******************************************************************************
* Definition of Index
*******************************************************************************/
#define	RSCFD_n_NUM 	1 	/* unit (n = 0) */
#define	RSCFD_n_EXIST 	0x00000001	/* 1 means exist unit corresponding bit number. bit number = unit number.  */


/*******************************************************************************
* Prototype declarations of functions and
* functional definition (macro)
*******************************************************************************/
/* open CANnTX pin */
void R_RSCFD_OpenCANnTX( uint8_t n, uint8_t pin );

/* open CANnRX pin */
void R_RSCFD_OpenCANnRX( uint8_t n, uint8_t pin );


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_device_RSCFD_H__ */
