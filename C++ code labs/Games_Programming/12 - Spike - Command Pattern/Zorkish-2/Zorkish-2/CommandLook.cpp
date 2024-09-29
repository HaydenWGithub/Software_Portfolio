//
//  CommandLook.cpp
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 3/10/2023.
//

#include "CommandLook.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::string CommandLook::Process(std::string fInput, Node* aLocation)
{
    //the location we're being passed in is of the current location.
    //we need to return the name of the next location based on the current locations connections
    //HOWEVER...not all commands are going to change the location, in those cases we will simply return
    //the original location
    std::string output = aLocation->name;
    
    std::istringstream iss(fInput);
    std::string command;
    iss >> command;
    if (command == "look"){
        iss >> command;
        if (command == "at"){
            iss >> command;
            for (Entity* entity : aLocation->entities){
                //convert entity name to lowercase
                std::string fName = entity->Name;
                std::transform(fName.begin(), fName.end(), fName.begin(), ::tolower);
                if (fName == command) {
                    std::cout << entity->Description << "\n";
                }
            }
        }
        else if (command == "look"){ //if the command is just a single word, it gets read twice
            std::cout << aLocation->description << "\n";
        }
        else
        {
            std::cout << "Second word invalid! \n";
        }
    }
    else{
        std::cout << "First word invalid! \n";
    }
    
    return output;
    
}
