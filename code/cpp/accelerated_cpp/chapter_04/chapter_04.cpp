
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

#include "grade.h"
#include "median.h"
#include "student_info.h"

using namespace std;

int main()
{
    vector<StudentInfo>  students;
    StudentInfo          record;
    string::size_type    max_len = 0;

    while (Read(cin, 3, record))
    {
        max_len = max(max_len, record.name.size());
        students.push_back(record);

        char ch;
        std::cout << "continue(Y(y)/N(n))?";
        std::cin >> ch;
        if (ch != 'Y' && ch != 'y')
            break;
    }
    
    sort(students.begin(), students.end(), Compare);

    for (vector<StudentInfo>::size_type i = 0; i != students.size(); i++)
    {
        cout << setw(max_len + 1) << students[i].name;

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

int GetWidth(double n) 
{
    return log10(n) + 1;
}
