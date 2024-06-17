#pragma once

#include "FileRead.h"
#include "GraphGenerator.h"

class Circuit
{
public:
	Circuit();
	
	void initializeCircuit();
	void simulateCircuit();
	bool checkLoops();
private:
	FileRead file;
	GraphGenerator graph;

};
