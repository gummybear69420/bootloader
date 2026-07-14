ENTRY(_asm_bootstrap_entrance)

SECTIONS { 
  . = 0x7c00; 
  
  text : {
    *(.text)
    *(.text.*)
  }
  
  . = 0x7c00 + 510
  
  .maigc_word :
  {
    SHORT(0xaa55)
  }


}
