_start:
	la sp, _stack_top
	#jal ra, start
	jal ra, main
	jal x0, _start
