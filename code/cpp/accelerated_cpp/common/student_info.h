
#ifndef __ACCELERATED_CPP_STUDENT_INFO_H__
#define __ACCELERATED_CPP_STUDENT_INFO_H__

#include <iostream>
#include <string>
#include <vector>

struct StudentInfo
{
    std::string     name;
    double          midterm, final;
    std::vector<double> homework;
};

bool Compare(const StudentInfo &, const StudentInfo &);

std::istream& ReadHw(std::istream &in, size_t num, std::vector<double> &);
std::istream& Read(std::istream &in, size_t num, StudentInfo &);

typedef double (*Analysis)(const std::vector<StudentInfo> &);

bool DidAllHW(const StudentInfo &s);
void WriteAnalysis(std::ostream &os, const std::string &name, 
                    Analysis,
                    std::vector<StudentInfo> &did,
                    std::vector<StudentInfo> &didnt);
double MedianAnalysis(const std::vector<StudentInfo> &students);
double AverageAnalysis(const std::vector<StudentInfo> &students);
double OptimisticAnalysis(const std::vector<StudentInfo> &students);

std::vector<StudentInfo> ExtractFails(std::vector<StudentInfo> &students);

class StudentInfo2
{
public:
    StudentInfo2() : midterm_(0.0), final_(0.0) {}
    StudentInfo2(std::istream &in) { Read(in); }
public:
    std::string name() const { return name_; }
    bool Valid() const { return !homework_.empty(); }
    std::istream &Read(std::istream &in);
    double Grade() const;
private:
    std::string         name_;
    double              midterm_, final_;
    std::vector<double> homework_;
};

#endif //__ACCELERATED_CPP_STUDENT_INFO_H__
