
#include "core.h"
#include "../chapter_04/grade.h"


namespace chapter_13 {

double Core::Grade() const
{
    return chapter_04::Grade(midterm_, final_, homework_);
}

std::istream& Core::ReadCommon(std::istream &in)
{
    in >> name_ >> midterm_ >> final_;
    return in;
}

std::istream& Core::Read(std::istream &in)
{
    ReadCommon(in);
    chapter_04::ReadHw(in, homework_);
    return in;
}
}