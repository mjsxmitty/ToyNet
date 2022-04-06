

#ifndef __HUAWEI_CHAPTER_04_CLASS_OBJECT_GZSTUDENT_H__
#define __HUAWEI_CHAPTER_04_CLASS_OBJECT_GZSTUDENT_H__

#include <string>

class GZStudent
{
public:
    GZStudent(const std::string &name);
public:
    static void PrintStudentList();
    static void DeleteStudentList();
private:
    std::string         name_;
    GZStudent*          next_;

    static GZStudent*   head_;
};

#endif // GZSTUDENT_H
