#pragma once
#include <vector>
#include "Component.h"

class Composite : public Component {
public:
    Composite(std::vector<bool> inputs);
    virtual ~Composite();

    virtual bool execute() override;
    void add(Component* com);
    void remove(Component* com);
    std::vector<Component*> getChildren();

private:
    std::vector<Component*> children;
};
