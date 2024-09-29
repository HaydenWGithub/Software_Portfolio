//
//  EntitySpecial.h
//  zorkish-3
//
//  Created by Hayden Flynn Whiteford on 15/10/2023.
//

#ifndef EntitySpecial_h
#define EntitySpecial_h
#include <string>
#include <map>
#include <variant>
#include "Entity.h"
#include <vector>
#include "Node.h"

class EntitySpecial : public Entity {
public:
    Node* ParentNode;
    std::map<std::string, std::variant<int, bool, Entity*, std::string>> Attributes;
    //an example of an action - "Use", "Health", -3
    std::map<std::string, std::map<std::string, std::variant<int, bool, Entity*, std::string>>> Actions;
    std::vector<Entity*> ContainedEntities;
    //we need a get description function in order to tell the code to avoid printing out private attributes
    void virtual GetDescription() override;
};

#endif /* EntitySpecial_h */
