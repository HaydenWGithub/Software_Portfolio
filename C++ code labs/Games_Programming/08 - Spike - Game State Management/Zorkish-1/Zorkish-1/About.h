//
//  About.h
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 6/9/2023.
//

#ifndef About_h
#define About_h

#include "GameState.h"

class About : public GameState {
private:
    char fInput;
    char fFiller;
    
public:
    virtual void Draw() override;
    virtual GameState* TakeInput() override;
    void Update(GameStateManager* aStateManager);
};
    
#endif /* About_h */
