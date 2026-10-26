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
* File Name    : R_driver_CLMA.c
* Version      : 1.00
* Module(s)    : CLMA
* Description  : CLMA driver that is used commonly by RH850 and R-Car products
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_CLMA.h"


/*******************************************************************************
* Section specification for entire file
*******************************************************************************/
#pragma	section	default


/*******************************************************************************
* Definitions
*******************************************************************************/
/* Definition of base address */
uint32_t	CLMAn_base[] = { CLMA0_inst_0_BASE, 
        	                 CLMA1_inst_0_BASE,
        	                 CLMA2_inst_0_BASE,
        	                 CLMA3_inst_0_BASE,
        	                 CLMA4_inst_0_BASE,
        	                 CLMA5_inst_0_BASE,
        	                 CLMA6_inst_0_BASE,
        	                 CLMA7_inst_0_BASE,
        	                 CLMA8_inst_0_BASE,
        	                 CLMA9_inst_0_BASE,
        	                 CLMA10_inst_0_BASE,
        	                 CLMA11_inst_0_BASE,
        	                 CLMA12_inst_0_BASE,
        	                 CLMA13_inst_0_BASE,
        	                 CLMA14_inst_0_BASE,
        	                 CLMA15_inst_0_BASE,
        	                 CLMA16_inst_0_BASE,
        	                 CLMA17_inst_0_BASE };

/*******************************************************************************
* Global variables
*******************************************************************************/


/*******************************************************************************
* Function body
*******************************************************************************/

/*******************************************************************************
* Description  : Configure and start CLMA
* Arguments    : uint8_t  n   : unit number of CLMA
*                uint16_t cmpl: lower limit [0 to 0x0FFF]
*                uint16_t cmph: upper limit [0 to 0x0FFF]
* Return Value : 0     : Register Readback check was successful
*                Others: Register Readback check was failed
* Remark       : If you want to use backup clock and monitor clock detection modes, 
*                set them using following functions before executing this function.
*                    R_CLMA_EnalbeStopDetectionMode(n);
*                    R_CLMA_DisableStopDetectionMode(n);
*                    R_CLMA_EnalbeBackupClock(n);
*                    R_CLMA_DisableBackupClock(n);
*                This function sets the CLMA for each unit. On the other hand, 
*                the backup clock is separated from this function because it 
*                affects multiple units.
*******************************************************************************/
uint8_t	R_CLMA_StartCLMA( uint8_t n, uint16_t cmpl, uint16_t cmph ){
	
	uint8_t	ret;
	
	
	/* Release write protection */
	R_CLMA_ReleaseWriteProtect();
	
	/* Set the minimum and maximum value */
	ret = R_CLMA_SetLimit( n, cmpl, cmph );
	
	/* enable CLMA */
	ret = Reg08WRC( &rCLMAnCTL(n).UINT8, 0x01, 0x01 );
	
	/* Set write protection */
	R_CLMA_SetWriteProtect();
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Reset CLMA
* Arguments    : uint8_t n: unit number of CLMA
* Return Value : non
*******************************************************************************/
uint8_t	R_CLMA_ResetCLMA( uint8_t n ){
	
	uint8_t	ret;
	
	
	/* Release write protection */
	R_CLMA_ReleaseWriteProtect();
	
	/* Enable CLMAn reset */
	/* bit 3: CLMA0TESEN, bit 4: CLMA1TESEN, ..., bit 3+n: CLMAnTESEN */
	ret = Reg32SetBitCheck( &rCLMATEST.UINT32, n + 3 );	/* CLMAnTESEN  = 1 */
	
	/* Mask the Error Notification */
	ret = Reg32SetBitCheck( &rCLMATEST.UINT32, 2 );	/* ERRMSK  = 1 */
	
	/* Reset Clock Monitor */
	ret = Reg32SetBitCheck( &rCLMATEST.UINT32, 0 );	/* RESCLM  = 1 */
	
	/* Wait Clock Monitor Reset Time */
	/* The lowest sampling clock is CLK_LSIOSC/2. So, the wait needs at least 1/(240kHz/2) */
	wait( 1100*2 );	/* > 18.52us = 2/(Min. of CLK_LSIOSC/2) */
	
	/* Release Clock Monitor Reset */
	ret = Reg32ClearBitCheck( &rCLMATEST.UINT32, 0 );	/* RESCLM  = 0 */
	
	/* Release mask of the Error Notification */
	ret = Reg32ClearBitCheck( &rCLMATEST.UINT32, 2 );	/* ERRMSK  = 0 */
	
	/* Disable CLMA0 Reset */
	/* bit 3: CLMA0TESEN, bit 4: CLMA1TESEN, ..., bit 3+n: CLMAnTESEN */
	ret = Reg32ClearBitCheck( &rCLMATEST.UINT32, n + 3 );	/* CLMAnTESEN  = 0 */
	
	/* Set write protection */
	R_CLMA_SetWriteProtect();
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Reset all unit of CLMA
* Arguments    : non
* Return Value : non
*******************************************************************************/
uint8_t	R_CLMA_ResetCLMA_All( void ){
	
	uint8_t	ret;
	
	
	/* Release write protection */
	R_CLMA_ReleaseWriteProtect();
	
	/* Enable CLMAn reset */
	/* bit 3: CLMA0TESEN, bit 4: CLMA1TESEN, ..., bit 3+n: CLMAnTESEN */
	ret = Reg32WRC( &rCLMATEST.UINT32, CLMA_n_EXIST << 3, CLMA_n_EXIST << 3 );	/* all CLMAnTESEN  = 1 */
	
	/* Mask the Error Notification */
	ret = Reg32SetBitCheck( &rCLMATEST.UINT32, 2 );	/* ERRMSK  = 1 */
	
	/* Reset Clock Monitor */
	ret = Reg32SetBitCheck( &rCLMATEST.UINT32, 0 );	/* RESCLM  = 1 */
	
	/* Wait Clock Monitor Reset Time */
	/* The lowest sampling clock is CLK_LSIOSC/2. So, the wait needs at least 1/(240kHz/2) */
	wait( 1100*2 );	/* > 18.52us = 2/(Min. of CLK_LSIOSC/2) */
	
	/* Release Clock Monitor Reset */
	ret = Reg32ClearBitCheck( &rCLMATEST.UINT32, 0 );	/* RESCLM  = 0 */
	
	/* Release mask of the Error Notification */
	ret = Reg32ClearBitCheck( &rCLMATEST.UINT32, 2 );	/* ERRMSK  = 0 */
	
	/* Disable CLMA0 Reset */
	/* bit 3: CLMA0TESEN, bit 4: CLMA1TESEN, ..., bit 3+n: CLMAnTESEN */
	ret = Reg32WRC( &rCLMATEST.UINT32, 0, CLMA_n_EXIST << 3 );	/* all CLMAnTESEN  = 0 */
	
	/* Set write protection */
	R_CLMA_SetWriteProtect();
	
	
	return( ret );
}


/*******************************************************************************
* Return to default section
*******************************************************************************/
#pragma	section	default
