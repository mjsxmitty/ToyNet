

#include "gz_text_query.h"
#include "gz_query_result.h"

#include <sstream>

using namespace std;

//TextQuery::TextQuery(ifstream &in) : file_(new vector<string>)
TextQuery::TextQuery(ifstream &in) : file_(new StrVec)
{
    string text;
    while (getline(in, text))
    {
        //file_->push_back(text);
        file_->PushBack(text);
        //int curr_line_num = file_->size() - 1;  //下标-->行号
        int curr_line_num = file_->Size() - 1;
        
        istringstream line(text);
        string word;
        while (line >> word)
        {
            auto &lines = wm_[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(curr_line_num);
        }
    }
}

QueryResult TextQuery::Query(const string &s) const
{
    static shared_ptr<set<line_no>> no_data(new set<line_no>);
    auto loc = wm_.find(s);
    if (loc == wm_.end())
        return QueryResult(s, no_data, file_);
    else
        return QueryResult(s, loc->second, file_);
}

