// DesignPatterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "FileRead.h"

int main()
{
    std::map<std::string, std::string> nodes;
    std::map<std::string, std::vector<std::string>> adjList;

    FileRead fileread;

    fileread.fileOpen("D:/SchoolPresentaties/GRINDSET/DesignPatterns/circuits/circuit1.txt");

    fileread.fileRead(nodes, adjList);

    fileread.fileClose();
}

