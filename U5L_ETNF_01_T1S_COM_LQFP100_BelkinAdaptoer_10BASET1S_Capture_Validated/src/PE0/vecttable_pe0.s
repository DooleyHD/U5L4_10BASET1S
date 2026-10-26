
/*******************************************************************************
* vector section
*******************************************************************************/
	.section .isr_vector
	.align	2

	/* definition of vector talbe */
	.globl	__isr_vector
__isr_vector:
	.long	__StackTop            /* Initial SP value */
	.long	Reset_Handler + 1     /* Reset Handler (Because it is a thumb instruction, the address of reset handler needs to be incremented by +1.) */
	.long	NMI_Handler           /* NMI Handler */
	.long	HardFault_Handler     /* Hard Fault Handler */
	.long	MemManage_Handler     /* MPU Fault Handler */
	.long	BusFault_Handler      /* Bus Fault Handler */
	.long	UsageFault_Handler    /* Usage Fault Handler */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	SVC_Handler           /* SVCall Handler */
	.long	DebugMon_Handler      /* Debug Monitor Handler */
	.long	0                     /* Reserved */
	.long	PendSV_Handler        /* PendSV Handler */
	.long	SysTick_Handler       /* SysTick Handler */

	/* External interrupts */
	.long	IntFunc_dummy	/* No.  0 INTECMNMI: ECM maskable interrupt1 */
	.long	IntFunc_dummy	/* No.  1 INTECMMI: ECM maskable interrupt2 */
	.long	IntFunc_dummy	/* No.  2 INTFPUEXCIRQ: FPU interrupt */
	.long	IntFunc_dummy	/* No.  3 INTTAUD0I0: TAUD0 Channel 0 interrupt */
	.long	IntFunc_dummy	/* No.  4 INTTAUD0I2: TAUD0 Channel 2 interrupt */
	.long	IntFunc_dummy	/* No.  5 INTTAUD0I4: TAUD0 Channel 4 interrupt */
	.long	IntFunc_dummy	/* No.  6 INTTAUD0I6: TAUD0 Channel 6 interrupt */
	.long	IntFunc_INTEINTSW0	/* No.  7 INTEINTSW0: Software interrupt 0 */
	.long	IntFunc_INTEINTSW1	/* No.  8 INTEINTSW1: Software interrupt 1 */
	.long	IntFunc_INTEINTSW2	/* No.  9 INTEINTSW2: Software interrupt 2 */
	.long	IntFunc_INTEINTSW3	/* No. 10 INTEINTSW3: Software interrupt 3 */
	.long	IntFunc_dummy	/* No. 11 INTS2HS0: Inter-PE interrupt from RSIP-M30A to CPU0 (Single interrupt request from RSIP-M30A to CPU) */
	.long	IntFunc_dummy	/* No. 12 INTWDTB0TIT: WDTB0 interrupt */
	.long	IntFunc_dummy	/* No. 13 INTTAUD0I8: TAUD0 Channel 8 interrupt */
	.long	IntFunc_dummy	/* No. 14 INTTAUD0I10: TAUD0 Channel 10 interrupt */
	.long	IntFunc_dummy	/* No. 15 INTTAUD0I12: TAUD0 Channel 12 interrupt */
	.long	IntFunc_dummy	/* No. 16 INTTAUD0I14: TAUD0 Channel 14 interrupt */
	.long	IntFunc_dummy	/* No. 17 INTTAPA0IPEK0: TAPA0 peak interrupt 0 */
	.long	IntFunc_dummy	/* No. 18 INTTAPA0IVLY0: TAPA0 valley interrupt 0 */
	.long	IntFunc_dummy	/* No. 19 INTPDMACERR: pDMAC transfer error interrupt */
	.long	IntFunc_dummy	/* No. 20 INTDTSERR: DTS transfer error */
	.long	IntFunc_dummy	/* No. 21 INTDCUDEGRADPE: Interrupt for degradation */
	.long	IntFunc_dummy	/* No. 22 INTFL0ENDNM: FPSYS0 Flash sequencer processing end interrupt */
	.long	IntFunc_dummy	/* No. 23 INTFL2ENDNM: FPSYS2 Flash sequencer processing end interrupt */
	.long	IntFunc_dummy	/* No. 24 INTDTS7TO0: DTS ch7-0 transfer end */
	.long	IntFunc_dummy	/* No. 25 INTDTSCT7TO0: DTS ch7-0 transfer count match */
	.long	IntFunc_dummy	/* No. 26 INTPDMAC0CH0: pDMAC0 channel 0 transfer completion */
//	.long	IntFunc_dummy	/* No. 26 INTPDMAC0CH2: pDMAC0 channel 2 transfer completion */
//	.long	IntFunc_dummy	/* No. 26 INTPDMAC0CH4: pDMAC0 channel 4 transfer completion */
//	.long	IntFunc_dummy	/* No. 26 INTPDMAC0CH6: pDMAC0 channel 6 transfer completion */
	.long	IntFunc_dummy	/* No. 27 INTPDMAC0CH1: pDMAC0 channel 1 transfer completion */
