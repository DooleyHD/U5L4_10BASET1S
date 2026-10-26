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
* File Name    : R_driver_clock.h
* Version      : 1.00
* Device(s)    : Clock controller
* Device(s)    : R-Car U5L product
* Description  : Clock controller driver for R-Car U5L
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_clock_H__
#define	__R_driver_clock_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_clock_reg.h"	/* for reference of register structure */
#include "R_driver_general.h"
#include "product.h"
#include "R_driver_port.h"	/* for the function R_CLK_OpenEXTCLKnO */


/*******************************************************************************
* Definition
*******************************************************************************/
/* SOSCST initial value */
#define	CLK_SOSCST_default	0x00080E80

/*******************************************************************************
* Extern of global variables
*******************************************************************************/


/*******************************************************************************
* Type definitions for the function return value
*******************************************************************************/


/*******************************************************************************
* Type definitions for the arguments of the function
*******************************************************************************/
/* GearUp/GearDown */
typedef enum{
	CLK_e_CLK_SYS0 = 0,	/* CLK_SYS0 */
	CLK_e_CLK_SYS1 = 1 	/* CLK_SYS1 */
}CLK_e_CLK_SYS;

/* R_CLK_ChangePLLDiv */
typedef enum{
	CLK_e_CLK_PLL0 = 0,	/* CLK_PLL0O */
	CLK_e_CLK_PLL1 = 1 	/* CLK_PLL1O */
}CLK_e_CLK_PLL;


/*******************************************************************************
* Prototype declarations of functions and
* functional definition (macro)
*******************************************************************************/

/*******************************************************************************
* Description  : Release write protection for clock related registers
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_CLK_ReleaseWriteProtect()	rCLKKCPROT1.UINT32 = 0xA5A5A501

/*******************************************************************************
* Description  : Set write protection for clock related registers
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_CLK_SetWriteProtect()    	rCLKKCPROT1.UINT32 = 0xA5A5A500

/*******************************************************************************
* Description  : Release write protection for HSIOSC trimming related registers
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_CLK_ReleaseWriteProtect_Trim()	rCLKKCPROT4.UINT32 = 0xA5A5A501

/*******************************************************************************
* Description  : Set write protection for HSIOSC trimming related registers
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_CLK_SetWriteProtect_Trim()    	rCLKKCPROT4.UINT32 = 0xA5A5A500

/*******************************************************************************
* Description  : Enables Main OSC
* Arguments    : (none)
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_NONEED   : not execute this function due to Main OSC has 
*                               already enabled
*******************************************************************************/
uint8_t R_CLK_EnableMOSC( void );

/*******************************************************************************
* Description  : Disables Main OSC
* Arguments    : (none)
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_NONEED   : not execute this function due to Main OSC has 
*                               already disabled
*******************************************************************************/
uint8_t R_CLK_DisableMOSC( void );

/*******************************************************************************
* Description  : Enables Sub OSC
* Arguments    : uint32_t stab_time: stabilization time ( 0008  to 0x0007FFFF)
*                                    (default 0x00080E80)
*                The stabilization time is stab_time / fRL.
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_NONEED   : not execute this function due to Sub OSC has 
*                               already enabled
*******************************************************************************/
uint8_t R_CLK_EnableSOSC( uint32_t stab_time );

/*******************************************************************************
* Description  : Disables Sub OSC
* Arguments    : (none)
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_NONEED   : not execute this function due to Sub OSC has 
*                               already disabled
*******************************************************************************/
uint8_t R_CLK_DisableSOSC( void );

/*******************************************************************************
* Description  : Enables PLL0/1
* Arguments    : (none)
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_NONEED   : not execute this function due to PLL has 
*                               already enabled
*                RET_ERR_STATE: not execute this function because PLL does 
*	                            not stoppped
*                               (PLLEN=1 and PLLSTAB=0: abnormal state)
*******************************************************************************/
uint8_t R_CLK_EnablePLL( void );

