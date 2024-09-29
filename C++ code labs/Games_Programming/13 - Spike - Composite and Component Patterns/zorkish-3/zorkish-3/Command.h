//
//  Command.h
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 27/9/2023.
//

#ifndef Command_h
#define Command_h

#include "Node.h"
#include <string>

class Command {
public:
    virtual std::string Process(std::string fInput, Node* aLocation);
};

#endif /* Command_h */
