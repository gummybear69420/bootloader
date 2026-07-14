#![no_std]
#![no_main]

use core::arch::global_asm; 

global_asm!(r"


"); 

fn _stage_one() -> ! {
    loop {

    }
}

use core::panic::PanicInfo; 

#[panic_handler]
fn panic_handler(_info: &PanicInfo) -> ! {
    loop {

    }
}
