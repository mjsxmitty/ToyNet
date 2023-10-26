
#include "folder.h"
#include "message.h"

void Folder::RemoveFromMessage()
{
    while (!messages_.empty())
        (*messages_.begin())->Remove(*this);
}

void Folder::AddToMessage(const Folder &f)
{
    for (auto msg : f.messages_)
        msg->AddFolder(this);
}

Folder::Folder(const Folder &f) : messages_(f.messages_)
{
    AddToMessage(f);
}

Folder::~Folder()
{
    RemoveFromMessage();
}

Folder& Folder::operator=(const Folder &f)
{
    RemoveFromMessage();
    messages_ = f.messages_;
    AddToMessage(f);
    return *this;
}

void Folder::Save(Message &m)
{
    messages_.insert(&m);
    m.AddFolder(this);
}

void Folder::Remove(Message &m)
{
    messages_.erase(&m);
    m.RemFolder(this);
}

void Folder::MoveMessage(Folder *f)
{
    messages_ = std::move(f->messages_);
    f->messages_.clear();

    for (auto m : messages_)
    {
        m->RemFolder(f);
        m->AddFolder(this);
    }
}

Folder::Folder(Folder &&f)
{
    MoveMessage(&f);
}

Folder& Folder::operator=(Folder &&f)
{
    if (this != &f)
    {
        RemoveFromMessage();
        MoveMessage(&f);
    }
    return *this;
}
