
#include <iostream>

#include "chapter_04.h"
#include "triangular.h"
#include "triangular_iterator.h"

using namespace std;

void Chapter_04()
{
    //Practice_4_3();
    //Practice_4_5();
    Practice_4_7();
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
    //Triangular::Display(20, 1, cout);
    cout << endl;

//    while (beg != end)
//    {
//        cout << *beg << ' ';
//        ++beg;
//    }
    cout << tri;
    cout << endl;
}
