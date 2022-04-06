#include <iostream>
#include <functional>

using namespace std;

int TT(int a, int b)
{
	cout << "TT" << endl;
	return a + b;
}
int TT111(int a)
{
	cout << "TT" << endl;
	return a;
}
auto la = [&](int a, int b)
{
	cout << "TT" << endl;
	return 123;
};

class FHello
{
public:
	int TT(int a, int b)
	{
		cout << "TT" << endl;
		return 123;
	}

	static int TT1(int a, int b)
	{
		cout << "TT" << endl;
		return 123;
	}
};

class FFUnction111
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

template< class T>
T FuncT(T a, T b)
{
	return a + b;
}

void CallBack(function<int(int, int)> func)
{
	//.....

	int ret = func(1,2);


	//....
}

int(*Func)(int, int);




//仿函数做代理
//TFunction
//TFunctionRef
#include "Delegate.h"

DEFINITION_SIMPLE_SINGLE_DELEGATE(HelloDDD, void, int)
DEFINITION_MULTICAST_SINGLE_DELEGATE(WWWWWM, int, int)
int main()
{
	//函数指针 lambda, 普通函数 对象函数 代理bind连用
	//对象函数
	//Func = TT;
	//FHello Hello;
	////boost::function

	//bind连用
	//function<int(int, int)> Hello_f = bind(&FHello::TT,&Hello, placeholders::_1, placeholders::_2);

	//int ret = Hello_f(1,2);

	//boost::function
	//对象
	//function<int(int, int)> Hello_f = FFUnction111();

	//int ret = Hello_f(1, 2);

	//和静态
	//function<int(int, int)> Hello_f = FHello::TT1;

	//int ret = Hello_f(1, 2);

	//模板连用
	//function<int(int, int)> Hello_f = FuncT<int>;

	//int ret = Hello_f(1, 2);

	CallBack([&](int a,int b) ->int
	{
		return a + b;
	});

	//延迟
	auto Funcd = bind(TT,1,2);

	//占位
	auto Funcd1 = bind(TT,placeholders::_1, placeholders::_2);

	auto Funcd2 = bind(FHello::TT1, 1, 2);

	auto Funcd3 = bind(FuncT<int>, 1, 2);

	int ret = Funcd(4,5);

	//FDelegateBase<int> Base;
	//Base.Bind(TT);
	
	struct FTest
	{
		int Init(int a, int b)
		{
			cout << "Init" << endl;
			return 0;
		}
		int TT111(int a)
		{
			cout << "TT" << endl;
			return a;
		}
		static int FFF(int a)
		{
			cout <<a <<endl;
			return a;
		}
	};
	FTest Test;
	FObjectDelegate<FTest, int, int, int> ObjectDelegate(&Test,&FTest::Init);
	ObjectDelegate.Execute(1,2);

	FFunctionDelegate< int, int, int> FunctionDelegate(TT);
	FunctionDelegate.Execute(1, 2);

	FDelegate<int, int, int> DelegateInstance;//单播代理
	DelegateInstance.Bind(TT);
	DelegateInstance.Execute(1, 2);

	DelegateInstance.Bind(&Test, &FTest::Init);
	DelegateInstance.Execute(1, 2);

	//创建代理
	auto Ddd = FDelegate<int, int, int>::Create(&Test, &FTest::Init);
	Ddd.Execute(1, 2);

	auto Ddd1 = FDelegate<int, int, int>::Create(TT);
	Ddd1.Execute(1, 2);

	auto Ddd2 = FDelegate<int, int, int>::Create([](int a, int b)->int 
	{
		cout <<"Hello" <<endl;
		return true;
	});
	Ddd2.Execute(1, 2);
	Ddd2.ReleaseDelegate();

	SIMPLE_SINGLE_DELEGATE(Simple, void, int);
	Simple.Bind([](int a)
	{
		cout <<"SIMPLE_SINGLE_DELEGATE"<<endl;
	});
	Simple.Execute(1);

	Simple.ReleaseDelegate();

	HelloDDD ddd;
	ddd.Bind([](int a)
	{
		cout << "SIMPLE_SINGLE_DELEGATE" << endl;
	});
	ddd.Execute(1);

	ddd.ReleaseDelegate();


	//多播
	FMulticastDelegate<int, int> MulticastDelegate;

	//
	MulticastDelegate.AddFunction([](int a)->int
	{
		cout << "SIMPLE_SINGLE_DELEGATE" << endl;
		return 0;
	});
	//
	MulticastDelegate.AddFunction(TT111); 

	MulticastDelegate.AddFunction(FTest::FFF);

	FTest Ttt;
	MulticastDelegate.AddFunction(&Ttt,&FTest::TT111);

	MulticastDelegate.Broadcast(100);
	MulticastDelegate.ReleaseDelegates();


	WWWWWM wwwl;
	wwwl.AddFunction([](int a)->int
	{
		cout << "SIMPLE_SINGLE_DELEGATE" << endl;
		return 0;
	});
	//
	wwwl.AddFunction(TT111);

	wwwl.AddFunction(FTest::FFF);

	wwwl.AddFunction(&Ttt, &FTest::TT111);

	wwwl.Broadcast(100);
	wwwl.ReleaseDelegates();
	return 0;
}