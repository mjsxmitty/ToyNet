
#ifndef __CPP_PRIMER_ACCOUNT_H__
#define __CPP_PRIMER_ACCOUNT_H__

#include <string>

class Account
{
public:
    void            Calculate() {amount_ += amount_ * interest_rate_; }

    static double   Rate() { return interest_rate_; }
    static void     Rate( double );
private:
    std::string     owner_;
    double          amount_;

    static double   interest_rate_;
    static double InitRate();

    static constexpr int period_ = 30;
    double daily_tbl_[period_];
};

#endif // __CPP_PRIMER_ACCOUNT_H__
