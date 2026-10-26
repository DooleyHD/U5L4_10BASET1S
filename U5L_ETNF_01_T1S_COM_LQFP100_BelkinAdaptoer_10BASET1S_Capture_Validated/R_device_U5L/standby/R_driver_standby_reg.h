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
* File Name    : R_driver_standby_reg.h
* Version      : 1.00
* Module(s)    : Standby controller
* Device(s)    : R-Car U5L product
* Description  : Register definition of standby controller for R-Car U5L
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_standby_reg_H__
#define	__R_driver_standby_reg_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_typedef.h"


/*******************************************************************************
* Register Base Address Definitions
*******************************************************************************/
/* no definition */


/*******************************************************************************
* Definition of register symbol
*******************************************************************************/
#define	rMSR_RSCFD   	(*(volatile STBC_s_MSR_RSCFD    *) (0x5C081000) )	/* Module Standby Register for RS-CANFD */
#define	rMSR_ETND    	(*(volatile STBC_s_MSR_ETND     *) (0x5C081030) )	/* Module Standby Register for ETND */
#define	rMSR_ETNF    	(*(volatile STBC_s_MSR_ETNF     *) (0x5C081034) )	/* Module Standby Register for ETNF */
#define	rMSR_RSENT   	(*(volatile STBC_s_MSR_RSENT    *) (0x5C081040) )	/* Module Standby Register for RSENT */
#define	rMSR_CSIH    	(*(volatile STBC_s_MSR_CSIH     *) (0x5C081050) )	/* Module Standby Register for CSIH */
#define	rMSR_RLIN3   	(*(volatile STBC_s_MSR_RLIN3    *) (0x5C081060) )	/* Module Standby Register for RLIN3 */
#define	rMSR_ADCK_ISO	(*(volatile STBC_s_MSR_ADCK_ISO *) (0x5C081078) )	/* Module Standby Register for SAR-ADC */
#define	rMSR_CXPI    	(*(volatile STBC_s_MSR_CXPI     *) (0x5C081080) )	/* Module Standby Register for CXPI */
#define	rMSR_MMCA    	(*(volatile STBC_s_MSR_MMCA     *) (0x5C081090) )	/* Module Standby Register for MMCA */
#define	rMSR_ENCA    	(*(volatile STBC_s_MSR_ENCA     *) (0x5C0810A0) )	/* Module Standby Register for ENCA */
#define	rMSR_PSI5    	(*(volatile STBC_s_MSR_PSI5     *) (0x5C0810B0) )	/* Module Standby Register for PSI5 */
#define	rMSR_PWMD    	(*(volatile STBC_s_MSR_PWMD     *) (0x5C0810D0) )	/* Module Standby Register for PWM-Diag */
#define	rMSR_RIIC    	(*(volatile STBC_s_MSR_RIIC     *) (0x5C0810F0) )	/* Module Standby Register for RIIC */
#define	rMSR_SFMA    	(*(volatile STBC_s_MSR_SFMA     *) (0x5C081110) )	/* Module Standby Register for SFMA */
#define	rMSR_TAPA    	(*(volatile STBC_s_MSR_TAPA     *) (0x5C081120) )	/* Module Standby Register for TAPA */
#define	rMSR_TAUD    	(*(volatile STBC_s_MSR_TAUD     *) (0x5C081130) )	/* Module Standby Register for TAUD */
#define	rMSR_TAUJ_ISO	(*(volatile STBC_s_MSR_TAUJ_ISO *) (0x5C081140) )	/* Module Standby Register for TAUJn (n = 0 - 3) */
#define	rMSR_OSTM    	(*(volatile STBC_s_MSR_OSTM     *) (0x5C081180) )	/* Module Standby Register for OSTM */
#define	rMSR_CANXL   	(*(volatile STBC_s_MSR_CANXL    *) (0x5C081230) )	/* Module Standby Register for CANXL */
#define	rMSR_RI3C    	(*(volatile STBC_s_MSR_RI3C     *) (0x5C081250) )	/* Module Standby Register for RI3C */
#define	rMSR_SSIF    	(*(volatile STBC_s_MSR_SSIF     *) (0x5C081260) )	/* Module Standby Register for SSIF */
#define	rSTBCKCPROT  	(*(volatile STBC_s_STBCKCPROT   *) (0x5C081700) )	/* Standby controller Register Key Code Protection Register */
#define	rMSRKCPROT   	(*(volatile STBC_s_MSRKCPROT    *) (0x5C081710) )	/* Module Standby Register Key Code Protection Register */
#define	rSTBC0PSC    	(*(volatile STBC_s_STBC0PSC     *) (0x5C088800) )	/* Power Save Control Register */
#define	rIOHOLD0     	(*(volatile STBC_s_IOHOLD0      *) (0x5C088900) )	/* I/O Buffer Hold Control Register 0 */
#define	rIOHOLD2     	(*(volatile STBC_s_IOHOLD2      *) (0x5C088908) )	/* I/O Buffer Hold Control Register 2 */
#define	rMSR_ADCK_AWO	(*(volatile STBC_s_MSR_ADCK_AWO *) (0x5C088A00) )	/* Module Standby Register for SAR-ADC */
#define	rMSR_RTCA    	(*(volatile STBC_s_MSR_RTCA     *) (0x5C088A10) )	/* Module Standby Register for RTCA */
#define	rMSR_WDTB_AWO	(*(volatile STBC_s_MSR_WDTB_AWO *) (0x5C088A30) )	/* Module Standby Register for WDTB */
#define	rWUF_A0      	(*(volatile STBC_s_WUF_A0       *) (0x5C08E400) )	/* Wake-Up Factor Register A0 */
#define	rWUFC_A0     	(*(volatile STBC_s_WUFC_A0      *) (0x5C08E404) )	/* Wake-Up Factor Clear Register A0 */
#define	rWUF0EN_A0   	(*(volatile STBC_s_WUF0EN_A0    *) (0x5C08E408) )	/* Wake-Up Factor 0 Enable Register A0 */
#define	rWUF1EN_A0   	(*(volatile STBC_s_WUF1EN_A0    *) (0x5C08E40C) )	/* Wake-Up Factor 1 Enable Register A0 */
#define	rWUF_A1      	(*(volatile STBC_s_WUF_A1       *) (0x5C08E410) )	/* Wake-Up Factor Register A1 */
#define	rWUFC_A1     	(*(volatile STBC_s_WUFC_A1      *) (0x5C08E414) )	/* Wake-Up Factor Clear Register A1 */
#define	rWUF0EN_A1   	(*(volatile STBC_s_WUF0EN_A1    *) (0x5C08E418) )	/* Wake-Up Factor 0 Enable Register A1 */
#define	rWUF1EN_A1   	(*(volatile STBC_s_WUF1EN_A1    *) (0x5C08E41C) )	/* Wake-Up Factor 1 Enable Register A1 */


