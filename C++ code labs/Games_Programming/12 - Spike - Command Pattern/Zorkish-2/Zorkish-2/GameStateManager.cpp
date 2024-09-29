//
//  GameStateManager.cpp
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 5/9/2023.
//

#include "GameStateManager.h"
#include "MainMenu.h" // Include MainMenu header

// Constructor
GameStateManager::GameStateManager() {
    CurrentState = new MainMenu(); // Initialize with TestState as the initial state
}

// Destructor
GameStateManager::~GameStateManager() {
    delete CurrentState; // Cleanup CurrentState when the GameStateManager is destroyed
}

void GameStateManager::Update() {
    
    CurrentState->Update(this);
    
}

void GameStateManager::Draw() {
    
    CurrentState->Draw();
}
