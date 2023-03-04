

#ifndef __ACCELERATED_CPP_STUDENTINFO_H__
#define __ACCELERATED_CPP_STUDENTINFO_H__

#include <iostream>
#include <string>
#include <vector>

namespace chapter_09
{

class StudentInfo
{
public:
    StudentInfo() : midterm_(0.0), final_(0.0) {}
    StudentInfo(std::istream &in) { Read(in); }
public:
    std::string name() const { return name_; }
    bool Valid() const { return !homework_.empty(); }
    std::istream &Read(std::istream &in);
    double Grade() const;
private:
    std::string         name_;
    double              midterm_, final_;
    std::vector<double> homework_;
};

} // namespace chapter_08


#endif //__ACCELERATED_CPP_STUDENT_INFO_H__
