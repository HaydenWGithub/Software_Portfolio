//
//  CommandUse.h
//  zorkish-3
//
//  Created by Hayden Flynn Whiteford on 17/10/2023.
//

#ifndef CommandUse_h
#define CommandUse_h

#include "Node.h"
#include "Command.h"
#include <string>

class CommandUse : public Command {
public:
    std::string Process(std::string fInput, Node* aLocation) override;
};


#endif /* CommandUse_h */
