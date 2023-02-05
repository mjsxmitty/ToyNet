
#ifndef __CPP_CHAPTER_02_H__
#define __CPP_CHAPTER_02_H__

#include <winerror.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>

using namespace std;

namespace chapter_02
{

struct Hello
{
    int     a;
    int     b;
    float   c;
    float   d;
private:
    int     m;
private:
    void hello(int i)
    {
        printf("Hello::hello(int)\n");
    }
public:
    void hello()
    {
        a = 0;
        b = 0;

        hello(a);  // 调用私有函数
    }
public:
    Hello()
    {
        ptr_ = new int;
    }

    ~Hello()
    {
        if (ptr_)
        {
            delete ptr_;
            ptr_ = nullptr;
        }
    }
private:
    int     *ptr_;
public:
    static void SHello();
public:
    inline int GetP() const { return p; }
private:
    int p;
};

class Monster
{
public:
    Monster();
    ~Monster();

    int         a;
    static int  b;

    static int SHello() { return b; }

    int Hello()
    {
        //Monster::SHello();    // 调用静态成员
        SHello();
        return b;
    }
public:
    inline int GetP() const { return p; }
private:
    int p;
};

inline int GetA()
{
    return 0;
}

class Workers           //基类 父类
{
public:
    void Work() {}
private:
    void Work1() {}
protected:
    void Work2() {}
};

class ComponentWorkers : public Workers
{
public:
    void Hello()
    {
        Work();
        //Work1();
        Work2();
    }
};

class SpliceWorkers : protected Workers
{
public:
    void Hello()
    {
        Work();
        //Work1();
        Work2();
    }
};

class SuperWorkers : private Workers
{
public:
    void Hello()
    {
        Work();
        //Work1();
        Work2();
    }
};

class TestWorkers : public SuperWorkers
{
public:
    void A()
    {
//        Work();
//        Work1();
//        Work2();
        Hello();
    }
};

class Object
{
public:
    void Destory(){}
};

class Actor : public Object
{
public:
    void Start() {}
    void End() {}
    void Net() {}
};

class Physics
{
public:
    void Simulate(){}
};

class Attackor;
class Attack
{
public:
    void AttackTarget(Attackor *target) {}
};

class hello : public Object
{

};

class Attackor : public Actor, public Physics, public Attack, public hello
{
public:
    // 菱形继承
    void func()
    {
        //Destory();
        hello::Destory();
        Actor::Destory();
    }
};

bool IsSimulate(Physics *p);

class HelloA
{
public:
    HelloA()
    {
        cout << "HelloA::HelloA()" << endl;
    }

    void Hello()
    {
        printf("HelloA::Hello()\n");
    }
};

class HelloB : virtual public HelloA
{
public:
    HelloB() : HelloA()
    {
        cout << "HelloB::HelloB()" << endl;
    }
};

class HelloC : virtual public HelloA
{
public:
    HelloC() : HelloA()
    {
        cout << "HelloC::HelloC()" << endl;
    }
};

class HelloD : public HelloB, public HelloC
{
public:
    HelloD() : HelloB(), HelloC()
    {
        cout << "HelloD::HelloD()" << endl;
    }
};

class HelloTest
{
    friend class HelloTest2;
public:
    void Hello1() {}
protected:
    void Hello2() {}
private:
    void Hello3() {}
};

class HelloTest2
{
public:
    void Init()
    {
        test.Hello1();
        test.Hello2();
        test.Hello3();
    }
private:
    HelloTest test;
};

class Test
{
public:
    friend void Print(Test &t)
    {
        t.Hello();
        printf("%d \n", t.a);
        printf("%d \n", t.b);

//        Test tt;
//        tt.a = 0;
    }

    static void Print2(Test &t)
    {
        t.Hello();
        printf("%d \n", t.a);
        printf("%d \n", t.b);
    }
private:
    void Hello()
    {
        a = 1;
        b = 2;
    }
private:
    int a;
    int b;
};

class testA {};

class TestA : public testA
{
public:
    TestA()
    {
        a = 1024;
        ptr = new Test();
    }

    TestA(int i)
    {
        a = i;
        ptr = new Test();
    }

    ~TestA()
    {
        cout << "TestA::~TestA()" << endl;
        if (ptr)
        {
            delete ptr;
            ptr = nullptr;
        }
    }

    TestA(int i, int j) : testA(), a(i), b(j) {}

    TestA(const TestA &t)
    {
        a = t.a;
        b = t.b;
        ptr = new Test();
        *ptr = *t.ptr;
    }

public:
    int     a;
    int     b;
    Test *ptr;
};

}

namespace Operator
{
class Stream
{
public:
    Stream& operator<<(const char *p)
    {
        printf(p);
        return *this;
    }

    Stream& operator<<(const Stream &p)
    {
        printf("\n");
        return *this;
    }

    Stream& operator<<(const int i)
    {
        printf("%d", i);
        return *this;
    }

    Stream& operator<<(const float f)
    {
        printf("%f", f);
        return *this;
    }

    Stream& operator<<(const double d)
    {
        printf("%le", d);
    }
public:
    Stream& operator=(const char *p)
    {
        ptr = (char *)malloc(strlen(p) + 1);
        strcpy(ptr, p);
        return *this;
    }

    Stream& operator=(const Stream &s)
    {
        ptr = (char *)malloc(strlen(s.ptr) + 1);
        strcpy(ptr, s.ptr);
        return *this;
    }

    Stream()
    {
        ptr = nullptr;
    }

    ~Stream()
    {
        if (ptr)
        {
            delete ptr;
            ptr = nullptr;
        }
    }

    Stream& Print()
    {
        if (ptr)
        {
            printf(ptr);
        }
        return *this;
    }
public:
    char    *ptr;
};

extern Stream GZstream;
extern Stream GZendl;

}

namespace ch_02
{
enum Hello
{
    Hello_A,
    Hello_B,
};

struct AssetHello
{
    void Init() {}
    void Hello() {}
};

class Interface {};

class hello : public Interface {};

Hello* GetHello();

}


#endif // __CPP_CHAPTER_02_H__
