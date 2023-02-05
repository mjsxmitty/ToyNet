
#ifndef __CPP_CHAPTER_05_H__
#define __CPP_CHAPTER_05_H__

#include <exception>
#include <string>

using namespace std;

namespace chapter_05
{

void out_put_log(const char *format, ...);

class Exception : public exception
{
public:
    Exception(const char *s) : info_(s) {}

    const char* what() const throw()
    {
        out_put_log("%s", info_.c_str());
    }

    void Hello() const
    {
        printf("hello\n");
    }
private:
    string info_;
};

class Hello
{
public:
    Hello() {}
};

}

#endif //
