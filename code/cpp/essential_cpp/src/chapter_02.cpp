
#include <iostream>

#include "common.h"
#include "num_sequence.h"

using namespace std;
using namespace common;

int main1()
{
    cout << "please enter a position: ";
    int pos;
    cin >> pos;

    int elem;
    if (FibonElem(pos, elem))
    {
        cout << "element at position: "
                    << pos << " is: " << elem
                    << endl;
    }
    else
    {
        cout << "sorry! cannot calculate position "
                    << pos << " elem."<< endl;
        return -1;
    }

    PrintFibon(pos);
    return 0;
}

int main2()
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
            cout << "element at position: " << pos
                << " value is: " << elem << endl;
        }
        else
            cout << "sorry! cannot calculate position "
                        << pos << " elem "<< endl;

        cout << "would you want to try again?(Y/N): ";
        char ch;
        cin >> ch;
        if (ch != 'y' && ch != 'Y')
            more = false;
    }

    return 0;
}

int main3()
{
    int ia[8] = { 8, 34, 3, 13, 1, 21, 5, 2 };
    vector<int> vec(ia, ia + 8);
#if 0
    Display(vec);
    BubbleSort(vec, NULL);     // 0->避免二义性
    Display(vec);
#endif
#if 1
    ofstream out("out.txt");
    Display(vec, out);
    BubbleSort(vec, out);
    Display(vec, out);
#endif
    return 0;
}

int main()
{
    bool more = true;
    while (more)
    {
        int cnt;
        cout << "enter a servies position: ";
        cin >> cnt;

        int elem;
        for (int i = NS_FIB; i < seq_cnt; ++i)
        {
            if (SeqElem(cnt, elem, seq_array[i]))
            {
                cout << seq_name[i] << " element at position: " << cnt
                            << " value is: " << elem << endl;
            }
        }

        cout << "would you want to try again?(Y/N): ";
        char ch;
        cin >> ch;
        if (ch != 'y' && ch != 'Y')
            more = false;
    }
}