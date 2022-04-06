

#ifndef __CHAPTER04_GRADE_H__
#define __CHAPTER04_GRADE_H__

#include "chapter04_student_info.h"

namespace Chapter04
{

double Grade(double, double, double);
double Grade(double, double, const std::vector<double>&);
double Grade(const StudentInfo &);

bool FGrade(const StudentInfo &);
} // namespace Chapter04


#endif //__CHAPTER04_GRADE_H__
