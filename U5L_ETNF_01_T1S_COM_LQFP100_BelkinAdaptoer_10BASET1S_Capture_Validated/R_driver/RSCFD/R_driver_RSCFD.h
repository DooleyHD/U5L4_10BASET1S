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
* File Name    : R_drv_xxx.h
* Version      : 1.00
* Device(s)    : xxx
* Description  : This is source file for xxx driver.
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_RSCFD_H__
#define	__R_driver_RSCFD_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_RSCFD_reg.h"	/* for reference of register structure */
#include "R_device_RSCFD.h"


/*******************************************************************************
* Register definition
*******************************************************************************/

/*******************************************************************************
* Extern of global variables
*******************************************************************************/
/* Register base address of each unit */
extern uint32_t	RSCFDn_base[];
#define	RSCFDn_base(n)	RSCFDn_base[n]


/*******************************************************************************
* Type definitions for function argument
*******************************************************************************/
/* argument for the function R_RSCFD_Config_ReceiveRule */
typedef struct{
	/* ID fiedl, IDE field and RTR field comparison and masking */
	uint32_t        	ID_comp :29;	/* ID field value to compare (RSCFDnCFDGAFLIDj.GAFLID bit) */
	uint32_t        	ID_mask :29;	/* ID field mask for compare (RSCFDnCFDGAFLMj.GAFLIDM bit) */
	RSCFD_e_IDE     	IDE_comp:1; 	/* IDE field value to compare (RSCFDnCFDGAFLIDj.GAFLIDE bit) */
	RSCFD_e_GAFLIDEM	IDE_mask:1; 	/* IDE field mask for compare (RSCFDnCFDGAFLMj.GAFLIDEM bit) */
	RSCFD_e_RTR     	RTR_comp:1; 	/* RTR field value to compare (RSCFDnCFDGAFLIDj.GAFLRTR bit) */
	RSCFD_e_GAFLRTRM	RTR_mask:1; 	/* RTR field mask for compare (RSCFDnCFDGAFLMj.GAFLRTRM bit) */
	
	/* Global Acceptance Filter List Entry Loopback Configuration
	   This bit can enable/disable the AFL entry depending on the Loopback Configuration or 
	   Mirror Mode condition. */
	RSCFD_e_GAFLLB  	GAFLLB :1;	/* RSCFDnCFDGAFLIDj.GAFLLB bit */		
	
	/* Message storage target
	   These values are set to RSCFDnCFDGAFLP1j.GAFLFDP bit. */
	uint8_t          	en_rx_fifos;        	/* Specifies the RX FIFO that is allowed to receive. 
	        	                  	               The bit number corresponds to the RX FIFO number. */
	uint32_t         	en_txrx_fifos   :24;	/* If GAFLSRDx=0, Specifies the TX/RX FIFO that is allowed to receive. 
	        	                  	               The bit number corresponds to the TX/RX FIFO number. */
	uint32_t         	en_tx_queues    :24;	/* If GAFLSRDx=1, Specifies the TX queue that is allowed to receive. */
	RSCFD_e_GAFLSRD0	GAFLSRD0        :1;  	/* Select TX/RX FIFO or TX queue  */
	RSCFD_e_GAFLSRD1	GAFLSRD1        :1;  	/* Select TX/RX FIFO or TX queue  */
	RSCFD_e_GAFLSRD2	GAFLSRD2        :1;  	/* Select TX/RX FIFO or TX queue  */
	RSCFD_e_GAFLRMV     en_rx_buffer    :1;     /* Enable RX buffer that is allowed to receive. */
	uint32_t            rx_buffer_num   :7; 	/* Specifies the RX Buffer that is allowed to receive. 
	                                               This value is set RSCFDnCFDGAFLP0j.GAFLRMDP bit */
	
	/* DLC check */
	RSCFD_e_DLC	min_dlc :4;		/* If the DLC value of the received message is equal or higher than 
	                               the configured DLC value the DLC check is passed. */
	/* Attaching information to receipt message */
	uint16_t	attach_PTR;		/* 16 bit pointer value to attach to receipt messages
	        	            	   This value is set to RSCFDnCFDGAFLP0j.GAFLPTR bit. */
	uint8_t 	attach_IFL :2;	/* 2 bit information label to attach to receipt messages
	        	            	   bit 0 of this value is set to RSCFDnCFDGAFLP0j.GAFLIFL0 bit.
	        	            	   bit 1 of this value is set to RSCFDnCFDGAFLMj.GAFLIFL1 bit. */
}RSCFD_s_config_AFL;

