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
#include "Player.h"
#include "Entity.h"


Graph::Graph(const std::string& inputFile) {
    Player* myPlayer = new Player();
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
    
    //reset getline to the start of the file
    file.clear();
    file.seekg(0, std::ios::beg);
    
    i = 0;
    while (std::getline(file, line)) {
        if (line.find("Entities: ") == 0) {
            size_t colonPos = line.find(':');
            // Extract the rest of the line after "Location: "
            std::string entities = line.substr(colonPos + 2);

            // Split the entities string into individual entity descriptions
            std::istringstream iss(entities);
            std::string entityInfo;

            // Read entity descriptions line by line
            while (std::getline(iss, entityInfo, ',')) {
                std::string entityName;
                std::string entityDescription;
                
                std::istringstream entityIss(entityInfo);
                
                std::getline(entityIss, entityName, ':');
                entityName.erase(0, entityName.find_first_not_of(" \t")); // Remove leading whitespaces
                entityName.erase(entityName.find_last_not_of(" \t") + 1); // Remove trailing whitespaces
                
                std::getline(entityIss, entityDescription, ',');
                entityDescription.erase(0, entityDescription.find_first_not_of(" \t")); // Remove leading whitespaces
                entityDescription.erase(entityDescription.find_last_not_of(" \t") + 1); // Remove trailing whitespaces
                
                Entity* entity = new Entity();
                entity->Name = entityName;
                entity->Description = entityDescription;
                
                nodes[i]->entities.push_back(entity);
            }
            i++;
        }
    }
    
    //reset getline to the start of the file
    file.clear();
    file.seekg(0, std::ios::beg);
    
    i = 0;
    while (std::getline(file, line)) {
        if (line.find("Mappings: ") == 0) {
            size_t colonPos = line.find(':');
            // Extract the rest of the line after "Mappings: "
            std::string mappings = line.substr(colonPos + 2);

            // Split the mappings string into individual mappings
            std::istringstream iss(mappings);
            std::string mapInfo;

            // Read mappings line by line
            while (std::getline(iss, mapInfo, ',')) {
                std::string mappingCommand;
                std::string mappingLocation;
                
                std::istringstream mapIss(mapInfo);
                
                std::getline(mapIss, mappingCommand, ':');
                mappingCommand.erase(0, mappingCommand.find_first_not_of(" \t")); // Remove leading whitespaces
                mappingCommand.erase(mappingCommand.find_last_not_of(" \t") + 1); // Remove trailing whitespaces
                
                std::getline(mapIss, mappingLocation, ',');
                mappingLocation.erase(0, mappingLocation.find_first_not_of(" \t")); // Remove leading whitespaces
                mappingLocation.erase(mappingLocation.find_last_not_of(" \t") + 1); // Remove trailing whitespaces
                
                //we need to check that the mapping location is indeed part of the connections for that node
                Node* mappedNode = nullptr;
                for (Node* connection : nodes[i]->connections){
                    if (connection->name == mappingLocation){
                        mappedNode = connection;
                    }
                }
                //then simply insert the key and value into the nodes->mappings
                if (mappedNode != nullptr){
                    std::string mappedNodeName = mappedNode->name;
                    std::transform(mappedNodeName.begin(), mappedNodeName.end(), mappedNodeName.begin(), ::tolower);
                    std::transform(mappingCommand.begin(), mappingCommand.end(), mappingCommand.begin(), ::tolower);
                    nodes[i]->mappings[mappingCommand] = mappedNodeName;
                }
                
                //NOTE: there may need to be code for dealing with capitals here
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
    
    commandManager = new CommandManager();
    currentLocation->myPlayer = myPlayer;
}

Graph::~Graph() {
    for (Node* node : nodes) {
        delete node;
    }
}

void Graph::displayLocation() const {
    if (currentLocation) {
        //std::cout << "Location: " << currentLocation->name << std::endl;
        //std::cout << "Description: " << currentLocation->description << std::endl;
    }
}

void Graph::takeInput() {
    /*std::cout << "Where would you like to go? \n";
    for (Node* connection : currentLocation->connections) {
        std::cout << connection->name << "\n";
    }*/
    //implement the "go" command
    std::cout << ":>";
    std::string line;
    std::getline(std::cin, line);
    nextLocation = commandManager->Process(line, currentLocation);
}

void Graph::updateLocation() {
    //with the way our nodes vector works, we cant actually use objects instead of names, since we
    //dont have pointers or variables that we could use to access each node. If we want to know what node
    //was what location, we need to iterate through and check the name, so we are doing this here.
    for (Node* connection : currentLocation->connections) {
        std::string fName = connection->name;
        std::transform(fName.begin(), fName.end(), fName.begin(), ::tolower);
        if (fName == nextLocation) {
            //giving the new location the pointer to our player
            connection->myPlayer = currentLocation->myPlayer;
            currentLocation = connection;
            break;
        }
    }
}

