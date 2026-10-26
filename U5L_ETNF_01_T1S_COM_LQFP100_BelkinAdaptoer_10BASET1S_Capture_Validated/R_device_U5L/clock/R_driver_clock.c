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
* File Name    : R_driver_clock.c
* Version      : 1.00
* Device(s)    : Clock controller
* Device(s)    : R-Car U5L product
* Description  : Clock controller driver for R-Car U5L
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_clock.h"
#include "R_driver_CLMA.h"


/*******************************************************************************
* Section specification for entire file
*******************************************************************************/
#pragma	section	default


/*******************************************************************************
* Definitions
*******************************************************************************/


/*******************************************************************************
* Global variables
*******************************************************************************/


/*******************************************************************************
* Function body
*******************************************************************************/

/*******************************************************************************
* Description  : Enables Main OSC
* Arguments    : (none)
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_NONEED   : not execute this function due to Main OSC has 
*                               already enabled
*******************************************************************************/
uint8_t R_CLK_EnableMOSC( void ){
	
	/* check Main OSC operating */
	/* MOSCS.MOSCEN = 1 & MOSCS.MOSCSTAB = 1? */
	if( (rMOSCS.UINT32 & 0x00000003) == 0x00000003 ){
		/* not execute this function due to Main OSC has already enabled */
		return( RET_NONEED );
	}
	
	/* Release write protection */
	R_CLK_ReleaseWriteProtect();
	
	/* Start the Main OSC */
	rMOSCE.BIT.MOSCENTRG = 1;
	
	/* Confirm that the Main OSC has been stable */
	/* wait until MOSCS.MOSCEN = 1 & MOSCS.MOSCSTAB = 1 */
	while( (rMOSCS.UINT32 & 0x00000003) != 0x00000003 )
		;
	
	/* Set write protection */
	R_CLK_SetWriteProtect();
	
	
	return( RET_OK );
}


/*******************************************************************************
* Description  : Disables Main OSC
* Arguments    : (none)
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_NONEED   : not execute this function due to Main OSC has 
*                               already disabled
*******************************************************************************/
uint8_t R_CLK_DisableMOSC( void ){

	/* check Main OSC stopped */
	/* rMOSCS.rMOSCEN = 0 & rMOSCS.MOSCSTAB = 0? */
	if( (rMOSCS.UINT32 & 0x00000003) == 0x00000000 ){
		/* not execute this function due to Main OSC has already disabled */
		return( RET_NONEED );
	}
	
	/* Release write protection */
	R_CLK_ReleaseWriteProtect();
	
	/* Stop the Main OSC */
	rMOSCE.BIT.MOSCDISTRG = 1;

	/* Confirm that the Main OSC has been stopped */
	/* wait until MOSCS.MOSCEN = 0 & MOSCS.MOSCSTAB = 0 */
	while( (rMOSCS.UINT32 & 0x00000003) != 0x00000000 )
		;
	
	/* Set write protection */
	R_CLK_SetWriteProtect();
	

	return( RET_OK );
}


/*******************************************************************************
* Description  : Enables Sub OSC
* Arguments    : uint32_t stab_time: stabilization time
*                The stabilization time is stab_time / fRL.
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_NONEED   : not execute this function due to Sub OSC has 
*                               already enabled
*******************************************************************************/
uint8_t R_CLK_EnableSOSC( uint32_t stab_time ){

	uint8_t	ret = RET_OK;


	/* check Sub OSC operating */
	/* SOSCS.SOSCEN = 1 & SOSCS.SOSCSTAB = 1? */
	if( (rSOSCS.UINT32 & 0x00000003) == 0x00000003 ){
		/* not execute this function due to Sub OSC has already enabled */
		return( RET_NONEED );
	}

	/* Release write protection */
	R_CLK_ReleaseWriteProtect();

	/* Set stabilization time */
	ret = Reg32WRC( &rSOSCST.UINT32, stab_time, 0x003FFFFF );

	/* Start the Sub OSC */
	rSOSCE.BIT.SOSCENTRG = 1;

	/* Confirm that the Sub OSC has been stable */
	/* wait until SOSCS.SOSCEN = 1 & SOSCS.SOSCSTAB = 1 */
	while( (rSOSCS.UINT32 & 0x00000003) != 0x00000003 )
		;

	/* Set write protection */
	R_CLK_SetWriteProtect();


	return( ret );
}


