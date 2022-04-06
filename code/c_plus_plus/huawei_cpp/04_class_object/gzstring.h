

#ifndef __HUAWEI_CHAPTER_04_CLASS_OBJECT_GZSTRING_H__
#define __HUAWEI_CHAPTER_04_CLASS_OBJECT_GZSTRING_H__

#include <iostream>

class GZString
{
    friend std::istream& operator>>(std::istream &is, GZString &item);
    friend std::ostream& operator<<(std::ostream &os, const GZString &item);
public:
    GZString(const char *str = nullptr);
    GZString(const GZString &rhs);
    GZString& operator=(const GZString &rhs);
    GZString& operator+=(const GZString &rhs);
    GZString operator+(const GZString &rhs);
    virtual ~GZString();
public:
    bool operator==(const GZString &rhs);
    bool operator!=(const GZString &rhs);
    bool operator>(const GZString &rhs);
    bool operator<(const GZString &rhs);
    char operator[](int index);

    void Display();
private:
    char *str_;
};

std::istream& operator>>(std::istream &is, GZString &item);
std::ostream& operator<<(std::ostream &os, const GZString &item);

#endif // __HUAWEI_CHAPTER_04_CLASS_OBJECT_GZSTRING_H__
