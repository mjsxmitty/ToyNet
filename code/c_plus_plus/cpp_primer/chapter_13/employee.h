

#ifndef __CPP_PRIMER_CHAPTER_13_GZEmployee_H__
#define __CPP_PRIMER_CHAPTER_13_GZEmployee_H__

#include <string>

class GZEmployee
{
public:
    GZEmployee() { my_sn_ = sn++; }
    GZEmployee(const std::string &s) : name_(s) { my_sn_ = sn++; }
    GZEmployee(const GZEmployee &e) { name_ = e.name_; my_sn_ = sn++; }
    GZEmployee& operator=(const GZEmployee &e) { name_ = e.GetName(); my_sn_ = e.my_sn_; return *this; }
public:
    const std::string&  GetName() const { return name_; }
    int                 GetMySn() const { return my_sn_; }
private:
    std::string name_;
    int         my_sn_;
    static int  sn;
};

void PrintGZEmployee(const GZEmployee &e);

#endif // __CPP_PRIMER_CHAPTER_13_GZEmployee_H__
