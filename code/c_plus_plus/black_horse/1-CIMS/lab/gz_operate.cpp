
#include <iostream>
#include "gz_operate.h"

using namespace std;

void AddPerson(AddressBooks *abs)
{
    if (abs->size == MAX_NUM)
    {
        cout << "" << endl;
        return ;
    }

    string name;
    cout << "请输入姓名: ";
    cin >> name;
    abs->person_array[abs->size].name = name;

    cout << "请输入性别: " << endl;
    cout << "1 -- 男" << endl;
    cout << "2 -- 女" << endl;
    int sex = 0;
    while (true)
    {
        cin >> sex;
        if (sex == 1 || sex == 2)
        {
            abs->person_array[abs->size].sex = sex;
            break;
        }
        cout << "输入有误,请重新输入!" << endl;
    }

    int age;
    cout << "请输入年龄: ";
    cin >> age;
    abs->person_array[abs->size].age = age;

    string phone;
    cout << "请输入电话: ";
    cin >> phone;
    abs->person_array[abs->size].phone = phone;

    string addr;
    cout << "请输入地址: ";
    cin >> addr;
    abs->person_array[abs->size].addr = addr;

    abs->size++;
    cout << "添加成功!" << endl;
}

void ShowPerson(AddressBooks* abs)
{
    if (abs->size == 0)
    {
        cout << "当前记录为空!" << endl;
        return ;
    }

    for (int i = 0; i != abs->size; ++i)
    {
        cout << "姓名：" << abs->person_array[i].name << "\t";
        cout << "性别：" << (abs->person_array[i].sex == 1 ? "男" : "女") << "\t";
        cout << "年纪：" << abs->person_array[i].age << "\t";
        cout << "电话：" << abs->person_array[i].phone << "\t";
        cout << "地址：" << abs->person_array[i].addr << "\t";
    }
}

void DeletePerson(AddressBooks* abs)
{
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int ret = IsExist(abs, name);
    if (ret == -1)
    {
        cout << "查无此人" << endl;
        return ;
    }

    for (int i = ret; i != abs->size; ++i)
        abs->person_array[i] = abs->person_array[i+1];
    abs->size--;
    cout << "删除成功" << endl;
}

void FindPerson(AddressBooks* abs)
{
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int ret = IsExist(abs, name);
    if (ret == -1)
    {
        cout << "查无此人" << endl;
        return ;
    }

    cout << "姓名：" << abs->person_array[ret].name << "\t";
    cout << "性别：" << (abs->person_array[ret].sex == 1 ? "男" : "女") << "\t";
    cout << "年纪：" << abs->person_array[ret].age << "\t";
    cout << "电话：" << abs->person_array[ret].phone << "\t";
    cout << "地址：" << abs->person_array[ret].addr << "\t";
}

void ModifyPerson(AddressBooks* abs)
{
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int ret = IsExist(abs, name);
    if (ret == -1)
    {
        cout << "查无此人" << endl;
        return ;
    }

    //string name;
    cout << "请输入姓名: ";
    cin >> name;
    abs->person_array[ret].name = name;

    cout << "请输入性别: " << endl;
    cout << "1 -- 男" << endl;
    cout << "2 -- 女" << endl;
    int sex = 0;
    while (true)
    {
        cin >> sex;
        if (sex == 1 || sex == 2)
        {
            abs->person_array[ret].sex = sex;
            break;
        }
        cout << "输入有误,请重新输入!" << endl;
    }

    int age;
    cout << "请输入年龄: ";
    cin >> age;
    abs->person_array[ret].age = age;

    string phone;
    cout << "请输入电话: ";
    cin >> phone;
    abs->person_array[ret].phone = phone;

    string addr;
    cout << "请输入地址: ";
    cin >> addr;
    abs->person_array[ret].addr = addr;

    cout << "修改成功" << endl;
}

void CleanPerson(AddressBooks* abs)
{
    abs->size = 0;
    cout << "通讯录已清空" << endl;
}

int IsExist(AddressBooks* abs, string name)
{
    for (int i = 0; i != abs->size; ++i)
    {
        if (abs->person_array[i].name == name)
            return i;
    }

    return -1;
}