/*******************************************************************************
* Definition of Register bit value
*******************************************************************************/
/* MSR_RSCFD.MS_RSCFD: Setting this bit to 1 stops all clocks connected to target module. */
typedef enum{
	STBC_e_MS_supply_clock = 0,	/* 0: The clocks are supplied. */
	STBC_e_MS_stop_clock   = 1 	/* 1: The clocks are stopped. */
}STBC_e_MS;

/* STBCKCPROT: Enable/Disables write access of protected registers */
/* MSRKCPROT: Enable/Disables write access of protected registers */
typedef enum{
	STBC_e_STBCKCPROT_write_disable = 0xA5A5A500,	/* les write access of protected registers */
	STBC_e_STBCKCPROT_write_enable  = 0xA5A5A501 	/* es write access of protected registers */
}STBC_e_STBCKCPROT;

/* STBCKCPROT.STBCKCE: Key Code Enable bit */
/* MSRKCPROT.KCE: Key Code Enable bit */
typedef enum{
	STBC_e_CKE_write_disable = 0,	/* 0: Disables write access of protected registers */
	STBC_e_CKE_write_enable  = 1 	/* 1: Enables write access of protected registers */
}STBC_e_CKE;

/* IOHOLD0.IOHOLD_Px: I/O hold state of each port group */
/* IOHOLD2.IOHOLD_Px: I/O hold state of each port group */
typedef enum{
	STBC_e_IOHOLD_release = 0,	/* 0: I/O hold state is released */
	STBC_e_IOHOLD_hold    = 1 	/* 1: I/O hold state */
}STBC_e_IOHOLD;