//	.long	IntFunc_dummy	/* No. 27 INTPDMAC0CH3: pDMAC0 channel 3 transfer completion */
//	.long	IntFunc_dummy	/* No. 27 INTPDMAC0CH5: pDMAC0 channel 5 transfer completion */
//	.long	IntFunc_dummy	/* No. 27 INTPDMAC0CH7: pDMAC0 channel 7 transfer completion */
	.long	IntFunc_dummy	/* No. 28 INTOSTM0TINT: OSTM0 interrupt */
	.long	IntFunc_dummy	/* No. 29 INTADCK0ERR: ADCK0 A/D error interrupt upper/ lower limit error interrupt  */
	.long	IntFunc_dummy	/* No. 30 INTADCK0I0: ADCK0 Scan group 0 (SG0) end interrupt  */
	.long	IntFunc_dummy	/* No. 31 INTADCK0I1: ADCK0 Scan group 1 (SG1) end interrupt */
	.long	IntFunc_dummy	/* No. 32 INTADCK0I2: ADCK0 Scan group 2 (SG2) end interrupt */
	.long	IntFunc_dummy	/* No. 33 INTADCK0I3: ADCK0 Scan group 3 (SG3) end interrupt */
	.long	IntFunc_dummy	/* No. 34 INTADCK0I4: ADCK0 Scan group 4 (SG4) end interrupt */
	.long	IntFunc_dummy	/* No. 35 INTADCK0MPX: ADCK0 MPX DMA trigger request */
	.long	IntFunc_dummy	/* No. 36 INTADCK0SD: ADCK0 SG-Diag end interrupt */
	.long	IntFunc_dummy	/* No. 37 INTCSIH0IC: CSIH0 communication status interrupt */
//	.long	IntFunc_dummy	/* No. 37 INTCSIH2IC: CSIH2 communication status interrupt */
//	.long	IntFunc_dummy	/* No. 37 INTCSIH4IC: CSIH4 communication status interrupt */
//	.long	IntFunc_dummy	/* No. 37 INTCSIH6IC: CSIH6 communication status interrupt */
	.long	IntFunc_dummy	/* No. 38 INTCSIH1IC: CSIH1 communication status interrupt */
//	.long	IntFunc_dummy	/* No. 38 INTCSIH3IC: CSIH3 communication status interrupt */
//	.long	IntFunc_dummy	/* No. 38 INTCSIH5IC: CSIH5 communication status interrupt */
//	.long	IntFunc_dummy	/* No. 38 INTCSIH7IC: CSIH7 communication status interrupt */
	.long	IntFunc_dummy	/* No. 39 INTCSIH0IR: CSIH0 receive status interrupt */
//	.long	IntFunc_dummy	/* No. 39 INTCSIH2IR: CSIH2 receive status interrupt */
//	.long	IntFunc_dummy	/* No. 39 INTCSIH4IR: CSIH4 receive status interrupt */
//	.long	IntFunc_dummy	/* No. 39 INTCSIH6IR: CSIH6 receive status interrupt */
	.long	IntFunc_dummy	/* No. 40 INTCSIH1IR: CSIH1 receive status interrupt */
//	.long	IntFunc_dummy	/* No. 40 INTCSIH3IR: CSIH3 receive status interrupt */
//	.long	IntFunc_dummy	/* No. 40 INTCSIH5IR: CSIH5 receive status interrupt */
//	.long	IntFunc_dummy	/* No. 40 INTCSIH7IR: CSIH7 receive status interrupt */
	.long	IntFunc_dummy	/* No. 41 INTCSIH0IRE: CSIH0 communication error interrupt */
//	.long	IntFunc_dummy	/* No. 41 INTCSIH2IRE: CSIH2 communication error interrupt */
//	.long	IntFunc_dummy	/* No. 41 INTCSIH4IRE: CSIH4 communication error interrupt */
//	.long	IntFunc_dummy	/* No. 41 INTCSIH6IRE: CSIH6 communication error interrupt */
	.long	IntFunc_dummy	/* No. 42 INTCSIH1IRE: CSIH1 communication error interrupt */
//	.long	IntFunc_dummy	/* No. 42 INTCSIH3IRE: CSIH3 communication error interrupt */
//	.long	IntFunc_dummy	/* No. 42 INTCSIH5IRE: CSIH5 communication error interrupt */
//	.long	IntFunc_dummy	/* No. 42 INTCSIH7IRE: CSIH7 communication error interrupt */
	.long	IntFunc_dummy	/* No. 43 INTCSIH0IJC: CSIH0 job completion interrupt */
//	.long	IntFunc_dummy	/* No. 43 INTCSIH2IJC: CSIH2 job completion interrupt */
//	.long	IntFunc_dummy	/* No. 43 INTCSIH4IJC: CSIH4 job completion interrupt */
//	.long	IntFunc_dummy	/* No. 43 INTCSIH6IJC: CSIH6 job completion interrupt */
	.long	IntFunc_dummy	/* No. 44 INTCSIH1IJC: CSIH1 job completion interrupt */
//	.long	IntFunc_dummy	/* No. 44 INTCSIH3IJC: CSIH3 job completion interrupt */
//	.long	IntFunc_dummy	/* No. 44 INTCSIH5IJC: CSIH5 job completion interrupt */
//	.long	IntFunc_dummy	/* No. 44 INTCSIH7IJC: CSIH7 job completion interrupt */
	.long	IntFunc_dummy	/* No. 45 INTRCANGERR0: RSCAN0 CAN global error interrupt */
	.long	IntFunc_dummy	/* No. 46 INTRCANGRECC0: RSCAN0 CAN receive FIFO interrupt */
	.long	IntFunc_dummy	/* No. 47 INTRCAN0ERR: CAN0 error interrupt */
//	.long	IntFunc_dummy	/* No. 47 INTRCAN2ERR: CAN2 error interrupt */
//	.long	IntFunc_dummy	/* No. 47 INTRCAN4ERR: CAN4 error interrupt */
	.long	IntFunc_dummy	/* No. 48 INTRCAN1ERR: CAN1 error interrupt */
