#pragma once
#include <vector>
#include "Component.h"
#include "Iterator.h"

class Composite : public Component {
public:
    Composite(std::vector<bool> inputs);
    virtual ~Composite();

    virtual bool execute() override;
    void add(Component* com);
    void remove(Component* com);
    std::vector<Component*> getChildren();
    virtual Component* clone() const override;

    ComponentIterator begin();
    ComponentIterator end();

private:
    std::vector<Component*> children;
};
