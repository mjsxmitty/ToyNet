
#ifndef __ACCELERATED_CPP_GRAD_H__
#define __ACCELERATED_CPP_GRAD_H__

#include <iostream>
#include <string>

#include "core.h"

namespace chapter_13 {

class Grad : public Core
{
public:
    Grad() : thesis_(0) {}
    Grad(std::istream &in) { Read(in); }
public:
    std::istream &Read(std::istream &in);
    double Grade() const;
private:
    double thesis_;
};

}

#endif //__ACCELERATED_CPP_Grad_H__