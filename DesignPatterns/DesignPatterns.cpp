// DesignPatterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

    // Print the adjacency list
    std::cout << "\nAdjacency List:" << std::endl;
    for (const auto& pair : adjList) {
        std::cout << pair.first << ": ";
        for (const auto& adj : pair.second) {
            std::cout << adj << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
