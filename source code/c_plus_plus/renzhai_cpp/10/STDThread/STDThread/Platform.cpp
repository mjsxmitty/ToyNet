#include "Platform.h"
#include "RunnableThread.h"
#include "Runnable.h"
#include <windows.h>
#include "RunnableThread.h"
#include <iostream>

#if __linux
#include <pthread.h>
#endif

class FWin32RunnableThread :public FRunnableThread
{
public:
	~FWin32RunnableThread()
	{
		CloseHandle(h);
	}

	virtual bool Create(FRunnable* InRunnable);

	virtual void Suspend() 
	{
		SuspendThread(h);
	};

	virtual void Resume() 
	{
		ResumeThread(h);
	};

protected:
	HANDLE h;
};


class FLinuxRunnableThread :public FRunnableThread
{
public:
	virtual bool Create(FRunnable* InRunnable) {}
};

DWORD WINAPI RunThread1(LPVOID lpPram)
{
	FRunnable* Runnable = (FRunnable*)lpPram;

	FRunnableThread* MyThread = Runnable->GetThread();
	MyThread->SetThreadID(GetCurrentThreadId());
#if _WIN32		
	struct FTagThreadNameInfo
	{
		DWORD dwType; //0x1000 4096
		LPCSTR szName;
		DWORD dwThreadID;
		DWORD dwFlags;
	};

	FTagThreadNameInfo Info;
	Info.dwType = 0x1000;
	Info.szName = MyThread->GetThreadName();
	Info.dwThreadID = MyThread->GetThreadID();
	Info.dwFlags = 0;
	__try
	{
		RaiseException(0x406D1388, 0, sizeof(Info) / sizeof(DWORD), (DWORD*)(&Info));
	}
	__except (EXCEPTION_CONTINUE_EXECUTION)
	{
		std::cout << "EXCEPTION_CONTINUE_EXECUTION" << std::endl;
	}

#elif __linux
	//linux 修改名字
#endif
	DWORD ReturnValue = Runnable->Run();

	Runnable->Exit();

	return ReturnValue;
}

bool FWin32RunnableThread::Create(FRunnable* InRunnable)
{
	if (InRunnable)
	{
		h = CreateThread(nullptr, 0,RunThread1, InRunnable, 0, nullptr);
		return true;
	}
	return false;
}

FRunnableThread* Platform::Create(FRunnable* InRunnable, 
	const EThreadPriority InPriority /*= EThreadPriority::TPri_Normal*/,
	unsigned int InStack /*= 0*/,
	const char* InThreadName)
{
	FRunnableThread* InThread = nullptr;

	if (InRunnable)
	{
#if _WIN32	
		if (InRunnable->Init())
		{
			InThread = new FWin32RunnableThread();

			//初始化
			InThread->SetPriority(InPriority);
			InThread->SetThreadName(InThreadName);

			//执行
			InThread->Create(InRunnable);
		}

#elif __linux
		InThread = new FLinuxRunnableThread();


#endif
	}
	return InThread;
}

