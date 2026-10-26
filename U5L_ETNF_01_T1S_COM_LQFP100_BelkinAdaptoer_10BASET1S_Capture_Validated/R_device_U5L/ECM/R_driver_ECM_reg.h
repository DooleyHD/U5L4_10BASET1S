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
* File Name    : R_driver_ECM_reg.h
* Version      : 1.00
* Device(s)    : ECM
* Description  : This is source file for ECM driver.
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_ECM_reg_H__
#define	__R_driver_ECM_reg_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"



/*******************************************************************************
* Register Base Address Definitions
*******************************************************************************/
#define ECM00_inst_0_BASE 	0x5C3CD000UL
#define ECMM00_inst_0_BASE	0x5C3CE000UL
#define	ECMM_base	ECMM00_inst_0_BASE
#define	ECM_base 	ECM00_inst_0_BASE


/*******************************************************************************
* Definition of register symbol
*******************************************************************************/
#define	rECMMESET        	(*(volatile ECM_s_ECMMESET    *) (ECMM_base + 0x000) )                    	/* ECM error set trigger register */
#define	rECMMECLR        	(*(volatile ECM_s_ECMMECLR    *) (ECMM_base + 0x004) )                    	/* ECM error clear trigger register */
#define	rECMMESSTRj(j)   	(*(volatile ECM_s_ECMMESSTRj  *) (ECMM_base + 0x048 + (j)*0x4) )          	/* ECM error source status register */
#define	rECMEPCFG        	(*(volatile ECM_s_ECMEPCFG    *) (ECM_base + 0x000) )                     	/* ECM error pulse configuration register */
#define	rECMISCFGj(j)    	(*(volatile ECM_s_ECMISCFGj   *) (ECM_base + 0x004 + (j)*0x4) )           	/* ECM interrupt type selection configuration register j */
#define	rECMINCFGi_j(i,j)	(*(volatile ECM_s_ECMINCFGi_j *) (ECM_base + 0x040 + (i)*0x3C + (j)*0x4) )	/* ECM interrupt notification configuration register i_j */
#define	rECMIRCFGj(j)    	(*(volatile ECM_s_ECMIRCFGj   *) (ECM_base + 0x220 + (j)*0x4) )           	/* ECM internal reset configuration register j */
#define	rECMEMKj(j)      	(*(volatile ECM_s_ECMEMKj     *) (ECM_base + 0x25C + (j)*0x4) )           	/* ECM error mask register j */
#define	rECMESSTCj(j)    	(*(volatile ECM_s_ECMESSTCj   *) (ECM_base + 0x478 + (j)*0x4) )           	/* ECM error source status clear trigger register j */
#define	rECMKCPROT       	(*(volatile ECM_s_ECMKCPROT   *) (ECM_base + 0x4B4) )                     	/* ECM key code protection register */
#define	rECMPEj(j)       	(*(volatile ECM_s_ECMPEj      *) (ECM_base + 0x4B8 + (j)*0x4) )           	/* ECM pseudo error trigger register j */
#define	rECMDTMCTL       	(*(volatile ECM_s_ECMDTMCTL   *) (ECM_base + 0x4F4) )                     	/* ECM delay timer control register */
#define	rECMDTMR         	(*(volatile ECM_s_ECMDTMR     *) (ECM_base + 0x4F8) )                     	/* ECM delay timer register */
#define	rECMDTMCMP       	(*(volatile ECM_s_ECMDTMCMP   *) (ECM_base + 0x4FC) )                     	/* ECM delay timer compare register */
#define	rECMDTMCFGj(j)   	(*(volatile ECM_s_ECMDTMCFGj  *) (ECM_base + 0x500 + (j)*0x4) )           	/* ECM delay timer configuration register j */
#define	rECMEOCCFG       	(*(volatile ECM_s_ECMEOCCFG   *) (ECM_base + 0x71C) )                     	/* ECM error output clear invalidation configuration register */
#define	rECMDIAG         	(*(volatile ECM_s_ECMDIAG     *) (ECM_base + 0x744) )                     	/* ECM Self-Diagnosis Test Register */
#define	rECMINTM         	(*(volatile ECM_s_ECMINTM     *) (ECM_base + 0x748) )                     	/* ECM Interrupt Monitor Register */
#define	rECMRESM         	(*(volatile ECM_s_ECMRESM     *) (ECM_base + 0x74C) )                     	/* ECM Reset Monitor Register */
#define	rECMDTTM         	(*(volatile ECM_s_ECMDTTM     *) (ECM_base + 0x750) )                     	/* ECM Delay Timer Trigger Monitor Register */


