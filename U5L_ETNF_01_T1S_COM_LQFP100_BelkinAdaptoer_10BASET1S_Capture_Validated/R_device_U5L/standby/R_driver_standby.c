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
* File Name    : R_driver_standby.c
* Version      : 1.00
* Device(s)    : Standby controller
* Device(s)    : R-Car U5L product
* Description  : Standby controller driver for R-Car U5L
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_standby.h"


/*******************************************************************************
* Section specification for entire file
*******************************************************************************/
#pragma	section	default


/*******************************************************************************
* Definitions
*******************************************************************************/
/* local definition for the function R_STB_EnterDeepStopMode */
#define	rSCR_main	(*(volatile uint32_t *)(0xE000ED10))	/* SCR, System Control Register */

/* local definition for the function R_STB_TransitCyclicRun */
#define	rFCLACTL0_IRQ_0	(*(volatile uint8_t *)(0x5C2D4A00))	/* Filter control register for IRQ0*/


/*******************************************************************************
* Global variables
*******************************************************************************/



/*******************************************************************************
* Function body
*******************************************************************************/

/*******************************************************************************
* Description  : Release module standby
* Arguments    : volatile uint32_t *msr_reg: MSR register
* Return Value : (none)
*******************************************************************************/
void R_STB_ReleaseModuleStandby( volatile uint32_t *msr_reg ){
	
	/* Release write protection */
	R_STB_ReleaseWriteProtect_MSR();
	
	/* release module standby */
	*msr_reg &= (uint32_t)~(1 << 31);
	
	/* ait until module standby released */
	while( (*msr_reg & (uint32_t)(1 << 31)) != 0 )
		;
		
	/* Set write protection */
	R_STB_SetWriteProtect_MSR();
}


/*******************************************************************************
* Description  : Set module standby
* Arguments    : volatile uint32_t *msr_reg: MSR register
* Return Value : (none)
*******************************************************************************/
void R_STB_SetModuleStandby( volatile uint32_t *msr_reg ){
	
	/* Release write protection */
	R_STB_ReleaseWriteProtect_MSR();
	
	/* release module standby */
	*msr_reg |= (uint32_t)(1 << 31);
	
	/* ait until module standby released */
	while( (*msr_reg & (uint32_t)(1 << 31)) == 0 )
		;
		
	/* Set write protection */
	R_STB_SetWriteProtect_MSR();
}


/*******************************************************************************
* Description  : Transitions to 1chip DeepSTOP Mode
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void R_STB_EnterDeepStopMode( void ){

	/* select deep sleep as its low-power mode (SCR.SLEEPDEEP = 1) */
	rSCR_main |= (1 << 2);

	/* release write protect */
	R_STB_ReleaseWriteProtect();
	
	/* Enter DeepSTOP mode */
	rSTBC0PSC.BIT.STBC0DISTRG = 1;
	
	/* set write protect */
	R_STB_SetWriteProtect();

#ifdef U5L
	/* wait for interrupt 
	   causes immediate entry to sleep mode unless the wakeup condition is true. 
	   When the processor executes a WFI instruction, it stops executing 
	   instructions and enters sleep mode. */
	__asm( "wfi" );
#endif

	/* wait until transition to DeepSTOP mode */
	while( 1 )
		;
}


/*******************************************************************************
* Description  : Transitions to Cyclic RUN mode via DeepSTOP mode using IRQ0
* Arguments    : (none)
* Return Value : (none)
* Remarkabke   : need to execute function STB_TransitCyclicRun_clear to reset 
*                IRQ0 wakeup factor and set wakeup mask.
*******************************************************************************/
void R_STB_TransitCyclicRun( void ){
	
	/* set WUFEN of IRQ0 for Cyclic RUN */
	R_STB_EnableWakeupFactor( STB_e_WUF_IRQ0, STB_e_WUF_type_CRUN );

	/* clear WUFEN of IRQ0 for RUN */
	R_STB_DisableWakeupFactor( STB_e_WUF_IRQ0, STB_e_WUF_type_RUN );

	/* generate wakeup */
	rFCLACTL0_IRQ_0 = (1 << 2) | (0 << 0);	/* Low level detection */
	rFCLACTL0_IRQ_0 = (1 << 2) | (1 << 0);	/* High level detection */

	/* after enabling Low level detection of High level detection,
	   WUF1 of IRQ0 is set.*/
	
	/* Enter DeepSTOP mode with WUF1 set */
	R_STB_EnterDeepStopMode();
			
	while( 1 )
		;
}


