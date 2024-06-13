#include "And.h"
And::And(std::vector<bool> inputs) : Component(inputs) {
    if (inputs.size() > 2) {
        std::cout << "too many inputs in and component" << std::endl;
    }
}
And::And(std::vector<bool> inputs, int id) : Component(inputs, id) {
    if (inputs.size() > 2) {
        std::cout << "too many inputs in and component" << std::endl;
    }
}
And::~And() {

}
Component* And::clone() const {
    return new And(*this);
}
bool And::execute() {
    if (inputs.size() < 2) {
        return false;
    }
    return (inputs[0] && inputs[1]);
}