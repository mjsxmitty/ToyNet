#include "Event.h"

FEvent::FEvent()
{
	M = CreateMutex(NULL, FALSE, NULL);

	WaitForSingleObject(M, INFINITE);
}

FEvent::~FEvent()
{
	ReleaseMutex(M);
}