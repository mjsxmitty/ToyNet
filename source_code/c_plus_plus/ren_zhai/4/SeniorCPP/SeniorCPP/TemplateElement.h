#pragma once
#include <iostream>
#include <type_traits>

//typedef/using
//enum、static const
//T,Args...
//::
//template

//if else  for ?
//递归、重载、和模板特化（偏特化）
//三目
//C++ 11 type_traits //编译期间 计算 查询 判断 和转换 选择

template<class T,T v>
struct Fconstffff
{
//	const
	static constexpr T value = v;
};
//const_cast
//template<int v1, int v2>
//struct Fconstffff1
//{
//	//	const
//	static constexpr T value = v1 + v2;
//};

template<class T>
struct RemoveConst
{
	using Type = T;
};

template<class T>
struct RemoveConst<const T>
{
	using Type = T;
};

template<bool v>
using bool_temp = Fconstffff<bool, v>;

template<class ,class>
constexpr bool isSame_V = false;

template<class T1>
constexpr bool isSame_V<T1,T1> = true;

template<class T1,class T2>
struct isSame :bool_temp<isSame_V<T1, T2>> {};

template<int a,int ...Args>
struct IntMax;

template<int a>
struct IntMax<a> :std::integral_constant<int,a>
{

};

template<int a1,int a2,int ...Args>
struct IntMax<a1, a2, Args...>
	:std::integral_constant<int, a1 >= a2 ?
	IntMax<a1, Args...>::value :
	IntMax<a2, Args...>::value>
{

};

template<typename ...Args>
struct MaxAlign
	:std::integral_constant<int,IntMax<std::alignment_of<Args>::value...>::value>
{

};
