
#ifndef __EFFECTIVE_CPP_ITEM_14_H__
#define __EFFECTIVE_CPP_ITEM_14_H__

#include <mutex>
#include <memory>
#include <iostream>

void Item14();

namespace effective_item_14 {

void lock(std::mutex *pm);
void unlock(std::mutex *pm);

class Lock
{
public:
    explicit Lock(std::mutex *pm) : mutex_ptr_(pm, unlock)
    {
        std::cout << "Lock::Lock()" << std::endl;
        lock(mutex_ptr_.get());
    }
private:
    std::shared_ptr<std::mutex> mutex_ptr_;
};

}


#endif // __EFFECTIVE_CPP_ITEM_14_H__
