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

	bool checkInserts(std::map<std::string, std::string>& nodes);

	void fileWrite(std::map<std::string, bool>);
	std::vector<std::string> getInsertOrder();
	std::vector<std::string> getProbes();

private:
	std::ifstream _file;
	std::vector<std::string> insertOrder;
	std::vector<std::string> probes;
	
};
