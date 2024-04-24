

const TITLE_OPEN_TAG:&str="<title>";
const TITLE_CLOSE_TAG:&str="</title>";
pub fn get_header(title:String )->String{
        let title_tag=format!("{}{}{}" , TITLE_OPEN_TAG , title , TITLE_CLOSE_TAG);
    return title_tag;
}