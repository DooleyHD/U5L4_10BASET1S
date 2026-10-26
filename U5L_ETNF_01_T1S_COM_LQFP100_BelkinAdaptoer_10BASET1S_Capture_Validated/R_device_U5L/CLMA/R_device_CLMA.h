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
* File Name    : R_device_CLMA.h
* Version      : 1.00
* Module(s)    : CLMA
* Device(s)    : R-Car U5L product
* Description  : This file contains product-specific descriptions of the CLMA 
*                drivers.
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_device_CLMA_H__
#define	__R_device_CLMA_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"
#include "product.h"


/*******************************************************************************
* Register Base Address Definitions
*******************************************************************************/
#define CLMAC_inst_0_BASE               0x5C081800UL
#define CLMA0_inst_0_BASE               0x5C081840UL
#define CLMA1_inst_0_BASE               0x5C081880UL
#define CLMA2_inst_0_BASE               0x5C0818C0UL
#define CLMA3_inst_0_BASE               0x5C081900UL
#define CLMA4_inst_0_BASE               0x5C081940UL
#define CLMA5_inst_0_BASE               0	/* not exist */
#define CLMA6_inst_0_BASE               0	/* not exist */
#define CLMA7_inst_0_BASE               0	/* not exist */
#define CLMA8_inst_0_BASE               0	/* not exist */
#define CLMA9_inst_0_BASE               0	/* not exist */
#define CLMA10_inst_0_BASE              0	/* not exist */
#define CLMA11_inst_0_BASE              0	/* not exist */
#define CLMA12_inst_0_BASE              0	/* not exist */
#define CLMA13_inst_0_BASE              0	/* not exist */
#define CLMA14_inst_0_BASE              0	/* not exist */
#define CLMA15_inst_0_BASE              0	/* not exist */
#define CLMA16_inst_0_BASE              0	/* not exist */
#define CLMA17_inst_0_BASE              0	/* not exist */


/*******************************************************************************
* Definition of Index
*******************************************************************************/
#define	CLMA_n_NUM 	5 	/* unit (n = 0 to 4) */
#define	CLMA_n_EXIST 	0x0000001F	/* 1 means exist unit corresponding bit number. bit number = unit number.  */


/*******************************************************************************
* Definition of lower/upper value
*******************************************************************************/
/* CLMA0
*******************************************************************************/
/* CLK_MOSC = 8MHz */
/* CLK_MOSC = 8MHz+/-0.1%, CLK_HSIOSC/128 = 0.125MHz+/-5% */
#define	CLMA0_LLIMIT_MOSC8MHz	(0x03CDU)	/* Lower limit */
#define	CLMA0_ULIMIT_MOSC8MHz	(0x0438U)	/* Upper limit */
/* CLK_MOSC = 16MHz */
/* CLK_MOSC = 16MHz+/-0.1%, CLK_HSIOSC/128 = 0.125MHz+/-5% */
#define	CLMA0_LLIMIT_MOSC16MHz	(0x079BU)	/* Lower limit */
#define	CLMA0_ULIMIT_MOSC16MHz	(0x086FU)	/* Upper limit */
/* CLK_MOSC = 20MHz */
/* CLK_MOSC = 20MHz+/-0.1%, CLK_HSIOSC/128 = 0.125MHz+/-5% */
#define	CLMA0_LLIMIT_MOSC20MHz	(0x0982U)	/* Lower limit */
#define	CLMA0_ULIMIT_MOSC20MHz	(0x0A8BU)	/* Upper limit */
/* CLK_MOSC = 24MHz */
/* CLK_MOSC = 24MHz+/-0.1%, CLK_HSIOSC/128 = 0.125MHz+/-5% */
#define	CLMA0_LLIMIT_MOSC24MHz	(0x0B69U)	/* Lower limit */
#define	CLMA0_ULIMIT_MOSC24MHz	(0x0CA6U)	/* Upper limit */

/* CLMA1 (CLMA1SEL=1)
*******************************************************************************/
/* CLK_HSIOSC = 16MHz+/-5%, CLK_LSIOSC = 0.24MHz+/-10% */
#define	CLMA1_LLIMIT_HSIOSC	(0x0398U)	/* Lower limit */
#define	CLMA1_ULIMIT_HSIOSC	(0x04DEU)	/* Upper limit */

