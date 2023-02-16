

#ifndef __ESSENTIAL_CPP_CHAPTER_05_STACK_VER1_H__
#define __ESSENTIAL_CPP_CHAPTER_05_STACK_VER1_H__

#include <string>
#include <iostream>

namespace chapter_05
{

namespace ver1
{

class Stack
{
public:
    virtual ~Stack(){}

    virtual bool pop(std::string &val) = 0;
    virtual bool push(const std::string &val) = 0;
    virtual bool peek(int index, std::string &val) = 0;

    virtual int size() const = 0;
    virtual int top() const = 0;

    virtual bool empty() const = 0;
    virtual bool full() const = 0;
    virtual void print(std::ostream &os = std::cout) const = 0;
};

std::ostream& operator<<(std::ostream &os, const Stack &rhs);

}

}


#endif // __ESSENTIAL_CPP_CHAPTER_05_STACK_VER1_H__
