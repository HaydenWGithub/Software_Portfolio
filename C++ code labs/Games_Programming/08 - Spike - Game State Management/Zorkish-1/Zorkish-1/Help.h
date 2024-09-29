//
//  Help.h
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 6/9/2023.
//

#ifndef Help_h
#define Help_h

#include "GameState.h"

class Help : public GameState {
private:
    char fInput;
    char fFiller;
public:
    virtual void Draw() override;
    virtual GameState* TakeInput() override;
    void Update(GameStateManager* aStateManager);
};

#endif /* Help_h */
