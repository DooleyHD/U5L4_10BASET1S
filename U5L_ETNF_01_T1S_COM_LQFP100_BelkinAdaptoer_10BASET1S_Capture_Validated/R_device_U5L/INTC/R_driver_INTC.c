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
* File Name    : R_drv_INTC.h
* Version      : 1.00
* Device(s)    : INTC
* Description  : This is header file for INTC driver.
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_INTC.h"

/*******************************************************************************
* Section specification for entire file
*******************************************************************************/
#pragma	section	default


/*******************************************************************************
* Global variables
*******************************************************************************/
/* all status of maskable interrupt
 * After get all interrupt status using the R_INTC_GetInterruptFlag_all,
 * the result is stored this variable.
 * If bit m in INTC_all_status[n] is set 1, the No. 32*n + m of interrupt cause
 * index (INTC_e_index) is pending. */
uint32_t INTC_All_Flag[INTC_e_index_end >> 5];


/*******************************************************************************
* Function body
*******************************************************************************/

/*******************************************************************************
* Description  : Set interrupt priority
*                This function sets the priority of an interrupt channel for
*                a specified interrupt source.
* Arguments    : INTC_e_index index: Index of interrupt information
*                uint32_t priority
* Return Value : RET_OK    : Changing interrupt priority was success.
*                RET_NG_REG: Changing interrupt priority was failed.
*******************************************************************************/
uint8_t R_INTC_SetPriority( INTC_e_index index, uint32_t priority ){

	IRQn_Type	irq = INTC_Info[index].IRQn;
	uint8_t 	ret;


	/* Set priority */
	NVIC_SetPriority( irq, priority );

	if( NVIC_GetPriority( irq ) == priority ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}

	return( ret );
}


/*******************************************************************************
* Description  : Enable interrupt of the specified channel
*                This function disables the specified interrupt channel.
* Arguments    : INTC_e_index index: Index of interrupt information
* Return Value : RET_OK    : Enabling interrupt was success.
*                RET_NG_REG: Enabling interrupt was failed.
*******************************************************************************/
uint8_t R_INTC_EnableInterrupt( INTC_e_index index ){

	IRQn_Type	irq = INTC_Info[index].IRQn;
	uint8_t 	ret;


	/* Enable interrupt */
	NVIC_EnableIRQ( irq );

	/* read NVIC_ISERn register
	 * After enabling/disabling IRQ, the NVIC_ISERn register must be read. */
	if( NVIC_GetEnableIRQ( irq ) == 1 ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}

	return( ret );
}


/*******************************************************************************
* Description  : Disable interrupt of the specified channel
*                This function disables the specified interrupt channel.
*                If it want to disable only some of the interrupts that have
*                multiple interrupt sources assigned to them, use the function
*                R_INTC_SetInterruptMask.
* Arguments    : INTC_e_index index: Index of interrupt information
* Return Value : RET_OK    : Enabling interrupt was success.
*                RET_NG_REG: Enabling interrupt was failed.
*******************************************************************************/
uint8_t R_INTC_DisableInterrupt( INTC_e_index index ){

	IRQn_Type	irq = INTC_Info[index].IRQn;
	uint8_t 	ret;


	/* Disable interrupt */
	NVIC_DisableIRQ( irq );

	/* read NVIC_ISERn register
	 * After enabling/disabling IRQ, the NVIC_ISERn register must be read. */
	if( NVIC_GetEnableIRQ( irq ) == 0 ){
		ret = RET_OK;
	}else{
		ret = RET_ERR_REG;
	}

	return( ret );
}


/*******************************************************************************
* Description  : Set the interrupt mask
*                For an interrupt that has multiple interrupt sources assigned
*                to one channel, set the corresponding bit of the IMFULMSK
*                register or IMFUPMSK register.
*                To mask interrupts for an interrupt source assigned to a channel,
*                disable that interrupt channel using R_INTC_DisableInterrupt.
* Arguments    : INTC_e_index index: Index of interrupt information
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_INTC_SetInterruptMask( INTC_e_index index ){

	uint8_t  	group;	/* group of IMFU register */
	uint8_t  	bit;  	/* bit position of IMFU register */
	uint32_t	ret = RET_OK;


	/* Get IMFU register number and bit position */
	group = INTC_Info[index].group;
	bit = INTC_Info[index].bit;

	/* Set interrupt mask */
	if( INTC_Info[index].ctrl== INTC_e_ctrl_IMFUL ){
		ret = Reg32SetBitCheck( &rIMFULMSKi(group).UINT32, bit );
	}else if( INTC_Info[index].ctrl== INTC_e_ctrl_IMFUP ){
		ret = Reg32SetBitCheck( &rIMFUPMSKj(group).UINT32, bit );
	}else{}


	return( ret );
}


/*******************************************************************************
* Description  : Clear the interrupt mask
*                For an interrupt that has multiple interrupt sources assigned
*                to one channel, clear the corresponding bit of the IMFULMSK
*                register or IMFUPMSK register.
*                To mask interrupts for an interrupt source assigned to a channel,
*                disable that interrupt channel using R_INTC_DisableInterrupt.
* Arguments    : INTC_e_index index: Index of interrupt information
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_INTC_ClearInterruptMask( INTC_e_index index ){

	uint8_t  	group;	/* group of IMFU register */
	uint8_t  	bit;  	/* bit position of IMFU register */
	uint32_t	ret = RET_OK;


	/* Get IMFU register number and bit position */
	group = INTC_Info[index].group;
	bit = INTC_Info[index].bit;

	/* Set interrupt mask */
	if( INTC_Info[index].ctrl== INTC_e_ctrl_IMFUL ){
		ret = Reg32ClearBitCheck( &rIMFULMSKi(group).UINT32, bit );
	}else if( INTC_Info[index].ctrl== INTC_e_ctrl_IMFUP ){
		ret = Reg32ClearBitCheck( &rIMFUPMSKj(group).UINT32, bit );
	}else{}


	return( ret );
}

