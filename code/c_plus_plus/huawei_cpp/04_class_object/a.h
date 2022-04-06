

#ifndef __HUAWEI_CHAPTER_04_CLASS_OBJECT_H__
#define __HUAWEI_CHAPTER_04_CLASS_OBJECT_H__


class A
{
public:
    A();
    A(const A&);
    A& operator=(const A&);
    ~A();
    void func();
};

class PmA
{
public:
    PmA(A *p) : p_(p) {}
    ~PmA() { delete p_; }
    A& operator*() { return *p_; }
    A* operator->(){ return p_; }
private:
    A *p_;
};

#endif // __HUAWEI_CHAPTER_04_CLASS_OBJECT_H__
