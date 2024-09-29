//
//  ComponentGetBalance.h
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 29/10/2023.
//

#ifndef ComponentGetBalance_h
#define ComponentGetBalance_h
#include "Component.h"

class ComponentGetBalance : public Component {
public:
    ComponentGetBalance();
    void Execute(std::string data, Player* player) override;
    void Execute(std::string data, Entity* entity) override;
};

#endif /* ComponentGetBalance_h */
