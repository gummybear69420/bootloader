ENTRY(0x7c00)

SECTIONS {
	. = 0x7c00; 

	.text : {
		*(.text)
		*(.text.*)
	}

	.data : {
		*(.data)
		*(.data.*)
	}

	.rodata : {
		*(.rodata)
		*(.rodata.*) 
	}

	. = 0x7c00 + 510; 

	.boot_magic : {
		SHORT(0xaa55)
	}

	/DISCARD/ : {
		*(.note)
		*(.note.*)
		*(.gnu)
		*(.gnu.*)
		*(.comment)
		*(.comment.*)
		*(.interp)
		*(.interp.*) 
	}
}


