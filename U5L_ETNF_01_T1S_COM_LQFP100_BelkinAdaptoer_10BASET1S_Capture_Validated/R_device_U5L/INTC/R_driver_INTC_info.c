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
* File Name    : R_driver_INTC_table.c
* Version      : 1.00
* Device(s)    : R-Car/U5L
* Description  : This is source file for interrupt information table.
*******************************************************************************/

/*******************************************************************************
* Includes
*******************************************************************************/
#include <R_driver_INTC_info.h>


/*******************************************************************************
* Interrupt information
*******************************************************************************/
const INTC_s_IntInfo INTC_Info[] = {
/*  ch_no, type,                IMFU register,    bit, group */
	{0,   INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTECMNMI: ECM maskable interrupt1 */
	{1,   INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTECMMI: ECM maskable interrupt2 */
	{2,   INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTFPUEXCIRQ: FPU interrupt */
	{3,   INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTTAUD0I0: TAUD0 Channel 0 interrupt */
	{4,   INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTTAUD0I2: TAUD0 Channel 2 interrupt */
	{5,   INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTTAUD0I4: TAUD0 Channel 4 interrupt */
	{6,   INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTTAUD0I6: TAUD0 Channel 6 interrupt */
	{7,   INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTEINTSW0: Software interrupt 0 */
	{8,   INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTEINTSW1: Software interrupt 1 */
	{9,   INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTEINTSW2: Software interrupt 2 */
	{10,  INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTEINTSW3: Software interrupt 3 */
	{11,  INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTS2HS0: Inter-PE interrupt from RSIP-M30A to CPU0 (Single interrupt request from RSIP-M30A to CPU) */
	{12,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTWDTB0TIT: WDTB0 interrupt */
	{13,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTTAUD0I8: TAUD0 Channel 8 interrupt */
	{14,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTTAUD0I10: TAUD0 Channel 10 interrupt */
	{15,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTTAUD0I12: TAUD0 Channel 12 interrupt */
	{16,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTTAUD0I14: TAUD0 Channel 14 interrupt */
	{17,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTTAPA0IPEK0: TAPA0 peak interrupt 0 */
	{18,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTTAPA0IVLY0: TAPA0 valley interrupt 0 */
	{19,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTPDMACERR: pDMAC transfer error interrupt */
	{20,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTDTSERR: DTS transfer error */
	{21,  INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTDCUDEGRADPE: Interrupt for degradation */
	{22,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTFL0ENDNM: FPSYS0 Flash sequencer processing end interrupt */
	{23,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTFL2ENDNM: FPSYS2 Flash sequencer processing end interrupt */
	{24,  INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTDTS7TO0: DTS ch7-0 transfer end */
	{25,  INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTDTSCT7TO0: DTS ch7-0 transfer count match */
	{26,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 0  },	/* INTPDMAC0CH0: pDMAC0 channel 0 transfer completion */
	{26,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 0  },	/* INTPDMAC0CH2: pDMAC0 channel 2 transfer completion */
	{26,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 0  },	/* INTPDMAC0CH4: pDMAC0 channel 4 transfer completion */
	{26,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 0  },	/* INTPDMAC0CH6: pDMAC0 channel 6 transfer completion */
	{27,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 1  },	/* INTPDMAC0CH1: pDMAC0 channel 1 transfer completion */
	{27,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 1  },	/* INTPDMAC0CH3: pDMAC0 channel 3 transfer completion */
	{27,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 1  },	/* INTPDMAC0CH5: pDMAC0 channel 5 transfer completion */
	{27,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 1  },	/* INTPDMAC0CH7: pDMAC0 channel 7 transfer completion */
	{28,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTOSTM0TINT: OSTM0 interrupt */
	{29,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK0ERR: ADCK0 A/D error interrupt upper/ lower limit error interrupt  */
	{30,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK0I0: ADCK0 Scan group 0 (SG0) end interrupt  */
	{31,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK0I1: ADCK0 Scan group 1 (SG1) end interrupt */
	{32,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK0I2: ADCK0 Scan group 2 (SG2) end interrupt */
	{33,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK0I3: ADCK0 Scan group 3 (SG3) end interrupt */
	{34,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK0I4: ADCK0 Scan group 4 (SG4) end interrupt */
	{35,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK0MPX: ADCK0 MPX DMA trigger request */
	{36,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK0SD: ADCK0 SG-Diag end interrupt */
	{37,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 2  },	/* INTCSIH0IC: CSIH0 communication status interrupt */
	{37,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 2  },	/* INTCSIH2IC: CSIH2 communication status interrupt */
	{37,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 2  },	/* INTCSIH4IC: CSIH4 communication status interrupt */
	{37,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 2  },	/* INTCSIH6IC: CSIH6 communication status interrupt */
	{38,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 3  },	/* INTCSIH1IC: CSIH1 communication status interrupt */
	{38,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 3  },	/* INTCSIH3IC: CSIH3 communication status interrupt */
	{38,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 3  },	/* INTCSIH5IC: CSIH5 communication status interrupt */
	{38,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 3  },	/* INTCSIH7IC: CSIH7 communication status interrupt */
	{39,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 4  },	/* INTCSIH0IR: CSIH0 receive status interrupt */
	{39,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 4  },	/* INTCSIH2IR: CSIH2 receive status interrupt */
	{39,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 4  },	/* INTCSIH4IR: CSIH4 receive status interrupt */
	{39,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 4  },	/* INTCSIH6IR: CSIH6 receive status interrupt */
	{40,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 5  },	/* INTCSIH1IR: CSIH1 receive status interrupt */
	{40,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 5  },	/* INTCSIH3IR: CSIH3 receive status interrupt */
	{40,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 5  },	/* INTCSIH5IR: CSIH5 receive status interrupt */
	{40,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 5  },	/* INTCSIH7IR: CSIH7 receive status interrupt */
	{41,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 6  },	/* INTCSIH0IRE: CSIH0 communication error interrupt */
	{41,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 6  },	/* INTCSIH2IRE: CSIH2 communication error interrupt */
	{41,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 6  },	/* INTCSIH4IRE: CSIH4 communication error interrupt */
	{41,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 6  },	/* INTCSIH6IRE: CSIH6 communication error interrupt */
	{42,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 7  },	/* INTCSIH1IRE: CSIH1 communication error interrupt */
	{42,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 7  },	/* INTCSIH3IRE: CSIH3 communication error interrupt */
	{42,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 7  },	/* INTCSIH5IRE: CSIH5 communication error interrupt */
	{42,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 7  },	/* INTCSIH7IRE: CSIH7 communication error interrupt */
	{43,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 8  },	/* INTCSIH0IJC: CSIH0 job completion interrupt */
	{43,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 8  },	/* INTCSIH2IJC: CSIH2 job completion interrupt */
	{43,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 8  },	/* INTCSIH4IJC: CSIH4 job completion interrupt */
	{43,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 8  },	/* INTCSIH6IJC: CSIH6 job completion interrupt */
	{44,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 9  },	/* INTCSIH1IJC: CSIH1 job completion interrupt */
	{44,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 9  },	/* INTCSIH3IJC: CSIH3 job completion interrupt */
	{44,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 9  },	/* INTCSIH5IJC: CSIH5 job completion interrupt */
	{44,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 9  },	/* INTCSIH7IJC: CSIH7 job completion interrupt */
	{45,  INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTRCANGERR0: RSCAN0 CAN global error interrupt */
	{46,  INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTRCANGRECC0: RSCAN0 CAN receive FIFO interrupt */
	{47,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 0, 0  },	/* INTRCAN0ERR: CAN0 error interrupt */
	{47,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 1, 0  },	/* INTRCAN2ERR: CAN2 error interrupt */
	{47,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 2, 0  },	/* INTRCAN4ERR: CAN4 error interrupt */
	{48,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 0, 1  },	/* INTRCAN1ERR: CAN1 error interrupt */
	{48,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 1, 1  },	/* INTRCAN3ERR: CAN3 error interrupt */
	{48,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 2, 1  },	/* INTRCAN5ERR: CAN5 error interrupt */
	{49,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 0, 2  },	/* INTRCAN0REC: CAN0 transmit/receive FIFO receive completion interrupt */
	{49,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 1, 2  },	/* INTRCAN2REC: CAN2 transmit/receive FIFO receive completion interrupt */
	{49,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 2, 2  },	/* INTRCAN4REC: CAN4 transmit/receive FIFO receive completion interrupt */
	{50,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 0, 3  },	/* INTRCAN1REC: CAN1 transmit/receive FIFO receive completion interrupt */
	{50,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 1, 3  },	/* INTRCAN3REC: CAN3 transmit/receive FIFO receive completion interrupt */
	{50,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 2, 3  },	/* INTRCAN5REC: CAN5 transmit/receive FIFO receive completion interrupt */
	{51,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 0, 4  },	/* INTRCAN0TRX: CAN0 transmit interrupt */
	{51,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 1, 4  },	/* INTRCAN2TRX: CAN2 transmit interrupt */
	{51,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 2, 4  },	/* INTRCAN4TRX: CAN4 transmit interrupt */
	{52,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 0, 5  },	/* INTRCAN1TRX: CAN1 transmit interrupt */
	{52,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 1, 5  },	/* INTRCAN3TRX: CAN3 transmit interrupt */
	{52,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 2, 5  },	/* INTRCAN5TRX: CAN5 transmit interrupt */
	{53,  INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTXCAN0FUNC: XCAN0 functional relevant */
	{54,  INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTXCAN0ERR: XCAN0 functional error relevant */
	{55,  INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTXCAN0SAFETY: XCAN0 safety relevant */
	{56,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 10 },	/* INTTAUJ0I0: Channel 0 interrupt */
	{56,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 10 },	/* INTTAUJ0I1: Channel 1 interrupt */
	{56,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 10 },	/* INTTAUJ0I2: Channel 2 interrupt */
	{56,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 10 },	/* INTTAUJ0I3: Channel 3 interrupt */
	{57,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 11 },	/* INTTAUJ1I0: Channel 0 interrupt */
	{57,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 11 },	/* INTTAUJ1I1: Channel 1 interrupt */
	{57,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 11 },	/* INTTAUJ1I2: Channel 2 interrupt */
	{57,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 11 },	/* INTTAUJ1I3: Channel 3 interrupt */
	{58,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 12 },	/* INTTAUJ2I0: Channel 0 interrupt */
	{58,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 12 },	/* INTTAUJ2I1: Channel 1 interrupt */
	{58,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 12 },	/* INTTAUJ2I2: Channel 2 interrupt */
	{58,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 12 },	/* INTTAUJ2I3: Channel 3 interrupt */
	{59,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 13 },	/* INTTAUJ3I0: Channel 0 interrupt */
	{59,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 13 },	/* INTTAUJ3I1: Channel 1 interrupt */
	{59,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 13 },	/* INTTAUJ3I2: Channel 2 interrupt */
	{59,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 13 },	/* INTTAUJ3I3: Channel 3 interrupt */
	{60,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 14 },	/* INTTAUD0I1: TAUD0 Channel 1 interrupt */
	{60,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 14 },	/* INTTAUD0I3: TAUD0 Channel 3 interrupt */
	{60,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 14 },	/* INTTAUD0I5: TAUD0 Channel 5 interrupt */
	{60,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 14 },	/* INTTAUD0I7: TAUD0 Channel 7 interrupt */
	{60,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 4, 14 },	/* INTTAUD0I9: TAUD0 Channel 9 interrupt */
	{60,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 5, 14 },	/* INTTAUD0I11: TAUD0 Channel 11 interrupt */
	{60,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 6, 14 },	/* INTTAUD0I13: TAUD0 Channel 13 interrupt */
	{60,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 7, 14 },	/* INTTAUD0I15: TAUD0 Channel 15 interrupt */
	{61,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 15 },	/* INTTAUD1I0: TAUD1 Channel 0 interrupt */
	{61,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 15 },	/* INTTAUD1I2: TAUD1 Channel 2 interrupt */
	{61,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 15 },	/* INTTAUD1I4: TAUD1 Channel 4 interrupt */
	{61,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 15 },	/* INTTAUD1I6: TAUD1 Channel 6 interrupt */
	{61,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 4, 15 },	/* INTTAUD1I8: TAUD1 Channel 8 interrupt */
	{61,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 5, 15 },	/* INTTAUD1I10: TAUD1 Channel 10 interrupt */
	{61,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 6, 15 },	/* INTTAUD1I12: TAUD1 Channel 12 interrupt */
	{61,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 7, 15 },	/* INTTAUD1I14: TAUD1 Channel 14 interrupt */
	{62,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 16 },	/* INTTAUD1I1: TAUD1 Channel 1 interrupt */
	{62,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 16 },	/* INTTAUD1I3: TAUD1 Channel 3 interrupt */
	{62,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 16 },	/* INTTAUD1I5: TAUD1 Channel 5 interrupt */
	{62,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 16 },	/* INTTAUD1I7: TAUD1 Channel 7 interrupt */
	{62,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 4, 16 },	/* INTTAUD1I9: TAUD1 Channel 9 interrupt */
	{62,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 5, 16 },	/* INTTAUD1I11: TAUD1 Channel 11 interrupt */
	{62,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 6, 16 },	/* INTTAUD1I13: TAUD1 Channel 13 interrupt */
	{62,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 7, 16 },	/* INTTAUD1I15: TAUD1 Channel 15 interrupt */
	{63,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 17 },	/* INTRLIN30: RLIN30 interrupt */
	{63,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 17 },	/* INTRLIN31: RLIN31 interrupt */
	{63,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 17 },	/* INTRLIN32: RLIN32 interrupt */
	{63,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 17 },	/* INTRLIN33: RLIN33 interrupt */
	{63,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 4, 17 },	/* INTRLIN34: RLIN34 interrupt */
	{63,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 5, 17 },	/* INTRLIN35: RLIN35 interrupt */
	{63,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 6, 17 },	/* INTRLIN36: RLIN36 interrupt */
	{63,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 7, 17 },	/* INTRLIN37: RLIN37 interrupt */
	{64,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 18 },	/* INTRLIN30UR0: RLIN30 transmit interrupt */
	{64,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 18 },	/* INTRLIN31UR0: RLIN31 transmit interrupt */
	{64,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 18 },	/* INTRLIN32UR0: RLIN32 transmit interrupt */
	{64,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 18 },	/* INTRLIN33UR0: RLIN33 transmit interrupt */
	{64,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 4, 18 },	/* INTRLIN34UR0: RLIN34 transmit interrupt */
	{64,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 5, 18 },	/* INTRLIN35UR0: RLIN35 transmit interrupt */
	{64,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 6, 18 },	/* INTRLIN36UR0: RLIN36 transmit interrupt */
	{64,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 7, 18 },	/* INTRLIN37UR0: RLIN37 transmit interrupt */
	{65,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 19 },	/* INTRLIN30UR1: RLIN30 receive completion interrupt */
	{65,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 19 },	/* INTRLIN31UR1: RLIN31 receive completion interrupt */
	{65,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 19 },	/* INTRLIN32UR1: RLIN32 receive completion interrupt */
	{65,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 19 },	/* INTRLIN33UR1: RLIN33 receive completion interrupt */
	{65,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 4, 19 },	/* INTRLIN34UR1: RLIN34 receive completion interrupt */
	{65,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 5, 19 },	/* INTRLIN35UR1: RLIN35 receive completion interrupt */
	{65,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 6, 19 },	/* INTRLIN36UR1: RLIN36 receive completion interrupt */
	{65,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 7, 19 },	/* INTRLIN37UR1: RLIN37 receive completion interrupt */
	{66,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 20 },	/* INTRLIN30UR2: RLIN30 status interrupt */
	{66,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 20 },	/* INTRLIN31UR2: RLIN31 status interrupt */
	{66,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 20 },	/* INTRLIN32UR2: RLIN32 status interrupt */
	{66,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 20 },	/* INTRLIN33UR2: RLIN33 status interrupt */
	{66,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 4, 20 },	/* INTRLIN34UR2: RLIN34 status interrupt */
	{66,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 5, 20 },	/* INTRLIN35UR2: RLIN35 status interrupt */
	{66,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 6, 20 },	/* INTRLIN36UR2: RLIN36 status interrupt */
	{66,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 7, 20 },	/* INTRLIN37UR2: RLIN37 status interrupt */
	{67,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 21 },	/* INTRSENT0RI: RSENT0 receive interrupt */
	{67,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 21 },	/* INTRSENT2RI: RSENT2 receive interrupt */
	{67,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 21 },	/* INTRSENT4RI: RSENT4 receive interrupt */
	{67,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 21 },	/* INTRSENT6RI: RSENT6 receive interrupt */
	{68,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 22 },	/* INTRSENT1RI: RSENT1 receive interrupt */
	{68,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 22 },	/* INTRSENT3RI: RSENT3 receive interrupt */
	{68,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 22 },	/* INTRSENT5RI: RSENT5 receive interrupt */
	{68,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 22 },	/* INTRSENT7RI: RSENT7 receive interrupt */
	{69,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 0, 6  },	/* INTRSENT0SI: RSENT0 status interrupt */
	{69,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 1, 6  },	/* INTRSENT2SI: RSENT2 status interrupt */
	{69,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 2, 6  },	/* INTRSENT4SI: RSENT4 status interrupt */
	{69,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 3, 6  },	/* INTRSENT6SI: RSENT6 status interrupt */
	{70,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 0, 7  },	/* INTRSENT1SI: RSENT1 status interrupt */
	{70,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 1, 7  },	/* INTRSENT3SI: RSENT3 status interrupt */
	{70,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 2, 7  },	/* INTRSENT5SI: RSENT5 status interrupt */
	{70,  INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 3, 7  },	/* INTRSENT7SI: RSENT7 status interrupt */
	{71,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTENCA0IOV: ENCA0 overflow interrupt */
	{72,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTENCA0I0: ENCA0 capture/compare match interrupt 0 */
	{73,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTENCA0I1: ENCA0 capture/compare match interrupt 1 */
	{74,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTENCA0IUD: ENCA0 underflow interrupt */
	{75,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTENCA0IEC: ENCA0 encoder clear interrupt (phase Z) */
	{76,  (INTC_e_IRQTYPE)0,    INTC_e_ctrl_none,  0, 0  },	/* Reserved: - */
	{77,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ0: External interrupt 0 */
	{78,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ1: External interrupt 1 */
	{79,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ2: External interrupt 2 */
	{80,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ3: External interrupt 3 */
	{81,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ4: External interrupt 4 */
	{82,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ5: External interrupt 5 */
	{83,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ6: External interrupt 6 */
	{84,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ16: External interrupt 16 */
	{85,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ18: External interrupt 18 */
	{86,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ19: External interrupt 19 */
	{87,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ20: External interrupt 20 */
	{88,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ21: External interrupt 21 */
	{89,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ22: External interrupt 22 */
	{90,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ23: External interrupt 23 */
	{91,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ24: External interrupt 24 */
	{92,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRTCA01S: RTCA0 1-second interval interrupt */
	{93,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRTCA0AL: RTCA0 Alarm interrupt */
	{94,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRTCA0R: RTCA0 Fixed interval interrupt */
	{95,  INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTS2H0: Inter-PE interrupt from RSIP-M30A to INTC2 (Interrupt request from RSIP-M30A to CPU (PE)) */
	{96,  INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTPWGCG00: PWGC unit 0 of group 0 interrupt */
	{97,  INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTPWGCG01: PWGC unit 0 of group 1 interrupt */
	{98,  INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTPWGCG02: PWGC unit 0 of group 2 interrupt */
	{99,  INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTPWSDQFULL: PWSD queue full interrupt */
	{100, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 0, 8  },	/* INTCXP10TI: CXP10 transfer interrupt */
	{100, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 1, 8  },	/* INTCXP12TI: CXP12 transfer interrupt */
	{101, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 0, 9  },	/* INTCXP10RI: CXP10 receive interrupt */
	{101, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 1, 9  },	/* INTCXP12RI: CXP12 receive interrupt */
	{102, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 0, 10 },	/* INTCXP10SI: CXP10 status interrupt */
	{102, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 1, 10 },	/* INTCXP12SI: CXP12 status interrupt */
	{103, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 0, 11 },	/* INTCXP11TI: CXP11 transfer interrupt */
	{103, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 1, 11 },	/* INTCXP13TI: CXP13 transfer interrupt */
	{104, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 0, 12 },	/* INTCXP11RI: CXP11 receive interrupt */
	{104, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 1, 12 },	/* INTCXP13RI: CXP13 receive interrupt */
	{105, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 0, 13 },	/* INTCXP11SI: CXP11 status interrupt */
	{105, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUL, 1, 13 },	/* INTCXP13SI: CXP13 status interrupt */
	{106, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRI3C0RESP: RI3C0 Normal Response queue full */
	{107, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRI3C0CMD: RI3C0 Normal Command queue empty */
	{108, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRI3C0IBI: RI3C0 Normal IBI Status queue full */
	{109, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRI3C0RX0: RI3C0 Normal Rx Data buffer 0 full */
	{110, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRI3C0TX0: RI3C0 Normal Tx Data buffer 0 empty */
	{111, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRI3C0RCV: RI3C0 Normal Receive Status queue full */
	{112, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRI3C0HRESP: RI3C0 High Priority Response queue full */
	{113, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRI3C0HCMD: RI3C0 High Priority Command queue empty */
	{114, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRI3C0HRX: RI3C0 High Priority Rx Data buffer full */
	{115, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRI3C0HTX: RI3C0 High Priority Tx Data buffer empty */
	{116, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTRI3C0TEND: RI3C0 Transmit end  */
	{117, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTRI3C0EEI: RI3C0 Communication error / event  */
	{118, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTRIIC0EE: RIIC0 communication error/event generation interrupt */
	{119, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRIIC0RI: RIIC0 receive end interrupt */
	{120, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRIIC0TI: RIIC0 transmit data empty interrupt */
	{121, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTRIIC0TEI: RIIC0 transmit end interrupt */
	{122, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTRIIC1EE: RIIC1 communication error/event generation interrupt */
	{123, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRIIC1RI: RIIC1 receive end interrupt */
	{124, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRIIC1TI: RIIC1 transmit data empty interrupt */
	{125, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTRIIC1TEI: RIIC1 transmit end interrupt */
	{126, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTCWEND: LPSB0 Port polling end interrupt */
	{127, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTDPE: LPSB0 Digital port error interrupt */
	{128, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 23 },	/* INTLPSTM0: LPSB0 Interval Timer 0 Interrupt */
	{128, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 23 },	/* INTLPSTM2: LPSB0 Interval Timer 2 Interrupt */
	{128, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 23 },	/* INTLPSTM4: LPSB0 Interval Timer 4 Interrupt */
	{129, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 24 },	/* INTLPSTM1: LPSB0 Interval Timer 1 Interrupt */
	{129, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 24 },	/* INTLPSTM3: LPSB0 Interval Timer 3 Interrupt */
	{130, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTRSIPMFATALERR: RSIP-M30A fatal error notification */
	{131, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTWDTBATIT: WDTBA interrupt */
	{132, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTDCUTDI: Dedicated interrupt for on-chip debug function */
	{133, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTSSIF0TX: Transmission data empty for channel 0 */
	{134, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTSSIF0RX: Reception data full for channel 0 */
	{135, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTSSIF0: Multi-purpose interrupt for channel 0 */
	{136, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTSSIF1TX: Transmission data empty for channel 1 */
	{137, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTSSIF1RX: Reception data full for channel 1 */
	{138, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTSSIF1: Multi-purpose interrupt for channel 1 */
	{139, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 25 },	/* INTPDMAC1CH0: pDMAC1 channel 0 transfer completion */
	{139, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 25 },	/* INTPDMAC1CH2: pDMAC1 channel 2 transfer completion */
	{139, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 25 },	/* INTPDMAC1CH4: pDMAC1 channel 4 transfer completion */
	{139, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 25 },	/* INTPDMAC1CH6: pDMAC1 channel 6 transfer completion */
	{140, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 26 },	/* INTPDMAC1CH1: pDMAC1 channel 1 transfer completion */
	{140, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 26 },	/* INTPDMAC1CH3: pDMAC1 channel 3 transfer completion */
	{140, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 26 },	/* INTPDMAC1CH5: pDMAC1 channel 5 transfer completion */
	{140, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 26 },	/* INTPDMAC1CH7: pDMAC1 channel 7 transfer completion */
	{141, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 27 },	/* INTTAUD2I0: TAUD2 Channel 0 interrupt */
	{141, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 27 },	/* INTTAUD2I2: TAUD2 Channel 2 interrupt */
	{141, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 27 },	/* INTTAUD2I4: TAUD2 Channel 4 interrupt */
	{141, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 27 },	/* INTTAUD2I6: TAUD2 Channel 6 interrupt */
	{141, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 4, 27 },	/* INTTAUD2I8: TAUD2 Channel 8 interrupt */
	{141, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 5, 27 },	/* INTTAUD2I10: TAUD2 Channel 10 interrupt */
	{141, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 6, 27 },	/* INTTAUD2I12: TAUD2 Channel 12 interrupt */
	{141, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 7, 27 },	/* INTTAUD2I14: TAUD2 Channel 14 interrupt */
	{142, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 28 },	/* INTTAUD2I1: TAUD2 Channel 1 interrupt */
	{142, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 28 },	/* INTTAUD2I3: TAUD2 Channel 3 interrupt */
	{142, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 28 },	/* INTTAUD2I5: TAUD2 Channel 5 interrupt */
	{142, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 28 },	/* INTTAUD2I7: TAUD2 Channel 7 interrupt */
	{142, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 4, 28 },	/* INTTAUD2I9: TAUD2 Channel 9 interrupt */
	{142, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 5, 28 },	/* INTTAUD2I11: TAUD2 Channel 11 interrupt */
	{142, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 6, 28 },	/* INTTAUD2I13: TAUD2 Channel 13 interrupt */
	{142, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 7, 28 },	/* INTTAUD2I15: TAUD2 Channel 15 interrupt */
	{143, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ7: External interrupt 7 */
	{144, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ9: External interrupt 9 */
	{145, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ10: External interrupt 10 */
	{146, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ11: External interrupt 11 */
	{147, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ12: External interrupt 12 */
	{148, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ13: External interrupt 13 */
	{149, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ14: External interrupt 14 */
	{150, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ15: External interrupt 15 */
	{151, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ17: External interrupt 17 */
	{152, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK1ERR: ADCK1 A/D error interrupt upper/lower limit error interrupt */
	{153, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK1I0: ADCK1 Scan group 0 (SG0) end interrupt  */
	{154, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK1I1: ADCK1 Scan group 1 (SG1) end interrupt */
	{155, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK1I2: ADCK1 Scan group 2 (SG2) end interrupt */
	{156, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK1I3: ADCK1 Scan group 3 (SG3) end interrupt */
	{157, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK1I4: ADCK1 Scan group 4 (SG4) end interrupt */
	{158, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK1MPX: ADCK1 MPX DMA trigger request */
	{159, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTADCK1SD: ADCK1 SG-Diag end interrupt */
	{160, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 29 },	/* INTRLIN38: RLIN38 interrupt */
	{160, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 29 },	/* INTRLIN39: RLIN39 interrupt */
	{160, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 29 },	/* INTRLIN310: RLIN310 interrupt */
	{160, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 29 },	/* INTRLIN311: RLIN311 interrupt */
	{160, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 4, 29 },	/* INTRLIN312: RLIN312 interrupt */
	{160, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 5, 29 },	/* INTRLIN313: RLIN313 interrupt */
	{160, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 6, 29 },	/* INTRLIN314: RLIN314 interrupt */
	{160, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 7, 29 },	/* INTRLIN315: RLIN315 interrupt */
	{161, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 30 },	/* INTRLIN38UR0: RLIN38 transmit interrupt */
	{161, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 30 },	/* INTRLIN39UR0: RLIN39 transmit interrupt */
	{161, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 30 },	/* INTRLIN310UR0: RLIN310 transmit interrupt */
	{161, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 30 },	/* INTRLIN311UR0: RLIN311 transmit interrupt */
	{161, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 4, 30 },	/* INTRLIN312UR0: RLIN312 transmit interrupt */
	{161, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 5, 30 },	/* INTRLIN313UR0: RLIN313 transmit interrupt */
	{161, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 6, 30 },	/* INTRLIN314UR0: RLIN314 transmit interrupt */
	{161, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 7, 30 },	/* INTRLIN315UR0: RLIN315 transmit interrupt */
	{162, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 31 },	/* INTRLIN38UR1: RLIN38 receive completion interrupt */
	{162, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 31 },	/* INTRLIN39UR1: RLIN39 receive completion interrupt */
	{162, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 31 },	/* INTRLIN310UR1: RLIN310 receive completion interrupt */
	{162, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 31 },	/* INTRLIN311UR1: RLIN311 receive completion interrupt */
	{162, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 4, 31 },	/* INTRLIN312UR1: RLIN312 receive completion interrupt */
	{162, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 5, 31 },	/* INTRLIN313UR1: RLIN313 receive completion interrupt */
	{162, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 6, 31 },	/* INTRLIN314UR1: RLIN314 receive completion interrupt */
	{162, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 7, 31 },	/* INTRLIN315UR1: RLIN315 receive completion interrupt */
	{163, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 32 },	/* INTRLIN38UR2: RLIN38 status interrupt */
	{163, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 32 },	/* INTRLIN39UR2: RLIN39 status interrupt */
	{163, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 2, 32 },	/* INTRLIN310UR2: RLIN310 status interrupt */
	{163, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 3, 32 },	/* INTRLIN311UR2: RLIN311 status interrupt */
	{163, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 4, 32 },	/* INTRLIN312UR2: RLIN312 status interrupt */
	{163, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 5, 32 },	/* INTRLIN313UR2: RLIN313 status interrupt */
	{163, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 6, 32 },	/* INTRLIN314UR2: RLIN314 status interrupt */
	{163, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 7, 32 },	/* INTRLIN315UR2: RLIN315 status interrupt */
	{164, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTOSTM1TINT: OSTM1 interrupt */
	{165, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTOSTM2TINT: OSTM2 interrupt */
	{166, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTETNF0DATA: ETNF0 Data related interrupt */
	{167, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTETNF0ERR: ETNF0 Data related interrupt */
	{168, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTETNF0MNG: ETNF0 Management related interrupt */
	{169, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTETNF0MAC: ETNF0 MAC interrupt */
	{170, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ8: External interrupt 8 */
	{171, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTPSI50SI: PSI50 status interrupt */
	{172, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTPSI50RI: PSI50 receive interrupt */
	{173, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTPSI50TI: PSI50 transfer interrupt */
	{174, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTPSI51SI: PSI51 status interrupt */
	{175, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTPSI51RI: PSI51 receive interrupt */
	{176, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTPSI51TI: PSI51 transfer interrupt */
	{177, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTPSI5W: Interruption reports the end of all channel enable */
	{178, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTMMCA0: MMCA interrupt */
	{179, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTOSTM3TINT: OSTM3 interrupt */
	{180, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* INTOSTM4TINT: OSTM4 interrupt */
	{181, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTXCAN1FUNC: XCAN1 functional relevant */
	{182, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTXCAN1ERR: XCAN1 functional error relevant */
	{183, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTXCAN1SAFETY: XCAN1 safety relevant */
	{184, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTETND00: ETND0 (Endstation) interrupt 0 */
	{185, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTETND01: ETND0 (Endstation) interrupt 1 */
	{186, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTETND02: ETND0 (Endstation) interrupt 2 */
	{187, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTETND03: ETND0 (Endstation) interrupt 3 */
	{188, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTETND04: ETND0 (Endstation) interrupt 4 */
	{189, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTETND05: ETND0 (Endstation) interrupt 5 */
	{190, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTETND06: ETND0 (Endstation) interrupt 6 */
	{191, INTC_e_IRQTYPE_level, INTC_e_ctrl_none,  0, 0  },	/* INTGPTP: gPTP interrupt */
	{192, INTC_e_IRQTYPE_edge,  INTC_e_ctrl_none,  0, 0  },	/* IRQ25: External interrupt 25 */
	{193, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 33 },	/* INTRLIN316: RLIN316 interrupt */
	{193, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 33 },	/* INTRLIN317: RLIN317 interrupt */
	{194, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 34 },	/* INTRLIN316UR0: RLIN316 transmit interrupt */
	{194, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 34 },	/* INTRLIN317UR0: RLIN317 transmit interrupt */
	{195, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 35 },	/* INTRLIN316UR1: RLIN316 receive completion interrupt */
	{195, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 35 },	/* INTRLIN317UR1: RLIN317 receive completion interrupt */
	{196, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 0, 36 },	/* INTRLIN316UR2: RLIN316 status interrupt */
	{196, INTC_e_IRQTYPE_level, INTC_e_ctrl_IMFUP, 1, 36 } 	/* INTRLIN317UR2: RLIN317 status interrupt */
};


/*******************************************************************************
* Array of interrupt index
*******************************************************************************/
/* INTTAUDnIm */
INTC_e_index	INTC_e_index_INTTAUDnIm[][16] = {
		{ INTC_e_index_INTTAUD0I0,  INTC_e_index_INTTAUD0I1,  INTC_e_index_INTTAUD0I2,  INTC_e_index_INTTAUD0I3,
		  INTC_e_index_INTTAUD0I4,  INTC_e_index_INTTAUD0I5,  INTC_e_index_INTTAUD0I6,  INTC_e_index_INTTAUD0I7,
		  INTC_e_index_INTTAUD0I8,  INTC_e_index_INTTAUD0I9,  INTC_e_index_INTTAUD0I10, INTC_e_index_INTTAUD0I11,
		  INTC_e_index_INTTAUD0I12, INTC_e_index_INTTAUD0I13, INTC_e_index_INTTAUD0I14, INTC_e_index_INTTAUD0I15
		},
		{ INTC_e_index_INTTAUD1I0,  INTC_e_index_INTTAUD1I1,  INTC_e_index_INTTAUD1I2,  INTC_e_index_INTTAUD1I3,
		  INTC_e_index_INTTAUD1I4,  INTC_e_index_INTTAUD1I5,  INTC_e_index_INTTAUD1I6,  INTC_e_index_INTTAUD1I7,
		  INTC_e_index_INTTAUD1I8,  INTC_e_index_INTTAUD1I9,  INTC_e_index_INTTAUD1I10, INTC_e_index_INTTAUD1I11,
		  INTC_e_index_INTTAUD1I12, INTC_e_index_INTTAUD1I13, INTC_e_index_INTTAUD1I14, INTC_e_index_INTTAUD1I15
		},
		{ INTC_e_index_INTTAUD2I0,  INTC_e_index_INTTAUD2I1,  INTC_e_index_INTTAUD2I2,  INTC_e_index_INTTAUD2I3,
		  INTC_e_index_INTTAUD2I4,  INTC_e_index_INTTAUD2I5,  INTC_e_index_INTTAUD2I6,  INTC_e_index_INTTAUD2I7,
		  INTC_e_index_INTTAUD2I8,  INTC_e_index_INTTAUD2I9,  INTC_e_index_INTTAUD2I10, INTC_e_index_INTTAUD2I11,
		  INTC_e_index_INTTAUD2I12, INTC_e_index_INTTAUD2I13, INTC_e_index_INTTAUD2I14, INTC_e_index_INTTAUD2I15
		}
};

/* INTEINTSWp */
INTC_e_index	INTC_e_index_INTEINTSWp[] = {
		INTC_e_index_INTEINTSW0, INTC_e_index_INTEINTSW1, INTC_e_index_INTEINTSW2, INTC_e_index_INTEINTSW3
};

/* INTLPSTMx */
INTC_e_index	INTC_e_index_INTLPSTMx[] = {
		INTC_e_index_INTLPSTM0, INTC_e_index_INTLPSTM1, INTC_e_index_INTLPSTM2, INTC_e_index_INTLPSTM3, INTC_e_index_INTLPSTM4
};

/* IRQn */
INTC_e_index	INTC_e_index_IRQn[] = {
		INTC_e_index_IRQ0,  INTC_e_index_IRQ1,  INTC_e_index_IRQ2,  INTC_e_index_IRQ3,
		INTC_e_index_IRQ4,  INTC_e_index_IRQ5,  INTC_e_index_IRQ6,  INTC_e_index_IRQ7,
		INTC_e_index_IRQ8,  INTC_e_index_IRQ9,  INTC_e_index_IRQ10, INTC_e_index_IRQ11,
		INTC_e_index_IRQ12, INTC_e_index_IRQ13, INTC_e_index_IRQ14, INTC_e_index_IRQ15,
		INTC_e_index_IRQ16, INTC_e_index_IRQ17, INTC_e_index_IRQ18, INTC_e_index_IRQ19,
		INTC_e_index_IRQ20, INTC_e_index_IRQ21, INTC_e_index_IRQ22, INTC_e_index_IRQ23,
		INTC_e_index_IRQ24, INTC_e_index_IRQ25
};

