//
//  GameObject.cpp
//  GameDataStructures
//
//  Created by Hayden Flynn Whiteford on 10/9/2023.
//

#include "GameObject.h"

// Constructor to initialize the description
GameObject::GameObject(const std::string& description) : description(description) {}

// Getter for the description
std::string GameObject::getDescription() const {
    return description;
}

// Setter for the description
void GameObject::setDescription(const std::string& newDescription) {
    description = newDescription;
}
