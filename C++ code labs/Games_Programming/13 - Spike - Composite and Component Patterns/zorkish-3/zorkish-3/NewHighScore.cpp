//
//  NewHighScore.cpp
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 7/9/2023.
//

#include "NewHighScore.h"

#include "MainMenu.h"

#include "GameStateManager.h"

#include <iostream>

void NewHighScore::Draw() {
    std::cout << "\nZorkish :: New High Score\n";
    std::cout << "--------------------------------------------------------\n\n";
    std::cout << "Congratulations!\n\n";
    std::cout << "You have made it to the Zorkish Hall Of Fame\n\n";
    std::cout << "Adventure: [the adventure world played]\n";
    std::cout << "Score: [the players score]\n";
    std::cout << "Moves: [number of moves player made]\n\n";
    std::cout << "Please type your name and press enter:\n";
}

GameState* NewHighScore::TakeInput() {
    //pressing enter from the last game state unfortunately triggers the input for this.
    //adding in a filler input so the user presses enter twice
    fFiller = std::cin.get();
    fInput = std::cin.get();
    std::cin.clear(); // Clear any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the remaining input until a newline character
    return new MainMenu();

    //do something for quit here
    
    return nullptr;
}

