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
* File Name    : R_driver_reset.h
* Version      : 1.00
* Device(s)    : Reset controller
* Device(s)    : R-Car U5L product
* Description  : Reset controller driver for R-Car U5L
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_reset_H__
#define	__R_driver_reset_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_reset_reg.h"	/* for reference of register structure */
#include "R_driver_general.h"
#include "product.h"


/*******************************************************************************
* Extern of global variables
*******************************************************************************/


/*******************************************************************************
* Type definitions for the function return value
*******************************************************************************/
/* GearUp/GearDown */
typedef enum{
	RES_e_RESF_RSIP_SWSRES = (1 << 16),	/* RSIP-M30A Software System Reset Flag */
	RES_e_RESF_DEEPSTOP    = (1 << 15),	/* DeepSTOP Reset Flag */
	RES_e_RESF_WDTBARES    = (1 <<  7),	/* WDTBA Reset Flag */
	RES_e_RESF_ECMRES      = (1 <<  6),	/* ECM System Reset 1 Flag */
	RES_e_RESF_SWSRES      = (1 <<  4),	/* Software System Reset Flag */
	RES_e_RESF_VMONRES     = (1 <<  3),	/* VMON Reset Flag */
	RES_e_RESF_EXRES       = (1 <<  2),	/* External Reset Flag */
	RES_e_RESF_POCRES      = (1 <<  0) 	/* Power On Reset Flag */
}RES_e_RESF;


/*******************************************************************************
* Type definitions for the arguments of the function
*******************************************************************************/
#define	RES_ALLRES	(0x000080DD)	/* all effective bit of RESFC */


/*******************************************************************************
* Prototype declarations of functions and
* functional definition (macro)
*******************************************************************************/

/*******************************************************************************
* Description  : Release write protection for reset related registers
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_RES_ReleaseWriteProtect()	rRESKCPROT0.UINT32 = 0xA5A5A501

/*******************************************************************************
* Description  : Set write protection for reset related registers
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_RES_SetWriteProtect()    	rRESKCPROT0.UINT32 = 0xA5A5A500

/*******************************************************************************
* Description  : Clears reset flag
* Arguments    : RES_e_RESF factor: reset factor
* Return Value : none
* Example      :
*	R_RES_ClearRESF( RES_e_RESF_DEEPSTOP );	// Clear DeepSTOP Reset Flag
*	R_RES_ClearRESF( RES_e_RESF_WDTBARES );	// Clear WDTBA Reset Flag
*	R_RES_ClearRESF( RES_e_RESF_ECMRES );	// Clear ECM System Reset 1 Flag
*	R_RES_ClearRESF( RES_e_RESF_SWSRES );	// Clear Software System Reset Flag
*	R_RES_ClearRESF( RES_e_RESF_VMONRES );	// Clear VMON Reset Flag
*	R_RES_ClearRESF( RES_e_RESF_EXRES );	// Clear External Reset Flag
*	R_RES_ClearRESF( RES_e_RESF_POCRES );	// Clear Power On Reset Flag
*	// Clear Power On Reset Flag and External Reset Flag
*	R_RES_ClearRESF( RES_e_RESF_POCRES | RES_e_RESF_EXRES );
*******************************************************************************/
#define	R_RES_ClearRESF(factor)	rRESFC.UINT32 = (factor)

/*******************************************************************************
* Description  : Clears all reset flag
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_RES_ClearRESF_All()	R_RES_ClearRESF( RES_ALLRES )

/*******************************************************************************
* Description  : Checks whether specified reset generated or not.
* Arguments    : RES_e_RESF factor: reset factor
* Return Value : 0: Reset "factor" has not occured
*                1: Reset "factor" has occured
*******************************************************************************/
#define	R_RES_CheckRESF(factor)	((rRESF.UINT32 & factor) == factor)

/*******************************************************************************
* Description  : Asserts software software system reset
* Arguments    : RES_e_RESF factor: reset factor
* Return Value : 0: Reset "factor" has not occured
*                1: Reset "factor" has occured
*******************************************************************************/
#define	R_RES_AssertSWSRES()	R_RES_ReleaseWriteProtect(); \
                            	rSWSRESA.UINT32 = (1 << 0); \
								R_RES_SetWriteProtect()

/*******************************************************************************
* Description  : Asserts ECM reset by generation ECM pseudo error
* Arguments    : none
* Return Value : none
*******************************************************************************/
void R_RES_AssertECMRES( void );

/*******************************************************************************
* Description  : Asserts WDTBA reset by writing incorrect code
* Arguments    : none
* Return Value : none
*******************************************************************************/
void R_RES_AssertWDTBARES( void );

/*******************************************************************************
* Description  : Asserts VMON reset using diagnosis function
* Arguments    : none
* Return Value : none
*******************************************************************************/
void R_RES_AssertVMONRES( void );

/*******************************************************************************
* Description  : Asserts DeepSTOP Reset
*                By causing a specific wake-up event to occur beforehand and 
*                then transitioning to DeepSTOP, a DeepSTOP reset occurs immediately.
* Arguments    : none
* Return Value : none
*******************************************************************************/
void R_RES_AssertDeepSTOPRES( void );

/*******************************************************************************
* Description  : Clears setting of the function RES_AssertDeepSTOPRES
* Arguments    : none
* Return Value : none
*******************************************************************************/
void R_RES_AssertDeepSTOPRES_clear( void );

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_reset_H__ */
