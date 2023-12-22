

#include "extract_fails.h"
#include "grade.h"

using std::list;

namespace chapter_05
{

list<StudentInfo> ExtractFails(list<StudentInfo> &students)
{
    list<StudentInfo> fail;
    list<StudentInfo>::iterator iter = students.begin();

    while (iter != students.end()) 
    {
        if (FGrade(*iter))
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

