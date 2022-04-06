#include <iostream>
#include "TTT.h"
#include "c1.hpp"

#include "Header.h"
#include "Net.h"
#include "TemplateElement.h"
#include <type_traits>

/*
class vector
{
public:
	void Add();
	void Remove();
private:
	int *data;
};

class vector1
{
public:
	void Add();
	void Remove();
private:
	float* data;
};
class vector2
{
public:
	void Add();
	void Remove();
private:
	double* data;
}*/;

void Print()
{
	cout << "Hello" << endl;
}

template<class T/*,typename T1*/>
class vector
{
public:
	T *operator[](int Index) const
	{
		return &Data[Index];
	}

	int Num() const { return 0; }

	template<class T2>
	void Fun()
	{
		T2 a;
	}

	void Call_Array_arg1(const vector<T>& InArray, ...)
	{

	}
private:
	T* Data;
	//T1* data1;
};

class FHello{};

template<typename T>
void Call_Array(const vector<T>& InArray)
{
	for (int i = 0; i< InArray.Num();i++)
	{
		 T *Ptr = InArray[i];


		//逻辑....
	}
}

template<typename T>
void Call_Array_arg(const vector<T>& InArray,...)
{
	for (int i = 0; i < InArray.Num(); i++)
	{
		T* Ptr = InArray[i];


		//逻辑....
	}
}

//void Call_Array(const vector<float>& InArray)
//{
//
//}
//
//void Call_Array(const vector<int>& InArray)
//{
//
//}
//
//void Call_Array(const vector<double>& InArray)
//{
//
//}

HELLO_CLASS(WWWWW, { cout << "WWWWW" << endl; },"%s HHHHHHHH","HelloCCCC")

class FHelloCcccc
{
public:

	void Hello()
	{
		cout << "Hello" <<endl;
	}
};

class FHelloCcccc1
{
public:

	void Hello()
	{
		cout << "Hello" << endl;
	}
};

//////////////////////////////////////////////////////////////////////////
struct FTestA
{

};

struct FTestB
{
	FTestB(int a, int b)
	{

	}

	int print(int a, int b)
	{
		printf("%i %i", a,b);

		return a + b;
	}
};

class AAA
{
public:
	struct CCCC
	{
		int a;
	};
};

class FInterface
{
public:
	virtual void Init() = 0;
};

enum ETestEnum
{
	AAAAAA,
	BBBBBB,
};

template<class T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type Func(T f)
{
	return f;
}

template<class T>
typename std::enable_if<!std::is_arithmetic<T>::value, T>::type Func(T &f)
{
	cout << "Hello" << endl;
	return f;
}

