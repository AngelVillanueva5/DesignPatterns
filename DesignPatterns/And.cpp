#include "And.h"
#include <iostream>
And And::m_cInstance("AND");
And::And() : Component() {

}
And::And(std::string id) : Component(id) {
}
And::~And() {

}
Component* And::clone() const {
    return new And;
}
bool And::execute() {
    if (inputs.size() < 1)
    {
        return NULL;
    }
    return (inputs[0] && inputs[1]);
}

int And::getInputCount()
{
    return inputs.size();
}

bool And::checkComponent()
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