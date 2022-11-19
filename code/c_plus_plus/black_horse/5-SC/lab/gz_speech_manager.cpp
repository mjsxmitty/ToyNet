
#include <deque>
#include <numeric>
#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>

#include "utility/Logger.h"
#include "gz_speech_manager.h"

using namespace yazi::utility;
using namespace std;

GZSpeechManager::GZSpeechManager()
{
    Logger::instance()->open("./test.log");
    InitSpeech();

    CreateSpeaker();

    LoadRecord();
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

void GZSpeechManager::StartSpeech()
{
    // 抽签
    SpeechDraw();

    SpeechContest();

    ShowScore();

    index_++;

    SpeechDraw();

    SpeechContest();

    ShowScore();

    SaveRecord();

    InitSpeech();

    CreateSpeaker();

    LoadRecord();
}

void GZSpeechManager::ShowRecord()
{
    if (file_is_empty_)
    {
        cout << "文件不存在,或者记录为空!" << endl;
        return ;
    }
    else
    {
	for (int i = 0; i < recore_.size(); i++)
	{
		cout << "第" << i + 1 << "届 " <<
			"冠军编号：" << recore_[i][0] << " 得分：" << recore_[i][1] << " "
			"亚军编号：" << recore_[i][2] << " 得分：" << recore_[i][3] << " "
			"季军编号：" << recore_[i][4] << " 得分：" << recore_[i][5] << endl;
	}
    }
}

void GZSpeechManager::ClearRecord()
{
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;
    if (select == 1)
    {
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        InitSpeech();

        CreateSpeaker();

        LoadRecord();
    }
}

void GZSpeechManager::InitSpeech()
{
    v1_.clear();
    v2_.clear();
    victory_.clear();
    speaker_.clear();
    recore_.clear();
    index_ = 1;
}

void GZSpeechManager::CreateSpeaker()
{
    string name_seed = "ABCDEFGHIJKL";

    for (int i = 0; i != name_seed.size(); ++i)
    {
        string name = "speaker.";
        name += name_seed[i];

        GZSpeaker sp;
        sp.name_ = name;
        for (int j = 0; j != 2; ++j)
            sp.score_[j] = 0;

        v1_.push_back(i + 10001);
        speaker_.insert(make_pair(i + 10001, sp));
    }
}

void GZSpeechManager::SpeechDraw()
{
	cout << "第 << " << index_ << " >> 轮比赛选手正在抽签"<<endl;
	cout << "---------------------" << endl;
    cout << "抽签后演讲顺序如下：" << endl;

    if (index_ == 1)
    {
        random_shuffle(v1_.begin(), v1_.end());
        for_each(v1_.begin(), v1_.end(), [](int i) { cout << i << " "; });
        cout << endl;
    }
    else
    {
        random_shuffle(v2_.begin(), v2_.end());
        for_each(v2_.begin(), v2_.end(), [](int i) { cout << i << " "; });
        cout << endl;
    }
}

void GZSpeechManager::SpeechContest()
{
    cout << "------------- 第" << index_ << "轮正式比赛开始：------------- " << endl;

    int num = 0;
    multimap<double, int, greater<int>> group_score;
    vector<int> ivec = (index_ == 1 ? v1_ : v2_);

    for (auto it = ivec.begin(); it != ivec.end(); ++it)
    {
        num++;
        deque<double> d;
        for (int i = 0; i != 10; ++i)
            d.push_back((rand() % 401 + 600) / 10.f);

        sort(d.begin(), d.end());
        d.pop_front();
        d.pop_back();

        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double avg = sum / d.size();

        speaker_[*it].score_[index_ - 1] = avg;
        group_score.insert(make_pair(avg, *it));

        if (num % 6 == 0)
        {
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            for (const auto &p : group_score)
            {
                cout << "编号: " << p.second
                     << " 姓名： " << speaker_[p.second].name_
                     << " 成绩： " << speaker_[p.second].score_[index_ - 1]
                     << endl;
            }

            int count = 0;
            for (multimap<double, int, greater<>>::const_iterator cit = group_score.cbegin();
                 cit != group_score.end() && count < 3; ++cit, ++count)
            {
                if (index_ == 1)
                    v2_.push_back((*cit).second);
                else
                    victory_.push_back((*cit).second);
            }
            group_score.clear();
            cout << endl;
            //cout << "v1 size: " << v1_.size() << ", v2 size: " << v2_.size() << endl;
        }
    }

    cout << "------------- 第" << index_ << "轮比赛完毕  ------------- " << endl;
}

void GZSpeechManager::ShowScore()
{
    cout << "---------第" << index_ << "轮晋级选手信息如下：-----------" << endl;
    vector<int> v = ((index_ == 1) ? v2_ : victory_);
    for (vector<int>::iterator cit = v.begin(); cit != v.end(); cit++)
    {
        cout << "选手编号：" << *cit
             << " 姓名： " << speaker_[*cit].name_
             << " 得分： " << speaker_[*cit].score_[index_ - 1]
             << endl;
    }
}

void GZSpeechManager::SaveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);

    for (auto it = victory_.begin(); it != victory_.end(); ++it)
    {
        ofs << *it << "," << speaker_[*it].score_[1] << ",";
    }
    ofs << endl;
    ofs.close();

    cout << "记录已经保存!" << endl;
    file_is_empty_ = false;
}

void GZSpeechManager::LoadRecord()
{
    ifstream ifs("speech.csv", ios::in); //输入流对象 读取文件
    if (!ifs.is_open())
    {
        file_is_empty_ = true;
        cout << "文件不存在！" << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空!" << endl;
        file_is_empty_ = true;
        ifs.close();
        return;
    }

    ifs.putback(ch);
    file_is_empty_ = false;

    int index = 0;
    string data;
    while (ifs >> data)
    {
        vector<string>  v;

        int pos = -1;
        int start = 0;
        while (true)
        {
            pos = data.find(",", start);
            if (pos == -1) break;

            string tmp = data.substr(start,pos - start);
            v.push_back(tmp);

            start = pos + 1;
        }
        
        recore_.insert(make_pair(index, v));
        index++;
    }
    debug("index = %d\n", index);
}
