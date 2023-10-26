
#include "grad.h"
#include "../chapter_04/grade.h"
#include <algorithm>

namespace chapter_13 {

std::istream& Grad::Read(std::istream &in)
{
    ReadCommon(in);
    chapter_04::ReadHw(in, homework_);
    in >> thesis_;
    return in;
}

double Grad::Grade() const
{
    return std::min(Core::Grade(), thesis_);
}

}