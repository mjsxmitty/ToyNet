
#include "item_12.h"
#include <iostream>

using namespace effective_item_12;

/* 赋值对象勿忘其每一部分 */
void Item12()
{
    std::cout << "**********item 12**********" << std::endl;
#if 1
    Customer c1("c1", "12");
    Customer c2(c1);
    std::cout << c2.name_ << ", " << c2.date_ << std::endl;
#endif
    std::cout << "***************************" << std::endl;
}

namespace effective_item_12 {

Customer::Customer(const Customer &rhs) : name_(rhs.name_){}
Customer& Customer::operator=(const Customer &rhs)
{
    name_ = rhs.name_;
    return *this;
}

PriorityCustomer::PriorityCustomer() : Customer("", ""), priority_(0)
{

}
PriorityCustomer::PriorityCustomer(const PriorityCustomer &rhs) : Customer(rhs), priority_(rhs.priority_)
{

}
PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer &rhs)
{
    Customer::operator=(rhs);
    priority_ = rhs.priority_;
    return *this;
}

}
