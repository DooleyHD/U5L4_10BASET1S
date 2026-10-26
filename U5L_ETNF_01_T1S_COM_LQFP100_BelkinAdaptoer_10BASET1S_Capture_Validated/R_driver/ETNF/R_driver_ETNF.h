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
* File Name    : R_driver_ETNF.h
* Version      : 1.00
* Device(s)    : ETNF
* Description  : This is header file for ETNF function.
*******************************************************************************/

/*******************************************************************************
* Ver.1.00     : 2024/06/20
*                - Create New
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__U2B_ETNF_H__
#define	__U2B_ETNF_H__

/*******************************************************************************
* Includes
*******************************************************************************/
#include "product.h"
#include "R_driver_typedef.h"
#include "R_driver_general.h"
#include "config.h"

#include "R_device_ETNF.h"
#include "R_driver_ETNF_reg.h"


/*******************************************************************************
* Register base address definition
*******************************************************************************/
/* Register base address */
extern const uint32_t	ETNFn_base_addr[];
extern const uint32_t	ETNFn_T1S_base_addr[];

#define	ETNFn_base(n)   	ETNFn_base_addr[n]
#define	ETNFn_T1S_base(n)	ETNFn_T1S_base_addr[n]


/*******************************************************************************
* Definition
*******************************************************************************/
/* frame */
#define ETNF_HEADER_SIZE	14U

/* Receive FIFO Warning Level */
#define	ETNF_RFCL_DEFAULT	0x1800

/* PLCA Setting */
#define ETNF_PLCA_ADDR_DEFAULT	0x02
#define ETNF_rPLCA_CONTROL_REG	0x000000
#define ETNF_rPLCA_STATUS_REG 	0x000001
#define ETNF_rPLCA_PLCAIDVER  	0x3FCA00
#define ETNF_rPLCA_PLCACTRL0  	0x3FCA01
#define ETNF_rPLCA_PLCACTRL1  	0x3FCA02
#define ETNF_rPLCA_PLCAST     	0x3FCA03
#define ETNF_rPLCA_PLCATOTMR  	0x3FCA04
#define ETNF_rPLCA_PLCABURST  	0x3FCA05
#define ETNF_rPLCA_PLCADIAG   	0x3FCA06
#define ETNF_rPLCA_CTIPVER    	0x3F8000
#define ETNF_rPLCA_T1STWEAKS  	0x3F8001
#define ETNF_rPLCA_T1SPLCAEXT 	0x3F8002
#define ETNF_rPLCA_T1SPMATUNE0	0x3F8003
#define ETNF_rPLCA_T1SPMATUNE1	0x3F8004
#define ETNF_rPLCA_T1STXCCTL  	0x3F8005
#define ETNF_rPLCA_T1STXCST   	0x3F8006
#define ETNF_rPLCA_T1SPCSCTRL 	0x2308F3
#define ETNF_rPLCA_T1SPCSST   	0x2308F4
#define ETNF_rPLCA_T1SPCSDIAG1	0x2308F5
#define ETNF_rPLCA_T1SPCSDIAG2	0x2308F6
#define ETNF_rPLCA_T1SPMACTRL 	0x2108F9
#define ETNF_rPLCA_T1SPMAST   	0x2108FA
#define ETNF_rPLCA_T1SPMATSTM 	0x2108FB

#define NULL_PTR	((void *)0)

/* used but has not optimisation
*******************************************************************************/
/* index of variable ETNF_CurrTxDesc */
#define	ETH_MAX_NUM_OF_DIE	15U

/* R_ETNF_Config_AVBDMAC_Rx */
#define	ETH_NUM_OF_RQC_REG	5U

/* PHY Setting */
/* App_InitSetting_EMAC */
#define	ETH_PHY_RESET	0x8000U
#define	ETH_PHY_RESET_REQ_CLEARED	0x0000U

/* R_ETNF_KeepLevel_MDC */
#define	ETH_PHY_MDC_DELAY	1000U


#define	ETH_PHY_CONTROL_REG_ID	0U

/* ETNF_PHYSetting */
#define PHY_LINKUP	0x0004U
#define PHY_ALL_HIGH_LEVEL	0xFFFFU

/* R_ETNF_WritePhyReg */
#define ETNF_MDC_HIGH	0x1U
#define ETNF_MDC_LOW 	0x0U
#define ETNF_MMD_READ	0x0U
#define ETNF_MMD_WRITE	0x2U
#define ETNF_MDO_HIGH	0x4U
#define ETNF_MDO_LOW  	0x0U

/* App_ConfigureT1SPHYSetting */
#define ETNF_rPLCA_STATUS_REG_DONE	( (1 << 5) |	/* LNOK=1: link negotiation is complete. */ \
                                  	  (1 << 3) |	/* ANAB=1: the PHY supports the Auto-Negotiation interface */ \
                                  	  (1 << 2) |	/* LKST=1: a valid link has been established */ \
                                  	  (1 << 0)) 	/* EXTC=1: the PHY supports Clause 22 to Clause 45 bridge access method */

/* T1S T1STXCCTL register */
typedef enum{
	ETNF_e_T1S_CMD_NORQ     = 0,	/* Normal operation */
	ETNF_e_T1S_CMD_SLEEPRQ  = 1,	/* SLEEP request to the TXC */
	ETNF_e_T1S_CMD_CONFIGRQ = 2,	/* CONFIG request to the TXC */
	ETNF_e_T1S_CMD_RESETRQ  = 3 	/* Forces RESET requests to the TXC repeatedly */
}ETNF_e_T1S_CMD;
									  
