#pragma once
#include "Component.h"
class And : public Component {
public:
    And(std::vector<bool> inputs);
    And(std::vector<bool> inputs, int id);
    virtual ~And();
    virtual bool execute() override;
    virtual Component* clone() const override;
private:
    int pd = 0;
    static And m_cInstance;
};