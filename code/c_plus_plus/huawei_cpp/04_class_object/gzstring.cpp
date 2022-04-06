
#include <iostream>
#include <string.h>
#include "gzstring.h"

using namespace std;

GZString::GZString(const char *str)
{
    if (str == nullptr)
    {
        str_ = new char[1];
        *str_ = '\0';
    }
    else
    {
        str_ = new char[strlen(str)];
        strcpy(str_, str);
    }
}

GZString::GZString(const GZString &rhs) //同类对象无私处
{
    //cout << "cp construct func, from content: " << rhs.str_ << endl;
    str_ = new char[strlen(rhs.str_)];
    strcpy(str_, rhs.str_);
}

GZString &GZString::operator=(const GZString &rhs)
{
    if (this == &rhs)
        return *this;

    delete [] str_;
    str_ = new char[strlen(rhs.str_)];
    strcpy(str_, rhs.str_);
    return *this;
}

GZString &GZString::operator+=(const GZString &rhs)
{
    int len = strlen(str_) + strlen(rhs.str_);

    char* temp_str = new char[len + 2];
    memset(temp_str, 0, sizeof(temp_str));

    strcat(temp_str, str_);
    strcat(temp_str, " ");
    strcat(temp_str, rhs.str_);

    delete [] str_;
    str_ = temp_str;
    //cout << "debug str_: " << temp_str << endl;
    return *this;
}

GZString GZString::operator+(const GZString &rhs)
{
    GZString ret(*this);
    return ret += rhs;
}

GZString::~GZString()
{
    delete [] str_;
}

bool GZString::operator==(const GZString &rhs)
{
    return strcmp(str_, rhs.str_) == 0;
}

bool GZString::operator!=(const GZString &rhs)
{
    return !(*this == rhs);
}

bool GZString::operator>(const GZString &rhs)
{
    return strcmp(str_, rhs.str_) > 0;
}

bool GZString::operator<(const GZString &rhs)
{
    return !(*this > rhs);
}

char GZString::operator[](int index)
{
    return str_[index];
}

void GZString::Display()
{
    cout << "content: " << str_ << endl;
}

istream &operator>>(istream &is, GZString &item)
{
    delete [] item.str_;

    string buf;
    getline(is, buf);

    //int len = buf.size();
    item.str_ = new char[buf.size() + 1];
    strcpy(item.str_, buf.c_str());
    return is;
}

ostream &operator<<(ostream &os, const GZString &item)
{
    os << item.str_;
    return os;
}
