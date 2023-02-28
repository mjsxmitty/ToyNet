
#include <stdexcept>
#include "grade.h"
#include "median.h"

using std::domain_error;

namespace chapter_04
{

double Grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double Grade(double midterm, double final, const std::vector<double> &hw)
{
    if (hw.empty())
    {
        throw domain_error("student has done no homework.");
    }
    
    return Grade(midterm, final, Median(hw));
} 

double Grade(const StudentInfo &s)
{
    return Grade(s.midterm, s.final, s.homework);
}

#define SCORE   60

bool FGrade(const StudentInfo &s)
{
    return Grade(s) < SCORE;
}

bool PGrade(const StudentInfo &s)
{
    return !FGrade(s);
}

} // namespace chapter_04
