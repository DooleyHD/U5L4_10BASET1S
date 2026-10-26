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
* File Name    : cstart_pe0.s
* Version      : 1.00
* Device(s)    : R-Car/U5L
* Description  : This is startup ruetine.
*******************************************************************************/

	.syntax unified


/*******************************************************************************
* reset_vector section
*******************************************************************************/
	.section .reset_handler, "ax"
	.align	2

	.thumb
	.thumb_func

	.globl	Reset_Handler
Reset_Handler:
	/* initialize general purpose resister */
	/**************************************************************************/
	MOVS  r0, #0x0
 	MOV   r1, r0
	MOV   r2, r0
	MOV   r3, r0
	MOV   r4, r0
	MOV   r5, r0
	MOV   r6, r0
	MOV   r7, r0
	MOV   r8, r0
	MOV   r9, r0
	MOV   r10,r0
	MOV   r11,r0
	MOV   r12,r0


	/* _RESETOUT = High level */
	/**************************************************************************/
#if 1
	.equ	REG_PKCPROT, 0x5C192F40U
	.equ	REG_PWE, 0x5C192F44U
	.equ	REG_PCR27_0, 0x5C1926C0U

	/* Relases protection for PWE register */
	ldr r0, =0xA5A5A501U	/* PKCPROT = 0xA5A5A501 */
	ldr r1, =REG_PKCPROT	/* PKCPROT */
	str r0, [r1]

	ldr r0, =0x00010000U	/* PWEP27 = 1 */
	ldr r1, =REG_PWE    	/* PWE */
	str r0, [r1]

	/* set PCR register
	 *   - bit 28: PODC27_0 = 0 (push pull)
	 *   - bit 12: P27_0    = 1 (high output)
	 *   - bit  4: PM27_0   = 0 (PORT output mode) */
	ldr r0, =0x00001000
	ldr r1, =REG_PCR27_0
	str r0, [r1]

	ldr r0, =0x00000000U	/* PWEP27 = 0 */
	ldr r1, =REG_PWE    	/* PWE */
	str r0, [r1]

	/* Set protection for PWE register */
	ldr r0, =0xA5A5A500U	/* PKCPROT = 0xA5A5A500 */
	ldr r1, =REG_PKCPROT	/* PKCPROT */
	str r0, [r1]
#endif

	/* Enable C-Cache */
	/**************************************************************************/
#if 0
	.equ	REG_CCACTL, 0x5FD21000U	/* C-Cache Control Register */
	.equ	REG_CCAFCT, 0x5FD21004U	/* C-Cache Flush Control Register */

	/* Cache enable and Flush Cache */
	ldr r0, =0x00000101	/* bit 0 ENC = 1, bit 8 FC = 1 */
	ldr r1, =REG_CCACTL
	str r0, [r1]

	/* Wait until Flush is completed */
.loop_fluch_comp:
	ldr	r1, =REG_CCAFCT 	/* RESF */
	ldr	r2, [r1]
	cmp	r2, #0
	bne	.loop_fluch_comp
#endif

	/*  Copy single section scheme.
	 **************************************************************************/
	/*  The ranges of copy from/to are specified by following symbols
	 *    __etext: LMA of start of the section to copy from. Usually end of text
	 *    __data_start__: VMA of start of the section to copy to
	 *    __data_end__: VMA of end of the section to copy to
	 *
	 *  All addresses must be aligned to 4 bytes boundary.
	 */
	ldr	r1, =__etext
	ldr	r2, =__data_start__
	ldr	r3, =__data_end__

.L_loop1:
	cmp	r2, r3
	ittt	lt
	ldrlt	r0, [r1], #4
	strlt	r0, [r2], #4
	blt	.L_loop1


	/*  Clear single BSS section scheme.
	 **************************************************************************/
	/*  The BSS section is specified by following symbols
	 *    __bss_start__: start of the BSS section.
	 *    __bss_end__: end of the BSS section.
	 *
	 *  Both addresses must be aligned to 4 bytes boundary.
	 */
	ldr	r1, =__bss_start__
	ldr	r2, =__bss_end__

	movs	r0, 0
.L_loop3:
	cmp	r1, r2
	itt	lt
	strlt	r0, [r1], #4
	blt	.L_loop3

	ldr	r1, =__GRAM_bss_start__
	ldr	r2, =__GRAM_bss_end__

	movs	r0, 0
.L_loop3g:
	cmp	r1, r2
	itt	lt
	strlt	r0, [r1], #4
	blt	.L_loop3g

	/*  RESF check
	 **************************************************************************/
	ldr  r1, =0x5C088500 	/* RESF */
	ldr  r0, [r1]
	movs r2, 0x00008000		/* DeepSTOP flag */
	and  r0, r2
	cbnz r0, .skip_RRAM_bss_clear


	/*  Clear single BSS section on RRAM.
	 **************************************************************************/
	/*  The BSS section on RRAM is specified by following symbols
	 *    __RRAM_bss_start__: start of the BSS section on RRAM.
	 *    __RRAM_bss_end__: end of the BSS section on RRAM.
	 *
	 *  Both addresses must be aligned to 4 bytes boundary.
	 */
	ldr	r1, =__RRAM_bss_start__
	ldr	r2, =__RRAM_bss_end__

	movs	r0, 0
.L_loop5:
	cmp	r1, r2
	itt	lt
	strlt	r0, [r1], #4
	blt	.L_loop5
.skip_RRAM_bss_clear:


	/*  Clear stack section */
	/**************************************************************************/
/*	ldr	r1, =__StackLimit */
	ldr	r1, =0x200E7000	/* [debug]*/
	ldr	r2, =__StackTop

	movs	r0, 0
.L_loop4:
	cmp	r1, r2
	itt	lt
	strlt	r0, [r1], #4
	blt	.L_loop4

	/* Set offset address of vector table */
	/**************************************************************************/
	ldr r1, =0xE000ED08 	/* VTOR */
	ldr r0, =__isr_vector
	str r0, [r1]

	/* blanch to main function */
	/**************************************************************************/
	BL    main
	NOP
	B  .

	/* define this section size */
	/**************************************************************************/
	.pool	/* data section in this section */

	/* size of Reset_Handler = current address(indicated by ".") minus address of Reset_Handler  */
	.size	Reset_Handler, . - Reset_Handler


/*******************************************************************************
* stack section
*******************************************************************************/
	.section .stack
	.align	4

	/* set stack size */
	.equ	Stack_Size, 0x1000

	/* set stack limit */
	.globl	__StackLimit
__StackLimit:
	.space	Stack_Size
	.size	__StackLimit, . - __StackLimit

	/* assign stack area */
	.globl	__StackTop
__StackTop:
	.size	__StackTop, . - __StackTop


/* EOF */