/* WUF_A0.WUF: Indicates Wake-Up Factor */
/* WUF_A1.WUF: Indicates Wake-Up Factor */
typedef enum{
	STBC_e_WUF_not_requested = 0,	/* 0: Wake-Up Factor 31 is not requested */
	STBC_e_WUF_requested     = 1 	/* 1: Wake-Up Factor 31 is requested */
}STBC_e_WUF;

/* WUF0EN_A0.WUF: Enables/disables WUF_A0 to Wake-Up Factor 0 */
/* WUF1EN_A0.WUF: Enables/disables WUF_A0 to Wake-Up Factor 1 */
/* WUF0EN_A1.WUF: Enables/disables WUF_A1 to Wake-Up Factor 0 */
/* WUF1EN_A1.WUF: Enables/disables WUF_A1 to Wake-Up Factor 1 */
typedef enum{
	STBC_e_WUFEN_disable = 0,	/* 0: WUF31 is disabled. */
	STBC_e_WUFEN_enable  = 1 	/* 1: WUF31 is enabled */
}STBC_e_WUFEN;



/*******************************************************************************
* Definition of Register typedef
*******************************************************************************/
/* MSR_RSCFD register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_RSCFD   	:1;
	}BIT;
}STBC_s_MSR_RSCFD;

/* MSR_ETND register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_ETND    	:1;
	}BIT;
}STBC_s_MSR_ETND;

/* MSR_ETNF register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_ETNF    	:1;
	}BIT;
}STBC_s_MSR_ETNF;

/* MSR_RSENT register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_RSENT   	:1;
	}BIT;
}STBC_s_MSR_RSENT;

/* MSR_CSIH register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_CSIH    	:1;
	}BIT;
}STBC_s_MSR_CSIH;

/* MSR_RLIN3 register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_RLIN3   	:1;
	}BIT;
}STBC_s_MSR_RLIN3;

/* MSR_ADCK_ISO register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_ADCK_ISO	:1;
	}BIT;
}STBC_s_MSR_ADCK_ISO;

/* MSR_CXPI register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_CXPI    	:1;
	}BIT;
}STBC_s_MSR_CXPI;

/* MSR_MMCA register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_MMCA    	:1;
	}BIT;
}STBC_s_MSR_MMCA;

/* MSR_ENCA register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_ENCA    	:1;
	}BIT;
}STBC_s_MSR_ENCA;

/* MSR_PSI5 register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_PSI5    	:1;
	}BIT;
}STBC_s_MSR_PSI5;

/* MSR_PWMD register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_PWMD    	:1;
	}BIT;
}STBC_s_MSR_PWMD;

/* MSR_RIIC register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_RIIC    	:1;
	}BIT;
}STBC_s_MSR_RIIC;

/* MSR_SFMA register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_SFMA    	:1;
	}BIT;
}STBC_s_MSR_SFMA;

/* MSR_TAPA register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_TAPA    	:1;
	}BIT;
}STBC_s_MSR_TAPA;

/* MSR_TAUD register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_TAUD    	:1;
	}BIT;
}STBC_s_MSR_TAUD;

/* MSR_TAUJ_ISO register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_TAUJ_ISO	:1;
	}BIT;
}STBC_s_MSR_TAUJ_ISO;

/* MSR_OSTM register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_OSTM    	:1;
	}BIT;
}STBC_s_MSR_OSTM;

/* MSR_CANXL register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_CANXL   	:1;
	}BIT;
}STBC_s_MSR_CANXL;

/* MSR_RI3C register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_RI3C    	:1;
	}BIT;
}STBC_s_MSR_RI3C;

/* MSR_SSIF register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_SSIF    	:1;
	}BIT;
}STBC_s_MSR_SSIF;

/* STBCKCPROT register */
typedef union{
		uint32_t     	UINT32;
	struct{
		STBC_e_CKE   	STBCKCE    	:1;
		uint32_t     	STBCKCPROT 	:31;
	}BIT;
}STBC_s_STBCKCPROT;

