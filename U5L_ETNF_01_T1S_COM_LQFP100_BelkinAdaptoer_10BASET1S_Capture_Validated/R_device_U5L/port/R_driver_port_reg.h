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
* File Name    : R_driver_port_reg.h
* Version      : 1.00
* Module(s)    : PORT
* Device(s)    : R-Car U5L product
* Description  : Register definition of PORT function for R-Car U5L
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_port_reg_H__
#define	__R_driver_port_reg_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"


/*******************************************************************************
* Register Base Address Definitions
*******************************************************************************/
#define PORT_inst_0_BASE 	0x5C190000UL
#define JPORT_inst_0_BASE	0x5C1A0000UL
#define PORT_base 	PORT_inst_0_BASE
#define JPORT_base	JPORT_inst_0_BASE


/*******************************************************************************
* Definition of register symbol for PORT function
*******************************************************************************/
#define	rPn(n)       	(*(volatile PORT_s_Pn      *) (PORT_base + 0x0000 + 0x40*(n)) )           	/* Port register */
#define	rAPn(n)      	(*(volatile PORT_s_Pn      *) (PORT_base + 0x0C80 + 0x40*(n)) )           	/* Port register */
#define	rJPn(n)      	(*(volatile PORT_s_JPn     *) (JPORT_base + 0x0000 + 0x40*(n)) )          	/* Port register */
#define	rPSRn(n)     	(*(volatile PORT_s_PSRn    *) (PORT_base + 0x0004 + 0x40*(n)) )           	/* Port Set Reset register */
#define	rAPSRn(n)    	(*(volatile PORT_s_PSRn    *) (PORT_base + 0x0C84 + 0x40*(n)) )           	/* Port Set Reset register */
#define	rJPSRn(n)    	(*(volatile PORT_s_PSRn    *) (JPORT_base + 0x0004 + 0x40*(n)) )          	/* Port Set Reset register */
#define	rPNOTn(n)    	(*(volatile PORT_s_PNOTn   *) (PORT_base + 0x0008 + 0x40*(n)) )           	/* Port NOT register */
#define	rAPNOTn(n)   	(*(volatile PORT_s_PNOTn   *) (PORT_base + 0x0C88 + 0x40*(n)) )           	/* Port NOT register */
#define	rJPNOTn(n)   	(*(volatile PORT_s_JPNOTn  *) (JPORT_base + 0x0008 + 0x40*(n)) )          	/* Port NOT register */
#define	rPPRn(n)     	(*(volatile PORT_s_PPRn    *) (PORT_base + 0x000C + 0x40*(n)) )           	/* Port Pin Read register */
#define	rAPPRn(n)    	(*(volatile PORT_s_PPRn    *) (PORT_base + 0x0C8C + 0x40*(n)) )           	/* Port Pin Read register */
#define	rJPPRn(n)    	(*(volatile PORT_s_JPPRn   *) (JPORT_base + 0x000C + 0x40*(n)) )          	/* Port Pin Read register */
#define	rIPPRn(n)    	(*(volatile PORT_s_PPRn    *) (PORT_base + 0x070C) )                      	/* Port Pin Read register */
#define	rPMn(n)      	(*(volatile PORT_s_PMn     *) (PORT_base + 0x0010 + 0x40*(n)) )           	/* Port Mode register */
#define	rAPMn(n)     	(*(volatile PORT_s_PMn     *) (PORT_base + 0x0C90 + 0x40*(n)) )           	/* Port Mode register */
#define	rJPMn(n)     	(*(volatile PORT_s_JPMn    *) (JPORT_base + 0x0010 + 0x40*(n)) )          	/* Port Mode register */
#define	rPMCn(n)     	(*(volatile PORT_s_PMCn    *) (PORT_base + 0x0014 + 0x40*(n)) )           	/* Port Mode Control register */
#define	rJPMCn(n)    	(*(volatile PORT_s_JPMCn   *) (JPORT_base + 0x0014 + 0x40*(n)) )          	/* Port Mode Control register */
#define	rPFCn(n)     	(*(volatile PORT_s_PFCn    *) (PORT_base + 0x0018 + 0x40*(n)) )           	/* Port Function Control register */
#define	rJPFCn(n)    	(*(volatile PORT_s_JPFCn   *) (JPORT_base + 0x0018 + 0x40*(n)) )          	/* Port Function Control register */
#define	rPFCEn(n)    	(*(volatile PORT_s_PFCEn   *) (PORT_base + 0x001C + 0x40*(n)) )           	/* Port Function Control Expansion register */
#define	rJPFCEn(n)   	(*(volatile PORT_s_JPFCEn  *) (JPORT_base + 0x001C + 0x40*(n)) )          	/* Port Function Control Expansion register */
#define	rPMSRn(n)    	(*(volatile PORT_s_PMSRn   *) (PORT_base + 0x0020 + 0x40*(n)) )           	/* Port Mode Set Reset register */
#define	rAPMSRn(n)   	(*(volatile PORT_s_PMSRn   *) (PORT_base + 0x0CA0 + 0x40*(n)) )           	/* Port Mode Set Reset register */
#define	rJPMSRn(n)   	(*(volatile PORT_s_PMSRn   *) (JPORT_base + 0x0020 + 0x40*(n)) )          	/* Port Mode Set Reset register */
#define	rPMCSRn(n)   	(*(volatile PORT_s_PMCSRn  *) (PORT_base + 0x0024 + 0x40*(n)) )           	/* Port Mode Control Set Reset register */
#define	rJPMCSRn(n)  	(*(volatile PORT_s_PMCSRn  *) (JPORT_base + 0x0024 + 0x40*(n)) )          	/* Port Mode Control Set Reset register */
#define	rPFCAEn(n)   	(*(volatile PORT_s_PFCAEn  *) (PORT_base + 0x0028 + 0x40*(n)) )           	/* Port Function Control Additional Expansion register */
#define	rPFCEAEn(n)  	(*(volatile PORT_s_PFCEAEn *) (PORT_base + 0x002C + 0x40*(n)) )           	/* Port function control extra additional expansion register */
#define	rPINVn(n)    	(*(volatile PORT_s_PINVn   *) (PORT_base + 0x0030 + 0x40*(n)) )           	/* Port output value Inversion register */
#define	rAPINVn(n)   	(*(volatile PORT_s_PINVn   *) (PORT_base + 0x0CB0 + 0x40*(n)) )           	/* Port output value Inversion register */
#define	rJPINVn(n)   	(*(volatile PORT_s_JPINVn  *) (JPORT_base + 0x0030 + 0x40*(n)) )          	/* Port output value Inversion register */
#define	rPIBCn(n)    	(*(volatile PORT_s_PIBCn   *) (PORT_base + 0x4000 + 0x40*(n)) )           	/* Port Input Buffer Control register */
#define	rAPIBCn(n)   	(*(volatile PORT_s_PIBCn   *) (PORT_base + 0x4C80 + 0x40*(n)) )           	/* Port Input Buffer Control register */
#define	rJPIBCn(n)   	(*(volatile PORT_s_JPIBCn  *) (JPORT_base + 0x4000 + 0x40*(n)) )          	/* Port Input Buffer Control register */
#define	rIPIBCn(n)   	(*(volatile PORT_s_PIBCn   *) (PORT_base + 0x4700) )                      	/* Port Input Buffer Control register */
#define	rPBDCn(n)    	(*(volatile PORT_s_PBDCn   *) (PORT_base + 0x4004 + 0x40*(n)) )           	/* Port Bi-Direction Control register */
#define	rAPBDCn(n)   	(*(volatile PORT_s_PBDCn   *) (PORT_base + 0x4C84 + 0x40*(n)) )           	/* Port Bi-Direction Control register */
#define	rJPBDCn(n)   	(*(volatile PORT_s_JPBDCn  *) (JPORT_base + 0x4004 + 0x40*(n)) )          	/* Port Bi-Direction Control register */
#define	rPIPCn(n)    	(*(volatile PORT_s_PIPCn   *) (PORT_base + 0x4008 + 0x40*(n)) )           	/* Port IP Control register */
#define	rPUn(n)      	(*(volatile PORT_s_PUn     *) (PORT_base + 0x400C + 0x40*(n)) )           	/* Pull-Up option register */
#define	rJPUn(n)     	(*(volatile PORT_s_JPUn    *) (JPORT_base + 0x400C + 0x40*(n)) )          	/* Pull-Up option register */
#define	rPDn(n)      	(*(volatile PORT_s_PDn     *) (PORT_base + 0x4010 + 0x40*(n)) )           	/* Pull-Down option register */
#define	rJPDn(n)     	(*(volatile PORT_s_JPDn    *) (JPORT_base + 0x4010 + 0x40*(n)) )          	/* Pull-Down option register */
#define	rPODCn(n)    	(*(volatile PORT_s_PODCn   *) (PORT_base + 0x4014 + 0x40*(n)) )           	/* Port Open Drain Control register */
#define	rAPODCn(n)   	(*(volatile PORT_s_PODCn   *) (PORT_base + 0x4C94 + 0x40*(n)) )           	/* Port Open Drain Control register */
#define	rJPODCn(n)   	(*(volatile PORT_s_JPODCn  *) (JPORT_base + 0x4014 + 0x40*(n)) )          	/* Port Open Drain Control register */
#define	rPDSCn(n)    	(*(volatile PORT_s_PDSCn   *) (PORT_base + 0x4018 + 0x40*(n)) )           	/* Port Drive Strength Control register */
#define	rJPDSCn(n)   	(*(volatile PORT_s_JPDSCn  *) (JPORT_base + 0x4018 + 0x40*(n)) )          	/* Port Drive Strength Control register */
#define	rPISn(n)     	(*(volatile PORT_s_PISn    *) (PORT_base + 0x401C + 0x40*(n)) )           	/* Port Input buffer Selection register */
#define	rJPISn(n)    	(*(volatile PORT_s_JPISn   *) (JPORT_base + 0x401C + 0x40*(n)) )          	/* Port Input buffer Selection register */
#define	rPISAn(n)    	(*(volatile PORT_s_PISAn   *) (PORT_base + 0x4024 + 0x40*(n)) )           	/* Port Input buffer Selection Advanced register */
#define	rJPISAn(n)   	(*(volatile PORT_s_JPISAn  *) (JPORT_base + 0x4024 + 0x40*(n)) )          	/* Port Input buffer Selection Advanced register */
#define	rPODCEn(n)   	(*(volatile PORT_s_PODCEn  *) (PORT_base + 0x4038 + 0x40*(n)) )           	/* Port Open Drain Control Expansion register */
#define	rAPODCEn(n)  	(*(volatile PORT_s_PODCEn  *) (PORT_base + 0x4CB8 + 0x40*(n)) )           	/* Port Open Drain Control Expansion register */
#define	rJPODCEn(n)  	(*(volatile PORT_s_JPODCEn *) (JPORT_base + 0x4038 + 0x40*(n)) )          	/* Port Open Drain Control Expansion register */
#define	rPCRn_m(n,m) 	(*(volatile PORT_s_PCRn_m  *) (PORT_base + 0x2000 + 0x40*(n) + 0x4*(m)) ) 	/* Port Control register */
#define	rAPCRn_m(n,m)	(*(volatile PORT_s_PCRn_m  *) (PORT_base + 0x2C80 + 0x40*(n) + 0x4*(m)) ) 	/* Port Control register */
#define	rJPCRn_m(n,m)	(*(volatile PORT_s_PCRn_m  *) (JPORT_base + 0x2000 + 0x40*(n) + 0x4*(m)) )	/* Port Control register */
#define	rPKCPROT     	(*(volatile PORT_s_PKCPROT *) (PORT_base + 0x2F40) )                      	/* Port Keycode Protection Register */
#define	rPWE         	(*(volatile PORT_s_PWE     *) (PORT_base + 0x2F44) )                      	/* Port Write Enable register */


