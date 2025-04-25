
#include <iostream>
#include <vector>
#include <algorithm>

#include "chapter_04.h"
#include "triangular.h"
#include "triangular_iterator.h"
#include "num_sequence.h"
#include "user_profile.h"

using namespace std;

namespace chapter_04
{

int CountLessThan(const vector<int> &vec, int comp)
{
    LessThan lt(comp);
    int count = 0;

    for (size_t ix = 0; ix < vec.size(); ++ix)
        if (lt(vec[ix]))
            ++count;

    return count;
}

int SumLessThan(const std::vector<int> &vec, int comp)
{
    LessThan lt(comp);

    int sum = 0;
    for (size_t i = 0; i < vec.size(); i++)
        if (lt(vec[i]))
            sum += vec[i];

    return sum;
}

void PrintLessThan(const vector<int> &vec, int comp, ostream &os)
{
    LessThan lt(comp);

    auto it = vec.begin(), it_end = vec.end();
    while ((it = find_if(it, it_end, lt)) != it_end)
    {
        os << *it << ' ';
        ++it;
    }
}


void hw_4_4()
{

}

}
