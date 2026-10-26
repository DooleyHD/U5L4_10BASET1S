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
* File Name    : R_driver_standby.h
* Version      : 1.00
* Device(s)    : Standby controller
* Device(s)    : R-Car U5L product
* Description  : Standby controller driver for R-Car U5L
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_standby_H__
#define	__R_driver_standby_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_standby_reg.h"	/* for reference of register structure */
#include "R_driver_general.h"
#include "product.h"
#include "product.h"


/*******************************************************************************
* Extern of global variables
*******************************************************************************/

/*******************************************************************************
* Definition
*******************************************************************************/
/* local definition for the function R_STB_SupplyClock_MOSC and R_STB_StopClock_MOSC*/
#define	rMOSCSTPM_STB 	(*(volatile uint32_t *) (0x5C08800C) )	/* Main OSC Stop Mask Register */
#define	rCLKKCPROT1_STB (*(volatile uint32_t *) (0x5C080700) )	/* Clock Controller Register Key Code Protection Register 1 */

/* local definition for the function R_STB_SupplyClock_HSOSC and R_STB_StopClock_HSOSC*/
#define	rHSOSCSTPM_STB	(*(volatile uint32_t *) (0x5C088104) )	/* HS IntOSC Stop Mask Register */

/* local definition for the function R_STB_SupplyClock_HSOSC and R_STB_StopClock_HSOSC*/
#define	rADCK0VCR0_STB	(*(volatile uint32_t *) (0x5C930000) )	/* Virtual channel register j */

/* Effective bits for IOHOLD register */
#define	STB_IOHOLD_ALL	0x003C3E0A
#define	STB_IOHOLD2_ALL	0x00000005


/*******************************************************************************
* Type definitions for the function return value
*******************************************************************************/


/*******************************************************************************
* Type definitions for the arguments of the function
*******************************************************************************/
/* index of wakeup register */
typedef enum{
	STB_e_WUF_reg_A0 = 0,
	STB_e_WUF_reg_A1 = 1,
}STB_e_WUF_reg;

/* kind of wakeup (wakeup to RUN mode or wakeup to Cyclic RUN mode) */
typedef enum{
	STB_e_WUF_type_RUN      = 1,
	STB_e_WUF_type_CRUN     = 2,
	STB_e_WUF_type_RUNCRUN  = 3
}STB_e_WUF_type;

