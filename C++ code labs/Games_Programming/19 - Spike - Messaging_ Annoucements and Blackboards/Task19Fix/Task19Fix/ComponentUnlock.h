//
//  ComponentUnlock.h
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 29/10/2023.
//

#ifndef ComponentUnlock_h
#define ComponentUnlock_h
#include "Component.h"

class ComponentUnlock : public Component {
public:
    ComponentUnlock();
    void Execute(std::string data, Entity* entity) override;
};


#endif /* ComponentUnlock_h */
