
#include <iostream>

#include "vec.hpp"
#include "student_info.h"

using namespace std;

int main()
{
    Vec<int> v1;
    Vec<int> v2(10, 1024);
    v1 = v2;
    cout << v1[1] << endl;

    v1.push_back(1);
    cout << v1.Size() << ", " << v1[v1.Size() - 1] << endl;

    Vec<StudentInfo> v3;
    StudentInfo s1;

    v3.push_back(s1);
    v3[0].name = "test";

    for (auto iter = v3.Begin(); iter != v3.End(); ++iter)
    {
        cout << iter->name << endl;
    }

    return 0;
}
