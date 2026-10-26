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
* File Name    : R_driver_RLIN3.h
* Version      : 1.00 (modified: [DJ] RLIN33 UART test, 2026.10)
* Module(s)    : RLIN3
* Device(s)    : RH850 series product, R-Car U5L product
* Description  : RLIN3 driver that is used commonly by RH850 and R-Car products
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_RLIN3_H__
#define	__R_driver_RLIN3_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_RLIN3_reg.h"	/* for reference of register structure */
#include "R_device_RLIN3.h"    	/* Product-specific definition */
#include "R_driver_general.h"  	/* common function */


/*******************************************************************************
* Definition
*******************************************************************************/
/* Total number of LIN Data Buffer register */
#define	RLIN3_b_NUM	8

/*******************************************************************************
* Type definitions for function argument
*******************************************************************************/
/* RLIN3 clock list */
typedef enum{
	RLIN3_e_clk_1_6MHz,	/* 1.6MHz (for CLK_CPU=CLK_HSIOSC) */
	RLIN3_e_clk_4MHz,
	RLIN3_e_clk_5MHz,
	RLIN3_e_clk_8MHz,
	RLIN3_e_clk_10MHz,
	RLIN3_e_clk_20MHz,
	RLIN3_e_clk_80MHz,
	RLIN3_e_clk_num,
}RLIN3_e_clk;

/* definition of label of baudrate for UART */
typedef enum{
	RLIN3u_e_baudrate_9600bps = 0,
	RLIN3u_e_baudrate_14400bps,
	RLIN3u_e_baudrate_19200bps,
	RLIN3u_e_baudrate_38400bps,
	RLIN3u_e_baudrate_57600bps,
	RLIN3u_e_baudrate_115200bps,
	RLIN3u_e_baudrate_230400bps,
	RLIN3u_e_baudrate_460800bps,
	RLIN3u_e_baudrate_921600bps,
	RLIN3u_e_baudrate_num
}RLIN3u_e_baudrate;

/* definition of label of baudrate for RLIN3 */
typedef enum{
	RLIN3m_e_baudrate_1000bps = 0,
	RLIN3m_e_baudrate_2400bps,
	RLIN3m_e_baudrate_9600bps,
	RLIN3m_e_baudrate_10400bps,
	RLIN3m_e_baudrate_19200bps,
	RLIN3m_e_baudrate_20000bps,
	RLIN3m_e_baudrate_43800bps,
	RLIN3m_e_baudrate_67600bps,
	RLIN3m_e_baudrate_115200bps,
	RLIN3m_e_baudrate_num
}RLIN3m_e_baudrate;

/* argument for the function R_RLIN3u_Config_baudrate */
typedef struct{
	uint8_t 	NSPB :4;	/* Bit Sampling Count Select */
	uint8_t 	LPRS :3;	/* Prescaler Clock Select */
	uint16_t 	LBRP;    	/* baud rate prescaler divides */
}RLIN3u_s_config_baudrate;

/* argument for the function R_RLIN3m_Config_baudrate */
typedef struct{
	uint8_t 	LPRS :3;	/* Prescaler Clock Select */
	uint8_t 	LBRP0;    	/* baud rate prescaler divides */
}RLIN3m_s_config_baudrate;

/* argument for the function R_RLIN3u_Config */
typedef struct{
	/* RLN3nLMD register: noise filter ON/OFF */
	RLIN3u_e_LRDNFS    	LRDNFS;	/* UART Reception Data Noise Filter Disable */
	
	/* RLN3nLEDE register: Enables error detection */
	RLIN3_s_RLN3nLEDE	LEDE;
	
	/* RLN3nLBFC register: Sets data format  */
	RLIN3_s_RLN3nLBFC	LBFC;
	
	/* RLN3nLSC register: set inter byte space */
	RLIN3u_e_IBS     	IBS;
	
	/* RLN3nLUOR1 register: Sets an interrupt generation timing */
	RLIN3_s_RLN3nLUOR1	LUOR1;
	
}RLIN3u_s_config;

