//
//  main.cpp
//  lab10B
//
//  Created by Hayden Flynn Whiteford on 13/9/2023.
//

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::ifstream inputFile("test2.txt", std::ios::in);
    std::string myText;
    while (getline (inputFile, myText)) {
      // Output the text from the file
        if (myText[0] != '\n' && myText[0] != '#'){
            
            //split the last line up and print
            
            std::stringstream ss(myText);
            std::string part;

            while (getline(ss, part, ':')) {
            // Print each part of the split line
                std::cout << "Bit: " << part << std::endl;
            }
        }
      
    }

    return 0;
}
