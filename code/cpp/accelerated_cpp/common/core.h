
#ifndef __ACCELERATED_CPP_CORE_H__
#define __ACCELERATED_CPP_CORE_H__

#include <iostream>
#include <vector>
#include <string>

class Core
{
    friend class StudentInfo3;
public:
    Core() : midterm_(0), final_(0) {}
    Core(std::istream &in) { Read(in); }
    virtual ~Core(){}
public:
    std::string name() const { return name_; }
    virtual std::istream &Read(std::istream &in);
    virtual double Grade() const;
    virtual void Regrade(double d, double = 0) { final_ = d; }
public:
    virtual Core* clone() { return new Core(*this); }
protected:
    std::istream& ReadCommon(std::istream &in);
    double              midterm_, final_;
    std::vector<double> homework_;
private:
    std::string         name_;
};

#endif // __ACCELERATED_CPP_CORE_H__