/* register number and bit position information of wakeup factor */
typedef enum{
	STB_e_WUF_NMI = (STB_e_WUF_reg_A0 << 8), 	/* A0 bit 0 */
	STB_e_WUF_reserved_A0_1,       	/* A0 bit 1 */
	STB_e_WUF_reserved_A0_2,       	/* A0 bit 2 */
	STB_e_WUF_reserved_A0_3,       	/* A0 bit 3 */
	STB_e_WUF_INTWDTBATIT,         	/* A0 bit 4 */
	STB_e_WUF_reserved_A0_5,       	/* A0 bit 5 */
	STB_e_WUF_reserved_A0_6,       	/* A0 bit 6 */
	STB_e_WUF_reserved_A0_7,       	/* A0 bit 7 */
	STB_e_WUF_INTRTCA01S,          	/* A0 bit 8 */
	STB_e_WUF_INTRTCA0AL,          	/* A0 bit 9 */
	STB_e_WUF_INTRTCA0R,           	/* A0 bit 10 */
	STB_e_WUF_reserved_A0_11,      	/* A0 bit 11 */
	STB_e_WUF_reserved_A0_12,      	/* A0 bit 12 */
	STB_e_WUF_reserved_A0_13,      	/* A0 bit 13 */
	STB_e_WUF_reserved_A0_14,      	/* A0 bit 14 */
	STB_e_WUF_reserved_A0_15,      	/* A0 bit 15 */
	STB_e_WUF_WUTRG0,              	/* A0 bit 16 */
	STB_e_WUF_WUTRG1,              	/* A0 bit 17 */
	STB_e_WUF_reserved_A0_18,      	/* A0 bit 18 */
	STB_e_WUF_reserved_A0_19,      	/* A0 bit 19 */
	STB_e_WUF_INTLPSTM0,           	/* A0 bit 20 */
	STB_e_WUF_INTLPSTM1,           	/* A0 bit 21 */
	STB_e_WUF_INTLPSTM2,           	/* A0 bit 22 */
	STB_e_WUF_INTLPSTM3,           	/* A0 bit 23 */
	STB_e_WUF_INTLPSTM4,           	/* A0 bit 24 */
	STB_e_WUF_reserved_A0_25,      	/* A0 bit 25 */
	STB_e_WUF_reserved_A0_26,      	/* A0 bit 26 */
	STB_e_WUF_reserved_A0_27,      	/* A0 bit 27 */
	STB_e_WUF_reserved_A0_28,      	/* A0 bit 28 */
	STB_e_WUF_reserved_A0_29,      	/* A0 bit 29 */
	STB_e_WUF_reserved_A0_30,      	/* A0 bit 30 */
	STB_e_WUF_INTDCUTDI,           	/* A0 bit 31 */
		
	STB_e_WUF_IRQ0 = (STB_e_WUF_reg_A1 << 8),	/* A1 bit 0 */
	STB_e_WUF_IRQ1,                	/* A1 bit 1 */
	STB_e_WUF_IRQ2,                	/* A1 bit 2 */
	STB_e_WUF_IRQ3,                	/* A1 bit 3 */
	STB_e_WUF_IRQ4,                	/* A1 bit 4 */
	STB_e_WUF_IRQ5,                	/* A1 bit 5 */
	STB_e_WUF_IRQ6,                	/* A1 bit 6 */
	STB_e_WUF_IRQ7,                	/* A1 bit 7 */
	STB_e_WUF_IRQ8,                	/* A1 bit 8 */
	STB_e_WUF_IRQ9,                	/* A1 bit 9 */
	STB_e_WUF_IRQ10,               	/* A1 bit 10 */
	STB_e_WUF_IRQ11,               	/* A1 bit 11 */
	STB_e_WUF_IRQ12,               	/* A1 bit 12 */
	STB_e_WUF_IRQ13,               	/* A1 bit 13 */
	STB_e_WUF_IRQ14,               	/* A1 bit 14 */
	STB_e_WUF_IRQ15,               	/* A1 bit 15 */
	STB_e_WUF_IRQ16,               	/* A1 bit 16 */
	STB_e_WUF_IRQ17,               	/* A1 bit 17 */
	STB_e_WUF_IRQ18,               	/* A1 bit 18 */
	STB_e_WUF_IRQ19,               	/* A1 bit 19 */
	STB_e_WUF_IRQ20,               	/* A1 bit 20 */
	STB_e_WUF_IRQ21,               	/* A1 bit 21 */
	STB_e_WUF_IRQ22,               	/* A1 bit 22 */
	STB_e_WUF_IRQ23,               	/* A1 bit 23 */
	STB_e_WUF_reserved_A1_24,      	/* A1 bit 24 */
	STB_e_WUF_reserved_A1_25,      	/* A1 bit 25 */
	STB_e_WUF_reserved_A1_26,      	/* A1 bit 26 */
	STB_e_WUF_reserved_A1_27,      	/* A1 bit 27 */
	STB_e_WUF_reserved_A1_28,      	/* A1 bit 28 */
	STB_e_WUF_reserved_A1_29,      	/* A1 bit 29 */
	STB_e_WUF_reserved_A1_30,      	/* A1 bit 30 */
	STB_e_WUF_reserved_A1_31       	/* A1 bit 31 */
}STB_e_WUF;	

#define	STB_e_WUF_INTLPSTMx(x)	(STB_e_WUF_INTLPSTM0 + x)
#define	STB_e_WUF_IRQx(x)     	(STB_e_WUF_IRQ0 + x)


/*******************************************************************************
* Prototype declarations of functions and
* functional definition (macro)
*******************************************************************************/

