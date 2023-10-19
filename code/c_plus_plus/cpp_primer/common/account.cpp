

#include "account.h"

double GZAccount::interest_rate_ = InitRate();


void GZAccount::Rate(double new_rate)
{
    interest_rate_ = new_rate;
}

double GZAccount::InitRate()
{
    return 0.0;
}

constexpr int GZAccount::period_;

void GZPractice_7_6()
{
    //使用类的静态成员
    double r = GZAccount::Rate();

    GZAccount ac1;
    GZAccount *ac2 = &ac1;
    r = ac1.Rate();
    r = ac2->Rate();
}