/*******************************************************************************
* Definition of Register bit value
*******************************************************************************/
/* ECMMESSTRj.SSE: Error source status bit */
typedef enum{
	ECM_e_SSE_not_error = 0,	/* 0: Error not occurred */
	ECM_e_SSE_error     = 1 	/* 1: Error occurred */
}ECM_e_SSE;

/* ECMEPCFG.SL: Error pin operation configuration bit */
typedef enum{
	ECM_e_SL_non_dynamic_mode = 0,	/* 0: Non-dynamic mode */
	ECM_e_SL_dynamic_mode     = 1 	/* 1: Dynamic mode*1 */
}ECM_e_SL;

/* ECMISCFGj.IS: Generation type of ECM maskable interupt selection bit */
typedef enum{
	ECM_e_IS_interrupt_2 = 0,	/* 0: ECM0 maskable interrupt 2 */
	ECM_e_IS_interrupt_1 = 1 	/* 1: ECM0 maskable interrupt 1 */
}ECM_e_IS;

/* ECMINCFGi_j.IE: ECM interrupt notification control bit */
typedef enum{
	ECM_e_IE_disable = 0,	/* 0: Interrupt generation disabled */
	ECM_e_IE_enable  = 1 	/* 1: Interrupt generation enabled */
}ECM_e_IE;

/* ECMIRCFGj.IRE: ECM internal reset generation control bit */
typedef enum{
	ECM_e_IRE_disable = 0,	/* 0: ECM0 internal reset generation disabled */
	ECM_e_IRE_enable  = 1 	/* 1: ECM0 internal reset generation enabled */
}ECM_e_IRE;

/* ECMEMKj.EMK: ECM error output signal mask control bit */
typedef enum{
	ECM_e_EMK_no_mask = 0,	/* 0: Error output is not masked */
	ECM_e_EMK_mask    = 1 	/* 1: Error output is masked */
}ECM_e_EMK;

/* ECMKCPROT: Enable/Disables write access of protected registers */
typedef enum{
	ECM_e_KCPROT_write_disable = 0xA5A5A500,	/* e write access to protected registers */
	ECM_e_KCPROT_write_enable  = 0xA5A5A501 	/*  */
}ECM_e_KCPROT;

/* ECMKCPROT.KCE: Key Code Enable bit */
typedef enum{
	ECM_e_KCE_write_disable = 0,	/* 0: Disable write access to protected registers */
	ECM_e_KCE_write_enable  = 1 	/* 1: Enable write access to protected registers */
}ECM_e_KCE;

/* ECMPEj.PE: ECM pseudo error trigger bit */
typedef enum{
	ECM_e_PE_no_assert_error = 0,	/* 0: Pseudo error is not generated. */
	ECM_e_PE_assert_error    = 1 	/* 1: Pseudo error is generated. */
}ECM_e_PE;

/* ECMDTMCTL.DTMSTACNTCLK: Delay timer start confirmation status. */
typedef enum{
	ECM_e_DTMSTACNTCLK_not_start = 0,	/* 0: Delay timer does not start */
	ECM_e_DTMSTACNTCLK_start     = 1 	/* 1: Delay timer starts. */
}ECM_e_DTMSTACNTCLK;

