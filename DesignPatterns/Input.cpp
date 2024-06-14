#include "Input.h"
Input Input::m_cInstance("INPUT");
Input::Input() : Component() {
    /*if (inputs.size() > 1) {
        std::cout << "too many inputs in Input component" << std::endl;
    }*/
}
Input::Input(std::string id) : Component(id) {

}
Input::~Input() {

}
Component* Input::clone() const {
    return new Input;
}
bool Input::execute() {
    return inputs[0];
}