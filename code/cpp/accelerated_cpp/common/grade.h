

#ifndef __ACCELERATED_CPP_GRADE_H__
#define __ACCELERATED_CPP_GRADE_H__

#include <vector>
#include "student_info.h"

extern double Grade(double, double, double);
extern double Grade(double, double, const std::vector<double>&);
extern double Grade(const StudentInfo &);

extern bool FGrade(const StudentInfo &);
extern bool PGrade(const StudentInfo &);


#endif //__ACCELERATED_CPP_GRADE_H__
