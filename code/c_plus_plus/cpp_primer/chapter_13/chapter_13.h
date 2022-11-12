

#ifndef __CPP_PRIMER_CHAPTER_13_H__
#define __CPP_PRIMER_CHAPTER_13_H__

#include <cstddef>

extern void ch_13();

extern void ch_13_1();
extern void ch_13_1_1();
extern void hw_13_4();

extern void hw_13_13();
extern void hw_13_17();
void ch_13_1_2();
void hw_13_18();
void hw_13_22();
void ch_13_3();
void hw_13_31();
void ch_13_6_2();
void ch_13_6_3();

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






#endif // __CPP_PRIMER_CHAPTER_13_H__
