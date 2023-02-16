

#ifndef __ESSENTIAL_CPP_CHAPTER_05_LIFO_STACK_H__
#define __ESSENTIAL_CPP_CHAPTER_05_LIFO_STACK_H__

#include <string>
#include <iostream>
#include <vector>

#include "stack_ver1.h"

namespace chapter_05
{

namespace ver1
{

class LifoStack : public Stack
{
public:
    LifoStack(int i = 0) : top_(i)
    {
        if (i)
            elem_.reserve(i);
    }
    virtual ~LifoStack(){}

    virtual bool pop(std::string &val);
    virtual bool push(const std::string &val);
    virtual bool peek(int index, std::string &val);

    virtual int size() const { return elem_.size();};
    virtual int top() const {return top_; };

    virtual bool empty() const {return elem_.empty(); };
    virtual bool full() const {return size() >= elem_.max_size(); };
    virtual void print(std::ostream &os = std::cout) const;

private:
    std::vector<std::string> elem_;
    int top_;
};

}

}

#endif // __ESSENTIAL_CPP_CHAPTER_05_LIFO_STACK_H__
