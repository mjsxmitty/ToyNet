
#include <iostream>
#include <vector>
#include "common.h"

using namespace chapter_02;

int main()
{
    int ia[8] = { 8, 34, 3, 13, 1, 21, 5, 2 };
    std::vector<int> vec(ia, ia + 8);
#if 0
    Display(vec);
    BubbleSort(vec, NULL);     // 0->避免二义性
    Display(vec);
#endif
#if 1
    std::ofstream out("out.txt");
    Display(vec, out);
    BubbleSort(vec, out);
    Display(vec, out);
#endif
    return 0;
}
