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
* File Name    : R_driver_RLIN3.c
* Version      : 1.00 (modified: [DJ] RLIN33 UART test, 2026.10)
* Module(s)    : RLIN3
* Device(s)    : RH850 series product, R-Car U5L product
* Description  : RLIN3 driver that is used commonly by RH850 and R-Car products
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_RLIN3.h"


/*******************************************************************************
* Section specification for entire file
*******************************************************************************/
#pragma	section	default


/*******************************************************************************
* Definitions
*******************************************************************************/
/* Definition of base address */
uint32_t	RLIN3n_base[] = { RLIN30_inst_0_BASE,
        	                  RLIN31_inst_0_BASE,
        	                  RLIN32_inst_0_BASE,
        	                  RLIN33_inst_0_BASE,
        	                  RLIN34_inst_0_BASE,
        	                  RLIN35_inst_0_BASE,
        	                  RLIN36_inst_0_BASE,
        	                  RLIN37_inst_0_BASE,
        	                  RLIN38_inst_0_BASE,
        	                  RLIN39_inst_0_BASE,
        	                  RLIN310_inst_0_BASE,
        	                  RLIN311_inst_0_BASE,
        	                  RLIN312_inst_0_BASE,
        	                  RLIN313_inst_0_BASE,
        	                  RLIN314_inst_0_BASE,
        	                  RLIN315_inst_0_BASE,
        	                  RLIN316_inst_0_BASE,
        	                  RLIN317_inst_0_BASE,
        	                  RLIN318_inst_0_BASE,
        	                  RLIN319_inst_0_BASE,
        	                  RLIN320_inst_0_BASE,
        	                  RLIN321_inst_0_BASE,
        	                  RLIN322_inst_0_BASE,
        	                  RLIN323_inst_0_BASE };


/*******************************************************************************
* Global variables (preset baudrate for UART)
*******************************************************************************/
/* setting value of RLN3nLWBR.NSPB[3:0] bit, RLN3nLWBR.LPRS[2:0] bit and RLN3nLBRP01 register */
const RLIN3u_s_config_baudrate RLIN3u_Baudrate[RLIN3_e_clk_num][RLIN3u_e_baudrate_num] = {	
		/* for CLK_RLIN = 1.6MHz */	
		{ { 0x5, 0x2,   6}, 	/* target:   9600bps, actual:   9523.81bps (error:  -0.794%) */
		  { 0x3, 0x2,   6}, 	/* target:  14400bps, actual:  14285.71bps (error:   0.794%) */
		  { 0x5, 0x1,   6}, 	/* target:  19200bps, actual:  19047.62bps (error:  -0.794%) */
		  { 0x5, 0x0,   6}, 	/* target:  38400bps, actual:  38095.24bps (error:  -0.794%) */
		  { 0x3, 0x0,   6}, 	/* target:  57600bps, actual:  57142.86bps (error:  -0.794%) */
		  { 0x3, 0x2,   0}, 	/* target: 115200bps, actual: 100000.00bps (error: -13.194%) */
		  { 0x3, 0x1,   0}, 	/* target: 230400bps, actual: 200000.00bps (error: -13.194%) */
		  { 0x3, 0x0,   0}, 	/* target: 460800bps, actual: 400000.00bps (error: -13.194%) */
		  { 0x3, 0x0,   0} },	/* target: 921600bps, actual: 400000.00bps (error: -56.597%) */

		/* for CLK_RLIN = 4MHz */	
		{ { 0x3, 0x3,  12}, 	/* target:   9600bps, actual:   9615.38bps (error:   0.160%) */
		  { 0x5, 0x1,  22}, 	/* target:  14400bps, actual:  14492.75bps (error:   0.000%) */
		  { 0x3, 0x2,  12}, 	/* target:  19200bps, actual:  19230.77bps (error:   0.160%) */
		  { 0x3, 0x1,  12}, 	/* target:  38400bps, actual:  38461.54bps (error:   0.160%) */
		  { 0x3, 0x0,  16}, 	/* target:  57600bps, actual:  58823.53bps (error:   2.124%) */
		  { 0x5, 0x1,   2}, 	/* target: 115200bps, actual: 111111.11bps (error:  -3.549%) */
		  { 0x5, 0x0,   2}, 	/* target: 230400bps, actual: 222222.22bps (error:  -3.549%) */
		  { 0x3, 0x1,   0}, 	/* target: 460800bps, actual: 500000.00bps (error:   8.507%) */
		  { 0x3, 0x0,   0} },	/* target: 921600bps, actual:1000000.00bps (error:   8.507%) */

		/* for CLK_RLIN = 5MHz */	
		{ { 0x3, 0x1,  64}, 	/* target:   9600bps, actual:   9615.38bps (error:   0.160%) */
		  { 0x5, 0x1,  28}, 	/* target:  14400bps, actual:  14367.82bps (error:   0.223%) */
		  { 0x3, 0x0,  64}, 	/* target:  19200bps, actual:  19230.77bps (error:   0.160%) */
		  { 0x5, 0x1,  10}, 	/* target:  38400bps, actual:  37878.79bps (error:  -1.357%) */
		  { 0x3, 0x1,  10}, 	/* target:  57600bps, actual:  56818.18bps (error:  -1.357%) */
		  { 0x3, 0x0,  10}, 	/* target: 115200bps, actual: 113636.36bps (error:  -1.357%) */
		  { 0x3, 0x0,   4}, 	/* target: 230400bps, actual: 250000.00bps (error:   8.507%) */
		  { 0x5, 0x1,   0}, 	/* target: 460800bps, actual: 416666.67bps (error:  -9.578%) */
		  { 0x5, 0x0,   0} },	/* target: 921600bps, actual: 833333.33bps (error:  -9.578%) */

		/* for CLK_RLIN = 8MHz */	
		{ { 0x5, 0x0, 138}, 	/* target:   9600bps, actual:   9592.33bps (error:  -0.080%) */
		  { 0x3, 0x0, 138}, 	/* target:  14400bps, actual:  14388.49bps (error:   0.080%) */
		  { 0x3, 0x3,  12}, 	/* target:  19200bps, actual:  19230.77bps (error:   0.160%) */
		  { 0x3, 0x2,  12}, 	/* target:  38400bps, actual:  38461.54bps (error:   0.160%) */
		  { 0x5, 0x0,  22}, 	/* target:  57600bps, actual:  57971.01bps (error:   0.644%) */
		  { 0x3, 0x0,  16}, 	/* target: 115200bps, actual: 117647.06bps (error:   2.124%) */
		  { 0x5, 0x1,   2}, 	/* target: 230400bps, actual: 222222.22bps (error:  -3.549%) */
		  { 0x5, 0x0,   2}, 	/* target: 460800bps, actual: 444444.44bps (error:  -3.549%) */
		  { 0x3, 0x1,   0} },	/* target: 921600bps, actual:1000000.00bps (error:   8.507%) */

		/* for CLK_RLIN = 10MHz */	
		{ { 0x3, 0x2,  64}, 	/* target:   9600bps, actual:   9615.38bps (error:   0.160%) */
		  { 0x5, 0x2,  28}, 	/* target:  14400bps, actual:  14367.82bps (error:   0.223%) */
		  { 0x3, 0x1,  64}, 	/* target:  19200bps, actual:  19230.77bps (error:   0.160%) */
		  { 0x3, 0x0,  64}, 	/* target:  38400bps, actual:  38461.54bps (error:   0.160%) */
		  { 0x5, 0x0,  28}, 	/* target:  57600bps, actual:  57471.26bps (error:  -0.223%) */
		  { 0x3, 0x1,  10}, 	/* target: 115200bps, actual: 113636.36bps (error:  -1.357%) */
		  { 0x3, 0x0,  10}, 	/* target: 230400bps, actual: 227272.73bps (error:  -1.357%) */
		  { 0x3, 0x0,   4}, 	/* target: 460800bps, actual: 500000.00bps (error:   8.507%) */
		  { 0x5, 0x1,   0} },	/* target: 921600bps, actual: 833333.33bps (error:  -9.578%) */

		/* for CLK_RLIN = 20MHz */	
		{ { 0x3, 0x0, 520}, 	/* target:   9600bps, actual:   9596.93bps (error:  -0.032%) */
		  { 0x3, 0x0, 346}, 	/* target:  14400bps, actual:  14409.22bps (error:   0.000%) */
		  { 0x3, 0x2,  64}, 	/* target:  19200bps, actual:  19230.77bps (error:   0.160%) */
		  { 0x3, 0x1,  64}, 	/* target:  38400bps, actual:  38461.54bps (error:   0.160%) */
		  { 0x5, 0x1,  28}, 	/* target:  57600bps, actual:  57471.26bps (error:  -0.223%) */
		  { 0x5, 0x0,  28}, 	/* target: 115200bps, actual: 114942.53bps (error:  -0.223%) */
		  { 0x3, 0x1,  10}, 	/* target: 230400bps, actual: 227272.73bps (error:  -1.357%) */
		  { 0x3, 0x0,  10}, 	/* target: 460800bps, actual: 454545.45bps (error:  -1.357%) */
		  { 0x3, 0x0,   4} },	/* target: 921600bps, actual:1000000.00bps (error:   8.507%) */

		/* for CLK_RLIN = 80MHz */	
		{ { 0x5, 0x0, 1388}, 	/* target:   9600bps, actual:   9599.23bps (error:  -0.008%) */
		  { 0x5, 0x1, 462}, 	/* target:  14400bps, actual:  14398.85bps (error:   0.008%) */
		  { 0x3, 0x1, 520}, 	/* target:  19200bps, actual:  19193.86bps (error:  -0.032%) */
		  { 0x3, 0x0, 520}, 	/* target:  38400bps, actual:  38387.72bps (error:  -0.032%) */
		  { 0x3, 0x0, 346}, 	/* target:  57600bps, actual:  57636.89bps (error:   0.064%) */
		  { 0x5, 0x2,  28}, 	/* target: 115200bps, actual: 114942.53bps (error:  -0.223%) */
		  { 0x5, 0x1,  28}, 	/* target: 230400bps, actual: 229885.06bps (error:  -0.223%) */
		  { 0x5, 0x0,  28}, 	/* target: 460800bps, actual: 459770.11bps (error:  -0.223%) */
		  { 0x3, 0x1,  10} },	/* target: 921600bps, actual: 909090.91bps (error:  -1.357%) */
};


