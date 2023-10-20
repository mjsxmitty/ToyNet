

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

namespace chapter_07 {

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
    static constexpr double rate = 6.5;
    static const int vec_size = 20;
    static const std::vector<int> ivec;
};

};

#endif // __CPP_PRIMER_CHAPTER_07_H__