/*******************************************************************************
* Definition of register symbol for PORT Noise Filter & Edge/Level Detection
*******************************************************************************/
#define	rFCLACTL0_IRQ_0	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4A00) )	/* Filter Control Register for IRQ0 */
#define	rFCLACTL1_IRQ_0	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4A04) )	/* Filter Control Register for IRQ1 */
#define	rFCLACTL2_IRQ_0	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4A08) )	/* Filter Control Register for IRQ2 */
#define	rFCLACTL3_IRQ_0	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4A0C) )	/* Filter Control Register for IRQ3 */
#define	rFCLACTL4_IRQ_0	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4A10) )	/* Filter Control Register for IRQ4 */
#define	rFCLACTL5_IRQ_0	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4A14) )	/* Filter Control Register for IRQ5 */
#define	rFCLACTL6_IRQ_0	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4A18) )	/* Filter Control Register for IRQ6 */
#define	rFCLACTL7_IRQ_0	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4A1C) )	/* Filter Control Register for IRQ7 */
#define	rFCLACTL0_IRQ_1	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4B00) )	/* Filter Control Register for IRQ8 */
#define	rFCLACTL1_IRQ_1	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4B04) )	/* Filter Control Register for IRQ9 */
#define	rFCLACTL2_IRQ_1	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4B08) )	/* Filter Control Register for IRQ10 */
#define	rFCLACTL3_IRQ_1	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4B0C) )	/* Filter Control Register for IRQ11 */
#define	rFCLACTL4_IRQ_1	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4B10) )	/* Filter Control Register for IRQ12 */
#define	rFCLACTL5_IRQ_1	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4B14) )	/* Filter Control Register for IRQ13 */
#define	rFCLACTL6_IRQ_1	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4B18) )	/* Filter Control Register for IRQ14 */
#define	rFCLACTL7_IRQ_1	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4B1C) )	/* Filter Control Register for IRQ15 */
#define	rFCLACTL0_IRQ_2	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4C00) )	/* Filter Control Register for IRQ16 */
#define	rFCLACTL1_IRQ_2	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4C04) )	/* Filter Control Register for IRQ17 */
#define	rFCLACTL2_IRQ_2	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4C08) )	/* Filter Control Register for IRQ18 */
#define	rFCLACTL3_IRQ_2	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4C0C) )	/* Filter Control Register for IRQ19 */
#define	rFCLACTL4_IRQ_2	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4C10) )	/* Filter Control Register for IRQ20 */
#define	rFCLACTL5_IRQ_2	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4C14) )	/* Filter Control Register for IRQ21 */
#define	rFCLACTL6_IRQ_2	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4C18) )	/* Filter Control Register for IRQ22 */
#define	rFCLACTL7_IRQ_2	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4C1C) )	/* Filter Control Register for IRQ23 */
#define	rFCLACTL0_IRQ_3	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4D00) )	/* Filter Control Register for IRQ24 */
#define	rFCLACTL1_IRQ_3	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4D04) )	/* Filter Control Register for IRQ25 */
#define	rFCLACTL0_IRQ_5	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4F00) )	/* Filter Control Register for NMI */
#define	rFCLACTL0_TAPA	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4800) )	/* Filter Control Register for TAPA0ESO */

#define	rFCLACTL_IRQn(n)	(*(volatile PORT_s_FCLACTLm *) (0x5C2D4A00 + ((n) >> 3) * 0x100 + ((n) & 0x7)*4 ) )	/* Filter Control Register for IRQn */
#define	rFCLACTL_NMI    	rFCLACTL0_IRQ_5
#define	rFCLACTL_TAPA   	rFCLACTL0_TAPA


/*******************************************************************************
* Definition of Register bit value
*******************************************************************************/
/* Pn.Pn_m: Sets the output level of pin 15 */
typedef enum{
	PORT_e_P_low  = 0,	/* 0: Port pin drives low level */
	PORT_e_P_high = 1 	/* 1: Port pin drives high level */
}PORT_e_P;

/* PSRn.PSRn_m (bit 31:16): Specifies whether the value of the corresponding lower bit PSRn_m value is written to Pn_m. */
typedef enum{
	PORT_e_PSR_H_Pn_is_not_PSRn = 0,	/* 0: Pn_m is not affected by PSRn_m */
	PORT_e_PSR_H_Pn_is_PSRn     = 1 	/* 1: Pn_m is PSRn_m */
}PORT_e_PSR_H;

/* PSRn.PSRn_m (bit 15:0): Sets the output level of pin Pn_m. */
typedef enum{
	PORT_e_PSR_L_low  = 0,	/* 0: Low level is written on Pn_m when it is enabled by PSRn_31 */
	PORT_e_PSR_L_high = 1 	/* 1: High level is written on Pn_m when it is enabled by PSRn_31 */
}PORT_e_PSR_L;

