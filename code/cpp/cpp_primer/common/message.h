

#ifndef __CPP_PRIMER_FOLDER_MESSAGE_H__
#define __CPP_PRIMER_FOLDER_MESSAGE_H__

#include <string>
#include <set>

class Folder;
class Message
{
    friend void Swap(Message &lhs, Message &rhs);
public:
    explicit Message(const std::string &str = "") : contents_(str) {}
    Message(const Message &rhs);
    Message(Message &&rhs);
    Message& operator=(Message &&rhs);
    Message& operator=(const Message &rhs);
    ~Message();
public:
    void Save(Folder &folder);
    void Remove(Folder &folder);

    void AddFolder(Folder *f) { folders_.insert(f); }
    void RemFolder(Folder *f) { folders_.erase(f); }
private:
    void AddToFolders(const Message &m);
    void RemoveFormFolders();

    void MoveFolders(Message *m);
private:
    std::string          contents_;
    std::set<Folder*>    folders_;    
};

void Swap(Message &lhs, Message &rhs);

#endif // __CPP_PRIMER_FOLDER_MESSAGE_H__