
/**
 * 异常和反射
 */

#ifndef __CPP_CH_5_HPP__
#define __CPP_CH_5_HPP__

#include <stdio.h>
#include <iostream>

#include "chapter_05.h"

using namespace std;

namespace chapter_05
{

void ch_5()
{
    /* 认识CPP异常 */
    {
        int i = 1024;
        try
        {
            if (i == 1024)
                throw "i = 1024";
        } catch (const char *s) {
            printf("exception info : %s\n", s);
        }
    }

    /* 封装任意参数打印 */
    {
        out_put_log("hhh %s", "nihao");
        out_put_log("hello %d-%d", 1024, 0);
    }

    /* 自定义异常类 */
    {
        int i = 1024;
        try
        {
            if (i == 1024)
                throw Exception("out range");
        } catch (const char *s) {
            printf("exception info : %s\n", s);
        }
        catch(const Exception &e) {
            cout << e.what() << endl;
            e.Hello();
        }
    }

    /* typeid获取类型反射信号 */
    {
        int     i = 1024;
        double  d = 3.14;

        const type_info &info = typeid(i);
        cout << "name: " << info.name()
             << ", hash: " << info.hash_code()
             << endl;

        const type_info &info1 = typeid(d);
        cout << "name: " << info1.name()
             << ", hash: " << info1.hash_code()
             << endl;

        Exception *e = new Exception("test");
        const type_info &info2 = typeid(*e);
        cout << "name: " << info2.name()
             << ", hash: " << info2.hash_code()
             << endl;

        const type_info &info3 = typeid(i * d);
        cout << "name: " << info3.name()
             << ", hash: " << info3.hash_code()
             << endl;
    }
}

}

#endif //
