#include "Not.h"
Not Not::m_cInstance("NOT");
Not::Not() : Component() {
    if (inputs.size() > 1) {
        std::cout << "too many inputs in Not component" << std::endl;
    }
}
Not::Not(std::string id) : Component(id) {
    if (inputs.size() > 2) {
        std::cout << "too many inputs in Input component" << std::endl;
    }
}
Not::~Not() {

}
Component* Not::clone() const {
    return new Not;
}
bool Not::execute() {
    return (!inputs[0]);
}

bool Not::checkComponent()
{
    if (inputs.size() < 1)
    {
        return false;

    }
    else
    {
        return true;
    }
}