/* no check
*******************************************************************************/
/* gPTP Timer Setting */
#define	CCC_CSEL_MASK                                   0x00030000UL
#define ETH_GCCR_LTI_REQ                                0x00000008UL
#define ETH_GCCR_LTO_REQ                                0x00000004UL
#define ETH_TCCR_TS_MASK                                0x00000100UL
#define ETH_TFWE_MASK                                   0x00000200UL
#define ETH_TFUE_MASK                                   0x00000100UL
#define TCCR_TFR_RELEASE_OLDEST_ENTRY                   0x00000200UL
#define TSR_TFFL_MASK                                   0x00000300UL
#define TFA2_TSV_MASK                                   0x0000FFFFUL
#define TFA2_TST_MASK                                   0x03FF0000UL
#define ETH_MAX_NUM_OF_COMPARE_UNIT                     8U
#define GCCR_LMTT_REQ                                   0x00000020UL
#define GCCR_LMTT_MASK                                  0x00000020UL
#define GCCR_LMTT_COMPLETED_REQUEST                     0x00000000UL
#define GCCR_TCR_MASK                                   0x00000003UL
#define GCCR_TCR_RESET                                  0x00000001UL
#define GCCR_TCR_CONTINUOUS_AVTP_CAPTURE                0x00000002UL
#define GCCR_TCR_COMPLETED_REQUEST                      0x00000000UL
#define GCCR_TCR_CAPTURE_TCSS_SETTING                   0x00000003UL

#define GCCR_LPTC_MASK                                  0x00000010UL
#define GCCR_LPTC_REQ                                   0x00000010UL
#define GCCR_LPTC_COMPLETED_REQUEST                     0x00000000UL
#define GCCR_LI_MASK                                    0x00700000UL
#define GCCR_SPC_MASK                                   0x00080000UL
#define GCCR_SPC_SINGLE_MODE                            0x00000000UL
#define GCCR_TCSS_GPTP_TIMER                            0x00000000UL
#define GCCR_TCSS_ADJUSTED_GPTP_TIMER                   0x00000100UL
#define GCCR_TCSS_AVTP_PRESENTATION_TIME                0x00000200UL

#define GCCR_TCSS_NO_CHANGE                             0x00000300UL

/* ETNF_CBSSetting */
#define	ETH_CBS_QUEUE_OFFSET	2U
#define ETH_NUM_OF_TX_QUEUE_USED_CBS	2U

/* Interrupt Setting */	/* ETNF_LoadDescBaseAddr */
#define	DLR_LBA_ALL_COMPLETED	0x00000000UL

#define GSR_AFU_ADD_AVTP_FIFO_COMPARE_VALUE_COMPLETED   0x00000000UL
#define GSR_AFFL_MASK                                   0x0000000FUL
#define ETH_TOTAL_NUM_OF_AVTP_FIFO_COMPARE_CONFIG_VALUE 15U
#define ETH_NUM_OF_AVTP_FIFO_COMPARE_UNIT               4U

#define GIS_PTMF_0                                      0x00000004UL
#define GIS_PTMF_1                                      0x00000008UL
#define GIS_PTMF_2                                      0x00000010UL
#define GIS_PTMF_3                                      0x00000020UL
#define GIS_PTMF_4                                      0x00000040UL
#define GIS_PTMF_5                                      0x00000080UL
#define GIS_PTMF_6                                      0x00000100UL
#define GIS_PTMF_7                                      0x00000200UL

#define GSR_AFU_24BIT_SHIFT                             24U
#define GSR_AFU_1BIT_MASK                               1U
#define GSR_AFU_0                                       0x01000000UL
#define GSR_AFU_1                                       0x02000000UL
#define GSR_AFU_2                                       0x04000000UL
#define GSR_AFU_3                                       0x08000000UL

#define TIS_TFUF_MASK                                   0x00000100UL
#define TIS_TFWF_MASK                                   0x00000200UL
#define TIS_TFUF_TIMESTAMP_FIFO_UPDATED                 0x00000100UL
#define TIS_TFWF_TIMESTAMP_FIFO_WARNING                 0x00000200UL


/** ETNF - Size of Registers Arrays */
#define ETNF_NUM_TXQ     	4u	/* total number of TX Queue */
#define ETNF_NUM_RXQ      	18u	/* total number of RX Queue */
#define ETNF_NUM_DESCQ    	(ETNF_NUM_TXQ + ETNF_NUM_RXQ)	/* total number of descriptor Queue */
#define ETNF_NUM_RX_CONFIG	5

#define ETNF_BDAT_TX_START_INDEX                     0
#define ETNF_BDAT_RX_START_INDEX                     ETNF_NUM_TXQ

#define SEPARATION_FILTER_QUEUE_MIN                  2
#define SEPARATION_FILTER_QUEUE_MAX                  17
#define ETNF_RX_FILTER_QUEUE_COUNT                   (SEPARATION_FILTER_QUEUE_MAX - SEPARATION_FILTER_QUEUE_MIN + 1)
#define ETNF_SFP_COUNT                               (ETNF_RX_FILTER_QUEUE_COUNT << 1)

