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
* File Name    : R_driver_reset_reg.h
* Version      : 1.00
* Module(s)    : Reset controller
* Device(s)    : R-Car U5L product
* Description  : Register definition of reset controller for R-Car U5L
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_reset_reg_H__
#define	__R_driver_reset_reg_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"


/*******************************************************************************
* Register Base Address Definitions
*******************************************************************************/
/* no definition */


/*******************************************************************************
* Definition of register symbol
*******************************************************************************/
#define	rRESKCPROT0	(*(volatile RES_s_RESKCPROT0 *) (0x5C080F00) )	/* Reset Controller Register Key Code Protection Register 0 */
#define	rSWSRESA   	(*(volatile RES_s_SWSRESA    *) (0x5C08840C) )	/* Software System Reset Assertion Register */
#define	rRESFC     	(*(volatile RES_s_RESFC      *) (0x5C088420) )	/* Reset Factor Clear Register */
#define	rRESF      	(*(volatile RES_s_RESF       *) (0x5C088500) )	/* Reset Factor Register */


/*******************************************************************************
* Definition of Register bit value
*******************************************************************************/
/* RESKCPROT0: Enable/Disables write access of protected registers */
typedef enum{
	RES_e_KCPROT_write_disable = 0xA5A5A500,	/* les write access of protected registers */
	RES_e_KCPROT_write_enable  = 0xA5A5A501 	/* es write access of protected registers */
}RES_e_KCPROT;

/* RESKCPROT0.KCE: Key Code Enable bit */
typedef enum{
	RES_e_KCE_write_disable = 0,	/* 0: Disables write access of protected registers */
	RES_e_KCE_write_enable  = 1 	/* 1: Enables write access of protected registers */
}RES_e_KCE;

/* RESF.RSIPMSRESF0: RSIP-M30A Software System SYS0_RESET Flag. */
/* RESF.DRESF0: DeepSTOP SYS0_RESET Flag. */
/* RESF.SRES1F4: WDTBA SYS0_RESET Flag */
/* RESF.SRES1F3: ECM System SYS0_RESET 1 Flag */
/* RESF.SRES2F0: Software System SYS0_RESET Flag */
/* RESF.SRES1F2: Primary VMON SYS0_RESET Flag */
/* RESF.SRES1F1: External SYS0_RESET Flag */
/* RESF.PRESF0: Power On SYS0_RESET Flag */
typedef enum{
	RES_e_RESFx_not_occurred = 0,	/* 0: No reset occurred */
	RES_e_RESFx_occurred     = 1 	/* 0: Reset occurred */
}RES_e_RESFx;


/*******************************************************************************
* Definition of Register typedef
*******************************************************************************/
/* RESKCPROT0 register */
typedef union{
		uint32_t  	UINT32;
	struct{
		RES_e_KCE 	KCE        	:1;
		uint32_t  	KCPROT     	:31;
	}BIT;
}RES_s_RESKCPROT0;

/* SWSRESA register */
typedef union{
		uint32_t  	UINT32;
	struct{
		uint32_t  	SWSRESA    	:1;
		uint32_t  	Reserved_1 	:31;
	}BIT;
}RES_s_SWSRESA;

/* RESFC register */
typedef union{
		uint32_t  	UINT32;
	struct{
		uint32_t  	PRESFC0    	:1;
		uint32_t  	Reserved_1 	:1;
		uint32_t  	SRES1FC1   	:1;
		uint32_t  	SRES1FC2   	:1;
		uint32_t  	SRES2FC0   	:1;
		uint32_t  	Reserved_5 	:1;
		uint32_t  	SRES1FC3   	:1;
		uint32_t  	SRES1FC4   	:1;
		uint32_t  	Reserved_8 	:7;
		uint32_t  	DRESFC0    	:1;
		uint32_t  	Reserved_16	:16;
	}BIT;
}RES_s_RESFC;

/* RESF register */
typedef union{
		uint32_t  	UINT32;
	struct{
		RES_e_RESFx	PRESF0     	:1;
		uint32_t   	Reserved_1 	:1;
		RES_e_RESFx	SRES1F1    	:1;
		RES_e_RESFx	SRES1F2    	:1;
		RES_e_RESFx	SRES2F0    	:1;
		uint32_t   	Reserved_5 	:1;
		RES_e_RESFx	SRES1F3    	:1;
		RES_e_RESFx	SRES1F4    	:1;
		uint32_t   	Reserved_8 	:7;
		RES_e_RESFx	DRESF0     	:1;
		RES_e_RESFx	RSIPMSRESF0	:1;
		uint32_t   	Reserved_17	:15;
	}BIT;
}RES_s_RESF;


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_reset_reg_H__ */

