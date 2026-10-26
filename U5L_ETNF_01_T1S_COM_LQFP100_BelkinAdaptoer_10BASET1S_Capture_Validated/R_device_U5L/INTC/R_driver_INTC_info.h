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
* File Name    : R_driver_INTC_table.h
* Version      : 1.00
* Device(s)    : R-Car/U5L
* Description  : This is source file for interrupt information table.
*******************************************************************************/

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#ifndef	__R_driver_INTC_table_H__
#define	__R_driver_INTC_table_H__


/*******************************************************************************
* Includes
*******************************************************************************/
#include "R_driver_INTC_reg.h"	/* for reference of register structure */
#include "R_driver_general.h"
#include "core_cm33.h"	/* for using NVIC functions */


/*******************************************************************************
* Typedef for Interrupt information
*******************************************************************************/
/* Detection type to NVIC */
typedef enum{
	INTC_e_IRQTYPE_edge,
	INTC_e_IRQTYPE_level
}INTC_e_IRQTYPE;

/* Exist or not exist IMFU */
typedef enum{
	INTC_e_ctrl_none, 	/* control/monitor by only NVIC registers */
	INTC_e_ctrl_IMFUL,	/* control/monitor by IMFUL registers and NVIC registers */
	INTC_e_ctrl_IMFUP,	/* control/monitor by IMFUP registers and NVIC registers */
}INTC_e_ctrl;

/* Interrupt information */
typedef struct{
	IRQn_Type      	IRQn       :9;	/* Interrupt channel number */
	INTC_e_IRQTYPE	type       :1;	/* Interrupt type (edge or level)*/
	INTC_e_ctrl   	ctrl       :2;	/* IMFUL or IMFUP register */
	uint32_t      	bit        :3;	/* Bit position of IMFU register */
	uint32_t      	group      :6;	/* Group of IMFU register */
}INTC_s_IntInfo;


