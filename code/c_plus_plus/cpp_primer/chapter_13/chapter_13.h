

#ifndef __CPP_PRIMER_CHAPTER_13_H__
#define __CPP_PRIMER_CHAPTER_13_H__

#include <cstddef>

void Chapter_13();

struct GZNoCopy
{
    GZNoCopy() = default;
    GZNoCopy(const GZNoCopy &) = delete;
    GZNoCopy& operator=(const GZNoCopy &) = delete;
    ~GZNoCopy() = default;
};

struct GZNoDtor
{
    GZNoDtor() = default;
    ~GZNoDtor() = delete;
};

class GZPrivateCopy
{
    GZPrivateCopy(const GZPrivateCopy &);
    GZPrivateCopy& operator=(const GZPrivateCopy &);
public:
    GZPrivateCopy() = default;
    ~GZPrivateCopy() = default;
};

void Practice_13_1_2();
void Homework_13_13();
void Homework_13_14();
void Homework_13_18();

void Homework_13_22();

void Practice_13_3();
void Homework_13_31();

void Practice_13_6_2();
void Practice_13_6_3();

struct Numbered
{
    Numbered() :my_sn_(sn_++){}
    // 13.15
    Numbered(const Numbered &rhs) : my_sn_(sn_++) {}

    static size_t   sn_;    // 用于生成唯一id
    size_t          my_sn_;
};


#endif // __CPP_PRIMER_CHAPTER_13_H__