/* argument for the function R_RSCFD_SetPresetBaudRate
   representive baudrate */
typedef enum{
	RSCFD_e_baudrate_Nomi_1M_Data_8M, 	/* Nominal baudrate = 1Mbps, Data Bitrate = 8Mbps */
	RSCFD_e_baudrate_Nomi_1M_Data_5M, 	/* Nominal baudrate = 1Mbps, Data Bitrate = 5Mbps */
	RSCFD_e_baudrate_Nomi_500K_Data_2M	/* Nominal baudrate = 500kps, Data Bitrate = 2Mbps */
}RSCFD_e_baudrate;

/* argument for the function R_RSCFD_SetPresetBaudRate
   CLK_RSCFD frequency */
typedef enum{
	RSCFD_e_freq_80,	/* 80MHz */
	RSCFD_e_freq_40,	/* 40MHz */
	RSCFD_e_freq_20 	/* 20MHz */
}RSCFD_e_freq;

/* buffer type for struct RSCFD_MB */
typedef enum{
	RSCFD_e_MBTYPE_RM,	/* Receive Message Buffer */
	RSCFD_e_MBTYPE_RF,	/* Receive FIFO Access Message Buffer */
	RSCFD_e_MBTYPE_CF,	/* Common FIFO Access Message Buffer */
	RSCFD_e_MBTYPE_TM,	/* Transmit Message Buffer */
	RSCFD_e_MBTYPE_NON	/* message buffer no use */
}RSCFD_e_MBTYPE;

/* message buffer structure */
typedef struct{
	RSCFD_e_DLC   	DLC	  	:4; 	/* DLC field */
	RSCFD_e_IDE 	IDE   	:1; 	/* IDE bit (0: STD-ID packet, 1: EXT-ID packet) */
	RSCFD_e_RTR 	RTR  	:1; 	/* RTR bit (0: Data frame, 1: Remote frame) */
	RSCFD_e_THLEN	THLEN	:1; 	/* Tx History List Entry enable */
	RSCFD_e_FDF  	FDF  	:1; 	/* CANFD Format bit (0: non FD, 1: CANFD) */
	RSCFD_e_BRS  	BRS  	:1; 	/* Bit Rate Switch bit (0: no switch, 1: bit rate switch) */
	RSCFD_e_ESI  	ESI  	:1; 	/* Error State Indicator bit (0: error active node, 1: error passive node) */
	uint8_t      	IFL  	:2; 	/* Information label Field */
	uint32_t    	ID      :29;	/* ID Field (STD-ID: 11 bit / EXT-ID: 29 bit) */
	uint16_t    	TS;         	/* Timestamp field */
	uint16_t    	PTR;        	/* Pointer Field */
	uint8_t     	*DB;         	/* Pointer to payload data area */
}RSCFD_s_MB;

/*******************************************************************************
* Definition
*******************************************************************************/
/* max index number of 1 RSCFD unit */
#define	RSCFD_CH_NUM	(8U)
#define	RSCFD_m_NUM		RSCFD_CH_NUM
#define	RSCFD_j_NUM 	(16U)	/* Number of filter rule number per page */
#define	RSCFD_x_NUM 	(8U)	/* Number of RX FIFO */
#define	RSCFD_a_NUM 	(8U)
#define	RSCFD_k_NUM 	(24U)	/* Number of TX/RX FIFO */
#define	RSCFD_p_NUM		(64U)	/* Number of TX message buffer */
#define	RSCFD_TM_PER_CH_NUM 	(64U)	/* TX message buffer per channel */
#define	RSCFD_RM_PER_CH_NUM 	(16U)	/* RX message buffer per channel */

