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
* File Name    : App_interrupt.h
* Version      : 1.00
* Description  : This file describes the interrupt processing .
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__App_interrupt_H__
#define	__App_interrupt_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "App_sub.h"
#include "App_main.h"

/* target module */
#include "R_driver_ETNF.h"


/*******************************************************************************
* Definition
*******************************************************************************/
/* None */


/*******************************************************************************
* Global variables
*******************************************************************************/
/* None */


/*******************************************************************************
* Prototype declarations of functions
* functional definition
*******************************************************************************/

/*******************************************************************************
* Description  : Handle data reception
* Arguments    : ETNF_s_DescType_Extend *rx_desc : Rx Descriptor Address
*                uint8_t queue_num : Rx Descriptor queue number
*                uint8_t desc_index: Rx Descriptor index
* Return Value : (none)
*******************************************************************************/
void App_Handle_Rx( ETNF_s_DescType_Extend *rx_desc, uint8_t queue_num, uint8_t desc_index );



/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __App_interrupt_H__ */

