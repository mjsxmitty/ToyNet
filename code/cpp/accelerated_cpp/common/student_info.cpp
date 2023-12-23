
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "student_info.h"
#include "grade.h"
#include "median.h"

using std::transform;
using std::accumulate;
using std::back_inserter;
using std::vector;

bool Compare(const StudentInfo &lhs, const StudentInfo &rhs)
{
    return lhs.name < rhs.name;
}

std::istream& Read(std::istream &is, size_t num, StudentInfo &s)
{
    std::cout << "Please enter name, midterm and final: ";
    is >> s.name >> s.midterm >> s.final;
    ReadHw(is, num, s.homework);
    return is;
}

std::istream& ReadHw(std::istream &in, size_t num, std::vector<double> &hw)
{
    std::cout << "Please enter homeworks: ";

    if (in)
    {
        hw.clear();
        double x;
        while (in >> x)
        {
            hw.push_back(x);
            if (hw.size() == num)
                break;
        }
            
        in.clear();
    }
    
    return in;
}

bool DidAllHW(const StudentInfo &s)
{
    return ((std::find(s.homework.begin(), s.homework.end(), 0)) != s.homework.end());
}

void WriteAnalysis(std::ostream &os, const std::string &name, 
                    double (*Analysis)(const std::vector<StudentInfo> &),
                    std::vector<StudentInfo> &did,
                    std::vector<StudentInfo> &didnt)
{
    os << name << ", (did)=" << Analysis(did)
                << ", (didnt)=" << Analysis(didnt)
                << std::endl;
}

double GradeAux(const StudentInfo &s)
{
    try {
        return Grade(s);
    } catch(const std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
        return Grade(s.midterm, s.final, 0);
    }
}

double MedianAnalysis(const vector<StudentInfo>& students)
{   
    vector<double> ret;
    transform(students.begin(), students.end(), back_inserter(ret), GradeAux);
    return Median(ret);
}

double Average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double AverageGrade(const StudentInfo& s)
{
    return Grade(s.midterm, s.final, Average(s.homework));
}

double AverageAnalysis(const vector<StudentInfo>& students)
{
    vector<double> ret;
    transform(students.begin(), students.end(), back_inserter(ret), AverageGrade);
    return Median(ret);
}

double OptimisticGrade(const StudentInfo& s)
{
    std::vector<double> nozero;
    std::remove_copy(s.homework.begin(), s.homework.end(), 
                        std::back_inserter(nozero), 0);
    if (nozero.empty())
        return Grade(s.midterm, s.midterm, 0);
    else
        return Grade(s.midterm, s.final, Median(s.homework));
}

double OptimisticAnalysis(const std::vector<StudentInfo> &students)
{
    std::vector<double> ret;
    std::transform(students.begin(), students.end(), std::back_inserter(ret), OptimisticGrade);
    return Median(ret);
}

std::vector<StudentInfo> ExtractFails(std::vector<StudentInfo> &students)
{
#if 0
    std::vector<StudentInfo> fail;
    std::remove_copy_if(students.begin(), students.end(), std::back_inserter(fail),
                            PGrade);
    
    students.erase(std::remove_if(students.begin(), students.end(), FGrade), students.end());
#endif
    std::vector<StudentInfo>::iterator it = 
                std::stable_partition(students.begin(), students.end(),PGrade);
    std::vector<StudentInfo> fail(it, students.end());
    students.erase(it, students.end());
    
    return fail;
}
