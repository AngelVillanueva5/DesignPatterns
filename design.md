 @startuml
interface Component {
  pd : Integer
  returnOutput()
}
class Circuit
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
class Composite {
 input : bool
 output : bool
}
class NodeList
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
Component <|.. Composite
Component <|.. XOR
Component <|.. Probe
Component <|.. NOT
Component <|.. Input
Composite ..> Iterator
NodeList <.. Circuit
Component <.. NodeList
FileManager <.. Circuit
FileManager <.. Probe
@enduml

volgens de leraar zag het er goed uit maar is het nog niet helemaal af, we moeten de factory method nog wat verder uitwerken maar volgens hem kunnen we daar veel design patterns in verwerken zoals een prototype via een clone
