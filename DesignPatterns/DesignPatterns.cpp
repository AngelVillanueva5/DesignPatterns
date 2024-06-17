// DesignPatterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Circuit.h"
#include <filesystem>
#include <string>
#include <iostream>

int main(int argc, const char* argv[])
{
    //std::string argPath = argv[1];
	std::string argPath = "D:/SchoolPresentaties/GRINDSET/DesignPatterns/circuits/circuit4.txt";
	Circuit& circuit = Circuit::getInstance();
	if (circuit.initializeCircuit(argPath) == false)
	{
		return -1;
	}

	if (circuit.simulateCircuit() == false)
	{
		return -1;
	}

	circuit.writeResult();
	

	delete& Circuit::getInstance();
}

