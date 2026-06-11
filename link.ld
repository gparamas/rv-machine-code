MEMORY {
	instr (r) : ORIGIN = 0x0, LENGTH = 32k
	ram (rwx) : ORIGIN = 0x0, LENGTH = 128k
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
	_global_pointer = . + 0x800;
	.data : {
		*(.data*)
		*(.sdata*)
	} > ram
	_bss_start = .;
	.bss : {
		*(.bss*)
		*(COMMON)
	} > ram
	_end = .;
	_stack_top = LENGTH(ram);
}
		