/* PPRn.PPRn_m: This register reflects the actual pin level when the input buffer is active */
typedef enum{
	PORT_e_PPR_low  = 0,	/* 0: Port pin is at low level */
	PORT_e_PPR_high = 1 	/* 1: Port pin is at high level */
}PORT_e_PPR;

/* PMn.PMn_m: Specifies input/output mode of the corresponding pin. */
typedef enum{
	PORT_e_PM_output = 0,	/* 0: Output mode (output enabled) */
	PORT_e_PM_input  = 1 	/* 1: Input mode (output disabled) */
}PORT_e_PM;

/* PMCn.PMCn_m: Specifies the operation mode of the corresponding pin. */
typedef enum{
	PORT_e_PMC_port_mode = 0,	/* 0: Port mode */
	PORT_e_PMC_alt_mode  = 1 	/* 1: Alternative mode */
}PORT_e_PMC;

/* PFCn.PFCn_m: Selects the alternative peripheral functions */
typedef enum{
	PORT_e_PFC_0 = 0,	/* 0: 0 */
	PORT_e_PFC_1 = 1 	/* 1: 1 */
}PORT_e_PFC;

/* PFCEn.PFCEn_m: Selects the alternative peripheral functions */
typedef enum{
	PORT_e_PFCE_0 = 0,	/* 0: 0 */
	PORT_e_PFCE_1 = 1 	/* 1: 1 */
}PORT_e_PFCE;

/* PMSRn.PMSRn_m (bit 31:16): Specifies whether the value of the corresponding lower bit PMSRn_m value is written to PMn_m. */
typedef enum{
	PORT_e_PMSR_H_PMn_is_not_PMSRn = 0,	/* 0: PMn_m is not affected by PMSRn_m. */
	PORT_e_PMSR_H_PMn_is_PMSRn     = 1 	/* 1: PMn_m is PMSRn_m */
}PORT_e_PMSR_H;

/* PMSRn.PMSRn_m (bit 15:0): Data bits that specify the PMn_m value if the corresponding upper bit (PMSRn_[31:16]) PMSRn_m is 1. */
typedef enum{
	PORT_e_PMSR_L_output = 0,	/* 0: PMn_m = 0 */
	PORT_e_PMSR_L_input  = 1 	/* 1: PMn_m = 1 */
}PORT_e_PMSR_L;

/* PMCSR10.PMCSRn_m (bit 31:16): Specifies whether the value of the corresponding lower bit PMCSRn_m value is written to PMCn_m. */
typedef enum{
	PORT_e_PMCSR_H_PMCn_is_not_PMCSRn = 0,	/* 0: PMCn_m is not affected by PMCSRn_m */
	PORT_e_PMCSR_H_PMCn_is_PMCSRn     = 1 	/* 1: PMCn_m is PMCSRn_m */
}PORT_e_PMCSR_H;

/* PMCSR10.PMCSRn_m (bit 15:0): Data bits that specify the PMCn_m value if the corresponding upper bit (PMCSRn_[31:16]) PMCSRn_m is 1. */
typedef enum{
	PORT_e_PMCSR_L_port_mode = 0,	/* 0: PMCn_m = 0 */
	PORT_e_PMCSR_L_alt_mode  = 1 	/* 1: PMCn_m = 1 */
}PORT_e_PMCSR_L;

/* PFCAEn.PFCAEn_m: Selects the alternative peripheral functions */
typedef enum{
	PORT_e_PFCAE_0 = 0,	/* 0: 0 */
	PORT_e_PFCAE_1 = 1 	/* 1: 1 */
}PORT_e_PFCAE;

/* PFCEAEn.PFCEAEn_m: Selects the alternative peripheral functions */
typedef enum{
	PORT_e_PFCEAE_0 = 0,	/* 0: 0 */
	PORT_e_PFCEAE_1 = 1 	/* 1: 1 */
}PORT_e_PFCEAE;

/* PINVn.PINVn_m: This register inverts the output value of the port. */
typedef enum{
	PORT_e_PINV_not_invert = 0,	/* 0: No effect */
	PORT_e_PINV_invert     = 1 	/* 1: Inverted value is output */
}PORT_e_PINV;

/* PIBCn.PIBCn_m: Enables/disables the input buffer: */
typedef enum{
	PORT_e_PIBC_disable = 0,	/* 0: Input buffer is disabled. */
	PORT_e_PIBC_enable  = 1 	/* 1: Input buffer is enabled. */
}PORT_e_PIBC;

/* PBDCn.PBDCn_m: Enables/disables bi-direction mode of the corresponding pin. */
typedef enum{
	PORT_e_PBDC_disable = 0,	/* 0: Bi-direction mode disabled */
	PORT_e_PBDC_enable  = 1 	/* 1: Bi-direction mode enabled */
}PORT_e_PBDC;

/* PIPCn.PIPCn_m: Specifies the I/O control mode. */
typedef enum{
	PORT_e_PIPC_software_IO = 0,	/* 0: I/O mode is selected by PMn.PMn_m (software I/O control). */
	PORT_e_PIPC_direct_IO   = 1 	/* 1: I/O mode is selected by the peripheral function (direct I/O control). */
}PORT_e_PIPC;

/* PUn.PUn_m: Specifies whether a pull-up resistor is connected to the corresponding pin. */
typedef enum{
	PORT_e_PU_disable = 0,	/* 0: No pull-up resistor connected */
	PORT_e_PU_enable  = 1 	/* 1: Pull-up resistor connected */
}PORT_e_PU;

/* PDn.PDn_m: Specifies whether to connect an internal pull-down resistor to the corresponding pin: */
typedef enum{
	PORT_e_PD_disable = 0,	/* 0: No internal pull-down resistor connected */
	PORT_e_PD_enable  = 1 	/* 1: An internal pull-down resistor connected */
}PORT_e_PD;

/* PODCn.PODCn_m: Specifies the output buffer function. */
typedef enum{
	PORT_e_PODC_push_pull  = 0,	/* 0: Push-pull */
	PORT_e_PODC_open_drain = 1 	/* 1: Open-drain */
}PORT_e_PODC;

/* PDSCn.PDSCn_m: Specifies the output buffer drive strength */
typedef enum{
	PORT_e_PDSC_0 = 0,	/* 0: 0 */
	PORT_e_PDSC_1 = 1 	/* 1: 1 */
}PORT_e_PDSC;

/* PISn.PISn_m: Specifies the input buffer characteristics */
typedef enum{
	PORT_e_PIS_0 = 0,	/* 0: 0 */
	PORT_e_PIS_1 = 1 	/* 1: 1 */
}PORT_e_PIS;

/* PISAn.PISAn_m: Specifies the input buffer characteristics */
typedef enum{
	PORT_e_PISA_0 = 0,	/* 0: 0 */
	PORT_e_PISA_1 = 1 	/* 1: 1 */
}PORT_e_PISA;

/* PODCEn.PODCEn_m: Selects the emulated P-channel Open-drain together with PODCn. */
typedef enum{
	PORT_e_PODCE_0 = 0,	/* 0: 0 */
	PORT_e_PODCE_1 = 1 	/* 1: 1 */
}PORT_e_PODCE;

/* PKCPROT: Enable/Disables write access of protected registers */
typedef enum{
	PORT_e_PKCPROT_write_disable = 0xA5A5A500,	/* Disable write access to protected registers */
	PORT_e_PKCPROT_write_enable  = 0xA5A5A501 	/* Enable write access to protected registers */
}PORT_e_PKCPROT;

/* PKCPROT.PWEEn_m: Key Code Enable bit */
typedef enum{
	PORT_e_PWEE_write_disable = 0,	/* 0: Disable write access to protected registers */
	PORT_e_PWEE_write_enable  = 1 	/* 1: Enable write access to protected registers */
}PORT_e_PWEE;

/* PWE.PWExn_m: Port Write Enable for Pn or APn or IP0 */
typedef enum{
	PORT_e_PWEx_write_disable = 0,	/* 0: Disables write access */
	PORT_e_PWEx_write_enable  = 1 	/* 1: Enables write access */
}PORT_e_PWEx;

