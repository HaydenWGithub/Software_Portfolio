//
//  Entity.h
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 26/10/2023.
//

#ifndef Entity_h
#define Entity_h

#include <string>
#include <map>
#include <variant>
#include <vector>
#include "PostOffice.h"
#include <list>
#include "Component.h"

class PostOffice;
class Component;

class Entity{
public:
    std::string Name;
    //Entity(PostOffice* aPostOffice);
    std::map<std::string, std::variant<int, bool, Entity*, std::string>> Attributes;
    //components now replace actions
    std::list<Component*> Components;
    std::vector<Entity*> ContainedEntities;
    //we need a get description function in order to tell the code to avoid printing out private attributes
    std::string Description;
    void SendMessage(std::string aMessage);
    PostOffice* postOffice;
};

#endif /* Entity_h */
