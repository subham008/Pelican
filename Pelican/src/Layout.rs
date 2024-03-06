use std::fs::File;
use std::io::BufReader;
use xml::reader::{EventReader , XmlEvent};


fn getEventReader(filename :String)->(EventReader<BufReader<File>> , std::io::Result<()>){
    let file = File::open(filename)?;
    let bfile = BufReader::new(file);
    return (EventReader::new(bfile)  , Ok(())  );
}


pub struct Layout{
    reader:EventReader<BufReader<File>>,
    filename:String,
}


impl Layout{
pub fn open(filename:String)->Layout{
    let filenameclone=filename.clone();
    let (rea , res) = getEventReader(filename);
    Layout{ reader: rea ,  filename:filenameclone }
}


pub fn printNodeTree(&self){
    let mut depth = 0;
    for e in self.reader {
        match e {
            Ok(XmlEvent::StartElement { name, .. }) => {
                println!("{:spaces$}+{name}", "", spaces = depth * 2);
                depth += 1;
            }
            Ok(XmlEvent::EndElement { name }) => {
                depth -= 1;
                println!("{:spaces$}-{name}", "", spaces = depth * 2);
            }
            Err(e) => {
                eprintln!("Error: {e}");
                break;
            }
            // There's more: https://docs.rs/xml-rs/latest/xml/reader/enum.XmlEvent.html
            _ => {}
        }
    }
}
}



fn useless(){
    let layout=Layout::open(String::from("file.xml"));
}