
#include "../chapter04/chapter04_grade.h"
#include "../chapter04/chapter04_median.h"
#include "chapter06_student.h"

#include <algorithm>
#include <numeric>

using std::transform;
using std::accumulate;
using std::back_inserter;
using std::vector;

using Chapter04::StudentInfo;

namespace Chapter06
{
    double GradeAux(const StudentInfo &s)
    {
        try {
            return Chapter04::Grade(s);
        } catch(const std::exception& e) {
            //std::cerr << e.what() << '\n';
            return Chapter04::Grade(s.midterm, s.final, 0);
        }
    }

    double MedianAnalysis(const vector<StudentInfo>& students)
    {   
        vector<double> ret;
        transform(students.begin(), students.end(), back_inserter(ret), GradeAux);
        return Chapter04::Median(ret);
    }

    double Average(const vector<double>& v)
    {
        return accumulate(v.begin(), v.end(), 0.0) / v.size();
    }

    double AverageGrade(const StudentInfo& s)
    {
        return Chapter04::Grade(s.midterm, s.final, Average(s.homework));
    }

    double AverageAnalysis(const vector<StudentInfo>& students)
    {
        vector<double> ret;
        transform(students.begin(), students.end(), back_inserter(ret), AverageGrade);
        return Chapter04::Median(ret);
    }
} // namespace Chapter06
