
#include "chapter_03.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace chapter_03 {

int CalcStudentGrade()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";

    vector<double> homework;
    double x;
    while (cin >> x)
        homework.push_back(x);

    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();

    if (size == 0)
    {
        cout << endl << "You must enter your grades.  "
                        "Please try again."
                     << endl;
        return -1;
    }

    sort(homework.begin(), homework.end());

    vec_sz mid = size/2;
    double median = (size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid]);

    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
        << 0.2 * midterm + 0.4 * final + 0.4 * median
        << setprecision(prec) << endl;

    return 0;
}

double Median(const vector<int> &integers, VecSz begin, VecSz end)
{
    VecSz size = begin + end;
    VecSz mid = size / 2;
    return size % 2 == 0 ? (integers[mid] + integers[mid - 1]) / 2.0 : integers[mid];
}

int Homework_2()
{
    cout << "Integers: ";

    vector<int> integers;
    int x;
    while (cin >> x)
        integers.push_back(x);

    if (integers.size() == 0)
    {
        cout << endl << "No integers!" << endl;
        return 1;
    }

    sort(integers.begin(), integers.end());

    VecSz mid = integers.size() / 2;
    VecSz lower_half_end;
    VecSz upper_half_begin;

    if (integers.size() % 2 != 0)
    {
        lower_half_end = mid;
        upper_half_begin = mid + 1;
    }
    else
    {
        lower_half_end = mid;
        upper_half_begin = mid - 1;
    }

    cout << "Q1" << endl;
    cout << Median(integers, 0, lower_half_end) << endl;

    cout << "Q2" << endl;
    cout << Median(integers, 0, integers.size()) << endl;

    cout << "Q3" << endl;
    cout << Median(integers, upper_half_begin, integers.size()) << endl;

    return 0;
}

int Homework_3()
{
    typedef vector<string>::size_type vec_sz;

    cout << "Words: ";
    string          s;
    vector<string>  words;
    vector<int>     counts;

    while (cin >> s)
    {
        bool found = false;
        for (vec_sz i = 0; i < words.size(); ++i)
        {
            if (s == words[i])
            {
                ++counts[i];
                found = true;
            }
        }

        //²»´æÔÚ
        if (!found)
        {
            words.push_back(s);
            counts.push_back(1);
        }
    }

    for (vec_sz i = 0; i < words.size(); ++i)
        cout << words[i] << " appeared "
             << counts[i] << " times"
             << endl;

    return 0;
}

int Homework_4()
{
    typedef string::size_type str_sz;

    string longest;
    str_sz longest_length = 0;
    string shortest;
    str_sz shortest_length = 0;

    cout << "Words: ";
    string s;

    while (cin >> s)
    {
        if (longest_length == 0 || s.size() > longest_length)
        {
            longest = s;
            longest_length = s.size();
        }

        if (shortest_length == 0 || s.size() < shortest_length)
        {
            shortest = s;
            shortest_length = s.size();
        }
    }

    cout << "longest: " << longest << endl;
    cout << "shortest: " << shortest << endl;

    return 0;

}

#define NUM_HOMEWORK 2

int Homework_5()
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
}
