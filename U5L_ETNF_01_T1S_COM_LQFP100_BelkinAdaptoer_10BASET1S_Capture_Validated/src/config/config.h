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
* File Name    : config.h
* Version      : 1.00 (modified: [DJ] COM port -> RLIN33 P09_0/P09_1, 2026.10)
* Description  : This header file describes general configuration of driver,
*                application.
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__config_H__
#define	__config_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "product.h"
#include "R_driver_typedef.h"
#include "R_driver_general.h"


/*******************************************************************************
* Definition for monitor port
*  Defines the port group and bit assignment of the general-purpose port used to
*  check the operation of the application. This is called the monitor port.
*  In the application code, you need to use this definition to set the PM 
*  register to 0 so that the port specified in this definition can be used as 
*  a monitor port.
*
*  		R_PORT_ChangeOutputLevel_P(n,value)
*  		R_PORT_OutputHigh_Pnm(n,m)
*  		R_PORT_OutputLow_Pnm(n,m)
*  		R_PORT_ToggleOutputLevel_Pnm(n,m)
*  		R_PORT_ToggleOutputLevel_P(n,value)
*******************************************************************************/
/* port group used for monitor port
*******************************************************************************/
#define	CFG_M_Pn	1	/* ISO port */
#define	CFG_M_Pm	0


/* Error monitor port
*******************************************************************************/
/* port group used for monitor port */
#define	CFG_EP_GROUP       		18	/* for piggyback board */

/* bit assign for monitor port */
#define	CFG_EP_NMI       		0	/* NMI */
#define	CFG_EP_HardFault 		1	/* HardFault */
#define	CFG_EP_MemManage 		2	/* MemManage */
#define	CFG_EP_BusFault  		3	/* BusFault */
#define	CFG_EP_UsageFault		4	/* UsageFault */
#define	CFG_EP_SVC      		5	/* SVC */
#define	CFG_EP_DebugMon 		6	/* DebugMon */
#define	CFG_EP_PendSV       	7	/* PendSV */
#define	CFG_EP_SysTick      	8	/* SysTick */

#define	CFG_EP_TOGGLE_PERIOD	1000*1000


/*******************************************************************************
* Definition for COM port communication using RLIN3
*  The R_COM_printf function written in R_COM.c uses RLIN3, but operates independently
*  of the RLIN3 driver.
*  Therefore, the RLIN3 base address used by the R_COM_printf function is specified
*  below. 
*******************************************************************************/
#if 1
/* [DJ] use RLIN33  (TX: P09_0,  RX: P09_1)  - U5L4 QFP100 pin 69 / 70
        TX: P09_0 ALT_OUT2 (RLIN33TX), RX: P09_1 ALT_IN2 (RLIN33RX)
        (checked with E02_Pin.xlsx and R_device_RLIN3.c, 2026.10.03)
        On the target board P09_0/P09_1 are also connected to the J-Link VCOM
        level shifter (U11). When an external USB-UART is used, set SW8 (VCOM)
        to OFF to avoid signal contention.                                    */
#define	CFG_COM_UNIT	(3)
/* [DJ] pin index for RLIN33 (R_device_RLIN3.c): 0: P01  1: P09  2: P10  3: P11
        CFG_COM_PIN = 1 ->
          R_RLIN3_OpenRLIN3nTX( 3, 1 ): R_PORT_SetAlt_Pnm( 9, 0, 2, OUT ) = P09_0 ALT_OUT2 RLIN33TX
          R_RLIN3_OpenRLIN3nRX( 3, 1 ): R_PORT_SetAlt_Pnm( 9, 1, 2, IN  ) = P09_1 ALT_IN2  RLIN33RX
          (RX with pin = 1 needs the RLIN33 "bit 3-2 = 00" case added in R_device_RLIN3.c)
        To use RLIN33RX/IRQ11 (ALT_IN5), call OpenRLIN3nRX with ((2 << 2) | 1).        */
#define	CFG_COM_PIN		(1)
#define	CFG_COM_base_addr 	(RLIN33_inst_0_BASE)	/* RLIN33  */
#define	CFG_COM_baudrate 	R_COM_e_baudrate_115200bps	/* RLIN33 */
#define	CFG_COM_clk_freq 	R_COM_e_clk_4MHz
#define	CFG_COM_CLK_RLIN3 	CLK_e_RLIN_CLK_MOSC_4MHz
#else
/* use RLIN30  (TX: P10_10,  RX: P10_9) */
#define	CFG_COM_UNIT	(0)
#define	CFG_COM_PIN		(1)
#define	CFG_COM_base_addr 	(0x5C3B4000U)	/* RLIN30 */
#define	CFG_COM_baudrate 	R_COM_e_baudrate_115200bps	/* RLIN30 */
#define	CFG_COM_clk_freq 	R_COM_e_clk_4MHz
#define	CFG_COM_CLK_RLIN3 	CLK_e_RLIN_CLK_MOSC_4MHz
#endif

