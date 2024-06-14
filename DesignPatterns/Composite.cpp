#include "Composite.h"
#include <algorithm>

Composite::Composite(std::vector<bool> inputs) : Component(inputs) {}

Composite::~Composite() {
    for (Component* child : children) {
        delete child;
    }
}

bool Composite::execute() {
    bool result = true;
    for (ComponentIterator it = this->begin(); it != this->end(); ++it) {
        if (!(*it)->execute()) {
            result = false;
        }
    }
    return result;
}

void Composite::add(Component* com) {
    children.push_back(com);
}

void Composite::remove(Component* com) {
    children.erase(std::remove(children.begin(), children.end(), com), children.end());
}

std::vector<Component*> Composite::getChildren() {
    return children;
}

Component* Composite::clone() const {
    Composite* newComposite = new Composite(this->inputs);
    for (Component* child : children) {
        newComposite->add(child->clone());
    }
    return newComposite;
}

ComponentIterator Composite::begin() {
    return ComponentIterator(children.begin());
}

ComponentIterator Composite::end() {
    return ComponentIterator(children.end());
}
