

#ifndef __MY_STRING_H__
#define __MY_STRING_H__

class String
{
private:
    char    *m_data;
public:
    String(const char *str = 0);
    String(const String &str);
    String& operator=(const String &str);
    ~String();
public:
    char *get_data() const { return m_data; }
};



#endif //__MY_STRING_H__