/* ECMDTMCTL.DTMSTP: Delay timer stop bit */
typedef enum{
	ECM_e_DTMSTP_no_assert_stop = 0,	/* 0: Delay timer is completed or stop request is not in progress. */
	ECM_e_DTMSTP_assert_stop    = 1 	/* 1: Stop request for delay timer is in progress. */
}ECM_e_DTMSTP;

/* ECMDTMCTL.DTMSTA: Delay timer start bit */
typedef enum{
	ECM_e_DTMSTA_stop  = 0,	/* 0: Delay timer does not start */
	ECM_e_DTMSTA_start = 1 	/* 1: Delay timer starts */
}ECM_e_DTMSTA;


/* ECMDTMCMP.CMPW: Indicates whether a write to the counter clock region of ECM0DTMCMP register setting is in progress */
/* ECMEOCCFG.CMPW: Indicates on execution of ECM0EOUTCLRT[23:0] register setting to counter clock domain */
typedef enum{
	ECM_e_CMPW_not_in_progress = 0,	/* 0: Not in progress */
	ECM_e_CMPW_in_progress     = 1 	/* 1: In progress. While the bit is set, further setting to ECM0DTMCMP is prohibited. */
}ECM_e_CMPW;

/* ECMDTMCFGj.DTME: ECM delay timer start control bit */
typedef enum{
	ECM_e_DTME_disable = 0,	/* 0: Delay timer start disabled */
	ECM_e_DTME_enable  = 1 	/* 1: Delay timer start enabled */
}ECM_e_DTME;


/* ECMEOCCFG.EOCIEN: Error Output Clear Invalidation Function Enabled */
typedef enum{
	ECM_e_EOCIEN_disable = 0,	/* 0: Disabled */
	ECM_e_EOCIEN_enable  = 1 	/* 1: Enabled */
}ECM_e_EOCIEN;

/* ECMTEST.ECM0TESTEN: ECM0 Test mode enable/disable */
typedef enum{
	ECM_e_ECM0TESTEN_disable = 1,	/* 1: Test mode enabled */
	ECM_e_ECM0TESTEN_enable  = 0 	/* 0: Test mode disabled */
}ECM_e_ECM0TESTEN;

/* ECMINTM.INTSTAT2: ECM0 interrupt 1 (CPU0) flag */
typedef enum{
	ECM_e_INTSTAT2_not_occured = 0,	/* 0: No Interruption from the ECM0 occurred. */
	ECM_e_INTSTAT2_occured     = 1 	/* 1: Interruption from the ECM0 occurred. */
}ECM_e_INTSTAT2;

/* ECMINTM.INTSTAT1: ECM0 interrupt 2 (CPU0) flag */
typedef enum{
	ECM_e_INTSTAT1_not_occured = 0,	/* 0: No Interruption from the ECM0 occurred. */
	ECM_e_INTSTAT1_occured     = 1 	/* 1: Interruption from the ECM0 occurred. */
}ECM_e_INTSTAT1;

/* ECMRESM.RESSTAT: Internal Reset flag */
typedef enum{
	ECM_e_RESSTAT_not_occured = 0,	/* 0: No Reset occurred. */
	ECM_e_RESSTAT_occured     = 1 	/* 1: Reset occurred. */
}ECM_e_RESSTAT;

/* ECMDTTM.DTM0: Delay Timer Trigger flag */
typedef enum{
	ECM_e_DTM0_not_occured = 0,	/* 0: No Trigger occurred. */
	ECM_e_DTM0_occured     = 1 	/* 1: Trigger occurred. */
}ECM_e_DTM0;


/*******************************************************************************
* Definition of Register typedef
*******************************************************************************/
/* ECMMESET register */
typedef union{
		uint32_t          	UINT32;
	struct{
		uint32_t          	EST         	:1;
		uint32_t          	Reserved_1  	:31;
	}BIT;
}ECM_s_ECMMESET;

/* ECMMECLR register */
typedef union{
		uint32_t          	UINT32;
	struct{
		uint32_t          	ECT         	:1;
		uint32_t          	Reserved_1  	:31;
	}BIT;
}ECM_s_ECMMECLR;

