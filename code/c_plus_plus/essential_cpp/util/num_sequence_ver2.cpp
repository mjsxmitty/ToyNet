
#include <iostream>

#include "num_sequence_ver2.h"

using namespace std;

std::ostream& operator<<(std::ostream &os, const NumSequenceVer2 &ns)
{
    cout << " ( " << ns.Length() << ", " << ns.BegPos() << " ) "; 
    return  ns.Print(os);
}

bool NumSequenceVer2::CheckIntegrity(int pos, int size) const
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
