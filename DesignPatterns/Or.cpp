#include "Or.h"
Or::Or(std::vector<bool> inputs) : Component(inputs) {
    if (inputs.size() > 1) {
        std::cout << "too many inputs in Or component" << std::endl;
    }
}
Or::Or(std::vector<bool> inputs, int id) : Component(inputs, id) {
    if (inputs.size() > 2) {
        std::cout << "too many inputs in Input component" << std::endl;
    }
}
Or::~Or() {

}
Component* Or::clone() const {
    return new Or(*this);
}
bool Or::execute() {
    return (!inputs[0]);
}