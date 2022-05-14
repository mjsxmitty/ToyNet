#pragma once

enum EThreadPriority;
class FRunnableThread;
class FRunnable
{
public:

	virtual bool Init() { return false; };

	virtual int Run() = 0;

	virtual int Stop() { return 0; };

	virtual void Start() {};

	virtual bool Exit() { return false; }

	virtual FRunnableThread* GetThread() = 0;
};

//线程队列
class FTaskRunnable :public FRunnable
{
public:
	enum EThreadState
	{
		FREE,
		WORK,
	};

	FTaskRunnable();

	void Create(const EThreadPriority InPriority, unsigned int InStack, const char* InThreadName);

	virtual bool Init();

	virtual int Run();

	virtual int Stop();

	virtual void Start();

	virtual bool Exit();

	void Bind(void (*InFun)(FTaskRunnable*));
	virtual FRunnableThread* GetThread();
	void SetState(EThreadState InState);
	inline EThreadState GetState() const { return State; }
protected:
	bool bStop;
	FRunnableThread* Thread;
	EThreadState State;

	void (*fun)(FTaskRunnable *);
};

#include <list>
//#include <functional>
class FThreadManage
{
public:
	FThreadManage();

	void Bind(void (*fun)(FTaskRunnable*));

private:
	std::list<FTaskRunnable> List;
//	std::list<std::function(void(FTaskRunnable*))> TaskList;
};

extern FThreadManage ThreadManage;