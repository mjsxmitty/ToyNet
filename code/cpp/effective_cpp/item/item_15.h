
#ifndef __EFFECTIVE_CPP_ITEM_15_H__
#define __EFFECTIVE_CPP_ITEM_15_H__

void Item15();

namespace effective_item_15 {

class FontHandle
{

};

FontHandle GetFont();
void ReleaseFont(FontHandle fh);

class Font
{
public:
    explicit Font(const FontHandle &fh) : fh_(fh) {}
    ~Font()
    {
        ReleaseFont(fh_);
    }

    FontHandle get() const
    {
        return fh_;
    }

    operator FontHandle() const
    {
        return fh_;
    }
private:
    FontHandle fh_;
};

void ChangeFontSize(FontHandle f, int new_size);

}

#endif // __EFFECTIVE_CPP_ITEM_15_H__