//	.long	IntFunc_dummy	/* No. 48 INTRCAN3ERR: CAN3 error interrupt */
//	.long	IntFunc_dummy	/* No. 48 INTRCAN5ERR: CAN5 error interrupt */
	.long	IntFunc_dummy	/* No. 49 INTRCAN0REC: CAN0 transmit/receive FIFO receive completion interrupt */
//	.long	IntFunc_dummy	/* No. 49 INTRCAN2REC: CAN2 transmit/receive FIFO receive completion interrupt */
//	.long	IntFunc_dummy	/* No. 49 INTRCAN4REC: CAN4 transmit/receive FIFO receive completion interrupt */
	.long	IntFunc_dummy	/* No. 50 INTRCAN1REC: CAN1 transmit/receive FIFO receive completion interrupt */
//	.long	IntFunc_dummy	/* No. 50 INTRCAN3REC: CAN3 transmit/receive FIFO receive completion interrupt */
//	.long	IntFunc_dummy	/* No. 50 INTRCAN5REC: CAN5 transmit/receive FIFO receive completion interrupt */
	.long	IntFunc_dummy	/* No. 51 INTRCAN0TRX: CAN0 transmit interrupt */
//	.long	IntFunc_dummy	/* No. 51 INTRCAN2TRX: CAN2 transmit interrupt */
//	.long	IntFunc_dummy	/* No. 51 INTRCAN4TRX: CAN4 transmit interrupt */
	.long	IntFunc_dummy	/* No. 52 INTRCAN1TRX: CAN1 transmit interrupt */
//	.long	IntFunc_dummy	/* No. 52 INTRCAN3TRX: CAN3 transmit interrupt */
//	.long	IntFunc_dummy	/* No. 52 INTRCAN5TRX: CAN5 transmit interrupt */
	.long	IntFunc_dummy	/* No. 53 INTXCAN0FUNC: XCAN0 functional relevant */
	.long	IntFunc_dummy	/* No. 54 INTXCAN0ERR: XCAN0 functional error relevant */
	.long	IntFunc_dummy	/* No. 55 INTXCAN0SAFETY: XCAN0 safety relevant */
	.long	IntFunc_dummy	/* No. 56 INTTAUJ0I0: Channel 0 interrupt */
//	.long	IntFunc_dummy	/* No. 56 INTTAUJ0I1: Channel 1 interrupt */
//	.long	IntFunc_dummy	/* No. 56 INTTAUJ0I2: Channel 2 interrupt */
//	.long	IntFunc_dummy	/* No. 56 INTTAUJ0I3: Channel 3 interrupt */
	.long	IntFunc_dummy	/* No. 57 INTTAUJ1I0: Channel 0 interrupt */
//	.long	IntFunc_dummy	/* No. 57 INTTAUJ1I1: Channel 1 interrupt */
//	.long	IntFunc_dummy	/* No. 57 INTTAUJ1I2: Channel 2 interrupt */
//	.long	IntFunc_dummy	/* No. 57 INTTAUJ1I3: Channel 3 interrupt */
	.long	IntFunc_dummy	/* No. 58 INTTAUJ2I0: Channel 0 interrupt */
//	.long	IntFunc_dummy	/* No. 58 INTTAUJ2I1: Channel 1 interrupt */
//	.long	IntFunc_dummy	/* No. 58 INTTAUJ2I2: Channel 2 interrupt */
//	.long	IntFunc_dummy	/* No. 58 INTTAUJ2I3: Channel 3 interrupt */
	.long	IntFunc_dummy	/* No. 59 INTTAUJ3I0: Channel 0 interrupt */
//	.long	IntFunc_dummy	/* No. 59 INTTAUJ3I1: Channel 1 interrupt */
//	.long	IntFunc_dummy	/* No. 59 INTTAUJ3I2: Channel 2 interrupt */
//	.long	IntFunc_dummy	/* No. 59 INTTAUJ3I3: Channel 3 interrupt */
	.long	IntFunc_dummy	/* No. 60 INTTAUD0I1: TAUD0 Channel 1 interrupt */
//	.long	IntFunc_dummy	/* No. 60 INTTAUD0I3: TAUD0 Channel 3 interrupt */
//	.long	IntFunc_dummy	/* No. 60 INTTAUD0I5: TAUD0 Channel 5 interrupt */
//	.long	IntFunc_dummy	/* No. 60 INTTAUD0I7: TAUD0 Channel 7 interrupt */
//	.long	IntFunc_dummy	/* No. 60 INTTAUD0I9: TAUD0 Channel 9 interrupt */
//	.long	IntFunc_dummy	/* No. 60 INTTAUD0I11: TAUD0 Channel 11 interrupt */
//	.long	IntFunc_dummy	/* No. 60 INTTAUD0I13: TAUD0 Channel 13 interrupt */
//	.long	IntFunc_dummy	/* No. 60 INTTAUD0I15: TAUD0 Channel 15 interrupt */
	.long	IntFunc_dummy	/* No. 61 INTTAUD1I0: TAUD1 Channel 0 interrupt */
//	.long	IntFunc_dummy	/* No. 61 INTTAUD1I2: TAUD1 Channel 2 interrupt */
//	.long	IntFunc_dummy	/* No. 61 INTTAUD1I4: TAUD1 Channel 4 interrupt */
//	.long	IntFunc_dummy	/* No. 61 INTTAUD1I6: TAUD1 Channel 6 interrupt */
//	.long	IntFunc_dummy	/* No. 61 INTTAUD1I8: TAUD1 Channel 8 interrupt */
//	.long	IntFunc_dummy	/* No. 61 INTTAUD1I10: TAUD1 Channel 10 interrupt */
//	.long	IntFunc_dummy	/* No. 61 INTTAUD1I12: TAUD1 Channel 12 interrupt */
//	.long	IntFunc_dummy	/* No. 61 INTTAUD1I14: TAUD1 Channel 14 interrupt */
	.long	IntFunc_dummy	/* No. 62 INTTAUD1I1: TAUD1 Channel 1 interrupt */
