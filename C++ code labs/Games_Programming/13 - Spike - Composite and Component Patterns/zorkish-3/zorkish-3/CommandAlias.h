//
//  CommandAlias.h
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 3/10/2023.
//

#ifndef CommandAlias_h
#define CommandAlias_h

#include "CommandManager.h"

class CommandAlias : public Command {
public:
    CommandAlias(CommandManager* CommandManager);
    std::string Process(std::string fInput, Node* aLocation) override;
    CommandManager* fCommandManager;
};

#endif /* CommandAlias_h */
