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
* File Name    : R_driver_CLMA_reg.h
* Version      : 1.00
* Module(s)    : CLMA
* Device(s)    : RH850 series product, R-Car U5L product
* Description  : Register definition of CLMA that is used commonly by RH850 and 
*                R-Car products
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_CLMA_reg_H__
#define	__R_driver_CLMA_reg_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"
#include "R_device_CLMA.h"    	/* Product-specific definition */


/*******************************************************************************
* Register Base Address Definitions
*******************************************************************************/
#define	CLMAn_base(n)       	CLMAn_base[n]
#define	CLMAC_base          	CLMAC_inst_0_BASE


/*******************************************************************************
* Definition of register symbol
*******************************************************************************/
#define	rCLMATEST       	(*(volatile CLMA_s_CLMATEST     *) (CLMAC_base + 0x00) )   	/* Clock Monitor Test Register */
#define	rCLMATESTS      	(*(volatile CLMA_s_CLMATESTS    *) (CLMAC_base + 0x04) )   	/* Clock Monitor Test Status Register */
#define	rCLMABCE        	(*(volatile CLMA_s_CLMABCE      *) (CLMAC_base + 0x08) )   	/* Clock Monitor Backup Clock Enable Register */
#define	rCLMAnCTL(n)    	(*(volatile CLMA_s_CLMAnCTL     *) (CLMAn_base(n) + 0x00) )	/* CLMAn Control Register */
#define	rCLMAnCMPL(n)   	(*(volatile CLMA_s_CLMAnCMPL    *) (CLMAn_base(n) + 0x08) )	/* CLMAn Comparison Register L */
#define	rCLMAnCMPH(n)   	(*(volatile CLMA_s_CLMAnCMPH    *) (CLMAn_base(n) + 0x0C) )	/* CLMAn Comparison Register H */
#define	rCLMAnSTPDTEN(n)	(*(volatile CLMA_s_CLMAnSTPDTEN *) (CLMAn_base(n) + 0x10) )	/* CLMA Clock Stop Detection Mode Enable Register */


/*******************************************************************************
* Definition of Register bit value
*******************************************************************************/
/* CLMAnCTL.CLME: Enable or disables the clock monitor. */
typedef enum{
	CLMA_e_CLME_disable = 0,	/* 0: Disables CLMA0. */
	CLMA_e_CLME_enable  = 1,	/* 1: Enables CLMA0. */
}CLMA_e_CLME;

/* CLMAnSTPDTEN.STPDTEN: CLMAn monitor stop detection mode enable/disable */
typedef enum{
	CLMA_e_STPDTEN_disable = 0,	/* 0: Stop Detection Mode is disabled. */
	CLMA_e_STPDTEN_enable = 1,	/* 1: Stop Detection Mode is enabled. */
}CLMA_e_STPDTEN;

/* CLMATEST.TESEN: CLMAn self-test enable/disable */
typedef enum{
	CLMA_e_TESEN_disable = 0,	/* 0: Test disabled. */
	CLMA_e_TESEN_enable = 1,	/* 1: Test enabled. */
}CLMA_e_TESEN;

/* CLMATEST.ERRMSK: CLMA test error mask setting */
typedef enum{
	CLMA_e_ERRMSK_no_mask = 0,	/* 0: Error signal generation enabled */
	CLMA_e_ERRMSK_mask = 1,	/* 1: Error signal generation disabled (masked) */
}CLMA_e_ERRMSK;

/* CLMATEST.MONCLKMSK: Monitor clock mask setting */
typedef enum{
	CLMA_e_MONCLKMSK_no_mask = 0,	/* 0: Monitored clock enabled */
	CLMA_e_MONCLKMSK_mask = 1,	/* 1: Monitored clock disabled (masked) */
}CLMA_e_MONCLKMSK;

/* CLMATEST.RESCLM: CLMAn test reset signal control */
typedef enum{
	CLMA_e_RESCLM_no_mask = 0,	/* 0: Reset signal for CLMAn is released. */
	CLMA_e_RESCLM_mask = 1,	/* 1: Reset signal for CLMAn is asserted. */
}CLMA_e_RESCLM;

/* CLMATESTS.ERRS: CLMAn error status */
typedef enum{
	CLMA_e_ERRS_no_error = 0,	/* 0: No error detected */
	CLMA_e_ERRS_error = 1,	/* 1: Error detected */
}CLMA_e_ERRS;

/* CLMABCE.BCE: Backup clock switching control */
typedef enum{
	CLMA_e_BCE_disable = 0,	/* 0: Disable the backup clock function */
	CLMA_e_BCE_enable = 1,	/* 1: Enable the backup clock function */
}CLMA_e_BCE;


/*******************************************************************************
* Definition of Register typedef
*******************************************************************************/
/* CLMAnCTL register */
typedef union{
		uint8_t           	UINT8;
	struct{
		CLMA_e_CLME       	CLME       	:1;
		uint8_t           	Reserved_1 	:7;
	}BIT;
}CLMA_s_CLMAnCTL;

/* CLMAnCMPL register */
typedef union{
		uint16_t          	UINT16;
	struct{
		uint16_t          	CMPL       	:12;
		uint16_t          	Reserved_12	:4;
	}BIT;
}CLMA_s_CLMAnCMPL;

/* CLMAnCMPH register */
typedef union{
		uint16_t          	UINT16;
	struct{
		uint16_t          	CMPH       	:12;
		uint16_t          	Reserved_12	:4;
	}BIT;
}CLMA_s_CLMAnCMPH;

/* CLMAnSTPDTEN register */
typedef union{
		uint8_t           	UINT8;
	struct{
		CLMA_e_STPDTEN    	STPDTEN    	:1;
		uint8_t           	Reserved_1 	:7;
	}BIT;
}CLMA_s_CLMAnSTPDTEN;

/* CLMATEST register */
typedef union{
		uint32_t          	UINT32;
	struct{
		CLMA_e_RESCLM    	RESCLM     	:1;
		CLMA_e_MONCLKMSK 	MONCLKMSK  	:1;
		CLMA_e_ERRMSK    	ERRMSK     	:1;
		CLMA_e_TESEN       	CLMA0TESEN 	:1;
		CLMA_e_TESEN       	CLMA1TESEN 	:1;
		CLMA_e_TESEN       	CLMA2TESEN 	:1;
		CLMA_e_TESEN       	CLMA3TESEN 	:1;
		CLMA_e_TESEN       	CLMA4TESEN 	:1;
		uint32_t          	Reserved_8 	:24;
	}BIT;
}CLMA_s_CLMATEST;

/* CLMATESTS register */
typedef union{
		uint32_t          	UINT32;
	struct{
		CLMA_e_ERRS        	CLMA0ERRS  	:1;
		CLMA_e_ERRS        	CLMA1ERRS  	:1;
		CLMA_e_ERRS        	CLMA2ERRS  	:1;
		CLMA_e_ERRS        	CLMA3ERRS  	:1;
		CLMA_e_ERRS        	CLMA4ERRS  	:1;
		uint32_t          	Reserved_5 	:27;
	}BIT;
}CLMA_s_CLMATESTS;

/* CLMABCE register */
typedef union{
		uint8_t           	UINT8;
	struct{
		CLMA_e_BCE        	BCE        	:1;
		uint8_t           	Reserved_1 	:7;
	}BIT;
}CLMA_s_CLMABCE;


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_CLMA_reg_H__ */