/* ECMMESSTRj register */
typedef union{
		uint32_t          	UINT32;
	struct{
		ECM_e_SSE         	SSEj_0      	:1;
		ECM_e_SSE         	SSEj_1      	:1;
		ECM_e_SSE         	SSEj_2      	:1;
		ECM_e_SSE         	SSEj_3      	:1;
		ECM_e_SSE         	SSEj_4      	:1;
		ECM_e_SSE         	SSEj_5      	:1;
		ECM_e_SSE         	SSEj_6      	:1;
		ECM_e_SSE         	SSEj_7      	:1;
		ECM_e_SSE         	SSEj_8      	:1;
		ECM_e_SSE         	SSEj_9      	:1;
		ECM_e_SSE         	SSEj_10     	:1;
		ECM_e_SSE         	SSEj_11     	:1;
		ECM_e_SSE         	SSEj_12     	:1;
		ECM_e_SSE         	SSEj_13     	:1;
		ECM_e_SSE         	SSEj_14     	:1;
		ECM_e_SSE         	SSEj_15     	:1;
		ECM_e_SSE         	SSEj_16     	:1;
		ECM_e_SSE         	SSEj_17     	:1;
		ECM_e_SSE         	SSEj_18     	:1;
		ECM_e_SSE         	SSEj_19     	:1;
		ECM_e_SSE         	SSEj_20     	:1;
		ECM_e_SSE         	SSEj_21     	:1;
		ECM_e_SSE         	SSEj_22     	:1;
		ECM_e_SSE         	SSEj_23     	:1;
		ECM_e_SSE         	SSEj_24     	:1;
		ECM_e_SSE         	SSEj_25     	:1;
		ECM_e_SSE         	SSEj_26     	:1;
		ECM_e_SSE         	SSEj_27     	:1;
		ECM_e_SSE         	SSEj_28     	:1;
		ECM_e_SSE         	SSEj_29     	:1;
		ECM_e_SSE         	SSEj_30     	:1;
		ECM_e_SSE         	SSEj_31     	:1;
	}BIT;
}ECM_s_ECMMESSTRj;

/* ECMEPCFG register */
typedef union{
		uint32_t          	UINT32;
	struct{
		uint32_t          	SL0         	:1;
		uint32_t          	Reserved_1  	:31;
	}BIT;
}ECM_s_ECMEPCFG;

/* ECMISCFGj register */
typedef union{
		uint32_t          	UINT32;
	struct{
		ECM_e_IS          	ISj_0       	:1;
		ECM_e_IS          	ISj_1       	:1;
		ECM_e_IS          	ISj_2       	:1;
		ECM_e_IS          	ISj_3       	:1;
		ECM_e_IS          	ISj_4       	:1;
		ECM_e_IS          	ISj_5       	:1;
		ECM_e_IS          	ISj_6       	:1;
		ECM_e_IS          	ISj_7       	:1;
		ECM_e_IS          	ISj_8       	:1;
		ECM_e_IS          	ISj_9       	:1;
		ECM_e_IS          	ISj_10      	:1;
		ECM_e_IS          	ISj_11      	:1;
		ECM_e_IS          	ISj_12      	:1;
		ECM_e_IS          	ISj_13      	:1;
		ECM_e_IS          	ISj_14      	:1;
		ECM_e_IS          	ISj_15      	:1;
		ECM_e_IS          	ISj_16      	:1;
		ECM_e_IS          	ISj_17      	:1;
		ECM_e_IS          	ISj_18      	:1;
		ECM_e_IS          	ISj_19      	:1;
		ECM_e_IS          	ISj_20      	:1;
		ECM_e_IS          	ISj_21      	:1;
		ECM_e_IS          	ISj_22      	:1;
		ECM_e_IS          	ISj_23      	:1;
		ECM_e_IS          	ISj_24      	:1;
		ECM_e_IS          	ISj_25      	:1;
		ECM_e_IS          	ISj_26      	:1;
		ECM_e_IS          	ISj_27      	:1;
		ECM_e_IS          	ISj_28      	:1;
		ECM_e_IS          	ISj_29      	:1;
		ECM_e_IS          	ISj_30      	:1;
		ECM_e_IS          	ISj_31      	:1;
	}BIT;
}ECM_s_ECMISCFGj;

