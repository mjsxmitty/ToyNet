
#include <iostream>
#include <vector>
#include <algorithm>

#include "chapter_04.h"
#include "triangular.h"
#include "triangular_iterator.h"

using namespace std;

void Chapter_04()
{
    //Practice_4_3();
    //Practice_4_5();
    //Practice_4_7();
    Practice_4_9();
}

void Example(const ValClass *pvc, ValClass &rvc)
{
    pvc->Val();
    rvc.Val();
}

void Practice_4_3()
{
    const ValClass  v1;
    ValClass        v2;
    Example(&v1, v2);
}

void Practice_4_5()
{
    char    ch;
    bool    more = true;

    while (more)
    {
        cout << "Please enter a num value: ";
        int val;
        cin >> val;

        bool is_elem = Triangular::IsElem(val);
        cout << val << (is_elem ? " is" : " is not")
             << " an element int the Triangular series.\n"
             << "Anther value?(Y/N)? ";

        //Triangular::Display(1, 10, cout);
        cin >> ch;
        if (ch == 'n' || ch == 'N')
            more = false;
    }
}

void Practice_4_7()
{
    Triangular  tri(20);
    Triangular::Iterator beg = tri.Begin();
    Triangular::Iterator end = tri.End();

    cout << "Triangular Sequence of: " << tri.Length() << " elements\n";
    cout << endl;

//    while (beg != end)
//    {
//        cout << *beg << ' ';
//        ++beg;
//    }
    cout << tri;
    cout << endl;
}

int CountLessThan(const vector<int> &vec, int comp)
{
    LessThan lt(comp);
    int count = 0;

    for (int ix = 0; ix < vec.size(); ++ix)
        if (lt(vec[ix]))
            ++count;

    return count;
}

void PrintLessThan(const vector<int> &vec, int comp, ostream &os = cout)
{
    LessThan lt(comp);
    auto it = vec.begin(), it_end = vec.end();

//    while ((it = find(it, it_end, lt)) != it_end)
//    {
//        os << *it << ' ';
//        ++it;
//    }
}

void Practice_4_9()
{
    int ia[16] = { 17, 12, 44, 9, 18, 45, 6, 14,
                   23, 67, 9, 0, 27, 55, 8, 16 };

    vector<int> vec( ia, ia+16 );
    int comp_val = 20;

    cout << CountLessThan(vec, comp_val);
    cout << endl;
    //PrintLessThan(vec, comp_val, cout);
}
