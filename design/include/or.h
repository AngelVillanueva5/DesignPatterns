#include "component.h"
class Or : public Component{
    public: 
    Or(std::vector<bool> inputs);
    virtual ~Or();
    virtual bool execute();
    private:
        int pd = 0;
        std::vector<bool> inputs;

};