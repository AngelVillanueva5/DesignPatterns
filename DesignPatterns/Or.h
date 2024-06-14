#include "Component.h"
class Or : public Component {
public:
    Or();
    Or(std::string id);
    virtual ~Or();
    virtual bool execute() override;
    virtual Component* clone() const override;
private:
    int pd = 0;
    static Or m_cInstance;
};