/* The relationship between the RLIN3 unit/ports and COM_UNIT/COM_PIN
   used for COM communication on R-Car/U5L is as follows:

   CFG_COM_UNIT	CFG_COM_PIN
   0           	0          : P00_2 RLIN30TX  / P00_3 RLIN30RX/IRQ8/CXP10RX
   0           	1          : P10_10 RLIN30TX / P10_9 RLIN30RX/IRQ8/CXP10RX
   1           	0          : P00_5 RLIN31TX  / P00_4  RLIN31RX/IRQ9/CXP11RX
   1           	1          : P10_12 RLIN31TX / P10_11 RLIN31RX/IRQ9/CXP11RX
   2           	0          : P00_14 RLIN32TX
   2           	1          : P10_14 RLIN32TX
   2           	2          : P11_3 RLIN32TX
   3           	0          : P01_1 RLIN33TX  / P01_0 RLIN33RX/CXP13RX            [DJ] added
   3           	1          : P09_0 RLIN33TX  / P09_1 RLIN33RX (ALT_OUT2/ALT_IN2) [DJ] added (used)
   3           	2          : P10_2 RLIN33TX  / P10_1 RLIN33RX/CXP13RX            [DJ] added
   3           	3          : P11_5 RLIN33TX  / P11_6 RLIN33RX/CXP13RX            [DJ] added
*/


/*******************************************************************************
* Definition for executing some functions in RAM (in debugging)
*  If USE_CRUN is defined, it enables allocation to the RAM_EXE section.
*  This allows some code to be executed in Retention RAM when in Cyclic RUN 
*  mode. 
*******************************************************************************/
/* reset vector for Cyclic RUN (to set OPBT) */
#define	CFG_CRUN_VECT   	0x00400000


/*******************************************************************************
* Test specific Option
* *******************************************************************************/
/*
	   P09_0 : RLIN33TX: log output  ([DJ] was P10_10: RLIN30TX)
	   P09_1 : RLIN33RX: echo test input ([DJ] added)
	A0 P01_0 : Rise: Start RUN
	A1 P01_1 : Rise: Set DeepSTOP trigger
	A2 P01_2 : Rise: Start Cyclic RUN
	A3 P00_1 : APO
	A4 P00_2 : DPO
	A5 P00_4 : SELDP0
	A6 P00_5 : SELDP1
	A7 P00_6 : SELDP2
	B0 P00_0 : LPSTMOUT3
	B1
	B2 P02_4 : ADCK0SEL0
	B3 P02_5 : ADCK0SEL1
	B4 P02_6 : ADCK0SEL2
	B5 P10_9 : ADCK0END0
	B6 P08_4 : EXTCLK0O
	   P08_1  DPIN0
	   P00_3  DPIN1
	   P08_0  DPIN2
	   P08_3  DPIN3
	   P08_4  DPIN4
	   P00_7  DPIN5
	   P00_8  DPIN6
	   P00_9  DPIN7
*/
#define	TEST_NO             1

/* target module
*******************************************************************************/
/* unit number */
#define	TEST_LPSB_UNIT   	0	/* unit number of LPSB */
#define	TEST_LPSB_TM_CH 	3	/* channel number of interval timer */
#define	TEST_ADCK_UNIT   	0	/* unit number of ADCK */
#define	TEST_ADCK_SG    	0	/* channel number of interval timer */

/* pullup/pulldown pattern and DPIN expectation value */
#define	TEST_DPIN_PATTERN	0xFF

/* wakeup factor */
#define	TEST_WUF	STB_e_WUF_WUTRG1

/* if defined, output log to COM port */
#if 0
#define	TEST_DEBUG_OUT
#endif


/*******************************************************************************
* This sample program was confirmed with the R-Car/U5L4 work sample.
* This version of the U5L4 product inserts a wait process when reading a register
* due to a bus read issue.
* For products that do not have the bus read issue, it can avoid inserting a wait
* process when reading a register by commenting out “#define U5L4_CPUREAD_WA”.
*******************************************************************************/
// #define	U5L4_CPUREAD_WA


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __config_H__ */


/* Definition for nop in Arm core
*******************************************************************************/
#define	__nop()	__asm("nop")
