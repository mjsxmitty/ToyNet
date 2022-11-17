
#include <iostream>
#include <stdlib.h>
#include <fstream>

#include "gz_worker_manager.h"
#include "gz_employee.h"
#include "gz_manager.h"
#include "gz_boss.h"

#define FILE_NAME   "emp_file.txt"

using namespace std;

GZWorkerManager::GZWorkerManager()
{
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);

    // 文件不存在
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;   //
        emp_num_ = 0;
        file_is_empty = true;
        emp_array_ = NULL;
        ifs.close();
        return ;
    }

    // 文件存在且为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空!" << endl;
        emp_num_ = 0;
        file_is_empty = true;
        emp_array_ = NULL;
        ifs.close();
        return ;
    }
    ifs.close();

    // 文件存在
    int num = GetEmpNum();
    cout << "职工个数为：" << num << endl;  //
    emp_num_ = num;

    emp_array_ = new GZworker* [num];
    InitEmp();
	for (int i = 0; i < emp_num_; i++)
	{
		cout << "职工号： " << this->emp_array_[i]->id_
			<< " 职工姓名： " << this->emp_array_[i]->name_
			<< " 部门编号： " << this->emp_array_[i]->dept_id_ 
            << endl;
	}
}
GZWorkerManager::~GZWorkerManager()
{
    if (emp_array_ != NULL)
    {
        delete [] emp_array_;
        emp_array_ = NULL;
    }
}

void GZWorkerManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void GZWorkerManager::ExitSystem()
{
	cout << "欢迎下次使用!" << endl;
	exit(0);    // 退出进程
}

void GZWorkerManager::AddEmp()
{
	cout << "请输入增加职工数量： " << endl;
	int add_num = 0;
	cin >> add_num;

    if (add_num < 0)
    {
        cout << "输入有误!" << endl;
        return ;
    }

    // 分配新空间
    int new_size = emp_num_ + add_num;
    GZworker **new_space = new GZworker* [new_size];

    // 拷贝源空间数据
    if (emp_array_ != NULL)
        for (int i = 0; i != emp_num_; ++i)
            new_space[i] = emp_array_[i];

    // 写入新数据
    for (int i = 0; i != add_num; ++i)
    {
        int id;
        cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
        cin >> id;

        string name;
        cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
        cin >> name;

        cout << "请选择该职工的岗位：" << endl;
        cout << "1、普通职工" << endl;
        cout << "2、经理" << endl;
        cout << "3、老板" << endl;
        int select;
        cin >> select;

        GZworker *worker = NULL;
        switch (select)
        {
            case 1:
                worker = new GZEmployee(id, name, select);
                break;
            case 2:
                worker = new GZManager(id, name, select);
                break;
            case 3:
                worker = new GZBoss(id, name, select);
                break;
            default:
                break;
        }

        new_space[emp_num_ + i] = worker;
    }

    // 释放原空间
    delete [] emp_array_;

    // 更新
    emp_array_ = new_space;
    emp_num_ = emp_num_ + new_size;
    Save();
    file_is_empty = false;

    cout << "成功添加 " << new_size << " 名新职工！" << endl;
}

void GZWorkerManager::Save()
{
    ofstream ofs;
    ofs.open(FILE_NAME, ios::app);
    if (!ofs.is_open())
    {
        cerr << "open " << FILE_NAME << " failed." << endl;
        return ;
    }

    for (int i = 0; i != emp_num_; i++)
    {
        ofs << emp_array_[i]->id_ << " "
            << emp_array_[i]->GetDeptName() << " "
            << emp_array_[i]->dept_id_ << endl;
    }

    ofs.close();
}

int GZWorkerManager::GetEmpNum ()
{
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);

    int id;
    string name;
    int did;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
        num++;
    ifs.close();
    return num;
}

void GZWorkerManager::InitEmp()
{
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);

    int id;
    string name;
    int did;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        GZworker *worker = NULL;
        if (did == 1)
            worker = new GZEmployee(id, name, did);
        else if (did == 2)
            worker = new GZManager(id, name, did);
        else
            worker = new GZBoss(id, name, did);
        
        emp_array_[index++] = worker;
    }
}

void GZWorkerManager::ShowEmp()
{
    if (file_is_empty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i != emp_num_; ++i)
            emp_array_[i]->ShowInfo();
    }
}