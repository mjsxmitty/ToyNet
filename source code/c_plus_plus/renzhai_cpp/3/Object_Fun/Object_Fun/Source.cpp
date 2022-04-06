#include <iostream>

using namespace std;

//
////
////void Func1(...)
////{
////	
////}
//
//class FA
//{
//public:
//	virtual void Func1()
//	{
//		printf("FA::Func1 \n");
//	}
//
//	//void Func1(int a)
//	//{
//
//	//}
//
//	//void Func1(int a, int b)
//	//{
//
//	//}
//
//	//void Func1(int a, int b, int c)
//	//{
//
//	//}
//};
//
////typedef struct FDD
////{
////	int(*fun)(int a, int b);
////
////
////};
//
//class FB : public  FA
//{
//public:
//	virtual void Func1()
//	{
//		printf("FB::Func1 \n");
//	}
//};
//
//class IInterface
//{
//public:
//
//	virtual void Init()		= 0;
//	virtual void Destroy()	= 0;
//};
//
//class FNewObject :public IInterface
//{
//public:
//	FNewObject(){}
//
//	virtual void Init() final;
//	virtual void Destroy() ;
//	void Destroy1(){}
//};
//
//class FNewObject1 :public FNewObject
//{
//public:
//	FNewObject1() {}
//
//	void Destroy() override {};
//	//void Destroy1() override {};
//};
//void FNewObject::Init()
//{
//
//}
//
//void FNewObject::Destroy()
//{
//
//}
class FHello1111
{
public:
	void Init() {}
	void Init1() {}
	void Init2() {}
};

class FHello11112 :public FHello1111
{

};
class FHello
{
public:
	virtual void Init() {}
	virtual void Init1() {}
	virtual void Init2() {}
};

class FHello1 :public FHello
{
public:
	void HelloC(){}
private:
	int a;
};

void Hello_C(int a)
{

}
class FTTTT:public FHello1{};
class FHelloTest 
{
public:
	FHelloTest();

	void Init();

	int a;
	int b;
	float aa;
};

FHelloTest::FHelloTest()
{
	a = 0;
	b = 10;
	aa = 10.f;
}

void FHelloTest::Init() 
{
	auto Hello_la = [&]()
	{
		cout << a << endl;
	};

	auto Hello_la2 = [&]() ->bool
	{
		cout << b << endl;

		return true;
	};

	Hello_la();

	if (bool bHello = Hello_la2())
	{
		cout << (bHello ? "TRUE" : "FALSE") << endl;
	}
}

const int aa11 = 0;
class FLllll
{
public:
	FLllll()
		:m_ptr(nullptr)
		//,m_ptrRef(NULL)
	{

	}

	const FHelloTest* m_ptr;
//	const FHelloTest& m_ptrRef;
};

//16 字节
struct FHelloStruct
{
	int a;
	int b;
	int c;
	int d;
}; 

void Fun(const int a,const FHelloTest *Ptr,const FHelloStruct &InHello)
{
	int ccc = Ptr->a;
	Ptr = new FHelloTest();

	InHello.a;
}
static FHelloStruct s;
class FTestConst
{
public:

	void Init() const {}
	void Init2() {}
	void Init1() const 
	{
		s.a = 0;
		Init();

	//	Init2();
	}

	const FTestConst* CreateObj() { return nullptr; }

	const FTestConst* GetConst()
	{
		return NULL;
	}

	const FTestConst& GetConst1()
	{
		if (const FTestConst *Obj = CreateObj())
		{
			return *Obj;
		}

		return FTestConst::NULLConst;
	}

	static FTestConst NULLConst;
private:
	int a;
};

FTestConst FTestConst::NULLConst;

FTestConst ccc[10];

int main()
{
	const FTestConst* CC = new FTestConst();
	CC->Init1();
	for (int i = 0 ; i < 10 ;i++)
	{
		const FTestConst* AA = &ccc[i];
		AA->Init();
	}

	//FA::Func1();

	//FA::Func1(1, 2);

	//FA::Func1(1, 2, 3);
	//FB A;
	//A.Func1();

	//FA* p = &A;

	//p->Func1();
	//A.Func1(1,2);
	//A.Func1(1, 2, 3);
	//FNewObject Obj;
	
	////FHello1 o;//分配一个字节
	////int len = sizeof(o);
	////cout << "大小 = " << len << "字节" << endl;

	//char buffer_C[1024] = "Hello asdasdasdasd \n";
	//char buffer_C2[1024] = "Hello asdasdasdasd1111 \n";
	//auto Hello = [&](char *buff)//const 
	//{
	//	auto Hello1 = [](char* buff)
	//	{
	//		printf("%s ~ \n", buff);
	//	};

	//	Hello1(buff);
	//	Hello1(buffer_C);
	//	Hello1(buffer_C2);
	//};

	//char buffer[1024] = "Hello";
	//Hello(buffer);

	//FHelloTest T;
	//T.Init();

	//const_cast
	//const FHelloTest* HellTest = new FHelloTest();	
	//FHelloTest* Test = const_cast<FHelloTest*>(HellTest);
	//Test->Init();

	////C风格的强转
	//FHelloTest* NewTest = (FHelloTest*)HellTest;
	//NewTest->Init();

	////reinterpret_cast
	//int a = reinterpret_cast<int>(NewTest);
	//FHelloTest *a1 = reinterpret_cast<FHelloTest *>(a);
	//a1->Init();

	////dynamic_cast
	////向上转换 ：
	////向下转换 ：NULL
	//FHello* hh = new FHello1();//向上转换

	////向下转换
	//FHello1 *aa = dynamic_cast<FHello1*>(hh);
	//aa->HelloC();

	////向上转换
	//FHello* aa1 = dynamic_cast<FHello*>(aa);
	//FHello* hh1 = aa;//进行隐式转换
	//aa1->Init();

	////转换失败会返回NULL
	//FTTTT* aa22 = dynamic_cast<FTTTT*>(hh);
	//if (aa22)
	//{
	//}

	////static_cast
	//FTTTT* aa223 = static_cast<FTTTT*>(hh);
	//FHello1111 *p11 = new FHello11112();

	//FHello11112* aa2233 = static_cast<FHello11112*>(p11);

	////const __unaligned
	//delete HellTest;
	//delete aa;

	//aa11 = 10;

	//FLllll* cc = new FLllll();
	//cc->m_ptr = new FHelloTest();
//	cc->m_ptr->a = 10;
	return 0;
}