/* argument for the function R_RLIN3m_Config */
typedef struct{
	/* RLN3nLMD register: noise filter ON/OFF */
	RLIN3m_e_LRDNFS    	LRDNFS;
	
	/* RLN3nLMD register: LIN Interrupt Output Select */
	RLIN3m_e_LIOS      	LIOS;
	
	/* RLN3nLMD register: LIN System Clock Select */
	RLIN3m_e_LCKS      	LCKS;
	
	/* RLN3nLIE register: LIN Interrupt Enable */
	RLIN3_s_RLN3nLIE 	LIE;
	
	/* RLN3nLEDE register: Enables error detection */
	RLIN3_s_RLN3nLEDE	LEDE;
	
	/* RLN3nLBFC register: frame configuration parameters  */
	RLIN3m_e_BLT    	BLT;	/* Transmission Break (Low Level) */
	RLIN3m_e_BDT    	BDT;	/* Transmission Break Delimiter (High Level)  */
	
	/* RLN3nLSC register: set inter byte space */
	RLIN3m_e_IBS     	IBS;	/* Inter-Byte Space Select */
	RLIN3m_e_IBHS     	IBHS;	/* Inter-Byte Space (Header)/Response Space Select */
	
	/* RLN3nLWUP register: LIN Wake-Up Configuration */
	RLIN3m_e_WUTL     	WUTL;	/* Wake-up Transmission Low Level Width Select */
	
}RLIN3m_s_config;

/* argument for the function R_RLIN3s_Config */
typedef struct{
	/* RLN3nLMD register: noise filter ON/OFF */
	RLIN3s_e_LRDNFS    	LRDNFS;
	
	/* RLN3nLMD register: LIN Interrupt Output Select */
	RLIN3s_e_LIOS      	LIOS;
	
	/* RLN3nLMD register: LIN slave mode selet (auto baud/fixed baud) */
	RLIN3s_e_LMD    	LMD;
	
	/* RLN3nLIE register: LIN Interrupt Enable */
	RLIN3_s_RLN3nLIE 	LIE;
	
	/* RLN3nLEDE register: Enables error detection */
	RLIN3_s_RLN3nLEDE	LEDE;
	
	/* RLN3nLBFC register: LIN Break Field Configuration  */
	RLIN3s_e_LBLT    	LBLT;	/* Reception Break (Low-Level) Detection Width Setting */
	
	/* RLN3nLSC register: set inter byte space */
	RLIN3s_e_IBS     	IBS;	/* Inter-Byte Space Select */
	RLIN3s_e_IBHS     	IBHS;	/* Inter-Byte Space (Header)/Response Space Select */
	
	/* RLN3nLWUP register: LIN Wake-Up Configuration */
	RLIN3s_e_WUTL     	WUTL;	/* Wake-up Transmission Low Level Width Select */
	
}RLIN3s_s_config;


/*******************************************************************************
* Type definitions for transmit/data packet
*******************************************************************************/
/* prity type */
typedef enum{
	RLIN3ms_e_parity_enve = 0,	/* even parity */
	RLIN3ms_e_parity_odd  = 1 	/* odd parity */
}RLIN3ms_e_parity;

/* Transmission/Reception Continuation Select */
typedef enum{
	RLIN3ms_e_LSS_last     = 0,	/* The data group to be transmitted/received next is the last one */
	RLIN3ms_e_LSS_not_last = 1 	/* The data group to be transmitted/received next is not the last one */
}RLIN3ms_e_LSS;

/* Frame Separate Mode Select */
/* reuse RLIN3m_e_FSM in R_driver_RLIN3_reg.h */

/* Checksum Select */
typedef enum{
	RLIN3ms_e_CSM_classic  = 0,	/* Classic checksum */
	RLIN3ms_e_CSM_enhance  = 1 	/* Enhanced checksum */
}RLIN3ms_e_CSM;

/* Response Field Communication Direction Select */
typedef enum{
	RLIN3ms_e_RFT_rx = 0,	/* Response Field Communication is Reception */
	RLIN3ms_e_RFT_tx = 1 	/* Response Field Communication is Transmission */
}RLIN3ms_e_RFT;

