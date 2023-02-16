

#include "chapter_02.h"
#include "num_sequence.h"

#include <iostream>
#include <vector>

using namespace std;

namespace chapter_02
{

bool FibonElem(int pos, int &elem)
{
    // 无效位置
    if (pos <= 0 || pos > 1024)
    {
        cerr << "invalid position" << pos
            << " ---> cannot handle request!"
            << endl;

        elem = 0;
        return false;
    }

    elem = 1;
    int val1 = 1, val2 = 1;

    for (int i = 3; i <= pos; i++)
    {
        elem = val2 + val1;
        val2 = val1;
        val1 = elem;
    }

    return true;
}

bool PrintFibon(int pos)
{
    if (pos <= 0 || pos > 1024)
    {
        cerr << "invalid position: " << pos
            << " --- cannot handle request!"
            << endl;

        return false;
    }

    cout << "the fibonacci sequence for "
        << pos << " positions: \n";

    switch (pos)
    {
        default:
        case 2:
            cout << "1 ";
        case 1:
            cout << "1 ";
            break;
    }

    int elem;
    int val1 = 1, val2 = 1;
    for (int i = 3; i <= pos; i++)
    {
        elem = val1 + val2;
        val2 = val1;
        val1 = elem;
        cout << elem << (!(i % 10) ? "\n" : " ");
    }

    cout << endl;
    return true;
}

void ch_2_1()
{
    cout << "please enter a position: ";
    int pos;
    cin >> pos;

    int elem;
    if (FibonElem(pos, elem))
    {
        cout << "element at position # "
            << pos << " is: " << elem << endl;
    }
    else
    {
        cout << "sorry! cannot calculate position: "
            << pos << " elem."<< endl;
        return ;
    }

    PrintFibon(pos);
}

void hw_2_1()
{
    bool more = true;
    while (more)
    {
        int pos;
        cout << "please enter a position: ";
        cin >> pos;

        int elem;
        if (FibonElem(pos, elem))
        {
            cout << "element at position # " << pos
                << " value is: " << elem << endl;
        }
        else
            cout << "sorry! cannot calculate position # "
                << pos << " elem "<< endl;

        cout << "would you want to try again?(Y/N): ";
        char ch;
        cin >> ch;
        if (ch != 'y' && ch != 'Y')
            more = false;
    }
}

void Display(const vector<int> *vec, ostream *out)
{
    ostream &os = (out == 0) ? cout : *out;
    if (vec == 0)
    {
        os << "Display(): the vec point to 0.\n";
        return ;
    }


    for (unsigned int i = 0; i < vec->size(); i++)
        os << (*vec)[i] << ' ';

    os << endl;
}

void Display(const vector<int> &vec, ostream &out)
{
    for (unsigned int i = 0; i < vec.size(); i++)
        out << vec[i] << ' ';

    out << endl;
}

void Swap(int &val1, int &val2, ostream &out)
{
    out << "swap ( " << val1 << ", " << val2 << " )\n";

    int temp = val1;
    val1 = val2;
    val2 = temp;

    out << "after swap: val1: " << val1
        << ", val2: " << val2 << endl;
}

void Swap(int &val1, int &val2, ostream *out)
{
    if (out != 0)
        (*out) << "swap ( " << val1 << ", " << val2 << " )\n";

    int temp = val1;
    val1 = val2;
    val2 = temp;

    if (out != 0)
        (*out) << "after swap: val1: " << val1
                << ", val2: " << val2 << endl;
}

void BubbleSort(vector<int> &vec, ostream &out)
{
    for (unsigned int i = 0; i < vec.size(); ++i)
    {
        for (unsigned int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[i] > vec[j])
            {
                out << "call swap()! position : " << i
                    << ", and position: " << j 
                    << " swapping: " << vec[i] 
                    << ", with: " << vec[j] 
                    << endl;

                Swap(vec[i], vec[j], out);

                out << "after swap vector element: ";
                Display(vec, out);
            }
        }
    }
}

