

#ifndef __ESSENTIAL_CPP_STACK_H__
#define __ESSENTIAL_CPP_STACK_H__

#include <vector>
#include <string>
#include <iostream>

namespace ver1
{
class Stack
{
public:
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

extern void FillStack(Stack &stack, std::istream &is = std::cin);

}

namespace ver2
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

inline std::ostream& operator<<(std::ostream &os, const Stack &rhs)
{
    rhs.print(os);
    return os;
}

}

namespace ver3
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


#endif // __ESSENTIAL_CPP_STACK_H__
