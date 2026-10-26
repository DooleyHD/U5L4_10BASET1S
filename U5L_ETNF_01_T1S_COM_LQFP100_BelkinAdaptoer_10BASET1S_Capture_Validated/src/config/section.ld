/* Linker script to configure memory regions. 
 * Need modifying for a specific board. 
 *   FLASH_A.ORIGIN: starting address of flash
 *   FLASH_A.LENGTH: length of flash
 *   LRAM.ORIGIN: starting address of LRAM bank 0
 *   LRAM.LENGTH: length of LRAM bank 0
 */
 
 
MEMORY
{
	FLASH_A   (rx)  : ORIGIN = 0x00000000, LENGTH = 0x00400000	/*   4 MByte Flash ROM Bank A */
	FLASH_B   (rx)  : ORIGIN = 0x00400000, LENGTH = 0x00400000	/*   4 MByte Flash ROM Bank B */
	DFLASH_0  (r)   : ORIGIN = 0x400C0000, LENGTH = 0x400CFFFF	/* 832 KByte Data Flash */
	LRAM      (rwx) : ORIGIN = 0x200E0000, LENGTH = 0x00008000	/*  32 KByte CPU RAM */
	RRAM      (rwx) : ORIGIN = 0x2C000000, LENGTH = 0x00001000	/*   4 KByte Retention RAM */
	GRAM      (rwx) : ORIGIN = 0x28000000, LENGTH = 0x00058000	 /* 352 KByte Retention RAM */
	OPBT_Area (r)   : ORIGIN = 0x401213A0, LENGTH = 0x000000E4	/* OPBT0 to OPBT55 (0x03A0 to 0x047F) */
  
}

/* Linker script to place sections and symbol values. Should be used together
 * with other linker script that defines memory regions FLASH_A and LRAM.
 * It references following symbols, which must be defined in code:
 *   Reset_Handler : Entry of reset handler
 * 
 * It defines following symbols, which code can use without definition:
 *   __exidx_start
 *   __exidx_end
 *   __copy_table_start__
 *   __copy_table_end__
 *   __zero_table_start__
 *   __zero_table_end__
 *   __etext
 *   __data_start__
 *   __preinit_array_start
 *   __preinit_array_end
 *   __init_array_start
 *   __init_array_end
 *   __fini_array_start
 *   __fini_array_end
 *   __data_end__
 *   __bss_start__
 *   __bss_end__
 *   __end__
 *   end
 *   __HeapLimit
 *   __StackLimit
 *   __StackTop
 *   __stack
 */
ENTRY(Reset_Handler)

SECTIONS
{

	.text_CRUN :
	{
		KEEP(*(.isr_vector_CRUN))
		KEEP(*(.reset_handler_CRUN))
		*(.text_CRUN*)
	
	} > FLASH_B

	.text :
	{
		KEEP(*(.isr_vector))
		KEEP(*(.reset_handler)) /* add */
		*(.text*)

		KEEP(*(.init))
		KEEP(*(.fini))

		*(.rodata*)

		KEEP(*(.eh_frame*))
	} > FLASH_A
	

	.ARM.extab : 
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	} > FLASH_A

	__exidx_start = .;
	.ARM.exidx :
	{
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
	} > FLASH_A
	__exidx_end = .;


	/* Location counter can end up 2byte aligned with narrow Thumb code but
	   __etext is assumed by startup code to be the LMA of a section in LRAM
	   which must be 4byte aligned */
	__etext = ALIGN (4);

	.data : AT (__etext)
	{
		__data_start__ = .;
		*(vtable)
		*(.data*)

		. = ALIGN(4);
		/* preinit data */
		PROVIDE_HIDDEN (__preinit_array_start = .);
		KEEP(*(.preinit_array))
		PROVIDE_HIDDEN (__preinit_array_end = .);

		. = ALIGN(4);
		/* init data */
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
		PROVIDE_HIDDEN (__init_array_end = .);


		. = ALIGN(4);
		/* finit data */
		PROVIDE_HIDDEN (__fini_array_start = .);
		KEEP(*(SORT(.fini_array.*)))
		KEEP(*(.fini_array))
		PROVIDE_HIDDEN (__fini_array_end = .);

		KEEP(*(.jcr*))
		. = ALIGN(4);
		/* All data end */
		__data_end__ = .;

	} > LRAM

	.bss :
	{
		. = ALIGN(4);
		__bss_start__ = .;
		*(.bss*)
		*(COMMON)
		. = ALIGN(4);
		__bss_end__ = .;
	} > LRAM
	
	.RRAM_bss :
	{
		. = ALIGN(4);
		__RRAM_bss_start__ = .;
		*(.RRAM_bss*)
		. = ALIGN(4);
		__RRAM_bss_end__ = .;
	} > RRAM
	
	.GRAM_bss :
	{
		. = ALIGN(4);
		__GRAM_bss_start__ = .;
		*(.GRAM_bss*)
		. = ALIGN(4);
		__GRAM_bss_end__ = .;
	} > GRAM
	
	.DFLASH0_const :
	{
		. = ALIGN(4);
		__DFLASH0_const_start__ = .;
		*(.DFLASH0_const*)
		. = ALIGN(4);
		__DFLASH0_const_end__ = .;
	} > DFLASH_0
	
	
	.heap (COPY):
	{
		__end__ = .;
		PROVIDE(end = .);
		*(.heap*)
		__HeapLimit = .;
	} > LRAM

	/* .stack section doesn't contains any symbols. It is only
	 * used for linker to calculate size of stack sections, and assign
	 * values to stack symbols later */
	.stack (COPY):
	{
		*(.__StackTop*)
	} > LRAM

	/* Set stack top to end of LRAM, and stack limit move down by
	 * size of stack_dummy section */
	__StackTop = ORIGIN(LRAM) + LENGTH(LRAM);
	__StackLimit = __StackTop - SIZEOF(.stack);
	PROVIDE(__stack = __StackTop);
	
	/* Check if data + heap + stack exceeds LRAM limit */
	ASSERT(__StackLimit >= __HeapLimit, "region LRAM overflowed with stack")
	
	
	/* OPBT */
	.OPBT0_top :
	{
		KEEP(*(.OPBT0_top*))
	} > OPBT_Area
}

