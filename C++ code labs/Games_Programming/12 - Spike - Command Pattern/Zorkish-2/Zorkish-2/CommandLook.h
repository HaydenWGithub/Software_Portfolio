//
//  CommandLook.h
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 3/10/2023.
//

#ifndef CommandLook_h
#define CommandLook_h

#include "Node.h"
#include "Command.h"
#include <string>
#include "Player.h"
#include "Entity.h"

class CommandLook : public Command {
public:
    std::string Process(std::string fInput, Node* aLocation) override;
};

#endif /* CommandLook_h */
