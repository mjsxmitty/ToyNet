

#ifndef __ESSENTIAL_CPP_STACK_H__
#define __ESSENTIAL_CPP_STACK_H__

#include <vector>
#include <string>

class Stack
{
public:
    //Stack();
    bool    Empty() const { return elems_.empty(); }
    bool    Full() const { return  elems_.size() == elems_.max_size(); }
    int     Size() const { return  elems_.size(); }

    bool    Push(const std::string &elem);
    bool    Pop(std::string &elem);
    bool    Peek(std::string &elem);

    bool    Find(const std::string &elem);
    int     Count(const std::string &elem);
private:
    std::vector<std::string>    elems_;
};

#endif // __ESSENTIAL_CPP_STACK_H__
