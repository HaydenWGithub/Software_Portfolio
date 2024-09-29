//
//  TestState2.cpp
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 6/9/2023.
//

#include "TestState2.h"
#include "TestState.h"
#include "GameStateManager.h"

#include <iostream>

void TestState2::Draw() {
    std::cout << "You have reached TestState2! Press a to go back to TestState: ";
}

GameState* TestState2::TakeInput() {
    std::cin >> fInput;

    if (fInput == 'a') {
        // User input is 'a', return a TestState2 object
        return new TestState();
    }

    // User input is not 'a', stay in the current state
    return nullptr;
}


