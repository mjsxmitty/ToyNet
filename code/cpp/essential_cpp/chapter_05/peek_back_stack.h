

#ifndef __ESSENTIAL_CPP_PEEKBACK_STACK_H__
#define __ESSENTIAL_CPP_PEEKBACK_STACK_H__

#include <string>
#include <iostream>
#include <vector>

namespace chapter_05
{
namespace ver2
{

template<typename T>
class Stack
{
public:
    Stack(int capacity = 0) : top_(capacity)
    {
        if (capacity)
            elem_.reserve(capacity);
    }

    ~Stack(){}

    bool pop(T &val);
    bool push(const T &val);
    bool peek(int index, T &val);

    int size() const { return elem_.size();}
    int top() const { return top_; }

    bool empty() const { return elem_.empty(); }
    bool full() const {return size() >= elem_.max_size(); }
    void print(std::ostream &os = std::cout) const;

private:
    std::vector<T> elem_;
    int top_;
};

template<typename T>
bool Stack<T>::pop(T &val)
{
    if (elem_.empty())
        return false;

    val = elem_[top_--];
    return true;
}

template<typename T>
bool Stack<T>::push(const T &val)
{
    if (full())
        return false;

    elem_.push_back(val);
    ++top_;
    return true;
}

template <typename T>
bool Stack<T>::peek(int index, T &val)
{
    if (empty())
        return false;

    if (index < 0 || index >= size())
        return false;

    val = elem_[index];
    return false;
}

template <typename T>
void Stack<T>::print(std::ostream &os) const
{
    for (auto &tmp : elem_)
        os << tmp << " ";

    os << std::endl;

}

}

}

#endif // __ESSENTIAL_CPP_PEEKBACK_STACK_H__
