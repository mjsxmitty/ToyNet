

#include <iostream>
#include <vector>
#include <algorithm>

#include "num_sequence.h"

using namespace std;
using namespace chapter_04;

int main()
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

    return 0;
}