/*******************************************************************************
* Description  : Disables PLL0/1
* Arguments    : (none)
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_NONEED   : not execute this function due to PLL has 
*                               already disabled
*                RET_ERR_STATE: not execute this function because PLL does 
*	                            not stoppped
*                               (PLLEN=1 and PLLSTAB=0: abnormal state)
*******************************************************************************/
uint8_t R_CLK_DisablePLL( void );

/*******************************************************************************
* Description  : Configures SSCG
* Arguments    : CLK_s_SSCGC sscgc
* Return Value : 0: Readback check of register was successful
*                1: Readback check of register was failed
* Example      :
	CLK_s_SSCGC	sscgc;
	
	sscgc.BIT_FPDF8.SELMPERCENT = CLK_e_SELMPERCENT_down_5_per;	// -5.0%
	sscgc.BIT_FPDF8.SELMFREQ    = CLK_e_SELMFREQ_FPDF8_40_0MHz;	// 40.0MHz when Fpdf = 8
	sscgc.BIT_FPDF8.SSMODE1     = CLK_e_SSMODE1_enable;        	// Modulation enabled
	
	R_CLK_ConfigSSCG( &sscgc );
*******************************************************************************/
uint8_t R_CLK_ConfigSSCG( CLK_s_SSCGC *sscgc );

/*******************************************************************************
* Description  : Changes divide rate of CLK_PLL0O or CLK_PLL1O
* Arguments    : 
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_ERR_PARAM: argument is out of range
*                RET_ERR_STATE: PLL does not started.
*******************************************************************************/
uint8_t R_CLK_ChangeDiv_PLL( CLK_e_CLK_PLL pll, CLK_e_PLLCLKDCSID div );

/*******************************************************************************
* Description  : Changes CLK_SYS0/1 from CLK_IOSC0/1 to CLK_PLL0/1O.
* Arguments    : CLK_e_CLK_SYS clk_sys
* 	             CLK_e_CLK_SYS0: change CLK_SYS0 to CLK_PLL0O
* 	             CLK_e_CLK_SYS1: change CLK_SYS1 to CLK_PLL1O
* Return Value : RET_OK       : no error
*                RET_ERR_PARAM: argument is out of range
*                RET_NONEED   : CLK_SYS0/SYS1 has already selected CLK_PLL0O/CLK_PLL1O
*                RET_ERR_STATE: PLL is neither stable state nor stop state
*******************************************************************************/
uint8_t R_CLK_GearUpCLK_SYS( CLK_e_CLK_SYS clk_sys );

/*******************************************************************************
* Description  : Changes CLK_SYS0/1 from CLK_PLL0/1O to CLK_IOSC0/1.
* Arguments    : CLK_e_CLK_SYS clk_sys
* 	             CLK_e_CLK_SYS0: change CLK_SYS0 to CLK_PLL0O
* 	             CLK_e_CLK_SYS1: change CLK_SYS1 to CLK_PLL1O
* Return Value : RET_OK       : no error
*                RET_ERR_PARAM: argument is out of range
*                RET_NONEED   : CLK_SYS0/SYS1 has already selected CLK_PLL0O/CLK_PLL1O
*                RET_ERR_STATE: PLL is neither stable state nor stop state
*******************************************************************************/
uint8_t R_CLK_GearDownCLK_SYS( CLK_e_CLK_SYS clk_sys );

/*******************************************************************************
* Description  : Changes source clock
* Arguments    : volatile uint32_t *rCKC_C_reg
*                    address of clock selector control register(CKS_xxxC)
*                volatile uint32_t *rCKS_S_reg
*                    address of clock selector status register(CKS_xxxS)
*                uint32_t clock: 
*                    value of clock selector control register(CKS_xxxC)
* Return Value : RET_OK       : no error occurred
*******************************************************************************/
uint8_t R_CLK_ChangeClockSource( volatile uint32_t *rCKC_C_reg, volatile uint32_t *rCKS_S_reg, uint32_t clock );

