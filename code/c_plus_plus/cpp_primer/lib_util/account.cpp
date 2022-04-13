
#include "account.h"

/* 遇到类关键字其之后都在类的作用域：InitRate()*/
double Account::interest_rate_ = InitRate();
//类外必须定义静态变量
double Account::InitRate()
{
    return 0.0;
}

/* static关键之只出现在声明语句中 */
void Account::Rate(double new_rate)
{
    interest_rate_ = new_rate;
}

/*类外声明*/
constexpr int Account::period_;