/* MSRKCPROT register */
typedef union{
		uint32_t     	UINT32;
	struct{
		STBC_e_CKE   	KCE        	:1;
		uint32_t     	KCPROT     	:31;
	}BIT;
}STBC_s_MSRKCPROT;

/* MSR_ADCK_AWO register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_ADCK_AWO	:1;
	}BIT;
}STBC_s_MSR_ADCK_AWO;

/* MSR_RTCA register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_RTCA    	:1;
	}BIT;
}STBC_s_MSR_RTCA;

/* MSR_WDTB_AWO register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:31;
		STBC_e_MS    	MS_WDTB_AWO	:1;
	}BIT;
}STBC_s_MSR_WDTB_AWO;

/* STBC0PSC register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:1;
		uint32_t     	STBC0DISTRG	:1;
		uint32_t     	Reserved_2 	:30;
	}BIT;
}STBC_s_STBC0PSC;

/* IOHOLD0 register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	Reserved_0 	:1;
		STBC_e_IOHOLD	IOHOLD_P01 	:1;
		uint32_t     	Reserved_2 	:1;
		STBC_e_IOHOLD	IOHOLD_P03 	:1;
		uint32_t     	Reserved_4 	:5;
		STBC_e_IOHOLD	IOHOLD_P09 	:1;
		STBC_e_IOHOLD	IOHOLD_P10 	:1;
		STBC_e_IOHOLD	IOHOLD_P11 	:1;
		STBC_e_IOHOLD	IOHOLD_P12 	:1;
		STBC_e_IOHOLD	IOHOLD_P13 	:1;
		uint32_t     	Reserved_14	:4;
		STBC_e_IOHOLD	IOHOLD_P18 	:1;
		STBC_e_IOHOLD	IOHOLD_P19 	:1;
		STBC_e_IOHOLD	IOHOLD_P20 	:1;
		STBC_e_IOHOLD	IOHOLD_P21 	:1;
		uint32_t     	Reserved_22	:10;
	}BIT;
}STBC_s_IOHOLD0;

/* IOHOLD2 register */
typedef union{
		uint32_t     	UINT32;
	struct{
		STBC_e_IOHOLD	IOHOLD_AP0 	:1;
		uint32_t     	Reserved_1 	:1;
		STBC_e_IOHOLD	IOHOLD_AP2 	:1;
		uint32_t     	Reserved_3 	:29;
	}BIT;
}STBC_s_IOHOLD2;

