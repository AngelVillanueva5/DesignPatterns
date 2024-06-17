#pragma once
#include "Component.h"
class Nor : public Component
{
public:
    Nor();
    Nor(std::string id);
    virtual ~Nor();
    virtual bool execute() override;
    virtual Component* clone() const override;
private:
    int pd = 0;
    static Nor m_cInstance;
};