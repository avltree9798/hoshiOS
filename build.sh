aarch64-elf-gcc -c boot.s -o out/boot.o
aarch64-elf-gcc -c lib/stdlib.s -o out/stdlib.o
aarch64-elf-gcc -c lib/handler.s -o out/handlera.o
aarch64-elf-gcc -c mmu.s -o out/mmu.o
aarch64-elf-gcc -std=c99 -ffreestanding -mgeneral-regs-only  -c main.c -o out/main.o
aarch64-elf-gcc -std=c99 -ffreestanding -mgeneral-regs-only  -c lib/uart.c -o out/uart.o
aarch64-elf-gcc -std=c99 -ffreestanding -mgeneral-regs-only  -c lib/stdio.c -o out/stdio.o
aarch64-elf-gcc -std=c99 -ffreestanding -mgeneral-regs-only  -c lib/debug.c -o out/debug.o
aarch64-elf-gcc -std=c99 -ffreestanding -mgeneral-regs-only  -c lib/handler.c  -o out/handler.o
aarch64-elf-gcc -std=c99 -ffreestanding -mgeneral-regs-only  -c lib/memory.c  -o out/memory.o
aarch64-elf-gcc -std=c99 -ffreestanding -mgeneral-regs-only  -c lib/file.c  -o out/file.o
aarch64-elf-gcc -std=c99 -ffreestanding -mgeneral-regs-only  -c lib/crypto.c  -o out/crypto.o
aarch64-elf-gcc -std=c99 -ffreestanding -mgeneral-regs-only  -c lib/process.c  -o out/process.o
aarch64-elf-ld -nostdlib -T link.lds -o out/kernel out/boot.o out/main.o out/stdlib.o out/uart.o out/stdio.o out/debug.o out/handlera.o out/handler.o out/mmu.o out/memory.o out/file.o out/crypto.o out/process.o
aarch64-elf-objcopy -O binary out/kernel out/kernel8.img
dd if=os.img >> out/kernel8.img