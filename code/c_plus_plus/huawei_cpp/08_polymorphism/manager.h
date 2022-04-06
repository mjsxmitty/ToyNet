

#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"


class Manager : virtual public Employee
{
public:
    Manager();
    ~Manager();
public:
    void promote(int increment = 0);
    void getPay();
    void disInfor();
protected:
    float fixSalay;
};

#endif // MANAGER_H
