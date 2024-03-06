 mod Layout;

fn main()  {

    let layout=Layout::open(String::from("file.xml"));
    match layout {
        Ok(layout) => {
            layout.printNodeTree();
        }
        Err(e) => {
            eprintln!("Error opening layout: {}", e);
        }
    }
}
