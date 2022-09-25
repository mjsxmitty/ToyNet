
#include <vector>
#include "fibonacci_ver3.h"

using namespace std;

vector<int> FibonacciVer3::elems_;

//显示调用基类
FibonacciVer3::FibonacciVer3(int len, int beg) :
                // NumSequenceVer3(len, beg, elems_){}
                NumSequenceVer3(len, beg, elems_, "FibonacciVer3"){}

FibonacciVer3::FibonacciVer3(const FibonacciVer3 &rhs):
                                NumSequenceVer3(rhs) { }

FibonacciVer3& FibonacciVer3::operator=(const FibonacciVer3 &rhs)
{
    if (this != &rhs)
        NumSequenceVer3::operator=(rhs);    //显示调用基类的copy assign
    
    return *this;
}

void FibonacciVer3::GenElems(int pos) const
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
