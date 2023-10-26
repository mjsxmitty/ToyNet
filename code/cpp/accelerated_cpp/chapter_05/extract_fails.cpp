

#include "extract_fails.h"
#include "../chapter_04/grade.h"

using std::list;
using chapter_04::StudentInfo;

namespace chapter_05
{

list<StudentInfo> ExtractFails(list<StudentInfo> &students)
{
    list<StudentInfo> fail;
    list<StudentInfo>::iterator iter = students.begin();

    while (iter != students.end()) 
    {
        if (chapter_04::FGrade(*iter)) 
        {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } 
        else
            ++iter;          
    }
    
    return fail;
}

} // namespace Chapter05

