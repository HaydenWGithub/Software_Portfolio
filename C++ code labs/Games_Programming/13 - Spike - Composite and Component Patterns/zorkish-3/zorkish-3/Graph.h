//
//  Graph.h
//  task11
//
//  Created by Hayden Flynn Whiteford on 18/9/2023.
//

#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include <string>
#include <vector>
#include "CommandManager.h"

class Graph {
public:
    Graph(const std::string& inputFile);
    ~Graph();

    void displayLocation() const;
    void takeInput();
    void updateLocation();

private:
    std::vector<Node*> nodes;
    Node* currentLocation;
    std::string nextLocation;
    CommandManager* commandManager;
    
};

#endif // GRAPH_H

