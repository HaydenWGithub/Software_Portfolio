//
//  ComponentOpen.h
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 27/10/2023.
//

#ifndef ComponentOpen_h
#define ComponentOpen_h
#include "Component.h"

class ComponentOpen : public Component {
public:
    ComponentOpen();
    void Execute(std::string data, Entity* entity) override;
};


#endif /* ComponentOpen_h */
