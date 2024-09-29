//
//  TestState.cpp
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 6/9/2023.
//

#include "TestState.h"
#include "TestState2.h" // Include TestState2 header for returning a TestState2 object
#include "GameStateManager.h"

#include <iostream>

void TestState::Draw() {
    std::cout << "Testing! Press the letter a: ";
}

GameState* TestState::TakeInput() {
    std::cin >> fInput;

    if (fInput == 'a') {
        // User input is 'a', return a TestState2 object
        return new TestState2();
    }

    // User input is not 'a', stay in the current state
    return nullptr;
}



