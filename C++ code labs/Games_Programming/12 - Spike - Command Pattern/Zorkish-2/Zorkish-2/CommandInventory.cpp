//
//  CommandInventory.cpp
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 28/9/2023.
//

#include "CommandInventory.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::string CommandInventory::Process(std::string fInput, Node* aLocation)
{
    //the location we're being passed in is of the current location.
    //we need to return the name of the next location based on the current locations connections
    //HOWEVER...not all commands are going to change the location, in those cases we will simply return
    //the original location
    std::string output = aLocation->name;
    
    //this will be more robust. as soon as we add entities, we will need to rework this to work with the new
    //object type.
    std::cout << "Inventory: \n";
    for (Entity* item : aLocation->myPlayer->inventory){
        std::cout << item->Name << "\n";
    }
    std::cout << "press enter to return to adventure";
    
    std::cin.get();
    
    return output;
}
