//
//  TestState2.h
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 6/9/2023.
//

#ifndef TestState2_h
#define TestState2_h

#include "GameState.h"

class TestState2 : public GameState {
private:
    char fInput;
    
public:
    virtual void Draw() override;
    virtual GameState* TakeInput() override;
    void Update(GameStateManager* aStateManager);
};

#endif /* TestState_h */
