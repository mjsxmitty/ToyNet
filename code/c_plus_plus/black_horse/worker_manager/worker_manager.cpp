
#include <iostream>
#include <fstream>

#include "worker_manager.h"
#include "boss.h"
#include "manager.h"
#include "employee.h"

#define FILE_NAME	"emp_file.txt"

using namespace std;

WorkerManager::WorkerManager()
{
	//1 文件不存在
	std::ifstream ifs;
	ifs.open(FILE_NAME, ios::in);
	if (!ifs.is_open()) {
		std::cout << "文件不存在!" << std::endl;
		emp_num_ = 0;
		emp_array_ = NULL;
		emp_file_empty_ = true;
		ifs.close();
		return ; 
	}
	
	//2 空文件
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		std::cout << "文件为空!" << std::endl;
		emp_num_ = 0;
		emp_array_ = NULL;
		emp_file_empty_ = true;
		ifs.close();
		return ; 
	}
	
	//3 存在数据
	int num = GetEmpNum();
	emp_num_ = num;
	emp_array_ = new Worker*[emp_num_];
	Init();
	emp_file_empty_ = false;
}

WorkerManager::~WorkerManager()
{
	if (emp_array_ != NULL) {
		for (int i = 0; i < emp_num_; i++) {
			if (emp_array_[i] != NULL) {
				delete emp_array_[i];
				emp_array_[i] = NULL;
			}
		}
		
		delete [] emp_array_;
		emp_array_ = NULL;
	}
}

void WorkerManager::ShowMenu()
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

void WorkerManager::ExitSysterm()
{
    cout << "欢迎下次使用！" << endl;
    exit(0);
}

void WorkerManager::Save()
{
	std::ofstream ofs;
	ofs.open(FILE_NAME, ios::out);

	for (int i = 0; i < emp_num_; i++) {
		ofs << emp_array_[i]->id_ << "\t"
			<< emp_array_[i]->name_ << "\t"
			<< emp_array_[i]->dept_id_
			<< std::endl;
	}
	ofs.close();
}

void WorkerManager::AddEmployee()
{
	std::cout << "请输入增加员工的数量: " << std::endl;
	int add_num = 0;
	std::cin >> add_num;
	if (add_num <= 0) {
		std::cout << "输入有误！" << std::endl;
		return ;
	}

	//开辟新空间
	int new_size = emp_num_ + add_num;
	Worker **new_space = new Worker*[new_size];

	//拷贝原数据
	if (emp_array_ != NULL) {
		for (int i = 0; i < emp_num_; i++) {
			new_space[i] = emp_array_[i];
		}
	}

	//插入新数据
	for (int i = 0; i < add_num; i++) {
		std::cout << "请输入第 " << i << " 个新职工编号: " << std::endl;
		int id;
		std::cin >> id;

		std::cout << "请输入第 " << i << " 个新职工姓名: " << std::endl;
		std::string name;
		std::cin >> name;

		std::cout << "请输入第 " << i << " 个新职工岗位: " << std::endl;
		std::cout << "1、普通职工" << std::endl;
		std::cout << "2、经理" << std::endl;
		std::cout << "3、老板" << std::endl;
		int d_select;
		std::cin >> d_select;

		Worker *worker = NULL;
		switch (d_select){
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
		}

		new_space[emp_num_ + i] = worker;
	}
	
	//释放原数据空间
	delete [] emp_array_;
	//重新指向新数据
	emp_array_ = new_space;
	//刷新个数
	emp_num_ = new_size;

	if (emp_file_empty_) {
		emp_file_empty_ = false;
	}
	
	std::cout << "成功添加： " << add_num << " 名新员工！" << std::endl;

	Save();
	system("clear");
}

int WorkerManager::GetEmpNum()
{
	std::ifstream ifs;
	ifs.open(FILE_NAME, ios::in);
	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
        //记录人数
		num++;
	}
	ifs.close();

	return num;
}

void WorkerManager::Init()
{
	std::ifstream ifs;
	ifs.open(FILE_NAME, ios::in);
	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
        Worker	*worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		} else if (dId == 2) {
			worker = new Manager(id, name, dId);
		} else {
			worker = new Boss(id, name, dId);
		}
		
		emp_array_[num] = worker;
		num++;
	}
	ifs.close();
}