/* FCLACTLm.INTL, INTF, INTF (bit 2-0): Detection mode selection */
typedef enum{
	PORT_e_INTx_disable      = 0,	/* Disable edge detection */
	PORT_e_INTx_rising_edge  = 1,	/* Rising edge detection */
	PORT_e_INTx_falling_edge = 2,	/* Falling edge detection */
	PORT_e_INTx_both_edge    = 3,	/* Both rising and falling edge detection */
	PORT_e_INTx_low_level    = 4,	/* Low level detection */
	PORT_e_INTx_high_level   = 5 	/* High level detection */
}PORT_e_INTx;

/* FCLACTLm.BYPS (bit 7): Bypass mode selection */
typedef enum{
	PORT_e_BYPS_filter       = 0,	/* Select filter signal */
	PORT_e_BYPS_bypass       = 1 	/* Select filter-bypass signal */
}PORT_e_BYPS;


/*******************************************************************************
* Definition of Register typedef
*******************************************************************************/
/* Pn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_P      	Pn_0       	:1;
		PORT_e_P      	Pn_1       	:1;
		PORT_e_P      	Pn_2       	:1;
		PORT_e_P      	Pn_3       	:1;
		PORT_e_P      	Pn_4       	:1;
		PORT_e_P      	Pn_5       	:1;
		PORT_e_P      	Pn_6       	:1;
		PORT_e_P      	Pn_7       	:1;
		PORT_e_P      	Pn_8       	:1;
		PORT_e_P      	Pn_9       	:1;
		PORT_e_P      	Pn_10      	:1;
		PORT_e_P      	Pn_11      	:1;
		PORT_e_P      	Pn_12      	:1;
		PORT_e_P      	Pn_13      	:1;
		PORT_e_P      	Pn_14      	:1;
		PORT_e_P      	Pn_15      	:1;
	}BIT;			
}PORT_s_Pn;				
				
/* JPn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_P      	JPn_0      	:1;
		PORT_e_P      	JPn_1      	:1;
		PORT_e_P      	JPn_2      	:1;
		PORT_e_P      	JPn_3      	:1;
		PORT_e_P      	JPn_4      	:1;
		PORT_e_P      	JPn_5      	:1;
		PORT_e_P      	JPn_6      	:1;
		PORT_e_P      	JPn_7      	:1;
	}BIT;			
}PORT_s_JPn;				
				
/* PSRn register */				
typedef union{				
		uint32_t      	UINT32;	
	struct{			
		PORT_e_PSR_H  	PSRn_0     	:1;
		PORT_e_PSR_H  	PSRn_1     	:1;
		PORT_e_PSR_H  	PSRn_2     	:1;
		PORT_e_PSR_H  	PSRn_3     	:1;
		PORT_e_PSR_H  	PSRn_4     	:1;
		PORT_e_PSR_H  	PSRn_5     	:1;
		PORT_e_PSR_H  	PSRn_6     	:1;
		PORT_e_PSR_H  	PSRn_7     	:1;
		PORT_e_PSR_H  	PSRn_8     	:1;
		PORT_e_PSR_H  	PSRn_9     	:1;
		PORT_e_PSR_H  	PSRn_10    	:1;
		PORT_e_PSR_H  	PSRn_11    	:1;
		PORT_e_PSR_H  	PSRn_12    	:1;
		PORT_e_PSR_H  	PSRn_13    	:1;
		PORT_e_PSR_H  	PSRn_14    	:1;
		PORT_e_PSR_H  	PSRn_15    	:1;
		PORT_e_PSR_H  	PSRn_16    	:1;
		PORT_e_PSR_L  	PSRn_17    	:1;
		PORT_e_PSR_L  	PSRn_18    	:1;
		PORT_e_PSR_L  	PSRn_19    	:1;
		PORT_e_PSR_L  	PSRn_20    	:1;
		PORT_e_PSR_L  	PSRn_21    	:1;
		PORT_e_PSR_L  	PSRn_22    	:1;
		PORT_e_PSR_L  	PSRn_23    	:1;
		PORT_e_PSR_L  	PSRn_24    	:1;
		PORT_e_PSR_L  	PSRn_25    	:1;
		PORT_e_PSR_L  	PSRn_26    	:1;
		PORT_e_PSR_L  	PSRn_27    	:1;
		PORT_e_PSR_L  	PSRn_28    	:1;
		PORT_e_PSR_L  	PSRn_29    	:1;
		PORT_e_PSR_L  	PSRn_30    	:1;
		PORT_e_PSR_L  	PSRn_31    	:1;
	}BIT;			
}PORT_s_PSRn;				
				