/*******************************************************************************
* Global variables (preset baudrate for LIN master)
*******************************************************************************/
/* setting value of RLN3nLWBR.LPRS[2:0] bit and RLN3nLBRP0 register */
const RLIN3m_s_config_baudrate RLIN3m_Baudrate[RLIN3_e_clk_num][RLIN3m_e_baudrate_num] = {
		/* for CLK_RLIN = 1.6MHz */	
		{ {0x2,  24},	/* fa =   1000.0bps (error:   0.000%), fb =    500.0bps, fc =    125.0bps */
		  {0x0,  40},	/* fa =   2439.0bps (error:   1.626%), fb =   1219.5bps, fc =    304.9bps */
		  {0x1,   4},	/* fa =  10000.0bps (error:   4.167%), fb =   5000.0bps, fc =   1250.0bps */
		  {0x0,   8},	/* fa =  11111.1bps (error:   6.838%), fb =   5555.6bps, fc =   1388.9bps */
		  {0x0,   4},	/* fa =  20000.0bps (error:   4.167%), fb =  10000.0bps, fc =   2500.0bps */
		  {0x0,   4},	/* fa =  20000.0bps (error:   0.000%), fb =  10000.0bps, fc =   2500.0bps */
		  {0x1,   0},	/* fa =  50000.0bps (error:  14.155%), fb =  25000.0bps, fc =   6250.0bps */
		  {0x0,   0},	/* fa = 100000.0bps (error:  47.929%), fb =  50000.0bps, fc =  12500.0bps */
		  {0x0,   0} },	/* fa = 100000.0bps (error: -13.194%), fb =  50000.0bps, fc =  12500.0bps */
					
		/* for CLK_RLIN = 4MHz */	
		{ {0x1, 124},	/* fa =   1000.0bps (error:   0.000%), fb =    500.0bps, fc =    125.0bps */
		  {0x3,  12},	/* fa =   2403.8bps (error:   0.160%), fb =   1201.9bps, fc =    300.5bps */
		  {0x1,  12},	/* fa =   9615.4bps (error:   0.160%), fb =   4807.7bps, fc =   1201.9bps */
		  {0x3,   2},	/* fa =  10416.7bps (error:   0.160%), fb =   5208.3bps, fc =   1302.1bps */
		  {0x0,  12},	/* fa =  19230.8bps (error:   0.160%), fb =   9615.4bps, fc =   2403.8bps */
		  {0x2,   2},	/* fa =  20833.3bps (error:   4.167%), fb =  10416.7bps, fc =   2604.2bps */
		  {0x0,   4},	/* fa =  50000.0bps (error:  14.155%), fb =  25000.0bps, fc =   6250.0bps */
		  {0x2,   0},	/* fa =  62500.0bps (error:  -7.544%), fb =  31250.0bps, fc =   7812.5bps */
		  {0x1,   0} },	/* fa = 125000.0bps (error:   8.507%), fb =  62500.0bps, fc =  15625.0bps */
		  
		/* for CLK_RLIN = 5MHz */	
		{ {0x3,  38},	/* fa =   1001.6bps (error:   0.160%), fb =    500.8bps, fc =    125.2bps */
		  {0x1,  64},	/* fa =   2403.8bps (error:   0.160%), fb =   1201.9bps, fc =    300.5bps */
		  {0x5,   0},	/* fa =   9765.6bps (error:   1.725%), fb =   4882.8bps, fc =   1220.7bps */
		  {0x1,  14},	/* fa =  10416.7bps (error:   0.160%), fb =   5208.3bps, fc =   1302.1bps */
		  {0x4,   0},	/* fa =  19531.3bps (error:   1.725%), fb =   9765.6bps, fc =   2441.4bps */
		  {0x4,   0},	/* fa =  19531.3bps (error:  -2.344%), fb =   9765.6bps, fc =   2441.4bps */
		  {0x0,   6},	/* fa =  44642.9bps (error:   1.924%), fb =  22321.4bps, fc =   5580.4bps */
		  {0x2,   0},	/* fa =  78125.0bps (error:  15.570%), fb =  39062.5bps, fc =   9765.6bps */
		  {0x0,   2} },	/* fa = 104166.7bps (error:  -9.578%), fb =  52083.3bps, fc =  13020.8bps */

		/* for CLK_RLIN = 8MHz */	
		{ {0x2, 124},	/* fa =   1000.0bps (error:   0.000%), fb =    500.0bps, fc =    125.0bps */
		  {0x4,  12},	/* fa =   2403.8bps (error:   0.160%), fb =   1201.9bps, fc =    300.5bps */
		  {0x2,  12},	/* fa =   9615.4bps (error:   0.160%), fb =   4807.7bps, fc =   1201.9bps */
		  {0x4,   2},	/* fa =  10416.7bps (error:   0.160%), fb =   5208.3bps, fc =   1302.1bps */
		  {0x1,  12},	/* fa =  19230.8bps (error:   0.160%), fb =   9615.4bps, fc =   2403.8bps */
		  {0x0,  24},	/* fa =  20000.0bps (error:   0.000%), fb =  10000.0bps, fc =   2500.0bps */
		  {0x0,  10},	/* fa =  45454.5bps (error:   3.778%), fb =  22727.3bps, fc =   5681.8bps */
		  {0x0,   6},	/* fa =  71428.6bps (error:   5.664%), fb =  35714.3bps, fc =   8928.6bps */
		  {0x2,   0} },	/* fa = 125000.0bps (error:   8.507%), fb =  62500.0bps, fc =  15625.0bps */

		/* for CLK_RLIN = 10MHz */	
		{ {0x4,  38},	/* fa =   1001.6bps (error:   0.160%), fb =    500.8bps, fc =    125.2bps */
		  {0x2,  64},	/* fa =   2403.8bps (error:   0.160%), fb =   1201.9bps, fc =    300.5bps */
		  {0x0,  64},	/* fa =   9615.4bps (error:   0.160%), fb =   4807.7bps, fc =   1201.9bps */
		  {0x2,  14},	/* fa =  10416.7bps (error:   0.160%), fb =   5208.3bps, fc =   1302.1bps */
		  {0x5,   0},	/* fa =  19531.3bps (error:   1.725%), fb =   9765.6bps, fc =   2441.4bps */
		  {0x0,  30},	/* fa =  20161.3bps (error:   0.806%), fb =  10080.6bps, fc =   2520.2bps */
		  {0x1,   6},	/* fa =  44642.9bps (error:   1.924%), fb =  22321.4bps, fc =   5580.4bps */
		  {0x0,   8},	/* fa =  69444.4bps (error:   2.728%), fb =  34722.2bps, fc =   8680.6bps */
		  {0x0,   4} },	/* fa = 125000.0bps (error:   8.507%), fb =  62500.0bps, fc =  15625.0bps */

		/* for CLK_RLIN = 20MHz */	
		{ {0x5,  38},	/* fa =   1001.6bps (error:   0.160%), fb =    500.8bps, fc =    125.2bps */
		  {0x3,  64},	/* fa =   2403.8bps (error:   0.160%), fb =   1201.9bps, fc =    300.5bps */
		  {0x1,  64},	/* fa =   9615.4bps (error:   0.160%), fb =   4807.7bps, fc =   1201.9bps */
		  {0x3,  14},	/* fa =  10416.7bps (error:   0.160%), fb =   5208.3bps, fc =   1302.1bps */
		  {0x0,  64},	/* fa =  19230.8bps (error:   0.160%), fb =   9615.4bps, fc =   2403.8bps */
		  {0x1,  30},	/* fa =  20161.3bps (error:   0.806%), fb =  10080.6bps, fc =   2520.2bps */
		  {0x2,   6},	/* fa =  44642.9bps (error:   1.924%), fb =  22321.4bps, fc =   5580.4bps */
		  {0x1,   8},	/* fa =  69444.4bps (error:   2.728%), fb =  34722.2bps, fc =   8680.6bps */
		  {0x1,   4} },	/* fa = 125000.0bps (error:   8.507%), fb =  62500.0bps, fc =  15625.0bps */

		/* for CLK_RLIN = 80MHz */	
		{ {0x7,  38},	/* fa =   1001.6bps (error:   0.160%), fb =    500.8bps, fc =    125.2bps */
		  {0x5,  64},	/* fa =   2403.8bps (error:   0.160%), fb =   1201.9bps, fc =    300.5bps */
		  {0x3,  64},	/* fa =   9615.4bps (error:   0.160%), fb =   4807.7bps, fc =   1201.9bps */
		  {0x5,  14},	/* fa =  10416.7bps (error:   0.160%), fb =   5208.3bps, fc =   1302.1bps */
		  {0x2,  64},	/* fa =  19230.8bps (error:   0.160%), fb =   9615.4bps, fc =   2403.8bps */
		  {0x1, 124},	/* fa =  20000.0bps (error:   0.000%), fb =  10000.0bps, fc =   2500.0bps */
		  {0x1,  56},	/* fa =  43859.6bps (error:   0.136%), fb =  21929.8bps, fc =   5482.5bps */
		  {0x0,  72},	/* fa =  68493.2bps (error:   1.321%), fb =  34246.6bps, fc =   8561.6bps */
		  {0x0,  42} }	/* fa = 116279.1bps (error:   0.937%), fb =  58139.5bps, fc =  14534.9bps */
};


