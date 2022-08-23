
#include <iostream>
#include <vector>

#include "num_seq.h"

using namespace std;

//pvec (*seq_array[])(int)
pfunc seq_array[seq_cnt] = {
    0,
    FiboSeq,    PellSeq,
    LucaSeq,    TriaSeq,
    SquaSeq,    PentSeq
};

pvec FiboSeq(int pos)
{
    static vector<int> elems;
    if (!CheckIntegrity(pos))
        return 0;
    
    if (elems.empty())
    {
        elems.push_back(1);
        elems.push_back(1);
    }

    if (elems.size() < pos)
    {
        int ix = elems.size();
        int n2 = elems[ix - 2];
        int n1 = elems[ix - 1];
        int elem;

        for (; ix < pos; ix++)
        {
            elem = n2 + n1;
            elems.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }

    return &elems;
}

pvec PellSeq(int pos)
{
    static vector<int> elems;
    if(!CheckIntegrity(pos))
        return 0;
    
    if (elems.empty())
    {
        elems.push_back(1);
        elems.push_back(2);
    }

    if (elems.size() < pos)
    {
        int ix = elems.size();
        int n2 = elems[ix - 2];
        int n1 = elems[ix - 1];
        int elem;

        for (; ix < pos; ix++)
        {
            elem = n2 + 2 * n1;
            elems.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }
    
    return &elems;
}

pvec LucaSeq(int pos)
{
    static vector<int> elems;
    if(!CheckIntegrity(pos))
        return 0;
    
    if (elems.empty())
    {
        elems.push_back(1);
        elems.push_back(3);
    }

    if (elems.size() < pos)
    {
        int ix = elems.size();
        int n2 = elems[ix - 2];
        int n1 = elems[ix - 1];
        int elem;

        for (; ix <= pos; ix++)
        {
            elem = n2 + n1;
            elems.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }
    
    return &elems;
}

pvec TriaSeq(int pos)
{
    static vector<int> elems;
    if(!CheckIntegrity(pos))
        return 0;
    
    if (elems.size() < pos)
    {
        int ix = elems.size() ? elems.size() + 1 : 1;
        for (; ix <= pos; ix++)
            elems.push_back(ix * (ix + 1) / 2);
    }
    
    return &elems;
}

pvec SquaSeq(int pos)
{
    static vector<int> elems;
    if(!CheckIntegrity(pos))
        return 0;
    
    if (elems.size() < pos)
    {
        int ix = elems.size() ? elems.size() + 1 : 1;
        for (; ix <= pos; ix++)
            elems.push_back(ix * ix);
    }
    
    return &elems;
}

pvec PentSeq(int pos)
{
    static vector<int> elems;
    if(!CheckIntegrity(pos))
        return 0;
    
    if (elems.size() < pos)
    {
        int ix = elems.size() ? elems.size() + 1 : 1;
        for (; ix <= pos; ix++)
            elems.push_back(ix * (3 * ix - 1) / 2);
    }
    
    return &elems;
}

/* 函数指针带来更大的弹性(call back) */
bool SeqElem(int pos, int &elem, pfunc f)
{
    pvec pseq = f(pos);
    if (!pseq)
    {
        elem = 0;
        return false;
    }
    
    elem = (*pseq)[pos - 1];
    return true;
}
