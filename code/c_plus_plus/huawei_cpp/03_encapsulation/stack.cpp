
#include <iostream>
#include <string.h>
#include "stack.h"

using namespace std;

//void GZStack::Init()
//{
//    memset(space, 0, sizeof(space));
//    top = 0;
//}
template <typename T>
GZStack<T>::GZStack(int size) : space(new T(size)), top(0)
{
    cout << "GZStack construct func." << endl;
//    space = new int[size];
//    top = 0;
}

template <typename T>
GZStack<T>::~GZStack()
{
    cout << "GZStack disconstruct func." << endl;
    delete space;
}

template <typename T>
bool GZStack<T>::IsEmpty()
{
    return top == 0;
}

template <typename T>
bool GZStack<T>::IsFull()
{
    return top == 1024;
}

template <typename T>
void GZStack<T>::Push(int data)
{
    space[top++] = data;
}

template <typename T>
T GZStack<T>::Pop()
{
    return space[--top];
}
