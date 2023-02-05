

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <iostream>

#include "chapter_05.h"

using namespace std;

namespace chapter_05
{
void out_put_log(const char *format, ...)
{
    char buff[1024] = {0};
    va_list in_args;
    va_start(in_args, format);
    vsnprintf(buff, sizeof(buff) - 1, format, in_args);
    va_end(in_args);

    cout << buff << endl;
}
}
