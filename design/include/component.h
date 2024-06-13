#pragma once
#include <iostream>
#include <vector>
class Component{
    public: 
    Component(std::vector<bool> inputs);
    Component(std::vector<bool> inputs,int id);
    virtual ~Component();
    virtual bool execute() {return false;};
    virtual Component  *clone() const = 0;
    private:
        int pd = 0;
        std::vector<bool> inputs;

};