
#include "grad.h"
#include "grade.h"
#include <algorithm>


std::istream& Grad::Read(std::istream &in)
{
    ReadCommon(in);
    ReadHw(in, homework_);
    in >> thesis_;
    return in;
}

double Grad::Grade() const
{
    return std::min(Core::Grade(), thesis_);
}
