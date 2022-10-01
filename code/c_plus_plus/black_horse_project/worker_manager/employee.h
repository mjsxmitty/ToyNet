
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <string>

#include "worker.h"

class Employee : public Worker
{
public:
    Employee(int id, std::string name, int did);
    void ShowInfo() const;
    std::string GetDeptName() const;
};

#endif

