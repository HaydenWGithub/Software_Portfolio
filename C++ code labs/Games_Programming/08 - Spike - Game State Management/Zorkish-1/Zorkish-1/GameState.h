//
//  GameState.h
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 5/9/2023.
//

#ifndef GameState_h
#define GameState_h

class GameStateManager; // Forward declaration

class GameState {
public:
    virtual void Draw();
    virtual GameState* TakeInput(); // Return a pointer to GameState
    void Update(GameStateManager* aStateManager); // Use a pointer to GameStateManager
};

#endif /* GameState_h */
