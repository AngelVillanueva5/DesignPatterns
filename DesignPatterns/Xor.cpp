
#include "Xor.h"
Xor Xor::m_cInstance("XOR");
Xor::Xor() : Component() {
    if (inputs.size() > 1) {
        std::cout << "too many inputs in Xor component" << std::endl;
    }
}
Xor::Xor(std::string id) : Component(id) {
    if (inputs.size() > 2) {
        std::cout << "too many inputs in Input component" << std::endl;
    }
}
Xor::~Xor() {

}
Component* Xor::clone() const {
    return new Xor;
}
bool Xor::execute() {
    return (!inputs[0]);
}