_start:
	la sp, _stack_top
	#jal ra, start
	jal x0, main
	#jal x0, _start

