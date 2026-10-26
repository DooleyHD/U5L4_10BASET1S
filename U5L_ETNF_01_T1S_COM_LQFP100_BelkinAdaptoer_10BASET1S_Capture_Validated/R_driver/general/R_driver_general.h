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
* Copyright (C) 2023 Renesas Electronics Corporation. All rights reserved.     
*******************************************************************************/
/*******************************************************************************
* File Name    : R_driver_general.h
* Version      : 1.00
* Device(s)    : -
* Description  : General function that is used commonly by products
*******************************************************************************/

/*******************************************************************************
* Ver.1.00     : 2023/10/30
*                - Create New
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_general_H__
#define	__R_driver_general_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"


/*******************************************************************************
* Type definition
*******************************************************************************/
/* for enable, disable */
typedef enum{
	disable = 0,	/* disable */
	enable  = 1,	/* enable */
}GE_e_endis;

typedef enum{
	enable_r  = 0,	/* enable */
	disable_r = 1,	/* disable */
}GE_e_disen;

/* for mask, no mask */
typedef enum{
	unmask = 0,  	/* release mask */
	mask   = 1,  	/* set mask */
}GE_e_mask;

typedef enum{
	mask_r   = 0,	/* set mask */
	unmask_r = 1,	/* release mask */
}GE_e_mask_r;

/* for supply, stop */
typedef enum{
	stop   = 0,  	/* stop */
	supply = 1,  	/* supply */
}GE_e_spply;

typedef enum{
	stop_r   = 1,	/* stop */
	supply_r = 0, 	/* supply */
}GE_e_spply_r;

typedef enum{
	nofunc = 0,  	/* no function */
	assert = 1,  	/* assert */
}GE_e_assert;


/*******************************************************************************
* Definitions
*******************************************************************************/
/* Return value of the general function */
#define	RET_OK       	(0U)	/* no error */
#define	RET_ERR_REG  	(1U)	/* register compare check error */
#define	RET_ERR_PARAM	(2U)	/* argument error */
#define	RET_ERR_STATE	(3U)	/* status error */
#define	RET_ERR_TIMEOUT	(4U)	/* timeout error */
#define	RET_NONEED   	(5U)	/* not need to execute this function */

#define	RET_TRUE  	(0U)
#define	RET_FALSE  	(0xFFU)
	
/* ture/false */
#define	TRUE	(1U)
#define	FALSE	(0U)

/* Retention RAM status */
#define	RRAM_STAT	(*(volatile uint32_t *) (RRAM_TOP + 0x8) )	/* Retention RAM status */
#define	RRAM_CC_END	(0xC0DEFF00U)                             	/* Finished writing the program to RRAM */


/*******************************************************************************
* Prototype declarations of functions and 
* Functional definitions
*******************************************************************************/
/* Wait functions *************************************************************/
/* waits by loop */
void wait( uint32_t count );

/* waits of us unit by loop */
void wait_us( uint32_t time_us );

/* waits of ms unit by loop */
void wait_ms( uint32_t time_ms );

/* waits of sec unit by loop */
void wait_sec( uint32_t time_sec );

/* General functions **********************************************************/
/* calcurates value^n */
int32_t power( int32_t value, uint8_t n );

/* Functions for register operation *******************************************/
/* register write, read and check for no wirte protected register */
uint8_t Reg32WRC( volatile uint32_t *write_reg, uint32_t write_data, uint32_t mask );
uint8_t Reg16WRC( volatile uint16_t *write_reg, uint16_t write_data, uint16_t mask );
uint8_t Reg08WRC( volatile uint8_t *write_reg, uint8_t write_data, uint8_t mask );

/* register write, read and check for wirte protected register */
uint8_t Reg32WRCp( volatile uint32_t *kprot_reg, volatile uint32_t *write_reg, uint32_t write_data, uint32_t mask );
uint8_t Reg16WRCp( volatile uint32_t *kprot_reg, volatile uint16_t *write_reg, uint16_t write_data, uint16_t mask );
uint8_t Reg08WRCp( volatile uint32_t *kprot_reg, volatile uint8_t *write_reg, uint8_t write_data, uint8_t mask );

/* register read and check */
uint8_t Reg32RC( volatile uint32_t *read_reg, uint32_t expect_data, uint32_t mask );
uint8_t Reg16RC( volatile uint16_t *read_reg, uint16_t expect_data, uint16_t mask );
uint8_t Reg08RC( volatile uint8_t *read_reg, uint8_t expect_data, uint8_t mask );

