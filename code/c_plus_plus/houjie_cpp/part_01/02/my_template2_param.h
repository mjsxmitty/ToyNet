

#ifndef __TEMPLATE_TEMPLATE_PARAM_H__
#define __TEMPLATE_TEMPLATE_PARAM_H__

#include <deque>
#include <list>

template<typename T>
class SmartPtr
{
public:
    T *ptr;
public:
    SmartPtr() : prt(new T){}
};

template<typename T, template<typename U>
                     class SmartPtr
        >
class XCLS
{
private:
    SmartPtr<U> sp;
public:
    XCLS(/* args */) : sp(new U);
};

 XCLS<int, SmartPtr> ccc;

template<typename T, class Sequence = std::deque<T>>
class Stack
{
protected:
    Sequence c;
};

// Stack<int> s1;
// Stack<int, list<int>> s2;
//不属于模板模板参数,因为第一个类型确定之后,第二个随即确定
#endif
