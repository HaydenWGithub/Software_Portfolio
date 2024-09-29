//
//  GameStateManager.h
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 5/9/2023.
//

#ifndef GameStateManager_h
#define GameStateManager_h

#include "GameState.h"

class GameStateManager {
public:
    GameState* CurrentState;

    // Constructor
    GameStateManager();

    // Destructor
    ~GameStateManager();

    void Update();
    void Draw();
};

#endif /* GameStateManager_h */
