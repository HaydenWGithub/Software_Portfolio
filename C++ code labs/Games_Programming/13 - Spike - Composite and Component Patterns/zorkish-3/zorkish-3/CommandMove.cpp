//
//  CommandMove.cpp
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 27/9/2023.
//

#include "CommandMove.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

std::string CommandMove::Process(std::string fInput, Node* aLocation)
{
    //the location we're being passed in is of the current location.
    //we need to return the name of the next location based on the current locations connections
    //HOWEVER...not all commands are going to change the location, in those cases we will simply return
    //the original location
    std::string output = aLocation->name;
    
    //we should run this input through 2 different maps
    
    //first, run this through a universal map that converts n, e, sw etc. to "go north/south/southwest..."
    std::map<std::string, std::string> directionsMap;
    
    directionsMap["n"] = "go north";
    directionsMap["e"] = "go east";
    directionsMap["s"] = "go south";
    directionsMap["w"] = "go west";
    //add more for diagonals
    if (directionsMap.find(fInput) != directionsMap.end()){
        fInput = directionsMap[fInput];
    }
    //then we need an else if statement for the second word where we run our second word through our nodes remapper
    //which should then return the correct output node
    
    std::istringstream iss(fInput);
    std::string command;
    iss >> command;
    if (command == "go" || command == "move"){
        iss >> command;
        if (command == "to"){
            iss >> output;
        }
        else if (aLocation->mappings.find(command) != aLocation->mappings.end()){
            output = aLocation->mappings[command];
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
