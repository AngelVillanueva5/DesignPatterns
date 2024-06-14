
#include "Xor.h"
Xor::Xor(std::vector<bool> inputs) : Component(inputs) {
    if (inputs.size() > 1) {
        std::cout << "too many inputs in Xor component" << std::endl;
    }
}
Xor::Xor(std::vector<bool> inputs, int id) : Component(inputs, id) {
    if (inputs.size() > 2) {
        std::cout << "too many inputs in Input component" << std::endl;
    }
}
Xor::~Xor() {

}
Component* Xor::clone() const {
    return new Xor(*this);
}
bool Xor::execute() {
    return (!inputs[0]);
}