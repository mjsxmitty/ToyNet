

#ifndef __HUAWEI_CHAPTER_08_POLYMORPHISM_H__
#define __HUAWEI_CHAPTER_08_POLYMORPHISM_H__

#include <iostream>

using namespace std;

void Chapter_08();

void Practice_8_2();
void Practice_8_4();
void Practice_8_5();

class VA
{
public:
    virtual void func()
    {
        cout<<"aaaaaaaaaaa"<<endl;
    }

};

class VB : virtual public VA {
public:
     void func()
     {
         cout<<"bbbbbbbbbbb"<<endl;
     }
};
class VC : virtual public VA
{
public:
     void func()
     {
         cout<<"cccccccccc"<<endl;
     }
};
class VD : public VB, public VC
{
public:

    void func()
    {
        cout<<"ddddddddddd"<<endl;
    }
};

class VBase
{
public:
    //virtual ~VBase(){}
};

class VDerive:public VBase
{

};

#endif // __HUAWEI_CHAPTER_08_POLYMORPHISM_H__
