build:
	./build.sh

run:
	qemu-system-aarch64 -M raspi3b -serial stdio -kernel out/kernel8.img

all:
	make build
	make run