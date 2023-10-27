
#include <iostream>
#include "gz_worker_manager.h"

using namespace std;

int main()
{
    GZWorkerManager wm;
	int             choice = 0;

	while (true)
	{
		//展示菜单
		wm.ShowMenu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;

		switch (choice)
		{
            case 0: //退出系统
                wm.ExitSystem();
                break;
            case 1: //添加职工
                wm.AddEmp();
                break;
            case 2: //显示职工
                wm.ShowEmp();
                break;
            case 3: //删除职工
                wm.DelEmp();
                break;
            case 4: //修改职工
                wm.ModEmp();
                break;
            case 5: //查找职工
                wm.FindEmp();
                break;
            case 6: //排序职工
                wm.SortEmp();
                break;
            case 7: //清空文件
                wm.CleanFile();
                break;
            default:
                break;
		}
	}
    cout << "End!" << endl;
    return 0;
}
