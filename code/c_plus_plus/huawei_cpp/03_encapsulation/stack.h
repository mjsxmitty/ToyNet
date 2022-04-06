

#ifndef __HUAWEI_CHAPTER_03_ENCAPSULATION_STACK_H__
#define __HUAWEI_CHAPTER_03_ENCAPSULATION_STACK_H__

template <typename T>
class GZStack
{
public:
    GZStack(int size);
    ~GZStack();
public:
    //void    Init();
    bool    IsEmpty();
    bool    IsFull();
    void    Push(int data);
    T     Pop();
private:
    //int space[1024];
    T   *space;
    int top;
};

#endif // __HUAWEI_CHAPTER_03_ENCAPSULATION_STACK_H__