//	.long	IntFunc_dummy	/* No. 62 INTTAUD1I3: TAUD1 Channel 3 interrupt */
//	.long	IntFunc_dummy	/* No. 62 INTTAUD1I5: TAUD1 Channel 5 interrupt */
//	.long	IntFunc_dummy	/* No. 62 INTTAUD1I7: TAUD1 Channel 7 interrupt */
//	.long	IntFunc_dummy	/* No. 62 INTTAUD1I9: TAUD1 Channel 9 interrupt */
//	.long	IntFunc_dummy	/* No. 62 INTTAUD1I11: TAUD1 Channel 11 interrupt */
//	.long	IntFunc_dummy	/* No. 62 INTTAUD1I13: TAUD1 Channel 13 interrupt */
//	.long	IntFunc_dummy	/* No. 62 INTTAUD1I15: TAUD1 Channel 15 interrupt */
	.long	IntFunc_dummy	/* No. 63 INTRLIN30: RLIN30 interrupt */
//	.long	IntFunc_dummy	/* No. 63 INTRLIN31: RLIN31 interrupt */
//	.long	IntFunc_dummy	/* No. 63 INTRLIN32: RLIN32 interrupt */
//	.long	IntFunc_dummy	/* No. 63 INTRLIN33: RLIN33 interrupt */
//	.long	IntFunc_dummy	/* No. 63 INTRLIN34: RLIN34 interrupt */
//	.long	IntFunc_dummy	/* No. 63 INTRLIN35: RLIN35 interrupt */
//	.long	IntFunc_dummy	/* No. 63 INTRLIN36: RLIN36 interrupt */
//	.long	IntFunc_dummy	/* No. 63 INTRLIN37: RLIN37 interrupt */
	.long	IntFunc_dummy	/* No. 64 INTRLIN30UR0: RLIN30 transmit interrupt */
//	.long	IntFunc_dummy	/* No. 64 INTRLIN31UR0: RLIN31 transmit interrupt */
//	.long	IntFunc_dummy	/* No. 64 INTRLIN32UR0: RLIN32 transmit interrupt */
//	.long	IntFunc_dummy	/* No. 64 INTRLIN33UR0: RLIN33 transmit interrupt */
//	.long	IntFunc_dummy	/* No. 64 INTRLIN34UR0: RLIN34 transmit interrupt */
//	.long	IntFunc_dummy	/* No. 64 INTRLIN35UR0: RLIN35 transmit interrupt */
//	.long	IntFunc_dummy	/* No. 64 INTRLIN36UR0: RLIN36 transmit interrupt */
//	.long	IntFunc_dummy	/* No. 64 INTRLIN37UR0: RLIN37 transmit interrupt */
	.long	IntFunc_dummy	/* No. 65 INTRLIN30UR1: RLIN30 receive completion interrupt */
//	.long	IntFunc_dummy	/* No. 65 INTRLIN31UR1: RLIN31 receive completion interrupt */
//	.long	IntFunc_dummy	/* No. 65 INTRLIN32UR1: RLIN32 receive completion interrupt */
//	.long	IntFunc_dummy	/* No. 65 INTRLIN33UR1: RLIN33 receive completion interrupt */
//	.long	IntFunc_dummy	/* No. 65 INTRLIN34UR1: RLIN34 receive completion interrupt */
//	.long	IntFunc_dummy	/* No. 65 INTRLIN35UR1: RLIN35 receive completion interrupt */
//	.long	IntFunc_dummy	/* No. 65 INTRLIN36UR1: RLIN36 receive completion interrupt */
//	.long	IntFunc_dummy	/* No. 65 INTRLIN37UR1: RLIN37 receive completion interrupt */
	.long	IntFunc_dummy	/* No. 66 INTRLIN30UR2: RLIN30 status interrupt */
//	.long	IntFunc_dummy	/* No. 66 INTRLIN31UR2: RLIN31 status interrupt */
//	.long	IntFunc_dummy	/* No. 66 INTRLIN32UR2: RLIN32 status interrupt */
//	.long	IntFunc_dummy	/* No. 66 INTRLIN33UR2: RLIN33 status interrupt */
//	.long	IntFunc_dummy	/* No. 66 INTRLIN34UR2: RLIN34 status interrupt */
//	.long	IntFunc_dummy	/* No. 66 INTRLIN35UR2: RLIN35 status interrupt */
//	.long	IntFunc_dummy	/* No. 66 INTRLIN36UR2: RLIN36 status interrupt */
//	.long	IntFunc_dummy	/* No. 66 INTRLIN37UR2: RLIN37 status interrupt */
	.long	IntFunc_dummy	/* No. 67 INTRSENT0RI: RSENT0 receive interrupt */
//	.long	IntFunc_dummy	/* No. 67 INTRSENT2RI: RSENT2 receive interrupt */
//	.long	IntFunc_dummy	/* No. 67 INTRSENT4RI: RSENT4 receive interrupt */
//	.long	IntFunc_dummy	/* No. 67 INTRSENT6RI: RSENT6 receive interrupt */
	.long	IntFunc_dummy	/* No. 68 INTRSENT1RI: RSENT1 receive interrupt */
