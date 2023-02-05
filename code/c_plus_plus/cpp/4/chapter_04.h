
#ifndef __CPP_CHAPTER_4_H__
#define __CPP_CHAPTER_4_H__

#include <string.h>
#include <stdio.h>

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
    //friend class Test8<T>;
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

template<typename T>
T& FunValue(T &arg)
{
    return arg;
}

template<typename T, typename ... Args>
T FunValue(T& head, Args &... args)
{
    return head + FunValue<T>(args ...);
}

}


#endif //__CPP_CHAPTER_4_H__
