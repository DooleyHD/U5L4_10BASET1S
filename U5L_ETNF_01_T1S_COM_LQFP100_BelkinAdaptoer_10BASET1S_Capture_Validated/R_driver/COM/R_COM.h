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
* File Name    : R_COM.h
* Version      : 1.00
* Device(s)    : RLIN3
* Description  : This is header file for printf function using RLIN3.
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_COM_H__
#define	__R_COM_H__


/*******************************************************************************
* Type definitions
*******************************************************************************/
/* RLIN clock list */
typedef enum{
	R_COM_e_clk_1_6MHz,	/* 1.6MHz (for CLK_CPU=CLK_HSIOSC) */
	R_COM_e_clk_4MHz,
	R_COM_e_clk_5MHz,
	R_COM_e_clk_8MHz,
	R_COM_e_clk_10MHz,
	R_COM_e_clk_20MHz,
	R_COM_e_clk_80MHz,
	R_COM_e_clk_num,
}R_COM_e_clk;

/* definition of label of baudrate */
typedef enum{
	R_COM_e_baudrate_9600bps = 0,
	R_COM_e_baudrate_14400bps,
	R_COM_e_baudrate_19200bps,
	R_COM_e_baudrate_38400bps,
	R_COM_e_baudrate_57600bps,
	R_COM_e_baudrate_115200bps,
	R_COM_e_baudrate_230400bps,
	R_COM_e_baudrate_460800bps,
	R_COM_e_baudrate_921600bps,
	R_COM_e_baudrate_num
}R_COM_e_baudrate;

/* general setting of UART */
typedef struct{
	uint8_t         	n;        	/* unit number of RLIN3 */
	uint32_t        	base_addr;	/* base address of RLIN3 to use */
	R_COM_e_baudrate	baudrate;	/* baudrate */
	R_COM_e_clk     	clk_freq;	/* frequency of RLIN3 PCLK */
}R_COM_s_setting;


/*******************************************************************************
* Prototype declarations of functions
*******************************************************************************/
/* Initial setting for using R_COM_printf */
uint8_t R_COM_Initialize( R_COM_s_setting setting );

/* transmits one data */
void R_COM_Tx( uint8_t n, uint8_t tx_data );

/* receive one data */
uint8_t R_COM_Rx( uint8_t n );

/* receive one byte */
uint8_t R_COM_ReadByte( void );

/* outputs characters in the same format as the printf function */
void R_COM_printf( int8_t *fmt, ... );

/* change RLIN3 unit to use the function R_COM_printf */
void R_COM_Change_Unit( uint8_t n );

#endif /* __R_COM_H__ */
