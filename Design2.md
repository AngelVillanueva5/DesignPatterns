@startuml

interface Component {
- int pd
- vector<bool> inputs
--
+ Component()
+ Component(string id);
+ virtual ~Component();
+ virtual execute() : bool
+ virtual clone() : Component*
+ virtual  setInputs(bool input) : void
}

'GATES

class AND {

}

class NAND {

}

class OR {

}

class NOR {

}

class XOR {

}


class NOT {

}

class Factory {
 - assign(const ID&, const Class*) : void
 - getMap() : FactoryMap&
 --
 + create(const ID&) : Class* 
}

class GraphGenerator {
- nodeObjecMap : map<string, Component*> 
- AdjecencyList : map<string, vector<Component*>> 
--
+ generateGraph() : void
+ generateNodes(map<string, string>& nodes) : void
+ generateEdges(map<string, vector<string>> edgeList) : void
+ getAdjecencyList() : map<string, vector<Component*>>
+ getNodeList() : map<string, Component*>
}

class Circuit {
     - FileRead file;
 - GraphGenerator graph;
 - static Circuit* mCircuit;
 --
 + initializeCircuit(string file) : void
 + simulateCircuit() : void
 + checkLoops() : bool
}

class FileRead {
 - ifstream _file;
 - vector<string> insertOrder;
 --
+ fileOpen(const string& fileName) : void
+ fileClose() : void
+ fileRead(map<string, string>& nodes, map<string, vector<string>>& adjList) : void
+ fileWrite(bool S, bool Cout) : void
+ getInsertOrder() : vector<string>
}

class Main {

}

AND --|> Component
NAND --|> Component
OR --|> Component
NOR --|> Component
XOR --|> Component
NOT --|> Component

Factory --> Component
Factory --> GraphGenerator

GraphGenerator --> Component
Circuit --> GraphGenerator
Circuit --> FileRead

Main --> Circuit



@enduml

