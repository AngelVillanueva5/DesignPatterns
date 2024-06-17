#include "GraphGenerator.h"

#include "FactoryMethod.h"

GraphGenerator::GraphGenerator() {}

void GraphGenerator::generateGraph() 
{

}


// Generate map of nodes
bool GraphGenerator::generateNodes(std::map<std::string, std::string>& nodeStringMap)
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
		try
		{
			if (component == nullptr)
			{
				throw nodeIterator->first;
			}
		}
		catch (std::string nodeName)
		{
			std::cout << "Node " << nodeName << " undefined or invalid, please correct the inserted circuit" << std::endl;
			return false;
		}

		nodeObjecMap.insert(std::make_pair(nodeIterator->first, component));
		nodeIterator++;
	}
}


// generate map with edges
bool GraphGenerator::generateEdges(std::map<std::string, std::vector<std::string>> edgeStringMap)
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
		if (component.size() <= 0)
		{
			std::cout << nodeName << "edge invalid" << std::endl;
			return false;
		}
		AdjecencyList.insert(std::make_pair(nodeName, component));
		edgeStringIterator++;
	}
	return true;
}


std::map<std::string, std::vector<Component*>> GraphGenerator::getAdjecencyList()
{
	return AdjecencyList;
}

std::map<std::string, Component*> GraphGenerator::getNodeList()
{
	return nodeObjecMap;
}