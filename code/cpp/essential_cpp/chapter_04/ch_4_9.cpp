
#include <iostream>
#include <vector>
#include <algorithm>

#include "chapter_04.h"

using namespace std;
using namespace chapter_04;

int main()
{
    int ia[16] = { 17, 12, 44, 9, 18, 45, 6, 14,
                    23, 67, 9, 0, 27, 55, 8, 16 };

    vector<int> vec( ia, ia+16 );
    int comp_val = 20;

    cout << "vector size: " << vec.size() << endl;
    cout << "vector less than comp val size: " << CountLessThan(vec, comp_val) << endl;
    cout << "vector sum is: " << SumLessThan(vec, comp_val) << endl;

    sort(vec.begin(), vec.end());
    for_each(vec.begin(), vec.end(), [](int i){
        cout << i << ' ';
    });
    cout << endl;

    PrintLessThan(vec, comp_val, cout);
    cout << endl;
    return 0;
}
