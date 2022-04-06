#ifndef SALESMAN_H
#define SALESMAN_H

#include "employee.h"

class SalesMan : virtual public Employee
{
public:
    SalesMan();
    ~SalesMan();
public:
    virtual void promote(int increment = 0) ;
    virtual void getPay();
    virtual void disInfor();
protected:
    float saleAmount;
    float persent;
};

#endif // SALESMAN_H
