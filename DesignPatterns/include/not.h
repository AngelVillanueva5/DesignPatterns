#include "component.h"
class Not : public Component{
    public: 
    Not(std::vector<bool> inputs);
    Not(std::vector<bool> inputs, int id);
    virtual ~Not();
    virtual bool execute() override;
    virtual Component *clone() const override;
    private:
        int pd = 0;
        std::vector<bool> inputs;
        static Not m_cInstance;
};