#define TX_CBS_QUEUE_MIN                             2
#define TX_CBS_QUEUE_MAX                             3
#define ETNF_CBS_COUNT                               (TX_CBS_QUEUE_MAX - TX_CBS_QUEUE_MIN + 1)    /* TX queue 2 and 3 */

#define ETNF_MAC_ADDRESS_SIZE                        6

#define	ETH_MAX_NUM_OF_RX_QUEUE                         18U

// update
/* ETNFnPIR PHY Interface Register */	
#define ETNFnPIR_MDC_SHIFT                 0
#define ETNFnPIR_MDC_MASK                  (0x1U << ETNFnPIR_MDC_SHIFT)
#define ETNFnPIR_MDC(x)                    (((uint32_t)(x) << ETNFnPIR_MDC_SHIFT) & ETNFnPIR_MDC_MASK)

#define ETNFnPIR_MMD_SHIFT                 1
#define ETNFnPIR_MMD_MASK                  (0x1U << ETNFnPIR_MMD_SHIFT)
#define ETNFnPIR_MMD(x)                    (((uint32_t)(x) << ETNFnPIR_MMD_SHIFT) & ETNFnPIR_MMD_MASK)

#define ETNFnPIR_MDO_SHIFT                 2
#define ETNFnPIR_MDO_MASK                  (0x1U << ETNFnPIR_MDO_SHIFT)
#define ETNFnPIR_MDO(x)                    (((uint32_t)(x) << ETNFnPIR_MDO_SHIFT) & ETNFnPIR_MDO_MASK)

#define ETNFnPIR_MDI_SHIFT                 3
#define ETNFnPIR_MDI_MASK                  (0x1U << ETNFnPIR_MDI_SHIFT)
#define ETNFnPIR_MDI(x)                    (((uint32_t)(x) << ETNFnPIR_MDI_SHIFT) & ETNFnPIR_MDI_MASK)

#define PHY_MII_PRE_VALUE                  0xFFFFFFFF
#define PHY_MII_ST                         0x1
#define PHY_MII_OP_READ                    0x2
#define PHY_MII_OP_WRITE                   0x1
#define PHY_MII_TA_WRITE                   0x2
// update

/*******************************************************************************
* Type definition for configuration functions
*******************************************************************************/
/* Configuration of EMAC */
typedef struct{
	ETNF_e_TRCCM	TRCCM;	/* Counter Clear Mode */
	ETNF_e_RCSC 	RCSC; 	/* Checksum Calculation */
	ETNF_e_DPAD 	DPAD; 	/* Data Padding */
	ETNF_e_RZPF 	RZPF; 	/* PAUSE Frame Reception with Time = 0 */
	ETNF_e_ZPF  	ZPF;  	/* PAUSE Frame Usage with TIME = 0 Enable/Disable CRS Assert Check */
	ETNF_e_PFR  	PFR;  	/* PAUSE Frame Receive Mode */
	ETNF_e_RXF  	RXF;  	/* Reception Flow Control Operation Mode */
	ETNF_e_TXF  	TXF;  	/* Transmission Flow Control Operation Mode */
	ETNF_e_DM    	DM;   	/* Mode selection */
	ETNF_e_PRM   	PRM;  	/* Promiscuous Mode */
}ETNF_s_Config_EMAC_Mode;

/* Configuration of T1S PHY */
typedef struct{
	ETNF_e_PMA_CFG  	pma_cfg;   	/* enable filter of T1S energy detection pin */
	ETNF_e_MDIO_SHARE	mdio_share;	/* select MDIO I/F */
	uint8_t          	phy_add:5;	/* PHY MDIO address */
}ETNF_s_Config_T1S;

/* Configuration of EMAC */
typedef struct{
	uint32_t	mahr;	/* lower 4bytes of MAC address (1st:2nd:3rd:4th) */
	uint16_t	malr;	/* upper 2bytes of MAC address (5th:6th) */
	uint32_t	size;	/* reception frame size */
	ETNF_e_ICDIP	icdip;	/* False Carrier Detect Interrupt Enable */
	ETNF_s_Config_EMAC_Mode ECMR;	/* ECMR regisger */
}ETNF_s_Config_EMAC;

/* configuration of AVB-DMAC for reception */
typedef struct{
	uint16_t    	RFCL;	/* Receive FIFO Warning Level */
	ETNF_e_ETS2 	ETS2;	/* Timestamp Enable (Stream) */
	ETNF_e_ETS0 	ETS0;	/* Timestamp Enable (Best Effort) */
	ETNF_e_ESF  	ESF;	/* Stream Filtering Select */
	ETNF_e_ENCF 	ENCF;	/* Network Control Filtering Enable */
	ETNF_e_EFFS 	EFFS;	/* Error Frame Enable */
	uint8_t     	DCNT;	/* Stored Data Counter [word] */
	uint8_t     	PCNT;	/* Stored Padding Counter [word] */
	uint8_t     	rxq_num;	/* number of RX queue */
}ETNF_s_Config_AVBDMAC_RX;

/* configuration for separation filter common */
typedef struct{
	uint8_t 	offset;
	uint32_t	fl_mask_lower;	/* filter mask of lower 32-bit */
	uint32_t	fl_mask_upper;	/* filter mask of upper 16-bit */
}ETNF_s_Config_sFilter_common;

