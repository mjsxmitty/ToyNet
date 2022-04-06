#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <winerror.h>
//iostream
using namespace std;

class FH 
{

};

struct FHello //
{
	FHello()
	{
		//初始化
		aa = new int;
	}

	~FHello()
	{
		if (aa)
		{
			delete aa;
			aa = NULL;
		}
	}

	int a;
	int b;
	float c;
	float d;
private:
	int m;

	int *aa;

public:
	void Hello1()
	{
		a = 0;
		b = 0;

		HHH();
	}
	static void Hello3();
	inline int GetP() const { return p; }
private:
	void HHH()
	{

	}
	int p;
};

void FHello::Hello3()
{

}

int Hello3()
{
	return 1 + 3;
}

class FMonster
{
public:
	FMonster();
	~FMonster();

	int a;
	int b;

	static int Helle3() { return 4; }
	int Helle4() 
	{ 
		FMonster::Helle3();
		return 4;
	}

	FORCEINLINE int GetAA()const { return a; }
	inline int GetP() const { return p; }//for 
private:
	int p;

};
inline int GetA()
{
	return 0;
}

FMonster::FMonster()
{
	int cc = ::Hello3();
	cout << cc << endl;
}

FMonster::~FMonster()
{

}

class FWorkers //基类 父类
{
public:
	void Work(){/*/...*/}
private:
	void Work1() {/*/...*/ }
protected:
	void Work3(){}
};

//SDK
//
//public 
	//1.public:		 public:
	//2.private		 private
	//3.protected	 protected
//protected
	//1.public:		 protected:
	//2.private		 private
	//3.protected	 protected
//private
	//1.public:		 private:
	//2.private		 private
	//3.protected	 private
class FComponentWorkers :private FWorkers
{
public:
	void Hello()
	{
		Work3();
		Work();
		//Work1();
	}
};


class FTest :public FComponentWorkers
{
public:
	void A()
	{
		Hello();
		//Work3();
		//Work();
	}
};

class FSpliceWorkers :public FWorkers
{

};

class UObject 
{
public:
	void Destroy(){}
};

class AActor :public UObject
{
public:
	void Start(){}
	void End(){}

	void Net(){}
};

class UHello :public UObject
{

};

class IPhysics
{
public:
	void Simulate(){}
};

class IAttack
{
public:
	void AttackTarget(class ACharacter *InTarget){}
};

class ACharacter :public AActor,public IPhysics,public IAttack, public UHello
{
	//sdasasdasd dasdasd
};

//virtual 
class A
{
public:
	A()
	{
		printf("Hello -A  \n");
	}

	void Hello()
	{
		printf("Hello()  \n");
	}
};

//变成共享类

class B :virtual public A
{
public:
	B()
		:A() 
	{}
};

class C :virtual public A
{
public:
	C()
		:A()
	{
	
	}
};

class D : public B, public C
{
public:
	D()
		:B(),C()
	{
	
	};
	~D() {};
};

bool IsSimulate(IPhysics *P)
{
	if (P)
	{
		P->Simulate();
	}

	return true;
}

class FTestClass
{
	friend class FTest2;//友元
public:
	void Hello(){}
private:
	void Hello1(){}
	void Hello2() {}
	void Hello3() {}
protected:
	void Hello4() {}
};

class FCC :public FTestClass
{
public:
};

class FTest2
{
public:

	void Init() 
	{
		Class.Hello();
		Class.Hello1();
		Class.Hello4();
	}
private:
	FTestClass Class;
};

class FTest3
{
public:

	friend void Printf_f(FTest3 &T) /*const*/
	{
		//没有 this
		T.Hello();
		printf("%d \n", T.b);
		printf("%d \n",T.a);
	}

	static void Hello1(FTest3& T)
	{
		//没有 this
		T.Hello();
		printf("%d \n", T.b);
		printf("%d \n", T.a);
	}
private:
	void Hello()
	{
		a = 0;
		b = 10;
	}
private:
	int a;
	int b;
};

class FHello_F{};

class FTestA :public FHello_F
{
public:
	FTestA();
	FTestA(const FTestA &Test);
	FTestA(int Ina, int intb, int inc);
	~FTestA();
public:
	int a;
	int b;
	int c;
	FTest3* T3;
};

FTestA::FTestA()
{
	this->a = 11;
	this->b = 13;
	this->c = 9;

	this->T3 = new FTest3();
}	

FTestA::FTestA(int Ina, int intb, int inc)
	:FHello_F()
	,a(Ina)
	,b(intb)	
	,c(inc)
{
	T3 = new FTest3();
}

FTestA::FTestA(const FTestA& Test)
{
	this->a = Test.a;
	this->b	= Test.b;
	this->T3 = new FTest3();
	*this->T3 = *Test.T3;
}

FTestA::~FTestA()
{
	if (T3)
	{
		delete T3;
		T3 = nullptr;
	}
}

const FTestA* TestA = NULL;

void HelloTest(){}

namespace AssetHello
{
	enum EHello
	{
		Hello_A,
		Hello_B,
	};

	struct FAssetHello
	{
		void Init() {}
		void Hello() {}
	};

	class IInterface
	{

	};

	class FHello :public IInterface
	{

	};

	FHello* GetHello();

	class Fistream
	{
	public:

		Fistream()
		{
			memset(&m_string, 0, 1024);
			m_p = NULL;
			a = 0;
		}

		Fistream& Print()
		{
			printf(m_string);

			if (m_p)
			{
				printf(m_p);
			}

			return *this;
		}

