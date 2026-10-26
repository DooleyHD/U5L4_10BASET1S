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
* Description  : This is source file for INTC driver.
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_INTC_H__
#define	__R_driver_INTC_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include <R_driver_INTC_info.h>	/* for reference of register structure */
#include "R_driver_INTC_reg.h"	/* for reference of register structure */
#include "R_driver_general.h"
#include "core_cm33.h"	/* for using NVIC functions */


/*******************************************************************************
* Definitions
*******************************************************************************/
#define	INTC_ch_MAX	196	/* max number of interrupt channel */
#define INTC_p_NUM	4	/* total number of software interrupt */


/*******************************************************************************
* Extern of global variables
*******************************************************************************/
/* all status of maskable interrupt */
extern uint32_t INTC_All_Flag[];


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
* Description  : Increment the counter of software interrupt
*                This function increments the software interrupt counter by one.
*                The counter of software interrupt is not 0, the software
*                interrupt generates as the level interrupt.
*
* Arguments    : uint8_t p    : index of SINTR register (p = 0 to 3)
* Return Value : None
*******************************************************************************/
#define	R_INTC_IncrementSoftwareInterrupt(p)	rSINTRp(p).UINT8 = 0x01
#define	R_INTC_AssertSoftwareInterrupt(p)   	R_INTC_IncrementSoftwareInterrupt(p)

/*******************************************************************************
* Description  : Decrement the counter of software interrupt
*                This function decrements the software interrupt counter by one.
*                The counter of software interrupt reaches 0, the software
*                interrupt is negated.
* Arguments    : uint8_t p    : index of SINTR register (p = 0 to 3)
* Return Value : None
*******************************************************************************/
#define	R_INTC_DecrementSoftwareInterrupt(p)	rSINTRp(p).UINT8 = 0x00

/*******************************************************************************
* Description  : De-assert a software interrupt
*                This function decrements the software interrupt counter until
*                the software interrupt is de-asserted.
* Arguments    : uint8_t p    : index of SINTR register (p = 0 to 3)
* Return Value : None
*******************************************************************************/
#define	R_INTC_DeassertSoftwareInterrupt(p) 	while( Reg08Read(rSINTRp(p).UINT8) ){rSINTRp(p).UINT8 = 0x00;}

/*******************************************************************************
* Description  : Get the counter value of the software interrupt
*                This function gets the counter value of software interrupt by
*                reading SINTR register.
* Arguments    : uint8_t p    : index of SINTR register (p = 0 to 3)
* Return Value : value of SINTRp register
*******************************************************************************/
#define	R_INTC_GetSoftwareInterruptCount(p)	Reg32Read( rSINTRp(p).UINT8 )

/*******************************************************************************
* Description  : Disable all interrupt
*                This intrinsic disables IRQ interrupts by setting the I-bit
*                in the CPSR.
* Arguments    : None
* Return Value : Returns the value the IRQ interrupt mask has in the PSR prior
*                to the disabling of IRQ interrupts.
*******************************************************************************/
#define	R_INTC_DI()	__disable_irq()

/*******************************************************************************
* Description  : Enable all interrupt
* Arguments    : None
* Return Value : None
*******************************************************************************/
#define	R_INTC_EI()	__enable_irq()

/*******************************************************************************
* Description  : Set interrupt priority
*                This function sets the priority of the specified interrupt
*                channel.
* Arguments    : INTC_e_index index: Index of interrupt information
*                uint32_t priority
* Return Value : RET_OK    : Enabling interrupt was success.
*                RET_NG_REG: Enabling interrupt was failed.
*******************************************************************************/
uint8_t R_INTC_SetPriority( INTC_e_index index, uint32_t priority );

/*******************************************************************************
* Description  : Set interrupt priority
*                This function sets the priority of the specified interrupt
*                channel.
* Arguments    : INTC_e_index index: Index of interrupt information
*                uint32_t priority
* Return Value : RET_OK    : Enabling interrupt was success.
*                RET_NG_REG: Enabling interrupt was failed.
*******************************************************************************/
#define	R_INTC_GetPriority(index)	NVIC_GetPriority(INTC_Info[index].IRQn)

/*******************************************************************************
* Description  : Enable interrupt of the specified channel
*                This function disables the specified interrupt channel.
* Arguments    : INTC_e_index index: Index of interrupt information
*                uint32_t priority
* Return Value : None
*******************************************************************************/
uint8_t R_INTC_EnableInterrupt( INTC_e_index index );

/*******************************************************************************
* Description  : Disable interrupt of the specified channel
*                This function disables the specified interrupt channel.
*                If it want to disable only some of the interrupts that have
*                multiple interrupt sources assigned to them, use the function
*                R_INTC_SetInterruptMask.
* Arguments    : INTC_e_index index: Index of interrupt information
*                uint32_t priority
* Return Value : None
*******************************************************************************/
uint8_t R_INTC_DisableInterrupt( INTC_e_index index );

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
uint8_t R_INTC_SetInterruptMask( INTC_e_index index );

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
uint8_t R_INTC_ClearInterruptMask( INTC_e_index index );

/*******************************************************************************
* Description  : Configuration of interrupt
*                This function enables or disables the specified interrupt channel
*                and sets the specified priority.
* Arguments    : INTC_e_index index: Index of interrupt information
*                uint32_t priority
* Return Value : None
*******************************************************************************/
uint8_t R_INTC_ConfigInterrupt( INTC_e_index index, GE_e_endis endis, uint32_t priority );

/*******************************************************************************
* Description  : Get the interrupt flag
*                This function returns the status of the specified interrupt
*                generation.
* Arguments    : INTC_e_index index: Index of interrupt information
* Return Value : 0: The interrupt has not generated
*                1: The interrupt has generated
*******************************************************************************/
uint8_t R_INTC_GetInterruptFlag( INTC_e_index index );

/*******************************************************************************
* Description  : Wait for the interrupt generate
*                This function waits the specified interrupt generates.
* Arguments    : INTC_s_IRQ int_info: Interrupt information
* Return Value : None
*******************************************************************************/
#define R_INTC_WaitInterrupt(index)	while( R_INTC_GetInterruptFlag(index) == 0 );

/*******************************************************************************
* Description  : Clear interrupt flag
*                This function clears the pending state of the specified interrupt.
* Arguments    : INTC_e_index index: Index of interrupt information
* Return Value : None
*******************************************************************************/
void R_INTC_ClearInterruptFlag( INTC_e_index index );

/*******************************************************************************
* Description  : Clear NMI flag
* Arguments    : None
* Return Value : None
*******************************************************************************/
#define R_INTC_ClearNMIFlag()	rNMIC.BIT.NMIC = 1


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_INTC_H__ */
