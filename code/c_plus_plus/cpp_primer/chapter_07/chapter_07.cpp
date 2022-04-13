
#include <string>

#include "chapter_07.h"
#include "../lib_util/account.h"
#include "../lib_util/sales_data.h"

using namespace std;

void Chapter_07()
{
    //Homework_7_11();
    //Practice_7_6();
    Homework_7_58();
}

void Homework_7_11()
{
    SalesData s1;
    SalesData s2("gao");
    SalesData s3("gao", 1, 3.3);
    SalesData s4(cin);
}

void Xxx::k() { return f();}
Xxx::Xxx() {f();}

NoDefault no(1);
C cc;
C ccc(10);
//B bbb;

/* 7-5-4 类型的隐式转换 */
void Practice_7_5_4()
{
    string null_book = "1-11-111-22";
    SalesData item;
    //item.Combine(null_book);                  //-->1

    //只允许一步转换
    //item.Combine("2-22-11-1111");
    //item.Combine(string("1-11-1111-222"));    //-->2
    item.Combine(SalesData("111-222-111"));     //-->3
    //item.Combine(cin);                        //-->4
    //SalesData item2 = string("1111");         //-->5

    //加上explicit之后，抑制隐式转换，1，2，4,5不成立
    //explicit只可以在函数声明处，单一参数的构造函数
    //此时必须 显示调用转换函数（显示调用构造函数）
    item.Combine(static_cast<SalesData>(cin));
    item.Combine(static_cast<SalesData>(null_book));
}

void Practice_7_6()
{
    //使用静态成员
    double r = Account::Rate();

    Account::Rate(5);

    Account ac1;
    Account *ac2 = &ac1;
    r = ac1.Rate();
    r = ac2->Rate();
    cout << "interest rate: " << r << endl;
}


constexpr double Example::rate;
const int Example::vec_size;
const std::vector<int> Example::ivec(20);
//constexpr ???

void Homework_7_58()
{
    cout << Example::rate << ", " << Example::vec_size << endl;
}
