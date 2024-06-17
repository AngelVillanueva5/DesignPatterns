#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>


class FileRead {
public:
	FileRead();
	~FileRead();

	void fileOpen(const std::string& fileName);
	void fileClose();
	void fileRead(std::map<std::string, std::string>& nodes, std::map<std::string, std::vector<std::string>>& adjList);

	void fileWrite(bool S, bool Cout);
	std::vector<std::string> getInsertOrder();

private:
	std::ifstream _file;
	std::vector<std::string> insertOrder;
	
};