//	.long	IntFunc_dummy	/* No. 68 INTRSENT3RI: RSENT3 receive interrupt */
//	.long	IntFunc_dummy	/* No. 68 INTRSENT5RI: RSENT5 receive interrupt */
//	.long	IntFunc_dummy	/* No. 68 INTRSENT7RI: RSENT7 receive interrupt */
	.long	IntFunc_dummy	/* No. 69 INTRSENT0SI: RSENT0 status interrupt */
//	.long	IntFunc_dummy	/* No. 69 INTRSENT2SI: RSENT2 status interrupt */
//	.long	IntFunc_dummy	/* No. 69 INTRSENT4SI: RSENT4 status interrupt */
//	.long	IntFunc_dummy	/* No. 69 INTRSENT6SI: RSENT6 status interrupt */
	.long	IntFunc_dummy	/* No. 70 INTRSENT1SI: RSENT1 status interrupt */
//	.long	IntFunc_dummy	/* No. 70 INTRSENT3SI: RSENT3 status interrupt */
//	.long	IntFunc_dummy	/* No. 70 INTRSENT5SI: RSENT5 status interrupt */
//	.long	IntFunc_dummy	/* No. 70 INTRSENT7SI: RSENT7 status interrupt */
	.long	IntFunc_dummy	/* No. 71 INTENCA0IOV: ENCA0 overflow interrupt */
	.long	IntFunc_dummy	/* No. 72 INTENCA0I0: ENCA0 capture/compare match interrupt 0 */
	.long	IntFunc_dummy	/* No. 73 INTENCA0I1: ENCA0 capture/compare match interrupt 1 */
	.long	IntFunc_dummy	/* No. 74 INTENCA0IUD: ENCA0 underflow interrupt */
	.long	IntFunc_dummy	/* No. 75 INTENCA0IEC: ENCA0 encoder clear interrupt (phase Z) */
	.long	IntFunc_dummy	/* No. 76 Reserved: - */
	.long	IntFunc_dummy	/* No. 77 IRQ0: External interrupt 0 */
	.long	IntFunc_dummy	/* No. 78 IRQ1: External interrupt 1 */
	.long	IntFunc_dummy	/* No. 79 IRQ2: External interrupt 2 */
	.long	IntFunc_dummy	/* No. 80 IRQ3: External interrupt 3 */
	.long	IntFunc_dummy	/* No. 81 IRQ4: External interrupt 4 */
	.long	IntFunc_dummy	/* No. 82 IRQ5: External interrupt 5 */
	.long	IntFunc_dummy	/* No. 83 IRQ6: External interrupt 6 */
	.long	IntFunc_dummy	/* No. 84 IRQ16: External interrupt 16 */
	.long	IntFunc_dummy	/* No. 85 IRQ18: External interrupt 18 */
	.long	IntFunc_dummy	/* No. 86 IRQ19: External interrupt 19 */
	.long	IntFunc_dummy	/* No. 87 IRQ20: External interrupt 20 */
	.long	IntFunc_dummy	/* No. 88 IRQ21: External interrupt 21 */
	.long	IntFunc_dummy	/* No. 89 IRQ22: External interrupt 22 */
	.long	IntFunc_dummy	/* No. 90 IRQ23: External interrupt 23 */
	.long	IntFunc_dummy	/* No. 91 IRQ24: External interrupt 24 */
	.long	IntFunc_dummy	/* No. 92 INTRTCA01S: RTCA0 1-second interval interrupt */
	.long	IntFunc_dummy	/* No. 93 INTRTCA0AL: RTCA0 Alarm interrupt */
	.long	IntFunc_dummy	/* No. 94 INTRTCA0R: RTCA0 Fixed interval interrupt */
	.long	IntFunc_dummy	/* No. 95 INTS2H0: Inter-PE interrupt from RSIP-M30A to INTC2 (Interrupt request from RSIP-M30A to CPU (PE)) */
	.long	IntFunc_dummy	/* No. 96 INTPWGCG00: PWGC unit 0 of group 0 interrupt */
	.long	IntFunc_dummy	/* No. 97 INTPWGCG01: PWGC unit 0 of group 1 interrupt */
	.long	IntFunc_dummy	/* No. 98 INTPWGCG02: PWGC unit 0 of group 2 interrupt */
	.long	IntFunc_dummy	/* No. 99 INTPWSDQFULL: PWSD queue full interrupt */
	.long	IntFunc_dummy	/* No.100 INTCXP10TI: CXP10 transfer interrupt */
//	.long	IntFunc_dummy	/* No.100 INTCXP12TI: CXP12 transfer interrupt */
	.long	IntFunc_dummy	/* No.101 INTCXP10RI: CXP10 receive interrupt */
//	.long	IntFunc_dummy	/* No.101 INTCXP12RI: CXP12 receive interrupt */
	.long	IntFunc_dummy	/* No.102 INTCXP10SI: CXP10 status interrupt */
//	.long	IntFunc_dummy	/* No.102 INTCXP12SI: CXP12 status interrupt */
	.long	IntFunc_dummy	/* No.103 INTCXP11TI: CXP11 transfer interrupt */
//	.long	IntFunc_dummy	/* No.103 INTCXP13TI: CXP13 transfer interrupt */
	.long	IntFunc_dummy	/* No.104 INTCXP11RI: CXP11 receive interrupt */
//	.long	IntFunc_dummy	/* No.104 INTCXP13RI: CXP13 receive interrupt */
	.long	IntFunc_dummy	/* No.105 INTCXP11SI: CXP11 status interrupt */
