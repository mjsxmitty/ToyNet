
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
    GZStrBlobPtr Begin();
    GZStrBlobPtr End();
public:
    // hw 12.22
    GZStrBlobPtr Begin() const;
    GZStrBlobPtr End() const;

public:
    const std::string& Front() const;
    const std::string& Back() const;

    // homework 13.55
    //void        PushBack(const std::string &&s) { data_->push_back(std::move(s)); }

    friend bool operator==(const GZStrBlob &lhs, const GZStrBlob &rhs);
    friend bool operator!=(const GZStrBlob &lhs, const GZStrBlob &rhs);
public:
    std::string& operator[](size_t n) { return (*data_)[n]; }
    const std::string& operator[](size_t n) const {return (*data_)[n]; }

public:    
    friend class GZStrBlobPtr;

    GZStrBlob(std::vector<std::string> *p);
    GZStrBlob(const GZStrBlob &rhs);
    GZStrBlob(GZStrBlob &&rhs);
    GZStrBlob& operator=(const GZStrBlob &rhs);
    GZStrBlob& operator=(GZStrBlob &&rhs);
    //GZStrBlob(std::string *, std::string*);




};

// homework 14.16
bool operator==(const GZStrBlob &lhs, const GZStrBlob &rhs);
bool operator!=(const GZStrBlob &lhs, const GZStrBlob &rhs);


/* 12.1.6 weak_ptr类 */
class GZStrBlobPtr
{
public:
    GZStrBlobPtr(): curr_(0) { }
    GZStrBlobPtr(const GZStrBlob &a, size_t sz = 0): wptr_(a.data_), curr_(sz) { }
public:
    GZStrBlobPtr&   Incr();
    std::string&    Deref() const;
private:
    std::shared_ptr<std::vector<std::string>>
        Check(std::size_t, const std::string&) const;
private:
    std::weak_ptr<std::vector<std::string>> wptr_;
    std::size_t                             curr_;

public:
    friend bool Equal(const GZStrBlobPtr&, const GZStrBlobPtr&);
    friend bool NotEqual(const GZStrBlobPtr&, const GZStrBlobPtr&);

    friend bool operator==(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);
    friend bool operator!=(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);

    friend GZStrBlobPtr operator+(const GZStrBlobPtr&, int);
    friend GZStrBlobPtr operator-(const GZStrBlobPtr&, int);
public:
    // homework14.26
    std::string& operator[](size_t n) { return (*wptr_.lock())[n]; }
    const std::string& operator[](size_t n) const { return  (*wptr_.lock())[n]; }
public:
    // homework14.27
    GZStrBlobPtr& operator++();
    GZStrBlobPtr& operator--();
    GZStrBlobPtr  operator++(int);
    GZStrBlobPtr  operator--(int);

    std::string& operator*() const;
    std::string* operator->() const;
public:
    
    std::string&    Deref(int index) const;
    
    GZStrBlobPtr&     Decr();
};

bool Equal(const GZStrBlobPtr&, const GZStrBlobPtr&);
bool NotEqual(const GZStrBlobPtr&, const GZStrBlobPtr&);

// homework 14.16
bool operator==(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);
bool operator!=(const GZStrBlobPtr &lhs, const GZStrBlobPtr &rhs);

GZStrBlobPtr operator+(const GZStrBlobPtr&, int);
GZStrBlobPtr operator-(const GZStrBlobPtr&, int);

#endif //
