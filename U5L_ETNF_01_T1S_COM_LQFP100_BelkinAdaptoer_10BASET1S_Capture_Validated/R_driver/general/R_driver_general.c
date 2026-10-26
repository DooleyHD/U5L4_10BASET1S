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
* File Name    : R_driver_general.c
* Version      : 1.00
* Device(s)    : -
* Description  : General function that is used commonly by products
*******************************************************************************/

/*******************************************************************************
* Ver.1.00     : 2023/10/30
*                - Create New
* Ver.1.01     : 2023/12/14
*                - Add the function wait_sec
*******************************************************************************/


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_general.h"
#include "config.h"


/*******************************************************************************
* Section specification for entire file
*******************************************************************************/
#ifdef USE_CRUN
#pragma section RAMEXE
#else
#pragma	section	default
#endif


/*******************************************************************************
* Type definition
*******************************************************************************/
/* (no typedef) */


/*******************************************************************************
* Definitions
*******************************************************************************/
/* (no definition) */


/*******************************************************************************
* Prototype declarations of functions and 
* Functional definitions
*******************************************************************************/

/*******************************************************************************
* Description  : This function waits by loop.
* Arguments    : uint32_t count: wait count (depends CPU clock)
* Return Value : (none)
*******************************************************************************/
void wait( uint32_t count ){
	
	while( count-- )
		;
}


/*******************************************************************************
* Description  : This function waits of us unit by loop.
* Arguments    : uint32_t time_us: wait time [us]
* Return Value : (none)
* Remark       : 
*    - The wait time obtained by this function is the time when CPUCLK=400MHz.
*    - The accuracy of time is -13ns/+25ns when time_us is 1 to 1000 us.
*    - If time_us is over 20ms, It is more accurate to use the function wait_ms.
*******************************************************************************/
void wait_us( uint32_t time_us ){

	uint32_t	wait_count;
	
	
	/* make loop number */
	wait_count = (time_us * 1000 - 162.496) / 17.49951344;
	
	/* wait specified time */
	while( wait_count-- )
		;
		
}


/*******************************************************************************
* Description  : This function waits of ms unit by loop.
* Arguments    : uint32_t time_ms: wait time [ms]
* Return Value : (none)
* Remark       :
*    - The wait time obtained by this function is the time when CPUCLK=400MHz.
*    - The accuracy of time is -0.175us/+0.8us.
*******************************************************************************/
void wait_ms( uint32_t time_ms ){

	uint32_t	wait_count;
	uint32_t	i;
	
	/* make wait_us(1) loop number */
	wait_count = ((time_ms * 1000) - 0.251) / 0.977500;
	
	/* wait specified time */
	for( i = 0; i <= wait_count; i++ ){
		wait_us( 1 );	// 1 us
	}
	
	/* correction */
	wait_count = 40;
	while( wait_count-- )
		;
	
}


/*******************************************************************************
* Description  : This function waits of ms unit by loop.
* Arguments    : uint32_t time_sec: wait time [s]
* Return Value : (none)
* Remark       :
*    - The wait time obtained by this function is the time when CPUCLK=400MHz.
*    - The accuracy of time is -0.175us/+0.8us.
*******************************************************************************/
void wait_sec( uint32_t time_sec ){

	uint32_t	i;
	
	
	/* wait specified time */
	for( i = 0; i <= time_sec; i++ ){
		wait_ms( 1000 );	// 1 sec
	}
	
}


/*******************************************************************************
* Description  : This function calcurates value^n.
* Arguments    : int32_t value: base number
*                uint8_t n    : exponent number
* Return Value : value^n
*******************************************************************************/
int32_t power( int32_t value, uint8_t n ){
	
	int32_t		cal = 1;
	
	
	if( n == 0 ){
		return( 1 );
	}else{
		while( n > 0 ){
			cal *= value;
			n--;
		}
	}

	return( cal );

}


