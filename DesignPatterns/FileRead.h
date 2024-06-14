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

	void fileOpen(std::ifstream& file, const std::string& fileName);
	void fileClose(std::ifstream& file);
	void fileRead(std::ifstream& file, std::map<std::string, std::string>& nodes, std::map<std::string, std::vector<std::string>>& adjList);
private:
	
	
};
