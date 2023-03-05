
#include "student_info.h"
#include "grad.h"

namespace chapter_13 {

std::istream& StudentInfo::Read(std::istream &in)
{
    delete cp_;

    char c;
    in >> c;

    if (c == 'U')
        cp_ = new Core(in);
    else
        cp_ = new Grad(in);
    

    return in;
}

StudentInfo::StudentInfo(const StudentInfo &s) : cp_(0)
{
    if (s.cp_)
        cp_ = s.cp_->clone();
}

StudentInfo& StudentInfo::operator=(const StudentInfo &s)
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

}