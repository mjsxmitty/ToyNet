#include <windows.h>
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>
#include <future>
#include "Runnable.h"
#include "Platform.h"
#include "Event.h"

using namespace std;

void Hello()
{
	cout << "Hello World" << endl;//异步

	this_thread::sleep_for(chrono::seconds(2));
}

void Hello2()
{
	cout << "Hello World" << endl;//异步

	this_thread::sleep_for(chrono::seconds(2));
}

void Hello3(int a ,const string &b)
{
	cout << "Hello World" << endl;//异步

	this_thread::sleep_for(chrono::seconds(2));
}
 
struct FMEvent
{
	FMEvent()
	{
		m.lock();
		cout << "Lock" << endl;
	}

	~FMEvent()
	{
		m.unlock();

		cout << "UnLock" << endl;
	}

	static mutex m;
};
mutex FMEvent::m;

#define LOCK_SCOPE FMEvent Event

void Hello66()
{
	bool bLock = FMEvent::m.try_lock();

	if (bLock)//非阻塞模式
	{
		//加锁
		LOCK_SCOPE;

		//线程排队
		cout << "Hello World" << endl;//异步

		this_thread::sleep_for(chrono::seconds(2));
	}	

	//FEvent::m.native_handle();

	//挂起 唤醒


}

class FTest
{
public: 
	void Run(const string& S)
	{
		cout << S << endl;
	}
};

void Hello77()
{
	while (true)
	{
		Sleep(1000);
		//this_thread::sleep_for(chrono::seconds(1000));
		cout << "Hello" << endl;
	}
}

void Hello88(const string &Msg)
{
	while (true)
	{
		Sleep(1000);
		//this_thread::sleep_for(chrono::seconds(1000));
		cout << "Hello" << Msg << endl;
	}
}


void Hello99(const string& Msg)
{
	//lock_guard<mutex> ww1(FEvent::m);
	
	//...
	unique_lock<mutex> ww2(FMEvent::m,defer_lock);
	//unique_lock<std::mutex> ww3(FEvent::m,chrono::seconds(2));
	//...

//	bool block = ww2.try_lock();//
//	ww2.try_lock_for(chrono::seconds(2));
	//time_t t = time(NULL); //c语言std里面讲解过
	//xtime timel;
	//xtime_get(&timel, t + 10000);
	//block = ww2.try_lock_until(&timel); //锁时间点
//	FEvent::m.try_lock_until()
	ww2.lock();
	//mutex *mm= ww2.release();
	//ww2.mutex();
	bool bw = ww2.owns_lock();//判断当前是不是锁住了
	unique_lock<mutex> ww6;
	ww2.swap(ww6);
	unique_lock<mutex> ww7 = move(ww6);

	cout << "asdas" << endl;
	ww7.unlock();
	//....
	Sleep(1000);
}

void Init()
{
	cout << "Hello" << endl;
	Sleep(2000);
}

once_flag o_flag;
void Hello1111()
{
	call_once(o_flag, []() 
	{
		Init();
	});
}

mutex tx;
mutex tx1;
condition_variable cm;
void Hello11()
{
	Sleep(1000);
//	cm.notify_one();
	cm.notify_all();
	Sleep(1000);
}

void Hello112()
{
	unique_lock<mutex> Lock(tx1);
	cm.wait(Lock);
	cout << "ddd" << endl;
}

string GetHello(int a)
{
	cout << a << endl;
	return "OK";
}

string GetHello1(future<string> &a)
{
	cout << a.get() << endl;
	return "OK";
}

string GetHello2(shared_future<string> a)
{
	cout << a.get() << endl;
	return "OK";
}

int helloccc(int a, int b)
{
	return a + b;
}
HANDLE hMutex = nullptr;
DWORD WINAPI FunThread(LPVOID lpPram)
{
	for (int i = 0; i < 100 ;i ++)
	{
		cout << "Hello" << endl;
	}


	//for (int i = 0; i < 10; i++)
	//{
	//	WaitForSingleObject(hMutex, INFINITE);
	//	Sleep(1000);

	//	ReleaseMutex(hMutex);
	//}

	Sleep(1000);
	return 0l;
}

//线程队列
class FMyRunnable :public FRunnable
{
public:
	FMyRunnable(const EThreadPriority InPriority /*= EThreadPriority::TPri_Normal*/,
		unsigned int InStack /*= 0*/,
		const char* InThreadName)
		:bStop(false)
	{
		Thread = Platform::Create(this, InPriority, InStack, InThreadName);
	}

	virtual bool Init() 
	{
		return true;
	};

