

#include "chapter05_extract_fails.h"
#include "../chapter04/chapter04_grade.h"

using std::list;
using Chapter04::StudentInfo;

namespace Chapter05
{
    list<StudentInfo> ExtractFails(list<StudentInfo> &students)
    {
        list<StudentInfo> fail;
        list<StudentInfo>::iterator iter = students.begin();

        while (iter != students.end()) {
            if (Chapter04::FGrade(*iter)) {
                fail.push_back(*iter);
                iter = students.erase(iter);
            } else
                ++iter;          
        }
        
        return fail;
    }
} // namespace Chapter05

