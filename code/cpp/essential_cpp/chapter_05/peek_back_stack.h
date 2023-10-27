

#ifndef __ESSENTIAL_CPP_CHAPTER_05_PEEK_BACK_STACK_H__
#define __ESSENTIAL_CPP_CHAPTER_05_PEEK_BACK_STACK_H__

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
    virtual ~Stack(){}

    virtual bool pop(T &val);
    virtual bool push(const T &val);
    virtual bool peek(int index, T &val);

    virtual int size() const { return elem_.size();}
    virtual int top() const { return top_; }

    virtual bool empty() const { return elem_.empty(); }
    virtual bool full() const {return size() >= elem_.max_size(); }
    virtual void print(std::ostream &os = std::cout) const;

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

#endif // __ESSENTIAL_CPP_CHAPTER_05_PEEK_BACK_STACK_H__
