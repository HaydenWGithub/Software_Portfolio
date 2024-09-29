//
//  Player.cpp
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 26/10/2023.
//

#include <stdio.h>
#include "Player.h"
#include <iostream>

void Player::SendMessage(std::string aMessage){
    postOffice->Messages.push_back(aMessage);
}
