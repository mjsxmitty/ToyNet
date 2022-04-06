

#include "boss.h"

#include <iostream>

Boss::Boss(int id, std::string name, int did)
{
    id_ = id;
    name_ = name;
    dept_id_ = did;
}

std::string Boss::GetDeptName() const
{
    return std::string("老板");
}

void Boss::ShowInfo() const 
{
    std::cout << "员工编号： " << id_
                << "\t职工姓名： " << name_
                << "\t岗位： " << GetDeptName()
                << "\t岗位职责： 管理公司所有事物."
                << std::endl;
}

