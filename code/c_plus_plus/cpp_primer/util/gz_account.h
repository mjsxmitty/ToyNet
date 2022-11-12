

#ifndef __GZ_ACCOUNT_H__
#define __GZ_ACCOUNT_H__

#include <string>

void GZPractice_7_6();

// 7.6 类的静态成员
class GZAccount
{
public:
    //使用类的静态成员
    void            Calculate() {amount_ += amount_ * interest_rate_; }

    static double   Rate() { return interest_rate_; }
    static void     Rate( double );
private:
    std::string     owner_;
    double          amount_;

    static double   interest_rate_;
    static double InitRate();

    //静态成员的类内初始化
    static constexpr int period_ = 30;
    double daily_tbl_[period_];
};

#endif // __GZ_ACCOUNT_H__
