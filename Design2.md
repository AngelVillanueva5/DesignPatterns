@startuml

interface Component {

}

'GATES

class AND {

}

class OR {

}

class NOT {

}

class Composite {

}

class Factory {

}

AND --|> Component
OR --|> Component
NOT --|> Component
Composite --|> Component

Factory --> Component

@enduml

