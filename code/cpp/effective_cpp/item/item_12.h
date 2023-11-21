
#ifndef __EFFECTIVE_CPP_ITEM_12_H__
#define __EFFECTIVE_CPP_ITEM_12_H__

#include <string>

void Item12();

namespace effective_item_12 {

class Customer
{
public:
    Customer(const std::string &name, const std::string &date):name_(name), date_(date){}
    Customer(const Customer &rhs);
    Customer& operator=(const Customer &rhs);
public:
    std::string name_;
    std::string date_;
};

class PriorityCustomer : public Customer
{
public:
    PriorityCustomer();
    PriorityCustomer(const PriorityCustomer &rhs);
    PriorityCustomer& operator=(const PriorityCustomer &rhs);
public:
    int priority_;
};

}

#endif // __EFFECTIVE_CPP_ITEM_12_H__
