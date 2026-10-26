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
* File Name    : R_COM.c
* Version      : 1.00
* Device(s)    : RH850 series product, R-Car U5L product
* Description  : This is source file for printf function using RLIN3.
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "product.h"
#include "R_driver_typedef.h"
#include "R_driver_general.h"
#include "R_driver_RLIN3.h"
#include "config.h"
#include "R_COM.h"

/* for R_COM_printf */
#include <stdarg.h>


/*******************************************************************************
* Local type definitions
*******************************************************************************/



/*******************************************************************************
* Local definitions
*******************************************************************************/

			  
/*******************************************************************************
* Definition
*******************************************************************************/
/* for R_COM_printf */
#define putchar(n, data)    R_COM_Tx( n, data )
#define C_MAX  		12	/* Max number of digits when displaying long data in octal */
#define	COM_MAX		24	/* Max number of RLIN3 unit */

/* for debug */
#define	COM_DEBUG		/* if defined, the codes for debug are activate */


/*******************************************************************************
* Global variables
*******************************************************************************/
/* standard RLIN3 unit (use R_COM_printf) */
uint8_t 	G_std_n = 0;


/*******************************************************************************
* Functional definition
*******************************************************************************/
/* none */


/*******************************************************************************
* Prototype declarations of local functions
*******************************************************************************/
/* these functions are called only function COM_printf. */
static void outs( uint8_t n, int8_t *s, int16_t c );
static void outc( uint8_t n, int8_t ch, int16_t c );
static void outn( uint8_t n, int8_t fm, uint32_t v, int16_t c );
static void outf( uint8_t n, float32 v, int16_t c, int16_t f );


/*******************************************************************************
* Function body
*******************************************************************************/
/*******************************************************************************
* [Description]
*	This function transmits one data.
*
* [Arguments]
*	uint8_t n:
*		unit number of RLIN3n
*	uint16_t tx_data
*		transmit data
*
* [Return Value]
*	(none)
*
* [Example]
*	R_COM_Tx( 0, 0xAA );	// transmit 0xAA from RLIN30
*******************************************************************************/
void R_COM_Change_Unit( uint8_t n ){
	
	G_std_n = n;
	
}


/*******************************************************************************
* [Description]
*	This function initializes UART specified RLIN3n unit.
*   	[communication format]
*			- data no invert
*			- no parity
*			- 1 stop bit
*			- LSB first
*			- 8 bit length
*			- error detection: all disable
*
* [Arguments]
*	R_COM_s_setting setting
*
* [Return Value]
*	non
*
* [Remarks]
*	- This function is supported only RLIN3.
*	- Supporting RLIN3 clock frequency is only defined by enum R_COM_e_clk.
*	- Supporting baudrate is only defined by enum R_COM_e_baudrate.
*	  The values of the RLN3nLWBR and RLN3nLBRP01 registers required to set the baud 
*	  rate are defined by the global constant G_setting_baudrate[][].
*
* [Example]
*	// Declear local variable for UART communication setting
*	R_COM_s_setting 	setting;
*
*	// set configuration value for UART communication
*	setting.base_addr = RLN30_base;
*	setting.baudrate  = R_COM_e_baudrate_230400bps;
*	setting.clk_freq  = R_COM_e_clk_5MHz;
*
*	// initial setting for UART communication
*	R_COM_Initialize( setting );
*******************************************************************************/
uint8_t R_COM_Initialize( R_COM_s_setting setting ){

	/* variables for general setting for RLIN3 */
	uint8_t         	n         = setting.n;       	/* unit number of RLIN3    */
	R_COM_e_baudrate	baudrate  = setting.baudrate;	/* baudrate                */
	R_COM_e_clk     	clk_freq  = setting.clk_freq;	/* frequency of RLIN3 PCLK */
	RLIN3u_s_config 	config; /* configuration of UART */
	/* variables for etc */
	uint8_t 	ret=RET_OK;
	
	
	/* set the RLIN3 unit to use the function R_COM_printf */
	/**************************************************************************/
	R_COM_Change_Unit( n );
	
	
	/* set baud rate */
	/**************************************************************************/
	R_RLIN3u_Config_baudrate( n, (RLIN3u_s_config_baudrate *)&RLIN3u_Baudrate[clk_freq][baudrate] );
	

	/* communication setting */
	/**************************************************************************/
	/*  noise filter ON/OFF */
	config.LRDNFS = RLIN3u_e_LRDNFS_enable;
	
	/* RLN3nLEDE register: Enables error detection */
	config.LEDE.BITu.FERE = RLIN3u_e_FERE_disable;	/* framing error detection */
	config.LEDE.BITu.OERE = RLIN3u_e_OERE_disable;	/* overrun error detection */
	config.LEDE.BITu.BERE = RLIN3u_e_BERE_disable;	/* bit error detection */
	
	/* RLN3nLBFC register: Sets data format  */
	config.LBFC.BITu.UTPS  = RLIN3u_e_UTPS_non_invert;   	/* UART Output Polarity Switch */
	config.LBFC.BITu.URPS  = RLIN3u_e_URPS_non_invert;   	/* UART Input Polarity Switch */
	config.LBFC.BITu.UPS   = RLIN3u_e_UPS_disable_parity;	/* UART Parity Select */
	config.LBFC.BITu.USBLS = RLIN3u_e_USBLS_1_stop_bit;  	/* UART Stop Bit length Select */
	config.LBFC.BITu.UBOS  = RLIN3u_e_UBOS_LSB_first;    	/* UART Transfer Format Order Select */
	config.LBFC.BITu.UBLS  = RLIN3u_e_UBLS_8_bits;       	/* UART Character Length Select */
	
	/* set inter byte space */
	config.IBS = RLIN3u_e_IBS_0_Tbit;	/* inter byte space = 0Tbit */

	/* Transmission interrupt is generated at the completion of transmission */
	config.LUOR1.BITu.UECD   = RLIN3u_e_UECD_disable;      	/* Expansion Bit Comparison Disable */
	config.LUOR1.BITu.UTIGTS = RLIN3u_e_UTIGTS_at_tx_start;	/* Transmission Interrupt Generation Timing Select */
	config.LUOR1.BITu.UEBDCE = RLIN3u_e_UEBDCE_disable;    	/* Expansion Bit Data Comparison Enable */
	config.LUOR1.BITu.UEBDL  = RLIN3u_e_UEBDL_value_0;     	/* Expansion Bit Detection Level Select */
	config.LUOR1.BITu.UEBE   = RLIN3u_e_UEBE_disable;      	/* Expansion Bit Enable */
	
	/* set register */
	R_RLIN3u_Config( n, &config );
	

	/* release LIN reset */
	/**************************************************************************/
	R_RLIN3_ReleaseLINreset( n );
	
	
	/* Enable TX and RX */
	/**************************************************************************/
	R_RLIN3u_EnableTXRX( n );
	
	
	return( ret );
}