/*******************************************************************************
* Description  : Release write protection for standby related registers
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_STB_ReleaseWriteProtect()	rSTBCKCPROT.UINT32 = 0xA5A5A501

/*******************************************************************************
* Description  : Set write protection for standby related registers
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_STB_SetWriteProtect()    	rSTBCKCPROT.UINT32 = 0xA5A5A500

/*******************************************************************************
* Description  : Release write protection for MSR registers
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_STB_ReleaseWriteProtect_MSR()	rMSRKCPROT.UINT32 = 0xA5A5A501

/*******************************************************************************
* Description  : Set write protection for MSR registers
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_STB_SetWriteProtect_MSR()    	rMSRKCPROT.UINT32 = 0xA5A5A500

/*******************************************************************************
* Description  : Set Main OSC continues operation in chip standby mode
* Arguments    : none
* Return Value : 0     : Register readback check was successful
*                others: The failure count of register readback check
*******************************************************************************/
#define	R_STB_SupplyClock_MOSC()	rCLKKCPROT1_STB = 0xA5A5A501; \
                                	Reg32SetBitCheck( &rMOSCSTPM_STB, 0 ); \
                                	rCLKKCPROT1_STB = 0xA5A5A500

/*******************************************************************************
* Description  : Set Main OSC stops operation in chip standby mode
* Arguments    : none
* Return Value : 0     : Register readback check was successful
*                others: The failure count of register readback check
*******************************************************************************/
#define	R_STB_StopClock_MOSC()  	rCLKKCPROT1_STB = 0xA5A5A501; \
                                	Reg32ClearBitCheck( &rMOSCSTPM_STB, 0 ); \
                                	rCLKKCPROT1_STB = 0xA5A5A500

/*******************************************************************************
* Description  : Set HS IntOSC continues operation in chip standby mode
* Arguments    : none
* Return Value : 0     : Register readback check was successful
*                others: The failure count of register readback check
*******************************************************************************/
#define	R_STB_SupplyClock_HSOSC()	rCLKKCPROT1_STB = 0xA5A5A501; \
	                             	Reg32SetBitCheck( &rHSOSCSTPM_STB, 0 ); \
	                             	rCLKKCPROT1_STB = 0xA5A5A500

/*******************************************************************************
* Description  : Set HS IntOSC stops operation in chip standby mode
* Arguments    : none
* Return Value : 0     : Register readback check was successful
*                others: The failure count of register readback check
*******************************************************************************/
#define	R_STB_StopClock_HSOSC()  	rCLKKCPROT1_STB = 0xA5A5A501; \
                                 	Reg32ClearBitCheck( &rHSOSCSTPM_STB, 0 ); \
                                 	rCLKKCPROT1_STB = 0xA5A5A500
								
/*******************************************************************************
* Description  : Release module standby
* Arguments    : volatile uint32_t *msr_reg: MSR register
* Return Value : (none)
*******************************************************************************/
void R_STB_ReleaseModuleStandby( volatile uint32_t *msr_reg );

/*******************************************************************************
* Description  : Set module standby
* Arguments    : volatile uint32_t *msr_reg: MSR register
* Return Value : (none)
*******************************************************************************/
void R_STB_SetModuleStandby( volatile uint32_t *msr_reg );

