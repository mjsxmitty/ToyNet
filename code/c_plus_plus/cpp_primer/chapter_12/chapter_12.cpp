
#include "chapter_12.h"
#include "str_blob.h"
#include "../chapter_07/gz_sales_data.h"

#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

void ch_12(int argc, char **argv)
{
    /* 动态内存与智能指针 */
    ch_12_1();

    /* 动态数组 */
    //ch_12_2();
}

/***************************************************************/
/***************************12.1********************************/

void ch_12_1()
{
    /* shared_ptr类 */
    //ch_12_1_1();
    //hw_12_1();

    /* 直接管理内存 */
    //ch_12_1_2();

    /* shared_ptr与类的结合 */
    //ch_12_1_3();

    /* 智能指针和异常 */
    //ch_12_1_4();

    /* unique_ptr*/
    //ch_12_1_5();

    /* weak_ptr */
    ch_12_1_6();
}

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

void ch_12_1_1()
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
}

void hw_12_1()
{
    GZStrBlob b1;
    {
        GZStrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        cout << "b1 size : " << b1.Size() << endl;
        cout << "b2 size : " << b2.Size() << endl;
        b2.PushBack("about");
        cout << "b1 size : " << b1.Size() << endl;
        cout << "b2 size : " << b2.Size() << endl;
    }
    cout << "b1 size : " << b1.Size() << endl;
}

void hw_12_2()
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

void ch_12_1_2()
{
    /* 使用new动态分配和管理对象 */ 
    {
        int *pi = new int;
        string *ps = new string;
        int *pi2 = new int(10);
        string *ps2 = new string(10, 'c');
        vector<int> *pv = new vector<int>{'a', 'b', 'c'};
    }

    {
        int i = 100;
        auto *pi = new auto (i);        //根据i推断
        auto *pi2 = new int(i);
        *pi = 10;
        string s = "hello";
        auto *ps = new auto (s);
    }

    /* 动态分配const对象 */ 
    {
        const int *pci = new const int(1024);
        const string *pcs = new const string;
    }


    /* 内存耗尽 */
    {
        int *ip = new (nothrow) int;    //分配不成功,返回空指针
    } 

    /* 释放动态内存 */ 
    {
        // delete p;
        // delete p2;
        // delete pi;
        // delete pi2;
        // delete pci;
        // delete pcs;
    }

    /* 指针值和delete */ 
    {
        int i2, *pi1 = &i2, *pi22 = nullptr;
        double *pd = new double(1024), *pd2 = pd;

    //    delete  i2;
    //    delete pi1;
        delete pd;
    //    delete pd2;
        delete pi22;
    }



    /*...这只是提供了有限的保护 */ 
    {
        int *p(new int(1024));
        auto q = p;

        delete p;
        p = nullptr;

        //*q = 0;
        //delete q;
    }
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

void hw_12_6()
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

    // hw 12.7
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
    /* 不能将一个内置指针隐式转换为一个智能指针 */
    //return new int(p);

    //return make_shared<int>(p);
    return shared_ptr<int>(new int(p));
}

void Process(shared_ptr<int> ptr)
{
    cout << "func ptr: " << *ptr << endl;
}

void ch_12_1_3()
{
    {
        shared_ptr<int> sp = Clone(3);
        cout << *sp << endl;
    }


    /* 不要混用普通指针和智能指针 */
    {
        // 正确的使用方法
        shared_ptr<int> p(new int(42));
        //Process(shared_ptr<int> (p));
        Process(p);
        int i = *p;
        cout << "i = " << i << endl;

        // 错误的使用方法
//        int *x(new int(42));
//        Process(new int());
//        Process(x);   //只能直接初始化
//        Process(shared_ptr<int> (x));
//        int j = *x;
//        cout << "j = " << j << endl;
    }


    /* 不要使用一个get初始化另一个智能指针或者为智能指针赋值 */
    {
//        shared_ptr<int> p(new int(42));
//        {
//            shared_ptr<int> q(p.get());
//            cout << "*q = " << *q << endl;
//        }
//        int foo = *p;
//        cout << "foo = " << foo << endl;
    }

    /* shared_ptr其他操作 */
    {
        shared_ptr<int> p(new int(42));
        shared_ptr<int> q = p;
        //cout << q.unique() << endl;
        if (!p.unique())
        {
            cout << "only one pointer!" << endl;
            p.reset(new int(1024));
            cout << "*p = " << *p << endl;
            *p += 1;
            cout << "*p = " << *p << endl;
        }
    }
}

struct Destination {};
// 没有析构
struct Connection{};

Connection Connect(Destination *dest)
{
    cout << "open connect ..." << endl;
}

void DisConnection(Connection c)
{
    cout << "disconnect ..." << endl;
}

void EndConnection(Connection *p) { DisConnection(*p); }

void FuncConnect(Destination &dest)
{
    cout << "FuncConnect ..." << endl;
    Connection c = Connect(&dest);

    cout << endl;
}

void FuncConnect1(Destination &dest)
{
    cout << "FuncConnect1 ..." << endl;
    Connection c = Connect(&dest);

    shared_ptr<Connection> p(&c, EndConnection);
    //shared_ptr<Connection> p1(&c, [](Connection *p){DisConnection(*p);});
    //shared_ptr<Connection> p(&c, DisConnection); //error

    //unique_ptr<Connection, decltype(EndConnection)*> up(&c, EndConnection);
}

