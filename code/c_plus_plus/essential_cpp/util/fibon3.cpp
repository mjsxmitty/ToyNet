
#include <vector>
#include "fibon3.h"

using namespace std;

vector<int> Fibon3::elems_;

//显示调用基类
Fibon3::Fibon3(int len, int beg) :
                NumSeq3(len, beg, elems_){}

Fibon3::Fibon3(const Fibon3 &rhs)
        : NumSeq3(rhs) {}

Fibon3& Fibon3::operator=(const Fibon3 &rhs)
{
    if (this != &rhs)
        NumSeq3::operator=(rhs);    //显示调用基类的copy assign
    
    return *this;
}

void Fibon3::GenElems(int pos) const
{
    if (elems_.empty())
    {
        elems_.push_back(1);
        elems_.push_back(1);
    }
    
    if(elems_.size() <= pos)
    {
        int ix = elems_.size();
        int n2 = elems_[ix - 2];
        int n1 = elems_[ix - 1];

        for ( ; ix < pos; ++ix)
        {
            int elem = n1 + n2;
            elems_.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }
}