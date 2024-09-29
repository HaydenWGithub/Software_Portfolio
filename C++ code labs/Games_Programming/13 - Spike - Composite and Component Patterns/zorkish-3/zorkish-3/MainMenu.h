//
//  MainMenu.h
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 6/9/2023.
//

#ifndef MainMenu_h
#define MainMenu_h

#include "GameState.h"
#include <string>

class MainMenu : public GameState {
private:
    std::string fInput;
    
public:
    virtual void Draw() override;
    virtual GameState* TakeInput() override;
    void Update(GameStateManager* aStateManager);
};
    
#endif /* MainMenu_h */
