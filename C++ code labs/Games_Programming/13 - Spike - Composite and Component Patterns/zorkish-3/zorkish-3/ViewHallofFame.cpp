//
//  ViewHallofFame.cpp
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 6/9/2023.
//

#include "ViewHallofFame.h"

#include "MainMenu.h"

#include "GameStateManager.h"

#include <iostream>

void ViewHallofFame::Draw() {
    std::cout << "\nZorkish :: Hall Of Fame\n";
    std::cout << "--------------------------------------------------------\n\n";
    std::cout << "Top 10 Zorkish Adventure Champions\n\n";
    std::cout << "  1. Fred, Mountain World, 5000\n";
    std::cout << "  2. Mary, Mountain World, 4000\n";
    std::cout << "  3. Joe, Water World, 3000\n";
    std::cout << "  4. Henry, Mountain World, 2000\n";
    std::cout << "  5. Susan, Mountain World, 1000\n";
    std::cout << "  6. Alfred, Water World, 900\n";
    std::cout << "  7. Clark, Mountain World, 800\n";
    std::cout << "  8. Harold, Mountain World, 500\n";
    std::cout << "  9. Julie, Water World, 300\n";
    std::cout << "  10. Bill, Box World, -5\n\n";
    std::cout << "Press Enter to return to the Main Menu";
}

GameState* ViewHallofFame::TakeInput() {
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
