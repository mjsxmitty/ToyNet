
#include <iostream>
#include <vector>
#include <algorithm>

#include "chapter_04.h"
#include "../util/triangular.h"
#include "../util/triangular_iterator.h"
#include "../util/num_sequence_ver1.h"

using namespace std;

void ch_4()
{
    //ch_4_1();
    //ch_4_3();
    //ch_4_5();
    //ch_4_7();
    ch_4_9();
    //ch_4_10();
}

void FillStack(Stack &stack, std::istream &is)
{
    string str;
    if (is >> str && !stack.Empty())
        stack.Push(str);
    cout << "read in " << stack.Size() << " elements\n";
}

void ch_4_1()
{
    Stack sta;
    cout << sta.Empty() << endl;
    FillStack(sta, cin);
}

void Example(const ValClass *pvc, ValClass &rvc)
{
    pvc->Val();
    rvc.Val();
}

void ch_4_3()
{
    Triangular tri(4);
    cout << tri << " -- sum of elements: "
      << Sum(tri) << endl;

    Triangular tri2(4, 3);
    cout << tri2 << " -- sum of elements: "
      << Sum(tri2) << endl;

    Triangular tri3(8, 8);
    cout << tri3 << " -- sum of elements: "
      << Sum(tri3) << endl;
}

void ch_4_5()
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
             << "Anther value(y/n)?";

        cin >> ch;
        if (ch == 'n' || ch == 'N')
            more = false;
    }
}

void ch_4_7()
{
    Triangular tri(20,3);
    //cout << tri << endl;
    cout << "Triangular Sequence of: " << tri.Length() << " elements\n";

    Triangular::Iterator beg = tri.Begin();
    Triangular::Iterator end = tri.End();

    while (beg != end)
    {
        cout << *beg << '\n';
        ++beg;
    }
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

int SumLessThan(const std::vector<int> &vec, int comp)
{
    LessThan lt(comp);
    
    int sum = 0;
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (lt(vec[i]))
        {
            //cout << "val: " << vec[i] << endl;
            sum += vec[i];
        }
    }
    
    return sum;
}

void PrintLessThan(const vector<int> &vec, int comp, ostream &os)
{
    LessThan lt(comp);

    auto it = vec.begin(), it_end = vec.end();
    while ((it = find_if(it, it_end, lt)) != it_end)
    {
        os << *it << ' ';
        ++it;
    }
}

void ch_4_9()
{
    int ia[16] = { 17, 12, 44, 9, 18, 45, 6, 14,
                   23, 67, 9, 0, 27, 55, 8, 16 };

    vector<int> vec( ia, ia+16 );
    int comp_val = 20;

    cout << "vector size: " << vec.size() << endl;
    cout << "vector less than comp val size: " << CountLessThan(vec, comp_val) << endl;
    cout << "vector sum is: " << SumLessThan(vec, comp_val) << endl;

    PrintLessThan(vec, comp_val, cout);
    cout << endl;
}

void ch_4_10()
{
    Triangular tri(6, 3);
    cout << tri << endl;

    Triangular tri2;
    cin >> tri2;
    cout << tri2 << endl;
}

void Display(ostream &os, const NumSequenceVer1 &ns,
             int pos, int elem_val)
{
    os << "The element at position: " << pos
        << " for the: " << ns.WhatAmI()
        << " sequence is: " << elem_val 
        << endl;
}

void ch_4_11()
{
    NumSequenceVer1 ns(1, 8);
    int elem_val = 0;
    int pos = 0;

    for (int ix = 0; ix < NumSequenceVer1::NumOfSequence(); ++ix)
    {

    }
}
