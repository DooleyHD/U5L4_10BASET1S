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
* File Name    : R_driver_port.c
* Version      : 1.00
* Module(s)    : PORT
* Device(s)    : R-Car U5L product
* Description  : PORT function driver for R-Car U5L
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_port.h"
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

/* definition of relationship between port number and PWE bit number
   index of PORT_PWE_bit[] is same as port group number and 
   value of PORT_PWE_bit[] provides PWE bit number */
const uint8_t PORT_PWE_bit[] = 
	{ 0,		/* P0: bit 0 of PWE register */
	  1,		/* P1: bit 1 of PWE register */
	  2,		/* P2: bit 2 of PWE register */
	  3,		/* P3: bit 3 of PWE register */
	  0xFF,		/* P4: not exist */
	  0xFF,		/* P5: not exist */
	  0xFF,		/* P6: not exist */
	  0xFF,		/* P7: not exist */
	  4,		/* P8: bit 4 of PWE register */
	  5,		/* P9: bit 5 of PWE register */
	  6,		/* P10: bit 6 of PWE register */
	  7,		/* P11: bit 7 of PWE register */
	  8,		/* P12: bit 8 of PWE register */
	  9,		/* P13: bit 9 of PWE register */
	  0xFF,		/* P14: not exist */
	  0xFF,		/* P15: not exist */
	  0xFF,		/* P16: not exist */
	  0xFF,		/* P17: not exist */
	  10,  		/* P18: bit 10 of PWE register */
	  11,		/* P19: bit 11 of PWE register */
	  12,		/* P20: bit 12 of PWE register */
	  13,		/* P21: bit 13 of PWE register */
	  0xFF,		/* P22: not exist */
	  0xFF,		/* P23: not exist */
	  0xFF,		/* P24: not exist */
	  0xFF,		/* P25: not exist */
	  0xFF,		/* P26: not exist */
	  16		/* P27: bit 16 of PWE register */
	};
	
const uint8_t PORT_PWEAP_bit[] = 
	{ 20,		/* AP0: bit 20 of PWE register */
	  0xFF,		/* AP1: not exist */
	  22		/* AP2: bit 1 of PWE register */
	};
	
const uint8_t PORT_PWEIP_bit[] = 
	{ 26		/* IP0: bit 20 of PWE register */
	};


/*******************************************************************************
* Function body
*******************************************************************************/

