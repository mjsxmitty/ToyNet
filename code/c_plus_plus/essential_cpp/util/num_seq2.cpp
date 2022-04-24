
#include <iostream>

#include "num_seq2.h"

using namespace std;

std::ostream& operator<<(std::ostream &os, const NumSeq2 &ns)
{
    cout << " ( " << ns.Length() << ", " << ns.BegPos() << " ) "; 
    ns.Print(os);
    return os;
}

bool NumSeq2::CheckIntegrity(int pos, int size) const
{
    if (pos <=0 || pos >= max_elems_)
    {
        cerr << "invalid position: " << pos
             << " can not handle request!!"
             << endl;
        return false;
    }

    if (pos > size)
        GenElems(pos);  //虚拟机制调用

    return true;
}