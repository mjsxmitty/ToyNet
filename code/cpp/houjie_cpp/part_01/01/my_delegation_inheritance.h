

#ifndef __MY_DELEGATION_INHERITANCE_H__
#define __MY_DELEGATION_INHERITANCE_H__

#include <vector>

class Component
{
private:
    int     value_;
public:
    Component(int val) { value_ = val; }
    //~Component();

    virtual void Add(Component *){}
};


class Primitive : public Component
{
public:
    Primitive(int val) : Component (val) {}
    //~Primitive();
};


class Composite : public Component
{
private:
    std::vector<Component*> c;
public:
    Composite(int val) : Component(val) {}
    //~Composite();

    void Add(Component *item) {
        c.push_back(item);
    }
};




#endif