/*******************************************************************************
* Description  : Release module standby for each module
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_STB_ReleaseModuleStandby_RSCFD()   	R_STB_ReleaseModuleStandby( &rMSR_RSCFD.UINT32 )
#define	R_STB_ReleaseModuleStandby_ETND()    	R_STB_ReleaseModuleStandby( &rMSR_ETND.UINT32 )
#define	R_STB_ReleaseModuleStandby_ETNF()    	R_STB_ReleaseModuleStandby( &rMSR_ETNF.UINT32 )
#define	R_STB_ReleaseModuleStandby_RSENT()   	R_STB_ReleaseModuleStandby( &rMSR_RSENT.UINT32 )
#define	R_STB_ReleaseModuleStandby_CSIH()    	R_STB_ReleaseModuleStandby( &rMSR_CSIH.UINT32 )
#define	R_STB_ReleaseModuleStandby_RLIN3()   	R_STB_ReleaseModuleStandby( &rMSR_RLIN3.UINT32 )
#define	R_STB_ReleaseModuleStandby_ADCK_ISO()	R_STB_ReleaseModuleStandby( &rMSR_ADCK_ISO.UINT32 )
#define	R_STB_ReleaseModuleStandby_CXPI()   	R_STB_ReleaseModuleStandby( &rMSR_CXPI.UINT32 )
#define	R_STB_ReleaseModuleStandby_MMCA()   	R_STB_ReleaseModuleStandby( &rMSR_MMCA.UINT32 )
#define	R_STB_ReleaseModuleStandby_ENCA()   	R_STB_ReleaseModuleStandby( &rMSR_ENCA.UINT32 )
#define	R_STB_ReleaseModuleStandby_PSI5()   	R_STB_ReleaseModuleStandby( &rMSR_PSI5.UINT32 )
#define	R_STB_ReleaseModuleStandby_PWMD()   	R_STB_ReleaseModuleStandby( &rMSR_PWMD.UINT32 )
#define	R_STB_ReleaseModuleStandby_RIIC()   	R_STB_ReleaseModuleStandby( &rMSR_RIIC.UINT32 )
#define	R_STB_ReleaseModuleStandby_SFMA()   	R_STB_ReleaseModuleStandby( &rMSR_SFMA.UINT32 )
#define	R_STB_ReleaseModuleStandby_TAPA()   	R_STB_ReleaseModuleStandby( &rMSR_TAPA.UINT32 )
#define	R_STB_ReleaseModuleStandby_TAUD()   	R_STB_ReleaseModuleStandby( &rMSR_TAUD.UINT32 )
#define	R_STB_ReleaseModuleStandby_TAUJ_ISO()	R_STB_ReleaseModuleStandby( &rMSR_TAUJ_ISO.UINT32 )
#define	R_STB_ReleaseModuleStandby_OSTM()   	R_STB_ReleaseModuleStandby( &rMSR_OSTM.UINT32 )
#define	R_STB_ReleaseModuleStandby_CANXL()  	R_STB_ReleaseModuleStandby( &rMSR_CANXL.UINT32 )
#define	R_STB_ReleaseModuleStandby_RI3C()   	R_STB_ReleaseModuleStandby( &rMSR_RI3C.UINT32 )
#define	R_STB_ReleaseModuleStandby_SSIF()   	R_STB_ReleaseModuleStandby( &rMSR_SSIF.UINT32 )
#define	R_STB_ReleaseModuleStandby_ADCK_AWO()	R_STB_ReleaseModuleStandby( &rMSR_ADCK_AWO.UINT32 ); \
       	                                     	{uint32_t dumm_read = rADCK0VCR0_STB;}
#define	R_STB_ReleaseModuleStandby_RTCA()   	R_STB_ReleaseModuleStandby( &rMSR_RTCA.UINT32 )
#define	R_STB_ReleaseModuleStandby_WDTB_AWO()	R_STB_ReleaseModuleStandby( &rMSR_WDTB_AWO.UINT32 )

/*******************************************************************************
* Description  : Set module standby for each module
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define	R_STB_SetModuleStandby_RSCFD()   	R_STB_SetModuleStandby( &rMSR_RSCFD.UINT32 )
#define	R_STB_SetModuleStandby_ETND()    	R_STB_SetModuleStandby( &rMSR_ETND.UINT32 )
#define	R_STB_SetModuleStandby_ETNF()    	R_STB_SetModuleStandby( &rMSR_ETNF.UINT32 )
#define	R_STB_SetModuleStandby_RSENT()   	R_STB_SetModuleStandby( &rMSR_RSENT.UINT32 )
#define	R_STB_SetModuleStandby_CSIH()    	R_STB_SetModuleStandby( &rMSR_CSIH.UINT32 )
#define	R_STB_SetModuleStandby_RLIN3()   	R_STB_SetModuleStandby( &rMSR_RLIN3.UINT32 )
#define	R_STB_SetModuleStandby_ADCK_ISO()	R_STB_SetModuleStandby( &rMSR_ADCK_ISO.UINT32 )
#define	R_STB_SetModuleStandby_CXPI()   	R_STB_SetModuleStandby( &rMSR_CXPI.UINT32 )
#define	R_STB_SetModuleStandby_MMCA()   	R_STB_SetModuleStandby( &rMSR_MMCA.UINT32 )
#define	R_STB_SetModuleStandby_ENCA()   	R_STB_SetModuleStandby( &rMSR_ENCA.UINT32 )
#define	R_STB_SetModuleStandby_PSI5()   	R_STB_SetModuleStandby( &rMSR_PSI5.UINT32 )
#define	R_STB_SetModuleStandby_PWMD()   	R_STB_SetModuleStandby( &rMSR_PWMD.UINT32 )
#define	R_STB_SetModuleStandby_RIIC()   	R_STB_SetModuleStandby( &rMSR_RIIC.UINT32 )
#define	R_STB_SetModuleStandby_SFMA()   	R_STB_SetModuleStandby( &rMSR_SFMA.UINT32 )
#define	R_STB_SetModuleStandby_TAPA()   	R_STB_SetModuleStandby( &rMSR_TAPA.UINT32 )
#define	R_STB_SetModuleStandby_TAUD()   	R_STB_SetModuleStandby( &rMSR_TAUD.UINT32 )
#define	R_STB_SetModuleStandby_TAUJ_ISO()	R_STB_SetModuleStandby( &rMSR_TAUJ_ISO.UINT32 )
#define	R_STB_SetModuleStandby_OSTM()   	R_STB_SetModuleStandby( &rMSR_OSTM.UINT32 )
#define	R_STB_SetModuleStandby_CANXL()  	R_STB_SetModuleStandby( &rMSR_CANXL.UINT32 )
#define	R_STB_SetModuleStandby_RI3C()   	R_STB_SetModuleStandby( &rMSR_RI3C.UINT32 )
#define	R_STB_SetModuleStandby_SSIF()   	R_STB_SetModuleStandby( &rMSR_SSIF.UINT32 )
#define	R_STB_SetModuleStandby_ADCK_AWO()	R_STB_SetModuleStandby( &rMSR_ADCK_AWO.UINT32 )
#define	R_STB_SetModuleStandby_RTCA()   	R_STB_SetModuleStandby( &rMSR_RTCA.UINT32 )
#define	R_STB_SetModuleStandby_WDTB_AWO()	R_STB_SetModuleStandby( &rMSR_WDTB_AWO.UINT32 )

/*******************************************************************************
* Description  : Transitions to 1chip DeepSTOP Mode
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void R_STB_EnterDeepStopMode( void );

/*******************************************************************************
* Description  : Transitions to Cyclic RUN mode via DeepSTOP mode using IRQ0
* Arguments    : (none)
* Return Value : (none)
* Remarkabke   : need to execute function STB_TransitCyclicRun_clear to reset 
*                IRQ0 wakeup factor and set wakeup mask.
*******************************************************************************/
void R_STB_TransitCyclicRun( void );

