
#include "lifo_stack.h"

using namespace std;

namespace ver2
{

bool LifoStack::pop(string &val)
{
    if (empty())
        return false;

    val = elem_[top_--];
    elem_.pop_back();
    return true;
}

bool LifoStack::push(const string &val)
{
    if (full())
       return false;

    elem_.push_back(val);
    ++top_;
    return true;
}

bool LifoStack::peek(int index, string &val)
{
    if (elem_.empty())
        return false;

    if (index < 0 || index >= size())
        return false;

    val = elem_[index];
    return true;
}

void LifoStack::print(ostream &os) const
{
    for (auto &val : elem_)
        cout << val << " ";
    cout << endl;
}

}
