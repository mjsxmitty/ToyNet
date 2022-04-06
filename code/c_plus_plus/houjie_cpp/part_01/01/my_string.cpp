
#include <iostream>
#include <string.h>
#include "my_string.h"

//参数在实现文件中不可以具有默认值
String::String(const char *cstr)
{
    if (cstr) {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    } else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

String::String(const String &str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

String& String::operator=(const String &str)
{
    //检测自赋值
    if (this == &str) 
        return *this;

    delete [] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

String::~String()
{
    delete [] m_data;
}

std::ostream& operator<<(std::ostream &os, const String &str)
{
    os << str.get_data();
    return os;
}