/* PNOTn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		uint16_t      	PNOTn_0    	:1;
		uint16_t      	PNOTn_1    	:1;
		uint16_t      	PNOTn_2    	:1;
		uint16_t      	PNOTn_3    	:1;
		uint16_t      	PNOTn_4    	:1;
		uint16_t      	PNOTn_5    	:1;
		uint16_t      	PNOTn_6    	:1;
		uint16_t      	PNOTn_7    	:1;
		uint16_t      	PNOTn_8    	:1;
		uint16_t      	PNOTn_9    	:1;
		uint16_t      	PNOTn_10   	:1;
		uint16_t      	PNOTn_11   	:1;
		uint16_t      	PNOTn_12   	:1;
		uint16_t      	PNOTn_13   	:1;
		uint16_t      	PNOTn_14   	:1;
		uint16_t      	PNOTn_15   	:1;
	}BIT;			
}PORT_s_PNOTn;				
				
/* JPNOTn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		uint8_t       	JPNOTn_0   	:1;
		uint8_t       	JPNOTn_1   	:1;
		uint8_t       	JPNOTn_2   	:1;
		uint8_t       	JPNOTn_3   	:1;
		uint8_t       	JPNOTn_4   	:1;
		uint8_t       	JPNOTn_5   	:1;
		uint8_t       	JPNOTn_6   	:1;
		uint8_t       	JPNOTn_7   	:1;
	}BIT;			
}PORT_s_JPNOTn;				
				
/* PPRn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PPR    	PPRn_0     	:1;
		PORT_e_PPR    	PPRn_1     	:1;
		PORT_e_PPR    	PPRn_2     	:1;
		PORT_e_PPR    	PPRn_3     	:1;
		PORT_e_PPR    	PPRn_4     	:1;
		PORT_e_PPR    	PPRn_5     	:1;
		PORT_e_PPR    	PPRn_6     	:1;
		PORT_e_PPR    	PPRn_7     	:1;
		PORT_e_PPR    	PPRn_8     	:1;
		PORT_e_PPR    	PPRn_9     	:1;
		PORT_e_PPR    	PPRn_10    	:1;
		PORT_e_PPR    	PPRn_11    	:1;
		PORT_e_PPR    	PPRn_12    	:1;
		PORT_e_PPR    	PPRn_13    	:1;
		PORT_e_PPR    	PPRn_14    	:1;
		PORT_e_PPR    	PPRn_15    	:1;
	}BIT;			
}PORT_s_PPRn;				
				
/* JPPRn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PPR    	JPPRn_0    	:1;
		PORT_e_PPR    	JPPRn_1    	:1;
		PORT_e_PPR    	JPPRn_2    	:1;
		PORT_e_PPR    	JPPRn_3    	:1;
		PORT_e_PPR    	JPPRn_4    	:1;
		PORT_e_PPR    	JPPRn_5    	:1;
		PORT_e_PPR    	JPPRn_6    	:1;
		PORT_e_PPR    	JPPRn_7    	:1;
	}BIT;			
}PORT_s_JPPRn;				
				
/* PMn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PM     	PMn_0      	:1;
		PORT_e_PM     	PMn_1      	:1;
		PORT_e_PM     	PMn_2      	:1;
		PORT_e_PM     	PMn_3      	:1;
		PORT_e_PM     	PMn_4      	:1;
		PORT_e_PM     	PMn_5      	:1;
		PORT_e_PM     	PMn_6      	:1;
		PORT_e_PM     	PMn_7      	:1;
		PORT_e_PM     	PMn_8      	:1;
		PORT_e_PM     	PMn_9      	:1;
		PORT_e_PM     	PMn_10     	:1;
		PORT_e_PM     	PMn_11     	:1;
		PORT_e_PM     	PMn_12     	:1;
		PORT_e_PM     	PMn_13     	:1;
		PORT_e_PM     	PMn_14     	:1;
		PORT_e_PM     	PMn_15     	:1;
	}BIT;			
}PORT_s_PMn;				
				
/* JPMn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PM     	JPMn_0     	:1;
		PORT_e_PM     	JPMn_1     	:1;
		PORT_e_PM     	JPMn_2     	:1;
		PORT_e_PM     	JPMn_3     	:1;
		PORT_e_PM     	JPMn_4     	:1;
		PORT_e_PM     	JPMn_5     	:1;
		PORT_e_PM     	JPMn_6     	:1;
		PORT_e_PM     	JPMn_7     	:1;
	}BIT;			
}PORT_s_JPMn;				
				
/* PMCn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PMC    	PMCn_0     	:1;
		PORT_e_PMC    	PMCn_1     	:1;
		PORT_e_PMC    	PMCn_2     	:1;
		PORT_e_PMC    	PMCn_3     	:1;
		PORT_e_PMC    	PMCn_4     	:1;
		PORT_e_PMC    	PMCn_5     	:1;
		PORT_e_PMC    	PMCn_6     	:1;
		PORT_e_PMC    	PMCn_7     	:1;
		PORT_e_PMC    	PMCn_8     	:1;
		PORT_e_PMC    	PMCn_9     	:1;
		PORT_e_PMC    	PMCn_10    	:1;
		PORT_e_PMC    	PMCn_11    	:1;
		PORT_e_PMC    	PMCn_12    	:1;
		PORT_e_PMC    	PMCn_13    	:1;
		PORT_e_PMC    	PMCn_14    	:1;
		PORT_e_PMC    	PMCn_15    	:1;
	}BIT;			
}PORT_s_PMCn;				
				
/* JPMCn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PMC    	JPMCn_0    	:1;
		PORT_e_PMC    	JPMCn_1    	:1;
		PORT_e_PMC    	JPMCn_2    	:1;
		PORT_e_PMC    	JPMCn_3    	:1;
		PORT_e_PMC    	JPMCn_4    	:1;
		PORT_e_PMC    	JPMCn_5    	:1;
		PORT_e_PMC    	JPMCn_6    	:1;
		PORT_e_PMC    	JPMCn_7    	:1;
	}BIT;			
}PORT_s_JPMCn;				
				
/* PFCn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PFC    	PFCn_0     	:1;
		PORT_e_PFC    	PFCn_1     	:1;
		PORT_e_PFC    	PFCn_2     	:1;
		PORT_e_PFC    	PFCn_3     	:1;
		PORT_e_PFC    	PFCn_4     	:1;
		PORT_e_PFC    	PFCn_5     	:1;
		PORT_e_PFC    	PFCn_6     	:1;
		PORT_e_PFC    	PFCn_7     	:1;
		PORT_e_PFC    	PFCn_8     	:1;
		PORT_e_PFC    	PFCn_9     	:1;
		PORT_e_PFC    	PFCn_10    	:1;
		PORT_e_PFC    	PFCn_11    	:1;
		PORT_e_PFC    	PFCn_12    	:1;
		PORT_e_PFC    	PFCn_13    	:1;
		PORT_e_PFC    	PFCn_14    	:1;
		PORT_e_PFC    	PFCn_15    	:1;
	}BIT;			
}PORT_s_PFCn;				
				
/* JPFCn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PFC    	JPFCn_0    	:1;
		PORT_e_PFC    	JPFCn_1    	:1;
		PORT_e_PFC    	JPFCn_2    	:1;
		PORT_e_PFC    	JPFCn_3    	:1;
		PORT_e_PFC    	JPFCn_4    	:1;
		PORT_e_PFC    	JPFCn_5    	:1;
		PORT_e_PFC    	JPFCn_6    	:1;
		PORT_e_PFC    	JPFCn_7    	:1;
	}BIT;			
}PORT_s_JPFCn;				
				
/* PFCEn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PFCE   	PFCEn_0    	:1;
		PORT_e_PFCE   	PFCEn_1    	:1;
		PORT_e_PFCE   	PFCEn_2    	:1;
		PORT_e_PFCE   	PFCEn_3    	:1;
		PORT_e_PFCE   	PFCEn_4    	:1;
		PORT_e_PFCE   	PFCEn_5    	:1;
		PORT_e_PFCE   	PFCEn_6    	:1;
		PORT_e_PFCE   	PFCEn_7    	:1;
		PORT_e_PFCE   	PFCEn_8    	:1;
		PORT_e_PFCE   	PFCEn_9    	:1;
		PORT_e_PFCE   	PFCEn_10   	:1;
		PORT_e_PFCE   	PFCEn_11   	:1;
		PORT_e_PFCE   	PFCEn_12   	:1;
		PORT_e_PFCE   	PFCEn_13   	:1;
		PORT_e_PFCE   	PFCEn_14   	:1;
		PORT_e_PFCE   	PFCEn_15   	:1;
	}BIT;			
}PORT_s_PFCEn;				
				
/* JPFCEn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PFCE   	JPFCEn_0   	:1;
		PORT_e_PFCE   	JPFCEn_1   	:1;
		PORT_e_PFCE   	JPFCEn_2   	:1;
		PORT_e_PFCE   	JPFCEn_3   	:1;
		PORT_e_PFCE   	JPFCEn_4   	:1;
		PORT_e_PFCE   	JPFCEn_5   	:1;
		PORT_e_PFCE   	JPFCEn_6   	:1;
		PORT_e_PFCE   	JPFCEn_7   	:1;
	}BIT;			
}PORT_s_JPFCEn;				
				
/* PMSRn register */				
typedef union{				
		uint32_t      	UINT32;	
	struct{			
		PORT_e_PMSR_H 	PMSRn_0    	:1;
		PORT_e_PMSR_H 	PMSRn_1    	:1;
		PORT_e_PMSR_H 	PMSRn_2    	:1;
		PORT_e_PMSR_H 	PMSRn_3    	:1;
		PORT_e_PMSR_H 	PMSRn_4    	:1;
		PORT_e_PMSR_H 	PMSRn_5    	:1;
		PORT_e_PMSR_H 	PMSRn_6    	:1;
		PORT_e_PMSR_H 	PMSRn_7    	:1;
		PORT_e_PMSR_H 	PMSRn_8    	:1;
		PORT_e_PMSR_H 	PMSRn_9    	:1;
		PORT_e_PMSR_H 	PMSRn_10   	:1;
		PORT_e_PMSR_H 	PMSRn_11   	:1;
		PORT_e_PMSR_H 	PMSRn_12   	:1;
		PORT_e_PMSR_H 	PMSRn_13   	:1;
		PORT_e_PMSR_H 	PMSRn_14   	:1;
		PORT_e_PMSR_H 	PMSRn_15   	:1;
		PORT_e_PMSR_H 	PMSRn_16   	:1;
		PORT_e_PMSR_L 	PMSRn_17   	:1;
		PORT_e_PMSR_L 	PMSRn_18   	:1;
		PORT_e_PMSR_L 	PMSRn_19   	:1;
		PORT_e_PMSR_L 	PMSRn_20   	:1;
		PORT_e_PMSR_L 	PMSRn_21   	:1;
		PORT_e_PMSR_L 	PMSRn_22   	:1;
		PORT_e_PMSR_L 	PMSRn_23   	:1;
		PORT_e_PMSR_L 	PMSRn_24   	:1;
		PORT_e_PMSR_L 	PMSRn_25   	:1;
		PORT_e_PMSR_L 	PMSRn_26   	:1;
		PORT_e_PMSR_L 	PMSRn_27   	:1;
		PORT_e_PMSR_L 	PMSRn_28   	:1;
		PORT_e_PMSR_L 	PMSRn_29   	:1;
		PORT_e_PMSR_L 	PMSRn_30   	:1;
		PORT_e_PMSR_L 	PMSRn_31   	:1;
	}BIT;			
}PORT_s_PMSRn;				
				
