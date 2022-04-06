//#include "stdio.h"
//#include "stdlib.h"
#include <iostream> 
//#include "stdbool.h"//c语言需要包含布尔

using namespace std;

struct FHello
{
	int a;
	int b;
	long int c;

};

void Fun(FHello &cc)//C++ 支持传引用  c语言不支持传引用
{
	cc.a = 0;
}

//4
void FunPtr(FHello* cc)//C++ 支持传引用  
{
	cc->a = 0;
}

FHello* CreateObject()
{
	return NULL;
}

struct FFF
{
	int q;
	int w;
};

struct FTest :public FFF
{
	void Hello(int a,int b){}



};

int main()
{
	FTest Test;

	//1.打印方式不同
	//printf("Hello World \n");//C的
	cout << "Hello World" << "www" << endl;//C++的打印

	//2.bool变量不同
	bool bOk = false;

	//3.c 形参 引用
	//引用的特性
	//引用必须初始化
	//唯一性

	//
	//底层实现的方式是一样 指针方式实现

	FHello o;
	FHello o333;
	FHello& o1 = o;
	FHello& o2 = o;//奔溃
//	sizeof(o1)
	//o2 = o333;

	FHello *optr = &o;
	optr = &o333;

	char** y = new char*[100];

	//
	if (CreateObject())
	{

	}
	Fun(o);
	system("pause");
	return 0;
}