/* ECMINCFGi_j register */
typedef union{
		uint32_t          	UINT32;
	struct{
		ECM_e_IE          	IEi_j_0     	:1;
		ECM_e_IE          	IEi_j_1     	:1;
		ECM_e_IE          	IEi_j_2     	:1;
		ECM_e_IE          	IEi_j_3     	:1;
		ECM_e_IE          	IEi_j_4     	:1;
		ECM_e_IE          	IEi_j_5     	:1;
		ECM_e_IE          	IEi_j_6     	:1;
		ECM_e_IE          	IEi_j_7     	:1;
		ECM_e_IE          	IEi_j_8     	:1;
		ECM_e_IE          	IEi_j_9     	:1;
		ECM_e_IE          	IEi_j_10    	:1;
		ECM_e_IE          	IEi_j_11    	:1;
		ECM_e_IE          	IEi_j_12    	:1;
		ECM_e_IE          	IEi_j_13    	:1;
		ECM_e_IE          	IEi_j_14    	:1;
		ECM_e_IE          	IEi_j_15    	:1;
		ECM_e_IE          	IEi_j_16    	:1;
		ECM_e_IE          	IEi_j_17    	:1;
		ECM_e_IE          	IEi_j_18    	:1;
		ECM_e_IE          	IEi_j_19    	:1;
		ECM_e_IE          	IEi_j_20    	:1;
		ECM_e_IE          	IEi_j_21    	:1;
		ECM_e_IE          	IEi_j_22    	:1;
		ECM_e_IE          	IEi_j_23    	:1;
		ECM_e_IE          	IEi_j_24    	:1;
		ECM_e_IE          	IEi_j_25    	:1;
		ECM_e_IE          	IEi_j_26    	:1;
		ECM_e_IE          	IEi_j_27    	:1;
		ECM_e_IE          	IEi_j_28    	:1;
		ECM_e_IE          	IEi_j_29    	:1;
		ECM_e_IE          	IEi_j_30    	:1;
		ECM_e_IE          	IEi_j_31    	:1;
	}BIT;
}ECM_s_ECMINCFGi_j;

/* ECMIRCFGj register */
typedef union{
		uint32_t          	UINT32;
	struct{
		ECM_e_IRE         	IREj_0      	:1;
		ECM_e_IRE         	IREj_1      	:1;
		ECM_e_IRE         	IREj_2      	:1;
		ECM_e_IRE         	IREj_3      	:1;
		ECM_e_IRE         	IREj_4      	:1;
		ECM_e_IRE         	IREj_5      	:1;
		ECM_e_IRE         	IREj_6      	:1;
		ECM_e_IRE         	IREj_7      	:1;
		ECM_e_IRE         	IREj_8      	:1;
		ECM_e_IRE         	IREj_9      	:1;
		ECM_e_IRE         	IREj_10     	:1;
		ECM_e_IRE         	IREj_11     	:1;
		ECM_e_IRE         	IREj_12     	:1;
		ECM_e_IRE         	IREj_13     	:1;
		ECM_e_IRE         	IREj_14     	:1;
		ECM_e_IRE         	IREj_15     	:1;
		ECM_e_IRE         	IREj_16     	:1;
		ECM_e_IRE         	IREj_17     	:1;
		ECM_e_IRE         	IREj_18     	:1;
		ECM_e_IRE         	IREj_19     	:1;
		ECM_e_IRE         	IREj_20     	:1;
		ECM_e_IRE         	IREj_21     	:1;
		ECM_e_IRE         	IREj_22     	:1;
		ECM_e_IRE         	IREj_23     	:1;
		ECM_e_IRE         	IREj_24     	:1;
		ECM_e_IRE         	IREj_25     	:1;
		ECM_e_IRE         	IREj_26     	:1;
		ECM_e_IRE         	IREj_27     	:1;
		ECM_e_IRE         	IREj_28     	:1;
		ECM_e_IRE         	IREj_29     	:1;
		ECM_e_IRE         	IREj_30     	:1;
		ECM_e_IRE         	IREj_31     	:1;
	}BIT;
}ECM_s_ECMIRCFGj;

