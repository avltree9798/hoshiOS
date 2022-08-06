aarch64-elf-gcc -c start.s -o bin/start.o
aarch64-elf-gcc -std=c99 -ffreestanding -mgeneral-regs-only  -c main.c -o bin/main.o
aarch64-elf-ld -nostdlib -T link.lds -o bin/init bin/start.o bin/main.o ../usr/lib/out/stdio.a
aarch64-elf-objcopy -O binary bin/init bin/init.ko