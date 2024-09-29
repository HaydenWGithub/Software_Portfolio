//
//  CommandTake.h
//  zorkish-3
//
//  Created by Hayden Flynn Whiteford on 17/10/2023.
//

#ifndef CommandTake_h
#define CommandTake_h

#include "Node.h"
#include "Command.h"
#include <string>

class CommandTake : public Command {
public:
    std::string Process(std::string fInput, Node* aLocation) override;
};

#endif /* CommandTake_h */
