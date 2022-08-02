
#ifndef __CPP_PRIMER_CHAPTER_12_STR_BLOB_H__
#define __CPP_PRIMER_CHAPTER_12_STR_BLOB_H__

#include <string>
#include <memory>
#include <vector>

class GZStrBlobPtr;

/* 12.1.1 shared_ptr类 */
class GZStrBlob
{
// 定义类
public:
    typedef std::vector<std::string>::size_type size_type;
public:
    GZStrBlob();
    GZStrBlob(const std::initializer_list<std::string> &il);
public:
    size_type   Size() const { return data_->size(); }
    bool        Empty() const { return data_->empty(); }
    void        PushBack(const std::string &t) { data_->push_back(t); }
    void        PopBack();

    std::string& Front();
    std::string& Back();
private:
    std::shared_ptr<std::vector<std::string>> data_;
    void CheckSize(size_type i, const std::string &msg) const;

public:
    friend class GZStrBlobPtr;

    GZStrBlob(std::vector<std::string> *p);
    GZStrBlob(const GZStrBlob &rhs);
    GZStrBlob(GZStrBlob &&rhs);
    GZStrBlob& operator=(const GZStrBlob &rhs);
    GZStrBlob& operator=(GZStrBlob &&rhs);
    //GZStrBlob(std::string *, std::string*);

    const std::string& Front() const;
    const std::string& Back() const;

    GZStrBlobPtr Begin();
    GZStrBlobPtr End();
    GZStrBlobPtr Begin() const;
    GZStrBlobPtr End() const;

};


class GZStrBlobPtr
{
    friend bool Equal(const GZStrBlobPtr&, const GZStrBlobPtr&);
    friend bool NotEqual(const GZStrBlobPtr&, const GZStrBlobPtr&);
    friend GZStrBlobPtr operator+(const GZStrBlobPtr&, int);
    friend GZStrBlobPtr operator-(const GZStrBlobPtr&, int);
public:
    GZStrBlobPtr(): curr_(0) { }
    GZStrBlobPtr(const GZStrBlob &a, size_t sz = 0): wptr_(a.data_), curr_(sz) { }

    GZStrBlobPtr& operator++();
    GZStrBlobPtr& operator--();
    GZStrBlobPtr  operator++(int);
    GZStrBlobPtr  operator--(int);
    std::string& operator*() const;
    std::string* operator->() const;
public:
    std::string&    Deref() const;
    std::string&    Deref(int index) const;
    GZStrBlobPtr&     Incr();
    GZStrBlobPtr&     Decr();
private:
    std::shared_ptr<std::vector<std::string>> 
        Check(std::size_t, const std::string&) const;
private:
    std::weak_ptr<std::vector<std::string>> wptr_;  
    std::size_t                             curr_;  
};

GZStrBlobPtr operator+(const GZStrBlobPtr&, int);
GZStrBlobPtr operator-(const GZStrBlobPtr&, int);

bool Equal(const GZStrBlobPtr&, const GZStrBlobPtr&);
bool NotEqual(const GZStrBlobPtr&, const GZStrBlobPtr&);
#endif //
