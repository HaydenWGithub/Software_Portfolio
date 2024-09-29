//
//  ViewHallofFame.h
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 6/9/2023.
//

#ifndef ViewHallofFame_h
#define ViewHallofFame_h

#include "GameState.h"

class ViewHallofFame : public GameState {
private:
    char fInput;
    char fFiller;

public:
    virtual void Draw() override;
    virtual GameState* TakeInput() override;
    void Update(GameStateManager* aStateManager);
};

#endif /* ViewHallofFame_h */
