
#include <algorithm>
#include "stack.h"

using namespace std;

bool Stack::Push(const std::string &elem)
{
    if (Full()) return false;

    elems_.push_back(elem);
    return true;
}

bool Stack::Pop(std::string &elem)
{
    if (Empty()) return false;

    elem = elems_.back();
    elems_.pop_back();
    return true;
}

bool Stack::Peek(std::string &elem)
{
    if (Empty()) return false;

    elem = elems_.back();
    //elems_.pop_back();
    return true;
}

bool Stack::Find(const std::string &elem)
{
    if (Empty()) return false;

    return find(elems_.begin(), elems_.end(), elem) != elems_.end();
}

int Stack::Count(const string &elem)
{
    if (Empty()) return false;

    return count(elems_.begin(), elems_.end(), elem);
}

