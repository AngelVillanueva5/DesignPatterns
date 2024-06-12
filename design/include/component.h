#include <iostream>
#include <vector>
class Component{
    public: 
    Component(std::vector<bool> inputs);
    virtual ~Component();
    virtual bool execute() = 0;
    private:
        int pd = 0;
        std::vector<bool> inputs;

};