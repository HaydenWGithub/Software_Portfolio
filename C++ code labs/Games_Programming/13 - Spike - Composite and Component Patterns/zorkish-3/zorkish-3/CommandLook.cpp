//
//  CommandLook.cpp
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 3/10/2023.
//

#include "CommandLook.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "EntitySpecial.h"
#include <variant>

std::string CommandLook::Process(std::string fInput, Node* aLocation)
{
    //the location we're being passed in is of the current location.
    //we need to return the name of the next location based on the current locations connections
    //HOWEVER...not all commands are going to change the location, in those cases we will simply return
    //the original location
    std::string output = aLocation->name;
    
    std::istringstream iss(fInput);
    std::string command;
    iss >> command;
    if (command == "look"){
        iss >> command;
        if (command == "at"){
            iss >> command;
            for (Entity* entity : aLocation->entities){
                //convert entity name to lowercase
                std::string fName = entity->Name;
                std::transform(fName.begin(), fName.end(), fName.begin(), ::tolower);
                if (fName == command) {
                    std::cout << entity->Description << "\n";
                }
            }
        }
        else if (command == "in"){
            iss >> command;
            for (Entity* entity : aLocation->entities){
                //convert entity name to lowercase
                std::string fName = entity->Name;
                std::transform(fName.begin(), fName.end(), fName.begin(), ::tolower);
                if (fName == command) {
                    EntitySpecial* SpecialEntity = dynamic_cast<EntitySpecial*>(entity);
                    //we should check whether isLocked is true
                    if (SpecialEntity->Attributes.find("isLocked") != SpecialEntity->Attributes.end()){
                        if (std::get<bool>(SpecialEntity->Attributes["isLocked"]) == true){
                            std::cout << "The " << fName << " is locked! isLocked is currently " << std::get<bool>(SpecialEntity->Attributes["isLocked"]) <<"!\n";
                        }
                        else{
                            std::cout << "You look inside the " << fName << ", and see: \n";
                            for (Entity* ContainedEntity : SpecialEntity->ContainedEntities){
                                std::cout << "  " << ContainedEntity->Name << "\n";
                            }
                        }
                    }
                    else{
                        std::cout << "You can't look in this entity!";
                    }
                    
                }
            }
        }
        else if (command == "look"){ //if the command is just a single word, it gets read twice
            std::cout << aLocation->description << "\n";
        }
        else
        {
            std::cout << "Second word invalid! \n";
        }
    }
    else{
        std::cout << "First word invalid! \n";
    }
    
    return output;
    
}