//	.long	IntFunc_dummy	/* No.105 INTCXP13SI: CXP13 status interrupt */
	.long	IntFunc_dummy	/* No.106 INTRI3C0RESP: RI3C0 Normal Response queue full */
	.long	IntFunc_dummy	/* No.107 INTRI3C0CMD: RI3C0 Normal Command queue empty */
	.long	IntFunc_dummy	/* No.108 INTRI3C0IBI: RI3C0 Normal IBI Status queue full */
	.long	IntFunc_dummy	/* No.109 INTRI3C0RX0: RI3C0 Normal Rx Data buffer 0 full */
	.long	IntFunc_dummy	/* No.110 INTRI3C0TX0: RI3C0 Normal Tx Data buffer 0 empty */
	.long	IntFunc_dummy	/* No.111 INTRI3C0RCV: RI3C0 Normal Receive Status queue full */
	.long	IntFunc_dummy	/* No.112 INTRI3C0HRESP: RI3C0 High Priority Response queue full */
	.long	IntFunc_dummy	/* No.113 INTRI3C0HCMD: RI3C0 High Priority Command queue empty */
	.long	IntFunc_dummy	/* No.114 INTRI3C0HRX: RI3C0 High Priority Rx Data buffer full */
	.long	IntFunc_dummy	/* No.115 INTRI3C0HTX: RI3C0 High Priority Tx Data buffer empty */
	.long	IntFunc_dummy	/* No.116 INTRI3C0TEND: RI3C0 Transmit end  */
	.long	IntFunc_dummy	/* No.117 INTRI3C0EEI: RI3C0 Communication error / event  */
	.long	IntFunc_dummy	/* No.118 INTRIIC0EE: RIIC0 communication error/event generation interrupt */
	.long	IntFunc_dummy	/* No.119 INTRIIC0RI: RIIC0 receive end interrupt */
	.long	IntFunc_dummy	/* No.120 INTRIIC0TI: RIIC0 transmit data empty interrupt */
	.long	IntFunc_dummy	/* No.121 INTRIIC0TEI: RIIC0 transmit end interrupt */
	.long	IntFunc_dummy	/* No.122 INTRIIC1EE: RIIC1 communication error/event generation interrupt */
	.long	IntFunc_dummy	/* No.123 INTRIIC1RI: RIIC1 receive end interrupt */
	.long	IntFunc_dummy	/* No.124 INTRIIC1TI: RIIC1 transmit data empty interrupt */
	.long	IntFunc_dummy	/* No.125 INTRIIC1TEI: RIIC1 transmit end interrupt */
	.long	IntFunc_dummy	/* No.126 INTCWEND: LPSB0 Port polling end interrupt */
	.long	IntFunc_dummy	/* No.127 INTDPE: LPSB0 Digital port error interrupt */
	.long	IntFunc_dummy	/* No.128 INTLPSTM0: LPSB0 Interval Timer 0 Interrupt */
//	.long	IntFunc_dummy	/* No.128 INTLPSTM2: LPSB0 Interval Timer 2 Interrupt */
//	.long	IntFunc_dummy	/* No.128 INTLPSTM4: LPSB0 Interval Timer 4 Interrupt */
	.long	IntFunc_dummy	/* No.129 INTLPSTM1: LPSB0 Interval Timer 1 Interrupt */
//	.long	IntFunc_dummy	/* No.129 INTLPSTM3: LPSB0 Interval Timer 3 Interrupt */
	.long	IntFunc_dummy	/* No.130 INTRSIPMFATALERR: RSIP-M30A fatal error notification */
	.long	IntFunc_dummy	/* No.131 INTWDTBATIT: WDTBA interrupt */
	.long	IntFunc_dummy	/* No.132 INTDCUTDI: Dedicated interrupt for on-chip debug function */
	.long	IntFunc_dummy	/* No.133 INTSSIF0TX: Transmission data empty for channel 0 */
	.long	IntFunc_dummy	/* No.134 INTSSIF0RX: Reception data full for channel 0 */
	.long	IntFunc_dummy	/* No.135 INTSSIF0: Multi-purpose interrupt for channel 0 */
	.long	IntFunc_dummy	/* No.136 INTSSIF1TX: Transmission data empty for channel 1 */
	.long	IntFunc_dummy	/* No.137 INTSSIF1RX: Reception data full for channel 1 */
	.long	IntFunc_dummy	/* No.138 INTSSIF1: Multi-purpose interrupt for channel 1 */
	.long	IntFunc_dummy	/* No.139 INTPDMAC1CH0: pDMAC1 channel 0 transfer completion */
//	.long	IntFunc_dummy	/* No.139 INTPDMAC1CH2: pDMAC1 channel 2 transfer completion */
//	.long	IntFunc_dummy	/* No.139 INTPDMAC1CH4: pDMAC1 channel 4 transfer completion */
//	.long	IntFunc_dummy	/* No.139 INTPDMAC1CH6: pDMAC1 channel 6 transfer completion */
	.long	IntFunc_dummy	/* No.140 INTPDMAC1CH1: pDMAC1 channel 1 transfer completion */
//	.long	IntFunc_dummy	/* No.140 INTPDMAC1CH3: pDMAC1 channel 3 transfer completion */
//	.long	IntFunc_dummy	/* No.140 INTPDMAC1CH5: pDMAC1 channel 5 transfer completion */
//	.long	IntFunc_dummy	/* No.140 INTPDMAC1CH7: pDMAC1 channel 7 transfer completion */
	.long	IntFunc_dummy	/* No.141 INTTAUD2I0: TAUD2 Channel 0 interrupt */