/* PMCSRn register */				
typedef union{				
		uint32_t      	UINT32;	
	struct{			
		PORT_e_PMCSR_H	PMCSRn_0   	:1;
		PORT_e_PMCSR_H	PMCSRn_1   	:1;
		PORT_e_PMCSR_H	PMCSRn_2   	:1;
		PORT_e_PMCSR_H	PMCSRn_3   	:1;
		PORT_e_PMCSR_H	PMCSRn_4   	:1;
		PORT_e_PMCSR_H	PMCSRn_5   	:1;
		PORT_e_PMCSR_H	PMCSRn_6   	:1;
		PORT_e_PMCSR_H	PMCSRn_7   	:1;
		PORT_e_PMCSR_H	PMCSRn_8   	:1;
		PORT_e_PMCSR_H	PMCSRn_9   	:1;
		PORT_e_PMCSR_H	PMCSRn_10  	:1;
		PORT_e_PMCSR_H	PMCSRn_11  	:1;
		PORT_e_PMCSR_H	PMCSRn_12  	:1;
		PORT_e_PMCSR_H	PMCSRn_13  	:1;
		PORT_e_PMCSR_H	PMCSRn_14  	:1;
		PORT_e_PMCSR_H	PMCSRn_15  	:1;
		PORT_e_PMCSR_H	PMCSRn_16  	:1;
		PORT_e_PMCSR_L	PMCSRn_17  	:1;
		PORT_e_PMCSR_L	PMCSRn_18  	:1;
		PORT_e_PMCSR_L	PMCSRn_19  	:1;
		PORT_e_PMCSR_L	PMCSRn_20  	:1;
		PORT_e_PMCSR_L	PMCSRn_21  	:1;
		PORT_e_PMCSR_L	PMCSRn_22  	:1;
		PORT_e_PMCSR_L	PMCSRn_23  	:1;
		PORT_e_PMCSR_L	PMCSRn_24  	:1;
		PORT_e_PMCSR_L	PMCSRn_25  	:1;
		PORT_e_PMCSR_L	PMCSRn_26  	:1;
		PORT_e_PMCSR_L	PMCSRn_27  	:1;
		PORT_e_PMCSR_L	PMCSRn_28  	:1;
		PORT_e_PMCSR_L	PMCSRn_29  	:1;
		PORT_e_PMCSR_L	PMCSRn_30  	:1;
		PORT_e_PMCSR_L	PMCSRn_31  	:1;
	}BIT;			
}PORT_s_PMCSRn;				
				
