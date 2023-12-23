
#include <iostream>
#include <string>
#include <vector>

#include "str.h"

using namespace std;

int main()
{
    string s;
    while (getline(cin, s)) {
        vector<string> v = Split(s);

        for (vector<string>::size_type i = 0; i < v.size(); ++i)
            cout << v[i] << ' ';
        cout << endl;
    }
    return 0;
}
