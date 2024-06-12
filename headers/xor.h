#include "component.h"
class Xor : public Component{
    public: 
    Xor(std::vector<bool> inputs);
    virtual ~Xor();
    virtual bool execute() override;
    private:
        int pd = 0;
        std::vector<bool> inputs;

};