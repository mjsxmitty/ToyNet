

#ifndef __MY_ACCOUNT_H__
#define __MY_ACCOUNT_H__

class Account
{
public:
    static double m_rate;
public:
    static void set_rate(const double &rate);
};

double Account::m_rate = 8.0;

void Account::set_rate(const double &rate)
{
    m_rate = rate;
}

void CallAccount()
{
    Account::set_rate(5.0);

    Account a;
    a.set_rate(6.0);
} 


class Single
{
public:
    static Single& GetInstance();
private:
    Single() {};
    Single(const Single &rhs);
};

Single& Single::GetInstance()
{
    static Single item;
    return item;
}


#endif //