/* for function RSCFD_SetBaudRate */
/* 160Tq (sample point=70%) */
#define	RSCFD_PREBRG_160TQ_TSEG1	(111U)
#define	RSCFD_PREBRG_160TQ_TSEG2	(48U)
#define	RSCFD_PREBRG_160TQ_SWJ  	(20U)
	
/* 80Tq (sample point=70%) */
#define	RSCFD_PREBRG_80TQ_TSEG1	(55U)
#define	RSCFD_PREBRG_80TQ_TSEG2	(24U)
#define	RSCFD_PREBRG_80TQ_SWJ  	(10U)
	
/* 40Tq (sample point=70%) */
#define	RSCFD_PREBRG_40TQ_TSEG1	(27U)
#define	RSCFD_PREBRG_40TQ_TSEG2	(12U)
#define	RSCFD_PREBRG_40TQ_SWJ  	(4U)
	
/* 20Tq (sample point=70%) */
#define	RSCFD_PREBRG_20TQ_TSEG1	(13U)
#define	RSCFD_PREBRG_20TQ_TSEG2	(6U)
#define	RSCFD_PREBRG_20TQ_SWJ  	(1U)
	
/* 16Tq (sample point=68.75%) */
#define	RSCFD_PREBRG_16TQ_TSEG1	(10U)
#define	RSCFD_PREBRG_16TQ_TSEG2	(5U)
#define	RSCFD_PREBRG_16TQ_SWJ  	(1U)
	
/* 10Tq (sample point=80%) */
#define	RSCFD_PREBRG_10TQ_TSEG1	(7U)
#define	RSCFD_PREBRG_10TQ_TSEG2	(2U)
#define	RSCFD_PREBRG_10TQ_SWJ  	(1U)
	
/* 8Tq (sample point=75%) */
#define	RSCFD_PREBRG_8TQ_TSEG1	(5U)
#define	RSCFD_PREBRG_8TQ_TSEG2	(2U)
#define	RSCFD_PREBRG_8TQ_SWJ  	(1U)
	
/* 5Tq (sample point=60%) */
#define	RSCFD_PREBRG_5TQ_TSEG1	(2U)
#define	RSCFD_PREBRG_5TQ_TSEG2	(2U)
#define	RSCFD_PREBRG_5TQ_SWJ  	(1U)

/* RSCFDnCFDGAFLP1j.GAFLFDP[31:0] */

/*******************************************************************************
* Type definitions for function return value
*******************************************************************************/


