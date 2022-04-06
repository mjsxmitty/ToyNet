

#ifndef __STUDENT_INFO_H__
#define __STUDENT_INFO_H__

#include <iostream>
#include <string>
#include <vector>

namespace Chapter04
{
struct StudentInfo
{
    std::string     name;
    double          midterm, final;
    std::vector<double> homework;
};

struct StudentInfoHw
{
    std::string     name;
    double          grade;
};

bool Compare(const StudentInfo &, const StudentInfo &);
std::istream& Read(std::istream &, StudentInfo &);
std::istream& ReadHw(std::istream &, std::vector<double> &);

} // namespace Chapter04





#endif //__STUDENT_INFO_H__
