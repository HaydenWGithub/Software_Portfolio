//
//  CommandManager.cpp
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 27/9/2023.
//

#include "CommandManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "CommandAlias.h"
#include "CommandTake.h"
#include "CommandUse.h"

CommandManager::CommandManager()
{
    commands["go"] = new CommandMove();
    commands["n"] = new CommandMove();
    commands["e"] = new CommandMove();
    commands["s"] = new CommandMove();
    commands["w"] = new CommandMove();
    //NOTE: all of the n, e, s, w , ne etc. commands should be remapped here
    commands["move"] = new CommandMove();
    commands["help"] = new CommandHelp();
    commands["inventory"] = new CommandInventory();
    commands["look"] = new CommandLook();
    commands["alias"] = new CommandAlias(this); //we need to pass ourselves in here to allow for updating the commands map
    commands["debug"] = new CommandDebug();
    commands["take"] = new CommandTake();
    commands["use"] = new CommandUse();
}

std::string CommandManager::Process(std::string aInput, Node* aLocation)
{
    //make sure the line is lowercase
    std::transform(aInput.begin(), aInput.end(), aInput.begin(), ::tolower);
    std::istringstream iss(aInput);
    std::string firstWord;
    iss >> firstWord;
    //going to hard code the quit command in here
    if (firstWord == "quit"){
        exit(0);
    }
    Command* command = commands[firstWord];
    return command->Process(aInput, aLocation);
}
