#include "Or.h"
Or Or::m_cInstance("OR");
Or::Or() : Component() {
    if (inputs.size() > 1) {
        std::cout << "too many inputs in Or component" << std::endl;
    }
}
Or::Or(std::string id) : Component(id) {
    if (inputs.size() > 2) {
        std::cout << "too many inputs in Input component" << std::endl;
    }
}
Or::~Or() {

}
Component* Or::clone() const {
    return new Or;
}
bool Or::execute() {
    return (!inputs[0]);
}