/*******************************************************************************
* Description  : Transitions to RUN mode via DeepSTOP mode using IRQ0
* Arguments    : (none)
* Return Value : (none)
* Remarkabke   : need to execute function STB_TransitCyclicRun_clear to reset 
*                IRQ0 wakeup factor and set wakeup mask.
*******************************************************************************/
void R_STB_TransitRun( void );

/*******************************************************************************
* Description  : Initialize the resource used R_STB_TransitCyclicRun function.
*                need to perform post processing of function
*                 R_STB_TransitCyclicRun function.
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void R_STB_TransitCyclicRun_clear( void );

/*******************************************************************************
* Description  : Initialize the resource used R_STB_TransitRun function.
*                need to perform post processing of function
*                 R_STB_TransitRun function.
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void R_STB_TransitRun_clear( void );

/*******************************************************************************
* Description  : Get bit position of WUF register from STB_e_WUF value
* Arguments    : STB_e_WUF wuf: register number and bit position information of 
*                               wakeup factor
* Return Value : bit number of WUF register
*******************************************************************************/
#define	R_STB_GetWUFbit(wuf)	(wuf & 0x00FF)

/*******************************************************************************
* Description  : Get register number of WUF register from STB_e_WUF value
* Arguments    : STB_e_WUF wuf: register number and bit position information of 
*                               wakeup factor
* Return Value : register number of WUF register (STB_e_WUF_reg_A0, STB_e_WUF_reg_A1)
*******************************************************************************/
#define	R_STB_GetWUFReg(wuf)	(wuf >> 8)

