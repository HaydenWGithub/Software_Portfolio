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

class Node {
public:
    //Node(const std::string& n, const std::string& desc);

    std::vector<Node*> connections;
    std::string name;
    std::string description;

    //void connect(Node* other);
};

#endif // NODE_H
