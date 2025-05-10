
#include "student_info.h"
#include "str_util.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main1()
{
    string s;
    while (getline(cin, s))
    {
        vector<string> v = Split(s);

        vector<string> frame = Frame(v);
        for_each(frame.begin(), frame.end(), [](const string &s) { cout << s << "\n";});
        cout << endl;

        vector<string> vcat = Vcat(v, frame);
        for_each(vcat.begin(), vcat.end(), [](const string &s) { cout << s << "\n";});
        cout << endl;

        vector<string> hcat = Hcat(v, frame);
        for_each(hcat.begin(), hcat.end(), [](const string &s) { cout << s << "\n";});
        cout << endl;

    }

    return 0;
}

int main2()
{
    string s;
    while (getline(cin, s))
    {
        vector<string> v = Split(s);
        for (vector<string>::size_type i = 0; i < v.size(); ++i)
        {
            vector<string> ret = FindUrls(v[i]);
            for_each(ret.begin(), ret.end(), [](const string &s) { cout << s << "\n";});
            cout << endl;
        }
    }

    return 0;
}

int main()
{
    vector<StudentInfo> did, didnt;
    StudentInfo student;
    int cnt = 0;

    while (Read(cin, student))
    {
        cnt++;

        if (DidAllHW(student))
            did.push_back(student);
        else
            didnt.push_back(student);

        if (cnt == 2)
            break;
    }

    if (did.empty() || didnt.empty())
    {
        cout << "vec is empty!" << endl;
        return -1;
    }

    WriteAnalysis(cout, "median analysis: ", MedianAnalysis, did, didnt);
    WriteAnalysis(cout, "average", AverageAnalysis, did, didnt);
    WriteAnalysis(cout, "optimistic", OptimisticAnalysis, did, didnt);

    return 0;
}
