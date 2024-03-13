use std::cell::Cell;

pub struct IdentityManager{
    user_obtained_ids:Vec<i64>,
    max_id:Cell<i64>,
    min_id:i64,
}

impl IdentityManager{
    pub fn new(obtained: Vec<i64> )->IdentityManager{
        let mut max=0;
        let mut min=0;

        //findig max
        for num in obtained.iter(){
              if *num>max{
                 max=*num;
              }
        }

        //findig max
        for num in obtained.iter(){
            if *num>min{
                min=*num;
            }
        }

        IdentityManager{user_obtained_ids:obtained  , max_id:Cell::new(max) , min_id:min }
    }



   pub  fn getNewID(&self) -> i64{
        let max_id=&self.max_id;
        let mut newid=max_id.get()+10;
        let mut isvalid=false;


        //cheking if my newid is taken by user or not
        while  isvalid {
            let mut count=0;
            for num in self.user_obtained_ids.iter() {
                if num == &newid{
                    break;
                }
                count=count+1;
            }

            if count == self.user_obtained_ids.len(){
                isvalid=true;
            }
            else {
                newid +=10;
            }
        }//enn of while loop

       self.max_id.set(newid);
       return newid;
    }

}





