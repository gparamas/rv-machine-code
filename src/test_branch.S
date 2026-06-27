li a0, 10
li a1, 20
li a3, 10
bne a0, a1, nq
li a4, 2
nq:
	li a4, 1
beq a0, a3, eq
li a5, 2
eq:
	li a5, 1
bge a1, a0, ge
li a6, 2
ge:
	li a6, 1
blt a3, a1, lt
li a7, 2
lt:
	li a7, 1