/* configuration for separation filter */
typedef struct{
	uint8_t 	num;
	uint32_t	fl_value_lower;	/* filter address of lower 32-bit */
	uint32_t	fl_value_upper;	/* filter address of upper 16-bit */
}ETNF_s_Config_sFilter;

/* configuration of AVB-DMAC for transmission */
typedef struct{
	/* ETNFnTGC register */
	uint8_t   	TBD3;	/* Transmit FIFO Size (Stream Class A) */
	uint8_t   	TBD2;	/* Transmit FIFO Size (Stream Class B) */
	uint8_t   	TBD1;	/* Transmit FIFO Size (Network Control) */
	uint8_t   	TBD0;	/* Transmit FIFO Size (Best Effort) */
	ETNF_e_TQP	TQP; 	/* Transmit Queue Priority */
	uint8_t   	MFEN;	/* MAC status FIFO Enable */
	uint8_t   	TFEN;	/* Timestamp FIFO Enable */
}ETNF_s_Config_AVBDMAC_TX;

/* configuration of AVB-DMAC for receive queue */
typedef struct{
	uint8_t 	queue;	/* queue number to configure */
	ETNF_e_PIA 	PIA;  	/* Packed Incremental Data Area */
	ETNF_e_UFCC	UFCC;	/* Unread Frame Counter Configuration */
}ETNF_s_Config_AVBDMAC_RXQ;


typedef struct STag_Eth_CBSConfig
{
	uint8_t ucCBSEnableTxQueueNum;
	uint32_t ulCIV;
	uint32_t ulCDV;
	uint32_t ulCUL;
	uint32_t ulCLL;
} Eth_CBSConfig;


typedef struct STag_Eth_PHYCtrlRegConfig
{
	uint8_t phy_addr;
	uint8_t ucPHYLoopBack;
	uint8_t ucPHYSpeed;
	uint8_t ucPHYAutoNegotiationEnable;
	uint8_t ucPHYPowerDown;
	uint8_t ucPHYIsolate;
	uint8_t ucPHYRestartNegotiation;
	uint8_t ucPHYDuplexMode;
} Eth_PHYCtrlRegConfig;


/*******************************************************************************
* Type definition for Descriptor
*******************************************************************************/
/* Descriptor Types */
typedef enum{
	ETNF_e_DT_FSTART  = 5UL,
	ETNF_e_DT_FMID    = 4UL,
	ETNF_e_DT_FEND    = 6UL,
	ETNF_e_DT_FSINGLE = 7UL,
	ETNF_e_DT_FEMPTY  = 12UL,
	ETNF_e_DT_LINK    = 8UL,
	ETNF_e_DT_LINKFIX = 9UL,
	ETNF_e_DT_LEMPTY  = 2UL,
	ETNF_e_DT_EOS     = 10UL,
	ETNF_e_DT_EEMPTY  = 3UL
}ETNF_e_DT;

/* Descriptor Interrupt Enable */
typedef enum{
	ETNF_e_DIE_disable = 0,	/* disable */
	/* The interrupt corresponding ETNFnDIS.DPFi is enalbe */
	ETNF_e_DIE_DSF1    = 1,
	ETNF_e_DIE_DSF2    = 2,
	ETNF_e_DIE_DSF3    = 3,
	ETNF_e_DIE_DSF4    = 4,
	ETNF_e_DIE_DSF5    = 5,
	ETNF_e_DIE_DSF6    = 6,
	ETNF_e_DIE_DSF7    = 7,
	ETNF_e_DIE_DSF8    = 8,
	ETNF_e_DIE_DSF9    = 9,
	ETNF_e_DIE_DSF10   = 10,
	ETNF_e_DIE_DSF11   = 11,
	ETNF_e_DIE_DSF12   = 12,
	ETNF_e_DIE_DSF13   = 13,
	ETNF_e_DIE_DSF14   = 14,
	ETNF_e_DIE_DSF15   = 15
}ETNF_e_DIE;

/* Payload CRC Status in Content control for reception */
typedef enum{
	ETNF_e_PC_not_match = 0,	/* Payload CRC is not matching */
	ETNF_e_PC_match     = 1 	/* Payload CRC is correct */
}ETNF_e_PC;

/* Padding Selection */
typedef enum{
	ETNF_e_PS_not_insert = 0,	/* Padding is not to be inserted */
	ETNF_e_PS_insert     = 1 	/* Padding data may be inserted */
}ETNF_e_PS;

/* Error Indication */
typedef enum{
	ETNF_e_EI_no_error = 0,	/* No error */
	ETNF_e_EI_error    = 1 	/* Error is detected */
}ETNF_e_EI;

/* Truncation Indication */
typedef enum{
	ETNF_e_EI_not_truncated = 0,	/* Data have not been truncated */
	ETNF_e_EI_truncated     = 1	/* Data have been truncated */
}ETNF_e_TR;

/* Content control for reception */
typedef struct{
	ETNF_e_TR	TR :1;	/* Truncation Indication */
	ETNF_e_EI	EI :1;	/* Error Indication */
	ETNF_e_PS	PS :1;	/* Padding Selection */
	ETNF_e_PC	PC :1;	/* Payload CRC Status in Content control for reception */
	uint16_t	MSC:8;	/* MAC Status Code */
}ETNF_s_CTRL_RX;

/* MAC Status storage Request */
typedef enum{
	ETNF_e_MSR_no_info   = 0,	/* No status information is stored */
	ETNF_e_MSR_kept_info = 1	/* Status information is to be kept for this frame in MAC status FIFO */
}ETNF_e_MSR;

