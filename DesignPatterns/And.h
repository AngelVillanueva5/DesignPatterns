#pragma once
#include "Component.h"
class And : public Component {
public:
    And();
    And(std::string id);
    virtual ~And();
    virtual bool execute() override;
    virtual Component* clone() const override;
    virtual bool checkComponent() override;
    int getInputCount();
private:
    int pd = 0;
    static And m_cInstance;
};