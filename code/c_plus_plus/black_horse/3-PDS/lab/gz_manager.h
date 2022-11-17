
#ifndef __BLOCK_HORSE_PDS_MANAGER_H__
#define __BLOCK_HORSE_PDS_MANAGER_H__

#include <string>
#include "gz_worker.h"

class GZManager : public GZworker
{
public:
    GZManager(int id, const std::string &name, int did);
public:
    virtual void ShowInfo();
    virtual std::string GetDeptName();
};

#endif //