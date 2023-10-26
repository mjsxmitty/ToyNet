
#include <iostream>
#include <vector>

#include "student_info.h"
#include "../chapter_04/student_info.h"
#include "../chapter_04/grade.h"

using std::vector;

namespace chapter_09
{

std::istream &StudentInfo::Read(std::istream &in)
{
    return chapter_04::ReadHw(in, homework_);
}

double StudentInfo::Grade() const
{
    return chapter_04::Grade(midterm_, final_, homework_);
}


} // namespace chapter_04

