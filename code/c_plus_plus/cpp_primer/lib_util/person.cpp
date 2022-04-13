
#include "person.h"

#include <iostream>

using std::istream;
using std::ostream;

Person::Person(istream &in)
{
    Read(in, *this);
    //in >> *this;
}

istream& Read(istream &in, Person &lhs)
{
    in >> lhs.name_ >> lhs.address_;
    return in;
}

ostream& Print(ostream &out, const Person &lhs)
{
    out << lhs.GetName() << " " << lhs.GetAddress();
    return out;
}
