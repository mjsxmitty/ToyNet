

#ifndef __CPP_PRIMER_CHAPTER_07_H__
#define __CPP_PRIMER_CHAPTER_07_H__

#include <string>

void Chapter_07();
void Practice_7_5_4();
void Practice_7_6();

class NoDefault
{
public:
    NoDefault(int i);
};

/*
class C
{
public:
    NoDefault nd;
    C(int i = 0) : nd(i){}
};
*/

struct B
{
    //B() {}
    NoDefault no;
};

//B b;

#endif // __CPP_PRIMER_CHAPTER_07_H__
