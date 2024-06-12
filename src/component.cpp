#include <vector>
class Component{
    public: 
    Component(std::vector inputs);
    virtual ~component();
    virtual std::vector output();
    private:
        int pd = 0;

}