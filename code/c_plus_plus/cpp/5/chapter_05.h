
#ifndef __CPP_CHAPTER_05_H__
#define __CPP_CHAPTER_05_H__

#include <exception>
#include <string>

using namespace std;

namespace chapter_05
{

void Test1();
void Test2();

void out_put_log(const char *format, ...);

void Test3();
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

void Test4();

class Hello
{
public:
    Hello() {}
};

}

#endif //
