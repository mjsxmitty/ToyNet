
#include <string>
#include <iostream>

#include "gz_manager.h"

using namespace std;

GZManager::GZManager(int id, const string &name, int did)
{
    id_ = id;
    name_ = name;
    dept_id_ = did;
}

void GZManager::ShowInfo()
{
	cout << "职工编号 : " << this->id_
		<< " \t职工姓名 : " << this->name_
		<< " \t岗位 : " << this->GetDeptName()
		<< " \t岗位职责 : 完成总裁交给的任务"
        << endl;
}

string GZManager::GetDeptName() { return string("经理"); }