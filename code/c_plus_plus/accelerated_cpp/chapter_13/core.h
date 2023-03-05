
#ifndef __ACCELERATED_CPP_CORE_H__
#define __ACCELERATED_CPP_CORE_H__

#include <iostream>
#include <vector>
#include <string>

namespace chapter_13 {

class Core
{
    friend class StudentInfo;
public:
    Core() : midterm_(0), final_(0) {}
    Core(std::istream &in) { Read(in); }
public:
    std::string name() const { return name_; }
    virtual std::istream &Read(std::istream &in);
    virtual double Grade() const;
    virtual void Regrade(double d, double = 0) { final_ = d; }
protected:
    virtual Core* clone() { return new Core(*this); }
    std::istream& ReadCommon(std::istream &in);
    double              midterm_, final_;
    std::vector<double> homework_;
private:
    std::string         name_;
};

} // chapter_13


#endif // __ACCELERATED_CPP_CORE_H__