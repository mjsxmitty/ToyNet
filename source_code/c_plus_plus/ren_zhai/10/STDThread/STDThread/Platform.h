#pragma once
#include "RunnableThread.h"

class Platform
{
public:
	static FRunnableThread* Create(
		FRunnable *InRunnable,
		const EThreadPriority InPriority,
		unsigned int InStack = 0,
		const char *InThreadName = nullptr);
};

