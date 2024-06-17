#include "Nor.h"

Nor Nor::m_cInstance("NOR");
Nor::Nor() : Component()
{

}

Nor::Nor(std::string id) : Component(id)
{

}

Nor::~Nor()
{

}

Component* Nor::clone() const
{
    return new Nor;
}

bool Nor::execute()
{
    for (int i = 0; i < inputs.size(); i++)
    {
        if (inputs[i] == true)
        {
            return false;
        }
    }
    return true;
}

bool Nor::checkComponent()
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