void ch_12_1_4()
{
    Destination d;
    //FuncConnect(d);
    FuncConnect1(d);
}

unique_ptr<string> Clone(string p)
{
    //return unique_ptr<string>(new string(p));
    unique_ptr<string> ret(new string(p));
    return ret;
}

void ch_12_1_5()
{
    {
        unique_ptr<string> p1(new string("hello world"));
        cout << "p1 = " << *p1 <<  endl;
//        unique_ptr<string> p2(p1);
//        unique_ptr<string> p3;
//        p3 =p1;

        unique_ptr<string> p2(p1.release());    // p1置空
//        cout << "p2 = " << *p2 << endl;

        unique_ptr<string> p3(new string("ni hao"));
        p2.reset(p3.release());                 // p2释放,指向p3
//        cout << "p2 = " << *p2 << endl;
    }

    /* 传递unique_ptr参数和返回unique_ptr */
    {
        string s = "hello";
        unique_ptr<string> ups = Clone(s);
    }

    /* 向unique_ptr传递删除器 */
    {
        Destination d;
        Connection c = Connect(&d);

        unique_ptr<Connection, decltype(EndConnection)*> p(&c, EndConnection);
    }
}

void ch_12_1_6()
{
    shared_ptr<int> isp = make_shared<int>(1024);
    weak_ptr<int>   wp(isp);
    cout << wp.use_count() << endl;

    if (isp.unique())
    {
        cout << "only one pointer!" << endl;
    }

    if (shared_ptr<int> isp2 = wp.lock())
    {
        cout << wp.use_count() << endl;
        if (isp.unique())
        {
            cout << "only one pointer2!" << endl;
        }
    }

    if (isp.unique())
    {
        cout << "only one pointer3!" << endl;
    }
}

void hw_12_20(int argc, char **argv)
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

/***************************************************************/
/***************************12.2********************************/

/* 12.2.1 new和数组 */
void ch_12_2_1()
{

    typedef int IntArry[10];
    int *parray = new IntArry;
    delete [] parray;

    int *pia = new int[10]{1,2,3};
    for (int *q = pia; q != pia + 10; ++q)
    {
        cout << *q << ' ';
    }
    cout << endl;
    delete [] pia;

    // 智能指针和动态数组
    unique_ptr<int []> upi(new int[10]);
    for (int i = 0; i != 10; ++i)
        upi[i] = i;
    upi.release();

    shared_ptr<int> sp(new int[10], [](int *p){delete [] p; });
    for (int i = 0; i != 10; ++i)
        *(sp.get() + i) = i;
    sp.reset();
}

void hw_12_23()
{
    const char *c1 = "Hello";
    const char *c2 = "World";

    char *nc = new char[strlen(c1) + strlen(c2) + 1];
    strcpy(nc, c1);
    strcat(nc, c2);
    cout << nc << endl;

    string s1 = "Nihao";
    string s2 = "World";
    strcpy(nc, (s1 + s2).c_str());
    cout << nc << endl;
    delete [] nc;
}

void hw_12_24()
{
    char *nc = new char[20];
    int  pos = 0;

    char c;
    while (cin.get(c))
    {
        if (isspace(c))
            break;

        nc[pos++] = c;
        if (pos == 20)
        {
            cout << "reach max!!!" << endl;
            break;
        }
    }
    nc[pos] = 0;
    cout << nc << endl;
    delete [] nc;
}

/* 12.2.2 allocator类 */
void ch_12_2_2()
{
    //
//    allocator<GZSalesData> gz_alloc;
//    auto gz_ptr = gz_alloc.allocate(10);
//    string isbn("gz_test");
//    gz_alloc.construct(gz_ptr, isbn);
//    cout << gz_ptr->Isbn() << endl;

//    gz_alloc.destroy(gz_ptr);
//    gz_alloc.deallocate(gz_ptr, 10);

    // allocator类
//    const size_t n = 100;
//    allocator<string> alloc;
//    auto p = alloc.allocate(n);

//    auto q = p;
//    alloc.construct(q++);
//    cout << *(q -1) << endl;

//    alloc.construct(q++, 10, 'c');
//    cout << *(q -1) << endl;

//    alloc.construct(q++, "hi");
//    cout << *(q -1) << endl;

//    while (q != p)
//        alloc.destroy(--q);

//    alloc.deallocate(p, n);

    vector<int> vi{1,2,3,4,5,6,7,8,9};
    allocator<int> ialloc;
    auto pi = ialloc.allocate(vi.size() * 2);

    auto qi = uninitialized_copy(vi.begin(), vi.end(), pi);
    uninitialized_fill_n(qi, vi.size(), 100);

    for (int i = 0; i != vi.size(); ++i)
        cout << *(pi + i) << ' ';
    cout << endl;

    for (int i = 0; i != vi.size(); ++i)
        cout << *(qi + i) << ' ';
    cout << endl;

    while (qi != pi)
        ialloc.destroy(--qi);
    ialloc.deallocate(pi, vi.size() * 2);
}


/***************************************************************/
/***************************12.3********************************/
//TODO...RR
