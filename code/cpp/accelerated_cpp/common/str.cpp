
#include "str.h"

std::ostream& operator<<(std::ostream &os, const Str &item)
{
    for (Str::size_type i = 0; i != item.Size(); ++i)
        os << item[i];

    return os;
}

std::istream& operator>>(std::istream &in, Str &item)
{
    item.data.Clear();

    char c;
    while(in.get(c) && isspace(c));

    if (in)
    {
        do
        {
            item.data.push_back(c);
        } while (in.get(c) && !isspace(c));

        in.unget();//
    }

    return in;
}

Str operator+(const Str &lhs, const Str &rhs)
{
    Str s = lhs;
    s += rhs;
    return s;
}