D_THREAD(GThread, FHelloCcccc)
D_THREAD(GThread1, FHelloCcccc1)
int main()
{
	//int aaaa1 = 10;
	//float dddd = 11.5f;
	//char cccc[] = "Hello";
	//Func(aaaa1, dddd, cccc);
	//FuncLen(aaaa1, dddd, cccc);

	//FuncFindParam(aaaa1, dddd, cccc, aaaa1, dddd, cccc);
	//FuncFindParam();

	//int a1 = 1;
	//int a2 = 3;
	//int a3 = 4;
	//int a4 = 12;
	//int i = FunValue(a1, a2, a3, a4);
	//cout << i << endl;

	////FHello_Class<int, float> aaaaa;
	////FHello_Class1 aaaaa12;

	FLen<int,float,double,int,long> Len;
	cout << Len.Number << endl;

	ddddd(vv, int, float, double, int, long);
	cout << vv.Number << endl;

	using Helloc = SpawnIndex<10>::Type;
	cout << typeid(Helloc).name() << endl;

	using Helloc1 = SpawnIndex1<10>::Type;
	cout << typeid(Helloc1).name() << endl;

	//SpawnIndex1<10>::Type *HellocObject = CreateObject<SpawnIndex1<10>::Type>();
	//if (HellocObject)
	//{

	//}
	//SpawnIndex<3>::Type;
	//struct SpawnIndex :SpawnIndex<2, 2>
	//struct SpawnIndex<2,2> :SpawnIndex<1, 1,2>
	//struct SpawnIndex<1,1,2> :SpawnIndex<0,0,1,2>
	//{
		//typedef HelloIndex<0,1,2> Type;
	//}
	FTestA* p = CreateObject<FTestA>();
	FTestB* p1 = CreateObject<FTestB>(1, 2);

	auto NewFunction = CreateDelegate(p1, &FTestB::print);

	int a = NewFunction(1, 2);

	//return 0;
//	//vector1 v;
//
//	vector<int> array_i;
//	vector<float> array_f;
//	vector<double> array_d;
//	vector<FHello> array_data;
//	vector<FHello*> array_data1;
//
//	Call_Array(array_i);
//	Call_Array(array_f);
//	Call_Array(array_d);
//	Call_Array(array_data);
//	Call_Array(array_data1);
//
//	array_i.Fun<int>();
//	FHelloHello<FTest> Array_CC;
//	float *p = Array_CC.HelloC_C<float>();
//
//	//boost
//	FHelloHello1<FTest> Array_CC1;
//	p = Array_CC.HelloC_C<float>();
//
//
//	FTest1 Test1;
//	Test1.HelloCCCC();
//
//	FTest4 Test4;
//	Test4.HelloCCCC();
//
//	FChello aaaa;
//	FTHello<int>* pt = &aaaa;
//	pt->Init();
//
//	pt->Hello();
//	pt->Hello(1, 2);
//
//	pt->Hello1(1, 2, 3, 4, 5, 6, 7, 5.f, 1.f);
//
//	FWWWWW<int> W;
//	W.Work();
//
//	int a = 10;
//	float c = 10.f;
//	char ww = 'd';
//
//	FHelloCcccc* ccc = GThread::Get();
//	ccc->Hello();
//
//	FHelloCcccc1* ccc1 = GThread1::Get();
//	ccc1->Hello();
//
//	GThread1::Destroy();
//	GThread::Destroy();
//
////	printf("%d,%s", a, c, ww);
//	Call_Array_arg(array_i, a, c, ww);
//
//	//客户端
//	int axx;
//	float aa;
//	char cc1;
//	NetControlMessage<NMT_Login>::Send(axx,aa,cc1);
//	//NetControlMessage<NMT_Welcome>::Send(a, aa, cc1);
////////////////////////////////////////////////////////////////////////////
//	//服务器
//	int a1;
//	float aa1;
//	char cc11;
//	NetControlMessage<NMT_Login>::Receive(a1, aa1, cc11);

	int v = Fconstffff<int, 1>::value;

	//
	RemoveConst<const int>::Type a1;
	a1 = 100;

	//比较类型是否一样
	bool tttt = isSame<int, float>::value;

	//错误的
//	v = Fconstffff1<1, 2>::value;//
	cout << endl;
	cout << std::is_same<int, float>::value << endl;

	auto Testl = []()
	{
		cout <<"Hello" <<endl;
	};

	//类
	cout << std::is_class<FTestB>::value << endl;
	cout << std::is_class<AAA>::value << endl;
	cout << std::is_class<int>::value << endl;
	cout << std::is_class<float>::value << endl;
	cout << std::is_class<ETestEnum>::value << endl;

	//枚举
	cout << std::is_enum<ETestEnum>::value << endl;
	cout << std::is_enum<FTestB>::value << endl;
	cout << std::is_enum<AAA>::value << endl;
	cout << std::is_enum<int>::value << endl;
	cout << std::is_enum<float>::value << endl;

	cout << std::is_integral<ETestEnum>::value << endl;
	cout << std::is_integral<FTestB>::value << endl;
	cout << std::is_integral<AAA>::value << endl;
	cout << std::is_integral<int>::value << endl;
	cout << std::is_integral<float>::value << endl;

	cout << std::is_floating_point<ETestEnum>::value << endl;
	cout << std::is_floating_point<FTestB>::value << endl;
	cout << std::is_floating_point<AAA>::value << endl;
	cout << std::is_floating_point<int>::value << endl;
	cout << std::is_floating_point<float>::value << endl;

	cout << std::is_floating_point<ETestEnum*>::value << endl;
	cout << std::is_floating_point<FTestB*>::value << endl;
	cout << std::is_floating_point<AAA*>::value << endl;
	cout << std::is_floating_point<int*>::value << endl;
	cout << std::is_floating_point<float*>::value << endl;

	cout << std::is_pointer<ETestEnum*>::value << endl;
	cout << std::is_pointer<FTestB*>::value << endl;
	cout << std::is_pointer<AAA*>::value << endl;
	cout << std::is_pointer<int*>::value << endl;
	cout << std::is_pointer<float*>::value << endl;

	cout << std::is_pointer<ETestEnum>::value << endl;
	cout << std::is_pointer<FTestB>::value << endl;
	cout << std::is_pointer<AAA>::value << endl;
	cout << std::is_pointer<int>::value << endl;
	cout << std::is_pointer<float>::value << endl;

	//左值&  右值&&
	cout << std::is_lvalue_reference<ETestEnum&>::value << endl;
	cout << std::is_lvalue_reference<FTestB&>::value << endl;
	cout << std::is_lvalue_reference<AAA&>::value << endl;
	cout << std::is_lvalue_reference<int&>::value << endl;
	cout << std::is_lvalue_reference<float&>::value << endl;

	cout << std::is_lvalue_reference<ETestEnum>::value << endl;
	cout << std::is_lvalue_reference<FTestB>::value << endl;
	cout << std::is_lvalue_reference<AAA>::value << endl;
	cout << std::is_lvalue_reference<int>::value << endl;
	cout << std::is_lvalue_reference<float>::value << endl;

	cout << std::is_rvalue_reference<ETestEnum&>::value << endl;
	cout << std::is_rvalue_reference<FTestB&>::value << endl;
	cout << std::is_rvalue_reference<AAA&>::value << endl;
	cout << std::is_rvalue_reference<int&>::value << endl;
	cout << std::is_rvalue_reference<float&>::value << endl;

	cout << std::is_rvalue_reference<ETestEnum&&>::value << endl;
	cout << std::is_rvalue_reference<FTestB&&>::value << endl;
	cout << std::is_rvalue_reference<AAA&&>::value << endl;
	cout << std::is_rvalue_reference<int&&>::value << endl;
	cout << std::is_rvalue_reference<float&&>::value << endl;
	
	cout << std::is_function<ETestEnum>::value << endl;
	cout << std::is_function<FTestB>::value << endl;
	cout << std::is_function<AAA>::value << endl;
	cout << std::is_function<int>::value << endl;
	cout << std::is_function<float>::value << endl;
	cout << std::is_function<void(int ,int )>::value << endl;
	cout << std::is_function<void(...)>::value << endl;

	cout << std::is_member_function_pointer<ETestEnum>::value << endl;
	cout << std::is_member_function_pointer<FTestB>::value << endl;
	cout << std::is_member_function_pointer<AAA>::value << endl;
	cout << std::is_member_function_pointer<int>::value << endl;
	cout << std::is_member_function_pointer<float>::value << endl;
	cout << std::is_member_function_pointer<void(int, int)>::value << endl;
	cout << std::is_member_function_pointer<void(...)>::value << endl;
	cout << std::is_member_function_pointer<int(AAA::CCCC::*)>::value << endl;
	cout << std::is_member_function_pointer<int(AAA::CCCC::*)()>::value << endl;
	
	cout << std::is_member_object_pointer<ETestEnum>::value << endl;
	cout << std::is_member_object_pointer<FTestB>::value << endl;
	cout << std::is_member_object_pointer<AAA>::value << endl;
	cout << std::is_member_object_pointer<int>::value << endl;
	cout << std::is_member_object_pointer<float>::value << endl;
	cout << std::is_member_object_pointer<void(int, int)>::value << endl;
	cout << std::is_member_object_pointer<void(...)>::value << endl;
	cout << std::is_member_object_pointer<float(AAA::CCCC::*)>::value << endl;
	cout << std::is_member_object_pointer<double(AAA::CCCC::*)()>::value << endl;

	cout << std::is_array<ETestEnum>::value << endl;
	cout << std::is_array<FTestB>::value << endl;
	cout << std::is_array<AAA>::value << endl;
	cout << std::is_array<int>::value << endl;
	cout << std::is_array<float>::value << endl;
	cout << std::is_array<void(int, int)>::value << endl;
	cout << std::is_array<void(...)>::value << endl;
	cout << std::is_array<float(AAA::CCCC::*)>::value << endl;
	cout << std::is_array<double(AAA::CCCC::*)()>::value << endl;
	cout << std::is_array<vector<int>>::value << endl;
	cout << std::is_array<int[]>::value << endl;

	cout << std::is_arithmetic<ETestEnum>::value << endl;
	cout << std::is_arithmetic<FTestB>::value << endl;
	cout << std::is_arithmetic<AAA>::value << endl;
	cout << std::is_arithmetic<int>::value << endl;
	cout << std::is_arithmetic<float>::value << endl;
	cout << std::is_arithmetic<void(int, int)>::value << endl;
	cout << std::is_arithmetic<void(...)>::value << endl;
	cout << std::is_arithmetic<float(AAA::CCCC::*)>::value << endl;
	cout << std::is_arithmetic<double(AAA::CCCC::*)()>::value << endl;
	cout << std::is_arithmetic<vector<int>>::value << endl;
	cout << std::is_arithmetic<int[]>::value << endl;

	cout << std::is_abstract<ETestEnum>::value << endl;
	cout << std::is_abstract<FTestB>::value << endl;
	cout << std::is_abstract<AAA>::value << endl;
	cout << std::is_abstract<int>::value << endl;
	cout << std::is_abstract<float>::value << endl;
	cout << std::is_abstract<void(int, int)>::value << endl;
	cout << std::is_abstract<void(...)>::value << endl;
	cout << std::is_abstract<float(AAA::CCCC::*)>::value << endl;
	cout << std::is_abstract<double(AAA::CCCC::*)()>::value << endl;
	cout << std::is_abstract<vector<int>>::value << endl; 
	cout << std::is_abstract<int[]>::value << endl;
	cout << std::is_abstract<FInterface>::value << endl;

	cout << std::is_same<int&,std::add_lvalue_reference<int>::type>::value << endl;
	cout << std::is_same<int&&, std::add_rvalue_reference<int>::type>::value << endl;
	cout << std::is_same<int, std::remove_const<const int>::type>::value << endl;
	cout << std::is_same<const int, std::add_const<int>::type>::value << endl;

	std::conditional<true,int, double>::type Hel = 100;
	std::conditional<false,int, double>::type Hel1 = 100;

	std::conditional<(sizeof(int) > sizeof(long double)), int, float>::type AA = 100;	
	cout << typeid(AA).name() << endl;

	//std::decay<int&>::type A1;//int
	//std::decay<int&&>::type A2;//int
	//std::decay<const int>::type A3;//int
	//std::decay<int[100]>::type A4;//int*
	//std::decay<int(int)>::type A5;//int(*)(int)
	AAA AAA444;
	auto aaaa = Func(1);
	auto aaaa1 = Func(1.1f);
	auto aaaa4 = Func(AAA444);

	//左值和右值
	//=
	//int a11 = 0; 
	//int b22 = 2;
	//a = b33 + 1;
	//表达式是不能左值
	//(a + b) = b + 1;
	//(a ++) = b + 1;
	//(a = 100) += b;
	//常量不能做左值
	//100 = a + b;

	//左值引用和右值引用
	//int& a;
	//int&& a;

//	int aaa1 = 100;
//	int& ccc = aaa1;
////	int& ccc = aaa1 * 100;
//	int&& ccc = aaa1 * 100;
//	int&& ccc = aaa1;

	//左值引用 持久
	//
	typedef std::integral_constant<int, 100>::type hello;
	hello ooo1;
	int i = ooo1;
	int i1 = static_cast<int>(ooo1);
	int i2 = ooo1.operator hello::value_type();

	//求最大整数
	cout << IntMax<1, 212, 300, 4, 54, 6, 7, 8, 100, 9>::value << endl;

	struct FAAAAA
	{
		int a;
		int b;
		double a1;
		float a2;
		long double bc;

	};

	int avvvv = alignof(FAAAAA);
	cout << MaxAlign<char, int, float, long, long long>::value << endl;
	return 0;
}