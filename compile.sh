riscv32-unknown-elf-gcc -O3 -T link.ld -nostartfiles start.S uart.c qspi.c src/$1.c -o elf/$1
riscv32-unknown-elf-objcopy -O binary elf/$1 bin/$1.bin  
printf '\xff\xff\xff\xff' >> bin/$1.bin
riscv32-unknown-elf-objdump -D -b binary -m riscv bin/$1.bin


