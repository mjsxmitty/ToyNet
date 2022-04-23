

#include "chapter_02.h"
#include "../util/num_seq.h"

#include <iostream>
#include <vector>

using namespace std;

void Chapter_02()
{
    //Practice_2_1();
    //Practice_2_3();
    //Homework_2_1();
    Homework_2_6();
}

bool FibonElem(int pos, int &elem)
{
    if (pos <= 0 || pos > 1024)
    {
        cerr << "invalid position: " << pos
             << " ---> cannot handle request!"
             << endl;
        elem = 0;
        return false;
    }

    elem = 1;
    int val1 = 1, val2 = 1;
    for (int i = 3; i <= pos; i++)
    {
        elem = val1 + val2;
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
         << pos << " positions: \n\t";

    switch (pos)
    {
        default:
        case 2:
            cout << "1\t";
        case 1:
            cout << "1\t";
            break;
    }

    int elem;
    int val1 = 1, val2 = 1;
    for (int i = 3; i <= pos; i++)
    {
        elem = val1 + val2;
        val2 = val1;
        val1 = elem;
        cout << elem << (!(i % 10) ? "\n\t" : "\t");
    }

    cout << endl;
    return false;
}

void Practice_2_1()
{
    int pos;
    cout << "please enter a position: ";
    cin >> pos;

    int elem;
    if (FibonElem(pos, elem))
    {
        cout << "fibonacci sequence at position: "
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

void Homework_2_1()
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
            cout << "fibonacci sequence at position: " << pos
                << " is: " << elem << endl;
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
    if (vec != 0)
    {
        *out << "display(): the vector pointer is 0\n";
        return ;
    }

    for (int i = 0; i < vec->size(); i++)
        *out << (*vec)[i] << ' ';

    *out << endl;
}

void Display(const vector<int> &vec, ostream &out)
{
    for (int i = 0; i < vec.size(); i++)
    out << vec[i] << ' ';

    out << endl;
}


void Swap(int &val1, int &val2, std::ostream &ofile)
{
    ofile << "swap ( " << val1 << ", " << val2 << " )\n";

    int temp = val1;
    val1 = val2;
    val2 = temp;

    ofile << "after swap(): val1: " << val1
          << ", val2: " << val2 << endl;
}

void Swap(int &val1, int &val2, std::ostream *ofile)
{
    if (ofile != 0)
        (*ofile) << "swap ( " << val1 << ", " << val2 << " )\n";

    int temp = val1;
    val1 = val2;
    val2 = temp;

    if (ofile != 0)
        (*ofile) << "after swap(): val1: " << val1
                 << ", val2: " << val2 << endl;
}

void BubbleSort(std::vector<int> &vec, std::ostream &ofile)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[i] > vec[j])
            {
                ofile << "call swap()! positon : " << i
                      << ", and position: " << j << " swapping: "
                      << vec[i] << ", with: " << vec[j] << endl;
                Swap(vec[i], vec[j], ofile);
            }
        }
    }
}

void BubbleSort(std::vector<int> &vec, std::ostream *ofile)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[i] > vec[j])
            {
                if (ofile != 0)
                    *ofile << "call swap()! positon : " << i
                        << ", and position: " << j << " swapping: "
                        << vec[i] << ", with: " << vec[j] << endl;
                Swap(vec[i], vec[j], ofile);
            }
        }
    }
}

void Practice_2_3()
{
    int ia[ 8 ] = { 8, 34, 3, 13, 1, 21, 5, 2 };
    vector<int> vec(ia, ia + 8);

    BubbleSort(vec, cout);
    Display(vec);

    ofstream    ofile("debug.txt");
    BubbleSort(vec, &ofile);
    Display(&vec, &ofile);
}

const vector<int>* FibonSeq(int pos)
{
//    const int           max_elems = 512;
    static vector<int>  elems;

//    if (pos <= 0 || pos > max_elems)
//    {
//        std::cerr << "invalid position: " << pos
//                  << "cannot handle request!\n";
//        return 0;
//    }

    if (!IsSizeOk(pos))
        return 0;

    for (int ix = elems.size(); ix < pos; ++ix)
        if (ix == 0 || ix == 1)
            elems.push_back(1);
        else
            elems.push_back(elems[ix - 2] + elems[ix - 1]);

    return &elems;
}

bool FibonElem2(int pos, int &elem)
{
    const vector<int> *pseq = FibonSeq(pos);
    if (!pseq)
    {
        elem = 0;
        return false;
    }

    elem = (*pseq)[pos - 1];
    return true;
}

void DisplayMsg(const std::string &msg)
{
    cerr << msg;
}

void DisplayMsg(const std::string &msg, int size)
{
    cerr << msg << " size: " << size << endl;
}

void Homework_2_6()
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
