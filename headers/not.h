#include "component.h"
class Not : public Component{
    public: 
    Not(std::vector<bool> inputs);
    virtual ~Not();
    virtual bool execute() override;
    private:
        int pd = 0;
        std::vector<bool> inputs;

};