/*******************************************************************************
* Prototype declarations of functions
* functional definition
*******************************************************************************/
/*******************************************************************************
* Description  : Preparation for use RSCFD
*                (wait until complete CANRAM initialize and transition to 
*                 Global Reset Mode.)
* Arguments    : uint8_t n: unit number of RSCFD
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_Prepare( uint8_t n, RSCFD_e_DCS dcs );

/*******************************************************************************
* Description  : Releases global stop mode
* Arguments    : uint8_t n: unit number of RSCFD
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_RelaseGloabalStop( uint8_t n );

/*******************************************************************************
* Description  : Releases Channel Stop Mode
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_ReleaseChannelStopMode( uint8_t n, uint8_t m );

/*******************************************************************************
* Description  : Changes specified Global Mode and until the mode changed
* Arguments    : uint8_t n        : unit number of RSCFD
*                RSCFD_e_GMDC gmdc: Global Mode to changing request
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_ChangeGloabalMode( uint8_t n, RSCFD_e_GMDC gmdc );

/*******************************************************************************
* Description  : Changes specified Channel Mode and until the mode changed
* Arguments    : uint8_t n          : unit number of RSCFD
*                uint8_t m          : channel number of RSCFDn
*                RSCFD_e_CHMDC chmdc: Channel Mode to changing request
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_ChangeChannelMode( uint8_t n, uint8_t m, RSCFD_e_CHMDC chmdc );

/*******************************************************************************
* Description  : Select RSCFD communication clock
* Arguments    : uint8_t n: unit number of RSCFD
*                RSCFD_e_DCS dcs: communication clock
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RSCFD_SelectCommunicationClock(n,dcs)	Reg32RMWC( &rRSCFDnCFDGCFG(n).UINT32, dcs, 1, 4 )

/*******************************************************************************
* Description  : Set reception rule total number
* Arguments    : uint8_t n  : unit number of RSCFD
*                uint8_t m  : channel number of RSCFDn
*                uint8_t num: total number of reveive rule
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RSCFD_SetReceiveRuleNumber(n,m,num)	Reg16WRC( &rRSCFDnCFDGAFLCFGm(n,m).UINT16, num, 0x01FF )

/*******************************************************************************
* Description  : Configures reception rule
* Arguments    : uint8_t n          : unit number of RSCFD
*                uint8_t rule_entry   : rule No. to edit
*                RSCFD_s_config_AFL *config: Configuration of reception rule
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_Config_ReceiveRule( uint8_t n, uint16_t rule_entry, RSCFD_s_config_AFL *config  );

/*******************************************************************************
* Description  : Configures Nominal Baudrate
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                RSCFD_s_RSCFDnCFDCmNCFG config: configuration of Nominal Baudrate
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RSCFD_Config_NominalBaudrate(n,m,config)	Reg32WRC( &rRSCFDnCFDCmNCFG(n,m).UINT32, config, 0xFFFFFFFF )

#if 0
/* How to use the function R_RSCFD_Config_NominalBaudrate */
	uint8_t 	n = 0;	/* unit number of RSCFD */
	uint8_t 	m = 0;	/* channel number of RSCFDnv */
	RSCFD_s_RSCFDnCFDCmNCFG	config_NBR;
	
	/* Norminal baoudrate setting (500kbps@40MHz: 8Tq (SS=1/TSEG1=4/TSEG2=3/SJW=1/sample point=62.5%) */
	config_NBR.BIT.NBRP   = 4;	/* Channel Nominal Baud Rate Prescaler = 4 div: Tq= 0.1us@40MHz (500kbps@20Tq, 1Mbps@10Tq) */
	config_NBR.BIT.NSJW   = 1;	/* Nominal Bit Rate Resynchronization Jump Width Control = 2 Tq */
	config_NBR.BIT.NTSEG1 = 4;	/* Time Segment 1 = 5 Tq */
	config_NBR.BIT.NTSEG2 = 3;	/* Time Segment 2 = 4 Tq */
	
	/* Configures Nominal Baudrate */
	R_RSCFD_Config_NominalBaudrate( n, m, config_NBR.UINT32 );
#endif

/*******************************************************************************
* Description  : Configures Data Bitrate
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                RSCFD_s_RSCFDnCFDCmDCFG config: configuration of data bit rate
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RSCFD_Config_DataBitrate(n,m,config)	Reg32WRC( &rRSCFDnCFDCmDCFG(n,m).UINT32, config, 0x0F0F1FFF )

#if 0
/* How to use the function R_RSCFD_Config_DataBitrate */
	uint8_t 	n = 0;	/* unit number of RSCFD */
	uint8_t 	m = 0;	/* channel number of RSCFDnv */
	RSCFD_s_RSCFDnCFDCmDCFG	config_DBR;
	
	/* Data bit rate setting */
	config_DBR.BIT.DBRP   = 4;	/* Channel Data Rate Prescaler */
	config_DBR.BIT.DSJW   = 1;	/* Resynchronization Jump Width */
	config_DBR.BIT.DTSEG1 = 4;	/* Time Segment 1 */
	config_DBR.BIT.DTSEG2 = 3;	/* Time Segment 2 */
	
	/* Configures Nominal Baudrate */
	R_RSCFD_Config_DataBitrate( n, m, config_DBR.UINT32 );
