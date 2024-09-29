//
//  main.cpp
//  GameDataStructures
//
//  Created by Hayden Flynn Whiteford on 10/9/2023.
//

#include <iostream>
#include "GameObject.h"
#include <vector>
#include <list>
#include <array>
#include <deque>
#include <numeric>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void printInventory(auto inventory) {
    for (const GameObject* item : inventory) {
        cout << item->getDescription();
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    GameObject* A = new GameObject(" A\n");
    GameObject* B = new GameObject(" B\n");
    GameObject* C = new GameObject(" C\n");
    GameObject* D = new GameObject(" D\n");
    
    
    std::cout << "items in inventory Vector:\n";
    std::vector<GameObject*> inventory = {A,B,C,D};
    //call measure time for the printInventory function here
    auto start = steady_clock::now();
    printInventory(inventory);
    auto end = steady_clock::now();
    duration<double> diff = end - start;
    cout << "Time taken: " << diff.count() << " s" << endl;
    
    //inventory 2 using the list (doubly-linked list) data structure
    std::cout << "items in inventory List:\n";
    std::list<GameObject*> inventory2 = {A,B,C,D};
    //call measure time for the printInventory function here
    auto start2 = steady_clock::now();
    printInventory(inventory2);
    auto end2 = steady_clock::now();
    duration<double> diff2 = end2 - start2;
    cout << "Time taken: " << diff2.count() << " s" << endl;
    
    //items in inventory 3 using a fixed array
    std::cout << "items in inventory Array:\n";
    std::array<GameObject*, 4> inventory3 = {A,B,C,D};
    //call measure time for the printInventory function here
    auto start3 = steady_clock::now();
    printInventory(inventory3);
    auto end3 = steady_clock::now();
    duration<double> diff3 = end3 - start3;
    cout << "Time taken: " << diff3.count() << " s" << endl;
    
    std::cout << "items in inventory Deque:\n";
    std::deque<GameObject*> inventory4 = {A,B,C,D};
    //call measure time for the printInventory function here
    auto start4 = steady_clock::now();
    printInventory(inventory3);
    auto end4 = steady_clock::now();
    duration<double> diff4 = end4 - start4;
    cout << "Time taken: " << diff4.count() << " s" << endl;
    
    cout << "ADDITION\n\n";
    
    GameObject* E = new GameObject("E");
    cout << "inventory Vector\n";
    auto start5 = steady_clock::now();
    inventory.push_back(E);
    auto end5 = steady_clock::now();
    duration<double> diff5 = end5 - start5;
    cout << "Time taken: " << diff5.count() << " s" << endl;
    
    cout << "inventory List\n";
    auto start6 = steady_clock::now();
    inventory2.push_back(E);
    auto end6 = steady_clock::now();
    duration<double> diff6 = end6 - start6;
    cout << "Time taken: " << diff6.count() << " s" << endl;
    
    cout << "inventory Array(EXCLUDE)\n";
    auto start7 = steady_clock::now();
    //doesnt actually have the ability to add
    std::array<GameObject*, 5> inventory3A = {A,B,C,D,E};
    auto end7 = steady_clock::now();
    duration<double> diff7 = end7 - start7;
    cout << "Time taken: " << diff7.count() << " s" << endl;
    
    cout << "inventory Deque\n";
    auto start8 = steady_clock::now();
    inventory4.push_back(E);
    auto end8 = steady_clock::now();
    duration<double> diff8 = end8 - start8;
    cout << "Time taken: " << diff8.count() << " s" << endl;
    
    cout << "REMOVAL\n\n";
    
    cout << "inventory Vector\n";
    auto start9 = steady_clock::now();
    inventory.erase(inventory.begin() + 4);
    auto end9 = steady_clock::now();
    duration<double> diff9 = end9 - start9;
    cout << "Time taken: " << diff9.count() << " s" << endl;
    
    cout << "inventory List\n";
    auto start10 = steady_clock::now();
    inventory2.remove(D);
    auto end10 = steady_clock::now();
    duration<double> diff10 = end10 - start10;
    cout << "Time taken: " << diff10.count() << " s" << endl;
    
    cout << "inventory Array(EXCLUDE)\n";
    auto start11 = steady_clock::now();
    std::array<GameObject*, 4> inventory3B = {A,B,C,D};
    auto end11 = steady_clock::now();
    duration<double> diff11 = end11 - start11;
    cout << "Time taken: " << diff11.count() << " s" << endl;
    
    cout << "inventory Deque\n";
    auto start12 = steady_clock::now();
    inventory4.erase(inventory4.begin() + 4);
    auto end12 = steady_clock::now();
    duration<double> diff12 = end12 - start12;
    cout << "Time taken: " << diff12.count() << " s" << endl;
    
    return 0;
}
