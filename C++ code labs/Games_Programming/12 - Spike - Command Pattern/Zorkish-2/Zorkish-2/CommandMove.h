//
//  CommandMove.h
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 27/9/2023.
//

#ifndef CommandMove_h
#define CommandMove_h

#include "Node.h"
#include "Command.h"
#include <string>

class CommandMove : public Command {
public:
    std::string Process(std::string fInput, Node* aLocation) override;
};

#endif /* CommandMove_h */