#endif

/*******************************************************************************
* Description  : Set typical Nominal bit rate and Data bit rate
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                uint8_t freq: frequency of CLK_RSCFD
*                RSCFD_e_baudrate: typical baudrate
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_SetPresetBaudRate( uint8_t n, uint8_t m, RSCFD_e_freq freq, RSCFD_e_baudrate baudrate );

/*******************************************************************************
* Description  : Configures RX FIFO buffer x
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t x: number of RX FIFO buffer
*                RSCFD_s_RSCFDnCFDRFCCx config: configuration of RX FIFO Buffer
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RSCFD_Config_RF(n,x,config)	Reg32WRC( &rRSCFDnCFDRFCCx(n,x).UINT32, config, 0x1101F773 )

#if 0
/* How to use the function R_RSCFD_Config_RF */
	uint8_t 	n = 0;	/* unit number of RSCFD */
	uint8_t 	x = 0;	/* number of RX FIFO buffer */
	RSCFD_s_RSCFDnCFDRFCCx	config_RxFIFO;	/* configuration of RX FIFO */
	
	/* set configuration value of RX FIFO */
	config_RxFIFO.BIT.RFE    = RSCFD_e_RFE_FIFO_disabled;                 	/* FIFO disabled */
	config_RxFIFO.BIT.RFIE   = RSCFD_e_RFIE_enable;	/* FIFO Interrupt generation enabled */
	config_RxFIFO.BIT.RFPLS  = RSCFD_e_PLS_8bytes;                     	/* 8 bytes */
	config_RxFIFO.BIT.RFDC   = RSCFD_e_RFDC_FIFO_depth_8messages;        	/* RX FIFO Depth */
	config_RxFIFO.BIT.RFIM   = RSCFD_e_RFIM_RXFIFO_reaches_RFIGCV;       	/* Interrupt generated when RX FIFO counter reaches RFIGCV value from values smaller than RFIGCV */
	config_RxFIFO.BIT.RFIGCV = RSCFD_e_RFIGCV_FIFO_7by8th_full;             /* Interrupt generated when FIFO is 7/8th full. */
	config_RxFIFO.BIT.RFFIE  = RSCFD_e_RFFIE_enable;	/* FIFO Interrupt generation enabled */
	config_RxFIFO.BIT.MEIE   = RSCFD_e_MEIE_disable;                     	/* Message Lost Error Interrupt Enabled */
	config_RxFIFO.BIT.DMAE   = RSCFD_e_DMAE_disable;                     	/* DMA Transfer Request disabled for channel m */

	/* Configures RX FIFO buffer x */
	R_RSCFD_Config_RF( n, x, config_RxFIFO.UINT32 );
#endif

