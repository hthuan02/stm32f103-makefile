ENTRY(Reset_Handler)

MEMORY
{
	FLASH(rx):ORIGIN =0x08000000,LENGTH =512K
	SRAM(rwx):ORIGIN =0x20000000,LENGTH =96K
}

__max_heap_size = 0x400;	/* A symbol declaration */
__max_stack_size = 0x200;

SECTIONS
{
	.text :
	{	/* '.' = VMA = 0x08000000 */
		*(.isr_vector)
		*(.text)
		*(.rodata)
		. = ALIGN(4);
		_etext = .;		/* store the updated location counter value into a symbol '_etext' */	
	}> FLASH
	
	.data :
	{
		_sdata = .;
		*(.data)
		. = ALIGN(4);
		_edata = .;
	}> SRAM AT> FLASH
	
	.bss :
	{
		_sbss = .;
		*(.bss)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;
	}> SRAM
}
