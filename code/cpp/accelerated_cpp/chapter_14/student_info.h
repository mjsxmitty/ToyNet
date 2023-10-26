
#ifndef __ACCELERATED_CPP_STUDENT1_H__
#define __ACCELERATED_CPP_STUDENT1_H__

#include <iostream>
#include <string>
#include <exception>

#include "../chapter_13/core.h"
#include "ptr.hpp"

namespace chapter_14 {

class StudentInfo
{
public:
    StudentInfo() {}
    StudentInfo(std::istream &in) { Read(in); }
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

    void ReGrade(double final, double thesis);
private:
    Ptr<chapter_13::Core> cp_;
};



}

#endif // __ACCELERATED_CPP_STUDENT_H__