		//重载
		//双目算术运算符	+ (加)，-(减)，*(乘)，/(除)，% (取模)
		//关系运算符	==(等于)，!= (不等于)，< (小于)，> (大于>，<=(小于等于)，>=(大于等于)
		//逻辑运算符	||(逻辑或)，&&(逻辑与)，!(逻辑非)
		//单目运算符	+ (正)，-(负)，*(指针)，&(取地址)
		//++(自增)，--(自减)
		//位运算符	| (按位或)，& (按位与)，~(按位取反)，^(按位异或),，<< (左移)，>>(右移)
		//赋值运算符	=, +=, -=, *=, /= , % = , &=, |=, ^=, <<=, >>=
		//空间申请与释放	new, delete, new[ ] , delete[]
		//其他运算符	()(函数调用)，->(成员访问)，,(逗号)，[](下标)

		//不可以的重载的
		//. 
		//*  ->*
		//:: 
		//sizeof
		//?:
		//#

		int operator+(const Fistream& p)
		{
			return a+p.a;
			
		}

		Fistream& operator++(int)
		{
			a++;
			return *this;
		}

		Fistream& operator--(int)
		{
			a--;
			return *this;
		}
		Fistream& operator-=(int)
		{
			a--;
			return *this;
		}
		Fistream& operator+=(int p)
		{
			a-= p;
			return *this;
		}
		Fistream& operator+=(const Fistream&p)
		{
			a+= p.a;
			return *this;
		}

		bool operator!=(const Fistream& p)
		{
			return a != p.a;
		}

		Fistream& operator=(const char* p)
		{
			strcpy(m_string, p);
			return *this;
		}

		Fistream& operator=(const Fistream &p)
		{
			m_p = (char*)malloc(1024);

			strcpy(this->m_p, p.m_p);
			return *this;
		}

		Fistream& operator=(const int p)
		{
			//itoa()
			//strcpy(m_string, p);
			return *this;
		}

		Fistream& operator<<(const char *p)
		{
			printf(p);
			return *this;
		}

		Fistream& operator<<(const Fistream& p)
		{
			printf("\n");
			return *this;
		}

		Fistream& operator<<(const int p)
		{
			printf("%d", p);
			return *this;
		}

		Fistream& operator<<(const float p)
		{
			printf("%f", p);
			return *this;
		}

		Fistream& operator<<(const double p)
		{
			printf("%le", p);
			return *this;
		}
		Fistream& operator>>(const char* p)
		{
			printf("%s", p);
			return *this;
		}
		char* m_p;
		int a;
	private:
		char m_string[1024];
		
	};

	Fistream printcout;
	Fistream endcout;
}

namespace AssetHello
{
	FHello* GetHello()
	{
		return NULL;
	}
}

namespace AssetHello
{
	class IInterface2
	{

	};
}

namespace AssetHello
{
	class IInterface3
	{

	};
}

//using namespace AssetHello;

int main()
{
	{
		//TestA = new FTestA();
		//TestA = new FTestA();
		//TestA->a = 10;

		FTestA A;
		cout << A.a << A.b << A.c << endl;
		FTestA B(1, 2, 3);

		//A = B;
		FTestA C(B);//浅拷贝
		std::cout << C.a << C.b << C.c << endl;

		//调用枚举
		AssetHello::EHello o = AssetHello::EHello::Hello_A;
		AssetHello::EHello o1 = AssetHello::Hello_A;

		AssetHello::FHello *p = new AssetHello::FHello();
		//AssetHello::GetHello();
		//GetHello();
		::HelloTest();

		//定义自己的打印方式
		AssetHello::printcout << "Hello" << AssetHello::endcout;
		AssetHello::printcout << "Hello" <<" 111" << "222" <<  "3333"<< AssetHello::endcout;
		AssetHello::printcout << 1.0034f << AssetHello::endcout;
		AssetHello::printcout << 1.00342314123 << AssetHello::endcout;
		AssetHello::printcout >> "Hello" << AssetHello::endcout;

		(AssetHello::printcout = "123456677").Print() << AssetHello::endcout;

		//=深拷贝和浅拷贝问题
		AssetHello::Fistream a, b;
		a.m_p = (char *)malloc(1024);
		strcpy(a.m_p, "Hello 111111");

		b = a;
		b.Print();


		//++ == != > < + - / ^
		int aaa = 10;
		aaa ++;
		aaa += 1;
		aaa = aaa + 1;

		AssetHello::printcout++;
		AssetHello::printcout--;
		AssetHello::printcout-=1;
		AssetHello::printcout+=1;
		AssetHello::printcout += AssetHello::endcout;
		int ccc = AssetHello::printcout + AssetHello::endcout;
		if (AssetHello::printcout != AssetHello::endcout)
		{
		}
	}
	/*FMonster Monster;
	Monster.GetP();
	FMonster::Helle3();
	Monster.Helle4();
	FHello Hello;
	Hello.Hello1();
	FHello::Hello3();
	Hello.a = 0;
	int k = Hello.a;
	Hello.b;*/
	//Hello.m = 10;
	//Hello.m1 = 10;

//	FComponentWorkers w;
//	w.Work();
//	w.Hello();
//	w.Work3();
//	w.Work1();
	//FSpliceWorkers w1;
	//w1.Work();

//	ACharacter A;
//	ACharacter B;
//	A.Simulate();
//	A.AttackTarget(&B);
//
//	IPhysics* P = &A;
//	IAttack* P1 = &A;
//	AActor* P2 = &A;
//
//	IsSimulate(&A);
////	A.Destroy();
//
//	D d;
//	d.Hello();
//	FTest2 Test2;
//	Test2.Init();
//
//	FTest3 T3;
//	Printf_f(T3);
//
//	FTest3::Hello1(T3);


	system("pause");

	return 0;
}