/* CLMA1 (CLMA1SEL=0)
*******************************************************************************/
/* CLK_MOSC = 8MHz */
/* CLK_HSIOSC = 16MHz+/-5%, CLK_MOSC/32 = 0.25MHz+/-0.1% */
#define	CLMA1_LLIMIT_HSIOSC_MOSC8MHz	(0x03CAU)	/* Lower limit */
#define	CLMA1_ULIMIT_HSIOSC_MOSC8MHz	(0x0436U)	/* Upper limit */
/* CLK_MOSC = 16MHz */
/* CLK_HSIOSC = 16MHz+/-5%, CLK_MOSC/32 = 0.5MHz+/-0.1% */
#define	CLMA1_LLIMIT_HSIOSC_MOSC16MHz	(0x01E4U)	/* Lower limit */
#define	CLMA1_ULIMIT_HSIOSC_MOSC16MHz	(0x021CU)	/* Upper limit */
/* CLK_MOSC = 20MHz */
/* CLK_HSIOSC = 16MHz+/-5%, CLK_MOSC/32 = 0.625MHz+/-0.1% */
#define	CLMA1_LLIMIT_HSIOSC_MOSC20MHz	(0x0183U)	/* Lower limit */
#define	CLMA1_ULIMIT_HSIOSC_MOSC20MHz	(0x01B0U)	/* Upper limit */
/* CLK_MOSC = 24MHz */
/* CLK_HSIOSC = 16MHz+/-5%, CLK_MOSC/32 = 0.75MHz+/-0.1% */
#define	CLMA1_LLIMIT_HSIOSC_MOSC24MHz	(0x0142U)	/* Lower limit */
#define	CLMA1_ULIMIT_HSIOSC_MOSC24MHz	(0x0168U)	/* Upper limit */

/* CLMA2
*******************************************************************************/
/* CLK_LSIOSC = 0.24MHz+/-10%, CLK_HSIOSC/128 = 0.125MHz+/-5% */
#define	CLMA2_LLIMITCLK_LSIOSC	(0x0019U)	/* Lower limit */
#define	CLMA2_ULIMITCLK_LSIOSC	(0x0025U)	/* Upper limit */

/* CLMA3
*******************************************************************************/
/* CLK_MOSC = 8MHz */
/* CLK_BUS4 = 60MHz+/-0.1%, CLK_MOSC/32 = 0.25MHz+/-0.1% */
#define	CLMA3_LLIMIT_PLLO_0B_CKDIVMD11B_MOSC8MHz	(0x0EF7U)	/* Lower limit */
#define	CLMA3_ULIMIT_PLLO_0B_CKDIVMD11B_MOSC8MHz	(0x0F09U)	/* Upper limit */
/* CLK_BUS4 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.25MHz+/-0.1% */
#define	CLMA3_LLIMIT_PLLO_0B_CKDIVMD10B_MOSC8MHz	(0x09F9U)	/* Lower limit */
#define	CLMA3_ULIMIT_PLLO_0B_CKDIVMD10B_MOSC8MHz	(0x0A07U)	/* Upper limit */
/* CLK_BUS4 = 30MHz+/-0.1%, CLK_MOSC/32 = 0.25MHz+/-0.1% */
#define	CLMA3_LLIMIT_PLLO_0B_CKDIVMD0XB_MOSC8MHz	(0x077BU)	/* Lower limit */
#define	CLMA3_ULIMIT_PLLO_0B_CKDIVMD0XB_MOSC8MHz	(0x0785U)	/* Upper limit */
/* CLK_BUS4 = 30MHz+/-0.1%, CLK_MOSC/32 = 0.25MHz+/-0.1% */
#define	CLMA3_LLIMIT_PLLO_1B_MOSC8MHz	(0x077BU)	/* Lower limit */
#define	CLMA3_ULIMIT_PLLO_1B_MOSC8MHz	(0x0785U)	/* Upper limit */

/* CLK_MOSC = 16MHz */
/* CLK_BUS4 = 60MHz+/-0.1%, CLK_MOSC/32 = 0.5MHz+/-0.1% */
#define	CLMA3_LLIMIT_BUS4_PLLO_0B_CKDIVMD11B_MOSC16MHz	(0x077BU)	/* Lower limit */
#define	CLMA3_ULIMIT_BUS4_PLLO_0B_CKDIVMD11B_MOSC16MHz	(0x0785U)	/* Upper limit */
/* CLK_BUS4 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.5MHz+/-0.1% */
#define	CLMA3_LLIMIT_BUS4_PLLO_0B_CKDIVMD10B_MOSC16MHz	(0x04FCU)	/* Lower limit */
#define	CLMA3_ULIMIT_BUS4_PLLO_0B_CKDIVMD10B_MOSC16MHz	(0x0504U)	/* Upper limit */
/* CLK_BUS4 = 30MHz+/-0.1%, CLK_MOSC/32 = 0.5MHz+/-0.1% */
#define	CLMA3_LLIMIT_BUS4_PLLO_0B_CKDIVMD0XB_MOSC16MHz	(0x03BDU)	/* Lower limit */
#define	CLMA3_ULIMIT_BUS4_PLLO_0B_CKDIVMD0XB_MOSC16MHz	(0x03C3U)	/* Upper limit */
/* CLK_BUS4 = 30MHz+/-0.1%, CLK_MOSC/32 = 0.5MHz+/-0.1% */
#define	CLMA3_LLIMIT_BUS4_PLLO_1B_MOSC16MHz	(0x03BDU)	/* Lower limit */
#define	CLMA3_ULIMIT_BUS4_PLLO_1B_MOSC16MHz	(0x03C3U)	/* Upper limit */

