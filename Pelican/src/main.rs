mod Identity;

use std::fmt::Display;
use std::fs::File;
use std::io::{BufRead, BufReader, Read, Write};
use std::path::Path;

mod identity;

fn createFile(name:String , data:String) -> File{
    let path = Path::new(name.as_str());
    let display = path.display();

    // Open the file in write mode (creates a new file if it doesn't exist)
    let mut file = match File::create(&path) {
        Err(why) => panic!("Couldn't create {}: {}", display, why),
        Ok(file) => file,
    };


    match file.write_all(data.as_bytes()) {
        Err(why) => panic!("Couldn't write to {}: ", why),
        Ok(_) => println!("Successfully wrote data to "),
    }
   return file;
}


fn main()  -> std::io::Result<()>{

    let obtained:Vec<i64>=vec![78 , 90, 34];

    let manager =identity::IdentityManager::new( obtained );


    println!("new id {}" , manager.getNewID());
    println!("new id {}" , manager.getNewID());
    println!("new id {}" , manager.getNewID());
    println!("new id {}" , manager.getNewID());
    println!("new id {}" , manager.getNewID());
    println!("new id {}" , manager.getNewID());
    println!("new id {}" , manager.getNewID());
    println!("new id {}" , manager.getNewID());

    Ok(())
}
