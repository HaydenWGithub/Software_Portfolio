//
//  ComponentTurnOn.h
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 28/10/2023.
//

#ifndef ComponentTurnOn_h
#define ComponentTurnOn_h
#include "Component.h"

class ComponentTurnOn : public Component {
public:
    ComponentTurnOn();
    void Execute(std::string data, Entity* entity) override;
};

#endif /* ComponentTurnOn_h */