/*******************************************************************************
* Function body
*******************************************************************************/

/*******************************************************************************
* Description  : configuration of baudrate for UART
* Arguments    : uint8_t n                       : unit number of RLIN3
*                R_RLIN3u_Config_baudrate *config: configuration of baudrate for UART
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3u_Config_baudrate( uint8_t n, RLIN3u_s_config_baudrate *config  ){
	
	uint8_t 	value08;     		/* reister setting value */
	uint8_t 	ret = RET_OK;
	
	
	value08 = ( (config->NSPB << 4) |
	            (config->LPRS << 1) );
	ret += Reg08WRC( &rRLN3nLWBR(n).UINT8, value08, 0xFF );
	
	/* RLN3nLBRP01: baud rate prescalar */
	ret += Reg16WRC( &rRLN3nLBRP01(n).UINT16, config->LBRP, 0xFFFF );
	
	return( ret );
}
#if 0
[Example to use R_RLIN3u_Config_baudrate

	RLIN3u_s_config_baudrate	config;
	uint8_t 	ret = RET_OK;
	
	/* prepare baudrate parameter */
	/* target: 115200bps, actual: 114285.71bps (error:  -0.794%) */
	config.NSPB = 0x6;	/* Bit Sampling Count Select */
	config.LPRS = 0x1;	/* Prescaler Clock Select */
	config.LBRP = 0x0; 	/* baud rate prescaler divides */
	
	/* Set register */
	ret = R_RLIN3u_Config_baudrate( n, &config );
#endif


/*******************************************************************************
* Description  : configuration of baudrate for LIN master
* Arguments    : uint8_t n                       : unit number of RLIN3
*                R_RLIN3m_Config_baudrate *config: configuration of baudrate for LIN master
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3m_Config_baudrate( uint8_t n, RLIN3m_s_config_baudrate *config  ){
	
	uint8_t 	value08;     		/* reister setting value */
	uint8_t 	ret = RET_OK;
	
	
	value08 = ( (0            << 4) |	/* NSPB[3:0]=0: 16 sampling times (fixed) */
	            (config->LPRS << 1) );
	ret += Reg08WRC( &rRLN3nLWBR(n).UINT8, value08, 0xFF );
	
	/* RLN3nLBRP0: baud rate prescalar */
	ret += Reg08WRC( &rRLN3nLBRP0(n).UINT8, config->LBRP0, 0xFF );
	
	return( ret );
}


