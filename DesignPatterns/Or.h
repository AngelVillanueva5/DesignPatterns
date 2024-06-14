#include "Component.h"
class Or : public Component {
public:
    Or(std::vector<bool> inputs);
    Or(std::vector<bool> inputs, int id);
    virtual ~Or();
    virtual bool execute() override;
    virtual Component* clone() const override;
private:
    int pd = 0;
    std::vector<bool> inputs;
    static Or m_cInstance;
};