/*******************************************************************************
* Description  : Releases write protection of specified port group.
* Arguments    : uint8_t n: port group number
*                PORT_e_kind kind: kind of target port
* Return Value : RET_OK       : Register Readback check was successful
*                RET_ERR_PARAM: Argument kind is out of range
*                RET_NONEED   : Port group n is not eligible for releasing write protection
*                RET_ERR_REG  : Register Readback check was failed
*******************************************************************************/
uint8_t R_PORT_ReleaseWriteProtect( uint8_t n, PORT_e_kind kind ){

	uint8_t 	ret;
	uint8_t 	bit;	/* target bit in PWE register */
	
	
	/* set target bit in PWE register */
	if( kind == PORT_e_kind_P ){
		bit = PORT_PWE_bit[n];
	}else if( kind == PORT_e_kind_AP ){
		bit = PORT_PWEAP_bit[n];
	}else if( kind == PORT_e_kind_IP ){
		bit = PORT_PWEIP_bit[n];
	}else if( kind == PORT_e_kind_JP ){
		return( RET_NONEED );   	/* no need to relase protection */
	}else{
		return( RET_ERR_PARAM );	/* kind is out of range */
	}
	
	if( bit == 0xFF ){
		return( RET_NONEED );   	/* no need to relase protection */
	}
	
	/* release write protection for PWE register */
	rPKCPROT.UINT32 = (uint32_t)PORT_e_PKCPROT_write_enable;
	
	/* enable to write */
	ret = Reg32SetBitCheck( &rPWE.UINT32, bit );
	
	/* set write protection for PWE register */
	rPKCPROT.UINT32 = (uint32_t)PORT_e_PKCPROT_write_disable;
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Sets write protection of specified port group.
* Arguments    : uint8_t n: port group number
*                PORT_e_kind kind: kind of target port
* Return Value : RET_OK       : Register Readback check was successful
*                RET_ERR_PARAM: Argument kind is out of range
*                RET_NONEED   : Port group n is not eligible for releasing write protection
*                RET_ERR_REG  : Register Readback check was failed
*******************************************************************************/
uint8_t R_PORT_SetWriteProtect( uint8_t n, PORT_e_kind kind ){

	uint8_t 	ret;
	uint8_t 	bit;	/* target bit in PWE register */
	
	
	/* set target bit in PWE register */
	if( kind == PORT_e_kind_P ){
		bit = PORT_PWE_bit[n];
	}else if( kind == PORT_e_kind_AP ){
		bit = PORT_PWEAP_bit[n];
	}else if( kind == PORT_e_kind_IP ){
		bit = PORT_PWEIP_bit[n];
	}else if( kind == PORT_e_kind_JP ){
		return( RET_NONEED );   	/* no need to relase protection */
	}else{
		return( RET_ERR_PARAM );	/* kind is out of range */
	}
	
	if( bit == 0xFF ){
		return( RET_NONEED );   	/* no need to relase protection */
	}
	
	/* release write protection for PWE register */
	rPKCPROT.UINT32 = (uint32_t)PORT_e_PKCPROT_write_enable;
	
	/* enable to write */
	ret = Reg32ClearBitCheck( &rPWE.UINT32, bit );
	
	/* set write protection for PWE register */
	rPKCPROT.UINT32 = (uint32_t)PORT_e_PKCPROT_write_disable;
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Changes alternative function.
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
*                uint8_t alt: alternative function number
*                PORT_e_IO io_mode: I/O
*                PORT_e_kind kind: kind of target port
* Return Value : RET_OK       : Register readback check was successful
*                RET_ERR_PARAM: Argument kind is out of range
*                RET_ERR_REG  : Register Readback check was failed
*******************************************************************************/
uint8_t R_PORT_ChangeAlt_nm( uint8_t n, uint8_t m, uint8_t alt, PORT_e_IO io_mode, PORT_e_kind kind ){
	
	uint32_t	value;
	uint8_t 	ret = RET_OK;
	uint8_t 	pwe_changed=FALSE;
	uint32_t	*pcr;
	uint8_t 	pwe_bit;	/* target bit position of PWE register */
	uint8_t 	pwe_value;	/* target bit position of PWE register */
	
	
	/* prepare */
	/**************************************************************************/
	switch( kind ){
		case PORT_e_kind_P:
			/* set PCR address */
			pcr = (uint32_t *)&rPCRn_m(n,m);
			
			/* get write protection state */
			pwe_bit = PORT_PWE_bit[n];
			pwe_value = (rPWE.UINT32 & (1 << pwe_bit)) >> pwe_bit;
			
			break;
			
		case PORT_e_kind_JP:
			/* set PCR address */
			pcr = (uint32_t *)&rJPCRn_m(n,m);
			
			/* set write protection state */
			pwe_bit = 0xFF;
			pwe_value = 1;	/* no write protection */
			
			break;
			
		default:
			return( RET_ERR_PARAM );
	}
	
	
	/* make write value */
	/**************************************************************************/
	/* initialize tartget port bit */
	value = 0x00000010;			/* PM=1, other bits=0 */
	
	/* select alternative function */
	value |= ((alt - 1) << 0);		/* {PFCEAE, PFCAE, PFCE, PFC} bit */
	
	/* set PIPC, PM, PMC */
	if( io_mode == PORT_e_IO_INOUT ){	/* using IP control */
		/* set PIPC bit */
		value |= (1 << 5);		/* PIPC=1 */
		
		/* set PMC bit */
		value |= (1 << 6);		/* PMC=1 */
		
	}else{                            	/* not using IP control */
		/* set PMC bit */
		value |= (1 << 6);		/* PMC=1 */
		
		/* set PM bit */
		if( io_mode == PORT_e_IO_OUT ){
			value &= ~(1 << 4);	/* PM=0 */
		}else{
			value |=  (1 << 4);	/* PM=1 */
		}
	}
	/* write target register */
	/**************************************************************************/
	/* check write protection for target port */
	if( (pwe_bit != 0xFF) && (pwe_value == 0) ){	/* not no protect and target bit = 0 */
		/* release write protection */
		R_PORT_ReleaseWriteProtect( n, kind );
		
		/* set PWE changed flag */
		pwe_changed = TRUE;
	}

	/* set register and check */
	ret = Reg32WRC( pcr, value, 0xFFFFFEFF );	/* no check PPR bit */
	
	/* restore write protection state */
	if( pwe_changed == TRUE ){	/* if write protection set before this function execute */
		/* set write protection */
		R_PORT_SetWriteProtect( n, kind );
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : Initialize port function.
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
*                PORT_e_kind kind: kind of target port
* Return Value : RET_OK       : Register readback check was successful
*                RET_ERR_PARAM: Argument kind is out of range
*                RET_ERR_REG  : Register Readback check was failed
*******************************************************************************/
uint8_t R_PORT_InitPort_nm( uint8_t n, uint8_t m, PORT_e_kind kind ){
	
	uint32_t	value;
	uint8_t 	ret = RET_OK;
	uint8_t 	pwe_changed=FALSE;
	uint32_t	*pcr;
	uint8_t 	pwe_bit;	/* target bit position of PWE register */
	uint8_t 	pwe_value;	/* target bit position of PWE register */
	
	
	/* prepare */
	/**************************************************************************/
	switch( kind ){
		case PORT_e_kind_P:
			/* set PCR address */
			pcr = (uint32_t *)&rPCRn_m(n,m);
			
			/* get write protection state */
			pwe_bit = PORT_PWE_bit[n];
			pwe_value = (rPWE.UINT32 & (1 << pwe_bit)) >> pwe_bit;
			
			break;
			
		case PORT_e_kind_JP:
			/* set PCR address */
			pcr = (uint32_t *)&rJPCRn_m(n,m);
			
			/* set write protection state */
			pwe_bit = 0xFF;
			pwe_value = 1;	/* no write protection */
			
			break;
			
		default:
			return( RET_ERR_PARAM );
	}
	
	
	/* make write value */
	/**************************************************************************/
	/* initialize tartget port bit */
	value = 0x00000010;			/* PM=1, other bits=0 */
	
	
	/* write target register */
	/**************************************************************************/
	/* check write protection for target port */
	if( (pwe_bit != 0xFF) && (pwe_value == 0) ){	/* not no protect and target bit = 0 */
		/* release write protection */
		R_PORT_ReleaseWriteProtect( n, kind );
		
		/* set PWE changed flag */
		pwe_changed = TRUE;
	}

	/* set register and check */
	ret = Reg32WRC( pcr, value, 0xFFFFFEFF );	/* no check PPR bit */
	
	/* restore write protection state */
	if( pwe_changed == TRUE ){	/* if write protection set before this function execute */
		/* set write protection */
		R_PORT_SetWriteProtect( n, kind );
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : Changes port drive strength.
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
*                PORT_e_st strength: drive strength
*                PORT_e_kind kind: kind of target port
* Return Value : RET_OK       : Register readback check was successful
*                RET_ERR_PARAM: Argument kind is out of range
*                RET_ERR_REG  : Register Readback check was failed
*******************************************************************************/
uint8_t R_PORT_ChangeStrength_nm( uint8_t n, uint8_t m, PORT_e_st strength, PORT_e_kind kind ){
	
	uint32_t	value;
	uint8_t 	ret = RET_OK;
	uint8_t 	pwe_changed=FALSE;
	uint32_t	*pcr;
	uint8_t 	pwe_bit;	/* target bit position of PWE register */
	uint8_t 	pwe_value;	/* target bit position of PWE register */
	
	
	/* prepare */
	/**************************************************************************/
	switch( kind ){
		case PORT_e_kind_P:
			/* set PCR address */
			pcr = (uint32_t *)&rPCRn_m(n,m);
			
			/* get write protection state */
			pwe_bit = PORT_PWE_bit[n];
			pwe_value = (rPWE.UINT32 & (1 << pwe_bit)) >> pwe_bit;
			
			break;
			
		case PORT_e_kind_JP:
			/* set PCR address */
			pcr = (uint32_t *)&rJPCRn_m(n,m);
			
			/* set write protection state */
			pwe_bit = 0xFF;
			pwe_value = 1;	/* no write protection */
			
			break;
			
		default:
			return( RET_ERR_PARAM );
	}
	
	
	/* make write value */
	/**************************************************************************/
	/* read current PCR register value */
	value = *pcr;
	
	/* make write value */
	switch( strength ){
	    case PORT_e_st_high:
	    case PORT_e_st_medium:
			value |=  (1 << 24);	/* JPDSCn_m=1 */
			
			break;
			
	    case PORT_e_st_low:
			value &= ~(1 << 24);	/* JPDSCn_m=0 */
			
			break;
			
	    default:
			break;
	}
	
	/* write target register */
	/**************************************************************************/
	/* check write protection for target port */
	if( (pwe_bit != 0xFF) && (pwe_value == 0) ){	/* not no protect and target bit = 0 */
		/* release write protection */
		R_PORT_ReleaseWriteProtect( n, kind );
		
		/* set PWE changed flag */
		pwe_changed = TRUE;
	}

	/* set register and check */
	ret = Reg32WRC( pcr, value, 0xFFFFFEFF );	/* no check PPR bit */
	
	/* restore write protection state */
	if( pwe_changed == TRUE ){	/* if write protection set before this function execute */
		/* set write protection */
		R_PORT_SetWriteProtect( n, kind );
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : Changes output buffer type (open-drain or push-pull).
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
*                PORT_e_outtype outtype: open-drain or push-pull
*                PORT_e_kind kind: kind of target port
* Return Value : RET_OK       : Register readback check was successful
*                RET_ERR_PARAM: Argument kind is out of range
*                RET_ERR_REG  : Register Readback check was failed
*******************************************************************************/
uint8_t R_PORT_ChangeOutputType_nm( uint8_t n, uint8_t m, PORT_e_outtype outtype, PORT_e_kind kind ){
	
	uint32_t	value;
	uint8_t 	ret = RET_OK;
	uint8_t 	pwe_changed=FALSE;
	uint32_t	*pcr;
	uint8_t 	pwe_bit;	/* target bit position of PWE register */
	uint8_t 	pwe_value;	/* target bit position of PWE register */
	
	
	/* prepare */
	switch( kind ){
		case PORT_e_kind_P:
			/* set PCR address */
			pcr = (uint32_t *)&rPCRn_m(n,m);
			
			/* get write protection state */
			pwe_bit = PORT_PWE_bit[n];
			pwe_value = (rPWE.UINT32 & (1 << pwe_bit)) >> pwe_bit;
			
			break;
			
		case PORT_e_kind_AP:
			/* set PCR address */
			pcr = (uint32_t *)&rAPCRn_m(n,m);
			
			/* get write protection state */
			pwe_bit = PORT_PWEAP_bit[n];
			pwe_value = (rPWE.UINT32 & (1 << pwe_bit)) >> pwe_bit;
			
			break;
			
		case PORT_e_kind_JP:
			/* set PCR address */
			pcr = (uint32_t *)&rJPCRn_m(n,m);
			
			/* set write protection state */
			pwe_bit = 0xFF;
			pwe_value = 1;	/* no write protection */
			
			break;
			
		default:
			return( RET_ERR_PARAM );
	}
	
	/* read current PCR register value */
	value = *pcr;
	
	/* make write value */
	switch( outtype ){
	    case PORT_e_outtype_pushpull:
			value &= ~(1 << 28);	/* PODCn_m  = 0 */
			value &= ~(1 << 27);	/* PODCEn_m = 0 */
			
			break;
			
	    case PORT_e_outtype_Nch_od:
			value |=  (1 << 28);	/* PODCn_m  = 1 */
			value &= ~(1 << 27);	/* PODCEn_m = 0 */
			
			break;
			
	    case PORT_e_outtype_Pch_od:
			value |=  (1 << 28);	/* PODCn_m  = 1 */
			value |=  (1 << 27);	/* PODCEn_m = 1 */
			
			break;
			
	    default:
			break;
	}
	
	/* check write protection for target port */
	if( (pwe_bit != 0xFF) && (pwe_value == 0) ){	/* not no protect and target bit = 0 */
		/* release write protection */
		R_PORT_ReleaseWriteProtect( n, kind );
		
		/* set PWE changed flag */
		pwe_changed = TRUE;
	}

	/* set register and check */
	ret = Reg32WRC( pcr, value, 0xFFFFFEFF );	/* no check PPR bit */
	
	/* restore write protection state */
	if( pwe_changed == TRUE ){	/* if write protection set before this function execute */
		/* set write protection */
		R_PORT_SetWriteProtect( n, kind );
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : Changes input buffer type (open-drain or push-pull).
* Arguments    : uint8_t n: port group number
*                uint8_t m: port bit number
*                PORT_e_intype intype: SHMT1 or SHMT4 or TTL
*                PORT_e_kind kind: kind of target port
* Return Value : RET_OK       : Register readback check was successful
*                RET_ERR_PARAM: Argument kind is out of range
*                RET_ERR_REG  : Register Readback check was failed
*******************************************************************************/
uint8_t R_PORT_ChangeInputType_nm( uint8_t n, uint8_t m, PORT_e_intype intype, PORT_e_kind kind ){
	
	uint32_t	value;
	uint8_t 	ret = RET_OK;
	uint8_t 	pwe_changed=FALSE;
	uint32_t	*pcr;
	uint8_t 	pwe_bit;	/* target bit position of PWE register */
	uint8_t 	pwe_value;	/* target bit position of PWE register */
	
	
	/* prepare */
	switch( kind ){
		case PORT_e_kind_P:
			/* set PCR address */
			pcr = (uint32_t *)&rPCRn_m(n,m);
			
			/* get write protection state */
			pwe_bit = PORT_PWE_bit[n];
			pwe_value = (rPWE.UINT32 & (1 << pwe_bit)) >> pwe_bit;
			
			break;
			
		case PORT_e_kind_AP:
			/* set PCR address */
			pcr = (uint32_t *)&rAPCRn_m(n,m);
			
			/* get write protection state */
			pwe_bit = PORT_PWEAP_bit[n];
			pwe_value = (rPWE.UINT32 & (1 << pwe_bit)) >> pwe_bit;
			
			break;
			
		case PORT_e_kind_JP:
			/* set PCR address */
			pcr = (uint32_t *)&rJPCRn_m(n,m);
			
			/* set write protection state */
			pwe_bit = 0xFF;
			pwe_value = 1;	/* no write protection */
			
			break;
			
		default:
			return( RET_ERR_PARAM );
	}
	
	/* read current PCR register value */
	value = *pcr;
	
	/* make write value */
	switch( intype ){
	    case PORT_e_intype_SHMT1:
			value &= ~(1 << 20);	/* PISn_m  = 0 */
			value &= ~(1 << 22);	/* PISAn_m = 0 */
			
			break;
			
	    case PORT_e_outtype_Nch_od:
			value |=  (1 << 20);	/* PISn_m  = 1 */
			value &= ~(1 << 22);	/* PISAn_m = 0 */
			
			break;
			
	    case PORT_e_outtype_Pch_od:
			value &= ~(1 << 20);	/* PISn_m  = 0 */
			value |=  (1 << 22);	/* PISAn_m = 1 */
			
			break;
			
	    default:
			break;
	}
	
	/* check write protection for target port */
	if( (pwe_bit != 0xFF) && (pwe_value == 0) ){	/* not no protect and target bit = 0 */
		/* release write protection */
		R_PORT_ReleaseWriteProtect( n, kind );
		
		/* set PWE changed flag */
		pwe_changed = TRUE;
	}

	/* set register and check */
	ret = Reg32WRC( pcr, value, 0xFFFFFEFF );	/* no check PPR bit */
	
	/* restore write protection state */
	if( pwe_changed == TRUE ){	/* if write protection set before this function execute */
		/* set write protection */
		R_PORT_SetWriteProtect( n, kind );
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : Configure filter control
* Arguments    : PORT_s_FCLACTLm *addr: address of filter control register
*                PORT_e_BYPS byps     : Bypass mode selection
*                PORT_e_INTx intx     : Detection mode selection
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_PORT_ConfigFilter( PORT_s_FCLACTLm *addr, PORT_e_BYPS byps, PORT_e_INTx intx ){

	uint8_t        	ret;
	PORT_s_FCLACTLm	value;


	/* prepare write value */
	value.BIT.INTx       = intx;
	value.BIT.Reserved_3 = 0;
	value.BIT.BYPS       = byps;

	/* Set register */
	ret = Reg08WRC( (volatile uint8_t *)addr, value.UINT8, 0x87 );


	return( ret );
}


/*******************************************************************************
* Return to default section
*******************************************************************************/
#pragma	section	default
