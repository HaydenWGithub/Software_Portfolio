//
//  ComponentCheckBalance.cpp
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 29/10/2023.
//

#include <stdio.h>
#include "ComponentCheckBalance.h"
#include <sstream>
#include <iostream>

ComponentCheckBalance::ComponentCheckBalance() {
    ActionName = "check balance";
}

void ComponentCheckBalance::Execute(std::string data, Entity* entity) {
    //this component will be attached to the atm
    //example data - "1234567812345678"
    
    //use data to get balance from attributes
    std::string balance = "“" + std::get<std::string>(entity->Attributes[data]) + "”";
    std::stringstream fmessage;
    fmessage << "{ from: atm, to: player, message: “get balance”, data: "<< balance << "}";
    std::string fMessageString = fmessage.str();
    entity->SendMessage(fMessageString);
}
