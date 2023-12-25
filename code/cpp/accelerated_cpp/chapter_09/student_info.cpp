
#include <iostream>
#include <vector>

#include "student_info.h"
#include "../common/student_info.h"
#include "grade.h"

using std::vector;

namespace ver2 {

std::istream &StudentInfo::Read(std::istream &in)
{
    return ReadHw(in, 3, homework_);
}

double StudentInfo::Grade() const
{
    return ::Grade(midterm_, final_, homework_);
}

}
