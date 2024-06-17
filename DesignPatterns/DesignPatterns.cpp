// DesignPatterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Circuit.h"
#include <filesystem>
#include <string>
#include <iostream>

int main(int argc, const char* argv[])
{
    //std::string argPath = argv[1];
	std::string argPath = "D:/SchoolPresentaties/GRINDSET/DesignPatterns/circuits/circuitTest.txt";
	Circuit& circuit = Circuit::getInstance();
	if (circuit.initializeCircuit(argPath) == false)
	{
		return -1;
	}

	circuit.simulateCircuit();
	

	delete& Circuit::getInstance();
}

