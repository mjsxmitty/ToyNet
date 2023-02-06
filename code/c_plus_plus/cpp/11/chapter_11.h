
#ifndef __CPP_CHAPETR_11_HPP__
#define __CPP_CHAPETR_11_HPP__

#include <iostream>
#include <stdio.h>
#include <functional>
#include <vector>

using namespace std;

namespace chapter_11
{

int FuncHello(int a, int b);

// auto Lambda = [](int a, int b) -> int
// {
//     printf("Lambda->param: %d, %d\n", a, b);
//     return a + b;
// };

class Hello
{
public:
    int hello(int a, int b)
    {
        printf("Hello::hello()->param: %d, %d\n", a, b);
        return a + b;
    }

    static int StaticHello(int a, int b)
    {
        printf("Hello::StaticHello->param: %d, %d\n", a, b);
        return a + b;
    }
};

class OperatorHello
{
public:
    int operator()(int a, int b)
    {
        printf("operator->param: %d, %d\n", a, b);
        return a + b;
    }
};

int FuncHello1(int a, int b, int c);
//int (*FunctionPtr)(int i, int j);

template <typename T>
T FuncTemplate(T a, T b)
{
    printf("template func param: %d, %d\n", a, b);
    return a + b;
}

void Call(function<int(int, int)> func);

void Test1();
void Test2();

void Test3();

template<typename RetType, typename ... Args>
class DelegateBase
{
public:
    virtual RetType Excute(Args &&... args)
    {
        return RetType();
    }
};

/* 对象代理 */
template<typename ObjectType, typename RetType, typename ... Args>
class ObjectDelegate : public DelegateBase<RetType, Args ...>
{
public:
    ObjectDelegate(ObjectType *in_ptr, RetType (ObjectType::*in_func_ptr)(Args ...))
        : ptr_(in_ptr), FuncPtr(in_func_ptr){}

    virtual RetType Excute(Args &&... args)
    {
        std::cout << "000" << endl;
        return (ptr_->*FuncPtr)(std::forward<Args>(args)...);
    }
private:
    ObjectType *ptr_;
    RetType (ObjectType::*FuncPtr)(Args ...);
};

/* 函数代理 */
template<typename RetType, typename ... Args>
class FuncDelegate : public DelegateBase<RetType, Args ...>
{
public:
    FuncDelegate(RetType (*in_func_ptr)(Args ...))
        : FuncPtr(in_func_ptr){}

    virtual RetType Excute(Args &&... args)
    {
        std::cout << "123" << endl;
        return (*FuncPtr)(std::forward<Args>(args)...);
    }
private:
    RetType (*FuncPtr)(Args ...);
};

template<typename RetType, typename ... Args>
class Delegate
{
public:
    Delegate() : current_delegate_ptr(nullptr) {}
    ~Delegate() { Release();}
public:
    void Release()
    {
        if (current_delegate_ptr)
        {
            delete current_delegate_ptr;
            current_delegate_ptr = nullptr;
        }
    }

    template<typename ObjectType>
    void Bind(ObjectType *in_ptr, RetType (ObjectType::*in_func_ptr)(Args ...))
    {
        Release();
        current_delegate_ptr = new ObjectDelegate<ObjectType, RetType, Args...>(in_ptr, in_func_ptr);
    }

    void Bind(RetType (*in_func_ptr)(Args ...))
    {
        Release();
        current_delegate_ptr = new FuncDelegate<RetType, Args...>(in_func_ptr);
    }

    bool isBound() const { return current_delegate_ptr != nullptr; }

    virtual RetType Excute(Args &&... args)
    {
        return current_delegate_ptr->Excute(std::forward<Args>(args)...);
    }

    static Delegate<RetType, Args...> Create(RetType (*in_func_ptr)(Args ...))
    {
        Delegate<RetType, Args...> instance;
        instance.Bind(in_func_ptr);
        return instance;
    }

    template<typename ObjectType>
    static Delegate<RetType, Args...> Create(ObjectType *in_ptr, RetType (ObjectType::*in_func_ptr)(Args ...))
    {
        Delegate<RetType, Args...> instance;
        instance.Bind(in_ptr, in_func_ptr);
        return instance;
    }

    Delegate<RetType, Args...>& operator=(Delegate<RetType, Args...> &rhs)
    {
        current_delegate_ptr = rhs.current_delegate_ptr;
        return *this;
    }
private:
    DelegateBase<RetType, Args...> *current_delegate_ptr;
};

template<typename RetType, typename ... Args>
class SingleDelegate : public Delegate<RetType, Args...>
{
public:
    SingleDelegate() {}
};

template<typename RetType, typename ... Args>
class MultiDelegate : public std::vector<Delegate<RetType, Args...>>
{
public:
    MultiDelegate() {}
public:
    template<typename ObjectType>
    void AddDelegate(ObjectType *in_ptr, RetType (ObjectType::*in_func_ptr)(Args ...))
    {
        this->emplace_back(Delegate<RetType, Args...>());
        Delegate<RetType, Args...> &instance = this->back();
        instance.Bind(in_ptr, in_func_ptr);
    }

    void AddDelegate(RetType (*in_func_ptr)(Args ...))
    {
        this->emplace_back(Delegate<RetType, Args...>());
        Delegate<RetType, Args...> &instance = this->back();
        instance.Bind(in_func_ptr);
    }

    void Broadcast(Args &&... args)
    {
        for(auto &tmp : *this)
        {
            // TODO...
            tmp.Excute(std::forward<Args>(args)...);
        }
    }

    void ReleaseDelegate()
    {
        for(auto &tmp : *this)
        {
            tmp.Release();
        }
    }
};

}

#endif //__CPP_CHAPETR_11_HPP__
