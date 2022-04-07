
#ifndef __ESSENTIAL_CPP_CHAPTER_04_H__
#define __ESSENTIAL_CPP_CHAPTER_04_H__

#include <string>
#include <iostream>

class ValClass
{
public:
    //ValClass() {}
    //std::string& Val() const { return val_; }
    const std::string& Val() const { std::cout << "const ValClass::Val()\n"; return val_; }
    std::string& Val() { std::cout << "none const ValClass::Val()\n";return val_; }
private:
    std::string val_;
};

void Chapter_04();

void Practice_4_3();

#endif // __ESSENTIAL_CPP_CHAPTER_04_H__
