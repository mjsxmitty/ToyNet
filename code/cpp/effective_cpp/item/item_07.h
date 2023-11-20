

#ifndef __EFFECTIVE_CPP_ITEM_07_H__
#define __EFFECTIVE_CPP_ITEM_07_H__

#include <iostream>

void Item07();

namespace effective_item_07 {

class TimeKeeper
{
public:
    TimeKeeper()
    {
        std::cout << "TimeKeeper default constructor fcuntion." << std::endl;
    }

    virtual ~TimeKeeper()
    {
        std::cout << "TimeKeeper destructor fcuntion." << std::endl;
    }
};

class AtomicClock : public TimeKeeper
{
public:
    AtomicClock()
    {
        std::cout << "AtomicClock default constructor fcuntion." << std::endl;
    }

    ~AtomicClock()
    {
        std::cout << "AtomicClock destructor fcuntion." << std::endl;
    }
};

TimeKeeper* GetTimeKeeper();

class Point
{
public:
    Point(int x, int y) {}
    virtual ~Point() {}
private:
    int x_, y_;
};

}

#endif // __EFFECTIVE_CPP_ITEM_07_H__
