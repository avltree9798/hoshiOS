rm -f out/*
aarch64-elf-gcc -c syscall.s -o out/syscall.o
aarch64-elf-gcc -std=c99 -ffreestanding -mgeneral-regs-only  -c stdio.c  -o out/stdio.o
aarch64-elf-gcc-ar rcs out/stdio.a out/stdio.o out/syscall.o