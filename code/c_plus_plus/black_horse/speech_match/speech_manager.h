
#ifndef __SPEECH_MANAGER_H__
#define __SPEECH_MANAGER_H__

#include <vector>
#include <map>

#include "speaker.h"



class SpeechManager
{
public:
    SpeechManager(/* args */);
    ~SpeechManager();
public:
    void ShowMenu();
    void ExitSysterm();
    void StartSpeech();
    void ShowRecord();
    void ClearRecord();
private:
    void Init();
    void CreateSpeaker();
    void SpeechDraw();
    void SpeechContest();
    void ShowScore();
    void SaveRecord();
    void LoadRecord();
public:
    int                 index_;
    std::vector<int>    v1_;
    std::vector<int>    v2_;

    std::vector<int>        vectry_;
    std::map<int, Speaker>  speaker_;

    bool                        file_is_empty_;
    std::map<int, std::vector<std::string>>    record_;
};




#endif

