
#include <iostream>
#include <string>
#include <vector>

#include "str_util.h"

using namespace std;

int main()
{
    string s;
    while (getline(cin, s)) 
    {
        vector<string> v = Split(s);

        for (vector<string>::size_type i = 0; i < v.size(); ++i)
            cout << v[i] << '\n';
        cout << endl;
    }
    return 0;
}
