//
//  CommandTake.cpp
//  zorkish-3
//
//  Created by Hayden Flynn Whiteford on 17/10/2023.
//

#include "CommandTake.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "EntitySpecial.h"

std::string CommandTake::Process(std::string fInput, Node* aLocation)
{
    //the location we're being passed in is of the current location.
    //we need to return the name of the next location based on the current locations connections
    //HOWEVER...not all commands are going to change the location, in those cases we will simply return
    //the original location
    std::string output = aLocation->name;
    
    std::istringstream iss(fInput);
    std::string command;
    iss >> command;
    if (command == "take"){
        iss >> command;
        std::string EntityTaken = command;
        iss >> command;
        if (command != EntityTaken){
            //the next phrase entered was "from"; read in the next word which should be the entity to take from
            iss >> command;
            //command should now be the entity container specifier
            EntitySpecial* container = nullptr;
            for (Entity* entity : aLocation->entities){
                //convert entity name to lowercase
                std::string fName = entity->Name;
                std::transform(fName.begin(), fName.end(), fName.begin(), ::tolower);
                if (fName == command) {
                    //check if the entity has a container
                    container = dynamic_cast<EntitySpecial*>(entity);
                    //check that the container has an islocked attribute
                    bool takeable = true;
                    if (container->Attributes.find("isLocked") != container->Attributes.end()){
                        //check that isLocked is false
                        if (std::get<bool>(container->Attributes["isLocked"]) == true){
                            takeable = false;
                        }
                    }
                    //check that the container has contained entities
                    if (takeable) {
                        if (container->ContainedEntities.size() > 0){
                            for (Entity* entity : container->ContainedEntities){
                                //convert entity name to lowercase
                                std::string fName = entity->Name;
                                std::transform(fName.begin(), fName.end(), fName.begin(), ::tolower);
                                if (fName == EntityTaken) {
                                    //put the entity into the player's inventory
                                    aLocation->myPlayer->inventory.push_back(entity);
                                    //erase the entity from the location's entity vector
                                    container->ContainedEntities.erase(std::remove(container->ContainedEntities.begin(), container->ContainedEntities.end(), entity), container->ContainedEntities.end());
                                    std::cout << "You take the " << entity->Name << " from the " << container->Name << ".\n";
                                }
                            }
                        }
                        else {
                            //container has no entities
                            std::cout << "There's nothing to take from the " << container->Name << "!\n";
                            
                        }
                    }
                    else {
                        //container is locked!
                        std::cout << "The " << container->Name << " is locked!";
                    }
                }
            }
        }
        else {
            for (Entity* entity : aLocation->entities){
                //convert entity name to lowercase
                std::string fName = entity->Name;
                std::transform(fName.begin(), fName.end(), fName.begin(), ::tolower);
                if (fName == command) {
                    //put the entity into the player's inventory
                    aLocation->myPlayer->inventory.push_back(entity);
                    //erase the entity from the location's entity vector
                    aLocation->entities.erase(std::remove(aLocation->entities.begin(), aLocation->entities.end(), entity), aLocation->entities.end());
                    std::cout << "You take the " << entity->Name << ".\n";
                }
            }
        }
        
    }
    return output;
}
