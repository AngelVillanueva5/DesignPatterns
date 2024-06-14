#include "component.h"
Component::Component(std::vector<bool> inputs){
    this->inputs = inputs;
}
Component::Component(std::vector<bool> inputs,int id){
    this->inputs = inputs;
}
Component::~Component(){
}