/* WUF_A0 register */
typedef union{
		uint32_t     	UINT32;
	struct{
		STBC_e_WUF   	WUF0       	:1;
		STBC_e_WUF   	WUF1       	:1;
		STBC_e_WUF   	WUF2       	:1;
		STBC_e_WUF   	WUF3       	:1;
		STBC_e_WUF   	WUF4       	:1;
		STBC_e_WUF   	WUF5       	:1;
		STBC_e_WUF   	WUF6       	:1;
		STBC_e_WUF   	WUF7       	:1;
		STBC_e_WUF   	WUF8       	:1;
		STBC_e_WUF   	WUF9       	:1;
		STBC_e_WUF   	WUF10      	:1;
		STBC_e_WUF   	WUF11      	:1;
		STBC_e_WUF   	WUF12      	:1;
		STBC_e_WUF   	WUF13      	:1;
		STBC_e_WUF   	WUF14      	:1;
		STBC_e_WUF   	WUF15      	:1;
		STBC_e_WUF   	WUF16      	:1;
		STBC_e_WUF   	WUF17      	:1;
		STBC_e_WUF   	WUF18      	:1;
		STBC_e_WUF   	WUF19      	:1;
		STBC_e_WUF   	WUF20      	:1;
		STBC_e_WUF   	WUF21      	:1;
		STBC_e_WUF   	WUF22      	:1;
		STBC_e_WUF   	WUF23      	:1;
		STBC_e_WUF   	WUF24      	:1;
		STBC_e_WUF   	WUF25      	:1;
		STBC_e_WUF   	WUF26      	:1;
		STBC_e_WUF   	WUF27      	:1;
		STBC_e_WUF   	WUF28      	:1;
		STBC_e_WUF   	WUF29      	:1;
		STBC_e_WUF   	WUF30      	:1;
		STBC_e_WUF   	WUF31      	:1;
	}BIT;
}STBC_s_WUF_A0;

/* WUFC_A0 register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	WUFC0      	:1;
		uint32_t     	WUFC1      	:1;
		uint32_t     	WUFC2      	:1;
		uint32_t     	WUFC3      	:1;
		uint32_t     	WUFC4      	:1;
		uint32_t     	WUFC5      	:1;
		uint32_t     	WUFC6      	:1;
		uint32_t     	WUFC7      	:1;
		uint32_t     	WUFC8      	:1;
		uint32_t     	WUFC9      	:1;
		uint32_t     	WUFC10     	:1;
		uint32_t     	WUFC11     	:1;
		uint32_t     	WUFC12     	:1;
		uint32_t     	WUFC13     	:1;
		uint32_t     	WUFC14     	:1;
		uint32_t     	WUFC15     	:1;
		uint32_t     	WUFC16     	:1;
		uint32_t     	WUFC17     	:1;
		uint32_t     	WUFC18     	:1;
		uint32_t     	WUFC19     	:1;
		uint32_t     	WUFC20     	:1;
		uint32_t     	WUFC21     	:1;
		uint32_t     	WUFC22     	:1;
		uint32_t     	WUFC23     	:1;
		uint32_t     	WUFC24     	:1;
		uint32_t     	WUFC25     	:1;
		uint32_t     	WUFC26     	:1;
		uint32_t     	WUFC27     	:1;
		uint32_t     	WUFC28     	:1;
		uint32_t     	WUFC29     	:1;
		uint32_t     	WUFC30     	:1;
		uint32_t     	WUFC31     	:1;
	}BIT;
}STBC_s_WUFC_A0;

/* WUF0EN_A0 register */
typedef union{
		uint32_t     	UINT32;
	struct{
		STBC_e_WUFEN 	WUFEN0     	:1;
		STBC_e_WUFEN 	WUFEN1     	:1;
		STBC_e_WUFEN 	WUFEN2     	:1;
		STBC_e_WUFEN 	WUFEN3     	:1;
		STBC_e_WUFEN 	WUFEN4     	:1;
		STBC_e_WUFEN 	WUFEN5     	:1;
		STBC_e_WUFEN 	WUFEN6     	:1;
		STBC_e_WUFEN 	WUFEN7     	:1;
		STBC_e_WUFEN 	WUFEN8     	:1;
		STBC_e_WUFEN 	WUFEN9     	:1;
		STBC_e_WUFEN 	WUFEN10    	:1;
		STBC_e_WUFEN 	WUFEN11    	:1;
		STBC_e_WUFEN 	WUFEN12    	:1;
		STBC_e_WUFEN 	WUFEN13    	:1;
		STBC_e_WUFEN 	WUFEN14    	:1;
		STBC_e_WUFEN 	WUFEN15    	:1;
		STBC_e_WUFEN 	WUFEN16    	:1;
		STBC_e_WUFEN 	WUFEN17    	:1;
		STBC_e_WUFEN 	WUFEN18    	:1;
		STBC_e_WUFEN 	WUFEN19    	:1;
		STBC_e_WUFEN 	WUFEN20    	:1;
		STBC_e_WUFEN 	WUFEN21    	:1;
		STBC_e_WUFEN 	WUFEN22    	:1;
		STBC_e_WUFEN 	WUFEN23    	:1;
		STBC_e_WUFEN 	WUFEN24    	:1;
		STBC_e_WUFEN 	WUFEN25    	:1;
		STBC_e_WUFEN 	WUFEN26    	:1;
		STBC_e_WUFEN 	WUFEN27    	:1;
		STBC_e_WUFEN 	WUFEN28    	:1;
		STBC_e_WUFEN 	WUFEN29    	:1;
		STBC_e_WUFEN 	WUFEN30    	:1;
		STBC_e_WUFEN 	WUFEN31    	:1;
	}BIT;
}STBC_s_WUF0EN_A0;