/*******************************************************************************
* Description  : configuration of interrupt
*                This function enables or disables the specified interrupt channel
*                and sets the specified priority.
*                When enabling an interrupt that has multiple interrupt sources
*                assigned to it, this function un-masks the interrupt source using
*                IMFULMSKi or IMFUPMSKi and also enables the interrupt channel to
*                which the interrupt source belongs.
*                When disabling an interrupt that has multiple interrupt sources
*                assigned to it, this function sets the mask of the interrupt source
*                using IMFULMSKi or IMFUPMSKi, but does not change the enable/disable
*                state of the interrupt channel to which the interrupt source belongs.
*                If an interrupt is specified that has only one assigned interrupt
*                source, this function enables or disables the interrupt channel itself.
* Arguments    : INTC_e_index index: Index of interrupt information
*                uint32_t priority
* Return Value : None
*******************************************************************************/
uint8_t R_INTC_ConfigInterrupt( INTC_e_index index, GE_e_endis endis, uint32_t priority ){

	volatile uint32_t	dummy;
	IRQn_Type        	irq = INTC_Info[index].IRQn;
	uint32_t	ret = RET_OK;


	/* Set priority */
	NVIC_SetPriority( irq, priority );

	/* Enable/Disable interrupt */
	if( endis == enable ){
		/* Enable interrupt channel */
		NVIC_EnableIRQ( irq );

		/* Release interrupt mask for each interrupt source */
		ret = R_INTC_ClearInterruptMask( index );

	}else{ /* endis = disable */
		if( INTC_Info[index].ctrl== INTC_e_ctrl_none ){
			/* Disable interrupt channel */
			NVIC_DisableIRQ( irq );

		}else{
			/* Set interrupt mask for each interrupt source */
			ret = R_INTC_SetInterruptMask( index );

		}

	}

	return( ret );
}


/*******************************************************************************
* Description  : Get the interrupt flag
*                This function returns the status of the specified interrupt
*                generation.
* Arguments    : INTC_e_index index: Index of interrupt information
* Return Value : 0: The interrupt has not generated
*                1: The interrupt has generated
*******************************************************************************/
uint8_t R_INTC_GetInterruptFlag( INTC_e_index index ){

	IRQn_Type	irq = INTC_Info[index].IRQn;
	uint8_t  	group;	/* group of IMFU register */
	uint8_t  	bit;  	/* bit position of IMFU register */
	uint32_t	flag;	/* interrupt pending flag */


	/* Get pending flag */
	flag = NVIC_GetPendingIRQ( irq );

	/* If multiple interrupt sources are muxed to one interrupt channel,
	 * the flag for each interrupt source is stored in the variable flag. */
	if( (flag == 1) && (INTC_Info[index].ctrl!= INTC_e_ctrl_none) ){
		/* Get IMFU register number and bit position */
		group = INTC_Info[index].group;
		bit = INTC_Info[index].bit;

		/* check interrupt flag */
		if( INTC_Info[index].ctrl== INTC_e_ctrl_IMFUL ){
			/* Change interrupt pending flag to each source */
			flag = ( ((Reg32Read(rIMFULFi(group).UINT32)) >> bit) & 1);
		}else if( INTC_Info[index].ctrl== INTC_e_ctrl_IMFUP ){
			/* Change interrupt pending flag to each source */
			flag = ( ((Reg32Read(rIMFUPFj(group).UINT32)) >> bit) & 1);
		}else{}

	}


	return( flag );
}


/*******************************************************************************
* Description  : Get all the interrupt flag
*                This function returns the status of the specified interrupt
*                generation.
* Arguments    : INTC_e_index index: Index of interrupt information
* Return Value : None
*******************************************************************************/
void R_INTC_GetInterruptFlag_All( void ){

	INTC_e_index 	index;

	for( index = 0; index < INTC_e_index_end; index++ ){
		INTC_All_Flag[index >> 5] = (R_INTC_GetInterruptFlag(index) << (index & 0x1F));
	}

}


/*******************************************************************************
* Description  : clear interrupt flag
*                This function clears the interrupt flag of channel.
*                If the specified interrupt is pulse interrupt, it clears
*                the corresponding bit of IMFUPj register.
*                If the interrupt whose type of interrupt is level interrupt,
*                it needs to stop the interrupt source before call this function.
* Arguments    : INTC_e_index index: Index of interrupt information
* Return Value : None
*******************************************************************************/
void R_INTC_ClearInterruptFlag( INTC_e_index index ){

	IRQn_Type	irq = INTC_Info[index].IRQn;
	uint8_t  	group;	/* group of IMFU register */
	uint8_t  	bit;  	/* bit position of IMFU register */


	/* Get IMFU register number and bit position */
	group = INTC_Info[index].group;
	bit = INTC_Info[index].bit;

	/* Clear interrupt flag of each source of level */
	if( INTC_Info[index].ctrl== INTC_e_ctrl_IMFUP ){
		rIMFUPCj(group).UINT32 = (1 << bit );
	}else{}

	/* Clear interrupt flag of interrupt channel */
	NVIC_ClearPendingIRQ( irq );

}


/*******************************************************************************
* Return to default section
*******************************************************************************/
#pragma	section	default
