
#ifndef __CPP_CHAPETR_10_HPP__
#define __CPP_CHAPETR_10_HPP__

#include <string>
#include <iostream>
#include <mutex>

namespace chapter_10
{

void Hello();

void TestThread();

void TestThread1();

class ThreadHello
{
public:
    ThreadHello () {}
    void Print(const std::string &s)
    {
        std::cout << "ThreadHello::Print(): "
                  << s << std::endl;
    }

    static void print(const std::string &s)
    {
        std::cout << "ThreadHello::print(): "
                  << s << std::endl;
    }
};

void TestThread2();

class Even
{
public:
    Even()
    {
        s_mutex.lock();
        std::cout << "lock" << std::endl;
    }
    ~Even()
    {
        s_mutex.unlock();
        std::cout << "unlock" << std::endl;
    }
    static std::mutex s_mutex;
};

void TestThread3();
void TestThread4();
void TestThread5();
void TestThread6();
}

#endif //__CPP_CHAPETR_10_HPP__
