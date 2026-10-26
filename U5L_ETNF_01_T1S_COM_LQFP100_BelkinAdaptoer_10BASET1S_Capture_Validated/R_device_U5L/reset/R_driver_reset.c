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
* File Name    : R_driver_reset.c
* Version      : 1.00
* Device(s)    : Reset controller
* Device(s)    : R-Car U5L product
* Description  : Reset controller driver for R-Car U5L
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_reset.h"


/*******************************************************************************
* Section specification for entire file
*******************************************************************************/
#pragma	section	default


/*******************************************************************************
* Definitions
*******************************************************************************/
/* local definition for the function R_RES_AssertECMRES */
#define ECM00_inst_0_BASE 	0x5C3CD000UL
#define	ECM_base         	ECM00_inst_0_BASE

#define	rECMKCPROT   	(*(volatile uint32_t *) (ECM_base + 0x4B4) )          	/* ECM key code protection register */
#define	rECMESSTCj(j)	(*(volatile uint32_t *) (ECM_base + 0x478 + (j)*0x4) )	/* ECM error source status clear trigger register j */
#define	rECMIRCFGj(j)	(*(volatile uint32_t *) (ECM_base + 0x220 + (j)*0x4) )	/* ECM internal reset configuration register j */
#define	rECMPEj(j)   	(*(volatile uint32_t *) (ECM_base + 0x4B8 + (j)*0x4) )	/* ECM pseudo error trigger register j */

/* local definition for the function R_RES_AssertWDTBARES */
#define	WDTBA_base	0x5C0A5000UL
#define	rWDTBAMD  	(*(volatile uint8_t *) (WDTBA_base + 0x000C) )	/* WDTBA Mode register */
#define	rWDTBAWDTE	(*(volatile uint8_t *) (WDTBA_base + 0x0000) )	/* WDTBA Enable register */

/* local definition for the function R_RES_AssertVMONRES */
#define	rVMONKCPROT 	(*(volatile uint32_t *) (0x5C089700) )	/* VMON Register Key Code Protection Register */
#define	rVMONF      	(*(volatile uint8_t  *) (0x5C089400) )	/* VMON Factor Register */
#define	rVMONFC     	(*(volatile uint8_t  *) (0x5C089404) )	/* VMONF Clear Register */
#define	rVMONDMASK  	(*(volatile uint8_t  *) (0x5C089410) )	/* VMON Detection Output Diagnosis MASK Register */
#define	rVMONDIAG   	(*(volatile uint8_t  *) (0x5C089414) )	/* VMON DIAG Mode Setting Register */

/* local definition for the function R_RES_AssertDeepSTOPRES */
#define	rCSR_main      	(*(volatile uint32_t *) (0xE000ED10) )	/* SCR, System Control Register */
#define	rFCLACTL0_IRQ_0	(*(volatile uint8_t  *) (0x5C2D4A00) )	/* Filter control register for IRQ0*/
#define	rWUF0EN_A1   	(*(volatile uint32_t *) (0x5C08E418) )	/* Wake-Up Factor 0 Enable Register A0 */
#define	rWUFC_A1     	(*(volatile uint32_t *) (0x5C08E414) )	/* Wake-Up Factor Clear Register A0 */
#define	rSTBCKCPROT  	(*(volatile uint32_t *) (0x5C081700) )	/* Standby controller Register Key Code Protection Register */
#define	rSTBC0PSC    	(*(volatile uint32_t *) (0x5C088800) )	/* Power Save Control Register */


/*******************************************************************************
* Global variables
*******************************************************************************/


/*******************************************************************************
* Function body
*******************************************************************************/

/*******************************************************************************
* Description  : Asserts ECM reset by generation of ECM pseudo error
* Arguments    : none
* Return Value : none
*******************************************************************************/
void R_RES_AssertECMRES( void ){
	
	uint8_t 	j = 0;
	uint8_t 	x = 11;
	
	
	/* release write protection of ECM */
	rECMKCPROT = 0xA5A5A501;

	/* clear target ECM flag */
	rECMESSTCj(j) |= (1 << x);

	/* enable ECM internal reset */
	rECMIRCFGj(j) |= (1 << x);

	/* generate pseudo error */
	rECMPEj(j) |= (1 << x);

	/* set write protection of ECM */
	rECMKCPROT = 0xA5A5A500;

}


