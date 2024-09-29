//
//  CommandHelp.h
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 28/9/2023.
//

#ifndef CommandHelp_h
#define CommandHelp_h

#include "Node.h"
#include "Command.h"
#include <string>

class CommandHelp : public Command {
public:
    std::string Process(std::string fInput, Node* aLocation) override;
};

#endif /* CommandHelp_h */