/* WUF1EN_A0 register */
typedef union{
		uint32_t     	UINT32;
	struct{
		STBC_e_WUFEN 	WUFEN0     	:1;
		STBC_e_WUFEN 	WUFEN1     	:1;
		STBC_e_WUFEN 	WUFEN2     	:1;
		STBC_e_WUFEN 	WUFEN3     	:1;
		STBC_e_WUFEN 	WUFEN4     	:1;
		STBC_e_WUFEN 	WUFEN5     	:1;
		STBC_e_WUFEN 	WUFEN6     	:1;
		STBC_e_WUFEN 	WUFEN7     	:1;
		STBC_e_WUFEN 	WUFEN8     	:1;
		STBC_e_WUFEN 	WUFEN9     	:1;
		STBC_e_WUFEN 	WUFEN10    	:1;
		STBC_e_WUFEN 	WUFEN11    	:1;
		STBC_e_WUFEN 	WUFEN12    	:1;
		STBC_e_WUFEN 	WUFEN13    	:1;
		STBC_e_WUFEN 	WUFEN14    	:1;
		STBC_e_WUFEN 	WUFEN15    	:1;
		STBC_e_WUFEN 	WUFEN16    	:1;
		STBC_e_WUFEN 	WUFEN17    	:1;
		STBC_e_WUFEN 	WUFEN18    	:1;
		STBC_e_WUFEN 	WUFEN19    	:1;
		STBC_e_WUFEN 	WUFEN20    	:1;
		STBC_e_WUFEN 	WUFEN21    	:1;
		STBC_e_WUFEN 	WUFEN22    	:1;
		STBC_e_WUFEN 	WUFEN23    	:1;
		STBC_e_WUFEN 	WUFEN24    	:1;
		STBC_e_WUFEN 	WUFEN25    	:1;
		STBC_e_WUFEN 	WUFEN26    	:1;
		STBC_e_WUFEN 	WUFEN27    	:1;
		STBC_e_WUFEN 	WUFEN28    	:1;
		STBC_e_WUFEN 	WUFEN29    	:1;
		STBC_e_WUFEN 	WUFEN30    	:1;
		STBC_e_WUFEN 	WUFEN31    	:1;
	}BIT;
}STBC_s_WUF1EN_A0;

