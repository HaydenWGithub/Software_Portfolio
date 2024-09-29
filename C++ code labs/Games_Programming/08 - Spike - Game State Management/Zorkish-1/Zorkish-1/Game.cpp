//
//  Game.cpp
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 4/9/2023.
//

#include <string>
#include <iostream>
#include "Game.h"

void Game::Run()
{
    GameStateManager StateManager; // Create a GameStateManager object

    // Call the StateManager's Draw() and then Update() functions
    while (true) {
        StateManager.Draw();
        StateManager.Update();
    }
}
