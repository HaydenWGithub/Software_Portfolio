//
//  ComponentGetBalance.cpp
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 29/10/2023.
//

#include <stdio.h>
#include "ComponentGetBalance.h"

ComponentGetBalance::ComponentGetBalance() {
    ActionName = "get balance";
}

void ComponentGetBalance::Execute(std::string data, Player* player) {
    player->Attributes["CheckedBalance"] = data;
}

void ComponentGetBalance::Execute(std::string data, Entity* entity) {
    entity->Attributes["CheckedBalance"] = data;
}
