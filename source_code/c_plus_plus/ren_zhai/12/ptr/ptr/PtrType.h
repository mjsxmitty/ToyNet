#pragma once

//引用计数
class FRefCounter
{
public:
	FRefCounter()
		:SharedCount(0)
		,WeakCount(0)
	{

	}

	int SharedCount;
	int WeakCount;
};