

#include <iostream>

// class MyClass
// {
// public:
//     void ShowClassName() {
//         std::cout << " My Class " << std::endl;
//     }

//     void ShowClassNum(){
//         if (this == NULL){
//             return ;
//         }
//         std::cout << "num: " << m_int << std::endl;
//     }
// private:
//     int m_int = 100;
// };

// void testClass(){
//     MyClass *p = NULL;
//     p->ShowClassName();
//     p->ShowClassNum();
// }

#include <vector>
using namespace std;
struct Range
{
    int start = 0;  // 开始位置(索引)
    int end = 0;    // 结束位置(索引)
};

struct Item
{
    int num = 0;
    Range range;
};


struct Part
{
    int num = 0;    // 编号
    int size = 0;   // 大小
};

bool Common(const vector<Part> &parts, int start, int end, vector<Item> &out)
{
    int total_size = 0;
    int left = 0, right = 0;

    for (size_t i = 0; i < parts.size(); i++)
    {
        left = total_size ? total_size : 0;
        right = left + parts[i].size - 1;

        if (right < start || left > end) 
        {
            total_size += parts[i].size;
            continue;
        }

        Item item;
        item.num = parts[i].num;
        if (right >= start && right <= end)
        {
            item.range.end = parts[i].size - 1;
            if (left < start)
            {
                item.range.start = start - left;
            }
            else
            {
                item.range.start = 0;
            }
        }
        else
        {
            item.range.end = end - left;
            if (left <= end && left >= start)
            {
                item.range.start = 0;
            }
            else
            {
                item.range.start = start - left;
            }
        }

        out.push_back(item);
        total_size += parts[i].size;
    }

    return true;
}

bool Common(int left, int right, int start, int end, Range &range)
{
    if (right < start || left > end)
    {
        return false;
    }

    // 以righ为基准判断left
    if (right >= start && right <= end)
    {
        range.end = right;
        if (left < start)
        {
            range.start = start;
        }
        else
        {
            range.start = left;
        }
    }
    else // right > end
    {
        range.end = end;
        if (left >= start && left <= end)
        {
            range.start = left;
        }
        else
        {
            range.start = start;
        }
    }
    return true;
}

int main()
{
    Part p1, p2, p3;
    p1.num = 1;
    p1.size = 6;

    p2.num = 2;
    p2.size = 6;

    p3.num = 3;
    p3.size = 6;

    int start = 0;
    int end = 0;

    vector<Part> parts;
    parts.push_back(p1);
    parts.push_back(p2);
    parts.push_back(p3);

    cout << "please enter a start: ";
    cin >> start;
    cout << "please enter a end: ";
    cin >> end;
    cout <<"[" << start << ", " << end <<"]" << endl;

    vector<Item> out;
    if (Common(parts, start, end, out))
    {
        for (size_t i = 0; i < out.size(); i++)
        {
            cout << out[i].num << "->" << out[i].range.start << ", " << out[i].range.end << endl;
        }
    }

    // int left = 16;
    // int right = 41;

    // cout << "start ..." << endl;
    // Range range;
    // if (Common(left, right, start, end, range))
    // {
    //     cout << range.start << ", " << range.end << endl;
    // }
    return 0;
}
