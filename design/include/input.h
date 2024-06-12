#include "component.h"
class Input : public Component{
    public: 
    Input(std::vector<bool> inputs);
    virtual ~Input();
    virtual bool execute() override;
    private:
        int pd = 0;
        std::vector<bool> inputs;

};