#pragma once

#include "FileRead.h"
#include "GraphGenerator.h"

class Circuit
{
public:
	Circuit();
	
	bool initializeCircuit(std::string file);
	void simulateCircuit();
	bool checkLoops(std::map<std::string, std::vector<std::string>> adjList);

	static Circuit& getInstance();
private:
	FileRead file;
	GraphGenerator graph;
	static Circuit* mCircuit;
};
