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
* File Name    : R_driver_ECM.h
* Version      : 1.00
* Device(s)    : ECM
* Description  : This is source file for ECM driver.
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_ECM_H__
#define	__R_driver_ECM_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_ECM_reg.h"	/* for reference of register structure */


/*******************************************************************************
* Definition of Index
*******************************************************************************/
#define	ECM_i_NUM 	1 	/* i = 0 */
#define	ECM_j_NUM 	3 	/* j = 0 to 2 */
#define	ECM_k_NUM 	1 	/* k = 0 */


/*******************************************************************************
* Extern of global variables
*******************************************************************************/


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
* Description  : Release write protection for ECM related registers
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_ECM_ReleaseWriteProtect()	rECMKCPROT.UINT32 = 0xA5A5A501

/*******************************************************************************
* Description  : Set write protection for ECM related registers
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_ECM_SetWriteProtect()    	rECMKCPROT.UINT32 = 0xA5A5A500

/*******************************************************************************
* Description  : Get "j" number of ECMMESSTRj, ECMISCFGj, ECMIRCFGj, ...
*                from ECM Error Number
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define R_ECM_GetECMReg(error_no)	( (uint8_t)(error_no / 32 ))

/*******************************************************************************
* Description  : Get bit position of ECMMESSTRj, ECMISCFGj, ECMIRCFGj, ...
*                from ECM Error Number
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define R_ECM_GetECMBit(error_no)	( (uint8_t)(error_no % 32) )

/*******************************************************************************
* Description  : Set ECM error mask
* Arguments    : uint8_t error_no: ECM error number
* Return Value : RET_OK     : Successful clearing of the specified error
*                RET_ERR_REG: Failed to clear the specified error
*******************************************************************************/
uint8_t R_ECM_SetErrorMask( uint16_t error_no );

/*******************************************************************************
* Description  : Clear ECM error mask
* Arguments    : uint8_t error_no: ECM error number
* Return Value : RET_OK     : Successful clearing of the specified error
*                RET_ERR_REG: Failed to clear the specified error
*******************************************************************************/
uint8_t R_ECM_ClearErrorMask( uint16_t error_no );

/*******************************************************************************
* Description  : Clear ECM error status
* Arguments    : uint8_t error_no: ECM error number
* Return Value : RET_OK     : Successful clearing of the specified error
*                RET_ERR_REG: Failed to clear the specified error
*******************************************************************************/
uint8_t R_ECM_ClearErrorStatus( uint16_t error_no );

/*******************************************************************************
* Description  : Clear all ECM error status
* Arguments    : uint8_t error_no: ECM error number
* Return Value : RET_OK     : Successful clearing of the specified error
*                RET_ERR_REG: Failed to clear the specified error
*******************************************************************************/
void R_ECM_ClearErrorStatus_All( void );

/*******************************************************************************
* Description  : Set ECM error status by pseudo error
* Arguments    : uint8_t error_no: ECM error number
* Return Value : (none)
*******************************************************************************/
void R_ECM_SetErrorStatus( uint16_t error_no );

/*******************************************************************************
* Description  : Sets ECM all error status by pseudo error
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void R_ECM_SetErrorStatus_All( void );




/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_ECM_H__ */
