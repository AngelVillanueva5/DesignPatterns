#pragma once
#include <map>
#include <string>
#include "Component.h"
class GraphGenerator 
{
public:

	GraphGenerator();

	void generateGraph();
	void generateNodes(std::map<std::string, std::string>& nodes);
	void generateEdges(std::map<std::string, std::vector<std::string>> edgeList);

	void executeAdjList();

	std::map<std::string, std::vector<Component*>> getAdjecencyList();
	std::map<std::string, Component*> getNodeList();
private:
	std::map<std::string, Component*> nodeObjecMap;
	std::map<std::string, std::vector<Component*>> AdjecencyList;

};