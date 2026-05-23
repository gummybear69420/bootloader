/*
  HACK: This creates a C function without any function prologe and ensures that the function is set within the correct section of the code,
  turning it equivilently into an assembly label. 

  naked: removes function prologe
  section: tells the linker where to put the function code 
 */
#define HACKED_FUNCTION __attribute__((naked, optimize("O0"), section(".text")))

/*
  GCC please stop changing my code behind my back :(
 */
#define v_asm __asm__ __volatile__ 

/*
  EXPLANATION: Because the segment:offset memory scheme is relative and has some logical problems that make it harder to work with; ie, there can be multiple pairs of segments:offsets that
  refer to the same memory address; I want to 0 all of the segment registers so that the memory addressing is absolute.

  Ensuring that all of the segment registers are equal to 0 does reduce accessable memory to about 64kb, but this will not be a problem for the bootstrap. 

  The following function is set at memory address 0x7c00 and is the first function ran by the CPU on boot. The only way (that I know of) to ensure that the CS register has the value of 0
  (which holds the segment part of the segment:offset scheme for jumps) is to long jump to a label. 
 */
HACKED_FUNCTION void _global_asm()
{
  v_asm(R"(

	ljmp $0, $_asm_start

	_asm_start:
	
	xor %ax, %ax
	mov %ax, %ds
        mov %ax, %ss
        mov %ax, %es
        mov %ax, %fs
        mov %ax, %gs

  )");
}


 
