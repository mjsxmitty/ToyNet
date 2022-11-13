
#ifndef __CPP_PRIMER_CHAPTER_12_STR_BLOB_H__
#define __CPP_PRIMER_CHAPTER_12_STR_BLOB_H__

#include <string>
#include <memory>
#include <vector>
#include <utility>

class GZStrBlobPtr;
class GZStrBlob
{
    friend class GZStrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
public:
    GZStrBlob();
    GZStrBlob(const std::initializer_list<std::string> &il);
    GZStrBlob(std::vector<std::string> *p);
    GZStrBlob(const GZStrBlob &rhs);
    GZStrBlob& operator=(const GZStrBlob &rhs);
public:
    size_type   Size() const { return data_->size(); }
    bool        Empty() const { return data_->empty(); }
    void        PushBack(const std::string &t) { data_->push_back(t); }
    void        PushBack(std::string &&t) { data_->push_back(std::move(t)); }
    void        PopBack();

    std::string& Front();
    std::string& Back();
    const std::string& Front() const;
    const std::string& Back() const;
public:
    GZStrBlobPtr Begin();
    GZStrBlobPtr End();
    GZStrBlobPtr Begin() const;
    GZStrBlobPtr End() const;
private:
    std::shared_ptr<std::vector<std::string>> data_;
    void CheckSize(size_type i, const std::string &msg) const;
public:
    friend bool operator==(const GZStrBlob &lhs, const GZStrBlob &rhs);
    friend bool operator!=(const GZStrBlob &lhs, const GZStrBlob &rhs);
    friend bool operator<(const GZStrBlob &lhs, const GZStrBlob &rhs);
    friend bool operator<=(const GZStrBlob &lhs, const GZStrBlob &rhs);
    friend bool operator>(const GZStrBlob &lhs, const GZStrBlob &rhs);
    friend bool operator>=(const GZStrBlob &lhs, const GZStrBlob &rhs);
public:
    std::string& operator[](size_t n) { return (*data_)[n]; }
    const std::string& operator[](size_t n) const {return (*data_)[n]; }

public:    
    GZStrBlob(GZStrBlob &&rhs);
    
    GZStrBlob& operator=(GZStrBlob &&rhs);
    //GZStrBlob(std::string *, std::string*);

};

bool operator==(const GZStrBlob &lhs, const GZStrBlob &rhs);
bool operator!=(const GZStrBlob &lhs, const GZStrBlob &rhs);
bool operator<(const GZStrBlob &lhs, const GZStrBlob &rhs);
bool operator<=(const GZStrBlob &lhs, const GZStrBlob &rhs);
bool operator>(const GZStrBlob &lhs, const GZStrBlob &rhs);
bool operator>=(const GZStrBlob &lhs, const GZStrBlob &rhs);
#endif //
