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
    std::cout << "  1. Stone World\n\n";
    std::cout << "Select 1(for now):";
}

GameState* SelectAdventure::TakeInput() {
    //pressing enter from the last game state unfortunately triggers the input for this.
    //adding in a filler input so the user presses enter twice
    fFiller = std::cin.get();
    std::getline(std::cin, fInput);

    if (fInput == "1") {
        fGraph = new Graph("locations.txt");
        std::cout << "\n\nWelcome to Zorkish: Stone World. This world is made up of several locations, objects and entities to interact with. Used it to test the Zorkish phase 2 spec.\n\n";
        while(true){
            fGraph->displayLocation();
            fGraph->takeInput();
            fGraph->updateLocation();
        }
    }
   
    
    std::cout << "Bad input! Enter again!";
    return this;
}
