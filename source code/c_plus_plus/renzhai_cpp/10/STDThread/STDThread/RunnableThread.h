#pragma once

enum EThreadPriority
{
	TPri_Normal,
	TPri_AboveNormal,
	TPri_BelowNormal,
	TPri_Highest,
	TPri_Lowest,
	TPri_SlightlyBelowNormal,
	TPri_TimeCritical,
	TPri_Num,
};

class FRunnable;
class FRunnableThread
{
public:
	FRunnableThread();
	virtual ~FRunnableThread(){}

	virtual bool Create(FRunnable* InRunnable) = 0;

	void SetPriority(EThreadPriority InPriority);
	void SetThreadName(const char * InThreadName);
	void SetThreadID(unsigned int InThreadID);

	const EThreadPriority GetPriority() const;
	const char* GetThreadName() const;
	const unsigned int GetThreadID() const;

	virtual void Suspend() {};
	virtual void Resume() {};
protected:
	EThreadPriority Priority;
	char ThreadName[512];
	unsigned int ThreadID;
};