/*******************************************************************************
* Description  : Asserts WDTBA reset by writing incorrect code
* Arguments    : none
* Return Value : none
*******************************************************************************/
void R_RES_AssertWDTBARES( void ){

	/* initial setitng of WDTBA */
	rWDTBAMD = (0 << 7) |	/* window size is set by WDTBnWS bit */
	           (0 << 4) |	/* overflow interval time = 2^9 / WDTBTCKI */
	           (0 << 3) |	/* WDTBnTIT is disabled */
	           (1 << 2) |	/* Reset mode */
	           (0 << 0) ;	/* the period over which the window is open = 25% */

	/* start WDTB */
	rWDTBAWDTE = 0xAC;
	
	/* write incorrect code */
	rWDTBAWDTE = 0x53;
	
}


/*******************************************************************************
* Description  : Asserts VMON reset using diagnosis function
* Arguments    : none
* Return Value : none
*******************************************************************************/
void R_RES_AssertVMONRES( void ){
	
	/* release write protection */
	rVMONKCPROT = 0xA5A5A501;
	
	/* clear VMON all error flags */
	if( rVMONF != 0 ){
		rVMONFC = 0x0C;
	}
	
	/* not mask VMON Reset mask VMONOUT */
	rVMONDMASK = 0x02;
	
	/* forces VMON comparators to output error */
	rVMONDIAG = 0x0C;
	
	/* set write protection */
	rVMONKCPROT = 0xA5A5A500;
	
	/* wait specified time */
	wait( 100 );
	
}


/*******************************************************************************
* Description  : c
*                By causing a specific wake-up event to occur beforehand and 
*                then transitioning to DeepSTOP, a DeepSTOP reset occurs immediately.
* Arguments    : none
* Return Value : none
*******************************************************************************/
void R_RES_AssertDeepSTOPRES( void ){
	
	/* enable wakeup of INTP0 */
	rWUF0EN_A1 |= (1 << 0);

	/* generate wakeup */
	rFCLACTL0_IRQ_0 = (1 << 2) | (0 << 0);	/* Low level detection */
	rFCLACTL0_IRQ_0 = (1 << 2) | (1 << 0);	/* High level detection */

	/* after enabling Low level detection of High level detection,
	   WUF0 of INTP0 is set.*/
	
	/* Enter DeepSTOP mode with WUF1 set */
	/* SCR.SLEEPDEEP */
	rCSR_main |= (1 << 2);

	/* release write protect */
	rSTBCKCPROT = 0xA5A5A501;
	
	/* Enter DeepSTOP mode (STBC0DISTRG = 1) */
	rSTBC0PSC = (1 << 1);
	
	/* set write protect */
	rSTBCKCPROT = 0xA5A5A500;

#ifdef U5L
	/* wait for interrupt 
	   causes immediate entry to sleep mode unless the wakeup condition is true. 
	   When the processor executes a WFI instruction, it stops executing 
	   instructions and enters sleep mode. */
	__asm( "wfi" );
#endif

			
	while( 1 )
		;
}


/*******************************************************************************
* Description  : Clears setting of the function RES_AssertDeepSTOPRES
* Arguments    : none
* Return Value : none
*******************************************************************************/
void R_RES_AssertDeepSTOPRES_clear( void ){
	
	/* reset FCLA of INTP0 */
	rFCLACTL0_IRQ_0 = 0;
	
	/* disable wakeup of INTP0 */
	rWUF0EN_A1 &= ~(1 << 0);
	
	/* clear wakeup flag of INTP0 */
	rWUFC_A1 = (1 << 1);
}


/*******************************************************************************
* Return to default section
*******************************************************************************/
#pragma	section	default