/*******************************************************************************
* Index of Interrupt information
*******************************************************************************/
typedef enum{
	INTC_e_index_INTECMNMI,       	/* INTECMNMI: ECM maskable interrupt1 */
	INTC_e_index_INTECMMI,        	/* INTECMMI: ECM maskable interrupt2 */
	INTC_e_index_INTFPUEXCIRQ,    	/* INTFPUEXCIRQ: FPU interrupt */
	INTC_e_index_INTTAUD0I0,      	/* INTTAUD0I0: TAUD0 Channel 0 interrupt */
	INTC_e_index_INTTAUD0I2,      	/* INTTAUD0I2: TAUD0 Channel 2 interrupt */
	INTC_e_index_INTTAUD0I4,      	/* INTTAUD0I4: TAUD0 Channel 4 interrupt */
	INTC_e_index_INTTAUD0I6,      	/* INTTAUD0I6: TAUD0 Channel 6 interrupt */
	INTC_e_index_INTEINTSW0,      	/* INTEINTSW0: Software interrupt 0 */
	INTC_e_index_INTEINTSW1,      	/* INTEINTSW1: Software interrupt 1 */
	INTC_e_index_INTEINTSW2,      	/* INTEINTSW2: Software interrupt 2 */
	INTC_e_index_INTEINTSW3,      	/* INTEINTSW3: Software interrupt 3 */
	INTC_e_index_INTS2HS0,        	/* INTS2HS0: Inter-PE interrupt from RSIP-M30A to CPU0 (Single interrupt request from RSIP-M30A to CPU) */
	INTC_e_index_INTWDTB0TIT,     	/* INTWDTB0TIT: WDTB0 interrupt */
	INTC_e_index_INTTAUD0I8,      	/* INTTAUD0I8: TAUD0 Channel 8 interrupt */
	INTC_e_index_INTTAUD0I10,     	/* INTTAUD0I10: TAUD0 Channel 10 interrupt */
	INTC_e_index_INTTAUD0I12,     	/* INTTAUD0I12: TAUD0 Channel 12 interrupt */
	INTC_e_index_INTTAUD0I14,     	/* INTTAUD0I14: TAUD0 Channel 14 interrupt */
	INTC_e_index_INTTAPA0IPEK0,   	/* INTTAPA0IPEK0: TAPA0 peak interrupt 0 */
	INTC_e_index_INTTAPA0IVLY0,   	/* INTTAPA0IVLY0: TAPA0 valley interrupt 0 */
	INTC_e_index_INTPDMACERR,     	/* INTPDMACERR: pDMAC transfer error interrupt */
	INTC_e_index_INTDTSERR,       	/* INTDTSERR: DTS transfer error */
	INTC_e_index_INTDCUDEGRADPE,  	/* INTDCUDEGRADPE: Interrupt for degradation */
	INTC_e_index_INTFL0ENDNM,     	/* INTFL0ENDNM: FPSYS0 Flash sequencer processing end interrupt */
	INTC_e_index_INTFL2ENDNM,     	/* INTFL2ENDNM: FPSYS2 Flash sequencer processing end interrupt */
	INTC_e_index_INTDTS7TO0,      	/* INTDTS7TO0: DTS ch7-0 transfer end */
	INTC_e_index_INTDTSCT7TO0,    	/* INTDTSCT7TO0: DTS ch7-0 transfer count match */
	INTC_e_index_INTPDMAC0CH0,    	/* INTPDMAC0CH0: pDMAC0 channel 0 transfer completion */
	INTC_e_index_INTPDMAC0CH2,    	/* INTPDMAC0CH2: pDMAC0 channel 2 transfer completion */
	INTC_e_index_INTPDMAC0CH4,    	/* INTPDMAC0CH4: pDMAC0 channel 4 transfer completion */
	INTC_e_index_INTPDMAC0CH6,    	/* INTPDMAC0CH6: pDMAC0 channel 6 transfer completion */
	INTC_e_index_INTPDMAC0CH1,    	/* INTPDMAC0CH1: pDMAC0 channel 1 transfer completion */
	INTC_e_index_INTPDMAC0CH3,    	/* INTPDMAC0CH3: pDMAC0 channel 3 transfer completion */
	INTC_e_index_INTPDMAC0CH5,    	/* INTPDMAC0CH5: pDMAC0 channel 5 transfer completion */
	INTC_e_index_INTPDMAC0CH7,    	/* INTPDMAC0CH7: pDMAC0 channel 7 transfer completion */
	INTC_e_index_INTOSTM0TINT,    	/* INTOSTM0TINT: OSTM0 interrupt */
	INTC_e_index_INTADCK0ERR,     	/* INTADCK0ERR: ADCK0 A/D error interrupt upper/ lower limit error interrupt  */
	INTC_e_index_INTADCK0I0,      	/* INTADCK0I0: ADCK0 Scan group 0 (SG0) end interrupt  */
	INTC_e_index_INTADCK0I1,      	/* INTADCK0I1: ADCK0 Scan group 1 (SG1) end interrupt */
	INTC_e_index_INTADCK0I2,      	/* INTADCK0I2: ADCK0 Scan group 2 (SG2) end interrupt */
	INTC_e_index_INTADCK0I3,      	/* INTADCK0I3: ADCK0 Scan group 3 (SG3) end interrupt */
	INTC_e_index_INTADCK0I4,      	/* INTADCK0I4: ADCK0 Scan group 4 (SG4) end interrupt */
	INTC_e_index_INTADCK0MPX,     	/* INTADCK0MPX: ADCK0 MPX DMA trigger request */
	INTC_e_index_INTADCK0SD,      	/* INTADCK0SD: ADCK0 SG-Diag end interrupt */
	INTC_e_index_INTCSIH0IC,      	/* INTCSIH0IC: CSIH0 communication status interrupt */
	INTC_e_index_INTCSIH2IC,      	/* INTCSIH2IC: CSIH2 communication status interrupt */
	INTC_e_index_INTCSIH4IC,      	/* INTCSIH4IC: CSIH4 communication status interrupt */
	INTC_e_index_INTCSIH6IC,      	/* INTCSIH6IC: CSIH6 communication status interrupt */
	INTC_e_index_INTCSIH1IC,      	/* INTCSIH1IC: CSIH1 communication status interrupt */
	INTC_e_index_INTCSIH3IC,      	/* INTCSIH3IC: CSIH3 communication status interrupt */
	INTC_e_index_INTCSIH5IC,      	/* INTCSIH5IC: CSIH5 communication status interrupt */
	INTC_e_index_INTCSIH7IC,      	/* INTCSIH7IC: CSIH7 communication status interrupt */
	INTC_e_index_INTCSIH0IR,      	/* INTCSIH0IR: CSIH0 receive status interrupt */
	INTC_e_index_INTCSIH2IR,      	/* INTCSIH2IR: CSIH2 receive status interrupt */
	INTC_e_index_INTCSIH4IR,      	/* INTCSIH4IR: CSIH4 receive status interrupt */
	INTC_e_index_INTCSIH6IR,      	/* INTCSIH6IR: CSIH6 receive status interrupt */
	INTC_e_index_INTCSIH1IR,      	/* INTCSIH1IR: CSIH1 receive status interrupt */
	INTC_e_index_INTCSIH3IR,      	/* INTCSIH3IR: CSIH3 receive status interrupt */
	INTC_e_index_INTCSIH5IR,      	/* INTCSIH5IR: CSIH5 receive status interrupt */
	INTC_e_index_INTCSIH7IR,      	/* INTCSIH7IR: CSIH7 receive status interrupt */
	INTC_e_index_INTCSIH0IRE,     	/* INTCSIH0IRE: CSIH0 communication error interrupt */
	INTC_e_index_INTCSIH2IRE,     	/* INTCSIH2IRE: CSIH2 communication error interrupt */
	INTC_e_index_INTCSIH4IRE,     	/* INTCSIH4IRE: CSIH4 communication error interrupt */
	INTC_e_index_INTCSIH6IRE,     	/* INTCSIH6IRE: CSIH6 communication error interrupt */
	INTC_e_index_INTCSIH1IRE,     	/* INTCSIH1IRE: CSIH1 communication error interrupt */
	INTC_e_index_INTCSIH3IRE,     	/* INTCSIH3IRE: CSIH3 communication error interrupt */
	INTC_e_index_INTCSIH5IRE,     	/* INTCSIH5IRE: CSIH5 communication error interrupt */
	INTC_e_index_INTCSIH7IRE,     	/* INTCSIH7IRE: CSIH7 communication error interrupt */
	INTC_e_index_INTCSIH0IJC,     	/* INTCSIH0IJC: CSIH0 job completion interrupt */
	INTC_e_index_INTCSIH2IJC,     	/* INTCSIH2IJC: CSIH2 job completion interrupt */
	INTC_e_index_INTCSIH4IJC,     	/* INTCSIH4IJC: CSIH4 job completion interrupt */
	INTC_e_index_INTCSIH6IJC,     	/* INTCSIH6IJC: CSIH6 job completion interrupt */
	INTC_e_index_INTCSIH1IJC,     	/* INTCSIH1IJC: CSIH1 job completion interrupt */
	INTC_e_index_INTCSIH3IJC,     	/* INTCSIH3IJC: CSIH3 job completion interrupt */
	INTC_e_index_INTCSIH5IJC,     	/* INTCSIH5IJC: CSIH5 job completion interrupt */
	INTC_e_index_INTCSIH7IJC,     	/* INTCSIH7IJC: CSIH7 job completion interrupt */
	INTC_e_index_INTRCANGERR0,    	/* INTRCANGERR0: RSCAN0 CAN global error interrupt */
	INTC_e_index_INTRCANGRECC0,   	/* INTRCANGRECC0: RSCAN0 CAN receive FIFO interrupt */
	INTC_e_index_INTRCAN0ERR,     	/* INTRCAN0ERR: CAN0 error interrupt */
	INTC_e_index_INTRCAN2ERR,     	/* INTRCAN2ERR: CAN2 error interrupt */
	INTC_e_index_INTRCAN4ERR,     	/* INTRCAN4ERR: CAN4 error interrupt */
	INTC_e_index_INTRCAN1ERR,     	/* INTRCAN1ERR: CAN1 error interrupt */
	INTC_e_index_INTRCAN3ERR,     	/* INTRCAN3ERR: CAN3 error interrupt */
	INTC_e_index_INTRCAN5ERR,     	/* INTRCAN5ERR: CAN5 error interrupt */
	INTC_e_index_INTRCAN0REC,     	/* INTRCAN0REC: CAN0 transmit/receive FIFO receive completion interrupt */
	INTC_e_index_INTRCAN2REC,     	/* INTRCAN2REC: CAN2 transmit/receive FIFO receive completion interrupt */
	INTC_e_index_INTRCAN4REC,     	/* INTRCAN4REC: CAN4 transmit/receive FIFO receive completion interrupt */
	INTC_e_index_INTRCAN1REC,     	/* INTRCAN1REC: CAN1 transmit/receive FIFO receive completion interrupt */
	INTC_e_index_INTRCAN3REC,     	/* INTRCAN3REC: CAN3 transmit/receive FIFO receive completion interrupt */
	INTC_e_index_INTRCAN5REC,     	/* INTRCAN5REC: CAN5 transmit/receive FIFO receive completion interrupt */
	INTC_e_index_INTRCAN0TRX,     	/* INTRCAN0TRX: CAN0 transmit interrupt */
	INTC_e_index_INTRCAN2TRX,     	/* INTRCAN2TRX: CAN2 transmit interrupt */
	INTC_e_index_INTRCAN4TRX,     	/* INTRCAN4TRX: CAN4 transmit interrupt */
	INTC_e_index_INTRCAN1TRX,     	/* INTRCAN1TRX: CAN1 transmit interrupt */
	INTC_e_index_INTRCAN3TRX,     	/* INTRCAN3TRX: CAN3 transmit interrupt */
	INTC_e_index_INTRCAN5TRX,     	/* INTRCAN5TRX: CAN5 transmit interrupt */
	INTC_e_index_INTXCAN0FUNC,    	/* INTXCAN0FUNC: XCAN0 functional relevant */
	INTC_e_index_INTXCAN0ERR,     	/* INTXCAN0ERR: XCAN0 functional error relevant */
	INTC_e_index_INTXCAN0SAFETY,  	/* INTXCAN0SAFETY: XCAN0 safety relevant */
	INTC_e_index_INTTAUJ0I0,      	/* INTTAUJ0I0: Channel 0 interrupt */
	INTC_e_index_INTTAUJ0I1,      	/* INTTAUJ0I1: Channel 1 interrupt */
	INTC_e_index_INTTAUJ0I2,      	/* INTTAUJ0I2: Channel 2 interrupt */
	INTC_e_index_INTTAUJ0I3,      	/* INTTAUJ0I3: Channel 3 interrupt */
	INTC_e_index_INTTAUJ1I0,      	/* INTTAUJ1I0: Channel 0 interrupt */
	INTC_e_index_INTTAUJ1I1,      	/* INTTAUJ1I1: Channel 1 interrupt */
	INTC_e_index_INTTAUJ1I2,      	/* INTTAUJ1I2: Channel 2 interrupt */
	INTC_e_index_INTTAUJ1I3,      	/* INTTAUJ1I3: Channel 3 interrupt */
	INTC_e_index_INTTAUJ2I0,      	/* INTTAUJ2I0: Channel 0 interrupt */
	INTC_e_index_INTTAUJ2I1,      	/* INTTAUJ2I1: Channel 1 interrupt */
	INTC_e_index_INTTAUJ2I2,      	/* INTTAUJ2I2: Channel 2 interrupt */
	INTC_e_index_INTTAUJ2I3,      	/* INTTAUJ2I3: Channel 3 interrupt */
	INTC_e_index_INTTAUJ3I0,      	/* INTTAUJ3I0: Channel 0 interrupt */
	INTC_e_index_INTTAUJ3I1,      	/* INTTAUJ3I1: Channel 1 interrupt */
	INTC_e_index_INTTAUJ3I2,      	/* INTTAUJ3I2: Channel 2 interrupt */
	INTC_e_index_INTTAUJ3I3,      	/* INTTAUJ3I3: Channel 3 interrupt */
	INTC_e_index_INTTAUD0I1,      	/* INTTAUD0I1: TAUD0 Channel 1 interrupt */
	INTC_e_index_INTTAUD0I3,      	/* INTTAUD0I3: TAUD0 Channel 3 interrupt */
	INTC_e_index_INTTAUD0I5,      	/* INTTAUD0I5: TAUD0 Channel 5 interrupt */
	INTC_e_index_INTTAUD0I7,      	/* INTTAUD0I7: TAUD0 Channel 7 interrupt */
	INTC_e_index_INTTAUD0I9,      	/* INTTAUD0I9: TAUD0 Channel 9 interrupt */
	INTC_e_index_INTTAUD0I11,     	/* INTTAUD0I11: TAUD0 Channel 11 interrupt */
	INTC_e_index_INTTAUD0I13,     	/* INTTAUD0I13: TAUD0 Channel 13 interrupt */
	INTC_e_index_INTTAUD0I15,     	/* INTTAUD0I15: TAUD0 Channel 15 interrupt */
	INTC_e_index_INTTAUD1I0,      	/* INTTAUD1I0: TAUD1 Channel 0 interrupt */
	INTC_e_index_INTTAUD1I2,      	/* INTTAUD1I2: TAUD1 Channel 2 interrupt */
	INTC_e_index_INTTAUD1I4,      	/* INTTAUD1I4: TAUD1 Channel 4 interrupt */
	INTC_e_index_INTTAUD1I6,      	/* INTTAUD1I6: TAUD1 Channel 6 interrupt */
	INTC_e_index_INTTAUD1I8,      	/* INTTAUD1I8: TAUD1 Channel 8 interrupt */
	INTC_e_index_INTTAUD1I10,     	/* INTTAUD1I10: TAUD1 Channel 10 interrupt */
	INTC_e_index_INTTAUD1I12,     	/* INTTAUD1I12: TAUD1 Channel 12 interrupt */
	INTC_e_index_INTTAUD1I14,     	/* INTTAUD1I14: TAUD1 Channel 14 interrupt */
	INTC_e_index_INTTAUD1I1,      	/* INTTAUD1I1: TAUD1 Channel 1 interrupt */
	INTC_e_index_INTTAUD1I3,      	/* INTTAUD1I3: TAUD1 Channel 3 interrupt */
	INTC_e_index_INTTAUD1I5,      	/* INTTAUD1I5: TAUD1 Channel 5 interrupt */
	INTC_e_index_INTTAUD1I7,      	/* INTTAUD1I7: TAUD1 Channel 7 interrupt */
	INTC_e_index_INTTAUD1I9,      	/* INTTAUD1I9: TAUD1 Channel 9 interrupt */
	INTC_e_index_INTTAUD1I11,     	/* INTTAUD1I11: TAUD1 Channel 11 interrupt */
	INTC_e_index_INTTAUD1I13,     	/* INTTAUD1I13: TAUD1 Channel 13 interrupt */
	INTC_e_index_INTTAUD1I15,     	/* INTTAUD1I15: TAUD1 Channel 15 interrupt */
	INTC_e_index_INTRLIN30,       	/* INTRLIN30: RLIN30 interrupt */
	INTC_e_index_INTRLIN31,       	/* INTRLIN31: RLIN31 interrupt */
	INTC_e_index_INTRLIN32,       	/* INTRLIN32: RLIN32 interrupt */
	INTC_e_index_INTRLIN33,       	/* INTRLIN33: RLIN33 interrupt */
	INTC_e_index_INTRLIN34,       	/* INTRLIN34: RLIN34 interrupt */
	INTC_e_index_INTRLIN35,       	/* INTRLIN35: RLIN35 interrupt */
	INTC_e_index_INTRLIN36,       	/* INTRLIN36: RLIN36 interrupt */
	INTC_e_index_INTRLIN37,       	/* INTRLIN37: RLIN37 interrupt */
	INTC_e_index_INTRLIN30UR0,    	/* INTRLIN30UR0: RLIN30 transmit interrupt */
	INTC_e_index_INTRLIN31UR0,    	/* INTRLIN31UR0: RLIN31 transmit interrupt */
	INTC_e_index_INTRLIN32UR0,    	/* INTRLIN32UR0: RLIN32 transmit interrupt */
	INTC_e_index_INTRLIN33UR0,    	/* INTRLIN33UR0: RLIN33 transmit interrupt */
	INTC_e_index_INTRLIN34UR0,    	/* INTRLIN34UR0: RLIN34 transmit interrupt */
	INTC_e_index_INTRLIN35UR0,    	/* INTRLIN35UR0: RLIN35 transmit interrupt */
	INTC_e_index_INTRLIN36UR0,    	/* INTRLIN36UR0: RLIN36 transmit interrupt */
	INTC_e_index_INTRLIN37UR0,    	/* INTRLIN37UR0: RLIN37 transmit interrupt */
	INTC_e_index_INTRLIN30UR1,    	/* INTRLIN30UR1: RLIN30 receive completion interrupt */
	INTC_e_index_INTRLIN31UR1,    	/* INTRLIN31UR1: RLIN31 receive completion interrupt */
	INTC_e_index_INTRLIN32UR1,    	/* INTRLIN32UR1: RLIN32 receive completion interrupt */
	INTC_e_index_INTRLIN33UR1,    	/* INTRLIN33UR1: RLIN33 receive completion interrupt */
	INTC_e_index_INTRLIN34UR1,    	/* INTRLIN34UR1: RLIN34 receive completion interrupt */
	INTC_e_index_INTRLIN35UR1,    	/* INTRLIN35UR1: RLIN35 receive completion interrupt */
	INTC_e_index_INTRLIN36UR1,    	/* INTRLIN36UR1: RLIN36 receive completion interrupt */
	INTC_e_index_INTRLIN37UR1,    	/* INTRLIN37UR1: RLIN37 receive completion interrupt */
	INTC_e_index_INTRLIN30UR2,    	/* INTRLIN30UR2: RLIN30 status interrupt */
	INTC_e_index_INTRLIN31UR2,    	/* INTRLIN31UR2: RLIN31 status interrupt */
	INTC_e_index_INTRLIN32UR2,    	/* INTRLIN32UR2: RLIN32 status interrupt */
	INTC_e_index_INTRLIN33UR2,    	/* INTRLIN33UR2: RLIN33 status interrupt */
	INTC_e_index_INTRLIN34UR2,    	/* INTRLIN34UR2: RLIN34 status interrupt */
	INTC_e_index_INTRLIN35UR2,    	/* INTRLIN35UR2: RLIN35 status interrupt */
	INTC_e_index_INTRLIN36UR2,    	/* INTRLIN36UR2: RLIN36 status interrupt */
	INTC_e_index_INTRLIN37UR2,    	/* INTRLIN37UR2: RLIN37 status interrupt */
	INTC_e_index_INTRSENT0RI,     	/* INTRSENT0RI: RSENT0 receive interrupt */
	INTC_e_index_INTRSENT2RI,     	/* INTRSENT2RI: RSENT2 receive interrupt */
	INTC_e_index_INTRSENT4RI,     	/* INTRSENT4RI: RSENT4 receive interrupt */
	INTC_e_index_INTRSENT6RI,     	/* INTRSENT6RI: RSENT6 receive interrupt */
	INTC_e_index_INTRSENT1RI,     	/* INTRSENT1RI: RSENT1 receive interrupt */
	INTC_e_index_INTRSENT3RI,     	/* INTRSENT3RI: RSENT3 receive interrupt */
	INTC_e_index_INTRSENT5RI,     	/* INTRSENT5RI: RSENT5 receive interrupt */
	INTC_e_index_INTRSENT7RI,     	/* INTRSENT7RI: RSENT7 receive interrupt */
	INTC_e_index_INTRSENT0SI,     	/* INTRSENT0SI: RSENT0 status interrupt */
	INTC_e_index_INTRSENT2SI,     	/* INTRSENT2SI: RSENT2 status interrupt */
	INTC_e_index_INTRSENT4SI,     	/* INTRSENT4SI: RSENT4 status interrupt */
	INTC_e_index_INTRSENT6SI,     	/* INTRSENT6SI: RSENT6 status interrupt */
	INTC_e_index_INTRSENT1SI,     	/* INTRSENT1SI: RSENT1 status interrupt */
	INTC_e_index_INTRSENT3SI,     	/* INTRSENT3SI: RSENT3 status interrupt */
	INTC_e_index_INTRSENT5SI,     	/* INTRSENT5SI: RSENT5 status interrupt */
	INTC_e_index_INTRSENT7SI,     	/* INTRSENT7SI: RSENT7 status interrupt */
	INTC_e_index_INTENCA0IOV,     	/* INTENCA0IOV: ENCA0 overflow interrupt */
	INTC_e_index_INTENCA0I0,      	/* INTENCA0I0: ENCA0 capture/compare match interrupt 0 */
	INTC_e_index_INTENCA0I1,      	/* INTENCA0I1: ENCA0 capture/compare match interrupt 1 */
	INTC_e_index_INTENCA0IUD,     	/* INTENCA0IUD: ENCA0 underflow interrupt */
	INTC_e_index_INTENCA0IEC,     	/* INTENCA0IEC: ENCA0 encoder clear interrupt (phase Z) */
	INTC_e_index_Reserved,        	/* Reserved: - */
	INTC_e_index_IRQ0,            	/* IRQ0: External interrupt 0 */
	INTC_e_index_IRQ1,            	/* IRQ1: External interrupt 1 */
	INTC_e_index_IRQ2,            	/* IRQ2: External interrupt 2 */
	INTC_e_index_IRQ3,            	/* IRQ3: External interrupt 3 */
	INTC_e_index_IRQ4,            	/* IRQ4: External interrupt 4 */
	INTC_e_index_IRQ5,            	/* IRQ5: External interrupt 5 */
	INTC_e_index_IRQ6,            	/* IRQ6: External interrupt 6 */
	INTC_e_index_IRQ16,           	/* IRQ16: External interrupt 16 */
	INTC_e_index_IRQ18,           	/* IRQ18: External interrupt 18 */
	INTC_e_index_IRQ19,           	/* IRQ19: External interrupt 19 */
	INTC_e_index_IRQ20,           	/* IRQ20: External interrupt 20 */
	INTC_e_index_IRQ21,           	/* IRQ21: External interrupt 21 */
	INTC_e_index_IRQ22,           	/* IRQ22: External interrupt 22 */
	INTC_e_index_IRQ23,           	/* IRQ23: External interrupt 23 */
	INTC_e_index_IRQ24,           	/* IRQ24: External interrupt 24 */
	INTC_e_index_INTRTCA01S,      	/* INTRTCA01S: RTCA0 1-second interval interrupt */
	INTC_e_index_INTRTCA0AL,      	/* INTRTCA0AL: RTCA0 Alarm interrupt */
	INTC_e_index_INTRTCA0R,       	/* INTRTCA0R: RTCA0 Fixed interval interrupt */
	INTC_e_index_INTS2H0,         	/* INTS2H0: Inter-PE interrupt from RSIP-M30A to INTC2 (Interrupt request from RSIP-M30A to CPU (PE)) */
	INTC_e_index_INTPWGCG00,      	/* INTPWGCG00: PWGC unit 0 of group 0 interrupt */
	INTC_e_index_INTPWGCG01,      	/* INTPWGCG01: PWGC unit 0 of group 1 interrupt */
	INTC_e_index_INTPWGCG02,      	/* INTPWGCG02: PWGC unit 0 of group 2 interrupt */
	INTC_e_index_INTPWSDQFULL,    	/* INTPWSDQFULL: PWSD queue full interrupt */
	INTC_e_index_INTCXP10TI,      	/* INTCXP10TI: CXP10 transfer interrupt */
	INTC_e_index_INTCXP12TI,      	/* INTCXP12TI: CXP12 transfer interrupt */
	INTC_e_index_INTCXP10RI,      	/* INTCXP10RI: CXP10 receive interrupt */
	INTC_e_index_INTCXP12RI,      	/* INTCXP12RI: CXP12 receive interrupt */
	INTC_e_index_INTCXP10SI,      	/* INTCXP10SI: CXP10 status interrupt */
	INTC_e_index_INTCXP12SI,      	/* INTCXP12SI: CXP12 status interrupt */
	INTC_e_index_INTCXP11TI,      	/* INTCXP11TI: CXP11 transfer interrupt */
	INTC_e_index_INTCXP13TI,      	/* INTCXP13TI: CXP13 transfer interrupt */
	INTC_e_index_INTCXP11RI,      	/* INTCXP11RI: CXP11 receive interrupt */
	INTC_e_index_INTCXP13RI,      	/* INTCXP13RI: CXP13 receive interrupt */
	INTC_e_index_INTCXP11SI,      	/* INTCXP11SI: CXP11 status interrupt */
	INTC_e_index_INTCXP13SI,      	/* INTCXP13SI: CXP13 status interrupt */
	INTC_e_index_INTRI3C0RESP,    	/* INTRI3C0RESP: RI3C0 Normal Response queue full */
	INTC_e_index_INTRI3C0CMD,     	/* INTRI3C0CMD: RI3C0 Normal Command queue empty */
	INTC_e_index_INTRI3C0IBI,     	/* INTRI3C0IBI: RI3C0 Normal IBI Status queue full */
	INTC_e_index_INTRI3C0RX0,     	/* INTRI3C0RX0: RI3C0 Normal Rx Data buffer 0 full */
	INTC_e_index_INTRI3C0TX0,     	/* INTRI3C0TX0: RI3C0 Normal Tx Data buffer 0 empty */
	INTC_e_index_INTRI3C0RCV,     	/* INTRI3C0RCV: RI3C0 Normal Receive Status queue full */
	INTC_e_index_INTRI3C0HRESP,   	/* INTRI3C0HRESP: RI3C0 High Priority Response queue full */
	INTC_e_index_INTRI3C0HCMD,    	/* INTRI3C0HCMD: RI3C0 High Priority Command queue empty */
	INTC_e_index_INTRI3C0HRX,     	/* INTRI3C0HRX: RI3C0 High Priority Rx Data buffer full */
	INTC_e_index_INTRI3C0HTX,     	/* INTRI3C0HTX: RI3C0 High Priority Tx Data buffer empty */
	INTC_e_index_INTRI3C0TEND,    	/* INTRI3C0TEND: RI3C0 Transmit end  */
	INTC_e_index_INTRI3C0EEI,     	/* INTRI3C0EEI: RI3C0 Communication error / event  */
	INTC_e_index_INTRIIC0EE,      	/* INTRIIC0EE: RIIC0 communication error/event generation interrupt */
	INTC_e_index_INTRIIC0RI,      	/* INTRIIC0RI: RIIC0 receive end interrupt */
	INTC_e_index_INTRIIC0TI,      	/* INTRIIC0TI: RIIC0 transmit data empty interrupt */
	INTC_e_index_INTRIIC0TEI,     	/* INTRIIC0TEI: RIIC0 transmit end interrupt */
	INTC_e_index_INTRIIC1EE,      	/* INTRIIC1EE: RIIC1 communication error/event generation interrupt */
	INTC_e_index_INTRIIC1RI,      	/* INTRIIC1RI: RIIC1 receive end interrupt */
	INTC_e_index_INTRIIC1TI,      	/* INTRIIC1TI: RIIC1 transmit data empty interrupt */
	INTC_e_index_INTRIIC1TEI,     	/* INTRIIC1TEI: RIIC1 transmit end interrupt */
	INTC_e_index_INTCWEND,        	/* INTCWEND: LPSB0 Port polling end interrupt */
	INTC_e_index_INTDPE,          	/* INTDPE: LPSB0 Digital port error interrupt */
	INTC_e_index_INTLPSTM0,       	/* INTLPSTM0: LPSB0 Interval Timer 0 Interrupt */
	INTC_e_index_INTLPSTM2,       	/* INTLPSTM2: LPSB0 Interval Timer 2 Interrupt */
	INTC_e_index_INTLPSTM4,       	/* INTLPSTM4: LPSB0 Interval Timer 4 Interrupt */
	INTC_e_index_INTLPSTM1,       	/* INTLPSTM1: LPSB0 Interval Timer 1 Interrupt */
	INTC_e_index_INTLPSTM3,       	/* INTLPSTM3: LPSB0 Interval Timer 3 Interrupt */
	INTC_e_index_INTRSIPMFATALERR,	/* INTRSIPMFATALERR: RSIP-M30A fatal error notification */
	INTC_e_index_INTWDTBATIT,     	/* INTWDTBATIT: WDTBA interrupt */
	INTC_e_index_INTDCUTDI,       	/* INTDCUTDI: Dedicated interrupt for on-chip debug function */
	INTC_e_index_INTSSIF0TX,      	/* INTSSIF0TX: Transmission data empty for channel 0 */
	INTC_e_index_INTSSIF0RX,      	/* INTSSIF0RX: Reception data full for channel 0 */
	INTC_e_index_INTSSIF0,        	/* INTSSIF0: Multi-purpose interrupt for channel 0 */
	INTC_e_index_INTSSIF1TX,      	/* INTSSIF1TX: Transmission data empty for channel 1 */
	INTC_e_index_INTSSIF1RX,      	/* INTSSIF1RX: Reception data full for channel 1 */
	INTC_e_index_INTSSIF1,        	/* INTSSIF1: Multi-purpose interrupt for channel 1 */
	INTC_e_index_INTPDMAC1CH0,    	/* INTPDMAC1CH0: pDMAC1 channel 0 transfer completion */
	INTC_e_index_INTPDMAC1CH2,    	/* INTPDMAC1CH2: pDMAC1 channel 2 transfer completion */
	INTC_e_index_INTPDMAC1CH4,    	/* INTPDMAC1CH4: pDMAC1 channel 4 transfer completion */
	INTC_e_index_INTPDMAC1CH6,    	/* INTPDMAC1CH6: pDMAC1 channel 6 transfer completion */
	INTC_e_index_INTPDMAC1CH1,    	/* INTPDMAC1CH1: pDMAC1 channel 1 transfer completion */
	INTC_e_index_INTPDMAC1CH3,    	/* INTPDMAC1CH3: pDMAC1 channel 3 transfer completion */
	INTC_e_index_INTPDMAC1CH5,    	/* INTPDMAC1CH5: pDMAC1 channel 5 transfer completion */
	INTC_e_index_INTPDMAC1CH7,    	/* INTPDMAC1CH7: pDMAC1 channel 7 transfer completion */
	INTC_e_index_INTTAUD2I0,      	/* INTTAUD2I0: TAUD2 Channel 0 interrupt */
	INTC_e_index_INTTAUD2I2,      	/* INTTAUD2I2: TAUD2 Channel 2 interrupt */
	INTC_e_index_INTTAUD2I4,      	/* INTTAUD2I4: TAUD2 Channel 4 interrupt */
	INTC_e_index_INTTAUD2I6,      	/* INTTAUD2I6: TAUD2 Channel 6 interrupt */
	INTC_e_index_INTTAUD2I8,      	/* INTTAUD2I8: TAUD2 Channel 8 interrupt */
	INTC_e_index_INTTAUD2I10,     	/* INTTAUD2I10: TAUD2 Channel 10 interrupt */
	INTC_e_index_INTTAUD2I12,     	/* INTTAUD2I12: TAUD2 Channel 12 interrupt */
	INTC_e_index_INTTAUD2I14,     	/* INTTAUD2I14: TAUD2 Channel 14 interrupt */
	INTC_e_index_INTTAUD2I1,      	/* INTTAUD2I1: TAUD2 Channel 1 interrupt */
	INTC_e_index_INTTAUD2I3,      	/* INTTAUD2I3: TAUD2 Channel 3 interrupt */
	INTC_e_index_INTTAUD2I5,      	/* INTTAUD2I5: TAUD2 Channel 5 interrupt */
	INTC_e_index_INTTAUD2I7,      	/* INTTAUD2I7: TAUD2 Channel 7 interrupt */
	INTC_e_index_INTTAUD2I9,      	/* INTTAUD2I9: TAUD2 Channel 9 interrupt */
	INTC_e_index_INTTAUD2I11,     	/* INTTAUD2I11: TAUD2 Channel 11 interrupt */
	INTC_e_index_INTTAUD2I13,     	/* INTTAUD2I13: TAUD2 Channel 13 interrupt */
	INTC_e_index_INTTAUD2I15,     	/* INTTAUD2I15: TAUD2 Channel 15 interrupt */
	INTC_e_index_IRQ7,            	/* IRQ7: External interrupt 7 */
	INTC_e_index_IRQ9,            	/* IRQ9: External interrupt 9 */
	INTC_e_index_IRQ10,           	/* IRQ10: External interrupt 10 */
	INTC_e_index_IRQ11,           	/* IRQ11: External interrupt 11 */
	INTC_e_index_IRQ12,           	/* IRQ12: External interrupt 12 */
	INTC_e_index_IRQ13,           	/* IRQ13: External interrupt 13 */
	INTC_e_index_IRQ14,           	/* IRQ14: External interrupt 14 */
	INTC_e_index_IRQ15,           	/* IRQ15: External interrupt 15 */
	INTC_e_index_IRQ17,           	/* IRQ17: External interrupt 17 */
	INTC_e_index_INTADCK1ERR,     	/* INTADCK1ERR: ADCK1 A/D error interrupt upper/lower limit error interrupt */
	INTC_e_index_INTADCK1I0,      	/* INTADCK1I0: ADCK1 Scan group 0 (SG0) end interrupt  */
	INTC_e_index_INTADCK1I1,      	/* INTADCK1I1: ADCK1 Scan group 1 (SG1) end interrupt */
	INTC_e_index_INTADCK1I2,      	/* INTADCK1I2: ADCK1 Scan group 2 (SG2) end interrupt */
	INTC_e_index_INTADCK1I3,      	/* INTADCK1I3: ADCK1 Scan group 3 (SG3) end interrupt */
	INTC_e_index_INTADCK1I4,      	/* INTADCK1I4: ADCK1 Scan group 4 (SG4) end interrupt */
	INTC_e_index_INTADCK1MPX,     	/* INTADCK1MPX: ADCK1 MPX DMA trigger request */
	INTC_e_index_INTADCK1SD,      	/* INTADCK1SD: ADCK1 SG-Diag end interrupt */
	INTC_e_index_INTRLIN38,       	/* INTRLIN38: RLIN38 interrupt */
	INTC_e_index_INTRLIN39,       	/* INTRLIN39: RLIN39 interrupt */
	INTC_e_index_INTRLIN310,      	/* INTRLIN310: RLIN310 interrupt */
	INTC_e_index_INTRLIN311,      	/* INTRLIN311: RLIN311 interrupt */
	INTC_e_index_INTRLIN312,      	/* INTRLIN312: RLIN312 interrupt */
	INTC_e_index_INTRLIN313,      	/* INTRLIN313: RLIN313 interrupt */
	INTC_e_index_INTRLIN314,      	/* INTRLIN314: RLIN314 interrupt */
	INTC_e_index_INTRLIN315,      	/* INTRLIN315: RLIN315 interrupt */
	INTC_e_index_INTRLIN38UR0,    	/* INTRLIN38UR0: RLIN38 transmit interrupt */
	INTC_e_index_INTRLIN39UR0,    	/* INTRLIN39UR0: RLIN39 transmit interrupt */
	INTC_e_index_INTRLIN310UR0,   	/* INTRLIN310UR0: RLIN310 transmit interrupt */
	INTC_e_index_INTRLIN311UR0,   	/* INTRLIN311UR0: RLIN311 transmit interrupt */
	INTC_e_index_INTRLIN312UR0,   	/* INTRLIN312UR0: RLIN312 transmit interrupt */
	INTC_e_index_INTRLIN313UR0,   	/* INTRLIN313UR0: RLIN313 transmit interrupt */
	INTC_e_index_INTRLIN314UR0,   	/* INTRLIN314UR0: RLIN314 transmit interrupt */
	INTC_e_index_INTRLIN315UR0,   	/* INTRLIN315UR0: RLIN315 transmit interrupt */
	INTC_e_index_INTRLIN38UR1,    	/* INTRLIN38UR1: RLIN38 receive completion interrupt */
	INTC_e_index_INTRLIN39UR1,    	/* INTRLIN39UR1: RLIN39 receive completion interrupt */
	INTC_e_index_INTRLIN310UR1,   	/* INTRLIN310UR1: RLIN310 receive completion interrupt */
	INTC_e_index_INTRLIN311UR1,   	/* INTRLIN311UR1: RLIN311 receive completion interrupt */
	INTC_e_index_INTRLIN312UR1,   	/* INTRLIN312UR1: RLIN312 receive completion interrupt */
	INTC_e_index_INTRLIN313UR1,   	/* INTRLIN313UR1: RLIN313 receive completion interrupt */
	INTC_e_index_INTRLIN314UR1,   	/* INTRLIN314UR1: RLIN314 receive completion interrupt */
	INTC_e_index_INTRLIN315UR1,   	/* INTRLIN315UR1: RLIN315 receive completion interrupt */
	INTC_e_index_INTRLIN38UR2,    	/* INTRLIN38UR2: RLIN38 status interrupt */
	INTC_e_index_INTRLIN39UR2,    	/* INTRLIN39UR2: RLIN39 status interrupt */
	INTC_e_index_INTRLIN310UR2,   	/* INTRLIN310UR2: RLIN310 status interrupt */
	INTC_e_index_INTRLIN311UR2,   	/* INTRLIN311UR2: RLIN311 status interrupt */
	INTC_e_index_INTRLIN312UR2,   	/* INTRLIN312UR2: RLIN312 status interrupt */
	INTC_e_index_INTRLIN313UR2,   	/* INTRLIN313UR2: RLIN313 status interrupt */
	INTC_e_index_INTRLIN314UR2,   	/* INTRLIN314UR2: RLIN314 status interrupt */
	INTC_e_index_INTRLIN315UR2,   	/* INTRLIN315UR2: RLIN315 status interrupt */
	INTC_e_index_INTOSTM1TINT,    	/* INTOSTM1TINT: OSTM1 interrupt */
	INTC_e_index_INTOSTM2TINT,    	/* INTOSTM2TINT: OSTM2 interrupt */
	INTC_e_index_INTETNF0DATA,    	/* INTETNF0DATA: ETNF0 Data related interrupt */
	INTC_e_index_INTETNF0ERR,     	/* INTETNF0ERR: ETNF0 Data related interrupt */
	INTC_e_index_INTETNF0MNG,     	/* INTETNF0MNG: ETNF0 Management related interrupt */
	INTC_e_index_INTETNF0MAC,     	/* INTETNF0MAC: ETNF0 MAC interrupt */
	INTC_e_index_IRQ8,            	/* IRQ8: External interrupt 8 */
	INTC_e_index_INTPSI50SI,      	/* INTPSI50SI: PSI50 status interrupt */
	INTC_e_index_INTPSI50RI,      	/* INTPSI50RI: PSI50 receive interrupt */
	INTC_e_index_INTPSI50TI,      	/* INTPSI50TI: PSI50 transfer interrupt */
	INTC_e_index_INTPSI51SI,      	/* INTPSI51SI: PSI51 status interrupt */
	INTC_e_index_INTPSI51RI,      	/* INTPSI51RI: PSI51 receive interrupt */
	INTC_e_index_INTPSI51TI,      	/* INTPSI51TI: PSI51 transfer interrupt */
	INTC_e_index_INTPSI5W,        	/* INTPSI5W: Interruption reports the end of all channel enable */
	INTC_e_index_INTMMCA0,        	/* INTMMCA0: MMCA interrupt */
	INTC_e_index_INTOSTM3TINT,    	/* INTOSTM3TINT: OSTM3 interrupt */
	INTC_e_index_INTOSTM4TINT,    	/* INTOSTM4TINT: OSTM4 interrupt */
	INTC_e_index_INTXCAN1FUNC,    	/* INTXCAN1FUNC: XCAN1 functional relevant */
	INTC_e_index_INTXCAN1ERR,     	/* INTXCAN1ERR: XCAN1 functional error relevant */
	INTC_e_index_INTXCAN1SAFETY,  	/* INTXCAN1SAFETY: XCAN1 safety relevant */
	INTC_e_index_INTETND00,       	/* INTETND00: ETND0 (Endstation) interrupt 0 */
	INTC_e_index_INTETND01,       	/* INTETND01: ETND0 (Endstation) interrupt 1 */
	INTC_e_index_INTETND02,       	/* INTETND02: ETND0 (Endstation) interrupt 2 */
	INTC_e_index_INTETND03,       	/* INTETND03: ETND0 (Endstation) interrupt 3 */
	INTC_e_index_INTETND04,       	/* INTETND04: ETND0 (Endstation) interrupt 4 */
	INTC_e_index_INTETND05,       	/* INTETND05: ETND0 (Endstation) interrupt 5 */
	INTC_e_index_INTETND06,       	/* INTETND06: ETND0 (Endstation) interrupt 6 */
	INTC_e_index_INTGPTP,         	/* INTGPTP: gPTP interrupt */
	INTC_e_index_IRQ25,           	/* IRQ25: External interrupt 25 */
	INTC_e_index_INTRLIN316,      	/* INTRLIN316: RLIN316 interrupt */
	INTC_e_index_INTRLIN317,      	/* INTRLIN317: RLIN317 interrupt */
	INTC_e_index_INTRLIN316UR0,   	/* INTRLIN316UR0: RLIN316 transmit interrupt */
	INTC_e_index_INTRLIN317UR0,   	/* INTRLIN317UR0: RLIN317 transmit interrupt */
	INTC_e_index_INTRLIN316UR1,   	/* INTRLIN316UR1: RLIN316 receive completion interrupt */
	INTC_e_index_INTRLIN317UR1,   	/* INTRLIN317UR1: RLIN317 receive completion interrupt */
	INTC_e_index_INTRLIN316UR2,   	/* INTRLIN316UR2: RLIN316 status interrupt */
	INTC_e_index_INTRLIN317UR2,   	/* INTRLIN317UR2: RLIN317 status interrupt */
	INTC_e_index_end            	/* Total number of INTC_e_index */
}INTC_e_index;


/*******************************************************************************
* Extern of global variables
*******************************************************************************/
extern const INTC_s_IntInfo INTC_Info[];
extern INTC_e_index	INTC_e_index_INTTAUDnIm[][16];
extern INTC_e_index	INTC_e_index_INTEINTSWp[];
extern INTC_e_index	INTC_e_index_INTLPSTMx[];
extern INTC_e_index	INTC_e_index_IRQn[];

/*******************************************************************************
* Definition of re-inclusion prevention
*******************************************************************************/
#endif /* __R_driver_INTC_table_H__ */
