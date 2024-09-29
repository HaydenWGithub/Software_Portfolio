//
//  Graph.cpp
//  task11
//
//  Created by Hayden Flynn Whiteford on 18/9/2023.
//

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>


Graph::Graph(const std::string& inputFile) {
    std::ifstream file(inputFile);
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return;
    }
    std::string line;
    //start off by finding every location part of the text file and create a new node for each
    while (std::getline(file, line)) {
        
        if (line.find("Location: ") == 0) {
            size_t colonPos = line.find(':');
            //extract the rest of the line after "Location: "
            std::string location = line.substr(colonPos + 2);
            //create a new node and give it name of location
            Node* node = new Node();
            node->name = location;
            //add it to our nodes vector
            nodes.push_back(node);
        }
    }
    //reset getline to the start of the file
    file.clear();
    file.seekg(0, std::ios::beg);
    
    //iterate through the file again but this time add the descriptions
    int i = 0;
    while(std::getline(file, line)){
        if (line.find("Description: ") == 0) {
            size_t colonPos = line.find(':');
            //extract the rest of the line after "Location: "
            std::string description = line.substr(colonPos + 2);
            nodes[i]->description = description;
            i++;
        }
    }
    
    //reset getline to the start of the file
    file.clear();
    file.seekg(0, std::ios::beg);
    
    //iterate through and add the connections to the other nodes
    i = 0;
    while(std::getline(file, line)){
        if (line.find("Connections: ") == 0) {
            size_t colonPos = line.find(':');
            //extract the rest of the line after "Location: "
            std::string connections = line.substr(colonPos + 2);
            
            // Split the connections string into individual node names
            std::istringstream iss(connections);
            std::string nodeName;
                    
            while (iss >> nodeName) {
            // Find the corresponding node in the nodes vector and add it as a connection
                for (Node* node : nodes) {
                    if (nodeName.find(node->name) == 0) {
                        nodes[i]->connections.push_back(node);
                    }
                }
            }
            i++;
        }
    }
    
    file.close();

    if (!nodes.empty()) {
        currentLocation = nodes[0];
    } else {
        currentLocation = nullptr;
    }
}

Graph::~Graph() {
    for (Node* node : nodes) {
        delete node;
    }
}

void Graph::displayLocation() const {
    if (currentLocation) {
        std::cout << "Location: " << currentLocation->name << std::endl;
        std::cout << "Description: " << currentLocation->description << std::endl;
    }
}

void Graph::takeInput() {
    std::cout << "Where would you like to go? \n";
    for (Node* connection : currentLocation->connections) {
        std::cout << connection->name << "\n";
    }
    //implement the "go" command
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::string command;
    iss >> command;
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    if (command == "go"){
        iss >> command;
        std::transform(command.begin(), command.end(), command.begin(), ::tolower);
        if (command == "to"){
            iss >> fInput;
            std::transform(fInput.begin(), fInput.end(), fInput.begin(), ::tolower);
        }
        else
        {
            std::cout << "Second word invalid! \n";
        }
    }
    else if (command == "quit"){
        exit(0);
    }
    else{
        std::cout << "First word invalid! \n";
    }
}

void Graph::updateLocation() {
    for (Node* connection : currentLocation->connections) {
        std::string fName = connection->name;
        std::transform(fName.begin(), fName.end(), fName.begin(), ::tolower);
        if (fName == fInput) {
            currentLocation = connection;
            break;
        }
    }
}

