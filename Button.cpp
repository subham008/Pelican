#ifndef _VIEW_
    #include "View.cpp"
#endif    

class Button:public View{

   public:
    static const char* BUTTON;

     Button(xml_node<>* node):View(node){
       if(isButton(node)){
          this->node=node;
        }
        else
          std::cout<<"Button()::ERROR -> passed  xml_node<>* is not a Button"<<std::endl;
     }

    

    const char* getValue(const char* attribute){
        if(node==NULL){
            std::cout<<"Button::getValue(const char*)::ERROR -> xml_node<>* is NULL , check is passed xml_node<>* is valid or not"<<std::endl;
            return 0;
        }
        return node->first_attribute(attribute)->value();
    }

     static bool isButton(xml_node<>* node){
         //checking is Valid
         // it will be valid if either text attribute or src attribute
         if(node->first_attribute(ATTRIBUTE_TEXT)==0  && node->first_attribute(ATTRIBUTE_src)==0 )
             return false;
         
         return true;
     }


     static const char* ATTRIBUTE_TEXT;
     static const char* ATTRIBUTE_src;
};

const char* Button::ATTRIBUTE_TEXT="text";
const char*Button::ATTRIBUTE_src="src";
const char* Button::BUTTON="Button";