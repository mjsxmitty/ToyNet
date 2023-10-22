
#ifndef __CPP_PRIMER_FLODER_H__
#define __CPP_PRIMER_FLODER_H__

#include "message.h"

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

#endif //__CPP_PRIMER_FLODER_H__