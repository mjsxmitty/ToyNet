

#ifndef __CPP_PRIMER_CHAPTER_12_TEXT_QUERY_H__
#define __CPP_PRIMER_CHAPTER_12_TEXT_QUERY_H__

#include <fstream>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include <map>

#include "../chapter_13/str_vec.h"


class QueryResult;
class TextQuery
{
    using line_no = std::vector<std::string>::size_type;
public:
    TextQuery(std::ifstream &in);
    QueryResult Query(const std::string &s) const;
private:
    //std::shared_ptr<std::vector<std::string>>   file_;      //下标就是行号
    std::shared_ptr<StrVec> file_;
    std::map<std::string, std::shared_ptr<std::set<line_no>>>   wm_;
};

#endif // __CPP_PRIMER_CHAPTER_12_TEXT_QUERY_H__
