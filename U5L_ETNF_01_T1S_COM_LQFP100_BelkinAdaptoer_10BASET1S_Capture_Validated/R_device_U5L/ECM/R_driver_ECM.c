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
* File Name    : R_driver_ECM.c
* Version      : 1.00
* Device(s)    : ECM
* Description  : This is header file for ECM driver.
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_ECM.h"
#include "R_driver_general.h"

/*******************************************************************************
* Section specification for entire file
*******************************************************************************/
#pragma	section	default


/*******************************************************************************
* Definitions
*******************************************************************************/


/*******************************************************************************
* Global variables
*******************************************************************************/


/*******************************************************************************
* Function body
*******************************************************************************/

/*******************************************************************************
* Description  : Set ECM error mask
* Arguments    : uint8_t error_no: ECM error number
* Return Value : RET_OK     : Successful clearing of the specified error
*                RET_ERR_REG: Failed to clear the specified error
*******************************************************************************/
uint8_t R_ECM_SetErrorMask( uint16_t error_no ){

	uint8_t		j, x;
	uint8_t 	ret;


	/* Get register number and bit number */
	j = R_ECM_GetECMReg( error_no );
	x = R_ECM_GetECMBit( error_no );

	/* Release write protection for ECM related registers */
	R_ECM_ReleaseWriteProtect();

	/* Set ECM error mask */
	ret = Reg32SetBitCheck( &rECMEMKj(j).UINT32, x );

	/* Set write protection for ECM related registers */
	R_ECM_SetWriteProtect();


	return( ret );
}


/*******************************************************************************
* Description  : Clear ECM error mask
* Arguments    : uint8_t error_no: ECM error number
* Return Value : RET_OK     : Successful clearing of the specified error
*                RET_ERR_REG: Failed to clear the specified error
*******************************************************************************/
uint8_t R_ECM_ClearErrorMask( uint16_t error_no ){

	uint8_t		j, x;
	uint8_t 	ret;


	/* Get register number and bit number */
	j = R_ECM_GetECMReg( error_no );
	x = R_ECM_GetECMBit( error_no );

	/* Release write protection for ECM related registers */
	R_ECM_ReleaseWriteProtect();

	/* Set ECM error mask */
	ret = Reg32ClearBitCheck( &rECMEMKj(j).UINT32, x );

	/* Set write protection for ECM related registers */
	R_ECM_SetWriteProtect();


	return( ret );
}


/*******************************************************************************
* Description  : Clear ECM error status
* Arguments    : uint8_t error_no: ECM error number
* Return Value : RET_OK     : Successful clearing of the specified error
*                RET_ERR_REG: Failed to clear the specified error
*******************************************************************************/
uint8_t R_ECM_ClearErrorStatus( uint16_t error_no ){

	uint8_t		j, x;
	uint8_t 	ret;


	/* Get register number and bit number */
	j = R_ECM_GetECMReg( error_no );
	x = R_ECM_GetECMBit( error_no );

	/* Release write protection for ECM related registers */
	R_ECM_ReleaseWriteProtect();

	/* clear ECM error status */
	rECMESSTCj(j).UINT32 &= ~(1 << x);

	/* Set write protection for ECM related registers */
	R_ECM_SetWriteProtect();


	// check error status
	if( (rECMMESSTRj(j).UINT32 & (1 << x)) == 0 ){
		/* Successful clearing of the specified error */
		ret = RET_OK;
	}else{
		/* Failed to clear the specified error */
		ret = RET_ERR_REG;
	}


	return( ret );
}


/*******************************************************************************
* Description  : Clear all ECM error status
* Arguments    : uint8_t error_no: ECM error number
* Return Value : RET_OK     : Successful clearing of the specified error
*                RET_ERR_REG: Failed to clear the specified error
*******************************************************************************/
void R_ECM_ClearErrorStatus_All( void ){

	/* Release write protection for ECM related registers */
	R_ECM_ReleaseWriteProtect();

	/* clear ECM error status */
	for( int8_t j = 0; j < ECM_j_NUM; j++ ){
		rECMESSTCj(j).UINT32 = 0xFFFFFFFF;
	}

	/* Set write protection for ECM related registers */
	R_ECM_SetWriteProtect();


}


/*******************************************************************************
* Description  : Set ECM error status by pseudo error
* Arguments    : uint8_t error_no: ECM error number
* Return Value : (none)
*******************************************************************************/
void R_ECM_SetErrorStatus( uint16_t error_no ){

	uint8_t		j, x;


	/* Get register number and bit number */
	j = R_ECM_GetECMReg( error_no );
	x = R_ECM_GetECMBit( error_no );

	/* Release write protection for ECM related registers */
	R_ECM_ReleaseWriteProtect();

	/* disable ECM reset output */
	rECMIRCFGj(j).UINT32 &= ~(1 << x);

	/* assert pseudo error */
	rECMPEj(j).UINT32 = (1 << x);

	/* Set error trigger */
	rECMMESET.BIT.EST = 1;

	/* Set write protection for ECM related registers */
	R_ECM_SetWriteProtect();

}


/*******************************************************************************
* Description  : Sets ECM all error status by pseudo error
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void R_ECM_SetErrorStatus_All( void ){

	/* Release write protection for ECM related registers */
	R_ECM_ReleaseWriteProtect();

	/* Set pseudo error trigger */
	for( uint8_t j = 0; j < ECM_j_NUM; j++ ){
		/* disable ECM reset output */
		rECMIRCFGj(j).UINT32 = 0;

		/* assert pseudo error */
		rECMPEj(j).UINT32 = 0xFFFFFFFF;
	}

	/* Set error trigger */
	rECMMESET.BIT.EST = 1;

	/* Set write protection for ECM related registers */
	R_ECM_SetWriteProtect();

}


/*******************************************************************************
* Return to default section
*******************************************************************************/
#pragma	section	default
