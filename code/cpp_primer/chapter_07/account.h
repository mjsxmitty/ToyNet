

#ifndef __CPP_PRIMER_CHAPTER_07_ACCOUNT_H__
#define __CPP_PRIMER_CHAPTER_07_ACCOUNT_H__

#include <string>

class Account
{
public:
    //Account();
public:
    void Calculate() { amount_ += amount_ * interest_rate_; }
    static double Rate() { return interest_rate_; }
    static void Rate(double new_rate);
private:
    std::string     owner_;
    double          amount_;
    static double   interest_rate_;    //利率
    static double   InitRate();

    /*constexpr类型可以类内初始化,初始值是常量表达式*/
    static constexpr int period_ = 30;
    double daily_tbl[period_];

    //static const int aaa = 3;
    //static double bbb = 2.2;
};

#endif // __CPP_PRIMER_CHAPTER_07_ACCOUNT_H__
