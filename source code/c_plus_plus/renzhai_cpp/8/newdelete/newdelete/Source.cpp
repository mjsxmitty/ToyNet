#include <iostream>

using namespace std;

struct FObject
{
public:
	FObject()
	{
		cout << "FObject" << endl;
	}

	virtual ~FObject()
	{
		cout << "~FObject" << endl;
	}
private:
	int a;
	int b;
};

struct FObjectss :public FObject
{
public:
	FObjectss()
	{
		cc = new char;
	}

	~FObjectss()
	{
		cout << "	~FObjectss()" << endl;
		delete cc;
	}
	char* cc;
};

template<class T>
class FPreDistribution
{
public:
	FPreDistribution(int InCount)
		:Numer(InCount)
	{
		Data = new T[InCount];
	}

	~FPreDistribution()
	{
		delete[] Data;
	}

	T* operator[](int Index)
	{
		return &Data[Index];
	}

	inline int Num() { return Numer; }
private:
	T* Data;
	int Numer;
};

int main()
{
	//int* p = new int; //堆 （这个需要程序员手动释放）

	//int p_int = 10;//栈

	//int* hello = &p_int;

	////*p = p_int;

	//p = hello;

	//cout << *p << endl;

	//delete p;//释放了栈的内存 所以产生奔溃

	//int *p_m = (int*)malloc(sizeof(int));//分配一片内存
	//int *p_n = new int;

	//delete p_m;
	//free(p_n);


//	FObject* p_m = (FObject*)malloc(sizeof(FObject));//分配一片内存
////	p_m->FObject();//不能调用
//
//	FObject* p_n = new FObject();
//
//	delete p_m;
//
//	p_n->~FObject(); //你可以调用默认的析构
//	free(p_n);

	//new delete 默认实现构造和析构 告诉对象它的生命周期
	//malloc free 简单粗暴的分配内存
	//FObject* p_n = new FObjectss();

//	//delete p_n;
////	char* pc = new char[1024];
//	FObject* p = new FObjectss[1024]; //一维数组
//	delete[] p;
////	delete p;
//
//	//二维数组
//	int** Hello = new int* [1024];
//	for (int i = 0 ; i <1024;i++)
//	{
//		Hello[i] = new int[10];
//	}
//
//	for (int i = 0; i < 1024; i++)
//	{
//		delete[] Hello[i];
//	}
//	delete[] Hello;
//
//	//对象的二维数组
//	FObjectss** Hello1 = new FObjectss * [1024];
//	for (int i = 0; i < 1024; i++)
//	{
//		Hello1[i] = new FObjectss[10];
//	}
//
//	for (int i = 0; i < 1024; i++)
//	{
//		delete[] Hello1[i];
//	}
//	delete[] Hello1;
//	
//
//	//三维数组的创建和释放
//	int*** SSS = new int** [1024];
//	for (int i = 0;i< 1024;i++)
//	{
//		SSS[i] = new int* [10];
//		for (int j = 0;j < 10;j++)
//		{
//			SSS[i][j] = new int[10];
//		}
//	}
//
//	for (int i = 0; i < 1024; i++)
//	{
//		SSS[i] = new int* [10];
//		for (int j = 0; j < 10; j++)
//		{
//			delete[] SSS[i][j];
//		}
//		delete[] SSS[i];
//	}
//	delete[] SSS;


	FObject *p_m = new FObject();
	//动态内存 ->内存碎片

	//预分配内存
	FObject* p_mv = new FObject[1024];

	//iocp
	FPreDistribution<FObject> PreDistribution(1024);
	FObject *Hellop = PreDistribution[56];

	return 0;
}