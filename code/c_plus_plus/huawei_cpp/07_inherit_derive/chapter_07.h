
#ifndef __HUAWEI_CHAPTER_07_INHERIT_DERIVE_H__
#define __HUAWEI_CHAPTER_07_INHERIT_DERIVE_H__

#include <iostream>

void Chapter_07();

void Practice_7_3();
void Practice_7_7();
void Practice_7_9();
void Practice_7_11();

using namespace std;

class Student
{
    friend ostream &operator<<(ostream & out, Student & stu);
private:
    int a;
    int b;
};

//ostream &operator<<(ostream &out, Student &stu)
//{
//    out<<stu.a<<"--"<<stu.b<<endl;
//}

//class Graduate : public Student
//{
//    friend ostream &operator<<(ostream & out, Graduate &gra);
//private:
//    int c;
//    int d;
//};

//ostream &operator<<(ostream &out, Graduate &gra)
//{
//    //out << (Student &)gra << endl;
//    out << static_cast<Student &>(gra) << endl;
//    out<<gra.c<<"**"<<gra.d<<endl;
//}

class Base
{
public:
    void func(int)
    {
        cout<<"haha"<<endl;
    }
};
class Drive:public Base
{
public:
    void func()
    {
        //func(); //func 死循环
        Base::func(1); //被 shadow 的成员，可以这样访问
        cout<<"hehe"<<endl;
    }
};

class Bed
{
public:
    Bed(){}
    ~Bed(){}
    void sleep() {cout << "sleep" << endl;}
};

class Sofa
{
public:
    Sofa(){}
    ~Sofa(){}
    void sit(){cout << "sit" << endl;}
};

class SofaBed : public Sofa, public Bed
{
public:
    SofaBed() {}
    ~SofaBed() {}
};

class M
{
public:
    M(int i):_data(i){}
    int _data;
};

class X : virtual public M
{
public:
    X(int d) : M(d){}
    void setData(int i)
    {
        _data = i;
    }
    //int _data;
};
class Y : virtual public M
{
public:
    Y(int d) : M(d){}
    int getData()
    {
        return _data;
    }
    //int _data;
};
class Z : public X ,public Y
{
public:
    Z(int x, int y): X(x),Y(y), M(100) {}
    void dis()
    {
        cout<<X::_data<<endl;
        cout<<Y::_data<<endl;
    }
};

#endif // __HUAWEI_CHAPTER_07_INHERIT_DERIVE_H__
