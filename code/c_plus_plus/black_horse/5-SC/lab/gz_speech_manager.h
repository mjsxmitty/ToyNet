
#ifndef __GZ_SPEECH_MANAGER_H__
#define __GZ_SPEECH_MANAGER_H__

#include <map>
#include <string>
#include <vector>

class GZSpeaker
{
public:
    std::string     name_;      //姓名
    double          score_[2];  //分数  最多有两轮得分
};

class GZSpeechManager
{
public:
    GZSpeechManager();
public:
    void ShowMenu();

    void ExitSystem();
private:
    void InitSpeech();

    void CreateSpeaker();
private:
    std::vector<int>            v1_;        // 第一轮

    std::vector<int>            v2_;        // 第二轮

    std::vector<int>            victory_;   // 第三轮

    std::map<int, GZSpeaker>    speaker_;
};

#endif // __GZ_SPEECH_MANAGER_H__
