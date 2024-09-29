//
//  Player.h
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 26/10/2023.
//

#ifndef Player_h
#define Player_h

#include <deque>
#include "Entity.h"
#include <map>
#include <variant>
#include "PostOffice.h"
#include "Component.h"

class Entity;
class PostOffice;
class Component;

class Player {
public:
    std::map<std::string, std::variant<int, bool, Entity*, std::string>> Attributes;
    std::list<Component*> Components;
    std::deque<Entity*> inventory;
    PostOffice* postOffice;
    void SendMessage(std::string aMessage);
};

#endif /* Player_h */
