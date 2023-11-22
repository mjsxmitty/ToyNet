

#ifndef __EFFECTIVE_CPP_ITEM_08_H__
#define __EFFECTIVE_CPP_ITEM_08_H__

void Item08();

namespace effective_item_08 {

class DBConnection
{
public:
    static DBConnection create()
    {
        static DBConnection db;
        return db;
    }

    // 抛出某种异常
    void close()
    {

    }
};


// 管理类
class DBCon
{
public:
    DBCon(const DBConnection &dbc) : db(dbc), closed(false)
    {

    }

    // 析构不应该吐出异常,应该吞掉或者终止
    ~DBCon()
    {
        if (!closed)
        {
            try {
                db.close();
            } catch (...) {
                //
                //std::abort();
            }
        }
    }

    // 交由用户去处理
    void Close()
    {
        db.close();
        closed = true;
    }
private:
    DBConnection db;
    bool closed = false;
};
}

#endif // __EFFECTIVE_CPP_ITEM_08_H__