/*******************************************************************************
* Description  : Disables Sub OSC
* Arguments    : (none)
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_NONEED   : not execute this function due to Sub OSC has 
*                               already disabled
*******************************************************************************/
uint8_t R_CLK_DisableSOSC( void ){

	uint8_t	ret = RET_OK;


	/* check Sub OSC stopped */
	/* SOSCS.SOSCEN = 0 & SOSCS.SOSCSTAB = 0? */
	if( (rSOSCS.UINT32 & 0x00000003) == 0x00000000 ){
		/* not execute this function due to Sub OSC has already disabled */
		return( RET_NONEED );
	}

	/* Release write protection */
	R_CLK_ReleaseWriteProtect();

	/* Stop the Sub OSC */
	rSOSCE.BIT.SOSCDISTRG = 1;

	/* Confirm that the Sub OSC has been stopped */
	/* wait until SOSCS.SOSCEN = 0 & SOSCS.SOSCSTAB = 0 */
	while( (rSOSCS.UINT32 & 0x00000003) != 0x00000000 )
		;

	/* Set write protection */
	R_CLK_SetWriteProtect();


	return( ret );
}


/*******************************************************************************
* Description  : Enables PLL0/1
* Arguments    : (none)
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_NONEED   : not execute this function due to PLL has 
*                               already enabled
*                RET_ERR_STATE: not execute this function because PLL does 
*	                            not stopped
*                               (PLLEN=1 and PLLSTAB=0: abnormal state)
*******************************************************************************/
uint8_t R_CLK_EnablePLL( void ){
	
	/* if PLL has already enabled, skip this function */
	/* PLLS.PLLCLKEN = 1 & PLLS.PLLCLKSTAB = 1? */
	if( (rPLLS.UINT32 & 0x00000003) == 0x00000003 ){
		return( RET_NONEED );
	}
	
	/* Confirm that the Main OSC is stable */
	/* if Main OSC is used as PLL input clock and 
	      Main OSC has not been enabled, enable Main OSC */
	if( (rCKS_PLLINS.BIT.PLLINSACT == CLK_e_PLLIN_CLK_MOSC) &&
	    ((rMOSCS.UINT32 & 0x00000003) != 0x00000003) ){
		/* enable Main OSC */
		R_CLK_EnableMOSC();
	}

	/* Confirm that the PLL is stopped */
	/* PLLS.PLLCLKEN != 0 | PLLS.PLLCLKSTAB != 0? */
	if( (rPLLS.UINT32 & 0x00000003) != 0x00000000 ){
		/* not execute this function because PLL does not stopped */
		/* (ether PLLEN=1 or PLLSTAB=1: abnormal state) */
		return( RET_ERR_STATE );
	}
	
	/* Release write protection */
	R_CLK_ReleaseWriteProtect();
	
	/* Start the PLL */
	rPLLE.BIT.PLLENTRG = 1;
	
	/* Confirm that the PLL has been stable */
	/* wait until PLLS.PLLCLKEN = 1 & PLLS.PLLCLKSTAB = 1 */
	while( (rPLLS.UINT32 & 0x00000003) != 0x00000003 )
		;
	
	/* Set write protection */
	R_CLK_SetWriteProtect();

	
	return( RET_OK );
}


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
uint8_t R_CLK_DisablePLL( void ){
	
	/* if PLL has already disabled, skip this function */
	/* PLLS.PLLCLKEN = 0 & PLLS.PLLCLKSTAB != 0? */
	if( (rPLLS.UINT32 & 0x00000003) == 0x00000000 ){	
		return( RET_NONEED );
	}
	

	/* Confirm that the PLL is stabled */
	/* PLLS.PLLCLKEN != 1 | PLLS.PLLCLKSTAB != 1? */
	if( (rPLLS.UINT32 & 0x00000003) != 0x00000003 ){
		/* not execute this function because PLL does not stopped */
		/* (ether PLLEN=1 or PLLSTAB=1: abnormal state) */
		return( RET_ERR_STATE );
	}
	
	/* Select CLK_IOSC1 for clock source of CLK_SYS1 (CKS_SYS1S.SYSCLKSACT = 1), 
	   CLK_SYS0 (CKS_SYS0S.SYSCLKSACT = 1). */
	R_CLK_GearDownCLK_SYS( CLK_e_CLK_SYS0 );
	R_CLK_GearDownCLK_SYS( CLK_e_CLK_SYS1 );
	
	/* Release write protection */
	R_CLK_ReleaseWriteProtect();
	
	/* Stop the PLL */
	rPLLE.BIT.PLLDISTRG = 1;
	
	/* Confirm that the PLL has been stopped */
	/* wait until PLLS.PLLCLKEN = 0 & PLLS.PLLCLKSTAB = 0 */
	while( (rPLLS.UINT32 & 0x00000003) != 0x00000000 )
		;
	
	/* Set write protection */
	R_CLK_SetWriteProtect();

	
	return( RET_OK );
}


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
uint8_t R_CLK_ConfigSSCG( CLK_s_SSCGC *sscgc ){

	uint8_t 	ret;
	
	
	/* Release write protection */
	R_CLK_ReleaseWriteProtect();

	/* set SSCGC register */
	ret = Reg32WRC( &rSSCGC.UINT32, sscgc->UINT32, 0x000003FF );
	
	/* Set write protection */
	R_CLK_SetWriteProtect();
	
	
	return( ret );
}


