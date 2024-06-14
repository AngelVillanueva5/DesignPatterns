#include "Component.h"
class Not : public Component {
public:
    Not();
    Not(std::string id);
    virtual ~Not();
    virtual bool execute() override;
    virtual Component* clone() const override;
private:
    int pd = 0;
    static Not m_cInstance;
};