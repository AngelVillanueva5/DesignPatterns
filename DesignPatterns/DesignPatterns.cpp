// DesignPatterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Composite.h"
#include "And.h"
int main()
{   
    And* and1 = new And({ false,true });
    And* and2 = new And({ true,true });
    And* and3 = new And({ true,true });
    Composite* root = new Composite({ true,true });
    root->add(and1);
    root->add(and2);
    root->add(and3);
    std::cout << root->execute() << std::endl;
    root->remove(and1);
    std::cout << root->execute() << std::endl;
    root->getChildren();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
