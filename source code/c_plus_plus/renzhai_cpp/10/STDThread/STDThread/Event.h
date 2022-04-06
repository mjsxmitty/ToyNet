#pragma once
#include <Windows.h>

struct FEvent
{
	FEvent();
	~FEvent();

private:
	HANDLE M;
};

