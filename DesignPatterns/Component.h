#pragma once
#include <iostream>
#include <vector>
class Component {
public:
    Component();
    Component(std::string id);
    virtual ~Component();
    virtual bool execute() { return false; };
    virtual Component* clone() const = 0;
    virtual void setInputs(std::vector<bool> inputs);
protected:
    int pd = 0;
    std::vector<bool> inputs;

};