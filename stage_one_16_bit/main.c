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
		 * clears the code segment register, sometimes full of garbage
		 * */
		ljmp $0, $_clear_cs_reg

		_clear_cs_reg: 
		
		/*
		 * Clearing all the registers 
		 * */
		xor %ax, %ax
		mov %
			
		/* Sanity check */	
		movb $0x0E, %ah 
		movb $'h', %al 
		int $0x10

	        call _c_entry
	)");	
}

void _c_entry(){
	while(1); 
}