/*******************************************************************************
* Description  : configuration of baudrate from preset baudrate for UART
* Arguments    : uint8_t n                       : unit number of RLIN3
*                R_RLIN3u_Config_baudrate *config: configuration of baudrate for UART
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3u_SetPresetBaudRate( uint8_t n, RLIN3_e_clk clock, RLIN3u_e_baudrate baudrete ){
	
	RLIN3u_s_config_baudrate	config;
	uint8_t 	ret = RET_OK;
	
	
	/* Get NSPB, LPRS and LBRP value from the array of the preset baudrate */
	config.NSPB = RLIN3u_Baudrate[clock][baudrete].NSPB;
	config.LPRS = RLIN3u_Baudrate[clock][baudrete].LPRS;
	config.LBRP = RLIN3u_Baudrate[clock][baudrete].LBRP;
	
	/* Set register */
	ret = R_RLIN3u_Config_baudrate( n, &config );
	
	
	return( ret );
}


/*******************************************************************************
* Description  : configuration of baudrate from preset baudrate for LIN master
* Arguments    : uint8_t n                       : unit number of RLIN3
*                R_RLIN3u_Config_baudrate *config: configuration of baudrate for LIN master
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3m_SetPresetBaudRate( uint8_t n, RLIN3_e_clk clock, RLIN3m_e_baudrate baudrete ){
	
	RLIN3m_s_config_baudrate	config;
	uint8_t 	ret = RET_OK;
	
	
	/* Get NSPB, LPRS and LBRP value from the array of the preset baudrate */
	config.LPRS  = RLIN3m_Baudrate[clock][baudrete].LPRS;
	config.LBRP0 = RLIN3m_Baudrate[clock][baudrete].LBRP0;
	
	/* Set register */
	ret = R_RLIN3m_Config_baudrate( n, &config );
	
	
	return( ret );
}


