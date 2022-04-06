
#include <iostream>
#include <vector>

#include "chapter04_student_info.h"
#include "chapter04_grade.h"

using std::vector;

namespace Chapter04
{
    bool Compare(const StudentInfo &lhs, const StudentInfo &rhs)
    {
        return lhs.name < rhs.name;
    }

    std::istream& Read(std::istream &is, StudentInfo &s)
    {
        //std::cout << "Please enter name, midterm and final: ";
        is >> s.name >> s.midterm >> s.final;
        return ReadHw(is, s.homework);


        vector<double> homework;
        return ReadHw(is, homework);
        
    }

    std::istream& ReadHW(std::istream &is, StudentInfoHw &s)
    {
        double midterm, final;
        // read and store the student's name and midterm and final exam grades
        is >> s.name >> midterm >> final;

        vector<double> homework;
        ReadHw(is, homework);
        
        if (is) {
            s.grade = Grade(midterm, final, homework);
        }
        
        return is;
    }

    std::istream& ReadHw(std::istream &in, std::vector<double> &hw)
    {
        //std::cout << "Please enter homeworks: ";
        if (in) {
            hw.clear();
            double x;
            while (in >> x) {
                hw.push_back(x);
            }

            in.clear();
        }
        return in;
    }

} // namespace Chapter04

