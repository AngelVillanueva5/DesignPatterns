#include "Component.h"
class Probe : public Component {
public:
    Probe();
    Probe(std::string id);
    virtual ~Probe();
    virtual bool execute() override;
    virtual Component* clone() const override;
private:
    int pd = 0;
    static Probe m_cInstance;
};