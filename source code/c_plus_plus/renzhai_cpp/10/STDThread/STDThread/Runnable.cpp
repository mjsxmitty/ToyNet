//#define _CRT_SECURE_NO_WARNINGS
#include "Runnable.h"
#include "Platform.h"
#include "RunnableThread.h"
#include <iostream>
#include <Windows.h>

void Hello_Test(FRunnable *)
{
	std::cout << "Test" << std::endl;
}

FTaskRunnable::FTaskRunnable()
	: bStop(false)
	, State(FREE)
	, fun(NULL)
{
	
}

void FTaskRunnable::Create(const EThreadPriority InPriority, unsigned int InStack, const char* InThreadName)
{
	Thread = Platform::Create(this, InPriority, InStack, InThreadName);
}

bool FTaskRunnable::Init()
{
	return true;
};

int FTaskRunnable::Run()
{
	if (Thread)
	{
		Thread->Suspend();
		while (!bStop)
		{
			if (fun)
			{
				fun(this);
			}

			Sleep(200);
		}
	}

	return 0;
}

int FTaskRunnable::Stop()
{
	bStop = true;

	return 0;
}

void FTaskRunnable::Start()
{
	bStop = false;
}

bool FTaskRunnable::Exit()
{
	delete Thread;
	return true;
}

FRunnableThread* FTaskRunnable::GetThread()
{
	return Thread;
}

FThreadManage::FThreadManage()
{
	//先预分配
	for (size_t i = 0; i < 12; i++)
	{
		List.emplace_back(FTaskRunnable());
	}

	const char MyThreadName[512] = "RenzhaiThread_";

	int i = 0;
	//执行线程
	for (auto &Tmp : List)
	{
		std::string Name = MyThreadName;

		char buff[512] = { 0 };
		_itoa(i, buff, 10);
		Name += buff;

		Tmp.Create(EThreadPriority::TPri_Normal,0, Name.c_str());

		i++;
	}
}

void FTaskRunnable::SetState(EThreadState InState)
{
	State = InState;
}

void FTaskRunnable::Bind(void (*InFun)(FTaskRunnable*))
{
	fun = InFun;
}

void FThreadManage::Bind(void (*fun)(FTaskRunnable*))
{
	for (auto& Tmp : List)
	{
		if (Tmp.GetState() == FTaskRunnable::EThreadState::FREE)
		{
			Tmp.SetState(FTaskRunnable::EThreadState::WORK);
			Tmp.Bind(fun);
			Tmp.GetThread()->Resume();

			break;
		}
	}
}

FThreadManage ThreadManage;