
#include <iostream>
#include <algorithm>
#include "stack.h"

using namespace std;

namespace ver1
{

void FillStack(Stack &stack, istream &is)
{
    string str;
    while (is >> str && !stack.Full())
        stack.Push(str);

    cout << "read in " << stack.Size() << " elements\n";
}

bool Stack::Push(const string &elem)
{
    if (Full())
    {
        cerr << "stack is full!" << endl;
        return false;
    }

    elems_.push_back(elem);
    return true;
}

bool Stack::Pop(string &elem)
{
    if (Empty()) return false;

    elem = elems_.back();
    elems_.pop_back();
    return true;
}

bool Stack::Peek(string &elem)
{
    if (Empty()) return false;

    elem = elems_.back();
    //elems_.pop_back();
    return true;
}

bool Stack::Find(const string &elem)
{
    if (Empty()) return false;

    return find(elems_.begin(), elems_.end(), elem) != elems_.end();
}

int Stack::Count(const string &elem)
{
    if (Empty()) return 0;

    return count(elems_.begin(), elems_.end(), elem);
}

}