/* struture of transmit/receive data packet */
typedef struct{
	/* value to set RLN3nLDFC register */
	RLIN3ms_e_LSS   	lss :1;	/* Transmission/Reception Continuation Select */
	RLIN3m_e_FSM    	fsm :1;	/* Frame Separate Mode Select (only LIN master mode) */
	RLIN3ms_e_CSM     	csm :1;	/* Checksum Select */
	uint8_t         	rfdl:4;	/* Response Field Length */
	
	/* value to set/get RLN3nLIDB, RLN3nLDBRb and RLN3nLCBR register */
	RLIN3ms_e_parity	id_parity_type;	/* prity type for making parity of ID field */
	uint8_t	id;               	/* ID */
	uint8_t	data[RLIN3_b_NUM];	/* Data */	
	uint8_t	checksum;         	/* checksum */	
}RLIN3ms_s_packet;


/*******************************************************************************
* Extern of global variables
*******************************************************************************/
/* Register base address */
extern uint32_t	RLIN3n_base[];

/* preset baudrate for UART */
extern const RLIN3u_s_config_baudrate RLIN3u_Baudrate[RLIN3_e_clk_num][RLIN3u_e_baudrate_num];

/* preset baudrate for LIN master */
extern const RLIN3m_s_config_baudrate RLIN3m_Baudrate[RLIN3_e_clk_num][RLIN3m_e_baudrate_num];


/*******************************************************************************
* Prototype declarations of functions and
* functional definition (macro)
*******************************************************************************/

/*******************************************************************************
* Description  : configuration of baudrate for UART
* Arguments    : uint8_t n                       : unit number of RLIN3
*                R_RLIN3u_Config_baudrate *config: configuration of baudrate for UART
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3u_Config_baudrate( uint8_t n, RLIN3u_s_config_baudrate *config  );

/*******************************************************************************
* Description  : configuration of baudrate for LIN master
* Arguments    : uint8_t n                       : unit number of RLIN3
*                R_RLIN3m_Config_baudrate *config: configuration of baudrate for LIN master
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3m_Config_baudrate( uint8_t n, RLIN3m_s_config_baudrate *config  );

/*******************************************************************************
* Description  : configuration of preset baudrate for UART
* Arguments    : uint8_t n                  : unit number of RLIN3
*                RLIN3_e_clk clock        : RLIN3 clock
*                RLIN3u_e_baudrate baudrete: baudrate
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3u_SetPresetBaudRate( uint8_t n, RLIN3_e_clk clock, RLIN3u_e_baudrate baudrete );

/*******************************************************************************
* Description  : configuration of preset baudrate for LIN master
* Arguments    : uint8_t n                       : unit number of RLIN3
*                R_RLIN3u_Config_baudrate *config: configuration of baudrate for LIN master
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3m_SetPresetBaudRate( uint8_t n, RLIN3_e_clk clock, RLIN3m_e_baudrate baudrete );

/*******************************************************************************
* Description  : configuration of communication for UART mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3u_s_config *config: configuration of UART
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3u_Config( uint8_t n, RLIN3u_s_config *config  );

/*******************************************************************************
* Description  : configuration of LIN master communication
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3u_s_config *config: configuration of LIN master
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3m_Config( uint8_t n, RLIN3m_s_config *config  );

/*******************************************************************************
* Description  : configuration of LIN slave communication
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3u_s_config *config: configuration of LIN slave
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3s_Config( uint8_t n, RLIN3s_s_config *config  );

/*******************************************************************************
* Description  : Release LIN reset
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3u_s_config *config: configuration of UART
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3_ReleaseLINreset( uint8_t n );

/*******************************************************************************
* Description  : Transit LIN reset
* Arguments    : uint8_t n              : unit number of RLIN3
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3_TransitLINreset( uint8_t n );

/*******************************************************************************
* Description  : Enters self-test mode
* Arguments    : uint8_t n              : unit number of RLIN3
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3ms_EnterSelfTestMode( uint8_t n );

/*******************************************************************************
* Description  : Enters LIN operation mode
* Arguments    : uint8_t n              : unit number of RLIN3
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3ms_EnterOperationMode( uint8_t n );

/*******************************************************************************
* Description  : Enable transmission for UART mode
* Arguments    : uint8_t n : unit number of RLIN3
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
/* [DJ] removed trailing ';' (macro was unusable as expression / in if-else) */
#define	R_RLIN3u_EnableTX(n) 	Reg08SetBitCheck( &rRLN3nLUOER(n).UINT8, 0 )	/* UTOE = 1 */

