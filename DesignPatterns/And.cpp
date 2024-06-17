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
    return (inputs[0] && inputs[1]);
}