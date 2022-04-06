#include "Header.h"
#include "stdio.h"

int __stdcall init_c(int a, int b)
{
	printf("%d %d",a,b);
	return 0;
}

int __stdcall get_c_name(int a, int b)
{
	 printf("%d %d", a, b);
	 return 0;
}

int get_c_name1(int a, int b)
{
	printf("%d %d", a, b);
	return 0;
}