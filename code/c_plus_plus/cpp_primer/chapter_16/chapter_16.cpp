

#include "chapter_16.h"
#include "../common/blob.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

void Chapter_16()
{
    //Practice_16_1_1();
    Practice_16_1_2();
    
    //Homework_16_4();
    //Homework_16_5();
}

void Practice_16_1_1()
{
    //TODO
    cout << Compare("hi", "hello") 
         << ", " << strcmp("hi", "hello") 
         << endl;

    cout << Compare(1, 3) << ", " 
         << Compare(string("hi"), string("hello")) 
         << endl;

    string s1("hi"), s2("hello");
    cout << Compare(s1, s2) << endl;
}


void Homework_16_4()
{
    vector<int> vec = {1, 23 ,43 ,3, 45,6,11};
    list<string> lst = {"hello", "hi", "nihao"};

    auto iter = Find(vec.begin(), vec.end(), 6);
    if (iter == vec.end())
        cout << "can not find value." << endl;
    else
        cout << "find value position: " 
             << iter - vec.begin() << endl;

    auto iter1 = Find(lst.begin(), lst.end(), "!");
    if (iter1 == lst.end())
        cout << "can not find value." << endl;
    else
        cout << "find value position: " 
             << iter - vec.begin() << endl;
}

void Homework_16_5()
{
    int iarray[5] = {1, 3 ,5 ,23, 6};
    string sarray[4] = {"nihao", "hi", "hello"};

    Print(iarray);
    Print(sarray);
}

void Practice_16_1_2()
{
    Blob<int>       ia = {1,2,3,4,5,6,7,8,9};
    Blob<string>    sa = {"hello", "hi", "nihao"};

    for (size_t i = 0; i != ia.Size(); i++)
        ia[i] = i * i;
    
    for (size_t i = 0; i < ia.Size(); i++)
        cout << ia[i] << " ";
    cout << endl;
    

    typedef Blob<string> StrBlob;
    StrBlob sb;

    BLOB<string>    sbb;

    TFoo<int> tf1, tf2;
    cout << TFoo<int>::Count() << ", " << tf1.Count() << ", " << tf2.Count() << endl;
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