/*******************************************************************************
* Description  : configuration of communication for UART mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3u_s_config *config: configuration of UART
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3u_Config( uint8_t n, RLIN3u_s_config *config  ){
	
	uint8_t 	value08;     		/* reister setting value */
	uint8_t 	ret = RET_OK;
	

	/* UART mode selection and noise filter ON/OFF */
	value08 = ( (config->LRDNFS << 5) |	/* enable/disable RX noise filter  */
	            (1 << 0) );            	/* LMD[1:0]=01B: select UART mode (fixed in UART mode) */
	ret += Reg08WRC( &rRLN3nLMD(n).UINT8, value08, 0x23 );
	
	/* Enables error detection */
	value08 = ( (config->LEDE.BITu.FERE << 3) | 	/* enable/disable framing error detection */
	            (config->LEDE.BITu.OERE << 2) | 	/* enable/disable overrun error detection */
	            (config->LEDE.BITu.BERE << 0) );	/* enable/disable bit error detection     */
	ret += Reg08WRC( &rRLN3nLEDE(n).UINT8, value08, 0x0D );
	
	/* set data format */
	value08 = ( (config->LBFC.BITu.UTPS  << 6) | 	/* transfer data normal output */
	            (config->LBFC.BITu.URPS  << 5) | 	/* receive data normal input   */
	            (config->LBFC.BITu.UPS   << 3) | 	/* disable parity         */
	            (config->LBFC.BITu.USBLS << 2) | 	/* stop bit = 1 bit           */
	            (config->LBFC.BITu.UBOS  << 1) | 	/* transfer format = LSB first */
	            (config->LBFC.BITu.UBLS  << 0) );	/* charactor length = 8 bits   */
	ret += Reg08WRC( &rRLN3nLBFC(n).UINT8, value08, 0x7F );
	
	/* set inter byte space */
	value08 = (config->IBS << 4); 	/* inter byte space = 0Tbit */
	ret += Reg08WRC( &rRLN3nLSC(n).UINT8, value08, 0x30 );

	/* Transmission interrupt is generated at the completion of transmission, and other options */
	value08 = ( (config->LUOR1.BITu.UECD   << 4) | 	/* Expansion Bit Comparison Disable */
	            (config->LUOR1.BITu.UTIGTS << 3) | 	/* Transmission Interrupt Generation Timing Select */
	            (config->LUOR1.BITu.UEBDCE << 2) | 	/* Expansion Bit Data Comparison EnableExpansion Bit Data Comparison Enable */
	            (config->LUOR1.BITu.UEBDL  << 1) | 	/* Expansion Bit Detection Level Select */
	            (config->LUOR1.BITu.UEBE   << 0) );	/* Expansion Bit Enable   */
	ret += Reg08WRC( &rRLN3nLUOR1(n).UINT8, value08, 0x1F );
	
	
	return( ret );
}
#if 0
[Example to use R_RLIN3u_Config
	RLIN3u_s_config 	config; /* configuration of UART */
	
	/* communication setting */
	/**************************************************************************/
	/*  noise filter ON/OFF */
	config.LRDNFS = RLIN3u_e_LRDNFS_enable;	/* enable the noise filter */
	
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
#endif


/*******************************************************************************
* Description  : configuration of LIN master communication
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3u_s_config *config: configuration of LIN master
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3m_Config( uint8_t n, RLIN3m_s_config *config  ){
	
	uint8_t 	value08;     		/* reister setting value */
	uint8_t 	ret = RET_OK;
	

	/* LIN master mode selection and noise filter ON/OFF */
	value08 = ( (config->LRDNFS << 5) |               	/* enable/disable RX noise filter  */
	            (config->LIOS   << 4) |               	/* LIN Interrupt Output Select */
	            (config->LCKS   << 2) |               	/* LIN System Clock Select */
	            (RLIN3m_e_LMD_LIN_master_mode << 0) );	/* LMD[1:0]=00B: LIN master mode */
	ret += Reg08WRC( &rRLN3nLMD(n).UINT8, value08, 0x3F );
	
	/* Enable LIN interrupt */
	value08 = ( (config->LIE.BITm.SHIE  << 3) | 	/* enable/disable successful header transmission interrupt request */
	            (config->LIE.BITm.ERRIE << 2) | 	/* error detection interrupt request */
	            (config->LIE.BITm.FRCIE << 1) | 	/* successful frame/wake-up reception interrupt request */
	            (config->LIE.BITm.FTCIE << 0) ); 	/* successful frame/wake-up transmission interrupt request */
	ret += Reg08WRC( &rRLN3nLIE(n).UINT8, value08, 0x0F );
	
	/* Enables error detection */
	value08 = ( (config->LEDE.BITm.LTES  << 7) |  	/* Frame/Response timeout error selection */
	            (config->LEDE.BITm.FERE  << 3) |  	/* enable/disable framing error detection */
	            (config->LEDE.BITm.FTERE << 2) |  	/* enable/disable frame/response timeout error detection */
	            (config->LEDE.BITm.PBERE << 1) |  	/* enable/disable physical bus error detection */
	            (config->LEDE.BITm.BERE  << 0) );	/* enable/disable bit error detection */
	ret += Reg08WRC( &rRLN3nLEDE(n).UINT8, value08, 0x1F );
	
	/* Configure LIN Break Field */
	value08 = ( (config->BDT << 4) | 	/* Transmission Break Delimiter (High Level)  */
	            (config->BLT << 0) );	/* Transmission Break (Low Level) Width   */
	ret += Reg08WRC( &rRLN3nLBFC(n).UINT8, value08, 0x3F );
	
	/* Configure LIN Space */
	value08 = ( (config->IBS  << 4) | 	/* Inter-Byte Space Select */
	            (config->IBHS << 0) );	/* Inter-Byte Space (Header)/Response Space Select */
	ret += Reg08WRC( &rRLN3nLSC(n).UINT8, value08, 0x3F );
	
	/* Transmission interrupt is generated at the completion of transmission, and other options */
	value08 = (config->WUTL << 4); 	/* Wake-up Transmission Low Level Width Select */
	ret += Reg08WRC( &rRLN3nLWUP(n).UINT8, value08, 0xF0 );
	
	
	return( ret );
}