/* WUF_A1 register */
typedef union{
		uint32_t     	UINT32;
	struct{
		STBC_e_WUF   	WUF0       	:1;
		STBC_e_WUF   	WUF1       	:1;
		STBC_e_WUF   	WUF2       	:1;
		STBC_e_WUF   	WUF3       	:1;
		STBC_e_WUF   	WUF4       	:1;
		STBC_e_WUF   	WUF5       	:1;
		STBC_e_WUF   	WUF6       	:1;
		STBC_e_WUF   	WUF7       	:1;
		STBC_e_WUF   	WUF8       	:1;
		STBC_e_WUF   	WUF9       	:1;
		STBC_e_WUF   	WUF10      	:1;
		STBC_e_WUF   	WUF11      	:1;
		STBC_e_WUF   	WUF12      	:1;
		STBC_e_WUF   	WUF13      	:1;
		STBC_e_WUF   	WUF14      	:1;
		STBC_e_WUF   	WUF15      	:1;
		STBC_e_WUF   	WUF16      	:1;
		STBC_e_WUF   	WUF17      	:1;
		STBC_e_WUF   	WUF18      	:1;
		STBC_e_WUF   	WUF19      	:1;
		STBC_e_WUF   	WUF20      	:1;
		STBC_e_WUF   	WUF21      	:1;
		STBC_e_WUF   	WUF22      	:1;
		STBC_e_WUF   	WUF23      	:1;
		STBC_e_WUF   	WUF24      	:1;
		STBC_e_WUF   	WUF25      	:1;
		STBC_e_WUF   	WUF26      	:1;
		STBC_e_WUF   	WUF27      	:1;
		STBC_e_WUF   	WUF28      	:1;
		STBC_e_WUF   	WUF29      	:1;
		STBC_e_WUF   	WUF30      	:1;
		STBC_e_WUF   	WUF31      	:1;
	}BIT;
}STBC_s_WUF_A1;

/* WUFC_A1 register */
typedef union{
		uint32_t     	UINT32;
	struct{
		uint32_t     	WUFC0      	:1;
		uint32_t     	WUFC1      	:1;
		uint32_t     	WUFC2      	:1;
		uint32_t     	WUFC3      	:1;
		uint32_t     	WUFC4      	:1;
		uint32_t     	WUFC5      	:1;
		uint32_t     	WUFC6      	:1;
		uint32_t     	WUFC7      	:1;
		uint32_t     	WUFC8      	:1;
		uint32_t     	WUFC9      	:1;
		uint32_t     	WUFC10     	:1;
		uint32_t     	WUFC11     	:1;
		uint32_t     	WUFC12     	:1;
		uint32_t     	WUFC13     	:1;
		uint32_t     	WUFC14     	:1;
		uint32_t     	WUFC15     	:1;
		uint32_t     	WUFC16     	:1;
		uint32_t     	WUFC17     	:1;
		uint32_t     	WUFC18     	:1;
		uint32_t     	WUFC19     	:1;
		uint32_t     	WUFC20     	:1;
		uint32_t     	WUFC21     	:1;
		uint32_t     	WUFC22     	:1;
		uint32_t     	WUFC23     	:1;
		uint32_t     	WUFC24     	:1;
		uint32_t     	WUFC25     	:1;
		uint32_t     	WUFC26     	:1;
		uint32_t     	WUFC27     	:1;
		uint32_t     	WUFC28     	:1;
		uint32_t     	WUFC29     	:1;
		uint32_t     	WUFC30     	:1;
		uint32_t     	WUFC31     	:1;
	}BIT;
}STBC_s_WUFC_A1;

