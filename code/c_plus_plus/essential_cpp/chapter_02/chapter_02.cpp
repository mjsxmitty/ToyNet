

#include "chapter_02.h"
#include "../num_seq/num_seq.h"

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

void Practice_2_1()
{
    int pos;
    cout << "please enter a position: ";
    cin >> pos;

    unsigned int elem;
    if (FibonacciElem(pos, elem))
    {
        cout << "fibonacci sequence at position: " << pos
             << " is: " << elem << endl;
    }
    else
        cout << "sorry! cannot calculate position # "
             << pos << " elem "<< endl;
    cout << "The fibonacci sequence at the end position: " 
         << pos << endl; 
    PrintFibonacci(pos);
}

void Homework_2_1()
{
    bool more = true;
    while (more)
    {
        int pos;
        cout << "please enter a position: ";
        cin >> pos;

        unsigned int elem;
        if (FibonacciElem(pos, elem))
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

void Practice_2_3()
{
    int ia[ 8 ] = { 8, 34, 3, 13, 1, 21, 5, 2 };
    vector<int> vec(ia, ia + 8);

    BubbleSort(vec, cout);
    Display(vec);
}

void Homework_2_6()
{
    cout << "max int value: " << Max(34, 199) 
         << ", max string value: " << Max("nihao", "hello") 
         << endl;

    int ia[ 8 ] = { 8, 34, 39, 13, 1, 21, 5, 2 };
    cout << "max array value: " << Max(ia, 8) << endl;

    vector<int> vec(ia, ia + 8);
    //cout << "max vec value: " << *Max(vec.begin(), vec.end()) << endl;
    cout << "max value: " << *max_element(vec.begin(), vec.end()) << endl;
}

void Display(const vector<int> *vec, ostream &out)
{
    if (!vec)
    {
        out << "display(): the vector pointer is 0\n";
        return ;
    }
    
    for (int i = 0; i < vec->size(); i++)
        out << (*vec)[i] << ' ';
    
    out << endl;
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
    if (ofile)
        (*ofile) << "swap ( " << val1 << ", " << val2 << " )\n";
    
    int temp = val1;
    val1 = val2;
    val2 = temp;

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
                if (ofile)
                    *ofile << "call swap()! positon : " << i
                        << ", and position: " << j << " swapping: " 
                        << vec[i] << ", with: " << vec[j] << endl;
                Swap(vec[i], vec[j], ofile);
            }
        }
    }
}

bool FibonacciElem(int pos, int elem)
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

bool PrintFibonacci(int pos)
{
    if (pos <= 0 || pos > 1024)
    {
        cerr << "invalid position: " << pos
             << " ---> cannot handle request!"
             << endl;
        return false;
    }

    cout << "The Fibonacci sequence for: "
         << pos << " positions: \n\t";

    switch (pos)
    {
        case 2:
            cout << "1 ";
        case 1:
            cout << "1 ";
            break;
        default:
            break;
    }

    unsigned int elem;
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

