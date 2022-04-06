
#ifndef __CHAPTER04_H__
#define __CHAPTER04_H__

#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

#include "chapter04_grade.h"
#include "chapter04_median.h"
#include "chapter04_student_info.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::sort;
using std::setw;
using std::streamsize;
using std::setprecision;

namespace Chapter04
{
    int testChapter04()
    {
        vector<StudentInfo>  students;
        StudentInfo          record;
        string::size_type    max_len = 0;

        while (Read(cin, record)) {
            max_len = max(max_len, record.name.size());
            students.push_back(record);
        }
        
        sort(students.begin(), students.end(), Compare);

        for (vector<StudentInfo>::size_type i = 0; i != students.size(); i++) {
            cout << setw(max_len + 1) << students[i].name << ' ';

            try {
                double final_grade = Grade(students[i]);
                streamsize prec = cout.precision();
                cout << setprecision(3) << final_grade << setprecision(prec);
            } catch(const std::exception& e) {
                std::cerr << e.what() << '\n';
            }
            cout << endl;
        }
        return 0;
    }

    int GetWidth(double n) {
        return log10(n) + 1;
    }

    int testChapter04Homework03()
    {
        double max = 1000.0;
        for (double i = 1.0; i != max; i++) {
            std::cout << setw(GetWidth(max)) << i << setw(GetWidth(max * max) + 1) << i * i << endl;
        }
        return 0;
    }
} // namespace Chapter04




#endif //__CHAPTER04_H__