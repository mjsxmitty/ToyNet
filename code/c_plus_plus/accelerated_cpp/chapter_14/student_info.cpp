
#include "student_info.h"
#include "../chapter_13/grad.h"

namespace chapter_14 {

std::istream& StudentInfo::Read(std::istream &in)
{
    char ch;
    in >> ch;

    if (ch == 'U')
        cp_ = new chapter_13::Core(in);
    else
        cp_ = new chapter_13::Grad(in);
    
    return in;
}

void StudentInfo::ReGrade(double final, double thesis)
{
    cp_.make_unique();
    if (cp_)
        cp_->Regrade(final, thesis);
    else
        throw std::runtime_error("regrade of unknow student.");
}

}