#include "Component.h"
class Xor : public Component {
public:
    Xor();
    Xor(std::string id);
    virtual ~Xor();
    virtual bool execute() override;
    virtual Component* clone() const override;
private:
    int pd = 0;
    static Xor m_cInstance;
};