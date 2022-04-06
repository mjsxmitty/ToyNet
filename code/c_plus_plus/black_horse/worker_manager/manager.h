

#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "worker.h"

class Manager : public Worker
{
public:
    Manager(int id, std::string name, int did);
    void ShowInfo() const;
    std::string GetDeptName() const;
};

#endif //__MANAGER_H__