/*******************************************************************************
* Description  : Transitions to RUN mode via DeepSTOP mode using IRQ0
* Arguments    : (none)
* Return Value : (none)
* Remarkabke   : need to execute function STB_TransitCyclicRun_clear to reset 
*                IRQ0 wakeup factor and set wakeup mask.
*******************************************************************************/
void R_STB_TransitRun( void ){
	
	/* set WUFEN of IRQ0 for RUN */
	R_STB_EnableWakeupFactor( STB_e_WUF_IRQ0, STB_e_WUF_type_RUN );

	/* clear WUFEN of IRQ0 for Cyclic RUN */
	R_STB_DisableWakeupFactor( STB_e_WUF_IRQ0, STB_e_WUF_type_CRUN );

	/* generate wakeup */
	rFCLACTL0_IRQ_0 = (1 << 2) | (0 << 0);	/* Low level detection */
	rFCLACTL0_IRQ_0 = (1 << 2) | (1 << 0);	/* High level detection */

	/* after enabling Low level detection of High level detection,
	   WUF0 of IRQ0 is set.*/
	
	/* Enter DeepSTOP mode with WUF1 set */
	R_STB_EnterDeepStopMode();
			
	while( 1 )
		;
}


/*******************************************************************************
* Description  : Initialize the resource used the function R_STB_TransitCyclicRun.
*                need to perform post processing of function
*                 R_STB_TransitCyclicRun function.
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void R_STB_TransitCyclicRun_clear( void ){
	
	/* reset FCLA of IRQ0 */
	rFCLACTL0_IRQ_0 = 0;
	
	/* set wakeup mask of IRQ0 */
	R_STB_DisableWakeupFactor( STB_e_WUF_IRQ0, STB_e_WUF_type_CRUN );
	
	/* clear wakeup flag of IRQ0 */
	R_STB_ClearWakeupFlag( STB_e_WUF_IRQ0 );

}


/*******************************************************************************
* Description  : Initialize the resource used the function R_STB_TransitRun.
*                need to perform post processing of function
*                 R_STB_TransitRun function.
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void R_STB_TransitRun_clear( void ){
	
	/* reset FCLA of IRQ0 */
	rFCLACTL0_IRQ_0 = 0;
	
	/* set wakeup mask of IRQ0 */
	R_STB_DisableWakeupFactor( STB_e_WUF_IRQ0, STB_e_WUF_type_RUN );
	
	/* clear wakeup flag of IRQ0 */
	R_STB_ClearWakeupFlag( STB_e_WUF_IRQ0 );

}


/*******************************************************************************
* Description  : Enable wakeup factor
* Arguments    : STB_e_WUF      wuf : register number and bit position information
*                                     of wakeup factor 
*                STB_e_WUF_type kind: kind of wakeup (wakeup to RUN mode or
*                                     wakeup to Cyclic RUN mode)
* Return Value : 0     : Register readback check was successful
*                others: The failure count of register readback check
* Example      :
*	// Enable wakeup to RUN mode by NMI
*	R_STB_EnableWakeupFactor( STB_e_WUF_NMI, STB_e_WUF_type_RUN );
*	// Enable wakeup to Cyclic RUN mode by WUTRG0
*	R_STB_EnableWakeupFactor( STB_e_WUF_WUTRG0, STB_e_WUF_type_CRUN );
*******************************************************************************/
uint8_t R_STB_EnableWakeupFactor( STB_e_WUF wuf, STB_e_WUF_type kind ){
	
	uint8_t 	bit;
	uint16_t	reg;
	uint8_t 	ret;
	volatile uint32_t 	*wufen;
	
	
	/* abstruct wakeup factor bit */
	bit = R_STB_GetWUFbit( wuf );
	
	/* abstruct wakeup factor register */
	reg = R_STB_GetWUFReg( wuf );
	
	if( kind == STB_e_WUF_type_RUN ){	
		/* enable wakeup to RUN mode */
		switch( reg ){
		    case STB_e_WUF_reg_A0:
				wufen = &rWUF0EN_A0.UINT32;
				break;
				
		    case STB_e_WUF_reg_A1:
				wufen = &rWUF0EN_A1.UINT32;
				break;
				
		    default:
		    	break;
		}
	}else if( kind == STB_e_WUF_type_CRUN ){
		/* enable wakeup to Cyclic RUN mode */
		switch( reg ){
		    case STB_e_WUF_reg_A0:
				wufen = &rWUF1EN_A0.UINT32;
				break;
				
		    case STB_e_WUF_reg_A1:
				wufen = &rWUF1EN_A1.UINT32;
				break;
				
		    default:
		    	break;
		}
	}else{}
	
	/* enable wakeup */
	ret = Reg32SetBitCheck( wufen, bit );
	
	return( ret );
}


