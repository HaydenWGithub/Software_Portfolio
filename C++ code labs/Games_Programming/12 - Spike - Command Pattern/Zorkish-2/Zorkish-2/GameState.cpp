//
//  GameState.cpp
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 5/9/2023.
//

#include "GameState.h" // Include the header file for GameState
#include "GameStateManager.h" // Include the header file for GameStateManager

// Define the virtual functions
void GameState::Draw() {
    // Implement the Draw function in derived classes
}

GameState* GameState::TakeInput() {
    // Implement the TakeInput function in derived classes
    return nullptr; // Default behavior returns nullptr
}

void GameState::Update(GameStateManager* aStateManager) {
    // Implement state-specific logic here
    GameState* fNextState = TakeInput();
    
    aStateManager->CurrentState = fNextState;
    // You can use aStateManager to change states if needed
}
