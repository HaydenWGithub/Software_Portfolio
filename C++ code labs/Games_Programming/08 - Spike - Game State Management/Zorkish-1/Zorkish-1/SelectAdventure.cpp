//
//  SelectAdventure.cpp
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 7/9/2023.
//

#include "SelectAdventure.h"
//other headers of other states go here
//#include "SelectAdventure.h"
//#include "ViewHallofFame.h"
#include "NewHighScore.h"
#include "MainMenu.h"

#include "GameStateManager.h"

#include <iostream>

void SelectAdventure::Draw() {
    std::cout << "\nZorkish :: Select Adventure\n";
    std::cout << "--------------------------------------------------------\n\n";
    std::cout << "Choose your adventure:\n\n";
    std::cout << "  1. Void World\n\n";
    std::cout << "Select 1(for now):";
}

GameState* SelectAdventure::TakeInput() {
    //pressing enter from the last game state unfortunately triggers the input for this.
    //adding in a filler input so the user presses enter twice
    fFiller = std::cin.get();
    std::getline(std::cin, fInput);

    if (fInput == "1") {
        std::cout << "\n\nWelcome to Zorkish: Void World\nThis world is simple and pointless. Used it to test Zorkish phase 1 spec.\n\n";
        std::getline(std::cin, fInput);
        std::cout << fInput;
        if (fInput == "quit"){
            exit(0);
        }
        else if (fInput == "hiscore"){
            return new NewHighScore();
        }
        else if (fInput == "\n"){
            return new MainMenu();
        }
    }
   
    
    std::cout << "Bad input! Enter again!";
    return this;
}
