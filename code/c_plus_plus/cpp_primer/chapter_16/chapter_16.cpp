

#include "chapter_16.h"
#include "ch_16.hpp"
#include "../common/blob.hpp"
#include "../common/blob_ptr.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;
using namespace chapter_16;

void ch_16()
{
    /* 定义模板 */
    ch_16_1();
}

void ch_16_1()
{
    /* 函数模板 */
    //ch_16_1_1();
    //hw_16_4();
    //hw_16_7();

    /* 模板参数 */
    //ch_16_1_3();

    /* 成员模板 */
    ch_16_1_4();
}

void ch_16_1_1()
{
    using namespace chapter_16;
    /* 实例化函数 */
    {
        cout << Compare(1, 0) << endl;

        vector<int> vec1{1,2,3}, vec2{4,5,6};
        cout << Compare(vec1, vec2) << endl;
    }
}


void hw_16_4()
{
    vector<int> vec = {1, 23 ,43 ,3, 45,6,11};

    auto iter = Find(vec.begin(), vec.end(), 6);
    if (iter == vec.end())
        cout << "not find value." << endl;
    else
        cout << "find value position: " 
             << iter - vec.begin() << endl;

    list<string> lst = {"hello", "hi", "nihao"};
    auto iter1 = Find(lst.begin(), lst.end(), "!");
    if (iter1 == lst.end())
        cout << "can not find value." << endl;
    else
        cout << "find value position: " 
             << iter - vec.begin() << endl;
}

void hw_16_7()
{
    int iarray[5] = {1, 3 ,5 ,23, 6};
    Print(iarray);

    string sarray[4] = {"nihao", "hi", "hello"};
    Print(sarray);
}

/* 通用和特定的模板的友好关系 */
template<typename T> class Pal;
class GZC   // 非模板类
{
    friend class Pal<GZC>;
    template<typename T> friend class Pal2;
};

template<typename T>
class GZC2
{
    friend class Pal<T>;
    template<typename X> friend class Pal2;
    friend class Pal3;
};

/* 令模板自己的类型参数成为友元 */
template <typename T>
class GZBar
{
    friend T;
};

void ch_16_1_2()
{
    /* 实例化类 */
    {
        Blob<string>    sa = {"hello", "hi", "nihao"};
    }

    /* 实例化成员函数 */
    {
        Blob<int>       ia = {1,2,3,4,5,6,7,8,9};

        for (size_t i = 0; i != ia.Size(); i++)
            ia[i] = i * i;

        for (size_t i = 0; i < ia.Size(); i++)
            cout << ia[i] << " ";
        cout << endl;
    }

    {
        typedef Blob<string> StrBlob;
        StrBlob sb;

        BLOB<string>    sbb;
    }

    {
        Foo<int> tf1, tf2;
        cout << Foo<int>::Count() << ", "
             << tf1.Count() << ", "
             << tf2.Count() << endl;
    }
}

void ch_16_1_3()
{
    /* 使用类类型成员 */
    {
        vector<int> ivec;
        cout << Top(ivec) << endl;
    }

    /* 模板默认实参与类模板 */
    {
        Numbers<long double> n1;
        Numbers<> n2;
    }
}

void ch_16_1_4()
{
    /* 普通（非模板）类的成员模板 */
    {
        double* p = new double;
        DebugDelete d;
        d(p);

        unique_ptr<int, DebugDelete> up(new int, DebugDelete());
    }

    /* 类模板的成员模板 */
    {
        //vector
    }
}

template <typename T>
void PrintV(const T &v)
{
    // for (typename T::size_type i = 0; i != v.size(); ++i)
    //     cout << v[i] << " ";

    for (auto i = v.begin(); i != v.end(); i++)
        cout << v[i] << " ";
    
    cout << endl;
}
