#include "Component.h"
class Input : public Component {
public:
    Input(std::vector<bool> inputs);
    Input(std::vector<bool> inputs, int id);
    virtual ~Input();
    virtual bool execute() override;
    virtual Component* clone() const override;
private:
    int pd = 0;
    static Input m_cInstance;
};