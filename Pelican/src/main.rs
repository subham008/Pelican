
use std::fs::File;
use std::io::{BufReader, Write};
use spex::common::XmlError;
use spex::parsing::XmlReader;
use spex::xml::XmlDocument;


//mod identity;
//mod HeaderManager;
//mod CssTags;

fn get_child_count(Xml_doc:XmlDocument)->Result<(),XmlError>{
    let bookstore=Xml_doc.unwrap().root().req("bookstore").element()?;
    let child_count=bookstore.elements().count();

    eprintln!("child count {child_count}");

    Ok(())
}
fn main() -> std::io::Result<()>{
    let file = File::open("file.xml")?;

    let xml_doc=XmlReader::parse_auto(file)?;
    get_child_count(xml_doc);

    Ok(())
}