/*******************************************************************************
* Description  : Disable transmission for UART mode
* Arguments    : uint8_t n : unit number of RLIN3
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
/* [DJ] removed trailing ';' */
#define	R_RLIN3u_DisableTX(n)	Reg08ClearBitCheck( &rRLN3nLUOER(n).UINT8, 0 )	/* UTOE = 0 */

/*******************************************************************************
* Description  : Enable reception for UART mode
* Arguments    : uint8_t n : unit number of RLIN3
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RLIN3u_EnableRX(n) 	Reg08SetBitCheck( &rRLN3nLUOER(n).UINT8, 1 )	/* UROE = 1 */

/*******************************************************************************
* Description  : Disable reception for UART mode
* Arguments    : uint8_t n : unit number of RLIN3
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RLIN3u_DisableRX(n)	Reg08ClearBitCheck( &rRLN3nLUOER(n).UINT8, 1 )	/* UROE = 0 */

/*******************************************************************************
* Description  : Enable transmission and reception for UART mode
* Arguments    : uint8_t n : unit number of RLIN3
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RLIN3u_EnableTXRX(n) 	Reg08RMWC( &rRLN3nLUOER(n).UINT8, 0x3, 0x3, 0 )	/* UTOE = 1 and UROE = 1 */

/*******************************************************************************
* Description  : Enable transmission and reception for UART mode
* Arguments    : uint8_t n : unit number of RLIN3
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
#define	R_RLIN3u_DisableTXRX(n)	Reg08RMWC( &rRLN3nLUOER(n).UINT8, 0, 0x3, 0 )	/* UTOE = 0 and UROE = 0 */

/*******************************************************************************
* Description  : Transmit 1 data
* Arguments    : uint8_t  n : unit number of RLIN3
                 uint16_t n : transmit data
* Return Value : None
*******************************************************************************/
#define	R_RLIN3u_Trasmit(n,data)	rRLN3nLUTDR(n).UINT16 = (uint16_t)(data)
/* [DJ] correctly spelled alias (original name kept for compatibility) */
#define	R_RLIN3u_Transmit(n,data)	R_RLIN3u_Trasmit(n,data)

/*******************************************************************************
* Description  : Read 1 received data
* Arguments    : uint8_t  n : unit number of RLIN3
* Return Value : rRLN3nLURDR(n).UINT16
* [DJ] bug fix : read the UART Reception Data Register (LURDR),
*                not the Transmission Data Register (LUTDR)
*******************************************************************************/
#define	R_RLIN3u_Receive(n)     	rRLN3nLURDR(n).UINT16

/*******************************************************************************
* Description  : Set transmit frame to transmit buffer
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *tx_packet: LIN packet for transmission
* Return Value : RET_OK: Register Readback check was successful
*                Others: Register Readback check was failed
*******************************************************************************/
uint8_t R_RLIN3ms_PrepareTransmit( uint8_t n, RLIN3ms_s_packet *tx_packet );

/*******************************************************************************
* Description  : Transmit Header in LIN master mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *tx_packet: LIN packet for transmit
* Return Value : RET_OK       : Transmit was successful
*                RET_ERR_STATE: Transmit was failed
*******************************************************************************/
uint8_t R_RLIN3m_TransmitHeader( uint8_t n, RLIN3ms_s_packet *tx_packet );

/*******************************************************************************
* Description  : Transmit Response in LIN master mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *tx_packet: LIN packet for transmit
* Return Value : RET_OK       : Transmit was successful
*                RET_ERR_STATE: Transmit was failed
*******************************************************************************/
uint8_t R_RLIN3m_TransmitResponse( uint8_t n, RLIN3ms_s_packet *tx_packet );

/*******************************************************************************
* Description  : Transmit Header and Response disabling frame separate mode
*                in LIN master mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *tx_packet: LIN packet for transmit
* Return Value : RET_OK       : Transmit was successful
*                RET_ERR_STATE: Transmit was failed
*******************************************************************************/
#define R_RLIN3m_TransmitHeaderResponse	R_RLIN3m_TransmitHeader

