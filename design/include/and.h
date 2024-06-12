#include "component.h"
class And : public Component{
    public: 
    And(std::vector<bool> inputs);
    virtual ~And();
    virtual bool execute() override;
    private:
        int pd = 0;
        std::vector<bool> inputs;

};