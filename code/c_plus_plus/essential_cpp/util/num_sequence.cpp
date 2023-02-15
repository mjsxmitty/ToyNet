
#include <iostream>
#include <vector>
#include <algorithm>

#include "num_sequence.h"

using namespace std;

namespace numeric_sequence
{
//pvec (*seq_array[])(int)
pfunc seq_array[seq_cnt] = {
    0,
    FiboSeq,    PellSeq,
    LucaSeq,    TriaSeq,
    SquaSeq,    PentSeq
};

pvec FiboSeq(int size)
{
    static vector<int> elems;
    if (!CheckIntegrity(size))
        return 0;
    
    if (elems.empty())
    {
        elems.push_back(1);
        elems.push_back(1);
    }

    if (elems.size() < size)
    {
        int ix = elems.size();
        int n2 = elems[ix - 2];
        int n1 = elems[ix - 1];
        int elem;

        for (; ix < size; ix++)
        {
            elem = n2 + n1;
            elems.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }

    return &elems;
}

pvec PellSeq(int size)
{
    static vector<int> elems;
    if(!CheckIntegrity(size))
        return 0;
    
    if (elems.empty())
    {
        elems.push_back(1);
        elems.push_back(2);
    }

    if (elems.size() < size)
    {
        int ix = elems.size();
        int n2 = elems[ix - 2];
        int n1 = elems[ix - 1];
        int elem;

        for (; ix < size; ix++)
        {
            elem = n2 + 2 * n1;
            elems.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }
    
    return &elems;
}

pvec LucaSeq(int size)
{
    static vector<int> elems;
    if(!CheckIntegrity(size))
        return 0;
    
    if (elems.empty())
    {
        elems.push_back(1);
        elems.push_back(3);
    }

    if (elems.size() < size)
    {
        int ix = elems.size();
        int n2 = elems[ix - 2];
        int n1 = elems[ix - 1];
        int elem;

        for (; ix <= size; ix++)
        {
            elem = n2 + n1;
            elems.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }
    
    return &elems;
}

pvec TriaSeq(int size)
{
    static vector<int> elems;
    if(!CheckIntegrity(size))
        return 0;
    
    if (elems.size() < size)
    {
        int ix = elems.size() ? elems.size() + 1 : 1;
        for (; ix <= size; ix++)
            elems.push_back(ix * (ix + 1) / 2);
    }
    
    return &elems;
}

pvec SquaSeq(int size)
{
    static vector<int> elems;
    if(!CheckIntegrity(size))
        return 0;
    
    if (elems.size() < size)
    {
        int ix = elems.size() ? elems.size() + 1 : 1;
        for (; ix <= size; ix++)
            elems.push_back(ix * ix);
    }
    
    return &elems;
}

pvec PentSeq(int size)
{
    static vector<int> elems;
    if(!CheckIntegrity(size))
        return 0;
    
    if (elems.size() < size)
    {
        int ix = elems.size() ? elems.size() + 1 : 1;
        for (; ix <= size; ix++)
            elems.push_back(ix * (3 * ix - 1) / 2);
    }
    
    return &elems;
}

bool SeqElem(int size, int &elem, pfunc f)
{
    pvec pseq = f(size);
    if (!pseq)
    {
        elem = 0;
        return false;
    }
    
    vector<int> ivec(*pseq);
    for_each(ivec.begin(), ivec.end(), [](int i) {
        cout << i << " ";
    });
    cout << endl;
    
    elem = (*pseq)[size - 1];
    
    return true;
}

}