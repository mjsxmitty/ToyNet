
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <future>
#include <condition_variable>

#include "chapter_10.h"

using namespace std;

namespace chapter_10
{

#define LOCK_SOPE Even;

mutex Even::s_mutex;

mutex s_mutex;

void Hello()
{
    //s_mutex.try_lock();
    //s_mutex.lock();
    //lock_guard<mutex> aa(Even::s_mutex);
    //lock_guard<mutex> aa(s_mutex);
    unique_lock<mutex> aa(s_mutex);
    //....
    //aa.lock();
    cout << "branch thread, thread id: " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(2));
    //s_mutex.unlock();
}

void Hello1()
{
    cout << "branch thread1, thread id: " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(2));
}

void Hello2(int i, const string &s)
{
    cout << "branch thread2, thread id: " << i << "-" << s << endl;
    this_thread::sleep_for(chrono::seconds(2));
}

void TestThread()
{
    thread t(Hello);
    //cout << t.joinable() << endl;
    //t.join();   // 同步,阻塞
    //t.detach();

    thread t1(Hello1);

    cout << "thread 1 id: " << t.get_id() << endl;
    cout << "thread 2 id: " << t1.get_id() << endl;
    t1.swap(t);
    cout << "thread 1 id: " << t.get_id() << endl;
    cout << "thread 2 id: " << t1.get_id() << endl;
    t.join();
    t1.join();
    cout << "main thread, thread id: " << this_thread::get_id() << endl;

}

void TestThread1()
{
    thread t(Hello2, 1, "hello");
    t.join();

    int i = 1024;
    string s = "hello";
    thread t2([](int i, const string &s) {
        cout << i << "->" << s << endl;
    }, i, s);

    t2.join();

    ThreadHello hello;
    thread t3(&ThreadHello::Print, &hello, "hello");
    t3.join();


    thread t4(ThreadHello::print, "hello");
    t4.join();

    thread t5 = move(t);
    t5.join();

    cout << "main thread ... " << endl;
}

once_flag oflag;
void CallOnce()
{
    call_once(oflag, [](){
        Hello1();
    });
}

void TestThread2()
{
    for (int i = 0; i != 5; ++i)
    {
//        thread t(Hello);
        thread t(CallOnce);
        t.detach();
    }

    this_thread::sleep_for(chrono::seconds(10));
}

condition_variable cv;

void LockTest()
{
    cout << "LockTest() start sleep ..." << endl;
    this_thread::sleep_for(chrono::seconds(10));
    cout << "LockTest()" << endl;
    //cv.notify_one();
    cv.notify_all();
    this_thread::sleep_for(chrono::seconds(5));
    cout << "LockTest() end ..." << endl;
}

mutex loack;
void LockTest1()
{
    cout << "LockTest1()" << endl;
    unique_lock<mutex> lock(loack);
    cout << "LockTest1() lock" << endl;
    cv.wait(lock);
    cout << "LockTest1()" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "LockTest1() end" << endl;
}
void TestThread3()
{
    thread t(LockTest);
    t.detach();
    cout << "LockTest start ..." << endl;

    thread t1(LockTest1);
    t1.detach();
    cout << "LockTest1 start ..." << endl;

    unique_lock<mutex> ul(s_mutex);
    cout << "LockTest lock ..." << endl;
    cv.wait(ul);        // 主线程锁住
    cout << "test end ..." << endl;
}

string GetRetValue(int i)
{
    char buff[128];
    snprintf(buff, sizeof (buff) - 1, "GetRetValue: %d", i);
    return buff;
}

void TestThread4()
{
    future<string> ret = async(launch::async, GetRetValue, 1024);   //异步
    this_thread::sleep_for(chrono::seconds(5));
    string s = ret.get();   // 只能get一次
    //ret.valid();
    cout << "ret: " << s << endl;
}

string GetRetValue1(future<string> &s)
{
    cout << "GetRetValue(future<string> &) : " << s.get() << endl;
    return "ok";
}

string GetRetValue2(shared_future<string> s)
{
    cout << "GetRetValue(future<string> &) : " << s.get() << endl;
    return "ok";
}
void TestThread5()
{
    promise<string> spro;
    future<string> fut = spro.get_future();
    //future<string> ret = async(launch::async, GetRetValue1, std::ref(fut));   //异步
    shared_future<string> share = fut.share();
    future<string> ret1 = async(launch::async, GetRetValue2, share);
    future<string> ret2 = async(launch::async, GetRetValue2, share);

    spro.set_value("123");
    cout << "test end ..." << endl;
    this_thread::sleep_for(chrono::seconds(5));
}

int Hello1(int i, int j)
{
    return i + j;
}

void TestThread6()
{
    packaged_task<int(int, int)> task([](int i, int j) -> int
    {
        return i + j;
    });

    //packaged_task<int(int, int)> task(std::bind(Hello1, 1, 2));

    this_thread::sleep_for(chrono::seconds(3));
    task(1, 4);
    this_thread::sleep_for(chrono::seconds(2));
    if (task.valid())
    {
        auto f = task.get_future();
        cout << "val = " << f.get() << endl;
    }
    this_thread::sleep_for(chrono::seconds(2));
}
}
