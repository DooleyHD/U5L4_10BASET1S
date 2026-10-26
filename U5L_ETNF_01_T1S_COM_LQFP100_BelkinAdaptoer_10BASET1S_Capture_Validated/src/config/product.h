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
* File Name    : product.h
* Version      : 1.00
* Device(s)    : R-Car/U5L
* Description  : This is header file for product information.
*******************************************************************************/



/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__U5L_product_H__
#define	__U5L_product_H__


/*******************************************************************************
* Includes
*******************************************************************************/
/* no include file */


/*******************************************************************************
* Product Series Selection
* release comment out for target product.
*******************************************************************************/
	#define	U5L	/* R-Car/U5L */

/*******************************************************************************
* (2) Product/Package Selection for U5L
*     Please release comment out for target product.
*******************************************************************************/
//	#define	U5L4_BGA257	/* R-Car/U5L4 BGA257 */
//	#define	U5L4_QFP176	/* R-Car/U5L4 QFP176 */
//	#define	U5L4_QFP144	/* R-Car/U5L4 QFP144 */
	#define	U5L4_QFP100	/* R-Car/U5L4 QFP100 */
//	#define	U5L2_QFP176	/* R-Car/U5L2 QFP176 */
//	#define	U5L2_QFP144	/* R-Car/U5L2 QFP144 */
//	#define	U5L2_QFP100	/* R-Car/U5L2 QFP100 */
//	#define	"U5L2_QFP80	/* R-Car/U5L2 QFP80 */
//	#define	"U5L2_QFP64	/* R-Car/U5L2 QFP64 */
//	#define	U5L1_QFP100	/* R-Car/U5L1 QFP100 */
//	#define	"U5L1_QFP80	/* R-Car/U5L1 QFP80 */
//	#define	"U5L1_QFP64	"/* R-Car/U5L1 QFP64 */

	/* set CANXL support / CANXL does not support */
//	#define	U5L_wCANXL 	/* CANXL support          */
	#define	U5L_woCANXL	/* CANXL does not support */
	
	/* set ETNF support / ETNF does not support */
	#ifdef U5L_wCANXL
	#define	U5L_woETNF	/* ETNF does not support */
	#else
	#define	U5L_wETNF	/* ETNF support          */
	#endif

/* set U5L product series */
/* (no need to change Because it is automatically selected by select U5L product) */
#if defined(U5L4_BGA257) || defined(U5L4_QFP176) || defined(U5L4_QFP144) || defined(U5L4_QFP100)
	#define	U5L4
#elif defined(U5L2_QFP176) || defined(U5L2_QFP144) || defined(U5L2_QFP100) || defined(U5L2_QFP80) || defined(U5L2_QFP64)
	#define	U5L2
#elif defined(U5L1_QFP100) || defined(U5L1_QFP80) || defined(U5L1_QFP64)
	#define	U5L1
#endif

/* set package */
/* (no need to change Because it is automatically selected by select U2A product) */
#if defined(U5L4_BGA257)
	#define	BGA257
#elif defined(U5L4_QFP176) || defined(U5L2_QFP176)
	#define	QFP176
#elif defined(U5L4_QFP144) || defined(U5L2_QFP144)
	#define	QFP144
#elif defined(U5L4_QFP100) || defined(U5L2_QFP100) || defined(U5L1_QFP100)
	#define	QFP100
#elif defined(U5L2_QFP80) || defined(U5L1_QFP80)
	#define	QFP80
#elif defined(U5L2_QFP64) || defined(U5L1_QFP64)
	#define	QFP64
#endif


/*******************************************************************************
* (3) Definition of CPU RAM address and size
*******************************************************************************/
#if defined(U5L4)
/* CPU RAM (self) */
	#define	LRAMS_TOP	(0x200E0000U)
	#define	LRAMS_END	(0x200FFFFFU)
	#define	LRAMS_SIZE	(LRAMS_END + 1 - LRAMS_TOP)

/* CPU RAM (CPU0) */
	#define	LRAM0_TOP	(0x204E0000U)
	#define	LRAM0_END	(0x204FFFFFU)
	#define	LRAM0_SIZE	(LRAMS_END + 1 - LRAMS_TOP)

