

#ifndef __WORKER_MANAGER_H__
#define __WORKER_MANAGER_H__

#include "worker.h"


class WorkerManager
{
public:
    WorkerManager(/* args */);
    ~WorkerManager();

public:
    void ShowMenu();
    void ExitSysterm();
    void AddEmployee();
    void Save();
    int GetEmpNum();
    void Init();
    void Show();
    int IsExit(int id);
    void DelEmp();
    void ModEmp();
    void FindEmp();
    int IsExit(std::string name);
    //sort
    void CleanFile();
    
private: 
    int     emp_num_;
    Worker  **emp_array_;
    bool    emp_file_empty_;
};




#endif //__WORKER_MANAGER_H__
