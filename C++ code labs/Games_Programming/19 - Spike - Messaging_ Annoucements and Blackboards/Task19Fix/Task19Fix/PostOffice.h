//
//  PostOffice.h
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 26/10/2023.
//

#ifndef PostOffice_h
#define PostOffice_h
#include <deque>
#include <string>
#include <list>
#include "Entity.h"
#include "Player.h"

class Entity;
class Player;

class PostOffice {
public:
    std::list<Entity*> Entities;
    Player* myPlayer;
    std::deque<std::string> Messages;
    void ReadMessage();
};

#endif /* PostOffice_h */
