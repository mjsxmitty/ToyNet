
#ifndef __CPP_CHAPTER_08_HPP__
#define __CPP_CHAPTER_08_HPP__

#include <iostream>

using namespace std;

namespace chapter_08
{

void Test1();
void Test2();
void Test3();
void Test4();
void Test5();

class Base
{
public:
    Base()
    {
        cout << "Base::Base()" << endl;
    }

    void Hello()
    {
        cout << "Base::Hello()" << endl;
    }

    virtual ~Base()
    {
        cout << "Base::~Base()" << endl;
    }
};

class Children : public Base
{
public:
    Children()
    {
        cout << "Children::Children()" << endl;
        ptr_ = new char;
    }

    ~Children()
    {
        cout << "Children::~Children()" << endl;
        if (ptr_ != nullptr)
        {
            delete ptr_;
            ptr_ = nullptr;
        }
    }
private:
    char *ptr_;
};


void Test6();

template <typename T>
class PreDistribution
{
public:
    PreDistribution(int count) : num_(count)
    {
        data_ = new T [count];
    }

    ~PreDistribution()
    {
        if (data_ != nullptr)
        {
            delete [] data_;
            data_ = nullptr;
        }
    }

    T* operator[](int index)
    {
        return &data_[index];
    }
private:
    T   *data_;
    int num_;
};
}

#endif //__CPP_CHAPTER_08_HPP__