/* CLK_MOSC = 20MHz */
/* CLK_BUS4 = 60MHz+/-0.1%, CLK_MOSC/32 = 0.625MHz+/-0.1% */
#define	CLMA3_LLIMIT_BUS4_PLLO_0B_CKDIVMD11B_MOSC20MHz	(0x05FBU)	/* Lower limit */
#define	CLMA3_ULIMIT_BUS4_PLLO_0B_CKDIVMD11B_MOSC20MHz	(0x0605U)	/* Upper limit */
/* CLK_BUS4 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.625MHz+/-0.1% */
#define	CLMA3_LLIMIT_BUS4_PLLO_0B_CKDIVMD10B_MOSC20MHz	(0x03FCU)	/* Lower limit */
#define	CLMA3_ULIMIT_BUS4_PLLO_0B_CKDIVMD10B_MOSC20MHz	(0x0404U)	/* Upper limit */
/* CLK_BUS4 = 30MHz+/-0.1%, CLK_MOSC/32 = 0.625MHz+/-0.1% */
#define	CLMA3_LLIMIT_BUS4_PLLO_0B_CKDIVMD0XB_MOSC20MHz	(0x02FDU)	/* Lower limit */
#define	CLMA3_ULIMIT_BUS4_PLLO_0B_CKDIVMD0XB_MOSC20MHz	(0x0303U)	/* Upper limit */
/* CLK_BUS4 = 30MHz+/-0.1%, CLK_MOSC/32 = 0.625MHz+/-0.1% */
#define	CLMA3_LLIMIT_BUS4_PLLO_1B_MOSC20MHz	(0x02FDU)	/* Lower limit */
#define	CLMA3_ULIMIT_BUS4_PLLO_1B_MOSC20MHz	(0x0303U)	/* Upper limit */

/* CLK_MOSC = 24MHz */
/* CLK_BUS4 = 60MHz+/-0.1%, CLK_MOSC/32 = 0.75MHz+/-0.1% */
#define	CLMA3_LLIMIT_BUS4_PLLO_0B_CKDIVMD11B_MOSC24MHz	(0x04FCU)	/* Lower limit */
#define	CLMA3_ULIMIT_BUS4_PLLO_0B_CKDIVMD11B_MOSC24MHz	(0x0504U)	/* Upper limit */
/* CLK_BUS4 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.75MHz+/-0.1% */
#define	CLMA3_LLIMIT_BUS4_PLLO_0B_CKDIVMD10B_MOSC24MHz	(0x0352U)	/* Lower limit */
#define	CLMA3_ULIMIT_BUS4_PLLO_0B_CKDIVMD10B_MOSC24MHz	(0x0359U)	/* Upper limit */
/* CLK_BUS4 = 30MHz+/-0.1%, CLK_MOSC/32 = 0.75MHz+/-0.1% */
#define	CLMA3_LLIMIT_BUS4_PLLO_0B_CKDIVMD0XB_MOSC24MHz	(0x027DU)	/* Lower limit */
#define	CLMA3_ULIMIT_BUS4_PLLO_0B_CKDIVMD0XB_MOSC24MHz	(0x0283U)	/* Upper limit */
/* CLK_BUS4 = 30MHz+/-0.1%, CLK_MOSC/32 = 0.75MHz+/-0.1% */
#define	CLMA3_LLIMIT_BUS4_PLLO_1B_MOSC24MHz	(0x027DU)	/* Lower limit */
#define	CLMA3_ULIMIT_BUS4_PLLO_1B_MOSC24MHz	(0x0283U)	/* Upper limit */

/* CLMA4
/* CLK_MOSC = 8MHz */
/* CLK_P040 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.25MHz+/-0.1% */
#define	CLMA4_LLIMIT_PLLO_CKDIVMD11B_MOSC8MHz	(0x09F9U)	/* Lower limit */
#define	CLMA4_ULIMIT_PLLO_CKDIVMD11B_MOSC8MHz	(0x0A07U)	/* Upper limit */
/* CLK_P040 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.25MHz+/-0.1% */
#define	CLMA4_LLIMIT_PLLO_CKDIVMD10B_MOSC8MHz	(0x09F9U)	/* Lower limit */
#define	CLMA4_ULIMIT_PLLO_CKDIVMD10B_MOSC8MHz	(0x0A07U)	/* Upper limit */
/* CLK_P040 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.25MHz+/-0.1% */
#define	CLMA4_LLIMIT_PLLO_CKDIVMD0XB_MOSC8MHz	(0x09F9U)	/* Lower limit */
#define	CLMA4_ULIMIT_PLLO_CKDIVMD0XB_MOSC8MHz	(0x0A07U)	/* Upper limit */

