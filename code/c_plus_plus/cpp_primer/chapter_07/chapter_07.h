

#ifndef __CPP_PRIMER_CHAPTER_07_H__
#define __CPP_PRIMER_CHAPTER_07_H__

#include <string>
#include <vector>

extern void ch_07();

extern void ch_7_3();
extern void ch_7_3_1();
extern void ch_7_3_2();

extern void ch_7_5();
extern void ch_7_5_4();
extern void ch_7_6();

/*****************************************************************/
/***************************7.6*********************************/
//静态成员可以运用在某种场景,普通成员不行
class Bar
{
public:
    //Bar() {}
    static Bar mem1;
    Bar *mem2;
    //Bar mem3;
};

class Example
{
public:
    //Example() {}
    //static const double rate = 6.5;
    static constexpr double rate = 6.5;
    static const int vec_size = 20;
    static const std::vector<int> ivec;
};

void Homework_7_58();


#endif // __CPP_PRIMER_CHAPTER_07_H__