/* PFCAEn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PFCAE  	PFCAEn_0   	:1;
		PORT_e_PFCAE  	PFCAEn_1   	:1;
		PORT_e_PFCAE  	PFCAEn_2   	:1;
		PORT_e_PFCAE  	PFCAEn_3   	:1;
		PORT_e_PFCAE  	PFCAEn_4   	:1;
		PORT_e_PFCAE  	PFCAEn_5   	:1;
		PORT_e_PFCAE  	PFCAEn_6   	:1;
		PORT_e_PFCAE  	PFCAEn_7   	:1;
		PORT_e_PFCAE  	PFCAEn_8   	:1;
		PORT_e_PFCAE  	PFCAEn_9   	:1;
		PORT_e_PFCAE  	PFCAEn_10  	:1;
		PORT_e_PFCAE  	PFCAEn_11  	:1;
		PORT_e_PFCAE  	PFCAEn_12  	:1;
		PORT_e_PFCAE  	PFCAEn_13  	:1;
		PORT_e_PFCAE  	PFCAEn_14  	:1;
		PORT_e_PFCAE  	PFCAEn_15  	:1;
	}BIT;			
}PORT_s_PFCAEn;				
				
/* PFCEAEn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PFCEAE 	PFCEAEn_0  	:1;
		PORT_e_PFCEAE 	PFCEAEn_1  	:1;
		PORT_e_PFCEAE 	PFCEAEn_2  	:1;
		PORT_e_PFCEAE 	PFCEAEn_3  	:1;
		PORT_e_PFCEAE 	PFCEAEn_4  	:1;
		PORT_e_PFCEAE 	PFCEAEn_5  	:1;
		PORT_e_PFCEAE 	PFCEAEn_6  	:1;
		PORT_e_PFCEAE 	PFCEAEn_7  	:1;
		PORT_e_PFCEAE 	PFCEAEn_8  	:1;
		PORT_e_PFCEAE 	PFCEAEn_9  	:1;
		PORT_e_PFCEAE 	PFCEAEn_10 	:1;
		PORT_e_PFCEAE 	PFCEAEn_11 	:1;
		PORT_e_PFCEAE 	PFCEAEn_12 	:1;
		PORT_e_PFCEAE 	PFCEAEn_13 	:1;
		PORT_e_PFCEAE 	PFCEAEn_14 	:1;
		PORT_e_PFCEAE 	PFCEAEn_15 	:1;
	}BIT;			
}PORT_s_PFCEAEn;				
				
/* PINVn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PINV   	PINVn_0    	:1;
		PORT_e_PINV   	PINVn_1    	:1;
		PORT_e_PINV   	PINVn_2    	:1;
		PORT_e_PINV   	PINVn_3    	:1;
		PORT_e_PINV   	PINVn_4    	:1;
		PORT_e_PINV   	PINVn_5    	:1;
		PORT_e_PINV   	PINVn_6    	:1;
		PORT_e_PINV   	PINVn_7    	:1;
		PORT_e_PINV   	PINVn_8    	:1;
		PORT_e_PINV   	PINVn_9    	:1;
		PORT_e_PINV   	PINVn_10   	:1;
		PORT_e_PINV   	PINVn_11   	:1;
		PORT_e_PINV   	PINVn_12   	:1;
		PORT_e_PINV   	PINVn_13   	:1;
		PORT_e_PINV   	PINVn_14   	:1;
		PORT_e_PINV   	PINVn_15   	:1;
	}BIT;			
}PORT_s_PINVn;				
				
/* JPINVn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PINV   	JPINVn_0   	:1;
		PORT_e_PINV   	JPINVn_1   	:1;
		PORT_e_PINV   	JPINVn_2   	:1;
		PORT_e_PINV   	JPINVn_3   	:1;
		PORT_e_PINV   	JPINVn_4   	:1;
		PORT_e_PINV   	JPINVn_5   	:1;
		PORT_e_PINV   	JPINVn_6   	:1;
		PORT_e_PINV   	JPINVn_7   	:1;
	}BIT;			
}PORT_s_JPINVn;				
				
/* PIBCn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PIBC   	PIBCn_0    	:1;
		PORT_e_PIBC   	PIBCn_1    	:1;
		PORT_e_PIBC   	PIBCn_2    	:1;
		PORT_e_PIBC   	PIBCn_3    	:1;
		PORT_e_PIBC   	PIBCn_4    	:1;
		PORT_e_PIBC   	PIBCn_5    	:1;
		PORT_e_PIBC   	PIBCn_6    	:1;
		PORT_e_PIBC   	PIBCn_7    	:1;
		PORT_e_PIBC   	PIBCn_8    	:1;
		PORT_e_PIBC   	PIBCn_9    	:1;
		PORT_e_PIBC   	PIBCn_10   	:1;
		PORT_e_PIBC   	PIBCn_11   	:1;
		PORT_e_PIBC   	PIBCn_12   	:1;
		PORT_e_PIBC   	PIBCn_13   	:1;
		PORT_e_PIBC   	PIBCn_14   	:1;
		PORT_e_PIBC   	PIBCn_15   	:1;
	}BIT;			
}PORT_s_PIBCn;				
				
/* JPIBCn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PIBC   	JPIBCn_0   	:1;
		PORT_e_PIBC   	JPIBCn_1   	:1;
		PORT_e_PIBC   	JPIBCn_2   	:1;
		PORT_e_PIBC   	JPIBCn_3   	:1;
		PORT_e_PIBC   	JPIBCn_4   	:1;
		PORT_e_PIBC   	JPIBCn_5   	:1;
		PORT_e_PIBC   	JPIBCn_6   	:1;
		PORT_e_PIBC   	JPIBCn_7   	:1;
	}BIT;			
}PORT_s_JPIBCn;				
				
/* PBDCn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PBDC   	PBDCn_0    	:1;
		PORT_e_PBDC   	PBDCn_1    	:1;
		PORT_e_PBDC   	PBDCn_2    	:1;
		PORT_e_PBDC   	PBDCn_3    	:1;
		PORT_e_PBDC   	PBDCn_4    	:1;
		PORT_e_PBDC   	PBDCn_5    	:1;
		PORT_e_PBDC   	PBDCn_6    	:1;
		PORT_e_PBDC   	PBDCn_7    	:1;
		PORT_e_PBDC   	PBDCn_8    	:1;
		PORT_e_PBDC   	PBDCn_9    	:1;
		PORT_e_PBDC   	PBDCn_10   	:1;
		PORT_e_PBDC   	PBDCn_11   	:1;
		PORT_e_PBDC   	PBDCn_12   	:1;
		PORT_e_PBDC   	PBDCn_13   	:1;
		PORT_e_PBDC   	PBDCn_14   	:1;
		PORT_e_PBDC   	PBDCn_15   	:1;
	}BIT;			
}PORT_s_PBDCn;				
				
/* JPBDCn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PBDC   	JPBDCn_0   	:1;
		PORT_e_PBDC   	JPBDCn_1   	:1;
		PORT_e_PBDC   	JPBDCn_2   	:1;
		PORT_e_PBDC   	JPBDCn_3   	:1;
		PORT_e_PBDC   	JPBDCn_4   	:1;
		PORT_e_PBDC   	JPBDCn_5   	:1;
		PORT_e_PBDC   	JPBDCn_6   	:1;
		PORT_e_PBDC   	JPBDCn_7   	:1;
	}BIT;			
}PORT_s_JPBDCn;				
				
/* PIPCn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PIPC   	PIPCn_0    	:1;
		PORT_e_PIPC   	PIPCn_1    	:1;
		PORT_e_PIPC   	PIPCn_2    	:1;
		PORT_e_PIPC   	PIPCn_3    	:1;
		PORT_e_PIPC   	PIPCn_4    	:1;
		PORT_e_PIPC   	PIPCn_5    	:1;
		PORT_e_PIPC   	PIPCn_6    	:1;
		PORT_e_PIPC   	PIPCn_7    	:1;
		PORT_e_PIPC   	PIPCn_8    	:1;
		PORT_e_PIPC   	PIPCn_9    	:1;
		PORT_e_PIPC   	PIPCn_10   	:1;
		PORT_e_PIPC   	PIPCn_11   	:1;
		PORT_e_PIPC   	PIPCn_12   	:1;
		PORT_e_PIPC   	PIPCn_13   	:1;
		PORT_e_PIPC   	PIPCn_14   	:1;
		PORT_e_PIPC   	PIPCn_15   	:1;
	}BIT;			
}PORT_s_PIPCn;				
				
/* PUn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PU     	PUn_0      	:1;
		PORT_e_PU     	PUn_1      	:1;
		PORT_e_PU     	PUn_2      	:1;
		PORT_e_PU     	PUn_3      	:1;
		PORT_e_PU     	PUn_4      	:1;
		PORT_e_PU     	PUn_5      	:1;
		PORT_e_PU     	PUn_6      	:1;
		PORT_e_PU     	PUn_7      	:1;
		PORT_e_PU     	PUn_8      	:1;
		PORT_e_PU     	PUn_9      	:1;
		PORT_e_PU     	PUn_10     	:1;
		PORT_e_PU     	PUn_11     	:1;
		PORT_e_PU     	PUn_12     	:1;
		PORT_e_PU     	PUn_13     	:1;
		PORT_e_PU     	PUn_14     	:1;
		PORT_e_PU     	PUn_15     	:1;
	}BIT;			
}PORT_s_PUn;				
				
/* JPUn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PU     	JPUn_0     	:1;
		PORT_e_PU     	JPUn_1     	:1;
		PORT_e_PU     	JPUn_2     	:1;
		PORT_e_PU     	JPUn_3     	:1;
		PORT_e_PU     	JPUn_4     	:1;
		PORT_e_PU     	JPUn_5     	:1;
		PORT_e_PU     	JPUn_6     	:1;
		PORT_e_PU     	JPUn_7     	:1;
	}BIT;			
}PORT_s_JPUn;				
				
/* PDn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PD     	PDn_0      	:1;
		PORT_e_PD     	PDn_1      	:1;
		PORT_e_PD     	PDn_2      	:1;
		PORT_e_PD     	PDn_3      	:1;
		PORT_e_PD     	PDn_4      	:1;
		PORT_e_PD     	PDn_5      	:1;
		PORT_e_PD     	PDn_6      	:1;
		PORT_e_PD     	PDn_7      	:1;
		PORT_e_PD     	PDn_8      	:1;
		PORT_e_PD     	PDn_9      	:1;
		PORT_e_PD     	PDn_10     	:1;
		PORT_e_PD     	PDn_11     	:1;
		PORT_e_PD     	PDn_12     	:1;
		PORT_e_PD     	PDn_13     	:1;
		PORT_e_PD     	PDn_14     	:1;
		PORT_e_PD     	PDn_15     	:1;
	}BIT;			
}PORT_s_PDn;				
				
/* JPDn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PD     	JPDn_0     	:1;
		PORT_e_PD     	JPDn_1     	:1;
		PORT_e_PD     	JPDn_2     	:1;
		PORT_e_PD     	JPDn_3     	:1;
		PORT_e_PD     	JPDn_4     	:1;
		PORT_e_PD     	JPDn_5     	:1;
		PORT_e_PD     	JPDn_6     	:1;
		PORT_e_PD     	JPDn_7     	:1;
	}BIT;			
}PORT_s_JPDn;				
				
/* PODCn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PODC   	PODCn_0    	:1;
		PORT_e_PODC   	PODCn_1    	:1;
		PORT_e_PODC   	PODCn_2    	:1;
		PORT_e_PODC   	PODCn_3    	:1;
		PORT_e_PODC   	PODCn_4    	:1;
		PORT_e_PODC   	PODCn_5    	:1;
		PORT_e_PODC   	PODCn_6    	:1;
		PORT_e_PODC   	PODCn_7    	:1;
		PORT_e_PODC   	PODCn_8    	:1;
		PORT_e_PODC   	PODCn_9    	:1;
		PORT_e_PODC   	PODCn_10   	:1;
		PORT_e_PODC   	PODCn_11   	:1;
		PORT_e_PODC   	PODCn_12   	:1;
		PORT_e_PODC   	PODCn_13   	:1;
		PORT_e_PODC   	PODCn_14   	:1;
		PORT_e_PODC   	PODCn_15   	:1;
	}BIT;			
}PORT_s_PODCn;				
				
/* JPODCn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PODC   	JPODCn_0   	:1;
		PORT_e_PODC   	JPODCn_1   	:1;
		PORT_e_PODC   	JPODCn_2   	:1;
		PORT_e_PODC   	JPODCn_3   	:1;
		PORT_e_PODC   	JPODCn_4   	:1;
		PORT_e_PODC   	JPODCn_5   	:1;
		PORT_e_PODC   	JPODCn_6   	:1;
		PORT_e_PODC   	JPODCn_7   	:1;
	}BIT;			
}PORT_s_JPODCn;				
				
/* PDSCn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PDSC   	PDSCn_0    	:1;
		PORT_e_PDSC   	PDSCn_1    	:1;
		PORT_e_PDSC   	PDSCn_2    	:1;
		PORT_e_PDSC   	PDSCn_3    	:1;
		PORT_e_PDSC   	PDSCn_4    	:1;
		PORT_e_PDSC   	PDSCn_5    	:1;
		PORT_e_PDSC   	PDSCn_6    	:1;
		PORT_e_PDSC   	PDSCn_7    	:1;
		PORT_e_PDSC   	PDSCn_8    	:1;
		PORT_e_PDSC   	PDSCn_9    	:1;
		PORT_e_PDSC   	PDSCn_10   	:1;
		PORT_e_PDSC   	PDSCn_11   	:1;
		PORT_e_PDSC   	PDSCn_12   	:1;
		PORT_e_PDSC   	PDSCn_13   	:1;
		PORT_e_PDSC   	PDSCn_14   	:1;
		PORT_e_PDSC   	PDSCn_15   	:1;
	}BIT;			
}PORT_s_PDSCn;				
				
/* JPDSCn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PDSC   	JPDSCn_0   	:1;
		PORT_e_PDSC   	JPDSCn_1   	:1;
		PORT_e_PDSC   	JPDSCn_2   	:1;
		PORT_e_PDSC   	JPDSCn_3   	:1;
		PORT_e_PDSC   	JPDSCn_4   	:1;
		PORT_e_PDSC   	JPDSCn_5   	:1;
		PORT_e_PDSC   	JPDSCn_6   	:1;
		PORT_e_PDSC   	JPDSCn_7   	:1;
	}BIT;			
}PORT_s_JPDSCn;				
				
/* PISn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PIS    	PISn_0     	:1;
		PORT_e_PIS    	PISn_1     	:1;
		PORT_e_PIS    	PISn_2     	:1;
		PORT_e_PIS    	PISn_3     	:1;
		PORT_e_PIS    	PISn_4     	:1;
		PORT_e_PIS    	PISn_5     	:1;
		PORT_e_PIS    	PISn_6     	:1;
		PORT_e_PIS    	PISn_7     	:1;
		PORT_e_PIS    	PISn_8     	:1;
		PORT_e_PIS    	PISn_9     	:1;
		PORT_e_PIS    	PISn_10    	:1;
		PORT_e_PIS    	PISn_11    	:1;
		PORT_e_PIS    	PISn_12    	:1;
		PORT_e_PIS    	PISn_13    	:1;
		PORT_e_PIS    	PISn_14    	:1;
		PORT_e_PIS    	PISn_15    	:1;
	}BIT;			
}PORT_s_PISn;				
				
/* JPISn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PIS    	JPISn_0    	:1;
		PORT_e_PIS    	JPISn_1    	:1;
		PORT_e_PIS    	JPISn_2    	:1;
		PORT_e_PIS    	JPISn_3    	:1;
		PORT_e_PIS    	JPISn_4    	:1;
		PORT_e_PIS    	JPISn_5    	:1;
		PORT_e_PIS    	JPISn_6    	:1;
		PORT_e_PIS    	JPISn_7    	:1;
	}BIT;			
}PORT_s_JPISn;				
				
/* PISAn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PISA   	PISAn_0    	:1;
		PORT_e_PISA   	PISAn_1    	:1;
		PORT_e_PISA   	PISAn_2    	:1;
		PORT_e_PISA   	PISAn_3    	:1;
		PORT_e_PISA   	PISAn_4    	:1;
		PORT_e_PISA   	PISAn_5    	:1;
		PORT_e_PISA   	PISAn_6    	:1;
		PORT_e_PISA   	PISAn_7    	:1;
		PORT_e_PISA   	PISAn_8    	:1;
		PORT_e_PISA   	PISAn_9    	:1;
		PORT_e_PISA   	PISAn_10   	:1;
		PORT_e_PISA   	PISAn_11   	:1;
		PORT_e_PISA   	PISAn_12   	:1;
		PORT_e_PISA   	PISAn_13   	:1;
		PORT_e_PISA   	PISAn_14   	:1;
		PORT_e_PISA   	PISAn_15   	:1;
	}BIT;			
}PORT_s_PISAn;				
				
/* JPISAn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PISA   	JPISAn_0   	:1;
		PORT_e_PISA   	JPISAn_1   	:1;
		PORT_e_PISA   	JPISAn_2   	:1;
		PORT_e_PISA   	JPISAn_3   	:1;
		PORT_e_PISA   	JPISAn_4   	:1;
		PORT_e_PISA   	JPISAn_5   	:1;
		PORT_e_PISA   	JPISAn_6   	:1;
		PORT_e_PISA   	JPISAn_7   	:1;
	}BIT;			
}PORT_s_JPISAn;				
				
/* PODCEn register */				
typedef union{				
		uint16_t      	UINT16;	
	struct{			
		PORT_e_PODCE  	PODCEn_0   	:1;
		PORT_e_PODCE  	PODCEn_1   	:1;
		PORT_e_PODCE  	PODCEn_2   	:1;
		PORT_e_PODCE  	PODCEn_3   	:1;
		PORT_e_PODCE  	PODCEn_4   	:1;
		PORT_e_PODCE  	PODCEn_5   	:1;
		PORT_e_PODCE  	PODCEn_6   	:1;
		PORT_e_PODCE  	PODCEn_7   	:1;
		PORT_e_PODCE  	PODCEn_8   	:1;
		PORT_e_PODCE  	PODCEn_9   	:1;
		PORT_e_PODCE  	PODCEn_10  	:1;
		PORT_e_PODCE  	PODCEn_11  	:1;
		PORT_e_PODCE  	PODCEn_12  	:1;
		PORT_e_PODCE  	PODCEn_13  	:1;
		PORT_e_PODCE  	PODCEn_14  	:1;
		PORT_e_PODCE  	PODCEn_15  	:1;
	}BIT;			
}PORT_s_PODCEn;				
				