/* Timestamp Store Request */
typedef enum{
	ETNF_e_TSR_not_retain_ts = 0,	/* The timestamp FIFO within the EthernetAVB module does not retain a transmission timestamp. */
	ETNF_e_TSR_retain_ts     = 1	/* The timestamp FIFO within the EthernetAVB module retains a transmission timestamp */
}ETNF_e_TSR;

/* Content control for transmission */
typedef union{
	uint16_t  	ALL;
	struct{
		uint16_t	TAG:10;	/* Frame Tag */
		ETNF_e_TSR	TSR:1;	/* Timestamp Store Request */
		ETNF_e_MSR	MSR:1;	/* MAC Status storage Request */
	}BIT;
}ETNF_s_CTRL_TX;

/* descriptor type */
typedef enum{
	ETNF_e_DescType_normal, 	/* Normal descriptor */
	ETNF_e_DescType_extend, 	/* Extended descriptor */
	ETNF_e_DescType_common  	/* When not distinguishing between Normal and Extended descriptors */
}ETNF_e_DescType;

/* Normal descriptor (usable in both reception and transmission) */
typedef struct{
	uint32_t  	DS  : 12;
	uint32_t  	CTRL: 12;
	ETNF_e_DIE	DIE : 4;
	ETNF_e_DT 	DT  : 4;
	uint32_t  	DPTR;
}ETNF_s_DescType_Normal;

/* Extended descriptor (usable only in reception) */
typedef struct{
	uint32_t  	DS  : 12;
	uint32_t  	CTRL: 12;
	ETNF_e_DIE	DIE : 4;
	ETNF_e_DT 	DT  : 4;
	uint32_t  	DPTR;
	uint32_t  	TS0;
	uint32_t  	TS1;
	uint16_t  	TS2;
	uint16_t  	reserved;
}ETNF_s_DescType_Extend;

/* for When not distinguishing between Normal and Extended descriptors */
#define	ETNF_s_DescType_Common	ETNF_s_DescType_Extend

/* Bit position of Ethernet frame */
typedef enum{
	ETNF_e_frameindex_DA1  = 0, 	/* Destination address (1st byte) */
	ETNF_e_frameindex_DA2  = 1, 	/* Destination address (2nd byte) */
	ETNF_e_frameindex_DA3  = 2, 	/* Destination address (3rd byte) */
	ETNF_e_frameindex_DA4  = 3, 	/* Destination address (4th byte) */
	ETNF_e_frameindex_DA5  = 4,	/* Destination address (5th byte) */
	ETNF_e_frameindex_DA6  = 5,	/* Destination address (6th byte) */	
	ETNF_e_frameindex_SA1  = 6, 	/* Source address (1st byte) */
	ETNF_e_frameindex_SA2  = 7, 	/* Source address (2nd byte) */
	ETNF_e_frameindex_SA3  = 8, 	/* Source address (3rd byte) */
	ETNF_e_frameindex_SA4  = 9, 	/* Source address (4th byte) */
	ETNF_e_frameindex_SA5  = 10, 	/* Source address (5th byte) */
	ETNF_e_frameindex_SA6  = 11, 	/* Source address (6th byte) */
	ETNF_e_frameindex_ET1  = 12,	/* Ethernet type (1st byte) */
	ETNF_e_frameindex_ET2  = 13,	/* Ethernet type (2nd byte) */
	ETNF_e_frameindex_Data = 14 	/* start of payload data */	
	
}ETNF_e_frameindex_ET;


/*******************************************************************************
* Type definition for ethernet frame
*******************************************************************************/
/* Ethernet frame */
typedef union{
	uint8_t	SA[6];	/* Destination address */
	uint8_t	DA[6];	/* source address */
	uint8_t	ET[2];	/* Ethernet type */
	uint8_t *payload;
}ETNF_s_frame;

/* Ethernet type */
typedef enum{
	ETNF_e_type_IPv4 = 0x0800,	/* Internet IP (IPv4) */
	ETNF_e_type_ARP  = 0x0806,	/* Address Resolution Protocol (ARP) */
	ETNF_e_type_RARP = 0x8035,	/* Reverse Address Resolution Protocol (RARP) */
	ETNF_e_type_VMTP = 0x805B,	/* Versatile Message Transaction Protocol (VMTP) */
	ETNF_e_type_APTK = 0x809B,	/* AppleTalk ( EtherTalk ) */
	ETNF_e_type_AARP = 0x80F3,	/* AppleTalk Address Resolution Porotocol (AARP) */
	ETNF_e_type_IPX  = 0x8137,	/* Novell Netware (IPX) */
	ETNF_e_type_SNMP = 0x814C,	/* SNMP over Ethernet */
	ETNF_e_type_NetBIOS   = 0x8191,	/* NetBIOS/NetBEUI */
	ETNF_e_type_XTP       = 0x817D,	/* XTP */
	ETNF_e_type_IPv6      = 0x86DD,	/* IP version 6 (IPv6) */
	ETNF_e_type_PPPoE_Dis = 0x8863,	/* PPPoE Discovery Stage */
	ETNF_e_type_PPPoE_Ses = 0x8864,	/* PPPoE Session Stage */
	ETNF_e_type_LB        = 0x9000 	/* Loopback ( Configuration Test Protocol ) */
}ETNF_e_type;

