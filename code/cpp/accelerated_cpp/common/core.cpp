
#include "core.h"
#include "grade.h"

double Core::Grade() const
{
    return ::Grade(midterm_, final_, homework_);
}

std::istream& Core::ReadCommon(std::istream &in)
{
    in >> name_ >> midterm_ >> final_;
    return in;
}

std::istream& Core::Read(std::istream &in)
{
    ReadCommon(in);
    ReadHw(in, 3, homework_);
    return in;
}
