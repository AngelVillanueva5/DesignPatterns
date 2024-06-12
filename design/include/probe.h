#include "component.h"
class Probe : public Component{
    public: 
    Probe(std::vector<bool> inputs);
    Probe(std::vector<bool> inputs, int id);
    virtual ~Probe();
    virtual bool execute() override;
    virtual Component *clone() const override;
    private:
        int pd = 0;
        std::vector<bool> inputs;
        static Probe m_cInstance;
};