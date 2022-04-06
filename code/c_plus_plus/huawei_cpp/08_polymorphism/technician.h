#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include "employee.h"

class Technician : public Employee
{
public:
    Technician();
    ~Technician();
public:
    virtual void promote(int increment = 0) ;
    virtual void getPay() ;
    virtual void disInfor() ;
private:
    int moneyPerHour;
    int hourCount;
};

#endif // TECHNICIAN_H
