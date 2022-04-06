

#ifndef __SPECIALIZATION_H__
#define __SPECIALIZATION_H__

/*特化*/
template<typename T>
struct Hash
{
    /* data */
};

template<>
struct Hash<char>
{
    char operator()(char x) const {return x;} 
};

template<>
struct Hash<int>
{
    int operator()(int x) const {return x;}
};

template<>
struct Hash<double>
{
    double operator()(double x) const { return x; }
};

void TestSpecialization();

/*偏特化--个数*/
template<typename T, typename Y>
class Vector {};

template<typename Y>
class Vector<bool, Y> {};

/*偏特化---范围*/

template<typename T>
class C
{

};

//由任意类型变为指针类型（范围缩小）
template<typename U>
class C<U*>
{

};

//C<string> obj;
//C<string*> obj2;

#endif //__SPECIALIZATION_H__
