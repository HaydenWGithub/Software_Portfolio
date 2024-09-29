//
//  MainMenu.cpp
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 6/9/2023.
//

#include "MainMenu.h"
//other headers of other states go here
#include "NewHighScore.h"
#include "SelectAdventure.h"
#include "ViewHallofFame.h"
#include "Help.h"
#include "About.h"

#include "GameStateManager.h"

#include <iostream>

void MainMenu::Draw() {
    std::cout << "\nZorkish :: Main Menu\n";
    std::cout << "--------------------------------------------------------\n\n";
    std::cout << "Welcome to Zorkish Adventures\n";
    std::cout << "  1. Select Adventure and Play\n";
    std::cout << "  2. Hall Of Fame\n";
    std::cout << "  3. Help\n";
    std::cout << "  4. About\n";
    std::cout << "  5. Quit\n\n";
    std::cout << "Select 1-5:>";
}

GameState* MainMenu::TakeInput() {
    std::cin >> fInput;
    if (fInput == "1") {
        return new SelectAdventure();
    }
    else if (fInput == "2"){
        return new ViewHallofFame();
    }
    else if (fInput == "3"){
        return new Help();
    }
    else if (fInput == "4"){
        return new About();
    }
    else if (fInput == "5"){
        exit(0);
    }
    else if (fInput == "hiscore"){
        return new NewHighScore();
    }
    else if (fInput == "quit"){
        exit(0);
    }
    
    std::cout << "Bad input! Enter again!";
    return this;
}
