#include "component.h"
class ComponentIterator{
    public:
    ComponentIterator();
    virtual ~ComponentIterator();
    virtual Component getNext();
    virtual bool hasMore();
};