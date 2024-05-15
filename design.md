@startuml
interface Component {
  pd : Integer
  returnOutput()
}
class Simulator
class AND {
AND(input1, input2)
input1 : bool
input2 : bool
output : bool
}
class OR {
OR(input1, input2)
input1 : bool
input2 : bool
output : bool
}
class NOT {
NOT(input1)
input1 : bool
output : bool
}
class Node
class Circuit {
 input : bool
 output : bool
}
class NodeList
class Converter
class XOR {
XOR(input1, input2)
input1 : bool
input2 : bool
output : bool
}
class Probe {
output : bool
}
class Input {
Value : bool
}
class FileManager
class Iterator

Component <|.. AND
Component <|.. OR
Component <|.. Circuit
Component <|.. XOR
Component <|.. Probe
Component <|.. NOT
Component <|.. Input
Circuit ..> Iterator
Simulator ..> Component
Component ..> Simulator
FileManager <.. Converter
Simulator ..> Converter
NodeList <.. Converter
FileManager <.. Probe
Node <.. NodeList
@enduml
