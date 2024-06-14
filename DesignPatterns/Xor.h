#include "Component.h"
class Xor : public Component {
public:
    Xor(std::vector<bool> inputs);
    Xor(std::vector<bool> inputs, int id);
    virtual ~Xor();
    virtual bool execute() override;
    virtual Component* clone() const override;
private:
    int pd = 0;
    static Xor m_cInstance;
};