/* register write, read and check for only specified bits */
uint8_t Reg32RMWC( volatile uint32_t *write_reg, uint32_t write_data, uint32_t bitrange, uint8_t position );
uint8_t Reg16RMWC( volatile uint16_t *write_reg, uint16_t write_data, uint16_t bitrange, uint8_t position );
uint8_t Reg08RMWC( volatile uint8_t *write_reg, uint8_t write_data, uint8_t bitrange, uint8_t position );

/* register write for only specified */
void Reg32RMW( volatile uint32_t *write_reg, uint32_t write_data, uint32_t bitrange, uint8_t position );
void Reg16RMW( volatile uint16_t *write_reg, uint16_t write_data, uint16_t bitrange, uint8_t position );
void Reg08RMW( volatile uint8_t *write_reg, uint8_t write_data, uint8_t bitrange, uint8_t position );

/* register set specified bit and check */
uint8_t Reg32SetBitCheck( volatile uint32_t *write_reg, uint8_t bit );
uint8_t Reg16SetBitCheck( volatile uint16_t *write_reg, uint8_t bit );
uint8_t Reg08SetBitCheck( volatile uint8_t *write_reg, uint8_t bit );

/* register clear specified bit and check */
uint8_t Reg32ClearBitCheck( volatile uint32_t *write_reg, uint8_t bit );
uint8_t Reg16ClearBitCheck( volatile uint16_t *write_reg, uint8_t bit );
uint8_t Reg08ClearBitCheck( volatile uint8_t *write_reg, uint8_t bit );

/* register set specified bit */
void Reg32SetBit( volatile uint32_t *write_reg, uint8_t bit );
void Reg16SetBit( volatile uint16_t *write_reg, uint8_t bit );
void Reg08SetBit( volatile uint8_t *write_reg, uint8_t bit );

/* register clear specified bit */
void Reg32ClearBit( volatile uint32_t *write_reg, uint8_t bit );
void Reg16ClearBit( volatile uint16_t *write_reg, uint8_t bit );
void Reg08ClearBit( volatile uint8_t *write_reg, uint8_t bit );

/* wait until specified bit becomes 1 */
void Reg32Wait1( volatile uint32_t *reg, uint8_t position );
void Reg16Wait1( volatile uint16_t *reg, uint8_t position );
void Reg08Wait1( volatile uint8_t *reg, uint8_t position );

/* wait until specified bit becomes 0 */
void Reg32Wait0( volatile uint32_t *reg, uint8_t position );
void Reg16Wait0( volatile uint16_t *reg, uint8_t position );
void Reg08Wait0( volatile uint8_t *reg, uint8_t position );

/*******************************************************************************
* Function Name: Sync_RegisterRead
* Description  : This function waits by previous read access end
* Arguments    : none
* Return Value : none
*******************************************************************************/
void Sync_RegisterRead( void );

/*******************************************************************************
* Function Name: Sync_RegisterRead
* Description  : This function reads work arround for U5L4 CPU read.
*                wait until all read access is complete
* Arguments    : None
* Return Value : None
*******************************************************************************/
#if defined(U5L4_CPUREAD_WA)
#define	Sync_RegisterRead()	__asm volatile( "dsb" )
#else
#define	Sync_RegisterRead()
#endif


/*******************************************************************************
* Function Name: Reg32Read
* Description  : This function reads register by 32-bit width
* Arguments    : *(volatile uint32_t *) reg: 32-bit register
* Return Value : read value
*******************************************************************************/
#define Reg32Read(reg)	({ \
	unsigned int read = (unsigned int)(reg); \
	Sync_RegisterRead(); \
	reg; \
})


/*******************************************************************************
* Function Name: Reg16Read
* Description  : This function reads register by 16-bit width
* Arguments    : *(volatile uint32_t *) reg: 16-bit register
* Return Value : read value
*******************************************************************************/
#define Reg16Read(reg)	({ \
	unsigned short read = (unsigned short)(reg); \
	Sync_RegisterRead(); \
	reg; \
})


/*******************************************************************************
* Function Name: Reg08Read
* Description  : This function reads register by 16-bit width
* Arguments    : *(volatile uint32_t *) reg: 16-bit register
* Return Value : read value
*******************************************************************************/
#define Reg08Read(reg)	({ \
	unsigned char read = (unsigned char)(reg); \
	Sync_RegisterRead(); \
	reg; \
})


#endif // __R_driver_general_H__
