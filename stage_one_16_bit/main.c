/*
 * A naked function has no function prologe and simply acts as an assembly label. This is a little hack to re-create the global_asm!() macro from rust. 
 * */
#define _hacked_function void __attribute((naked, section(".text")))

/*
 * Beggining of the bootstrap assembly. 
 * */
_hacked_function _asm_entry(){
	__asm__ __volatile__(R"(
		.code16

		/*
		 * The only way to set the CS register is to perform a long jump. Qemu automatically ensures that the code segment is 0, however this is not garunteed on hardware.
		 * 
		 * As far as I know, the reason this is done is to ensure that there will not be undefined behaviour if the segment register is set to 0x7c00 and the instruction pointer is set to 0. The
		 * jump to the memory address 0:_clear_cs_reg ensures that cs = 0 and the instruction pointer is pointing to the correct memory address. 
		 *
		 * *Needs fact checking. 
		 * */
		ljmp $0, $_clear_cs_reg

		_clear_cs_reg: 
		
		/*
		 * Clearing all of the segment registers. Simplifies memory addressing with segment:offset scheme if the segment register is set to 0. Xoring AX with itself sets the value of 
		 * the register to 0. 
		 * */
		xor %ax, %ax
		mov %ax, %ds
		mov %ax, %es
		mov %ax, %ss
		mov %ax, %fs
		mov %ax, %gs

		/*
		 * TODO: enable A20. 
		 * Qemu automatically enables the A20 line, so I wont bother with that headace right now. 
		 * */

		/* Sanity check */	
		movb $0x0E, %ah 
		movb $'h', %al 
		int $0x10

		/*
		 * Disable interupts
		 * */
		cli
			
		

	        call _c_entry
	)");	
}

typedef struct __attribute__((packed)) {
	
} global_descriptor_table_r;  

void _c_entry(){
	while(1); 
}



