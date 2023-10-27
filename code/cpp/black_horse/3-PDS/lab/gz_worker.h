
#ifndef __BLOCK_HORSE_PDS_WORKER_H__
#define __BLOCK_HORSE_PDS_WORKER_H__

#include <string>

class GZworker
{
public:
    virtual void ShowInfo() = 0;
    virtual std::string GetDeptName() = 0;
public:
    int         id_;
    std::string name_;
    int         dept_id_;
};

#endif //