#include "component.h"
class Probe : public Component{
    public: 
    Probe(std::vector<bool> inputs);
    virtual ~Probe();
    virtual bool execute() override;
    private:
        int pd = 0;
        std::vector<bool> inputs;

};