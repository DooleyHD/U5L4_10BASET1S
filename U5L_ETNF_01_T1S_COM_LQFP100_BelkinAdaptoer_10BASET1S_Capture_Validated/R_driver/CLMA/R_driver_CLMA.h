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
* File Name    : R_driver_CLMA.h
* Version      : 1.00
* Module(s)    : CLMA
* Device(s)    : RH850 series product, R-Car U5L product
* Description  : CLMA driver that is used commonly by RH850 and R-Car products
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_CLMA_H__
#define	__R_driver_CLMA_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_CLMA_reg.h"	/* for reference of register structure */
#include "R_Device_CLMA.h"    	/* Product-specific definition */
#include "R_driver_general.h"  	/* common function */


/*******************************************************************************
* Extern of global variables
*******************************************************************************/
extern uint32_t	CLMAn_base[];


/*******************************************************************************
* Type definitions for the function return value
*******************************************************************************/


/*******************************************************************************
* Type definitions for the arguments of the function
*******************************************************************************/


/*******************************************************************************
* Prototype declarations of functions and
* functional definition (macro)
*******************************************************************************/

/*******************************************************************************
* Description  : Release write protection for CLMA related registers
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_CLMA_ReleaseWriteProtect()	rCLMAKCPROT.UINT32 = 0xA5A5A501


/*******************************************************************************
* Description  : Set write protection for CLMA related registers
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_CLMA_SetWriteProtect()	rCLMAKCPROT.UINT32 = 0xA5A5A500


/*******************************************************************************
* Description  : Set lower limit and upper limit
* Arguments    : uint8_t  n   : unit number of CLMA
*                uint16_t cmpl: lower limit [0 to 0x0FFF]
*                uint16_t cmph: upper limit [0 to 0x0FFF]
* Return Value : 0     : Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define R_CLMA_SetLimit(n,cmpl,cmph)	Reg16WRC( &rCLMAnCMPL(n).UINT16, (uint16_t)cmpl, 0x0FFF ); \
       	                            	Reg16WRC( &rCLMAnCMPH(n).UINT16, (uint16_t)cmph, 0x0FFF ) \


/*******************************************************************************
* Description  : Enalbe Stop detection mode
* Arguments    : uint8_t n: unit number of CLMA
* Return Value : 0     : Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_CLMA_EnalbeStopDetectionMode(n)	Reg08SetBitCheck( &rCLMAnSTPDTEN(n).UINT8, 0 )


/*******************************************************************************
* Description  : Disable Stop detection mode
* Arguments    : uint8_t n: unit number of CLMA
* Return Value : 0     : Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_CLMA_DisableStopDetectionMode(n)	Reg08ClearBitCheck( &rCLMAnSTPDTEN(n).UINT8, 0 )


/*******************************************************************************
* Description  : Enalbe backup clock function
* Arguments    : uint8_t n: unit number of CLMA
* Return Value : 0     : Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_CLMA_EnalbeBackupClock 	Reg08SetBitCheck( &CLMABCE.UINT8, 0 )


/*******************************************************************************
* Description  : Disable backup clock function
* Arguments    : uint8_t n: unit number of CLMA
* Return Value : 0     : Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_CLMA_DisableBackupClock	Reg08ClearBitCheck( &CLMABCE.UINT8, 0 )


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
uint8_t	R_CLMA_StartCLMA( uint8_t n, uint16_t cmpl, uint16_t cmph );


/*******************************************************************************
* Description  : Get error status of all CLMA units
* Arguments    : none
* Return Value : value of CLMATESTS register
*                0        : No error ocurred on all CLMA units
*                bit n = 1: Error occured on CLMAn
*******************************************************************************/
#define	R_CLMA_GetStatus()	rCLMATESTS.UINT32


/*******************************************************************************
* Description  : Reset CLMA
* Arguments    : uint8_t n: unit number of CLMA
* Return Value : non
*******************************************************************************/
uint8_t	R_CLMA_ResetCLMA( uint8_t n );


/*******************************************************************************
* Description  : Reset all unit of CLMA
* Arguments    : non
* Return Value : non
*******************************************************************************/
uint8_t	R_CLMA_ResetCLMA_All( void );


/*******************************************************************************
* Description  : Enable Self Test
* Arguments    : uint8_t n: unit number of CLMA
* Return Value : 0     : Register Readback check was successful
*                Others: Register Readback check was failed
* Remark       : bit 3: CLMA0TESEN, bit 4: CLMA1TESEN, ..., bit 3+n: CLMAnTESEN
*******************************************************************************/
#define	R_CLMA_EnableTest(n)	Reg32SetBitCheck( &rCLMATEST.UINT32, n + 3 );	/* CLMAnTESEN  = 1 */


/*******************************************************************************
* Description  : Enable Self Test
* Arguments    : uint8_t n: unit number of CLMA
* Return Value : 0     : Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_CLMA_EnableErrorMask(n)	Reg32SetBitCheck( &rCLMATEST.UINT32, 2 );	/* ERRMSK  = 1 */


/*******************************************************************************
* Description  : Enable Self Test
* Arguments    : uint8_t n: unit number of CLMA
* Return Value : 0     : Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_CLMA_DisableErrorMask(n)	Reg32ClearBitCheck( &rCLMATEST.UINT32, 2 );	/* ERRMSK  = 0 */


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_CLMA_H__ */