/*******************************************************************************
* Description  : Disable wakeup factor
* Arguments    : STB_e_WUF      wuf : register number and bit position information
*                                     of wakeup factor 
*                STB_e_WUF_type kind: kind of wakeup (wakeup to RUN mode or
*                                     wakeup to Cyclic RUN mode)
* Return Value : 0     : Register readback check was successful
*                others: The failure count of register readback check
* Example      :
*	// disable wakeup to RUN mode by NMI
*	R_STB_DisableWakeupFactor( STB_e_WUF_NMI, STB_e_WUF_type_RUN );
*	// disable wakeup to Cyclic RUN mode by WUTRG0
*	R_STB_DisableWakeupFactor( STB_e_WUF_WUTRG0, STB_e_WUF_type_CRUN );
*******************************************************************************/
uint8_t R_STB_DisableWakeupFactor( STB_e_WUF wuf, STB_e_WUF_type kind ){
	
	uint8_t 	bit;
	uint16_t	reg;
	uint8_t 	ret;
	
	
	/* abstruct wakeup factor bit */
	bit = R_STB_GetWUFbit( wuf );
	
	/* abstruct wakeup factor register */
	reg = R_STB_GetWUFReg( wuf );
	
	/* disable wakeup to RUN mode */
	if( kind  == STB_e_WUF_type_RUN ){	/* kind = STB_e_WUF_type_RUN */
		switch( reg ){
		    case STB_e_WUF_reg_A0:
				ret = Reg32ClearBitCheck( &rWUF0EN_A0.UINT32, bit );
				break;
				
		    case STB_e_WUF_reg_A1:
				ret = Reg32ClearBitCheck( &rWUF0EN_A1.UINT32, bit );
				break;
				
		    default:
		    	break;
		}

	/* disable wakeup to Cyclic RUN mode */
	}else if( kind == STB_e_WUF_type_CRUN ){	/* kind = STB_e_WUF_type_RUN_CRUN */
		switch( reg ){
		    case STB_e_WUF_reg_A0:
				ret = Reg32ClearBitCheck( &rWUF1EN_A0.UINT32, bit );
				break;
				
		    case STB_e_WUF_reg_A1:
				ret = Reg32ClearBitCheck( &rWUF1EN_A1.UINT32, bit );
				break;
				
		    default:
		    	break;
		}

	}else{}

	
	return( ret );
}


/*******************************************************************************
* Description  : Disable all wakeup factors
* Arguments    : STB_e_WUF_type kind: kind of wakeup (wakeup to RUN mode or
*                                     wakeup to Cyclic RUN mode)
* Return Value : 0     : Register readback check was successful
*                others: The failure count of register readback check
*******************************************************************************/
uint8_t R_STB_DisableWakeupFactor_All( STB_e_WUF_type kind ){

	uint8_t 	bit;
	uint16_t	reg;
	uint8_t 	ret = RET_OK;


	/* disable wakeup to RUN mode */
	if( kind & STB_e_WUF_type_RUN ){	/* kind = STB_e_WUF_type_RUN */
		ret += Reg32WRC( &rWUF0EN_A0.UINT32, 0, 0xFFFFFFFF );
		ret += Reg32WRC( &rWUF0EN_A1.UINT32, 0, 0xFFFFFFFF );
	}

	/* disable wakeup to Cyclic RUN mode */
	if( kind & STB_e_WUF_type_CRUN ){	/* kind = STB_e_WUF_type_RUN_CRUN */
		ret += Reg32WRC( &rWUF1EN_A0.UINT32, 0, 0xFFFFFFFF );
		ret += Reg32WRC( &rWUF1EN_A1.UINT32, 0, 0xFFFFFFFF );
	}


	return( ret );
}


/*******************************************************************************
* Description  : Clear wakeup flag
* Arguments    : STB_e_WUF wuf : register number and bit position information
*                                of wakeup factor 
* Return Value : none
* Remark       : In U5L product, wakeup flag registers do not separate with
*                for RUN mode and Cyclic RUN mode (WUF0_Ax, WUF1_Ax).
* Example      :
*	// clear wakeup flag of NMI
*	R_STB_ClearWakeupFlag( STB_e_WUF_NMI );
*	// clear wakeup flag of WUTRG0
*	R_STB_ClearWakeupFlag( STB_e_WUF_WUTRG0 );
*******************************************************************************/
void R_STB_ClearWakeupFlag( STB_e_WUF wuf ){
	
	uint8_t 	bit;
	uint16_t	reg;
	
	
	/* abstruct wakeup factor bit */
	bit = R_STB_GetWUFbit( wuf );
	
	/* abstruct wakeup factor register */
	reg = R_STB_GetWUFReg( wuf );
	
	/* clear wakeup flag */
	switch( reg ){
	    case STB_e_WUF_reg_A0:
			rWUFC_A0.UINT32 = (1 << bit);
			break;
			
	    case STB_e_WUF_reg_A1:
	    	rWUFC_A1.UINT32 = (1 << bit);
			break;
			
	    default:
	    	break;
	}
}


/*******************************************************************************
* Description  : Releases I/O hold of all port
* Arguments    : none
* Return Value : 0     : Register readback check was successful
*                others: The failure count of register readback check
*******************************************************************************/
uint8_t R_STB_ReleaseIOHOLD_All( void ){

	uint8_t 	ret=RET_OK;
	

	/* release write protect */
	R_STB_ReleaseWriteProtect();
	
	/* Release all I/O hold */
	ret += Reg32WRC( &rIOHOLD0.UINT32, 0, STB_IOHOLD_ALL );
	ret += Reg32WRC( &rIOHOLD2.UINT32, 0, STB_IOHOLD2_ALL );
	
	/* set write protect */
	R_STB_ReleaseWriteProtect(); 
	
	
	return( ret );
}


/*******************************************************************************
* Return to default section
*******************************************************************************/
#pragma	section	default
