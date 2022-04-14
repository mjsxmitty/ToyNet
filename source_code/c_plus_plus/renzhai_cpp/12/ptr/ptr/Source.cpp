#include <iostream>
#include <vector>
#include "SharedPtr.h"


using namespace std;
class FHelloBase
{
public:
	FHelloBase()
	{
		a = new int;
	}
	~FHelloBase()
	{
		delete a;
		a = nullptr;
	}
	bool IsVaild()
	{
		return a != nullptr;
	}

private:

	int *a;
};

class FHello
{
public:
	FHello() 
	{ 
		a = 100;
		ptr = new FHelloBase();
	}

	~FHello()
	{
		delete ptr;
		ptr = nullptr;
	}


	void init()
	{
		a = 0;
		if (ptr->IsVaild())
		{

		}
	}
private:
	int a;
	FHelloBase* ptr;
};

//UE4
//class FTestUE4 :public TSharedFromThis<FTestUE4>
//{
//
//};
class FTestPtr2
{
public:
	FTestPtr2()
	{
		a = 1000;
	}
	~FTestPtr2()
	{

	}
	void Init()
	{
		cout << "Init" << endl;
	}

private:
	int a;
};
class FTestPtr :public enable_shared_from_this<FTestPtr>
{
public:
	FTestPtr()
	{
		a = 1000;
	}
	~FTestPtr()
	{
		
	}
	void Init()
	{
		cout << "Init" << endl;
	}

private:
	int a;
};

class IInterface
{
public:

	void SetPtr(shared_ptr<FTestPtr> InPtr)
	{
		Weak = InPtr;
	}

	virtual void DoWork() = 0;
protected:
	weak_ptr<FTestPtr> Weak;
};

//TSharedFromThis
class A :public IInterface
{
public:

	virtual void DoWork()
	{
		Weak.lock()->Init();
	}
};
class FHelloF
{
public:
	FHelloF()
		:Instance(new FTestPtr)
	{
		
	}

	IInterface* CreateInterface()
	{
		IInterface *face = new A();
		face->SetPtr(Instance);
		return face;
	}

	shared_ptr<FTestPtr> Get();
private:
	shared_ptr<FTestPtr> Instance;
};

shared_ptr<FTestPtr> FHelloF::Get()
{
	return Instance;
}

class FTestDeleter
{
	int count;
public:
	FTestDeleter()
		:count(0)
	{

	}

	template<class T>
	void operator()(T* p)
	{
		cout <<"operator" <<endl;

		delete p;
	}
};

