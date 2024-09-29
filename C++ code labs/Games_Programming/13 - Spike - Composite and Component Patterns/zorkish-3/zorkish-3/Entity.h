//
//  Entity.h
//  Zorkish-2
//
//  Created by Hayden Flynn Whiteford on 2/10/2023.
//

#ifndef Entity_h
#define Entity_h

#include <string>

class Entity {
public:
    std::string Name;
    std::string Description;
    void virtual GetDescription();
};


#endif /* Entity_h */
