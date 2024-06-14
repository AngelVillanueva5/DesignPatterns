#include "And.h"
#include <iostream>
And And::m_cInstance("AND");
And::And() : Component() {

}
And::And(std::string id) : Component(id) {
}
And::~And() {

}
Component* And::clone() const {
    return new And;
}
bool And::execute() {
    std::cout << "and execute" << std::endl;
    if (inputs.size() < 2) {
        return false;
    }
   
    return (inputs[0] && inputs[1]);
}