
#include "student_info.h"
#include "str_util.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
#if 0
    string s;
    while (getline(cin, s)) {
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
#endif
#if 0
    string s;
    while (getline(cin, s)) {
        vector<string> v = Split(s);
        for (vector<string>::size_type i = 0; i < v.size(); ++i)
        {
            vector<string> ret = FindUrls(v[i]);
            for_each(ret.begin(), ret.end(), [](const string &s) { cout << s << "\n";});
            cout << endl;
        }
    }
#endif
    std::vector<StudentInfo> did, didnt;
    StudentInfo student;
    int cnt = 0;

    while (Read(std::cin, 3, student))
    {
        cnt++;

        if (DidAllHW(student))
            did.push_back(student);
        else
            didnt.push_back(student);
            
        if (cnt == 3)
            break;
    }
    
    if (did.empty() || didnt.empty()) 
    {
        cout << "vec is empty!" << endl;
        return -1;
    }

    WriteAnalysis(std::cout, "median", MedianAnalysis, did, didnt);
    WriteAnalysis(std::cout, "average", AverageAnalysis, did, didnt);
    WriteAnalysis(std::cout, "optimistic", OptimisticAnalysis, did, didnt);
    return 0;
}
