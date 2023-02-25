

#ifndef __ACCELERATED_CPP_CHAPTER_3_H__
#define __ACCELERATED_CPP_CHAPTER_3_H__

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace chapter_03 {


int CalcStudentGrade();

typedef vector<int>::size_type VecSz;
double Median(const vector<int> &integers, VecSz begin, VecSz end);

int Homework_2();
int Homework_3();
int Homework_4();
int Homework_5();
}

#endif //__ACCELERATED_CPP_CHAPTER_3_H__
