//
//  Game.h
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 5/9/2023.
//

#ifndef Game_h
#define Game_h

#include "GameStateManager.h"
#include "Player.h"

class Game {
public:
    GameStateManager StateManager;
    void Run();
};

#endif /* Game_h */

