//
//  SelectAdventure.h
//  Zorkish-1
//
//  Created by Hayden Flynn Whiteford on 6/9/2023.
//

#ifndef SelectAdventure_h
#define SelectAdventure_h

#include "GameState.h"
#include <string>
#include "Graph.h"

class SelectAdventure : public GameState {
private:
    std::string fInput;
    char fFiller;
    Graph* fGraph;
public:
    virtual void Draw() override;
    virtual GameState* TakeInput() override;
    void Update(GameStateManager* aStateManager);
};

#endif /* SelectAdventure_h */