//
//  PostOffice.cpp
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 26/10/2023.
//

#include <stdio.h>
#include "PostOffice.h"
#include <string>
#include <sstream>
#include <iostream>
#include "Entity.h"
#include <variant>
#include "Player.h"


void PostOffice::ReadMessage() {
    //EXAMPLE MESSAGE: { from: player, to: A (light switch), message: “turn on” }
    bool isToPlayer = false;
    //read message string into a local variable
    std::string fMessage = Messages.front();
    std::istringstream fMessageISS(fMessage);
    
    //determine from and set local variable
    std::string fFromName;
    std::variant<Player*, Entity*> fFrom;
    while (std::getline(fMessageISS, fFromName, ' ')){
        if (fFromName.find("from:") == 0) {
            std::getline(fMessageISS, fFromName, ',');
            break;
        }
    }
        //loop through all entities in list
    if (fFromName == "player"){
        //set player variable to player pointer we already have
        fFrom = myPlayer;
    }
    else {
        //loop
        for (Entity* entity : Entities) {
            if (entity->Name == fFromName) {
                fFrom = entity;
            }
            
        }
    }
    
    //determine to and set local variable
    std::string fToName;
    std::variant<Player*, Entity*> fTo;
    while (std::getline(fMessageISS, fToName, ' ')){
        if (fToName.find("to:") == 0) {
            std::getline(fMessageISS, fToName, ',');
            break;
        }
    }
    //loop through all entities in list
    if (fToName == "player"){
        //set player variable to player pointer we already have
        fTo = myPlayer;
        isToPlayer = true;
    }
    else {
        //loop
        for (Entity* entity : Entities) {
            if (entity->Name == fToName) {
                fTo = entity;
            }
            
        }
    }
    
    
    //determine component and set local variable pointer
    std::string fComponentName;
    Component* fComponent = nullptr;
    while (std::getline(fMessageISS, fComponentName, ' ')){
        if (fComponentName.find("message:") == 0) {
            std::string fTempMessage = "";
            while (true){
                std::getline(fMessageISS, fComponentName, ' ');
                fTempMessage = fTempMessage + " " + fComponentName;
                std::string targetQuote = u8"”";  // UTF-8 encoded right double quotation mark
                // Convert the last character of the extracted message value to a string
                if (fTempMessage.back() == ','){
                    fTempMessage.erase(fTempMessage.find_last_not_of(',') + 1);
                }
                std::string lastChars = fTempMessage.substr(fTempMessage.size() - targetQuote.size());

                if (lastChars == targetQuote) {
                    fComponentName = fTempMessage;
                    break;
                    // The last character of stringName is a right double quotation mark
                }
            }
            fComponentName.erase(0, fComponentName.find_first_not_of(' '));
            fComponentName.erase(0, fComponentName.find_first_not_of("“")); // Remove leading quotes
            fComponentName.erase(fComponentName.find_last_not_of("”") + 1); // Remove trailing quotes
            break;
        }
    }
        //loop through all components in "to" entity
    if (isToPlayer){
        for (Component* component : std::get<Player*>(fTo)->Components){
            if (component->ActionName == fComponentName){
                fComponent = component;
                break;
            }
            
        }
    }
    else {
        for (Component* component : std::get<Entity*>(fTo)->Components){
            if (component->ActionName == fComponentName){
                fComponent = component;
                break;
            }
            
        }
    }
    
    //check if data is included and set local variable
    std::string fDataString = "";
    while (std::getline(fMessageISS, fDataString, ' ')){
        if (fDataString.find("data:") == 0) {
            std::getline(fMessageISS, fDataString, '}');
            fDataString.erase(0, fDataString.find_first_not_of("“")); // Remove leading quotes
            fDataString.erase(fDataString.find_last_not_of("”") + 1); // Remove trailing quotes
            break;
        }
    }
    
    //finally, call execute() of component with entity pointer and data
    if (isToPlayer){
        fComponent->Execute(fDataString, std::get<Player*>(fTo));
    }
    else {
        fComponent->Execute(fDataString, std::get<Entity*>(fTo));
    }
    
    
    //we should also update the fto entity with an "InConversationWith" attribute pointing to our "from" sender.
    //this allows for the receiver to be able to send a message back.
    
    
    //bump message
    Messages.pop_front();
    
}
