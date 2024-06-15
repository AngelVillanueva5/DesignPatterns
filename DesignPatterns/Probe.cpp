
#include "Probe.h"
Probe Probe::m_cInstance("PROBE");
Probe::Probe() : Component() {
    if (inputs.size() > 1) {
        std::cout << "too many inputs in Probe component" << std::endl;
    }
}
Probe::Probe(std::string id) : Component(id) {
    if (inputs.size() > 2) {
        std::cout << "too many inputs in Input component" << std::endl;
    }
}
Probe::~Probe() {

}
Component* Probe::clone() const {
    return new Probe;
}
bool Probe::execute() {
    return (inputs[0]);
}