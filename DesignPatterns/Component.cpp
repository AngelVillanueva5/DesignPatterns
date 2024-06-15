#include "Component.h"
#include "FactoryMethod.h"
Component::Component() {
}
Component::Component(std::string id) {
    Factory::FactoryMethod<std::string, Component>::assign(id, this);
}
void Component::setInputs(bool input) {
    this->inputs.push_back(input);
}
Component::~Component() {
}