
#ifndef __WORKER_H__
#define __WORKER_H__

#include <string>

class Worker
{
public:
    virtual void ShowInfo() const = 0;
    virtual std::string GetDeptName() const = 0;
public:
    int             id_;
    std::string     name_;
    int             dept_id_;   //部门编号
};


#endif //__WORKER_H__
