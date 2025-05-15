
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <ios>

#include "student_info.h"
#include "grade.h"
#include "median.h"

using namespace std;

bool Compare(const StudentInfo &lhs, const StudentInfo &rhs)
{
    return lhs.name < rhs.name;
}

istream& Read(istream &is, StudentInfo &s)
{
    cout << "Please enter name, midterm and final (or 'exit' to finish): ";
    if (!(is >> s.name) || s.name == "exit")
    {
        is.setstate(ios::failbit);  // 设置失败状态以终止循环
        return is;
    }

    if (!(is >> s.midterm >> s.final))
    {
        cerr << "Error reading midterm/final scores\n";
        is.clear();  // 清除错误状态
        is.ignore(numeric_limits<streamsize>::max(), '\n');  // 跳过当前行(忽略输入流中最多 numeric_limits<streamsize>::max() 个字符，直到遇到换行符 \n（包括换行符本身）)
        is.setstate(ios::failbit);  // 主动标记为失败以终止循环
        return is;
    }

    ReadHw(is, s.homework);

    // 检查是否有作业成绩
    if (s.homework.empty())
    {
        cerr << "Warning: No homework scores entered\n";
    }

    return is;
}

istream& ReadHw(istream &in, vector<double> &hw)
{
    cout << "Please enter homeworks (enter any non-number to finish): ";

    hw.clear();
    double x;
    while (in >> x)  // 当输入非数字时自动停止
        hw.push_back(x);

    // 清除错误状态并忽略错误输入
    in.clear();
    in.ignore(numeric_limits<streamsize>::max(), '\n');

    return in;
}

bool DidAllHW(const StudentInfo &s)
{
    return ((find(s.homework.begin(), s.homework.end(), 0)) != s.homework.end());
}

void WriteAnalysis(ostream &os, const string &name, double (*Analysis)(const vector<StudentInfo> &v),
                   vector<StudentInfo> &did, vector<StudentInfo> &didnt)
{
    os << name
       << ", (did)=" << Analysis(did)
       << ", (didnt)=" << Analysis(didnt)
       << endl;
}

double GradeAux(const StudentInfo &s)
{
    try
    {
        return Grade(s);
    } catch(const exception& e) {
        cerr << "error: " << e.what() << '\n';
        return Grade(s.midterm, s.final, 0);
    }
}

double MedianAnalysis(const vector<StudentInfo>& students)
{
    vector<double> ret;
    transform(students.begin(), students.end(), back_inserter(ret), GradeAux);
    return Median(ret);
}

double Average(const vector<double> &v)
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
    vector<double> nozero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nozero), 0);
    if (nozero.empty())
        return Grade(s.midterm, s.midterm, 0);
    else
        return Grade(s.midterm, s.final, Median(s.homework));
}

double OptimisticAnalysis(const vector<StudentInfo> &students)
{
    vector<double> ret;
    transform(students.begin(), students.end(), back_inserter(ret), OptimisticGrade);
    return Median(ret);
}

vector<StudentInfo> ExtractFails(vector<StudentInfo> &students)
{
#if 0
    vector<StudentInfo> fail;
    remove_copy_if(students.begin(), students.end(), back_inserter(fail), PGrade);
    students.erase(remove_if(students.begin(), students.end(), FGrade), students.end());
#endif

    vector<StudentInfo>::iterator it = stable_partition(students.begin(), students.end(), PGrade);
    vector<StudentInfo> fail(it, students.end());
    students.erase(it, students.end());

    return fail;
}

/***************************************************************************************************/

namespace ver1
{
istream &StudentInfo::Read(istream &in)
{
    return ReadHw(in, homework_);
}

double StudentInfo::Grade() const
{
    return ::Grade(midterm_, final_, homework_);
}
}
/***************************************************************************************************/

#include "grad.h"

istream& StudentInfo3::Read(istream &in)
{
    delete cp_;

    char c;
    in >> c;
    cout << "1" << endl;
    if (c == 'u')
    {
        cp_ = new Core(in);
    }
    else
    {
        cp_ = new Grad(in);
    }


    return in;
}

StudentInfo3::StudentInfo3(const StudentInfo3 &s) : cp_(0)
{
    if (s.cp_)
        cp_ = s.cp_->clone();
}

StudentInfo3& StudentInfo3::operator=(const StudentInfo3 &s)
{
    if (this != &s)
    {
        delete cp_;

        if (s.cp_)
            cp_ = s.cp_->clone();
        else
            cp_ = 0;
    }

    return *this;
}

/***************************************************************************************************/

istream& StudentInfo4::Read(istream &in)
{
    char ch;
    in >> ch;

    if (ch == 'U')
        cp_ = new Core(in);
    else
        cp_ = new Grad(in);

    return in;
}

void StudentInfo4::ReGrade(double final, double thesis)
{
    cp_.make_unique();  // 控制是否复制
    if (cp_)
        cp_->Regrade(final, thesis);
    else
        throw runtime_error("regrade of unknow student.");
}
