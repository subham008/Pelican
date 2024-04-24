

pub struct CSS{
    values:Vec<String>,
    name:String
}


impl CSS{
    pub fn new( values:Vec<String> , tag_name:String)->Self{
        return CSS{values:values , name:tag_name};
    }

    pub fn add_value(value:String){
        Self.values.append(&mut vec![value]);
    }
}