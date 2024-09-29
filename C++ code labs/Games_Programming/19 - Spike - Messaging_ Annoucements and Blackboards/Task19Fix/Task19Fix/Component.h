//
//  Component.h
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 26/10/2023.
//

#ifndef Component_h
#define Component_h
#include <string>
#include "Entity.h"
#include "Player.h"

class Entity;
class Player;

//ABSTRACT CLASS
class Component {
public:
    std::string ActionName;
    void virtual Execute(std::string data, Entity* entity) = 0;
    void virtual Execute(std::string data, Player* player);
};

#endif /* Component_h */
