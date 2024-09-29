//
//  CommandHelp.cpp
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 28/9/2023.
//

#include "CommandHelp.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::string CommandHelp::Process(std::string fInput, Node* aLocation)
{
    //the location we're being passed in is of the current location.
    //we need to return the name of the next location based on the current locations connections
    //HOWEVER...not all commands are going to change the location, in those cases we will simply return
    //the original location
    std::string output = aLocation->name;
    
    std::cout << "\nZorkish :: Adventure :: Help\n";
    std::cout << "--------------------------------------------------------\n\n";
    std::cout << "The following commands are supported:\n\n";
    std::cout << "  Quit,\n";
    std::cout << "  Go/Move (to) \n\n";
    std::cout << "  Help \n\n";
    std::cout << "  Inventory \n\n";
    std::cout << "  Look at \n\n";
    std::cout << "  Debug \n\n";
    std::cout << "  Alias [old Command] [new Command] \n\n";
    std::cout << "Press Enter to return to the Adventure";
    
    std::cin.get();
    
    return output;
}