/*******************************************************************************
* Description  : Changes divide rate of CLK_PLL0O or CLK_PLL1O
* Arguments    : CLK_e_CLK_PLL     pll: target PLL
*                CLK_e_PLLCLKDCSID div: target divide rate
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_ERR_PARAM: argument is out of range
*                RET_ERR_STATE: PLL does not started.
*******************************************************************************/
uint8_t R_CLK_ChangeDiv_PLL( CLK_e_CLK_PLL pll, CLK_e_PLLCLKDCSID div ){

	volatile uint32_t	*rCKD_c_addr;	/* CLK_PLL0O/CLK_PLL1O  Divider Control Register */
	volatile uint32_t	*rCKD_s_addr;	/* CLK_PLL0O/CLK_PLL1O Divider Status Register */


	/* prepare control/status register */
	if( pll == CLK_e_CLK_PLL0 ){
		rCKD_c_addr = &rCKD_PLL0C.UINT32;
		rCKD_s_addr = &rCKD_PLL0S.UINT32;
	}else if( pll == CLK_e_CLK_PLL1 ){
		rCKD_c_addr = &rCKD_PLL1C.UINT32;
		rCKD_s_addr = &rCKD_PLL1S.UINT32;
	}else{
		/* parameter error */
		return( RET_ERR_PARAM );
	}

	/* if PLL is disabled, skip this function */
	/* PLLS.PLLCLKEN != 1 & PLLS.PLLCLKSTAB != 1? */
	if( (rPLLS.UINT32 & 0x00000003) != 0x00000003 ){
		return( RET_ERR_STATE );
	}
	
	/* Release write protection */
	R_CLK_ReleaseWriteProtect();

	/* set clock divider control register */
	*rCKD_c_addr = (uint32_t)div;
	
	/* wait until clock changing is completed */
	/* wait until PLLCLKDSYNC bit = 1 */
	while( (*rCKD_s_addr & (1 << 1)) != (1 << 1) )
		;
		
	/* Set write protection */
	R_CLK_SetWriteProtect();
	
	
	return( RET_OK );
}


