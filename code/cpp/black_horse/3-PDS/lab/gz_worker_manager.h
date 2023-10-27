
#ifndef __BLOCK_HORSE_PDS_WORKER_MANAGER_H__
#define __BLOCK_HORSE_PDS_WORKER_MANAGER_H__

#include "gz_worker.h"

class GZWorkerManager
{
public:
    GZWorkerManager();
    ~GZWorkerManager();
public:
    void ShowMenu();

    void ExitSystem();

    void AddEmp();

    void ShowEmp();

    void DelEmp();

    void ModEmp();

    void FindEmp();

    void SortEmp();

    void CleanFile();
private:
    void Save();

    int GetEmpNum();

    void InitEmp();

    int IsExist(int id);

    int IsExist(std::string name);
private:
    int         emp_num_;
    GZworker    **emp_array_;
    bool        file_is_empty = true;
};





#endif //__BLOCK_HORSE_PDS_WORKER_MANAGER_H__
