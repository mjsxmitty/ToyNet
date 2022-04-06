
#include <iostream>
#include "employee.h"

Employee::Employee(int id, std::string name, int did)
{
    id_ = id;
    name_ = name;
    dept_id_ = did;
}

std::string Employee::GetDeptName() const
{
    return std::string("员工");
}

void Employee::ShowInfo() const 
{
    std::cout << "员工编号： " << id_
                << "\t职工姓名： " << name_
                << "\t岗位： " << GetDeptName()
                << "\t岗位职责： 完成经理交给的任务。"
                << std::endl;
}