/* ECMEMKj register */
typedef union{
		uint32_t          	UINT32;
	struct{
		ECM_e_EMK         	EMKj_0      	:1;
		ECM_e_EMK         	EMKj_1      	:1;
		ECM_e_EMK         	EMKj_2      	:1;
		ECM_e_EMK         	EMKj_3      	:1;
		ECM_e_EMK         	EMKj_4      	:1;
		ECM_e_EMK         	EMKj_5      	:1;
		ECM_e_EMK         	EMKj_6      	:1;
		ECM_e_EMK         	EMKj_7      	:1;
		ECM_e_EMK         	EMKj_8      	:1;
		ECM_e_EMK         	EMKj_9      	:1;
		ECM_e_EMK         	EMKj_10     	:1;
		ECM_e_EMK         	EMKj_11     	:1;
		ECM_e_EMK         	EMKj_12     	:1;
		ECM_e_EMK         	EMKj_13     	:1;
		ECM_e_EMK         	EMKj_14     	:1;
		ECM_e_EMK         	EMKj_15     	:1;
		ECM_e_EMK         	EMKj_16     	:1;
		ECM_e_EMK         	EMKj_17     	:1;
		ECM_e_EMK         	EMKj_18     	:1;
		ECM_e_EMK         	EMKj_19     	:1;
		ECM_e_EMK         	EMKj_20     	:1;
		ECM_e_EMK         	EMKj_21     	:1;
		ECM_e_EMK         	EMKj_22     	:1;
		ECM_e_EMK         	EMKj_23     	:1;
		ECM_e_EMK         	EMKj_24     	:1;
		ECM_e_EMK         	EMKj_25     	:1;
		ECM_e_EMK         	EMKj_26     	:1;
		ECM_e_EMK         	EMKj_27     	:1;
		ECM_e_EMK         	EMKj_28     	:1;
		ECM_e_EMK         	EMKj_29     	:1;
		ECM_e_EMK         	EMKj_30     	:1;
		ECM_e_EMK         	EMKj_31     	:1;
	}BIT;
}ECM_s_ECMEMKj;

/* ECMESSTCj register */
typedef union{
		uint32_t          	UINT32;
	struct{
		uint32_t          	CLSSEj_0    	:1;
		uint32_t          	CLSSEj_1    	:1;
		uint32_t          	CLSSEj_2    	:1;
		uint32_t          	CLSSEj_3    	:1;
		uint32_t          	CLSSEj_4    	:1;
		uint32_t          	CLSSEj_5    	:1;
		uint32_t          	CLSSEj_6    	:1;
		uint32_t          	CLSSEj_7    	:1;
		uint32_t          	CLSSEj_8    	:1;
		uint32_t          	CLSSEj_9    	:1;
		uint32_t          	CLSSEj_10   	:1;
		uint32_t          	CLSSEj_11   	:1;
		uint32_t          	CLSSEj_12   	:1;
		uint32_t          	CLSSEj_13   	:1;
		uint32_t          	CLSSEj_14   	:1;
		uint32_t          	CLSSEj_15   	:1;
		uint32_t          	CLSSEj_16   	:1;
		uint32_t          	CLSSEj_17   	:1;
		uint32_t          	CLSSEj_18   	:1;
		uint32_t          	CLSSEj_19   	:1;
		uint32_t          	CLSSEj_20   	:1;
		uint32_t          	CLSSEj_21   	:1;
		uint32_t          	CLSSEj_22   	:1;
		uint32_t          	CLSSEj_23   	:1;
		uint32_t          	CLSSEj_24   	:1;
		uint32_t          	CLSSEj_25   	:1;
		uint32_t          	CLSSEj_26   	:1;
		uint32_t          	CLSSEj_27   	:1;
		uint32_t          	CLSSEj_28   	:1;
		uint32_t          	CLSSEj_29   	:1;
		uint32_t          	CLSSEj_30   	:1;
		uint32_t          	CLSSEj_31   	:1;
	}BIT;
}ECM_s_ECMESSTCj;

