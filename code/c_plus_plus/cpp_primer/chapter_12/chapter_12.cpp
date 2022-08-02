
#include "chapter_12.h"
#include "str_blob.h"

#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <vector>
#include <fstream>

using namespace std;

void Chapter_12(int argc, char **argv)
{
    //Practice_12_1_1();
    //Homework_12_2();
    //Practice_12_1_2();
    //Homework_12_5();
    Practice_12_1_3();
    //Practice_12_1_5();
    //Homework_12_20(argc, argv);
}

/***************************************************************/
/***************************12.1********************************/

typedef int T;
struct Foo
{
    Foo(T t) : val(t) {}
    T   val;
};

std::ostream& Print(std::ostream &os, const Foo& f)
{
    os << f.val;
    return os;
}

shared_ptr<Foo> Factory(T arg)
{
    return make_shared<Foo>(arg);
}

// 返回指针会递增引用计数
shared_ptr<Foo> UseFactory(T arg)
{
    shared_ptr<Foo> p = Factory(arg);
    if (p)
        Print(cout, *p);
    else
        cout << "malloc addr failed." << endl;
    cout << endl;

    return p;
}


/* 12.1.1 shared_ptr类 */
void Practice_12_1_1()
{
    shared_ptr<string>      p1;
    shared_ptr<list<int>>   p2;
    if (p1)
        cout << "pi ptr is empty." << endl;
    // if (p1 && p1->empty())
    //     *p1 = "hi";
    // cout << *p1 << endl;

    // make_shared 函数
    shared_ptr<int> p3 = make_shared<int>(42);
    cout << *p3 << endl;

    shared_ptr<string> p4 = make_shared<string>(10, 'a');
    cout << *p4 << endl;

    shared_ptr<int> p5 = make_shared<int>();
    auto p6 = make_shared<vector<int>>();

    cout << "test use GZStrBlob class ..." << endl;
    GZStrBlob b1;
    cout << "b1 size: " << b1.Size() << endl;
    {
        GZStrBlob b2 = {"a", "an", "the"};
        cout << "before push back b2 size: " << b2.Size() << endl;
        b1 = b2;
        cout << "before push back b1 size: " << b1.Size() << endl;
        b2.PushBack("about");
        cout << "after push back b2 size: " << b2.Size() << endl;
        cout << "after push back b1 size: " << b1.Size() << endl;
    }
    cout << "b1 size: " << b1.Size() << endl;

}

void Homework_12_2()
{
    GZStrBlob b1;
    {
        GZStrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        cout << "b1 size: " << b1.Size() << ", b2 size: " << b2.Size() << endl;
        b2.PushBack("hi");
        cout << "b1 size: " << b1.Size() << ", b2 size: " << b2.Size() << endl;
    }
    cout << "b1 size: " << b1.Size() << endl;
    cout << "b1 front: " << b1.Front() << ", b1 back: " << b1.Back() << endl;

    GZStrBlob b3 = b1;
    cout << "b1 size: " << b1.Size() << ", b3 size: " << b3.Size() << endl;

    for (auto iter = b1.Begin(); NotEqual(iter, b1.End()); iter.Incr())
        cout << iter.Deref() << endl;
}


/* 12.1.2 直接管理内存 */
void Practice_12_1_2()
{
    // 使用new动态分配和管理对象
//    int *pi = new int;
//    string *ps = new string;
//    int *pi2 = new int(10);
//    string *ps2 = new string(10, 'c');
//    vector<int> *pv = new vector<int>{'a', 'b', 'c'};

//    int i = 100;
//    auto *pi = new auto (i);        //根据i推断
//    auto *pi2 = new int(i);
//    *pi = 10;
//    string s = "nihao";
//    auto *ps = new auto (s);

    // 动态分配const对象
//    const int *pci = new const int(1024);
//    const string *pcs = new const string;

    // 内存耗尽
//    int *ip = new (nothrow) int;    //分配不成功,返回空指针

    // 释放动态内存
//    delete p;
//    delete p2;
//    delete pi;
//    delete pi2;
//    delete pci;
//    delete pcs;

    // 指针值和delete
    int i2, *pi1 = &i2, *pi22 = nullptr;
    double *pd = new double(1024), *pd2 = pd;

//    delete  i2;
//    delete pi1;
    delete pd;
//    delete pd2;
    delete pi22;


    // ...这只是提供了有限的保护
    int *p(new int(1024));
    auto q = p;

    delete p;
    p = nullptr;

    //*q = 0;
    //delete q;
}

