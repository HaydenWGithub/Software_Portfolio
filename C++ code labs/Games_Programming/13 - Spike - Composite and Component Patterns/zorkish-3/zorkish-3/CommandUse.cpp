//
//  CommandUse.cpp
//  zorkish-3
//
//  Created by Hayden Flynn Whiteford on 17/10/2023.
//

#include "CommandUse.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "EntitySpecial.h"

std::string CommandUse::Process(std::string fInput, Node* aLocation)
{
    //the location we're being passed in is of the current location.
    //we need to return the name of the next location based on the current locations connections
    //HOWEVER...not all commands are going to change the location, in those cases we will simply return
    //the original location
    std::string output = aLocation->name;
    
    std::istringstream iss(fInput);
    std::string command;
    iss >> command;
    if (command == "use"){
        iss >> command;
        //identify the Entity being used. For this we're going to use the rule that you can only use entities that
        //are already in your inventory, meaning you would have to "Take" the object before using it
        EntitySpecial* SpecialEntity = nullptr;
        std::string EntityUsedName;
        for (Entity* entity : aLocation->myPlayer->inventory){
            std::string fName = entity->Name;
            std::transform(fName.begin(), fName.end(), fName.begin(), ::tolower);
            if (fName == command) {
                EntityUsedName = command;
                SpecialEntity = dynamic_cast<EntitySpecial*>(entity);
            }
        }
        //check if there is a target being used; if there isnt, we assume the target is ourselves
        if (SpecialEntity != nullptr){
            iss >> command;
            if (command == EntityUsedName){
                //target is ourselves; we know this because what we've read in is the same word as before, meaning there
                //is no other word after the entity specifier
                //check that we have the attribute for the use action
                std::string attribute;
                std::variant<int, bool, Entity*, std::string> effect;
                for (auto entry : SpecialEntity->Actions["Use"]){
                    attribute = entry.first;
                    effect = entry.second;
                }
                bool hasAttribute = false;
                for (auto entry : aLocation->myPlayer->Attributes){
                    if (entry.first == attribute){
                        hasAttribute = true;
                        //actually have the effect, affect the player
                        //we need to determine the data type of the effect
                        if (std::holds_alternative<int>(effect)) {
                            //add the effect to the entry.second
                            aLocation->myPlayer->Attributes[attribute] = std::get<int>(entry.second) + std::get<int>(effect);
                            std::cout << "you used the " << SpecialEntity->Name << "! " << attribute << " was affected! It's now " << std::get<int>(aLocation->myPlayer->Attributes[attribute]) << "! \n";
                        }
                        else if (std::holds_alternative<bool>(effect)) {
                            //set the entry.second to the effect
                            aLocation->myPlayer->Attributes[attribute] = std::get<bool>(effect);
                            std::cout << "you used the " << SpecialEntity->Name << "! " << attribute << " was affected!\n";
                        }
                    }
                }
                if (!hasAttribute){
                    std::cout << "You can't use the " << SpecialEntity->Name << " on yourself!\n";
                }
                
            }
            else if (command == "on"){
                iss >> command;
                EntitySpecial* target = nullptr;
                for (Entity* entity : aLocation->entities){
                    std::string fName = entity->Name;
                    std::transform(fName.begin(), fName.end(), fName.begin(), ::tolower);
                    if (fName == command) {
                        target = dynamic_cast<EntitySpecial*>(entity);
                    }
                }
                if (target != nullptr){
                    //check that the target has the attribute
                    //check that we have the attribute for the use action
                    std::string attribute;
                    std::variant<int, bool, Entity*, std::string> effect;
                    for (auto entry : SpecialEntity->Actions["Use"]){
                        attribute = entry.first;
                        effect = entry.second;
                    }
                    bool hasAttribute = false;
                    for (auto entry : target->Attributes){
                        if (entry.first == attribute){
                            hasAttribute = true;
                            //actually have the effect, affect the player
                            //we need to determine the data type of the effect
                            if (std::holds_alternative<int>(effect)) {
                                //add the effect to the entry.second
                                target->Attributes[attribute] = std::get<int>(entry.second) + std::get<int>(effect);
                                std::cout << "you used the " << SpecialEntity->Name << "! " << attribute << " was affected!\n";
                            }
                            else if (std::holds_alternative<bool>(effect)) {
                                //set the entry.second to the effect
                                target->Attributes[attribute] = std::get<bool>(effect);
                                std::cout << "you used the " << SpecialEntity->Name << "! " << attribute << " was affected! It's now " << std::get<bool>(target->Attributes[attribute]) << "!\n";
                            }
                        }
                    }
                    if (!hasAttribute){
                        std::cout << "you can't use the " << SpecialEntity->Name << " on the " << target->Name << "!\n";
                    }
                }
                else {
                    //target is invalid
                    std::cout << "Invalid target! Make sure the target isn't in your inventory!";
                }
            }
        }
        else {
            //entity specifier was invalid; the entity was not in our inventory
            std::cout << "Invalid Entity! Make sure the Entity you intend to use is in your Inventory!";
        }
        
        
    }
    
    return output;
}
