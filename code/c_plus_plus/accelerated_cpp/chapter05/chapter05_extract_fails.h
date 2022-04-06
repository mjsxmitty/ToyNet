

#ifndef __CHAPTER05_EXTRACT_H__
#define __CHAPTER05_EXTRACT_H__

#include <list>
#include "../chapter04/chapter04_student_info.h"

namespace Chapter05
{
std::list<Chapter04::StudentInfo> ExtractFails(std::list<Chapter04::StudentInfo> &students);
} // namespace Chapter05



#endif //__CHAPTER05_EXTRACT_H__