/*******************************************************************************
* Description  : Enable wakeup factor
* Arguments    : STB_e_WUF      wuf : register number and bit position information
*                                     of wakeup factor 
*                STB_e_WUF_type kind: kind of wakeup (wakeup to RUN mode or
*                                     wakeup to Cyclic RUN mode)
* Return Value : 0     : Register readback check was successful
*                others: The failure count of register readback check
*******************************************************************************/
uint8_t R_STB_EnableWakeupFactor( STB_e_WUF wuf, STB_e_WUF_type kind );

/*******************************************************************************
* Description  : Disable wakeup factor
* Arguments    : STB_e_WUF      wuf : register number and bit position information
*                                     of wakeup factor 
*                STB_e_WUF_type kind: kind of wakeup (wakeup to RUN mode or
*                                     wakeup to Cyclic RUN mode)
* Return Value : 0     : Register readback check was successful
*                others: The failure count of register readback check
*******************************************************************************/
uint8_t R_STB_DisableWakeupFactor( STB_e_WUF wuf, STB_e_WUF_type kind );

/*******************************************************************************
* Description  : Disable all wakeup factors
* Arguments    : STB_e_WUF_type kind: kind of wakeup (wakeup to RUN mode or
*                                     wakeup to Cyclic RUN mode)
* Return Value : 0     : Register readback check was successful
*                others: The failure count of register readback check
*******************************************************************************/
uint8_t R_STB_DisableWakeupFactor_All( STB_e_WUF_type kind );

/*******************************************************************************
* Description  : Clear wakeup flag
* Arguments    : STB_e_WUF wuf : register number and bit position information
*                                of wakeup factor 
* Return Value : none
*******************************************************************************/
void R_STB_ClearWakeupFlag( STB_e_WUF wuf );

/*******************************************************************************
* Description  : Clear all wakeup flag
* Arguments    : none
* Return Value : none
* Remark       : In U5L product, wakeup flag registers do not separate with
*                for RUN mode and Cyclic RUN mode (WUF0_Ax, WUF1_Ax).
* Example      :
*	// clear wakeup flag of NMI
*	R_STB_ClearWakeupFlag( STB_e_WUF_NMI );
*	// clear wakeup flag of WUTRG0
*	R_STB_ClearWakeupFlag( STB_e_WUF_WUTRG0 );
*******************************************************************************/
#define	R_STB_ClearWakeupFlag_All()	rWUFC_A0.UINT32 = 0xFFFFFFFF; \
       	                           	rWUFC_A1.UINT32 = 0xFFFFFFFF;

/*******************************************************************************
* Description  : Releases I/O hold of Pn port
* Arguments    : uint8_t n: number of port group
* Return Value : 0     : Register readback check was successful
*                others: The failure count of register readback check
*******************************************************************************/
#define	R_STB_ReleaseIOHOLD_Pn(n)	R_STB_ReleaseWriteProtect(); \
                                 	Reg32ClearBitCheck( &rIOHOLD0.UINT32, n ); \
                                 	R_STB_SetWriteProtect()

/*******************************************************************************
* Description  : Releases I/O hold of APn port
* Arguments    : uint8_t n: number of AP port group
* Return Value : 0     : Register readback check was successful
*                others: The failure count of register readback check
*******************************************************************************/
#define	R_STB_ReleaseIOHOLD_APn(n)	R_STB_ReleaseWriteProtect(); \
                                  	Reg32ClearBitCheck( &rIOHOLD2.UINT32, n ); \
                                  	R_STB_SetWriteProtect()

/*******************************************************************************
* Description  : Releases I/O hold of all port
* Arguments    : none
* Return Value : 0     : Register readback check was successful
*                others: The failure count of register readback check
*******************************************************************************/
uint8_t R_STB_ReleaseIOHOLD_All( void );


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_standby_H__ */
