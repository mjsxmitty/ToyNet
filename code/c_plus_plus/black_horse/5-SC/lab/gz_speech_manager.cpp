
#include <iostream>
#include "gz_speech_manager.h"

using namespace std;

GZSpeechManager::GZSpeechManager()
{

}

void GZSpeechManager::ShowMenu()
{
    cout << "********************************************" << endl;
    cout << "*************  欢迎参加演讲比赛 ************" << endl;
    cout << "*************  1.开始演讲比赛  *************" << endl;
    cout << "*************  2.查看往届记录  *************" << endl;
    cout << "*************  3.清空比赛记录  *************" << endl;
    cout << "*************  0.退出比赛程序  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void GZSpeechManager::ExitSystem()
{
    cout << "欢迎下次使用!" << endl;
    exit(0);
}

void GZSpeechManager::InitSpeech()
{
    v1_.clear();
    v2_.clear();
    victory_.clear();
    speaker_.clear();
}

void GZSpeechManager::CreateSpeaker()
{
    string name_seed = "ABCDEFGHIJKL";

    for (int i = 0; i != name_seed.size(); ++i)
    {
        string name = "speaker - ";
        name += name_seed[i];

        GZSpeaker sp;
        sp.name_ = name;
        for (int j = 0; j != 2; ++j)
            sp.score_[j] = 0;

        v1_.push_back(i + 10001);
        speaker_.insert(make_pair(i + 10001, sp));
    }
}