vector<int>* NewVector()
{
    return new (nothrow) vector<int>;
}

shared_ptr<vector<int>> NewVec()
{
    return make_shared<vector<int>>();
}

void ReadVec(vector<int> *pv)
{
    int i;
    while (cin >> i)
        pv->push_back(i);
}

void ReadVec(shared_ptr<vector<int>> &vec)
{
    int i;
    while (cin >> i)
        vec->push_back(i);
}

void PrintVec(vector<int> *pv)
{
    for (const auto &i : *pv)
        cout << i << " ";
    cout << endl;
}

void PrintVec(shared_ptr<vector<int>> &vec)
{
    for (const auto &item : *vec)
        cout << item << " ";
    cout << endl;
}

void Homework_12_6()
{
    vector<int> *pv = NewVector();
    if (!pv)
    {
        cout << "malloc vector failed." << endl;
        return ;
    }

    ReadVec(pv);
    PrintVec(pv);
    delete pv;
    pv = nullptr;

    // homework 12.7
    shared_ptr<vector<int>> spv = NewVec();
    if (!spv)
    {
        cout << "malloc vector failed." << endl;
        return ;
    }

    ReadVec(spv);
    PrintVec(spv);
}

shared_ptr<int> Clone(int p)
{
    //return new int(p);
    //return make_shared<int>(p);
    return shared_ptr<int>(new int(p));
}

void Practice_12_1_3()
{
    // 不能将一个内置指针隐式转换为一个智能指针
    shared_ptr<int> sp = Clone(3);
    cout << *sp << endl;


}

void Practice_12_1_5()
{
    unique_ptr<string> p1(new string("hello world"));
    cout << "p1 = " << *p1 <<  endl;
//    unique_ptr<string> p2 = p1;
//    unique_ptr<string> p2;
//    p3 =p1;

    unique_ptr<string> p2(p1.release());
    cout << "p2 = " << *p2 << endl;

    unique_ptr<string> p3(new string("ni hao"));
    p2.reset(p3.release());
    cout << "p2 = " << *p2 << endl;
}

/*unique_ptr可以拷贝一个临时临时值*/
unique_ptr<string> Clone(string p)
{
    //return unique_ptr<string>(new string(p));
    unique_ptr<string> ret(new string(p));
    return ret;
}


void Homework_12_20(int argc, char **argv)
{
    //cout << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in)
    {
        cout << " open file failed." << endl;
        return ;
    }
    
    GZStrBlob sb;
    string s;
    while (getline(in, s))
        sb.PushBack(s);

    for (auto it = sb.Begin(); NotEqual(it, sb.End()); it.Incr())
        cout << it.Deref() << endl;
}

void Practice_12_2_1()
{
    unique_ptr<string []> ps(new string[10]);
    for (int i = 0; i != 10; ++i)
        ps[i] = i;
    ps.release();

    shared_ptr<int> sp(new int[10], [](int *p){delete [] p; });
    for (int i = 0; i != 10; ++i)
        *(sp.get() + i) = i;
    sp.reset();
}

void Practice_12_2_2()
{
    const size_t n = 100;
    allocator<string> alloc;
    auto p = alloc.allocate(n);

    auto q = p;
    alloc.construct(q++);
    cout << *(q -1) << endl;

    alloc.construct(q++, 10, 'c');
    cout << *(q -1) << endl;

    alloc.construct(q++, "hi");
    cout << *(q -1) << endl;

    while (q != p)
        alloc.destroy(--q);

    alloc.deallocate(p, n);

    vector<int> vi{1,2,3,4,5,6,7,8,9};
    allocator<int> ialloc;
    auto pi = ialloc.allocate(vi.size() * 2);

    auto qi = uninitialized_copy(vi.begin(), vi.end(), pi);
    uninitialized_fill_n(qi, vi.size(), 100);

    for (int i = 0; i != vi.size(); ++i)
        cout << *(pi + i) << endl;

    for (int i = 0; i != vi.size(); ++i)
        cout << *(qi + i) << endl;

    ialloc.deallocate(pi, vi.size() * 2);
}
