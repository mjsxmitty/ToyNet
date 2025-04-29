#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> integers;
    cout << "Enter integers (Ctrl+D to end): ";

    // 输入整数集合
    int x;
    while (cin >> x) 
    {
        integers.push_back(x);
    }

    // 检查空输入
    if (integers.empty()) 
    {
        cout << "No integers entered!" << endl;
        return 1;
    }

    // 降序排序
    sort(integers.rbegin(), integers.rend());

    // 计算每部分大小
    typedef vector<int>::size_type vec_sz;
    vec_sz size = integers.size();
    vec_sz part_size = (size + 3) / 4;  // 向上取整 ((size + k - 1) / k : k为分组数)

    // 分割并输出4部分
    for (vec_sz i = 0; i < 4; ++i)
    {
        vec_sz start = i * part_size;
        vec_sz end = min(start + part_size, size);

        cout << "Part " << i + 1 << ": ";
        for (vec_sz j = start; j < end; ++j) {
            cout << integers[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
