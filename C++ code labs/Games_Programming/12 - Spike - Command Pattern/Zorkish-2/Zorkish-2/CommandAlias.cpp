//
//  CommandAlias.cpp
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 3/10/2023.
//

#include <stdio.h>
#include "CommandAlias.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "CommandManager.h"

CommandAlias::CommandAlias(CommandManager* aCommandManager){
    fCommandManager = aCommandManager;
}

std::string CommandAlias::Process(std::string fInput, Node* aLocation)
{
    //the location we're being passed in is of the current location.
    //we need to return the name of the next location based on the current locations connections
    //HOWEVER...not all commands are going to change the location, in those cases we will simply return
    //the original location
    std::string output = aLocation->name;
    
    std::istringstream iss(fInput);
    std::string word;
    std::string oldCommand;
    std::string newCommand;
    iss >> word;
    if (word == "alias"){
        iss >> oldCommand;
        iss >> newCommand;
        fCommandManager->commands[newCommand] = fCommandManager->commands[oldCommand];
    }
    
    return output;
}

