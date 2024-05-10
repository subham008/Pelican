#include "rapidxml/rapidxml-1.13/rapidxml.hpp"
#include<iostream>

#ifndef _ERROR_
 #include "Error.cpp"
#endif 

#include <list>
#include<cstring>
#include<string>
#include <unordered_map>


using namespace rapidxml;
using namespace std;




const char* TITLE_ELEMENT="title";
const char* ATTRIBUTE_LAYOUT_HEIGHT="layout_height";
const char* ATTRIBUTE_LAYOUT_WIDTH="layout_width";
const char* ATTRIBUTE_ORIENTATION="orientation";
const char* LINEAR_LAYOUT="LinearLayout";
const char* ATTRIBUTE_ID="id";


class Style{
   private:
     unordered_map<string , string>    attributes;
   public:

   void setAttribute(string name , string value) {
       attributes[name]=value;
   }
   
   string getAttrValue(string name){
       return attributes[name];
   }

   string getHardStyle(){
          char quote='"';
          string st="style="+quote;
         for(auto it:attributes){
             st=st+it.first+":"+it.second+";  "; 
         }

         st=st+quote;
         return st;
   }

   int getAttrsize(){
    return attributes.size();
   }

};


int fillAttributesToStyle(Style* style , xml_node<>* node){
     xml_attribute<>* attr=node->first_attribute();
     while(attr!=0){
        style->setAttribute(attr->name() , attr->value());
        attr=attr->next_attribute();
     }

}

class View{

    private:
    Style style; 
    public:
    xml_node<>* node=NULL;
    View(xml_node<>* node){
        if(isView(node)){
          this->node=node;
        }
        else
          std::cout<<"View()::"<<INVALID_VIEW<<std::endl;

         
       fillAttributesToStyle(&style , node);

    }


    const char* getValue(const char* attribute){
        if(node==NULL){
            std::cout<<"View::getValue(const char*)::ERROR -> xml_node<>* is NULL , check is passed xml_node<>* is valid or not"<<std::endl;
            return 0;
        }
        return node->first_attribute(attribute)->value();
    }


 virtual   const char* getHTML(){
         //here it will return html of the view
         string node_name=this->node->name();
         string html_start="<"+node_name+" "+style.getHardStyle()+" "+">"+style.getAttrsize("text")+"</"+node_name+">"
         return html_start;
    }


  static bool isView(xml_node<>* node){
         //checking is Valid
         // it has layout_width and layout_height attributes
         if(node->first_attribute(ATTRIBUTE_LAYOUT_WIDTH)==0)
             return false;

         if(node->first_attribute(ATTRIBUTE_LAYOUT_WIDTH)==0)
             return false;     
         
         return true;
    }


    bool isValid(){
        if(node==NULL)
          return false;
        else
          return true;  
    }



};











void parseChilds(xml_node<>* node, list<View*> list);



class LinearLayout:public View{

   private:
    std::list<View*> child_list;
   public:

    LinearLayout(xml_node<>* node) : View(node){
        if(node==0)
           std::cout<<"LinearLayout():passed xml is null";
        if(isLinearLayout(node)){
          this->node=node;
          parseChilds(node , child_list);
        }
        else
          std::cout<<"LinearLayout()::ERROR -> passed  xml_node<>* is not a LinearLayout"<<std::endl;
    }




    const char* getValue(const char* attribute){
        if(node==NULL){
            std::cout<<"LinearLayout::getValue(const char*)::ERROR -> xml_node<>* is NULL , check is passed xml_node<>* is valid or not"<<std::endl;
            return 0;
        }
        return node->first_attribute(attribute)->value();
    }


    string getHTML(){
        //here it will return html of the view
         string node_name=this->node->name();
         string html_start="<div"+style.getHardStyle()+" "+">"+style.getAttrsize("text")+"</div>"
         return html_start;
    }
   
   //for adding childs
    void addChild(View* v){
        if(v->isValid())
            child_list.push_back(v);
    }

    std::list<View*> getChild(){
       return this->child_list;
    }

    
    
   static bool isLinearLayout(xml_node<>* node){
          //checking is Valid
         // it will be valid if has attribute orientation
         if(node->first_attribute(ATTRIBUTE_ORIENTATION)==0)
             return false;
         
         return true;
   }

   
};    

class ChildParser{
  
   public:
      
      static int  parse(xml_node<>* root, std::list<View*> list){
          //parsing elements
          int count=0;
          xml_node<>* child=root->first_node();

          if(child == 0) 
              return count;
          
          while (child!=0)
          { 
            if(strcmp(child->name() , LINEAR_LAYOUT)==0){
                  list.push_back(new LinearLayout(child));
            }
            else       
                  list.push_back(new View(child));

            count++;
            child=child->next_sibling();
          }
              
          return count; 
      }
};



void parseChilds(xml_node<>* node, list<View*> list){
        int c= ChildParser::parse(node , list)  ;
        std::cout<<"LinearLayout : child count:"<<c<<std::endl;
    }









class SourceParser
{

  private:
   xml_node<>* node; 
   View* parent_layout;
   
   const char* title="TITLE";


   //returns 1 on success or 0 on error
   int parseComponents(){
     //considering node* as the root node
      //getting title  node
      
      xml_node<>* title_node=node->first_node(TITLE_ELEMENT);  
      if(title_node==0){
        std::cout<<"parser error:"<<TITLE_ELEMENT_NOT_FOUND;
        return 0;
      }else{
         this->title=title_node->value();
      }

    //now getting parent_layout
     //if there are more layout calsses than each layout manager need to be checked using else if() statement as any layout manager can be use as a parent layout 
    xml_node<>* pnode=node->first_node(LINEAR_LAYOUT);
    if(pnode!=0)
        parent_layout=new LinearLayout(pnode);
   else{
    cout<<"SourceParser():"<<PARENT_LAYOUT_NOT_FOUND<<endl;


   } 
   
     
  return 1;
   }

int parse_result;
public:
    SourceParser(xml_node<>* root){
            node=root;
            this->parse_result= this->parseComponents();
    };
    
    const char* getTitle(){
      return this->title;
    }

    View* getParentLayout(){
      return this->parent_layout;
    }

   bool isParseSuccess(){
     if(this->parse_result==1)
        return true;

     return false;   
   }



   
};





 