#[allow(dead_code)]
#[allow(unused_imports)]

use std::env; 
use std::path::Path;
use std::process::Command;
use std::fs; 

fn main() {
    let builder_dir = env::var("CARGO_MANIFEST_DIR").unwrap();
    let builder_dir = Path::new(&builder_dir);

    let root_project_dir = builder_dir.parent().unwrap();

    // to string? 
    // println!("{}", root_project_dir.display());
    
    // Call cargo build in other projects here
    // I guess avoid calling direct directories in case this needs to be built on windows?
    // Do I really care? Nope. Fuck windows.
    //let call_cargo = Command::new("cargo"); // does this work? 
    
    find_cargo_project_directorys(&root_project_dir);
}

fn find_cargo_project_directorys(path: &Path){
    // For each item in the directory
    // Check if item is a cargo directory
    // if so exit directory, push it onto the directory list, and continue to next one
    
    for entry in fs::read_dir(path){
        println!("{}", entry.display());
    }
}
