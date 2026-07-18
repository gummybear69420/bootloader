// test 

#define _hacked_function void __attribute((naked, section(".text")))

#define VGA_MEMORY 0xB800

_hacked_function _asm_entry(){
	__asm__ __volatile__(R"(
		.code16

		ljmp $0, $_clear_cs_reg

		_clear_cs_reg: 
		
		movb $0x0E, %ah 
		movb $'h', %al 
		int $0x10

	        call _c_entry
	)");	
}

void _c_entry(){
	volatile int* vga_buffer = (volatile int*)VGA_MEMORY;
	while(1){
		*vga_buffer= (unsigned int)0x0F68;
	}; 
}



