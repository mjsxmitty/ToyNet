

#include "chapter_02.h"
#include "../util/num_sequence.h"

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
       cout << "elemment at position # "
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
            cout << "elemment at position # " << pos
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

void Swap(int &val1, int &val2, std::ostream &ofile)
{
    ofile << "swap ( " << val1 << ", " << val2 << " )\n";

    int temp = val1;
    val1 = val2;
    val2 = temp;

    ofile << "after swap: val1: " << val1
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
        (*ofile) << "after swap: val1: " << val1
                 << ", val2: " << val2 << endl;
}

void BubbleSort(std::vector<int> &vec, std::ostream &ofile)
{
    for (unsigned int i = 0; i < vec.size(); ++i)
    {
        for (unsigned int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[i] > vec[j])
            {
                ofile << "call swap()! positon : " << i
                      << ", and position: " << j << " swapping: "
                      << vec[i] << ", with: " << vec[j] << endl;

                Swap(vec[i], vec[j], ofile);

                ofile << "after swap vector elemment: ";
                Display(vec, ofile);
            }
        }
    }
}

void BubbleSort(std::vector<int> *vec, std::ostream *out)
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
                    *out << "call swap()! positon : " << i
                        << ", and position: " << j << " swapping: "
                        << (*vec)[i] << ", with: " << (*vec)[j] << endl;


                Swap((*vec)[i], (*vec)[j], out);

                if (out != 0)
                {
                    *out << "after swap vector elemment: ";
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

    ofstream    ofile("out.txt");
    Display(vec, ofile);
    BubbleSort(vec, ofile);
    Display(vec, ofile);
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

        ofstream    ofile("debug.txt");
        Display(FibonSeq1(pos), &ofile);

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

bool FibonElem2(int pos, int &elem)
{
    const vector<int> *pseq = FibonSeq2(pos);
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

/* 锟斤拷锟斤拷指锟斤拷锟斤拷锟斤拷锟斤拷锟侥碉拷锟斤拷 */
void ch_2_8()
{
//    bool more = true;
//    while (more)
//    {
//        cout << "please enter a sequence index(0~7): ";
//        int index;
//        cin >> index;
//        pfunc pf = seq_array[index];
//        if (!pf)
//        {
//            DisPlay("Internal error: func ptr is set to null.");

//            cout << "would you want to try again?(Y/N): ";
//            char ch;
//            cin >> ch;
//            if (ch != 'y' && ch != 'Y')
//                more = false;
//            continue;
//        }

//        int pos;
//        cout << "please enter a position: ";
//        cin >> pos;

//        int elem;
//        ofstream    ofile("debug.txt");
//        SeqElem(pos, elem, pf);
//        cout << "position: " << pos << " value is: " << elem << endl;

//        cout << "would you want to try again?(Y/N): ";
//        char ch;
//        cin >> ch;
//        if (ch != 'y' && ch != 'Y')
//            more = false;
//    }

    bool more = true;
    while (more)
    {
        int pos;
        cout << "please enter a position: ";
        cin >> pos;

        int elem;
        SeqElem(pos, elem, seq_array[NS_FIB]);
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
