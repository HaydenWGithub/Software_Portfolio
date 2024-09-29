//
//  CommandManager.h
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 27/9/2023.
//

#ifndef CommandManager_h
#define CommandManager_h

#include "Node.h"
#include <map>
#include <string>
#include "Command.h"
#include "CommandMove.h"
#include "CommandHelp.h"
#include "CommandInventory.h"
#include "CommandLook.h"
#include "CommandDebug.h"

class CommandManager {
public:
    std::map<std::string, Command*> commands;
    CommandManager();
    std::string Process(std::string aInput, Node* aLocation);
};

#endif /* CommandManager_h */
