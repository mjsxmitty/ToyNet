
#include <iostream>
#include "common.h"

using namespace std;
using namespace common;

int main()
{
    cout << "max int value: " << Max(34, 199)
        << ", max string value: " << Max("nihao", "hello")
        << endl;

    int ia[8] = { 8, 34, 39, 13, 1, 21, 5, 2 };
    vector<int> vec(ia, ia + 8);
    cout << "max vec value: " << Max(vec) << endl;
    cout << "max array value: " << Max(ia, 8) << endl;

    string sarray[]={ "we", "were", "her", "pride", "of", "ten" };
    vector<string> svec( sarray, sarray+6 );
    cout << "max svec value: " << Max(svec) << endl;
    cout << "max sarray value: " << Max(sarray, sizeof(sarray) / sizeof (sarray[0])) << endl;

    float farray[]={ 2.5, 24.8, 18.7, 4.1, 23.9 };
    vector<float> fvec( farray, farray+5 );
    cout << "max fvec value: " << Max(fvec) << endl;
    cout << "max farray value: " << Max(farray, sizeof(farray) / sizeof (farray[0])) << endl;
}
