#ifndef HEADER_H
#define HEADER_H

#define FENZHUANGC_API __declspec(dllexport)

#ifdef __cplusplus
extern "C" //告诉编译器 这里面是c语言的代码
{
#endif
	FENZHUANGC_API int __stdcall init_c(int a,int b);

	FENZHUANGC_API int __stdcall get_c_name(int a, int b);
	
	int get_c_name1(int a, int b);


#ifdef __cplusplus
}
#endif

#endif