/*******************************************************************************
* Description  : Configures TX/RX FIFO buffer k
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t k: number of TX/RX FIFO buffer
*                RSCFD_s_RSCFDnCFDCFCCk config: configuration of TX/RX FIFO
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RSCFD_Config_CF(n,k,config)	Reg32WRC( &rRSCFDnCFDCFCCk(n,k).UINT32, config, 0xFFFFFF77 )

#if 0
/* How to use the function R_RSCFD_ConfigTxRxFIFO */
	uint8_t 	n = 0;	/* unit number of RSCFD */
	uint8_t 	k = 0;	/* number of TX/RX FIFO buffer */
	RSCFD_s_RSCFDnCFDCmNCFG	config_CF;
	
	config_CF.BIT.CFE    = RSCFD_e_E_FIFO_disable;                      	/* FIFO disable */
 	config_CF.BIT.CFRXIE = RSCFD_e_CFRXIE_disable;	/* FIFO Interrupt generation enabled for Frame RX */
	config_CF.BIT.CFTXIE = RSCFD_e_CFTXIE_enable;	/* FIFO Interrupt generation enabled for Frame TX */
	config_CF.BIT.CFPLS  = RSCFD_e_PLS_8_bytes;                          	/* 8 bytes */
	config_CF.BIT.CFM    = RSCFD_e_CFM_TX_FIFO_mode;                      	/* TX FIFO Mode */
	config_CF.BIT.CFITSS = RSCFD_e_CFITSS_ref_clock;                	/* Reference Clock (x1 / x10 period) */
	config_CF.BIT.CFITR  = RSCFD_e_CFITR_period_x1;       	/* Reference Clock Period x1 */
	config_CF.BIT.CFIM   = RSCFD_e_IM_IGCV;                                             	/* depend on CFM bit */
	config_CF.BIT.CFIGCV = RSCFD_e_IGCV_7_8_full;               	/* Interrupt generated = when FIFO is 7/8th full. */
	config_CF.BIT.CFTML  = 1;                                             	/* TX/RX FIFO TX Message Buffer Link */
	config_CF.BIT.CFDC   = RSCFD_e_CFDC_FIFO_depth_4messages;             	/* FIFO Depth = 4 messages */
	config_CF.BIT.CFITT  = 0;                                             	/* Transmit/Receive FIFO Interval Transmission Time */
	
	/* Configures TX/RX FIFO buffer k */
	R_RSCFD_Config_CF( n, k, config_CF.UINT32 );
#endif

/*******************************************************************************
* Description  : Configures RX message buffer p
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t x: number of RX message buffer
*                RSCFD_s_RSCFDnCFDRFCCx config: configuration of RX FIFO Buffer
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RSCFD_Config_RM(n,config)	Reg32WRC( &rRSCFDnCFDRMNB(n).UINT32, config, 0x000007FF )

#if 0
/* How to use the function R_RSCFD_Config_RM */
	uint8_t 	n = 0;	/* unit number of RSCFD */
	uint8_t 	p = 0;	/* number of TX/RX FIFO buffer */
	RSCFD_s_RSCFDnCFDRMNB	config_RM;
	
	config_RM.BIT.NRXMB  = 1;	/* Number of RX Message Buffers */
 	config_RM.BIT.RMPLS = RSCFD_e_PLS_64_bytes;	/* Payload Data Size */
	
	/* Configures TX/RX FIFO buffer k */
	R_RSCFD_Config_RM( n, config_RM.UINT32 );
#endif

/*******************************************************************************
* Description  : Convert DLC value to message size [byte]
* Arguments    : uint8_t dlc: DLC value
*                RSCFD_e_FDF fdf: non CANFD frame or CANFD frame
* Return Value : size[byte] corresponding the argument dlc.
*                if unexpected error occured, retrun 0xFF
*******************************************************************************/
uint8_t R_RSCFD_DLC2size( uint8_t dlc, RSCFD_e_FDF fdf );

/*******************************************************************************
* Description  : Set transmit message to TX/RX FIFO
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                uint8_t k: number of TX/RX FIFO buffer
*                RSCFD_s_MB txframe: fields value of transmit message
* Return Value : RET_OK:        Register Readback check was successful
*                RET_ERR_PARAM: Parameter is out of range
*                Others:        Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_SetMessageBuffer_CF( uint8_t n, uint8_t m, uint8_t k, RSCFD_s_MB *mb );

/*******************************************************************************
* Description  : Set transmit message to TX Buffer
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                uint8_t p: number of TX buffer
*                RSCFD_s_MB txframe: fields value of transmit message
* Return Value : RET_OK:        Register Readback check was successful
*                RET_ERR_PARAM: Parameter is out of range
*                Others:        Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_SetMessageBuffer_TM( uint8_t n, uint8_t m, uint8_t p, RSCFD_s_MB *mb );

/*******************************************************************************
* Description  : Get reception frame to TX/RX FIFO
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                uint8_t k: number of TX/RX FIFO buffer
*                RSCFD_s_MB mb: message buffer
* Return Value : RET_OK:        Register Readback check was successful
*                RET_ERR_PARAM: Parameter is out of range
*                Others:        Register Readback check was failed
*******************************************************************************/
void R_RSCFD_GetMessageBuffer_CF( uint8_t n, uint8_t m, uint8_t k, RSCFD_s_MB *mb );

