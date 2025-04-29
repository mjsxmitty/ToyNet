
#ifndef __ESSENTIAL_CPP_LIFO_STACK_H__
#define __ESSENTIAL_CPP_LIFO_STACK_H__

#include <string>
#include <iostream>
#include <vector>

#include "stack.h"

namespace ver2
{

class LifoStack : public Stack
{
public:
    LifoStack(int i = 0) : top_(i)
    {
        if (i)
            elem_.reserve(i);
    }

    ~LifoStack(){}

    bool pop(std::string &val);
    bool push(const std::string &val);
    bool peek(int index, std::string &val);

    int size() const { return elem_.size();};
    int top() const {return top_; };

    bool empty() const {return elem_.empty(); };
    bool full() const {return size() >= (int)elem_.max_size(); };
    void print(std::ostream &os = std::cout) const;

private:
    std::vector<std::string> elem_;
    int top_;
};

}

#endif // __ESSENTIAL_CPP_LIFO_STACK_H__
