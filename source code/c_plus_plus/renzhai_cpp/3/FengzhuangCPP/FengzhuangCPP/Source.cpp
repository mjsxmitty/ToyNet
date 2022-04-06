#include "Interface.h"
#include <iostream>

class FHello :public IInterface
{
public:
	FHello();

	virtual void Init();
	virtual void Destroy();
	virtual char* GetName();

private:
	char Name[1024];
};

FHello::FHello()
{
	memset(Name, 0, 1024);
	strcpy(Name, "Hello");
}

void FHello::Init()
{
	printf("FHello::Init() \n");
}


void FHello::Destroy()
{
	printf("FHello::Destroy() \n");
}

char* FHello::GetName()
{
	return Name;
}

IInterface* IInterface::CreateInterface()
{
	return new FHello();
}