/*******************************************************************************
* Description  : Get reception frame to RX FIFO
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                uint8_t x: number of RX FIFO buffer
*                RSCFD_s_MB mb: message buffer
* Return Value : RET_OK:        Register Readback check was successful
*                RET_ERR_PARAM: Parameter is out of range
*                Others:        Register Readback check was failed
*******************************************************************************/
void R_RSCFD_GetMessageBuffer_RF( uint8_t n, uint8_t m, uint8_t x, RSCFD_s_MB *mb );

/*******************************************************************************
* Description  : Get reception frame to RX buffer
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                uint8_t p: number of RX buffer
*                RSCFD_s_MB mb: message buffer
* Return Value : RET_OK:        Register Readback check was successful
*                RET_ERR_PARAM: Parameter is out of range
*                Others:        Register Readback check was failed
*******************************************************************************/
void R_RSCFD_GetMessageBuffer_RM( uint8_t n, uint8_t m, uint8_t x, RSCFD_s_MB *mb );

/*******************************************************************************
* Description  : Enables RX FIFO buffer x
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t x: number of RX FIFO buffer
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RSCFD_EnableBuffer_RF(n,x) 	Reg32SetBitCheck( &rRSCFDnCFDRFCCx(n,x).UINT32, 0 )	/* RFE=1 */

/*******************************************************************************
* Description  : Disables RX FIFO buffer x
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t x: number of RX FIFO buffer
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RSCFD_DisableBuffer_RF(n,x)	Reg32ClearBitCheck( &rRSCFDnCFDRFCCx(n,x).UINT32, 0 )	/* RFE=0 */

/*******************************************************************************
* Description  : Enables TX/RX FIFO buffer k
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t k: number of TX/RX FIFO buffer
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RSCFD_EnableBuffer_CF(n,k) 	Reg32SetBitCheck( &rRSCFDnCFDCFCCk(n,k).UINT32, 0 )   		/* CFE=1 */

/*******************************************************************************
* Description  : Disables TX/RX FIFO buffer k
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t k: number of TX/RX FIFO buffer
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RSCFD_DisableBuffer_CF(n,k) 	Reg32ClearBitCheck( &rRSCFDnCFDCFCCk(n,k).UINT32, 0 ) 		/* CFE=0 */

/*******************************************************************************
* Description  : Increment FIFO pointer for TX/RX FIFO
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t k: number of TX/RX FIFO buffer
* Return Value : None
*******************************************************************************/
#define	R_RSCFD_IncrementPointer_CF(n,k)	rRSCFDnCFDCFPCTRk(n,k).UINT32 = 0x000000FF

/*******************************************************************************
* Description  : Increment FIFO pointer for RX FIFO
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t k: number of TX/RX FIFO buffer
* Return Value : None
*******************************************************************************/
#define	R_RSCFD_IncrementPointer_RF(n,x)	rRSCFDnCFDRFPCTRx(n,x).UINT32 = 0x000000FF

/*******************************************************************************
* Description  : Wait until TX/RX FIFO is empty for waiting transmission complete
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t k: number of TX/RX FIFO buffer
* Return Value : None
*******************************************************************************/
#define R_RSCFD_WaitBufferEmpty_CF(n,k)	Reg32Wait1( &rRSCFDnCFDCFSTSk(n,k).UINT32, 0 )	/*  wait unti CFEMP=1 */

/*******************************************************************************
* Description  : Wait until TX/RX FIFO is empty for waiting transmission complete
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t k: number of TX/RX FIFO buffer
* Return Value : None
*******************************************************************************/
#define R_RSCFD_WaitBufferNotFull_CF(n,k)	Reg32Wait0( &rRSCFDnCFDCFSTSk(n,k).UINT32, 1 )	/*  wait unti CFFLL=0 */

