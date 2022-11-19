
#include <iostream>
#include <map>
#include "gz_speech_manager.h"

using namespace std;

int main()
{
    srand((unsigned int)time(NULL));

    GZSpeechManager sm;
    int choice = 0; //用来存储用户的选项

    while (true)
    {
        sm.ShowMenu();

        cout << "请输入您的选择： " << endl;
        cin >> choice; // 接受用户的选项

        switch (choice)
        {
            case 1:  //开始比赛
                sm.StartSpeech();
                break;
            case 2:  //查看记录
                sm.ShowRecord();
                break;
            case 3:  //清空记录
                sm.ClearRecord();
                break;
            case 0:  //退出系统
                sm.ExitSystem();
                break;
            default:
                break;
        }
    }

    return 0;
}