/* ECMKCPROT register */
typedef union{
		uint32_t          	UINT32;
	struct{
		ECM_e_KCE         	KCE         	:1;
		uint32_t          	KCPROT      	:31;
	}BIT;
}ECM_s_ECMKCPROT;

/* ECMPEj register */
typedef union{
		uint32_t          	UINT32;
	struct{
		ECM_e_PE          	PEj_0       	:1;
		ECM_e_PE          	PEj_1       	:1;
		ECM_e_PE          	PEj_2       	:1;
		ECM_e_PE          	PEj_3       	:1;
		ECM_e_PE          	PEj_4       	:1;
		ECM_e_PE          	PEj_5       	:1;
		ECM_e_PE          	PEj_6       	:1;
		ECM_e_PE          	PEj_7       	:1;
		ECM_e_PE          	PEj_8       	:1;
		ECM_e_PE          	PEj_9       	:1;
		ECM_e_PE          	PEj_10      	:1;
		ECM_e_PE          	PEj_11      	:1;
		ECM_e_PE          	PEj_12      	:1;
		ECM_e_PE          	PEj_13      	:1;
		ECM_e_PE          	PEj_14      	:1;
		ECM_e_PE          	PEj_15      	:1;
		ECM_e_PE          	PEj_16      	:1;
		ECM_e_PE          	PEj_17      	:1;
		ECM_e_PE          	PEj_18      	:1;
		ECM_e_PE          	PEj_19      	:1;
		ECM_e_PE          	PEj_20      	:1;
		ECM_e_PE          	PEj_21      	:1;
		ECM_e_PE          	PEj_22      	:1;
		ECM_e_PE          	PEj_23      	:1;
		ECM_e_PE          	PEj_24      	:1;
		ECM_e_PE          	PEj_25      	:1;
		ECM_e_PE          	PEj_26      	:1;
		ECM_e_PE          	PEj_27      	:1;
		ECM_e_PE          	PEj_28      	:1;
		ECM_e_PE          	PEj_29      	:1;
		ECM_e_PE          	PEj_30      	:1;
		ECM_e_PE          	PEj_31      	:1;
	}BIT;
}ECM_s_ECMPEj;

/* ECMDTMCTL register */
typedef union{
		uint32_t          	UINT32;
	struct{
		ECM_e_DTMSTA      	DTMSTA      	:1;
		ECM_e_DTMSTP      	DTMSTP      	:1;
		uint32_t          	Reserved_2  	:2;
		ECM_e_DTMSTACNTCLK	DTMSTACNTCLK	:1;
		uint32_t          	Reserved_5  	:27;
	}BIT;
}ECM_s_ECMDTMCTL;

/* ECMDTMR register */
typedef union{
		uint32_t          	UINT32;
	struct{
		uint32_t          	DTMR        	:24;
		uint32_t          	Reserved_24 	:8;
	}BIT;
}ECM_s_ECMDTMR;

/* ECMDTMCMP register */
typedef union{
		uint32_t          	UINT32;
	struct{
		uint32_t          	DTMCMP      	:24;
		ECM_e_CMPW        	CMPW        	:1;
		uint32_t          	Reserved_25 	:7;
	}BIT;
}ECM_s_ECMDTMCMP;

