#include "Iterator.h"

ComponentIterator::ComponentIterator(std::vector<Component*>::iterator it) : current(it) {}

ComponentIterator& ComponentIterator::operator++() {
    ++current;
    return *this;
}

Component* ComponentIterator::operator*() const {
    return *current;
}

bool ComponentIterator::operator!=(const ComponentIterator& other) const {
    return current != other.current;
}