/******************-*************************************************************
* Description  : Changes CLK_SYS0/1 from CLK_IOSC0/1 to CLK_PLL0/1O
* Arguments    : CLK_e_CLK_SYS clk_sys
* 	             CLK_e_CLK_SYS0: change CLK_SYS0 to CLK_PLL0O
* 	             CLK_e_CLK_SYS1: change CLK_SYS1 to CLK_PLL1O
* Return Value : RET_OK       : no error
*                RET_ERR_PARAM: argument is out of range
*                RET_NONEED   : CLK_SYS0/SYS1 has already selected CLK_PLL0O/CLK_PLL1O
*                RET_ERR_STATE: PLL is neither stable state nor stop state
*******************************************************************************/
uint8_t R_CLK_GearUpCLK_SYS( CLK_e_CLK_SYS clk_sys ){
	
	volatile uint32_t	*rCKS_c_addr;	/* CLK_SYS0/CLK_SYS1 Selector Control Register */
	volatile uint32_t	*rCKS_s_addr;	/* CLK_SYS0/CLK_SYS1 Selector Status Register */
	volatile uint32_t	*rCKD_c_addr;	/* CLK_PLL0O/CLK_PLL1O  Divider Control Register */
	volatile uint32_t	*rCKD_s_addr;	/* CLK_PLL0O/CLK_PLL1O Divider Status Register */

	int32_t  		ckd_value[8];
	uint8_t  		ckd_i;
	uint8_t  		ckd_i_end=0;
	
	
	/* prepare control/status register */
	/**************************************************************************/
	if( clk_sys == CLK_e_CLK_SYS0 ){
		rCKS_c_addr = &rCKS_SYS0C.UINT32;
		rCKS_s_addr = &rCKS_SYS0S.UINT32;
		rCKD_c_addr = &rCKD_PLL0C.UINT32;
		rCKD_s_addr = &rCKD_PLL0S.UINT32;
	}else if( clk_sys == CLK_e_CLK_SYS1 ){
		rCKS_c_addr = &rCKS_SYS1C.UINT32;
		rCKS_s_addr = &rCKS_SYS1S.UINT32;
		rCKD_c_addr = &rCKD_PLL1C.UINT32;
		rCKD_s_addr = &rCKD_PLL1S.UINT32;
	}else{
		/* parameter error */
		return( RET_ERR_PARAM );
	}
	

	/* if CLK_SYS0/SYS1 has already selected CLK_PLL0O/CLK_PLL1O, skip this function */
	/**************************************************************************/
	if( (*rCKS_s_addr & (1 << 0)) == 0x00000000 ){
		return( RET_NONEED );
	}
	
	
	/* Verify that PLL0/PLL1 is stable */
	/**************************************************************************/
	/* (If PLL is disabled, PLL enable. If PLL could not enable, skip this function.) */
	if( R_CLK_EnablePLL() == RET_ERR_STATE ){
		return( RET_ERR_STATE );
	}
	
	
	/* prepare gear up */
	/**************************************************************************/
	/* set divide rate */
			ckd_value[ckd_i_end++] = 2;
			ckd_value[ckd_i_end++] = 4;
			ckd_value[ckd_i_end++] = 6;
			ckd_value[ckd_i_end++] = 8;
			ckd_value[ckd_i_end++] = 10;
			ckd_value[ckd_i_end++] = 12;
			ckd_value[ckd_i_end++] = 14;
			ckd_value[ckd_i_end]   = 0;		/* no divide */
	
			
	/* Release write protection */
	/**************************************************************************/
	R_CLK_ReleaseWriteProtect();
	
	
	/* [Step1] Division ratio of clock source
	 *         PLL0/PLL1 is changed
	 *         from 1/1 to start_rate/16
	 **************************************************************************/
	/* change divide of CLK_PLL0O/PLL1O */
	*rCKD_c_addr = ckd_value[0];
	
	/* verify that the value of CLKDSYNC is 1B. */
	while( (*rCKD_s_addr & (1 << 1)) != (1 << 1) )
		;
	
	
	/* [Step2] The clock source for the System clock
	 *         is changed from CLK_IOSC1 to
	 *         CLK_PLL0O/CLK_PLL1O.
	 **************************************************************************/
	/* change CLK_SYS0/SYS1 to CLK_PLL0O/PLL1O */
	*rCKS_c_addr = 0;
	
	/* verify that the value of SYSCLKSACT is 0B. */
	while( *rCKS_s_addr != 0 )
		;
	
	/* wait 100us */
	wait( 100 );	/* need to check whether this value is appropriate */
	
	
	/* [Step3] Division ratio of clock source PLL0/PLL1 is changed
	 *         4/16(1st) -> 6/16 -> 8/16 -> 10/16 -> 12/16 -> 14/16 -> 16/16. (PLL0/1)
	 **************************************************************************/
	for( ckd_i = 1; ckd_i <= ckd_i_end; ckd_i++ ){
		/* change divide of CLK_PLL0O/PLL1O */
		*rCKD_c_addr = ckd_value[ckd_i];
		
		/* verify that the value of CLKDSYNC is 1B. */
		while( (*rCKD_s_addr & (1 << 1)) != (1 << 1) )
			;
	
		/* wait 100us */
		wait( 100 );	/* need to check whether this value is appropriate */
	}
	
	
	/* Set write protection */
	/**************************************************************************/
	R_CLK_SetWriteProtect();
	
	
	return( RET_OK );
}


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
uint8_t R_CLK_GearDownCLK_SYS( CLK_e_CLK_SYS clk_sys ){

	volatile uint32_t	*rCKS_c_addr;	/* CLK_SYS0/CLK_SYS1 Selector Control Register */
	volatile uint32_t	*rCKS_s_addr;	/* CLK_SYS0/CLK_SYS1 Selector Status Register */
	volatile uint32_t	*rCKD_c_addr;	/* CLK_PLL0O/CLK_PLL1O  Divider Control Register */
	volatile uint32_t	*rCKD_s_addr;	/* CLK_PLL0O/CLK_PLL1O Divider Status Register */

	int32_t  		ckd_value[8];
	uint8_t  		ckd_i;
	uint8_t  		ckd_i_end=0;


	/* prepare control/status register */
	/**************************************************************************/
	if( clk_sys == CLK_e_CLK_SYS0 ){
		rCKS_c_addr = &rCKS_SYS0C.UINT32;
		rCKS_s_addr = &rCKS_SYS0S.UINT32;
		rCKD_c_addr = &rCKD_PLL0C.UINT32;
		rCKD_s_addr = &rCKD_PLL0S.UINT32;
	}else if( clk_sys == CLK_e_CLK_SYS1 ){
		rCKS_c_addr = &rCKS_SYS1C.UINT32;
		rCKS_s_addr = &rCKS_SYS1S.UINT32;
		rCKD_c_addr = &rCKD_PLL1C.UINT32;
		rCKD_s_addr = &rCKD_PLL1S.UINT32;
	}else{
		/* parameter error */
		return( RET_ERR_PARAM );
	}

	/* if CLK_SYS0/SYS1 has already selected CLK_IOSC1, skip this function */
	/**************************************************************************/
	if( (*rCKS_s_addr & (1 << 0)) == (1 << 0) ){
		return( RET_NONEED );
	}

	/* prepare gear up */
	/**************************************************************************/
	/* set divide rate */
			ckd_value[ckd_i_end++] = 14;
			ckd_value[ckd_i_end++] = 12;
			ckd_value[ckd_i_end++] = 10;
			ckd_value[ckd_i_end++] = 8;
			ckd_value[ckd_i_end++] = 6;
			ckd_value[ckd_i_end++] = 4;
			ckd_value[ckd_i_end]   = 2;


	/* Release write protection */
	/**************************************************************************/
	R_CLK_ReleaseWriteProtect();


	/* [Step1] Division ratio of clock source PLL0/PLL1 is changed
	 **************************************************************************/
	for( ckd_i = 0; ckd_i <= ckd_i_end; ckd_i++ ){
		/* change divide of CLK_PLL0O/PLL1O */
		*rCKD_c_addr = ckd_value[ckd_i];

		/* verify that the value of CLKDSYNC is 1B. */
		while( (*rCKD_s_addr & (1 << 1)) != (1 << 1) )
			;

		/* wait 100us */
		wait( 100 );	/* need to check whether this value is appropriate */
	}
	
	
	/* [Step2] The clock source for the System clock is changed from
	 *         CLK_SYS0/SYS1 to CLK_IOSC.
	 **************************************************************************/
	/* change CLK_SYS_xxx to CLK_IOSC */
	*rCKS_c_addr = 1;

	/* verify that the value of CLKSACT is 1B. */
	while( *rCKS_s_addr != 1 )
		;

	/* wait 100us */
	wait( 100 );	/* need to check whether this value is appropriate */


	/* Set write protection */
	/**************************************************************************/
	R_CLK_SetWriteProtect();


	return( RET_OK );
}


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
uint8_t R_CLK_ChangeClockSource( volatile uint32_t *rCKC_C_reg, volatile uint32_t *rCKS_S_reg, uint32_t clock ){

	/* Release write protection */
	R_CLK_ReleaseWriteProtect();

	/* set clock selector control register */
	*rCKC_C_reg = (uint32_t)clock;
	
	/* wait until clock changing is completed */
	while( *rCKS_S_reg != clock )
		;
		
	/* Set write protection */
	R_CLK_SetWriteProtect();
	
	
	return( RET_OK );
}


