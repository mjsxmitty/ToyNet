
#include <string>
#include <iostream>

#include "gz_employee.h"

using namespace std;

GZEmployee::GZEmployee(int id, const string &name, int did)
{
    id_ = id;
    name_ = name;
    dept_id_ = did;
}

void GZEmployee::ShowInfo()
{
	cout << "职工编号 : " << this->id_
		<< " \t职工姓名 : " << this->name_
		<< " \t岗位 : " << this->GetDeptName()
		<< " \t岗位职责 : 完成经理交给的任务"
        << endl;
}

string GZEmployee::GetDeptName() { return string("员工"); }