

#ifndef __MY_QUEUE_H__
#define __MY_QUEUE_H__

#include <deque>

//Adapter
//has-a
template<typename T, typename Sequence = std::deque<T>>
class Queue
{
protected:
    Sequence    c;  //deque<T>  c;
public:
    bool Empty() const { return c.empty(); }
    size_t Size() const { return c.size(); }
    T& Front() { return c.front(); }
    T& Back() { return c.back(); }

    void Push(const T &val) { c.push_back(val); }
    void Pop() { c.pop_front(); }
}; 





#endif

