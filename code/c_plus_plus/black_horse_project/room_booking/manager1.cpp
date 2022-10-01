

#include "global.hpp"
#include "manager1.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;
// Manager::Manager(/* args */)
// {
// }

// Manager::~Manager()
// {
// }

Manager1::Manager1(string name, string pwd) 
{
    name_ = name;
    passwd_ = pwd;

	InitVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom cr;
	while (ifs >> cr.id_ && ifs >> cr.max_num_) {
		computers_.push_back(cr);
	}
	//cout << "当前机房数量为： " << computers_.size() << endl;
	ifs.close();
}

void Manager1::OperateMenu()
{
	cout << "欢迎管理员："<< name_ << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Manager1::AddPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string tip;
	string err_tip;
	string file_name;

	int select = 0;
	cin >> select;
	if (select == 1) {
		file_name == STUDENT_FILE;
		tip = "请输入学号： ";
		err_tip = "学号重复，请重新输入";
	} else {
		file_name = TEACHER_FILE;
		tip = "请输入职工编号：";
		err_tip= "职工号重复，请重新输入";
	}
	

	ofstream ofs;
	ofs.open(file_name, ios::in | ios::app);

	cout << tip << endl;
	int id;
	
	while (true) {
		cin >> id;
		bool ret = CheckRepeat(id, 1);
		if (ret) {
			cout << err_tip << endl;
		} else {
			break;
		}
	}
	

	string name;
	cout << "请输入姓名： " << endl;
	cin >> name;

	string pwd;
	cout << "请输入密码： " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功" << endl;

	ofs.close();

	//每次添加之后及时更新内存的数据
	InitVector();
}

void Manager1::InitVector()
{
	students_.clear();
	teachers_.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	
	Student stu;
	while (ifs >> stu.id && ifs >> stu.name_ && ifs >> stu.passwd_) {
		students_.push_back(stu);
	}
	cout << "当前学生数量为： " << students_.size() << endl;
	ifs.close();
	
	//ifstream ifs;
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	
	Teacher tea;
	while (ifs >> tea.id && ifs >> tea.name_ && ifs >> tea.passwd_) {
		teachers_.push_back(tea);
	}
	cout << "当前老师数量为： " << teachers_.size() << endl;
	ifs.close();
}

bool Manager1::CheckRepeat(int id, int type)
{
	if (type == 1) {
		for (vector<Student>::iterator i = students_.begin(); i != students_.end(); i++) {
			if (id == i->id) {
				return true;
			}
		}
	} else {
		for (vector<Teacher>::iterator i = teachers_.begin(); i != teachers_.end(); i++) {
			if (id == i->id) {
				return true;
			}
		}
	}

	return false;
}

void PrintStudent(const Student &s)
{
	cout << "学号： " << s.id << " 姓名： " << s.name_ << " 密码：" << s.passwd_ << endl;
}
void PrintTeacher(const Teacher &t)
{
	cout << "职工号： " << t.id << " 姓名： " << t.name_ << " 密码：" << t.passwd_ << endl;
}

void Manager1::ShowPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		for_each(students_.begin(), students_.end(), PrintStudent);
	} else {
		for_each(teachers_.begin(), teachers_.end(), PrintTeacher);
	}
}

void Manager1::ShowComputer()
{
	cout << "机房信息如下： " << endl;
	for (vector<ComputerRoom>::const_iterator i = computers_.begin(); i != computers_.end(); i++) {
		cout << "机房编号： " << i->id_ << " 机房最大容量： " << i->max_num_ << endl;
	}
}

void Manager1::CleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功！" << endl;
}