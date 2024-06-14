#include "Component.h"
Component::Component() {
}
Component::Component(std::string id) {
}
void Component::setInputs(std::vector<bool> inputs) {
    this->inputs = inputs;
}
Component::~Component() {
}