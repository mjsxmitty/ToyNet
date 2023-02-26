
#include "../chapter_04/grade.h"
#include "../chapter_04/median.h"
#include "chapter06_student.h"

#include <algorithm>
#include <numeric>

using std::transform;
using std::accumulate;
using std::back_inserter;
using std::vector;

using chapter_04::StudentInfo;

namespace Chapter06
{
    double GradeAux(const StudentInfo &s)
    {
        try {
            return chapter_04::Grade(s);
        } catch(const std::exception& e) {
            //std::cerr << e.what() << '\n';
            return chapter_04::Grade(s.midterm, s.final, 0);
        }
    }

    double MedianAnalysis(const vector<StudentInfo>& students)
    {   
        vector<double> ret;
        transform(students.begin(), students.end(), back_inserter(ret), GradeAux);
        return chapter_04::Median(ret);
    }

    double Average(const vector<double>& v)
    {
        return accumulate(v.begin(), v.end(), 0.0) / v.size();
    }

    double AverageGrade(const StudentInfo& s)
    {
        return chapter_04::Grade(s.midterm, s.final, Average(s.homework));
    }

    double AverageAnalysis(const vector<StudentInfo>& students)
    {
        vector<double> ret;
        transform(students.begin(), students.end(), back_inserter(ret), AverageGrade);
        return chapter_04::Median(ret);
    }
} // namespace Chapter06
