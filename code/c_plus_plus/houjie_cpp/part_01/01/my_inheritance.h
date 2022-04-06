

#ifndef __MY_INHERITANCE_H__
#define __MY_INHERITANCE_H__

#include <iostream>


struct ListNodeBase
{
    ListNodeBase    *m_next;
    ListNodeBase    *m_prev;
};


template <typename T>
struct ListNode : public ListNodeBase
{
    T m_data;
};

class Object
{
public:
    Object(){ std::cout << "object construct func start." << std::endl; }
    ~Object() { std::cout << "object disstruct func start." << std::endl;}
};

class Base
{
private:
    //Object obj;
public:
    Base(){ std::cout << "base construct func start." << std::endl; }
    ~Base(){ std::cout << "base disstruct func start." << std::endl;}
};


class Children : public Base
{
private:
    Object obj;
public:
    Children () { std::cout << "children construct func start." << std::endl; }
    ~Children () { std::cout << "children disstruct func start." << std::endl;}
};



#endif