/*******************************************************************************
* Description  : Changes divide rate for EXTCLK
* Arguments    : uint8_t  n  : unit number of EXTCLK
*                uint16_t div: target divide rate
* Return Value : processing result of this function
*                RET_OK       : no error occurred
*                RET_ERR_PARAM: argument is out of range
********************************************************************************/
uint8_t R_CLK_ChangeDiv_EXTCLK( uint8_t n, uint16_t div ){

	volatile uint32_t	*rCKD_c_addr;	/* Divider Control Register */
	volatile uint32_t	*rCKD_s_addr;	/* Divider Status Register */


	/* prepare control/status register */
	if( n == 0 ){
		rCKD_c_addr = &rCKD_EXTCLK0C.UINT32;
		rCKD_s_addr = &rCKD_EXTCLK0S.UINT32;
	}else if( n == 1 ){
		rCKD_c_addr = &rCKD_EXTCLK1C.UINT32;
		rCKD_s_addr = &rCKD_EXTCLK1S.UINT32;
	}else{
		/* parameter error */
		return( RET_ERR_PARAM );
	}

	/* Release write protection */
	R_CLK_ReleaseWriteProtect();

	/* set divider control register */
	*rCKD_c_addr = (uint32_t)div;
	
	/* wait until divide change or stop EXTCLK */
	if( div == 0 ){
		/* wait until clock stopped (EXTCLKnCLKACT=0 & EXTCLKnSYNC=1) */
		while( (*rCKD_s_addr & (3 << 0) ) != (1 << 0) )
			;

	}else{
		/* wait until clock changing is completed (EXTCLKnCLKACT=1 & EXTCLKnSYNC = 1) */
		while( (*rCKD_s_addr & (3 << 0) ) != (3 << 0) )
			;
	}
		
	/* Set write protection */
	R_CLK_SetWriteProtect();
	
	
	return( RET_OK );
}


