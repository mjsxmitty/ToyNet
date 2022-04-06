

#include "manager.h"

#include <iostream>

Manager::Manager(int id, std::string name, int did)
{
    id_ = id;
    name_ = name;
    dept_id_ = did;
}

std::string Manager::GetDeptName() const
{
    return std::string("经理");
}

void Manager::ShowInfo() const 
{
    std::cout << "员工编号： " << id_
                << "\t职工姓名： " << name_
                << "\t岗位： " << GetDeptName()
                << "\t岗位职责： 完成老板交给的任务,并下发给员工."
                << std::endl;
}

