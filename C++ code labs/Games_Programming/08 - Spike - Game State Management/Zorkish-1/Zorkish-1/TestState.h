//
//  TestState.h
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 6/9/2023.
//

#ifndef TestState_h
#define TestState_h

#include "GameState.h"

class TestState : public GameState {
private:
    char fInput;

public:
    virtual void Draw() override;
    virtual GameState* TakeInput() override;
    void Update(GameStateManager* aStateManager);
};

#endif /* TestState_h */
