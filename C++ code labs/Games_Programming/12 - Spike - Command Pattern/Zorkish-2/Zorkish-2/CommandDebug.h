//
//  CommandDebug.h
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 3/10/2023.
//

#ifndef CommandDebug_h
#define CommandDebug_h

#include "Node.h"
#include "Command.h"
#include <string>
#include "Player.h"
#include "Entity.h"

class CommandDebug : public Command {
public:
    std::string Process(std::string fInput, Node* aLocation) override;
};


#endif /* CommandDebug_h */
