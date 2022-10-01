

#ifndef __ORDER_FILE_H__
#define __ORDER_FILE_H__

#include <map>
#include <string>

class OrderFile
{
public:
    int size_;
    std::map<int, std::map<std::string, std::string>> order_data_;
public:
    OrderFile(/* args */);
    //~OrderFile();

    void UpdateOrder();


};

#endif //__ORDER_FILE_H__
