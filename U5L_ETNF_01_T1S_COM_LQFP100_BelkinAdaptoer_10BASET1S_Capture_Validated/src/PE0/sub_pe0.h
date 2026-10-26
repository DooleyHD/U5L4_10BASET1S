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
* File Name    : sub_pe0.h
* Version      : 1.00
* Description  : This header file describes sub routine for the application.
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__sub_pe0_H__
#define	__sub_pe0_H__


/*******************************************************************************
* Includes
*******************************************************************************/
/* general */
#include "R_driver_typedef.h"
#include "R_driver_general.h"
#include "product.h"
#include "config.h"

/* product-specified */
#include "R_driver_port.h"
#include "R_driver_clock.h"
#include "R_driver_reset.h"
#include "R_driver_standby.h"
#include "R_driver_INTC.h"

/* COM port communication */
#include "R_COM.h"
#include "R_device_RLIN3.h"	/* for pin setting */

/* Application */
#include "App_main.h"
#include "App_sub.h"

/*******************************************************************************
* Definition
*******************************************************************************/

/*******************************************************************************
* Prototype declarations of functions
* functional definition
*******************************************************************************/
/* start COM port communication */
void App_OpenCOMport( void );

/*******************************************************************************
* Description  : ETNF product-dependent settings
* Arguments    : None
* Return Value : None
*******************************************************************************/
void App_ConfigETNF_product( void );


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __sub_pe0_H__ */

