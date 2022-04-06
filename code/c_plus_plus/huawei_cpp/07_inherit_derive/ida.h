

#ifndef __HUAWEI_CHAPTER_07_IDA_H__
#define __HUAWEI_CHAPTER_07_IDA_H__


#include <iostream>
#include <typeinfo>

using namespace std;

class IDA {
public:
    IDA()
    {
        cout<<this<<", "<<typeid(this).name()<<endl;
    }
    int a;
};

class IDB : public IDA {
public:
    IDB()
    {
        cout<<this<<", "<<typeid(this).name()<<endl;
    }

int b;
};

class IDC : public IDB {
public:
    IDC()
    {
        cout<<this<<", "<<typeid(this).name()<<endl;
    }
    void func()
    {
        cout<<&a<<endl;
        cout<<&b<<endl;
        cout<<&c<<endl;
    }
int c;
};

#endif // __HUAWEI_CHAPTER_07_IDA_H__