/* WUF0EN_A1 register */
typedef union{
		uint32_t     	UINT32;
	struct{
		STBC_e_WUFEN 	WUFEN0     	:1;
		STBC_e_WUFEN 	WUFEN1     	:1;
		STBC_e_WUFEN 	WUFEN2     	:1;
		STBC_e_WUFEN 	WUFEN3     	:1;
		STBC_e_WUFEN 	WUFEN4     	:1;
		STBC_e_WUFEN 	WUFEN5     	:1;
		STBC_e_WUFEN 	WUFEN6     	:1;
		STBC_e_WUFEN 	WUFEN7     	:1;
		STBC_e_WUFEN 	WUFEN8     	:1;
		STBC_e_WUFEN 	WUFEN9     	:1;
		STBC_e_WUFEN 	WUFEN10    	:1;
		STBC_e_WUFEN 	WUFEN11    	:1;
		STBC_e_WUFEN 	WUFEN12    	:1;
		STBC_e_WUFEN 	WUFEN13    	:1;
		STBC_e_WUFEN 	WUFEN14    	:1;
		STBC_e_WUFEN 	WUFEN15    	:1;
		STBC_e_WUFEN 	WUFEN16    	:1;
		STBC_e_WUFEN 	WUFEN17    	:1;
		STBC_e_WUFEN 	WUFEN18    	:1;
		STBC_e_WUFEN 	WUFEN19    	:1;
		STBC_e_WUFEN 	WUFEN20    	:1;
		STBC_e_WUFEN 	WUFEN21    	:1;
		STBC_e_WUFEN 	WUFEN22    	:1;
		STBC_e_WUFEN 	WUFEN23    	:1;
		STBC_e_WUFEN 	WUFEN24    	:1;
		STBC_e_WUFEN 	WUFEN25    	:1;
		STBC_e_WUFEN 	WUFEN26    	:1;
		STBC_e_WUFEN 	WUFEN27    	:1;
		STBC_e_WUFEN 	WUFEN28    	:1;
		STBC_e_WUFEN 	WUFEN29    	:1;
		STBC_e_WUFEN 	WUFEN30    	:1;
		STBC_e_WUFEN 	WUFEN31    	:1;
	}BIT;
}STBC_s_WUF0EN_A1;

/* WUF1EN_A1 register */
typedef union{
		uint32_t     	UINT32;
	struct{
		STBC_e_WUFEN 	WUFEN0     	:1;
		STBC_e_WUFEN 	WUFEN1     	:1;
		STBC_e_WUFEN 	WUFEN2     	:1;
		STBC_e_WUFEN 	WUFEN3     	:1;
		STBC_e_WUFEN 	WUFEN4     	:1;
		STBC_e_WUFEN 	WUFEN5     	:1;
		STBC_e_WUFEN 	WUFEN6     	:1;
		STBC_e_WUFEN 	WUFEN7     	:1;
		STBC_e_WUFEN 	WUFEN8     	:1;
		STBC_e_WUFEN 	WUFEN9     	:1;
		STBC_e_WUFEN 	WUFEN10    	:1;
		STBC_e_WUFEN 	WUFEN11    	:1;
		STBC_e_WUFEN 	WUFEN12    	:1;
		STBC_e_WUFEN 	WUFEN13    	:1;
		STBC_e_WUFEN 	WUFEN14    	:1;
		STBC_e_WUFEN 	WUFEN15    	:1;
		STBC_e_WUFEN 	WUFEN16    	:1;
		STBC_e_WUFEN 	WUFEN17    	:1;
		STBC_e_WUFEN 	WUFEN18    	:1;
		STBC_e_WUFEN 	WUFEN19    	:1;
		STBC_e_WUFEN 	WUFEN20    	:1;
		STBC_e_WUFEN 	WUFEN21    	:1;
		STBC_e_WUFEN 	WUFEN22    	:1;
		STBC_e_WUFEN 	WUFEN23    	:1;
		STBC_e_WUFEN 	WUFEN24    	:1;
		STBC_e_WUFEN 	WUFEN25    	:1;
		STBC_e_WUFEN 	WUFEN26    	:1;
		STBC_e_WUFEN 	WUFEN27    	:1;
		STBC_e_WUFEN 	WUFEN28    	:1;
		STBC_e_WUFEN 	WUFEN29    	:1;
		STBC_e_WUFEN 	WUFEN30    	:1;
		STBC_e_WUFEN 	WUFEN31    	:1;
	}BIT;
}STBC_s_WUF1EN_A1;


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_standby_reg_H__ */

