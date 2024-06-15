#include "GraphGenerator.h"

#include "FactoryMethod.h"
#include "FileRead.h"
#include "Component.h"

GraphGenerator::GraphGenerator() {}

void GraphGenerator::generateGraph() 
{
	std::map<std::string, std::string> nodes;
	std::map<std::string, std::vector<std::string>> adjList;
	FileRead file;

	file.fileOpen("D:/SchoolPresentaties/GRINDSET/DesignPatterns/circuits/circuit1.txt");

	file.fileRead(nodes, adjList);

	file.fileClose();

	// Print the adjacency list
	std::cout << "\nAdjacency List:" << std::endl;
	for (const auto& pair : adjList)
	{
		std::cout << pair.first << ": ";
		for (const auto& adj : pair.second)
		{
			std::cout << adj << " ";
		}
		std::cout << std::endl;
	}

	generateNodes(nodes);

	generateEdges(adjList);

	executeAdjList();

}


// GENERATE LIST OF EXISTING NODES
void GraphGenerator::generateNodes(std::map<std::string, std::string>& nodeStringMap)
{

	std::map<std::string, std::string>::iterator nodeIterator = nodeStringMap.begin();

	while (nodeIterator != nodeStringMap.end())
	{
		std::string gateType = nodeIterator->second;
		
		if (gateType == "INPUT_HIGH")
		{
			gateType = "INPUT";
			Component* component = Factory::FactoryMethod<std::string, Component>::create(gateType);
			
			component->setInputs(true);
			nodeObjecMap.insert(std::make_pair(nodeIterator->first, component));
			nodeIterator++;
			continue;
		}
		else if (gateType == "INPUT_LOW")
		{
			gateType = "INPUT";
			Component* component = Factory::FactoryMethod<std::string, Component>::create(gateType);
			component->setInputs(false);
			nodeObjecMap.insert(std::make_pair(nodeIterator->first, component));
			nodeIterator++;
			continue;
		}

		Component* component = Factory::FactoryMethod<std::string, Component>::create(gateType);
		nodeObjecMap.insert(std::make_pair(nodeIterator->first, component));
		nodeIterator++;
	}


}


// CONNECT EDGES OF NODES
void GraphGenerator::generateEdges(std::map<std::string, std::vector<std::string>> edgeStringMap)
{
	
	std::map<std::string, std::vector<std::string>>::iterator edgeStringIterator = edgeStringMap.begin();

	while (edgeStringIterator != edgeStringMap.end())
	{
		std::vector<Component*> component;

		std::string nodeName = edgeStringIterator->first;

		std::vector<std::string> edges = edgeStringIterator->second;

		std::map<std::string, Component*>::iterator nodeMapIterator2 = nodeObjecMap.find(nodeName);
		std::cout << "Edges are: " << std::endl;
		for (const std::string& edge : edges)
		{
			std::map<std::string, Component*>::iterator nodeMapIterator = nodeObjecMap.find(edge);
			std::cout << edge << std::endl;

			component.push_back(nodeMapIterator->second);
			

		}

		AdjecencyList.insert(std::make_pair(nodeName, component));
		edgeStringIterator++;
	}
}


// TEMPORARY EXECUTE CIRCUIT FUNCTION
void GraphGenerator::executeAdjList()
{
	std::map<std::string, std::vector<Component*>>::iterator AdjecencyIterator = AdjecencyList.begin();

	while (AdjecencyIterator != AdjecencyList.end())
	{
		
		std::string nodeName = AdjecencyIterator->first;
		std::map<std::string, Component*>::iterator nodeMapIterator = nodeObjecMap.find(nodeName);
		Component* comptest = nodeMapIterator->second;
		bool executeValue = comptest->execute();
		std::vector<Component*> edgeVector = AdjecencyIterator->second;
		std::vector<std::string> it;
		for (std::vector<Component*>::iterator it = edgeVector.begin(); it != edgeVector.end(); ++it)
		{
			(*it)->setInputs(executeValue);
		}
		AdjecencyIterator++;
	}


	// code can be uncommented to test outputs
	/*std::map<std::string, Component*>::iterator nodeMapIterator1 = nodeObjecMap.find("S");
	Component* component1 = nodeMapIterator1->second;

	bool valueS = component1->execute();

	std::map<std::string, Component*>::iterator nodeMapIterator2 = nodeObjecMap.find("Cout");
	Component* component2 = nodeMapIterator2->second;

	bool valueCout = component2->execute();

	std::cout << "Value S is: " << valueS << std::endl;

	std::cout << "Value Cout is: " << valueCout << std::endl;*/

}