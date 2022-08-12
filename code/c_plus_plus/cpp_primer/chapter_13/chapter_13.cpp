
#include "chapter_13.h"
#include "employee.h"
#include "has_ptr.h"
#include "str_vec.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void Chapter_13()
{
    //Homework_13_13();
    //Homework_13_14();
    //Homework_13_18();

    //Practice_13_3();
    //Homework_13_22();

    Practice_13_6_2();
    //Homework_13_31();
}

/***************************************************************/
/***************************13.1********************************/

class X
{
public:
    X() { cout << "construct func." << endl;}
    X(const X &x) { cout << "copy construct func." << endl; }
    X& operator= (const X &x) { cout << "assign construct func." << endl; return *this;}
    ~X() { cout << "distruct func." << endl; }
};

void F1(X x)
{
    //cout << "pass by value func!" << endl;
}

void F2(X &x)
{
    //cout << "pass by refrence func!" << endl;
}

void Homework_13_13()
{
    X object;
    cout << endl;

//    cout << "pass value call" << endl;
//    F1(object);
//    cout << endl;

//    cout << "refrence call" << endl;
//    F2(object);
//    cout << endl;

//    cout << "malloc " << endl;
//    X *p = new X;
//    cout << endl;

//    cout << "vector push back val" << endl;
//    vector<X> vec;  //vec析构的时候,会析构里边的对象
//    vec.push_back(object);
//    cout << endl;

//    cout << "dis object" << endl;
//    delete p;
//    cout << endl;

//    cout << "create new object" << endl;
//    X y = object;
//    cout << endl;

    cout << "assign value" << endl;
    X new_val;
    new_val = object;
    cout << endl;
}

size_t Numbered::sn_ = 0;

// homework 13.16
void f(const Numbered &s)
//void f(Numbered s)
{
    cout << s.my_sn_ << endl;
}

void Homework_13_14()
{
    Numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}

/* 13.1.6 阻止拷贝*/
void Practice_13_1_2()
{
    GZNoCopy no_object;
    //GZNoCopy no_object2 = no_object;
    GZNoCopy no_object3;
    //no_object3 = no_object;

    //GZNoDtor no_dtor;
    //GZNoDtor *no_dtor_ptr = new GZNoDtor;
    //delete no_dtor_ptr;

    GZPrivateCopy pri_object;
    //GZPrivateCopy pri_object2 = pri_object;

    //GZPrivateCopy pri_object3;
    //pri_object3 = pri_object;
}

void Homework_13_18()
{
    GZEmployee a("a"), b = a, c;
    c = b;

    PrintGZEmployee(a);
    PrintGZEmployee(b);
    PrintGZEmployee(c);
}

/***************************************************************/
/***************************13.3********************************/

class GZFoo
{
    friend void swap(GZFoo &lhs, GZFoo &rhs);
public:
    explicit GZFoo(const string &s) : s_(s), hp_(s) {}
    string PrintVal() const { return s_; }
private:
    string s_;
    HasPtr hp_;
};

// swap调用的应该是swap，而不是std::swap
void swap(GZFoo &lhs, GZFoo &rhs)
{
    using std::swap;
    cout << "swap GZFoo object: " << lhs.PrintVal() <<
            " and " << rhs.PrintVal() << endl;
    swap(lhs.hp_, rhs.hp_);
}

void Practice_13_3()
{
//    GZFoo foo1("foo1"), foo2("foo2");
//    swap(foo1, foo2);

    HasPtr h1("h1"), h2("h2");
    h1 = h2;
}

// 编译器会为GZX和GZhasX合成移动构造函数
struct GZX
{
    int     i;
    string  s;
};

struct GZhasX
{
    GZX mem;
};

struct GZY
{
    int     i;
    string  s;
    GZY(const GZY&){}
};

struct GZhasY
{
    GZhasY() = default;
    GZhasY(GZhasY &&) = default;

    GZY mem;
};

StrVec GetVec(istream &is)
{

}

class Foo
{
public:
    Foo() {cout << "construct func." << endl;}
    Foo(const Foo &rhs) { cout << "copy construct func." << endl; }
    // Foo Sorted() &&;
    // Foo Sorted() const &;
    //~Foo();
private:
    vector<int> data;
};

// Foo Foo::Sorted() &&
// {
//     cout << "right version." << endl;
//     sort()
// }

void Practice_13_6_2()
{
    //
//    StrVec sv1;
//    //StrVec sv2(sv1);
//    StrVec sv3;
//    sv3 = std::move(sv1);

    // 合成移动操作
//    GZX x, x2 = std::move(x);
//    GZhasX hx, hx2 = std::move(hx);

    //GZhasY hy, hy2 = std::move(hy);

    // 移动右值,拷贝左值...
    StrVec v1, v2;
    //v1 = v2;
    //v2 = GetVec(cin);

    // 没有移动构造函数，右值被拷贝
    Foo x;
    Foo y(x);
    Foo z(std::move(x));    //Foo&& --> const Foo&
}

void Homework_13_22()
{
    HasPtr h1("hi");
    HasPtr h2(h1);
    HasPtr h3 = h1;

    *h2 = "nihao";
    *h3 = "hello";

    cout << "h1: " << *h1 << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    cout << endl;

    swap(h2, h3);
    cout << "h1: " << *h1 << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
}

void Homework_13_31()
{
    srand(time(NULL));
    vector<HasPtr> vec;

    for (int i = 0; i != 10; ++i)
        vec.push_back(to_string(rand() % 1000));

    for (auto &it : vec)
        cout << *it << " ";
    cout << endl;

    sort(vec.begin(), vec.end());
    for (auto &it : vec)
        cout << *it << " ";

}
