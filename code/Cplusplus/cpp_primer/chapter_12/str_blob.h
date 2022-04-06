


#ifndef __CPP_PRIMER_CHAPTER_12_STR_BLOB_H__
#define __CPP_PRIMER_CHAPTER_12_STR_BLOB_H__

#include <string>
#include <memory>
#include <vector>

class StrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
public:
    StrBlob();
    StrBlob(std::vector<std::string> *p); 
    StrBlob(const std::initializer_list<std::string> &il);
    StrBlob(const StrBlob &rhs);
    StrBlob(StrBlob &&rhs);
    StrBlob& operator=(const StrBlob &rhs);
    StrBlob& operator=(StrBlob &&rhs);
	//StrBlob(std::string *, std::string*);  
public:
    size_type   Size() const { return data_->size(); }
    bool        Empty() const { return data_->empty(); }
    void        PushBack(const std::string &t) { data_->push_back(t); }
    void        PopBack();
    std::string& Front();
    std::string& Back();
    const std::string& Front() const;
    const std::string& Back() const;

	StrBlobPtr Begin();
    StrBlobPtr End();
    StrBlobPtr Begin() const;
    StrBlobPtr End() const;
private:
    std::shared_ptr<std::vector<std::string>> data_; 
    void CheckSize(size_type i, const std::string &msg) const;
};


class StrBlobPtr 
{
	friend bool Equal(const StrBlobPtr&, const StrBlobPtr&);
    friend bool NotEqual(const StrBlobPtr&, const StrBlobPtr&);
    friend StrBlobPtr operator+(const StrBlobPtr&, int);
    friend StrBlobPtr operator-(const StrBlobPtr&, int);
public:
    StrBlobPtr(): curr_(0) { }
    StrBlobPtr(const StrBlob &a, size_t sz = 0): wptr_(a.data_), curr_(sz) { }

    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr  operator++(int);
    StrBlobPtr  operator--(int);
    std::string& operator*() const;
    std::string* operator->() const;
public:
    std::string&    Deref() const;
    std::string&    Deref(int index) const;
    StrBlobPtr&     Incr();      
    StrBlobPtr&     Decr();       
private:
    std::shared_ptr<std::vector<std::string>> 
        Check(std::size_t, const std::string&) const;
private:
    std::weak_ptr<std::vector<std::string>> wptr_;  
    std::size_t                             curr_;  
};

StrBlobPtr operator+(const StrBlobPtr&, int);
StrBlobPtr operator-(const StrBlobPtr&, int);

bool Equal(const StrBlobPtr&, const StrBlobPtr&);
bool NotEqual(const StrBlobPtr&, const StrBlobPtr&);
#endif //