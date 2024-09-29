//
//  Help.cpp
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 6/9/2023.
//

#include "Help.h"
//other headers of other states go here
//#include "SelectAdventure.h"
//#include "ViewHallofFame.h"
//#include "About.h"
#include "MainMenu.h"

#include "GameStateManager.h"

#include <iostream>

void Help::Draw() {
    std::cout << "\nZorkish :: Help\n";
    std::cout << "--------------------------------------------------------\n\n";
    std::cout << "The following commands are supported:\n\n";
    std::cout << "  quit,\n";
    std::cout << "  hiscore (for testing)\n\n";
    std::cout << "Press Enter to return to the Main Menu";
}

GameState* Help::TakeInput() {
    //pressing enter from the last game state unfortunately triggers the input for this.
    //adding in a filler input so the user presses enter twice
    fFiller = std::cin.get();
    fInput = std::cin.get();

    if (fInput == '\n') {
        return new MainMenu();
    }
    //do something for quit here
    
    // User input is not 'a', stay in the current state
    return nullptr;
}