/*******************************************************************************
* [Description]
*	This function transmits one data.
*
* [Arguments]
*	uint8_t n:
*		unit number of RLIN3n
*	uint16_t tx_data
*		transmit data
*
* [Return Value]
*	(none)
*
* [Example]
*	R_COM_Tx( 0, 0xAA );	// transmit 0xAA from RLIN30
*******************************************************************************/
void R_COM_Tx( uint8_t n, uint8_t tx_data ){
	
	/* transmit data */
	rRLN3nLUTDR(n).UINT16 = (uint16_t)tx_data;
	
	/* wait until Transmission is started (UTS=1) */
	while( (rRLN3nLST(n).UINT8 & (1 << 4)) != (1 << 4) )
		;
		
	/* wait until Transmission is stopped (UTS=0) */
	while( (rRLN3nLST(n).UINT8 & (1 << 4)) == (1 << 4) )
		;

		
	__nop();	/* for break point */
	
}


/*******************************************************************************
* [Description]
*	This function receives one data.
*
* [Arguments]
*	uint8_t n: unit number of RLIN3n
*
* [Return Value]
*	(none)
*
* [Example]
*	uint8_t rx_data;
*
*	rx_data = R_COM_Rx( 0 );	// receive data from RLIN30
*******************************************************************************/
uint8_t R_COM_Rx( uint8_t n ){
	
	uint8_t 	rx_data;
	
	
	/* wait until Reception is started (URS=1) */
	while( (rRLN3nLST(n).UINT8 & (1 << 5)) != (1 << 5) )
		;
		
	/* wait until Reception is stopped (URS=0) */
	while( (rRLN3nLST(n).UINT8 & (1 << 5)) == (1 << 5) )
		;
	
	/* receive data */
	rx_data = rRLN3nLUTDR(n).UINT16;
	
	
	return( rx_data );
}


