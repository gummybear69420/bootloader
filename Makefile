CC = gcc
LD = ld

# TODO: Seperate these into the respective CFLAGS/LDFLAGS variables, some of these "linker" features are no longer supported by LD but somehow supported by GCC because GCC dev's are bumass fucking retards
# Some of these options aren't even in the up-to-date GCC 16.1.1 documentation, god some people should just fucking kill themself instead of writing documentation
CFLAGS = -m16 -ffreestanding -nostartfiles -nodefaultlibs -no-pie -fno-pic -fno-asynchronous-unwind-tables -mtune=i386 -mno-red-zone -c -Wa,"./stage_one/src/code16gcc.h"


#CFLAGS = -m16 -ffreestanding -mno-red-zone -c
#LDFLAGS = -Z nodefaultlib  -nodefaultlibs -no-pie -m elf_i386

all: main

main: strip
	echo "Building, linking and stripping boot.c..."
	qemu-system-x86_64 -drive format=raw,file=boot.bin  

debug: strip
	qemu-system-x86_64 -drive format=raw,file=boot.bin -s -S 

strip: link
	objcopy -O binary boot.elf boot.bin

link: compile
	$(LD) -T bl_link.ld -m elf_i386 boot.o -o boot.elf

compile: 
	$(CC) $(CFLAGS) -o boot.o stage_one/src/boot.c 
