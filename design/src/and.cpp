#include "and.h"
And::And(std::vector<bool> inputs) : Component(inputs){
    if(inputs .size() > 2){
        std::cout << "too many inputs in and component" << std::endl;
    }
}
bool And::execute(){
    if(inputs.size() < 2){
        return false;
    }
    return (inputs[0] && inputs[1]);
}