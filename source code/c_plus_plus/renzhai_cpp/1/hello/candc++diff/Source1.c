#include "stdio.h"

void Hello(int a, int b)
{

}

struct FT
{ 
	void (*Hello1)(int, int);

	int a;
	int b;
} FTs;

void main1()
{
	FTs.Hello1 = Hello;

}