
/*像指针的类（智能指针）*/
#ifndef __POINT_LIKE_CLASS_H_
#define __POINT_LIKE_CLASS_H_

template<typename T>
class SharePtr
{
private:
    T   *px;
public:
    SharePtr(T *p) : px(p){}
public:
    //px->methoc()
    T* operator->() const { return px; }
    T& operator*() const { return *px; } 
};

void TestPointClass();


//双向连表
template<typename T>
struct Node
{
    void    *prev;
    void    *next;
    T       data;
};

//迭代器里边也是包含指针
template<typename T>
struct ListIterator
{
    typedef Node<T> *LinkType;
    LinkType    node;

    T& operator*() const { return (*node).data; }

    // ListIterator<Foo>::iterator iter;
    // iter->method();

    // 调用Foo::method();
    // (*iter).method();
    // &(*iter)->method();
    T* operator->() const { return &(operator*()); }
};


#endif //__POINT_LIKE_CLASS_H_