#elif defined(U5L2) || defined(U5L1)
/* CPU RAM (self) */
	#define	LRAMS_TOP	(0x200E0000U)
	#define	LRAMS_END	(0x200E7FFFU)
	#define	LRAMS_SIZE	(LRAMS_END + 1 - LRAMS_TOP)

/* CPU RAM (CPU0) */
	#define	LRAM0_TOP	(0x204E0000U)
	#define	LRAM0_END	(0x204E7FFFU)
	#define	LRAM0_SIZE	(LRAMS_END + 1 - LRAMS_TOP)
#endif


/*******************************************************************************
* (4) Definition of Global RAM address and size
*******************************************************************************/
#if defined(U5L4)
/* Global RAM (area which not depend on option bytes GRAM_SIZE) */
	#define	GRAM0_TOP	(0x28000000U)
	#define	GRAM0_END	(0x28057FFFU)
	#define	GRAM0_SIZE	(GRAM0_END + 1 - GRAM0_TOP)
	#define	GRAM_TOP 	GRAM0_TOP
	#define	GRAM_END 	GRAM0_END
	#define	GRAM_SIZE 	GRAM0_SIZE
/* Global RAM (area which depend on option bytes GRAM_SIZE) */
	#define	GRAM1_TOP	(0x28058000U)
	#define	GRAM1_END	(0x280AFFFFU)
	#define	GRAM1_SIZE	(GRAM1_END + 1 - GRAM1_TOP)

#elif defined(U5L2)
/* Global RAM */
	#define	GRAM_TOP	(0x28000000U)
	#define	GRAM_END	(0x2801FFFFU)
	#define	GRAM_SIZE	(GRAM_END + 1 - GRAM_TOP)

/* Global RAM */
	#define	GRAM_TOP	(0x28058000U)
	#define	GRAM_END	(0x280AFFFFU)
	#define	GRAM_SIZE	(GRAM_END + 1 - GRAM_TOP)
#endif

/*******************************************************************************
* (5) Definition of Retention RAM address and size
*******************************************************************************/
#if defined(U5L4) || defined(U5L2)
/* Retention RAM */
	#define	RRAM0_TOP	(0x2C000000U)
	#define	RRAM0_END	(0x2C000FFFU)
	#define	RRAM0_SIZE	(RRAM0_END + 1 - RRAM0_TOP)
	#define	RRAM1_TOP	(0x2C001000U)	/* OPBT.GRAM_SIZE = 0xB */
	#define	RRAM1_END	(0x2C003FFFU)
	#define	RRAM1_SIZE	(RRAM1_END + 1 - RRAM1_TOP)
	#define	RRAM2_TOP	(0x2C004000U)	/* OPBT.GRAM_SIZE = 10B */
	#define	RRAM2_END	(0x2C007FFFU)
	#define	RRAM2_SIZE	(RRAM2_END + 1 - RRAM2_TOP)
	#define	RRAM_TOP 	RRAM0_TOP	/* OPBT.GRAM_SIZE = 0xB */
	#define	RRAM_END 	RRAM2_END
	#define	RRAM_SIZE 	(RRAM_END  + 1 - RRAM_TOP )

#elif defined(U5L1)
/* Retention RAM */
	#define	RRAM0_TOP	(0x2C000000U)
	#define	RRAM0_END	(0x2C000FFFU)
	#define	RRAM0_SIZE	(RRAM0_END + 1 - RRAM0_TOP)
	#define	RRAM1_TOP	(0x2C001000U)	/* OPBT.GRAM_SIZE = 0xB */
	#define	RRAM1_END	(0x2C003FFFU)
	#define	RRAM1_SIZE	(RRAM1_END + 1 - RRAM1_TOP)
	#define	RRAM2_TOP	(0x2C002000U)	/* OPBT.GRAM_SIZE = 10B */
	#define	RRAM2_END	(0x2C007FFFU)
	#define	RRAM2_SIZE	(RRAM2_END + 1 - RRAM2_TOP)
	#define	RRAM_TOP 	RRAM0_TOP	/* OPBT.GRAM_SIZE = 0xB */
	#define	RRAM_END 	RRAM2_END
	#define	RRAM_SIZE 	(RRAM_END  + 1 - RRAM_TOP )
#endif


/*******************************************************************************
* DefinitionDefinition of module number
*******************************************************************************/
	#define	PE_NUM	(1U)
	#define	PE_EXIST	(0x00000001)

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif	/* __product_H__ */