/*******************************************************************************
* Description  : This function writes specified value to specified
*                register by 32-bit width and read and check value.
* Arguments    : volatile uint32_t *write_reg: register address
*	             uint32_t write_value        : write value
*	             uint32_t comp               : compare target bit
*                    Set the bit to be compared to 1.
*                    ex) Compare only bit 0, other bits are not compared.
*                        comp = (1 << 0)
*                    ex) Only bit 0 is excluded from comparison, other bits are 
*                        included in comparison.
*                        comp = ~(1 << 0)
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
*******************************************************************************/
uint8_t Reg32WRC( volatile uint32_t *write_reg, uint32_t write_data, uint32_t comp ){
	
	uint8_t	ret;
	
	
	// write write_data to target register
	*write_reg = write_data;
	
	// read back check
	if( (Reg32Read(*write_reg) & comp) == (write_data & comp) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function writes specified value to specified
*                register by 16-bit width and read and check value.
* Arguments    : volatile uint16_t *write_reg: register address
*	             uint16_t write_value        : write value
*	             uint16_t comp               : compare target bit
*                    Set the bit to be compared to 1.
*                    ex) Compare only bit 0, other bits are not compared.
*                        comp = (1 << 0)
*                    ex) Only bit 0 is excluded from comparison, other bits are 
*                        included in comparison.
*                        comp = ~(1 << 0)
* Return Value : RET_OK:      read data matched expect data.
*	             RET_ERR_REG: read data unmatched expect data.
*******************************************************************************/
uint8_t Reg16WRC( volatile uint16_t *write_reg, uint16_t write_data, uint16_t comp ){
	
	uint8_t	ret;
	
	
	// write write_data to target register
	*write_reg = write_data;
	
	// read back check
	if( (Reg16Read(*write_reg) & comp) == (write_data & comp) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Function Name: Reg08WRC
* Description  : This function writes specified value to specified
*                register by 8-bit width and read and check value.
* Arguments    : volatile uint8_t *write_reg: register address
*	             uint8_t write_value        : write value
*	             uint8_t comp               : compare target bit
*                    Set the bit to be compared to 1.
*                    ex) Compare only bit 0, other bits are not compared.
*                        comp = (1 << 0)
*                    ex) Only bit 0 is excluded from comparison, other bits are 
*                        included in comparison.
*                        comp = ~(1 << 0)
* Return Value : RET_OK:      read data matched expect data.
*	             RET_ERR_REG: read data unmatched expect data.
*******************************************************************************/
uint8_t Reg08WRC( volatile uint8_t *write_reg, uint8_t write_data, uint8_t comp ){
	
	uint8_t	ret;
	
	
	// write write_data to target register
	*write_reg = write_data;
	
	// read back check
	if( (Reg08Read(*write_reg) & comp) == (write_data & comp) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function writes specified value to specified
*                register by 32-bit width and read and check value.
* Arguments    : volatile uint32_t *kprot_reg: address of KPORT register
*                volatile uint32_t *write_reg: address of target register
*                uint32_t write_value        : write value
*                uint32_t comp               : compare target bit
*                    Set the bit to be compared to 1.
*                    ex) Compare only bit 0, other bits are not compared.
*                        comp = (1 << 0)
*                    ex) Only bit 0 is excluded from comparison, other bits are 
*                        included in comparison.
*                        comp = ~(1 << 0)
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
*******************************************************************************/
uint8_t Reg32WRCp( volatile uint32_t *kprot_reg, volatile uint32_t *write_reg, uint32_t write_data, uint32_t comp ){
	
	uint8_t	ret;
	
	
	// release write protect
	*kprot_reg = 0xA5A5A501;
	
	// write write_data to target register
	*write_reg = write_data;
	
	// read back check
	if( (Reg32Read(*write_reg) & comp) == (write_data & comp) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	// set write protect
	*kprot_reg = 0xA5A5A500;
	
	
	return( ret );
	
}


/*******************************************************************************
// Function Name: Reg16WRCp
* Description  : This function writes specified value to specified
*                register by 16-bit width and read and check value.
* Arguments    : volatile uint32_t *kprot_reg: address of KPORT register
*                volatile uint16_t *write_reg: register address
*                uint16_t write_value        : write value
*                uint16_t comp               : compare target bit
*                    Set the bit to be compared to 1.
*                    ex) Compare only bit 0, other bits are not compared.
*                        comp = (1 << 0)
*                    ex) Only bit 0 is excluded from comparison, other bits are 
*                        included in comparison.
*                        comp = ~(1 << 0)
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
*******************************************************************************/
uint8_t Reg16WRCp( volatile uint32_t *kprot_reg, volatile uint16_t *write_reg, uint16_t write_data, uint16_t comp ){
	
	uint8_t	ret;
	
	
	// release write protect
	*kprot_reg = 0xA5A5A501;
	
	// write write_data to target register
	*write_reg = write_data;
	
	// read back check
	if( (Reg16Read(*write_reg) & comp) == (write_data & comp) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	// set write protect
	*kprot_reg = 0xA5A5A500;
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function writes specified value to specified register 
*                by 8-bit width and read and check value.
* Arguments    : volatile uint32_t *kprot_reg: address of KPORT register
*                volatile uint8_t *write_reg: register address
*                uint8_t write_value        : write value
*                uint8_t comp               : compare target(1: compare target)
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
*******************************************************************************/
uint8_t Reg08WRCp( volatile uint32_t *kprot_reg, volatile uint8_t *write_reg, uint8_t write_data, uint8_t comp ){
	
	uint8_t	ret;
	
	
	// release write protect
	*kprot_reg = 0xA5A5A501;
	
	// write write_data to target register
	*write_reg = write_data;
	
	// read back check
	if( (Reg08Read(*write_reg) & comp) == (write_data & comp) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	// set write protect
	*kprot_reg = 0xA5A5A500;
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function reads to specified register by 32-bit width 
*                and check value.
* Arguments    : volatile uint32_t *read_reg: register address
*                uint32_t expect_value      : expect value
*                uint32_t comp              : compare target(1: compare target)
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
*******************************************************************************/
uint8_t Reg32RC( volatile uint32_t *read_reg, uint32_t expect_data, uint32_t comp ){
	
	uint8_t	ret;
	
	
	if( (Reg32Read(*read_reg) & comp) == (expect_data & comp) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function reads to specified register by 16-bit 
*                width and check value.
* Arguments    : 
*                volatile uint16_t *read_reg: register address
*                uint16_t expect_value      : expect value
*                uint16_t comp              : compare target(1: compare target)
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
*******************************************************************************/
uint8_t Reg16RC( volatile uint16_t *read_reg, uint16_t expect_data, uint16_t comp ){
	
	uint8_t	ret;
	
	
	if( (Reg16Read(*read_reg) & comp) == (expect_data & comp) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function reads to specified register by 8-bit width 
*                and check value.
* Arguments    : 
*                volatile uint8_t *read_reg: register address
*                uint8_t expect_value      : expect value
*                uint8_t comp              : compare target(1: compare target)
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
*******************************************************************************/
uint8_t Reg08RC( volatile uint8_t *read_reg, uint8_t expect_data, uint8_t comp ){
	
	uint8_t	ret;
	
	
	if( (Reg08Read(*read_reg) & comp) == (expect_data & comp) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
// Function Name: Reg32RMWC
* Description  : This function changes specified bits of specificed register 
*                read and check. (for 32-bit register)
* Arguments    : volatile uint32_t *write_reg: register address
*                uint16_t write_data         : write value
*                uint16_t bitrange           : target bits relative range (ex. bit 7-6: 0x3, bit 15-12: 0xF)
*                uint8_t position           : start bit position of target bits (ex. bit 7-6: 6,  bit 15-12: 12)
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
*    bitrange   = 0xF (4 bits)
*    position   = 4
*    write_data = 0xB
*    before target register value: 0xAAAAAAAA
*    after target register value : 0xAABAAAAA (change bit 7-4 to 0xB) 
*******************************************************************************/
uint8_t Reg32RMWC( volatile uint32_t *write_reg, uint32_t write_data, uint32_t bitrange, uint8_t position ){
	
	uint8_t	ret;
	uint32_t	value;
	uint32_t	comp;
	
	
	// make write value
	comp = bitrange << position;
	value = Reg32Read(*write_reg) & ~comp | (write_data << position);	// clear target bits and set target value
	
	
	// write register
	*write_reg = value;
	
	
	if( (Reg32Read(*write_reg) & comp) == (value & comp) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function changes specified bits of specificed register 
*                and read and check. (for 16-bit register)
* Arguments    : volatile uint16_t *write_reg: register address
*                uint16_t write_data         : write value
*                uint16_t bitrange           : target bits relative range (ex. bit 7-6: 0x3, bit 15-12: 0xF)
*                uint8_t position           : start bit position of target bits (ex. bit 7-6: 6,  bit 15-12: 12)
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
* Example      : 
*    bitrange   = 0xF (4 bits)
*    position   = 4
*    write_data = 0xB
*    before target register value: 0xAAAA
*    after target register value : 0xAABA (change bit 7-4 to 0xB) 
*******************************************************************************/
uint8_t Reg16RMWC( volatile uint16_t *write_reg, uint16_t write_data, uint16_t bitrange, uint8_t position ){
	
	uint8_t	ret;
	uint16_t	value;
	uint16_t	comp;
	
	
	// make write value
	comp = bitrange << position;
	value = Reg16Read(*write_reg) & ~comp | (write_data << position);	// clear target bits and set target value
	
	
	// write register
	*write_reg = value;
	
	
	if( (Reg16Read(*write_reg) & comp) == (value & comp) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function changes specified bits of specificed register 
*                and read and check. (for 8-bit register)
* Arguments    : volatile uint8_t *write_reg: register address
*                uint8_t write_data         : write value
*                uint8_t bitrange           : target bits relative range (ex. bit 7-6: 0x3, bit 5-2: 0xF)
*                uint8_t position           : start bit position of target bits (ex. bit 7-6: 6,  bit 5-2: 2)
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
* Example      : 
*    bitrange   = 0xF (4 bits)
*    position   = 4
*    write_data = 0xB
*    before target register value: 0xAA
*    after target register value : 0xBA (change bit 7-4 to 0xB) 
*******************************************************************************/
uint8_t Reg08RMWC( volatile uint8_t *write_reg, uint8_t write_data, uint8_t bitrange, uint8_t position ){
	
	uint8_t	ret;
	uint8_t	value;
	uint8_t	comp;
	
	
	// make write value
	comp = bitrange << position;
	value = Reg08Read(*write_reg) & ~comp | (write_data << position);	// clear target bits and set target value
	
	
	// write register
	*write_reg = value;
	
	
	if( (Reg08Read(*write_reg) & comp) == (value & comp) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function changes specified bits of specificed register.
*                (for 32-bit register)
* Arguments    : volatile uint32_t *write_reg: register address
*                uint16_t write_data         : write value
*                uint16_t bitrange           : target bits relative range (ex. bit 7-6: 0x3, bit 15-12: 0xF)
*                uint8_t position           : start bit position of target bits (ex. bit 7-6: 6,  bit 15-12: 12)
* Return Value : (none)
* Example      : 
*    position   = 4
*    write_data = 0xB
*    before target register value: 0xAAAAAAAA
*    after target register value : 0xAABAAAAA (change bit 7-4 to 0xB) 
*******************************************************************************/
void Reg32RMW( volatile uint32_t *write_reg, uint32_t write_data, uint32_t bitrange, uint8_t position ){
	
	uint32_t	value;
	uint32_t	comp;
	
	
	// make write value
	comp = bitrange << position;
	value = (Reg32Read(*write_reg) & ~comp) | (write_data << position);	// clear target bits and set target value
	
	
	// write register
	*write_reg = value;
	
}


/*******************************************************************************
* Description  : This function changes specified bits of specificed register.
*                (for 16-bit register)
* Arguments    : volatile uint16_t *write_reg: register address
*                uint16_t write_data         : write value
*                uint16_t bitrange           : target bits relative range (ex. bit 7-6: 0x3, bit 15-12: 0xF)
*                uint8_t position           : start bit position of target bits (ex. bit 7-6: 6,  bit 15-12: 12)
* Return Value : (none)
* Example      : 
*    position   = 4
*    write_data = 0xB
*    before target register value: 0xAAAA
*    after target register value : 0xAABA (change bit 7-4 to 0xB) 
*******************************************************************************/
void Reg16RMW( volatile uint16_t *write_reg, uint16_t write_data, uint16_t bitrange, uint8_t position ){
	
	uint16_t	value;
	uint16_t	comp;
	
	
	// make write value
	comp = bitrange << position;
	value = (Reg16Read(*write_reg) & ~comp) | (write_data << position);	// clear target bits and set target value
	
	
	// write register
	*write_reg = value;
	
}


/*******************************************************************************
* Description  : This function changes specified bits of specificed register.
*                (for 8-bit register)
* Arguments    : volatile uint8_t *write_reg: register address
*                uint8_t write_data         : write value
*                uint8_t bitrange           : target bits relative range (ex. bit 7-6: 0x3, bit 5-2: 0xF)
*                uint8_t position           : start bit position of target bits (ex. bit 7-6: 6,  bit 5-2: 2)
* Return Value : (none)
* Example      : 
*    position   = 4
*    before target register value: 0xAA
*    after target register value : 0xBA (change bit 7-4 to 0xB) 
*******************************************************************************/
void Reg08RMW( volatile uint8_t *write_reg, uint8_t write_data, uint8_t bitrange, uint8_t position ){
	
	uint8_t	value;
	uint8_t	comp;
	
	
	// make write value
	comp = bitrange << position;
	value = (Reg08Read(*write_reg) & ~comp) | (write_data << position);	// clear target bits and set target value
	
	
	// write register
	*write_reg = value;
	
}


/*******************************************************************************
* Description  : This function sets specified 1 bit of specificed register
*                and read and check.
* Arguments    : volatile uint32_t *write_reg: register address
*                uint8_t bit                : tartget bit position
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
* Example      : 
*    position   = 4
*    before target register value: 0x00000000
*    after target register value : 0x00000010
*******************************************************************************/
uint8_t Reg32SetBitCheck( volatile uint32_t *write_reg, uint8_t bit ){
	
	uint8_t 	ret;
	
	
	// write register
	*write_reg = Reg32Read(*write_reg) | (1 << bit);
	
	
	if( (*write_reg & (1 << bit)) == (1 << bit) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function sets specified 1 bit of specificed register
*                and read and check.
* Arguments    : volatile uint16_t *write_reg: register address
*                uint8_t bit                 : tartget bit position
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
* Example      : 
*    position   = 4
*    before target register value: 0x0000
*    after target register value : 0x0010
*******************************************************************************/
uint8_t Reg16SetBitCheck( volatile uint16_t *write_reg, uint8_t bit ){
	
	uint8_t	ret;
	
	
	// write register
	*write_reg = Reg16Read(*write_reg) | (1 << bit);
	
	
	if( (*write_reg & (1 << bit)) == (1 << bit) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function sets specified 1 bit of specificed register 
*                and read and check.
* Arguments    : volatile uint8_t *write_reg: register address
*                uint8_t bit                : tartget bit position
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
* Example      : 
*    position   = 4
*    before target register value: 0x00
*    after target register value : 0x10
*******************************************************************************/
uint8_t Reg08SetBitCheck( volatile uint8_t *write_reg, uint8_t bit ){
	
	uint8_t	ret;
	
	
	// write register
	*write_reg = Reg08Read(*write_reg) | (1 << bit);
	
	
	if( (*write_reg & (1 << bit)) == (1 << bit) ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function clears specified 1 bit of specificed register 
*                and read and check.
* Arguments    : volatile uint32_t *write_reg: register address
*                uint8_t bit                : tartget bit position
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
* Example      : 
*    position   = 4
*    before target register value: 0xFFFFFFFF
*    after target register value : 0xFFFFFFEF
*******************************************************************************/
uint8_t Reg32ClearBitCheck( volatile uint32_t *write_reg, uint8_t bit ){
	
	uint8_t	ret;
	
	
	// write register
	*write_reg = Reg32Read(*write_reg) & ~(1 << bit);
	
	
	if( (*write_reg & (1 << bit)) == 0 ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function clears specified 1 bit of specificed register 
*                and read and check.
* Arguments    : volatile uint16_t *write_reg: register address
*                uint8_t bit                : tartget bit position
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
* Example      : 
*    position   = 4
*    before target register value: 0xFFFF
*    after target register value : 0xFFEF
*******************************************************************************/
uint8_t Reg16ClearBitCheck( volatile uint16_t *write_reg, uint8_t bit ){
	
	uint8_t	ret;
	
	
	// write register
	*write_reg = Reg16Read(*write_reg) & ~(1 << bit);
	
	
	if( (*write_reg & (1 << bit)) == 0 ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function clears specified 1 bit of specificed register and 
*                read and check.
* Arguments    : volatile uint8_t *write_reg: register address
*                uint8_t bit                : tartget bit position
* Return Value : RET_OK:      read data matched expect data.
*                RET_ERR_REG: read data unmatched expect data.
* Example      : 
*    position   = 4
*    before target register value: 0xFF
*    after target register value : 0xEF
*******************************************************************************/
uint8_t Reg08ClearBitCheck( volatile uint8_t *write_reg, uint8_t bit ){
	
	uint8_t	ret;
	
	
	// write register
	*write_reg = Reg08Read(*write_reg) & ~(1 << bit);
	
	
	if( (*write_reg & (1 << bit)) == 0 ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}
	
	
	return( ret );
	
}


/*******************************************************************************
* Description  : This function sets specified 1 bit of specificed register.
* Arguments    : volatile uint32_t *write_reg: register address
*                uint8_t bit                : tartget bit position
* Return Value : (none)
* Example      : 
*    position   = 4
*    before target register value: 0x00000000
*    after target register value : 0x00000010
*******************************************************************************/
void Reg32SetBit( volatile uint32_t *write_reg, uint8_t bit ){
	
	// write register
	*write_reg = Reg32Read(*write_reg) | (1 << bit);
	
}


/*******************************************************************************
* Description  : This function sets specified 1 bit of specificed register.
* Arguments    : volatile uint16_t *write_reg: register address
*                uint8_t bit                : tartget bit position
* Return Value : (none)
* Example      : 
*    position   = 4
*    before target register value: 0x0000
*    after target register value : 0x0010
*******************************************************************************/
void Reg16SetBit( volatile uint16_t *write_reg, uint8_t bit ){
	
	// write register
	*write_reg = Reg16Read(*write_reg) | (1 << bit);
	
}


/*******************************************************************************
* Description  : This function sets specified 1 bit of specificed register.
* Arguments    : volatile uint8_t *write_reg: register address
*                uint8_t bit                : tartget bit position
* Return Value : (none)
* Example      : 
*    position   = 4
*    before target register value: 0x00
*    after target register value : 0x10
*******************************************************************************/
void Reg08SetBit( volatile uint8_t *write_reg, uint8_t bit ){
	
	// write register
	*write_reg = Reg08Read(*write_reg) | (1 << bit);
	
}


/*******************************************************************************
// Function Name: Reg32ClearBit
* Description  : This function clears specified 1 bit of specificed register.
* Arguments    : volatile uint32_t *write_reg: register address
*                uint8_t bit                : tartget bit position
* Return Value : (none)
* Example      : 
*    position   = 4
*    before target register value: 0xFFFFFFFF
*    after target register value : 0xFFFFFFEF
*******************************************************************************/
void Reg32ClearBit( volatile uint32_t *write_reg, uint8_t bit ){
	
	// write register
	*write_reg = Reg32Read(*write_reg) & ~(1 << bit);
	
}


/*******************************************************************************
* Description  : This function clears specified 1 bit of specificed register.
* Arguments    : volatile uint16_t *write_reg: register address
*                uint8_t bit                 : tartget bit position
* Return Value : (none)
* Example      : 
*    position   = 4
*    before target register value: 0xFFFF
*    after target register value : 0xFFEF
*******************************************************************************/
void Reg16ClearBit( volatile uint16_t *write_reg, uint8_t bit ){
	
	// write register
	*write_reg = Reg16Read(*write_reg) & ~(1 << bit);
	
}


/*******************************************************************************
* Description  : This function clears specified 1 bit of specificed register.
* Arguments    : volatile uint8_t *write_reg: register address
*                uint8_t bit                : tartget bit position
* Return Value : (none)
* Example      : 
*    position   = 4
*    before target register value: 0xFF
*    after target register value : 0xEF
*******************************************************************************/
void Reg08ClearBit( volatile uint8_t *write_reg, uint8_t bit ){
	
	// write register
	*write_reg = Reg08Read(*write_reg) & ~(1 << bit);
	
}


/*******************************************************************************
* Description  : This function waits target bit becomes 1.
* Arguments    : uint32_t          : register address
*                uint8_t position : target bit position
* Return Value : (none)
*******************************************************************************/
void Reg32Wait1( volatile uint32_t *reg, uint8_t position ){
	
	while( (Reg32Read(*reg) & (1 << position)) != (1 << position) )
		;
		
}


/*******************************************************************************
* Description  : This function waits target bit becomes 1.
* Arguments    : uint16_t         : register address
*                uint8_t position : target bit position
* Return Value : (none)
*******************************************************************************/
void Reg16Wait1( volatile uint16_t *reg, uint8_t position ){
	
	while( (Reg16Read(*reg) & (1 << position)) != (1 << position) )
		;
		
}


/*******************************************************************************
// Function Name: Reg08Wait1
* Description  : This function waits target bit becomes 1.
* Arguments    : uint8_t          : register address
*                uint8_t position : target bit position
* Return Value : (none)
*******************************************************************************/
void Reg08Wait1( volatile uint8_t *reg, uint8_t position ){
	
	while( (Reg08Read(*reg) & (1 << position)) != (1 << position) )
		;
		
}


/*******************************************************************************
// Function Name: Reg32Wait0
* Description  : This function waits target bit becomes 0.
* Arguments    : uint32_t          : register address
*                uint8_t position : target bit position
* Return Value : (none)
*******************************************************************************/
void Reg32Wait0( volatile uint32_t *reg, uint8_t position ){
	
	while( (Reg32Read(*reg) & (1 << position)) )
		;
		
}


/*******************************************************************************
// Function Name: Reg16Wait0
* Description  : This function waits target bit becomes 0.
* Arguments    : 
*                uint16_t          : register address
*                uint8_t position : target bit position
* Return Value : (none)
*******************************************************************************/
void Reg16Wait0( volatile uint16_t *reg, uint8_t position ){
	
	while( (Reg16Read(*reg) & (1 << position)) )
		;
		
}


/*******************************************************************************
// Function Name: Reg08Wait0
* Description  : This function waits target bit becomes 0.
* Arguments    : uint8_t          : register address
*                uint8_t position : target bit position
* Return Value : (none)
*******************************************************************************/
void Reg08Wait0( volatile uint8_t *reg, uint8_t position ){
	
	while( (Reg08Read(*reg) & (1 << position)) )
		;
		
}

#pragma section default
