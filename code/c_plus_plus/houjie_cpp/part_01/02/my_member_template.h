

#ifndef __MEMBER_TEMPLATE_H__
#define __MEMBER_TEMPLATE_H__

template<typename T1, typename T2>
class Pair
{
public:
    typedef T1  FirstType;
    typedef T2  SecondType;
public:
    T1  first;
    T2  second;
public:
    Pair() : first(T1()), second(T2()){}
    Pair(const T1 &a, const T2 &b) : T1(a), T2(b) {}

    template<typename U1, typename U2>
    Pair(const Pair<U1, U2> &p) : first(p.first), second(p.second) {}
    //~Pair();
};




#endif //__MEMBER_TEMPLATE_H__
