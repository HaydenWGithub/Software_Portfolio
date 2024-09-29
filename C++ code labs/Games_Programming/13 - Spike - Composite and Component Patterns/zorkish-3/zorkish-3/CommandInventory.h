//
//  CommandInventory.h
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 28/9/2023.
//

#ifndef CommandInventory_h
#define CommandInventory_h

#include "Node.h"
#include "Command.h"
#include <string>
#include "Player.h"
#include "Entity.h"

class CommandInventory : public Command {
public:
    std::string Process(std::string fInput, Node* aLocation) override;
};

#endif /* CommandInventory_h */
