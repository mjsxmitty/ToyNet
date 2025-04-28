
#include <iostream>
#include <vector>
#include <algorithm>

#include "stack.h"
#include "triangular.h"
#include "common.h"

using namespace std;

int main1()
{
    ver1::Stack sta;
    ver1::FillStack(sta, cin);

    return 0;
}

int main2()
{
    Triangular tri(4);
    cout << tri << " -- sum of elements: "
        << Sum(tri) << endl;

    Triangular tri2(4, 3);
    cout << tri2 << " -- sum of elements: "
        << Sum(tri2) << endl;

    Triangular tri3(4, 8);
    cout << tri3 << " -- sum of elements: "
        << Sum(tri3) << endl;
    return 0;
}

int mai3()
{
    char ch;
    bool more = true;

    while (more)
    {
        cout << "Enter a value: ";
        int ival;
        cin >> ival;

        bool is_elem = Triangular::IsElem(ival);
        cout << ival << (is_elem ? " is " : " is not ")
                << "an element in the Triangular series.\n"
                << "Anther value(y/n)? ";

        cin >> ch;
        if (ch == 'y' || ch == 'N')
            more = true;
        else
            more = false;
    }
    return 0;
}

int main4()
{
    Triangular tri(20);
    cout << "Triangular Sequence of: " << tri.Length() << " elements\n";

    Triangular::Iterator beg = tri.Begin();
    Triangular::Iterator end = tri.End();

    cout << tri << endl;

    while (beg != end)
    {
        cout << *beg << ' ';
        ++beg;
    }
    cout << endl;

    return 0;
}

int main5()
{
    int ia[16] = { 17, 12, 44, 9, 18, 45, 6, 14,
                    23, 67, 9, 0, 27, 55, 8, 16 };

    vector<int> vec( ia, ia+16 );
    int comp_val = 20;

    cout << "vector size: " << vec.size() << endl;
    cout << "vector less than comp val size: " << common::CountLessThan(vec, comp_val) << endl;
    cout << "vector sum is: " << common::SumLessThan(vec, comp_val) << endl;

    sort(vec.begin(), vec.end());
    for_each(vec.begin(), vec.end(), [](int i){
        cout << i << ' ';
    });
    cout << endl;

    common::PrintLessThan(vec, comp_val, cout);
    cout << endl;
    return 0;
}

int main6()
{
    Triangular tri(6, 3);
    cout << tri << endl;

    Triangular tri2;
    cin >> tri2;
    cout << tri2 << endl;

    return 0;
}

int main()
{
    ver2::NumSequence ns;
    int elem_val = 0;
    int pos;
    cout << "enter a position: ";
    cin >> pos;

    for (int ix = 1; ix < ver2::NumSequence::NumOfSequence(); ++ix)
    {
        ns.SetBegin(ix);
        ns.SetSequence(ver2::NumSequence::SeqType(ix));
        elem_val = ns.Elem(pos);
        ver2::Display(cout, ns, pos, elem_val);
    }

    ver2::NumSequence ns1(1,2,ver2::NumSequence::NS_FIB);
    ver2::NumSequence ns2(1,2,ver2::NumSequence::NS_FIB);
    cout << ( ns != ns1 ) << endl;
    cout << ( ns2 == ns1 ) << endl;

    int value;
    cout << "enter a sequence value: ";
    cin >> value;

    bool ret = ns.IsElem(value);
    if (ret)
        cout << "elem " << value <<  " is " << ns.WhatAmI() << " elem, distance: "
            << ns.PosElem(value) << endl;
    else
        cout << "elem " << value << " is not " << ns.WhatAmI() << " elem.\n";

    return 0;
}