//
//  ComponentOpen.cpp
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 27/10/2023.
//

#include <stdio.h>
#include "ComponentOpen.h"

ComponentOpen::ComponentOpen() {
    ActionName = "open";
}

void ComponentOpen::Execute(std::string data, Entity* entity) {
    entity->Attributes["open"] = true;
}
