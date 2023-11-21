
#ifndef __EFFECTIVE_CPP_ITEM_09_H__
#define __EFFECTIVE_CPP_ITEM_09_H__

#include <string>

void Item09();

namespace effective_item_09 {

class Transcation
{
public:
    explicit Transcation(const std::string &s);
    void LogTranscation2(const std::string &s) const;

    Transcation();

    void Init()
    {
        LogTranscation();
    }
    virtual void LogTranscation();
};

class BuyTranscation : public Transcation
{
public:
    void LogTranscation();

    BuyTranscation();
private:
    static std::string CreateLogString()
    {
        return "create log string";
    }
};

}

#endif // __EFFECTIVE_CPP_ITEM_09_H__
