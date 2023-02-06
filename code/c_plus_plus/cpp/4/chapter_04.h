
#ifndef __CPP_CHAPTER_4_H__
#define __CPP_CHAPTER_4_H__

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <utility>
#include <forward_list>

namespace chapter_04
{

class Hello{};

template<typename T>
class Vector;

template <typename T>
void CallArray(const Vector<T> &vec)
{
    for (int i = 0; i < vec.Num(); ++i)
    {
        T *p = vec[i];
        //
    }
}

template<typename T>
class Vector
{
    friend class Test7;
public:

    T* operator[](int index) const
    {
        return &data_[index];
    }

    int Num() const
    {
        return 0;
    }

    // 可以分文件定义
    void Hello();

    template<typename T1>
    T1* Hello1()
    {
        printf("Vector<T>::Hello1()\n");
        bool flag = data_->Work();
        return nullptr;
    }
private:
    inline void hello()
    {
        printf("inline Vector<T>::hello()\n");
    }
private:
    T *data_;
};

template<typename T>
void Vector<T>::Hello()
{
    printf("Vector<T>::Hello()\n");
}

void Test11();
void Test22();

class Test
{
public:
    bool Work()
    {
        printf("Test::Work()\n");
        return true;
    }
};


class Test1 : public Vector<Test>
{
public:
    void Hello2()
    {
        printf("Test1::Hello2()\n");
    }
};

template <typename T>
class Test2 : public Vector<T>
{
public:
    void Hello2()
    {
        printf("Test2<T>::Hello2()\n");
    }
};

template <typename X, typename Y, typename Z >
class Test3 : public Vector<Y>
{
public:
    void Hello2()
    {
        printf("Test3<X, Y, Z>::Hello2()\n");
    }
private:
    X a;
    Y b;
    Z c;
};

class Test4 : virtual public Vector<Test>
{
public:
    Test4() : Vector<Test>() {}

};

class Test5 : virtual public Vector<Test>
{
    typedef Vector<Test> Base;
public:
    Test5() : Base() {}

};

class Test6 : public Test4, public Test5
{
public:
    //Test6() : Test4(), Test5() {}
};

class Test7
{
public:
    void Hello()
    {
        printf("Test7::Hello()\n");
        ct_.Hello();
        ct_.Hello1<int>();
        ct_.hello();
    }
private:
    Vector<Test> ct_;   //
};

//template <typename T>
//class Test8
//{
//public:
//    void Hello()
//    {
//        printf("Test7::Hello()\n");
//        ct_.Hello();
//        ct_.Hello1<int>();
//        ct_.hello();
//    }
//private:
//    Vector1<T> ct_;
//};

void Test33();

template<typename T>
class hello
{
public:
    virtual void Init()
    {
        printf("hello::Init()\n");
    }

    virtual void Destory()
    {
        printf("hello::Destory()\n");
    }

    void Hello()
    {
        printf("hello::Hello()\n");
    }

    void Hello(int a)
    {
        printf("hello::Hello(int a)\n");
    }

    void Hello(int a,int b)
    {
        printf("hello::Hello(int a,int b)\n");
    }

    void Hello1(...)
    {

        printf("hello::Hello1(...)\n");
    }
private:
    T *ptr_;
};

class hello1 : public hello<int>
{
public:
    virtual void Init()
    {
        printf("hello1::Init()\n");
        hello<int>::Init();             // 调用基类成员
    }

    virtual void Destory()
    {
        printf("hello1::Destory()\n");
    }
};

void Test44();
/*
#define HELLO_CLASS(ClassName, Code) \
template<typename T> \
class F##ClassName \
{ \
public: \
    void Work() \
    { \
        Code; \
    } \
private: \
    T* t_; \
};
*/
void Test55();

void Test66();

template<typename T>
void PrintValue(T &arg)
{
    std::cout << arg << std::endl;
}

template<typename ... T>
void Func(T &... arg)
{
    std::cout << sizeof ... (arg) << std::endl;
    char arr[] = {(PrintValue(arg), 0) ...};    // void
}

template<typename ... T>
void Func1(T &... arg)
{
    char arr[] = {arg ... };
    for (auto t : arr)
    {
        std::cout << t << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void PrintVal(T &t)
{
    std::cout << "param: " << t << std::endl;
}

template<typename T, typename ... Y>
void PrintVal(T& head, Y &... args)
{
    std::cout << "param: " << head << std::endl;
    PrintVal(args ...);
}

// 终止函数
template<typename T>
T& FunValue(T &arg)
{
    return arg;
}

template<typename T, typename ... Y>
T FunValue(T& head, Y &... args)
{
    return head + FunValue<T>(args ...); // 调用特定类型
}

/* 模板泛化 */
template<typename T, typename Y>
class HelloClass
{
public:
    T a;
    Y b;
};

/* 模板全特化 */
template<>
class HelloClass<int, float>
{
public:
};

template<typename T>
class HelloClass<int, T>
{
public:
};

/* 函数泛化 */
//template <typename T>
//void Func11()
//{

//}

/* 函数全特化 */
//template <>
//void Func11<int>()
//{

//}

void Test77();

template <typename T, typename ... Arg>
class TestLen
{
public:
    enum
    {
        Number = TestLen<T>::Number + TestLen<Arg...>::Number
    };
};

template <typename Last>
class TestLen<Last>
{
public:
    enum
    {
        Number = sizeof(Last)
    };
};

void Test88();

template<int...>
struct HelloIndex {};

template<int N, int ... T>
struct SpawnIndex : SpawnIndex<N - 1, N - 1, T ...>
{

};

template<int ... T>
struct SpawnIndex<0, T ...>
{
    typedef HelloIndex<T ...> Type;
};

void Test99();

class TestA
{
public:
    TestA(int i, const std::string &s)
    {
        std::cout << "TestA::TestA(int,string)" << std::endl;
    }

    bool Print(int i, int j)
    {
        std::cout << "TestA::Print(int,int)" << std::endl;
        return true;
    }
};

template<typename T, class ... ParamTypes>
T* CreateObj(ParamTypes &&... args)
{
    return new T(std::forward<ParamTypes>(args) ... );
}

void Test101();

template<typename ObjectType, typename RetType, typename ... Args>
class Delegate
{
public:
    Delegate(ObjectType *in_ptr, RetType (ObjectType::*in_func_ptr)(Args ...))
        : ptr_(in_ptr), FuncPtr(in_func_ptr){}

    RetType operator()(Args &&... args)
    {
        return (ptr_->*FuncPtr)(std::forward<Args>(args)...);
    }
private:
    ObjectType *ptr_;
    RetType (ObjectType::*FuncPtr)(Args ...);
};

template<typename ObjectType, typename RetType, typename ... Args>
Delegate<ObjectType, RetType, Args...>
CreateObject(ObjectType *in_object, RetType (ObjectType::*in_func_ptr)(Args ...))
{
    return Delegate<ObjectType, RetType, Args...>(in_object, in_func_ptr);
}

void Test102();



}


#endif //__CPP_CHAPTER_4_H__
