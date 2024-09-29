//
//  ComponentCheckBalance.h
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 29/10/2023.
//

#ifndef ComponentCheckBalance_h
#define ComponentCheckBalance_h
#include "Component.h"

class ComponentCheckBalance : public Component {
public:
    ComponentCheckBalance();
    void Execute(std::string data, Entity* entity) override;
};

#endif /* ComponentCheckBalance_h */
