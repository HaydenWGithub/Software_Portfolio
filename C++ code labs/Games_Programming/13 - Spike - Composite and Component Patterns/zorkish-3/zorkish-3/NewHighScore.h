//
//  NewHighScore.h
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 6/9/2023.
//

#ifndef NewHighScore_h
#define NewHighScore_h

#include "GameState.h"
#include <string>

class NewHighScore : public GameState {
private:
    std::string fInput;
    std::string fFiller;

public:
    virtual void Draw() override;
    virtual GameState* TakeInput() override;
    void Update(GameStateManager* aStateManager);
};

#endif /* NewHighScore_h */
