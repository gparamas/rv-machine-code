MEMORY {
	instr (r) : ORIGIN = 0, LENGTH = 32k
	ram (rwx) : ORIGIN = 0x8000, LENGTH = 128k
	mmio (rwx) : ORIGIN = 0x34000, LENGTH = 1k
}

SECTIONS 
{
	. = 0x0;
	.text : {
		/*start.o(.text)*/
		*(.text*)
		*(.rodata*)
	} > instr
	.data : {
		*(.data*)
	} /*> ram*/ > instr
	_bss_start = .;
	.bss : {
		*(.bss*)
		*(COMMON)
	} /*> ram*/ > instr
	_end = .;
	_stack_top = ORIGIN(ram) + LENGTH(ram);
}
		






