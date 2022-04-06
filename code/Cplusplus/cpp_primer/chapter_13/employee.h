

#ifndef __CPP_PRIMER_CHAPTER_13_EMPLOYEE_H__
#define __CPP_PRIMER_CHAPTER_13_EMPLOYEE_H__

#include <string>

class Employee
{
public:
    Employee() { my_sn_ = sn++; }
    Employee(const std::string &s) : name_(s) { my_sn_ = sn++; }
    Employee(const Employee &e) { name_ = e.name_; my_sn_ = sn++; }
    Employee& operator=(const Employee &e) { name_ = e.GetName(); return *this; }
public:
    const std::string&  GetName() const { return name_; }
    int                 GetMySn() const { return my_sn_; }
private:
    std::string name_;
    int         my_sn_;
    static int  sn;
};

void PrintEmployee(const Employee &e);

#endif // __CPP_PRIMER_CHAPTER_13_EMPLOYEE_H__