/*******************************************************************************
* Description  : Changes source clock for CLK_PLLIN
* Arguments    : CLK_e_PLLIN clock: clock source for CLK_PLLIN
* Return Value : RET_OK: no error occurred
* Example      :
	R_CLK_ChangeClock_PLLIN( CLK_e_PLLIN_CLK_MOSC );	// CLK_PLLIN = CLK_MOSC
	R_CLK_ChangeClock_PLLIN( CLK_e_PLLIN_CLK_HSIOSC );	// CLK_PLLIN = CLK_HSIOSC
*******************************************************************************/
#define	R_CLK_ChangeClock_PLLIN(clock)	R_CLK_ChangeClockSource( &rCKS_PLLINC.UINT32, &rCKS_PLLINS.UINT32, clock )

/*******************************************************************************
* Description  : Changes source clock for CLK_RLIN3
* Arguments    : CLK_e_RLIN clock: clock source for CLK_RLIN3
* Return Value : RET_OK: no error occurred
* Example      :
	R_CLK_ChangeClock_RLIN3( CLK_e_RLIN_CLK_IOSC0 );	// CLK_RLIN3 = CLK_IOSC0
	R_CLK_ChangeClock_RLIN3( CLK_e_RLIN_CLK_P080 );	// CLK_RLIN3 = CLK_P080
	R_CLK_ChangeClock_RLIN3( CLK_e_RLIN_CLK_MOSC );	// CLK_RLIN3 = CLK_MOSC
	R_CLK_ChangeClock_RLIN3( CLK_e_RLIN_CLK_MOSC_4MHz );	// CLK_RLIN3 = 4MHz with CLK_MOSC
*******************************************************************************/
#define	R_CLK_ChangeClock_RLIN3(clock)	R_CLK_ChangeClockSource( &rCKS_RLINC.UINT32, &rCKS_RLINS.UINT32, clock )

/*******************************************************************************
* Description  : Changes source clock for EXTCLK1O
* Arguments    : CLK_e_EXTCLK1 clock: clock source for EXTCLK1O
* Return Value : RET_OK: no error occurred
* Example      :
	R_CLK_ChangeClock_EXTCLK1O( CLK_e_EXTCLK1_CLK_BUS8 );	// EXTCLK1O = CLK_BUS8 (default)
	R_CLK_ChangeClock_EXTCLK1O( CLK_e_EXTCLK1_CLK_P080 );	// EXTCLK1O = CLK_P080
*******************************************************************************/
#define	R_CLK_ChangeClock_EXTCLK1O(clock)	R_CLK_ChangeClockSource( &rCKS_EXTCLK1C.UINT32, &rCKS_EXTCLK1S.UINT32, clock )

/*******************************************************************************
* Description  : Changes source clock for CLK_RTCA
* Arguments    : CLK_e_ARTCA clock: clock source for CLK_RTCA
* Return Value : RET_OK: no error occurred
* Example      :
	R_CLK_ChangeClock_RTCA( CLK_e_ARTCA_CLK_IOSC0 );	// CLK_RTCA = CLK_IOSC0 (default)
	R_CLK_ChangeClock_RTCA( CLK_e_ARTCA_CLK_LSIOSC );	// CLK_RTCA = CLK_LSIOSC
	R_CLK_ChangeClock_RTCA( CLK_e_ARTCA_CLK_SOSC );	// CLK_RTCA = CLK_SOSC
*******************************************************************************/
#define	R_CLK_ChangeClock_RTCA(clock)	R_CLK_ChangeClockSource( &rCKS_ARTCAC.UINT32, &rCKS_ARTCAS.UINT32, clock )

