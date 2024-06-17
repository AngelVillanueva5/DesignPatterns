#pragma once
#include <iostream>
#include <vector>
class Component {
public:
    Component();
    Component(std::string id);
    virtual ~Component();
    virtual bool execute() { return false; };
    virtual Component* clone() const = 0;
    virtual void setInputs(bool input);

    void subscribe(Component* observer);
    void unsubscribe(Component* observer);

    void addSubject(Component* subject);
    void removeSubject(Component* subject);

    void notify();


    virtual void update();

protected:
    int pd = 0;
    std::vector<bool> inputs;
    std::vector<Component*> observers;
    std::vector<Component*> subjects;

};