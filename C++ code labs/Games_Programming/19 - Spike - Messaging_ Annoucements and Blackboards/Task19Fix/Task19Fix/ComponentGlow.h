//
//  ComponentGlow.h
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 28/10/2023.
//

#ifndef ComponentGlow_h
#define ComponentGlow_h
#include "Component.h"

class ComponentGlow : public Component {
public:
    ComponentGlow();
    void Execute(std::string data, Entity* entity) override;
};

#endif /* ComponentGlow_h */
