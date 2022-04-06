#pragma once
#include <iostream>

class FTest;

using namespace std;

template<class T>
class FHelloHello
{
	friend class FTest8;
public:
	void HelloC(){}

	void HelloCCCC();

	void TestHello();

	template<class T1>
	T1* HelloC_C()
	{
		T Data;
		bool bWork = Data.Work();

		return nullptr;
	}
	//FORCEINLINE
	inline int GetHELLO() const { return 0; }
private:
	T* Data;
};

template<class T>
void FHelloHello<T>::TestHello()
{
	cout << "void FHelloHello<T>::TestHello()" << endl;
}

//作弊的功能
class FTest8
{
public:

	FHelloHello<FTest> TTT;
};

template<class T>
void FHelloHello<T>::HelloCCCC()
{

}

//UE4多线程 会大量
class FTest
{
public:
	bool Work();
};


class FTest1 :public FHelloHello<FTest>
{
public:

	void HelloCC(){}
};

template<class T>
class FTest2 :public FHelloHello<T>
{
public:

	void HelloCC() {}
};

template<class T, class T1, class T2, class T3>
class FTest3 :public FHelloHello<T>
{
public:

	void HelloCC() {}

private:
	T1 a;
	T2 b;
	T3 c;
};

class FTest4 :virtual public FHelloHello<FTest>
{
	typedef FHelloHello<FTest> Super;
public:
	FTest4()
		:Super()
	{}
};


class FTest6 :virtual public FHelloHello<FTest>
{
	typedef FHelloHello<FTest> Super;
public:
	FTest6()
		:Super()
	{}
};

class FAA :public FTest4,public FTest6
{
public:
};

template<class T>
class FTHello
{

public:

	virtual void Init()
	{
		cout << "FTHello::Init" << endl;
	}
	virtual void Destroy()
	{
		cout << "FTHello::Destroy" << endl;
	}

	void Hello()
	{
		cout << "Hello" << endl;
	}

	void Hello(int a)
	{
		cout << "Hello" << endl;
	}

	void Hello(int a,int b)
	{
		cout << "Hello" << endl;
	}

	void Hello1(...)
	{

		cout << "..." << endl;
	}
private:
	T* A;
};

class FChello :public FTHello<int>
{
	typedef FTHello<int> Super;
public:
	virtual void Init()
	{
		cout << "FChello::Init" << endl;
		Super::Init();
	}
	virtual void Destroy()
	{
		cout << "FChello::Destroy" << endl;
		Super::Destroy();
	}
};

#define HELLO_CLASS(ClassName,Code,Fcc,...) \
template<class T> \
class F##ClassName \
{ \
public: \
	void Work() \
	{ \
		printf(Fcc,__VA_ARGS__);\
		Code; \
	} \
private: \
	T* A; \
};