#include "Xor.h"

Xor Xor::m_cInstance("XOR");
Xor::Xor() : Component()
{

}

Xor::Xor(std::string id) : Component(id)
{

}

Xor::~Xor()
{

}

Component* Xor::clone() const
{
    return new Xor;
}
bool Xor::execute() {
    bool returnState = 0;
    for (int i = 0; i < inputs.size(); i++)
    {
        
        if (inputs[i] == true)
        {
            returnState = !returnState;
        }
    }
    return returnState;
}