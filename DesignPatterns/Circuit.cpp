#include "Circuit.h"

Circuit::Circuit() {}

void Circuit::initializeCircuit()
{
	std::map<std::string, std::string> nodes;
	std::map<std::string, std::vector<std::string>> adjList;

	file.fileOpen("D:/SchoolPresentaties/GRINDSET/DesignPatterns/circuits/CIRCUIT3.TXT");

	file.fileRead(nodes, adjList);

	file.fileClose();

	graph.generateNodes(nodes);
	graph.generateEdges(adjList);
}

bool Circuit::checkLoops()
{
	/*std::vector<std::string> insertOrder = file.getInsertOrder();

	for (const std::string& insert : insertOrder)
	{
		std::map<std::string, Component*>::iterator nodeIterator = nodeObjecMap.find(insert);
		std::map<std::string, std::vector<Component*>>::iterator adjecencyIterator = AdjecencyList.find(insert);

		Component* executeComponent = nodeIterator->second;
		std::vector<Component*> edgeVector = adjecencyIterator->second;

		bool executeValue = executeComponent->execute();
		for (std::vector<Component*>::iterator it = edgeVector.begin(); it != edgeVector.end(); ++it)
		{
			(*it)->setInputs(executeValue);
		}
	}*/

	return true;
}

void Circuit::simulateCircuit()
{
	std::vector<std::string> insertOrder = file.getInsertOrder();
	std::map<std::string, Component*> nodeObjecMap;
	std::map<std::string, std::vector<Component*>> AdjecencyList;

	nodeObjecMap = graph.getNodeList();
	AdjecencyList = graph.getAdjecencyList();

	std::map<std::string, std::vector<Component*>>::iterator AdjecencyIterator = AdjecencyList.begin();


	for (const std::string& insert : insertOrder)
	{
		std::map<std::string, Component*>::iterator nodeIterator = nodeObjecMap.find(insert);
		std::map<std::string, std::vector<Component*>>::iterator adjecencyIterator = AdjecencyList.find(insert);

		Component* executeComponent = nodeIterator->second;
		std::vector<Component*> edgeVector = adjecencyIterator->second;

		bool executeValue = executeComponent->execute();
		for (std::vector<Component*>::iterator it = edgeVector.begin(); it != edgeVector.end(); ++it)
		{
			(*it)->setInputs(executeValue);
		}
	}

	// code can be uncommented to test outputs
	std::map<std::string, Component*>::iterator nodeMapIterator1 = nodeObjecMap.find("S");
	Component* component1 = nodeMapIterator1->second;

	bool valueS = component1->execute();

	std::map<std::string, Component*>::iterator nodeMapIterator2 = nodeObjecMap.find("Cout");
	Component* component2 = nodeMapIterator2->second;

	bool valueCout = component2->execute();

	std::cout << "Value S is: " << valueS << std::endl;

	std::cout << "Value Cout is: " << valueCout << std::endl;

	file.fileWrite(valueS, valueCout);
		
}