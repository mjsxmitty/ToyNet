
#include <string>
#include <iostream>

#include "gz_boss.h"

using namespace std;

GZBoss::GZBoss(int id, const string &name, int did)
{
    id_ = id;
    name_ = name;
    dept_id_ = did;
}

void GZBoss::ShowInfo()
{
	cout << "职工编号 : " << this->id_
		<< " \t职工姓名 : " << this->name_
		<< " \t岗位 : " << this->GetDeptName()
		<< " \t岗位职责 : 管理公司所有事物"
        << endl;
}

string GZBoss::GetDeptName() { return string("总裁"); }