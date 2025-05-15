
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

extern bool Compare(const StudentInfo &, const StudentInfo &);

extern std::istream& ReadHw(std::istream &in,  std::vector<double> &);
extern std::istream& Read(std::istream &in, StudentInfo &);

typedef double (*Analysis)(const std::vector<StudentInfo> &);

extern bool DidAllHW(const StudentInfo &s);
extern void WriteAnalysis(std::ostream &os, const std::string &name, Analysis,
                          std::vector<StudentInfo> &did, std::vector<StudentInfo> &didnt);
extern double MedianAnalysis(const std::vector<StudentInfo> &students);
extern double AverageAnalysis(const std::vector<StudentInfo> &students);
extern double OptimisticAnalysis(const std::vector<StudentInfo> &students);

extern std::vector<StudentInfo> ExtractFails(std::vector<StudentInfo> &students);

namespace ver1
{
class StudentInfo
{
public:
    StudentInfo() : midterm_(0.0), final_(0.0) {}
    StudentInfo(std::istream &in) { Read(in); }
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

}

#include "core.h"

class StudentInfo3
{
public:
    StudentInfo3() : cp_(0) {}
    StudentInfo3(std::istream &in) : cp_(0) { Read(in); }
    StudentInfo3(const StudentInfo3 &rhs);
    StudentInfo3& operator=(const StudentInfo3 &rhs);
    ~StudentInfo3() { delete cp_; }
public:
    std::istream& Read(std::istream &in);
    std::string name() const
    {
        if (cp_)
            return cp_->name();
        else
            throw std::domain_error("uninit student.");
    }

    double grade() const
    {
        if (cp_)
            return cp_->Grade();
        else
            throw std::domain_error("uninit student.");
    }

    static bool compare(const StudentInfo3 &lhs,
                        const StudentInfo3 &rhs)
    {
        return lhs.name() < rhs.name();
    }
private:
    Core* cp_;
};

#include "handle.hpp"

class StudentInfo4
{
public:
    StudentInfo4() {}
    StudentInfo4(std::istream &in) { Read(in); }
public:
    std::istream& Read(std::istream &in);
    std::string name() const
    {
        if (cp_)
            return cp_->name();
        else
            throw std::domain_error("uninit student.");
    }

    double grade() const
    {
        if (cp_)
            return cp_->Grade();
        else
            throw std::domain_error("uninit student.");
    }

    static bool compare(const StudentInfo4 &lhs,
                        const StudentInfo4 &rhs)
    {
        return lhs.name() < rhs.name();
    }

    void ReGrade(double final, double thesis);
private:
    Ptr<Core> cp_;
};

#endif //__ACCELERATED_CPP_STUDENT_INFO_H__
