#include "RunnableThread.h"
#include <corecrt_memory.h>

FRunnableThread::FRunnableThread()
	:Priority(EThreadPriority::TPri_Normal)
	,ThreadID(0u)
{
	memset(ThreadName, 0, 512);
}

void FRunnableThread::SetPriority(EThreadPriority InPriority)
{
	Priority = InPriority;
}

void FRunnableThread::SetThreadName(const char* InThreadName)
{
	memcpy(ThreadName, InThreadName, 512);
}

void FRunnableThread::SetThreadID(unsigned int InThreadID)
{
	ThreadID = InThreadID;
}

const EThreadPriority FRunnableThread::GetPriority() const
{
	return Priority;
}

const char* FRunnableThread::GetThreadName() const
{
	return ThreadName;
}

const unsigned int FRunnableThread::GetThreadID() const
{
	return ThreadID;
}