/* configuration of the descriptor base address table 
 * other than fields set fixed value in the function R_ETNF_Config_DBAT. */
typedef struct{
	uint32_t       	addr;  	/* base address */
	ETNF_e_DescType	type;	/* descriptor type (Normal or Extended) */
}ETNF_s_Config_DBAT;

typedef struct STag_Eth_gPTPTimerOffsetConfig
{
	uint32_t ulTimerOffsetLower;
	uint32_t ulTimerOffsetMid;
	uint16_t usTimerOffsetUpper;
} Eth_gPTPTimerOffsetConfig;


typedef struct STag_Eth_CaptureTimerConfig
{
	uint32_t ulMaxTransitionTime;
	uint8_t ucCaptureSource;
} Eth_CaptureTimerConfig;


typedef struct STag_Eth_TimestampFIFOConfig
{
	uint8_t TFEN;
	uint8_t ucTimerstampWarninglevelIntEnable;
	uint8_t ucTimerstampUpdateIntEnable;
} Eth_TimestampFIFOConfig;


typedef struct{
	uint32_t TS0;
	uint32_t TS1;
	uint16_t TS2;
	uint16_t usTag;
}ETNF_s_TSResult;

typedef struct{
	uint32_t TS0;
	uint32_t TS1;
	uint16_t TS2;
}ETNF_s_TimerCapResult;


typedef struct STag_Eth_AVTPCompareConfig
{
	uint8_t ucCompareUnitNum;
	uint8_t ucTotalNumofCompareData;
	const uint32_t * pulCompareDataAddr;
} Eth_AVTPCompareConfig;


/*******************************************************************************
* Unit Number definition
*******************************************************************************/
/* no definition */


/*******************************************************************************
* Prototype declarations of functions and
* Functional definitions
*******************************************************************************/
void R_ETNF_CurrentTxDescSetting( ETNF_s_DescType_Normal * pstTxDescQueueAddr, uint8_t ucTotalNumOfDesc );

extern void _IntFunc_INTETNF0DATA( void );
extern void _IntFunc_INTETNF0MNG( void );

void ETNF_TXNotification( ETNF_s_DescType_Normal * pTxDescAddr );
void ETNF_TSNotification( void );
void ETNF_AVTPComparisonNotification( uint32_t ulCompareUnit );

/*******************************************************************************
* Description  : Get current operation mode
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : ETNF_e_OPS ops: operation mode (ENTFnCSR.OPS bit value)
*******************************************************************************/
#define	R_ETNF_Get_CurrentMode(n)	(ETNF_e_OPS)(Reg32Read(rETNFnCSR(n)) & 0x00000007)

/*******************************************************************************
* Description  : Set operation mode
*                This function only sets operation mode to CCC.OPC bits.
*                This function only uses in the function R_ETNF_ChangeMode.
* Arguments    : uint8_t  n  : unit number of ETNF
*                ETNF_e_OPC opc: operation mode (ENTFnCCC.OPC bit value)
* Return Value : (none)
*******************************************************************************/
#define	R_ETNF_SetMode(n,opc)	Reg32RMWC( &rETNFnCCC(n), opc, 0x3, 0 );	/* OPC = opc */

/*******************************************************************************
* Description  : Get current operation mode
* Arguments    : uint8_t  n  : unit number of ETNF
*                ETNF_e_OPS ops: operation mode (ETNFnCSR.OPS bit value)
* Return Value : (none)
*******************************************************************************/
#define	R_ETNF_WaitModeChenge(n,ops)	while( (Reg32Read(rETNFnCSR(n)) & 0x00000007) != ops );

/*******************************************************************************
* Description  : Operation Mode Change
* Arguments    : uint8_t  n  : unit number of ETNF
*                uint8_t mode : Mode to change
* Return Value : (none)
*******************************************************************************/
void R_ETNF_ChangeMode( uint8_t n, ETNF_e_OPC mode );

/*******************************************************************************
* Description  : E-MAC Initialization
* Arguments    : uint8_t n                 : unit number of ETNF
*                ETNF_s_Config_EMAC *config: Configuration value for E-MAC
* Return Value : (none)
*******************************************************************************/
uint8_t R_ETNF_ConfigEMAC( uint8_t n, ETNF_s_Config_EMAC *config );

/*******************************************************************************
* Description  : Configuration of T1S PHY
* Arguments    : uint8_t  n  : unit number of ETNF
*                ETNF_s_Config_T1S config : Configuration of T1S PHY
* Return Value : (none)
*******************************************************************************/
uint8_t R_ETNF_Config_T1SPHY( uint8_t n, ETNF_s_Config_T1S config );

/*******************************************************************************
* Description  : Enable AVB loop back
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : (none)
*******************************************************************************/
#define	R_ETNF_EnableAVBLB(n)	Reg32SetBitCheck( &rETNFnCCC(n), 24 )	/* LBMO=1 */

/*******************************************************************************
* Description  : Cpnfiguration fo receive frame interrupt
* Arguments    : uint8_t  n  : unit number of ETNF
*                uint8_t queue_word: Specify the RX Queue to enable interrupt.
*                                    The bit position corresponds to the TX queue index.
*                            ex) 0x00000001: RX queue 0
*                                0x0000000F: RX queue 3-0
*                                0x0003FFFF: RX queue 17-0
* Return Value : (none)
*******************************************************************************/
#define	R_ETNF_ConfigRxInt(n,queue_word)	Reg32WRC( &rETNFnRIC0(n), queue_word, 0x0003FFFF )	/* FRE17-0=queue_word */

