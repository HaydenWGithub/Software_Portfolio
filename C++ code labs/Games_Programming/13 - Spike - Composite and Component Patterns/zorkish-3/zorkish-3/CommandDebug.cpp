//
//  CommandDebug.cpp
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 4/10/2023.
//

#include <stdio.h>
#include "CommandDebug.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::string CommandDebug::Process(std::string fInput, Node* aLocation)
{
    //the location we're being passed in is of the current location.
    //we need to return the name of the next location based on the current locations connections
    //HOWEVER...not all commands are going to change the location, in those cases we will simply return
    //the original location
    std::string output = aLocation->name;
    
    //this will be more robust. as soon as we add entities, we will need to rework this to work with the new
    //object type.
    std::cout << "CURRENT LOCATION: " << aLocation->name << "\n";
    
    std::cout << "CURRENT CONNECTED LOCATIONS: \n";
    for (Node* node : aLocation->connections){
        std::cout << "  " << node->name << "\n";
    }
    
    std::cout << "AVAILABLE ENTITIES: \n";
    for (Entity* entity : aLocation->entities){
        std::cout << "  " << entity->Name << "\n";
    }
    
    std::cout << "CURRENT INVENTORY: \n";
    for (Entity* item : aLocation->myPlayer->inventory){
        std::cout << item->Name << "\n";
    }
    std::cout << "press enter to return to adventure";
    
    std::cin.get();
    
    return output;
}

