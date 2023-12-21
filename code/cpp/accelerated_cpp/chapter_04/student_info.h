

#ifndef __ACCELERATED_CPP_STUDENT_INFO_H__
#define __ACCELERATED_CPP_STUDENT_INFO_H__

#include <iostream>
#include <string>
#include <vector>

struct StudentInfo
{
    std::string     name;
    double          midterm, final;
    std::vector<double> homework;
};

bool Compare(const StudentInfo &, const StudentInfo &);
std::istream& ReadHw(std::istream &, std::vector<double> &);

//struct StudentInfoHw
//{
//    std::string     name;
//    double          grade;
//};

std::istream& Read(std::istream &, StudentInfo &);

#endif //__ACCELERATED_CPP_STUDENT_INFO_H__
