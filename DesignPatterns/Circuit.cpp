#include "Circuit.h"

Circuit* Circuit::mCircuit = nullptr;

Circuit::Circuit() {}

bool Circuit::initializeCircuit(std::string fileString)
{
	std::map<std::string, std::string> nodes;
	std::map<std::string, std::vector<std::string>> adjList;

	file.fileOpen(fileString);

	file.fileRead(nodes, adjList);

	file.fileClose();

	if (checkLoops(adjList) == false)
	{
		return false;
	}

	if (graph.generateNodes(nodes) == false)
	{
		std::cout << "Exiting due to invalid file" << std::endl;
		return false;
	}

	graph.generateEdges(adjList);

	return true;
}


// Checks for faults in the circuit such as loops
bool Circuit::checkLoops(std::map<std::string, std::vector<std::string>> adjList)
{
	std::vector<std::string> nodeList = file.getInsertOrder();
	std::map<std::string, std::vector<std::string>>::iterator adjListIterator = adjList.begin();
	for (int nodeListIterator = 0; nodeListIterator < nodeList.size(); nodeListIterator++)
	{
		std::map<std::string, std::vector<std::string>>::iterator adjecencyIterator = adjList.find(nodeList[nodeListIterator]);
		std::vector<std::string> test2 = adjecencyIterator->second;

		for (const std::string& edge : test2)
		{
			for (int edgeIterator = 0; edgeIterator < nodeListIterator; edgeIterator++)
			{
				if (nodeList[edgeIterator] == edge)
				{
					std::cout << "faulty circuit" << std::endl;
					return false;
				}
			}
		}
	}

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


// Singleton design pattern
Circuit& Circuit::getInstance()
{
	if (mCircuit == nullptr)
	{
		mCircuit = new Circuit;
	}

	return *mCircuit;
}