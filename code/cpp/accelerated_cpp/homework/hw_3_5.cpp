
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


#define NUM_HOMEWORK 2

int main()
{
    vector<string> names;
    vector<double> final_grades;
    bool done = false;

    while (!done)
    {
        cout << "Please enter your first name: ";
        string name;
        cin >> name;
        cout << "Hello, " << name << "!" << endl;
        names.push_back(name);

        cout << "Please enter your midterm and final exam grades: ";
        double midterm, final;
        cin >> midterm >> final;

        cout << "Enter both your homework grades, "
                "followed by end-of-file: ";

        int     count = 0;
        double  sum = 0;

        double  x;
        while (count < NUM_HOMEWORK)
        {
            ++count;
            cin >> x;
            sum += x;
        }

        double final_grade = 0.2 * midterm + 0.4 * final + 0.4 * sum / count;
        final_grades.push_back(final_grade);

        cout << "More? (Y/N) ";
        string s;
        cin >> s;

        if (s != "Y" && s != "y")
            done = true;
    }

    for (vector<string>::size_type i = 0; i < names.size(); ++i)
    {
        streamsize prec = cout.precision();
        cout << names[i] << "'s final grade is " << setprecision(3)
            << final_grades[i]
            << setprecision(prec) << endl;
    }

    return 0;
}

