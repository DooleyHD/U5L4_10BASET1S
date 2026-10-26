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
* File Name    : R_driver_INTC_reg.h
* Version      : 1.00
* Device(s)    : INTC
* Description  : This is source file for INTC driver.
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_INTC_reg_H__
#define	__R_driver_INTC_reg_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"

/*******************************************************************************
* Register Base Address Definitions
*******************************************************************************/
#define INTIF_base	0x5CE90000UL	/* INTIF00_inst_0_BASE */
#define EINT_base 	0x5C600000UL	/* EINT00_inst_0_BASE */
#define FENC_base 	0x5C0A3A00UL	/* FENC00_inst_0_BASE */
#define IMFU_base 	0x5CE80000UL	/* IMFU00_inst_0_BASE */

/*******************************************************************************
* Definition of register symbol
*******************************************************************************/
#define	rPINTk(k)    	(*(volatile INTC_s_PINTk     *) (INTIF_base + 0x00 + 0x04*(k)) ) 	/* Peripheral Interrupt Status Register */
#define	rPINTCLRk(k) 	(*(volatile INTC_s_PINTCLRk  *) (INTIF_base + 0x20 + 0x04*(k)) ) 	/* Peripheral Interrupt Status Clear Register */
#define	rSINTRp(p)   	(*(volatile INTC_s_SINTRp    *) (EINT_base + 0x4*(p)) )          	/* Software Interrupt Register p */
#define	rNMIF        	(*(volatile INTC_s_NMIF      *) (FENC_base) )                    	/* NMI Status Register */
#define	rNMIC        	(*(volatile INTC_s_NMIC      *) (FENC_base + 0x8) )              	/* NMI Status Clear Register */
#define	rIMFULFi(i)  	(*(volatile INTC_e_ctrl_IMFULFi   *) (IMFU_base + 0x10*(i)) )         	/* IMFU Level Status Register */
#define	rIMFULMSKi(i)	(*(volatile INTC_e_ctrl_IMFULMSKi *) (IMFU_base + 0x10*(i) + 0x4) )   	/* IMFU Level Mask Register */
#define	rIMFUPFj(j)  	(*(volatile INTC_e_ctrl_IMFUPFj   *) (IMFU_base + 0x10*(j) + 0x1000) )	/* IMFU Pulse Status Register */
#define	rIMFUPMSKj(j)	(*(volatile INTC_e_ctrl_IMFUPMSKj *) (IMFU_base + 0x10*(j) + 0x1004) )	/* IMFU Pulse Mask Register */
#define	rIMFUPCj(j)  	(*(volatile INTC_e_ctrl_IMFUPCj   *) (IMFU_base + 0x10*(j) + 0x1008) )	/* IMFU Pulse Clear Register */


/*******************************************************************************
* Definition of Register bit value
*******************************************************************************/
/* PINTk.INTDTSx (x = 0 to 7): DTS ch n transfer completion interrupt status */
typedef enum{
	INTC_e_INTDTS_no_request = 0,	/* 0: No transfer complete interrupt request present */
	INTC_e_INTDTS_requested  = 1 	/* 1: Transfer complete interrupt request present */
}INTC_e_INTDTS;

/* SINTRp.SINTCp[7:0]: This bit generates a software interrupt. */
typedef enum{
	INTC_e_SINTC_increment = 0x01,	/* Writing 01H: Increments the counter. */
	INTC_e_SINTC_decrement = 0x00 	/* Writing 00H: Decrements the counter. */
}INTC_e_SINTC;

/* NMIF.NMIF: External NMI interrupt flag */
typedef enum{
	INTC_e_NMIF_no_request = 0,	/* 0: No External NMI interrupt occurred. */
	INTC_e_NMIF_requested  = 1 	/* 1: External NMI interrupt occurred. */
}INTC_e_NMIF;

/* IMFULFi.LIFFx (x = 7 to 0): Interrupt factor flag. */
typedef enum{
	INTC_e_LIFF_no_request = 0,	/* 0: No interrupt factor detected */
	INTC_e_LIFF_requested  = 1 	/* 1: Interrupt factor detected */
}INTC_e_LIFF;

