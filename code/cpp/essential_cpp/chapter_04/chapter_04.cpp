
#include <iostream>
#include <vector>
#include <algorithm>

#include "chapter_04.h"
#include "triangular.h"
#include "triangular_iterator.h"
#include "num_sequence_ver1.h"
#include "user_profile.h"

using namespace std;
namespace chapter_04
{

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

    Triangular tri3(4, 8);
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
        if (ch == 'y' || ch == 'N')
            more = true;
        else
            more = false;
    }
}

void ch_4_7()
{
    Triangular tri(20);
    cout << "Triangular Sequence of: " << tri.Length() << " elements\n";

    Triangular::Iterator beg = tri.Begin();
    Triangular::Iterator end = tri.End();

    cout << tri << endl;

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
        if (lt(vec[i]))
            sum += vec[i];
    
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

    sort(vec.begin(), vec.end());
    for_each(vec.begin(), vec.end(), [](int i){
        cout << i << ' ';
    });
    cout << endl;

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

void Display(ostream &os, NumSequence &ns,
                int pos, int elem_val)
{
    os << ns << endl;
    os << "The element at position: " << pos
        << " for the: " << ns.WhatAmI()
        << " sequence is: " << elem_val 
        << endl;
}

void ch_4_11()
{
    NumSequence ns;
    int elem_val = 0;
    int pos;
    cout << "enter a position: ";
    cin >> pos;

    for (int ix = 1; ix < NumSequence::NumOfSequence(); ++ix)
    {
        ns.SetSequence(NumSequence::SeqType(ix));
        elem_val = ns.Elem(pos);
        Display(cout, ns, pos, elem_val);
    }
}

void hw_4_4()
{
    UserProfile up1;
    UserProfile up2;
    cout << (up1 == up2 ? "equal" : "not equal") << endl;
    cout << up1 << endl;
    cout << up2 << endl;

    UserProfile up("gao", UserProfile::ULevel(1));
    cout << up << endl;

    up.reset_login("test");
    up.reset_level("Guru");
    up.bump_guess_count(10);
    cout << up << endl;
}
void hw_4_5()
{

}


}
