riscv32-unknown-elf-gcc -nostartfiles $1.S -o $1
riscv32-unknown-elf-objcopy -O binary $1 $1.bin  
riscv32-unknown-elf-objdump -D -b binary -m riscv $1.bin