/* IMFULMSKi.LIFMSKx (x = 7 to 0): Interrupt factor is masked. */
typedef enum{
	INTC_e_LIFMSK_no_mask = 0,	/* 0: Not masked. */
	INTC_e_LIFMSK_mask    = 1 	/* 1: Masked. */
}INTC_e_LIFMSK;

/* IMFUPFj.PIFFx (x = 7 to 0): Interrupt factor flag. */
typedef enum{
	INTC_e_PIFF_no_request = 0,	/* 0: No interrupt factor detected */
	INTC_e_PIFF_requested  = 1 	/* 1: Interrupt factor detected */
}INTC_e_PIFF;

/* IMFUPMSKj.PIFMSKx (x = 7 to 0): Interrupt factor is masked. */
typedef enum{
	INTC_e_PIFMSK_no_mask = 0,	/* 0: Not masked. */
	INTC_e_PIFMSK_mask    = 1 	/* 1: Masked. */
}INTC_e_PIFMSK;


/*******************************************************************************
* Definition of Register typedef
*******************************************************************************/
/* PINTk register */
typedef union{
		uint32_t     	UINT32;	
	struct{
		INTC_e_INTDTS	INTDTS0   	:1;
		INTC_e_INTDTS	INTDTS1   	:1;
		INTC_e_INTDTS	INTDTS2   	:1;
		INTC_e_INTDTS	INTDTS3   	:1;
		INTC_e_INTDTS	INTDTS4   	:1;
		INTC_e_INTDTS	INTDTS5   	:1;
		INTC_e_INTDTS	INTDTS6   	:1;
		INTC_e_INTDTS	INTDTS7   	:1;
		uint32_t     	Reserved_8	:24;
	}BIT;
}INTC_s_PINTk;

/* PINTCLRk register */
typedef union{
		uint32_t     	UINT32;	
	struct{
		uint32_t     	INTCLR0   	:1;
		uint32_t     	INTCLR1   	:1;
		uint32_t     	INTCLR2   	:1;
		uint32_t     	INTCLR3   	:1;
		uint32_t     	INTCLR4   	:1;
		uint32_t     	INTCLR5   	:1;
		uint32_t     	INTCLR6   	:1;
		uint32_t     	INTCLR7   	:1;
		uint32_t     	Reserved_8	:24;
	}BIT;
}INTC_s_PINTCLRk;

/* SINTRp register */
typedef union{
		uint8_t      	UINT8;	
	struct{
		INTC_e_SINTC 	SINTC0    	:8;
	}BIT;
}INTC_s_SINTRp;

/* NMIF register */
typedef union{
		uint32_t     	UINT32;	
	struct{
		INTC_e_NMIF  	NMIF      	:1;
		uint32_t     	Reserved_1	:31;
	}BIT;
}INTC_s_NMIF;

/* NMIC register */
typedef union{
		uint32_t     	UINT32;	
	struct{
		uint32_t     	NMIC      	:1;
		uint32_t     	Reserved_1	:31;
	}BIT;
}INTC_s_NMIC;

/* IMFULFi register */
typedef union{
		uint32_t     	UINT32;	
	struct{
		INTC_e_LIFF  	LIFF      	:8;
		uint32_t     	Reserved_8	:24;
	}BIT;
}INTC_e_ctrl_IMFULFi;

/* IMFULMSKi register */
typedef union{
		uint32_t     	UINT32;	
	struct{
		INTC_e_LIFMSK	LIFMSK    	:8;
		uint32_t     	Reserved_8	:24;
	}BIT;
}INTC_e_ctrl_IMFULMSKi;

/* IMFUPFj register */
typedef union{
		uint32_t     	UINT32;	
	struct{
		INTC_e_PIFF  	PIFF      	:8;
		uint32_t     	Reserved_8	:24;
	}BIT;
}INTC_e_ctrl_IMFUPFj;

/* IMFUPMSKj register */
typedef union{
		uint32_t     	UINT32;
	struct{
		INTC_e_PIFMSK	PIFMSK    	:8;
		uint32_t     	Reserved_8	:24;
	}BIT;
}INTC_e_ctrl_IMFUPMSKj;

/* IMFUPCj register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	PIFC      	:8;
		uint32_t     	Reserved_8	:24;
	}BIT;
}INTC_e_ctrl_IMFUPCj;


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_INTC_reg_H__ */

