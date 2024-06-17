#pragma once
#include "Component.h"
class Nand : public Component
{
public:
    Nand();
    Nand(std::string id);
    virtual ~Nand();
    virtual bool execute() override;
    virtual Component* clone() const override;
    virtual bool checkComponent() override;
private:
    int pd = 0;
    static Nand m_cInstance;
};