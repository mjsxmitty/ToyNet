

#ifndef __SPEAKER_H__
#define __SPEAKER_H__

#include <string>

class Speaker
{
public:
    Speaker(/* args */);
    ~Speaker();
public:
    std::string     name_;
    double          score_[2];
};





#endif