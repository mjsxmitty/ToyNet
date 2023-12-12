
#include <iostream>
#include "chapter_02.h"

using namespace std;
using namespace chapter_02;

/* chapter 2.1 */
int main()
{
    cout << "please enter a position: ";
    int pos;
    cin >> pos;

    int elem;
    if (FibonElem(pos, elem))
    {
        cout << "element at position # "
            << pos << " is: " << elem
            << endl;
    }
    else
    {
        cout << "sorry! cannot calculate position: "
            << pos << " elem."<< endl;
        return -1;
    }

    PrintFibon(pos);
    return 0;
}

/* practice 2.1 */
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

    return 0;
}
