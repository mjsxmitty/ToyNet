

#ifndef __ACCELERATED_CPP_GRADE_H__
#define __ACCELERATED_CPP_GRADE_H__

#include "student_info.h"


double Grade(double, double, double);
double Grade(double, double, const std::vector<double>&);
double Grade(const StudentInfo &);

bool FGrade(const StudentInfo &);
bool PGrade(const StudentInfo &);


#endif //__ACCELERATED_CPP_GRADE_H__