/* JPODCEn register */				
typedef union{				
		uint8_t       	UINT8;	
	struct{			
		PORT_e_PODCE  	JPODCEn_0  	:1;
		PORT_e_PODCE  	JPODCEn_1  	:1;
		PORT_e_PODCE  	JPODCEn_2  	:1;
		PORT_e_PODCE  	JPODCEn_3  	:1;
		PORT_e_PODCE  	JPODCEn_4  	:1;
		PORT_e_PODCE  	JPODCEn_5  	:1;
		PORT_e_PODCE  	JPODCEn_6  	:1;
		PORT_e_PODCE  	JPODCEn_7  	:1;
	}BIT;			
}PORT_s_JPODCEn;				
				
/* PCRn_m register */				
typedef union{				
		uint32_t      	UINT32;	
	struct{			
		PORT_e_PFC    	PFC        	:1;
		PORT_e_PFCE   	PFCE       	:1;
		PORT_e_PFCAE  	PFCAE      	:1;
		PORT_e_PFCEAE 	PFCEAE     	:1;
		PORT_e_PM     	PM         	:1;
		PORT_e_PIPC   	PIPC       	:1;
		PORT_e_PMC    	PMC        	:1;
		 uint32_t     	Reserved_7 	:1;
		PORT_e_PPR    	PPR        	:1;
		 uint32_t     	Reserved_9 	:3;
		PORT_e_P      	P          	:1;
		 uint32_t     	Reserved_13	:3;
		PORT_e_PIBC   	PIBC       	:1;
		PORT_e_PBDC   	PBDC       	:1;
		PORT_e_PD     	PD         	:1;
		PORT_e_PU     	PU         	:1;
		PORT_e_PIS    	PIS        	:1;
		 uint32_t     	Reserved_21	:1;
		PORT_e_PISA   	PISA       	:1;
		 uint32_t     	Reserved_23	:1;
		PORT_e_PDSC   	PDSC       	:1;
		 uint32_t     	Reserved_25	:2;
		PORT_e_PODCE  	PODCE      	:1;
		PORT_e_PODC   	PODC       	:1;
		 uint32_t     	Reserved_29	:1;
		PORT_e_PINV   	PINV       	:1;
		 uint32_t     	Reserved_31	:1;
	}BIT;			
}PORT_s_PCRn_m;				
				
/* PKCPROT register */				
typedef union{				
		uint32_t      	UINT32;	
	struct{			
		PORT_e_PWEE   	PWEE       	:1;
		 uint32_t     	PKCPROT    	:31;
	}BIT;			
}PORT_s_PKCPROT;				
				
/* PWE register */				
typedef union{				
		uint32_t      	UINT32;	
	struct{			
		PORT_e_PWEx   	PWEP00     	:1;
		PORT_e_PWEx   	PWEP01     	:1;
		PORT_e_PWEx   	PWEP02     	:1;
		PORT_e_PWEx   	PWEP03     	:1;
		PORT_e_PWEx   	PWEP08     	:1;
		PORT_e_PWEx   	PWEP09     	:1;
		PORT_e_PWEx   	PWEPn      	:1;
		PORT_e_PWEx   	PWEP11     	:1;
		PORT_e_PWEx   	PWEP12     	:1;
		PORT_e_PWEx   	PWEP13     	:1;
		PORT_e_PWEx   	PWEP18     	:1;
		PORT_e_PWEx   	PWEP19     	:1;
		PORT_e_PWEx   	PWEP20     	:1;
		PORT_e_PWEx   	PWEP21     	:1;
		 uint32_t     	Reserved_14	:2;
		PORT_e_PWEx   	PWEP27     	:1;
		 uint32_t     	Reserved_17	:3;
		PORT_e_PWEx   	PWEAP0     	:1;
		 uint32_t     	Reserved_21	:1;
		PORT_e_PWEx   	PWEAP2     	:1;
		 uint32_t     	Reserved_23	:3;
		PORT_e_PWEx   	PWEIP0     	:1;
		 uint32_t     	Reserved_27	:5;
	}BIT;			
}PORT_s_PWE;


/* FCLACTLm register */
typedef union{
		uint8_t      	UINT8;
	struct{
		PORT_e_INTx   	INTx      	:3;	/* bit 0: INTR, bit 1: INTF, bit2: INTL*/
		uint8_t     	Reserved_3	:4;
		PORT_e_BYPS   	BYPS     	:1;
	}BIT;
}PORT_s_FCLACTLm;


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_port_reg_H__ */

