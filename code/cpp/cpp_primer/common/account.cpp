

#include "account.h"

double Account::interest_rate_ = InitRate();

void Account::Rate(double new_rate)
{
    interest_rate_ = new_rate;
}

double Account::InitRate()
{
    return 0.0;
}

constexpr int Account::period_;
