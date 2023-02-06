
#ifndef __CPP_CHAPETR_12_HPP__
#define __CPP_CHAPETR_12_HPP__

#include <memory>

using namespace std;

namespace chapter_12
{

void Test1();
void Test2();

class TestPtr : public enable_shared_from_this<TestPtr>
{
public:

};

void Test3();
void Test4();
void Test5();
void Test6();


class RefCount
{
public:
    RefCount() : shared_count_(0), weak_ptr_(0){}

    int shared_count_;
    int weak_ptr_;
};

template <typename T>
class SharedPtr
{
public:
    SharedPtr(T* ptr = nullptr) : ptr_(ptr)
    {
        count_ = new RefCount();
        if (ptr)
        {
            count_->shared_count_ = 1;
        }
    }

    SharedPtr(const SharedPtr &rhs)
    {
        ptr_ = rhs.ptr_;
        rhs.count_->shared_count_++;
        count_ = rhs.count_;
    }

    SharedPtr& operator=(const SharedPtr &rhs)
    {
        if (this != &rhs)
        {
            Release();
            rhs.count_->shared_count_++;
            count_ = rhs.count_;
            ptr_ = rhs.ptr_;

        }
    }

    T operator*()
    {
        return *ptr_;
    }

    T* operator->()
    {
        return ptr_;
    }

    void Release()
    {
        count_->shared_count_--;
        if (count_->shared_count_ == 0)
        {
            delete count_;
            count_ = nullptr;
            delete ptr_;
            ptr_ = nullptr;
        }
    }

    ~SharedPtr() {}
private:
    T           *ptr_;
    RefCount    *count_;
};
}

#endif //__CPP_CHAPETR_12_HPP__
