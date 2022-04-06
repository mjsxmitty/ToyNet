#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
#include <atlstr.h>

using namespace std;

struct FA
{
	int a;
};

//专门输出到我们的DebugLog
void out_put_debug_log(const char *in_format,...)
{
	char buffer[8196] = { 0 };
	va_list in_args;
	va_start(in_args, in_format);
	_vsnprintf(buffer, sizeof(buffer) - 1, in_format, in_args);
	va_end(in_args);

	OutputDebugString(CA2W(buffer));
}
char p[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX 奔溃";
struct FXXXX :public exception
{
	const char* what() const throw()
	{	
		out_put_debug_log("当前出现问题 [%s] 巴拉巴拉....\n", p);
		return p;
	}

	const char* Hello() const
	{
		return p;
	}
};

struct FXXXX11
{
	const char* what() const throw()
	{
		out_put_debug_log("当前出现问题 [%s] 巴拉巴拉....\n", p);
		return p;
	}

	const char* Hello() const
	{
		return p;
	}
};

struct FXXXX112
{
	const char* Hello() const
	{
		return p;
	}
};

//std::exception
//std::bad_alloc new 异常
//std::bad_cast dynamic_cast 异常
//std::bad_exception 
//std::bad_typeid typeid()
//std::logic_error
//std::domain_error
//const throw()
//std::invalid_argument
//std::length_error std::string FString
//std::out_of_range std::vector
//std::runtime_error
//std::overflow_error  
//std::range_error
//char dd[1204] 
//std::underflow_error

class DDD{};

//typeid(dataType)
//typeid(expression)
int main()
{
	double a = 0.0;
	int b = 10;

	const type_info &Info =	typeid(10 * 20 / 100);
	cout << "   Name =" << Info.name() 
		 << "\n raw_name =" << Info.raw_name() 
		 << "\n hash_code =" << Info.hash_code()
		 << endl;



//	int c = b / a;

//	FA* d = NULL;
//	d->a = 10;

	//try
	//{
	//	if (b == 10)
	//	{
	//		throw FXXXX112();
	//	}
	//}
	//catch (const char *Msg) //捕获我们的错位信息
	//{
	//	cout << Msg << endl;

	//	out_put_debug_log("当前出现问题 [%s] 巴拉巴拉....", Msg);
	////	assert(0);
	//}
	//catch (const FXXXX& Msg) //捕获我们的错位信息
	//{
	//	cout << Msg.what() << endl;
	//	cout << Msg.Hello() << endl;
	//}
	//catch (const FXXXX11& Msg) //捕获我们的错位信息
	//{
	//	cout << Msg.what() << endl;
	//	cout << Msg.Hello() << endl;
	//}
	//catch (const FXXXX112& Msg) //捕获我们的错位信息
	//{
	//	cout << Msg.Hello() << endl;
	//}

	return 0;
}
