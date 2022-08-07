

#ifndef __CPP_PRIMER_CHAPTER_13_H__
#define __CPP_PRIMER_CHAPTER_13_H__

#include <cstddef>

void Chapter_13();

void Practice_13_6_2();

void Homework_13_13();
void Homework_13_14();
void Homework_13_18();
void Homework_13_22();
void Homework_13_31();


struct Numbered
{
    Numbered() :my_sn_(sn_++){}
    // 13.15
    Numbered(const Numbered &rhs) : my_sn_(sn_++) {}

    static size_t   sn_;    // 用于生成唯一id
    size_t          my_sn_;
};


#endif // __CPP_PRIMER_CHAPTER_13_H__
