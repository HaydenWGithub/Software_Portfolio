//
//  Node.h
//  task11
//
//  Created by Hayden Flynn Whiteford on 18/9/2023.
//

#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include "Player.h"
#include "Entity.h"
#include <map>

class Node {
public:
    //Node(const std::string& n, const std::string& desc);
    Player* myPlayer;
    std::vector<Node*> connections;
    std::string name;
    std::string description;
    std::vector<Entity*> entities;
    std::map<std::string, std::string> mappings;

    //void connect(Node* other);
};

#endif // NODE_H