/*******************************************************************************
* Description  : Changes source clock for CLK_ADC0
* Arguments    : CLK_e_AADC clock: clock source for CLK_ADC0
* Return Value : RET_OK: no error occurred
* Example      :
	R_CLK_ChangeClock_ADC0( CLK_e_AADC_CLK_IOSC0 );	// CLK_ADC0 = CLK_IOSC0 (default)
	R_CLK_ChangeClock_ADC0( CLK_e_AADC_CLK_P040 );	// CLK_ADC0 = CLK_P040
	R_CLK_ChangeClock_ADC0( CLK_e_AADC_CLK_HSIOSC_2 );	// CLK_ADC0 = CLK_HSIOSC/2
*******************************************************************************/
#define	R_CLK_ChangeClock_ADC0(clock)	R_CLK_ChangeClockSource( &rCKS_AADCC.UINT32, &rCKS_AADCS.UINT32, clock )

/*******************************************************************************
* Description  : Changes source clock for EXTCLK0O
* Arguments    : CLK_e_EXTCLK0 clock: clock source for EXTCLK0O
* Return Value : RET_OK       : no error occurred
* Example      :
	R_CLK_ChangeClock_EXTCLK0O( CLK_e_EXTCLK0_CLK_MOSC );	// EXTCLK0O = CLK_MOSC
	R_CLK_ChangeClock_EXTCLK0O( CLK_e_EXTCLK0_CLK_LSIOSC );	// EXTCLK0O = CLK_LSIOSC
	R_CLK_ChangeClock_EXTCLK0O( CLK_e_EXTCLK0_CLK_HSIOSC_2 );	// EXTCLK0O = CLK_HSIOSC/2 (default)
	R_CLK_ChangeClock_EXTCLK0O( CLK_e_EXTCLK0_CLK_SOSC );	// EXTCLK0O = CLK_SOSC
*******************************************************************************/
#define	R_CLK_ChangeClock_EXTCLK0O(clock)	R_CLK_ChangeClockSource( &rCKS_EXTCLK0C.UINT32, &rCKS_EXTCLK0S.UINT32, clock )

/*******************************************************************************
* Description  : Changes source clock for CLK_LPS
* Arguments    : CLK_e_ALPS clock: clock source for CLK_LPS
* Return Value : RET_OK: no error occurred
* Example      :
	R_CLK_ChangeClock_LPS( CLK_e_ALPS_CLK_IOSC0 );	// CLK_LPS = CLK_IOSC0 (default)
	R_CLK_ChangeClock_LPS( CLK_e_ALPS_CLK_LSIOSC );	// CLK_LPS = CLK_LSIOSC
	R_CLK_ChangeClock_LPS( CLK_e_ALPS_CLK_HSIOSC_2 );	// CLK_LPS = CLK_HSIOSC/2
*******************************************************************************/
#define	R_CLK_ChangeClock_LPS(clock)	R_CLK_ChangeClockSource( &rCKS_ALPSC.UINT32, &rCKS_ALPSS.UINT32, clock )

/*******************************************************************************
* Description  : Changes divide rate for EXTCLK
* Arguments    : uint8_t  n  : unit number of EXTCLK
*                uint16_t div: target divide rate
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_ERR_PARAM: argument is out of range
********************************************************************************/
uint8_t R_CLK_ChangeDiv_EXTCLK( uint8_t n, uint16_t div );

/*******************************************************************************
* Description  : Open EXTCLKnO pin.
* Arguments    : uint8_t n  : unit number of EXTCLK
*                uint8_t pin: serial number of same function pin
* Return Value : (none)
*******************************************************************************/
void R_CLK_OpenEXTCLKnO( uint8_t n, uint8_t pin, PORT_e_st strength );

/*******************************************************************************
* Description  : Force stop CLK_HSOSC
*                This function intentionally generates a CLMA error and stops
*                the CLK_HSOSC.
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void R_CLK_ForceStopHSOSC( void );

/*******************************************************************************
* Description  : Release stop CLK_HSOSC
*                This function intentionally generates a CLMA error and stops
*                the CLK_HSOSC.
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void R_CLK_ReleaseStopHSOSC( void );


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_clock_H__ */