//	.long	IntFunc_dummy	/* No.141 INTTAUD2I2: TAUD2 Channel 2 interrupt */
//	.long	IntFunc_dummy	/* No.141 INTTAUD2I4: TAUD2 Channel 4 interrupt */
//	.long	IntFunc_dummy	/* No.141 INTTAUD2I6: TAUD2 Channel 6 interrupt */
//	.long	IntFunc_dummy	/* No.141 INTTAUD2I8: TAUD2 Channel 8 interrupt */
//	.long	IntFunc_dummy	/* No.141 INTTAUD2I10: TAUD2 Channel 10 interrupt */
//	.long	IntFunc_dummy	/* No.141 INTTAUD2I12: TAUD2 Channel 12 interrupt */
//	.long	IntFunc_dummy	/* No.141 INTTAUD2I14: TAUD2 Channel 14 interrupt */
	.long	IntFunc_dummy	/* No.142 INTTAUD2I1: TAUD2 Channel 1 interrupt */
//	.long	IntFunc_dummy	/* No.142 INTTAUD2I3: TAUD2 Channel 3 interrupt */
//	.long	IntFunc_dummy	/* No.142 INTTAUD2I5: TAUD2 Channel 5 interrupt */
//	.long	IntFunc_dummy	/* No.142 INTTAUD2I7: TAUD2 Channel 7 interrupt */
//	.long	IntFunc_dummy	/* No.142 INTTAUD2I9: TAUD2 Channel 9 interrupt */
//	.long	IntFunc_dummy	/* No.142 INTTAUD2I11: TAUD2 Channel 11 interrupt */
//	.long	IntFunc_dummy	/* No.142 INTTAUD2I13: TAUD2 Channel 13 interrupt */
//	.long	IntFunc_dummy	/* No.142 INTTAUD2I15: TAUD2 Channel 15 interrupt */
	.long	IntFunc_dummy	/* No.143 IRQ7: External interrupt 7 */
	.long	IntFunc_dummy	/* No.144 IRQ9: External interrupt 9 */
	.long	IntFunc_dummy	/* No.145 IRQ10: External interrupt 10 */
	.long	IntFunc_dummy	/* No.146 IRQ11: External interrupt 11 */
	.long	IntFunc_dummy	/* No.147 IRQ12: External interrupt 12 */
	.long	IntFunc_dummy	/* No.148 IRQ13: External interrupt 13 */
	.long	IntFunc_dummy	/* No.149 IRQ14: External interrupt 14 */
	.long	IntFunc_dummy	/* No.150 IRQ15: External interrupt 15 */
	.long	IntFunc_dummy	/* No.151 IRQ17: External interrupt 17 */
	.long	IntFunc_dummy	/* No.152 INTADCK1ERR: ADCK1 A/D error interrupt upper/lower limit error interrupt */
	.long	IntFunc_dummy	/* No.153 INTADCK1I0: ADCK1 Scan group 0 (SG0) end interrupt  */
	.long	IntFunc_dummy	/* No.154 INTADCK1I1: ADCK1 Scan group 1 (SG1) end interrupt */
	.long	IntFunc_dummy	/* No.155 INTADCK1I2: ADCK1 Scan group 2 (SG2) end interrupt */
	.long	IntFunc_dummy	/* No.156 INTADCK1I3: ADCK1 Scan group 3 (SG3) end interrupt */
	.long	IntFunc_dummy	/* No.157 INTADCK1I4: ADCK1 Scan group 4 (SG4) end interrupt */
	.long	IntFunc_dummy	/* No.158 INTADCK1MPX: ADCK1 MPX DMA trigger request */
	.long	IntFunc_dummy	/* No.159 INTADCK1SD: ADCK1 SG-Diag end interrupt */
	.long	IntFunc_dummy	/* No.160 INTRLIN38: RLIN38 interrupt */
//	.long	IntFunc_dummy	/* No.160 INTRLIN39: RLIN39 interrupt */
//	.long	IntFunc_dummy	/* No.160 INTRLIN310: RLIN310 interrupt */
//	.long	IntFunc_dummy	/* No.160 INTRLIN311: RLIN311 interrupt */
//	.long	IntFunc_dummy	/* No.160 INTRLIN312: RLIN312 interrupt */
//	.long	IntFunc_dummy	/* No.160 INTRLIN313: RLIN313 interrupt */
//	.long	IntFunc_dummy	/* No.160 INTRLIN314: RLIN314 interrupt */
//	.long	IntFunc_dummy	/* No.160 INTRLIN315: RLIN315 interrupt */
	.long	IntFunc_dummy	/* No.161 INTRLIN38UR0: RLIN38 transmit interrupt */
//	.long	IntFunc_dummy	/* No.161 INTRLIN39UR0: RLIN39 transmit interrupt */
//	.long	IntFunc_dummy	/* No.161 INTRLIN310UR0: RLIN310 transmit interrupt */
//	.long	IntFunc_dummy	/* No.161 INTRLIN311UR0: RLIN311 transmit interrupt */
//	.long	IntFunc_dummy	/* No.161 INTRLIN312UR0: RLIN312 transmit interrupt */
//	.long	IntFunc_dummy	/* No.161 INTRLIN313UR0: RLIN313 transmit interrupt */
//	.long	IntFunc_dummy	/* No.161 INTRLIN314UR0: RLIN314 transmit interrupt */
//	.long	IntFunc_dummy	/* No.161 INTRLIN315UR0: RLIN315 transmit interrupt */
	.long	IntFunc_dummy	/* No.162 INTRLIN38UR1: RLIN38 receive completion interrupt */
