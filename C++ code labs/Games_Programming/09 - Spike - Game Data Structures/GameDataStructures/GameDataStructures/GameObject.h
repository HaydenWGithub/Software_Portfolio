//
//  GameObject.h
//  GameDataStructures
//
//  Created by Hayden Flynn Whiteford on 10/9/2023.
//

#ifndef GameObject_h
#define GameObject_h

#include <string>

class GameObject {
public:
    GameObject(const std::string& description);
    
    // Getter for the description
    std::string getDescription() const;

    // Setter for the description
    void setDescription(const std::string& description);

private:
    std::string description;
};

#endif // GAMEOBJECT_H