void WorkerManager::Show()
{
	if (emp_file_empty_) {
		std::cout << "文件不存在或者为空！" << std::endl;
		return ;
	}

	for (int i = 0; i < emp_num_; i++) {
		emp_array_[i]->ShowInfo();
	}
}

int WorkerManager::IsExit(int id)
{
	//bool exit_flag = false;
	int index = -1;
	for (int i = 0; i < emp_num_; i++) {
		if (emp_array_[i]->id_ == id) {
			index = i;
		}
	}
	
	return index;
}

int WorkerManager::IsExit(std::string name)
{
	int index = -1;
	for (int i = 0; i < emp_num_; i++) {
		if (emp_array_[i]->name_ == name) {
			index = i;
		}
	}
	return index;
}

void WorkerManager::DelEmp()
{
	if (emp_file_empty_) {
		std::cout << "文件不存在或记录为空!" << std::endl;
		return ;
	}
	
	std::cout << "请输入想要删除的职工号：" << std::endl;
	int id = 0;
	std::cin >> id;
	int index = IsExit(id);
	if (index != -1) {
		for (int i = index; i < emp_num_ - 1; i++) {
			emp_array_[i] = emp_array_[i + 1];
		}
		
		emp_num_--;
		Save();
		std::cout << "删除成功！" << std::endl;
	} else {
		std::cout << "删除失败！" << std::endl;
	}
	system("clear");
}

void WorkerManager::ModEmp()
{
	if (emp_file_empty_) {
		std::cout << "文件不存在或记录为空!" << std::endl;
		return ;
	}
	
	std::cout << "请输入想要修改的职工号：" << std::endl;
	int id = 0;
	std::cin >> id;
	int index = IsExit(id);
	if (index != -1) {

		delete emp_array_[index];

		std::cout << "查到: " << id << "号职工." << std::endl;
		std::cout << "请输入修改职工编号: " << std::endl;
		int id;
		std::cin >> id;

		std::cout << "请输入修改职工姓名: " << std::endl;
		std::string name;
		std::cin >> name;

		std::cout << "请输入修改职工岗位: " << std::endl;
		std::cout << "1、普通职工" << std::endl;
		std::cout << "2、经理" << std::endl;
		std::cout << "3、老板" << std::endl;

		int d_select;
		std::cin >> d_select;

		Worker *worker = NULL;
		switch (d_select) {
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
		}

		emp_array_[index] = worker;
		std::cout << "修改成功" << std::endl;
		Save();
	} else {
		std::cout << "修改失败，查无此人" << std::endl;
	}
	system("clear");
}

void WorkerManager::FindEmp()
{
	if (emp_file_empty_) {
		std::cout << "文件不存在或记录为空!" << std::endl;
		return ;
	}

	std::cout << "请输入查找方式： " << std::endl;
	std::cout << "1、按职工编号查找" << std::endl;
	std::cout << "2、按姓名查找" << std::endl;
	
	int select = 0;
	std::cin >> select;
	if (select == 1) {
		std::cout << "请输入查找的员工编号： " << std::endl;
		int id;
		std::cin >> id;
		int index = IsExit(id);
		if (index == -1) {
			std::cout << "查无此人!" << std::endl;
			return ;
		}
		
		emp_array_[index]->ShowInfo();
	} else if (select == 2) {
		std::cout << "请输入查找的员工姓名： " << std::endl;
		std::string name;
		std::cin >> name;
		int index = IsExit(name);
		if (index == -1) {
			std::cout << "查无此人!" << std::endl;
			return ;
		}
		
		emp_array_[index]->ShowInfo();
	} else {
		std::cout << "输入有误!" << std::endl;
	}
	//system("clear");
}

void WorkerManager::CleanFile()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILE_NAME, ios::trunc);
		ofs.close();

		if (emp_array_ != NULL) {
			for (int i = 0; i < emp_num_; i++) {
				if (emp_array_[i] != NULL) {
					delete emp_array_[i];
					emp_array_[i] = NULL;
				}
			}
			
			delete [] emp_array_;
			emp_array_ = NULL;
			emp_num_ = 0;
			emp_file_empty_ = true;
		}
	
		cout << "清空成功！" << endl;
	}
}