/*******************************************************************************
* Description  : Wait until TX/RX FIFO is empty for waiting transmission complete
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t k: number of TX/RX FIFO buffer
* Return Value : None
*******************************************************************************/
#define R_RSCFD_WaitBufferNotEmpty_RF(n,x)	Reg32Wait0( &rRSCFDnCFDRFSTSx(n,x).UINT32, 0 )	/* wait unti RFEMP=0 */

/*******************************************************************************
* Description  : Request transmission for TX buffer
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t p: number of TX buffer
* Return Value : None
*******************************************************************************/
#define R_RSCFD_RequestTx(n,p)	rRSCFDnCFDTMCp(n,p).UINT8 = (1 << 0)	/* TMTR = 1 */

/*******************************************************************************
* Description  : Wait until transmission complete for TX buffer
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t p: number of TX buffer
* Return Value : None
*******************************************************************************/
#define R_RSCFD_WaitTxComplete(n,p)	Reg08Wait1( &rRSCFDnCFDTMSTSp(n,p).UINT8, 2 )	/* wait until TMTRF1=1 */

/*******************************************************************************
* Description  : Clear transmission complete flag for TX buffer
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t p: number of TX buffer
* Return Value : None
*******************************************************************************/
#define R_RSCFD_ClearTxComplete(n,p)	Reg08ClearBit( &rRSCFDnCFDTMSTSp(n,p).UINT8, 2 )	/* clear TMTRF1 bit */

/*******************************************************************************
* Description  : Wait until transmission complete for RX buffer
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t p: number of RX buffer
* Return Value : None
*******************************************************************************/
#define R_RSCFD_WaitRxComplete(n,f) 	Reg32Wait1( &rRSCFDnCFDRMNDt(n,f/32).UINT32, f%32 )	/* wait until RMNSu=1 */

/*******************************************************************************
* Description  : Clear transmission complete flag for RX buffer
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t p: number of RX buffer
* Return Value : None
*******************************************************************************/
#define R_RSCFD_ClearRxComplete(n,f)	Reg32ClearBit( &rRSCFDnCFDRMNDt(n,f/32).UINT32, f%32 )	/* clear RMNSu bit */

/*******************************************************************************
* Description  : Enter specified test mode
* Arguments    : uint8_t n: unit number of RSCFD
*                uint8_t m: channel number of RSCFDn
*                RSCFD_e_CTMS ctms: channel test mode
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_EnterTestMode( uint8_t n, uint8_t m, RSCFD_e_CTMS ctms );

/*******************************************************************************
* Description  : Enter RAM test mode
* Arguments    : uint8_t n: unit number of RSCFD
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_EnterRAMtestMode( uint8_t n );

/*******************************************************************************
* Description  : Checke whether the RAM test mode enabled
* Arguments    : uint8_t n          : unit number of RSCFD
* Return Value : RTME bit value (RSCFD_e_RTME)
*                  RSCFD_e_RTME_disabled: RAM Test Mode disabled.
*                  RSCFD_e_RTME_enebled:  RAM Test Mode enabled.
*******************************************************************************/
#define	R_RSCFD_CheckRAMTestModeEnable(n)	rRSCFDnCFDGTSTCTR(n).BIT.RTME

/*******************************************************************************
* Description  : Unlcok RAM test mode
* Arguments    : uint8_t n: unit number of RSCFD
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RSCFD_UnlockTestMode( uint8_t n );

/*******************************************************************************
* Description  : convert PLS value to byte
* Arguments    : RSCFD_e_PLS pls: PLS bit value
* Return Value : 0     : unexpected error occured
*                Others: byte number corresponding pls
*******************************************************************************/
uint8_t	R_RSCFD_PLS_to_Byte( RSCFD_e_PLS pls );


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_RSCFD_H__ */
