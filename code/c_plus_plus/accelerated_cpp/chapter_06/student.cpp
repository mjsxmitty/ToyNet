
#include "../chapter_04/grade.h"
#include "../chapter_04/median.h"
#include "student.h"

#include <algorithm>
#include <numeric>

using std::transform;
using std::accumulate;
using std::back_inserter;
using std::vector;

using chapter_04::StudentInfo;

namespace chapter_06
{

bool DidAllHW(const chapter_04::StudentInfo &s)
{
    return ((std::find(s.homework.begin(), s.homework.end(), 0)) != s.homework.end());
}

void WriteAnalysis(std::ostream &os, const std::string &name, 
                    double (*Analysis)(const std::vector<chapter_04::StudentInfo> &),
                    std::vector<chapter_04::StudentInfo> &did,
                    std::vector<chapter_04::StudentInfo> &didnt)
{
    os << name << "median(did)=" << Analysis(did)
                << "median(didnt)=" << Analysis(didnt)
                << std::endl;
}

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

double OptimisticGrade(const chapter_04::StudentInfo& s)
{
    std::vector<double> nozero;
    std::remove_copy(s.homework.begin(), s.homework.end(), 
                        std::back_inserter(nozero), 0);
    if (nozero.empty())
        return chapter_04::Grade(s.midterm, s.midterm, 0);
    else
        return chapter_04::Grade(s.midterm, s.final, chapter_04::Median(s.homework));
}

double OptimisticAnalysis(const std::vector<chapter_04::StudentInfo> &students)
{
    std::vector<double> ret;
    std::transform(students.begin(), students.end(), std::back_inserter(ret), OptimisticGrade);
    return chapter_04::Median(ret);
}

std::vector<chapter_04::StudentInfo> ExtractFails(std::vector<chapter_04::StudentInfo> &students)
{
    std::vector<chapter_04::StudentInfo> fail;
    std::remove_copy_if(students.begin(), students.end(), std::back_inserter(fail),
                            chapter_04::PGrade);
    
    students.erase(std::remove_if(students.begin(), students.end(), chapter_04::FGrade), students.end());
    return fail;
}

std::vector<chapter_04::StudentInfo> ExtractFails2(std::vector<chapter_04::StudentInfo> &students)
{
    std::vector<chapter_04::StudentInfo>::iterator it = 
                std::stable_partition(students.begin(), students.end(),chapter_04::PGrade);
    std::vector<chapter_04::StudentInfo> fail(it, students.end());
    students.erase(it, students.end());
    return fail;
}

} // namespace chapter_06
