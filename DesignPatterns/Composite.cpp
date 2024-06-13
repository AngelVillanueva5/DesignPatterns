#include "Composite.h"

Composite::Composite(std::vector<bool> inputs) : Component(inputs) {
}

Composite::~Composite() {
    for (Component* child : children) {
        delete child;
    }
}

bool Composite::execute() {
    return false;
}

void Composite::add(Component* com) {
    children.push_back(com);
}

void Composite::remove(Component* com) {
}

std::vector<Component*> Composite::getChildren() {
    return children;
}
