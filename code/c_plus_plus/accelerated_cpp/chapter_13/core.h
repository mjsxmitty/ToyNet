
#ifndef __ACCELERATED_CPP_CORE_H__
#define __ACCELERATED_CPP_CORE_H__

#include <iostream>
#include <vector>
#include <string>

namespace chapter_13 {

class Core
{
public:
    Core() : midterm_(0), final_(0) {}
    Core(std::istream &in) { Read(in); }
public:
    std::string name() const { return name_; }
    std::istream &Read(std::istream &in);
    double Grade() const;
protected:
    std::istream& ReadCommon(std::istream &in);
    double              midterm_, final_;
    std::vector<double> homework_;
private:
    std::string         name_;
};

} // chapter_13


#endif // __ACCELERATED_CPP_CORE_H__