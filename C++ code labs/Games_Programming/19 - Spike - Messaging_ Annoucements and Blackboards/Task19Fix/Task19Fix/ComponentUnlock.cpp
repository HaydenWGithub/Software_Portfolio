//
//  ComponentUnlock.cpp
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 29/10/2023.
//

#include <stdio.h>
#include <iostream>
#include "ComponentUnlock.h"

ComponentUnlock::ComponentUnlock() {
    ActionName = "unlock";
}

void ComponentUnlock::Execute(std::string data, Entity* entity) {
    if (std::get<std::string>(entity->Attributes["code"]) == data){
        entity->Attributes["unlocked"] = true;
    }
    else {
        std::cout << "Locked!";
    }
    
}
