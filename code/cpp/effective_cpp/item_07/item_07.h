

#ifndef __EFFECTIVE_CPP_ITEM_07_H__
#define __EFFECTIVE_CPP_ITEM_07_H__

#include <iostream>

class TimeKeeper
{
public:
    TimeKeeper()
    {
        std::cout << "TimeKeeper default constructor fuction." << std::endl;
    }

    virtual ~TimeKeeper()
    {
        std::cout << "TimeKeeper destructor fuction." << std::endl;
    }
};

class AtomicClock : public TimeKeeper
{
public:
    AtomicClock()
    {
        std::cout << "AtomicClock default constructor fuction." << std::endl;
    }

    ~AtomicClock()
    {
        std::cout << "AtomicClock destructor fuction." << std::endl;
    }
};

class Point
{
public:
    Point(int x, int y) {}
    virtual ~Point() {}
private:
    int x_, y_;
};

class SpecialString : public std::string     // string 不存在虚函数
{

};

class AMOV
{
public:
    virtual ~AMOV() = 0;
};

#endif // __EFFECTIVE_CPP_ITEM_07_H__