/*******************************************************************************
* Description  : configuration of LIN slave communication
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3u_s_config *config: configuration of LIN slave
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3s_Config( uint8_t n, RLIN3s_s_config *config  ){
	
	uint8_t 	value08;     		/* reister setting value */
	uint8_t 	ret = RET_OK;
	

	/* LIN master mode selection and noise filter ON/OFF */
	value08 = ( (config->LRDNFS << 5) |  	/* enable/disable RX noise filter  */
	            (config->LIOS   << 4) |  	/* LIN Interrupt Output Select */
	            (config->LMD    << 0) );	/* LIN slave mode Select */
	ret += Reg08WRC( &rRLN3nLMD(n).UINT8, value08, 0x3F );
	
	/* Enable LIN interrupt */
	value08 = ( (config->LIE.BITs.SHIE  << 3) | 	/* enable/disable successful header transmission interrupt request */
	            (config->LIE.BITs.ERRIE << 2) | 	/* error detection interrupt request */
	            (config->LIE.BITs.FRCIE << 1) | 	/* successful frame/wake-up reception interrupt request */
	            (config->LIE.BITs.FTCIE << 0) ); 	/* successful frame/wake-up transmission interrupt request */
	ret += Reg08WRC( &rRLN3nLIE(n).UINT8, value08, 0x0F );
	
	/* Enables error detection */
	value08 = ( (config->LEDE.BITs.LTES  << 7) |  	/* Frame/Response timeout error selection */
	            (config->LEDE.BITs.IPERE << 6) |  	/* enable/disable ID Parity error detection */
	            (config->LEDE.BITs.SFERE << 4) |  	/* enable/disable Sync Field error detection */
	            (config->LEDE.BITs.FERE  << 3) |  	/* enable/disable framing error detection */
	            (config->LEDE.BITs.TERE  << 2) |  	/* enable/disable frame/response timeout error detection */
	            (config->LEDE.BITs.BERE  << 0) );	/* enable/disable bit error detection */
	ret += Reg08WRC( &rRLN3nLEDE(n).UINT8, value08, 0xDD );
	
	/* set data format */
	value08 = (config->LBLT << 0); 	/* Reception Break (Low-Level) Detection Width */
	ret += Reg08WRC( &rRLN3nLBFC(n).UINT8, value08, 0x01 );
	
	/* set data format */
	value08 = ( (config->IBS  << 4) | 	/* Inter-Byte Space Select */
	            (config->IBHS << 0) );	/* Response Space Setting */
	ret += Reg08WRC( &rRLN3nLSC(n).UINT8, value08, 0x3F );
	
	/* Transmission interrupt is generated at the completion of transmission, and other options */
	value08 = (config->WUTL << 4); 	/* Wake-up Transmission Low Level Width Select */
	ret += Reg08WRC( &rRLN3nLWUP(n).UINT8, value08, 0xF0 );
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Release LIN reset
* Arguments    : uint8_t n              : unit number of RLIN3
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3_ReleaseLINreset( uint8_t n ){
	
	uint8_t 	ret = RET_OK;
	
	
	/* release LIN reset mode */
	ret += Reg08SetBitCheck( &rRLN3nLCUC(n).UINT8, 0 );	/* OM0=1: release LIN reset mode */
	
	/* check reset release */
	Reg08Wait1( &rRLN3nLMST(n).UINT8, 0 );	/* wait until OMM0 = 1 */
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Transit LIN reset
* Arguments    : uint8_t n              : unit number of RLIN3
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3_TransitLINreset( uint8_t n ){
	
	uint8_t 	ret = RET_OK;
	
	
	/* transit to LIN reset mode */
	/* [DJ] bug fix: OM0 is bit 0 of RLN3nLCUC (bit 1 is OM1).                  */
	/*      Clearing bit 1 never sets OM0=0, so the OMM0 wait below could hang. */
	ret += Reg08ClearBitCheck( &rRLN3nLCUC(n).UINT8, 0 );	/* OM0=0: transit to LIN reset mode */
	
	/* check reset relase */
	Reg08Wait0( &rRLN3nLMST(n).UINT8, 0 );	/* wait until OMM0 = 0 */
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Enters self-test mode
* Arguments    : uint8_t n              : unit number of RLIN3
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3ms_EnterSelfTestMode( uint8_t n ){
	
	uint8_t 	ret = RET_OK;
	
	
	/* transit LIN reset mode */
	ret += R_RLIN3_TransitLINreset( n );
	
	/* special sequence to enter self-test mode */
	rRLN3nLSTC(n).UINT8 = 0xA7;
	rRLN3nLSTC(n).UINT8 = 0x58;
	rRLN3nLSTC(n).UINT8 = 0x01;
	
	/* wait until mode transition complete */
	Reg08Wait1( &rRLN3nLSTC(n).UINT8, 0 );		/* wait until LSTM = 1 */
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Enters LIN operation mode
* Arguments    : uint8_t n              : unit number of RLIN3
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3ms_EnterOperationMode( uint8_t n ){
	
	uint8_t 	ret = RET_OK;
	
	
	/* release LIN reset mode */
	ret += R_RLIN3_ReleaseLINreset( n );
	
	/* transit LIN operation mode */
	ret += Reg08WRC( &rRLN3nLCUC(n).UINT8, (3 << 0), 0x03 );	/* OM1-0=11B: LIN operation mode */
	
	/* wait until mode transition complete */
	while( (rRLN3nLMST(n).UINT8 & (3 << 0)) != 3U )	/* wait unti OMM1=1 and OMM0=1 */
		;
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Set transmit setting and set frame to transmit buffer
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *tx_packet: LIN packet for transmission
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3ms_PrepareTransmit( uint8_t n, RLIN3ms_s_packet *tx_packet ){
	
	uint8_t 	value08;     		/* reister setting value */
	uint8_t 	i;
	uint8_t		parity = 0;
	uint8_t 	ret = RET_OK;
	
	
	/* set transmit control data
	***************************************************************************/
	value08 = ( (tx_packet->lss  << 7) | 	/* LSS: Transmission/Reception Continuation Select */
	            (tx_packet->fsm  << 6) | 	/* FSM: Frame Separate Mode Select */
	            (tx_packet->csm  << 5) | 	/* CSM: Checksum Select */
	            (RLIN3ms_e_RFT_tx  << 4) | 	/* RMT=1(transmit): Response Field Communication Direction Select */
	            (tx_packet->rfdl << 0) );	/* RFDL[3:0]=0: Response Field Length Select */
	ret += Reg08WRC( &rRLN3nLDFC(n).UINT8, value08, 0xFF );
	
	
	/* set transmit ID
	***************************************************************************/
	/* calculate ID[5:0] bit parity */
	for( i = 0;  i <= 5; i++ ){
		parity += ((tx_packet->id & (1 << i)) >> i);
	}
	
	/* make IDP[1:0] bit value */
	if( (parity % 2) == 0 ){	// even
		if( tx_packet->id_parity_type == RLIN3ms_e_parity_odd ){
			parity = 1;		/* IDP[1:0] bit */
		}else{
			parity = 0;		/* IDP[1:0] bit */
		}
	}else{				// odd
		if( tx_packet->id_parity_type == RLIN3ms_e_parity_enve ){
			parity = 1;		/* IDP[1:0] bit */
		}else{
			parity = 0;		/* IDP[1:0] bit */
		}
	}
	
	/* set ID to register */
	value08 = (parity << 6) | (tx_packet->id & 0x3F);
	ret += Reg08WRC( &rRLN3nLIDB(n).UINT8, value08, 0xFF );
	
	
	/* set transmit data
	***************************************************************************/
	for( i = 0;  i < RLIN3_b_NUM; i++ ){
		ret += Reg08WRC( &rRLN3nLDBRb(n,i+1).UINT8, tx_packet->data[i], 0xFF );
	}
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Transmit Header in LIN master mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *tx_packet: LIN packet for transmit
* Return Value : RET_OK       : Transmit was successful
*                RET_ERR_STATE: Transmit was failed
*******************************************************************************/
uint8_t R_RLIN3m_TransmitHeader( uint8_t n, RLIN3ms_s_packet *tx_packet ){

	uint8_t          	ret = RET_OK;
	RLIN3_s_RLN3nLST	read08;
	
	
	/* start transmit */
	Reg08SetBitCheck( &rRLN3nLTRC(n).UINT8, 1 );	/* FTS=1 */
	
	/* wait data receive */
	do{
		/* read status */
		read08.UINT8 = Reg08Read( rRLN3nLST(n).UINT8 );
		
		/* if error occured */
		if( read08.BITm.ERR ){
			ret = RET_ERR_STATE;
			break;
		}
	}while( read08.BITm.HTRC == 1 );	/* exit if successful header transmission */
	
	/* Clear flags */
	read08.UINT8 = Reg08Read(rRLN3nLST(n).UINT8);
	read08.UINT8 &= ~0x88;	/* clear ERR and FTC bit */
	rRLN3nLST(n).UINT8 = read08.UINT8;
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Transmit Response in LIN master mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *tx_packet: LIN packet for transmit
* Return Value : RET_OK       : Transmit was successful
*                RET_ERR_STATE: Transmit was failed
*******************************************************************************/
uint8_t R_RLIN3m_TransmitResponse( uint8_t n, RLIN3ms_s_packet *tx_packet ){

	uint8_t          	ret = RET_OK;
	RLIN3_s_RLN3nLST	read08;
	
	
	/* start transmit */
	Reg08SetBitCheck( &rRLN3nLTRC(n).UINT8, 1 );	/* RTS=1 */
	
	/* wait data receive */
	do{
		/* read status */
		read08.UINT8 = Reg08Read( rRLN3nLST(n).UINT8 );
		
		/* if error occured */
		if( read08.BITm.ERR ){
			ret = RET_ERR_STATE;
			break;
		}
	}while( read08.BITm.HTRC == 1 );	/* exit if successful header transmission */
	
	/* Get transmitted checksum */
	tx_packet->checksum = rRLN3nLCBR(n).UINT8;
	
	/* Clear flags */
	read08.UINT8 = Reg08Read(rRLN3nLST(n).UINT8);
	read08.UINT8 &= ~0x88;	/* clear ERR and FTC bit */
	rRLN3nLST(n).UINT8 = read08.UINT8;
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Receive Response in LIN master mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *rx_packet: LIN packet for reception
* Return Value : RET_OK       : Reception was successful
*                RET_ERR_STATE: Reception was failed
*******************************************************************************/
uint8_t R_RLIN3m_ReceiveResponse( uint8_t n, RLIN3ms_s_packet *rx_packet ){
	
	uint8_t           	i;
	RLIN3_s_RLN3nLST	read08;
	uint8_t         	ret = RET_OK;
	
	
	/* wait data receive */
	do{
		/* read status */
		read08.UINT8 = Reg08Read( rRLN3nLST(n).UINT8 );
		
		/* if error occured */
		if( read08.BITm.ERR ){
			ret = RET_ERR_STATE;
			break;
		}
	}while( read08.BITm.FRC == 1 );	/* exit if reception complete */
	
	/* Get received data from buffer */
	if( ret == RET_OK ){
		/* Get received data from buffer */
		for( i = 0;  i < 8; i++ ){
			rx_packet->data[i] = rRLN3nLDBRb(n,i+1).UINT8;
		}
		
		/* Get checksum from buffer */
		rx_packet->checksum = rRLN3nLCBR(n).UINT8;
	}
	
	/* Clear flags */
	read08.UINT8 = Reg08Read(rRLN3nLST(n).UINT8);
	read08.UINT8 &= ~0x4A;	/* clear D1RC, ERR and FRC bit */
	rRLN3nLST(n).UINT8 = read08.UINT8;
	
	return( ret );
}


/*******************************************************************************
* Description  : Set transmit setting and set frame to transmit buffer
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *tx_packet: LIN packet for reception
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t RLIN3s_PrepareReceive( uint8_t n, RLIN3ms_s_packet *rx_packet ){
	
	uint8_t 	value08;     		/* reister setting value */
	uint8_t 	ret = RET_OK;
	
	
	/* set transmit control data
	***************************************************************************/
	value08 = ( (rx_packet->lss   << 7) | 	/* LSS: Transmission/Reception Continuation Select */
	            (rx_packet->csm   << 5) | 	/* LCS: Checksum Select */
	            (RLIN3s_e_RCDS_rx << 4) | 	/* RCDS=1(reception): Response Field Communication Direction Select */
	            (rx_packet->rfdl  << 0) );	/* RFDL[3:0]=0: Response Field Length Select */
	ret += Reg08WRC( &rRLN3nLDFC(n).UINT8, value08, 0xFF );
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Receive Header in LIN slave mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *rx_packet: LIN packet for reception
* Return Value : RET_OK       : Reception was successful
*                RET_ERR_STATE: Reception was failed
*******************************************************************************/
uint8_t R_RLIN3s_ReceiveHeader( uint8_t n, RLIN3ms_s_packet *rx_packet ){
	
	uint8_t          	ret = RET_OK;
	RLIN3_s_RLN3nLST	read08;
	
	
	/* start reception */
	Reg08SetBitCheck( &rRLN3nLTRC(n).UINT8, 0 );	/* FTS=1 */
	
	/* wait data receive */
	do{
		/* read status */
		read08.UINT8 = Reg08Read( rRLN3nLST(n).UINT8 );
		
		/* if error occured */
		if( read08.BITm.ERR ){
			ret = RET_ERR_STATE;
			break;
		}
	}while( read08.BITm.HTRC == 1 );	/* exit if header reception complete */
	
	
	/* Clear flags */
	read08.UINT8 = Reg08Read(rRLN3nLST(n).UINT8);
	read08.UINT8 &= ~0x88;	/* clear ERR and HTRC bit */
	rRLN3nLST(n).UINT8 = read08.UINT8;
	
	/* Get header */
	rx_packet->id = Reg08Read( rRLN3nLIDB(n).UINT8 );
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Transmit Response in LIN slave mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *rx_packet: LIN packet for reception
* Return Value : RET_OK       : Transmit was successful
*                RET_ERR_STATE: Transmit was failed
*******************************************************************************/
uint8_t R_RLIN3s_TransmitResponse( uint8_t n, RLIN3ms_s_packet *rx_packet ){

	uint8_t          	ret = RET_OK;
	RLIN3_s_RLN3nLST	read08;
	
	
	/* start transmit */
	Reg08SetBitCheck( &rRLN3nLTRC(n).UINT8, 1 );	/* RTS=1 */
	
	/* wait data receive */
	do{
		/* read status */
		read08.UINT8 = Reg08Read( rRLN3nLST(n).UINT8 );
		
		/* if error occured */
		if( read08.BITm.ERR ){
			ret = RET_ERR_STATE;
			break;
		}
	}while( read08.BITm.FTC == 1 );	/* exit if successful response/wake-up transmission */
	
	/* check response space dominant detection */
	Reg08Wait1( &rRLN3nLRSS(n).UINT8, 0 );	/* wait until RSDD = 1 */
	
	/* Clear flags */
	read08.UINT8 = Reg08Read(rRLN3nLST(n).UINT8);
	read08.UINT8 &= ~0x09;	/* clear ERR and FTC bit */
	rRLN3nLST(n).UINT8 = read08.UINT8;
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Reception Response in LIN slave mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *rx_packet: LIN packet for reception
* Return Value : RET_OK       : Transmit was successful
*                RET_ERR_STATE: Transmit was failed
*******************************************************************************/
uint8_t R_RLIN3s_ReceiveResponse( uint8_t n, RLIN3ms_s_packet *rx_packet ){

	uint8_t         	i;
	uint8_t          	ret = RET_OK;
	RLIN3_s_RLN3nLST	read08;
	
	
	/* start reception */
	Reg08SetBitCheck( &rRLN3nLTRC(n).UINT8, 1 );	/* RTS=1 */
	
	/* wait data receive */
	do{
		/* read status */
		read08.UINT8 = Reg08Read( rRLN3nLST(n).UINT8 );
		
		/* if error occured */
		if( read08.BITm.ERR ){
			ret = RET_ERR_STATE;
			break;
		}
	}while( read08.BITm.FRC == 1 );	/* exit if Response/Wake-up reception complete */
	
	
	/* Get received data from buffer */
	if( ret == RET_OK ){
		for( i = 0;  i < 8; i++ ){
			rx_packet->data[i] = rRLN3nLDBRb(n,i+1).UINT8;
		}
		
		/* Get checksum from buffer */
		rx_packet->checksum = rRLN3nLCBR(n).UINT8;
	}
	
	
	/* Clear flags */
	read08.UINT8 = Reg08Read(rRLN3nLST(n).UINT8);
	read08.UINT8 &= ~0x4A;	/* clear D1RC, ERR and FRC bit */
	rRLN3nLST(n).UINT8 = read08.UINT8;
	
	
	return( ret );
}

/*******************************************************************************
* [DJ] UART polling API (added for RLIN33 UART test on R-Car U5L4)
*******************************************************************************/

/*******************************************************************************
* Description  : Transmit 1 byte (polling)
* Arguments    : uint8_t n    : unit number of RLIN3
*                uint8_t data : transmit data
* Return Value : None
*******************************************************************************/
void R_RLIN3u_SendByte( uint8_t n, uint8_t data ){
	
	/* wait until the previous transmission is finished (UTS = 0) */
	while( (Reg08Read( rRLN3nLST(n).UINT8 ) & RLIN3u_LST_UTS) != 0U )
		;
	
	/* writing LUTDR starts transmission (UTOE = 1 is required) */
	R_RLIN3u_Transmit( n, data );
}


/*******************************************************************************
* Description  : Transmit '\0' terminated string (polling)
* Arguments    : uint8_t n          : unit number of RLIN3
*                const char *string : transmit string
* Return Value : None
*******************************************************************************/
void R_RLIN3u_SendString( uint8_t n, const char *string ){
	
	while( *string != '\0' ){
		/* convert LF to CR+LF for terminal software (Tera Term) */
		if( *string == '\n' ){
			R_RLIN3u_SendByte( n, (uint8_t)'\r' );
		}
		R_RLIN3u_SendByte( n, (uint8_t)*string );
		string++;
	}
}


/*******************************************************************************
* Description  : Receive 1 byte (polling)
* Arguments    : uint8_t n        : unit number of RLIN3
*                uint8_t *data    : received data
*                uint32_t timeout : polling count (RLIN3u_WAIT_FOREVER: no timeout)
* Return Value : RET_OK       : 1 byte was received
*                RET_ERR_STATE: reception error (framing/overrun/bit) or timeout
*******************************************************************************/
uint8_t R_RLIN3u_ReceiveByte( uint8_t n, uint8_t *data, uint32_t timeout ){
	
	uint8_t 	status;
	uint32_t	count = 0U;
	
	
	/* wait until reception complete (FRC = 1) or error (ERR = 1) */
	do{
		status = Reg08Read( rRLN3nLST(n).UINT8 );
		
		if( (timeout != RLIN3u_WAIT_FOREVER) && (++count >= timeout) ){
			return( RET_ERR_STATE );	/* timeout */
		}
	}while( (status & (RLIN3u_LST_FRC | RLIN3u_LST_ERR)) == 0U );
	
	/* reception error: clear error status (FER/OER/BER) and return error */
	if( (status & RLIN3u_LST_ERR) != 0U ){
		rRLN3nLEST(n).UINT8 = 0x00;	/* write 0 to clear error flags */
		(void)R_RLIN3u_Receive( n );	/* discard received data */
		rRLN3nLST(n).UINT8 = (uint8_t)(status & ~RLIN3u_LST_FRC);
		return( RET_ERR_STATE );
	}
	
	/* get received data */
	*data = (uint8_t)R_RLIN3u_Receive( n );
	
	/* clear FRC flag (write 0) */
	rRLN3nLST(n).UINT8 = (uint8_t)(status & ~RLIN3u_LST_FRC);
	
	
	return( RET_OK );
}


/*******************************************************************************
* Return to default section
*******************************************************************************/
#pragma	section	default
