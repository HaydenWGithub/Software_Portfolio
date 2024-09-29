//
//  ComponentGlow.cpp
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 28/10/2023.
//

#include <stdio.h>
#include "ComponentGlow.h"

ComponentGlow::ComponentGlow() {
    ActionName = "glow!";
}

void ComponentGlow::Execute(std::string data, Entity* entity) {
    entity->Attributes["glowing"] = true;
}
