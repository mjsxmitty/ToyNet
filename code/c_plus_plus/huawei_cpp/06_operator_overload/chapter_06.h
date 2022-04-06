

#ifndef __HUAWEI_CHAPTER_06_OPERATE_OVERLOAD_H__
#define __HUAWEI_CHAPTER_06_OPERATE_OVERLOAD_H__

#include <cstddef>
#include <iostream>

void Chapter_06();

void Practice_6_1();
void Practice_6_4();
void Practice_6_5();

class Com
{
public:
    int operator()(int i)
    {
        return i * i;
    }

    int operator()(double d)
    {
        return d * d;
    }

    bool operator()(int i, int j) { return i > j; }
};

//void *operator new(size_t);
//void operator delete(void *);
//void *operator new[](size_t);
//void operator delete[](void *);

using namespace std;
class B {
public:
    B()
    {
        cout<<"b constructor"<<endl;
    }
    ~B()
    {
        cout<<"b destructor"<<endl;
    }

    void * operator new (size_t size)
    {
        cout<<"new "<< size <<endl;
        void *p = malloc(size); // ((B*)p)->a = 100;
        cout<<"new "<< size << " end"<<endl;
        return p;
    }
    void operator delete(void *p)
    {
        cout<<"delete"<<endl;
        free(p);
    }
    void * operator new[] (size_t size)
    {
        cout<<"new[] "<<size<<endl;
        void *p = malloc(size);
        cout<<"new "<< size << " end"<<endl;
        return p;
    }
    void operator delete[](void *p)
    {
        cout<<"delete[] "<<endl;
        free(p);
    }
private:
        int a;
};

#endif // __HUAWEI_CHAPTER_06_OPERATE_OVERLOAD_H__
