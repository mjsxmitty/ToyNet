
#ifndef __ESSENTIAL_CPP_CHAPTER_04_H__
#define __ESSENTIAL_CPP_CHAPTER_04_H__

#include <string>
#include <iostream>
#include <vector>

#include "../util/stack.h"

void ch_4();

extern void FillStack(Stack &stack, std::istream &is = std::cin);
extern void ch_4_1();
extern void ch_4_3();
extern void ch_4_5();
extern void ch_4_7();

class LessThan
{
public:
    LessThan(int val) : val_(val) {}
    bool operator()(int nval) const;
private:
    int val_;
};

inline bool LessThan::operator()(int val) const 
{ 
    return val < val_;
}

extern int CountLessThan(const std::vector<int> &vec, int comp);
extern int SumLessThan(const std::vector<int> &vec, int comp);
extern void PrintLessThan(const std::vector<int> &vec, int comp, 
                          std::ostream &os = std::cout);

extern void ch_4_9();
extern void ch_4_10();


void Chapter_04();

void Practice_4_3();
void Practice_4_5();
void Practice_4_7();
void Practice_4_9();
void Practice_4_10();
void Practice_4_11();

class ValClass
{
public:
    //ValClass() {}
    //std::string& Val() const { return val_; } //语法没有问题,但是不是一个良好的设计
    const std::string& Val() const { std::cout << "const ValClass::Val()\n"; return val_; }
    std::string& Val() { std::cout << "none const ValClass::Val()\n";return val_; }
private:
    std::string val_;
};





#endif // __ESSENTIAL_CPP_CHAPTER_04_H__
