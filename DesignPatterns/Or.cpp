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
    for (int i = 0; i < inputs.size(); i++)
    {
        if (inputs[i] == true)
        {
            return true;
        }
    }
    return false;
}

bool Or::checkComponent()
{
    if (inputs.size() < 2)
    {
        return false;
    }
    else
    {
        return true;
    }
}