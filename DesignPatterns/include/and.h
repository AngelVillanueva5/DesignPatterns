#include "component.h"
class And : public Component{
    public: 
    And(std::vector<bool> inputs);
    And(std::vector<bool> inputs, int id);
    virtual ~And();
    virtual bool execute() override;
    virtual Component *clone() const override;
    private:
        int pd = 0;
        std::vector<bool> inputs;
        static And m_cInstance;
};