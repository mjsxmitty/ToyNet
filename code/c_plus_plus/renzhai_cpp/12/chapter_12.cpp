

#include "chapter_12.h"
#include <memory>
#include <iostream>

using namespace std;

namespace chapter_12
{

void Test1()
{
    int *p = new int;

    //shared_ptr<int> ptr = p;  //error
    shared_ptr<int> ptr(p);
    cout << ptr.use_count() << endl;

    shared_ptr<int> ptr1 = make_shared<int>();
    cout << ptr.use_count() << endl;

    shared_ptr<int> ptr2(ptr);
    cout << ptr.use_count() << endl;

    shared_ptr<int> ptr3 = ptr;
    cout << ptr.use_count() << endl;

    ptr3 = nullptr;
    cout << ptr.use_count() << endl;
}

void Test2()
{
    int *p = new int(1024);
    shared_ptr<int> ptr(p);

    int *pi = ptr.get();    //不可以delete
    cout << *pi << endl;
    ptr.unique();

    shared_ptr<int> ptr1 = make_shared<int>(0);
    ptr.swap(ptr1);
    cout << *ptr << endl;

    ptr.reset(); //ptr = nullptr;
}

void Test3()
{
    shared_ptr<TestPtr> ptr(new TestPtr);
    TestPtr *p = ptr.get();
    // 转为智能指针
    shared_ptr<TestPtr> p2 = p->shared_from_this();
    p2.use_count();
}

void Test4()
{
    shared_ptr<int> ptr(new int);

    weak_ptr<int> wptr = ptr;
    wptr.lock();    // 转为共享指针
    wptr.expired();
    wptr.use_count();
}

void Test5()
{}
void Test6()
{
    unique_ptr<int> p(new int());
    unique_ptr<int> p1 = unique_ptr<int>(new int(1024));

    p.reset();
    p.release();
}

}
