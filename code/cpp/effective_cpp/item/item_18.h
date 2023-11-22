
#ifndef __EFFECTIVE_CPP_ITEM_18_H__
#define __EFFECTIVE_CPP_ITEM_18_H__

#include <memory>

void Item18();

namespace effective_item_18 {

class Month {
public:
    static Month Jan() { return Month(1); } // 函数，返回有效月份
    static Month Feb() { return Month(2); }

    static Month Dec() { return Month(12); }
    // 其它成员函数
private:
    explicit Month(int m); // 阻止生成新的月份
    // 月份专属数据
};

class Day {
public:

};

class Year {
public:

};

class Date
{
public:
    //Date(int mouth, int day, int year) {}
    Date(const Month &, const Day &, const Year &) {}
};

class Investment{};
std::shared_ptr<Investment> CreateInvestment();
void GetRaidOfInvestment(Investment *);
}

#endif // __EFFECTIVE_CPP_ITEM_18_H__
