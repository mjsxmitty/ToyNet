
#ifndef __BLOCK_HORSE_PDS_BOSS_H__
#define __BLOCK_HORSE_PDS_BOSS_H__

#include <string>
#include "gz_worker.h"

class GZBoss : public GZworker
{
public:
    GZBoss(int id, const std::string &name, int did);
public:
    virtual void ShowInfo();
    virtual std::string GetDeptName();
};

#endif //