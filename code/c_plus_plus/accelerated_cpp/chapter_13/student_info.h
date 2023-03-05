
#ifndef __ACCELERATED_CPP_STUDENT_H__
#define __ACCELERATED_CPP_STUDENT_H__

#include <iostream>
#include <string>
#include <exception>

#include "core.h"

namespace chapter_13 {

class StudentInfo
{
public:
    StudentInfo() : cp_(0) {}
    StudentInfo(std::istream &in) : cp_(0) { Read(in); }
    StudentInfo(const StudentInfo &rhs);
    StudentInfo& operator=(const StudentInfo &rhs);
    ~StudentInfo() { delete cp_; }
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

    static bool compare(const StudentInfo &lhs,
                        const StudentInfo &rhs)
    {
        return lhs.name() < rhs.name();
    }
private:
    Core* cp_;
};

}

#endif // __ACCELERATED_CPP_STUDENT_H__