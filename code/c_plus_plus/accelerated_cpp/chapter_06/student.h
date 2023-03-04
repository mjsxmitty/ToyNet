

#ifndef __ACCELERATED_CPP_CHAPTER_06_STUDENT_H__
#define __ACCELERATED_CPP_CHAPTER_06_STUDENT_H__

#include "../chapter_04/student_info.h"
#include <iostream>
#include <vector>

namespace chapter_06
{

typedef double (*Analysis)(const std::vector<chapter_04::StudentInfo> &);

bool DidAllHW(const chapter_04::StudentInfo &s);
void WriteAnalysis(std::ostream &os, const std::string &name, 
                    Analysis,
                    std::vector<chapter_04::StudentInfo> &did,
                    std::vector<chapter_04::StudentInfo> &didnt);
double MedianAnalysis(const std::vector<chapter_04::StudentInfo> &students);
double AverageAnalysis(const std::vector<chapter_04::StudentInfo> &students);
double OptimisticAnalysis(const std::vector<chapter_04::StudentInfo> &students);

std::vector<chapter_04::StudentInfo> ExtractFails(std::vector<chapter_04::StudentInfo> &students);
std::vector<chapter_04::StudentInfo> ExtractFails2(std::vector<chapter_04::StudentInfo> &students);

} // namespace Chapter06


#endif //__ACCELERATED_CPP_CHAPTER_06_STUDENT_H__
