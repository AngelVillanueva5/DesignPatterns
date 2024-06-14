
#include "Probe.h"
Probe::Probe(std::vector<bool> inputs) : Component(inputs) {
    if (inputs.size() > 1) {
        std::cout << "too many inputs in Probe component" << std::endl;
    }
}
Probe::Probe(std::vector<bool> inputs, int id) : Component(inputs, id) {
    if (inputs.size() > 2) {
        std::cout << "too many inputs in Input component" << std::endl;
    }
}
Probe::~Probe() {

}
Component* Probe::clone() const {
    return new Probe(*this);
}
bool Probe::execute() {
    return (!inputs[0]);
}