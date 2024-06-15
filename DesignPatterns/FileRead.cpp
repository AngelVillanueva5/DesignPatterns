#include "FileRead.h"
#include <cstdio>

FileRead::FileRead()
{

}

FileRead::~FileRead()
{

}

void FileRead::fileOpen(const std::string& fileName)
{
	_file.open(fileName);
	if (!_file.is_open()) {
		std::cerr << "Error opening file: " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}
}

void FileRead::fileClose()
{
	if (_file.is_open()) {
		_file.close();
	}
}

void FileRead::fileRead(std::map<std::string, std::string>& nodes,
	std::map<std::string, std::vector<std::string>>& adjList)
{
	std::string line;
	bool readNodes = false;
	bool readEdges = false;

	while (std::getline(_file, line)) {
		if (line.find("# Description of all the nodes") != std::string::npos)
		{
			readNodes = true;
			readEdges = false;
			continue;
		}

		if (line.find("# Description of all the edges") != std::string::npos) {
			readNodes = false;
			readEdges = true;
			continue;
		}

		if (readNodes) {
			if (line.empty() || line[0] == '#') continue;
			std::istringstream iss(line);
			std::string key, value;
			if (std::getline(iss, key, ':') && std::getline(iss, value, ';')) {
				key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
				value.erase(remove_if(value.begin(), value.end(), ::isspace), value.end());
				nodes[key] = value;
			}
		}
		if (readEdges) {
			if (line.empty() || line[0] == '#') continue;
			std::istringstream iss(line);
			std::string key, values;
			if (std::getline(iss, key, ':') && std::getline(iss, values, ';')) {
				key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
				values.erase(remove_if(values.begin(), values.end(), ::isspace), values.end());
				std::istringstream valuesStream(values);
				std::string value;
				while (std::getline(valuesStream, value, ',')) {
					value.erase(remove_if(value.begin(), value.end(), ::isspace), value.end());
					adjList[key].push_back(value);
				}
			}
		}
	}
	

}


