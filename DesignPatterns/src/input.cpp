#include "component.h"
#include "input.h"
Input::Input(std::vector<bool> inputs) : Component(inputs){
    if(inputs .size() > 1){
        std::cout << "too many inputs in Input component" << std::endl;
    }
}
Input::Input(std::vector<bool> inputs, int id) : Component(inputs, id){
    if(inputs .size() > 2){
        std::cout << "too many inputs in Input component" << std::endl;
    }
}
Input::~Input(){
    
}
Component* Input::clone() const {
    return new Input(*this);
}
bool Input::execute(){
    return inputs[0];
}