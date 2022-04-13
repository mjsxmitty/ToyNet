

#ifndef __CPP_PRIMER_ACCOUNT_H__
#define __CPP_PRIMER_ACCOUNT_H__

#include <string>

class Account
{
public:
    /* 7-6 静态成员 */
    //不与任何对象绑定
    //不包含const
    //不包含this
    static double   Rate() { return interest_rate_; }
    static void     Rate(double new_rate);

    //成员函数可以直接使用静态成员
    void            Calculate() { amount_ += amount_ * interest_rate_; }
private:
    std::string     owner_;
    double          amount_;

    static double   interest_rate_;    //利率
    static double   InitRate();

    /* 静态成员类内初始化 */
    //constexpr类型可以类内初始化,初始值是常量表达式
    static constexpr int period_ = 30;
    double daily_tbl[period_];
};

#endif // __CPP_PRIMER_ACCOUNT_H__
