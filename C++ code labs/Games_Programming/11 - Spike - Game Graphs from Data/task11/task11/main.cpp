//
//  main.cpp
//  task11
//
//  Created by Hayden Flynn Whiteford on 18/9/2023.
//

#include <iostream>
#include "Graph.h"

int main(int argc, const char * argv[]) {
    Graph gameWorld("locations.txt");

        while (true) {
            gameWorld.displayLocation();
            gameWorld.takeInput();
            gameWorld.updateLocation();
        }

        return 0;
}
