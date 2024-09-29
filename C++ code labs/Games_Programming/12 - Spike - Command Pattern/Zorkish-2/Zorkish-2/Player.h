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

class Player {
public:
    std::deque<Entity*> inventory;
};

#endif /* Player_h */
