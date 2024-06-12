#include "component.h"
#include "not.h"
Not::Not(std::vector<bool> inputs) : Component(inputs){
    if(inputs .size() > 1){
        std::cout << "too many inputs in Not component" << std::endl;
    }
}
Not::Not(std::vector<bool> inputs, int id) : Component(inputs, id){
    if(inputs .size() > 2){
        std::cout << "too many inputs in Input component" << std::endl;
    }
}
Component* Not::clone() const {
    return new Not(*this);
}
bool Not::execute(){
    return (!inputs[0]);
}