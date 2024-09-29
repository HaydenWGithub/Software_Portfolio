//
//  main.cpp
//  lab10C
//
//  Created by Hayden Flynn Whiteford on 13/9/2023.
//

#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

int main(int argc, const char * argv[]) {
    
    //open the file for reading
    std::ifstream inputFile("test3.json");
    
    //parse the json data?
    json jsonData;
    inputFile >> jsonData;
    
    //close it again - we put the data into the json data file
    inputFile.close();
    
    //we use the & symbol here so we get the values by reference instead of making copies
    for (auto& entry : jsonData.items()) {
        std::string key = entry.key();       // Get the key
        json value = entry.value();          // Get the value

        // Print the key and value
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
        }

    
    
    return 0;
}
