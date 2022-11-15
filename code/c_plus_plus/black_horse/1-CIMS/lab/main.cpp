
#include <iostream>
#include "gz_person.h"
#include "gz_operate.h"

using namespace std;

void ShowMenu();

int main()
{
    AddressBooks abs;
    int select = 0;

    while (true)
    {
        ShowMenu();

        cin >> select;
        switch (select)
        {
            case 1:  //添加联系人
                break;
            case 2:  //显示联系人
                break;
            case 3:  //删除联系人
                break;
            case 4:  //查找联系人
                break;
            case 5:  //修改联系人
                break;
            case 6:  //清空联系人
                break;
            case 0:  //退出通讯录
                cout << "欢迎下次使用" << endl;
                return 0;
            default: break;
        }
    }

    return 0;
}

void ShowMenu()
{
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}
