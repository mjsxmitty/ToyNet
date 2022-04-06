

#ifndef __HUAWEI_CHAPTER_08_POLYMORPHISM_STORY_H__
#define __HUAWEI_CHAPTER_08_POLYMORPHISM_STORY_H__

#include <string>

class Reader
{
public:
    virtual std::string GetContent() = 0;
};

class Book : public Reader
{
public:
    std::string GetContent();
};

class Newspaper : public Reader
{
public:
    std::string GetContent();
};


class Person
{
public:
    void TellStory(Reader *r);
};
#endif // __HUAWEI_CHAPTER_08_POLYMORPHISM_STORY_H__
