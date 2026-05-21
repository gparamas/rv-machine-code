li a0, 0xF123FABC
sb a0, 0(x0)
srai a0, a0, 8
sb a0, 1(x0)
srai a0, a0, 8
sb a0, 2(x0)
srai a0, a0, 8
sb a0, 3(x0)
lb a1, 0(x0)
lb a2, 1(x0)
lb a3, 2(x0)
lb a4, 3(x0)
lh a5, 0(x0)
lh a6, 2(x0)
lw a7, 0(x0)
li a0, 0x12345678
sh a0, 0(x0)
srai a0, a0, 16
sh a0, 2(x0)
li a0, 0xBAD1BAD1
sw a0, 0(x0)


