

#ifndef __HUAWEI_CHAPTER_03_ENCAPSULATION_DATE_H__
#define __HUAWEI_CHAPTER_03_ENCAPSULATION_DATE_H__


class GZDate
{
public:
    void Init();
    void Print();
    bool IsLeapYear();
private:
    int year,month,day;
};

#endif // __HUAWEI_CHAPTER_03_ENCAPSULATION_DATE_H_
