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
* File Name    : Test_main.c
* Version      : 1.00
* Device(s)    : R-Car/U5L
* Description  : This is source file for test main function.
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
/* general */
#include "config.h"
#include "R_driver_port.h"
#include "R_driver_INTC.h"

/* Test */

/*******************************************************************************
* Global variable
*******************************************************************************/
uint8_t	Test_INTEINTSW2_Generated = 0;



/*******************************************************************************
* Description  : Exception handler of NMI
* Arguments    : None
* Return Value : None
*******************************************************************************/
static void Inform_Exception( uint8_t n, uint8_t m ){

	uint32_t	count = CFG_EP_TOGGLE_PERIOD;


	/* open port */
	R_PORT_SetOuputMode_Pnm( n, m );

	/* toggle port */
	while( 1 ){
		R_PORT_ToggleOutputLevel_Pnm( n, m );
		wait( count );
	}

}


/*******************************************************************************
* Description  : Exception handler of NMI
* Arguments    : None
* Return Value : None
*******************************************************************************/
__attribute__((weak))
void NMI_Handler(){

	uint8_t 	n = CFG_EP_GROUP;
	uint8_t 	m = CFG_EP_NMI;


	/* toggle port */
	Inform_Exception( n, m );

}


/*******************************************************************************
* Description  : Exception handler of HardFault
* Arguments    : None
* Return Value : None
*******************************************************************************/
__attribute__((weak))
void HardFault_Handler(){

	uint8_t 	n = CFG_EP_GROUP;
	uint8_t 	m = CFG_EP_HardFault;


	/* toggle port */
	Inform_Exception( n, m );

}


/*******************************************************************************
* Description  : Exception handler of MemManage
* Arguments    : None
* Return Value : None
*******************************************************************************/
__attribute__((weak))
void MemManage_Handler(){

	uint8_t 	n = CFG_EP_GROUP;
	uint8_t 	m = CFG_EP_MemManage;


	/* toggle port */
	Inform_Exception( n, m );

}


/*******************************************************************************
* Description  : Exception handler of BusFault
* Arguments    : None
* Return Value : None
*******************************************************************************/
__attribute__((weak))
void BusFault_Handler(){

	uint8_t 	n = CFG_EP_GROUP;
	uint8_t 	m = CFG_EP_BusFault;


	/* toggle port */
	Inform_Exception( n, m );

}


/*******************************************************************************
* Description  : Exception handler of UsageFault
* Arguments    : None
* Return Value : None
*******************************************************************************/
__attribute__((weak))
void UsageFault_Handler(){

	uint8_t 	n = CFG_EP_GROUP;
	uint8_t 	m = CFG_EP_UsageFault;


	/* toggle port */
	Inform_Exception( n, m );

}


/*******************************************************************************
* Description  : Exception handler of SVC
* Arguments    : None
* Return Value : None
*******************************************************************************/
__attribute__((weak))
void SVC_Handler(){

	uint8_t 	n = CFG_EP_GROUP;
	uint8_t 	m = CFG_EP_SVC;


	/* toggle port */
	Inform_Exception( n, m );

}


/*******************************************************************************
* Description  : Exception handler of DebugMon
* Arguments    : None
* Return Value : None
*******************************************************************************/
__attribute__((weak))
void DebugMon_Handler(){

	uint8_t 	n = CFG_EP_GROUP;
	uint8_t 	m = CFG_EP_DebugMon;


	/* toggle port */
	Inform_Exception( n, m );

}


/*******************************************************************************
* Description  : Exception handler of PendSV
* Arguments    : None
* Return Value : None
*******************************************************************************/
__attribute__((weak))
void PendSV_Handler(){

	uint8_t 	n = CFG_EP_GROUP;
	uint8_t 	m = CFG_EP_PendSV;


	/* toggle port */
	Inform_Exception( n, m );

}


/*******************************************************************************
* Description  : Exception handler of SysTick
* Arguments    : None
* Return Value : None
*******************************************************************************/
__attribute__((weak))
void SysTick_Handler(){

	uint8_t 	n = CFG_EP_GROUP;
	uint8_t 	m = CFG_EP_SysTick;


	/* toggle port */
	Inform_Exception( n, m );

}


/*******************************************************************************
* Description  : Interrupt handler of INTEINTSW0
* Arguments    : None
* Return Value : None
*******************************************************************************/
void IntFunc_INTEINTSW0( void ){

#ifndef CFG_INT_MULTI
	/* DI */
	R_INTC_DI();
#endif

//	Test_INTEINTSWk( 0 );

#ifndef CFG_INT_MULTI
	/* EI */
	R_INTC_EI();
#endif

}


/*******************************************************************************
* Description  : Interrupt handler of INTEINTSW1
* Arguments    : None
* Return Value : None
*******************************************************************************/
void IntFunc_INTEINTSW1( void ){

#ifndef CFG_INT_MULTI
	/* DI */
	R_INTC_DI();
#endif

	//	Test_INTEINTSWk( 1 );

#ifndef CFG_INT_MULTI
	/* EI */
	R_INTC_EI();
#endif

}


/*******************************************************************************
* Description  : Interrupt handler of INTEINTSW2
* Arguments    : None
* Return Value : None
*******************************************************************************/
void IntFunc_INTEINTSW2( void ){

#ifndef CFG_INT_MULTI
	/* DI */
	R_INTC_DI();
#endif

	//	Test_INTEINTSWk( 2 );

#ifndef CFG_INT_MULTI
	/* EI */
	R_INTC_EI();
#endif

}


/*******************************************************************************
* Description  : Interrupt handler of INTEINTSW3
* Arguments    : None
* Return Value : None
*******************************************************************************/
void IntFunc_INTEINTSW3( void ){

#ifndef CFG_INT_MULTI
	/* DI */
	R_INTC_DI();
#endif

	//	Test_INTEINTSWk( 3 );

#ifndef CFG_INT_MULTI
	/* EI */
	R_INTC_EI();
#endif

}
