

#include "gz_query_result.h"

using namespace std;

ostream &PrintQueryResult(ostream &os, const QueryResult &result)
{
    os << result.sought_word_ << " occurs: " << result.lines_->size()
       << (result.lines_->size() > 1 ? " times" : "time") << endl;

    //已经处理了lines_为0的情况
    for (const auto &num : *result.lines_)
        cout << "\nline number: " << num + 1 << " : "
             << *(result.file_->Begin() + num) << endl;
    return os;
}
