#include <iostream>

using namespace std;

class FHello
{
public:

	FHello *operator *()
	{
		return nullptr;
	}
	FHello* operator *(const FHello& In)
	{
		return nullptr;
	}
	FHello & operator +(const FHello &In)
	{
		return *this;
	}
	FHello& operator -(const FHello& In)
	{
		return *this;
	}
	FHello& operator /(const FHello& In)
	{
		return *this;
	}
	FHello& operator&(const FHello& In)
	{
		return *this;
	}
	FHello& operator^(const FHello& In)
	{
		return *this;
	}
	FHello& operator++(int)
	{
		return *this;
	}
	FHello& operator--(int)
	{
		return *this;
	}
	FHello& operator-=(const FHello &In)
	{
		return *this;
	}
	FHello& operator+=(const FHello& In)
	{
		return *this;
	}
	FHello& operator*=(const FHello& In)
	{
		return *this;
	}
	FHello& operator/=(const FHello& In)
	{
		return *this;
	}
	FHello& operator=(const FHello& In)
	{
		return *this;
	}
	FHello& operator==(const FHello& In)
	{
		return *this;
	}
	FHello& operator!=(const FHello& In)
	{
		return *this;
	}
	FHello& operator^=(const FHello& In)
	{
		return *this;
	}
	FHello& operator|(const FHello& In)
	{
		return *this;
	}
	FHello& operator||(const FHello& In)
	{
		return *this;
	}
};

int main()
{
	FHello A, B;
	auto a = *A;
	auto b = A||B;
	auto c = A | B;
	auto d = A ^ B;
	auto e = A++;
	auto f = A--;
	auto g = A * B;
	auto h = A / B;
	auto i = A != B;
}