/*******************************************************************************
* Description  : AVB-DMAC Rx Setting
* Arguments    : uint8_t  n  : unit number of ETNF
*                ETNF_s_Config_AVBDMAC_RX  *config_rx : Configuration ric for AVB-DMAC Rx
*                ETNF_s_Config_AVBDMAC_RXQ *config_rxq: Configuration ric for Rx Queue
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_ETNF_Config_AVBDMAC_Rx( uint8_t n, ETNF_s_Config_AVBDMAC_RX *config_rx, ETNF_s_Config_AVBDMAC_RXQ *config_rxq );

/*******************************************************************************
* Description  : Configure Separation Filter Offset
* Arguments    : uint8_t n     : unit number of ETNF
*                uint8_t offset: Filter offset value
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_ETNF_SetsFilterOffset(n,offset)	Reg32WRC( &rETNFnSFO(n), offset, 0x0000003F )

/*******************************************************************************
* Description  : Configure Separation Filter Pattern
* Arguments    : uint8_t  n  : unit number of ETNF
*                ETNF_s_Config_sFilter *config: Configuration value for Separation filter
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_ETNF_Config_sFilterPattern( uint8_t n, ETNF_s_Config_sFilter *config );

/*******************************************************************************
* Description  : Configure Separation Filter Mask
* Arguments    : uint8_t  n  : unit number of ETNF
*                ETNF_s_Config_sFilter_common *config: Configuration value for Separation filter Mask setting
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_ETNF_Config_sFilterMask( uint8_t n, ETNF_s_Config_sFilter_common *config );

/*******************************************************************************
* Description  : AVB-DMAC Tx Setting
* Arguments    : uint8_t  n  : unit number of ETNF
*                ETNF_s_Config_AVBDMAC_TX *config: Configuration value for AVB-DMAC Tx
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_ETNF_Config_AVBDMAC_Tx( uint8_t n, ETNF_s_Config_AVBDMAC_TX *config );

/*******************************************************************************
* Description  : Cpnfiguration fo descriptor interrupt
* Arguments    : uint8_t  n  : unit number of ETNF
*                uint8_t queue_word: Specify the descriptor to enable interrupt.
*                                    The bit position corresponds to the descriptor index.
*                            ex) 0x00000002: descriptor 1
*                                0x0000000E: descriptor 3-1
*                                0x0000FFFE: descriptor 15-1
* Return Value : (none)
*******************************************************************************/
#define	R_ETNF_ConfigDescInt(n,desc_hword)	Reg32WRC( &rETNFnDIC(n), desc_hword, 0x0000FFFE )	/* DPE15-1=desc_hword */

/*******************************************************************************
* Description  : Descriptor Base Address Table Setting
* Arguments    : uint8_t  n   : unit number of ETNF
*                uint32_t addr: Base address of the descriptor table in the URAM
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_ETNF_SetDescBaseAddrTable(n,addr)	Reg32WRC( &rETNFnDBAT(n), addr, 0xFFFFFFFF )

/*******************************************************************************
* Description  : Base Descriptor Queue Setting
* Arguments    : uint8_t  n   : unit number of ETNF
*                uint32_t addr[]: Descriptor Queue Address
*                ETNF_s_DescType_Normal dbat[]: Descriptor base address table
* Return Value : (none)
*******************************************************************************/
void R_ETNF_Config_DBAT( uint8_t n, uint32_t addr[], ETNF_s_DescType_Normal dbat[] );

/*******************************************************************************
* Description  : Set destination address to frame
* Arguments    : ETNF_s_DescType_Normal *desc_queue_addr : Tx Descriptor Queue Address
*                uint8_t total_num: Total Number of Descriptor
* Return Value : (none)
*******************************************************************************/
void R_ETNF_SetFrameDA( uint8_t *frame, uint8_t addr[] );

/*******************************************************************************
* Description  : Set source address to frame
* Arguments    : ETNF_s_DescType_Normal *desc_queue_addr : Tx Descriptor Queue Address
*                uint8_t total_num: Total Number of Descriptor
* Return Value : (none)
*******************************************************************************/
void R_ETNF_SetFrameSA( uint8_t *frame, uint8_t addr[] );

/*******************************************************************************
* Description  : Set type to frame
* Arguments    : ETNF_s_DescType_Normal *desc_queue_addr : Tx Descriptor Queue Address
*                uint8_t total_num: Total Number of Descriptor
* Return Value : (none)
*******************************************************************************/
void R_ETNF_SetFrameET( uint8_t *frame, uint16_t type );


/*******************************************************************************
* Description  : Enable Transmission and Reception
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_ETNF_Enable_TXRX(n)	Reg32RMWC( &rETNFnECMR(n), 0x3, 0x3, 5 )	/* RE = 1 and TE = 1*/


/*******************************************************************************
* Description  : Enable Reception
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_ETNF_Enable_RX(n)	Reg32SetBitCheck( &rETNFnECMR(n), 6 )	/* RE = 1 */

