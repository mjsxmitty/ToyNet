#pragma once

#define D_THREAD(TName,TInstance) \
template<class T> \
class FThread_##TName \
{ \
public: \
	static T* Get() \
	{ \
		if (!Instance) \
		{ \
			Instance = new T(); \
		} \
		return Instance; \
	} \
	static void Destroy()  \
	{ \
		delete Instance;Instance = NULL; \
	} \
private: \
	static T* Instance; \
}; \
template<class T> \
T *FThread_##TName<T>::Instance = NULL; \
typedef FThread_##TName<TInstance> TName;
