#ifndef SALEMANAGER_H
#define SALEMANAGER_H

#include "salesman.h"
#include "manager.h"

class SaleManager : public SalesMan, public Manager
{
public:
    SaleManager();
    ~SaleManager();
public:
    void promote(int increment = 0);
    void getPay();
    void disInfor();
};

#endif // SALEMANAGER_H
