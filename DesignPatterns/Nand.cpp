#include "Nand.h"
#include <iostream>
Nand Nand::m_cInstance("NAND");
Nand::Nand() : Component()
{

}
Nand::Nand(std::string id) : Component(id)
{
}
Nand::~Nand()
{

}
Component* Nand::clone() const
{
    return new Nand;
}
bool Nand::execute()
{
    std::cout << "NAND execute" << std::endl;
    if (inputs[0] && inputs[1])
    {
        return false;
    }
    else
    {
        return true;
    }
}