/*******************************************************************************
* [Description]
*	This function outputs characters in the same format as the printf function 
*	by using RLIN3 configured by the function R_COM_Initialize called the latest.
*   "called the latest" means that the RLIN3 unit to be used by this function is
*   the unit specified by the argument of the most recently executed function 
*   R_COM_Initialize or unit specified by the argument by the function R_COM_Change_Unit.
*
* [Arguments]
* 	char *fmt: string with format to output
* 	    [format]
* 		%c: output charactor (ex."%c")
* 		%s: output charactors (ex. %8s", "%-10s")
* 		%d: output decimal integer number  (ex. "%-2d","%03d")
* 		%o: output octadecimal integer number (ex. "%06o","%03o")
* 		%x: output hexadecimal integer number (ex. "%04x")
* 		%f: output floating point number (ex. "%5.3f")
*
*  [Return Value]
*	non
*******************************************************************************/
void R_COM_printf( int8_t *fmt, ... )
{
	va_list 	args;
	int8_t  	*p;
	uint32_t	v;
	float32		fr;
	int16_t 	c;
	int16_t 	f;
	uint8_t 	n;
	
	
	/* set RLIN3 unit to use this function */
	n = G_std_n;
	
	/* preparation of using argument */
	va_start( args, fmt );

	/* main output routine */
	for( p = fmt; *p != '\0'; p++ ){
		/* if current charactor is formator */
        	if (*p == '%') {
			p++;
			
			/* check and get digit number */
			if ((*p >= '1') && (*p <= '9')) {
				c = *p++ - '0';
				while ((*p >= '0') && (*p <= '9')){
					c = c * 10 + (*p++ - '0');
				}
	    		}else{
				c = -1;
			}
	    
			/* check and get digit number for fraction part */
			if (*p == '.') {
				p++;
				f = *p++ - '0';
				while ((*p >= '0') && (*p <= '9')){
					f = f * 10 + (*p++ - '0');
				}
			}else{
				f = -1;
			}
 
			switch (*p) {
			    case 's':	/* output charactors */
					v = (uint32_t)va_arg(args, long);
					outs(n, (int8_t*)v, c);
					break;
			    case 'c':	/* output charactor */
					v = (uint32_t)va_arg(args, long);
					outc(n, (int8_t)v, c);
					break;
			    case 'd': case 'o': case 'x':	/* output integer number */
					v = (uint32_t)va_arg(args, long);
					outn(n, *p, v, c);
					break;
			    case 'f':	/* output floating point number */
					fr = (float32)va_arg(args, double);
					outf(n, fr, c, f);
					break;
			}
			
			/* if current charactor is end of string */
			if (*p == '\0'){
				goto fin;
			}
			
		/* if current charactor is line feed symbol */
		}else if (*p == '\n') {
			/* Output carriage return and line feed */
			putchar(n, '\r');
			putchar(n, '\n');
			
		/* if current charactor is other than those above */
		}else{
			/* Outputs the character of the argument as is */
			putchar(n, *p);
		}
	}
fin:
	
	/* end of using argument */
	va_end( args );
	
}

 
/*******************************************************************************
* [Description]
*	This function outputs string specified formator %s.
*
* [Arguments]
*	uint8_t n: unit number of RLIN3n
* 	int8_t *s: string to output
* 	int16_t c: string number to output
*
*  [Return Value]
*	non
*******************************************************************************/
static void outs( uint8_t n, int8_t *s, int16_t c ){
	
	int8_t	*p;
	
	
	/* output string */
	for( p = s; *p != '\0'; p++ ){
		if (c-- == 0){
			return;
		}
	        putchar(n, *p);
	}
	
	/* output fil character */
	while( c-- > 0 ){
		putchar(n, ' ');
	}
	
}

 
/*******************************************************************************
* [Description] 
*	This function outputs character specified formator %c.
*
* [Arguments]
*	uint8_t n: unit number of RLIN3n
* 	int8_t ch: charactor to output
* 	int16_t c : charactor number to output (output "c-1" ' ') 
*
* [Return Value]
*	non
*******************************************************************************/
static void outc( uint8_t n, int8_t ch, int16_t c ){
	
	/* output character */
	putchar(n, ch);
	
	/* output fil character */
	while( --c > 0 ){
		putchar(n, ' ');
	}
	
}
 
 
/*******************************************************************************
* [Description]
*	This function outputs integer number specified formator %d/%o/%x.
*
* [Arguments]
*	uint8_t n: unit number of RLIN3n
*	int8_t fm: formator ('d' or 'o' or 'x')
*	uint32_t v : integer number to output
*	int16_t c : digit to output
*
* [Return Value]
*	non
*******************************************************************************/
static void outn( uint8_t n, int8_t fm, uint32_t v, int16_t c ){
	
	int8_t	s[C_MAX], *p, z;
	uint16_t	b;
	
	
	/* set base number b and fil character z */
	switch ( fm ) {
	    case 'd':
		b = 10;
		z = '0';	/* padding 0 */
		break;
	    case 'o':
		b = 8;
		z = '0';
		break;
	    case 'x':
		b = 16;
		z = '0';
		break;
	    default:
		return;
	}
	
	/* convert number to ASCII character */
	p = s;
	do {
		c--;
		*p++ = "0123456789ABCDEF"[v % b];
		v /= b;
	}while( v != 0 );
	
	/* output fil character */
	for( ; c > 0; c-- ){
		putchar(n, z);
	}
	
	/* output number */
	while( p > s ){
		putchar(n, *--p);
	}
	
} 
 
 
/*******************************************************************************
* [Description]
*	This function outputs floating point number specified formator %f.
*	This function can output -10^19 to +10^19.
*
* [Arguments]
*	uint8_t n: unit number of RLIN3n
*	float32 v: value with floating point number
*	int16_t c: output digit of integer part (currently, not support)
*	int16_t f: output digit of fractional part
*
* [Return Value]
*	non
*
* [Remark]
*	In order to increase the precision of the output floating-point number, 
*	this function uses the long long type in the calculation of each digit 
*	output process. In the result, this function can output only -10^19 to 
*	+10^19, not support full range of float type.
*	ex) output 2.409000E+006
*	   output result of this function         : 2409000.0
*	   output result of low precision function: 2385999.5
*******************************************************************************/
static void outf( uint8_t n, float32 v, int16_t c, int16_t f ){
	  
	int8_t  	i, j;  	/* loop variable for fraction part bit loop */
 	int8_t  	e;     	/* current digit value                      */
	float32 	v_temp;	/* working value                            */
	uint64_t	v_keta;	/* value for digit check                    */
	int8_t  	flag;  	/* found the most significant digit         */
	uint8_t 	error[] = "(over 2^32-1)";
	
	
	/* output sign */
	/**************************************************************************/
	if( v < 0 ){
		putchar(n,  '-' );
		v_temp = -1 * v;	/* reverse sign */
	}else{
		v_temp = v;     	/* copy original value to variable */
	}
	
	/* output integer part */
	/**************************************************************************/
	/* prepare convert: make divisor of maximum ditit */
	v_keta = 1;
	for( j = 0; j < 19; j++ ){
		v_keta = v_keta * 10;
	}
	
	/* digit check */
	if( v_temp > (0xFFFFFFFF-1) ){	/* over 2^32-1 */
		/* output error message */
		i = 0; 
		while( error[i]!='\0' ){
			putchar(n,  error[i++] );
		}
		
		return;
	}
	
	/* prepare to get and output each digit */
	flag = 0;	/* initialize of flag for found the most significant digit */
	
	/* This loop serches most significant digit from the most significant digit by
	   original value divide by 10^38, 10^37, 10^36, ... .
	   The value of i when divide result is not 0 is the most significant digit.
	   Then the flag is set 1 and output the number of this digit.
	   After flag = 1, output each digit number. */
	for( i = 19; i >= 0; i-- ){
		/* get number of current keta */
		e = v_temp / v_keta;
		
		/* 1st number found or after */
		if( ((e != 0) && (flag == 0)) || (flag == 1) ){
			/* set 1st number found flag */
			flag = 1;
			
			/* output number of current keta */
			putchar(n,  '0' + e );
			
			/* remove outputed digit */
			v_temp = v_temp - e * v_keta;
	   	}
		
		/* current keta */
		v_keta = v_keta / 10;
	}
	
	/* In case of v < 0
	   In this case, the above loop outputs nothing, so it outputs the integer part 0. */
	if( flag == 0 ){
		putchar(n,  '0' );
	}
	
	
	/* output decimal point */
	/**************************************************************************/
	putchar(n,  '.' );
	
	
	/* output fractional part */
	/**************************************************************************/
	for( i = 0; i < f; i++ ){
		/* increment one decimal point */
		v_temp = v_temp * 10;

		/* get number of current incremented decimal point number */
		e = v_temp;
		
		/* output number of current keta */
		putchar(n,  '0' + e );
			
		/* surplus */
		v_temp = v_temp - e;
	}
	
	__nop();
	
} 



/*******************************************************************************
* [Description]
*	This function receives one data.
*
* [Arguments]
*	(none)
*
* [Return Value]
*	(none)
*
* [Example]
*	uint8_t rx_data;
*
*	rx_data = R_COM_ReadByte();	// receive data from RLIN30
*******************************************************************************/
uint8_t R_COM_ReadByte( void ){

	return( R_COM_Rx( G_std_n ) );

}

