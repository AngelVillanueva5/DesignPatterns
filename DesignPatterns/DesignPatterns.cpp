#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

void fileOpen() {
    
}

void fileClose() {
    
}

void fileRead() {
    
}

int main() {
    std::ifstream file;
    std::string fileName = "D:/SchoolPresentaties/GRINDSET/DesignPatterns/circuits/circuit1.txt";
    std::map<std::string, std::string> nodes;
    std::map<std::string, std::vector<std::string>> adjList;

    fileOpen(file, fileName);
    fileRead(file, nodes, adjList);
    fileClose(file);

    // Print the nodes
    std::cout << "Nodes:" << std::endl;
    for (const auto& pair : nodes) {
        std::cout << pair.first << ": " << pair.second << std::endl;
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