void BubbleSort(vector<int> *vec, ostream *out)
{    
    if (vec == 0)
    {
        cout << "Bubble(): the point to vec is 0.\n";
        return ;
    }

    for (unsigned int i = 0; i < vec->size(); ++i)
    {
        for (unsigned int j = i + 1; j < vec->size(); ++j)
        {
            if (vec[i] > vec[j])
            {
                *out << (*vec)[i];
                if (out != 0)
                    *out << "call swap()! position : " << i
                        << ", and position: " << j << " swapping: "
                        << (*vec)[i] << ", with: " << (*vec)[j] << endl;


                Swap((*vec)[i], (*vec)[j], out);

                if (out != 0)
                {
                    *out << "after swap vector element: ";
                    Display(vec, out);
                }
            }
        }
    }
}

void ch_2_3()
{
    int ia[ 8 ] = { 8, 34, 3, 13, 1, 21, 5, 2 };
    vector<int> vec(ia, ia + 8);

//    Display(vec);
//    //BubbleSort(vec, cout);
//    BubbleSort(vec, 0);     // 0->避免二义性
//    Display(vec);

    ofstream    out("out.txt");
    Display(vec, out);
    BubbleSort(vec, out);
    Display(vec, out);
}

const vector<int>* FibonSeq1(int size)
{
    static vector<int>  elems;
    const int           max_elems = 1024;

    if (size <= 0 || size > max_elems)
    {
        cerr << "invalid size: " << size
            << "cannot handle request!\n";

        return 0;
    }

    for (int ix = elems.size(); ix < size; ++ix)
        if (ix == 0 || ix == 1)
            elems.push_back(1);
        else
            elems.push_back(elems[ix - 2] + elems[ix - 1]);

    return &elems;
}

void ch_2_4()
{
    bool more = true;
    while (more)
    {
        int pos;
        cout << "please enter a position: ";
        cin >> pos;

        ofstream    out("debug.txt");
        Display(FibonSeq1(pos), &out);

        cout << "would you want to try again?(Y/N): ";
        char ch;
        cin >> ch;
        if (ch != 'y' && ch != 'Y')
            more = false;
    }
}

const vector<int>* FibonSeq2(int size)
{
    static vector<int>  elems;

    if (!IsSizeOk1(size))
        return 0;

    for (int ix = elems.size(); ix < size; ++ix)
        if (ix == 0 || ix == 1)
            elems.push_back(1);
        else
            elems.push_back(elems[ix - 2] + elems[ix - 1]);

    return &elems;
}

bool FibonElem2(int size, int &elem)
{
    const vector<int> *pseq = FibonSeq2(size);
    if (!pseq)
    {
        elem = 0;
        return false;
    }

    elem = (*pseq)[size - 1];
    return true;
}

void DisplayMsg(const string &msg)
{
    cerr << msg << endl;
}

void DisplayMsg(const string &msg, int size)
{
    cerr << msg << " size: " << size << endl;
}

bool SeqElem(int size, int &elem, const std::vector<int>* (*seq_ptr)(int))
{
    const vector<int> *pseq = seq_ptr(size);
    if (!pseq)
    {
        elem = 0;
        DisplayMsg("Oops: seq ptr is point to null.");
        return false;
    }

    elem = (*pseq)[size - 1];
    return true;
}

void ch_2_8()
{
    using namespace ver0;

    bool more = true;
    while (more)
    {
        int pos;
        cout << "please enter a position: ";
        cin >> pos;

        int select;
        cout << "please enter a seq(1~7): ";
        cin >> select;

        int elem;
        ver0::SeqElem(pos + 1, elem, seq_array[select]);
        cout << "position: " << pos << " value is: " << elem << endl;

        cout << "would you want to try again?(Y/N): ";
        char ch;
        cin >> ch;
        if (ch != 'y' && ch != 'Y')
            more = false;
    }
}


void hw_2_6()
{
    cout << "max int value: " << Max(34, 199) 
        << ", max string value: " << Max("nihao", "hello") 
        << endl;

    int ia[ 8 ] = { 8, 34, 39, 13, 1, 21, 5, 2 };
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

}