/* ECMDTMCFGj register */
typedef union{
		uint32_t          	UINT32;
	struct{
		ECM_e_DTME        	DTMEj_0     	:1;
		ECM_e_DTME        	DTMEj_1     	:1;
		ECM_e_DTME        	DTMEj_2     	:1;
		ECM_e_DTME        	DTMEj_3     	:1;
		ECM_e_DTME        	DTMEj_4     	:1;
		ECM_e_DTME        	DTMEj_5     	:1;
		ECM_e_DTME        	DTMEj_6     	:1;
		ECM_e_DTME        	DTMEj_7     	:1;
		ECM_e_DTME        	DTMEj_8     	:1;
		ECM_e_DTME        	DTMEj_9     	:1;
		ECM_e_DTME        	DTMEj_10    	:1;
		ECM_e_DTME        	DTMEj_11    	:1;
		ECM_e_DTME        	DTMEj_12    	:1;
		ECM_e_DTME        	DTMEj_13    	:1;
		ECM_e_DTME        	DTMEj_14    	:1;
		ECM_e_DTME        	DTMEj_15    	:1;
		ECM_e_DTME        	DTMEj_16    	:1;
		ECM_e_DTME        	DTMEj_17    	:1;
		ECM_e_DTME        	DTMEj_18    	:1;
		ECM_e_DTME        	DTMEj_19    	:1;
		ECM_e_DTME        	DTMEj_20    	:1;
		ECM_e_DTME        	DTMEj_21    	:1;
		ECM_e_DTME        	DTMEj_22    	:1;
		ECM_e_DTME        	DTMEj_23    	:1;
		ECM_e_DTME        	DTMEj_24    	:1;
		ECM_e_DTME        	DTMEj_25    	:1;
		ECM_e_DTME        	DTMEj_26    	:1;
		ECM_e_DTME        	DTMEj_27    	:1;
		ECM_e_DTME        	DTMEj_28    	:1;
		ECM_e_DTME        	DTMEj_29    	:1;
		ECM_e_DTME        	DTMEj_30    	:1;
		ECM_e_DTME        	DTMEj_31    	:1;
	}BIT;
}ECM_s_ECMDTMCFGj;

/* ECMEOCCFG register */
typedef union{
		uint32_t          	UINT32;
	struct{
		uint32_t          	EOUTCLRT    	:24;
		ECM_e_CMPW        	CMPW        	:1;
		uint32_t          	Reserved_25 	:6;
		ECM_e_EOCIEN      	EOCIEN      	:1;
	}BIT;
}ECM_s_ECMEOCCFG;

/* ECMDIAG register */
typedef union{
		uint32_t          	UINT32;
	struct{
		uint32_t          	DIAGEN      	:1;
		uint32_t          	Reserved_1  	:31;
	}BIT;
}ECM_s_ECMDIAG;

/* ECMINTM register */
typedef union{
		uint32_t          	UINT32;
	struct{
		uint32_t          	Reserved_0  	:1;
		ECM_e_INTSTAT1    	INTSTAT1    	:1;
		ECM_e_INTSTAT2    	INTSTAT2    	:1;
		uint32_t          	Reserved_3  	:2;
		uint32_t          	Reserved_5  	:1;
		uint32_t          	Reserved_6  	:1;
		uint32_t          	Reserved_7  	:25;
	}BIT;
}ECM_s_ECMINTM;

/* ECMRESM register */
typedef union{
		uint32_t          	UINT32;
	struct{
		ECM_e_RESSTAT     	RESSTAT     	:1;
		uint32_t          	Reserved_1  	:31;
	}BIT;
}ECM_s_ECMRESM;

/* ECMDTTM register */
typedef union{
		uint32_t          	UINT32;
	struct{
		ECM_e_DTM0        	DTM0        	:1;
		uint32_t          	Reserved_1  	:1;
		uint32_t          	Reserved_2  	:1;
		uint32_t          	Reserved_3  	:29;
	}BIT;
}ECM_s_ECMDTTM;


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_ECM_reg_H__ */

