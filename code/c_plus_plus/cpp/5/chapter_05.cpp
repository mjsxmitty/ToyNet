

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <iostream>

#include "chapter_05.h"

using namespace std;

namespace chapter_05
{

void Test1()
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

void out_put_log(const char *format, ...)
{
    char buff[1024] = {0};
    va_list in_args;
    va_start(in_args, format);
    vsnprintf(buff, sizeof(buff) - 1, format, in_args);
    va_end(in_args);

    cout << buff << endl;
}

void Test2()
{
    out_put_log("hhh %s", "nihao");
    out_put_log("hello %d-%d", 1024, 0);
}

void Test3()
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

void Test4()
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
