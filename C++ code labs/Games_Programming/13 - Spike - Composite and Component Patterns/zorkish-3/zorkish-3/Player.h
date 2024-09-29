//
//  Player.h
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 28/9/2023.
//

#ifndef Player_h
#define Player_h

#include <deque>
#include "Entity.h"
#include <map>
#include <variant>

class Player {
public:
    Player();
    std::map<std::string, std::variant<int, bool, Entity*, std::string>> Attributes;
    std::deque<Entity*> inventory;
};

#endif /* Player_h */
