
#include <vector>
#include "fibonacci_ver2.h"

using namespace std;
namespace chapter_05
{

namespace ver2
{

vector<int> Fibonacci::elems_;

//显示调用基类
Fibonacci::Fibonacci(int len, int beg) :
                // NumSequence(len, beg, elems_){}
                NumSequence(len, beg, elems_, "Fibonacci"){}

Fibonacci::Fibonacci(const Fibonacci &rhs):
                                NumSequence(rhs) { }

Fibonacci& Fibonacci::operator=(const Fibonacci &rhs)
{
    if (this != &rhs)
        NumSequence::operator=(rhs);    //显示调用基类的copy assign
    
    return *this;
}

void Fibonacci::GenElems(int pos) const
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

}

}