/*******************************************************************************
* Description  : Open EXTCLKnO pin.
* Arguments    : uint8_t n  : unit number of EXTCLK
*                uint8_t pin: serial number of same function pin
*                PORT_e_st strength: drive strength
* Return Value : (none)
*******************************************************************************/
void R_CLK_OpenEXTCLKnO( uint8_t n, uint8_t pin, PORT_e_st strength ){

	uint8_t 	p_n, p_m, alt;
	
	switch( (n << 4) | pin ){
		/* EXTCLK0O */
		case (0 << 4) | 0:	p_n = 0; p_m = 7; alt = 2;	break;	/* P00_7 EXTCLK0O */
		case (0 << 4) | 1:	p_n = 8; p_m = 4; alt = 4;	break;	/* P08_4 EXTCLK0O */
		case (0 << 4) | 2:	p_n = 0; p_m = 0; alt = 6;	break;	/* P00_0 EXTCLK0O */
		
		/* EXTCLK1O */
		case (1 << 4) | 0:	p_n = 10; p_m = 0; alt = 2;	break;	/* P10_0 EXTCLK1O */
		case (1 << 4) | 1:	p_n = 9;  p_m = 2; alt = 4;	break;	/* P09_2 EXTCLK1O */
		case (1 << 4) | 2:	p_n = 10; p_m = 3; alt = 5;	break;	/* P10_3 EXTCLK1O */
	}
	
	/* Change port alternative function */
	R_PORT_SetAlt_Pnm( p_n, p_m, alt, PORT_e_IO_OUT );

	/* Change port drive strength */
	R_PORT_ChangeStrength_Pnm( p_n, p_m, strength );

}


/*******************************************************************************
* Description  : Force stop CLK_HSOSC
*                This function intentionally generates a CLMA error and stops
*                the CLK_HSOSC.
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void R_CLK_ForceStopHSOSC( void ){

	uint8_t 	n = 1;


	/* set CLMA error limit */
	rCLMAnCMPH(n).UINT16 = 0;

	/* start CLMA1 */
	rCLMAKCPROT.UINT32 = 0xA5A5A501;
	rCLMAnCTL(n).UINT8 = 0x01;
	rCLMAKCPROT.UINT32 = 0xA5A5A500;

}


/*******************************************************************************
* Description  : Release stop CLK_HSOSC
*                This function intentionally generates a CLMA error and stops
*                the CLK_HSOSC.
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void R_CLK_ReleaseStopHSOSC( void ){

	uint8_t 	n = 1;


	/* Reset CLMA1 */
	rCLMAKCPROT.UINT32 = 0xA5A5A501;
	rCLMATEST.BIT.CLMA1TESEN = CLMA_e_TESEN_enable;
	rCLMATEST.BIT.RESCLM     = CLMA_e_RESCLM_mask;
	rCLMATEST.BIT.RESCLM     = CLMA_e_RESCLM_no_mask;
	rCLMATEST.BIT.CLMA1TESEN = CLMA_e_TESEN_disable;
	rCLMAKCPROT.UINT32 = 0xA5A5A500;

}

	
/*******************************************************************************
* Return to default section
*******************************************************************************/
#pragma	section	default
