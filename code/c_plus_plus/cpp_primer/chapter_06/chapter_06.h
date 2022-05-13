
#ifndef __CPP_PRIMER_CHAPTER_06_H__
#define __CPP_PRIMER_CHAPTER_06_H__

#include <string>
#include <sstream>

void Chapter_06();

void Practice_6_1_1();
void Practice_6_1_3();
void Practice_6_2_2();
void Practice_6_2_6();
void Practice_6_3_2();
void Practice_6_3_3();
void Practice_6_7();

void Homework_6_33();

void Practice();

struct ErrCode
{
    ErrCode(int i) : num(i) {}
    
    std::string Msg()
    {
        std::stringstream s;
        s << "ErrCode: " << num;
        return s.str();
    }     
    int num;    
};

#endif // __CPP_PRIMER_CHAPTER_06_H__