/*******************************************************************************
* Description  : Stop Transmission
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_ETNF_StopTransmisson( uint8_t n );

/*******************************************************************************
* Description  : Stop Reception
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_ETNF_StopReception( uint8_t n );

/*******************************************************************************
* Description  : Stop And Reset
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_ETNF_StopAndReset( uint8_t n );

/*******************************************************************************
* Description  : Request Frame Transmission
* Arguments    : uint8_t  n  : unit number of ETNF
*                uint8_t queue_byte: Specify the Queue to request transmission.
*                                    The bit position corresponds to the TX queue index.
*                            ex) 0x1 (0000B): TX queue 0
*                                0x5 (0101B): TX queue 2 and TX queue 0
*                                0xF (1111B): TX queue 0 and TX queue 0
* Return Value : (none)
*******************************************************************************/
#define R_ETNF_RequestFrameTransmission(n,queue_byte)	Reg32RMWC( &rETNFnTCCR(n), queue_byte, 0xF, 0 )	/* TSRQ3-0=queue_byte */

/*******************************************************************************
* Description  : Wait Transmission Completed
* Arguments    : uint8_t  n  : unit number of ETNF
* Return Value : (none)
*******************************************************************************/
void R_ETNF_WaitTransmissionComplete( uint8_t n );



/*******************************************************************************
* Description  : Wait for MDC half cycle to keep MDC level
*                The wait time of this function decides period of MDC.
* Arguments    : (none)
* Return Value : (none)
*******************************************************************************/
void R_ETNF_KeepLevel_MDC( void );

/*******************************************************************************
* Description  : 1-bit data write to MII interface
* Arguments    : uint8_t    n  : unit number of ETNF
*                ETNF_e_MDO mdo: output value to MDO pin (0 or 1)
* Return Value : (none)
*******************************************************************************/
void R_ETNF_OutputMO_bit( uint8_t n, ETNF_e_MDO mdo );

/*******************************************************************************
* Description  : 1-bit data read from MII interface
* Arguments    : uint8_t    n  : unit number of ETNF
* Return Value : ETNFnPIR.MDI bit value
*******************************************************************************/
uint8_t R_ETNF_InputMI_bit( uint8_t n );

/*******************************************************************************
* Description  : release MII interface for write sequence
* Arguments    : uint8_t    n  : unit number of ETNF
* Return Value : (none)
*******************************************************************************/
void R_ETNF_ReleaseMO_write( uint8_t n );

/*******************************************************************************
* Description  : release MII interface for read sequence
* Arguments    : uint8_t    n  : unit number of ETNF
* Return Value : (none)
*******************************************************************************/
void R_ETNF_ReleaseMO_read( uint8_t n );

/*******************************************************************************
* Description  : PHY Write Control Register
* Arguments    : uint8_t  n      : unit number of ETNF
*                uint8_t  phyaddr: PHY device address
*                uint8_t  regaddr: PHY register address
*                uint16_t value  : Value to write to DATA field
* Return Value : (none)
*******************************************************************************/
void R_ETNF_WritePhyReg( uint8_t n, uint8_t phyaddr, uint8_t regaddr, uint16_t value );

/*******************************************************************************
* Description  : PHY Read Control Register
* Arguments    : uint8_t  n : unit number of ETNF
*                uint8_t ucPhyAddr: PHY device Address
* Return Value : uint16_t LusPhyReadResult: Read result of PHY STATUS Register
*******************************************************************************/
uint16_t R_ETNF_ReadPhyReg( uint8_t n, uint8_t phyaddr, uint8_t regaddr );

/*******************************************************************************
* Description  : Write to PHY Clause45 Register
* Arguments    : uint8_t  n           : unit number of ETNF
*	           : uint8_t  phyAddr     : PHY address
*	           : uint32_t regAddr     : PHY Register address
*	           : uint16_t write_value : write value
* Return Value : (none)
*******************************************************************************/
void R_ETNF_WritePhyReg_Clause45( uint8_t n, uint8_t phyAddr, uint32_t regAddr, uint16_t write_value );

/*******************************************************************************
* Description  : Read from PHY Clause45 Register
* Arguments    : uint8_t  n           : unit number of ETNF
*	       : uint8_t  phyAddr     : PHY address
*	       : uint32_t regAddr     : PHY Register address
*	       : uint16_t write_value : write value
* Return Value : (none)
*******************************************************************************/
uint16_t R_ETNF_ReadPhyReg_Clause45( uint8_t n, uint8_t phyAddr, uint32_t regAddr );

/*******************************************************************************
* Extern of global variable
*******************************************************************************/


/* for descriptor handling
*******************************************************************************/
/* Holds the the RX normal/extended descriptor currently being processed by the ETNF driver. */
extern ETNF_s_DescType_Common *ETNF_CurrRxDesc[ETNF_NUM_RXQ];

/* Holds the index of the RX descriptor currently being processed by the ETNF driver. */
extern uint8_t R_ETNF_CurrRxDescIndex[ETNF_NUM_RXQ];

/* Holds the the TX descriptor currently being processed by the ETNF driver.
   The index is based on DIE. */
extern ETNF_s_DescType_Normal *ETNF_CurrTxDesc[ETH_MAX_NUM_OF_DIE];

/* for AVTP FIFO
*******************************************************************************/
extern const uint32_t *GpulNextCompareDataAddr[ETH_NUM_OF_AVTP_FIFO_COMPARE_UNIT];
extern uint8_t GucRemainingCompareDataCount[ETH_NUM_OF_AVTP_FIFO_COMPARE_UNIT];


#endif // __U5L_ETNF_H__