//	.long	IntFunc_dummy	/* No.162 INTRLIN39UR1: RLIN39 receive completion interrupt */
//	.long	IntFunc_dummy	/* No.162 INTRLIN310UR1: RLIN310 receive completion interrupt */
//	.long	IntFunc_dummy	/* No.162 INTRLIN311UR1: RLIN311 receive completion interrupt */
//	.long	IntFunc_dummy	/* No.162 INTRLIN312UR1: RLIN312 receive completion interrupt */
//	.long	IntFunc_dummy	/* No.162 INTRLIN313UR1: RLIN313 receive completion interrupt */
//	.long	IntFunc_dummy	/* No.162 INTRLIN314UR1: RLIN314 receive completion interrupt */
//	.long	IntFunc_dummy	/* No.162 INTRLIN315UR1: RLIN315 receive completion interrupt */
	.long	IntFunc_dummy	/* No.163 INTRLIN38UR2: RLIN38 status interrupt */
//	.long	IntFunc_dummy	/* No.163 INTRLIN39UR2: RLIN39 status interrupt */
//	.long	IntFunc_dummy	/* No.163 INTRLIN310UR2: RLIN310 status interrupt */
//	.long	IntFunc_dummy	/* No.163 INTRLIN311UR2: RLIN311 status interrupt */
//	.long	IntFunc_dummy	/* No.163 INTRLIN312UR2: RLIN312 status interrupt */
//	.long	IntFunc_dummy	/* No.163 INTRLIN313UR2: RLIN313 status interrupt */
//	.long	IntFunc_dummy	/* No.163 INTRLIN314UR2: RLIN314 status interrupt */
//	.long	IntFunc_dummy	/* No.163 INTRLIN315UR2: RLIN315 status interrupt */
	.long	IntFunc_dummy	/* No.164 INTOSTM1TINT: OSTM1 interrupt */
	.long	IntFunc_dummy	/* No.165 INTOSTM2TINT: OSTM2 interrupt */
	.long	IntFunc_INTETNF0DATA	/* No.166 INTETNF0DATA: ETNF0 Data related interrupt */
	.long	IntFunc_dummy	/* No.167 INTETNF0ERR: ETNF0 Data related interrupt */
	.long	IntFunc_dummy	/* No.168 INTETNF0MNG: ETNF0 Management related interrupt */
	.long	IntFunc_dummy	/* No.169 INTETNF0MAC: ETNF0 MAC interrupt */
	.long	IntFunc_dummy	/* No.170 IRQ8: External interrupt 8 */
	.long	IntFunc_dummy	/* No.171 INTPSI50SI: PSI50 status interrupt */
	.long	IntFunc_dummy	/* No.172 INTPSI50RI: PSI50 receive interrupt */
	.long	IntFunc_dummy	/* No.173 INTPSI50TI: PSI50 transfer interrupt */
	.long	IntFunc_dummy	/* No.174 INTPSI51SI: PSI51 status interrupt */
	.long	IntFunc_dummy	/* No.175 INTPSI51RI: PSI51 receive interrupt */
	.long	IntFunc_dummy	/* No.176 INTPSI51TI: PSI51 transfer interrupt */
	.long	IntFunc_dummy	/* No.177 INTPSI5W: Interruption reports the end of all channel enable */
	.long	IntFunc_dummy	/* No.178 INTMMCA0: MMCA interrupt */
	.long	IntFunc_dummy	/* No.179 INTOSTM3TINT: OSTM3 interrupt */
	.long	IntFunc_dummy	/* No.180 INTOSTM4TINT: OSTM4 interrupt */
	.long	IntFunc_dummy	/* No.181 INTXCAN1FUNC: XCAN1 functional relevant */
	.long	IntFunc_dummy	/* No.182 INTXCAN1ERR: XCAN1 functional error relevant */
	.long	IntFunc_dummy	/* No.183 INTXCAN1SAFETY: XCAN1 safety relevant */
	.long	IntFunc_dummy	/* No.184 INTETND00: ETND0 (Endstation) interrupt 0 */
	.long	IntFunc_dummy	/* No.185 INTETND01: ETND0 (Endstation) interrupt 1 */
	.long	IntFunc_dummy	/* No.186 INTETND02: ETND0 (Endstation) interrupt 2 */
	.long	IntFunc_dummy	/* No.187 INTETND03: ETND0 (Endstation) interrupt 3 */
	.long	IntFunc_dummy	/* No.188 INTETND04: ETND0 (Endstation) interrupt 4 */
	.long	IntFunc_dummy	/* No.189 INTETND05: ETND0 (Endstation) interrupt 5 */
	.long	IntFunc_dummy	/* No.190 INTETND06: ETND0 (Endstation) interrupt 6 */
	.long	IntFunc_dummy	/* No.191 INTGPTP: gPTP interrupt */
	.long	IntFunc_dummy	/* No.192 IRQ25: External interrupt 25 */
	.long	IntFunc_dummy	/* No.193 INTRLIN316: RLIN316 interrupt */
//	.long	IntFunc_dummy	/* No.193 INTRLIN317: RLIN317 interrupt */
	.long	IntFunc_dummy	/* No.194 INTRLIN316UR0: RLIN316 transmit interrupt */
//	.long	IntFunc_dummy	/* No.194 INTRLIN317UR0: RLIN317 transmit interrupt */
	.long	IntFunc_dummy	/* No.195 INTRLIN316UR1: RLIN316 receive completion interrupt */
//	.long	IntFunc_dummy	/* No.195 INTRLIN317UR1: RLIN317 receive completion interrupt */
	.long	IntFunc_dummy	/* No.196 INTRLIN316UR2: RLIN316 status interrupt */
//	.long	IntFunc_dummy	/* No.196 INTRLIN317UR2: RLIN317 status interrupt */


IntFunc_dummy:
	B  .

	/* size of __isr_vector = current address(indicated by ".") minus address of __isr_vector  */
	.size	__isr_vector, . - __isr_vector



/* EOF */
