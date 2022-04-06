

#ifndef __CPP_PRIMER_CHAPTER_13_FOLDER_MESSAGE_H__
#define __CPP_PRIMER_CHAPTER_13_FOLDER_MESSAGE_H__

#include <string>
#include <set>

class Folder;
class Message
{
    friend void Swap(Message &lhs, Message &rhs);
public:
    explicit Message(const std::string &str = "") : contents_(str) {}
    Message(const Message &rhs);
    Message& operator=(const Message &rhs);
    
    ~Message();
    
    Message(Message &&rhs);
    Message& operator=(Message &&rhs);
public:
    void Save(Folder &folder);
    void Remove(Folder &folder);

    void AddFolder(Folder *f) { folders_.insert(f); }
    void RemFolder(Folder *f) { folders_.erase(f); }
private:
    /*更新folders*/
    void AddToFolder(const Message &m);
    void RemoveFormFolder();

    void MoveFolders(Message *m);
private:
    std::string          contents_;
    std::set<Folder*>    folders_;    
};

void Swap(Message &lhs, Message &rhs);

class Folder
{
public:
    Folder() = default;
    Folder(const Folder &rhs);
    Folder(Folder &&rhs);
    Folder& operator=(const Folder &rhs);
    Folder& operator=(Folder &&rhs);
    ~Folder();
public:
    void Save(Message &m);
    void Remove(Message &m);

    void AddMsg(Message *m) { messages_.insert(m); }
    void RemMsg(Message *m) { messages_.erase(m); }
private:
    void AddToMessage(const Folder &f);
    void RemoveFromMessage();
    void MoveMessage(Folder *item);
private:
    std::set<Message*>   messages_;
};




#endif //