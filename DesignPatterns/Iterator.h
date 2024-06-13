#include "component.h"
class ComponentIterator {
public:
    ComponentIterator();
    virtual ~ComponentIterator();
    virtual Component getNext();
    virtual bool hasMore();
private:
    std::vector<Component> cache;
    int currentPos = 0;

};