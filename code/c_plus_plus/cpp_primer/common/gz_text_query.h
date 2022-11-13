

#ifndef __CPP_PRIMER_CHAPTER_12_TEXT_QUERY_H__
#define __CPP_PRIMER_CHAPTER_12_TEXT_QUERY_H__

#include <fstream>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include <map>

#include "../common/gz_str_blob.h"
#include "../common/gz_str_vec.h"

class QueryResult;
class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;
public:
    TextQuery(std::ifstream &in);
    QueryResult Query(const std::string &s) const;

    std::string CleanupStr(const std::string &s);
private:
    std::map<std::string, std::shared_ptr<std::set<line_no>>>   wm_;
    //std::shared_ptr<std::vector<std::string>>   file_;  // 下标就是行号
    //GZStrBlob       file_;
    std::shared_ptr<GZStrVec> file_;                    // 文件内容与结果类公用
};

#endif // __CPP_PRIMER_CHAPTER_12_TEXT_QUERY_H__
