
#ifndef __CPP_CHAPTER_03_H__
#define __CPP_CHAPTER_03_H__

#include <stdio.h>

namespace chapter_03
{

class A
{
public:
    virtual void Func()
    {
        printf("virtual A::Func()\n");
    }

    void Func1()
    {
        printf("A::Func1()\n");
    }

    void Func1(int a)
    {
        printf("A::Func1(int a)\n");
    }

    void Func1(int a, int b) {}

    void Func1(int a, int b, int c) {}
};

class B : public A
{
public:
    void Func() override
    {
        printf("virtual Ch3B::Func()\n");
    }

    void Func1()
    {
        //Ch3A::Func1(1);
        printf("Ch3B::Func1()\n");
    }

    void Func1(int a, int b, int c, int d) {}
};

class Interface
{
public:

    virtual void Init()		= 0;
    virtual void Destroy()	= 0;
};

class NewObject :public Interface
{
public:
    NewObject(){}

    virtual void Init() final
    {
        printf("NewObject::Init()\n");
    }
    virtual void Destroy() {}
    void Destroy1(){}
};

class NewObject1 final : public NewObject
{
public:
    NewObject1() {}

    void Destroy() override {};
    //void Destroy1() override {};
};

//class NewObject2 : public NewObject1
//{
//public:
//    NewObject2() {}

//    void Destroy() override {};
//};

class HelloTest
{
public:
    HelloTest();

    void Init();
public:
    int a;
    int b;
    float aa;
};

class Hello
{
public:
    virtual void Init() {}
    virtual void Init1() {}
    virtual void Init2() {}
};

class Hello1 : public Hello
{
public:
    void Hello(){}
private:
    int a;
};

class Hello2 : public Hello1 {};

class HelloA
{
public:
    void Init() {}
    void Init1() {}
    void Init2() {}
};

class HelloB :public HelloA {};

class Const
{
public:
    Const() : m_ptr(nullptr)
        //,m_ptrRef(NULL)
    {}

    const HelloTest* m_ptr;
//	const HelloTest& m_ptrRef;
};

//16 字节
struct HelloStruct
{
    int a;
    int b;
    int c;
    int d;
};

static HelloTest s_t;

class TestConst
{
public:
    void Init() const {}
    void Init2() {}
    void Init1() const
    {
        s_t.a = 100;
        Init();

        //Init2();
    }

    const TestConst* CreateObj() { return nullptr; }

    // 尽量返回指针
    const TestConst& GetConst()
    {
        if (const TestConst *obj = CreateObj())
        {
            return *obj;
        }

        return NULLConst;
    }

    static TestConst NULLConst;
private:
    int a;
};

}

#endif // __CPP_CHAPTER_03_H__