	virtual int Run()
	{
		for (;;)
		{
			int i = 0;
			while (!bStop)//逻辑层
			{
				//具体逻辑
				Sleep(200);

				std::cout << "FMyRunnable" << std::endl;

				if (i >= 10)//100
				{
					if (Thread)
					{
						Thread->Suspend();
					}
				}

				i++;
			}

			Sleep(1000);
			break;
		}

		return 0;
	}

	virtual int Stop()
	{
		return 0;
	}

	virtual bool Exit()
	{
		delete Thread;
		return true;
	}

	virtual FRunnableThread* GetThread()
	{
		return Thread;
	}
protected:
	bool bStop;
	FRunnableThread* Thread;
};


//std:: 跨平台
//分配一定的栈数据
int main()
{
	//1.Thread API
///////////////////////////////////////////////////////
//	std::thread thread(Hello); //thread.joinable
	//thread.join();//阻塞
	//thread.detach();//非阻塞
	//bool Helloccc = thread.joinable();
	//thread::id ThrID = thread.get_id();
	//int threadNumber = thread.hardware_concurrency();
//	auto c1 = thread.native_handle();

	//std::thread thread2(Hello2);
	//thread.swap(thread2);
	//thread.join();

	//thread2.join();
	/*for (int i = 0; i < thread.hardware_concurrency(); i++)
	{
		std::thread thread(Hello);
		thread.detach();
	}*/
	//thread.join();
	//join 它会阻塞主线程 同步操作

	//2.传递参数
/////////////////////////////////////////////////////
	//传递特定参数
	//thread newThread(Hello3,1,"Hello Thread");
	//newThread.detach();

	//传递lambda
	//int a = 100;
	//thread newThread1([&](int b,const string &c) 
	//{
	//	cout << a << b << c << endl;
	//}, 1, "Hello Thread");
	//newThread1.detach();

	//传对象
//	FTest T;
//	thread newThread1(&FTest::Run,&T,"Hello");
////	newThread1.detach();
//
//	for (int i = 0; i < newThread1.hardware_concurrency(); i++)
//	{
//		std::thread thread(Hello66);
//		thread.detach();
//	}
//	this_thread::sleep_for(chrono::seconds(1000));

	//thread th(Hello77);
	//SuspendThread(th.native_handle());
	//this_thread::sleep_for(chrono::seconds(2));
	//ResumeThread(th.native_handle());

	//thread newThread1(Hello99,move("Hello"));
	//thread newThread333 = move(newThread1);

	//newThread333.detach();

	//std::thread thread(Hello11);
	//thread.detach();
	//std::thread thread1(Hello112);
	//thread1.detach();
	//unique_lock<mutex> Lock(tx);
	//cm.wait(Lock);//主线程锁住

	/*future<string> newfutre = async(launch::deferred, GetHello, 8);
	Sleep(2000); 
	string re; 
	if (newfutre.valid())
	{
		re = newfutre.get();
	}*/

	//promise<string> pro;
	////promise<string> pro1;
	////pro = move(pro1);
	//future<string> fut = pro.get_future();
	//future<string> newfutre = async(launch::async, GetHello1, std::ref(fut));
	//pro.set_value("Hello");
	////re = newfutre.get();//奔溃
	//cout << "Hello" <<endl;

	//promise<string> pro;
	//future<string> fut = pro.get_future();
	//shared_future<string> sharef1 = fut.share();
	////shared_future<string> sharef2 = fut.share();
	////sharef2 = sharef1;
	//future<string> newfutre = async(launch::async, GetHello2, sharef1);
	//future<string> newfutre1 = async(launch::async, GetHello2, sharef1);
	//future<string> newfutre2 = async(launch::async, GetHello2, sharef1);
	//string okstirng = newfutre2.get();
	//pro.set_value("Hello1");
	////re = newfutre.get();//奔溃
	//cout << "Hello" << endl;

	//lambda
	//packaged_task<int(int, int)> task([](int a, int b) ->int
	//{
	//	return a + b;
	//});

	//普通函数
	//packaged_task<int(int, int)> task(helloccc);

	//bind
//	packaged_task<int(int, int)> task(bind(helloccc,1,2));
//
////	this_thread::sleep_for(chrono::seconds(1));
//
//	task(1, 4);//这个1 4 是失效的 
//
//	this_thread::sleep_for(chrono::seconds(1));
//	bool bvalid = task.valid();
//	auto f = task.get_future();
//	cout << f.get() << endl;
//
//	this_thread::sleep_for(chrono::seconds(100));

	//thread t(Hello);
	//this_thread::sleep_for(chrono::seconds(4));//Sleep()
	//chrono::steady_clock::time_point timepos = chrono::steady_clock::now() + chrono::milliseconds(2000);
	////chrono::steady_clock::now();
	//this_thread::sleep_until(timepos);
	//t.join();

	/*mutex mutex_m;
	unique_lock<mutex> l(mutex_m);
	l.try_lock_for(chrono::seconds(4));
	chrono::steady_clock::time_point timepos = chrono::steady_clock::now() + chrono::milliseconds(2000);
	l.try_lock_until(timepos);

	promise<int> pro;
	auto f= pro.get_future();
	f.wait_for(chrono::seconds(4));
	chrono::steady_clock::time_point timepos = chrono::steady_clock::now() + chrono::milliseconds(2000);
	f.wait_until(timepos);

	condition_variable cv;
	cv.wait_for(l,chrono::seconds(4));
	chrono::steady_clock::time_point timepos = chrono::steady_clock::now() + chrono::milliseconds(2000);
	cv.wait_until(l, timepos);*/
	
	//WINBASEAPI
	//_Ret_maybenull_
	//HANDLE
	//WINAPI
	//CreateThread(
	//	_In_opt_ LPSECURITY_ATTRIBUTES lpThreadAttributes,//和线程安全有关 一般为null
	//	_In_ SIZE_T dwStackSize,//线程栈的大小
	//	_In_ LPTHREAD_START_ROUTINE lpStartAddress,//它是被线程执行的回调函数
	//	_In_opt_ __drv_aliasesMem LPVOID lpParameter,//传入线程的参数
	//	_In_ DWORD dwCreationFlags,//控制线程的标准 0 CREATE_SUSPENDED(0x00000004)
	//	_Out_opt_ LPDWORD lpThreadId //id
	//);
	//
	//thread t(Hello);
	//t.native_handle();

	HANDLE h = CreateThread(nullptr, 0, FunThread, nullptr, 0, nullptr);
	
	//WINBASEAPI
	//	_Ret_maybenull_
	//	HANDLE
	//	WINAPI
	//	CreateMutexW(
	//		_In_opt_ LPSECURITY_ATTRIBUTES lpMutexAttributes,//和线程安全有关 一般为null
	//		_In_ BOOL bInitialOwner,//有没有该锁的控制权
	//		_In_opt_ LPCWSTR lpName//锁名字
	//	);

//	hMutex = CreateMutex(nullptr, FALSE, L"HelloMutex");
	//std::mutex l;
	//l.lock();
	//l.unlock();
	//for (int i = 0; i < 10 ; i ++)
	//{
	//	WaitForSingleObject(hMutex,INFINITE);
	//	Sleep(1000);

	//	ReleaseMutex(hMutex);
	//}

	SuspendThread(h);
	Sleep(2000);
	ResumeThread(h);
	Sleep(2000);
	CloseHandle(h);

	char ThreadName[512] = "RenzhaiThread_xxx";
	FMyRunnable(EThreadPriority::TPri_Normal,0, ThreadName);
	{
		FEvent();
		//具体逻辑

	}

	auto CCCCCC = [](FTaskRunnable *R)
	{
		cout << "Hello TaskRunnable" << endl;
	};

	auto CCCCCC1 = [](FTaskRunnable* R)
	{
		cout << "Hello TaskRunnable1" << endl;
	};

	auto CCCCCC2 = [](FTaskRunnable* R)
	{
		cout << "Hello TaskRunnable2" << endl;
	};

	auto CCCCCC3 = [](FTaskRunnable* R)
	{
		cout << "Hello TaskRunnable3" << endl;
	};

	auto CCCCCC4 = [](FTaskRunnable* R)
	{
		cout << "Hello TaskRunnable4" << endl;
	};

	ThreadManage.Bind(CCCCCC);
	ThreadManage.Bind(CCCCCC1);
	ThreadManage.Bind(CCCCCC2);
	ThreadManage.Bind(CCCCCC3);
	ThreadManage.Bind(CCCCCC4);
	//ThreadManage.Bind(CCCCCC);
	//ThreadManage.Bind(CCCCCC);
	//ThreadManage.Bind(CCCCCC);
	//ThreadManage.Bind(CCCCCC);
	//ThreadManage.Bind(CCCCCC);

	//1.任务完成了怎么办？
	//2.安全
	//3.请结合我们自己写代理 融合在我们的线程队列（池）里面
	Sleep(1111112000);
	//std::thread d;
	return 0;
}

// 可能输出
// Suspend printHello thread
// main thread sleep 1 s
// main thread sleep 2 s
// main thread sleep 3 s
// 0 :Hello world
// ...
