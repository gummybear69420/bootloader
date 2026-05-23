ENTRY(_global_asm)

SECTIONS
{
	. = 0x7c00;

	.text :
	{
	      *(.text*)
	}

	. = 0x7c00 + 510;

	.magic_word : {
	     SHORT(0xaa55) 
	}

	/DISCARD/ : {
	    *(.eh_frame*)
	    *(.note*)
	    *(.comment*)
	}
}
