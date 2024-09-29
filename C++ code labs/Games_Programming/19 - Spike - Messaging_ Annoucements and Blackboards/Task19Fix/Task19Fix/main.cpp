//
//  main.cpp
//  Task19Fix
//
//  Created by Hayden Flynn Whiteford on 26/10/2023.
//

#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "PostOffice.h"
#include "Component.h"
#include "ComponentOpen.h"
#include "ComponentTurnOn.h"
#include "ComponentGlow.h"
#include "ComponentUnlock.h"
#include "ComponentCheckBalance.h"
#include "ComponentGetBalance.h"

PostOffice* myPostOffice = new PostOffice();
Entity* box = new Entity();
Player* myPlayer = new Player();
Component* open = new ComponentOpen();
Entity* lightSwitch = new Entity;
Entity* globe = new Entity();
Component* turnOn = new ComponentTurnOn();
Component* glow = new ComponentGlow();
Entity* luggage = new Entity();
Component* unlock = new ComponentUnlock();
Entity* atm = new Entity();
Component* checkBalance = new ComponentCheckBalance;
Component* getBalance = new ComponentGetBalance;


int main(int argc, const char * argv[]) {
    // insert code here...
    
    box->Attributes["open"] = false;
    box->Name = "box";
    box->Components.push_back(open);
    
    myPostOffice->Entities.push_back(box);
    myPlayer->postOffice = myPostOffice;
    myPostOffice->myPlayer = myPlayer;
    
    std::cout << "box open status is currently: " << std::get<bool>(box->Attributes["open"]) << "\n";
    std::string message = "{ from: player, to: box, message: “open” }";
    std::cout << "Player is sending message: " << message << "\n";
    myPlayer->SendMessage(message);
    std::cout << "Reading Message...\n";
    myPostOffice->ReadMessage();
    std::cout << "Message read and executed!\n";
    std::cout << "box open status is currently: " << std::get<bool>(box->Attributes["open"]) << "\n\n";
    
    std::cout << "TEST #2\n";
    globe->Name = "globe";
    globe->Attributes["glowing"] = false;
    globe->Components.push_back(glow);
    globe->postOffice = myPostOffice;
    
    lightSwitch->Name = "switch";
    lightSwitch->Attributes["on"] = false;
    lightSwitch->Components.push_back(turnOn);
    lightSwitch->postOffice = myPostOffice;
    
    myPostOffice->Entities.push_back(lightSwitch);
    myPostOffice->Entities.push_back(globe);
    
    std::cout << "switch on status is currently: " << std::get<bool>(lightSwitch->Attributes["on"]) << "\n";
    std::cout << "globe glowing status is currently: " << std::get<bool>(globe->Attributes["glowing"]) << "\n";
    message = "{ from: player, to: switch, message: “turn on” }";
    std::cout << "Player is sending message: " << message << "\n";
    myPlayer->SendMessage(message);
    std::cout << "Reading Message...\n";
    myPostOffice->ReadMessage();
    myPostOffice->ReadMessage();
    std::cout << "Message read and executed!\n";
    std::cout << "switch on status is currently: " << std::get<bool>(lightSwitch->Attributes["on"]) << "\n";
    std::cout << "globe glowing status is currently: " << std::get<bool>(globe->Attributes["glowing"]) << "\n\n";
    
    std::cout << "TEST #3\n";
    luggage->Name = "luggage";
    luggage->Attributes["unlocked"] = false;
    luggage->Attributes["code"] = "123456";
    luggage->Components.push_back(unlock);
    luggage->postOffice = myPostOffice;
    
    myPostOffice->Entities.push_back(luggage);
    
    std::cout << "unlock status is currently: " << std::get<bool>(luggage->Attributes["unlocked"]) << "\n";
    message = "{ from: player, to: luggage, message: “unlock”, data: “123456”}";
    std::cout << "Player is sending message: " << message << "\n";
    myPlayer->SendMessage(message);
    std::cout << "Reading Message...\n";
    myPostOffice->ReadMessage();
    std::cout << "Message read and executed!\n";
    std::cout << "unlock status is currently: " << std::get<bool>(luggage->Attributes["unlocked"]) << "\n\n";
    
    std::cout << "TEST #4\n";
    myPlayer->Attributes["CheckedBalance"] = "Balance Unknown :(";
    myPlayer->Components.push_back(getBalance);
    
    atm->Name = "atm";
    atm->Attributes["1234567812345678"] = "$75";
    atm->Components.push_back(checkBalance);
    atm->postOffice = myPostOffice;
    
    myPostOffice->Entities.push_back(atm);
    
    std::cout << "Player's CheckedBalance status is currently: " << std::get<std::string>(myPlayer->Attributes["CheckedBalance"]) << "\n";
    message = "{ from: player, to: atm, message: “check balance”, data: “1234567812345678”}";
    std::cout << "Player is sending message: " << message << "\n";
    myPlayer->SendMessage(message);
    std::cout << "Reading Message...\n";
    myPostOffice->ReadMessage();
    std::cout << "Message read and executed!\n";
    message = "{ from: atm, to: player, message: “get balance”, data: “$75”}";
    std::cout << "atm is sending message: " << message << "\n";
    myPostOffice->ReadMessage();
    std::cout << "Message read and executed!\n";
    std::cout << "Player's CheckedBalance status is currently: " << std::get<std::string>(myPlayer->Attributes["CheckedBalance"]) << "\n";
    
    return 0;
}