int main()
{
	//vector<FHello*> Arrays;
	//for (int i = 0; i < 10000; i++)
	//{
	//	FHello *p = new FHello();
	//	Arrays.push_back(p);

	//	delete p;


	//	if (Arrays[0])
	//	{
	//		Arrays[0]->init();
	//	}
	//}	

	//TSharedPtr
	//裸指针
	int* a = new int;

	//共享指针的初始化
	//std::shared_ptr<int> ptr = a;//X不允许这样赋值
	shared_ptr<int> ptr(a);//X
	cout << ptr.use_count() << endl;
	//TSharedPtr<int> pre(a); UE4
	//UE4  MakeShareable(new int)
	//std  make_shared<int>(12);
	shared_ptr<int> ptr1 = make_shared<int>(12);//直接变
	cout << ptr1.use_count() << endl;
	shared_ptr<int> ptr2(ptr1);//增加引用计数 //敏感检测
	cout << ptr1.use_count() << endl;
	shared_ptr<int> ptr3 = ptr1;
	cout << ptr1.use_count() << endl;
	ptr3 = nullptr;//
	cout << ptr1.use_count() << endl;
	//std::weak_ptr

	//智能指针转为原始指针 裸指针
	int* iii = ptr1.get();
	int aaa = *ptr1;
	if (ptr1.unique())
	{
		cout << "唯一" << endl;
	}

	//ptr1.swap(ptr);
	ptr1.reset();

	//
	shared_ptr<FTestPtr> NewPtr(new FTestPtr);
	FTestPtr* HelloPtr = NewPtr.get();
	shared_ptr<FTestPtr> Hello2 = HelloPtr->shared_from_this();
	//TSharedPtr<>
	//TSharedRef<>
	//TWeakPtr
	//TWeakObjectPtr
	//TWeakObjectPtrMapKeyFuncs

	//std::weak_ptr<>
	weak_ptr<FTestPtr> HelloWeak = Hello2;
	HelloWeak.lock()->Init(); //转为共享指针
	if (HelloWeak.use_count() == 0)
	{

	}

	if (HelloWeak.expired()) //共享指针是否释放了
	{
		cout << "失效了" << endl;
	}

	/*
	std::auto_ptr<FTestPtr> C++ 11标准中废弃了
	std::auto_ptr_ref<FTestPtr>
	std::unique_ptr<FTestPtr>*/


	FHelloF HelloF;
	IInterface* I = HelloF.CreateInterface();
	I->DoWork();

	//C++ 11废弃
	auto_ptr<FTestPtr> Instance1(new FTestPtr());
	auto_ptr<FTestPtr> Instance2;
	Instance2 = Instance1;//转移控制权 不安全
	FTestPtr* OOO = Instance2.release();
	Instance2.reset(new FTestPtr()); //重新 设置设置一个类
	FTestPtr* OOO1 = Instance2.get();

	//
	unique_ptr<FTestPtr> Instance3(new FTestPtr());
	//unique_ptr<FTestPtr> Instance4(Instance3);
	//Instance4 = Instance3;
	unique_ptr<FTestPtr> Instance4 = unique_ptr<FTestPtr>(new FTestPtr());
	//weak_ptr<FTestPtr> ww22 = Instance4; //不支持

	struct FPtr
	{
		FPtr()
		{
			Instance3 = unique_ptr<FTestPtr>(new FTestPtr());
		}

		unique_ptr<FTestPtr> Instance3;
	};

	Instance4.get_deleter();

	unique_ptr<FTestPtr, FTestDeleter> Instance5(new FTestPtr());
	unique_ptr<FTestPtr, FTestDeleter> Instance6(new FTestPtr(), Instance5.get_deleter());
	//TUniquePtr

	//导致内存奔溃
	FSharedPtr<FTestPtr2> TestPtr2(new FTestPtr2());
	FSharedPtr<FTestPtr2> TestPtr3(TestPtr2);
	FSharedPtr<FTestPtr2> TestPtr4 = TestPtr2;

	TestPtr4.Release();
	TestPtr3->Init();
	TestPtr3.Release();

	FWeakPtr<FTestPtr2> HelloWPtr = TestPtr2;
	FWeakPtr<FTestPtr2> HelloWPtr2(TestPtr2);
	HelloWPtr2.Pin()->Init();
	HelloWPtr2.Release();

	//可以通过这种方式来移交我们的控制权力
	unique_ptr<FTestPtr> Instance555(new FTestPtr());
	unique_ptr<FTestPtr> Instance300 = move(Instance555);

	//mysql //

	//C++ 4种
	//C-> (type )

	struct FCastTestInterface :public enable_shared_from_this<FCastTestInterface>
	{
		FCastTestInterface()
			:a(100)
		{

		}
		virtual void Hello(){}

		int a;
	};

	struct FCastTest :public FCastTestInterface
	{
		FCastTest()
			:b(200)
		{

		}
		int b;
	};

	shared_ptr<FCastTestInterface> MyInterface(new FCastTest());
	cout << MyInterface->a << endl;;
	//MyInterface->b;
	shared_ptr<const FCastTest> TestCast = dynamic_pointer_cast<FCastTest>(MyInterface);
//	TestCast->b = 122;
	shared_ptr< FCastTest> TestCast1 = const_pointer_cast<FCastTest>(TestCast);
	TestCast1->b = 122;
	cout << TestCast->b << endl;

	shared_ptr<FCastTest> TestCast222 = static_pointer_cast<FCastTest>(MyInterface);

	shared_ptr<FCastTest> TestCast2223 = reinterpret_pointer_cast<FCastTest>(MyInterface);

	return 0;
}