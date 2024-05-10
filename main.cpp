
#include "sources.cpp"
#include <fstream>
#include <string>


using namespace std;
using namespace rapidxml;


char* readFileContent(const std::string& fileName) {
    std::ifstream fileStream(fileName, std::ios::in | std::ios::binary);
    if (!fileStream.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return nullptr;
    }

    fileStream.seekg(0, std::ios::end);
    std::streamoff fileSize = fileStream.tellg();
    fileStream.seekg(0, std::ios::beg);

    char* buffer = new char[fileSize + 1];
    fileStream.read(buffer, fileSize);
    buffer[fileSize] = '\0'; // Null terminate the buffer

    fileStream.close();
    return buffer;
}


void createHTMLfile(std::string& file_name ,   )

int getChildElementCount(xml_node<>& node) {
    xml_node<>* child = node.first_node();
    int count = 0;

    while (child != nullptr) {
        if (child->type() == node_element) {
            count++;
        }
        child = child->next_sibling();
    }

    return count;
}


int main(int argc , const char* argv[]){
    xml_document<> doc;

    char* file_data=readFileContent("file.xml");
    doc.parse<0>(file_data);
    
    xml_node<> *root=doc.first_node("root");

    SourceParser parser(root);
    cout<<"Title:"<<parser.getTitle()<<endl;

  
    return 0;
}
