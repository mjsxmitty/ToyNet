//#pragma once
#ifndef INTERFACE_H
#define INTERFACE_H
#define _CRT_SECURE_NO_WARNINGS

#define FENGZHUANGCPP_API __declspec(dllexport)
//动态连接库
//静态连接库
class FENGZHUANGCPP_API IInterface
{
public:

	static IInterface* CreateInterface();

	virtual void Init() = 0;
	virtual void Destroy() = 0;
	virtual char *GetName() = 0;
};


#endif
