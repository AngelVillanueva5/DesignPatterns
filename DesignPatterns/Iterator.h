#pragma once
#include <vector>
#include "Component.h"

class ComponentIterator {
public:
    ComponentIterator(std::vector<Component*>::iterator it);

    ComponentIterator& operator++();
    Component* operator*() const;
    bool operator!=(const ComponentIterator& other) const;

private:
    std::vector<Component*>::iterator current;
};
