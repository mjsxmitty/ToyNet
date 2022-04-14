
#ifndef __ESSENTIAL_CPP_CHAPTER_02_H__
#define __ESSENTIAL_CPP_CHAPTER_02_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

void Chapter_02();

void Practice_2_1();
void Practice_2_3();
void Homework_2_1();
void Homework_2_6();

extern void Display(const std::vector<int> *vec, std::ostream *out = 0);
extern void Display(const std::vector<int> &vec, std::ostream &out = std::cout);

extern void Swap(int &val1, int &val2, std::ostream &ofile);
extern void Swap(int &val1, int &val2, std::ostream *ofile = 0);

extern void BubbleSort(std::vector<int> &vec, std::ostream &ofile);
extern void BubbleSort(std::vector<int> &vec, std::ostream *ofile = 0);

extern bool FibonElem(int pos, int &elem);
extern bool PrintFibon(int pos);

extern std::vector<int> FibonSeq(int size);

template <typename T>
inline T Max(T t1, T t2) { return t1 > t2 ? t1 : t2; }

template <typename T>
inline T Max(const std::vector<T> &vec)
{
    return *std::max_element(vec.begin(), vec.end());
}

template <typename T>
inline T Max(const T *arr, int size)
{
    return *std::max_element(arr, arr + size);
}

#endif //__ESSENTIAL_CPP_CHAPTER_02_H__