/* CLK_MOSC = 16MHz */
/* CLK_P040 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.5MHz+/-0.1% */
#define	CLMA4_LLIMIT_PLLO_CKDIVMD11B_MOSC16MHz	(0x04FCU)	/* Lower limit */
#define	CLMA4_ULIMIT_PLLO_CKDIVMD11B_MOSC16MHz	(0x0504U)	/* Upper limit */
/* CLK_P040 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.5MHz+/-0.1% */
#define	CLMA4_LLIMIT_PLLO_CKDIVMD10B_MOSC16MHz	(0x04FCU)	/* Lower limit */
#define	CLMA4_ULIMIT_PLLO_CKDIVMD10B_MOSC16MHz	(0x0504U)	/* Upper limit */
/* CLK_P040 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.5MHz+/-0.1% */
#define	CLMA4_LLIMIT_PLLO_CKDIVMD0XB_MOSC16MHz	(0x04FCU)	/* Lower limit */
#define	CLMA4_ULIMIT_PLLO_CKDIVMD0XB_MOSC16MHz	(0x0504U)	/* Upper limit */

/* CLK_MOSC = 20MHz */
/* CLK_P040 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.625MHz+/-0.1% */
#define	CLMA4_LLIMIT_PLLO_CKDIVMD11B_MOSC20MHz	(0x03FCU)	/* Lower limit */
#define	CLMA4_ULIMIT_PLLO_CKDIVMD11B_MOSC20MHz	(0x0404U)	/* Upper limit */
/* CLK_P040 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.625MHz+/-0.1% */
#define	CLMA4_LLIMIT_PLLO_CKDIVMD10B_MOSC20MHz	(0x03FCU)	/* Lower limit */
#define	CLMA4_ULIMIT_PLLO_CKDIVMD10B_MOSC20MHz	(0x0404U)	/* Upper limit */
/* CLK_P040 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.625MHz+/-0.1% */
#define	CLMA4_LLIMIT_PLLO_CKDIVMD0XB_MOSC20MHz	(0x03FCU)	/* Lower limit */
#define	CLMA4_ULIMIT_PLLO_CKDIVMD0XB_MOSC20MHz	(0x0404U)	/* Upper limit */

/* CLK_MOSC = 24MHz */
/* CLK_P040 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.75MHz+/-0.1% */
#define	CLMA4_LLIMIT_PLLO_CKDIVMD11B_MOSC24MHz	(0x0352U)	/* Lower limit */
#define	CLMA4_ULIMIT_PLLO_CKDIVMD11B_MOSC24MHz	(0x0359U)	/* Upper limit */
/* CLK_P040 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.75MHz+/-0.1% */
#define	CLMA4_LLIMIT_PLLO_CKDIVMD10B_MOSC24MHz	(0x0352U)	/* Lower limit */
#define	CLMA4_ULIMIT_PLLO_CKDIVMD10B_MOSC24MHz	(0x0359U)	/* Upper limit */
/* CLK_P040 = 40MHz+/-0.1%, CLK_MOSC/32 = 0.75MHz+/-0.1% */
#define	CLMA4_LLIMIT_PLLO_CKDIVMD0XB_MOSC24MHz	(0x0352U)	/* Lower limit */
#define	CLMA4_ULIMIT_PLLO_CKDIVMD0XB_MOSC24MHz	(0x0359U)	/* Upper limit */


/*******************************************************************************
* Definition of Register bit value
*******************************************************************************/
/* CLMAKCPROT.KCE: Key Code Enable bit */
typedef enum{
	CLMA_e_KCE_access_disable = 0,	/* 0: Disables write access of protected registers */
	CLMA_e_KCE_access_enable = 1,	/* 1: Enables write access of protected registers */
}CLMA_e_KCE;


/*******************************************************************************
* Definition of Register typedef
*******************************************************************************/
/* CLMAKCPROT register */
typedef union{
		uint32_t           	UINT32;
	struct{
		CLMA_e_KCE        	KCE        	:1;
		uint32_t          	KCPROT     	:31;
	}BIT;
}CLMA_s_CLMAKCPROT;


/*******************************************************************************
* Definition of register symbol
*******************************************************************************/
#define	rCLMAKCPROT     	(*(volatile CLMA_s_CLMAKCPROT   *) (0x5C081F00) )          	/* Clock Monitor Register Key Code Protection Register */


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_device_CLMA_H__ */
