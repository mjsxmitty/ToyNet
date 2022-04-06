
#include <stdexcept>
#include "chapter04_grade.h"
#include "chapter04_median.h"

using std::domain_error;

#define SCORE   60

namespace Chapter04
{

    double Grade(double midterm, double final, double homework)
    {
        return 0.2 * midterm + 0.4 * final + 0.4 * homework;
    }

    double Grade(double midterm, double final, const std::vector<double> &hw)
    {
        if (hw.empty()) {
            throw domain_error("student has done no homework.");
        }
        
        return Grade(midterm, final, Median(hw));
    }

    double Grade(const StudentInfo &s)
    {
         return Grade(s.midterm, s.final, s.homework);
    }

    bool FGrade(const StudentInfo &s)
    {
        return Grade(s) < SCORE;
    }
} // namespace Chapter04
