
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <stdlib.h>
#include <numeric>
#include <fstream>

#include "speech_manager.h"

using namespace std;

SpeechManager::SpeechManager(/* args */)
{
    Init();
    CreateSpeaker();
    LoadRecord();
}

SpeechManager::~SpeechManager()
{
}

void SpeechManager::ShowMenu()
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

void SpeechManager::ExitSysterm()
{
	cout << "欢迎下次使用" << endl;
	//system("pause");
	exit(0);
}

void SpeechManager::Init()
{
    v1_.clear();
    v2_.clear();
    vectry_.clear();
    speaker_.clear();

    index_ = 1;
    record_.clear();
}


void SpeechManager::CreateSpeaker()
{
    std::string name_seed = "ABCDEFGHJJKL";
    for (int i = 0; i < name_seed.size(); i++) {

        std::string name = "选手_";
        name += name_seed[i];

        Speaker sp;
        sp.name_ = name;
        for (int i = 0; i < 2; i++) {
            sp.score_[i] = 0;
        }
        
        v1_.push_back(i + 10001);
        speaker_.insert(make_pair(i + 10001, sp));
    }
    //cout << "v1 size: " << v1_.size() << endl;
}

void SpeechManager::SpeechDraw()
{
	cout << "第 << " << index_ << " >> 轮比赛选手正在抽签"<<endl;
	cout << "---------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;

    if (index_ == 1) {
        random_shuffle(v1_.begin(), v1_.end());
        for (size_t i = 0; i < v1_.size(); i++) {
            cout << v1_[i] << " ";
        }
        cout << endl;
    } else {
        random_shuffle(v2_.begin(), v2_.end());
        for (size_t i = 0; i < v2_.size(); i++) {
            cout << v2_[i] << " ";
        }
        cout << endl;
    }
	cout << "---------------------" << endl;
	//system("pause");
	cout << endl;
}

void SpeechManager::SpeechContest()
{
    cout << "------------- 第 "<< index_ << " 轮正式比赛开始：------------- " << endl;
    
    //获取当前统计的演讲者
    vector<int> temp_vec;
    if (index_ == 1) {
        temp_vec = v1_;
    } else {
        temp_vec = v2_;
    }

    int     num = 0;
    multimap<double, int, greater<int>> group_score;

    //遍历
    for (vector<int>::const_iterator it = temp_vec.begin(); it != temp_vec.end(); it++) {
        
        num++;
        //打分
        deque<int>  score;
        for (int i = 0; i < 10; i++) {
            double temp_score = (rand() % 401 + 600) / 10.f;
            score.push_back(temp_score);
        }
        //找出平均分
        sort(score.begin(), score.end(), greater<double>());
        score.pop_front();
        score.pop_back();

        double sum = accumulate(score.begin(), score.end(), 0.0f);
        double avg = sum / score.size();

        speaker_[*it].score_[index_ - 1] = avg;
        group_score.insert(make_pair(avg, *it));

        if (num % 6 == 0) {
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            for (multimap<double, int, greater<int>>::iterator i = group_score.begin(); i != group_score.end(); i++) {
				cout << "编号: " << i->second << " 姓名： " << speaker_[i->second].name_ << " 成绩： " << speaker_[i->second].score_[index_ - 1] << endl;
            }
            
            int count = 0;
            for (multimap<double, int, greater<int>>::iterator i = group_score.begin(); i != group_score.end() && count < 3; i++, count++) {
                if (index_ == 1) {
                    v2_.push_back((*i).second);
                } else {
                    vectry_.push_back((*i).second);
                }
            }
            group_score.clear();
            cout << endl;
        }
    }
    cout << "------------- 第 " << index_ << " 轮比赛完毕  ------------- " << endl;
}

void SpeechManager::ShowScore()
{
    cout << "---------第 " << index_ << " 轮晋级选手信息如下：-----------" << endl;
    vector<int> temp_vec;
    if (index_ == 1) {
        temp_vec = v2_;
    } else {
        temp_vec = vectry_;
    }

    for (vector<int>::iterator it = temp_vec.begin(); it != temp_vec.end(); it++) {
		cout << "选手编号：" << *it << " 姓名： " << speaker_[*it].name_ << " 得分： " << speaker_[*it].score_[index_ - 1] << endl;
    }
    //system("clear");
    //ShowMenu();
}

void SpeechManager::SaveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);

    for (vector<int>::iterator i = vectry_.begin(); i < vectry_.end(); i++) {
        ofs << *i << "," << speaker_[*i].score_[1] << ",";
    }
    cout << endl;
    
    ofs.close();
    file_is_empty_ = false;
    cout << "记录已经保存" << endl;
}

void SpeechManager::StartSpeech()
{
	//第一轮比赛
	//1、抽签
	SpeechDraw();
	//2、比赛
    SpeechContest();
	//3、显示晋级结果
    ShowScore();
	//第二轮比赛
    index_++;
	//1、抽签
    SpeechDraw();
	//2、比赛
    SpeechContest();
	//3、显示最终结果
    ShowScore();
	//4、保存分数
    SaveRecord();

    Init();
    CreateSpeaker();
    LoadRecord();

    cout << "比赛完毕！" << endl;
}

void SpeechManager::LoadRecord()
{
    ifstream ifs("speech.csv", ios::in);
    if (!ifs.is_open()) {
        file_is_empty_ = true;
        cout << "文件不存在！" << endl;
        ifs.close();
        return ;
    }

    char ch; 
    ifs >> ch;
    if (ifs.eof()) {
        file_is_empty_ = true;
        cout << "文件为空!" << endl;
        ifs.close();
        return ;
    }
    
    file_is_empty_ = false;
    ifs.putback(ch);

    int index = 0;
    string data;
    while (ifs >> data) {
        vector<string> temp_vec;
        int pos = -1;
        int start = 0;
        while (true) {
            pos = data.find(",", start);
            if (pos == -1) {
                break;
            }

            string temp_str = data.substr(start, pos - start);
            temp_vec.push_back(temp_str);
            start = pos + 1;
        }
        record_.insert(make_pair(index_, temp_vec));
        index_++;
    }
    ifs.close();
}

void SpeechManager::ShowRecord()
{
    if (file_is_empty_) {
        cout << "文件不存在或者记录为空！" << endl;
        return ;
    }
    
    for (int i = 0; i < record_.size(); i++) {
		cout << "第" << i + 1 << "届 " <<
			"冠军编号：" << record_[i][0] << " 得分：" << record_[i][1] << " "
			"亚军编号：" << record_[i][2] << " 得分：" << record_[i][3] << " "
			"季军编号：" << record_[i][4] << " 得分：" << record_[i][5] << endl;
    }
    
}

void SpeechManager::ClearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;
    if (select == 1) {
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        Init();
        CreateSpeaker();
        LoadRecord();

        cout << "清空成功！" << endl;
    }
    
}