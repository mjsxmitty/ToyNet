#include "dlllib/Interface.h"
#include "Clib/Header.h"
#include <iostream>

#pragma comment(lib,"FengzhuangCPP.lib")
#pragma comment(lib,"fenzhuangC.lib")
using namespace std;

//模块
int main()
{
	//调用C++
	IInterface *IF = IInterface::CreateInterface();
	cout << IF->GetName() << endl;
	IF->Init();
	IF->Destroy();

	//调用c库
	init_c(1, 2);
	get_c_name(2, 3);

	//默认
	//缺省值(默认)

	//DLL 和 Lib exe pdb
	return 0;
}