//
//  main.cpp
//  lab10
//
//  Created by Hayden Flynn Whiteford on 12/9/2023.
//

#include <iostream>
#include <fstream>

class CompoundType {
public:
    char Var1 = 'A';
    int Var2 = 1;
    float Var3 = 3.14;
};

CompoundType* test = new CompoundType();

void printVar(CompoundType* aClass){
    std::cout << aClass->Var1 << "\n";
    std::cout << aClass->Var2 << "\n";
    std::cout << aClass->Var3 << "\n";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    CompoundType* test = new CompoundType();
    printVar(test);
    
    //create file
    //std::ofstream outputFile("test1.bin", std::ios::binary);
    std::ifstream inputFile("test1.bin", std::ios::binary);
    
    //write
    //outputFile.write(reinterpret_cast<char*>(&test->Var1), sizeof(test->Var1));
    //outputFile.write(reinterpret_cast<char*>(&test->Var2), sizeof(test->Var2));
    //outputFile.write(reinterpret_cast<char*>(&test->Var3), sizeof(test->Var3));
    
    //read
    inputFile.read(reinterpret_cast<char*>(&test->Var1), sizeof(test->Var1));
    inputFile.read(reinterpret_cast<char*>(&test->Var2), sizeof(test->Var2));
    inputFile.read(reinterpret_cast<char*>(&test->Var3), sizeof(test->Var3));

    //close
    
    //outputFile.close();
    inputFile.close();
    
    //print the values
    std::cout << "Values after reading from file:\n";
    printVar(test);
    return 0;
}
