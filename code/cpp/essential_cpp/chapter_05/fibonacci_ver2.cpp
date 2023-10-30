
#include <vector>
#include "fibonacci_ver2.h"

using namespace std;

namespace chapter_05
{
namespace ver2
{

vector<int> Fibonacci::elems_;

Fibonacci::Fibonacci(int len, int beg) :
                // NumSequence(len, beg, elems_){}
                NumSequence(len, beg, elems_, "Fibonacci")
{

}

Fibonacci::Fibonacci(const Fibonacci &rhs) : NumSequence(rhs) // 基类没有会自动调用默认
{

}

Fibonacci& Fibonacci::operator=(const Fibonacci &rhs)
{
    if (this != &rhs)
        NumSequence::operator=(rhs);    // 必须手动调用
    
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
