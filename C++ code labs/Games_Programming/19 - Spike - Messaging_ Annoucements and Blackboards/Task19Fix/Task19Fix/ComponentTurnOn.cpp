//
//  ComponentTurnOn.cpp
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 28/10/2023.
//

#include <stdio.h>
#include "ComponentTurnOn.h"
#include <sstream>
#include <iostream>

ComponentTurnOn::ComponentTurnOn() {
    ActionName = "turn on";
}

void ComponentTurnOn::Execute(std::string data, Entity* entity) {
    entity->Attributes["on"] = true;
    std::stringstream fmessage;
    fmessage << "{ from: " << entity->Name << ", to: globe, message: “glow!” }";
    
    std::string fMessageString = fmessage.str();
    entity->SendMessage(fMessageString);
}