/*******************************************************************************
* Description  : Receive Response in LIN master mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *rx_packet: LIN packet for reception
* Return Value : RET_OK       : Reception was successful
*                RET_ERR_STATE: Reception was failed
*******************************************************************************/
uint8_t R_RLIN3m_ReceiveResponse( uint8_t n, RLIN3ms_s_packet *rx_packet );

/*******************************************************************************
* Description  : Receive Header in LIN slave mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *rx_packet: LIN packet for reception
* Return Value : RET_OK       : Reception was successful
*                RET_ERR_STATE: Reception was failed
*******************************************************************************/
uint8_t R_RLIN3s_ReceiveHeader( uint8_t n, RLIN3ms_s_packet *rx_packet );

/*******************************************************************************
* Description  : Transmit Response in LIN slave mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *rx_packet: LIN packet for reception
* Return Value : RET_OK       : Transmit was successful
*                RET_ERR_STATE: Transmit was failed
*******************************************************************************/
uint8_t R_RLIN3s_TransmitResponse( uint8_t n, RLIN3ms_s_packet *rx_packet );

/*******************************************************************************
* Description  : Reception Response in LIN slave mode
* Arguments    : uint8_t n              : unit number of RLIN3
*                RLIN3ms_s_packet *rx_packet: LIN packet for reception
* Return Value : RET_OK       : Transmit was successful
*                RET_ERR_STATE: Transmit was failed
*******************************************************************************/
uint8_t R_RLIN3s_ReceiveResponse( uint8_t n, RLIN3ms_s_packet *rx_packet );

/*******************************************************************************
* Description  : Request no response in LIN slave mode
*                Execute this function  if no response is to be transmitted/received 
*                after receiving the header and checking the received ID.
*                Once RLN3nLTRC.LNRR is set, this bit is automatically cleared to 0
*                upon detection of new sync field or transition to LIN reset mode.
* Arguments    : uint8_t n              : unit number of RLIN3
* Return Value : RET_OK       : Transmit was successful
*                RET_ERR_STATE: Transmit was failed
*******************************************************************************/
#define R_RLIN3s_RequestNoresponse(n)	Reg08WRC( &rRLN3nLTRC(n).UINT8, 0x04, 0x07 )	/* [DJ] removed trailing ';' */

/*******************************************************************************
* [DJ] UART polling API (added for RLIN33 UART test on R-Car U5L4)
*******************************************************************************/
/* RLN3nLST bit position in UART mode (check with the R-Car U5L User's Manual) */
#define	RLIN3u_LST_FTC	(1U << 0)	/* UART Transmission Completion Flag */
#define	RLIN3u_LST_FRC	(1U << 1)	/* UART Reception Completion Flag    */
#define	RLIN3u_LST_ERR	(1U << 3)	/* Error Detection Flag              */
#define	RLIN3u_LST_UTS	(1U << 4)	/* Transmission Status (1: busy)     */
#define	RLIN3u_LST_URS	(1U << 5)	/* Reception Status    (1: busy)     */

/* timeout value for R_RLIN3u_ReceiveByte: wait forever */
#define	RLIN3u_WAIT_FOREVER	0U

/*******************************************************************************
* Description  : Transmit 1 byte (polling). Waits until the previous
*                transmission is finished (UTS = 0) and writes LUTDR.
* Arguments    : uint8_t n    : unit number of RLIN3
*                uint8_t data : transmit data
* Return Value : None
*******************************************************************************/
void R_RLIN3u_SendByte( uint8_t n, uint8_t data );

/*******************************************************************************
* Description  : Transmit '\0' terminated string (polling)
* Arguments    : uint8_t n          : unit number of RLIN3
*                const char *string : transmit string
* Return Value : None
*******************************************************************************/
void R_RLIN3u_SendString( uint8_t n, const char *string );

/*******************************************************************************
* Description  : Receive 1 byte (polling)
* Arguments    : uint8_t n        : unit number of RLIN3
*                uint8_t *data    : received data
*                uint32_t timeout : polling count (RLIN3u_WAIT_FOREVER: no timeout)
* Return Value : RET_OK       : 1 byte was received
*                RET_ERR_STATE: reception error (framing/overrun/bit) or timeout
*******************************************************************************/
uint8_t R_RLIN3u_ReceiveByte( uint8_t n, uint8_t *data, uint32_t timeout );


/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_RLIN3_H__ */
