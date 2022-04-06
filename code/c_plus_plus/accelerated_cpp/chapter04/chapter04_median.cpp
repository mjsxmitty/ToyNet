
#include <stdexcept>
#include <algorithm>
#include "chapter04_median.h"

using std::sort;
using std::domain_error;
using std::vector;

namespace Chapter04
{
    double Median(std::vector<double> vec)
    {
        typedef vector<double>::size_type vec_sz;

        vec_sz size = vec.size();
        if (size == 0) {
            throw domain_error("median of an empty vector.");
        }
        
        sort(vec.begin(), vec.end());

        vec_sz mid = size / 2;
        return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
    }
} // namespace Chapter04
