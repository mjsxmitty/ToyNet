
#ifndef __BLOCK_HORSE_PDS_EMPLOYEE_H__
#define __BLOCK_HORSE_PDS_EMPLOYEE_H__

#include <string>
#include "gz_worker.h"

class GZEmployee : public GZworker
{
public:
    GZEmployee(int id, const std::string &name, int did);
public:
    virtual void ShowInfo();
    virtual std::string GetDeptName();
};

#endif //