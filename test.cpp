#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    // Create an unordered_map to store key-value pairs of strings
    std::unordered_map<std::string, std::string> myMap;

    // Insert key-value pairs
    myMap["apple"] = "A fruit";
    myMap["book"] = "For reading";
    myMap["computer"] = "An electronic device";
    

    std::string ap="apple";

    // Access value using key
    std::string value = myMap[ap];
    std::cout << "Value for key 'apple': " << value << std::endl;

    std::cout<<"style=\"";

    return 0;
}