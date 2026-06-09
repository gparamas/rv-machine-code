riscv32-unknown-elf-gcc -O3 -T link.ld -nostartfiles start.S uart.c $1.c -o $1
riscv32-unknown-elf-objcopy -O binary $1 $1.bin  
printf '\xff\xff\xff\xff' >> main.bin
riscv32-unknown-elf-objdump -D -b binary -m riscv $1.bin


