

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee
{
public:
    Employee();
    virtual ~Employee();
public:
    virtual void promote(int increment = 0) =0;
    virtual void getPay() = 0;
    virtual void disInfor() = 0;
protected:
    string name;
    int num;
    int grade;
    float salary;
    static int startNum;
};

#endif // EMPLOYEE_H
