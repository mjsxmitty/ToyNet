
#ifndef __CPP_PRIMER_CHAPTER_06_H__
#define __CPP_PRIMER_CHAPTER_06_H__

#include <string>
#include <sstream>

extern void ch_06();

extern int fact(int val);
extern void ch_6_1();
extern void ch_6_1_1();
extern void ch_6_1_3();

extern void ch_6_2();
extern void ch_6_2_2();
extern void ch_6_2_4();
extern void ch_6_2_6();
extern void hw_6_33();

extern void ch_6_3();
extern void ch_6_3_2();
extern void ch_6_3_3();

extern void ch_6_5();
extern void ch_6_5_1();

constexpr int NewSize() {return 10;}
constexpr size_t Scale(size_t cnt)
{
    typedef std::string::size_type sz;
    return  NewSize() * cnt;
}

extern void ch_6_5_2();
extern void ch_6_5_3();

extern void ch_6_7();
extern void ch_6_7_test_1();
extern void ch_6_7_test_2();
extern void hw_54_55_56();

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
